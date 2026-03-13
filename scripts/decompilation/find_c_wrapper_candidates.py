#!/usr/bin/env python3
"""Find asm volatile functions that can be converted from ret-in-asm to C-wrapper form.

A "C-wrapper" function has:
  - C function signature and return statement
  - asm volatile for the computation (without ret)
  - Output constraints ("=a", "=t", "=c") to pass results back to C

This script identifies ret-in-asm functions that are safe to convert,
filtering out those with blockers like [esp+N] access, vtable jmp, or bool return.
"""

import re
from pathlib import Path
from dataclasses import dataclass, field


@dataclass
class Candidate:
    file: str
    name: str
    line: int
    asm_lines: list[str] = field(default_factory=list)
    return_register: str = "eax"  # "eax", "st0", "void", "al"
    has_ecx_save: bool = False  # push esi; mov esi, ecx
    ret_cleanup: int = 0  # ret N stack cleanup bytes
    return_type: str = ""
    blocker: str = ""  # empty = convertible


def normalize_asm(line: str) -> str:
    """Strip encoding hints and normalize whitespace."""
    line = re.sub(r'%?\{disp\d+%?\}\s*', '', line)
    line = re.sub(r'\s+', ' ', line).strip()
    return line


def extract_volatile_instructions(body: str) -> list[str]:
    """Extract instruction lines from asm volatile blocks."""
    instructions = []
    for m in re.finditer(r'asm\s+volatile\s*\((.*?)\)', body, re.DOTALL):
        block = m.group(1)
        colon_pos = block.find(':::')
        if colon_pos == -1:
            colon_pos = block.find(':')
        if colon_pos != -1:
            block = block[:colon_pos]
        strings = re.findall(r'"([^"]*)"', block)
        full_asm = ''.join(strings)
        for line in re.split(r'\\n\\t|\\n', full_asm):
            line = normalize_asm(line)
            if line and not line.endswith(':'):
                instructions.append(line)
    return instructions


def has_output_constraints(body: str) -> bool:
    """Check if the asm volatile already has output constraints (already C-wrapper)."""
    for m in re.finditer(r'asm\s+volatile\s*\((.*?)\)', body, re.DOTALL):
        block = m.group(1)
        if '"=a"' in block or '"=t"' in block or '"=c"' in block:
            return True
    return False


def analyze_function(filepath: Path, text: str, match: re.Match) -> Candidate | None:
    """Analyze a single function for C-wrapper conversion eligibility."""
    func_start = match.start()
    return_type = match.group(1)
    func_name = match.group(2)
    params = match.group(3)
    line_num = text[:func_start].count('\n') + 1

    # Find the closing brace
    brace_depth = 0
    body_start = text.index('{', match.end() - 1)
    pos = body_start
    while pos < len(text):
        if text[pos] == '{':
            brace_depth += 1
        elif text[pos] == '}':
            brace_depth -= 1
            if brace_depth == 0:
                break
        pos += 1
    body = text[body_start:pos + 1]

    # Must have asm volatile
    if 'asm volatile' not in body:
        return None

    # Must have __builtin_unreachable (ret-in-asm form)
    if '__builtin_unreachable' not in body:
        return None

    # Skip if already has output constraints (already C-wrapper)
    if has_output_constraints(body):
        return None

    instructions = extract_volatile_instructions(body)
    if not instructions:
        return None

    cand = Candidate(
        file=str(filepath.relative_to(filepath.parent.parent.parent)),
        name=func_name,
        line=line_num,
        asm_lines=instructions,
        return_type=return_type,
    )

    # --- Check blockers ---

    # Find ret instruction
    ret_idx = None
    for i, line in enumerate(instructions):
        if line.startswith('ret'):
            ret_idx = i
            break

    if ret_idx is None:
        cand.blocker = "no ret found"
        return cand

    # Check for ret N (stack cleanup)
    ret_line = instructions[ret_idx]
    ret_match = re.match(r'ret\s+0x([0-9a-f]+)', ret_line)
    if ret_match:
        cand.ret_cleanup = int(ret_match.group(1), 16)

    # Instructions before ret (the actual computation)
    code = instructions[:ret_idx]

    # Check for trailing code after ret (not just nops)
    trailing = instructions[ret_idx + 1:]
    non_nop_trailing = [l for l in trailing if l.strip() != 'nop']
    if non_nop_trailing:
        cand.blocker = f"trailing code after ret ({len(non_nop_trailing)} instrs)"
        return cand

    # Check for [esp+N] access (stack param access — breaks with C wrapper)
    joined = ' '.join(code)
    if re.search(r'\[esp', joined):
        cand.blocker = "[esp+N] access (stack params)"
        return cand

    # Check for jmp to vtable (can't convert jmp to call+ret)
    if re.search(r'jmp\s+dword ptr \[eax', joined):
        cand.blocker = "vtable jmp (not call)"
        return cand

    # Check for jmp to symbol (tail call)
    if re.search(r'jmp\s+\S', joined) and not re.search(r'j(e|ne|g|ge|l|le|a|ae|b|be|z|nz|s|ns|o|no|p|np)\s', joined):
        # This is a jmp to a target, not a conditional jump
        if re.search(r'jmp\s+(?!dword)', joined):
            cand.blocker = "jmp tail call"
            return cand

    # Check for ret N with stack cleanup
    if cand.ret_cleanup > 0:
        cand.blocker = f"ret {cand.ret_cleanup:#x} (stack cleanup)"
        return cand

    # Check return type — bool adds "and al, 1"
    clean_ret = return_type.strip()
    if clean_ret == 'bool':
        cand.blocker = "bool return type (adds 'and al, 1')"
        return cand

    # --- Determine return register ---

    # Check for FPU operations before ret (float return via ST(0))
    fpu_ops = [l for l in code if re.match(r'f(ld|add|sub|mul|div|comp|st|xch)', l)]
    if fpu_ops:
        # Check if the last FPU op leaves result in ST(0)
        last_fpu = fpu_ops[-1]
        if last_fpu.startswith('fstp') or last_fpu.startswith('fistp'):
            # fstp stores AND pops — result is NOT in ST(0)
            cand.return_register = "eax"
        else:
            cand.return_register = "st0"
    else:
        cand.return_register = "eax"

    # Check for void return (no result expected)
    if clean_ret == 'void':
        cand.return_register = "void"

    # Check for ecx save pattern (push esi; mov esi, ecx)
    if len(code) >= 2:
        first_two = ' '.join(code[:2])
        if 'push esi' in first_two and re.search(r'mov\.?s?\s+esi,\s*ecx', first_two):
            cand.has_ecx_save = True
        # Also check mov.s esi, ecx without push first
        elif re.search(r'mov\.?s?\s+esi,\s*ecx', ' '.join(code[:3])):
            cand.has_ecx_save = True

    return cand


def main():
    src_dir = Path(__file__).parent.parent.parent / "src" / "c"

    func_pattern = re.compile(
        r'^(?:__attribute__\(\([^)]*\)\)\s*\n)?'
        r'(\S.*?)\s+(?:__fastcall|__cdecl)\s+(\w+)\s*\(([^)]*)\)\s*\n\{',
        re.MULTILINE
    )

    candidates = []
    blocked = []

    for cfile in sorted(src_dir.glob("*.c")):
        text = cfile.read_text()
        for match in func_pattern.finditer(text):
            cand = analyze_function(cfile, text, match)
            if cand is None:
                continue
            if cand.blocker:
                blocked.append(cand)
            else:
                candidates.append(cand)

    # Group candidates by return register
    by_register: dict[str, list[Candidate]] = {}
    for c in candidates:
        by_register.setdefault(c.return_register, []).append(c)

    print("=" * 80)
    print(f"C-WRAPPER CONVERSION CANDIDATES — {len(candidates)} convertible")
    print("=" * 80)

    for reg in ["eax", "st0", "void"]:
        funcs = by_register.get(reg, [])
        if not funcs:
            continue
        constraint = {"eax": '"=a"(result)', "st0": '"=t"(result)', "void": "no output"}[reg]
        print(f"\n{'─' * 80}")
        print(f"  {reg.upper()} return ({len(funcs)} functions) — use {constraint}")
        print(f"{'─' * 80}")
        for c in funcs:
            short_name = c.name.split('__')[0] if '__' in c.name else c.name
            ecx_tag = " [ecx-save]" if c.has_ecx_save else ""
            print(f"    {c.file}:{c.line:<5}  {short_name:<45}  {c.return_type}{ecx_tag}")

    # Blocked summary
    by_blocker: dict[str, list[Candidate]] = {}
    for c in blocked:
        by_blocker.setdefault(c.blocker, []).append(c)

    print(f"\n{'=' * 80}")
    print(f"BLOCKED — {len(blocked)} functions")
    print(f"{'=' * 80}")
    for reason, funcs in sorted(by_blocker.items(), key=lambda x: -len(x[1])):
        print(f"\n  {reason} ({len(funcs)})")
        for c in funcs[:5]:  # Show first 5 of each category
            short_name = c.name.split('__')[0] if '__' in c.name else c.name
            print(f"    {c.file}:{c.line:<5}  {short_name}")
        if len(funcs) > 5:
            print(f"    ... and {len(funcs) - 5} more")

    print(f"\n{'=' * 80}")
    print(f"SUMMARY")
    print(f"{'=' * 80}")
    print(f"  Convertible:  {len(candidates):>4}")
    for reg in ["eax", "st0", "void"]:
        count = len(by_register.get(reg, []))
        if count:
            print(f"    {reg.upper()}: {count}")
    ecx_count = sum(1 for c in candidates if c.has_ecx_save)
    print(f"    With ecx-save: {ecx_count}")
    print(f"  Blocked:      {len(blocked):>4}")
    for reason, funcs in sorted(by_blocker.items(), key=lambda x: -len(x[1])):
        print(f"    {reason}: {len(funcs)}")


if __name__ == "__main__":
    main()

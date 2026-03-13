#!/usr/bin/env python3
"""Find functions that could be converted to C if no_callee_saves or forced_callee_saves were available.

Scans all .c files in src/c/ for functions using the ret-in-asm pattern
(asm volatile + __builtin_unreachable) and classifies them into:

  Category A - "no_callee_saves candidates":
    Functions that use [esp+N] but do NOT push callee-saved registers
    (esi, edi, ebx, ebp). These only use scratch registers and access
    stack params directly. Convertible with just no_callee_saves.

  Category B - "forced_callee_saves candidates":
    Functions that use [esp+N] AND push callee-saved registers. These
    need forced_callee_saves with the exact push sequence specified.

  Category C - "already simple":
    Functions with ret N but NO [esp access. These might already be
    convertible without any special attributes.
"""

import re
from pathlib import Path
from dataclasses import dataclass, field


# Callee-saved registers whose push/pop the compiler normally controls
CALLEE_SAVED_PUSH_RE = re.compile(r'push\s+(esi|edi|ebx|ebp|ecx)')


@dataclass
class Candidate:
    file: str
    name: str
    line: int
    asm_lines: list[str] = field(default_factory=list)
    category: str = ""       # "A", "B", or "C"
    push_sequence: list[str] = field(default_factory=list)
    has_esp_access: bool = False
    ret_cleanup: int = 0
    return_type: str = ""


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


def extract_function_body(text: str, match: re.Match) -> str | None:
    """Extract the full function body between braces."""
    try:
        brace_depth = 0
        body_start = text.index('{', match.end() - 1)
        pos = body_start
        while pos < len(text):
            if text[pos] == '{':
                brace_depth += 1
            elif text[pos] == '}':
                brace_depth -= 1
                if brace_depth == 0:
                    return text[body_start:pos + 1]
            pos += 1
    except ValueError:
        pass
    return None


def find_push_sequence(instructions: list[str]) -> list[str]:
    """Extract the ordered sequence of callee-saved register pushes."""
    pushes = []
    for line in instructions:
        m = CALLEE_SAVED_PUSH_RE.match(line.strip())
        if m:
            pushes.append(m.group(1))
    return pushes


def analyze_function(
    filepath: Path, src_root: Path, text: str, match: re.Match
) -> Candidate | None:
    """Analyze a single ret-in-asm function for callee-save classification."""
    func_start = match.start()
    return_type = match.group(1)
    func_name = match.group(2)
    line_num = text[:func_start].count('\n') + 1

    body = extract_function_body(text, match)
    if body is None:
        return None

    # Must be a ret-in-asm function (asm volatile + __builtin_unreachable)
    if 'asm volatile' not in body:
        return None
    if '__builtin_unreachable' not in body:
        return None

    instructions = extract_volatile_instructions(body)
    if not instructions:
        return None

    # Compute the relative file path for display
    try:
        rel_file = str(filepath.relative_to(src_root))
    except ValueError:
        rel_file = str(filepath)

    cand = Candidate(
        file=rel_file,
        name=func_name,
        line=line_num,
        asm_lines=instructions,
        return_type=return_type,
    )

    # Check for [esp+N] access in the asm body
    joined = ' '.join(instructions)
    cand.has_esp_access = bool(re.search(r'\[esp', joined))

    # Find callee-saved register pushes
    cand.push_sequence = find_push_sequence(instructions)

    # Check for ret N (stack cleanup)
    for line in instructions:
        ret_match = re.match(r'ret\s+0x([0-9a-fA-F]+)', line.strip())
        if ret_match:
            cand.ret_cleanup = int(ret_match.group(1), 16)
            break
        # Also match plain "ret N" with decimal
        ret_match = re.match(r'ret\s+(\d+)', line.strip())
        if ret_match:
            cand.ret_cleanup = int(ret_match.group(1))
            break

    # Classify into categories
    if cand.has_esp_access and not cand.push_sequence:
        cand.category = "A"
    elif cand.has_esp_access and cand.push_sequence:
        cand.category = "B"
    elif not cand.has_esp_access and cand.ret_cleanup > 0:
        cand.category = "C"
    else:
        # Does not fit any of the three categories
        return None

    return cand


def format_push_sequence(pushes: list[str]) -> str:
    """Format the push sequence for display."""
    if not pushes:
        return "(none)"
    return " -> ".join(f"push {r}" for r in pushes)


def main():
    src_root = Path(__file__).parent.parent.parent
    src_dir = src_root / "src" / "c"

    func_pattern = re.compile(
        r'^(?:__attribute__\(\([^)]*\)\)\s*\n)?'
        r'(\S.*?)\s+(?:__fastcall|__cdecl)\s+(\w+)\s*\(([^)]*)\)\s*\n\{',
        re.MULTILINE,
    )

    category_a: list[Candidate] = []
    category_b: list[Candidate] = []
    category_c: list[Candidate] = []

    # Scan top-level .c files and files in subdirectories
    c_files = sorted(src_dir.rglob("*.c"))

    for cfile in c_files:
        text = cfile.read_text()
        for match in func_pattern.finditer(text):
            cand = analyze_function(cfile, src_root, text, match)
            if cand is None:
                continue
            if cand.category == "A":
                category_a.append(cand)
            elif cand.category == "B":
                category_b.append(cand)
            elif cand.category == "C":
                category_c.append(cand)

    total = len(category_a) + len(category_b) + len(category_c)

    # --- Category A ---
    print("=" * 90)
    print(f"CATEGORY A: no_callee_saves candidates ({len(category_a)} functions)")
    print("  Uses [esp+N] but NO callee-saved pushes -- scratch registers only")
    print("=" * 90)
    for c in category_a:
        short_name = c.name.split('__')[0] if '__' in c.name else c.name
        ret_tag = f"  ret {c.ret_cleanup:#x}" if c.ret_cleanup else ""
        print(f"  {c.file}:{c.line:<5}  {short_name:<50}  {c.return_type}{ret_tag}")

    # --- Category B ---
    print()
    print("=" * 90)
    print(f"CATEGORY B: forced_callee_saves candidates ({len(category_b)} functions)")
    print("  Uses [esp+N] AND has callee-saved pushes -- needs forced_callee_saves")
    print("=" * 90)

    # Group by push sequence for readability
    by_push_seq: dict[str, list[Candidate]] = {}
    for c in category_b:
        key = ", ".join(c.push_sequence)
        by_push_seq.setdefault(key, []).append(c)

    for seq_key in sorted(by_push_seq.keys()):
        funcs = by_push_seq[seq_key]
        print(f"\n  Push sequence: [{seq_key}] ({len(funcs)} functions)")
        print(f"  {'-' * 80}")
        for c in funcs:
            short_name = c.name.split('__')[0] if '__' in c.name else c.name
            ret_tag = f"  ret {c.ret_cleanup:#x}" if c.ret_cleanup else ""
            print(
                f"    {c.file}:{c.line:<5}  {short_name:<48}  "
                f"{c.return_type}{ret_tag}"
            )

    # --- Category C ---
    print()
    print("=" * 90)
    print(f"CATEGORY C: already simple ({len(category_c)} functions)")
    print("  Has ret N but NO [esp access -- may already be convertible")
    print("=" * 90)
    for c in category_c:
        short_name = c.name.split('__')[0] if '__' in c.name else c.name
        pushes_tag = (
            f"  pushes: [{', '.join(c.push_sequence)}]"
            if c.push_sequence
            else ""
        )
        print(
            f"  {c.file}:{c.line:<5}  {short_name:<50}  "
            f"{c.return_type}  ret {c.ret_cleanup:#x}{pushes_tag}"
        )

    # --- Summary ---
    print()
    print("=" * 90)
    print("SUMMARY")
    print("=" * 90)
    print(f"  Total ret-in-asm functions analyzed:  {total}")
    print()
    print(f"  Category A (no_callee_saves):         {len(category_a):>4}")
    print(f"  Category B (forced_callee_saves):      {len(category_b):>4}")
    print(f"  Category C (already simple):           {len(category_c):>4}")

    if by_push_seq:
        print()
        print("  Push sequence breakdown (Category B):")
        for seq_key in sorted(by_push_seq.keys(), key=lambda k: -len(by_push_seq[k])):
            count = len(by_push_seq[seq_key])
            print(f"    [{seq_key}]: {count}")


if __name__ == "__main__":
    main()

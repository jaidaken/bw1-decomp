#!/usr/bin/env python3
"""Classify asm-containing functions by decompilation difficulty.

Scans all .c files in src/c/ and categorizes every function that still
contains asm() or asm volatile() calls into difficulty tiers based on
pattern matching.
"""

import re
import sys
from pathlib import Path
from dataclasses import dataclass, field


@dataclass
class AsmFunction:
    file: str
    name: str
    line: int
    asm_lines: list[str] = field(default_factory=list)
    asm_type: str = "individual"  # "individual" or "volatile"
    category: str = "unknown"
    difficulty: str = "unknown"
    note: str = ""


def normalize_asm_line(line: str) -> str:
    """Strip encoding hints and normalize whitespace from an asm instruction."""
    line = re.sub(r'%?\{disp\d+%?\}\s*', '', line)
    line = re.sub(r'\s+', ' ', line).strip()
    return line


def extract_volatile_instructions(body: str) -> list[str]:
    """Extract instruction lines from asm volatile blocks in a function body."""
    instructions = []
    # Find all asm volatile blocks and extract their string contents
    for m in re.finditer(r'asm\s+volatile\s*\((.*?)\)', body, re.DOTALL):
        block = m.group(1)
        # Extract everything before the first ':' (output operands)
        colon_pos = block.find(':::')
        if colon_pos == -1:
            # Try single colon (output : input : clobber)
            colon_pos = block.find(':')
        if colon_pos != -1:
            block = block[:colon_pos]
        # Extract all string literals and concatenate
        strings = re.findall(r'"([^"]*)"', block)
        full_asm = ''.join(strings)
        # Split on \n\t or \n
        for line in re.split(r'\\n\\t|\\n', full_asm):
            line = normalize_asm_line(line)
            if line and not line.endswith(':'):  # skip labels
                instructions.append(line)
    return instructions


def extract_individual_instructions(body: str) -> list[str]:
    """Extract instruction lines from individual asm() calls in a function body."""
    instructions = []
    for m in re.findall(r'(?<!volatile\s)asm\s*\("([^"]+)"\s*\)', body):
        line = normalize_asm_line(m)
        if line and not line.endswith(':'):
            instructions.append(line)
    # Also match multi-line asm blocks
    for m in re.findall(r'(?<!volatile\s)asm\s*\(\s*\n\s*"([^"]+)"', body):
        line = normalize_asm_line(m)
        if line and not line.endswith(':'):
            instructions.append(line)
    return instructions


def extract_asm_functions(filepath: Path) -> list[AsmFunction]:
    """Extract all functions containing asm() or asm volatile() from a C file."""
    text = filepath.read_text()
    functions = []

    # Match function definitions with __fastcall or __cdecl
    func_pattern = re.compile(
        r'^(?:(__attribute__\(\([^)]*\)\))\s*\n)?'
        r'(\S.*?)\s+(?:__fastcall|__cdecl)\s+(\w+)\s*\(([^)]*)\)\s*\n\{',
        re.MULTILINE
    )

    for match in func_pattern.finditer(text):
        func_start = match.start()
        func_name = match.group(3)
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

        has_volatile = 'asm volatile' in body or 'asm  volatile' in body
        has_individual = bool(re.search(r'asm\s*\("', body))

        if not has_volatile and not has_individual:
            continue

        # Extract instructions based on type
        if has_volatile:
            asm_lines = extract_volatile_instructions(body)
            asm_type = "volatile"
        else:
            asm_lines = extract_individual_instructions(body)
            asm_type = "individual"

        if not asm_lines:
            continue

        func = AsmFunction(
            file=str(filepath.relative_to(filepath.parent.parent.parent)),
            name=func_name,
            line=line_num,
            asm_lines=asm_lines,
            asm_type=asm_type,
        )
        classify_function(func)
        functions.append(func)

    return functions


def classify_function(func: AsmFunction):
    """Classify a function by its asm pattern."""
    lines = func.asm_lines
    n = len(lines)

    # Filter out labels and trailing junk (calls after ret)
    code_lines = []
    for line in lines:
        stripped = line.strip()
        if stripped.startswith('LAB__') or (stripped.startswith('call') and code_lines and any('ret' in cl for cl in code_lines)):
            continue
        code_lines.append(stripped)

    # Remove trailing instructions after ret (padding/alignment artifacts)
    ret_idx = None
    for i, line in enumerate(code_lines):
        if line.strip().startswith('ret'):
            ret_idx = i
            break
    if ret_idx is not None:
        main_code = code_lines[:ret_idx + 1]
    else:
        main_code = code_lines

    n_code = len(main_code)
    joined = ' | '.join(main_code)

    # === TRIVIAL: fld [const]; ret === (return float constant)
    if n_code <= 3 and re.search(r'fld\s+dword ptr \[_rdata', joined):
        if 'ret' in joined and 'call' not in joined:
            const_match = re.search(r'\[(_rdata_\w+)\]', joined)
            const_name = const_match.group(1) if const_match else "?"
            func.category = "float_const_return"
            func.difficulty = "LOW"
            func.note = f"return {const_name};"
            return

    # === TRIVIAL: fld [ecx + N]; ret === (return float field)
    if n_code <= 3 and re.search(r'fld\s+dword ptr \[ecx \+ 0x([0-9a-f]+)\]', joined):
        if 'ret' in joined and 'call' not in joined:
            offset_match = re.search(r'\[ecx \+ 0x([0-9a-f]+)\]', joined)
            offset = offset_match.group(1) if offset_match else "?"
            func.category = "float_field_getter"
            func.difficulty = "LOW"
            func.note = f"return this->field_at_0x{offset};"
            return

    # === TRIVIAL: mov eax, [ecx + N]; ret === (return ptr/int field)
    if n_code <= 3 and re.search(r'mov\s+eax,\s*dword ptr \[ecx \+ 0x([0-9a-f]+)\]', joined):
        if 'ret' in joined and 'call' not in joined and 'jmp' not in joined:
            offset_match = re.search(r'\[ecx \+ 0x([0-9a-f]+)\]', joined)
            offset = offset_match.group(1) if offset_match else "?"
            func.category = "int_field_getter"
            func.difficulty = "LOW"
            func.note = f"return this->field_at_0x{offset};"
            return

    # === TRIVIAL: mov eax, ecx; ret === (return this)
    if n_code <= 3 and re.search(r'mov\.?s?\s+eax,\s*ecx', joined) and 'ret' in joined:
        func.category = "return_this"
        func.difficulty = "LOW"
        func.note = "return this;"
        return

    # === TRIVIAL: xor eax, eax; ret === (return 0)
    if n_code <= 3 and re.search(r'xor\.?s?\s+eax,\s*eax', joined) and 'ret' in joined:
        func.category = "return_zero"
        func.difficulty = "LOW"
        func.note = "return 0;"
        return

    # === TRIVIAL: mov al, 0x01; ret === (return true as byte)
    if n_code <= 3 and re.search(r'mov\s+al,\s*0x0[01]', joined) and 'ret' in joined:
        val = "true" if "0x01" in joined else "false"
        func.category = "return_bool_byte"
        func.difficulty = "LOW"
        func.note = f"return {val}; (byte-sized)"
        return

    # === TRIVIAL: or eax, -0x1; ret === (return -1)
    if n_code <= 3 and 'or' in joined and '-0x1' in joined and 'ret' in joined:
        func.category = "return_minus_one"
        func.difficulty = "LOW"
        func.note = "return -1;"
        return

    # === LOW: jmp target (thunk)
    if n_code == 1 and re.match(r'jmp\s+', joined):
        target = re.search(r'jmp\s+(\S+)', joined)
        func.category = "jmp_thunk"
        func.difficulty = "LOW"
        func.note = f"jmp {target.group(1)[:40] if target else '?'};"
        return

    # === LOW: simple setter: mov eax, [esp+N]; mov [ecx+N], eax; ret ===
    if n_code <= 4 and re.search(r'mov.*\[esp', joined) and re.search(r'mov.*\[ecx \+', joined) and 'ret' in joined:
        func.category = "field_setter"
        func.difficulty = "LOW"
        func.note = "this->field = param;"
        return

    # === LOW: lea eax, [ecx+N]; ret === (return address of field)
    if n_code <= 3 and re.search(r'lea\s+eax,\s*\[ecx \+ 0x([0-9a-f]+)\]', joined) and 'ret' in joined:
        offset_match = re.search(r'\[ecx \+ 0x([0-9a-f]+)\]', joined)
        offset = offset_match.group(1) if offset_match else "?"
        func.category = "lea_addr_getter"
        func.difficulty = "LOW"
        func.note = f"return &this->field_at_0x{offset};"
        return

    # === LOW: set field to constant; ret
    if n_code <= 3 and re.search(r'mov\s+dword ptr \[ecx \+.*\],\s*0x', joined) and 'ret' in joined:
        func.category = "field_set_const"
        func.difficulty = "LOW"
        func.note = "this->field = constant;"
        return

    # === LOW: word set + return 1 (mov word [ecx+N], imm; mov eax, 1; ret)
    if n_code <= 4 and re.search(r'mov\s+word ptr \[ecx', joined) and re.search(r'mov\s+eax,\s*0x0*1', joined) and 'ret' in joined:
        func.category = "word_set_return_1"
        func.difficulty = "LOW"
        func.note = "this->short_field = imm; return 1;"
        return

    # === LOW: set null + return 1 (mov [ecx+N], 0; mov eax, 1; ret)
    if n_code <= 4 and re.search(r'mov\s+dword ptr \[ecx.*\],\s*0x0+\b', joined) and re.search(r'mov\s+eax,\s*0x0*1', joined) and 'ret' in joined:
        func.category = "set_null_return_1"
        func.difficulty = "LOW"
        func.note = "this->field = NULL; return 1;"
        return

    # === LOW: mov eax, [ecx+A]; mov eax, [eax+B]; ret (double deref)
    if n_code <= 4 and re.search(r'mov\s+eax,.*\[ecx', joined) and re.search(r'mov\s+eax,.*\[eax', joined) and 'ret' in joined:
        func.category = "double_deref_getter"
        func.difficulty = "LOW"
        func.note = "return this->ptr->field;"
        return

    # === LOW: mov eax, [ecx+A]; fld [eax+B]; ret (info float getter)
    if n_code <= 4 and re.search(r'mov\s+eax,.*\[ecx', joined) and re.search(r'fld\s+dword ptr \[eax', joined) and 'ret' in joined:
        func.category = "info_float_getter"
        func.difficulty = "LOW"
        func.note = "return this->ptr->float_field;"
        return

    # === LOW: mov eax, [ecx+A]; add eax, B; ret (info addr getter)
    if n_code <= 4 and re.search(r'mov\s+eax,.*\[ecx', joined) and 'add eax' in joined and 'ret' in joined:
        func.category = "info_addr_getter"
        func.difficulty = "LOW"
        func.note = "return &this->ptr->field;"
        return

    # === LOW-MEDIUM: virtual dispatch: mov eax, [ecx]; jmp [eax + N] ===
    if n_code <= 4 and re.search(r'mov\s+eax,\s*dword ptr \[ecx\]', joined) and re.search(r'jmp\s+dword ptr \[eax \+ 0x([0-9a-f]+)\]', joined):
        offset_match = re.search(r'jmp\s+dword ptr \[eax \+ 0x([0-9a-f]+)\]', joined)
        offset = offset_match.group(1) if offset_match else "?"
        func.category = "vtable_dispatch"
        func.difficulty = "LOW-MEDIUM"
        func.note = f"return this->vt[0x{offset}]();"
        return

    # === LOW-MEDIUM: virtual dispatch via call
    if n_code <= 4 and re.search(r'mov\s+eax,\s*dword ptr \[ecx\]', joined) and re.search(r'call\s+dword ptr \[eax \+ 0x([0-9a-f]+)\]', joined):
        offset_match = re.search(r'call\s+dword ptr \[eax \+ 0x([0-9a-f]+)\]', joined)
        offset = offset_match.group(1) if offset_match else "?"
        func.category = "vtable_call"
        func.difficulty = "LOW-MEDIUM"
        func.note = f"calls this->vt[0x{offset}]() and returns result;"
        return

    # === LOW-MEDIUM: neg/sbb pattern (boolify)
    if re.search(r'\.byte 0x1b, 0xc0', joined) and n_code <= 10:
        func.category = "neg_sbb_pattern"
        func.difficulty = "LOW-MEDIUM"
        func.note = "neg/sbb boolification"
        return

    # === MEDIUM: indirect field access: mov ecx, [ecx+N]; then vtable dispatch ===
    if n_code <= 4 and re.search(r'mov\s+ecx,.*\[ecx \+ 0x', joined) and re.search(r'jmp\s+dword ptr \[eax', joined):
        func.category = "indirect_vtable_dispatch"
        func.difficulty = "MEDIUM"
        func.note = "this->sub_object->vt_method();"
        return

    # === MEDIUM: bitfield accessor ===
    if re.search(r'(shr|shl|and\s|or\.|not)', joined) and n_code <= 8:
        func.category = "bitfield_accessor"
        func.difficulty = "MEDIUM"
        func.note = "bit manipulation on flags field"
        return

    # === MEDIUM: struct copy (MapCoords return) ===
    if joined.count('mov') >= 4 and re.search(r'mov\s+dword ptr \[edx', joined) and n_code <= 12:
        func.category = "struct_copy"
        func.difficulty = "MEDIUM"
        func.note = "copies struct fields to output pointer"
        return

    # === MEDIUM: FPU comparison (fcomp/fnstsw/test) ===
    if 'fcomp' in joined and 'fnstsw' in joined and n_code <= 15:
        func.category = "fpu_comparison"
        func.difficulty = "MEDIUM"
        func.note = "float comparison with branch"
        return

    # === MEDIUM: simple function call wrapper ===
    if n_code <= 5 and re.search(r'call\s+\?', joined) and 'ret' in joined:
        func.category = "call_wrapper"
        func.difficulty = "MEDIUM"
        func.note = "wraps a call to another named function"
        return

    # === MEDIUM: FPU init/store (fld/fmul/fstp globals) ===
    if n_code <= 5 and re.search(r'f(ld|mul|add|sub|st)', joined) and 'call' not in joined:
        func.category = "fpu_init"
        func.difficulty = "MEDIUM"
        func.note = f"FPU operations ({n_code} instructions)"
        return

    # === MEDIUM: vtable call + push imm (with return value) ===
    if n_code <= 8 and re.search(r'mov\s+eax,\s*dword ptr \[ecx\]', joined) and 'push' in joined and re.search(r'call\s+dword ptr \[eax', joined):
        func.category = "vtable_call_with_args"
        func.difficulty = "MEDIUM"
        func.note = "vtable dispatch with pushed args"
        return

    # Count total asm lines for complexity estimate
    if n_code <= 10:
        func.category = "small_complex"
        func.difficulty = "MEDIUM"
        func.note = f"{n_code} asm lines"
    elif n_code <= 25:
        func.category = "medium_complex"
        func.difficulty = "MEDIUM-HIGH"
        func.note = f"{n_code} asm lines"
    elif n_code <= 50:
        func.category = "large_complex"
        func.difficulty = "HIGH"
        func.note = f"{n_code} asm lines"
    else:
        func.category = "very_large"
        func.difficulty = "VERY HIGH"
        func.note = f"{n_code} asm lines"


def main():
    src_dir = Path(__file__).parent.parent.parent / "src" / "c"

    all_functions: list[AsmFunction] = []
    for cfile in sorted(src_dir.glob("*.c")):
        all_functions.extend(extract_asm_functions(cfile))

    # Sort by difficulty
    difficulty_order = {"LOW": 0, "LOW-MEDIUM": 1, "MEDIUM": 2, "MEDIUM-HIGH": 3, "HIGH": 4, "VERY HIGH": 5, "unknown": 6}
    all_functions.sort(key=lambda f: (difficulty_order.get(f.difficulty, 6), f.file, f.line))

    # Count by asm type
    n_volatile = sum(1 for f in all_functions if f.asm_type == "volatile")
    n_individual = sum(1 for f in all_functions if f.asm_type == "individual")

    # Print summary
    by_difficulty: dict[str, list[AsmFunction]] = {}
    for func in all_functions:
        by_difficulty.setdefault(func.difficulty, []).append(func)

    print("=" * 80)
    print(f"ASM Function Classification — {len(all_functions)} functions total")
    print(f"  asm volatile: {n_volatile}  |  individual asm: {n_individual}")
    print("=" * 80)

    for diff in ["LOW", "LOW-MEDIUM", "MEDIUM", "MEDIUM-HIGH", "HIGH", "VERY HIGH", "unknown"]:
        funcs = by_difficulty.get(diff, [])
        if not funcs:
            continue
        print(f"\n{'─' * 80}")
        print(f"  {diff} ({len(funcs)} functions)")
        print(f"{'─' * 80}")

        by_category: dict[str, list[AsmFunction]] = {}
        for f in funcs:
            by_category.setdefault(f.category, []).append(f)

        for cat, cat_funcs in sorted(by_category.items()):
            print(f"\n  [{cat}] ({len(cat_funcs)})")
            for f in cat_funcs:
                short_name = f.name.split('__')[0] if '__' in f.name else f.name
                tag = "V" if f.asm_type == "volatile" else "I"
                print(f"    [{tag}] {f.file}:{f.line:<5}  {short_name:<43}  {f.note}")

    # Print actionable summary
    print(f"\n{'=' * 80}")
    print("SUMMARY — Ready to decompile")
    print(f"{'=' * 80}")
    low = len(by_difficulty.get("LOW", []))
    low_med = len(by_difficulty.get("LOW-MEDIUM", []))
    med = len(by_difficulty.get("MEDIUM", []))
    rest = len(all_functions) - low - low_med - med
    print(f"  LOW:         {low:>4}  (field getters, return constants, return this)")
    print(f"  LOW-MEDIUM:  {low_med:>4}  (vtable dispatch, neg/sbb patterns)")
    print(f"  MEDIUM:      {med:>4}  (bitfields, struct copy, FPU, call wrappers)")
    print(f"  HIGH+:       {rest:>4}  (complex logic, large functions)")
    print(f"  TOTAL:       {len(all_functions):>4}")
    print(f"\n  asm volatile: {n_volatile}  |  individual asm: {n_individual}")


if __name__ == "__main__":
    main()

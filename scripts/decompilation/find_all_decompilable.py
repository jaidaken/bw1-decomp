#!/usr/bin/env python3
"""Find all remaining asm functions that match confirmed-working decompilation patterns."""

import re
import os
import sys
from pathlib import Path

# Patterns that are confirmed to produce byte-identical code
PATTERNS = {
    "field_getter": {
        "desc": "mov eax, [ecx+N]; ret",
        "regex": r"^8b[4-7]1[0-9a-f]{2}c3$",  # mov eax,[ecx+disp8]; ret
    },
    "field_getter_disp32": {
        "desc": "mov eax, [ecx+N]; ret (32-bit disp)",
        "regex": r"^8b81[0-9a-f]{8}c3$",  # mov eax,[ecx+disp32]; ret
    },
    "double_deref": {
        "desc": "mov eax, [ecx+A]; mov eax, [eax+B]; ret",
        "regex": r"^8b[4-7]1[0-9a-f]{2}8b[48]0[0-9a-f]{2,8}c3$",
    },
    "info_float_getter": {
        "desc": "mov eax, [ecx+0x28]; fld [eax+N]; ret",
        "regex": r"^8b4128d9[48]0[0-9a-f]{2,8}c3$",
    },
    "info_addr_getter": {
        "desc": "mov eax, [ecx+0x28]; add eax, N; ret",
        "regex": r"^8b412805[0-9a-f]{8}c3$",
    },
    "lea_addr_getter": {
        "desc": "lea eax, [ecx+N]; ret",
        "regex": r"^8d[4-7]1[0-9a-f]{2}c3$",
    },
    "field_setter": {
        "desc": "mov eax, [esp+4]; mov [ecx+N], eax; ret 4",
        "regex": r"^8b4424048941[0-9a-f]{2}c20400$",
    },
    "field_setter_disp32": {
        "desc": "mov eax, [esp+4]; mov [ecx+N], eax; ret 4",
        "regex": r"^8b44240489[89]1[0-9a-f]{8}c20400$",
    },
    "array_getter": {
        "desc": "mov eax, [esp+4]; mov eax, [ecx+eax*4+N]; ret 4",
        "regex": r"^8b4424048b[48][48]81[0-9a-f]{8}c20400$",
    },
    "set_null_ret1": {
        "desc": "mov [ecx+N], 0; mov eax, 1; ret",
        "regex": r"^c7[4-7]1[0-9a-f]{2}00000000b801000000c3$",
    },
    "return_true_bool": {
        "desc": "mov al, 1; ret",
        "regex": r"^b001c3$",
    },
    "jmp_thunk": {
        "desc": "jmp target",
        "regex": r"^e9[0-9a-f]{8}$",
    },
    "call_field_access": {
        "desc": "call func; mov eax, [eax+N]; ret",
        "regex": r"^e8[0-9a-f]{8}8b[48]0[0-9a-f]{2,8}c3$",
    },
}


def parse_asm_functions(filepath):
    """Parse a .c file and extract asm-only functions with their byte sequences."""
    with open(filepath) as f:
        lines = f.readlines()

    functions = []
    i = 0
    while i < len(lines):
        # Look for function definitions
        line = lines[i]
        # Match function definition patterns
        func_match = re.match(
            r'^(?:__attribute__\(\([^)]+\)\)\s*)?'
            r'(?:(?:extern|static)\s+)?'
            r'(?:\w+\s+)+?'
            r'(?:__fastcall|__cdecl|__stdcall)\s+'
            r'(\w+)\s*\(',
            line
        )
        if func_match:
            func_name = func_match.group(1)
            func_line = i + 1

            # Find the opening brace
            brace_line = i
            while brace_line < len(lines) and '{' not in lines[brace_line]:
                brace_line += 1
            if brace_line >= len(lines):
                i += 1
                continue

            # Collect all asm bytes until closing brace
            j = brace_line + 1
            asm_bytes = []
            has_c_code = False
            has_asm = False
            ret_found = False

            while j < len(lines):
                l = lines[j].strip()
                if l == '}':
                    break
                if l.startswith('asm(') or l.startswith('__asm__(') or l.startswith('"'):
                    has_asm = True
                    # Extract bytes from comment: // 0xADDR    HEXBYTES
                    byte_match = re.search(r'//\s*0x[0-9a-f]+\s+([0-9a-f]+)', l)
                    if byte_match:
                        hex_bytes = byte_match.group(1)
                        if not ret_found:
                            asm_bytes.append(hex_bytes)
                            # Check if this is a ret instruction
                            if hex_bytes.startswith('c3') or hex_bytes.startswith('c2'):
                                ret_found = True
                        # After ret, these are trailing padding - DON'T include
                elif l and not l.startswith('//') and not l.startswith('__builtin_unreachable'):
                    if l not in ('', ';'):
                        has_c_code = True
                j += 1

            if has_asm and not has_c_code and asm_bytes:
                full_hex = ''.join(asm_bytes)
                functions.append({
                    'name': func_name,
                    'line': func_line,
                    'hex': full_hex,
                    'num_asm': len(asm_bytes),
                })
        i += 1
    return functions


def check_jmp_target_same_file(filepath, func_hex):
    """Check if a jmp target function is defined in the same file."""
    if not func_hex.startswith('e9'):
        return False
    # The jmp target is a relative offset - can't easily determine from hex alone
    # Instead, check if the function referenced in asm is defined in this file
    with open(filepath) as f:
        content = f.read()
    # Find the jmp asm line
    jmp_match = re.search(r'asm\(".*jmp\s+\?(\w+)@(\w+)', content)
    if jmp_match:
        func = jmp_match.group(1)
        cls = jmp_match.group(2)
        # Check if this function is defined in the same file
        # Look for Mac-mangled name pattern
        pattern = f'{func}__'
        return pattern in content and content.count(pattern) > 1  # >1 means definition exists
    return False


def main():
    src_dir = Path('src/c')
    if not src_dir.exists():
        src_dir = Path('/home/jaidaken/bw1-decomp/src/c')

    results = {}
    total_matched = 0
    jmp_same_file = 0
    jmp_diff_file = 0

    for cfile in sorted(src_dir.glob('*.c')):
        functions = parse_asm_functions(cfile)
        for func in functions:
            hex_str = func['hex']
            for pat_name, pat_info in PATTERNS.items():
                if re.match(pat_info['regex'], hex_str):
                    rel_path = str(cfile.relative_to(src_dir.parent.parent))
                    if pat_name == 'jmp_thunk':
                        same_file = check_jmp_target_same_file(str(cfile), hex_str)
                        if same_file:
                            jmp_same_file += 1
                            status = "SAME_FILE (blocked)"
                        else:
                            jmp_diff_file += 1
                            status = "DIFF_FILE (can decompile)"
                    else:
                        status = "can decompile"

                    if pat_name not in results:
                        results[pat_name] = []
                    results[pat_name].append({
                        **func,
                        'file': rel_path,
                        'status': status,
                    })
                    total_matched += 1
                    break

    print("=" * 80)
    print("DECOMPILABLE FUNCTIONS FOUND")
    print("=" * 80)

    decompilable = 0
    for pat_name, funcs in sorted(results.items()):
        pat_desc = PATTERNS[pat_name]['desc']
        decompilable_funcs = [f for f in funcs if 'blocked' not in f['status']]
        blocked_funcs = [f for f in funcs if 'blocked' in f['status']]

        if decompilable_funcs:
            print(f"\n--- {pat_name}: {pat_desc} ({len(decompilable_funcs)} decompilable) ---")
            for f in decompilable_funcs:
                print(f"  {f['file']}:{f['line']}  {f['name']}  [{f['hex'][:30]}...]")
                decompilable += 1

        if blocked_funcs:
            print(f"\n--- {pat_name}: {pat_desc} ({len(blocked_funcs)} blocked - same file) ---")
            for f in blocked_funcs:
                print(f"  {f['file']}:{f['line']}  {f['name']}  [SAME FILE]")

    print(f"\n{'=' * 80}")
    print(f"TOTAL: {total_matched} matched, {decompilable} decompilable, {total_matched - decompilable} blocked")
    print(f"JMP thunks: {jmp_diff_file} cross-file (decompilable), {jmp_same_file} same-file (blocked)")


if __name__ == '__main__':
    main()

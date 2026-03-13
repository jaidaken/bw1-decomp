#!/usr/bin/env python3
"""Find asm functions with no trailing padding after ret - candidates for decompilation."""

import re
import sys
from pathlib import Path


def parse_asm_functions(filepath):
    """Parse a .c file and extract asm-only functions with instruction details."""
    with open(filepath) as f:
        lines = f.readlines()

    functions = []
    i = 0
    while i < len(lines):
        line = lines[i]
        # Match function definition
        func_match = re.match(
            r'^(?:__attribute__\(\([^)]+\)\)\s*)?'
            r'(?:(?:extern|static)\s+)?'
            r'(?:[\w\s*]+?\s+)?'
            r'(?:__fastcall|__cdecl|__stdcall)\s+'
            r'(\w+)\s*\(',
            line
        )
        if func_match:
            func_name = func_match.group(1)
            func_line = i + 1

            # Find opening brace
            brace_line = i
            while brace_line < len(lines) and '{' not in lines[brace_line]:
                brace_line += 1
            if brace_line >= len(lines):
                i += 1
                continue

            # Collect asm lines
            j = brace_line + 1
            asm_lines = []
            has_c_code = False
            has_asm = False
            has_trailing_after_ret = False
            ret_found = False

            while j < len(lines):
                l = lines[j].strip()
                if l == '}':
                    break
                if l.startswith('asm(') or l.startswith('__asm__(') or l.startswith('"'):
                    has_asm = True
                    byte_match = re.search(r'//\s*0x[0-9a-f]+\s+([0-9a-f]+)', l)
                    # Extract instruction mnemonic
                    instr_match = re.search(r'asm\("([^"]+)"\)|__asm__\("([^"]+)"\)', l)
                    instr = (instr_match.group(1) or instr_match.group(2)).strip() if instr_match else ""
                    # Remove labels
                    if instr.endswith(':'):
                        j += 1
                        continue

                    if ret_found:
                        if byte_match:
                            has_trailing_after_ret = True
                    else:
                        if byte_match:
                            hex_bytes = byte_match.group(1)
                            asm_lines.append({
                                'hex': hex_bytes,
                                'instr': instr,
                                'line': j + 1,
                            })
                            if hex_bytes.startswith('c3') or hex_bytes.startswith('c2'):
                                ret_found = True
                elif l and not l.startswith('//') and not l.startswith('__builtin_unreachable'):
                    if l not in ('', ';'):
                        has_c_code = True
                j += 1

            if has_asm and not has_c_code and asm_lines and ret_found:
                full_hex = ''.join(a['hex'] for a in asm_lines)
                functions.append({
                    'name': func_name,
                    'line': func_line,
                    'hex': full_hex,
                    'asm_lines': asm_lines,
                    'num_asm': len(asm_lines),
                    'has_trailing': has_trailing_after_ret,
                    'func_sig': line.strip(),
                })
        i += 1
    return functions


def classify_instructions(asm_lines):
    """Classify the instruction sequence to determine if it's potentially decompilable."""
    instrs = [a['instr'] for a in asm_lines]
    hexes = [a['hex'] for a in asm_lines]

    # Check for known blocked instruction patterns
    blocked_reasons = []

    for idx, (instr, hx) in enumerate(zip(instrs, hexes)):
        clean = re.sub(r'\{[^}]+\}\s*', '', instr).strip()

        # Blocked: movzx (indicates bitfield/byte load that clang won't match)
        if clean.startswith('movzx'):
            blocked_reasons.append(f"movzx at line {asm_lines[idx]['line']}")

        # Blocked: vtable call (mov eax,[ecx]; call [eax+N] or jmp [eax+N])
        if re.match(r'(call|jmp)\s+dword ptr \[eax', clean):
            blocked_reasons.append(f"vtable dispatch at line {asm_lines[idx]['line']}")
        if re.match(r'(call|jmp)\s+dword ptr \[edx', clean):
            blocked_reasons.append(f"vtable dispatch at line {asm_lines[idx]['line']}")

        # Blocked: fld from rdata (float constant)
        if 'fld' in clean and 'rdata' in clean:
            blocked_reasons.append(f"float constant at line {asm_lines[idx]['line']}")

        # Blocked: fldz or fld1
        if clean in ('fldz', 'fld1'):
            blocked_reasons.append(f"float constant {clean} at line {asm_lines[idx]['line']}")

        # Blocked: mov al, [data_bytes] (byte from global)
        if hx.startswith('a0') and 'data_bytes' in instr:
            blocked_reasons.append(f"byte global load at line {asm_lines[idx]['line']}")

        # Blocked: inc/dec byte
        if re.match(r'(inc|dec)\s+byte ptr', clean):
            blocked_reasons.append(f"inc/dec byte at line {asm_lines[idx]['line']}")

        # Blocked: string address (mov eax, offset or mov eax, OFFSET)
        if hx.startswith('b8') and ('offset' in instr.lower() or 's_' in instr):
            blocked_reasons.append(f"string address at line {asm_lines[idx]['line']}")

    return blocked_reasons


def main():
    src_dir = Path('src/c')
    if not src_dir.exists():
        src_dir = Path('/home/jaidaken/bw1-decomp/src/c')

    no_padding = []
    with_padding = []
    total_asm = 0

    for cfile in sorted(src_dir.glob('*.c')):
        functions = parse_asm_functions(cfile)
        for func in functions:
            total_asm += 1
            rel_path = str(cfile.relative_to(src_dir.parent.parent))
            func['file'] = rel_path

            if not func['has_trailing']:
                blocked = classify_instructions(func['asm_lines'])
                func['blocked_reasons'] = blocked
                no_padding.append(func)
            else:
                with_padding.append(func)

    # Print results
    print("=" * 80)
    print(f"ASM FUNCTIONS WITHOUT TRAILING PADDING ({len(no_padding)} of {total_asm} total)")
    print("=" * 80)

    # Group by complexity
    decompilable = [f for f in no_padding if not f['blocked_reasons']]
    blocked = [f for f in no_padding if f['blocked_reasons']]

    print(f"\n--- POTENTIALLY DECOMPILABLE ({len(decompilable)}) ---")
    for f in sorted(decompilable, key=lambda x: x['num_asm']):
        instrs = ' | '.join(a['instr'][:40] for a in f['asm_lines'])
        print(f"\n  {f['file']}:{f['line']}  {f['name']}  ({f['num_asm']} asm lines)")
        print(f"    Hex: {f['hex'][:60]}")
        for a in f['asm_lines']:
            clean = re.sub(r'\{[^}]+\}\s*', '', a['instr']).strip()
            print(f"      {clean}")

    print(f"\n--- BLOCKED (no trailing but has blocked patterns: {len(blocked)}) ---")
    for f in sorted(blocked, key=lambda x: x['num_asm']):
        reasons = ', '.join(f['blocked_reasons'])
        print(f"  {f['file']}:{f['line']}  {f['name']}  ({f['num_asm']} asm)  [{reasons}]")

    print(f"\n--- WITH TRAILING PADDING ({len(with_padding)} functions) ---")
    print(f"  (not shown, these have junk after ret)")

    print(f"\n{'=' * 80}")
    print(f"SUMMARY: {total_asm} asm functions total")
    print(f"  No trailing padding: {len(no_padding)}")
    print(f"    Potentially decompilable: {len(decompilable)}")
    print(f"    Blocked by instruction patterns: {len(blocked)}")
    print(f"  With trailing padding: {len(with_padding)}")


if __name__ == '__main__':
    main()

#!/usr/bin/env python3
"""Analyze all scalar deleting destructor (??_G) functions in asm files.

Parses ??_G functions from src/asm/unprocessed/ and classifies them by pattern variant.
Outputs a summary and full JSON listing.
"""

import json
import re
import sys
from collections import Counter
from pathlib import Path

ASM_DIR = Path(__file__).resolve().parent.parent.parent / "src" / "asm" / "unprocessed"

# Match ??_G function labels - the mangled form of scalar deleting destructors
# Pattern: ??_G<class>@@UAEPAXI@Z: or ??G<class>@@UAE@XZ: (malformed)
SDTOR_LABEL_RE = re.compile(r'^(\?\?_?G[^:]+@@(?:UAEPAXI|UAE)@[A-Z]?Z):$')

# Instruction line pattern: leading whitespace, optional {disp} prefix, mnemonic, operands, // comment
# Also handles .Lbl_addr_ labels with instruction on same line
INSTR_RE = re.compile(
    r'^\s+(?:\{[^}]+\}\s+)?'    # optional {disp8}/{disp32}
    r'(\S+)'                     # mnemonic (possibly with .s suffix)
    r'(?:\s+(.*?))?'             # optional operands
    r'(?:\s*//.*)?$'             # optional trailing comment
)

LBL_INSTR_RE = re.compile(
    r'^\.Lbl_addr_\w+:\s+'       # .Lbl_addr_ label prefix
    r'(?:\{[^}]+\}\s+)?'         # optional {disp}
    r'(\S+)'                     # mnemonic
    r'(?:\s+(.*?))?'             # optional operands
    r'(?:\s*//.*)?$'             # optional comment
)


def parse_instruction(line):
    """Parse a single asm line into (mnemonic, operands) or None.

    Handles both regular instructions and .Lbl_addr_ prefixed instructions.
    """
    stripped = line.strip()
    if not stripped:
        return None

    # Try .Lbl_addr_ line first
    m = LBL_INSTR_RE.match(stripped)
    if m:
        mnemonic = m.group(1)
        operands = (m.group(2) or '').strip()
        if mnemonic.endswith('.s'):
            mnemonic = mnemonic[:-2]
        return mnemonic, operands

    # Regular instruction line
    m = INSTR_RE.match(line)
    if m:
        mnemonic = m.group(1)
        operands = (m.group(2) or '').strip()
        if mnemonic.endswith('.s'):
            mnemonic = mnemonic[:-2]
        return mnemonic, operands

    return None


def extract_class_name(symbol):
    """Extract class name from ??_G<class>@@UAEPAXI@Z or ??G<class>@@UAE@XZ."""
    m = re.match(r'\?\?_G(.+?)@@UAEPAXI@Z', symbol)
    if m:
        return m.group(1)
    m = re.match(r'\?\?G(.+?)@@UAE@XZ', symbol)
    if m:
        return m.group(1)
    return symbol


def extract_sdtor_functions(filepath):
    """Extract all ??_G function bodies from an asm file.

    Returns list of (symbol, instructions) tuples where instructions is a list
    of (mnemonic, operands) tuples, stopping at `ret 0x0004`.
    """
    results = []
    with open(filepath, 'r') as f:
        all_lines = f.readlines()

    i = 0
    while i < len(all_lines):
        line = all_lines[i].rstrip('\n')
        m = SDTOR_LABEL_RE.match(line)
        if m:
            symbol = m.group(1)
            instructions = []
            i += 1
            found_ret = False
            while i < len(all_lines):
                bline = all_lines[i].rstrip('\n')
                parsed = parse_instruction(bline)
                if parsed:
                    mnemonic, operands = parsed
                    if mnemonic != 'nop':
                        instructions.append((mnemonic, operands))
                    # Stop after ret 0x0004 (the canonical end of a sdtor)
                    if mnemonic == 'ret' and '0x0004' in operands:
                        found_ret = True
                        i += 1
                        break
                else:
                    # Non-instruction, non-blank line = label = function boundary
                    stripped = bline.strip()
                    if stripped and not stripped.startswith('.Lbl_addr_'):
                        break
                i += 1
            results.append((symbol, instructions))
        else:
            i += 1

    return results


def analyze_sdtor(symbol, instructions):
    """Analyze a single scalar deleting destructor function.

    Returns a dict with extracted properties.
    """
    class_name = extract_class_name(symbol)
    info = {
        'symbol': symbol,
        'class_name': class_name,
        'has_vtable_write': False,
        'vtable_address': None,
        'destructor_call': None,
        'op_delete_call': None,
        'op_delete_args': 0,
        'delete_size_hex': None,
        'has_push_ecx': False,
        'variant': 'unknown',
        'num_calls': 0,
    }

    if not instructions:
        info['variant'] = 'empty'
        return info

    # Collect structured data from the instruction stream
    calls = []         # (index, target)
    pushes = []        # (index, operand)
    add_esps = []      # (index, value)
    vtable_write = None  # (index, address)

    for idx, (mnemonic, operands) in enumerate(instructions):
        if mnemonic == 'call':
            calls.append((idx, operands.strip()))
        elif mnemonic == 'push':
            pushes.append((idx, operands.strip()))
        elif mnemonic == 'add' and operands.startswith('esp'):
            m = re.search(r'0x([0-9a-fA-F]+)', operands)
            if m:
                add_esps.append((idx, int(m.group(1), 16)))
        elif mnemonic == 'mov':
            # Vtable write: mov dword ptr [esi], 0xNNNNNNNN
            m = re.match(r'dword ptr \[esi\],\s*0x([0-9a-fA-F]+)', operands)
            if m:
                vtable_write = (idx, '0x' + m.group(1))

    info['num_calls'] = len(calls)

    # Check for push ecx preamble (extra stack frame, like UR_Explosion)
    if instructions[0][0] == 'push' and instructions[0][1] == 'ecx':
        info['has_push_ecx'] = True

    # Handle vtable write
    if vtable_write is not None:
        info['has_vtable_write'] = True
        info['vtable_address'] = vtable_write[1]

    # Standard pattern has exactly 2 calls: destructor + operator delete
    # Some have only 1 call (destructor only, no delete - shouldn't happen for sdtors)
    # Complex ones have 3+ calls (pre-cleanup + destructor + delete)

    if len(calls) == 0:
        info['variant'] = 'no_calls'
        return info

    if len(calls) == 1:
        # Only one call. This could be:
        # 1. A trivial destructor sdtor: no dtor call, the single call is operator delete
        #    Pattern: test / push esi / mov esi,ecx / vtable_write / je / push esi / call delete
        # 2. A dtor-only sdtor (no delete at all, unlikely)
        # Check if there's a test instruction BEFORE the call - if so, the call is the delete
        call_idx = calls[0][0]
        has_test_before = any(
            mnemonic == 'test' and idx < call_idx
            for idx, (mnemonic, _) in enumerate(instructions)
        )
        if has_test_before:
            # The single call is operator delete (trivial/no destructor)
            info['destructor_call'] = None
            info['op_delete_call'] = calls[0][1]
            # Determine args from add esp
            for add_idx, add_val in add_esps:
                if add_idx > call_idx:
                    if add_val == 8:
                        info['op_delete_args'] = 2
                    elif add_val == 4:
                        info['op_delete_args'] = 1
                    break
            has_vt = info['has_vtable_write']
            args = info['op_delete_args']
            if has_vt:
                info['variant'] = f'no_dtor_vtable_write_{args}arg'
            else:
                info['variant'] = f'no_dtor_{args}arg'
        else:
            info['destructor_call'] = calls[0][1]
            info['variant'] = 'dtor_only'
        return info

    # For 2 calls: standard pattern
    # call[0] = destructor, call[1] = operator delete
    # For 3+ calls with vtable write:
    #   The vtable write appears before a destructor call
    #   There might be cleanup calls before the main destructor
    # For 3+ calls with push ecx (UR_Explosion):
    #   Extra cleanup code, then destructor, then delete

    if len(calls) == 2:
        dtor_call = calls[0][1]
        delete_call = calls[1][1]
    else:
        # 3+ calls: identify destructor and delete
        # The delete call is always the LAST call
        # The destructor call is the one just before the test/je pattern
        # Find the 'test' instruction to locate the boundary
        test_idx = None
        for idx, (mnemonic, operands) in enumerate(instructions):
            if mnemonic == 'test' and 'byte ptr' in operands and '0x01' in operands:
                test_idx = idx
                break

        if test_idx is not None:
            # The destructor call is the last call before the test
            dtor_call = None
            for cidx, ctarget in reversed(calls):
                if cidx < test_idx:
                    dtor_call = ctarget
                    break
            # The delete call is the first call after the test
            delete_call = None
            for cidx, ctarget in calls:
                if cidx > test_idx:
                    delete_call = ctarget
                    break
            if dtor_call is None:
                dtor_call = calls[0][1]
            if delete_call is None:
                delete_call = calls[-1][1]
        else:
            # Fallback: first call is dtor, last is delete
            dtor_call = calls[0][1]
            delete_call = calls[-1][1]

    info['destructor_call'] = dtor_call
    info['op_delete_call'] = delete_call

    # Find the delete call index
    delete_call_idx = None
    for cidx, ctarget in calls:
        if ctarget == delete_call:
            delete_call_idx = cidx

    # Determine operator delete arg count from add esp after delete call
    if delete_call_idx is not None:
        for add_idx, add_val in add_esps:
            if add_idx > delete_call_idx:
                if add_val == 8:
                    info['op_delete_args'] = 2
                elif add_val == 4:
                    info['op_delete_args'] = 1
                break

    # Extract size pushed for 2-arg operator delete
    if info['op_delete_args'] == 2 and delete_call_idx is not None:
        # Pattern: push SIZE; push esi; call delete
        # Find the push before the delete call that's not 'push esi'
        for pidx, pval in reversed(pushes):
            if pidx < delete_call_idx and pval not in ('esi', 'ecx', 'eax'):
                info['delete_size_hex'] = pval
                break

    # Check if there are extra calls before the destructor (cleanup code)
    has_extra_calls = False
    if len(calls) >= 3:
        # Count calls before the destructor
        dtor_call_idx = None
        for cidx, ctarget in calls:
            if ctarget == dtor_call:
                dtor_call_idx = cidx
                break
        if dtor_call_idx is not None:
            extra_calls = [c for c in calls if c[0] < dtor_call_idx]
            if extra_calls:
                has_extra_calls = True

    # Classify variant
    has_vt = info['has_vtable_write']
    args = info['op_delete_args']

    if has_extra_calls:
        if has_vt:
            info['variant'] = 'complex_vtable_write'
        else:
            info['variant'] = 'complex'
    elif has_vt and args == 2:
        info['variant'] = 'vtable_write_2arg'
    elif has_vt and args == 1:
        info['variant'] = 'vtable_write_1arg'
    elif has_vt:
        info['variant'] = 'vtable_write_unknown_args'
    elif args == 2:
        info['variant'] = 'standard_2arg'
    elif args == 1:
        info['variant'] = 'standard_1arg'
    else:
        info['variant'] = 'unknown'

    return info


def main():
    asm_files = sorted(ASM_DIR.glob('runblack.reassemble.*.asm'))

    all_results = []
    files_with_sdtors = 0

    for asm_file in asm_files:
        functions = extract_sdtor_functions(asm_file)
        if functions:
            files_with_sdtors += 1
            for symbol, instructions in functions:
                result = analyze_sdtor(symbol, instructions)
                result['asm_file'] = asm_file.name
                all_results.append(result)

    # Summary
    print(f"{'='*80}")
    print(f"Scalar Deleting Destructor (??_G) Analysis")
    print(f"{'='*80}")
    print(f"Total ??_G functions found: {len(all_results)}")
    print(f"Across {files_with_sdtors} asm files")
    print()

    # Variant classification
    variant_counts = Counter(r['variant'] for r in all_results)
    print(f"{'='*80}")
    print(f"Variant Classification")
    print(f"{'='*80}")
    for variant, count in variant_counts.most_common():
        pct = 100.0 * count / len(all_results)
        print(f"  {variant:30s} {count:4d}  ({pct:5.1f}%)")
    print()

    # Operator delete symbols used
    delete_syms = Counter(r['op_delete_call'] for r in all_results if r['op_delete_call'])
    print(f"{'='*80}")
    print(f"Operator Delete Symbols")
    print(f"{'='*80}")
    for sym, count in delete_syms.most_common():
        print(f"  {sym:50s} {count:4d}")
    print()

    # Size distribution for 2-arg deletes
    sizes_2arg = Counter(r['delete_size_hex'] for r in all_results if r['op_delete_args'] == 2)
    print(f"{'='*80}")
    print(f"Size Distribution (2-arg operator delete)")
    print(f"{'='*80}")
    print(f"Total 2-arg functions: {sum(sizes_2arg.values())}")
    print(f"Distinct sizes: {len(sizes_2arg)}")
    print()
    print(f"  Top 20 sizes:")
    for size, count in sizes_2arg.most_common(20):
        print(f"    {size:20s} {count:4d}")
    if len(sizes_2arg) > 20:
        print(f"    ... and {len(sizes_2arg) - 20} more distinct sizes")
    print()

    # Destructor call targets
    dtor_syms = Counter(r['destructor_call'] for r in all_results if r['destructor_call'])
    print(f"{'='*80}")
    print(f"Destructor Call Targets")
    print(f"{'='*80}")
    print(f"Total distinct destructor targets: {len(dtor_syms)}")
    print(f"  Top 20 most-reused destructors:")
    for sym, count in dtor_syms.most_common(20):
        print(f"    {sym:60s} {count:4d}")
    print()

    # Vtable write analysis
    vtable_funcs = [r for r in all_results if r['has_vtable_write']]
    print(f"{'='*80}")
    print(f"Vtable Write Analysis")
    print(f"{'='*80}")
    print(f"Functions with vtable write: {len(vtable_funcs)}")
    vtable_addrs = Counter(r['vtable_address'] for r in vtable_funcs)
    print(f"Distinct vtable addresses: {len(vtable_addrs)}")
    if vtable_funcs:
        print(f"\n  All vtable-writing ??_G functions:")
        for r in vtable_funcs:
            print(f"    {r['class_name']:50s} vtable={r['vtable_address']}  dtor={r['destructor_call']}")
    print()

    # Complex variants
    complex_funcs = [r for r in all_results if r['variant'].startswith('complex')]
    print(f"{'='*80}")
    print(f"Complex Variants (extra pre-destruction code)")
    print(f"{'='*80}")
    print(f"Total: {len(complex_funcs)}")
    for r in complex_funcs:
        extra = f" vtable={r['vtable_address']}" if r['has_vtable_write'] else ""
        print(f"  {r['class_name']:50s} dtor={r['destructor_call']}{extra}  [{r['asm_file']}]")
    print()

    # 1-arg operator delete functions
    onearg_funcs = [r for r in all_results if r['op_delete_args'] == 1]
    print(f"{'='*80}")
    print(f"1-arg Operator Delete Functions")
    print(f"{'='*80}")
    print(f"Total: {len(onearg_funcs)}")
    for r in onearg_funcs:
        print(f"  {r['class_name']:50s} delete={r['op_delete_call']}  [{r['asm_file']}]")
    print()

    # Unknown/unclassified variants
    unknown_funcs = [r for r in all_results if r['variant'] == 'unknown']
    if unknown_funcs:
        print(f"{'='*80}")
        print(f"Unknown/Unclassified Variants")
        print(f"{'='*80}")
        print(f"Total: {len(unknown_funcs)}")
        for r in unknown_funcs:
            print(f"  {r['symbol']:60s} calls={r['num_calls']}  [{r['asm_file']}]")
        print()

    # Write full JSON output
    json_path = Path(__file__).resolve().parent / "sdtor_analysis.json"
    with open(json_path, 'w') as f:
        json.dump(all_results, f, indent=2)
    print(f"Full JSON output written to: {json_path}")

    return all_results


if __name__ == '__main__':
    main()

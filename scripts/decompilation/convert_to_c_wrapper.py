#!/usr/bin/env python3
"""Automatically convert ret-in-asm functions to C-wrapper form.

Transforms functions from:
    type func(this) {
        asm volatile ("...code...\n\tret" ::: "eax", "ecx", "edx", "memory");
        __builtin_unreachable();
    }
To:
    type func(this) {
        type result;
        asm volatile ("...code..." : "=a"(result) : "c"(this) : "edx", "memory");
        return result;
    }
"""

import re
import sys
from pathlib import Path
from dataclasses import dataclass


@dataclass
class FuncInfo:
    file: str
    name: str
    start: int  # char offset in file
    end: int    # char offset in file (after closing brace)
    body: str
    return_type: str
    return_register: str  # "eax", "st0", "void"
    ecx_modified: bool
    has_ecx_save: bool  # push esi; mov esi, ecx pattern
    calling_conv: str  # "__fastcall" or "__cdecl"


def normalize_asm(line: str) -> str:
    line = re.sub(r'%?\{disp\d+%?\}\s*', '', line)
    line = re.sub(r'\s+', ' ', line).strip()
    return line


def extract_asm_volatile_block(body: str, start_pos: int = 0):
    """Extract asm volatile block content using balanced paren matching.
    Returns (content, start, end) or None if not found.
    """
    idx = body.find('asm volatile', start_pos)
    if idx == -1:
        idx = body.find('asm\tvolatile', start_pos)
    if idx == -1:
        return None

    # Find the opening paren
    paren_start = body.find('(', idx)
    if paren_start == -1:
        return None

    # Match balanced parens, respecting string literals
    depth = 0
    pos = paren_start
    in_string = False
    while pos < len(body):
        ch = body[pos]
        if ch == '"' and (pos == 0 or body[pos - 1] != '\\'):
            in_string = not in_string
        elif not in_string:
            if ch == '(':
                depth += 1
            elif ch == ')':
                depth -= 1
                if depth == 0:
                    content = body[paren_start + 1:pos]
                    return content, paren_start, pos
        pos += 1
    return None


def extract_volatile_instructions(body: str) -> list[str]:
    instructions = []
    result = extract_asm_volatile_block(body)
    if result is None:
        return instructions
    block, _, _ = result

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
    result = extract_asm_volatile_block(body)
    if result is None:
        return False
    block, _, _ = result
    return '"=a"' in block or '"=t"' in block or '"=c"' in block


def check_ecx_modified(instructions: list[str]) -> bool:
    """Check if ecx is modified in the instruction list (excluding mov esi, ecx save)."""
    for inst in instructions:
        norm = inst.lower().strip()
        if re.match(r'xor\.?s?\s+ecx,\s*ecx', norm):
            return True
        if re.match(r'mov\.?s?\s+ecx,', norm) and 'mov.s esi, ecx' not in inst and 'mov esi, ecx' not in inst:
            return True
    return False


def find_functions(filepath: Path, text: str) -> list[FuncInfo]:
    func_pattern = re.compile(
        r'^(?:__attribute__\(\([^)]*\)\)\s*\n)?'
        r'(\S.*?)\s+(__fastcall|__cdecl)\s+(\w+)\s*\(([^)]*)\)\s*\n\{',
        re.MULTILINE
    )

    results = []
    for match in func_pattern.finditer(text):
        return_type = match.group(1).strip()
        calling_conv = match.group(2)
        func_name = match.group(3)

        # Find closing brace
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
        func_end = pos + 1

        # Must have asm volatile + __builtin_unreachable (ret-in-asm form)
        if 'asm volatile' not in body or '__builtin_unreachable' not in body:
            continue

        # Skip if already converted
        if has_output_constraints(body):
            continue

        instructions = extract_volatile_instructions(body)
        if not instructions:
            continue

        # Find ret
        ret_idx = None
        for i, line in enumerate(instructions):
            if line.startswith('ret'):
                ret_idx = i
                break

        if ret_idx is None:
            continue

        # Check for ret N (stack cleanup)
        ret_line = instructions[ret_idx]
        has_ret_n = bool(re.match(r'ret\s+0x', ret_line))

        params = match.group(4)
        param_list = [p.strip() for p in params.split(',') if p.strip()]

        code = instructions[:ret_idx]

        # Check trailing (non-nop)
        trailing = instructions[ret_idx + 1:]
        if any(l.strip() != 'nop' for l in trailing):
            continue

        # Check blockers
        joined = ' '.join(code)
        if re.search(r'\[esp', joined):
            continue

        if has_ret_n:
            # ret N is allowed if the compiler will generate the same ret N
            # based on the calling convention and parameter count
            if calling_conv == '__fastcall':
                stack_params = max(0, len(param_list) - 2)
            else:
                stack_params = len(param_list)
            expected_ret = stack_params * 4
            ret_match = re.match(r'ret\s+(0x[0-9a-f]+)', ret_line)
            actual_ret = int(ret_match.group(1), 16) if ret_match else 0
            if actual_ret != expected_ret:
                continue  # ret N doesn't match expected stack cleanup
        elif calling_conv == '__fastcall' and len(param_list) > 2:
            continue  # Has stack params but no ret N — mismatch
        if re.search(r'jmp\s+dword ptr \[eax', joined):
            continue

        # Check for unconditional jmp (tail call) — but allow if conditional jumps
        # also present (means the jmp is a branch path, not a whole-function tail call)
        has_unconditional_jmp = any(
            l.startswith('jmp ') and 'dword ptr' not in l for l in code
        )
        has_conditional_jmp = any(
            re.match(r'j(e|ne|g|ge|l|le|a|ae|b|be|z|nz|s|ns|o|no|p|np)\s', l) for l in code
        )
        if has_unconditional_jmp and not has_conditional_jmp:
            continue

        # Check bool return
        if return_type.strip() == 'bool':
            continue

        # Determine return register
        clean_ret = return_type.strip()
        if clean_ret == 'void':
            return_register = "void"
        elif clean_ret in ('float', 'double'):
            # Float/double return — check FPU
            fpu_ops = [l for l in code if re.match(r'f(ld|add|sub|mul|div|comp|st|xch)', l)]
            if fpu_ops:
                last_fpu = fpu_ops[-1]
                if last_fpu.startswith('fstp') or last_fpu.startswith('fistp'):
                    return_register = "eax"  # FPU stored to memory, result in eax
                else:
                    return_register = "st0"
            else:
                return_register = "st0"  # float return, assume ST0
        else:
            # Integer/pointer/bool32_t return — always eax
            return_register = "eax"

        # Check ecx-save pattern
        has_ecx_save = False
        if len(code) >= 2:
            first_two = ' '.join(code[:2])
            if 'push esi' in first_two and re.search(r'mov\.?s?\s+esi,\s*ecx', first_two):
                has_ecx_save = True
            elif len(code) >= 3 and re.search(r'mov\.?s?\s+esi,\s*ecx', ' '.join(code[:3])):
                has_ecx_save = True

        ecx_modified = check_ecx_modified(code)

        results.append(FuncInfo(
            file=str(filepath),
            name=func_name,
            start=match.start(),
            end=func_end,
            body=body,
            return_type=return_type,
            return_register=return_register,
            ecx_modified=ecx_modified,
            has_ecx_save=has_ecx_save,
            calling_conv=calling_conv,
        ))

    return results


def transform_function(text: str, func: FuncInfo) -> str:
    """Transform a single function from ret-in-asm to C-wrapper form."""
    body = func.body

    # Find the asm volatile block with balanced parens
    result = extract_asm_volatile_block(body)
    if result is None:
        return None
    asm_content, paren_start, paren_end = result

    # Find the __builtin_unreachable after the asm volatile
    unreachable_match = re.search(r'\s*;\s*\n\s*__builtin_unreachable\(\);', body[paren_end:])
    if unreachable_match is None:
        return None

    # Find where the strings end and constraints begin
    triple_colon = asm_content.rfind(':::')
    if triple_colon == -1:
        return None
    strings_part = asm_content[:triple_colon]
    clobber_part = asm_content[triple_colon + 3:]

    # Extract quoted strings
    string_lines = re.findall(r'"([^"]*)"', strings_part)
    if not string_lines:
        return None

    # Join all strings
    full_asm = ''.join(string_lines)

    # Split into instruction lines (including labels)
    asm_lines = re.split(r'\\n\\t|\\n', full_asm)

    # Find ret index (in full list including labels)
    ret_idx = None
    for i, line in enumerate(asm_lines):
        stripped = normalize_asm(line)
        if stripped.startswith('ret'):
            ret_idx = i
            break

    if ret_idx is None:
        return None

    # Keep lines before ret
    asm_lines = asm_lines[:ret_idx]

    # Remove trailing empty lines
    while asm_lines and not asm_lines[-1].strip():
        asm_lines.pop()

    # Count original strings for formatting
    orig_strings = re.findall(r'"[^"]*"', strings_part)

    # Build output/input/clobber constraints
    orig_clobbers = re.findall(r'"(\w+)"', clobber_part)

    outputs = []
    inputs = []
    new_clobbers = []

    if func.return_register == "eax":
        outputs.append('"=a"(result)')
    elif func.return_register == "st0":
        outputs.append('"=t"(result)')

    is_fastcall = func.calling_conv == '__fastcall'
    has_ecx_clobber = 'ecx' in orig_clobbers

    # For __fastcall: ecx carries 'this', move from clobber to input/output
    # For __cdecl: leave ecx in clobbers as-is
    if is_fastcall and has_ecx_clobber:
        if func.ecx_modified:
            outputs.append('"=c"(dummy)')
        inputs.append('"c"(this)')

    # Build clobbers
    for c in orig_clobbers:
        if c == 'eax' and func.return_register == 'eax':
            continue  # now an output
        if c == 'ecx' and is_fastcall:
            continue  # now input/output
        new_clobbers.append(f'"{c}"')

    output_str = ', '.join(outputs) if outputs else ''
    input_str = ', '.join(inputs) if inputs else ''
    clobber_str = ', '.join(new_clobbers) if new_clobbers else ''

    constraint_str = f': {output_str} : {input_str} : {clobber_str}'

    # Build variable declarations
    decls = []
    if func.ecx_modified and is_fastcall:
        decls.append('    void* dummy;')

    if func.return_register in ("eax", "st0"):
        clean_type = func.return_type.strip()
        decls.append(f'    {clean_type} result;')

    decl_block = '\n'.join(decls)

    # Build return statement
    return_stmt = '    return result;' if func.return_register in ("eax", "st0") else ''

    # Reconstruct asm string
    if len(orig_strings) == 1:
        new_asm_text = '\\n\\t'.join(asm_lines)
        new_strings = f'"{new_asm_text}"'
        new_body_inner = f'asm volatile (\n        {new_strings}\n        {constraint_str}\n    )'
    else:
        new_lines = []
        for i, line in enumerate(asm_lines):
            if i < len(asm_lines) - 1:
                new_lines.append(f'        "{line}\\n\\t"')
            else:
                new_lines.append(f'        "{line}"')
        new_strings = '\n'.join(new_lines)
        new_body_inner = f'asm volatile (\n{new_strings}\n        {constraint_str}\n    )'

    # Build complete new body
    parts = ['{\n']
    if decl_block:
        parts.append(decl_block + '\n')
    parts.append(f'    {new_body_inner};\n')
    if return_stmt:
        parts.append(return_stmt + '\n')
    parts.append('}')

    return ''.join(parts)


def process_file(filepath: Path, dry_run: bool = False) -> list[str]:
    """Process a single file, converting all eligible functions."""
    text = filepath.read_text()
    funcs = find_functions(filepath, text)

    if not funcs:
        return []

    converted = []
    for func in reversed(funcs):
        new_body = transform_function(text, func)
        if new_body is None:
            continue

        old_body = func.body
        body_start = text.find(old_body, func.start)
        if body_start == -1:
            continue

        if dry_run:
            print(f"  Would convert: {func.name} ({func.return_register}, ecx_mod={func.ecx_modified}, conv={func.calling_conv})")
            converted.append(func.name)
            continue

        text = text[:body_start] + new_body + text[body_start + len(old_body):]
        converted.append(func.name)

    if not dry_run and converted:
        filepath.write_text(text)

    return list(reversed(converted))


def main():
    src_dir = Path(__file__).parent.parent.parent / "src" / "c"

    dry_run = '--dry-run' in sys.argv
    single_file = None
    for arg in sys.argv[1:]:
        if arg != '--dry-run' and not arg.startswith('-'):
            single_file = arg

    if single_file:
        files = [Path(single_file)]
    else:
        files = sorted(src_dir.glob("*.c"))

    total = 0
    for filepath in files:
        converted = process_file(filepath, dry_run=dry_run)
        if converted:
            for name in converted:
                print(f"  {'[DRY] ' if dry_run else ''}Converted: {filepath.name}::{name}")
            total += len(converted)

    print(f"\n{'Would convert' if dry_run else 'Converted'}: {total} functions")


if __name__ == "__main__":
    main()

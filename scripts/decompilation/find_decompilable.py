#!/usr/bin/env python3
"""Find functions that match known-working decompilation patterns.

Scans all .c files in src/c/ and identifies asm functions (both individual
asm() and asm volatile()) that match patterns we've confirmed produce
byte-identical output with clang.
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
    raw_body: str = ""
    return_type: str = ""
    this_type: str = ""
    params: str = ""
    has_attribute: str = ""
    has_trailing_padding: bool = False
    trailing_type: str = "clean"  # "clean", "nops_only", "has_code"
    asm_type: str = "individual"  # "individual" or "volatile"


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
        # Extract everything before the clobber list
        colon_pos = block.find(':::')
        if colon_pos == -1:
            colon_pos = block.find(':')
        if colon_pos != -1:
            block = block[:colon_pos]
        # Extract all string literals
        strings = re.findall(r'"([^"]*)"', block)
        full_asm = ''.join(strings)
        for line in re.split(r'\\n\\t|\\n', full_asm):
            line = normalize_asm(line)
            if line and not line.endswith(':'):
                instructions.append(line)
    return instructions


def extract_individual_instructions(body: str) -> list[str]:
    """Extract instruction lines from individual asm() calls."""
    instructions = []
    for m in re.findall(r'asm\s*\("([^"]+)"\s*\)', body):
        line = normalize_asm(m)
        if line and not line.endswith(':'):
            instructions.append(line)
    block_lines = re.findall(r'"([^"]+?)\\n"', body)
    for line in block_lines:
        line = normalize_asm(line)
        if line and not line.endswith(':'):
            instructions.append(line)
    return instructions


def extract_asm_functions(filepath: Path) -> list[AsmFunction]:
    """Extract all functions containing asm() or asm volatile() from a C file."""
    text = filepath.read_text()
    functions = []

    func_pattern = re.compile(
        r'^(?:(__attribute__\(\([^)]*\)\))\s*\n)?'
        r'(\S.*?)\s+(?:__fastcall|__cdecl)\s+(\w+)\s*\(([^)]*)\)\s*\n\{',
        re.MULTILINE
    )

    for match in func_pattern.finditer(text):
        func_start = match.start()
        attr = match.group(1) or ""
        return_type = match.group(2)
        func_name = match.group(3)
        params = match.group(4)
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

        if has_volatile:
            clean_lines = extract_volatile_instructions(body)
            asm_type = "volatile"
        else:
            clean_lines = extract_individual_instructions(body)
            asm_type = "individual"

        if not clean_lines:
            continue

        # Check for trailing padding (instructions after ret)
        has_trailing = False
        trailing_type = "clean"  # "clean", "nops_only", "has_code"
        found_ret = False
        trailing_lines = []
        for line in clean_lines:
            if found_ret:
                trailing_lines.append(line.strip())
            if not found_ret and line.strip().startswith('ret'):
                found_ret = True
        if trailing_lines:
            has_trailing = True
            if all(l == 'nop' for l in trailing_lines):
                trailing_type = "nops_only"
            else:
                trailing_type = "has_code"

        # Get first param type
        this_type = ""
        if params:
            first_param = params.split(',')[0].strip()
            type_match = re.match(r'(?:const\s+)?(?:struct\s+)?(\w+)\*', first_param)
            if type_match:
                this_type = type_match.group(1)

        func = AsmFunction(
            file=str(filepath.relative_to(filepath.parent.parent.parent)),
            name=func_name,
            line=line_num,
            asm_lines=clean_lines,
            raw_body=body,
            return_type=return_type,
            this_type=this_type,
            params=params,
            has_attribute=attr,
            has_trailing_padding=has_trailing,
            trailing_type=trailing_type,
            asm_type=asm_type,
        )
        functions.append(func)

    return functions


def analyze_pattern(func: AsmFunction) -> dict | None:
    """Analyze if a function matches a known-working pattern. Returns info dict or None."""
    lines = func.asm_lines
    if func.trailing_type == "has_code":
        return None

    # Get lines before ret, normalized
    code = []
    for line in lines:
        n = normalize_asm(line)
        code.append(n)
        if n.startswith('ret'):
            break

    joined = ' | '.join(code)

    # Pattern 1: Simple field getter - mov eax, [ecx + offset]; ret
    m = re.match(
        r'.*mov\s+eax,\s*dword ptr \[ecx \+ 0x([0-9a-f]+)\]\s*\|\s*ret',
        joined
    )
    if m and len(code) == 2:
        offset = int(m.group(1), 16)
        return {
            'pattern': 'field_getter',
            'offset': offset,
            'note': f'return this->field_at_0x{offset:x};',
        }

    # Pattern 2: Float field getter - fld [ecx + offset]; ret
    m = re.match(
        r'.*fld\s+dword ptr \[ecx \+ 0x([0-9a-f]+)\]\s*\|\s*ret',
        joined
    )
    if m and len(code) == 2:
        offset = int(m.group(1), 16)
        return {
            'pattern': 'float_field_getter',
            'offset': offset,
            'note': f'return this->float_field_at_0x{offset:x};',
        }

    # Pattern 3: Double dereference getter - mov eax, [ecx + A]; mov eax, [eax + B]; ret
    m = re.match(
        r'.*mov\s+eax,\s*dword ptr \[ecx \+ 0x([0-9a-f]+)\]\s*\|'
        r'\s*.*mov\s+eax,\s*dword ptr \[eax \+ 0x([0-9a-f]+)\]\s*\|\s*ret',
        joined
    )
    if m and len(code) == 3:
        off1 = int(m.group(1), 16)
        off2 = int(m.group(2), 16)
        return {
            'pattern': 'double_deref_getter',
            'offset1': off1,
            'offset2': off2,
            'note': f'return this->ptr_at_0x{off1:x}->field_at_0x{off2:x};',
        }

    # Pattern 4: Info float getter - mov eax, [ecx + A]; fld [eax + B]; ret
    m = re.match(
        r'.*mov\s+eax,\s*dword ptr \[ecx \+ 0x([0-9a-f]+)\]\s*\|'
        r'\s*.*fld\s+dword ptr \[eax \+ 0x([0-9a-f]+)\]\s*\|\s*ret',
        joined
    )
    if m and len(code) == 3:
        off1 = int(m.group(1), 16)
        off2 = int(m.group(2), 16)
        return {
            'pattern': 'info_float_getter',
            'offset1': off1,
            'offset2': off2,
            'note': f'return this->ptr_at_0x{off1:x}->float_at_0x{off2:x};',
        }

    # Pattern 5: Info pointer+offset - mov eax, [ecx + A]; add eax, B; ret
    m = re.match(
        r'.*mov\s+eax,\s*dword ptr \[ecx \+ 0x([0-9a-f]+)\]\s*\|'
        r'\s*add\s+eax,\s*0x([0-9a-f]+)\s*\|\s*ret',
        joined
    )
    if m and len(code) == 3:
        off1 = int(m.group(1), 16)
        off2 = int(m.group(2), 16)
        return {
            'pattern': 'info_addr_getter',
            'offset1': off1,
            'offset2': off2,
            'note': f'return &this->ptr_at_0x{off1:x}->field_at_0x{off2:x};',
        }

    # Pattern 6: Simple setter - mov eax, [esp + 0x04]; mov [ecx + offset], eax; ret
    m = re.match(
        r'.*mov\s+eax,\s*dword ptr \[esp \+ 0x04\]\s*\|'
        r'\s*.*mov\s+dword ptr \[ecx \+ 0x([0-9a-f]+)\],\s*eax\s*\|\s*ret',
        joined
    )
    if m and len(code) == 3:
        offset = int(m.group(1), 16)
        return {
            'pattern': 'field_setter',
            'offset': offset,
            'note': f'this->field_at_0x{offset:x} = param;',
        }

    # Pattern 7: Set null and return 1 - mov [ecx + A], 0; mov eax, 1; ret
    m = re.match(
        r'.*mov\s+dword ptr \[ecx \+ 0x([0-9a-f]+)\],\s*0x0+\s*\|'
        r'\s*mov\s+eax,\s*0x0*1\s*\|\s*ret',
        joined
    )
    if m and len(code) == 3:
        offset = int(m.group(1), 16)
        return {
            'pattern': 'set_null_return_1',
            'offset': offset,
            'note': f'this->field_at_0x{offset:x} = NULL; return 1;',
        }

    # Pattern 8: Return true (mov al, 0x01; ret)
    m = re.match(r'mov\s+al,\s*0x01\s*\|\s*ret', joined)
    if m and len(code) == 2:
        return {
            'pattern': 'return_true',
            'note': 'return true;',
        }

    # Pattern 9: Array indexed getter - mov eax, [esp+4]; mov eax, [ecx + eax*4 + offset]; ret
    m = re.match(
        r'.*mov\s+eax,\s*dword ptr \[esp \+ 0x04\]\s*\|'
        r'\s*.*mov\s+eax,\s*dword ptr \[ecx \+ eax \* 0x4 \+ 0x([0-9a-f]+)\]\s*\|\s*ret',
        joined
    )
    if m and len(code) == 3:
        offset = int(m.group(1), 16)
        return {
            'pattern': 'array_indexed_getter',
            'offset': offset,
            'note': f'return this->array_at_0x{offset:x}[param];',
        }

    # Pattern 10: LEA address getter - lea eax, [ecx + offset]; ret
    m = re.match(
        r'.*lea\s+eax,\s*\[ecx \+ 0x([0-9a-f]+)\]\s*\|\s*ret',
        joined
    )
    if m and len(code) == 2:
        offset = int(m.group(1), 16)
        return {
            'pattern': 'lea_addr_getter',
            'offset': offset,
            'note': f'return &this->field_at_0x{offset:x};',
        }

    # Pattern 11: XOR return 0 - xor eax, eax; ret
    m = re.match(r'xor\.?s?\s+eax,\s*eax\s*\|\s*ret', joined)
    if m and len(code) == 2:
        return {
            'pattern': 'return_zero_xor',
            'note': 'return 0; (XOR32rr_REV)',
        }

    # Pattern 12: Return this - mov eax, ecx; ret (MOV32rr_REV)
    m = re.match(r'mov\.?s?\s+eax,\s*ecx\s*\|\s*ret', joined)
    if m and len(code) == 2:
        return {
            'pattern': 'return_this',
            'note': 'return this; (MOV32rr_REV)',
        }

    # Pattern 13: Word set + return 1 - mov word [ecx+N], imm; mov eax, 1; ret N
    m = re.match(
        r'.*mov\s+word ptr \[ecx \+ 0x([0-9a-f]+)\],\s*0x([0-9a-f]+)\s*\|'
        r'\s*mov\s+eax,\s*0x0*1\s*\|\s*ret',
        joined
    )
    if m and len(code) == 3:
        offset = int(m.group(1), 16)
        return {
            'pattern': 'word_set_return_1',
            'offset': offset,
            'note': f'this->field_at_0x{offset:x} = imm16; return 1;',
        }

    # Pattern 14: Jmp thunk - jmp target
    # Note: same-file jmp thunks with {disp32} can't use musttail (short jmp encoding)
    m = re.match(r'jmp\s+(\S+)', joined)
    if m and len(code) == 1:
        # Check if original had {disp32} encoding hint (may be escaped as %{disp32%})
        has_disp32 = ('disp32' in func.raw_body) and ('jmp' in func.raw_body)
        return {
            'pattern': 'jmp_thunk',
            'note': f'jmp {m.group(1)[:40]};',
            'blocked': has_disp32,
            'block_reason': '{disp32} jmp — musttail uses wrong encoding' if has_disp32 else None,
        }

    return None


def main():
    src_dir = Path(__file__).parent.parent.parent / "src" / "c"

    all_funcs = []
    for cfile in sorted(src_dir.glob("*.c")):
        all_funcs.extend(extract_asm_functions(cfile))

    # Analyze each function
    matches = []
    for func in all_funcs:
        result = analyze_pattern(func)
        if result:
            matches.append((func, result))

    # Separate clean matches from nop-padded/blocked ones
    clean = [(f, i) for f, i in matches if f.trailing_type == "clean" and not i.get('blocked')]
    blocked_enc = [(f, i) for f, i in matches if i.get('blocked')]
    nop_padded = [(f, i) for f, i in matches if f.trailing_type == "nops_only" and not i.get('blocked')]

    if clean:
        print(f"DECOMPILABLE ({len(clean)} functions):\n")
        for func, info in clean:
            tag = "V" if func.asm_type == "volatile" else "I"
            print(f"  [{tag}] {func.file}:{func.line:<5} {func.name:<50} {info['pattern']:<25} {info['note']}")

    if nop_padded:
        print(f"\nNOP-PADDED (needs alignment handling, {len(nop_padded)} functions):\n")
        for func, info in nop_padded:
            tag = "V" if func.asm_type == "volatile" else "I"
            print(f"  [{tag}] {func.file}:{func.line:<5} {func.name:<50} {info['pattern']:<25} {info['note']}")

    # Show blocked float_const_return functions
    blocked_float = []
    for func in all_funcs:
        if func.trailing_type == "has_code":
            continue
        code = []
        for line in func.asm_lines:
            n = normalize_asm(line)
            code.append(n)
            if n.startswith('ret'):
                break
        joined = ' | '.join(code)
        if len(code) <= 3 and re.search(r'fld\s+dword ptr \[_rdata', joined) and 'ret' in joined:
            const_match = re.search(r'\[(_rdata_\w+)\]', joined)
            const_name = const_match.group(1) if const_match else "?"
            blocked_float.append((func, const_name))

    if blocked_float:
        print(f"\nBLOCKED — float const return ({len(blocked_float)} functions, needs LLVM patch):\n")
        for func, const_name in blocked_float:
            short_name = func.name.split('__')[0] if '__' in func.name else func.name
            print(f"  [B] {func.file}:{func.line:<5} {short_name:<50} return {const_name};")

    if blocked_enc:
        print(f"\nBLOCKED — encoding constraints ({len(blocked_enc)} functions):\n")
        for func, info in blocked_enc:
            short_name = func.name.split('__')[0] if '__' in func.name else func.name
            print(f"  [B] {func.file}:{func.line:<5} {short_name:<50} {info.get('block_reason', '?')}")

    print(f"\n{'='*80}")
    print(f"Total: {len(clean)} decompilable, {len(nop_padded)} nop-padded, {len(blocked_enc)} blocked-encoding, {len(blocked_float)} blocked-float")
    n_volatile = sum(1 for f in all_funcs if f.asm_type == "volatile")
    n_individual = sum(1 for f in all_funcs if f.asm_type == "individual")
    print(f"Total asm functions: {len(all_funcs)} (volatile: {n_volatile}, individual: {n_individual})")


if __name__ == "__main__":
    main()

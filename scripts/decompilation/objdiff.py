#!/usr/bin/env python3
"""objdiff.py — Compare compiled C function bytes against original ASM bytes.

Usage:
    python3 scripts/decompilation/objdiff.py <file.c> <msvc_mangled_name>
    python3 scripts/decompilation/objdiff.py src/c/Object.000.c "?StandAnimation@Object@@UAEIXZ"

Finds the function in the compiled object file and the expected bytes from
the original ASM source annotations, then reports byte-level differences
with attribute suggestions.
"""

import sys
import re
import subprocess
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent.parent
BUILD_DIR = PROJECT_ROOT / "cmake-build-presets" / "release"
LLVM_OBJDUMP = PROJECT_ROOT.parent / "llvm-project" / "install" / "bin" / "llvm-objdump"
ASM_DIR = PROJECT_ROOT / "src" / "asm" / "unprocessed"

# Attribute suggestion table: (expected_opcode_byte, got_opcode_byte) -> suggestion
OPCODE_SUGGESTIONS = {
    (0x03, 0x01): "msvc6_regalloc — reversed ADD (03 vs 01)",
    (0x0B, 0x09): "msvc6_regalloc — reversed OR (0B vs 09)",
    (0x13, 0x11): "msvc6_regalloc — reversed ADC (13 vs 11)",
    (0x1B, 0x19): "msvc6_regalloc — reversed SBB (1B vs 19)",
    (0x23, 0x21): "msvc6_regalloc — reversed AND (23 vs 21)",
    (0x2B, 0x29): "msvc6_regalloc — reversed SUB (2B vs 29)",
    (0x33, 0x31): "XOR32rr_REV — reversed XOR (33 vs 31)",
    (0x3B, 0x39): "msvc6_regalloc — reversed CMP (3B vs 39)",
    (0x8B, 0x89): "MOV32rr_REV — reversed MOV (8B vs 89)",
    (0x01, 0x03): "msvc6_regalloc — reversed ADD (got REV, expected canonical)",
    (0x09, 0x0B): "msvc6_regalloc — reversed OR (got REV, expected canonical)",
    (0x31, 0x33): "XOR32rr_REV — reversed XOR (got REV, expected canonical)",
    (0x89, 0x8B): "MOV32rr_REV — reversed MOV (got REV, expected canonical)",
}

# Multi-byte pattern suggestions
PATTERN_SUGGESTIONS = [
    (bytes([0x83, 0xC8, 0xFF]), bytes([0xB8, 0xFF, 0xFF, 0xFF, 0xFF]),
     "prefer_or_minus_one — or eax,-1 (3 bytes) vs mov eax,-1 (5 bytes)"),
    (bytes([0x59]), bytes([0x83, 0xC4, 0x04]),
     "prefer_pop_cleanup — pop ecx (1 byte) vs add esp,4 (3 bytes)"),
    (bytes([0xD9, 0xEE]), None,
     "suppress_fp_imm — fldz should be fld [mem]"),
    (bytes([0xD9, 0xE8]), None,
     "suppress_fp_imm — fld1 should be fld [mem]"),
]


def find_object_file(c_file: str) -> Path:
    """Find the compiled .o file for a given .c source."""
    c_path = Path(c_file)
    if not c_path.is_absolute():
        c_path = PROJECT_ROOT / c_path
    rel = c_path.relative_to(PROJECT_ROOT)
    obj_dir = BUILD_DIR / "CMakeFiles" / "runblack-reassembled-src-001.dir"
    obj_path = obj_dir / (str(rel) + ".o")
    if obj_path.exists():
        return obj_path
    for pattern in BUILD_DIR.rglob(f"*/{c_path.name}.o"):
        return pattern
    raise FileNotFoundError(f"Object file not found for {c_file}")


def disassemble_function(obj_path: Path, symbol: str) -> list:
    """Extract function instructions from object file."""
    result = subprocess.run(
        [str(LLVM_OBJDUMP), "-d", str(obj_path)],
        capture_output=True, text=True
    )
    lines = result.stdout.splitlines()
    in_func = False
    instructions = []

    for line in lines:
        if symbol in line and ">:" in line:
            in_func = True
            continue
        if in_func:
            if re.match(r'\s*[0-9a-f]+\s+<', line) and ">:" in line:
                break
            m = re.match(r'\s+[0-9a-f]+:\s+((?:[0-9a-f]{2}\s)+)\s+(.+)', line)
            if m:
                hex_bytes = bytes.fromhex(m.group(1).strip().replace(" ", ""))
                asm_text = m.group(2).strip()
                # Stop at nop padding (function alignment)
                if asm_text == "nop" and len(hex_bytes) == 1:
                    break
                instructions.append((hex_bytes, asm_text))

    return instructions


def find_asm_function(symbol: str) -> list:
    """Find expected bytes from ASM source files."""
    # Search all ASM files for the symbol
    for asm_file in sorted(ASM_DIR.glob("*.asm")):
        with open(asm_file) as f:
            lines = f.readlines()

        # Find the symbol label
        in_func = False
        instructions = []
        for line in lines:
            stripped = line.strip()

            # Function label
            if stripped.startswith(symbol + ":") or stripped.endswith(symbol + ":"):
                label_part = stripped.split(":")[0].strip()
                if label_part == symbol or label_part.endswith(symbol):
                    in_func = True
                    continue

            if in_func:
                # Next function label (not a local label like LAB_xxx)
                if re.match(r'^[?_@\w].*:', stripped) and not stripped.startswith("LAB") and not stripped.startswith("0:"):
                    break

                # Instruction with byte comment: "mov eax, ecx  // 0x00435520 8bc1"
                m = re.search(r'//\s*0x[0-9a-f]+\s+([0-9a-f]+)', stripped)
                if m:
                    hex_bytes = bytes.fromhex(m.group(1))
                    asm_text = stripped.split("//")[0].strip()
                    # Skip nop padding
                    if hex_bytes == b'\x90' and ('nop' in asm_text.lower() or not asm_text):
                        break
                    instructions.append((hex_bytes, asm_text))

        if instructions:
            return instructions

    return []


def suggest_fixes(expected: bytes, got: bytes) -> list:
    """Find attribute suggestions for byte differences."""
    suggestions = []

    # Check opcode-level suggestions
    if len(expected) > 0 and len(got) > 0:
        key = (expected[0], got[0])
        if key in OPCODE_SUGGESTIONS:
            suggestions.append(OPCODE_SUGGESTIONS[key])

    # Check multi-byte patterns
    for exp_pat, got_pat, suggestion in PATTERN_SUGGESTIONS:
        if exp_pat and expected[:len(exp_pat)] == exp_pat:
            if got_pat is None or (len(got) >= len(got_pat) and got[:len(got_pat)] == got_pat):
                suggestions.append(suggestion)

    return suggestions


def main():
    if len(sys.argv) < 3:
        print("Usage: python3 objdiff.py <file.c> <msvc_mangled_symbol>")
        print('Example: python3 objdiff.py src/c/Object.000.c "?StandAnimation@Object@@UAEIXZ"')
        print()
        print("The symbol should be the MSVC-mangled name (appears in .globl directives")
        print("in the ASM files and in asm() labels in the header files).")
        sys.exit(1)

    c_file = sys.argv[1]
    symbol = sys.argv[2]

    print(f"objdiff: {symbol}")
    print("=" * 60)

    # Get compiled bytes
    try:
        obj_path = find_object_file(c_file)
    except FileNotFoundError as e:
        print(f"ERROR: {e}")
        sys.exit(1)

    compiled = disassemble_function(obj_path, symbol)
    if not compiled:
        print(f"ERROR: Symbol '{symbol}' not found in object file")
        sys.exit(1)

    compiled_bytes = b"".join(b for b, _ in compiled)
    print(f"Compiled: {len(compiled_bytes)} bytes ({len(compiled)} instructions)")

    # Get expected bytes from ASM
    expected = find_asm_function(symbol)
    if not expected:
        print(f"Expected: (not found in ASM files — showing compiled output only)")
        print()
        for byte_data, asm_text in compiled:
            print(f"  {byte_data.hex(' '):30s} {asm_text}")
        sys.exit(0)

    expected_bytes = b"".join(b for b, _ in expected)
    print(f"Expected: {len(expected_bytes)} bytes ({len(expected)} instructions)")

    if compiled_bytes == expected_bytes:
        print(f"\n  MATCH! All {len(compiled_bytes)} bytes identical.")
        sys.exit(0)

    # Diff instruction by instruction
    print(f"\n  MISMATCH — {len(compiled_bytes)} compiled vs {len(expected_bytes)} expected bytes")
    print()

    max_inst = max(len(compiled), len(expected))
    compiled_offset = 0
    expected_offset = 0

    for i in range(max_inst):
        if i < len(expected) and i < len(compiled):
            exp_bytes, exp_asm = expected[i]
            got_bytes, got_asm = compiled[i]

            if exp_bytes == got_bytes:
                marker = "  "
            else:
                marker = ">>"
                # Get suggestions
                fixes = suggest_fixes(exp_bytes, got_bytes)

            print(f"  {marker} Expected: {exp_bytes.hex(' '):30s} {exp_asm}")
            print(f"  {marker} Got:      {got_bytes.hex(' '):30s} {got_asm}")
            if exp_bytes != got_bytes:
                fixes = suggest_fixes(exp_bytes, got_bytes)
                for fix in fixes:
                    print(f"     -> TRY: {fix}")
            print()

        elif i < len(expected):
            exp_bytes, exp_asm = expected[i]
            print(f"  -- Expected: {exp_bytes.hex(' '):30s} {exp_asm}")
            print(f"  -- Got:      (missing)")
            print()

        elif i < len(compiled):
            got_bytes, got_asm = compiled[i]
            print(f"  ++ Expected: (missing)")
            print(f"  ++ Got:      {got_bytes.hex(' '):30s} {got_asm}")
            print()


if __name__ == "__main__":
    main()

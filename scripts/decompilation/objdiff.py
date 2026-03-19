#!/usr/bin/env python3
"""objdiff.py — Compare compiled C function bytes against original ASM bytes.

Usage:
    python3 scripts/decompilation/objdiff.py <file.c> <symbol>   (single function diff)
    python3 scripts/decompilation/objdiff.py <file.c>            (batch: diff all functions)

Examples:
    python3 scripts/decompilation/objdiff.py src/c/Object.000.c "?StandAnimation@Object@@UAEIXZ"
    python3 scripts/decompilation/objdiff.py src/c/Object.000.c

Finds the function in the compiled object file and the expected bytes from
the original ASM source annotations, then reports byte-level differences
with attribute suggestions.  Uses Needleman-Wunsch alignment so that
extra/missing instructions show as gaps instead of offsetting everything.

Attributes NOT auto-detectable (must be applied manually):
    trailing_bytes  — raw bytes emitted after function body
    trailing_asm    — assembly emitted after function body (with relocations)
    msvc6_sdtor     — replaces entire function with MSVC 6.0 scalar deleting destructor
"""

import sys
import re
import subprocess
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent.parent
BUILD_DIR = PROJECT_ROOT / "cmake-build-presets" / "release"
LLVM_OBJDUMP = PROJECT_ROOT.parent / "llvm-project" / "install" / "bin" / "llvm-objdump"
ASM_DIR = PROJECT_ROOT / "src" / "asm" / "unprocessed"

# ---------------------------------------------------------------------------
# Suggestion tables
# ---------------------------------------------------------------------------

# Opcode-level: (expected_first_byte, got_first_byte) -> suggestion
OPCODE_SUGGESTIONS = {
    # Reversed reg-reg encodings (msvc6_regalloc)
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
    # prefer_xor8: xor al,al (32) vs xor eax,eax (33/31)
    (0x32, 0x33): "prefer_xor8 — expected xor al,al (32) but got xor eax,eax (33)",
    (0x32, 0x31): "prefer_xor8 — expected xor al,al (32) but got xor eax,eax (31)",
}

# Multi-byte pattern: (expected_prefix | None, got_prefix | None, suggestion)
# None means "match any bytes on that side"
PATTERN_SUGGESTIONS = [
    # prefer_or_minus_one
    (bytes([0x83, 0xC8, 0xFF]), bytes([0xB8, 0xFF, 0xFF, 0xFF, 0xFF]),
     "prefer_or_minus_one — or eax,-1 (3 bytes) vs mov eax,-1 (5 bytes)"),
    # prefer_pop_cleanup
    (bytes([0x59]), bytes([0x83, 0xC4, 0x04]),
     "prefer_pop_cleanup — pop ecx (1 byte) vs add esp,4 (3 bytes)"),
    # suppress_fp_imm: expected fldz/fld1, got fld from const pool (D9 05 = fld dword ptr [disp32])
    (bytes([0xD9, 0xEE]), bytes([0xD9, 0x05]),
     "suppress_fp_imm — expected fldz (D9 EE), got fld [mem] (D9 05)"),
    (bytes([0xD9, 0xE8]), bytes([0xD9, 0x05]),
     "suppress_fp_imm — expected fld1 (D9 E8), got fld [mem] (D9 05)"),
    # suppress_fp_imm reverse: compiled has fldz/fld1 but expected loads from mem
    (bytes([0xD9, 0x05]), bytes([0xD9, 0xEE]),
     "suppress_fp_imm (remove?) — expected fld [mem], got fldz"),
    (bytes([0xD9, 0x05]), bytes([0xD9, 0xE8]),
     "suppress_fp_imm (remove?) — expected fld [mem], got fld1"),
    # expand_movzx: compiled has movzx (0F B6) where expected has xor+mov
    (bytes([0x33]), bytes([0x0F, 0xB6]),
     "expand_movzx — expected xor (33)+mov, got movzx (0F B6)"),
    (bytes([0x32]), bytes([0x0F, 0xB6]),
     "expand_movzx — expected xor (32)+mov, got movzx (0F B6)"),
    (None, bytes([0x0F, 0xB6]),
     "expand_movzx — compiled uses movzx (0F B6); expected may use xor+mov"),
    # prefer_sete_ecx: sete cl (0F 94 C1) vs sete al (0F 94 C0)
    (bytes([0x0F, 0x94, 0xC1]), bytes([0x0F, 0x94, 0xC0]),
     "prefer_sete_ecx — expected sete cl (C1) but got sete al (C0)"),
    (bytes([0x0F, 0xB6, 0xC1]), bytes([0x0F, 0xB6, 0xC0]),
     "prefer_sete_ecx — expected movzx eax,cl (C1) but got movzx eax,al (C0)"),
    # prefer_neg_sbb: neg (F7 D8-DF) vs xor (33/31)
    (bytes([0xF7, 0xD8]), bytes([0x33]),
     "prefer_neg_sbb — expected neg eax (F7 D8) but got xor (33). MSVC uses neg+sbb+inc"),
    (bytes([0xF7, 0xD9]), bytes([0x33]),
     "prefer_neg_sbb — expected neg ecx (F7 D9) but got xor (33)"),
    (bytes([0xF7, 0xDA]), bytes([0x33]),
     "prefer_neg_sbb — expected neg edx (F7 DA) but got xor (33)"),
    (bytes([0x1B]), bytes([0x85]),
     "prefer_neg_sbb — expected sbb (1B) but got test (85)"),
    # no_test_sete_fold: not al (F6 D0) vs test al,imm (A8/F6 C0)
    (bytes([0xF6, 0xD0]), bytes([0xA8]),
     "no_test_sete_fold — expected not al (F6 D0) but got test al,imm (A8)"),
    (bytes([0xF6, 0xD0]), bytes([0xF6, 0xC0]),
     "no_test_sete_fold — expected not al (F6 D0) but got test al,imm (F6 C0)"),
    (bytes([0xC1, 0xE8]), bytes([0x0F, 0x94]),
     "no_test_sete_fold — expected shr eax,N (C1 E8) but got sete (0F 94)"),
    # no_bool_mask: compiled has extra and al,1 / and eax,1
    (None, bytes([0x24, 0x01]),
     "no_bool_mask — compiled has and al,1 (24 01) not in expected"),
    (None, bytes([0x83, 0xE0, 0x01]),
     "no_bool_mask — compiled has and eax,1 (83 E0 01) not in expected"),
    # prefer_fmul_mem: compiled has fmulp (DE C9) where expected has fmul [mem]
    (None, bytes([0xDE, 0xC9]),
     "prefer_fmul_mem — compiled has fmulp (DE C9); expected may use fmul [mem]"),
    (bytes([0xD8]), bytes([0xD9]),
     "prefer_fmul_mem — expected fmul/fadd [mem] (D8) but got fld [mem] (D9)"),
    # prefer_inc_dec_byte: expected inc/dec byte [mem] (FE) vs movzx sequence
    (bytes([0xFE]), bytes([0x0F, 0xB6]),
     "prefer_inc_dec_byte — expected inc/dec byte [mem] (FE) but got movzx (0F B6)"),
]

# ---------------------------------------------------------------------------
# Symbol index (lazy, built on first use)
# ---------------------------------------------------------------------------

_symbol_index = None  # symbol_name -> (asm_file_path, line_number_0based)

_BYTE_COMMENT_RE = re.compile(r'//\s*0x[0-9a-f]+\s+((?:[0-9a-f]{2})+)\s*$')
_LABEL_RE = re.compile(r'^([?_@\w][^:\s]*):')


def build_symbol_index():
    """Scan all ASM files once and return symbol -> (file, line_idx) mapping."""
    index = {}
    for asm_file in sorted(ASM_DIR.glob("*.asm")):
        with open(asm_file) as f:
            for line_idx, line in enumerate(f):
                m = _LABEL_RE.match(line.strip())
                if not m:
                    continue
                label = m.group(1)
                # Skip local labels
                if label.startswith(('.Lbl_', 'LAB', 'start_', '0')):
                    continue
                if label not in index:
                    index[label] = (asm_file, line_idx)
    return index


def _get_symbol_index():
    global _symbol_index
    if _symbol_index is None:
        _symbol_index = build_symbol_index()
    return _symbol_index


# ---------------------------------------------------------------------------
# Data extraction
# ---------------------------------------------------------------------------

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
    """Extract function instructions from object file.

    Returns list of (bytes, asm_text, reloc_offsets) tuples.
    reloc_offsets is a set of byte positions within this instruction
    that are filled by the linker (should be masked during comparison).
    """
    result = subprocess.run(
        [str(LLVM_OBJDUMP), "-dr", str(obj_path)],
        capture_output=True, text=True
    )
    lines = result.stdout.splitlines()
    in_func = False
    instructions = []
    # Map: section_offset -> index in instructions list
    offset_to_idx = {}

    for line in lines:
        if symbol in line and ">:" in line:
            in_func = True
            continue
        if in_func:
            if re.match(r'\s*[0-9a-f]+\s+<', line) and ">:" in line:
                break

            # Relocation line: "\t\t0000004b:  IMAGE_REL_..."
            if 'IMAGE_REL_' in line:
                reloc_m = re.match(r'\s+([0-9a-f]+):\s+IMAGE_REL_', line)
                if reloc_m and instructions:
                    abs_offset = int(reloc_m.group(1), 16)
                    # Find which instruction contains this relocation
                    # by checking recorded offsets
                    for instr_off in sorted(offset_to_idx.keys(), reverse=True):
                        if instr_off <= abs_offset:
                            idx = offset_to_idx[instr_off]
                            ibytes, _, irelocs = instructions[idx]
                            if abs_offset < instr_off + len(ibytes):
                                for b in range(4):
                                    pos = abs_offset - instr_off + b
                                    if pos < len(ibytes):
                                        irelocs.add(pos)
                            break
                continue

            m = re.match(r'\s+([0-9a-f]+):\s+((?:[0-9a-f]{2}\s)+)\s+(.+)', line)
            if m:
                instr_offset = int(m.group(1), 16)
                hex_bytes = bytes.fromhex(m.group(2).strip().replace(" ", ""))
                asm_text = m.group(3).strip()
                if asm_text == "nop" and len(hex_bytes) == 1:
                    break
                offset_to_idx[instr_offset] = len(instructions)
                instructions.append((hex_bytes, asm_text, set()))

    return instructions


def list_obj_symbols(obj_path: Path) -> list:
    """Extract defined function symbols from a compiled .o file."""
    result = subprocess.run(
        [str(LLVM_OBJDUMP), "-t", str(obj_path)],
        capture_output=True, text=True
    )
    symbols = []
    for line in result.stdout.splitlines():
        # COFF format: [...](sec  N)(...)(ty  20)(scl   2)(...) 0xNNN symbol_name
        # sec > 0 = defined, ty 20 = function, scl 2 = external
        if '(ty  20)' not in line or '(scl   2)' not in line:
            continue
        # sec must be positive (defined, not extern)
        sec_m = re.search(r'\(sec\s+(\d+)\)', line)
        if not sec_m or int(sec_m.group(1)) < 1:
            continue
        # Symbol name is the last whitespace-delimited token
        parts = line.rsplit(None, 1)
        if len(parts) == 2:
            symbols.append(parts[1])
    return symbols


def find_asm_function(symbol: str) -> list:
    """Find expected bytes from ASM source files using the symbol index.

    Returns list of (bytes, asm_text, set()) tuples (empty reloc set —
    ASM files have final linked bytes with no relocations).
    """
    index = _get_symbol_index()
    entry = index.get(symbol)
    if entry is None:
        return []

    asm_file, label_line_idx = entry
    with open(asm_file) as f:
        all_lines = f.readlines()

    instructions = []
    # Start at the label line itself — it may contain instruction bytes
    for line_idx in range(label_line_idx, len(all_lines)):
        stripped = all_lines[line_idx].strip()

        if line_idx == label_line_idx:
            # This is the label line; check if it also has instruction bytes
            m = _BYTE_COMMENT_RE.search(stripped)
            if m:
                hex_bytes = bytes.fromhex(m.group(1))
                # Extract asm text between the colon and the comment
                after_colon = stripped.split(":", 1)[1] if ":" in stripped else ""
                asm_text = after_colon.split("//")[0].strip()
                if not (hex_bytes == b'\x90' and ('nop' in asm_text.lower() or not asm_text)):
                    instructions.append((hex_bytes, asm_text, set()))
            continue

        # Next function label (not a local label)
        if re.match(r'^[?_@\w].*:', stripped) and not stripped.startswith(('.Lbl_', 'LAB', '0:')):
            break

        m = _BYTE_COMMENT_RE.search(stripped)
        if m:
            hex_bytes = bytes.fromhex(m.group(1))
            asm_text = stripped.split("//")[0].strip()
            if hex_bytes == b'\x90' and ('nop' in asm_text.lower() or not asm_text):
                break
            instructions.append((hex_bytes, asm_text, set()))

    return instructions


# ---------------------------------------------------------------------------
# Relocation-aware byte comparison
# ---------------------------------------------------------------------------

def bytes_match(exp_bytes, got_bytes, got_relocs):
    """Compare instruction bytes, ignoring positions covered by relocations.

    got_relocs is a set of byte offsets in got_bytes that are linker-filled.
    The corresponding positions in exp_bytes hold the final linked values
    which will always differ from the .o placeholder — so we skip them.
    """
    if len(exp_bytes) != len(got_bytes):
        return False
    for i in range(len(exp_bytes)):
        if i in got_relocs:
            continue
        if exp_bytes[i] != got_bytes[i]:
            return False
    return True


def masked_hex(raw_bytes, relocs):
    """Format bytes as hex string with 'xx' for relocation positions."""
    parts = []
    for i, b in enumerate(raw_bytes):
        parts.append("xx" if i in relocs else f"{b:02x}")
    return " ".join(parts)


# ---------------------------------------------------------------------------
# Alignment (Needleman-Wunsch on instruction byte tuples)
# ---------------------------------------------------------------------------

MATCH_SCORE = 2
MISMATCH_SCORE = -1
GAP_SCORE = -2
ALIGN_LIMIT = 500  # Fall back to index-based for huge functions


def align_instructions(expected, compiled):
    """Align two instruction lists using Needleman-Wunsch.

    Returns list of (exp_entry_or_None, got_entry_or_None) pairs.
    """
    n, m = len(expected), len(compiled)

    # Fast path: either side empty
    if n == 0:
        return [(None, c) for c in compiled]
    if m == 0:
        return [(e, None) for e in expected]

    # Fall back to simple index alignment for very large functions
    if n > ALIGN_LIMIT or m > ALIGN_LIMIT:
        return _index_align(expected, compiled)

    # Build DP score matrix
    score = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        score[i][0] = score[i - 1][0] + GAP_SCORE
    for j in range(1, m + 1):
        score[0][j] = score[0][j - 1] + GAP_SCORE

    def _score(ei, cj):
        return MATCH_SCORE if bytes_match(ei[0], cj[0], cj[2]) else MISMATCH_SCORE

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            s = _score(expected[i - 1], compiled[j - 1])
            score[i][j] = max(
                score[i - 1][j - 1] + s,
                score[i - 1][j] + GAP_SCORE,
                score[i][j - 1] + GAP_SCORE,
            )

    # Traceback
    aligned = []
    i, j = n, m
    while i > 0 or j > 0:
        if i > 0 and j > 0:
            s = _score(expected[i - 1], compiled[j - 1])
            if score[i][j] == score[i - 1][j - 1] + s:
                aligned.append((expected[i - 1], compiled[j - 1]))
                i -= 1
                j -= 1
                continue
        if i > 0 and score[i][j] == score[i - 1][j] + GAP_SCORE:
            aligned.append((expected[i - 1], None))
            i -= 1
        else:
            aligned.append((None, compiled[j - 1]))
            j -= 1

    aligned.reverse()
    return aligned


def _index_align(expected, compiled):
    """Simple index-based alignment (fallback for huge functions)."""
    result = []
    max_len = max(len(expected), len(compiled))
    for i in range(max_len):
        e = expected[i] if i < len(expected) else None
        c = compiled[i] if i < len(compiled) else None
        result.append((e, c))
    return result


# ---------------------------------------------------------------------------
# Suggestion engine
# ---------------------------------------------------------------------------

def suggest_fixes(expected: bytes, got: bytes) -> list:
    """Find attribute suggestions for a single instruction byte difference."""
    suggestions = []

    # Opcode-level
    if expected and got:
        key = (expected[0], got[0])
        if key in OPCODE_SUGGESTIONS:
            suggestions.append(OPCODE_SUGGESTIONS[key])

    # Multi-byte patterns
    for exp_pat, got_pat, suggestion in PATTERN_SUGGESTIONS:
        exp_match = (exp_pat is None) or (len(expected) >= len(exp_pat) and expected[:len(exp_pat)] == exp_pat)
        got_match = (got_pat is None) or (len(got) >= len(got_pat) and got[:len(got_pat)] == got_pat)
        if exp_match and got_match:
            suggestions.append(suggestion)

    return suggestions


def suggest_function_fixes(expected_instrs, compiled_instrs):
    """Find attribute suggestions from whole-function analysis."""
    suggestions = []

    if not expected_instrs or not compiled_instrs:
        return suggestions

    # --- Prologue: callee-save push detection ---
    callee_push_opcodes = {0x53: 'ebx', 0x55: 'ebp', 0x56: 'esi', 0x57: 'edi'}

    def leading_pushes(instrs):
        regs = []
        for entry in instrs[:6]:
            b = entry[0]
            if len(b) == 1 and b[0] in callee_push_opcodes:
                regs.append((b[0], callee_push_opcodes[b[0]]))
            else:
                break
        return regs

    exp_pushes = leading_pushes(expected_instrs)
    got_pushes = leading_pushes(compiled_instrs)

    if got_pushes and not exp_pushes:
        suggestions.append(
            f"no_callee_saves — compiled has callee-save pushes "
            f"({','.join(r for _, r in got_pushes)}) not in expected")
    elif exp_pushes and got_pushes and exp_pushes != got_pushes:
        exp_names = ','.join(r for _, r in exp_pushes)
        got_names = ','.join(r for _, r in got_pushes)
        suggestions.append(
            f"forced_callee_saves — expected pushes [{exp_names}] "
            f"but got [{got_names}]. "
            f'Add __attribute__((forced_callee_saves("{exp_names}")))')

    # --- Epilogue: ret detection ---
    exp_last = expected_instrs[-1][0]
    got_last = compiled_instrs[-1][0]
    exp_has_ret = exp_last[0] in (0xC3, 0xC2)
    got_has_ret = got_last[0] in (0xC3, 0xC2)

    if got_has_ret and not exp_has_ret:
        suggestions.append("no_ret — compiled ends with ret but expected does not")

    # ret N mismatch
    if exp_last[0] == 0xC2 and got_last[0] == 0xC2 and exp_last != got_last:
        exp_n = int.from_bytes(exp_last[1:3], 'little')
        got_n = int.from_bytes(got_last[1:3], 'little')
        suggestions.append(
            f'ret_cleanup_override — expected ret {exp_n} but got ret {got_n}. '
            f'Add __attribute__((ret_cleanup_override("{exp_n}")))')
    elif exp_last[0] == 0xC2 and got_last[0] == 0xC3:
        exp_n = int.from_bytes(exp_last[1:3], 'little')
        suggestions.append(
            f'ret_cleanup_override — expected ret {exp_n} but got ret. '
            f'Add __attribute__((ret_cleanup_override("{exp_n}")))')
    elif exp_last[0] == 0xC3 and got_last[0] == 0xC2:
        got_n = int.from_bytes(got_last[1:3], 'little')
        suggestions.append(
            f"ret_cleanup_override — expected ret but got ret {got_n}")

    # --- Instruction count: movzx, fmulp, inc/dec byte ---
    def count_prefix(instrs, prefix):
        return sum(1 for entry in instrs if len(entry[0]) >= len(prefix) and entry[0][:len(prefix)] == prefix)

    exp_movzx = count_prefix(expected_instrs, b'\x0f\xb6')
    got_movzx = count_prefix(compiled_instrs, b'\x0f\xb6')
    if got_movzx > exp_movzx:
        suggestions.append(
            f"expand_movzx — compiled has {got_movzx} movzx (0F B6), "
            f"expected has {exp_movzx}. MSVC uses xor+mov instead")

    exp_fmulp = count_prefix(expected_instrs, b'\xde\xc9')
    got_fmulp = count_prefix(compiled_instrs, b'\xde\xc9')
    if got_fmulp > exp_fmulp:
        suggestions.append(
            f"prefer_fmul_mem — compiled has {got_fmulp} fmulp (DE C9), "
            f"expected has {exp_fmulp}. MSVC folds into fmul [mem]")

    exp_fe = count_prefix(expected_instrs, b'\xfe')
    got_fe = count_prefix(compiled_instrs, b'\xfe')
    if exp_fe > got_fe:
        suggestions.append(
            f"prefer_inc_dec_byte — expected has {exp_fe} inc/dec byte (FE), "
            f"compiled has {got_fe}. Compiled likely uses movzx+add+mov sequence")

    return suggestions


# ---------------------------------------------------------------------------
# Single-function diff
# ---------------------------------------------------------------------------

def diff_single(c_file, symbol):
    """Diff a single function and print detailed output."""
    print(f"objdiff: {symbol}")
    print("=" * 60)

    try:
        obj_path = find_object_file(c_file)
    except FileNotFoundError as e:
        print(f"ERROR: {e}")
        sys.exit(1)

    compiled = disassemble_function(obj_path, symbol)
    if not compiled:
        print(f"ERROR: Symbol '{symbol}' not found in object file")
        sys.exit(1)

    compiled_bytes = b"".join(b for b, _, _ in compiled)
    print(f"Compiled: {len(compiled_bytes)} bytes ({len(compiled)} instructions)")

    expected = find_asm_function(symbol)
    if not expected:
        print(f"Expected: (not found in ASM files — showing compiled output only)")
        print()
        for byte_data, asm_text, _ in compiled:
            print(f"  {byte_data.hex(' '):30s} {asm_text}")
        sys.exit(0)

    expected_bytes = b"".join(b for b, _, _ in expected)
    print(f"Expected: {len(expected_bytes)} bytes ({len(expected)} instructions)")

    # Check for match (relocation-aware)
    all_match = (len(expected) == len(compiled) and
                 all(bytes_match(e[0], c[0], c[2]) for e, c in zip(expected, compiled)))
    if all_match:
        print(f"\n  MATCH! All {len(compiled_bytes)} bytes identical (relocations masked).")
        sys.exit(0)

    print(f"\n  MISMATCH — {len(compiled_bytes)} compiled vs {len(expected_bytes)} expected bytes")
    print()

    aligned = align_instructions(expected, compiled)
    all_suggestions = set()

    for exp_entry, got_entry in aligned:
        if exp_entry is not None and got_entry is not None:
            exp_bytes, exp_asm, _ = exp_entry
            got_bytes, got_asm, got_relocs = got_entry
            match = bytes_match(exp_bytes, got_bytes, got_relocs)
            marker = "  " if match else ">>"
            got_display = masked_hex(got_bytes, got_relocs)
            print(f"  {marker} Expected: {exp_bytes.hex(' '):30s} {exp_asm}")
            print(f"  {marker} Got:      {got_display:30s} {got_asm}")
            if not match:
                fixes = suggest_fixes(exp_bytes, got_bytes)
                for fix in fixes:
                    print(f"     -> TRY: {fix}")
                    all_suggestions.add(fix.split(" — ")[0].strip())
            print()

        elif exp_entry is not None:
            exp_bytes, exp_asm, _ = exp_entry
            print(f"  -- Expected: {exp_bytes.hex(' '):30s} {exp_asm}")
            print(f"  -- Got:      (gap)")
            print()

        else:
            got_bytes, got_asm, got_relocs = got_entry
            got_display = masked_hex(got_bytes, got_relocs)
            print(f"  ++ Expected: (gap)")
            print(f"  ++ Got:      {got_display:30s} {got_asm}")
            print()

    # Function-level suggestions
    func_fixes = suggest_function_fixes(expected, compiled)
    if func_fixes:
        print("  Function-level suggestions:")
        for fix in func_fixes:
            print(f"     -> TRY: {fix}")
            all_suggestions.add(fix.split(" — ")[0].strip())
        print()

    # Summary
    if all_suggestions:
        print("  Suggested attributes:")
        for attr in sorted(all_suggestions):
            base = attr.split("(")[0].strip() if "(" in attr else attr
            print(f"    __attribute__(({base}))")


# ---------------------------------------------------------------------------
# Batch mode
# ---------------------------------------------------------------------------

def batch_diff(c_file):
    """Diff all functions in a C file and print a summary table."""
    try:
        obj_path = find_object_file(c_file)
    except FileNotFoundError as e:
        print(f"ERROR: {e}")
        sys.exit(1)

    symbols = list_obj_symbols(obj_path)
    if not symbols:
        print(f"No function symbols found in {c_file}")
        sys.exit(1)

    print(f"objdiff batch: {c_file} ({len(symbols)} functions)")
    print("=" * 78)

    match_count = 0
    mismatch_count = 0
    noref_count = 0

    for symbol in symbols:
        compiled = disassemble_function(obj_path, symbol)
        if not compiled:
            continue
        compiled_bytes = b"".join(b for b, _, _ in compiled)
        comp_len = len(compiled_bytes)

        expected = find_asm_function(symbol)
        if not expected:
            noref_count += 1
            sym_display = symbol if len(symbol) <= 55 else symbol[:52] + "..."
            print(f"  {sym_display:55s}  NO_REF     {comp_len:>4d} bytes compiled")
            continue

        expected_bytes = b"".join(b for b, _, _ in expected)
        exp_len = len(expected_bytes)

        # Relocation-aware match check
        all_match = (len(expected) == len(compiled) and
                     all(bytes_match(e[0], c[0], c[2]) for e, c in zip(expected, compiled)))
        if all_match:
            match_count += 1
            sym_display = symbol if len(symbol) <= 55 else symbol[:52] + "..."
            print(f"  {sym_display:55s}  MATCH      {comp_len:>4d} bytes")
        else:
            mismatch_count += 1
            sym_display = symbol if len(symbol) <= 55 else symbol[:52] + "..."
            print(f"  {sym_display:55s}  MISMATCH   {comp_len:>4d} vs {exp_len} bytes")

    print("=" * 78)
    total = match_count + mismatch_count + noref_count
    print(f"Summary: {match_count} MATCH, {mismatch_count} MISMATCH, {noref_count} NO_REF ({total} total)")


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    if len(sys.argv) == 2:
        # Batch mode: objdiff.py <file.c>
        batch_diff(sys.argv[1])
    elif len(sys.argv) >= 3:
        # Single function: objdiff.py <file.c> <symbol>
        diff_single(sys.argv[1], sys.argv[2])
    else:
        print("Usage: python3 objdiff.py <file.c> <symbol>   (single function diff)")
        print("       python3 objdiff.py <file.c>            (batch: diff all functions)")
        print()
        print('Example: python3 objdiff.py src/c/Object.000.c "?StandAnimation@Object@@UAEIXZ"')
        print("         python3 objdiff.py src/c/Object.000.c")
        sys.exit(1)


if __name__ == "__main__":
    main()

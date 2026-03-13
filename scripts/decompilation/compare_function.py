#!/usr/bin/env python3
"""Compare compiled function bytes against expected bytes from asm comments.

Parses a .c source file to extract expected machine code bytes from inline asm
comments, then compares them against the actual bytes produced by the compiler
in the corresponding COFF object file.

Usage:
    python scripts/decompilation/compare_function.py src/c/GameThing.001.c GetDrawImportance
    python scripts/decompilation/compare_function.py src/c/GameThing.001.c --all
"""

import argparse
import ctypes
import re
import struct
import sys
from dataclasses import dataclass
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent
OBJ_DIR = PROJECT_ROOT / "cmake-build-presets" / "release" / "CMakeFiles" / "runblack-reassembled-src-001.dir" / "src" / "c"

# COFF relocation types that occupy 4 bytes
FOUR_BYTE_RELOC_TYPES = {
    0x06,  # IMAGE_REL_I386_DIR32
    0x07,  # IMAGE_REL_I386_DIR32NB
    0x14,  # IMAGE_REL_I386_REL32 (0x14 = 20 decimal)
}


# ── COFF Structures ──────────────────────────────────────────────────────────


class COFFHeader(ctypes.LittleEndianStructure):
    _fields_ = [
        ("Machine", ctypes.c_uint16),
        ("NumberOfSections", ctypes.c_uint16),
        ("TimeDateStamp", ctypes.c_uint32),
        ("PointerToSymbolTable", ctypes.c_uint32),
        ("NumberOfSymbols", ctypes.c_uint32),
        ("SizeOfOptionalHeader", ctypes.c_uint16),
        ("Characteristics", ctypes.c_uint16),
    ]


class SectionHeader(ctypes.LittleEndianStructure):
    _fields_ = [
        ("Name", ctypes.c_char * 8),
        ("VirtualSize", ctypes.c_uint32),
        ("VirtualAddress", ctypes.c_uint32),
        ("SizeOfRawData", ctypes.c_uint32),
        ("PointerToRawData", ctypes.c_uint32),
        ("PointerToRelocations", ctypes.c_uint32),
        ("PointerToLinenumbers", ctypes.c_uint32),
        ("NumberOfRelocations", ctypes.c_uint16),
        ("NumberOfLinenumbers", ctypes.c_uint16),
        ("Characteristics", ctypes.c_uint32),
    ]


class SymbolTableEntry(ctypes.LittleEndianStructure):
    _pack_ = 1
    _layout_ = "ms"
    _fields_ = [
        ("Name", ctypes.c_char * 8),
        ("Value", ctypes.c_uint32),
        ("SectionNumber", ctypes.c_int16),
        ("Type", ctypes.c_uint16),
        ("StorageClass", ctypes.c_uint8),
        ("NumberOfAuxSymbols", ctypes.c_uint8),
    ]


class RelocationEntry(ctypes.LittleEndianStructure):
    _pack_ = 1
    _fields_ = [
        ("VirtualAddress", ctypes.c_uint32),
        ("SymbolTableIndex", ctypes.c_uint32),
        ("Type", ctypes.c_uint16),
    ]


# ── COFF Parser ──────────────────────────────────────────────────────────────


@dataclass(frozen=True)
class CoffSymbol:
    name: str
    value: int
    section_number: int
    storage_class: int


@dataclass(frozen=True)
class CoffRelocation:
    virtual_address: int
    type: int


@dataclass(frozen=True)
class CoffTextSection:
    raw_data: bytes
    raw_data_offset: int
    relocations: tuple[CoffRelocation, ...]


@dataclass(frozen=True)
class CoffInfo:
    text_section: CoffTextSection
    symbols: tuple[CoffSymbol, ...]


def _resolve_symbol_name(name_bytes: bytes, data: bytes, strtab_offset: int) -> str:
    """Resolve a COFF symbol name, handling long names via the string table."""
    if name_bytes[:4] == b"\x00\x00\x00\x00":
        str_off = struct.unpack_from("<I", name_bytes, 4)[0]
        end = data.find(b"\x00", strtab_offset + str_off)
        if end == -1:
            end = len(data)
        return data[strtab_offset + str_off : end].decode("ascii", errors="replace")
    return name_bytes.rstrip(b"\x00").decode("ascii", errors="replace")


def parse_coff(obj_path: Path) -> CoffInfo:
    """Parse a COFF object file and return text section data, symbols, and relocations."""
    data = obj_path.read_bytes()

    header = COFFHeader.from_buffer_copy(data)
    sections_offset = ctypes.sizeof(COFFHeader) + header.SizeOfOptionalHeader
    strtab_offset = header.PointerToSymbolTable + header.NumberOfSymbols * 18

    # Find .text section
    text_section = None
    for i in range(header.NumberOfSections):
        sec_offset = sections_offset + i * ctypes.sizeof(SectionHeader)
        sec = SectionHeader.from_buffer_copy(data, sec_offset)
        sec_name = sec.Name.rstrip(b"\x00").decode("ascii", errors="replace")
        if sec_name == ".text":
            raw = data[sec.PointerToRawData : sec.PointerToRawData + sec.SizeOfRawData]
            relocations = []
            for j in range(sec.NumberOfRelocations):
                rel_off = sec.PointerToRelocations + j * ctypes.sizeof(RelocationEntry)
                rel = RelocationEntry.from_buffer_copy(data, rel_off)
                relocations.append(CoffRelocation(
                    virtual_address=rel.VirtualAddress,
                    type=rel.Type,
                ))
            text_section = CoffTextSection(
                raw_data=bytes(raw),
                raw_data_offset=sec.PointerToRawData,
                relocations=tuple(relocations),
            )
            break

    if text_section is None:
        raise ValueError(f"No .text section found in {obj_path}")

    # Parse symbols
    symbols = []
    sym_idx = 0
    while sym_idx < header.NumberOfSymbols:
        entry_offset = header.PointerToSymbolTable + sym_idx * 18
        entry = SymbolTableEntry.from_buffer_copy(data, entry_offset)
        # Read raw name bytes directly from data to avoid ctypes null truncation
        raw_name_bytes = data[entry_offset : entry_offset + 8]
        name = _resolve_symbol_name(raw_name_bytes, data, strtab_offset)
        symbols.append(CoffSymbol(
            name=name,
            value=entry.Value,
            section_number=entry.SectionNumber,
            storage_class=entry.StorageClass,
        ))
        sym_idx += 1 + entry.NumberOfAuxSymbols

    return CoffInfo(text_section=text_section, symbols=tuple(symbols))


# ── Source Parser ────────────────────────────────────────────────────────────


@dataclass(frozen=True)
class ExpectedByte:
    value: int
    is_relocated: bool


@dataclass(frozen=True)
class SourceFunction:
    name: str
    mangled_name: str
    has_asm: bool
    expected_bytes: tuple[ExpectedByte, ...]
    source_line: int


# Regex for the byte comment pattern: // 0xHHHHHHHH    HEXBYTES
# The hex address is the original address, and the hex bytes are the expected machine code
_BYTE_COMMENT_RE = re.compile(r"//\s*0x[0-9a-fA-F]+\s+([0-9a-fA-F]+)\s*$")

# Regex to match function definitions (with optional __attribute__ prefix)
_FUNC_DEF_RE = re.compile(
    r"^(?:__attribute__\(\([^)]*\)\)\s*\n)?"
    r"(\S.*?)\s+__fastcall\s+(\w+)\s*\(([^)]*)\)\s*\n\{",
    re.MULTILINE,
)


def _extract_short_name(mangled_name: str) -> str:
    """Extract the bare function name from a Mac-style mangled name.

    E.g. 'GetDrawImportance__9GameThingFv' -> 'GetDrawImportance'
         '__dt__23GVillagerStateTableInfoFv' -> '__dt'
         '__ct__5AbodeFv' -> '__ct'
         'CallEntryStateFunction__Uc__8VillagerFUc' -> 'CallEntryStateFunction'
         'IsTouching_3__8VillagerCFP6Objectf' -> 'IsTouching_3'
    """
    # Find the double-underscore that separates function name from class+args encoding.
    # The class encoding starts with a digit after the '__'.
    # For names like __dt__23Foo, we need the split at __23, not __dt.
    m = re.search(r"__(\d)", mangled_name)
    if m:
        short = mangled_name[: m.start()]
        # The short name may include overload arg encoding suffixes like __Uc.
        # E.g. 'CallEntryStateFunction__Uc' -> strip the __Uc part.
        # These arg type encodings come after the first __ following the real name.
        # Split on __ and take only the first part (the actual function name).
        parts = short.split("__")
        if parts[0] == "" and len(parts) >= 2:
            # Name starts with __ (e.g. __dt, __ct): take __part[1]
            return f"__{parts[1]}"
        return parts[0]
    # Fallback: split on first '__' that is followed by something
    parts = mangled_name.split("__")
    if len(parts) >= 2 and parts[0]:
        return parts[0]
    return mangled_name


def _find_function_body(text: str, match_end: int) -> str:
    """Find the complete function body by matching braces."""
    brace_start = text.index("{", match_end - 1)
    depth = 0
    pos = brace_start
    while pos < len(text):
        if text[pos] == "{":
            depth += 1
        elif text[pos] == "}":
            depth -= 1
            if depth == 0:
                return text[brace_start : pos + 1]
        pos += 1
    return text[brace_start:]


def _has_relocation_marker(asm_text: str) -> bool:
    """Check if an asm line references a symbol that will need relocation.

    Lines with {disp32} marker, direct symbol references, or call targets
    will have 4-byte relocations applied by the linker.
    """
    return "{disp32}" in asm_text or bool(re.search(r"\bcall\s+\?", asm_text))


def _extract_expected_bytes_from_body(body: str) -> tuple[ExpectedByte, ...]:
    """Extract expected bytes from asm comment annotations in a function body."""
    result = []
    for line in body.split("\n"):
        m = _BYTE_COMMENT_RE.search(line)
        if m is None:
            continue
        hex_str = m.group(1)
        raw_bytes = bytes.fromhex(hex_str)

        # Determine if this line has a relocation
        relocated = _has_relocation_marker(line)

        for b in raw_bytes:
            result.append(ExpectedByte(value=b, is_relocated=relocated))

    return tuple(result)


def parse_source_functions(source_path: Path) -> list[SourceFunction]:
    """Parse a C source file and extract all function definitions with expected bytes."""
    text = source_path.read_text()
    functions = []

    for match in _FUNC_DEF_RE.finditer(text):
        mangled_name = match.group(2)
        short_name = _extract_short_name(mangled_name)
        line_num = text[: match.start()].count("\n") + 1
        body = _find_function_body(text, match.end())
        has_asm = "asm(" in body
        expected = _extract_expected_bytes_from_body(body) if has_asm else ()

        functions.append(SourceFunction(
            name=short_name,
            mangled_name=mangled_name,
            has_asm=has_asm,
            expected_bytes=expected,
            source_line=line_num,
        ))

    return functions


# ── Matching & Comparison ────────────────────────────────────────────────────


def _extract_class_name(mangled_name: str) -> str | None:
    """Extract the class name from a Mac-style mangled name.

    E.g. 'GetDrawImportance__9GameThingFv' -> 'GameThing'
         '__dt__23GVillagerStateTableInfoFv' -> 'GVillagerStateTableInfo'
    """
    m = re.search(r"__(\d+)", mangled_name)
    if m:
        class_len = int(m.group(1))
        class_start = m.end()
        return mangled_name[class_start : class_start + class_len]
    return None


def _find_symbol_for_function(
    coff: CoffInfo, short_name: str, mangled_name: str
) -> CoffSymbol | None:
    """Find the COFF symbol corresponding to a source function.

    Matches by looking for the short function name in MSVC-mangled symbol names.
    The source uses Mac-style mangling (e.g. GetDrawImportance__9GameThingFv)
    while COFF uses MSVC mangling (e.g. ?GetDrawImportance@GameThing@@QAEMXZ).

    Some functions use the Mac-mangled name directly as the COFF symbol
    (with stdcall @N decoration), e.g. @Remove__31LHOrderedLinkedList_9Glocation_Fv@12
    """
    class_name = _extract_class_name(mangled_name)

    # Handle special names: constructors (__ct) and destructors (__dt)
    # MSVC: ??0ClassName@@ = constructor, ??1ClassName@@ = destructor
    # ??_GClassName@@ = scalar deleting destructor
    # ??_DClassName@@ = vbase destructor
    if short_name == "__ct" and class_name:
        prefixes = [f"??0{class_name}@"]
    elif short_name == "__dt" and class_name:
        prefixes = [f"??1{class_name}@", f"??_G{class_name}@", f"??_D{class_name}@"]
    else:
        prefixes = [f"?{short_name}@"]

    # Try exact match on the MSVC name pattern
    candidates = []
    for sym in coff.symbols:
        if sym.section_number <= 0:
            continue
        if any(p in sym.name for p in prefixes):
            candidates.append(sym)

    if len(candidates) == 1:
        return candidates[0]

    if len(candidates) > 1 and class_name:
        # Disambiguate using class name
        for sym in candidates:
            if f"@{class_name}@" in sym.name:
                return sym
        # Still ambiguous: return first match
        return candidates[0]

    if len(candidates) > 1:
        return candidates[0]

    if candidates:
        return candidates[0]

    # Fallback 1: Try matching overloaded functions where the short name
    # has a trailing _N discriminator (e.g. IsTouching_3 -> IsTouching)
    base_name = re.sub(r"_\d+$", "", short_name)
    if base_name != short_name:
        fallback_candidates = [
            sym for sym in coff.symbols
            if sym.section_number > 0 and f"?{base_name}@" in sym.name
        ]
        if len(fallback_candidates) == 1:
            return fallback_candidates[0]
        if len(fallback_candidates) > 1 and class_name:
            for sym in fallback_candidates:
                if f"@{class_name}@" in sym.name:
                    return sym

    # Fallback 2: Try matching by the full Mac-mangled name as COFF symbol.
    # Some functions (stdcall, non-MSVC mangled) use patterns like:
    #   @FuncName__ClassName...@N  or  _FuncName__ClassName...
    for sym in coff.symbols:
        if sym.section_number <= 0:
            continue
        # Strip leading @ or _ and trailing @N from COFF symbol
        sym_stripped = sym.name.lstrip("@_")
        sym_stripped = re.sub(r"@\d+$", "", sym_stripped)
        if sym_stripped == mangled_name:
            return sym

    # Fallback 3: Try matching by the short name embedded anywhere in the
    # symbol name (for unusual mangling schemes like FUN_XXXXXXXX)
    if short_name.startswith("FUN_"):
        for sym in coff.symbols:
            if sym.section_number > 0 and short_name in sym.name:
                return sym

    return None


def _get_function_size(coff: CoffInfo, symbol: CoffSymbol) -> int:
    """Determine the size of a function by finding the next symbol in the same section."""
    same_section = sorted(
        (s for s in coff.symbols if s.section_number == symbol.section_number and s.value > symbol.value),
        key=lambda s: s.value,
    )
    if same_section:
        return same_section[0].value - symbol.value

    # Last function in section: use remaining section data
    return len(coff.text_section.raw_data) - symbol.value


def _get_relocations_for_range(
    coff: CoffInfo, start: int, size: int
) -> set[int]:
    """Get the set of byte offsets within [start, start+size) that are relocated.

    Each relocation covers 4 bytes (for DIR32 and REL32 types).
    Returns offsets relative to `start`.
    """
    relocated_offsets = set()
    for rel in coff.text_section.relocations:
        if rel.type not in FOUR_BYTE_RELOC_TYPES:
            continue
        rel_start = rel.virtual_address
        rel_end = rel_start + 4
        # Check overlap with our range
        if rel_end > start and rel_start < start + size:
            for off in range(max(0, rel_start - start), min(size, rel_end - start)):
                relocated_offsets.add(off)
    return relocated_offsets


@dataclass(frozen=True)
class ByteComparison:
    offset: int
    expected: int
    actual: int
    is_relocated: bool
    matches: bool


@dataclass(frozen=True)
class ComparisonResult:
    function_name: str
    mangled_name: str
    symbol_name: str | None
    source_line: int
    has_asm: bool
    expected_size: int
    actual_size: int
    comparisons: tuple[ByteComparison, ...]
    all_match: bool
    non_reloc_match: bool
    error: str | None


def compare_function(
    source_func: SourceFunction,
    coff: CoffInfo,
) -> ComparisonResult:
    """Compare a source function's expected bytes against actual compiled bytes."""
    if not source_func.has_asm:
        return ComparisonResult(
            function_name=source_func.name,
            mangled_name=source_func.mangled_name,
            symbol_name=None,
            source_line=source_func.source_line,
            has_asm=False,
            expected_size=0,
            actual_size=0,
            comparisons=(),
            all_match=True,
            non_reloc_match=True,
            error="Function has no asm blocks (decompiled C code, nothing to compare)",
        )

    if not source_func.expected_bytes:
        return ComparisonResult(
            function_name=source_func.name,
            mangled_name=source_func.mangled_name,
            symbol_name=None,
            source_line=source_func.source_line,
            has_asm=True,
            expected_size=0,
            actual_size=0,
            comparisons=(),
            all_match=True,
            non_reloc_match=True,
            error="Function has asm blocks but no byte annotations in comments",
        )

    symbol = _find_symbol_for_function(coff, source_func.name, source_func.mangled_name)
    if symbol is None:
        return ComparisonResult(
            function_name=source_func.name,
            mangled_name=source_func.mangled_name,
            symbol_name=None,
            source_line=source_func.source_line,
            has_asm=True,
            expected_size=len(source_func.expected_bytes),
            actual_size=0,
            comparisons=(),
            all_match=False,
            non_reloc_match=False,
            error=f"Symbol not found in object file for '{source_func.name}'",
        )

    func_offset = symbol.value
    func_size = _get_function_size(coff, symbol)
    actual_bytes = coff.text_section.raw_data[func_offset : func_offset + func_size]
    relocated_offsets = _get_relocations_for_range(coff, func_offset, func_size)

    expected = source_func.expected_bytes
    # Trim trailing padding (0xCC or 0x90 int3/nop) from actual bytes
    actual_trimmed_size = len(actual_bytes)
    while actual_trimmed_size > 0 and actual_bytes[actual_trimmed_size - 1] in (0x90, 0xCC):
        actual_trimmed_size -= 1

    compare_len = min(len(expected), actual_trimmed_size)
    comparisons = []
    all_match = True
    non_reloc_match = True

    for i in range(compare_len):
        is_relocated = i in relocated_offsets or expected[i].is_relocated
        matches = expected[i].value == actual_bytes[i]

        if not matches:
            if is_relocated:
                # Relocation differences are expected
                pass
            else:
                all_match = False
                non_reloc_match = False

        comparisons.append(ByteComparison(
            offset=i,
            expected=expected[i].value,
            actual=actual_bytes[i],
            is_relocated=is_relocated,
            matches=matches,
        ))

    # Handle size mismatches
    for i in range(compare_len, len(expected)):
        all_match = False
        non_reloc_match = False
        comparisons.append(ByteComparison(
            offset=i,
            expected=expected[i].value,
            actual=-1,
            is_relocated=expected[i].is_relocated,
            matches=False,
        ))

    for i in range(compare_len, actual_trimmed_size):
        all_match = False
        non_reloc_match = False
        comparisons.append(ByteComparison(
            offset=i,
            expected=-1,
            actual=actual_bytes[i],
            is_relocated=i in relocated_offsets,
            matches=False,
        ))

    return ComparisonResult(
        function_name=source_func.name,
        mangled_name=source_func.mangled_name,
        symbol_name=symbol.name,
        source_line=source_func.source_line,
        has_asm=True,
        expected_size=len(expected),
        actual_size=actual_trimmed_size,
        comparisons=tuple(comparisons),
        all_match=all_match,
        non_reloc_match=non_reloc_match,
        error=None,
    )


# ── Display ──────────────────────────────────────────────────────────────────

# ANSI color codes
_GREEN = "\033[32m"
_RED = "\033[31m"
_YELLOW = "\033[33m"
_CYAN = "\033[36m"
_DIM = "\033[2m"
_BOLD = "\033[1m"
_RESET = "\033[0m"


def _supports_color() -> bool:
    """Check whether stdout supports ANSI colors."""
    if not hasattr(sys.stdout, "isatty"):
        return False
    return sys.stdout.isatty()


def _c(code: str, text: str, use_color: bool) -> str:
    """Apply ANSI color code if color is supported."""
    if use_color:
        return f"{code}{text}{_RESET}"
    return text


def display_result(result: ComparisonResult, verbose: bool = False) -> None:
    """Print a formatted comparison result."""
    color = _supports_color()

    header = f"  {result.function_name} (line {result.source_line})"
    print(f"\n{_c(_BOLD, header, color)}")
    print(f"  Source: {result.mangled_name}")
    if result.symbol_name:
        print(f"  Symbol: {result.symbol_name}")

    if result.error:
        print(f"  {_c(_YELLOW, result.error, color)}")
        return

    print(f"  Expected: {result.expected_size} bytes, Actual: {result.actual_size} bytes")

    if result.non_reloc_match and result.expected_size == result.actual_size:
        print(f"  {_c(_GREEN, 'MATCH (all non-relocated bytes match)', color)}")
        if not verbose:
            return
    elif result.non_reloc_match:
        print(f"  {_c(_YELLOW, 'PARTIAL MATCH (non-relocated bytes match, size differs)', color)}")
    else:
        print(f"  {_c(_RED, 'MISMATCH', color)}")

    # Show byte-by-byte comparison
    BYTES_PER_ROW = 16
    comparisons = result.comparisons
    num_rows = (len(comparisons) + BYTES_PER_ROW - 1) // BYTES_PER_ROW

    print()
    print(f"  {'Offset':<8} {'Expected':<50} {'Actual':<50}")
    print(f"  {'------':<8} {'--------':<50} {'------':<50}")

    for row in range(num_rows):
        start = row * BYTES_PER_ROW
        end = min(start + BYTES_PER_ROW, len(comparisons))
        row_comps = comparisons[start:end]

        expected_parts = []
        actual_parts = []
        has_mismatch = False

        for comp in row_comps:
            exp_str = f"{comp.expected:02x}" if comp.expected >= 0 else "--"
            act_str = f"{comp.actual:02x}" if comp.actual >= 0 else "--"

            if comp.matches:
                expected_parts.append(_c(_DIM, exp_str, color))
                actual_parts.append(_c(_DIM, act_str, color))
            elif comp.is_relocated:
                expected_parts.append(_c(_CYAN, exp_str, color))
                actual_parts.append(_c(_CYAN, act_str, color))
            else:
                has_mismatch = True
                expected_parts.append(_c(_RED, exp_str, color))
                actual_parts.append(_c(_RED, act_str, color))

        offset_str = f"0x{start:04x}"
        marker = _c(_RED, " <<", color) if has_mismatch else ""
        print(f"  {offset_str:<8} {' '.join(expected_parts):<50} {' '.join(actual_parts):<50}{marker}")

    # Legend
    print()
    print(f"  Legend: {_c(_DIM, 'match', color)}  "
          f"{_c(_CYAN, 'relocation (expected difference)', color)}  "
          f"{_c(_RED, 'MISMATCH', color)}")


def display_summary(results: list[ComparisonResult]) -> None:
    """Print a summary of all comparison results."""
    color = _supports_color()

    total = len(results)
    skipped = sum(1 for r in results if r.error and "no asm" in r.error)
    no_annotations = sum(1 for r in results if r.error and "no byte annotations" in r.error)
    errors = sum(1 for r in results if r.error and "no asm" not in r.error and "no byte annotations" not in r.error)
    compared = total - skipped - no_annotations - errors
    matched = sum(1 for r in results if not r.error and r.non_reloc_match)
    mismatched = compared - matched

    print(f"\n{'=' * 70}")
    print(f"  Summary: {total} functions found")
    if skipped > 0:
        print(f"    {_c(_DIM, f'{skipped} skipped (decompiled C, no asm)', color)}")
    if no_annotations > 0:
        print(f"    {_c(_YELLOW, f'{no_annotations} have asm but no byte annotations', color)}")
    if errors > 0:
        print(f"    {_c(_RED, f'{errors} errors', color)}")
    if compared > 0:
        print(f"    {_c(_GREEN, f'{matched} matched', color)}")
        if mismatched > 0:
            print(f"    {_c(_RED, f'{mismatched} mismatched', color)}")
    print(f"{'=' * 70}")


# ── Main ─────────────────────────────────────────────────────────────────────


def resolve_source_path(source_arg: str) -> Path:
    """Resolve the source file path relative to the project root or as absolute."""
    path = Path(source_arg)
    if path.is_absolute() and path.exists():
        return path
    # Try relative to project root
    candidate = PROJECT_ROOT / path
    if candidate.exists():
        return candidate
    # Try relative to cwd
    candidate = Path.cwd() / path
    if candidate.exists():
        return candidate
    raise FileNotFoundError(f"Source file not found: {source_arg}")


def resolve_obj_path(source_path: Path) -> Path:
    """Derive the object file path from the source file path."""
    source_name = source_path.name
    obj_name = f"{source_name}.o"
    obj_path = OBJ_DIR / obj_name
    if not obj_path.exists():
        raise FileNotFoundError(
            f"Object file not found: {obj_path}\n"
            f"Make sure the project has been built (cmake --build cmake-build-presets/release)"
        )
    return obj_path


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Compare compiled function bytes against expected bytes from asm comments.",
        epilog="Examples:\n"
               "  %(prog)s src/c/GameThing.001.c GetDrawImportance\n"
               "  %(prog)s src/c/GameThing.001.c --all\n"
               "  %(prog)s src/c/GameThing.001.c --all --verbose\n",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument("source_file", help="Path to the .c source file")
    parser.add_argument("function_name", nargs="?", help="Function name to compare (omit with --all)")
    parser.add_argument("--all", action="store_true", help="Compare all functions in the file")
    parser.add_argument("--verbose", "-v", action="store_true", help="Show byte details even for matching functions")

    args = parser.parse_args()

    if not args.all and not args.function_name:
        parser.error("Either provide a function name or use --all")

    try:
        source_path = resolve_source_path(args.source_file)
    except FileNotFoundError as e:
        print(f"Error: {e}", file=sys.stderr)
        return 1

    try:
        obj_path = resolve_obj_path(source_path)
    except FileNotFoundError as e:
        print(f"Error: {e}", file=sys.stderr)
        return 1

    # Parse source
    source_functions = parse_source_functions(source_path)
    if not source_functions:
        print(f"No functions found in {source_path}", file=sys.stderr)
        return 1

    # Filter to requested function(s)
    if args.all:
        targets = source_functions
    else:
        targets = [f for f in source_functions if f.name == args.function_name]
        if not targets:
            available = [f.name for f in source_functions]
            print(f"Function '{args.function_name}' not found in {source_path}", file=sys.stderr)
            print(f"Available functions: {', '.join(available)}", file=sys.stderr)
            return 1

    # Parse COFF object
    try:
        coff = parse_coff(obj_path)
    except Exception as e:
        print(f"Error parsing object file {obj_path}: {e}", file=sys.stderr)
        return 1

    color = _supports_color()
    print(f"{_c(_BOLD, f'Comparing: {source_path.name} -> {obj_path.name}', color)}")

    # Compare each target
    results = []
    for func in targets:
        result = compare_function(func, coff)
        results.append(result)
        display_result(result, verbose=args.verbose)

    if len(results) > 1:
        display_summary(results)

    # Return non-zero if any non-relocated mismatches
    has_mismatch = any(
        not r.non_reloc_match
        for r in results
        if r.error is None
    )
    return 1 if has_mismatch else 0


if __name__ == "__main__":
    sys.exit(main())

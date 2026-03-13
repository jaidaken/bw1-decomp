#!/usr/bin/env python3
"""
Find symbol mismatches between staging and target .obj files.

For each objdiff unit, extracts defined .text symbols from both the
staging .obj (MSVC 12.0) and target .obj (reassembled), then identifies
symbols that exist in one side but not the other.

Demangles MSVC names via c++filt and matches by base name (class::method)
to find cases where the same function has different mangled names due to
return type, const qualifier, or parameter type differences.

Usage:
    python3 scripts/decompilation/find_symbol_mismatches.py [--verbose] [--fix-header]
"""

import argparse
import json
import re
import struct
from collections import defaultdict
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent
BUILD_DIR = PROJECT_ROOT / "cmake-build-presets" / "objdiff"
OBJDIFF_CONFIG = BUILD_DIR / "objdiff.json"

# COFF constants
_FILE_HDR_FMT = '<HHIIIHH'
_FILE_HDR_SIZE = struct.calcsize(_FILE_HDR_FMT)
_SYMBOL_SIZE = 18

# COFF section flags
IMAGE_SCN_CNT_CODE = 0x00000020

# COFF symbol storage classes
IMAGE_SYM_CLASS_EXTERNAL = 2
IMAGE_SYM_CLASS_STATIC = 3

# COFF symbol section number special values
IMAGE_SYM_UNDEFINED = 0


def extract_coff_symbols(obj_path: Path) -> dict[str, dict]:
    """Extract all defined function symbols from a COFF .obj file.

    Returns dict of symbol_name -> {section_num, storage_class, value, size}
    """
    try:
        data = obj_path.read_bytes()
    except FileNotFoundError:
        return {}

    if len(data) < _FILE_HDR_SIZE:
        return {}

    (machine, num_sections, timestamp, sym_table_offset,
     num_symbols, opt_hdr_size, characteristics) = struct.unpack_from(_FILE_HDR_FMT, data, 0)

    if sym_table_offset == 0 or num_symbols == 0:
        return {}

    # Parse section headers to identify .text sections
    section_hdr_offset = _FILE_HDR_SIZE + opt_hdr_size
    section_hdr_size = 40
    code_sections = set()
    section_names = {}

    for i in range(num_sections):
        offset = section_hdr_offset + i * section_hdr_size
        if offset + section_hdr_size > len(data):
            break
        name_bytes = data[offset:offset+8]
        null_idx = name_bytes.find(b'\x00')
        if null_idx >= 0:
            sec_name = name_bytes[:null_idx].decode('ascii', errors='replace')
        else:
            sec_name = name_bytes.decode('ascii', errors='replace')
        characteristics = struct.unpack_from('<I', data, offset + 36)[0]
        section_num = i + 1  # 1-based
        section_names[section_num] = sec_name
        if characteristics & IMAGE_SCN_CNT_CODE:
            code_sections.add(section_num)

    # String table
    string_table_offset = sym_table_offset + num_symbols * _SYMBOL_SIZE
    string_table_size = struct.unpack_from('<I', data, string_table_offset)[0] if string_table_offset < len(data) else 4

    def read_symbol_name(sym_offset):
        name_field = data[sym_offset:sym_offset + 8]
        if name_field[:4] == b'\x00\x00\x00\x00':
            str_offset = struct.unpack_from('<I', name_field, 4)[0]
            abs_offset = string_table_offset + str_offset
            null_pos = data.index(b'\x00', abs_offset)
            return data[abs_offset:null_pos].decode('ascii', errors='replace')
        else:
            null_idx = name_field.find(b'\x00')
            if null_idx == -1:
                return name_field.decode('ascii', errors='replace')
            return name_field[:null_idx].decode('ascii', errors='replace')

    symbols = {}
    i = 0
    while i < num_symbols:
        sym_offset = sym_table_offset + i * _SYMBOL_SIZE
        if sym_offset + _SYMBOL_SIZE > len(data):
            break

        name = read_symbol_name(sym_offset)
        value = struct.unpack_from('<I', data, sym_offset + 8)[0]
        section_num = struct.unpack_from('<h', data, sym_offset + 12)[0]
        storage_class = data[sym_offset + 16]
        num_aux = data[sym_offset + 17]

        # Only care about defined symbols in code sections
        if section_num > 0 and section_num in code_sections:
            symbols[name] = {
                'section': section_num,
                'section_name': section_names.get(section_num, '?'),
                'storage_class': storage_class,
                'value': value,
            }

        i += 1 + num_aux

    return symbols


def extract_base_name(mangled: str) -> str | None:
    """Extract the base function name from an MSVC mangled name.

    MSVC mangling: ?Method@Class@@<suffix>
    For nested: ?Method@Class@Namespace@@<suffix>
    For C functions: _name or _name@N (stdcall)

    Returns the qualified name like "Class::Method" or just "name" for C.
    """
    if mangled.startswith('?'):
        # C++ mangled name: ?Method@Class@@suffix
        parts = mangled.split('@@')
        if len(parts) >= 2:
            qualified = parts[0][1:]  # strip leading ?
            # qualified is like "Method@Class" or "Method@Class@Namespace"
            # Reverse to get Class::Method or Namespace::Class::Method
            name_parts = qualified.split('@')
            return '::'.join(reversed(name_parts))
    elif mangled.startswith('_'):
        # C function: _name or _name@N
        name = mangled[1:]
        at_idx = name.find('@')
        if at_idx > 0:
            name = name[:at_idx]
        return name

    return None


def extract_suffix(mangled: str) -> str | None:
    """Extract the type encoding suffix from an MSVC mangled name.

    E.g., ?Foo@Bar@@UAEIXZ -> UAEIXZ
    """
    if mangled.startswith('?'):
        parts = mangled.split('@@')
        if len(parts) >= 2:
            return '@@'.join(parts[1:])
    return None


def classify_mismatch(target_mangled: str, staging_mangled: str,
                       target_demangled: str, staging_demangled: str) -> str:
    """Classify the type of mismatch between two mangled names."""
    # Common MSVC return type codes
    # _N = bool, I = unsigned int, E = unsigned char, M = float
    # H = int, K = unsigned long, X = void, PAV = pointer to class

    if target_mangled == staging_mangled:
        return "EXACT_MATCH"

    # Check if the difference is just return type
    # In MSVC mangling: ?Method@Class@@<access><return_type><params>
    # e.g., ?Foo@Bar@@UAE_NXZ (bool) vs ?Foo@Bar@@UAEIXZ (unsigned int)

    # Find the common prefix up to the access/return segment
    # MSVC pattern: ?name@class@@QAE|UAE|etc + return + params + Z
    t_prefix = target_mangled.split('@@')
    s_prefix = staging_mangled.split('@@')

    if len(t_prefix) >= 2 and len(s_prefix) >= 2:
        if t_prefix[0] == s_prefix[0]:
            # Same function name, different encoding after @@
            t_suffix = '@@'.join(t_prefix[1:])
            s_suffix = '@@'.join(s_prefix[1:])

            # Check for bool vs uint (most common)
            # _N = bool, I = unsigned int
            if t_suffix.replace('_N', 'I') == s_suffix or s_suffix.replace('_N', 'I') == t_suffix:
                return "RETURN_TYPE: bool vs uint"
            if t_suffix.replace('I', '_N') == s_suffix or s_suffix.replace('I', '_N') == t_suffix:
                return "RETURN_TYPE: uint vs bool"

            # Check for bool vs bool32_t in params
            # PAV -> pointer, _N -> bool in params
            if '_N' in t_suffix or '_N' in s_suffix:
                return "TYPE: bool involvement"

            # Check for const qualifier differences
            # QBE = const, QAE = non-const (for thiscall)
            if 'QBE' in t_suffix and 'QAE' in s_suffix:
                return "CONST: target=const, staging=non-const"
            if 'QAE' in t_suffix and 'QBE' in s_suffix:
                return "CONST: target=non-const, staging=const"
            if 'UBE' in t_suffix and 'UAE' in s_suffix:
                return "CONST: target=const, staging=non-const (virtual)"
            if 'UAE' in t_suffix and 'UBE' in s_suffix:
                return "CONST: target=non-const, staging=const (virtual)"

            return f"ENCODING: {t_suffix} vs {s_suffix}"

    return "UNKNOWN"


def main():
    parser = argparse.ArgumentParser(description="Find symbol mismatches between staging and target .obj files")
    parser.add_argument('--verbose', '-v', action='store_true', help='Show detailed mismatch info')
    parser.add_argument('--summary', '-s', action='store_true', help='Show only summary statistics')
    parser.add_argument('--unit', '-u', type=str, help='Only check specific unit (by name prefix)')
    args = parser.parse_args()

    if not OBJDIFF_CONFIG.exists():
        print(f"Error: {OBJDIFF_CONFIG} not found. Run a build first.")
        return

    with open(OBJDIFF_CONFIG) as f:
        config = json.load(f)

    units = config.get('units', config.get('objects', []))

    # Collect all mismatches
    all_mismatches = []
    category_counts = defaultdict(int)
    units_with_mismatches = 0
    total_staging_only = 0
    total_target_only = 0
    total_matched = 0

    for unit in units:
        name = unit.get('name', '')
        if args.unit and not name.startswith(args.unit):
            continue

        target_path = BUILD_DIR / unit.get('target_path', '')
        staging_path = BUILD_DIR / unit.get('base_path', '')

        if not target_path.exists() or not staging_path.exists():
            continue

        target_syms = extract_coff_symbols(target_path)
        staging_syms = extract_coff_symbols(staging_path)

        # Filter to only function symbols (starting with ? for C++ or _ for C)
        target_funcs = {k: v for k, v in target_syms.items()
                       if k.startswith('?') or k.startswith('_')}
        staging_funcs = {k: v for k, v in staging_syms.items()
                        if k.startswith('?') or k.startswith('_')}

        # Find exact matches
        common = set(target_funcs.keys()) & set(staging_funcs.keys())
        staging_only = set(staging_funcs.keys()) - set(target_funcs.keys())
        target_only = set(target_funcs.keys()) - set(staging_funcs.keys())

        total_matched += len(common)
        total_staging_only += len(staging_only)
        total_target_only += len(target_only)

        if not staging_only and not target_only:
            continue

        units_with_mismatches += 1

        # Build base_name -> mangled_name mappings for unmatched symbols
        staging_base = {}
        for sym in staging_only:
            base = extract_base_name(sym)
            if base:
                staging_base.setdefault(base, []).append(sym)

        target_base = {}
        for sym in target_only:
            base = extract_base_name(sym)
            if base:
                target_base.setdefault(base, []).append(sym)

        # Find base name matches (same function, different mangling)
        matched_bases = set(staging_base.keys()) & set(target_base.keys())

        unit_mismatches = []
        for base in sorted(matched_bases):
            for t_sym in target_base[base]:
                for s_sym in staging_base[base]:
                    category = classify_mismatch(
                        t_sym, s_sym, t_sym, s_sym
                    )
                    category_counts[category] += 1
                    unit_mismatches.append({
                        'unit': name,
                        'base_name': base,
                        'target_mangled': t_sym,
                        'staging_mangled': s_sym,
                        'target_suffix': extract_suffix(t_sym) or '',
                        'staging_suffix': extract_suffix(s_sym) or '',
                        'category': category,
                    })

        # Also track truly orphaned symbols (no base name match)
        orphan_staging = staging_only - {s for base in matched_bases for s in staging_base.get(base, [])}
        orphan_target = target_only - {s for base in matched_bases for s in target_base.get(base, [])}

        if unit_mismatches or (args.verbose and (orphan_staging or orphan_target)):
            all_mismatches.extend(unit_mismatches)

            if not args.summary:
                print(f"\n{'='*60}")
                print(f"Unit: {name}")
                print(f"  Matched: {len(common)}, Staging-only: {len(staging_only)}, Target-only: {len(target_only)}")

                for mm in unit_mismatches:
                    print(f"\n  [{mm['category']}] {mm['base_name']}")
                    print(f"    Target:  {mm['target_mangled']}")
                    print(f"    Staging: {mm['staging_mangled']}")

                if args.verbose and orphan_staging:
                    print(f"\n  Staging-only (no match):")
                    for s in sorted(orphan_staging):
                        print(f"    {s} [{extract_base_name(s)}]")

                if args.verbose and orphan_target:
                    print(f"\n  Target-only (no match):")
                    for s in sorted(orphan_target):
                        print(f"    {s} [{extract_base_name(s)}]")

    # Summary
    print(f"\n{'='*60}")
    print(f"SUMMARY")
    print(f"{'='*60}")
    print(f"Total symbol matches:        {total_matched}")
    print(f"Total staging-only symbols:  {total_staging_only}")
    print(f"Total target-only symbols:   {total_target_only}")
    print(f"Units with mismatches:       {units_with_mismatches}")
    print(f"Identified name mismatches:  {len(all_mismatches)}")
    print(f"\nMismatch categories:")
    for cat, count in sorted(category_counts.items(), key=lambda x: -x[1]):
        print(f"  {count:4d}  {cat}")


if __name__ == '__main__':
    main()

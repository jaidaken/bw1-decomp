#!/usr/bin/env python3
"""
Find virtual method groups where the base class uses bool return (_N mangling)
but derived classes use uint32_t return (I mangling) in their asm attributes.

Also finds const+bool mismatches (UBE_N base vs UAEI derived).

Usage: python3 scripts/decompilation/find_mixed_return_virtuals.py
"""

import re
import glob
from collections import defaultdict


def parse_asm_attributes(header_dir="black"):
    """Parse all asm() attributes from headers and extract method info."""
    methods = []

    for hfile in sorted(glob.glob(f"{header_dir}/*.h")):
        with open(hfile) as f:
            content = f.read()

        # Find all asm("?...") attributes with their C declarations
        # Pattern: type __fastcall FuncName__ClassName...(params) asm("?mangled@name");
        for m in re.finditer(
            r'(\w[\w\s\*]+?)\s+__fastcall\s+(\w+)\(([^)]*)\)\s*asm\("(\?[^"]+)"\)',
            content
        ):
            c_return_type = m.group(1).strip()
            func_name_raw = m.group(2)
            params = m.group(3)
            mangled = m.group(4)

            # Parse mangled name: ?MethodName@ClassName@@<calling_convention><return_type>...
            mangled_match = re.match(
                r'\?(\w+)@(\w+)@@(U[AB]E)([_A-Z]+?)(?:PA[UV]\w+@@)*(?:ABU\w+@@)*(?:M|K|I|H|N|G|J|_N)?@?@?Z',
                mangled
            )
            if not mangled_match:
                # Try simpler pattern
                mangled_match = re.match(r'\?(\w+)@(\w+)@@(U[AB]E)(.+?)(?:Z|$)', mangled)

            if mangled_match:
                method_name = mangled_match.group(1)
                class_name = mangled_match.group(2)
            else:
                # Fall back to extracting class/method from mangled name
                parts = mangled.split('@')
                if len(parts) >= 3:
                    method_name = parts[0][1:]  # Remove leading ?
                    class_name = parts[1]
                else:
                    continue

            # Determine return type from mangling
            # UAE_N = virtual bool, UAEI = virtual uint32_t
            # UBE_N = virtual bool const, UBEI = virtual uint32_t const
            is_bool_return = 'UAE_N' in mangled or 'UBE_N' in mangled
            is_uint_return = 'UAEI' in mangled or 'UBEI' in mangled
            is_const = 'UBE' in mangled

            if is_bool_return or is_uint_return:
                methods.append({
                    'method': method_name,
                    'class': class_name,
                    'mangled': mangled,
                    'is_bool': is_bool_return,
                    'is_const': is_const,
                    'c_return': c_return_type,
                    'header': hfile,
                })

    return methods


def find_staging_files(staging_dir="src/staging"):
    """Map class names to staging files that define their methods."""
    class_to_files = defaultdict(set)

    for cpp_file in sorted(glob.glob(f"{staging_dir}/*.cpp")):
        with open(cpp_file) as f:
            content = f.read()

        # Find method definitions: ReturnType ClassName::MethodName(...)
        for m in re.finditer(r'(\w+)\s+(\w+)::(\w+)\s*\(', content):
            class_name = m.group(2)
            class_to_files[class_name].add(cpp_file)

    return class_to_files


def main():
    methods = parse_asm_attributes()
    class_to_files = find_staging_files()

    # Group by method name to find base/derived mismatches
    method_groups = defaultdict(list)
    for m in methods:
        # Create a signature key (method name + rough param pattern)
        key = m['method']
        method_groups[key].append(m)

    # Known base classes (in inheritance order)
    base_classes = {'GameThingWithPos', 'GameThing', 'Object', 'MobileWallHug', 'Fixed'}

    print("=" * 80)
    print("MIXED RETURN TYPE VIRTUAL METHOD GROUPS")
    print("=" * 80)
    print()

    issue1_count = 0
    issue2_count = 0

    for method_name, entries in sorted(method_groups.items()):
        # Check if this group has mixed bool/uint32_t returns
        bool_entries = [e for e in entries if e['is_bool']]
        uint_entries = [e for e in entries if not e['is_bool']]

        if bool_entries and uint_entries:
            # Check if base class has bool and derived has uint32_t
            base_bool = [e for e in bool_entries if e['class'] in base_classes]
            derived_uint = [e for e in uint_entries if e['class'] not in base_classes]

            if base_bool:
                has_const = any(e['is_const'] for e in base_bool)
                issue_type = "Issue 2 (const+bool)" if has_const else "Issue 1 (bool/uint32_t)"
                if has_const:
                    issue2_count += len(base_bool) + len(derived_uint)
                else:
                    issue1_count += len(base_bool) + len(derived_uint)

                print(f"--- {method_name} [{issue_type}] ---")

                for e in sorted(entries, key=lambda x: (x['class'] not in base_classes, x['class'])):
                    role = "BASE" if e['class'] in base_classes else "DERIVED"
                    ret = "bool (_N)" if e['is_bool'] else "uint32_t (I)"
                    const = " const" if e['is_const'] else ""
                    files = class_to_files.get(e['class'], {'(no staging file)'})
                    files_str = ", ".join(sorted(f.split('/')[-1] for f in files))
                    print(f"  {role:8} {e['class']:<25} {ret:<18}{const}")
                    print(f"           mangled: {e['mangled']}")
                    print(f"           staging: {files_str}")
                print()

    print("=" * 80)
    print(f"SUMMARY")
    print(f"  Issue 1 (bool vs uint32_t): ~{issue1_count} function entries")
    print(f"  Issue 2 (const+bool):       ~{issue2_count} function entries")
    print(f"  Total:                      ~{issue1_count + issue2_count}")
    print("=" * 80)


if __name__ == "__main__":
    main()

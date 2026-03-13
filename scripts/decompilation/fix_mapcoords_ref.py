#!/usr/bin/env python3
"""Fix MapCoords const pointer -> const reference mismatches.

Changes `const MapCoords*` to `const MapCoords&` in C++ header declarations
and staging implementations, where the asm label uses ABU (reference) not PBU (pointer).

This only fixes the C++ sections of headers and the staging .cpp files.
The C sections of headers are left alone since the asm() labels are already correct.
"""

import re
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent
HEADERS_DIR = PROJECT_ROOT / "black"
STAGING_DIR = PROJECT_ROOT / "src" / "staging"


def fix_header_cpp_section(header_path: Path) -> int:
    """Fix const MapCoords* -> const MapCoords& in C++ section of header.

    Only changes declarations where the asm label has ABUMapCoords (reference).
    Returns number of changes made.
    """
    text = header_path.read_text()

    # Split into C++ section and C section
    cpp_start = text.find('#ifdef __cplusplus')
    cpp_end = text.find('#else // __cplusplus')
    if cpp_start == -1 or cpp_end == -1:
        return 0

    c_section = text[cpp_end:]
    cpp_section = text[cpp_start:cpp_end]

    # Find methods in C section that have ABUMapCoords in their asm label
    # Pattern: asm("?MethodName@Class@@...ABUMapCoords...@Z");
    methods_with_ref = set()
    for match in re.finditer(r'asm\("(\?[^"]+ABUMapCoords[^"]+)"\)', c_section):
        label = match.group(1)
        # Extract method name: ?MethodName@Class@@... -> MethodName
        parts = label.split('@@')
        if parts:
            qualified = parts[0][1:]  # strip ?
            method = qualified.split('@')[0]
            methods_with_ref.add(method)

    if not methods_with_ref:
        return 0

    changes = 0
    new_lines = []
    for line in cpp_section.split('\n'):
        original = line
        # Check if this line declares a method that should use reference
        for method in methods_with_ref:
            # Match patterns like: method_name(const MapCoords*
            # But be careful to only replace MapCoords specifically
            pattern = rf'(\b{re.escape(method)}\b.*?)\bconst MapCoords\*'
            if re.search(pattern, line):
                line = re.sub(
                    r'\bconst MapCoords\*(\s*)',
                    r'const MapCoords&\1',
                    line,
                    count=1  # Only first occurrence per line
                )
                if line != original:
                    changes += 1
        new_lines.append(line)

    if changes:
        new_cpp = '\n'.join(new_lines)
        new_text = text[:cpp_start] + new_cpp + text[cpp_end:]
        header_path.write_text(new_text)

    return changes


def fix_staging_file(staging_path: Path, header_methods: dict) -> int:
    """Fix const MapCoords* -> const MapCoords& in staging .cpp file.

    header_methods: dict of class_name -> set of method_names that use reference.
    Returns number of changes made.
    """
    text = staging_path.read_text()
    changes = 0
    new_lines = []

    for line in text.split('\n'):
        original = line
        # Match method definitions like: void ClassName::MethodName(const MapCoords* param)
        for class_name, methods in header_methods.items():
            for method in methods:
                pattern = rf'(\b{re.escape(class_name)}::{re.escape(method)}\b.*?)\bconst MapCoords\*'
                if re.search(pattern, line):
                    line = re.sub(
                        r'\bconst MapCoords\*(\s*)',
                        r'const MapCoords&\1',
                        line,
                        count=1
                    )
                    if line != original:
                        changes += 1
                        break
            if line != original:
                break
        new_lines.append(line)

    if changes:
        staging_path.write_text('\n'.join(new_lines))

    return changes


def main():
    # Step 1: Find all methods in headers that have ABUMapCoords in asm labels
    # Build mapping: class_name -> set of method_names
    header_methods = {}
    total_header_changes = 0

    for header in sorted(HEADERS_DIR.glob("*.h")):
        text = header.read_text()

        cpp_end = text.find('#else // __cplusplus')
        if cpp_end == -1:
            continue

        c_section = text[cpp_end:]

        # Find methods with ABUMapCoords in asm labels
        methods = set()
        for match in re.finditer(r'asm\("(\?([^@]+)@([^@]+)@[^"]*ABUMapCoords[^"]+)"\)', c_section):
            method_name = match.group(2)
            class_name = match.group(3)
            methods.add(method_name)
            header_methods.setdefault(class_name, set()).add(method_name)

        if methods:
            changes = fix_header_cpp_section(header)
            if changes:
                total_header_changes += changes
                print(f"  Header: {header.name}: {changes} changes ({', '.join(sorted(methods))})")

    print(f"\nTotal header changes: {total_header_changes}")

    # Step 2: Fix staging .cpp files
    total_staging_changes = 0
    for staging in sorted(STAGING_DIR.glob("*.cpp")):
        changes = fix_staging_file(staging, header_methods)
        if changes:
            total_staging_changes += changes
            print(f"  Staging: {staging.name}: {changes} changes")

    print(f"\nTotal staging changes: {total_staging_changes}")
    print(f"\nGrand total: {total_header_changes + total_staging_changes} changes")


if __name__ == '__main__':
    main()

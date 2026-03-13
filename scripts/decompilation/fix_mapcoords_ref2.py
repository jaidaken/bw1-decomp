#!/usr/bin/env python3
"""Fix remaining const MapCoords* -> const MapCoords& in C++ sections.

Direct approach: find all lines in C++ sections with 'const MapCoords*' that
correspond to methods with ABUMapCoords in their asm labels.
"""

import re
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent
HEADERS_DIR = PROJECT_ROOT / "black"
STAGING_DIR = PROJECT_ROOT / "src" / "staging"


def get_ref_methods(header_path: Path) -> set[str]:
    """Get method names that use ABUMapCoords in asm labels."""
    text = header_path.read_text()
    cpp_end = text.find('#else // __cplusplus')
    if cpp_end == -1:
        return set()

    c_section = text[cpp_end:]
    methods = set()
    for match in re.finditer(r'asm\("\?([^@]+)@[^"]*ABUMapCoords[^"]*"\)', c_section):
        methods.add(match.group(1))
    return methods


def fix_file(filepath: Path, methods: set[str]) -> int:
    """Replace const MapCoords* -> const MapCoords& for given methods."""
    text = filepath.read_text()
    lines = text.split('\n')
    changes = 0

    for i, line in enumerate(lines):
        if 'const MapCoords*' not in line:
            continue
        # Check if any target method name is on this line
        for method in methods:
            if method in line:
                new_line = line.replace('const MapCoords*', 'const MapCoords&', 1)
                if new_line != line:
                    lines[i] = new_line
                    changes += 1
                break

    if changes:
        filepath.write_text('\n'.join(lines))
    return changes


def main():
    # Collect ALL methods with ABUMapCoords from all headers
    all_methods = set()
    per_header_methods = {}

    for header in sorted(HEADERS_DIR.glob("*.h")):
        methods = get_ref_methods(header)
        if methods:
            per_header_methods[header.name] = methods
            all_methods.update(methods)

    # Fix C++ sections of headers (only between #ifdef __cplusplus and #else)
    total = 0
    for header in sorted(HEADERS_DIR.glob("*.h")):
        text = header.read_text()
        cpp_start = text.find('#ifdef __cplusplus')
        cpp_end = text.find('#else // __cplusplus')
        if cpp_start == -1 or cpp_end == -1:
            continue

        cpp_section = text[cpp_start:cpp_end]
        lines = cpp_section.split('\n')
        changes = 0

        for i, line in enumerate(lines):
            if 'const MapCoords*' not in line:
                continue
            for method in all_methods:
                if method in line:
                    new_line = line.replace('const MapCoords*', 'const MapCoords&', 1)
                    if new_line != line:
                        lines[i] = new_line
                        changes += 1
                    break

        if changes:
            new_cpp = '\n'.join(lines)
            new_text = text[:cpp_start] + new_cpp + text[cpp_end:]
            header.write_text(new_text)
            total += changes
            print(f"  {header.name}: {changes}")

    print(f"Header fixes: {total}")

    # Fix staging files
    stotal = 0
    for staging in sorted(STAGING_DIR.glob("*.cpp")):
        changes = fix_file(staging, all_methods)
        if changes:
            stotal += changes
            print(f"  {staging.name}: {changes}")

    print(f"Staging fixes: {stotal}")
    print(f"Grand total: {total + stotal}")


if __name__ == '__main__':
    main()

#!/usr/bin/env python3
"""Fix const MapCoords* -> const MapCoords& in C++ sections and staging.

Uses class+method pairs from asm labels with ABUMapCoords to identify
which declarations need changing.
"""

import re
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent
HEADERS_DIR = PROJECT_ROOT / "black"
STAGING_DIR = PROJECT_ROOT / "src" / "staging"


def collect_ref_pairs() -> dict[str, set[str]]:
    """Collect class->method pairs that use ABUMapCoords from all header asm labels.

    Returns dict of class_name -> set of method_names.
    """
    pairs = {}
    for header in HEADERS_DIR.glob("*.h"):
        text = header.read_text()
        cpp_end = text.find('#else // __cplusplus')
        if cpp_end == -1:
            continue

        c_section = text[cpp_end:]
        for match in re.finditer(r'asm\("\?([^@]+)@([^@]+)@@[^"]*ABUMapCoords[^"]*"\)', c_section):
            method = match.group(1)
            cls = match.group(2)
            pairs.setdefault(cls, set()).add(method)

    return pairs


def fix_headers(pairs: dict[str, set[str]]) -> int:
    """Fix C++ section declarations using class+method pairs."""
    # For headers, we need to match virtual declarations.
    # The line may not contain the class name (it's implied by the class scope).
    # So we need to know which class each header defines and use that.
    total = 0
    all_methods = set()
    for methods in pairs.values():
        all_methods.update(methods)

    for header in sorted(HEADERS_DIR.glob("*.h")):
        text = header.read_text()
        cpp_start = text.find('#ifdef __cplusplus')
        cpp_end = text.find('#else // __cplusplus')
        if cpp_start == -1 or cpp_end == -1:
            continue

        c_section = text[cpp_end:]
        cpp_section = text[cpp_start:cpp_end]

        # Find which methods THIS header's classes have with ABUMapCoords
        header_methods = set()
        for match in re.finditer(r'asm\("\?([^@]+)@[^@]+@@[^"]*ABUMapCoords[^"]*"\)', c_section):
            header_methods.add(match.group(1))

        if not header_methods:
            continue

        lines = cpp_section.split('\n')
        changes = 0
        for i, line in enumerate(lines):
            if 'const MapCoords*' not in line:
                continue
            for method in header_methods:
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

    return total


def fix_staging(pairs: dict[str, set[str]]) -> int:
    """Fix staging .cpp files using class::method pairs."""
    total = 0
    for staging in sorted(STAGING_DIR.glob("*.cpp")):
        text = staging.read_text()
        lines = text.split('\n')
        changes = 0

        for i, line in enumerate(lines):
            if 'const MapCoords*' not in line:
                continue
            # Match ClassName::MethodName pattern
            for cls, methods in pairs.items():
                for method in methods:
                    # Check for Class::Method( in the line
                    if f'{cls}::{method}' in line:
                        new_line = line.replace('const MapCoords*', 'const MapCoords&', 1)
                        if new_line != line:
                            lines[i] = new_line
                            changes += 1
                        break
                if lines[i] != line:
                    break

        if changes:
            staging.write_text('\n'.join(lines))
            total += changes
            print(f"  {staging.name}: {changes}")

    return total


def main():
    pairs = collect_ref_pairs()
    print(f"Found {sum(len(v) for v in pairs.values())} class::method pairs with ABUMapCoords")
    print(f"Classes: {len(pairs)}")

    print("\nFixing headers:")
    h = fix_headers(pairs)
    print(f"Header total: {h}")

    print("\nFixing staging:")
    s = fix_staging(pairs)
    print(f"Staging total: {s}")

    print(f"\nGrand total: {h + s}")


if __name__ == '__main__':
    main()

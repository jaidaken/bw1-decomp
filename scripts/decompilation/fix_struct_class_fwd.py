#!/usr/bin/env python3
"""
Fix struct/class forward declarations in C++ sections of dual-section headers.

Only modifies the C++ section (between #ifdef __cplusplus and #else).
The C section forward declarations remain unchanged.

Usage:
    python3 scripts/decompilation/fix_struct_class_fwd.py [--dry-run]
"""

import re
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent
HEADER_DIR = PROJECT_ROOT / "black"

# Types that need 'class' in C++ forward declarations (target uses PAV/V)
NEED_CLASS = [
    "WorshipSite",
    "Citadel",
    "SpellEventInfo",
    "Reaction",
]

# Types that need 'struct' in C++ forward declarations (target uses PAU/U)
NEED_STRUCT = [
    "ControlHandUpdateInfo",
    "RPHolder",
    "PSysProcessInfo",
    "EffectNumbers",
]

# Types previously tried as struct but are actually class in most target TUs
# (reverted): Reaction (target has PAV/class in ~190 functions, only 1 has PAU/struct)


def fix_header(path: Path, dry_run: bool = False) -> list[str]:
    """Fix forward declarations in a single header file.

    Returns list of changes made.
    """
    text = path.read_text()
    lines = text.split('\n')
    changes = []

    # Find the C++ section boundaries
    cpp_start = None
    cpp_end = None
    for i, line in enumerate(lines):
        if line.strip() == '#ifdef __cplusplus':
            cpp_start = i
        elif line.strip().startswith('#else') and cpp_start is not None:
            cpp_end = i
            break

    if cpp_start is None or cpp_end is None:
        return changes

    modified = False
    new_lines = list(lines)

    for i in range(cpp_start, cpp_end):
        line = new_lines[i]

        # Check for types that need 'class' (currently 'struct')
        for type_name in NEED_CLASS:
            old = f"struct {type_name};"
            new = f"class {type_name};"
            if line.strip() == old:
                new_lines[i] = line.replace(old, new)
                changes.append(f"  {path.name}:{i+1}: {old} -> {new}")
                modified = True

        # Check for types that need 'struct' (currently 'class')
        for type_name in NEED_STRUCT:
            old = f"class {type_name};"
            new = f"struct {type_name};"
            if line.strip() == old:
                new_lines[i] = line.replace(old, new)
                changes.append(f"  {path.name}:{i+1}: {old} -> {new}")
                modified = True

    if modified and not dry_run:
        path.write_text('\n'.join(new_lines))

    return changes


def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('--dry-run', action='store_true')
    args = parser.parse_args()

    total_changes = 0
    for header in sorted(HEADER_DIR.glob("*.h")):
        changes = fix_header(header, args.dry_run)
        if changes:
            print(f"\n{header.name}:")
            for c in changes:
                print(c)
            total_changes += len(changes)

    action = "Would change" if args.dry_run else "Changed"
    print(f"\n{action} {total_changes} forward declarations")


if __name__ == '__main__':
    main()

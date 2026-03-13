#!/usr/bin/env python3

"""Apply all scalar deleting destructor patches to their staging files."""

import pathlib
import sys


def main():
    project_root = pathlib.Path(__file__).parent.parent.parent
    patch_dir = pathlib.Path(__file__).parent / "sdtor_generated"
    staging_dir = project_root / "src" / "staging"

    patches = sorted(patch_dir.glob("*.patch"))
    if not patches:
        print("No .patch files found in", patch_dir)
        return 1

    applied = 0
    skipped = 0
    for patch_file in patches:
        # Patch filename: runblack.reassemble.XXXX.ADDR-ADDR.cpp.patch
        # Staging filename: runblack.reassemble.XXXX.ADDR-ADDR.cpp
        staging_name = patch_file.stem  # removes .patch suffix
        staging_file = staging_dir / staging_name

        if not staging_file.exists():
            print(f"SKIP: staging file not found: {staging_file}")
            skipped += 1
            continue

        patch_content = patch_file.read_text()
        with open(staging_file, "a") as f:
            f.write(patch_content)
        applied += 1
        print(f"OK: {staging_name}")

    print(f"\nDone: {applied} applied, {skipped} skipped out of {len(patches)} patches")
    return 0


if __name__ == "__main__":
    sys.exit(main())

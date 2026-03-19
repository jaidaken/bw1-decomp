#!/usr/bin/env python3
"""Replace stub files in the game directory with real files from the ISO cab extract.

Source: extracted cab from the original Black & White ISO
Destination: Black_&_White/ game directory

Rules:
- Only replace files where the cab version is LARGER (replacing stubs with real files)
- Copy files that don't exist in the destination
- Do NOT replace runblack.exe or any project-built executables
- Report all actions taken
"""

import os
import shutil
import sys
from pathlib import Path

CAB_ROOT = Path("/home/jaidaken/Downloads/Black-White_Win_EN_ISO-Version (1)/extracted_cab")
GAME_ROOT = Path("/home/jaidaken/bw1-decomp/Black_&_White")

# Mapping from cab directory name -> destination path relative to GAME_ROOT
# Files inside each cab dir are copied to the corresponding destination dir,
# preserving any subdirectory structure within the cab dir.
DIRECTORY_MAP = {
    "Audio":                "Audio",
    "Audio_-_English":      "Audio/Dialogue",
    "BODGE_JC":             "Data/Misc",
    "Citadel":              "Data/Citadel",
    "CreatureCave_Html":    "Data/CreatureCave_Html",
    "CreatureMesh":         "Data/CreatureMesh",
    "CTR":                  "Data/CTR",
    "Data":                 "Scripts",
    "Font_-_Europe":        "Data",
    "HandDemo":             "Data/HandDemo",
    "HelpSprite":           "Data/HelpSprite",
    "Immersion":            "Data/Immersion",
    "Landscape":            "Data/Landscape",
    "Language":             "Data/Language",
    "logo_-_english":       "Data",
    "Online_Maps":          "Online Maps",
    "Other_Graphics":       "Data",
    "Plugins":              "Plug Ins",
    "PreIntro":             "Data",
    "Program_Files":        "",  # game root
    "readme_-_usa":         "",  # game root
    "Spells":               "Data/Spells",
    "Symbols":              "Data/Symbols",
    "TextScript_-_USA":     "Scripts",
    "Textures":             "Data/Textures",
    "WeatherSystem":        "Data/WeatherSystem",
    "WorkStuff":            "",  # game root (CreatureUpload.exe)
    "Zones":                "Data/Zones",
}

# Files to NEVER replace (case-insensitive basename matching)
SKIP_BASENAMES = {
    "runblack.exe",
    "runblack-reassembled.exe",
    "runblack-wine-fix.exe",
    "runblack-wine-fix-veh.exe",
}

# Directories to skip entirely (installer/setup stuff, not game content)
SKIP_CAB_DIRS = {
    "_Engine_Engine_Files",
    "_Engine_Kernel_Placeholder",
    "_Engine_ScriptEngine",
    "_Engine_SelfRegistering",
    "_Support_English_Files",
    "_Support_English_OS_Independent_Files",
    "_Support_English_String_Tables",
    "_Support_Language_Independent_Intel_32_Files",
    "_Support_Language_Independent_OS_Independent_Files",
    "_Support_Non-SelfRegistering",
    "Setup_Program",
}


def should_skip_file(basename: str) -> bool:
    """Check if a file should be skipped."""
    if basename.lower() in SKIP_BASENAMES:
        return True
    return False


def main():
    dry_run = "--dry-run" in sys.argv
    if dry_run:
        print("=== DRY RUN MODE (no files will be copied) ===\n")

    stats = {
        "replaced_stubs": 0,
        "new_files": 0,
        "skipped_same_or_smaller": 0,
        "skipped_protected": 0,
        "skipped_same_size": 0,
        "errors": 0,
        "total_bytes_copied": 0,
    }

    replaced_details = []
    new_details = []
    skipped_protected_details = []

    for cab_dir_name, dest_rel in sorted(DIRECTORY_MAP.items()):
        cab_dir = CAB_ROOT / cab_dir_name
        if not cab_dir.is_dir():
            print(f"WARNING: Cab directory not found: {cab_dir}")
            continue

        dest_base = GAME_ROOT / dest_rel if dest_rel else GAME_ROOT

        # Walk all files in the cab directory
        for root, dirs, files in os.walk(cab_dir):
            root_path = Path(root)
            # Relative path within the cab directory (preserving subdirs)
            rel_in_cab = root_path.relative_to(cab_dir)

            for filename in sorted(files):
                cab_file = root_path / filename
                dest_file = dest_base / rel_in_cab / filename

                if should_skip_file(filename):
                    stats["skipped_protected"] += 1
                    skipped_protected_details.append(str(dest_file.relative_to(GAME_ROOT)))
                    continue

                cab_size = cab_file.stat().st_size
                if cab_size == 0:
                    # Skip zero-byte placeholder files
                    continue

                if dest_file.exists():
                    dest_size = dest_file.stat().st_size
                    if cab_size > dest_size:
                        # Cab file is larger -> replace stub
                        size_ratio = cab_size / dest_size if dest_size > 0 else float('inf')
                        detail = (
                            f"  {dest_file.relative_to(GAME_ROOT)}: "
                            f"{dest_size:>12,} -> {cab_size:>12,} bytes "
                            f"({size_ratio:.1f}x larger)"
                        )
                        replaced_details.append(detail)

                        if not dry_run:
                            dest_file.parent.mkdir(parents=True, exist_ok=True)
                            shutil.copy2(str(cab_file), str(dest_file))

                        stats["replaced_stubs"] += 1
                        stats["total_bytes_copied"] += cab_size
                    elif cab_size == dest_size:
                        stats["skipped_same_size"] += 1
                    else:
                        # Cab file is smaller -> keep existing (could be patched version)
                        stats["skipped_same_or_smaller"] += 1
                else:
                    # File doesn't exist in destination -> copy it
                    detail = (
                        f"  {dest_file.relative_to(GAME_ROOT)}: "
                        f"NEW ({cab_size:>12,} bytes)"
                    )
                    new_details.append(detail)

                    if not dry_run:
                        dest_file.parent.mkdir(parents=True, exist_ok=True)
                        shutil.copy2(str(cab_file), str(dest_file))

                    stats["new_files"] += 1
                    stats["total_bytes_copied"] += cab_size

    # Print report
    print("=" * 70)
    print("STUB REPLACEMENT REPORT")
    print("=" * 70)

    if replaced_details:
        print(f"\nReplaced stubs ({stats['replaced_stubs']} files):")
        for d in replaced_details:
            print(d)

    if new_details:
        print(f"\nNew files copied ({stats['new_files']} files):")
        for d in new_details:
            print(d)

    if skipped_protected_details:
        print(f"\nSkipped (protected) ({stats['skipped_protected']} files):")
        for d in skipped_protected_details:
            print(f"  {d}")

    print(f"\n{'=' * 70}")
    print(f"Summary:")
    print(f"  Replaced stubs:           {stats['replaced_stubs']:>6}")
    print(f"  New files copied:         {stats['new_files']:>6}")
    print(f"  Skipped (same size):      {stats['skipped_same_size']:>6}")
    print(f"  Skipped (cab smaller):    {stats['skipped_same_or_smaller']:>6}")
    print(f"  Skipped (protected):      {stats['skipped_protected']:>6}")
    print(f"  Total bytes copied:       {stats['total_bytes_copied']:>14,}")
    print(f"  Total MB copied:          {stats['total_bytes_copied'] / (1024*1024):>10.1f} MB")
    print(f"{'=' * 70}")

    if dry_run:
        print("\n=== DRY RUN COMPLETE (no files were actually copied) ===")
        print("Run without --dry-run to perform the actual copy.")


if __name__ == "__main__":
    main()

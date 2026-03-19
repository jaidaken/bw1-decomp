#!/usr/bin/env python3
"""Batch apply conversions and verify MD5 with binary search on failure.

Takes a list of patch operations (file modifications), applies them all,
builds, checks MD5. If MD5 fails, uses binary search to find which
conversion(s) broke it.

Usage:
    # As a library (called from auto_convert.py):
    from batch_verify import batch_apply_and_verify
    results = batch_apply_and_verify(patches)

    # Standalone: apply patches from JSON file
    python3 scripts/decompilation/batch_verify.py patches.json
"""

import json
import shutil
import subprocess
import sys
from dataclasses import asdict, dataclass
from pathlib import Path

TARGET_MD5 = "174b1a64e74b2321f3c38ccc8a511e78"
PROJECT_ROOT = Path(__file__).parent.parent.parent


@dataclass
class Patch:
    """A single file modification."""
    file: str          # relative to project root
    function: str      # function name for identification
    old_text: str      # exact text to replace
    new_text: str      # replacement text
    description: str = ""


@dataclass
class PatchResult:
    function: str
    file: str
    success: bool
    error: str = ""


def build_and_check_md5() -> tuple[bool, str]:
    """Build the project and check MD5. Returns (matches, md5_or_error)."""
    result = subprocess.run(
        ["cmake", "--workflow", "--preset", "release"],
        capture_output=True,
        text=True,
        cwd=PROJECT_ROOT,
        timeout=300,
    )

    if result.returncode != 0:
        # Combine stdout and stderr for error info
        error_text = result.stderr[-500:] if result.stderr else result.stdout[-500:]
        return False, f"Build failed: {error_text}"

    # Extract MD5 from output
    for line in result.stdout.splitlines():
        if "md5sum" in line.lower() or len(line.strip()) == 32 + 2 + len("runblack"):
            parts = line.strip().split()
            if parts and len(parts[0]) == 32:
                md5 = parts[0]
                return md5 == TARGET_MD5, md5

    # Try computing MD5 directly
    exe_path = PROJECT_ROOT / "cmake-build-presets" / "release" / "runblack-reassembled.exe"
    if exe_path.exists():
        md5_result = subprocess.run(
            ["md5sum", str(exe_path)], capture_output=True, text=True
        )
        md5 = md5_result.stdout.strip().split()[0]
        return md5 == TARGET_MD5, md5

    return False, "Could not determine MD5"


def apply_patch(patch: Patch) -> bool:
    """Apply a single patch. Returns True on success."""
    filepath = PROJECT_ROOT / patch.file
    if not filepath.exists():
        return False

    text = filepath.read_text()
    if patch.old_text not in text:
        return False

    new_text = text.replace(patch.old_text, patch.new_text, 1)
    filepath.write_text(new_text)
    return True


def revert_patch(patch: Patch) -> bool:
    """Revert a single patch. Returns True on success."""
    filepath = PROJECT_ROOT / patch.file
    if not filepath.exists():
        return False

    text = filepath.read_text()
    if patch.new_text not in text:
        return False

    new_text = text.replace(patch.new_text, patch.old_text, 1)
    filepath.write_text(new_text)
    return True


def binary_search_failures(patches: list[Patch]) -> list[PatchResult]:
    """Binary search to find which patches cause MD5 mismatch.

    Assumes all patches are currently applied and MD5 doesn't match.
    Returns results for each patch.
    """
    if len(patches) <= 1:
        # Base case: this single patch is the problem
        return [
            PatchResult(
                function=p.function,
                file=p.file,
                success=False,
                error="MD5 mismatch",
            )
            for p in patches
        ]

    mid = len(patches) // 2
    first_half = patches[:mid]
    second_half = patches[mid:]

    # Revert second half, test first half alone
    for p in second_half:
        revert_patch(p)

    matches, md5 = build_and_check_md5()

    if matches:
        # First half is good, problem is in second half
        results_first = [
            PatchResult(function=p.function, file=p.file, success=True)
            for p in first_half
        ]
        # Re-apply second half for further bisection
        for p in second_half:
            apply_patch(p)
        # Revert first half to isolate
        for p in first_half:
            revert_patch(p)

        matches2, _ = build_and_check_md5()

        # Re-apply first half (known good)
        for p in first_half:
            apply_patch(p)

        if not matches2:
            # Second half alone fails, recurse
            results_second = binary_search_failures(second_half)
        else:
            # Interaction between halves? Mark all second half as failed
            results_second = [
                PatchResult(function=p.function, file=p.file, success=False, error="MD5 mismatch (interaction)")
                for p in second_half
            ]
        return results_first + results_second
    else:
        # First half alone fails, re-apply second half, recurse into first
        for p in second_half:
            apply_patch(p)

        # Revert first half to test second half alone
        for p in first_half:
            revert_patch(p)

        matches2, _ = build_and_check_md5()

        # Re-apply first half
        for p in first_half:
            apply_patch(p)

        if matches2:
            # Only first half is bad
            results_first = binary_search_failures(first_half)
            results_second = [
                PatchResult(function=p.function, file=p.file, success=True)
                for p in second_half
            ]
        else:
            # Both halves have problems
            results_first = binary_search_failures(first_half)
            results_second = binary_search_failures(second_half)

        return results_first + results_second


def batch_apply_and_verify(patches: list[Patch], revert_failures: bool = True) -> list[PatchResult]:
    """Apply all patches, build, verify MD5. Binary search on failure.

    Args:
        patches: List of patches to apply
        revert_failures: If True, revert patches that cause MD5 mismatch

    Returns:
        List of results for each patch
    """
    if not patches:
        return []

    # Back up original files
    backup = {}
    for patch in patches:
        filepath = PROJECT_ROOT / patch.file
        if filepath.exists() and str(filepath) not in backup:
            backup[str(filepath)] = filepath.read_text()

    # Apply all patches
    applied = []
    for patch in patches:
        if apply_patch(patch):
            applied.append(patch)
        else:
            print(f"  WARNING: Could not apply patch for {patch.function} in {patch.file}")

    if not applied:
        return [
            PatchResult(function=p.function, file=p.file, success=False, error="Could not apply patch")
            for p in patches
        ]

    # Build and check
    print(f"  Building with {len(applied)} patches applied...")
    matches, md5 = build_and_check_md5()

    if matches:
        print(f"  MD5 MATCHES! All {len(applied)} patches are good.")
        return [
            PatchResult(function=p.function, file=p.file, success=True)
            for p in applied
        ]

    print(f"  MD5 MISMATCH: got {md5}, expected {TARGET_MD5}")
    print(f"  Starting binary search across {len(applied)} patches...")

    # Binary search for failures
    results = binary_search_failures(applied)

    if revert_failures:
        # Revert failed patches
        for result in results:
            if not result.success:
                matching_patches = [p for p in applied if p.function == result.function]
                for p in matching_patches:
                    revert_patch(p)
                print(f"  REVERTED: {result.function} ({result.error})")

        # Final verify after reverting failures
        good_count = sum(1 for r in results if r.success)
        if good_count > 0:
            print(f"  Verifying {good_count} remaining patches...")
            final_match, final_md5 = build_and_check_md5()
            if not final_match:
                print(f"  WARNING: Still mismatched after reverting failures! Restoring all backups.")
                for path, content in backup.items():
                    Path(path).write_text(content)
                return [
                    PatchResult(function=p.function, file=p.file, success=False, error="Batch failure")
                    for p in patches
                ]

    return results


def main():
    if len(sys.argv) < 2:
        print("Usage: python3 batch_verify.py patches.json")
        print("  patches.json: [{file, function, old_text, new_text, description}, ...]")
        sys.exit(1)

    patches_file = Path(sys.argv[1])
    patches_data = json.loads(patches_file.read_text())
    patches = [Patch(**p) for p in patches_data]

    print(f"Loaded {len(patches)} patches from {patches_file}")
    results = batch_apply_and_verify(patches)

    success = sum(1 for r in results if r.success)
    failed = sum(1 for r in results if not r.success)
    print(f"\nResults: {success} success, {failed} failed")

    for r in results:
        status = "OK" if r.success else f"FAIL: {r.error}"
        print(f"  {r.function}: {status}")


if __name__ == "__main__":
    main()

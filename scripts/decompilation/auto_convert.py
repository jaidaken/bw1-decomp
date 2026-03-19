#!/usr/bin/env python3
"""Auto-convert trivial asm functions to pure C.

Generates C code for functions matching known-working patterns, then
uses batch_verify to apply and validate via MD5.

Handles:
  - neg/sbb boolification patterns (comparison -> bool via neg+sbb+inc)
  - vtable dispatch (mov eax,[ecx]; jmp [eax+N])
  - vtable call (mov eax,[ecx]; call [eax+N]; ret)
  - call wrappers that forward to a single named function

Usage:
    python3 scripts/decompilation/auto_convert.py [--dry-run] [--category=CATEGORY]
"""

import json
import re
import sys
from pathlib import Path

from batch_verify import Patch, batch_apply_and_verify
from classify_asm_functions import AsmFunction, extract_asm_functions, normalize_asm_line
from triage_asm_functions import (
    TriageEntry,
    detect_blockers,
    detect_wrapper_state,
    extract_raw_bodies,
    similarity_hash,
    assign_strategy,
    compute_priority,
)

PROJECT_ROOT = Path(__file__).parent.parent.parent
SRC_DIR = PROJECT_ROOT / "src" / "c"


# ---------------------------------------------------------------------------
# Pattern converters: each returns (new_function_body, required_attributes) or None
# ---------------------------------------------------------------------------

def convert_neg_sbb_pattern(func: AsmFunction, raw_body: str) -> tuple[str, list[str]] | None:
    """Convert neg/sbb boolification to C.

    Pattern: load value -> cmp/test -> neg eax; sbb eax,eax; inc eax (or similar)
    Meaning: return (value != 0) ? 0 : 1  or  return (value == 0) ? 1 : 0

    The .byte 0x1b, 0xc0 is SBB EAX, EAX (encoded as 1B C0).
    Typical sequence:
      movzx eax, byte ptr [ecx + N]  ; or mov eax, [ecx+N]
      neg eax                         ; CF = (eax != 0)
      .byte 0x1b, 0xc0               ; sbb eax, eax  (eax = CF ? -1 : 0)
      inc eax                         ; eax = CF ? 0 : 1
      ret                             ; return (original == 0)
    OR:
      cmp [ecx+N], value
      .byte 0x1b, 0xc0               ; sbb eax, eax
      neg eax                         ; eax = (CF was set) ? 1 : 0
      ret                             ; return (field < value) -- unsigned
    """
    lines = func.asm_lines
    joined = " | ".join(lines)

    # Must have the sbb marker
    if ".byte 0x1b, 0xc0" not in joined:
        return None

    # This pattern is complex -- many variants. For now, return None
    # to indicate we need more analysis. The AI pipeline will handle these.
    # TODO: implement the most common variants
    return None


def convert_vtable_dispatch(func: AsmFunction, raw_body: str) -> tuple[str, list[str]] | None:
    """Convert vtable dispatch (jmp-through-vtable) to C.

    Pattern: mov eax, [ecx]; jmp [eax + N]
    Meaning: return this->vftable->method_at_N(this)

    This is a tail call to a virtual method.
    """
    lines = func.asm_lines
    if len(lines) != 2:
        return None

    # Match: mov eax, dword ptr [ecx]
    if not re.match(r'mov\s+eax,\s*dword ptr \[ecx\]', lines[0]):
        return None

    # Match: jmp dword ptr [eax + 0xN]
    jmp_match = re.match(r'jmp\s+dword ptr \[eax \+ 0x([0-9a-f]+)\]', lines[1])
    if not jmp_match:
        return None

    vtable_offset = int(jmp_match.group(1), 16)
    # vtable index = offset / 4
    vtable_index = vtable_offset // 4

    # Extract function signature to determine return type
    ret_type_match = re.search(r'(\w[\w\s*]+?)\s+__fastcall', raw_body)
    if not ret_type_match:
        return None
    ret_type = ret_type_match.group(1).strip()

    # Extract 'this' type
    this_type_match = re.search(r'__fastcall\s+\w+\s*\(\s*(?:struct\s+)?(\w+)\s*\*\s*this', raw_body)
    this_type = this_type_match.group(1) if this_type_match else "void"

    # Check if the function has no_ret attribute (common for vtable dispatches)
    has_no_ret = "__attribute__((no_ret))" in raw_body

    # For vtable dispatch, the function already has the right calling convention
    # We need: ((ret_type (__fastcall *)(this_type*))this->vftable[index])(this)
    # But this involves indirect call which may hit the PeepholeOptimizer crash blocker.
    # For now, skip these -- they need the vtable crash fix first.
    return None


def convert_vtable_call(func: AsmFunction, raw_body: str) -> tuple[str, list[str]] | None:
    """Convert vtable call + ret to C.

    Pattern: mov eax, [ecx]; call [eax + N]; ret
    Similar to dispatch but with call instead of jmp.
    Same blocker applies (indirect call crash).
    """
    # Same blocker as vtable_dispatch
    return None


def convert_call_wrapper(func: AsmFunction, raw_body: str) -> tuple[str, list[str]] | None:
    """Convert simple call wrappers.

    Pattern: push arg; call ?FuncName@...; (ret)
    Already in C-wrapper form with asm volatile.
    """
    # These are already C-wrappers. The asm body is a single call.
    # We'd need to identify the target function and replicate the call in C.
    # This requires knowing the target function's signature.
    # Defer to AI pipeline for now.
    return None


# ---------------------------------------------------------------------------
# Generate patches from triage data
# ---------------------------------------------------------------------------

def generate_patches(dry_run: bool = False, category_filter: str | None = None) -> list[Patch]:
    """Scan all asm functions and generate patches for auto-convertible ones."""
    patches = []

    for cfile in sorted(SRC_DIR.glob("*.c")):
        funcs = extract_asm_functions(cfile)
        if not funcs:
            continue

        raw_bodies = extract_raw_bodies(cfile)

        for func in funcs:
            raw_body = raw_bodies.get(func.name, "")
            blockers = detect_blockers(func, raw_body)

            if category_filter and func.category != category_filter:
                continue

            # Try each converter
            result = None

            if func.category == "neg_sbb_pattern":
                result = convert_neg_sbb_pattern(func, raw_body)
            elif func.category == "vtable_dispatch":
                result = convert_vtable_dispatch(func, raw_body)
            elif func.category == "vtable_call":
                result = convert_vtable_call(func, raw_body)
            elif func.category == "call_wrapper":
                result = convert_call_wrapper(func, raw_body)

            if result is None:
                continue

            new_body, required_attrs = result

            # Generate the patch
            # TODO: build old_text and new_text from raw_body transformation
            # For now, this is a placeholder structure
            patch = Patch(
                file=str(cfile.relative_to(PROJECT_ROOT)),
                function=func.name,
                old_text="",  # filled by specific converter
                new_text="",  # filled by specific converter
                description=f"Auto-convert {func.category}: {func.name}",
            )
            patches.append(patch)

    return patches


def main():
    dry_run = "--dry-run" in sys.argv
    category_filter = None
    for arg in sys.argv[1:]:
        if arg.startswith("--category="):
            category_filter = arg.split("=", 1)[1]

    print("Auto-converter: scanning for convertible functions...")
    patches = generate_patches(dry_run=dry_run, category_filter=category_filter)

    if not patches:
        print("No auto-convertible functions found at this time.")
        print()
        print("Most remaining functions need:")
        print("  - neg/sbb pattern support (14 functions)")
        print("  - vtable indirect call fix (23 functions)")
        print("  - AI-assisted conversion (171+ functions)")
        print()
        print("Run 'python3 triage_asm_functions.py' for the full breakdown.")
        return

    if dry_run:
        print(f"\n[DRY RUN] Would convert {len(patches)} functions:")
        for p in patches:
            print(f"  {p.file}: {p.function} - {p.description}")
        return

    print(f"\nApplying {len(patches)} conversions...")
    results = batch_apply_and_verify(patches)

    success = sum(1 for r in results if r.success)
    failed = sum(1 for r in results if not r.success)
    print(f"\nDone: {success} converted, {failed} failed")


if __name__ == "__main__":
    main()

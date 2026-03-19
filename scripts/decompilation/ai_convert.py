#!/usr/bin/env python3
"""AI-assisted conversion of asm functions to pure C.

Feeds asm function bodies + struct definitions + examples to Claude API
to generate candidate C code, then applies and verifies via MD5.

Usage:
    # Convert a single function
    python3 scripts/decompilation/ai_convert.py src/c/Fixed.000.c CanBeSetOnFire

    # Convert all zero-blocker functions in priority order
    python3 scripts/decompilation/ai_convert.py --batch [--limit=10]

    # Dry run: show what would be converted
    python3 scripts/decompilation/ai_convert.py --batch --dry-run

    # Convert all functions in a specific file
    python3 scripts/decompilation/ai_convert.py --file src/c/Object.000.c
"""

import json
import os
import re
import subprocess
import sys
from pathlib import Path

from batch_verify import Patch, batch_apply_and_verify, build_and_check_md5, TARGET_MD5
from classify_asm_functions import AsmFunction, extract_asm_functions
from triage_asm_functions import (
    detect_blockers,
    detect_wrapper_state,
    extract_raw_bodies,
)

PROJECT_ROOT = Path(__file__).parent.parent.parent
SRC_DIR = PROJECT_ROOT / "src" / "c"
HEADER_DIR = PROJECT_ROOT / "black"


def get_struct_context(func_name: str, raw_body: str) -> str:
    """Extract relevant struct field mappings for the function's this type.

    Returns a compact offset->field mapping instead of the full struct definition.
    """
    from offset_to_field import FieldMapper

    # Find the this-parameter type
    this_match = re.search(r'(?:struct\s+)?(\w+)\s*\*\s*this', raw_body)
    if not this_match:
        return ""

    this_type = this_match.group(1)

    # Also check if there are casts to other struct types in the raw body
    cast_types = set(re.findall(r'struct\s+(\w+)\s*\*', raw_body))
    cast_types.add(this_type)

    mapper = FieldMapper(HEADER_DIR)
    result_lines = []

    for stype in sorted(cast_types):
        fields = mapper.get_all_fields(stype)
        if fields:
            result_lines.append(f"// struct {stype} field layout:")
            for offset in sorted(fields.keys()):
                f = fields[offset]
                result_lines.append(f"//   0x{offset:04x}: {f.type_name:<20} {f.name}")
            result_lines.append("")

    # Also try to read a compact version of the C struct definition (just fields, max 60 lines)
    header_file = HEADER_DIR / f"{this_type}.h"
    if not header_file.exists():
        for hfile in HEADER_DIR.glob("*.h"):
            if this_type.lower() in hfile.stem.lower():
                header_file = hfile
                break

    if header_file.exists():
        try:
            text = header_file.read_text()
            lines = text.split("\n")
            # Find the C struct (not class) definition
            for i, line in enumerate(lines):
                if re.search(rf'struct\s+\w*{this_type}\w*\s*\{{', line):
                    # Extract fields only (skip virtual functions, RTTI, etc.)
                    depth = 0
                    field_lines = [line]
                    for j in range(i + 1, min(i + 80, len(lines))):
                        depth += lines[j].count("{") - lines[j].count("}")
                        stripped = lines[j].strip()
                        # Keep field declarations and offset comments
                        if stripped and not stripped.startswith("//") and not stripped.startswith("virtual"):
                            field_lines.append(lines[j])
                        if depth < 0:
                            field_lines.append("};")
                            break
                    if len(field_lines) <= 60:
                        result_lines.append("\n".join(field_lines))
                    break
        except Exception:
            pass

    return "\n".join(result_lines) if result_lines else f"// No struct info for {this_type}"


def get_examples() -> str:
    """Get examples of successful conversions."""
    return """
// Example 1: Simple field getter (pure C, no asm needed)
float __fastcall GetScale__6ObjectFv(struct GameThingWithPos* this)
{
    return ((struct Object*)this)->scale;
}

// Example 2: Float setter with msvc6_regalloc attribute
// LLVM generates fld+fstp, the X86PreferIntegerFloatMove pass converts to mov+mov
__attribute__((no_callee_saves, msvc6_regalloc, trailing_asm("...")))
void __fastcall SetJustScale__6ObjectFf(struct Object* this, const void* edx, float scale)
{
    this->scale = scale;
}

// Example 3: Bitfield accessor (C-wrapper with asm for encoding-sensitive bits)
// ASM: xor.s eax, eax; mov al, byte ptr [ecx + 0x0a]; not al
// C:   return (~this->flags >> 3) & 1;
// The xor.s encoding needs XOR32rr_REV attribute.

// Example 4: Return zero with XOR encoding
__attribute__((XOR32rr_REV))
uint32_t __fastcall GetTastiness__6ObjectFv(struct Object* this)
{
    return 0;
}

// Example 5: Boolean return (careful: use bool32_t not bool to avoid 'and al,1')
bool32_t __fastcall CanBeCrushed__11FixedObjectFv(struct Object* this)
{
    return true;
}
"""


def build_prompt(func: AsmFunction, raw_body: str, struct_context: str) -> str:
    """Build the prompt for Claude to generate C code."""
    asm_body = "\n".join(f"  {line}" for line in func.asm_lines)

    return f"""Convert this x86 asm function to pure C. Keep the EXACT same signature and attributes.

RULES:
- Use bool32_t (not bool) for boolean returns
- xor.s/mov.s in asm = reversed encoding, add XOR32rr_REV/MOV32rr_REV attribute
- [ecx+N] = this->field (see struct info below)
- Remove asm volatile block, write pure C logic
- Return ONLY the complete function (attributes + signature + body), no explanation

CURRENT FUNCTION:
{raw_body}

ASM (normalized):
{asm_body}

STRUCT INFO:
{struct_context}

Return ONLY the replacement function code, nothing else."""


def call_claude(prompt: str) -> str | None:
    """Call Claude CLI to generate C code."""
    try:
        result = subprocess.run(
            ["claude", "--print", "-p", prompt, "--model", "sonnet"],
            capture_output=True,
            text=True,
            timeout=180,
        )
        if result.returncode != 0:
            print(f"  Claude CLI error: {result.stderr[:200]}")
            return None
        return result.stdout.strip()
    except FileNotFoundError:
        print("  ERROR: 'claude' CLI not found. Install with: npm install -g @anthropic-ai/claude-code")
        return None
    except subprocess.TimeoutExpired:
        print("  ERROR: Claude CLI timed out")
        return None


def extract_function_from_file(filepath: Path, func_name: str) -> tuple[str, int, int] | None:
    """Extract a function's full text from a source file.

    Returns (function_text, start_line, end_line) or None.
    """
    text = filepath.read_text()

    # Find the function definition
    func_pattern = re.compile(
        r'((?:__attribute__\(\([^)]*\)\)\s*\n)*'
        r'\S.*?\s+(?:__fastcall|__cdecl)\s+' + re.escape(func_name) + r'\s*\([^)]*\)\s*\n\{)',
        re.MULTILINE,
    )

    match = func_pattern.search(text)
    if not match:
        return None

    # Find closing brace
    func_start = match.start()
    brace_start = text.index("{", match.end() - 1)
    depth = 0
    pos = brace_start
    while pos < len(text):
        if text[pos] == "{":
            depth += 1
        elif text[pos] == "}":
            depth -= 1
            if depth == 0:
                break
        pos += 1

    func_text = text[func_start : pos + 1]
    start_line = text[:func_start].count("\n") + 1
    end_line = text[: pos + 1].count("\n") + 1

    return func_text, start_line, end_line


def convert_single_function(filepath: Path, func_name: str, dry_run: bool = False) -> bool:
    """Convert a single function using AI assistance. Returns True on success."""
    print(f"\nConverting: {func_name} in {filepath.name}")

    # Extract the function
    result = extract_function_from_file(filepath, func_name)
    if not result:
        print(f"  Could not find function {func_name} in {filepath}")
        return False

    raw_body, start_line, end_line = result

    # Check if it still has asm
    if "asm" not in raw_body:
        print(f"  Function already converted (no asm found)")
        return True

    # Get struct context
    struct_context = get_struct_context(func_name, raw_body)

    # Build prompt
    funcs = extract_asm_functions(filepath)
    func_obj = None
    for f in funcs:
        if f.name == func_name:
            func_obj = f
            break

    if not func_obj:
        print(f"  Could not parse asm for {func_name}")
        return False

    prompt = build_prompt(func_obj, raw_body, struct_context)

    if dry_run:
        print(f"  Would send {len(prompt)} char prompt to Claude")
        print(f"  ASM lines: {len(func_obj.asm_lines)}")
        print(f"  Category: {func_obj.category}")
        return True

    # Call Claude
    print(f"  Generating C code via Claude CLI...")
    new_code = call_claude(prompt)
    if not new_code:
        return False

    # Clean up the response: extract code from markdown fences if present
    # Try to find code between ``` fences
    fence_match = re.search(r'```(?:c|cpp)?\s*\n(.*?)```', new_code, re.DOTALL)
    if fence_match:
        new_code = fence_match.group(1).strip()
    else:
        # No fences -- try to find the function definition
        func_match = re.search(
            r'(?:__attribute__.*?\n)?(?:\w[\w\s*]+\s+__(?:fastcall|cdecl)\s+\w+\s*\(.*?\)\s*\{.*\})',
            new_code,
            re.DOTALL,
        )
        if func_match:
            new_code = func_match.group(0).strip()
        else:
            new_code = new_code.strip()

    print(f"  Generated {len(new_code)} chars of C code:")
    for line in new_code.split("\n"):
        print(f"    > {line}")

    # Apply as a patch
    patch = Patch(
        file=str(filepath.relative_to(PROJECT_ROOT)),
        function=func_name,
        old_text=raw_body,
        new_text=new_code,
        description=f"AI-convert {func_name}",
    )

    results = batch_apply_and_verify([patch], revert_failures=True)
    if results and results[0].success:
        print(f"  SUCCESS: {func_name} converted and MD5 verified!")
        return True
    else:
        print(f"  FAILED: MD5 mismatch, reverted")
        return False


def main():
    dry_run = "--dry-run" in sys.argv
    batch_mode = "--batch" in sys.argv
    limit = 10
    file_filter = None

    for arg in sys.argv[1:]:
        if arg.startswith("--limit="):
            limit = int(arg.split("=")[1])
        elif arg.startswith("--file="):
            file_filter = arg.split("=")[1]

    if batch_mode:
        # Get triage data and convert zero-blocker functions in priority order
        from triage_asm_functions import main as triage_main

        print("Running triage to find convertible functions...")

        # Get entries via JSON output
        import io
        old_argv = sys.argv
        sys.argv = ["triage", "--json"]
        old_stdout = sys.stdout
        sys.stdout = io.StringIO()
        triage_main()
        json_output = sys.stdout.getvalue()
        sys.stdout = old_stdout
        sys.argv = old_argv

        entries = json.loads(json_output)

        # Filter: zero blockers, c_wrapper or raw_asm, small enough
        candidates = [
            e for e in entries
            if e["blocker_count"] == 0
            and e["instruction_count"] <= 15
            and e["wrapper_state"] in ("c_wrapper", "raw_asm")
            and e["category"] not in ("jmp_thunk", "vtable_dispatch", "vtable_call")
        ]

        if file_filter:
            candidates = [e for e in candidates if file_filter in e["file"]]

        candidates = candidates[:limit]

        print(f"\nFound {len(candidates)} candidates (limit={limit})")

        if dry_run:
            for i, e in enumerate(candidates, 1):
                short = e["function"].split("__")[0] if "__" in e["function"] else e["function"]
                print(f"  {i}. {e['file']}:{e['line']} {short} ({e['instruction_count']} inst, {e['category']})")
            return

        success_count = 0
        fail_count = 0
        for e in candidates:
            filepath = SRC_DIR / Path(e["file"]).name
            ok = convert_single_function(filepath, e["function"])
            if ok:
                success_count += 1
            else:
                fail_count += 1

        print(f"\n{'='*60}")
        print(f"BATCH RESULTS: {success_count} success, {fail_count} failed out of {len(candidates)}")

    elif len(sys.argv) >= 3 and not sys.argv[1].startswith("--"):
        # Single function mode
        filepath = Path(sys.argv[1])
        if not filepath.is_absolute():
            filepath = PROJECT_ROOT / filepath
        func_name = sys.argv[2]
        convert_single_function(filepath, func_name, dry_run=dry_run)

    else:
        print("Usage:")
        print("  python3 ai_convert.py src/c/File.c FunctionName [--dry-run]")
        print("  python3 ai_convert.py --batch [--limit=10] [--dry-run]")
        print("  python3 ai_convert.py --batch --file=Object.000.c [--limit=5]")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Enhanced triage of asm functions with similarity clustering and blocker analysis.

Extends classify_asm_functions.py with:
  - Similarity hashing: normalizes offsets/immediates to wildcards, groups
    structurally identical functions together.
  - Blocker intersection: for each function, lists ALL conversion blockers
    (not just the first match).
  - JSON work queue output, sorted by conversion probability.

Usage:
    python3 scripts/decompilation/triage_asm_functions.py [--json] [--summary]
"""

import json
import re
import sys
from collections import Counter, defaultdict
from dataclasses import asdict, dataclass, field
from hashlib import sha256
from pathlib import Path

# Import from existing classifier
from classify_asm_functions import (
    AsmFunction,
    extract_asm_functions,
    normalize_asm_line,
)


# ---------------------------------------------------------------------------
# Blocker detection
# ---------------------------------------------------------------------------

BLOCKERS = [
    "esp_access",         # [esp+N] stack param access
    "bool_return",        # bool return type -> compiler adds and al,1
    "trailing_code",      # code/data after ret (not just NOPs)
    "individual_asm",     # individual asm() calls (not volatile blocks)
    "cross_label",        # labels referenced across functions
    "fpu_complex",        # complex FPU sequences (fucompp, fsqrt, etc.)
    "indirect_call",      # indirect call through register or memory
    "seh_frame",          # structured exception handling
    "disp32_jmp",         # {disp32} jmp thunk (encoding constraint)
    "multiple_ret",       # multiple ret instructions (branching)
    "string_ref",         # references string literals
    "large_stack_frame",  # sub esp, N (local variables)
]


def detect_wrapper_state(func: AsmFunction, raw_body: str) -> str:
    """Detect whether the function is raw asm, a C-wrapper, or a call-wrapper.

    Returns one of:
      "raw_asm"              - function body IS the asm (needs full conversion)
      "c_wrapper"            - has return + asm volatile with constraints (body needs C replacement)
      "call_wrapper"         - asm wraps a single call to another function
      "conditionally_converted" - has #if HAS_EXPAND_MOVZX (or similar) with pure C path
      "pure_c"               - no asm at all (shouldn't be in the list but just in case)
    """
    if not raw_body:
        return "raw_asm"

    # Check for #if HAS_EXPAND_MOVZX or similar conditional C paths
    # These functions have pure C when compiled with our LLVM fork
    if re.search(r'#if\s+HAS_EXPAND_MOVZX', raw_body):
        return "conditionally_converted"

    has_return = bool(re.search(r'\breturn\b', raw_body))
    has_output_constraint = '"=a"' in raw_body or '"=t"' in raw_body
    has_single_call = bool(re.search(r'call\s+[\?_]', " ".join(func.asm_lines)))
    n_instructions = len(func.asm_lines)

    if has_return and has_output_constraint:
        if n_instructions <= 3 and has_single_call:
            return "call_wrapper"
        return "c_wrapper"

    if "__builtin_unreachable" in raw_body:
        return "raw_asm"

    if has_return and "asm" not in raw_body.split("{", 1)[-1].split("return")[0]:
        return "pure_c"

    return "raw_asm"


def detect_blockers(func: AsmFunction, raw_body: str) -> list[str]:
    """Detect ALL conversion blockers for a function (not just first match)."""
    blockers = []
    joined = " | ".join(func.asm_lines)
    lines = func.asm_lines

    # esp access (stack parameters beyond this pointer)
    if re.search(r'\[esp', joined):
        blockers.append("esp_access")

    # bool return type (compiler will add and al,1 boolification)
    if raw_body and re.search(r'\bbool\b\s+__fastcall', raw_body):
        if 'bool32_t' not in raw_body:
            blockers.append("bool_return")

    # trailing code after ret
    ret_seen = False
    has_trailing = False
    for line in lines:
        if line.strip().startswith("ret"):
            ret_seen = True
            continue
        if ret_seen:
            stripped = line.strip()
            if stripped and not stripped.startswith("nop") and not stripped.startswith("LAB"):
                has_trailing = True
                break
    if has_trailing:
        blockers.append("trailing_code")

    # individual asm (harder to convert than volatile blocks)
    if func.asm_type == "individual":
        blockers.append("individual_asm")

    # complex FPU (not handled by simple passes)
    fpu_complex_ops = ["fucompp", "fsqrt", "fpatan", "fyl2x", "fsincos", "fprem", "fscale"]
    for op in fpu_complex_ops:
        if op in joined:
            blockers.append("fpu_complex")
            break

    # indirect calls (vtable dispatch through register)
    if re.search(r'call\s+dword ptr \[e[abcd]x', joined):
        blockers.append("indirect_call")

    # {disp32} jmp encoding constraint
    if raw_body and re.search(r'\{disp32\}.*jmp', raw_body):
        blockers.append("disp32_jmp")

    # multiple ret instructions (branching)
    ret_count = sum(1 for line in lines if line.strip().startswith("ret"))
    if ret_count > 1:
        blockers.append("multiple_ret")

    # string literal references
    if re.search(r'OFFSET\s+_\?\?_C@', joined) or re.search(r'push\s+0x00[89a-f]', joined):
        blockers.append("string_ref")

    # large stack frame
    if re.search(r'sub\s+esp,\s*0x', joined):
        blockers.append("large_stack_frame")

    return blockers


# ---------------------------------------------------------------------------
# Similarity hashing
# ---------------------------------------------------------------------------

def similarity_hash(lines: list[str]) -> str:
    """Create a structural hash by normalizing constants and offsets to wildcards."""
    normalized = []
    for line in lines:
        # Normalize hex immediates: 0x1234 -> 0xN
        s = re.sub(r'0x[0-9a-fA-F]+', '0xN', line)
        # Normalize decimal immediates (standalone numbers > 1)
        s = re.sub(r'\b\d{2,}\b', 'N', s)
        # Normalize symbol names (mangled C++ names)
        s = re.sub(r'\?\??\w+@[\w@]+', 'SYM', s)
        s = re.sub(r'_\w+__\w+', 'SYM', s)
        # Normalize label references
        s = re.sub(r'LAB__addr_\w+', 'LAB', s)
        # Normalize rdata references
        s = re.sub(r'_rdata_\w+', 'RDATA', s)
        s = re.sub(r'data_bytes \+ 0xN', 'DATA', s)
        normalized.append(s.strip())
    pattern = "\n".join(normalized)
    return sha256(pattern.encode()).hexdigest()[:16]


# ---------------------------------------------------------------------------
# Function body extraction (raw, for blocker detection)
# ---------------------------------------------------------------------------

def extract_raw_bodies(filepath: Path) -> dict[str, str]:
    """Extract raw function bodies keyed by function name."""
    text = filepath.read_text()
    bodies = {}

    func_pattern = re.compile(
        r'^(?:(__attribute__\(\([^)]*\)\))\s*\n)?'
        r'(\S.*?)\s+(?:__fastcall|__cdecl)\s+(\w+)\s*\(([^)]*)\)\s*\n\{',
        re.MULTILINE,
    )

    for match in func_pattern.finditer(text):
        func_name = match.group(3)
        brace_depth = 0
        body_start = text.index("{", match.end() - 1)
        pos = body_start
        while pos < len(text):
            if text[pos] == "{":
                brace_depth += 1
            elif text[pos] == "}":
                brace_depth -= 1
                if brace_depth == 0:
                    break
            pos += 1
        # Include attribute line + signature for return type detection
        # Also look back up to 5 lines for #if guards
        attr_start = match.start()
        context_start = max(0, text.rfind("\n", 0, attr_start - 200) + 1) if attr_start > 200 else 0
        context_start = max(0, attr_start - 200)
        preceding_context = text[context_start:attr_start]
        body_text = text[attr_start : pos + 1]
        # Attach preceding context if it has preprocessor conditionals
        if "#if" in preceding_context:
            bodies[func_name] = preceding_context + body_text
        else:
            bodies[func_name] = body_text

    return bodies


# ---------------------------------------------------------------------------
# Conversion strategy assignment
# ---------------------------------------------------------------------------

def assign_strategy(func: AsmFunction, blockers: list[str]) -> str:
    """Assign a conversion strategy based on category and blockers."""
    if blockers:
        # Some blockers are soft (can be worked around)
        hard_blockers = [b for b in blockers if b not in ("trailing_code",)]
        if not hard_blockers and func.difficulty in ("LOW", "LOW-MEDIUM"):
            return "auto_with_trailing_asm"
        if blockers == ["indirect_call"] and func.category in ("vtable_dispatch", "vtable_call"):
            return "vtable_template"
        if blockers == ["esp_access"] and func.difficulty == "LOW":
            return "manual_simple"
        if "individual_asm" in blockers and len(blockers) == 1:
            return "refactor_to_volatile"
        return "manual_complex" if len(hard_blockers) > 1 else "manual_simple"

    # No blockers
    if func.difficulty == "LOW":
        return "auto_convert"
    if func.difficulty == "LOW-MEDIUM":
        if func.category in ("vtable_dispatch", "vtable_call"):
            return "vtable_template"
        if func.category == "neg_sbb_pattern":
            return "neg_sbb_template"
        return "auto_convert"
    if func.difficulty == "MEDIUM":
        if func.category in ("bitfield_accessor", "struct_copy", "fpu_init", "call_wrapper"):
            return "ai_assisted"
        return "ai_assisted"
    return "ai_complex"


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

@dataclass
class TriageEntry:
    file: str
    function: str
    line: int
    difficulty: str
    category: str
    note: str
    asm_type: str
    wrapper_state: str  # raw_asm, c_wrapper, call_wrapper, pure_c
    instruction_count: int
    blockers: list[str]
    blocker_count: int
    similarity_group: str
    strategy: str
    priority: float  # 0.0 = highest priority (easiest)


def compute_priority(entry: TriageEntry) -> float:
    """Compute a priority score (lower = easier/higher priority)."""
    diff_score = {
        "LOW": 0, "LOW-MEDIUM": 1, "MEDIUM": 2,
        "MEDIUM-HIGH": 3, "HIGH": 4, "VERY HIGH": 5,
    }.get(entry.difficulty, 6)

    blocker_penalty = entry.blocker_count * 2
    size_penalty = min(entry.instruction_count / 10.0, 5.0)

    strategy_bonus = {
        "auto_convert": -2,
        "auto_with_trailing_asm": -1,
        "vtable_template": 0,
        "neg_sbb_template": 0,
        "manual_simple": 1,
        "ai_assisted": 2,
        "refactor_to_volatile": 3,
        "manual_complex": 4,
        "ai_complex": 5,
    }.get(entry.strategy, 5)

    return diff_score + blocker_penalty + size_penalty + strategy_bonus


def main():
    src_dir = Path(__file__).parent.parent.parent / "src" / "c"
    output_json = "--json" in sys.argv
    summary_only = "--summary" in sys.argv

    # Collect all asm functions using existing classifier
    all_functions: list[AsmFunction] = []
    raw_bodies_by_file: dict[str, dict[str, str]] = {}

    for cfile in sorted(src_dir.glob("*.c")):
        funcs = extract_asm_functions(cfile)
        all_functions.extend(funcs)
        if funcs:
            raw_bodies_by_file[str(cfile)] = extract_raw_bodies(cfile)

    # Build triage entries
    entries: list[TriageEntry] = []
    similarity_groups: dict[str, list[str]] = defaultdict(list)

    for func in all_functions:
        # Get raw body for blocker detection
        filepath = src_dir / Path(func.file).name
        raw_bodies = raw_bodies_by_file.get(str(filepath), {})
        raw_body = raw_bodies.get(func.name, "")

        blockers = detect_blockers(func, raw_body)
        sim_hash = similarity_hash(func.asm_lines)
        wrapper_state = detect_wrapper_state(func, raw_body)
        strategy = assign_strategy(func, blockers)

        entry = TriageEntry(
            file=func.file,
            function=func.name,
            line=func.line,
            difficulty=func.difficulty,
            category=func.category,
            note=func.note,
            asm_type=func.asm_type,
            wrapper_state=wrapper_state,
            instruction_count=len(func.asm_lines),
            blockers=blockers,
            blocker_count=len(blockers),
            similarity_group=sim_hash,
            strategy=strategy,
            priority=0.0,
        )
        entry.priority = compute_priority(entry)
        entries.append(entry)
        similarity_groups[sim_hash].append(func.name)

    # Sort by priority (lowest = easiest = do first)
    entries.sort(key=lambda e: (e.priority, e.file, e.line))

    # --- Output ---

    if output_json:
        print(json.dumps([asdict(e) for e in entries], indent=2))
        return

    # Print summary
    print("=" * 80)
    print(f"TRIAGE REPORT — {len(entries)} asm functions")
    print("=" * 80)

    # Wrapper state breakdown
    by_wrapper = Counter(e.wrapper_state for e in entries)
    print("\n  WRAPPER STATE:")
    for state, count in sorted(by_wrapper.items(), key=lambda x: -x[1]):
        print(f"    {state:<25} {count:>4}")

    # Strategy breakdown
    by_strategy = Counter(e.strategy for e in entries)
    print("\n  CONVERSION STRATEGY BREAKDOWN:")
    for strat, count in sorted(by_strategy.items(), key=lambda x: -x[1]):
        print(f"    {strat:<25} {count:>4}")

    # Blocker analysis
    print("\n  BLOCKER FREQUENCY:")
    blocker_counts = Counter()
    for e in entries:
        for b in e.blockers:
            blocker_counts[b] += 1
    for blocker, count in sorted(blocker_counts.items(), key=lambda x: -x[1]):
        print(f"    {blocker:<25} {count:>4} functions")

    no_blockers = sum(1 for e in entries if e.blocker_count == 0)
    one_blocker = sum(1 for e in entries if e.blocker_count == 1)
    multi_blockers = sum(1 for e in entries if e.blocker_count > 1)
    print(f"\n    No blockers:  {no_blockers:>4}")
    print(f"    1 blocker:    {one_blocker:>4}")
    print(f"    2+ blockers:  {multi_blockers:>4}")

    # Similarity groups
    large_groups = {k: v for k, v in similarity_groups.items() if len(v) >= 3}
    print(f"\n  SIMILARITY GROUPS (3+ identical structure): {len(large_groups)}")
    for gid, members in sorted(large_groups.items(), key=lambda x: -len(x[1]))[:15]:
        sample = members[0].split("__")[0] if "__" in members[0] else members[0]
        print(f"    {gid}: {len(members)} functions (e.g. {sample})")

    if not summary_only:
        # Print prioritized work queue
        print(f"\n{'=' * 80}")
        print("WORK QUEUE — Top 50 (lowest priority score = easiest)")
        print(f"{'=' * 80}")

        for i, e in enumerate(entries[:50], 1):
            short_name = e.function.split("__")[0] if "__" in e.function else e.function
            blockers_str = ",".join(e.blockers) if e.blockers else "none"
            print(
                f"  {i:>3}. [{e.strategy:<20}] "
                f"{e.file}:{e.line:<5} {short_name:<30} "
                f"({e.instruction_count} inst, blockers: {blockers_str})"
            )

    # Print auto-convertible estimate
    auto = sum(1 for e in entries if e.strategy.startswith("auto"))
    template = sum(1 for e in entries if "template" in e.strategy)
    ai = sum(1 for e in entries if e.strategy.startswith("ai"))
    manual = sum(1 for e in entries if e.strategy.startswith("manual"))

    print(f"\n{'=' * 80}")
    print("ESTIMATED CONVERSION BREAKDOWN:")
    print(f"{'=' * 80}")
    print(f"  Auto-convertible:    {auto:>4}  (script can generate C directly)")
    print(f"  Template-based:      {template:>4}  (vtable/neg_sbb templates)")
    print(f"  AI-assisted:         {ai:>4}  (need LLM to generate C)")
    print(f"  Manual:              {manual:>4}  (need human judgment or LLVM fixes)")
    print(f"  TOTAL:               {len(entries):>4}")


if __name__ == "__main__":
    main()

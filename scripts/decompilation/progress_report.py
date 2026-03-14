#!/usr/bin/env python3
"""Generate a unified progress report for the bw1-decomp project.

Reports THREE distinct metrics that measure different things:

  1. SOURCE STATE - What language is each function written in?
     Counts whether the function body is pure C, inline asm, or a mix.
     This tells you how much WORK has been done, but NOT whether it's correct.
     A function can be "written as C" but compile to completely wrong bytes.

  2. BYTE-EXACT MATCH (src/c/ only) - Of our decompiled functions, how many
     compile to identical machine code as the original MSVC binary?
     This is the TRUE progress metric. Only byte-matched functions count as
     "done". The gap between "written as C" and "byte-matched" represents
     functions that need LLVM encoding attributes (expand_movzx, no_bool_mask,
     trailing_bytes, etc.) to fix compiler output mismatches.

  3. OVERALL BYTE MATCH (all units) - The global objdiff percentage including
     libraries (LIBCMT, zlib), staging stubs, and our src/c/ code. This is
     what decomp.dev displays. It's lower than src/c/-only because libraries
     are large and mostly unmatched.

Usage:
  python progress_report.py                        # source-only (no objdiff)
  python progress_report.py --report report.json   # full report with objdiff
"""

import argparse
import json
import re
from pathlib import Path
from dataclasses import dataclass


@dataclass
class FileStats:
    filename: str
    total_functions: int = 0
    decompiled: int = 0
    asm_volatile: int = 0
    individual_asm: int = 0
    mixed: int = 0
    # objdiff metrics (from report.json when available)
    matched_code: int = 0
    total_code: int = 0
    matched_code_percent: float = 0.0
    matched_functions: int = 0
    total_objdiff_functions: int = 0


def count_functions(filepath: Path) -> FileStats:
    """Count functions by decompilation state in a C file."""
    text = filepath.read_text()
    stats = FileStats(filename=str(filepath.name))

    func_pattern = re.compile(
        r'^(?:__attribute__\(\([^)]*\)\)\s*\n)?'
        r'(\S.*?)\s+(?:__fastcall|__cdecl)\s+(\w+)\s*\(([^)]*)\)\s*\n\{',
        re.MULTILINE
    )

    for match in func_pattern.finditer(text):
        brace_depth = 0
        body_start = text.index('{', match.end() - 1)
        pos = body_start
        while pos < len(text):
            if text[pos] == '{':
                brace_depth += 1
            elif text[pos] == '}':
                brace_depth -= 1
                if brace_depth == 0:
                    break
            pos += 1

        body = text[body_start:pos + 1]
        stats.total_functions += 1

        has_volatile = 'asm volatile' in body
        has_individual = bool(re.search(r'asm\s*\("', body))
        has_c_code = False

        for line in body.split('\n'):
            stripped = line.strip()
            if not stripped or stripped in ('{', '}', ';'):
                continue
            if stripped.startswith('//') or stripped.startswith('/*'):
                continue
            if stripped.startswith('asm') or stripped.startswith('"'):
                continue
            if stripped.startswith('__builtin_unreachable'):
                continue
            if re.match(r'(void|int|uint|float|double|struct|enum|bool|char|const|return)\s', stripped):
                has_c_code = True
                break
            if '=' in stripped or 'if ' in stripped or 'for ' in stripped or 'while ' in stripped:
                has_c_code = True
                break

        if has_volatile and has_c_code:
            stats.mixed += 1
        elif has_volatile:
            stats.asm_volatile += 1
        elif has_individual:
            stats.individual_asm += 1
        else:
            stats.decompiled += 1

    return stats


def load_objdiff_report(report_path: Path) -> dict:
    """Load objdiff report and return a dict keyed by unit name."""
    with open(report_path) as f:
        report = json.load(f)

    units_by_name = {}
    for unit in report.get("units", []):
        name = unit.get("name", "")
        if "/" in name:
            short = name.split("/")[-1] + ".c"
        else:
            short = name + ".c"
        units_by_name[short] = unit

    return {
        "measures": report.get("measures", {}),
        "units": units_by_name,
    }


def merge_stats(file_stats: FileStats, objdiff_unit: dict) -> None:
    """Merge objdiff unit data into file stats."""
    measures = objdiff_unit.get("measures", {})
    file_stats.matched_code = int(measures.get("matched_code", 0) or 0)
    file_stats.total_code = int(measures.get("total_code", 0) or 0)
    file_stats.matched_code_percent = float(measures.get("matched_code_percent", 0) or 0)
    file_stats.matched_functions = int(measures.get("matched_functions", 0) or 0)
    file_stats.total_objdiff_functions = int(measures.get("total_functions", 0) or 0)


def format_bar(pct: float, width: int = 40) -> str:
    filled = int(width * pct / 100)
    return '#' * filled + '-' * (width - filled)


def main():
    parser = argparse.ArgumentParser(description="bw1-decomp progress report")
    parser.add_argument("--report", type=Path, default=None,
                        help="Path to objdiff report.json for byte-match data")
    args = parser.parse_args()

    src_dir = Path(__file__).parent.parent.parent / "src" / "c"

    # Auto-detect report.json if not specified
    if args.report is None:
        default_report = Path(__file__).parent.parent.parent / "cmake-build-presets" / "objdiff" / "report.json"
        if default_report.exists():
            args.report = default_report

    objdiff = None
    if args.report and args.report.exists():
        objdiff = load_objdiff_report(args.report)

    all_stats: list[FileStats] = []
    for cfile in sorted(src_dir.glob("*.c")):
        stats = count_functions(cfile)
        if stats.total_functions > 0:
            if objdiff:
                unit = objdiff["units"].get(stats.filename)
                if unit:
                    merge_stats(stats, unit)
            all_stats.append(stats)

    # Aggregate
    total = sum(s.total_functions for s in all_stats)
    decompiled = sum(s.decompiled for s in all_stats)
    volatile = sum(s.asm_volatile for s in all_stats)
    individual = sum(s.individual_asm for s in all_stats)
    mixed = sum(s.mixed for s in all_stats)
    src_pct = 100 * decompiled / total if total else 0

    print("=" * 80)
    print("DECOMPILATION PROGRESS REPORT")
    print("=" * 80)

    # ── 1. Source State ──
    print(f"""
  1. SOURCE STATE
     What language is each function written in?
     NOTE: "Written as C" does NOT mean the output matches the original.
  {'─' * 55}
  Total functions:   {total:>5}
  Written as C:      {decompiled:>5}  ({src_pct:.1f}%)
  asm volatile:      {volatile:>5}  ({100*volatile/total:.1f}%)
  Individual asm:    {individual:>5}  ({100*individual/total:.1f}%)
  Mixed (C+asm):     {mixed:>5}  ({100*mixed/total:.1f}%)

  C code:     [{format_bar(src_pct)}] {src_pct:.1f}%""")

    # ── 2. Byte-Exact Match ──
    if objdiff:
        src_matched = sum(s.matched_functions for s in all_stats)
        src_total_od = sum(s.total_objdiff_functions for s in all_stats)
        src_matched_bytes = sum(s.matched_code for s in all_stats)
        src_total_bytes = sum(s.total_code for s in all_stats)
        src_byte_pct = 100 * src_matched_bytes / src_total_bytes if src_total_bytes else 0
        src_func_pct = 100 * src_matched / src_total_od if src_total_od else 0

        m = objdiff["measures"]
        global_pct = float(m.get("matched_code_percent", 0) or 0)
        global_matched = int(m.get("matched_code", 0) or 0)
        global_total = int(m.get("total_code", 0) or 0)
        global_funcs_matched = int(m.get("matched_functions", 0) or 0)
        global_funcs_total = int(m.get("total_functions", 0) or 0)

        gap = decompiled - src_matched

        print(f"""
  2. BYTE-EXACT MATCH (src/c/ only)
     Of our decompiled functions, how many compile to identical bytes?
     This is the TRUE progress metric for decompilation correctness.
  {'─' * 55}
  Matched functions: {src_matched:>5} / {src_total_od}  ({src_func_pct:.1f}%)
  Matched bytes:     {src_matched_bytes:>5} / {src_total_bytes:,}  ({src_byte_pct:.1f}%)

  Byte match: [{format_bar(src_func_pct)}] {src_func_pct:.1f}%

  3. OVERALL BYTE MATCH (all units incl. libraries)
     Global objdiff percentage shown on decomp.dev. Includes LIBCMT,
     zlib, staging stubs, and our src/c/ code.
  {'─' * 55}
  Matched functions: {global_funcs_matched:>5} / {global_funcs_total}
  Matched bytes:     {global_matched:>5} / {global_total:,}  ({global_pct:.1f}%)

  Overall:    [{format_bar(global_pct)}] {global_pct:.1f}%

  4. GAP ANALYSIS
     Why "written as C" != "byte-matched":
     Functions written in C may compile to different bytes than the
     original MSVC 6.0 output due to encoding mismatches (MOVZX vs
     XOR+MOV, and al 1 masking, fldz vs fld [const], etc.).
     These need custom LLVM attributes to fix.
  {'─' * 55}
  Written as C:          {decompiled:>5}   (source says it's C)
  Byte-exact matches:    {src_matched:>5}   (compiler output matches original)
  C but NOT matching:    {gap:>5}   (need LLVM attributes to fix encoding)
  Still in asm:          {total - decompiled:>5}   (not yet converted to C)""")
    else:
        print(f"""
  2. BYTE-EXACT MATCH: no objdiff report found
     Generate with: python configure_objdiff.py
     Or download from CI: gh run download <id> --name WIN32_1.20_EN_report""")

    # ── Per-file table ──
    asm_files = [s for s in all_stats if s.asm_volatile > 0 or s.individual_asm > 0]
    asm_files.sort(key=lambda s: s.asm_volatile + s.individual_asm, reverse=True)

    print(f"\n{'─' * 80}")
    print(f"  Files with remaining asm ({len(asm_files)} files)")
    print(f"{'─' * 80}")
    if objdiff:
        print(f"  {'File':<38} {'Total':>5} {'C':>4} {'Vol':>4} {'Ind':>4} {'Mix':>4} {'Match':>6} {'Bytes':>7}")
        print(f"  {'─'*38} {'─'*5} {'─'*4} {'─'*4} {'─'*4} {'─'*4} {'─'*6} {'─'*7}")
        for s in asm_files:
            mf = f"{s.matched_functions}" if s.total_objdiff_functions > 0 else "-"
            mb = f"{s.matched_code_percent:.1f}%" if s.total_code > 0 else "  -"
            print(f"  {s.filename:<38} {s.total_functions:>5} {s.decompiled:>4} "
                  f"{s.asm_volatile:>4} {s.individual_asm:>4} {s.mixed:>4} "
                  f"{mf:>6} {mb:>7}")
    else:
        print(f"  {'File':<45} {'Total':>5} {'C':>5} {'Vol':>5} {'Ind':>5} {'Mix':>5}")
        print(f"  {'─'*45} {'─'*5} {'─'*5} {'─'*5} {'─'*5} {'─'*5}")
        for s in asm_files:
            print(f"  {s.filename:<45} {s.total_functions:>5} {s.decompiled:>5} "
                  f"{s.asm_volatile:>5} {s.individual_asm:>5} {s.mixed:>5}")

    # Fully decompiled files
    done_files = [s for s in all_stats if s.asm_volatile == 0 and s.individual_asm == 0 and s.mixed == 0]
    if objdiff:
        perfect_files = [s for s in done_files if s.matched_code_percent >= 99.9 and s.total_code > 0]
        print(f"\n{'─' * 80}")
        print(f"  Fully C files:            {len(done_files):>3} / {len(all_stats)}")
        print(f"  Fully C + byte-matched:   {len(perfect_files):>3} / {len(all_stats)}")
        print(f"{'─' * 80}")
    else:
        print(f"\n{'─' * 80}")
        print(f"  Fully decompiled files: {len(done_files)} / {len(all_stats)}")
        print(f"{'─' * 80}")


if __name__ == "__main__":
    main()

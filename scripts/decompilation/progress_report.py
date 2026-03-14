#!/usr/bin/env python3
"""Generate a progress report for the bw1-decomp project.

Shows two metrics side-by-side:
  1. Source state: How many functions are written in C vs inline asm
  2. Byte match: How many compiled functions produce identical bytes (from objdiff)

Usage:
  python progress_report.py                    # source-only (no objdiff data)
  python progress_report.py --report report.json  # merged with objdiff data
"""

import argparse
import json
import re
from pathlib import Path
from dataclasses import dataclass, field


@dataclass
class FileStats:
    filename: str
    total_functions: int = 0
    decompiled: int = 0
    asm_volatile: int = 0
    individual_asm: int = 0
    mixed: int = 0  # functions with both C code and asm
    # objdiff metrics (populated when report.json is available)
    matched_code: int = 0
    total_code: int = 0
    matched_code_percent: float = 0.0
    matched_functions: int = 0
    total_objdiff_functions: int = 0


def count_functions(filepath: Path) -> FileStats:
    """Count functions by decompilation state in a C file."""
    text = filepath.read_text()
    stats = FileStats(filename=str(filepath.name))

    # Match function definitions (__fastcall or __cdecl)
    func_pattern = re.compile(
        r'^(?:__attribute__\(\([^)]*\)\)\s*\n)?'
        r'(\S.*?)\s+(?:__fastcall|__cdecl)\s+(\w+)\s*\(([^)]*)\)\s*\n\{',
        re.MULTILINE
    )

    for match in func_pattern.finditer(text):
        # Find the closing brace
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

        # Check for meaningful C code (not just asm, builtin_unreachable, or declarations)
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
                # C code (declarations, returns, etc.)
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
        # Extract filename from unit name (e.g., "c/Abode.000" -> "Abode.000.c")
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


def format_bar(pct: float, width: int = 30) -> str:
    """Create a progress bar string."""
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

    # Load objdiff data if available
    objdiff = None
    if args.report and args.report.exists():
        objdiff = load_objdiff_report(args.report)

    all_stats: list[FileStats] = []
    for cfile in sorted(src_dir.glob("*.c")):
        stats = count_functions(cfile)
        if stats.total_functions > 0:
            # Merge objdiff data if available
            if objdiff:
                unit = objdiff["units"].get(stats.filename)
                if unit:
                    merge_stats(stats, unit)
            all_stats.append(stats)

    # Aggregate source stats
    total = sum(s.total_functions for s in all_stats)
    decompiled = sum(s.decompiled for s in all_stats)
    volatile = sum(s.asm_volatile for s in all_stats)
    individual = sum(s.individual_asm for s in all_stats)
    mixed = sum(s.mixed for s in all_stats)

    src_pct = 100 * decompiled / total if total else 0

    print("=" * 80)
    print("DECOMPILATION PROGRESS REPORT")
    print("=" * 80)

    # ── Source State ──
    print(f"\n  SOURCE STATE (functions written in C vs asm)")
    print(f"  {'─' * 50}")
    print(f"  Total functions:   {total:>5}")
    print(f"  Decompiled (C):    {decompiled:>5}  ({src_pct:.1f}%)")
    print(f"  asm volatile:      {volatile:>5}  ({100*volatile/total:.1f}%)")
    print(f"  Individual asm:    {individual:>5}  ({100*individual/total:.1f}%)")
    print(f"  Mixed (C+asm):     {mixed:>5}  ({100*mixed/total:.1f}%)")
    print(f"\n  Written as C: [{format_bar(src_pct)}] {src_pct:.1f}%")

    # ── Byte Match (objdiff) ──
    if objdiff:
        m = objdiff["measures"]
        match_pct = float(m.get("matched_code_percent", 0) or 0)
        match_funcs = int(m.get("matched_functions", 0) or 0)
        total_funcs = int(m.get("total_functions", 0) or 0)
        match_bytes = int(m.get("matched_code", 0) or 0)
        total_bytes = int(m.get("total_code", 0) or 0)
        func_pct = 100 * match_funcs / total_funcs if total_funcs else 0

        print(f"\n  BYTE-EXACT MATCH (compiled output vs original binary)")
        print(f"  {'─' * 50}")
        print(f"  Matched functions: {match_funcs:>5} / {total_funcs}  ({func_pct:.1f}%)")
        print(f"  Matched bytes:     {match_bytes:>5} / {total_bytes}  ({match_pct:.1f}%)")
        print(f"\n  Byte match:   [{format_bar(match_pct)}] {match_pct:.1f}%")

        # ── Gap Analysis ──
        gap = decompiled - match_funcs
        print(f"\n  GAP ANALYSIS")
        print(f"  {'─' * 50}")
        print(f"  Functions in C but NOT byte-matching: {gap}")
        print(f"  These need LLVM attributes to fix encoding mismatches.")
    else:
        print(f"\n  BYTE-EXACT MATCH: no objdiff report found")
        print(f"  Run: python configure_objdiff.py && objdiff-cli report generate -o report.json")

    # Per-file breakdown (only files with asm remaining)
    asm_files = [s for s in all_stats if s.asm_volatile > 0 or s.individual_asm > 0]
    asm_files.sort(key=lambda s: s.asm_volatile + s.individual_asm, reverse=True)

    print(f"\n{'─' * 80}")
    print(f"  Files with remaining asm ({len(asm_files)} files)")
    print(f"{'─' * 80}")
    if objdiff:
        print(f"  {'File':<40} {'Total':>5} {'C':>5} {'Vol':>5} {'Ind':>5} {'Mix':>5} {'Match%':>7}")
        print(f"  {'─'*40} {'─'*5} {'─'*5} {'─'*5} {'─'*5} {'─'*5} {'─'*7}")
        for s in asm_files:
            match_str = f"{s.matched_code_percent:.1f}%" if s.total_code > 0 else "   -"
            print(f"  {s.filename:<40} {s.total_functions:>5} {s.decompiled:>5} "
                  f"{s.asm_volatile:>5} {s.individual_asm:>5} {s.mixed:>5} {match_str:>7}")
    else:
        print(f"  {'File':<45} {'Total':>5} {'C':>5} {'Vol':>5} {'Ind':>5} {'Mix':>5}")
        print(f"  {'─'*45} {'─'*5} {'─'*5} {'─'*5} {'─'*5} {'─'*5}")
        for s in asm_files:
            print(f"  {s.filename:<45} {s.total_functions:>5} {s.decompiled:>5} "
                  f"{s.asm_volatile:>5} {s.individual_asm:>5} {s.mixed:>5}")

    # Fully decompiled files
    done_files = [s for s in all_stats if s.asm_volatile == 0 and s.individual_asm == 0 and s.mixed == 0]
    print(f"\n{'─' * 80}")
    print(f"  Fully decompiled files: {len(done_files)} / {len(all_stats)}")
    print(f"{'─' * 80}")


if __name__ == "__main__":
    main()

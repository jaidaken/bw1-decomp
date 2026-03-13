#!/usr/bin/env python3
"""Generate a progress report for the bw1-decomp project.

Counts functions in three states:
  1. Decompiled (pure C, no asm)
  2. asm volatile (converted from individual asm, not yet decompiled)
  3. Individual asm (not yet converted to asm volatile)

Also counts decompilable functions (matching known-working patterns).
"""

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
    mixed: int = 0  # functions with both C code and asm


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


def main():
    src_dir = Path(__file__).parent.parent.parent / "src" / "c"

    all_stats: list[FileStats] = []
    for cfile in sorted(src_dir.glob("*.c")):
        stats = count_functions(cfile)
        if stats.total_functions > 0:
            all_stats.append(stats)

    # Aggregate
    total = sum(s.total_functions for s in all_stats)
    decompiled = sum(s.decompiled for s in all_stats)
    volatile = sum(s.asm_volatile for s in all_stats)
    individual = sum(s.individual_asm for s in all_stats)
    mixed = sum(s.mixed for s in all_stats)

    print("=" * 80)
    print("DECOMPILATION PROGRESS REPORT")
    print("=" * 80)
    print(f"\n  Total functions:   {total:>5}")
    print(f"  Decompiled (C):    {decompiled:>5}  ({100*decompiled/total:.1f}%)")
    print(f"  asm volatile:      {volatile:>5}  ({100*volatile/total:.1f}%)")
    print(f"  Individual asm:    {individual:>5}  ({100*individual/total:.1f}%)")
    print(f"  Mixed (C+asm):     {mixed:>5}  ({100*mixed/total:.1f}%)")

    # Progress bar
    pct = 100 * decompiled / total if total else 0
    bar_len = 50
    filled = int(bar_len * pct / 100)
    bar = '#' * filled + '-' * (bar_len - filled)
    print(f"\n  Decompiled: [{bar}] {pct:.1f}%")

    # Per-file breakdown (only files with asm remaining)
    asm_files = [s for s in all_stats if s.asm_volatile > 0 or s.individual_asm > 0]
    asm_files.sort(key=lambda s: s.asm_volatile + s.individual_asm, reverse=True)

    print(f"\n{'─' * 80}")
    print(f"  Files with remaining asm ({len(asm_files)} files)")
    print(f"{'─' * 80}")
    print(f"  {'File':<45} {'Total':>5} {'C':>5} {'Vol':>5} {'Ind':>5} {'Mix':>5}")
    print(f"  {'─'*45} {'─'*5} {'─'*5} {'─'*5} {'─'*5} {'─'*5}")
    for s in asm_files:
        print(f"  {s.filename:<45} {s.total_functions:>5} {s.decompiled:>5} {s.asm_volatile:>5} {s.individual_asm:>5} {s.mixed:>5}")

    # Fully decompiled files
    done_files = [s for s in all_stats if s.asm_volatile == 0 and s.individual_asm == 0 and s.mixed == 0]
    print(f"\n{'─' * 80}")
    print(f"  Fully decompiled files: {len(done_files)} / {len(all_stats)}")
    print(f"{'─' * 80}")


if __name__ == "__main__":
    main()

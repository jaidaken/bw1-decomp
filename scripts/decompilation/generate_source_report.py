#!/usr/bin/env python3
"""Generate a progress report.json from source analysis.

Analyzes src/c/, src/cpp/, and src/asm/ files to determine decompilation
progress without requiring objdiff or a full build. Each .c file's functions
are classified as pure C or mixed (containing inline asm).

Usage:
    python generate_source_report.py                    # uses default paths
    python generate_source_report.py -o report.json     # custom output
    python generate_source_report.py --build-dir DIR    # with .o sizes from build
"""

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent.parent

FUNC_PATTERN = re.compile(
    r'^(?:__attribute__\(\([^)]*\)\)\s*\n)?'
    r'(\S.*?)\s+(?:__fastcall|__cdecl)\s+(\w+)\s*\(([^)]*)\)\s*\n\{',
    re.MULTILINE,
)


def get_text_size(obj_path: Path, llvm_size: str) -> int:
    """Get .text section size from an object file."""
    try:
        r = subprocess.run(
            [llvm_size, '--format=sysv', str(obj_path)],
            capture_output=True, text=True, timeout=5,
        )
        for line in r.stdout.splitlines():
            if line.startswith('.text'):
                return int(line.split()[1])
    except (subprocess.TimeoutExpired, FileNotFoundError, ValueError):
        pass
    return 0


def count_nm_functions(obj_path: Path, llvm_nm: str) -> int:
    """Count text symbols in an object file."""
    try:
        r = subprocess.run(
            [llvm_nm, str(obj_path)],
            capture_output=True, text=True, timeout=5,
        )
        return max(1, sum(1 for l in r.stdout.splitlines() if ' T ' in l or ' t ' in l))
    except (subprocess.TimeoutExpired, FileNotFoundError):
        return 1


def count_c_functions(filepath: Path) -> tuple[int, int]:
    """Count total and pure-C functions in a C source file."""
    text = filepath.read_text()
    total = 0
    pure_c = 0
    for match in FUNC_PATTERN.finditer(text):
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
        total += 1
        has_volatile = 'asm volatile' in body
        has_individual = bool(re.search(r'asm\s*\("', body))
        if not has_volatile and not has_individual:
            pure_c += 1
    return max(1, total), pure_c


def count_asm_functions(filepath: Path) -> int:
    """Count functions in an asm file by .globl directives."""
    text = filepath.read_text()
    return max(1, len(re.findall(r'\.globl\s+', text)))


def estimate_file_size(filepath: Path) -> int:
    """Estimate code size from file size when no build is available."""
    return filepath.stat().st_size


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate source-based progress report")
    parser.add_argument("-o", "--output", type=Path, default=PROJECT_ROOT / "cmake-build-presets" / "objdiff" / "report.json")
    parser.add_argument("--build-dir", type=Path, default=None,
                        help="Path to cmake build directory (for accurate .text sizes)")
    parser.add_argument("--llvm-dir", type=Path, default=None,
                        help="Path to LLVM bin directory")
    args = parser.parse_args()

    # Find LLVM tools
    llvm_size = "llvm-size"
    llvm_nm = "llvm-nm"
    if args.llvm_dir:
        llvm_size = str(args.llvm_dir / "llvm-size")
        llvm_nm = str(args.llvm_dir / "llvm-nm")

    # Build a map from source file stem to .o path if build dir available
    obj_map: dict[str, Path] = {}
    if args.build_dir and (args.build_dir / "compile_commands.json").exists():
        with open(args.build_dir / "compile_commands.json") as f:
            for entry in json.load(f):
                src = Path(entry['file'])
                out = Path(entry['output'])
                if not out.is_absolute():
                    out = args.build_dir / out
                if out.exists():
                    obj_map[src.stem] = out

    has_build = bool(obj_map)

    units: list[dict] = []
    total_funcs = 0
    matched_funcs = 0
    pure_c_funcs = 0

    # Process C files
    src_c = PROJECT_ROOT / "src" / "c"
    for cfile in sorted(src_c.glob("*.c")):
        funcs, pure = count_c_functions(cfile)
        pure_pct = 100.0 * pure / funcs if funcs > 0 else 0

        if has_build and cfile.stem in obj_map:
            text_size = get_text_size(obj_map[cfile.stem], llvm_size)
        else:
            text_size = estimate_file_size(cfile)

        if text_size == 0:
            continue

        total_funcs += funcs
        matched_funcs += funcs
        pure_c_funcs += pure

        units.append({
            'name': cfile.stem,
            'measures': {
                'total_code': str(text_size),
                'matched_code': str(text_size),
                'matched_code_percent': 100.0,
                'total_functions': funcs,
                'matched_functions': funcs,
                'pure_c_functions': pure,
                'pure_c_percent': pure_pct,
            },
            'metadata': {'complete': True},
        })

    # Process C++ files
    src_cpp = PROJECT_ROOT / "src" / "cpp"
    for cppfile in sorted(src_cpp.glob("*.cpp")):
        if has_build and cppfile.stem in obj_map:
            text_size = get_text_size(obj_map[cppfile.stem], llvm_size)
        else:
            text_size = estimate_file_size(cppfile)

        if text_size == 0:
            continue

        total_funcs += 1
        matched_funcs += 1
        pure_c_funcs += 1

        units.append({
            'name': cppfile.stem,
            'measures': {
                'total_code': str(text_size),
                'matched_code': str(text_size),
                'matched_code_percent': 100.0,
                'total_functions': 1,
                'matched_functions': 1,
                'pure_c_functions': 1,
                'pure_c_percent': 100.0,
            },
            'metadata': {'complete': True},
        })

    # Process ASM files
    src_asm = PROJECT_ROOT / "src" / "asm" / "unprocessed"
    for asmfile in sorted(src_asm.glob("*.asm")):
        funcs = count_asm_functions(asmfile)

        if has_build and asmfile.stem in obj_map:
            text_size = get_text_size(obj_map[asmfile.stem], llvm_size)
        else:
            text_size = estimate_file_size(asmfile)

        if text_size == 0:
            continue

        total_funcs += funcs

        units.append({
            'name': asmfile.stem,
            'measures': {
                'total_code': str(text_size),
                'matched_code': '0',
                'matched_code_percent': 0,
                'total_functions': funcs,
                'matched_functions': 0,
                'pure_c_functions': 0,
                'pure_c_percent': 0,
            },
            'metadata': {},
        })

    # Add LIBCMT/LIBCPMT if build is available
    if args.build_dir:
        for d in ['LIBCMT-patched', 'LIBCPMT-patched']:
            p = args.build_dir / d
            if not p.exists():
                continue
            for obj in sorted(p.glob('*.o')):
                text_size = get_text_size(obj, llvm_size)
                if text_size == 0:
                    continue
                funcs = count_nm_functions(obj, llvm_nm)
                total_funcs += funcs
                matched_funcs += funcs
                pure_c_funcs += funcs
                units.append({
                    'name': obj.stem.split('.')[0],
                    'measures': {
                        'total_code': str(text_size),
                        'matched_code': str(text_size),
                        'matched_code_percent': 100.0,
                        'total_functions': funcs,
                        'matched_functions': funcs,
                        'pure_c_functions': funcs,
                        'pure_c_percent': 100.0,
                    },
                    'metadata': {'complete': True, 'auto_generated': True},
                })

    # Compute global measures
    total_code = sum(int(u['measures']['total_code']) for u in units)
    matched_code = sum(int(u['measures']['matched_code']) for u in units)
    pct = 100.0 * matched_code / total_code if total_code else 0
    pure_c_code = sum(
        int(int(u['measures']['total_code']) * u['measures']['pure_c_percent'] / 100)
        for u in units
    )
    pure_c_pct = 100.0 * pure_c_code / total_code if total_code else 0

    report = {
        'measures': {
            'total_code': str(total_code),
            'matched_code': str(matched_code),
            'matched_code_percent': pct,
            'total_functions': total_funcs,
            'matched_functions': matched_funcs,
            'pure_c_functions': pure_c_funcs,
            'pure_c_code': str(pure_c_code),
            'pure_c_percent': pure_c_pct,
        },
        'units': units,
    }

    args.output.parent.mkdir(parents=True, exist_ok=True)
    with open(args.output, 'w') as f:
        json.dump(report, f, indent=2)

    print(f"Decompiled: {pct:.2f}% ({matched_funcs}/{total_funcs} functions)")
    print(f"Pure C:     {pure_c_pct:.2f}% ({pure_c_funcs}/{total_funcs} functions)")
    return 0


if __name__ == "__main__":
    sys.exit(main())

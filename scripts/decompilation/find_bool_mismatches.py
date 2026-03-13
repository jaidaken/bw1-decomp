#!/usr/bin/env python3
"""Find staging functions that use `bool` return type but whose corresponding
asm() attribute in the headers uses `I` (uint32_t) return mangling instead of
`_N` (bool).

These should be changed to `bool32_t`.

MSVC mangling after @@<calling_convention>:
  _N  = bool
  I   = unsigned int (uint32_t / bool32_t)

Calling convention patterns (3 uppercase letters after @@):
  UAE = virtual __thiscall (non-const)
  UBE = virtual __thiscall (const)
  QAE = non-virtual __thiscall (non-const)
  QBE = non-virtual __thiscall (const)
  IAE = near __thiscall (non-const, protected)
  IBE = near __thiscall (const, protected)
  AAE = private __thiscall (non-const)
  ABE = private __thiscall (const)
  SA  = static (cdecl)
  YA  = free function (cdecl)
"""

import re
import sys
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[2]
HEADERS_DIR = PROJECT_ROOT / "black"
STAGING_DIR = PROJECT_ROOT / "src" / "staging"


def count_mangled_params(rest_after_ret: str) -> int:
    """Count parameters from the mangled suffix after the return type.

    This is a rough heuristic. In MSVC mangling:
      XZ = void params (0 params)
      <type>@Z = one param, etc.
    We just need to distinguish 0, 1, 2+ params for overload matching.
    """
    if rest_after_ret == "XZ" or rest_after_ret == "Z":
        return 0
    # Count @ signs before final Z roughly corresponds to param separators
    # But this is really a rough heuristic. Better to look at the C declaration.
    return -1  # unknown, but non-zero


def count_c_params_from_header(line: str) -> int:
    """Count the number of non-this, non-edx parameters from the header C declaration.

    Header declarations look like:
        bool __fastcall FuncName(struct Class* this, const void* edx, Type1 p1, Type2 p2)
    We skip 'this' and 'edx' params.
    """
    m = re.search(r'__(?:fastcall|cdecl)\s+\w+\s*\(([^)]*)\)', line)
    if not m:
        return -1
    params_str = m.group(1).strip()
    if not params_str:
        return 0
    params = [p.strip() for p in params_str.split(",")]
    # Skip 'this' and 'edx' params (first two for __fastcall member functions)
    real_params = []
    for p in params:
        if "this" in p or "edx" in p:
            continue
        real_params.append(p)
    return len(real_params)


def count_staging_params(line: str) -> int:
    """Count parameters from a staging function definition line.

    Staging definitions look like:
        bool ClassName::FuncName(Type1 p1, Type2 p2) const
    """
    m = re.search(r'\(([^)]*)\)', line)
    if not m:
        return -1
    params_str = m.group(1).strip()
    if not params_str:
        return 0
    # Handle function pointer params which contain commas inside parens
    # Simple approach: just count top-level commas
    depth = 0
    count = 1
    for ch in params_str:
        if ch == '(':
            depth += 1
        elif ch == ')':
            depth -= 1
        elif ch == ',' and depth == 0:
            count += 1
    return count


def parse_header_asm_attrs(headers_dir: Path) -> dict:
    """Parse all asm() attributes from header files.

    Returns a dict mapping (class_name, func_name) to a list of entry dicts.
    """
    asm_pattern = re.compile(
        r'(\w+)\s+__(?:fastcall|cdecl|stdcall)\s+'
        r'(\w+)\s*\('   # mangled C name
        r'.*?\)\s*'     # params (non-greedy, handles nested parens via asm anchor)
        r'asm\("([^"]+)"\)'
    )

    mangled_pattern = re.compile(
        r'\?(\w+)@(\w+)@@'
        r'([A-Z]{3}|[A-Z]{2})'  # calling convention
        r'(.+)'  # return type + params
    )

    special_pattern = re.compile(r'\?\?_')

    results = {}

    for header_file in sorted(headers_dir.glob("*.h")):
        with open(header_file, "r", encoding="utf-8", errors="replace") as f:
            for line_num, line in enumerate(f, 1):
                if 'asm("' not in line:
                    continue

                m = asm_pattern.search(line)
                if not m:
                    continue

                ret_type = m.group(1)
                mangled_name = m.group(3)

                if special_pattern.match(mangled_name):
                    continue

                mm = mangled_pattern.match(mangled_name)
                if not mm:
                    continue

                func_name = mm.group(1)
                class_name = mm.group(2)
                cc = mm.group(3)
                rest = mm.group(4)

                # Determine return type mangling
                if rest.startswith("_N"):
                    return_mangling = "_N"
                    params_suffix = rest[2:]
                elif rest.startswith("I"):
                    return_mangling = "I"
                    params_suffix = rest[1:]
                elif rest.startswith("X"):
                    return_mangling = "X"
                    params_suffix = rest[1:]
                else:
                    return_mangling = rest[0]
                    params_suffix = rest[1:]

                is_const = cc in ("UBE", "QBE", "IBE", "ABE")
                n_params = count_c_params_from_header(line)

                key = (class_name, func_name)
                if key not in results:
                    results[key] = []
                results[key].append({
                    "header_file": str(header_file.relative_to(PROJECT_ROOT)),
                    "line_num": line_num,
                    "mangled": mangled_name,
                    "return_mangling": return_mangling,
                    "ret_type": ret_type,
                    "is_const": is_const,
                    "n_params": n_params,
                    "params_suffix": params_suffix,
                    "line": line.strip(),
                })

    return results


def parse_staging_bool_functions(staging_dir: Path) -> list:
    """Find all function definitions in staging that return `bool` (not bool32_t)."""
    func_pattern = re.compile(
        r'^bool\s+'
        r'(?:(\w+)::)?'     # optional class name
        r'(\w+)\s*\('       # function name
        r'([^)]*)\)'        # params (captured for counting)
        r'(\s*const)?'      # optional const qualifier
    )

    results = []

    for src_file in sorted(staging_dir.iterdir()):
        if not (src_file.suffix == ".cpp" or src_file.suffix == ".c"):
            continue

        with open(src_file, "r", encoding="utf-8", errors="replace") as f:
            for line_num, line in enumerate(f, 1):
                stripped = line.strip()

                if stripped.startswith("bool32_t"):
                    continue

                m = func_pattern.match(stripped)
                if not m:
                    continue

                class_name = m.group(1)
                func_name = m.group(2)
                is_const = m.group(4) is not None
                n_params = count_staging_params(stripped)

                results.append({
                    "file": str(src_file.relative_to(PROJECT_ROOT)),
                    "line_num": line_num,
                    "class_name": class_name,
                    "func_name": func_name,
                    "is_const": is_const,
                    "n_params": n_params,
                    "full_line": stripped,
                })

    return results


def find_best_header_match(staging_func, header_entries):
    """Find the best matching header declaration for a staging function.

    Matching priority:
    1. Same param count + same const-ness
    2. Same param count (any const)
    3. Same const-ness (any param count)
    4. First entry (fallback)
    """
    s_const = staging_func["is_const"]
    s_nparams = staging_func["n_params"]

    # Score entries
    scored = []
    for entry in header_entries:
        score = 0
        if entry["n_params"] == s_nparams:
            score += 10
        if entry["is_const"] == s_const:
            score += 1
        scored.append((score, entry))

    scored.sort(key=lambda x: -x[0])
    return scored[0][1]


def find_mismatches():
    """Find staging functions where bool should be bool32_t based on mangling."""
    print("Parsing header asm() attributes...")
    header_attrs = parse_header_asm_attrs(HEADERS_DIR)
    total_decls = sum(len(v) for v in header_attrs.values())
    print(f"  Found {total_decls} asm declarations across {len(header_attrs)} unique (class, func) pairs")

    print("\nParsing staging bool functions...")
    staging_funcs = parse_staging_bool_functions(STAGING_DIR)
    print(f"  Found {len(staging_funcs)} bool functions in staging")

    print("\n" + "=" * 100)
    print("MISMATCHES: staging uses `bool` but mangling says `I` (uint32_t) -- should be `bool32_t`")
    print("=" * 100)

    mismatches = []
    matched_correct = []
    unmatched = []

    for sf in staging_funcs:
        class_name = sf["class_name"]
        func_name = sf["func_name"]

        if class_name is None:
            unmatched.append((sf, "free function"))
            continue

        key = (class_name, func_name)

        if key not in header_attrs:
            unmatched.append((sf, "no header match"))
            continue

        entries = header_attrs[key]
        best = find_best_header_match(sf, entries)

        ret = best["return_mangling"]
        if ret == "I":
            mismatches.append((sf, best))
        elif ret == "_N":
            matched_correct.append((sf, best))
        else:
            unmatched.append((sf, f"unexpected return mangling: {ret} in {best['mangled']}"))

    # Print mismatches
    for sf, hdr in mismatches:
        const_str = " const" if sf["is_const"] else ""
        print(f"\n  {sf['file']}:{sf['line_num']}")
        print(f"    staging:  bool {sf['class_name']}::{sf['func_name']}(...){const_str}  [{sf['n_params']} params]")
        print(f"    header:   {hdr['header_file']}:{hdr['line_num']}  [{hdr['n_params']} params]")
        print(f"    mangled:  {hdr['mangled']}")
        print(f"    return:   I (uint32_t) -- should be bool32_t")

    print(f"\n{'=' * 100}")
    print(f"SUMMARY")
    print(f"{'=' * 100}")
    print(f"  Total bool functions in staging:     {len(staging_funcs)}")
    print(f"  Mismatches (bool -> bool32_t):        {len(mismatches)}")
    print(f"  Correctly using bool (_N mangling):   {len(matched_correct)}")
    print(f"  Unmatched / other:                    {len(unmatched)}")

    if unmatched:
        print(f"\n{'=' * 100}")
        print(f"UNMATCHED (no header found or other):")
        print(f"{'=' * 100}")
        for sf, reason in unmatched:
            cls = sf["class_name"] or "(free)"
            print(f"  {sf['file']}:{sf['line_num']} -- {cls}::{sf['func_name']} -- {reason}")

    return mismatches


if __name__ == "__main__":
    mismatches = find_mismatches()
    sys.exit(0 if not mismatches else 1)

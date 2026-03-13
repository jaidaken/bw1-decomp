#!/usr/bin/env python3
"""Generate staging code for scalar deleting destructors (??_G functions).

Reads sdtor_analysis.json and generates:
1. .patch files containing C++ code blocks to append to staging .cpp files
2. cl_wrapper_entries.py with Python dict literals for cl_wrapper.py

MSVC 6.0 (original binary) generates ??_G differently from MSVC 12.0 (staging).
This script generates __declspec(naked) replacements that replicate the original pattern.
"""

import json
import re
from collections import defaultdict
from pathlib import Path

SCRIPT_DIR = Path(__file__).parent
PROJECT_ROOT = SCRIPT_DIR.parent.parent
ANALYSIS_JSON = SCRIPT_DIR / "sdtor_analysis.json"
OUTPUT_DIR = SCRIPT_DIR / "sdtor_generated"
ASM_DIR = PROJECT_ROOT / "src" / "asm" / "unprocessed"

SKIP_CLASSES = frozenset({
    "Feature", "CitadelBuildingSite", "Mobile", "Flowers", "Furniture",
    "GestureSystem", "PSysInterface", "Particle3DPnt", "ParticleChainJoint",
    "TownStats", "WorshipSiteUpgrade",
})

SUPPORTED_VARIANTS = frozenset({
    "standard_1arg",
    "standard_2arg",
    "vtable_write_1arg",
    "vtable_write_2arg",
    "no_dtor_vtable_write_1arg",
})


def sanitize_c_name(name):
    """Sanitize a class name for use as a C identifier.

    Replaces @ with _AT_ since @ is not valid in C identifiers or asm labels.
    """
    return name.replace("@", "_AT_")


def is_jmp_thunk(symbol):
    """Check if symbol is a _jmp_addr_ thunk."""
    return symbol is not None and symbol.startswith("_jmp_addr_")


def is_lbl_addr(symbol):
    """Check if symbol is a .Lbl_addr_ local label."""
    return symbol is not None and symbol.startswith(".Lbl_addr_")


def is_mangled_cpp(symbol):
    """Check if symbol is a mangled C++ name (starts with ??)."""
    return symbol is not None and symbol.startswith("??")


def is_import_thunk(symbol):
    """Check if symbol is an import thunk (dword ptr [__imp_...])."""
    return symbol is not None and symbol.startswith("dword ptr [")


def needs_proxy(symbol):
    """Check if a symbol needs a proxy (rename) in cl_wrapper.

    _jmp_addr_ symbols don't need proxies because the C compiler adds the _
    prefix automatically. Everything else (mangled C++ symbols, .Lbl_addr_
    labels, import thunks) needs proxies because they can't be valid C
    identifiers.
    """
    if symbol is None:
        return False
    if is_jmp_thunk(symbol):
        return False
    # Everything else needs a proxy
    return True


def dtor_c_name(symbol, dtor_id_map):
    """Return the C identifier to use for a destructor call in asm."""
    if symbol is None:
        return None
    if is_jmp_thunk(symbol):
        # _jmp_addr_0x00436960 -> jmp_addr_0x00436960 (C compiler adds _ prefix)
        return symbol[1:]  # strip leading _
    # Mangled, .Lbl_addr_, import thunk, etc. -> use proxy
    return f"sdtor_dt_{dtor_id_map[symbol]}"


def dtor_call_asm(symbol, dtor_id_map):
    """Return the full asm call instruction for a destructor.

    Import thunks use indirect calls: call dword ptr [proxy]
    Everything else uses direct calls: call proxy
    """
    if symbol is None:
        return None
    c_name = dtor_c_name(symbol, dtor_id_map)
    if is_import_thunk(symbol):
        return f"call dword ptr [{c_name}]"
    return f"call {c_name}"


def vtable_c_name(vtable_address, vt_id_map):
    """Return the C identifier for a vtable reference in asm."""
    if vtable_address is None:
        return None
    return f"sdtor_vt_{vt_id_map[vtable_address]}"


def opdelete_c_name(symbol, opd_id_map):
    """Return the C identifier for an operator delete call in asm."""
    if is_jmp_thunk(symbol):
        return symbol[1:]  # strip leading _
    return f"sdtor_opd_{opd_id_map[symbol]}"


def parse_vtable_address_map():
    """Parse rdata vftable asm files to build vtable_address -> class_name map.

    The VftableAndRTTI label is at offset N, and the actual vfptr starts at
    offset N+4 (after the RTTI Complete Object Locator pointer). So the vtable
    address written by ??_G functions is VftableAndRTTI_address + 4.

    Returns:
        dict mapping vtable address string (e.g. "0x008b5658") to class name
    """
    vt_map = {}
    pattern = re.compile(
        r'^VftableAndRTTI\s+(\S+)\s+.*?=\s+(0x[0-9a-f]+)\s*$'
    )

    for asm_path in sorted(ASM_DIR.glob("rdata.*vftables*.asm")):
        with open(asm_path) as f:
            for line in f:
                m = pattern.match(line)
                if m:
                    class_name = m.group(1)
                    rtti_addr = int(m.group(2), 16)
                    # vfptr is at rtti_addr + 4
                    vfptr_addr = f"0x{rtti_addr + 4:08x}"
                    vt_map[vfptr_addr] = class_name

    return vt_map


def build_id_maps(entries):
    """Build sequential ID maps for unique symbols that need proxies.

    Returns:
        dtor_id_map: {real_dtor_symbol: id_number} for symbols needing proxies
        vt_id_map: {vtable_address: id_number}
        opd_id_map: {real_opdelete_symbol: id_number} for symbols needing proxies
    """
    dtor_id_map = {}
    vt_id_map = {}
    opd_id_map = {}

    dtor_counter = 0
    vt_counter = 0
    opd_counter = 0

    for entry in entries:
        dtor = entry["destructor_call"]
        if dtor is not None and needs_proxy(dtor) and dtor not in dtor_id_map:
            dtor_id_map[dtor] = dtor_counter
            dtor_counter += 1

        if entry["has_vtable_write"] and entry["vtable_address"] is not None:
            vt_addr = entry["vtable_address"]
            if vt_addr not in vt_id_map:
                vt_id_map[vt_addr] = vt_counter
                vt_counter += 1

        opd = entry["op_delete_call"]
        if needs_proxy(opd) and opd not in opd_id_map:
            opd_id_map[opd] = opd_counter
            opd_counter += 1

    return dtor_id_map, vt_id_map, opd_id_map


def generate_extern_decls(file_entries, dtor_id_map, vt_id_map, opd_id_map):
    """Generate unique extern "C" declarations for a staging file."""
    declared = set()
    lines = []

    for entry in file_entries:
        dtor = entry["destructor_call"]
        if dtor is not None:
            c_name = dtor_c_name(dtor, dtor_id_map)
            if c_name not in declared:
                declared.add(c_name)
                if is_import_thunk(dtor):
                    # Import thunks are data (IAT pointers), used with indirect call
                    lines.append(f'extern "C" char {c_name};')
                else:
                    lines.append(f'extern "C" void {c_name}();')

        if entry["has_vtable_write"] and entry["vtable_address"] is not None:
            c_name = vtable_c_name(entry["vtable_address"], vt_id_map)
            if c_name not in declared:
                declared.add(c_name)
                lines.append(f'extern "C" char {c_name};')

        opd = entry["op_delete_call"]
        c_name = opdelete_c_name(opd, opd_id_map)
        if c_name not in declared:
            declared.add(c_name)
            lines.append(f'extern "C" void {c_name}();')

    return lines


def generate_naked_function(entry, dtor_id_map, vt_id_map, opd_id_map):
    """Generate a __declspec(naked) function for one entry."""
    cls = sanitize_c_name(entry["class_name"])
    variant = entry["variant"]
    has_vtable = entry["has_vtable_write"]
    has_dtor = entry["destructor_call"] is not None

    dtor_call = dtor_call_asm(entry["destructor_call"], dtor_id_map) if has_dtor else None
    opd_ref = opdelete_c_name(entry["op_delete_call"], opd_id_map)
    vt_ref = vtable_c_name(entry["vtable_address"], vt_id_map) if has_vtable else None

    is_2arg = "2arg" in variant
    delete_size = entry["delete_size_hex"]

    lines = []
    lines.append(f"__declspec(naked) void __cdecl sdtor_{cls}() {{")
    lines.append("    __asm {")
    lines.append("        push esi")
    lines.append("        mov esi, ecx")

    if has_vtable and vt_ref is not None:
        lines.append(f"        mov dword ptr [esi], offset {vt_ref}")

    if has_dtor and dtor_call is not None:
        lines.append(f"        {dtor_call}")

    lines.append("        test byte ptr [esp + 8], 1")
    lines.append(f"        je short skip_{cls}")

    if is_2arg:
        lines.append(f"        push {delete_size}")

    lines.append("        push esi")
    lines.append(f"        call {opd_ref}")

    if is_2arg:
        lines.append("        add esp, 8")
    else:
        lines.append("        add esp, 4")

    lines.append(f"    skip_{cls}:")
    lines.append("        mov eax, esi")
    lines.append("        pop esi")
    lines.append("        ret 4")
    lines.append("    }")
    lines.append("}")

    return lines


def extract_import_symbol(import_expr):
    """Extract the actual symbol name from an import thunk expression.

    "dword ptr [__imp___1LHLobby__UAE_XZ@4]" -> "__imp___1LHLobby__UAE_XZ@4"
    """
    # Strip "dword ptr [" prefix and "]" suffix
    start = import_expr.index("[") + 1
    end = import_expr.index("]")
    return import_expr[start:end]


def generate_cl_wrapper_entries(entries, dtor_id_map, vt_id_map, opd_id_map,
                                vtable_addr_map):
    """Generate the three cl_wrapper.py dictionaries."""
    hide_auto = {}
    rename_manual = {}
    rename_proxies = {}

    # Counter for defunct names
    defunct_counter = 0

    for entry in entries:
        cls = entry["class_name"]
        safe_cls = sanitize_c_name(cls)
        sdtor_symbol = f"??_G{cls}@@UAEPAXI@Z"

        # hide_auto: rename auto-generated ??_G to defunct
        hide_auto[sdtor_symbol] = f"?defunct_sg{defunct_counter}@@YAXXZ"
        defunct_counter += 1

        # rename_manual: rename manual sdtor_<SafeClassName> to ??_G
        # The C function sdtor_<SafeClassName>() gets mangled to ?sdtor_<SafeClassName>@@YAXXZ
        rename_manual[f"?sdtor_{safe_cls}@@YAXXZ"] = sdtor_symbol

    # rename_proxies: map proxy symbols to real symbols
    # Destructor proxies
    for real_symbol, id_num in sorted(dtor_id_map.items(), key=lambda x: x[1]):
        proxy = f"_sdtor_dt_{id_num}"
        # For import thunks, extract the actual symbol name from the expression
        if is_import_thunk(real_symbol):
            rename_proxies[proxy] = extract_import_symbol(real_symbol)
        else:
            rename_proxies[proxy] = real_symbol

    # Vtable proxies - use the vtable_addr_map parsed from rdata asm
    # to get the correct class name for each vtable address
    for vt_addr, id_num in sorted(vt_id_map.items(), key=lambda x: x[1]):
        proxy = f"_sdtor_vt_{id_num}"
        if vt_addr in vtable_addr_map:
            vt_class = vtable_addr_map[vt_addr]
        else:
            # Fallback: find the first class that uses this vtable address
            vt_class = None
            for entry in entries:
                if entry["vtable_address"] == vt_addr:
                    vt_class = entry["class_name"]
                    break
            print(f"WARNING: vtable address {vt_addr} not found in rdata asm, "
                  f"using class name: {vt_class}")
        rename_proxies[proxy] = f"??_7{vt_class}@@6B@"

    # Op delete proxies
    for real_symbol, id_num in sorted(opd_id_map.items(), key=lambda x: x[1]):
        proxy = f"_sdtor_opd_{id_num}"
        rename_proxies[proxy] = real_symbol

    return hide_auto, rename_manual, rename_proxies


def format_dict(d, name, indent=4):
    """Format a Python dict as a readable string."""
    pad = " " * indent
    lines = [f"{name} = {{"]
    for k, v in d.items():
        lines.append(f'{pad}"{k}": "{v}",')
    lines.append("}")
    return "\n".join(lines)


def main():
    with open(ANALYSIS_JSON) as f:
        all_entries = json.load(f)

    # Partition entries
    skipped_already_handled = []
    skipped_complex = []
    to_generate = []

    for entry in all_entries:
        cls = entry["class_name"]
        variant = entry["variant"]

        if cls in SKIP_CLASSES:
            skipped_already_handled.append(entry)
            continue

        if variant not in SUPPORTED_VARIANTS:
            skipped_complex.append(entry)
            continue

        to_generate.append(entry)

    # Parse vtable address -> class name from rdata asm files
    vtable_addr_map = parse_vtable_address_map()

    # Build ID maps for proxy symbols
    dtor_id_map, vt_id_map, opd_id_map = build_id_maps(to_generate)

    # Group by staging file
    by_file = defaultdict(list)
    for entry in to_generate:
        staging_file = entry["asm_file"].replace(".asm", ".cpp")
        by_file[staging_file].append(entry)

    # Create output directory
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    # Generate patch files
    for staging_file, file_entries in sorted(by_file.items()):
        patch_lines = []
        patch_lines.append("")
        patch_lines.append("// ============================================================")
        patch_lines.append("// Scalar deleting destructor replacements (auto-generated)")
        patch_lines.append("// ============================================================")
        patch_lines.append("")

        # Extern declarations
        extern_lines = generate_extern_decls(
            file_entries, dtor_id_map, vt_id_map, opd_id_map
        )
        patch_lines.extend(extern_lines)
        patch_lines.append("")

        # Naked functions
        for entry in file_entries:
            func_lines = generate_naked_function(
                entry, dtor_id_map, vt_id_map, opd_id_map
            )
            patch_lines.extend(func_lines)
            patch_lines.append("")

        patch_path = OUTPUT_DIR / f"{staging_file}.patch"
        patch_path.write_text("\n".join(patch_lines))

    # Generate cl_wrapper entries
    hide_auto, rename_manual, rename_proxies = generate_cl_wrapper_entries(
        to_generate, dtor_id_map, vt_id_map, opd_id_map, vtable_addr_map
    )

    cl_wrapper_path = OUTPUT_DIR / "cl_wrapper_entries.py"
    sections = []
    sections.append('"""Auto-generated cl_wrapper.py entries for scalar deleting destructors."""')
    sections.append("")
    sections.append("# Step 1: Hide auto-generated ??_G symbols (rename to defunct names)")
    sections.append(format_dict(hide_auto, "hide_auto"))
    sections.append("")
    sections.append("# Step 2: Rename manual sdtor functions to ??_G symbol names")
    sections.append(format_dict(rename_manual, "rename_manual"))
    sections.append("")
    sections.append("# Step 3: Rename proxy symbols to real mangled names")
    sections.append(format_dict(rename_proxies, "rename_proxies"))
    sections.append("")

    cl_wrapper_path.write_text("\n".join(sections))

    # Print summary
    variant_counts = defaultdict(int)
    for entry in to_generate:
        variant_counts[entry["variant"]] += 1

    print("=" * 60)
    print("Scalar Deleting Destructor Staging Generator")
    print("=" * 60)
    print()
    print(f"Total entries in JSON:           {len(all_entries)}")
    print(f"Already handled (skipped):       {len(skipped_already_handled)}")
    print(f"Complex variants (skipped):      {len(skipped_complex)}")
    print(f"Entries to generate:             {len(to_generate)}")
    print()
    print("Variant breakdown:")
    for variant in sorted(variant_counts):
        print(f"  {variant:35s} {variant_counts[variant]:4d}")
    print()
    print(f"Staging files affected:          {len(by_file)}")
    print()
    print("Proxy symbol counts:")
    print(f"  Destructor proxies (mangled/Lbl): {len(dtor_id_map)}")
    print(f"  Vtable proxies:                   {len(vt_id_map)}")
    print(f"  Operator delete proxies:          {len(opd_id_map)}")
    print()

    # Jmp thunk breakdown
    dtor_jmp = sum(1 for e in to_generate if is_jmp_thunk(e["destructor_call"]))
    dtor_lbl = sum(1 for e in to_generate if is_lbl_addr(e["destructor_call"]))
    dtor_mangled = sum(
        1 for e in to_generate
        if e["destructor_call"] is not None and is_mangled_cpp(e["destructor_call"])
    )
    dtor_import = sum(1 for e in to_generate if is_import_thunk(e["destructor_call"]))
    dtor_none = sum(1 for e in to_generate if e["destructor_call"] is None)
    opd_jmp = sum(1 for e in to_generate if is_jmp_thunk(e["op_delete_call"]))
    opd_mangled = sum(1 for e in to_generate if is_mangled_cpp(e["op_delete_call"]))

    print("Destructor call types:")
    print(f"  Mangled C++ (??):                 {dtor_mangled}")
    print(f"  Thunks (_jmp_addr_):              {dtor_jmp}")
    print(f"  Local labels (.Lbl_addr_):        {dtor_lbl}")
    print(f"  Import thunks (__imp_):           {dtor_import}")
    print(f"  None (no destructor):             {dtor_none}")
    print()
    print("Operator delete call types:")
    print(f"  Mangled C++ (??3):                {opd_mangled}")
    print(f"  Thunks (_jmp_addr_):              {opd_jmp}")
    print()
    print(f"Output directory: {OUTPUT_DIR}")
    print(f"  Patch files: {len(by_file)}")
    print(f"  cl_wrapper_entries.py: 1")
    print()

    if skipped_complex:
        print("Skipped complex variants:")
        for entry in skipped_complex:
            print(f"  {entry['class_name']:40s} {entry['variant']:25s} {entry['asm_file']}")
        print()


if __name__ == "__main__":
    main()

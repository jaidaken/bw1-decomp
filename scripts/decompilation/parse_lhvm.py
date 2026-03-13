"""Parse LHVM bytecode from challenge.chl and search for specific native calls.

Usage: python parse_lhvm.py <chl_file> [--call N] [--disasm SCRIPT_NAME] [--list-scripts]
"""
import struct
import sys
from pathlib import Path

OPCODES = {
    0x00: "END", 0x01: "WAIT", 0x02: "PUSH", 0x03: "POP",
    0x04: "ADD", 0x05: "CALL", 0x06: "SUB", 0x07: "NEG",
    0x08: "MUL", 0x09: "DIV", 0x0A: "MOD", 0x0B: "NOT",
    0x0C: "AND", 0x0D: "OR", 0x0E: "EQ", 0x0F: "NEQ",
    0x10: "GEQ", 0x11: "LEQ", 0x12: "GT", 0x13: "LT",
    0x14: "JUMP", 0x15: "SLEEP", 0x16: "EXCEPT", 0x17: "CAST",
    0x18: "RUN", 0x19: "ENDEXCEPT", 0x1A: "RETEXCEPT",
    0x1B: "FAILEXCEPT", 0x1C: "BRKEXCEPT", 0x1D: "SWAP",
    0x1E: "LINE",
}

DATA_TYPES = {
    0: "none", 1: "int", 2: "float", 3: "vector",
    4: "obj", 5: "bool", 6: "var",
}


def read_cstr(data, offset):
    """Read null-terminated string from data."""
    end = data.index(b'\x00', offset)
    return data[offset:end].decode('ascii', errors='replace'), end + 1


def parse_chl(path):
    """Parse a .chl file and return its components."""
    data = Path(path).read_bytes()
    off = 0

    # Header
    magic = data[off:off+4]
    off += 4
    assert magic == b'LHVM', f"Bad magic: {magic}"
    version = struct.unpack_from('<I', data, off)[0]
    off += 4
    print(f"LHVM version {version}")

    # Global variables
    num_globals = struct.unpack_from('<I', data, off)[0]
    off += 4
    globals_list = []
    for _ in range(num_globals):
        name, off = read_cstr(data, off)
        globals_list.append(name)
    print(f"{num_globals} global variables")

    # Code section
    num_instructions = struct.unpack_from('<I', data, off)[0]
    off += 4
    print(f"{num_instructions} instructions")

    instructions = []
    for i in range(num_instructions):
        opcode, access, dtype, param, lineno = struct.unpack_from('<5I', data, off)
        off += 20
        instructions.append((opcode, access, dtype, param, lineno))

    # Auto-start scripts
    num_autostart = struct.unpack_from('<I', data, off)[0]
    off += 4
    autostart_ids = []
    for _ in range(num_autostart):
        sid = struct.unpack_from('<I', data, off)[0]
        off += 4
        autostart_ids.append(sid)
    print(f"{num_autostart} auto-start scripts: {autostart_ids}")

    # Scripts section
    num_scripts = struct.unpack_from('<I', data, off)[0]
    off += 4
    scripts = []
    for _ in range(num_scripts):
        name, off = read_cstr(data, off)
        source, off = read_cstr(data, off)
        unk1, unk2 = struct.unpack_from('<II', data, off)
        off += 8
        num_locals = struct.unpack_from('<I', data, off)[0]
        off += 4
        locals_list = []
        for _ in range(num_locals):
            lname, off = read_cstr(data, off)
            locals_list.append(lname)
        ip, param_count, script_id = struct.unpack_from('<III', data, off)
        off += 12
        scripts.append({
            'name': name, 'source': source, 'unk1': unk1, 'unk2': unk2,
            'locals': locals_list, 'ip': ip, 'param_count': param_count,
            'id': script_id,
        })
    print(f"{num_scripts} scripts")

    return {
        'version': version,
        'globals': globals_list,
        'instructions': instructions,
        'autostart': autostart_ids,
        'scripts': scripts,
    }


def find_script_for_ip(scripts, ip):
    """Find which script owns an instruction pointer."""
    best = None
    for s in scripts:
        if s['ip'] <= ip:
            if best is None or s['ip'] > best['ip']:
                best = s
    return best


def disasm_instruction(ip, instr, globals_list=None):
    """Disassemble a single instruction."""
    opcode, access, dtype, param, lineno = instr
    mnem = OPCODES.get(opcode, f"UNK_{opcode:#x}")
    dt = DATA_TYPES.get(dtype, f"type{dtype}")
    acc = "stk" if access == 1 else "var" if access == 2 else f"acc{access}"

    extra = ""
    if opcode == 0x02:  # PUSH
        if dtype == 2:  # float
            fval = struct.unpack('<f', struct.pack('<I', param))[0]
            extra = f" {fval}"
        elif access == 2 and globals_list and param < len(globals_list):
            extra = f" [{globals_list[param]}]"
        else:
            extra = f" {param}"
    elif opcode == 0x05:  # CALL
        extra = f" #{param}"
    elif opcode == 0x14:  # JUMP
        extra = f" -> {param}"
    elif opcode == 0x18:  # RUN
        extra = f" script#{param}"
    elif opcode == 0x03:  # POP
        if access == 2 and globals_list and param < len(globals_list):
            extra = f" [{globals_list[param]}]"
        else:
            extra = f" {param}"
    else:
        if param != 0:
            extra = f" {param}"

    return f"  [{ip:6d}] {mnem:12s} {acc:4s} {dt:6s}{extra}  (line {lineno})"


def main():
    import argparse
    parser = argparse.ArgumentParser(description="Parse LHVM bytecode")
    parser.add_argument("chl_file", help="Path to challenge.chl")
    parser.add_argument("--call", type=int, help="Find all CALL #N instructions")
    parser.add_argument("--call-context", type=int, default=5,
                        help="Number of preceding instructions to show (default: 5)")
    parser.add_argument("--disasm", help="Disassemble a named script")
    parser.add_argument("--list-scripts", action="store_true", help="List all scripts")
    parser.add_argument("--list-calls", action="store_true", help="List unique CALL targets with counts")
    args = parser.parse_args()

    chl = parse_chl(args.chl_file)
    instructions = chl['instructions']
    scripts = chl['scripts']
    globals_list = chl['globals']

    if args.list_scripts:
        for s in scripts:
            print(f"  [{s['id']:4d}] {s['name']:40s} IP={s['ip']:6d} params={s['param_count']} locals={len(s['locals'])}")
        return

    if args.list_calls:
        from collections import Counter
        call_counts = Counter()
        for ip, instr in enumerate(instructions):
            if instr[0] == 0x05:  # CALL
                call_counts[instr[3]] += 1
        for func_id, count in sorted(call_counts.items()):
            print(f"  CALL #{func_id}: {count} times")
        return

    if args.call is not None:
        target = args.call
        ctx = args.call_context
        print(f"\nSearching for CALL #{target}...\n")
        found = 0
        for ip, instr in enumerate(instructions):
            if instr[0] == 0x05 and instr[3] == target:
                found += 1
                script = find_script_for_ip(scripts, ip)
                sname = script['name'] if script else "???"
                print(f"--- CALL #{target} at IP {ip} in script '{sname}' ---")
                start = max(0, ip - ctx)
                for j in range(start, min(ip + 2, len(instructions))):
                    marker = ">>>" if j == ip else "   "
                    print(f"{marker}{disasm_instruction(j, instructions[j], globals_list)}")
                print()
        print(f"Total: {found} CALL #{target} instructions found")
        return

    if args.disasm:
        target_script = None
        for s in scripts:
            if s['name'].lower() == args.disasm.lower():
                target_script = s
                break
        if not target_script:
            print(f"Script '{args.disasm}' not found")
            return

        # Find end of script (start of next script or end of instructions)
        next_ip = len(instructions)
        for s in scripts:
            if s['ip'] > target_script['ip'] and s['ip'] < next_ip:
                next_ip = s['ip']

        print(f"\nScript '{target_script['name']}' (ID {target_script['id']}, IP {target_script['ip']}-{next_ip-1})")
        print(f"  Params: {target_script['param_count']}, Locals: {target_script['locals']}")
        print()
        for ip in range(target_script['ip'], next_ip):
            print(disasm_instruction(ip, instructions[ip], globals_list))


if __name__ == '__main__':
    main()

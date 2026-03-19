"""Post-build patcher to fix Wine/Proton crashes in Black & White's runblack.exe.

Takes the byte-exact runblack-reassembled.exe and produces a patched copy that
runs under Wine/Proton without the DirectPlay-related crashes.

Strategy (three layers of defense):

  Layer 0: Redirect DirectPlay initialization
    Three calls to the GInterface/HelpText init function at 0x005CCF80 create
    DirectPlay objects. Under Wine, COM classes aren't registered so these produce
    allocated-but-uninitialized objects (worse than null). The first call is
    replaced with a call to cave code that writes a dummy struct pointer into
    all 6 DP globals. The other two calls are NOP'd.

  Layer 1: Safe-load all DirectPlay global pointer reads
    Six globals at 0x00D17C98-0x00D17CAC are read from ~1400 direct load sites.
    Each load is replaced with a call to a code-cave function that returns the
    dummy struct when the pointer is null (belt-and-suspenders with Layer 0).

  Layer 2: Guard secondary crash sites
    - Tribe table: bounds-check corrupted tribe index (2 sites)
    - Vtable delegate: validate vtable pointer range (1 site)
    - TownStats: validate Object::info vtable range before dereference (4 sites)

  Layer 3: Vectored Exception Handler (VEH) safety net
    ~275 sites dereference Object::info (+0x28) without NULL check.
    A VEH catches ACCESS_VIOLATION at low addresses (NULL+offset) within
    the game's .text section, decodes the x86 ModR/M byte to find the
    register containing NULL, fixes it to point to our dummy struct, and
    resumes execution. This is a universal fix that covers all info-deref
    sites without patching each individually.
"""

import argparse
import hashlib
import struct
from pathlib import Path

# --- PE Layout ---
IMAGE_BASE = 0x00400000
EXPECTED_MD5 = "174b1a64e74b2321f3c38ccc8a511e78"
RDATA_VA_START = 0x008A9000
RDATA_VA_END = 0x009C6000
TEXT_FILE_START = 0x00001000
CODE_CAVE_FILE_OFFSET = 0x004A8970
CODE_CAVE_VA = CODE_CAVE_FILE_OFFSET + IMAGE_BASE
CODE_CAVE_MAX = 1680

# Writable dummy struct location in .data section (2432 bytes of zeros available)
DUMMY_FILE_OFFSET = 0x0083C680
DUMMY_VA = DUMMY_FILE_OFFSET + IMAGE_BASE  # 0x00C3C680

# --- Fix 0: DirectPlay init calls to NOP ---
DP_INIT_CALL_VAS = [0x0071935B, 0x0071946B, 0x0071957B]

# --- Fix 1: DirectPlay global pointers ---
DP_GLOBAL_ADDRS = [0x00D17C98, 0x00D17C9C, 0x00D17CA0, 0x00D17CA4, 0x00D17CA8, 0x00D17CAC]
DUMMY_STRUCT_SIZE = 0x200        # 512 bytes, covers max observed offset ~0x1F8

# --- Fix 2: Tribe table bounds check ---
TRIBE_LOOKUP_VAS = [0x00405A8C, 0x007519FC]  # mov eax,[ebp]; mov edx,[eax*4+table]
TRIBE_LOOKUP_SIZE = 10       # 3 + 7 bytes
TRIBE_TABLE_VA = 0x00C22FDC
TRIBE_TABLE_COUNT = 10

# --- Fix 3: Vtable delegate validation ---
VTABLE_THUNK_VA = 0x00404AA0   # mov ecx,[ecx+0x28]; mov eax,[ecx]; jmp [eax+0x2C]
VTABLE_THUNK_SIZE = 7

# --- Fix 4: TownStats info pointer validation ---
# TownStats methods dereference Object::info (+0x28). Under Wine, some objects
# have garbage (non-NULL) info pointers from uninitialized DirectPlay memory.
# Instead of NOPing all 8 functions (which kills population counters and town AI),
# we validate the info pointer's vtable: valid GObjectInfo subclasses have vtables
# in .rdata (0x008A9000-0x009C6000). Garbage pointers won't.
#
# Only 4 functions need patching:
#   0x00739A20 — Town::AddAbodeToTownStats wrapper (calls 0x7498C0)
#   0x00739A40 — Town::RemoveAbodeFromTownStats wrapper (calls 0x749990)
#   0x007492E0 — TownStats secondary Add (Villager*), accesses [villager+0x28]
#   0x007493C0 — TownStats::Remove(Villager*), accesses [villager+0x28]
#
# 4 functions that were previously NOPed do NOT need it:
#   0x00749490 — ChildToAdult: no info deref, uses GetAbode() vtable call
#   0x00749500 — VillagerMoveOutOfAbode: no info deref, vtable call only
#   0x007498C0 — main TownStats::Add(Abode*): only called from wrapper 0x739A20
#   0x00749990 — main TownStats::Remove(Abode*): only called from wrapper 0x739A40
#
# Wrapper functions (19 bytes each, thiscall ret 4):
TOWNSTATS_WRAPPER_ADD_VA = 0x00739A20   # mov eax,[esp+4]; push eax; add ecx,0x610; call 0x7498C0; ret 4
TOWNSTATS_WRAPPER_ADD_SIZE = 19
TOWNSTATS_WRAPPER_REM_VA = 0x00739A40   # mov eax,[esp+4]; push eax; add ecx,0x610; call 0x749990; ret 4
TOWNSTATS_WRAPPER_REM_SIZE = 19
TOWNSTATS_INNER_ADD_VA = 0x007498C0     # target of wrapper Add
TOWNSTATS_INNER_REM_VA = 0x00749990     # target of wrapper Remove
# Secondary Villager stat functions (thiscall ret 4, prologue: sub esp,8; push esi; push edi = 5 bytes):
TOWNSTATS_VILLAGER_ADD_VA = 0x007492E0
TOWNSTATS_VILLAGER_REM_VA = 0x007493C0
TOWNSTATS_VILLAGER_DISPLACED = 5        # bytes displaced by jmp

# --- Fix 16: VEH hotspot trampolines ---
# These 4 functions cause ~180K access violations per session, hammering the VEH.
# Each dereferences Object::info (+0x28) or a vtable return value without checking.
# Replace with trampolines that validate before dereferencing.
#
# Abode::GetPercentAbodeFullWithAdults (0x407050) — 55K hits
#   reads [info+0x174]. Displace 7 bytes. Returns float, bail=0.0.
VEH_ABODE_ADULTS_VA = 0x00407050
VEH_ABODE_ADULTS_DISPLACED = 7  # sub esp,8; push esi; mov esi,[ecx+0x28]
#
# Abode::GetPercentAbodeFullWithChildren (0x407090) — 55K hits
#   reads [info+0x178]. Displace 7 bytes. Returns float, bail=0.0.
VEH_ABODE_CHILDREN_VA = 0x00407090
VEH_ABODE_CHILDREN_DISPLACED = 7  # mov eax,[ecx+0x28]; sub esp,8; push esi
#
# Living::IsReadyForNewAnimation (0x5EC960) — 43K hits
#   vtable call returns NULL, then [eax+0x20] faults. Displace 14 bytes (incl call).
#   Returns int (bool 0/1), bail=0. ret 4 (1 stack arg).
VEH_ANIM_READY_VA = 0x005EC960
VEH_ANIM_READY_DISPLACED = 14  # push esi; mov esi,ecx; mov ecx,[esi+0x40]; mov eax,[ecx]; call [eax+0x184]
#
# MultiMapFixed::GetInfluence (0x52ECA0) — 28K hits
#   reads [info+0x11C] as float. Displace 10 bytes. Returns float, bail=0.0. ret.
VEH_INFLUENCE_VA = 0x0052ECA0
VEH_INFLUENCE_DISPLACED = 10  # push ecx; push esi; mov esi,ecx; mov eax,[esi]; push edi; mov edi,[esi+0x28]

# --- Fix 17: Remaining VEH hotspot trampolines (second pass) ---
# After Fix 16 eliminated ~180K AVs from 4 functions, ~512 AVs remain across
# 9 functions/sites. Same Object::info NULL-deref pattern.
#
# Full function replacements (leaf, no frame):
VEH2_GET_ABODE_TYPE_VA = 0x004061F0    # Abode::GetAbodeType — 312 hits
VEH2_GET_ABODE_TYPE_SIZE = 10           # mov eax,[ecx+0x28]; mov eax,[eax+0x120]; ret
VEH2_OBJ_IS_TYPE_8_VA = 0x006380C0     # unnamed: return (info->type == 8) — 19 hits
VEH2_OBJ_IS_TYPE_8_SIZE = 17
VEH2_OBJ_IS_TYPE_0_VA = 0x006380E0     # unnamed: return (info->type == 0) — 19 hits
VEH2_OBJ_IS_TYPE_0_SIZE = 16
VEH2_OBJ_IS_TYPE_6_VA = 0x006380F0     # unnamed: return (info->type == 6) — 4 hits
VEH2_OBJ_IS_TYPE_6_SIZE = 17
VEH2_GET_ROOM_ADULTS_VA = 0x00404660   # Abode::GetRoomLeftForAdults — 19 hits
VEH2_GET_ROOM_ADULTS_SIZE = 20
#
# Displaced-prologue patches:
VEH2_INIT_FIXED_MAP_VA = 0x0063A640    # Object::InitialiseIsFixedForMapList — 38 hits
VEH2_INIT_FIXED_MAP_DISPLACED = 6      # push esi; mov esi,ecx; mov eax,[esi+0x28]
#
# Mid-function crash site patches:
VEH2_PROCESS_CRASH_VA = 0x004044D8     # inside Abode::Process — 38 hits
VEH2_PROCESS_DISPLACED = 5             # mov ecx,[esi+0x28]; or al,0x40
VEH2_PROCESS_RESUME_VA = 0x004044DD    # valid path: mov [esi+0x7c],al continues
VEH2_PROCESS_SKIP_VA = 0x004044E6      # bail path: skip mov edx,[ecx+0x1b0]
VEH2_FINDTYPE_SITE1_VA = 0x0060161A    # MapCell::FindTypeOnMap site 1 — 19 hits
VEH2_FINDTYPE_SITE1_DISPLACED = 6      # mov ecx,[edi+0x28]; mov eax,[ecx+0x10]
VEH2_FINDTYPE_SITE1_RESUME_VA = 0x00601620  # push eax continues
VEH2_FINDTYPE_SITE2_VA = 0x00601668    # MapCell::FindTypeOnMap site 2 — 18 hits
VEH2_FINDTYPE_SITE2_DISPLACED = 6      # mov ecx,[eax+0x28]; cmp [ecx+0x10],edi
VEH2_FINDTYPE_SITE2_RESUME_VA = 0x0060166E  # je continues
VEH2_FINDTYPE_SITE2_TRAVERSE_VA = 0x00601670  # bail: skip compare, go to traversal

# --- Fix 5: Skip info-index branches that use [info+0x1F8] as array index ---
# At 0x004041C7: jnz +0x47 → jmp +0x47 (skip Object::info array index path)
# The branch accesses info+0x1F8 and uses it as [esi+edx*4+0xA8] — overflows
# when info is our dummy struct. Under Wine this is dead stats code.
INFO_INDEX_SKIP_VAS = [0x004041C7]  # change 75 XX → EB XX

# --- Fix 6: NOP functions with garbage vtable dereferences ---
# 0x00404B10: thiscall function that calls [vtable+0x2C]. Crashes when ECX
# points to an object with a corrupted vtable. Returns boolean. NOP to return 0.
# Uses ret 0x10 (4 stack args).
VTABLE_DEREF_NOP_VAS = [(0x00404B10, 0x10)]  # (va, stack_cleanup_bytes)

# --- Fix 10: Intro cleanup + state bit clear via trampoline ---
# After the interactive intro, the game calls 0x5F89F0(2) to release intro
# resources (textures, sprites, materials) and reset render state. Then Loop 2
# at 0x5FA0B5 renders black frames until state bits 0+1 at 0xE85304 clear.
# Under Wine, the cinematic callback that clears these bits never completes,
# so Loop 2 hangs forever.
# Fix: redirect the cleanup call through a code cave trampoline that calls
# 0x5F89F0(2) (preserving resource cleanup) AND clears the state bits.
# Loop 2's test immediately sees bits clear and exits naturally.
LOOP2_TRANSITION_VA = 0x005FA0AB  # push 2; call 0x5F89F0; add esp,4 (10 bytes)

# --- Fix 15: Stream write NULL guard ---
# Function at 0x5167D0 is a stream/buffer write (thiscall, ret 0x0C).
# During texture loading, some objects have NULL stream pointers.
# The VEH recovery sets the NULL register to dummy_va, causing the function
# to write into read-only .text → cascading corruption → hard hang.
# Guard: check stream param, return 0 if NULL.
STREAM_WRITE_VA = 0x005167D0

# --- Fix 7: Vectored Exception Handler for Object::info NULL crashes ---
# ~275 sites dereference Object::info (+0x28) without NULL check.
# Instead of patching each one, install a VEH that catches ACCESS_VIOLATION
# at low addresses (NULL+offset) and fixes the faulting register to point
# to our dummy struct, then resumes execution.
GETPROCADDRESS_IAT_VA = 0x008A9170
GETMODULEHANDLE_IAT_VA = 0x008A91CC
KERNEL32_STRING_VA = 0x009C055E  # "KERNEL32.dll\0" in .rdata
TEXT_VA_START = 0x00401000
TEXT_VA_END = 0x008A9000
# CONTEXT offsets for x86 registers (by r/m field 0-7):
# eax=0xB0, ecx=0xAC, edx=0xA8, ebx=0xA4, esp=0xC4, ebp=0xB4, esi=0xA0, edi=0x9C
CTX_REG_OFFSETS = bytes([0xB0, 0xAC, 0xA8, 0xA4, 0xC4, 0xB4, 0xA0, 0x9C])
AVEH_NAME = b'AddVectoredExceptionHandler\x00'
ORIGINAL_DP_INIT_VA = 0x005CCF80  # Original GInterface/HelpText init function


def va_to_offset(va):
    return va - IMAGE_BASE


def encode_call(from_va, to_va):
    """Encode a 5-byte CALL rel32 (E8 rel32)."""
    return b'\xe8' + struct.pack('<i', to_va - (from_va + 5))


def encode_jmp(from_va, to_va):
    """Encode a 5-byte JMP rel32 (E9 rel32)."""
    return b'\xe9' + struct.pack('<i', to_va - (from_va + 5))


def build_cave(dummy_va):
    """Build all code cave content including VEH handler.

    Returns (cave_bytes, dummy_struct_bytes, init_globals_va, safe_loaders,
             safe_tribe_va, safe_vtable_va).
    """
    cave = bytearray()
    dummy_bytes = struct.pack('<I', dummy_va)

    # --- Dummy struct: self-referencing (in cave, read-only in .text) ---
    # Every dword = dummy_va. Pointer chains loop back safely.
    # Read-only is intentional: writes fault → game's SEH recovers gracefully.
    dummy_struct = dummy_bytes * (DUMMY_STRUCT_SIZE // 4)
    cave += dummy_struct

    # --- VEH handler (105 bytes) ---
    # Catches ACCESS_VIOLATION at low fault addresses within .text, decodes
    # the x86 ModR/M byte to find the NULL base register, sets it to
    # dummy_va, and resumes execution.
    veh_handler_va = CODE_CAVE_VA + len(cave)
    veh_table_va = veh_handler_va + 97
    veh = bytearray()
    veh += b'\x8b\x44\x24\x04'                                 # +0:  mov eax, [esp+4]       ; EXCEPTION_POINTERS*
    veh += b'\x8b\x08'                                          # +4:  mov ecx, [eax]         ; EXCEPTION_RECORD*
    veh += b'\x8b\x50\x04'                                      # +6:  mov edx, [eax+4]       ; CONTEXT*
    veh += b'\x81\x39' + struct.pack('<I', 0xC0000005)          # +9:  cmp dword [ecx], C0000005h
    veh += b'\x75\x4b'                                           # +15: jne .pass (->92)
    veh += b'\x81\x79\x18' + struct.pack('<I', 0x1000)          # +17: cmp dword [ecx+18h], 1000h  ; fault addr < 4K?
    veh += b'\x73\x42'                                           # +24: jae .pass (->92)
    veh += b'\x8b\x8a' + struct.pack('<I', 0xB8)                # +26: mov ecx, [edx+B8h]    ; Eip
    veh += b'\x81\xf9' + struct.pack('<I', TEXT_VA_START)        # +32: cmp ecx, TEXT_VA_START
    veh += b'\x72\x34'                                           # +38: jb .pass (->92)
    veh += b'\x81\xf9' + struct.pack('<I', TEXT_VA_END)          # +40: cmp ecx, TEXT_VA_END
    veh += b'\x73\x2c'                                           # +46: jae .pass (->92)
    veh += b'\x0f\xb6\x01'                                      # +48: movzx eax, byte [ecx]  ; first opcode byte
    veh += b'\x3c\x0f'                                           # +51: cmp al, 0Fh            ; two-byte opcode?
    veh += b'\x74\x06'                                           # +53: je .twobyte (->61)
    veh += b'\x0f\xb6\x41\x01'                                  # +55: movzx eax, byte [ecx+1] ; ModR/M at +1
    veh += b'\xeb\x04'                                           # +59: jmp .got_modrm (->65)
    veh += b'\x0f\xb6\x41\x02'                                  # +61: movzx eax, byte [ecx+2] ; ModR/M at +2
    veh += b'\x83\xe0\x07'                                       # +65: and eax, 7             ; r/m field
    veh += b'\x3c\x04'                                           # +68: cmp al, 4              ; skip SIB (ESP)
    veh += b'\x74\x14'                                           # +70: je .pass (->92)
    veh += b'\x0f\xb6\x80' + struct.pack('<I', veh_table_va)    # +72: movzx eax, byte [eax+table]
    veh += b'\xc7\x04\x02' + struct.pack('<I', dummy_va)        # +79: mov [edx+eax], dummy_va
    veh += b'\x83\xc8\xff'                                       # +86: or eax, -1  ; CONTINUE_EXECUTION
    veh += b'\xc2\x04\x00'                                       # +89: ret 4
    veh += b'\x31\xc0'                                           # +92: xor eax, eax ; CONTINUE_SEARCH
    veh += b'\xc2\x04\x00'                                       # +94: ret 4
    veh += CTX_REG_OFFSETS                                        # +97: register offset table
    assert len(veh) == 105, f"VEH handler size {len(veh)} != 105"
    cave += veh

    # --- AVEH function name string ---
    aveh_string_va = CODE_CAVE_VA + len(cave)
    cave += AVEH_NAME

    # --- Init function: install VEH then chain to original text init ---
    # The original function at 0x005CCF80 is a text string copy helper (wcslen +
    # operator new + wcscpy), NOT DirectPlay. We must let it run to populate the
    # localization tables. We just prepend VEH installation before it.
    init_globals_va = CODE_CAVE_VA + len(cave)
    cave += b'\x51'                                               # push ecx  (save this ptr)
    # Resolve and install VEH handler at runtime
    cave += b'\x68' + struct.pack('<I', KERNEL32_STRING_VA)      # push "KERNEL32.dll"
    cave += b'\xff\x15' + struct.pack('<I', GETMODULEHANDLE_IAT_VA)  # call [GetModuleHandleA]
    cave += b'\x68' + struct.pack('<I', aveh_string_va)          # push "AddVectoredExceptionHandler"
    cave += b'\x50'                                               # push eax  ; kernel32 handle
    cave += b'\xff\x15' + struct.pack('<I', GETPROCADDRESS_IAT_VA)   # call [GetProcAddress]
    cave += b'\x68' + struct.pack('<I', veh_handler_va)          # push handler
    cave += b'\x6a\x01'                                           # push 1    ; First=TRUE
    cave += b'\xff\xd0'                                           # call eax  ; AddVectoredExceptionHandler
    cave += b'\x59'                                               # pop ecx   (restore this ptr)
    jmp_va = CODE_CAVE_VA + len(cave)
    cave += encode_jmp(jmp_va, ORIGINAL_DP_INIT_VA)              # jmp 0x005CCF80 (chains to original)

    # --- Safe-load functions for each DP global (eax/edx/ecx variants) ---
    safe_loaders = {}
    for dp_addr in DP_GLOBAL_ADDRS:
        addr_bytes = struct.pack('<I', dp_addr)
        vas = []

        # safe_load_eax: mov eax,[addr]; test eax,eax; jne +5; mov eax,dummy; ret
        vas.append(CODE_CAVE_VA + len(cave))
        cave += b'\xa1' + addr_bytes
        cave += b'\x85\xc0\x75\x05'
        cave += b'\xb8' + dummy_bytes
        cave += b'\xc3'

        # safe_load_edx: mov edx,[addr]; test edx,edx; jne +5; mov edx,dummy; ret
        vas.append(CODE_CAVE_VA + len(cave))
        cave += b'\x8b\x15' + addr_bytes
        cave += b'\x85\xd2\x75\x05'
        cave += b'\xba' + dummy_bytes
        cave += b'\xc3'

        # safe_load_ecx: mov ecx,[addr]; test ecx,ecx; jne +5; mov ecx,dummy; ret
        vas.append(CODE_CAVE_VA + len(cave))
        cave += b'\x8b\x0d' + addr_bytes
        cave += b'\x85\xc9\x75\x05'
        cave += b'\xb9' + dummy_bytes
        cave += b'\xc3'

        safe_loaders[dp_addr] = tuple(vas)

    # --- Tribe table bounds check ---
    safe_tribe_va = CODE_CAVE_VA + len(cave)
    cave += b'\x8b\x45\x00'                                     # mov eax, [ebp]
    cave += b'\x83\xf8' + bytes([TRIBE_TABLE_COUNT])             # cmp eax, 10
    cave += b'\x72\x02'                                          # jb .ok
    cave += b'\x31\xc0'                                          # xor eax, eax
    cave += b'\x8b\x14\x85' + struct.pack('<I', TRIBE_TABLE_VA) # mov edx, [eax*4+table]
    cave += b'\xc3'                                              # ret

    # --- Vtable delegate with validation ---
    safe_vtable_va = CODE_CAVE_VA + len(cave)
    cave += b'\x8b\x49\x28'                                     # mov ecx, [ecx+0x28]
    cave += b'\x85\xc9'                                          # test ecx, ecx
    cave += b'\x74\x13'                                          # jz .bail
    cave += b'\x8b\x01'                                          # mov eax, [ecx]
    cave += b'\x3d' + struct.pack('<I', RDATA_VA_START)          # cmp eax, RDATA_START
    cave += b'\x72\x0a'                                          # jb .bail
    cave += b'\x3d' + struct.pack('<I', RDATA_VA_END)            # cmp eax, RDATA_END
    cave += b'\x73\x03'                                          # jae .bail
    cave += b'\xff\x60\x2c'                                      # jmp [eax+0x2C]
    cave += b'\x31\xc0'                                          # xor eax, eax
    cave += b'\xc3'                                              # ret

    # --- Intro cleanup trampoline for Fix 10 ---
    # Calls the intro cleanup function 0x5F89F0(2) then clears state bits
    # so Loop 2 exits naturally. This preserves intro resource cleanup
    # (texture/sprite release, render state reset) that was accidentally
    # skipped by the old Fix 10 which replaced the cleanup call entirely.
    intro_cleanup_trampoline_va = CODE_CAVE_VA + len(cave)
    INTRO_RENDER_FUNC_VA = 0x005F89F0
    tramp = bytearray()
    tramp += b'\x6a\x02'                                                # push 2
    tramp += encode_call(intro_cleanup_trampoline_va + len(tramp),
                         INTRO_RENDER_FUNC_VA)                          # call 0x5F89F0
    tramp += b'\x83\xc4\x04'                                            # add esp, 4
    tramp += b'\x80\x25' + struct.pack('<I', 0x00E85304) + b'\xfc'     # and byte ptr [0xE85304], 0xFC
    tramp += b'\xc3'                                                     # ret
    cave += tramp

    # --- Fix 15: Stream write NULL guard ---
    # Function at 0x5167D0 crashes when stream param ([esp+4]) is NULL.
    # Guard: check stream, return 0 if NULL, else run displaced instructions and jump back.
    stream_null_guard_va = CODE_CAVE_VA + len(cave)
    guard = bytearray()
    guard += b'\x8b\x44\x24\x04'          # mov eax, [esp+4]  ; stream param
    guard += b'\x85\xc0'                    # test eax, eax
    guard += b'\x75\x05'                    # jne .ok (+5 bytes)
    guard += b'\x33\xc0'                    # xor eax, eax      ; return 0
    guard += b'\xc2\x0c\x00'               # ret 0x000C
    # .ok: execute displaced instructions then jump back
    guard += b'\x8b\x44\x24\x0c'           # mov eax, [esp+0xC] (original)
    guard += b'\x53'                         # push ebx (original)
    jmp_back_va = stream_null_guard_va + len(guard)
    guard += encode_jmp(jmp_back_va, 0x005167D5)  # jmp past displaced bytes
    cave += guard

    # --- Fix 4: TownStats info pointer validation trampolines ---
    # Validate Object::info vtable before allowing TownStats functions to proceed.
    # Valid GObjectInfo subclasses have vtable pointers in .rdata.
    rdata_start = struct.pack('<I', RDATA_VA_START)
    rdata_end = struct.pack('<I', RDATA_VA_END)

    # Trampoline A: Abode Add wrapper (replaces entire 0x739A20 body)
    # ecx = Town* (this), [esp+4] = Abode*
    # Layout: validation (29 bytes) | push+add+call (12 bytes) | ret 4 (3 bytes)
    # Bail target = ret 4 at +41
    townstats_wrapper_add_guard_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\x44\x24\x04'                    # +0:  mov eax, [esp+4]     ; Abode*
    t += b'\x8b\x50\x28'                         # +4:  mov edx, [eax+0x28]  ; info ptr
    t += b'\x85\xd2'                              # +7:  test edx, edx
    t += b'\x74\x1e'                              # +9:  jz .bail (11+30=41)
    t += b'\x8b\x12'                              # +11: mov edx, [edx]       ; vtable
    t += b'\x81\xfa' + rdata_start                # +13: cmp edx, RDATA_START
    t += b'\x72\x14'                              # +19: jb .bail (21+20=41)
    t += b'\x81\xfa' + rdata_end                  # +21: cmp edx, RDATA_END
    t += b'\x73\x0c'                              # +27: jae .bail (29+12=41)
    # Valid — execute original wrapper body
    t += b'\x50'                                   # +29: push eax             ; Abode*
    t += b'\x81\xc1\x10\x06\x00\x00'             # +30: add ecx, 0x610       ; &town->stats
    tramp_call_va = townstats_wrapper_add_guard_va + len(t)
    t += encode_call(tramp_call_va, TOWNSTATS_INNER_ADD_VA)  # +36: call 0x7498C0
    # .bail:
    t += b'\xc2\x04\x00'                          # +41: ret 4
    assert len(t) == 44
    cave += t

    # Trampoline B: Abode Remove wrapper (replaces entire 0x739A40 body)
    # Same layout as trampoline A, calls 0x749990 instead
    townstats_wrapper_rem_guard_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\x44\x24\x04'                    # +0:  mov eax, [esp+4]     ; Abode*
    t += b'\x8b\x50\x28'                         # +4:  mov edx, [eax+0x28]  ; info ptr
    t += b'\x85\xd2'                              # +7:  test edx, edx
    t += b'\x74\x1e'                              # +9:  jz .bail (11+30=41)
    t += b'\x8b\x12'                              # +11: mov edx, [edx]       ; vtable
    t += b'\x81\xfa' + rdata_start                # +13: cmp edx, RDATA_START
    t += b'\x72\x14'                              # +19: jb .bail (21+20=41)
    t += b'\x81\xfa' + rdata_end                  # +21: cmp edx, RDATA_END
    t += b'\x73\x0c'                              # +27: jae .bail (29+12=41)
    # Valid — execute original wrapper body
    t += b'\x50'                                   # +29: push eax             ; Abode*
    t += b'\x81\xc1\x10\x06\x00\x00'             # +30: add ecx, 0x610       ; &town->stats
    tramp_call_va = townstats_wrapper_rem_guard_va + len(t)
    t += encode_call(tramp_call_va, TOWNSTATS_INNER_REM_VA)  # +36: call 0x749990
    # .bail:
    t += b'\xc2\x04\x00'                          # +41: ret 4
    assert len(t) == 44
    cave += t

    # Trampoline C: Villager secondary Add (0x7492E0) — validate then displaced prologue
    # ecx = TownStats* (this), [esp+4] = Villager*
    # Layout: validation (29 bytes) | bail ret 4 (3 bytes) | displaced prologue + jmp (10 bytes)
    # Bail target = ret 4 at +29, .ok = +32
    townstats_villager_add_guard_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\x44\x24\x04'                    # +0:  mov eax, [esp+4]     ; Villager*
    t += b'\x8b\x50\x28'                         # +4:  mov edx, [eax+0x28]  ; info ptr
    t += b'\x85\xd2'                              # +7:  test edx, edx
    t += b'\x74\x12'                              # +9:  jz .bail (11+18=29)
    t += b'\x8b\x12'                              # +11: mov edx, [edx]       ; vtable
    t += b'\x81\xfa' + rdata_start                # +13: cmp edx, RDATA_START
    t += b'\x72\x08'                              # +19: jb .bail (21+8=29)
    t += b'\x81\xfa' + rdata_end                  # +21: cmp edx, RDATA_END
    t += b'\x72\x03'                              # +27: jb .ok (29+3=32)
    # .bail:
    t += b'\xc2\x04\x00'                          # +29: ret 4
    # .ok: displaced prologue (sub esp,8; push esi; push edi) then jmp back
    t += b'\x83\xec\x08'                          # +32: sub esp, 8
    t += b'\x56'                                   # +35: push esi
    t += b'\x57'                                   # +36: push edi
    jmp_va = townstats_villager_add_guard_va + len(t)
    t += encode_jmp(jmp_va, TOWNSTATS_VILLAGER_ADD_VA + TOWNSTATS_VILLAGER_DISPLACED)  # +37: jmp 0x7492E5
    assert len(t) == 42
    cave += t

    # Trampoline D: Villager secondary Remove (0x7493C0) — same pattern
    townstats_villager_rem_guard_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\x44\x24\x04'                    # +0:  mov eax, [esp+4]     ; Villager*
    t += b'\x8b\x50\x28'                         # +4:  mov edx, [eax+0x28]  ; info ptr
    t += b'\x85\xd2'                              # +7:  test edx, edx
    t += b'\x74\x12'                              # +9:  jz .bail (11+18=29)
    t += b'\x8b\x12'                              # +11: mov edx, [edx]       ; vtable
    t += b'\x81\xfa' + rdata_start                # +13: cmp edx, RDATA_START
    t += b'\x72\x08'                              # +19: jb .bail (21+8=29)
    t += b'\x81\xfa' + rdata_end                  # +21: cmp edx, RDATA_END
    t += b'\x72\x03'                              # +27: jb .ok (29+3=32)
    # .bail:
    t += b'\xc2\x04\x00'                          # +29: ret 4
    # .ok: displaced prologue then jmp back
    t += b'\x83\xec\x08'                          # +32: sub esp, 8
    t += b'\x56'                                   # +35: push esi
    t += b'\x57'                                   # +36: push edi
    jmp_va = townstats_villager_rem_guard_va + len(t)
    t += encode_jmp(jmp_va, TOWNSTATS_VILLAGER_REM_VA + TOWNSTATS_VILLAGER_DISPLACED)  # +37: jmp 0x7493C5
    assert len(t) == 42
    cave += t

    # --- Fix 16: VEH hotspot trampolines ---
    rdata_start = struct.pack('<I', RDATA_VA_START)
    rdata_end = struct.pack('<I', RDATA_VA_END)

    # Trampoline 16a: Abode::GetPercentAbodeFullWithAdults (0x407050)
    # Displaced 7 bytes: sub esp,8 (3); push esi (1); mov esi,[ecx+0x28] (3)
    # After: esi = info. Validate vtable. Bail = return 0.0 (fldz).
    # Normal return: pop esi; add esp,8; ret (thiscall, no stack args).
    # Bail at +40: pop esi; fldz; add esp,8; ret
    veh_abode_adults_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x83\xec\x08'                          # +0:  sub esp, 8         (displaced)
    t += b'\x56'                                    # +3:  push esi           (displaced)
    t += b'\x8b\x71\x28'                          # +4:  mov esi, [ecx+0x28](displaced)
    # validate esi (info)
    t += b'\x85\xf6'                               # +7:  test esi, esi
    t += b'\x74\x1f'                               # +9:  jz .bail (11+31=42)
    t += b'\x8b\x16'                               # +11: mov edx, [esi]     ; vtable
    t += b'\x81\xfa' + rdata_start                 # +13: cmp edx, RDATA_START
    t += b'\x72\x15'                               # +19: jb .bail (21+21=42)
    t += b'\x81\xfa' + rdata_end                   # +21: cmp edx, RDATA_END
    t += b'\x73\x0d'                               # +27: jae .bail (29+13=42)
    # valid — jump back to original function after displaced bytes
    jmp_va = veh_abode_adults_va + len(t)           # +29
    t += encode_jmp(jmp_va, VEH_ABODE_ADULTS_VA + VEH_ABODE_ADULTS_DISPLACED)  # jmp 0x407057
    # .bail: return 0.0
    assert len(t) == 34                             # jmp is at +29, 5 bytes = 34
    # Wait, let me recalculate. +29 has 5-byte jmp = 34. But bail offset was +42. Wrong.
    # Let me recalculate bail offsets after seeing where we are.
    # Actually, I should calculate bail = len after jmp = 34
    t += b'\x5e'                                    # +34: pop esi
    t += b'\xd9\xee'                               # +35: fldz (push 0.0)
    t += b'\x83\xc4\x08'                          # +37: add esp, 8
    t += b'\xc3'                                    # +40: ret
    assert len(t) == 41
    cave += t

    # Fix bail offsets: bail is at +34
    # jz at +9: next_ip=11, target=34, offset=23=0x17
    # jb at +19: next_ip=21, target=34, offset=13=0x0D
    # jae at +27: next_ip=29, target=34, offset=5=0x05
    # Overwrite the placeholder offsets
    cave_start = len(cave) - len(t)
    cave[cave_start + 10] = 0x17  # jz offset
    cave[cave_start + 20] = 0x0D  # jb offset
    cave[cave_start + 28] = 0x05  # jae offset

    # Trampoline 16b: Abode::GetPercentAbodeFullWithChildren (0x407090)
    # Displaced 7 bytes: mov eax,[ecx+0x28] (3); sub esp,8 (3); push esi (1)
    # After: eax = info. Validate vtable. Bail = return 0.0.
    veh_abode_children_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\x41\x28'                          # +0:  mov eax, [ecx+0x28](displaced)
    t += b'\x83\xec\x08'                          # +3:  sub esp, 8         (displaced)
    t += b'\x56'                                    # +6:  push esi           (displaced)
    # validate eax (info)
    t += b'\x85\xc0'                               # +7:  test eax, eax
    t += b'\x74\xff'                               # +9:  jz .bail (placeholder)
    t += b'\x8b\x10'                               # +11: mov edx, [eax]     ; vtable
    t += b'\x81\xfa' + rdata_start                 # +13: cmp edx, RDATA_START
    t += b'\x72\xff'                               # +19: jb .bail (placeholder)
    t += b'\x81\xfa' + rdata_end                   # +21: cmp edx, RDATA_END
    t += b'\x73\xff'                               # +27: jae .bail (placeholder)
    jmp_va = veh_abode_children_va + len(t)         # +29
    t += encode_jmp(jmp_va, VEH_ABODE_CHILDREN_VA + VEH_ABODE_CHILDREN_DISPLACED)  # jmp 0x407097
    bail_off = len(t)                               # +34
    t += b'\x5e'                                    # pop esi
    t += b'\xd9\xee'                               # fldz
    t += b'\x83\xc4\x08'                          # add esp, 8
    t += b'\xc3'                                    # ret
    assert len(t) == 41
    # Fix bail offsets
    t[10] = bail_off - 11   # jz: 34-11=23=0x17
    t[20] = bail_off - 21   # jb: 34-21=13=0x0D
    t[28] = bail_off - 29   # jae: 34-29=5=0x05
    cave += t

    # Trampoline 16c: Living::IsReadyForNewAnimation (0x5EC960)
    # Displaced 14 bytes: push esi(1); mov esi,ecx(2); mov ecx,[esi+0x40](3);
    #   mov eax,[ecx](2); call [eax+0x184](6) — all position-independent.
    # After call: eax = return value. Check for NULL/low. Bail = return 0. ret 4.
    veh_anim_ready_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x56'                                    # +0:  push esi           (displaced)
    t += b'\x8b\xf1'                               # +1:  mov esi, ecx       (displaced)
    t += b'\x8b\x4e\x40'                          # +3:  mov ecx, [esi+0x40](displaced)
    t += b'\x8b\x01'                               # +6:  mov eax, [ecx]     (displaced)
    t += b'\xff\x90\x84\x01\x00\x00'             # +8:  call [eax+0x184]   (displaced)
    # check return value — fault happens when eax is near-NULL
    t += b'\x3d\x00\x10\x00\x00'                  # +14: cmp eax, 0x1000
    t += b'\x72\xff'                               # +19: jb .bail (placeholder)
    jmp_va = veh_anim_ready_va + len(t)             # +21
    t += encode_jmp(jmp_va, VEH_ANIM_READY_VA + VEH_ANIM_READY_DISPLACED)  # jmp 0x5EC96E
    bail_off = len(t)                               # +26
    t += b'\x31\xc0'                               # xor eax, eax (return 0)
    t += b'\x5e'                                    # pop esi
    t += b'\xc2\x04\x00'                          # ret 4
    assert len(t) == 32
    t[20] = bail_off - 21   # jb: 26-21=5=0x05
    cave += t

    # Trampoline 16d: MultiMapFixed::GetInfluence (0x52ECA0)
    # Displaced 10 bytes: push ecx(1); push esi(1); mov esi,ecx(2);
    #   mov eax,[esi](2); push edi(1); mov edi,[esi+0x28](3)
    # After: edi = info. Validate vtable. Bail = return 0.0.
    # Normal epilogue: pop edi; pop esi; pop ecx; ret (thiscall, no stack args).
    veh_influence_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x51'                                    # +0:  push ecx           (displaced)
    t += b'\x56'                                    # +1:  push esi           (displaced)
    t += b'\x8b\xf1'                               # +2:  mov esi, ecx       (displaced)
    t += b'\x8b\x06'                               # +4:  mov eax, [esi]     (displaced)
    t += b'\x57'                                    # +6:  push edi           (displaced)
    t += b'\x8b\x7e\x28'                          # +7:  mov edi, [esi+0x28](displaced)
    # validate edi (info)
    t += b'\x85\xff'                               # +10: test edi, edi
    t += b'\x74\xff'                               # +12: jz .bail (placeholder)
    t += b'\x8b\x17'                               # +14: mov edx, [edi]     ; vtable
    t += b'\x81\xfa' + rdata_start                 # +16: cmp edx, RDATA_START
    t += b'\x72\xff'                               # +22: jb .bail (placeholder)
    t += b'\x81\xfa' + rdata_end                   # +24: cmp edx, RDATA_END
    t += b'\x73\xff'                               # +30: jae .bail (placeholder)
    jmp_va = veh_influence_va + len(t)              # +32
    t += encode_jmp(jmp_va, VEH_INFLUENCE_VA + VEH_INFLUENCE_DISPLACED)  # jmp 0x52ECAA
    bail_off = len(t)                               # +37
    t += b'\x5f'                                    # pop edi
    t += b'\x5e'                                    # pop esi
    t += b'\xd9\xee'                               # fldz (return 0.0 in ST(0))
    t += b'\x59'                                    # pop ecx
    t += b'\xc3'                                    # ret
    assert len(t) == 43
    t[13] = bail_off - 14   # jz: 37-14=23=0x17
    t[23] = bail_off - 24   # jb: 37-24=13=0x0D
    t[31] = bail_off - 32   # jae: 37-32=5=0x05
    cave += t

    # --- Fix 17: Shared info validation helper (31 bytes) ---
    # Input: eax = object pointer (has ->info at +0x28)
    # Output: eax = info (non-zero) if valid, ZF=0
    #         eax = 0 if invalid, ZF=1
    # Clobbers: edx
    validate_info_va = CODE_CAVE_VA + len(cave)
    v = bytearray()
    v += b'\x8b\x40\x28'                          # +0:  mov eax, [eax+0x28]  ; info
    v += b'\x85\xc0'                               # +3:  test eax, eax
    v += b'\x74\x15'                               # +5:  jz .bad (→ +28)
    v += b'\x8b\x10'                               # +7:  mov edx, [eax]       ; vtable
    v += b'\x81\xfa' + rdata_start                 # +9:  cmp edx, RDATA_START
    v += b'\x72\x0b'                               # +15: jb .bad (→ +28)
    v += b'\x81\xfa' + rdata_end                   # +17: cmp edx, RDATA_END
    v += b'\x73\x03'                               # +23: jae .bad (→ +28)
    v += b'\x85\xc0'                               # +25: test eax, eax  (ZF=0)
    v += b'\xc3'                                    # +27: ret
    v += b'\x31\xc0'                               # +28: xor eax, eax  (.bad, ZF=1)
    v += b'\xc3'                                    # +30: ret
    assert len(v) == 31
    cave += v

    # --- Fix 17a: Abode::GetAbodeType (0x4061F0) — 312 hits ---
    # Replaces entire 10-byte function. On invalid info, uses dummy_va so
    # the function reads from the self-referencing dummy struct — same
    # behavior as the VEH path. This avoids changing code paths during loading.
    veh2_get_abode_type_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\xc1'                               # +0:  mov eax, ecx
    t += encode_call(veh2_get_abode_type_va + len(t),
                     validate_info_va)              # +2:  call validate_info
    t += b'\x75\x05'                               # +7:  jnz .valid (→ +14)
    t += b'\xb8' + dummy_bytes                      # +9:  mov eax, dummy_va
    t += b'\x8b\x80\x20\x01\x00\x00'             # +14: mov eax, [eax+0x120]
    t += b'\xc3'                                    # +20: ret
    assert len(t) == 21
    cave += t

    # --- Fix 17b-1: Object type==8 check (0x6380C0) — 19 hits ---
    veh2_obj_is_type_8_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\xc1'                               # +0:  mov eax, ecx
    t += encode_call(veh2_obj_is_type_8_va + len(t),
                     validate_info_va)              # +2:  call validate_info
    t += b'\x75\x05'                               # +7:  jnz .valid (→ +14)
    t += b'\xb8' + dummy_bytes                      # +9:  mov eax, dummy_va
    t += b'\x8b\x50\x10'                           # +14: mov edx, [eax+0x10]
    t += b'\x33\xc9'                               # +17: xor ecx, ecx
    t += b'\x83\xfa\x08'                           # +19: cmp edx, 8
    t += b'\x0f\x94\xc1'                           # +22: sete cl
    t += b'\x8b\xc1'                               # +25: mov eax, ecx
    t += b'\xc3'                                    # +27: ret
    assert len(t) == 28
    cave += t

    # --- Fix 17b-2: Object type==0 check (0x6380E0) — 19 hits ---
    veh2_obj_is_type_0_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\xc1'                               # +0:  mov eax, ecx
    t += encode_call(veh2_obj_is_type_0_va + len(t),
                     validate_info_va)              # +2:  call validate_info
    t += b'\x75\x05'                               # +7:  jnz .valid (→ +14)
    t += b'\xb8' + dummy_bytes                      # +9:  mov eax, dummy_va
    t += b'\x8b\x50\x10'                           # +14: mov edx, [eax+0x10]
    t += b'\x33\xc9'                               # +17: xor ecx, ecx
    t += b'\x85\xd2'                               # +19: test edx, edx
    t += b'\x0f\x94\xc1'                           # +21: sete cl
    t += b'\x8b\xc1'                               # +24: mov eax, ecx
    t += b'\xc3'                                    # +26: ret
    assert len(t) == 27
    cave += t

    # --- Fix 17b-3: Object type==6 check (0x6380F0) — 4 hits ---
    veh2_obj_is_type_6_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\xc1'                               # +0:  mov eax, ecx
    t += encode_call(veh2_obj_is_type_6_va + len(t),
                     validate_info_va)              # +2:  call validate_info
    t += b'\x75\x05'                               # +7:  jnz .valid (→ +14)
    t += b'\xb8' + dummy_bytes                      # +9:  mov eax, dummy_va
    t += b'\x8b\x50\x10'                           # +14: mov edx, [eax+0x10]
    t += b'\x33\xc9'                               # +17: xor ecx, ecx
    t += b'\x83\xfa\x06'                           # +19: cmp edx, 6
    t += b'\x0f\x94\xc1'                           # +22: sete cl
    t += b'\x8b\xc1'                               # +25: mov eax, ecx
    t += b'\xc3'                                    # +27: ret
    assert len(t) == 28
    cave += t

    # --- Fix 17c: Abode::GetRoomLeftForAdults (0x404660) — 19 hits ---
    # Replaces entire 20-byte function. Returns int (max - current) in eax.
    veh2_get_room_adults_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x51'                                    # +0:  push ecx  (save this)
    t += b'\x8b\xc1'                               # +1:  mov eax, ecx
    t += encode_call(veh2_get_room_adults_va + len(t),
                     validate_info_va)              # +3:  call validate_info
    t += b'\x59'                                    # +8:  pop ecx   (restore this)
    t += b'\x75\x05'                               # +9:  jnz .valid (→ +16)
    t += b'\xb8' + dummy_bytes                      # +11: mov eax, dummy_va
    t += b'\x8b\x80\x74\x01\x00\x00'             # +16: mov eax, [eax+0x174]
    t += b'\x33\xd2'                               # +22: xor edx, edx
    t += b'\x8a\x91\xb4\x00\x00\x00'             # +24: mov dl, [ecx+0xB4]
    t += b'\x2b\xc2'                               # +30: sub eax, edx
    t += b'\xc3'                                    # +32: ret
    assert len(t) == 33
    cave += t

    # --- Fix 17d: Object::InitialiseIsFixedForMapList (0x63A640) — 38 hits ---
    # Displace 6 bytes: push esi; mov esi,ecx; mov eax,[esi+0x28]
    # Helper replaces the displaced info load. On invalid, uses dummy_va
    # so the function continues with dummy values (same as VEH behavior).
    veh2_init_fixed_map_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x56'                                    # +0:  push esi  (displaced)
    t += b'\x8b\xf1'                               # +1:  mov esi, ecx  (displaced)
    t += b'\x8b\xc6'                               # +3:  mov eax, esi
    t += encode_call(veh2_init_fixed_map_va + len(t),
                     validate_info_va)              # +5:  call validate_info
    t += b'\x75\x05'                               # +10: jnz .valid (→ +17)
    t += b'\xb8' + dummy_bytes                      # +12: mov eax, dummy_va
    jmp_va = veh2_init_fixed_map_va + len(t)        # +17
    t += encode_jmp(jmp_va,
                    VEH2_INIT_FIXED_MAP_VA + VEH2_INIT_FIXED_MAP_DISPLACED)
    assert len(t) == 22
    cave += t

    # --- Fix 17e: Abode::Process crash at 0x4044D8 — 38 hits ---
    # Mid-function: displace 5 bytes (mov ecx,[esi+0x28]; or al,0x40).
    # On invalid info, uses dummy_va as ecx so the function continues
    # reading from dummy struct (same as VEH behavior).
    veh2_process_crash_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x0c\x40'                               # +0:  or al, 0x40  (displaced)
    t += b'\x50'                                    # +2:  push eax  (save or'd flags)
    t += b'\x8b\xc6'                               # +3:  mov eax, esi  (object ptr)
    t += encode_call(veh2_process_crash_va + len(t),
                     validate_info_va)              # +5:  call validate_info
    t += b'\x75\x05'                               # +10: jnz .valid (→ +17)
    t += b'\xb8' + dummy_bytes                      # +12: mov eax, dummy_va
    t += b'\x8b\xc8'                               # +17: mov ecx, eax  (info or dummy)
    t += b'\x58'                                    # +19: pop eax  (restore flags)
    jmp_va = veh2_process_crash_va + len(t)         # +20
    t += encode_jmp(jmp_va, VEH2_PROCESS_RESUME_VA) # jmp 0x4044DD
    assert len(t) == 25
    cave += t

    # --- Fix 17f-1: MapCell::FindTypeOnMap site 1 (0x60161A) — 19 hits ---
    # Displace 6 bytes: mov ecx,[edi+0x28]; mov eax,[ecx+0x10]
    # On invalid info, uses dummy_va so type comparison proceeds with
    # dummy object_type (won't match any real search type).
    veh2_findtype_site1_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\xc7'                               # +0:  mov eax, edi
    t += encode_call(veh2_findtype_site1_va + len(t),
                     validate_info_va)              # +2:  call validate_info
    t += b'\x75\x05'                               # +7:  jnz .valid (→ +14)
    t += b'\xb8' + dummy_bytes                      # +9:  mov eax, dummy_va
    t += b'\x8b\x40\x10'                           # +14: mov eax, [eax+0x10]
    jmp_va = veh2_findtype_site1_va + len(t)        # +17
    t += encode_jmp(jmp_va, VEH2_FINDTYPE_SITE1_RESUME_VA)  # jmp 0x601620
    assert len(t) == 22
    cave += t

    # --- Fix 17f-2: MapCell::FindTypeOnMap site 2 (0x601668) — 18 hits ---
    # Displace 6 bytes: mov ecx,[eax+0x28]; cmp [ecx+0x10],edi
    # On invalid info, uses dummy_va so type comparison proceeds with
    # dummy object_type (won't match, traversal continues to next object).
    veh2_findtype_site2_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x50'                                    # +0:  push eax  (save object ptr)
    t += encode_call(veh2_findtype_site2_va + len(t),
                     validate_info_va)              # +1:  call validate_info
    t += b'\x75\x05'                               # +6:  jnz .valid (→ +13)
    t += b'\xb8' + dummy_bytes                      # +8:  mov eax, dummy_va
    t += b'\x8b\xc8'                               # +13: mov ecx, eax  (info or dummy)
    t += b'\x58'                                    # +15: pop eax  (restore object)
    t += b'\x39\x79\x10'                           # +16: cmp [ecx+0x10], edi
    jmp_va = veh2_findtype_site2_va + len(t)        # +19
    t += encode_jmp(jmp_va, VEH2_FINDTYPE_SITE2_RESUME_VA)  # jmp 0x60166E
    assert len(t) == 24
    cave += t

    # --- Dummy struct: self-referencing, goes in .data (writable) ---
    dummy_struct = dummy_bytes * (DUMMY_STRUCT_SIZE // 4)

    return (cave, dummy_struct, init_globals_va, safe_loaders,
            safe_tribe_va, safe_vtable_va, intro_cleanup_trampoline_va,
            stream_null_guard_va,
            townstats_wrapper_add_guard_va, townstats_wrapper_rem_guard_va,
            townstats_villager_add_guard_va, townstats_villager_rem_guard_va,
            veh_abode_adults_va, veh_abode_children_va,
            veh_anim_ready_va, veh_influence_va,
            veh2_get_abode_type_va, veh2_obj_is_type_8_va,
            veh2_obj_is_type_0_va, veh2_obj_is_type_6_va,
            veh2_get_room_adults_va, veh2_init_fixed_map_va,
            veh2_process_crash_va, veh2_findtype_site1_va,
            veh2_findtype_site2_va)


def patch_dp_loads(data, dp_addr, safe_eax_va, safe_edx_va, safe_ecx_va):
    """Replace all mov eax/edx/ecx,[dp_addr] with calls to safe_load variants."""
    addr_bytes = struct.pack('<I', dp_addr)
    patched = skipped = 0
    pos = TEXT_FILE_START

    while pos < CODE_CAVE_FILE_OFFSET:
        idx = data.find(addr_bytes, pos, CODE_CAVE_FILE_OFFSET)
        if idx == -1:
            break

        if idx >= 1 and data[idx - 1] == 0xA1:
            # mov eax, [addr] — 5 bytes
            off = idx - 1
            after = data[idx + 4:idx + 10]
            if b'\x85\xc0' in after:
                skipped += 1
            else:
                data[off:off + 5] = encode_call(off + IMAGE_BASE, safe_eax_va)
                patched += 1

        elif idx >= 2 and data[idx - 2:idx] == b'\x8b\x15':
            # mov edx, [addr] — 6 bytes
            off = idx - 2
            after = data[idx + 4:idx + 10]
            if b'\x85\xd2' in after:
                skipped += 1
            else:
                data[off:off + 6] = encode_call(off + IMAGE_BASE, safe_edx_va) + b'\x90'
                patched += 1

        elif idx >= 2 and data[idx - 2:idx] == b'\x8b\x0d':
            # mov ecx, [addr] — 6 bytes
            off = idx - 2
            after = data[idx + 4:idx + 10]
            if b'\x85\xc9' in after:
                skipped += 1
            else:
                data[off:off + 6] = encode_call(off + IMAGE_BASE, safe_ecx_va) + b'\x90'
                patched += 1

        pos = idx + 4

    return patched, skipped


def main():
    parser = argparse.ArgumentParser(
        description="Apply Wine/Proton crash fixes to byte-exact runblack exe.")
    parser.add_argument("--input", "-i", type=Path, required=True)
    parser.add_argument("--output", "-o", type=Path, required=True)
    parser.add_argument("--skip", type=str, default="",
                        help="Comma-separated fix numbers to skip, e.g. --skip 4,5,6")
    args = parser.parse_args()
    skip = set(int(x) for x in args.skip.split(",") if x.strip())
    if skip:
        print(f"Skipping fixes: {sorted(skip)}")

    data = bytearray(args.input.read_bytes())
    md5 = hashlib.md5(data).hexdigest()
    if md5 != EXPECTED_MD5:
        print(f"WARNING: Input MD5 {md5} != expected {EXPECTED_MD5}")
    else:
        print(f"Input MD5 verified: {md5}")

    # === Build code cave (dummy in .text, read-only — writes fault and game's SEH recovers) ===
    dummy_va = CODE_CAVE_VA
    (cave, dummy_struct, init_globals_va, safe_loaders, safe_tribe_va,
     safe_vtable_va, intro_cleanup_trampoline_va,
     stream_null_guard_va,
     townstats_wrapper_add_guard_va, townstats_wrapper_rem_guard_va,
     townstats_villager_add_guard_va, townstats_villager_rem_guard_va,
     veh_abode_adults_va, veh_abode_children_va,
     veh_anim_ready_va, veh_influence_va,
     veh2_get_abode_type_va, veh2_obj_is_type_8_va,
     veh2_obj_is_type_0_va, veh2_obj_is_type_6_va,
     veh2_get_room_adults_va, veh2_init_fixed_map_va,
     veh2_process_crash_va, veh2_findtype_site1_va,
     veh2_findtype_site2_va,
     ) = build_cave(dummy_va)

    # === Write code cave ===
    cave_off = va_to_offset(CODE_CAVE_VA)
    assert len(cave) <= CODE_CAVE_MAX, f"Cave {len(cave)} > {CODE_CAVE_MAX}"
    assert all(b == 0 for b in data[cave_off:cave_off + len(cave)]), \
        "Code cave area not empty"
    data[cave_off:cave_off + len(cave)] = cave
    print(f"Code cave: {len(cave)}/{CODE_CAVE_MAX} bytes at {CODE_CAVE_VA:#010x}")

    # === Fix 0: Redirect first text init call to install VEH + chain to original ===
    # All three calls are text string loaders, not DirectPlay. We only hook call #1
    # to install VEH before it runs. Calls #2/#3 are left untouched.
    if 0 not in skip:
        call_va = DP_INIT_CALL_VAS[0]
        off = va_to_offset(call_va)
        assert data[off] == 0xE8, f"Expected CALL at {call_va:#x}, got {data[off]:#x}"
        data[off:off + 5] = encode_call(call_va, init_globals_va)
        print(f"Fix 0: Hooked 1st text init call to install VEH + chain to original")
    else:
        print("Fix 0: SKIPPED")

    # === Fix 1: REMOVED — Fix 0 already sets DP globals to dummy_va ===
    print("Fix 1: Removed (redundant with Fix 0)")

    # === Fix 2: Tribe table bounds check ===
    if 2 not in skip:
        for va in TRIBE_LOOKUP_VAS:
            off = va_to_offset(va)
            data[off:off + TRIBE_LOOKUP_SIZE] = encode_call(va, safe_tribe_va) + b'\x90' * 5
        print(f"Fix 2: Tribe bounds check at {len(TRIBE_LOOKUP_VAS)} sites")
    else:
        print("Fix 2: SKIPPED")

    # === Fix 3: Vtable delegate validation ===
    if 3 not in skip:
        off = va_to_offset(VTABLE_THUNK_VA)
        data[off:off + VTABLE_THUNK_SIZE] = encode_jmp(VTABLE_THUNK_VA, safe_vtable_va) + b'\x90' * 2
        print(f"Fix 3: Vtable delegate guard at {VTABLE_THUNK_VA:#010x}")
    else:
        print("Fix 3: SKIPPED")

    # === Fix 4: TownStats info pointer validation ===
    if 4 not in skip:
        # Wrapper Add: replace 0x739A20 (19 bytes) with jmp to trampoline + NOPs
        off = va_to_offset(TOWNSTATS_WRAPPER_ADD_VA)
        assert data[off:off + 4] == b'\x8b\x44\x24\x04', \
            f"Expected mov eax,[esp+4] at {TOWNSTATS_WRAPPER_ADD_VA:#x}"
        data[off:off + TOWNSTATS_WRAPPER_ADD_SIZE] = \
            encode_jmp(TOWNSTATS_WRAPPER_ADD_VA, townstats_wrapper_add_guard_va) + \
            b'\x90' * (TOWNSTATS_WRAPPER_ADD_SIZE - 5)

        # Wrapper Remove: replace 0x739A40 (19 bytes) with jmp to trampoline + NOPs
        off = va_to_offset(TOWNSTATS_WRAPPER_REM_VA)
        assert data[off:off + 4] == b'\x8b\x44\x24\x04', \
            f"Expected mov eax,[esp+4] at {TOWNSTATS_WRAPPER_REM_VA:#x}"
        data[off:off + TOWNSTATS_WRAPPER_REM_SIZE] = \
            encode_jmp(TOWNSTATS_WRAPPER_REM_VA, townstats_wrapper_rem_guard_va) + \
            b'\x90' * (TOWNSTATS_WRAPPER_REM_SIZE - 5)

        # Villager secondary Add: replace first 5 bytes of 0x7492E0 with jmp
        off = va_to_offset(TOWNSTATS_VILLAGER_ADD_VA)
        assert data[off:off + 5] == b'\x83\xec\x08\x56\x57', \
            f"Expected sub esp,8; push esi; push edi at {TOWNSTATS_VILLAGER_ADD_VA:#x}"
        data[off:off + 5] = encode_jmp(TOWNSTATS_VILLAGER_ADD_VA, townstats_villager_add_guard_va)

        # Villager secondary Remove: replace first 5 bytes of 0x7493C0 with jmp
        off = va_to_offset(TOWNSTATS_VILLAGER_REM_VA)
        assert data[off:off + 5] == b'\x83\xec\x08\x56\x57', \
            f"Expected sub esp,8; push esi; push edi at {TOWNSTATS_VILLAGER_REM_VA:#x}"
        data[off:off + 5] = encode_jmp(TOWNSTATS_VILLAGER_REM_VA, townstats_villager_rem_guard_va)

        print(f"Fix 4: Info validation on 4 TownStats functions (2 wrappers + 2 inner)")
    else:
        print("Fix 4: SKIPPED")

    # === Fix 5: Skip info-index branches ===
    if 5 not in skip:
        for va in INFO_INDEX_SKIP_VAS:
            off = va_to_offset(va)
            assert data[off] == 0x75, f"Expected JNZ (0x75) at {va:#x}, got {data[off]:#x}"
            data[off] = 0xEB
        print(f"Fix 5: Skipped {len(INFO_INDEX_SKIP_VAS)} info-index branches")
    else:
        print("Fix 5: SKIPPED")

    # === Fix 6: NOP functions with garbage vtable dereferences ===
    if 6 not in skip:
        for va, cleanup in VTABLE_DEREF_NOP_VAS:
            off = va_to_offset(va)
            data[off:off + 5] = b'\x33\xc0' + b'\xc2' + struct.pack('<H', cleanup)
        print(f"Fix 6: NOP'd {len(VTABLE_DEREF_NOP_VAS)} vtable-deref functions")
    else:
        print("Fix 6: SKIPPED")

    # === Fix 10: Intro cleanup + clear state bits via code cave trampoline ===
    # Between Loop 1 and Loop 2, the game calls 0x5F89F0(2) to clean up intro
    # resources. We redirect through a trampoline that ALSO clears bits 0+1 at
    # [0xE85304] so Loop 2 exits immediately.
    # Original: push 2 (6a 02) + call 0x5F89F0 (e8 XX XX XX XX) + add esp,4 (83 c4 04) = 10 bytes
    # Replaced: call trampoline (e8 XX XX XX XX) + 5 NOPs
    if 10 not in skip:
        off = va_to_offset(LOOP2_TRANSITION_VA)
        expected = b'\x6a\x02\xe8'  # push 2 + call opcode
        actual = data[off:off + 3]
        assert actual == expected, \
            f"Expected push 2 + call at {LOOP2_TRANSITION_VA:#x}, got {actual.hex()}"
        patch = encode_call(LOOP2_TRANSITION_VA, intro_cleanup_trampoline_va)
        patch += b'\x90' * 5  # NOPs to fill remaining 5 bytes
        assert len(patch) == 10
        data[off:off + 10] = patch
        print(f"Fix 10: Intro cleanup + bit-clear trampoline at {LOOP2_TRANSITION_VA:#010x}")
    else:
        print("Fix 10: SKIPPED")

    # === Fix 15: Guard stream write function against NULL stream ===
    if 15 not in skip:
        off = va_to_offset(STREAM_WRITE_VA)
        expected = b'\x8b\x44\x24\x0c\x53'  # mov eax,[esp+0xC]; push ebx
        actual = data[off:off + 5]
        assert actual == expected, \
            f"Expected stream write prologue at {STREAM_WRITE_VA:#x}, got {actual.hex()}"
        data[off:off + 5] = encode_jmp(STREAM_WRITE_VA, stream_null_guard_va)
        print(f"Fix 15: Stream NULL guard at {STREAM_WRITE_VA:#010x}")
    else:
        print("Fix 15: SKIPPED")

    # === Fix 16: VEH hotspot trampolines ===
    if 16 not in skip:
        # 16a: Abode::GetPercentAbodeFullWithAdults — displace 7 bytes
        off = va_to_offset(VEH_ABODE_ADULTS_VA)
        assert data[off:off + 7] == b'\x83\xec\x08\x56\x8b\x71\x28', \
            f"Expected prologue at {VEH_ABODE_ADULTS_VA:#x}"
        data[off:off + 7] = encode_jmp(VEH_ABODE_ADULTS_VA, veh_abode_adults_va) + b'\x90\x90'

        # 16b: Abode::GetPercentAbodeFullWithChildren — displace 7 bytes
        off = va_to_offset(VEH_ABODE_CHILDREN_VA)
        assert data[off:off + 7] == b'\x8b\x41\x28\x83\xec\x08\x56', \
            f"Expected prologue at {VEH_ABODE_CHILDREN_VA:#x}"
        data[off:off + 7] = encode_jmp(VEH_ABODE_CHILDREN_VA, veh_abode_children_va) + b'\x90\x90'

        # 16c: Living::IsReadyForNewAnimation — displace 14 bytes
        off = va_to_offset(VEH_ANIM_READY_VA)
        assert data[off:off + 3] == b'\x56\x8b\xf1', \
            f"Expected prologue at {VEH_ANIM_READY_VA:#x}"
        data[off:off + 14] = encode_jmp(VEH_ANIM_READY_VA, veh_anim_ready_va) + b'\x90' * 9

        # 16d: MultiMapFixed::GetInfluence — displace 10 bytes
        off = va_to_offset(VEH_INFLUENCE_VA)
        assert data[off:off + 7] == b'\x51\x56\x8b\xf1\x8b\x06\x57', \
            f"Expected prologue at {VEH_INFLUENCE_VA:#x}"
        data[off:off + 10] = encode_jmp(VEH_INFLUENCE_VA, veh_influence_va) + b'\x90' * 5

        print(f"Fix 16: VEH hotspot trampolines for 4 functions (~180K AVs eliminated)")
    else:
        print("Fix 16: SKIPPED")

    # === Fix 17: Remaining VEH hotspot trampolines (second pass) ===
    if 17 not in skip:
        # 17a: Abode::GetAbodeType — replace entire 10-byte function
        off = va_to_offset(VEH2_GET_ABODE_TYPE_VA)
        assert data[off:off + 3] == b'\x8b\x41\x28', \
            f"Expected mov eax,[ecx+0x28] at {VEH2_GET_ABODE_TYPE_VA:#x}"
        data[off:off + VEH2_GET_ABODE_TYPE_SIZE] = \
            encode_jmp(VEH2_GET_ABODE_TYPE_VA, veh2_get_abode_type_va) + \
            b'\x90' * (VEH2_GET_ABODE_TYPE_SIZE - 5)

        # 17b-1: Object type==8 check — replace entire 17-byte function
        off = va_to_offset(VEH2_OBJ_IS_TYPE_8_VA)
        assert data[off:off + 3] == b'\x8b\x41\x28', \
            f"Expected mov eax,[ecx+0x28] at {VEH2_OBJ_IS_TYPE_8_VA:#x}"
        data[off:off + VEH2_OBJ_IS_TYPE_8_SIZE] = \
            encode_jmp(VEH2_OBJ_IS_TYPE_8_VA, veh2_obj_is_type_8_va) + \
            b'\x90' * (VEH2_OBJ_IS_TYPE_8_SIZE - 5)

        # 17b-2: Object type==0 check — replace entire 16-byte function
        off = va_to_offset(VEH2_OBJ_IS_TYPE_0_VA)
        assert data[off:off + 3] == b'\x8b\x41\x28', \
            f"Expected mov eax,[ecx+0x28] at {VEH2_OBJ_IS_TYPE_0_VA:#x}"
        data[off:off + VEH2_OBJ_IS_TYPE_0_SIZE] = \
            encode_jmp(VEH2_OBJ_IS_TYPE_0_VA, veh2_obj_is_type_0_va) + \
            b'\x90' * (VEH2_OBJ_IS_TYPE_0_SIZE - 5)

        # 17b-3: Object type==6 check — replace entire 17-byte function
        off = va_to_offset(VEH2_OBJ_IS_TYPE_6_VA)
        assert data[off:off + 3] == b'\x8b\x41\x28', \
            f"Expected mov eax,[ecx+0x28] at {VEH2_OBJ_IS_TYPE_6_VA:#x}"
        data[off:off + VEH2_OBJ_IS_TYPE_6_SIZE] = \
            encode_jmp(VEH2_OBJ_IS_TYPE_6_VA, veh2_obj_is_type_6_va) + \
            b'\x90' * (VEH2_OBJ_IS_TYPE_6_SIZE - 5)

        # 17c: Abode::GetRoomLeftForAdults — replace entire 20-byte function
        off = va_to_offset(VEH2_GET_ROOM_ADULTS_VA)
        assert data[off:off + 3] == b'\x8b\x41\x28', \
            f"Expected mov eax,[ecx+0x28] at {VEH2_GET_ROOM_ADULTS_VA:#x}"
        data[off:off + VEH2_GET_ROOM_ADULTS_SIZE] = \
            encode_jmp(VEH2_GET_ROOM_ADULTS_VA, veh2_get_room_adults_va) + \
            b'\x90' * (VEH2_GET_ROOM_ADULTS_SIZE - 5)

        # 17d: Object::InitialiseIsFixedForMapList — displace 6-byte prologue
        off = va_to_offset(VEH2_INIT_FIXED_MAP_VA)
        assert data[off:off + 3] == b'\x56\x8b\xf1', \
            f"Expected push esi; mov esi,ecx at {VEH2_INIT_FIXED_MAP_VA:#x}"
        data[off:off + VEH2_INIT_FIXED_MAP_DISPLACED] = \
            encode_jmp(VEH2_INIT_FIXED_MAP_VA, veh2_init_fixed_map_va) + \
            b'\x90' * (VEH2_INIT_FIXED_MAP_DISPLACED - 5)

        # 17e: Abode::Process mid-function crash — displace 5 bytes
        off = va_to_offset(VEH2_PROCESS_CRASH_VA)
        assert data[off:off + 3] == b'\x8b\x4e\x28', \
            f"Expected mov ecx,[esi+0x28] at {VEH2_PROCESS_CRASH_VA:#x}"
        data[off:off + VEH2_PROCESS_DISPLACED] = \
            encode_jmp(VEH2_PROCESS_CRASH_VA, veh2_process_crash_va)

        # 17f-1: FindTypeOnMap site 1 — displace 6 bytes
        off = va_to_offset(VEH2_FINDTYPE_SITE1_VA)
        assert data[off:off + 3] == b'\x8b\x4f\x28', \
            f"Expected mov ecx,[edi+0x28] at {VEH2_FINDTYPE_SITE1_VA:#x}"
        data[off:off + VEH2_FINDTYPE_SITE1_DISPLACED] = \
            encode_jmp(VEH2_FINDTYPE_SITE1_VA, veh2_findtype_site1_va) + \
            b'\x90' * (VEH2_FINDTYPE_SITE1_DISPLACED - 5)

        # 17f-2: FindTypeOnMap site 2 — displace 6 bytes
        off = va_to_offset(VEH2_FINDTYPE_SITE2_VA)
        assert data[off:off + 3] == b'\x8b\x48\x28', \
            f"Expected mov ecx,[eax+0x28] at {VEH2_FINDTYPE_SITE2_VA:#x}"
        data[off:off + VEH2_FINDTYPE_SITE2_DISPLACED] = \
            encode_jmp(VEH2_FINDTYPE_SITE2_VA, veh2_findtype_site2_va) + \
            b'\x90' * (VEH2_FINDTYPE_SITE2_DISPLACED - 5)

        print(f"Fix 17: VEH hotspot trampolines for 9 sites (~512 AVs eliminated)")
    else:
        print("Fix 17: SKIPPED")

    # === Write output ===
    args.output.write_bytes(data)
    print(f"Output MD5: {hashlib.md5(data).hexdigest()}")
    print(f"Wrote {args.output}")


if __name__ == "__main__":
    main()

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

# --- Fix 19: Bounds-check default array lookup in spell/ability handler ---
# Function at 0x5C8720 takes a type index arg. Default case at 0x5C88CF does
# mov eax,[esi+eax*4+0x30] — crashes when eax is garbage (0x4BF0C3F0) from
# corrupted vtable return. Fault addr 0x4E4C45A4 >> VEH threshold.
# Fix: redirect the `ja .default` at 0x5C872E to a cave trampoline that
# bounds-checks eax before the array lookup.
FIX19_JA_VA = 0x005C872E           # ja .default (0F 87 9B 01 00 00)
FIX19_MAX_INDEX = 0xB3             # 179 entries (offset 0x30 to 0x2FC, /4)

# --- Fix 20: Validate vtable in LH3DMesh pack index function ---
# Function at 0x636E30 (_jmp_addr_0x00636e30) does:
#   mov eax,[ecx]; call [eax+0x2c]  — vtable dispatch
# When ecx points to object with garbage vtable (0x3CBD2E43), call [eax+0x2c]
# faults at high address → unhandled crash.
# Fix: replace function entry (5 bytes) with jmp to data cave trampoline.
FIX20_FUNC_VA = 0x00636E30         # function entry
FIX20_FUNC_SIZE = 5                # mov eax,[ecx] (2) + call [eax+0x2c] (3)
FIX20_RESUME_VA = 0x00636E35       # test eax, eax (after the call)

# --- Fix 22: Guard mesh/anim index function against dummy struct ---
# Function at 0x83ADD0 loads flags from [ecx+0x50] and mesh index from [ecx+0x5c].
# When ecx is the VEH dummy struct, [ecx+0x50] = dummy_va, test ah,0x08 passes
# (0x89 & 0x08 = 0x08), returning dummy_va as mesh index → cube rendering.
# Fix: check ecx == dummy_va, return -1 if so.
FIX22_FUNC_VA = 0x0083ADD0
FIX22_FUNC_SIZE = 16

# --- Fix 23: Diagnostic — zero MorphAnims blend weights (inline) ---
# Morphable::MorphAnims() at 0x619100 blends bone matrices using unclamped
# weights from fields 0xA0 and 0xA8. Under Wine, timing differences can cause
# these weights to exceed 1.0 during animation transitions, producing bone
# overshoot (visible as skeleton stretching). This diagnostic patches 4 field
# loads inline to force zero weights — no code cave needed.
# Each patch replaces a 6-byte field load with a same-size zero constant.
FIX23_PATCHES = [
    # (va, original_bytes, patch_bytes, description)
    (0x00619106, b'\xd9\x83\xa0\x00\x00\x00',                  # fld [ebx+0xA0]
                 b'\xd9\xee\x90\x90\x90\x90', "fld w1→fldz"),  # fldz + 4 NOP
    (0x0061913E, b'\x8b\x8b\xa0\x00\x00\x00',                  # mov ecx,[ebx+0xA0]
                 b'\x33\xc9\x90\x90\x90\x90', "mov w1→xor"),   # xor ecx,ecx + 4 NOP
    (0x00619150, b'\xd9\x83\xa8\x00\x00\x00',                  # fld [ebx+0xA8]
                 b'\xd9\xee\x90\x90\x90\x90', "fld w2→fldz"),  # fldz + 4 NOP
    (0x00619187, b'\x8b\x93\xa8\x00\x00\x00',                  # mov edx,[ebx+0xA8]
                 b'\x33\xd2\x90\x90\x90\x90', "mov w2→xor"),   # xor edx,edx + 4 NOP
]

# --- Fix 6: Guard GAbodeInfo::IsOkToCreateAtPos vtable deref ---
# 0x00404B10: thiscall function that does [ecx] → call [vtable+0x2C]. Crashes when
# ECX points to an object with a corrupted vtable. Instead of NOPing the whole function,
# validate [ecx] vtable in .rdata range — only bail on garbage, let valid calls through.
# Displaces 8-byte prologue (two mov instructions). Uses ret 0x10 (4 stack args).

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

    # --- Dummy struct: hybrid zero-filled with pointer self-references ---
    # Zero-filled by default so all scalar fields (enums, counts, floats,
    # indices) read as 0 — safe for any interpretation. Only pointer offsets
    # retain self-references (dummy_va) to prevent dereference cascades into
    # Wine's zero page (which is readable, unlike native Windows).
    # Read-only (.text section) is intentional: writes fault → game SEH recovers.
    #
    # Pointer offsets derived from Object + GObjectInfo struct hierarchies:
    #   Object:       vtable(0x0), next(0x10), map_child(0x20), info(0x28),
    #                 map_parent(0x38), game_3d_object(0x40), fire_effect(0x44)
    #   GObjectInfo:  vtable(0x0), next(0x8)
    POINTER_OFFSETS = [0x00, 0x08, 0x10, 0x20, 0x28, 0x38, 0x40, 0x44]
    cave += b'\x00' * DUMMY_STRUCT_SIZE
    for off in POINTER_OFFSETS:
        struct.pack_into('<I', cave, off, dummy_va)

    # --- Safe return gadget (3 bytes) ---
    # Used by VEH to redirect bogus EIP (< 0x1000) from zero-page vtable
    # dispatches. Returns 0 to caller via: xor eax, eax; ret.
    safe_ret_va = CODE_CAVE_VA + len(cave)
    cave += b'\x31\xc0'                                          # xor eax, eax
    cave += b'\xc3'                                               # ret

    # --- VEH handler (139 bytes) ---
    # Catches ACCESS_VIOLATION at low fault addresses:
    #  Case A: EIP in .text → decode ModR/M, fix NULL register to dummy_va
    #  Case B: EIP < 0x1000 → bogus jump from zero-page vtable dispatch,
    #           redirect EIP to safe_ret_va (xor eax,eax; ret)
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
    veh += b'\x72\x41'                                           # +38: jb .check_bogus (->105)
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
    # .check_bogus: EIP < TEXT_VA_START. Is it < 0x1000 (zero-page dispatch)?
    veh += b'\x81\xf9' + struct.pack('<I', 0x1000)              # +105: cmp ecx, 0x1000
    veh += b'\x73\xeb'                                           # +111: jae .pass (->92)
    # Bogus jump target: redirect EIP to safe_ret_va, zero Eax
    veh += b'\xc7\x82\xb8\x00\x00\x00' + struct.pack('<I', safe_ret_va)
                                                                  # +113: mov [edx+0xB8], safe_ret_va (set Eip)
    veh += b'\xc7\x82\xb0\x00\x00\x00\x00\x00\x00\x00'         # +123: mov [edx+0xB0], 0 (set Eax=0)
    veh += b'\x83\xc8\xff'                                       # +133: or eax, -1  ; CONTINUE_EXECUTION
    veh += b'\xc2\x04\x00'                                       # +136: ret 4
    assert len(veh) == 139, f"VEH handler size {len(veh)} != 139"
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

    # --- Fix 16/17: VEH hotspot trampolines ---
    rdata_start = struct.pack('<I', RDATA_VA_START)
    rdata_end = struct.pack('<I', RDATA_VA_END)

    # --- Shared info validation helper (29 bytes) ---
    # Input: eax = object pointer (has ->info at +0x28)
    # Output: eax = info (non-zero) if valid, ZF=0
    #         eax = 0 if invalid, ZF=1
    # Clobbers: edx
    validate_info_va = CODE_CAVE_VA + len(cave)
    v = bytearray()
    v += b'\x8b\x40\x28'                          # +0:  mov eax, [eax+0x28]  ; info
    v += b'\x85\xc0'                               # +3:  test eax, eax
    v += b'\x74\x13'                               # +5:  jz .bad (→ +26)
    v += b'\x8b\x10'                               # +7:  mov edx, [eax]       ; vtable
    v += b'\x81\xfa' + rdata_start                 # +9:  cmp edx, RDATA_START
    v += b'\x72\x09'                               # +15: jb .bad (→ +26)
    v += b'\x81\xfa' + rdata_end                   # +17: cmp edx, RDATA_END
    v += b'\x73\x01'                               # +23: jae .bad (→ +26)
    v += b'\xc3'                                    # +25: ret (ZF=0 from cmp)
    v += b'\x31\xc0'                               # +26: xor eax, eax  (.bad, ZF=1)
    v += b'\xc3'                                    # +28: ret
    assert len(v) == 29
    cave += v

    # Fix 16 trampolines removed — VEH handles these ~180K AVs directly.
    # Reclaimed 127 bytes of cave space (16a: 27B, 16b: 25B, 16c: 32B, 16d: 43B).

    # --- Fix 17a: Abode::GetAbodeType (0x4061F0) — 312 hits ---
    # Replaces entire 10-byte function. On invalid info, return 0 (safe
    # default for ABODE_TYPE enum) instead of reading from dummy struct.
    veh2_get_abode_type_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\xc1'                               # +0:  mov eax, ecx
    t += encode_call(veh2_get_abode_type_va + len(t),
                     validate_info_va)              # +2:  call validate_info
    t += b'\x75\x04'                               # +7:  jnz .valid (→ +13)
    t += b'\x31\xc0'                               # +9:  xor eax, eax (type=0)
    t += b'\xc3'                                    # +11: ret
    # .valid: eax = validated info pointer
    t += b'\x90'                                    # +12: nop (alignment)
    t += b'\x8b\x80\x20\x01\x00\x00'             # +13: mov eax, [eax+0x120]
    t += b'\xc3'                                    # +19: ret
    assert len(t) == 20
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
    # On invalid info, return 0 ("no room") — safe conservative answer that
    # prevents AI from assigning villagers to ghost abodes.
    veh2_get_room_adults_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x51'                                    # +0:  push ecx  (save this)
    t += b'\x8b\xc1'                               # +1:  mov eax, ecx
    t += encode_call(veh2_get_room_adults_va + len(t),
                     validate_info_va)              # +3:  call validate_info
    t += b'\x59'                                    # +8:  pop ecx   (restore this)
    t += b'\x75\x04'                               # +9:  jnz .valid (→ +15)
    t += b'\x31\xc0'                               # +11: xor eax, eax (no room)
    t += b'\xc3'                                    # +13: ret
    t += b'\x90'                                    # +14: nop (alignment)
    # .valid: eax = validated info pointer
    t += b'\x8b\x80\x74\x01\x00\x00'             # +15: mov eax, [eax+0x174]
    t += b'\x33\xd2'                               # +21: xor edx, edx
    t += b'\x8a\x91\xb4\x00\x00\x00'             # +23: mov dl, [ecx+0xB4]
    t += b'\x2b\xc2'                               # +29: sub eax, edx
    t += b'\xc3'                                    # +31: ret
    assert len(t) == 32
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

    # --- Fix 19: Bounds-check spell handler default array lookup ---
    # The default case does mov eax,[esi+eax*4+0x30] with unchecked eax.
    # Bounds-check eax, return 0 if out of range. Shared epilogue saves bytes.
    fix19_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x3d' + struct.pack('<I', FIX19_MAX_INDEX)  # +0:  cmp eax, 0xB3       (5)
    t += b'\x73\x06'                                    # +5:  jae .bail (→ +13)   (2)
    t += b'\x8b\x44\x86\x30'                            # +7:  mov eax, [esi+eax*4+0x30] (4)
    t += b'\xeb\x02'                                     # +11: jmp .done (→ +15)  (2)
    # .bail:
    t += b'\x31\xc0'                                     # +13: xor eax, eax       (2)
    # .done: shared epilogue
    t += b'\x5f'                                         # +15: pop edi            (1)
    t += b'\x5e'                                         # +16: pop esi            (1)
    t += b'\xc2\x0c\x00'                                # +17: ret 0x0C           (3)
    assert len(t) == 20
    cave += t

    # --- Fix 20: Validate vtable in LH3DMesh pack index function ---
    # mov eax,[ecx]; call [eax+0x2c] — crashes when vtable is garbage.
    # Check vtable < RDATA_END, bail with eax=0 if invalid.
    fix20_va = CODE_CAVE_VA + len(cave)
    rdata_end_bytes = struct.pack('<I', RDATA_VA_END)
    t = bytearray()
    t += b'\x8b\x01'                                    # +0:  mov eax, [ecx]  (displaced) (2)
    t += b'\x3d' + rdata_end_bytes                       # +2:  cmp eax, RDATA_END          (5)
    t += b'\x72\x04'                                     # +7:  jb .ok (→ +13)              (2)
    t += b'\x31\xc0'                                     # +9:  xor eax, eax                (2)
    t += b'\xeb\x03'                                     # +11: jmp .done (→ +16)           (2)
    # .ok:
    t += b'\xff\x50\x2c'                                 # +13: call [eax+0x2c] (displaced) (3)
    # .done:
    jmp_va = fix20_va + len(t)                           # +16
    t += encode_jmp(jmp_va, FIX20_RESUME_VA)             # +16: jmp 0x636E35               (5)
    assert len(t) == 21
    cave += t

    # --- Fix 5: Validate info pointer before array index access ---
    # At 0x4041C5, a virtual call result is tested. If 0, the code loads
    # [esi+0x28] (info) and uses [info+0x1F8] as array index. Garbage info
    # pointers produce huge indices → out-of-bounds crash at high address
    # (beyond VEH threshold). We validate info with validate_info first.
    # Displaces 7 bytes: test eax,eax (2) + jne (2) + mov ecx,[esi+0x28] (3)
    FIX5_VA = 0x004041C5
    FIX5_DISPLACED = 7
    FIX5_JNE_TARGET = 0x00404210    # original jne target (skip registration)
    FIX5_RESUME = 0x004041CC        # resume at mov edx,[ecx+0x1f8]
    fix5_trampoline_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x85\xc0'                                  # +0:  test eax, eax       (displaced)
    t += b'\x75\x10'                                  # +2:  jne .skip (→ +20)   (displaced, short)
    t += b'\x8b\xc6'                                  # +4:  mov eax, esi        (object → eax)
    t += encode_call(fix5_trampoline_va + len(t),
                     validate_info_va)                 # +6:  call validate_info  (5)
    t += b'\x74\x07'                                  # +11: jz .skip (→ +20)    (invalid info)
    t += b'\x8b\xc8'                                  # +13: mov ecx, eax        (validated info → ecx)
    jmp_va = fix5_trampoline_va + len(t)              # +15
    t += encode_jmp(jmp_va, FIX5_RESUME)              # +15: jmp 0x4041CC        (5)
    # .skip: skip registration (original jne target)
    skip_va = fix5_trampoline_va + len(t)             # +20
    t += encode_jmp(skip_va, FIX5_JNE_TARGET)         # +20: jmp 0x404210        (5)
    assert len(t) == 25
    cave += t

    # --- Fix 6a: Bounds-check GetInfoFromText index (call site 2) ---
    # At 0x71579D: lea edi,[eax*8+_AbodeInfos] — eax = index*57 from LEA chain.
    # If GetInfoFromText returned -1, eax = -57 → wild pointer.
    # Bounds-check: index*57 must be < 147*57 = 8379 (0x20BB).
    # Bail to 0x717E8A (function's clean exit: pop regs, return 0).
    ABODEINFOS_BASE_VA = 0x00C3C690
    FIX6A_LEA_VA = 0x0071579D
    FIX6A_BAIL_VA = 0x00717E8A
    fix6a_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x3d\xbb\x20\x00\x00'                  # +0:  cmp eax, 0x20BB       (5)
    t += b'\x73\xff'                               # +5:  jae .bail (placeholder)(2)
    t += b'\x8d\x3c\xc5' + struct.pack('<I', ABODEINFOS_BASE_VA)
                                                    # +7:  lea edi,[eax*8+base]  (7)
    jmp_va = fix6a_va + len(t)
    t += encode_jmp(jmp_va, FIX6A_LEA_VA + 7)     # +14: jmp 0x7157A4          (5)
    bail_off = len(t)                               # +19
    t += encode_jmp(fix6a_va + bail_off, FIX6A_BAIL_VA)  # +19: jmp 0x717E8A    (5)
    assert len(t) == 24
    t[6] = bail_off - 7     # jae: 19 - 7 = 12
    cave += t

    # --- Fix 6c: Validate GAbodeInfo::Find return vtable (call site 3) ---
    # GAbodeInfo::Find (0x405B30) returns pointer into _AbodeInfos or NULL.
    # Its epilogue at 0x405B69 is: pop edi; pop esi; ret (+ 4 NOP padding).
    # Replace the ret+NOPs (5 bytes) with jmp to cave that validates vtable.
    # Inlined vtable check — no separate helper needed.
    FIND_EPILOGUE_VA = 0x00405B6B    # the ret instruction
    fix6c_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x85\xc0'                               # +0:  test eax, eax         (2)
    t += b'\x74\x13'                               # +2:  jz .bad (→ +23)       (2)
    t += b'\x8b\x10'                               # +4:  mov edx, [eax]        (2)
    t += b'\x81\xfa' + rdata_start                 # +6:  cmp edx, RDATA_START  (6)
    t += b'\x72\x09'                               # +12: jb .bad (→ +23)       (2)
    t += b'\x81\xfa' + rdata_end                   # +14: cmp edx, RDATA_END    (6)
    t += b'\x73\x01'                               # +20: jae .bad (→ +23)      (2)
    t += b'\xc3'                                    # +22: ret (valid)           (1)
    t += b'\x31\xc0'                               # +23: xor eax, eax          (2)
    t += b'\xc3'                                    # +25: ret                    (1)
    assert len(t) == 26
    cave += t

    # --- Fix 6 trampoline: Validate vtable at IsOkToCreateAtPos entry ---
    # Instead of NOPing the function (which kills abode placement), validate
    # [ecx] vtable at entry. If in .rdata range, execute displaced prologue
    # and let the function proceed normally. If garbage, return false.
    # Displaces 8 bytes: mov eax,[esp+0xc] (4) + mov edx,[esp+0x8] (4).
    fix6_trampoline_va = CODE_CAVE_VA + len(cave)
    t = bytearray()
    t += b'\x8b\x01'                               # +0:  mov eax, [ecx]        (2) load vtable
    t += b'\x3d' + rdata_start                      # +2:  cmp eax, RDATA_START  (5)
    t += b'\x72\x14'                               # +7:  jb .bail (→ +29)      (2)
    t += b'\x3d' + rdata_end                        # +9:  cmp eax, RDATA_END    (5)
    t += b'\x73\x0d'                               # +14: jae .bail (→ +29)     (2)
    # Valid vtable — displaced prologue
    t += b'\x8b\x44\x24\x0c'                       # +16: mov eax, [esp+0xc]    (4) displaced
    t += b'\x8b\x54\x24\x08'                       # +20: mov edx, [esp+0x8]    (4) displaced
    jmp_va = fix6_trampoline_va + len(t)            # +24
    t += encode_jmp(jmp_va, 0x00404B18)             # +24: jmp 0x404B18          (5) resume
    # .bail:
    t += b'\x31\xc0'                               # +29: xor eax, eax          (2)
    t += b'\xc2\x10\x00'                           # +31: ret 0x10              (3)
    assert len(t) == 34
    cave += t

    # --- Dummy struct: self-referencing, goes in .data (writable) ---
    dummy_struct = dummy_bytes * (DUMMY_STRUCT_SIZE // 4)

    return (cave, dummy_struct, init_globals_va, safe_loaders,
            safe_tribe_va, safe_vtable_va, intro_cleanup_trampoline_va,
            stream_null_guard_va,
            townstats_wrapper_add_guard_va, townstats_wrapper_rem_guard_va,
            townstats_villager_add_guard_va, townstats_villager_rem_guard_va,
            veh2_get_abode_type_va, veh2_obj_is_type_8_va,
            veh2_obj_is_type_0_va, veh2_obj_is_type_6_va,
            veh2_get_room_adults_va, veh2_init_fixed_map_va,
            veh2_process_crash_va, veh2_findtype_site1_va,
            veh2_findtype_site2_va,
            fix19_va, fix20_va, fix5_trampoline_va,
            fix6a_va, fix6c_va, fix6_trampoline_va)


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
     veh2_get_abode_type_va, veh2_obj_is_type_8_va,
     veh2_obj_is_type_0_va, veh2_obj_is_type_6_va,
     veh2_get_room_adults_va, veh2_init_fixed_map_va,
     veh2_process_crash_va, veh2_findtype_site1_va,
     veh2_findtype_site2_va,
     fix19_va, fix20_va, fix5_trampoline_va,
     fix6a_va, fix6c_va, fix6_trampoline_va,
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

    # === Fix 1: Safe-load all DirectPlay global pointer reads ===
    # ~1400 sites read from 6 DP globals. Each load is replaced with a call to a
    # cave function that returns dummy when the pointer is NULL.
    if 1 not in skip:
        total_patched = total_skipped = 0
        for dp_addr in DP_GLOBAL_ADDRS:
            safe_eax_va, safe_edx_va, safe_ecx_va = safe_loaders[dp_addr]
            p, s = patch_dp_loads(data, dp_addr, safe_eax_va, safe_edx_va, safe_ecx_va)
            total_patched += p
            total_skipped += s
        print(f"Fix 1: Safe-load {total_patched} DP global reads ({total_skipped} already guarded)")
    else:
        print("Fix 1: SKIPPED")

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

    # === Fix 5: Validate info pointer before array index access ===
    if 5 not in skip:
        off = va_to_offset(0x004041C5)
        assert data[off:off + 4] == b'\x85\xc0\x75\x47', \
            f"Expected test eax,eax; jne at 0x4041C5, got {data[off:off+4].hex()}"
        data[off:off + 7] = encode_jmp(0x004041C5, fix5_trampoline_va) + b'\x90\x90'
        print(f"Fix 5: Info validation trampoline at 0x004041C5 (array index guard)")
    else:
        print("Fix 5: SKIPPED")

    # === Fix 6: Guard GAbodeInfo::IsOkToCreateAtPos + upstream root-cause fixes ===
    # IsOkToCreateAtPos (0x404B10) crashes when ECX has a corrupted vtable.
    # Instead of NOPing the function (which kills abode placement), validate
    # [ecx] vtable at entry — only bail on garbage, let valid calls through.
    # Additionally, guard two upstream sources of garbage GAbodeInfo* pointers.
    # (Fix 6b removed: patching GetInfo@PlannedAbode to return NULL caused
    # callers at 0x4060C0/0x4061A0/0x4061E0 to deref NULL → VEH cascade → crash.)
    if 6 not in skip:
        # Fix 6: Validate vtable at IsOkToCreateAtPos entry
        # Displace 8 bytes (two mov instructions), jmp to trampoline that checks vtable
        func_va = 0x00404B10
        off = va_to_offset(func_va)
        assert data[off:off + 4] == b'\x8b\x44\x24\x0c', \
            f"Expected mov eax,[esp+0xc] at {func_va:#x}, got {data[off:off+4].hex()}"
        data[off:off + 5] = encode_jmp(func_va, fix6_trampoline_va)
        data[off + 5:off + 8] = b'\x90\x90\x90'  # NOP padding for displaced 2nd mov
        print(f"  Fix 6: Vtable validation trampoline at {func_va:#010x}")

        # Fix 6a: Bounds-check GetInfoFromText index before LEA (call site 2)
        # At 0x71579D: lea edi,[eax*8+_AbodeInfos] — if index from GetInfoFromText
        # is -1 (not found), eax=-57 → wild pointer. Replace 7-byte LEA with jmp.
        off = va_to_offset(0x0071579D)
        assert data[off] == 0x8D and data[off + 1] == 0x3C, \
            f"Expected LEA edi at 0x71579D, got {data[off:off+2].hex()}"
        data[off:off + 5] = encode_jmp(0x0071579D, fix6a_va)
        data[off + 5:off + 7] = b'\x90\x90'
        print(f"  Fix 6a: GetInfoFromText bounds check at 0x0071579D")

        # Fix 6c: Validate GAbodeInfo::Find return vtable (call site 3)
        # Find epilogue at 0x405B6B: ret + 4 NOPs (5 bytes). Replace with jmp to
        # cave trampoline that validates [eax] vtable, returns NULL if corrupt.
        off = va_to_offset(0x00405B6B)
        assert data[off:off + 5] == b'\xc3\x90\x90\x90\x90', \
            f"Expected ret+nops at 0x405B6B, got {data[off:off+5].hex()}"
        data[off:off + 5] = encode_jmp(0x00405B6B, fix6c_va)
        print(f"  Fix 6c: GAbodeInfo::Find vtable validation at 0x00405B6B")

        print(f"Fix 6: Vtable validation at IsOkToCreateAtPos + 2 upstream guards (6a, 6c)")
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

    # === Fix 16: REMOVED — VEH handles these; trampolines blocked animations ===
    print("Fix 16: Removed (VEH handles ~180K AVs directly)")

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

    # === Fix 19: Bounds-check spell handler default array lookup ===
    if 19 not in skip:
        # Redirect ja at 0x5C872E to the code cave trampoline
        off = va_to_offset(FIX19_JA_VA)
        assert data[off:off + 2] == b'\x0f\x87', \
            f"Expected ja at {FIX19_JA_VA:#x}, got {data[off:off+2].hex()}"
        new_rel32 = fix19_va - (FIX19_JA_VA + 6)
        data[off + 2:off + 6] = struct.pack('<i', new_rel32)
        print(f"Fix 19: Spell handler bounds check at {FIX19_JA_VA:#010x}")
    else:
        print("Fix 19: SKIPPED")

    # === Fix 20: Validate vtable in LH3DMesh pack index function ===
    if 20 not in skip:
        # Replace function entry with jmp to code cave trampoline
        off = va_to_offset(FIX20_FUNC_VA)
        assert data[off:off + 2] == b'\x8b\x01', \
            f"Expected mov eax,[ecx] at {FIX20_FUNC_VA:#x}, got {data[off:off+2].hex()}"
        data[off:off + FIX20_FUNC_SIZE] = encode_jmp(FIX20_FUNC_VA, fix20_va)
        print(f"Fix 20: Vtable validation at {FIX20_FUNC_VA:#010x}")
    else:
        print("Fix 20: SKIPPED")

    # === Fix 22: REMOVED — 0x83ADD0 confirmed not cause of cubes ===
    print("Fix 22: Removed (not the cause of cube rendering)")

    # === Fix 23: REMOVED — zeroed ALL blend weights globally, not just invalid ones ===
    print("Fix 23: Removed (too aggressive — disabled all morph animation blending)")

    # === Write output ===
    args.output.write_bytes(data)
    print(f"Output MD5: {hashlib.md5(data).hexdigest()}")
    print(f"Wrote {args.output}")


if __name__ == "__main__":
    main()

// Creature AI support functions (global constructors)
// Extracted from runblack.reassemble.0253.004af640-004c4ab0.asm
// Address range: [0x004c48f0, 0x004c4970)

#include "Creature.h"
#include <stdint.h>

extern char rdata_bytes[] asm("rdata_bytes");
extern char data_bytes[] asm("data_bytes");
extern uint8_t DAT_00fac934 asm("_DAT_00fac934");

// ============================================================================
// globl_ct_0x004c48f0: once-guard + atexit registration
// ============================================================================

__attribute__((no_callee_saves, crt_guard_pattern, TestRev, OR32rr_REV, no_branch_threading, expand_movzx))
void __cdecl globl_ct_0x004c48f0(void)
{
    extern void __cdecl __opaque_crt_register(void) asm("_crt_global_destruction_register_0x004c4910");
    if (!(DAT_00fac934 & 1)) {
        DAT_00fac934 |= 1;
    }
    __attribute__((musttail)) return __opaque_crt_register();
}

__attribute__((prefer_pop_cleanup))
void __cdecl crt_global_destruction_register_0x004c4910(void)
{
    extern int __cdecl atexit(void (*)(void));
    atexit((void (*)(void))0x00407870);
}

// ============================================================================
// globl_ct_0x004c4920: jmp to fld*fmul*fstp (float multiply + store)
// ============================================================================

extern void __cdecl FUN_004c4930__8CreatureFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x004c4920(void)
{
    __attribute__((musttail)) return FUN_004c4930__8CreatureFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_004c4930__8CreatureFv(void)
{
    *(float*)(data_bytes + 0x2bc644) = *(float*)(rdata_bytes + 0x26358) * *(float*)(rdata_bytes + 0x26354);
}

// ============================================================================
// globl_ct_0x004c4950: jmp to mov [mem], -1 (set to 0xffffffff)
// ============================================================================

extern void __cdecl FUN_004c4960__8CreatureFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x004c4950(void)
{
    __attribute__((musttail)) return FUN_004c4960__8CreatureFv();
}

__attribute__((trailing_asm("call ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9")))
void __cdecl FUN_004c4960__8CreatureFv(void)
{
    *(uint32_t*)(data_bytes + 0x2bc640) = 0xffffffff;
}

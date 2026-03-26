// Creature AI support functions (global constructors)
// Extracted from runblack.reassemble.0253.004af640-004c4ab0.asm
// Address range: [0x004c48f0, 0x004c4970)

#include "Creature.h"
#include <stdint.h>

extern char rdata_bytes[];
extern char data_bytes[];
extern uint8_t _DAT_00fac934;

// ============================================================================
// globl_ct_0x004c48f0: once-guard + atexit registration
// ============================================================================

__attribute__((no_ret))
void __cdecl globl_ct_0x004c48f0(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x004c4904\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x004c4904:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x004c4910"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
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

void __cdecl FUN_004c4930__8CreatureFv(void)
{
    asm volatile (
        "%{disp32%} fld       dword ptr [rdata_bytes + 0x26358]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x26354]\n\t"
        "%{disp32%} fstp      dword ptr [data_bytes + 0x2bc644]"
        ::: "memory"
    );
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
    asm volatile (
        "%{disp32%} mov       dword ptr [data_bytes + 0x2bc640], 0xffffffff"
        ::: "memory"
    );
}

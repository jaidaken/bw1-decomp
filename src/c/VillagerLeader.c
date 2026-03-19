#include "Villager.h"

const float villager_leader_float1000p0_0x0099a9ac = 1000.0f;
const float villager_leader_num_days_in_year_0x0099a9b0 = 365.25f;
const float villager_leader_seconds_in_day_0x0099a9b4 = 86400.0f;

float villager_leader_seconds_in_year_0x00db9e20;

__attribute__((no_ret))
void __cdecl globl_ct_0x00762680(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x00762694\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x00762694:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x007626a0"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

void __cdecl crt_global_destruction_register_0x007626a0(void)
{
    asm volatile (
        "push               0x00407870\n\t"
        "call               _atexit\n\t"
        "pop                ecx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

extern void __cdecl FUN_007626c0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x007626b0(void)
{
    __attribute__((musttail)) return FUN_007626c0__8VillagerFv();
}

void __cdecl FUN_007626c0__8VillagerFv(void)
{
    asm volatile (
        "%{disp32%} fld  dword ptr [_villager_leader_seconds_in_day_0x0099a9b4]\n\t"
        "%{disp32%} fmul dword ptr [_villager_leader_num_days_in_year_0x0099a9b0]\n\t"
        "%{disp32%} fstp dword ptr [_villager_leader_seconds_in_year_0x00db9e20]"
        ::: "memory"
    );
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CheckLeaderNeeded__8VillagerFv(struct Villager* this)
{
    return 0;
}

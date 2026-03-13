#include "Villager.h"

const float villager_trader_num_days_in_year_0x0099aa50 = 365.25f;
const float villager_trader_seconds_in_day_0x0099aa54 = 86400.0f;
const float villager_trader_float0p7_0x0099aa58 = 0.7f;

uint32_t villager_trader_uint_0x00dcb160;
uint32_t villager_trader_uint_0x00dcb164;
float villager_trader_seconds_in_year_0x00dcb168;


void __cdecl globl_ct_0x0076b920(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x0076b934\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x0076b934:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x0076b940"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

void __cdecl crt_global_destruction_register_0x0076b940(void)
{
    asm volatile (
        "push               0x00407870\n\t"
        "call               _atexit\n\t"
        "pop                ecx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

extern void __cdecl FUN_0076b960__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x0076b950(void)
{
    __attribute__((musttail)) return FUN_0076b960__8VillagerFv();
}

void __cdecl FUN_0076b960__8VillagerFv(void)
{
    asm volatile (
        "%{disp32%} fld  dword ptr [_villager_trader_seconds_in_day_0x0099aa54]\n\t"
        "%{disp32%} fmul dword ptr [_villager_trader_num_days_in_year_0x0099aa50]\n\t"
        "%{disp32%} fstp dword ptr [_villager_trader_seconds_in_year_0x00dcb168]"
        ::: "memory"
    );
}

bool32_t __fastcall ArrivesInAbodeToPickUpExcess__8VillagerFv(struct Villager* this)
{
    return 1;
}

bool32_t __fastcall ArrivesInAbodeToTrade__8VillagerFv(struct Villager* this)
{
    return 1;
}

void __fastcall SetupFoodForWoodTrade__8VillagerFl(struct Villager* this, const void* edx, long param_1)
{
    return;
}

bool32_t __fastcall ExcessFood__8VillagerFv(struct Villager* this)
{
    return 1;
}

void __fastcall SetupWoodForFoodTrade__8VillagerFl(struct Villager* this, const void* edx, long param_1)
{
    return;
}

bool32_t __fastcall ExcessWood__8VillagerFv(struct Villager* this)
{
    return 1;
}

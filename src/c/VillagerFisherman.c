#include "Villager.h"

const float villager_fisherman_num_days_in_year_0x0099a970 = 365.25f;
const float villager_fisherman_seconds_in_day_0x0099a974 = 86400.0f;

char s_VillagerFisherman_cpp[] = "C:\\dev\\MP\\Black\\VillagerFisherman.cpp";

float villager_fisherman_seconds_in_year_0x00db9e04;

void __cdecl globl_ct_0x0075b460(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x0075b474\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x0075b474:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x0075b480"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

void __cdecl crt_global_destruction_register_0x0075b480(void)
{
    asm volatile (
        "push               0x00407870\n\t"
        "call               _atexit\n\t"
        "pop                ecx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

extern void __cdecl FUN_0075b4a0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x0075b490(void)
{
    __attribute__((musttail)) return FUN_0075b4a0__8VillagerFv();
}

void __cdecl FUN_0075b4a0__8VillagerFv(void)
{
    asm volatile (
        "%{disp32%} fld  dword ptr [_villager_fisherman_seconds_in_day_0x0099a974]\n\t"
        "%{disp32%} fmul dword ptr [_villager_fisherman_num_days_in_year_0x0099a970]\n\t"
        "%{disp32%} fstp dword ptr [_villager_fisherman_seconds_in_year_0x00db9e04]"
        ::: "memory"
    );
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall FishermanLookForWater__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075b4fd\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x04]\n\t"
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], 0x00000000\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x0073e750\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075b4fd\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?VillagerBecomesFisherman@Villager@@QAEIPAVFishFarm@@@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x0075b4fd:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall VillagerBecomesFisherman__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?FishermanLookForWater@Villager@@QAEIXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b550\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000118]\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x04]\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x0052c870\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000118]\n\t"
        "push               0x37\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n\t"
        "neg                eax\n\t"
        "sbb.s              eax, eax\n\t"
        "neg                eax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x0075b550:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall VillagerBecomesFisherman__8VillagerFP8FishFarm(struct Villager* this, const void* edx, struct FishFarm* param_1)
{
    asm volatile (
        "sub                esp, 0x18\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x20]\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x10]\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], ecx\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "push               eax\n\t"
        "call               dword ptr [edx + 0x104]\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000118]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], edx\n\t"
        "%{disp8%} fld        dword ptr [eax + 0x08]\n\t"
        "push               0x37\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x18]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x18\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

bool32_t __fastcall FishermanArrivesAtFishing__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "%{disp32%} mov       edi, dword ptr [esi + 0x00000118]\n\t"
        "call               ?IsAtValidFishingPos@Villager@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b60f\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x104]\n\t"
        "push               0x37\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x0c]\n\t"
        "push               edx\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x0075b60f:\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x104]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "call               @__eq__9MapCoordsCFRC9MapCoords@12\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075b64e\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x08]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x0052c870\n\t"
        "push               0x37\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupMoveToPos@Villager@@QAE_NABUMapCoords@@W4VILLAGER_STATES@@@Z\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x0075b64e:\n\t"
        "push               0x1\n\t"
        "push               0x38\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PlayAnimThenSetState@Living@@QAEXEK@Z\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsAtValidFishingPos__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00000118]\n\t"
        "%{disp8%} mov        dx, word ptr [ecx + 0x16]\n\t"
        "cmp                dx, word ptr [eax + 0x16]\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b690\n\t"
        "%{disp8%} mov        cx, word ptr [ecx + 0x1a]\n\t"
        "cmp                cx, word ptr [eax + 0x1a]\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b690\n\t"
        "mov                eax, 0x00000001\n\t"
        "ret\n"
        "LAB__addr_0x0075b690:\n\t"
        "xor.s              eax, eax\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall Fishing__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "sub                esp, 0x1c\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               0x1\n\t"
        "call               @IsReadyForNewAnimation__6LivingFUl@12\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0075b80d\n\t"
        "xor.s              edi, edi\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000090], di\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000118]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00000084]\n\t"
        "push               0x62\n\t"
        "push               0x00c23750\n\t"
        "push               eax\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], edi\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x18]\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x40\n\t"
        "%{disp32%} je        LAB__addr_0x0075b80d\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       edx, dword ptr [ecx + 0x00000264]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edi\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x0c]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x3f800000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], 0x3f666666\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x23d4]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], 0x3f333333\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], 0x3f19999a\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n\t"
        "call               ?GetFoodCapacity@Villager@@QAEHXZ\n\t"
        "movsx              eax, ax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], eax\n\t"
        "mov                ecx, OFFSET _GGameInfo_00d019f8\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "call               ?GetSeason@GGameInfo@@QAEIXZ\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "%{disp8%} fmul       dword ptr [esp + eax * 0x4 + 0x14]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x0c]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b77e\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFoodCapacity@Villager@@QAEHXZ\n\t"
        "movsx              ecx, ax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075b790\n"
        "LAB__addr_0x0075b77e:\n\t"
        "mov                ecx, OFFSET _GGameInfo_00d019f8\n\t"
        "call               ?GetSeason@GGameInfo@@QAEIXZ\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "%{disp8%} fmul       dword ptr [esp + eax * 0x4 + 0x14]\n"
        "LAB__addr_0x0075b790:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n\t"
        "push               0x7\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x6c8]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x08]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edi\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x0c]\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x08]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x40\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b7d7\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "mov.s              ecx, esi\n\t"
        "push               eax\n\t"
        "call               ?PickupFood@Villager@@QAEXF@Z\n"
        "LAB__addr_0x0075b7d7:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFoodCapacity@Villager@@QAEHXZ\n\t"
        "movsx              eax, ax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], eax\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x08]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b800\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFoodCapacity@Villager@@QAEHXZ\n\t"
        "test               ax, ax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b80d\n"
        "LAB__addr_0x0075b800:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GotoStoragePitForDropOff@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x1c\n\t"
        "ret\n"
        "LAB__addr_0x0075b80d:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x1c\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

bool32_t __fastcall EnterFishing__8VillagerFUcUc(struct Villager* this, const void* edx, unsigned char param_1, unsigned char param_2)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "and                eax, 0x000000ff\n\t"
        "and                ecx, 0x000000ff\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsStateEntryFunctionSameAs@Villager@@QBEIKK@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b86f\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075b86f\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000118]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00000080]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075b869\n"
        "LAB__addr_0x0075b85e:\n\t"
        "cmp                dword ptr [eax + 0x04], esi\n\t"
        "%{disp8%} je         LAB__addr_0x0075b86f\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b85e\n"
        "LAB__addr_0x0075b869:\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x0052d250\n"
        "LAB__addr_0x0075b86f:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0008"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

bool32_t __fastcall ExitFishing__8VillagerFUc(struct Villager* this, const void* edx, unsigned char param_1)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "and                ecx, 0x000000ff\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x96c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b8cc\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000118]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075b8c2\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075b8c2\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000118]\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x0052d290\n"
        "LAB__addr_0x0075b8c2:\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], 0x00000000\n"
        "LAB__addr_0x0075b8cc:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

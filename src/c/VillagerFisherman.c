#include "Villager.h"

const float villager_fisherman_num_days_in_year_0x0099a970 = 365.25f;
const float villager_fisherman_seconds_in_day_0x0099a974 = 86400.0f;

char s_VillagerFisherman_cpp[] = "C:\\dev\\MP\\Black\\VillagerFisherman.cpp";

float villager_fisherman_seconds_in_year_0x00db9e04;

__attribute__((no_ret))
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

__attribute__((prefer_pop_cleanup))
void __cdecl crt_global_destruction_register_0x0075b480(void)
{
    extern int __cdecl atexit(void (*)(void));
    atexit((void (*)(void))0x00407870);
}

extern void __cdecl FUN_0075b4a0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x0075b490(void)
{
    __attribute__((musttail)) return FUN_0075b4a0__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_0075b4a0__8VillagerFv(void)
{
    extern float __opaque_a asm("_villager_fisherman_seconds_in_day_0x0099a974");
    extern float __opaque_b asm("_villager_fisherman_num_days_in_year_0x0099a970");
    extern float __opaque_c asm("_villager_fisherman_seconds_in_year_0x00db9e04");
    __opaque_c = __opaque_a * __opaque_b;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall FishermanLookForWater__8VillagerFv(struct Villager* this)
{
    bool32_t result;
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
        "pop                ecx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall VillagerBecomesFisherman__8VillagerFv(struct Villager* this)
{
    bool32_t result;
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
        "add                esp, 0x0c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall VillagerBecomesFisherman__8VillagerFP8FishFarm(struct Villager* this, const void* edx, struct FishFarm* param_1)
{
    bool32_t result;
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
        "add                esp, 0x18"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall FishermanArrivesAtFishing__8VillagerFv(struct Villager* this)
{
    bool32_t result;
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
        "add                esp, 0x0c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall IsAtValidFishingPos__8VillagerFv(struct Villager* this)
{
    bool32_t result;
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
        "xor.s              eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall Fishing__8VillagerFv(struct Villager* this)
{
    bool32_t result;
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
        "add                esp, 0x1c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall EnterFishing__8VillagerFUcUc(struct Villager* this, const void* edx, unsigned char param_1, unsigned char param_2)
{
    bool32_t result;
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
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((forced_callee_saves("esi"), force_this_esi, MOV32rr_REV, prefer_push_before_ecx))
bool32_t __fastcall ExitFishing__8VillagerFUc(struct Villager* this, const void* edx, unsigned char param_1)
{
    /* Use asm for param load + first vtable call to match MSVC encoding */
    int first_call_result;
    asm volatile (
        "%{disp8%} mov ecx, dword ptr [esp + 0x08]\n\t"
        "mov eax, dword ptr [esi]\n\t"
        "and ecx, 0x000000ff\n\t"
        "push ecx\n\t"
        "mov.s ecx, esi\n\t"
        "call dword ptr [eax + 0x96c]"
        : "=a"(first_call_result) : "S"(this) : "ecx", "edx", "memory"
    );
    if (__builtin_expect(first_call_result != 0, 0)) goto done;
    {
        void* fish_farm = *(void**)((char*)this + 0x118);
        if (fish_farm) {
            register void* ff_vt asm("edx") = *(void**)fish_farm;
            asm volatile ("" :: "r"(ff_vt));
            typedef uint32_t (__attribute__((thiscall)) *fn_2c_t)(void*);
            fn_2c_t fn1 = ((fn_2c_t*)ff_vt)[0x2c / 4];
            if (fn1(fish_farm)) {
                typedef uint32_t (__attribute__((thiscall)) *fn_48_t)(struct Villager*);
                fn_48_t fn2 = ((fn_48_t*)(*(void**)this))[0x48 / 4];
                fn2(this);
                void* ff2 = *(void**)((char*)this + 0x118);
                extern void __attribute__((thiscall)) __opaque_RemoveFisherman(void*, struct Villager*) asm("_jmp_addr_0x0052d290");
                __opaque_RemoveFisherman(ff2, this);
            }
        }
        *(uint32_t*)((char*)this + 0x118) = 0;
    }
done:
    return 1;
}

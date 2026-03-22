#include "Villager.h"

const float villager_fireman_num_days_in_year_0x0099a960 = 365.25f;
const float villager_fireman_seconds_in_day_0x0099a964 = 86400.0f;
const float villager_fireman_m8p0_0x0099a968 = -8.0f;
const float villager_fireman_point_to_coord_0x0099a96c = 6553.6f;

char s_VillagerFireman_cpp[] = "C:\\dev\\MP\\Black\\VillagerFireman.cpp";

float villager_fireman_seconds_in_year_0x00db9e00;

__attribute__((no_ret))
void __cdecl globl_ct_0x0075a370(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x0075a384\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x0075a384:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x0075a390"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((prefer_pop_cleanup))
void __cdecl crt_global_destruction_register_0x0075a390(void)
{
    extern int __cdecl atexit(void (*)(void));
    atexit((void (*)(void))0x00407870);
}

extern void __cdecl FUN_0075a3b0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x0075a3a0(void)
{
    __attribute__((musttail)) return FUN_0075a3b0__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_0075a3b0__8VillagerFv(void)
{
    extern float __opaque_a asm("_villager_fireman_seconds_in_day_0x0099a964");
    extern float __opaque_b asm("_villager_fireman_num_days_in_year_0x0099a960");
    extern float __opaque_c asm("_villager_fireman_seconds_in_year_0x00db9e00");
    __opaque_c = __opaque_a * __opaque_b;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall DecideHowToPutOutFire__8VillagerFP10FireEffect(struct Villager* this, const void* edx, struct FireEffect* param_1)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x14]\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n\t"
        "push               eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x00000000\n\t"
        "call               _jmp_addr_0x00730070\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000114], eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075a433\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x04]\n\t"
        "push               ecx\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFireFightingPos@Villager@@QAEIPAVFireEffect@@PAUMapCoords@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075a433\n\t"
        "push               0x000000d8\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x08]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupMoveAroundFire@Villager@@QAEIABUMapCoords@@W4VILLAGER_STATES@@@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0075a433:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x00)))
float __stdcall GetViaPoint__FRC9MapCoordsRC9MapCoordsRC9MapCoordsfR9MapCoordsfPbPbf(const struct MapCoords* param_1, const struct MapCoords* param_2, const struct MapCoords* param_3, float param_4, struct MapCoords* param_5, float param_6, bool* param_7, bool* param_8, float param_9)
{
    float result;
    asm volatile (
        "%{disp8%} fld        dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x20]\n\t"
        "%{disp32%} fmul      dword ptr [_villager_fireman_point_to_coord_0x0099a96c]\n\t"
        "sub                esp, 0x14\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x24]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x2c]\n\t"
        "%{disp32%} fmul      dword ptr [_villager_fireman_point_to_coord_0x0099a96c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} je         LAB__addr_0x0075a46a\n\t"
        "mov                byte ptr [eax], 0x00\n"
        "LAB__addr_0x0075a46a:\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "%{disp8%} mov        ebp, dword ptr [esp + 0x38]\n\t"
        "test               ebp, ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} je         LAB__addr_0x0075a47a\n\t"
        "%{disp8%} mov        byte ptr [ebp + 0x00], 0x00\n"
        "LAB__addr_0x0075a47a:\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x30]\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x28]\n\t"
        "mov                ecx, dword ptr [edi]\n\t"
        "mov                edx, dword ptr [ebx]\n\t"
        "%{disp8%} mov        esi, dword ptr [ebx + 0x04]\n\t"
        "mov.s              eax, ecx\n\t"
        "sub.s              eax, edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x40], eax\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x40]\n\t"
        "%{disp8%} mov        eax, dword ptr [edi + 0x04]\n\t"
        "sub.s              eax, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x40], eax\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x40]\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x40]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x40]\n\t"
        "fld                st(1)\n\t"
        "fmul               st, st(2)\n\t"
        "faddp              st(1), st\n\t"
        "fsqrt\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x14]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x34]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} je         LAB__addr_0x0075a4e0\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x44]\n\t"
        "fstp               st(0)\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0075a74f\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float0p0]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                byte ptr [eax], 0x01\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x14\n\t"
        "ret\n"
        "LAB__addr_0x0075a4e0:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x34]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x3c]\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "sub.s              eax, edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "%{disp8%} fdiv       dword ptr [esp + 0x14]\n\t"
        "%{disp8%} mov        eax, dword ptr [edx + 0x04]\n\t"
        "sub.s              eax, esi\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x30]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x30]\n\t"
        "%{disp32%} fsubr     dword ptr [_rdata_float1p0]\n\t"
        "fsqrt\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x28]\n\t"
        "%{disp8%} fdiv       dword ptr [esp + 0x14]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x3c]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x40]\n\t"
        "%{disp8%} fdiv       dword ptr [esp + 0x14]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x40]\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x18]\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x18]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x18]\n\t"
        "fld                st(1)\n\t"
        "fmul               st, st(2)\n\t"
        "faddp              st(1), st\n\t"
        "fsqrt\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x14]\n\t"
        "%{disp32%} fcomp     dword ptr [rdata_bytes + 0x16518]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp32%} jne       LAB__addr_0x0075a74d\n\t"
        "%{disp8%} fdiv       dword ptr [esp + 0x14]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "%{disp8%} fdiv       dword ptr [esp + 0x14]\n\t"
        "fld                st(0)\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x40]\n\t"
        "fld                st(2)\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x3c]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x18]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x28]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} je         LAB__addr_0x0075a599\n\t"
        "pop                edi\n\t"
        "fstp               st(0)\n\t"
        "pop                esi\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float0p0]\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x14\n\t"
        "ret\n"
        "LAB__addr_0x0075a599:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x3c]\n\t"
        "fchs\n\t"
        "fmul               st, st(1)\n\t"
        "fxch               st(2)\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x40]\n\t"
        "faddp              st(2), st\n\t"
        "fxch               st(1)\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "fstp               st(0)\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075a5cb\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x48]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x0075a5dc\n"
        "LAB__addr_0x0075a5cb:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x48]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075a651\n"
        "LAB__addr_0x0075a5dc:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x28]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ecx\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x40]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], 0x00000000\n\t"
        "fchs\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x30]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x3c]\n\t"
        "fsubp              st(1), st\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} fiadd      dword ptr [esp + 0x1c]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x28]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x3c]\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x38]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x30]\n\t"
        "mov                dword ptr [esi], eax\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x40]\n\t"
        "%{disp8%} mov        ecx, dword ptr [edi + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], 0x00000000\n\t"
        "fsubp              st(1), st\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} fiadd      dword ptr [esp + 0x1c]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x04], eax\n\t"
        "call               __CIacos\n\t"
        "fchs\n\t"
        "test               ebp, ebp\n\t"
        "%{disp8%} je         LAB__addr_0x0075a6c6\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075a6c2\n"
        "LAB__addr_0x0075a651:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x28]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ecx\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x40]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], 0x00000000\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x30]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x3c]\n\t"
        "fsubp              st(1), st\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} fiadd      dword ptr [esp + 0x1c]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x28]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x3c]\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x38]\n\t"
        "mov                dword ptr [esi], eax\n\t"
        "%{disp8%} mov        edx, dword ptr [edi + 0x04]\n\t"
        "fchs\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], edx\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x30]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], 0x00000000\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x40]\n\t"
        "fsubp              st(1), st\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} fiadd      dword ptr [esp + 0x1c]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x04], eax\n\t"
        "call               __CIacos\n\t"
        "test               ebp, ebp\n\t"
        "%{disp8%} je         LAB__addr_0x0075a6c6\n"
        "LAB__addr_0x0075a6c2:\n\t"
        "%{disp8%} mov        byte ptr [ebp + 0x00], 0x01\n"
        "LAB__addr_0x0075a6c6:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x2c]\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "sub                ecx, dword ptr [edi]\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        eax, dword ptr [edi + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x3c], ecx\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x3c]\n\t"
        "sub.s              edx, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x3c], edx\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x3c]\n\t"
        "fld                st(0)\n\t"
        "fmul               st, st(1)\n\t"
        "fld                st(2)\n\t"
        "fmul               st, st(3)\n\t"
        "faddp              st(1), st\n\t"
        "fsqrt\n\t"
        "fstp               st(2)\n\t"
        "fstp               st(0)\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x34]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075a714\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x44]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075a755\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                byte ptr [eax], 0x01\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x14\n\t"
        "ret\n"
        "LAB__addr_0x0075a714:\n\t"
        "mov                ecx, dword ptr [ebx]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "sub.s              eax, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x34], eax\n\t"
        "%{disp8%} mov        eax, dword ptr [ebx + 0x04]\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x34]\n\t"
        "sub.s              ecx, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x34], ecx\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x34]\n\t"
        "fld                st(0)\n\t"
        "fmul               st, st(1)\n\t"
        "fld                st(2)\n\t"
        "fmul               st, st(3)\n\t"
        "faddp              st(1), st\n\t"
        "fsqrt\n\t"
        "fstp               st(2)\n\t"
        "fstp               st(0)\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x14]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0075a755\n"
        "LAB__addr_0x0075a74d:\n\t"
        "fstp               st(0)\n"
        "LAB__addr_0x0075a74f:\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float0p0]\n"
        "LAB__addr_0x0075a755:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x14"
        : "=t"(result) :: "eax", "ecx", "edx", "memory"
    );
    return result;
}

void FUN_0075a760__8VillagerFv(void)
{
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall SetupMoveAroundFire__8VillagerFRC9MapCoords15VILLAGER_STATES(struct Villager* this, const void* edx, const struct MapCoords* param_1, enum VILLAGER_STATES param_2)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000dc\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0075a7d7\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "push               edi\n\t"
        "push               ecx\n\t"
        "%{disp32%} lea       ecx, dword ptr [esi + 0x0000010c]\n\t"
        "call               ?Init@JustWholeMapXZ@@QAEXABUMapCoords@@@Z\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x10]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "push               0x2\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x938]\n\t"
        "cmp                edi, 0x3b\n\t"
        "pop                edi\n\t"
        "%{disp8%} jne        LAB__addr_0x0075a7ce\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075a7ce\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x0073e300\n\t"
        "or                 byte ptr [esi + 0xe0], 0x10\n"
        "LAB__addr_0x0075a7ce:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x0075a7d7:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
uint32_t __fastcall MoveAroundFire__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x28\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} lea       eax, dword ptr [esi + 0x0000010c]\n\t"
        "push               edi\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x24]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], eax\n\t"
        "call               _jmp_addr_0x00603030\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "xor.s              ebx, ebx\n\t"
        "push               ebx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x24]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x85c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075a839\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PopFromPrevious@Villager@@QAEXXZ\n\t"
        "push               0x000000a3\n\t"
        "push               0x2\n\t"
        "%{disp32%} lea       ecx, dword ptr [esi + 0x0000008c]\n\t"
        "call               @SetState__12LivingActionFUlUc@16\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x28\n\t"
        "ret\n"
        "LAB__addr_0x0075a839:\n\t"
        "%{disp32%} mov       ebp, dword ptr [esi + 0x00000114]\n\t"
        "cmp.s              ebp, ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], ebx\n\t"
        "%{disp32%} je        LAB__addr_0x0075aa79\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               _jmp_addr_0x007305f0\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0075aa79\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x20]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x24]\n\t"
        "%{disp32%} lea       edi, dword ptr [esi + 0x00000080]\n\t"
        "mov.s              edx, edi\n\t"
        "mov                dword ptr [edx], eax\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x28]\n\t"
        "%{disp8%} mov        dword ptr [edx + 0x04], ecx\n\t"
        "push               ebx\n\t"
        "%{disp8%} mov        dword ptr [edx + 0x08], eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x16]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x19]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x1d], bl\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x1e], bl\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x1f], bl\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x38], ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x3c], ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x40], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], 0x00000000\n\t"
        "call               dword ptr [eax + 0x64]\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float1p0]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x3c]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               _jmp_addr_0x00730020\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, ebp\n\t"
        "fstp               dword ptr [esp]\n\t"
        "call               _jmp_addr_0x007305f0\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x860]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n\t"
        "push               eax\n\t"
        "call               ?GetViaPoint@@YGMABUMapCoords@@00MAAU1@MPA_N2M@Z\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float0p0]\n\t"
        "add                esp, 0x24\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x40\n\t"
        "%{disp8%} jne        LAB__addr_0x0075a918\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x30]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x34]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], edx\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x13], 0x01\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075a91a\n"
        "LAB__addr_0x0075a918:\n\t"
        "fstp               st(0)\n"
        "LAB__addr_0x0075a91a:\n\t"
        "cmp                byte ptr [esp + 0x11], bl\n\t"
        "%{disp8%} je         LAB__addr_0x0075a966\n\t"
        "cmp                byte ptr [esp + 0x12], bl\n\t"
        "%{disp8%} je         LAB__addr_0x0075a966\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "push               0x2\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x938]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x20]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x24]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x28]\n\t"
        "mov                dword ptr [edi], ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x20]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x20]\n\t"
        "%{disp8%} mov        dword ptr [edi + 0x04], edx\n\t"
        "%{disp8%} mov        dword ptr [edi + 0x08], eax\n\t"
        "call               ?Init@JustWholeMapXZ@@QAEXABUMapCoords@@@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x28\n\t"
        "ret\n"
        "LAB__addr_0x0075a966:\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               ?GetFirstCaused@FireEffect@@QAEIXZ\n\t"
        "mov.s              edi, eax\n\t"
        "cmp.s              edi, ebx\n\t"
        "%{disp32%} je        LAB__addr_0x0075aa33\n"
        "LAB__addr_0x0075a977:\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x14]\n\t"
        "push               edx\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x16]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x19]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x1d], bl\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x1e], bl\n\t"
        "call               dword ptr [edx + 0x64]\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float1p0]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x3c]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x00730020\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "fstp               dword ptr [esp]\n\t"
        "call               _jmp_addr_0x007305f0\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x3c]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n\t"
        "push               eax\n\t"
        "call               ?GetViaPoint@@YGMABUMapCoords@@00MAAU1@MPA_N2M@Z\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float0p0]\n\t"
        "add                esp, 0x24\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x40\n\t"
        "%{disp8%} je         LAB__addr_0x0075a9f1\n\t"
        "cmp                byte ptr [esp + 0x11], bl\n\t"
        "%{disp8%} je         LAB__addr_0x0075a9e4\n\t"
        "cmp                byte ptr [esp + 0x12], bl\n\t"
        "%{disp8%} jne        LAB__addr_0x0075a9f1\n"
        "LAB__addr_0x0075a9e4:\n\t"
        "mov.s              ecx, edi\n\t"
        "fstp               st(0)\n\t"
        "call               _jmp_addr_0x00732ad0\n\t"
        "mov.s              edi, eax\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075aa2b\n"
        "LAB__addr_0x0075a9f1:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x34]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x30]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], eax\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x13], 0x01\n\t"
        "call               ?GetFirstCaused@FireEffect@@QAEIXZ\n\t"
        "mov.s              edi, eax\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x18]\n\t"
        "inc                eax\n\t"
        "cmp                eax, 0x000003e8\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "%{disp8%} jae        LAB__addr_0x0075aa79\n"
        "LAB__addr_0x0075aa2b:\n\t"
        "cmp.s              edi, ebx\n\t"
        "%{disp32%} jne       LAB__addr_0x0075a977\n"
        "LAB__addr_0x0075aa33:\n\t"
        "cmp                byte ptr [esp + 0x13], bl\n\t"
        "%{disp8%} jne        LAB__addr_0x0075aa47\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x1c]\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x24]\n\t"
        "call               _jmp_addr_0x00603260\n"
        "LAB__addr_0x0075aa47:\n\t"
        "push               0x000000dc\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x24]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075aa79\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x0000008e]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetStateSpeed@Villager@@QAEXE@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x28\n\t"
        "ret\n"
        "LAB__addr_0x0075aa79:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x28"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall GetFireFightingPos__8VillagerFP10FireEffectP9MapCoords(struct Villager* this, const void* edx, struct FireEffect* param_1, struct MapCoords* param_2)
{
    asm("sub                esp, 0x28");                                     // 0x0075aa90    83ec28
    asm("push               ebx");                                           // 0x0075aa93    53
    asm("push               esi");                                           // 0x0075aa94    56
    asm("push               edi");                                           // 0x0075aa95    57
    asm("{disp8} mov        edi, dword ptr [esp + 0x38]");                   // 0x0075aa96    8b7c2438
    asm("test               edi, edi");                                      // 0x0075aa9a    85ff
    asm("mov.s              ebx, ecx");                                      // 0x0075aa9c    8bd9
    asm("{disp32} je        LAB__addr_0x0075ab91");                          // 0x0075aa9e    0f84ed000000
    asm("mov.s              ecx, edi");                                      // 0x0075aaa4    8bcf
    asm("call               _jmp_addr_0x007305f0");                          // 0x0075aaa6    e8455bfdff
    asm("mov.s              esi, eax");                                      // 0x0075aaab    8bf0
    asm("test               esi, esi");                                      // 0x0075aaad    85f6
    asm("{disp32} je        LAB__addr_0x0075ab91");                          // 0x0075aaaf    0f84dc000000
    asm("{disp8} lea        eax, dword ptr [esp + 0x10]");                   // 0x0075aab5    8d442410
    asm("push               eax");                                           // 0x0075aab9    50
    asm("mov.s              ecx, edi");                                      // 0x0075aaba    8bcf
    asm("{disp8} mov        dword ptr [esp + 0x14], 0x00000000");            // 0x0075aabc    c744241400000000
    asm("{disp8} mov        dword ptr [esp + 0x18], 0x00000000");            // 0x0075aac4    c744241800000000
    asm("{disp8} mov        dword ptr [esp + 0x1c], 0x00000000");            // 0x0075aacc    c744241c00000000
    asm("call               _jmp_addr_0x0072fef0");                          // 0x0075aad4    e81754fdff
    asm("{disp8} lea        ecx, dword ptr [ebx + 0x14]");                   // 0x0075aad9    8d4b14
    asm("push               ecx");                                           // 0x0075aadc    51
    asm("{disp8} lea        edx, dword ptr [esp + 0x14]");                   // 0x0075aadd    8d542414
    asm("push               edx");                                           // 0x0075aae1    52
    asm("call               ?Get3DAngleFromXZ@GUtils@@SAMABUMapCoords@@0@Z");                               // 0x0075aae2    e88927ffff
    asm("{disp8} fstp       dword ptr [esp + 0x14]");                        // 0x0075aae7    d95c2414
    asm("mov                eax, dword ptr [esi]");                          // 0x0075aaeb    8b06
    asm("add                esp, 0x08");                                     // 0x0075aaed    83c408
    asm("mov.s              ecx, esi");                                      // 0x0075aaf0    8bce
    asm("call               dword ptr [eax + 0x64]");                        // 0x0075aaf2    ff5064
    asm("{disp8} fstp       dword ptr [esp + 0x38]");                        // 0x0075aaf5    d95c2438
    asm("mov.s              ecx, edi");                                      // 0x0075aaf9    8bcf
    asm("call               _jmp_addr_0x00730020");                          // 0x0075aafb    e82055fdff
    asm("{disp8} fcomp      dword ptr [esp + 0x38]");                        // 0x0075ab00    d85c2438
    asm("fnstsw             ax");                                            // 0x0075ab04    dfe0
    asm("test               ah, 0x01");                                      // 0x0075ab06    f6c401
    asm("{disp8} je         LAB__addr_0x0075ab14");                          // 0x0075ab09    7409
    asm("mov                edx, dword ptr [esi]");                          // 0x0075ab0b    8b16
    asm("mov.s              ecx, esi");                                      // 0x0075ab0d    8bce
    asm("call               dword ptr [edx + 0x64]");                        // 0x0075ab0f    ff5264
    asm("{disp8} jmp        LAB__addr_0x0075ab1b");                          // 0x0075ab12    eb07
    asm("LAB__addr_0x0075ab14:");
    asm("mov.s              ecx, edi");                                      // 0x0075ab14    8bcf
    asm("call               _jmp_addr_0x00730020");                          // 0x0075ab16    e80555fdff
    asm("LAB__addr_0x0075ab1b:");
    asm("mov                eax, dword ptr [ebx]");                          // 0x0075ab1b    8b03
    asm("{disp8} fstp       dword ptr [esp + 0x38]");                        // 0x0075ab1d    d95c2438
    asm("mov.s              ecx, ebx");                                      // 0x0075ab21    8bcb
    asm("call               dword ptr [eax + 0x64]");                        // 0x0075ab23    ff5064
    asm("{disp8} fadd       dword ptr [esp + 0x38]");                        // 0x0075ab26    d8442438
    asm("push               0x00000133");                                    // 0x0075ab2a    6833010000
    asm("push               0x00c2372c");                                    // 0x0075ab2f    682c37c200
    asm("{disp8} fstp       dword ptr [esp + 0x40]");                        // 0x0075ab34    d95c2440
    asm("push               0x3f800000");                                    // 0x0075ab38    680000803f
    asm("call               ?GameFloatRand@GRand@@SAMM@Z");                  // 0x0075ab3d    e8ee39f8ff
    asm("{disp8} mov        edx, dword ptr [esp + 0x18]");                   // 0x0075ab42    8b542418
    asm("{disp8} fadd       dword ptr [esp + 0x44]");                        // 0x0075ab46    d8442444
    asm("{disp8} lea        eax, dword ptr [esp + 0x28]");                   // 0x0075ab4a    8d442428
    asm("{disp8} fstp       dword ptr [esp + 0x44]");                        // 0x0075ab4e    d95c2444
    asm("{disp8} mov        ecx, dword ptr [esp + 0x44]");                   // 0x0075ab52    8b4c2444
    asm("push               ecx");                                           // 0x0075ab56    51
    asm("push               edx");                                           // 0x0075ab57    52
    asm("push               eax");                                           // 0x0075ab58    50
    asm("call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z"); // 0x0075ab59    e8222affff
    asm("add                esp, 0x18");                                     // 0x0075ab5e    83c418
    asm("push               eax");                                           // 0x0075ab61    50
    asm("{disp8} lea        ecx, dword ptr [esp + 0x2c]");                   // 0x0075ab62    8d4c242c
    asm("push               ecx");                                           // 0x0075ab66    51
    asm("{disp8} lea        ecx, dword ptr [esi + 0x14]");                   // 0x0075ab67    8d4e14
    asm("call               @__pl__9MapCoordsCFRC9MapCoords@16");            // 0x0075ab6a    e8b1a9eaff
    asm("mov                ecx, dword ptr [eax]");                          // 0x0075ab6f    8b08
    asm("{disp8} mov        edx, dword ptr [esp + 0x3c]");                   // 0x0075ab71    8b54243c
    asm("mov                dword ptr [edx], ecx");                          // 0x0075ab75    890a
    asm("{disp8} mov        ecx, dword ptr [eax + 0x04]");                   // 0x0075ab77    8b4804
    asm("{disp8} mov        dword ptr [edx + 0x04], ecx");                   // 0x0075ab7a    894a04
    asm("{disp8} mov        eax, dword ptr [eax + 0x08]");                   // 0x0075ab7d    8b4008
    asm("pop                edi");                                           // 0x0075ab80    5f
    asm("pop                esi");                                           // 0x0075ab81    5e
    asm("{disp8} mov        dword ptr [edx + 0x08], eax");                   // 0x0075ab82    894208
    asm("mov                eax, 0x00000001");                               // 0x0075ab85    b801000000
    asm("pop                ebx");                                           // 0x0075ab8a    5b
    asm("add                esp, 0x28");                                     // 0x0075ab8b    83c428
    asm("ret                0x0008");                                        // 0x0075ab8e    c20800
    asm("LAB__addr_0x0075ab91:");
    asm("pop                edi");                                           // 0x0075ab91    5f
    asm("pop                esi");                                           // 0x0075ab92    5e
    asm("xor.s              eax, eax");                                      // 0x0075ab93    33c0
    asm("pop                ebx");                                           // 0x0075ab95    5b
    asm("add                esp, 0x28");                                     // 0x0075ab96    83c428
    asm("ret                0x0008");                                        // 0x0075ab99    c20800
    asm("nop");                                                              // 0x0075ab9c    90
    asm("nop");                                                              // 0x0075ab9d    90
    asm("nop");                                                              // 0x0075ab9e    90
    asm("nop");                                                              // 0x0075ab9f    90
    asm("LAB__addr_0x0075aba0:");
    asm("push               ecx");                                           // 0x0075aba0    51
    asm("push               ebx");                                           // 0x0075aba1    53
    asm("push               esi");                                           // 0x0075aba2    56
    asm("push               edi");                                           // 0x0075aba3    57
    asm("{disp8} mov        edi, dword ptr [esp + 0x14]");                   // 0x0075aba4    8b7c2414
    asm("test               edi, edi");                                      // 0x0075aba8    85ff
    asm("mov.s              ebx, ecx");                                      // 0x0075abaa    8bd9
    asm("{disp32} je        LAB__addr_0x0075ac39");                          // 0x0075abac    0f8487000000
    asm("mov.s              ecx, edi");                                      // 0x0075abb2    8bcf
    asm("call               _jmp_addr_0x007305f0");                          // 0x0075abb4    e8375afdff
    asm("mov.s              esi, eax");                                      // 0x0075abb9    8bf0
    asm("test               esi, esi");                                      // 0x0075abbb    85f6
    asm("{disp8} je         LAB__addr_0x0075ac39");                          // 0x0075abbd    747a
    asm("{disp8} lea        eax, dword ptr [esi + 0x14]");                   // 0x0075abbf    8d4614
    asm("push               eax");                                           // 0x0075abc2    50
    asm("{disp8} lea        ecx, dword ptr [ebx + 0x14]");                   // 0x0075abc3    8d4b14
    asm("push               ecx");                                           // 0x0075abc6    51
    asm("call               ?GetDistanceInMetres@GUtils@@SAMABUMapCoords@@0@Z");                               // 0x0075abc7    e8a421ffff
    asm("{disp8} fstp       dword ptr [esp + 0x14]");                        // 0x0075abcc    d95c2414
    asm("mov                edx, dword ptr [esi]");                          // 0x0075abd0    8b16
    asm("add                esp, 0x08");                                     // 0x0075abd2    83c408
    asm("mov.s              ecx, esi");                                      // 0x0075abd5    8bce
    asm("call               dword ptr [edx + 0x64]");                        // 0x0075abd7    ff5264
    asm("{disp8} fstp       dword ptr [esp + 0x14]");                        // 0x0075abda    d95c2414
    asm("mov.s              ecx, edi");                                      // 0x0075abde    8bcf
    asm("call               _jmp_addr_0x00730020");                          // 0x0075abe0    e83b54fdff
    asm("{disp8} fcomp      dword ptr [esp + 0x14]");                        // 0x0075abe5    d85c2414
    asm("fnstsw             ax");                                            // 0x0075abe9    dfe0
    asm("test               ah, 0x01");                                      // 0x0075abeb    f6c401
    asm("{disp8} je         LAB__addr_0x0075abf9");                          // 0x0075abee    7409
    asm("mov                eax, dword ptr [esi]");                          // 0x0075abf0    8b06
    asm("mov.s              ecx, esi");                                      // 0x0075abf2    8bce
    asm("call               dword ptr [eax + 0x64]");                        // 0x0075abf4    ff5064
    asm("{disp8} jmp        LAB__addr_0x0075ac00");                          // 0x0075abf7    eb07
    asm("LAB__addr_0x0075abf9:");
    asm("mov.s              ecx, edi");                                      // 0x0075abf9    8bcf
    asm("call               _jmp_addr_0x00730020");                          // 0x0075abfb    e82054fdff
    asm("LAB__addr_0x0075ac00:");
    asm("mov                edx, dword ptr [ebx]");                          // 0x0075ac00    8b13
    asm("{disp8} fstp       dword ptr [esp + 0x14]");                        // 0x0075ac02    d95c2414
    asm("mov.s              ecx, ebx");                                      // 0x0075ac06    8bcb
    asm("call               dword ptr [edx + 0x64]");                        // 0x0075ac08    ff5264
    asm("{disp8} fadd       dword ptr [esp + 0x14]");                        // 0x0075ac0b    d8442414
    asm("{disp8} fld        dword ptr [esp + 0x0c]");                        // 0x0075ac0f    d944240c
    asm("fcomp              st(1)");                                         // 0x0075ac13    d8d9
    asm("fnstsw             ax");                                            // 0x0075ac15    dfe0
    asm("test               ah, 0x41");                                      // 0x0075ac17    f6c441
    asm("{disp8} jne        LAB__addr_0x0075ac37");                          // 0x0075ac1a    751b
    asm("{disp8} fadd       dword ptr [esp + 0x18]");                        // 0x0075ac1c    d8442418
    asm("{disp8} fcomp      dword ptr [esp + 0x0c]");                        // 0x0075ac20    d85c240c
    asm("fnstsw             ax");                                            // 0x0075ac24    dfe0
    asm("test               ah, 0x41");                                      // 0x0075ac26    f6c441
    asm("{disp8} jne        LAB__addr_0x0075ac39");                          // 0x0075ac29    750e
    asm("pop                edi");                                           // 0x0075ac2b    5f
    asm("pop                esi");                                           // 0x0075ac2c    5e
    asm("mov                eax, 0x00000001");                               // 0x0075ac2d    b801000000
    asm("pop                ebx");                                           // 0x0075ac32    5b
    asm("pop                ecx");                                           // 0x0075ac33    59
    asm("ret                0x0008");                                        // 0x0075ac34    c20800
    asm("LAB__addr_0x0075ac37:");
    asm("fstp               st(0)");                                         // 0x0075ac37    ddd8
    asm("LAB__addr_0x0075ac39:");
    asm("pop                edi");                                           // 0x0075ac39    5f
    asm("pop                esi");                                           // 0x0075ac3a    5e
    asm("xor.s              eax, eax");                                      // 0x0075ac3b    33c0
    asm("pop                ebx");                                           // 0x0075ac3d    5b
    asm("pop                ecx");                                           // 0x0075ac3e    59
}

__attribute__((no_callee_saves))
bool32_t __fastcall PutOutFireByBeating__8VillagerFv(struct Villager* this)
{
    asm("sub                esp, 0x4c");                                     // 0x0075ac50    83ec4c
    asm("push               esi");                                           // 0x0075ac53    56
    asm("mov.s              esi, ecx");                                      // 0x0075ac54    8bf1
    asm("{disp32} mov       eax, dword ptr [esi + 0x00000114]");             // 0x0075ac56    8b8614010000
    asm("push               0x40000000");                                    // 0x0075ac5c    6800000040
    asm("push               eax");                                           // 0x0075ac61    50
    asm("call               LAB__addr_0x0075aba0");                          // 0x0075ac62    e839ffffff
    asm("test               eax, eax");                                      // 0x0075ac67    85c0
    asm("{disp32} je        LAB__addr_0x0075ad26");                          // 0x0075ac69    0f84b7000000
    asm("{disp32} mov       ecx, dword ptr [esi + 0x00000114]");             // 0x0075ac6f    8b8e14010000
    asm("push               0x2");                                           // 0x0075ac75    6a02
    asm("call               _jmp_addr_0x007305f0");                          // 0x0075ac77    e87459fdff
    asm("push               eax");                                           // 0x0075ac7c    50
    asm("mov.s              ecx, esi");                                      // 0x0075ac7d    8bce
    asm("call               ?LookAtObject@Living@@QAEIPAVGameThingWithPos@@K@Z");                          // 0x0075ac7f    e89c18e9ff
    asm("test               eax, eax");                                      // 0x0075ac84    85c0
    asm("{disp32} je        LAB__addr_0x0075ad7f");                          // 0x0075ac86    0f84f3000000
    asm("push               0x1");                                           // 0x0075ac8c    6a01
    asm("mov.s              ecx, esi");                                      // 0x0075ac8e    8bce
    asm("call               @IsReadyForNewAnimation__6LivingFUl@12");        // 0x0075ac90    e8cb1ce9ff
    asm("test               eax, eax");                                      // 0x0075ac95    85c0
    asm("{disp32} je        LAB__addr_0x0075ad7f");                          // 0x0075ac97    0f84e2000000
    asm("{disp32} mov       ecx, dword ptr [esi + 0x00000114]");             // 0x0075ac9d    8b8e14010000
    asm("test               ecx, ecx");                                      // 0x0075aca3    85c9
    asm("{disp32} je        LAB__addr_0x0075ad70");                          // 0x0075aca5    0f84c5000000
    asm("call               _jmp_addr_0x00730380");                          // 0x0075acab    e8d056fdff
    asm("test               eax, eax");                                      // 0x0075acb0    85c0
    asm("{disp32} je        LAB__addr_0x0075ad70");                          // 0x0075acb2    0f84b8000000
    asm("{disp32} mov       ecx, dword ptr [esi + 0x00000114]");             // 0x0075acb8    8b8e14010000
    asm("mov                eax, dword ptr [ecx]");                          // 0x0075acbe    8b01
    asm("call               dword ptr [eax + 0x2c]");                        // 0x0075acc0    ff502c
    asm("test               eax, eax");                                      // 0x0075acc3    85c0
    asm("{disp32} je        LAB__addr_0x0075ad70");                          // 0x0075acc5    0f84a5000000
    asm("{disp32} mov       ecx, dword ptr [esi + 0x00000114]");             // 0x0075accb    8b8e14010000
    asm("call               _jmp_addr_0x007305f0");                          // 0x0075acd1    e81a59fdff
    asm("test               eax, eax");                                      // 0x0075acd6    85c0
    asm("{disp8} jne        LAB__addr_0x0075acdf");                          // 0x0075acd8    7505
    asm("pop                esi");                                           // 0x0075acda    5e
    asm("add                esp, 0x4c");                                     // 0x0075acdb    83c44c
    asm("ret");                                                              // 0x0075acde    c3
    asm("LAB__addr_0x0075acdf:");
    asm("{disp32} mov       ecx, dword ptr [_villager_fireman_m8p0_0x0099a968]"); // 0x0075acdf    8b0d68a99900
    asm("push               0x0");                                           // 0x0075ace5    6a00
    asm("push               0x3f800000");                                    // 0x0075ace7    680000803f
    asm("push               0x0");                                           // 0x0075acec    6a00
    asm("push               ecx");                                           // 0x0075acee    51
    asm("push               0x0");                                           // 0x0075acef    6a00
    asm("{disp8} lea        ecx, dword ptr [esp + 0x24]");                   // 0x0075acf1    8d4c2424
    asm("call               ??0EffectValues@@QAE@W4EFFECT_TYPE@@MPAVGameThing@@MPAVGPlayer@@@Z");                    // 0x0075acf5    e846a3dcff
    asm("{disp32} mov       ecx, dword ptr [esi + 0x00000114]");             // 0x0075acfa    8b8e14010000
    asm("{disp8} lea        edx, dword ptr [esp + 0x10]");                   // 0x0075ad00    8d542410
    asm("push               edx");                                           // 0x0075ad04    52
    asm("call               _jmp_addr_0x007305f0");                          // 0x0075ad05    e8e658fdff
    asm("push               eax");                                           // 0x0075ad0a    50
    asm("call               _jmp_addr_0x00730670");                          // 0x0075ad0b    e86059fdff
    asm("add                esp, 0x08");                                     // 0x0075ad10    83c408
    asm("{disp8} lea        ecx, dword ptr [esp + 0x10]");                   // 0x0075ad13    8d4c2410
    asm("call               _jmp_addr_0x00436960");                          // 0x0075ad17    e844bccdff
    asm("mov                eax, 0x00000001");                               // 0x0075ad1c    b801000000
    asm("pop                esi");                                           // 0x0075ad21    5e
    asm("add                esp, 0x4c");                                     // 0x0075ad22    83c44c
    asm("ret");                                                              // 0x0075ad25    c3
    asm("LAB__addr_0x0075ad26:");
    asm("{disp32} mov       eax, dword ptr [esi + 0x00000114]");             // 0x0075ad26    8b8614010000
    asm("{disp8} lea        ecx, dword ptr [esp + 0x04]");                   // 0x0075ad2c    8d4c2404
    asm("push               ecx");                                           // 0x0075ad30    51
    asm("push               eax");                                           // 0x0075ad31    50
    asm("mov.s              ecx, esi");                                      // 0x0075ad32    8bce
    asm("{disp8} mov        dword ptr [esp + 0x0c], 0x00000000");            // 0x0075ad34    c744240c00000000
    asm("{disp8} mov        dword ptr [esp + 0x10], 0x00000000");            // 0x0075ad3c    c744241000000000
    asm("{disp8} mov        dword ptr [esp + 0x14], 0x00000000");            // 0x0075ad44    c744241400000000
    asm("call               ?GetFireFightingPos@Villager@@QAEIPAVFireEffect@@PAUMapCoords@@@Z");                          // 0x0075ad4c    e83ffdffff
    asm("test               eax, eax");                                      // 0x0075ad51    85c0
    asm("{disp8} je         LAB__addr_0x0075ad70");                          // 0x0075ad53    741b
    asm("push               0x000000d8");                                    // 0x0075ad55    68d8000000
    asm("{disp8} lea        edx, dword ptr [esp + 0x08]");                   // 0x0075ad5a    8d542408
    asm("push               edx");                                           // 0x0075ad5e    52
    asm("mov.s              ecx, esi");                                      // 0x0075ad5f    8bce
    asm("call               ?SetupMoveAroundFire@Villager@@QAEIABUMapCoords@@W4VILLAGER_STATES@@@Z");                          // 0x0075ad61    e80afaffff
    asm("mov                eax, 0x00000001");                               // 0x0075ad66    b801000000
    asm("pop                esi");                                           // 0x0075ad6b    5e
    asm("add                esp, 0x4c");                                     // 0x0075ad6c    83c44c
    asm("ret");                                                              // 0x0075ad6f    c3
    asm("LAB__addr_0x0075ad70:");
    asm("mov                eax, dword ptr [esi]");                          // 0x0075ad70    8b06
    asm("push               0x000000a3");                                    // 0x0075ad72    68a3000000
    asm("mov.s              ecx, esi");                                      // 0x0075ad77    8bce
    asm("call               dword ptr [eax + 0x8e8]");                       // 0x0075ad79    ff90e8080000
    asm("LAB__addr_0x0075ad7f:");
    asm("mov                eax, 0x00000001");                               // 0x0075ad7f    b801000000
    asm("pop                esi");                                           // 0x0075ad84    5e
    asm("add                esp, 0x4c");                                     // 0x0075ad85    83c44c
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsValidFire__8VillagerFP10FireEffect(struct Villager* this, const void* edx, struct FireEffect* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00205c14]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075adae\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x04]\n"
        "LAB__addr_0x0075ada3:\n\t"
        "cmp.s              eax, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075adb3\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x3c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075ada3\n"
        "LAB__addr_0x0075adae:\n\t"
        "xor.s              eax, eax\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0075adb3:\n\t"
        "mov                eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall EnterPutOutFire__8VillagerFUcUc(struct Villager* this, const void* edx, unsigned char param_1, unsigned char param_2)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "and                eax, 0x000000ff\n\t"
        "push               eax\n\t"
        "and                edi, 0x000000ff\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "call               ?IsStateEntryFunctionSameAs@Villager@@QBEIKK@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075ae41\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000114]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075ae55\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsValidFire@Villager@@QAEIPAVFireEffect@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075ae4b\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075ae55\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000094]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075ae55\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x34]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x0075ae55\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "call               ?GetFirstCaused@FireEffect@@QAEIXZ\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075ae35\n"
        "LAB__addr_0x0075ae2a:\n\t"
        "cmp                dword ptr [eax + 0x04], esi\n\t"
        "%{disp8%} je         LAB__addr_0x0075ae75\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075ae2a\n"
        "LAB__addr_0x0075ae35:\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x007309a0\n"
        "LAB__addr_0x0075ae41:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x0075ae4b:\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000114], 0x00000000\n"
        "LAB__addr_0x0075ae55:\n\t"
        "lea                eax, dword ptr [edi + edi * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, edi\n\t"
        "lea                eax, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax * 0x4 + 0x00db9f30]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075ae75\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x998]\n"
        "LAB__addr_0x0075ae75:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall ExitPutOutFire__8VillagerFUc(struct Villager* this, const void* edx, unsigned char param_1)
{
    bool32_t result;
    asm volatile (
        "push               ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x08]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, ebx\n\t"
        "and                ecx, 0x000000ff\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x96c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075af14\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075aee0\n\t"
        "call               ?GetFirstCaused@FireEffect@@QAEIXZ\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075aec0\n"
        "LAB__addr_0x0075aeb5:\n\t"
        "cmp                dword ptr [eax + 0x04], esi\n\t"
        "%{disp8%} je         LAB__addr_0x0075aed4\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075aeb5\n"
        "LAB__addr_0x0075aec0:\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000114], 0x00000000\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0075aed4:\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x007309e0\n"
        "LAB__addr_0x0075aee0:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000114], 0x00000000\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075af14\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00000df4]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} je         LAB__addr_0x0075af14\n"
        "LAB__addr_0x0075aeff:\n\t"
        "cmp                dword ptr [edx + 0x04], esi\n\t"
        "%{disp8%} je         LAB__addr_0x0075af0c\n\t"
        "mov                edx, dword ptr [edx]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} jne        LAB__addr_0x0075aeff\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075af14\n"
        "LAB__addr_0x0075af0c:\n\t"
        "push               esi\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?RemoveVillagerOnWayToWorshipSite@Town@@QAEXPAVVillager@@@Z\n"
        "LAB__addr_0x0075af14:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x910]\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall EnterOnFire__8VillagerFUcUc(struct Villager* this, const void* edx, unsigned char param_1, unsigned char param_2)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075af6f\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075af6f\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "call               ?GetFirstCaused@FireEffect@@QAEIXZ\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075af63\n"
        "LAB__addr_0x0075af58:\n\t"
        "cmp                dword ptr [eax + 0x04], esi\n\t"
        "%{disp8%} je         LAB__addr_0x0075af78\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075af58\n"
        "LAB__addr_0x0075af63:\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x007309a0\n"
        "LAB__addr_0x0075af6f:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x0075af78:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall ExitOnFire__8VillagerFUc(struct Villager* this, const void* edx, unsigned char param_1)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075afc9\n\t"
        "call               ?GetFirstCaused@FireEffect@@QAEIXZ\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075afbf\n"
        "LAB__addr_0x0075af99:\n\t"
        "cmp                dword ptr [eax + 0x04], esi\n\t"
        "%{disp8%} je         LAB__addr_0x0075afb3\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075af99\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000114], eax\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0075afb3:\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x007309e0\n"
        "LAB__addr_0x0075afbf:\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000114], 0x00000000\n"
        "LAB__addr_0x0075afc9:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((msvc6_regalloc))
bool32_t __fastcall PutOutFireWithWater__8VillagerFv(struct Villager* this)
{
    typedef void (__attribute__((thiscall)) *fn_t)(struct Villager*, int);
    fn_t fn = ((fn_t*)(*(void**)this))[0x8e8 / 4];
    fn(this, 0xa3);
    return 1;
}

__attribute__((msvc6_regalloc))
bool32_t __fastcall GetWaterToPutOutFire__8VillagerFv(struct Villager* this)
{
    typedef void (__attribute__((thiscall)) *fn_t)(struct Villager*, int);
    fn_t fn = ((fn_t*)(*(void**)this))[0x8e8 / 4];
    fn(this, 0xa3);
    return 1;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall StopFireFighting__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000114]\n\t"
        "test               eax, eax\n\t"
        "push               edi\n\t"
        "%{disp32%} je        LAB__addr_0x0075b168\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "cmp                al, -0x24\n\t"
        "%{disp32%} jne       LAB__addr_0x0075b143\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x0000008e]\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       edi, dword ptr [ecx * 0x4 + 0x00db9e98]\n\t"
        "lea                eax, dword ptr [edi + edi * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091b8]\n\t"
        "cmp                ecx, 0x0075ae80\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b097\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075b092\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091bc]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b097\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091c0]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b097\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091c4]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b097\n"
        "LAB__addr_0x0075b092:\n\t"
        "mov                edi, 0x000000a3\n"
        "LAB__addr_0x0075b097:\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075b0b1\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x007309e0\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000114], 0x00000000\n"
        "LAB__addr_0x0075b0b1:\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008c]\n\t"
        "cmp                al, -0x24\n\t"
        "push               ebp\n\t"
        "%{disp32%} lea       ebp, dword ptr [esi + 0x0000008c]\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b0cf\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075b0ef\n"
        "LAB__addr_0x0075b0cf:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x904]\n\t"
        "push               edi\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               @SetState__12LivingActionFUlUc@16\n\t"
        "push               0x0\n\t"
        "push               0x2\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               @SetState__12LivingActionFUlUc@16\n"
        "LAB__addr_0x0075b0ef:\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        al, byte ptr [ebp + 0x00]\n\t"
        "pop                ebp\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x8]\n\t"
        "shl                ecx, 4\n\t"
        "add                ecx, 0x00d091b8\n\t"
        "mov.s              edi, ecx\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "cmp                eax, 0x0075ae80\n\t"
        "%{disp8%} mov        ecx, dword ptr [edi + 0x04]\n\t"
        "%{disp8%} mov        edx, dword ptr [edi + 0x08]\n\t"
        "%{disp8%} mov        edi, dword ptr [edi + 0x0c]\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b168\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075b125\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b168\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b168\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b168\n"
        "LAB__addr_0x0075b125:\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008e]\n\t"
        "test               al, al\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b168\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "push               0x2\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x938]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0075b143:\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x007309e0\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000114], 0x00000000\n\t"
        "call               dword ptr [eax + 0x8e8]\n"
        "LAB__addr_0x0075b168:\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall SetupOnFire__8VillagerFP10FireEffect(struct Villager* this, const void* edx, struct FireEffect* param_1)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "test               byte ptr [esi + 0x24], 0x44\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b1d8\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075b1d8\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x000000b4]\n\t"
        "and                cl, 0x01\n\t"
        "cmp                cl, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075b1d8\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8ec]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x860]\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       ecx, dword ptr [esi + 0x0000010c]\n\t"
        "call               ?Init@JustWholeMapXZ@@QAEXABUMapCoords@@@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000db\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000114], eax\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x0075b1d8:\n\t"
        "pop                esi"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall OnFire__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x2c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x44]\n\t"
        "test               ecx, ecx\n\t"
        "push               edi\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b1fb\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?FinishBeingOnFire@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x2c\n\t"
        "ret\n"
        "LAB__addr_0x0075b1fb:\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000114]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], 0x00000000\n\t"
        "%{disp32%} je        LAB__addr_0x0075b30d\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x007305f0\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b232\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x2c\n\t"
        "ret\n"
        "LAB__addr_0x0075b232:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x44]\n\t"
        "call               _jmp_addr_0x00730360\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       edi, dword ptr [esi + 0x00000114]\n\t"
        "%{disp8%} je         LAB__addr_0x0075b26c\n\t"
        "push               0x00000268\n\t"
        "push               0x00c2372c\n\t"
        "push               0x41200000\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "add                esp, 0x0c\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x00730000\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x08]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075b2e4\n"
        "LAB__addr_0x0075b26c:\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x007305f0\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n\t"
        "push               eax\n\t"
        "call               ?GetDistanceInMetres@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "add                esp, 0x08\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x00730000\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x08]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075b2a6\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?FinishBeingOnFire@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x2c\n\t"
        "ret\n"
        "LAB__addr_0x0075b2a6:\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "call               _jmp_addr_0x0072ff10\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "push               0x00000272\n\t"
        "push               0x00c2372c\n\t"
        "call               _jmp_addr_0x00730000\n\t"
        "%{disp8%} fsub       dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float1p0]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x14]\n\t"
        "add                esp, 0x0c\n"
        "LAB__addr_0x0075b2e4:\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000114]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x08]\n\t"
        "mov                edi, dword ptr [esi]\n\t"
        "push               edx\n\t"
        "call               _jmp_addr_0x007305f0\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x18]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edi + 0xb00]\n\t"
        "%{disp32%} jmp       LAB__addr_0x0075b392\n"
        "LAB__addr_0x0075b30d:\n\t"
        "call               _jmp_addr_0x00730360\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b323\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?FinishBeingOnFire@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x2c\n\t"
        "ret\n"
        "LAB__addr_0x0075b323:\n\t"
        "push               0x0000027d\n\t"
        "push               0x00c2372c\n\t"
        "push               0x40c90fdb\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "push               0x0000027e\n\t"
        "push               0x00c2372c\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x20]\n\t"
        "push               0x40c00000\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x24]\n\t"
        "%{disp32%} fadd      dword ptr [rdata_bytes + 0x2418]\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x34]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x20]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x20]\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "push               eax\n\t"
        "call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "add                esp, 0x24\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x2c]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "call               @__pl__9MapCoordsCFRC9MapCoords@16\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edx\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n"
        "LAB__addr_0x0075b392:\n\t"
        "push               0x000000db\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008e]\n\t"
        "test               al, al\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b3be\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "push               0x2\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x938]\n"
        "LAB__addr_0x0075b3be:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x2c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall FinishBeingOnFire__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} lea       eax, dword ptr [esi + 0x0000010c]\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       ecx, dword ptr [esi + 0x00000080]\n\t"
        "call               _jmp_addr_0x00603260\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PopFromPrevious@Villager@@QAEXXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsFireMan__8VillagerFv(struct Object* this)
{
    bool32_t result;
    asm volatile (
        "push               ecx\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x00], al\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x00]\n\t"
        "and                ecx, 0x000000ff\n\t"
        "lea                ecx, dword ptr [ecx + ecx * 0x8]\n\t"
        "shl                ecx, 4\n\t"
        "%{disp32%} mov       edx, dword ptr [ecx + 0x00d091b8]\n\t"
        "cmp                edx, 0x0075ae80\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b44d\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} je         LAB__addr_0x0075b455\n\t"
        "%{disp32%} mov       edx, dword ptr [ecx + 0x00d091bc]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b44d\n\t"
        "%{disp32%} mov       edx, dword ptr [ecx + 0x00d091c0]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} jne        LAB__addr_0x0075b44d\n\t"
        "%{disp32%} mov       edx, dword ptr [ecx + 0x00d091c4]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} je         LAB__addr_0x0075b455\n"
        "LAB__addr_0x0075b44d:\n\t"
        "cmp                al, -0x29\n\t"
        "%{disp8%} je         LAB__addr_0x0075b455\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x0075b455:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ecx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}


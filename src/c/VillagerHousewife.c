#include "Villager.h"

const float villager_housewife_float1000p0_0x0099a99c = 1000.0f;
const float villager_housewife_float10p0_0x0099a9a0 = 10.0f;
const float villager_housewife_num_days_in_year_0x0099a9a4 = 365.25f;
const float villager_housewife_seconds_in_day_0x0099a9a8 = 86400.0f;

__attribute__((aligned(4))) char s_VillagerHousewife_cpp[] = "C:\\dev\\MP\\Black\\VillagerHousewife.cpp";

float villager_housewife_seconds_in_year_0x00db9e1c;

__attribute__((no_ret))
void __cdecl globl_ct_0x00761b80(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x00761b94\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x00761b94:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x00761ba0"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((prefer_pop_cleanup))
void __cdecl crt_global_destruction_register_0x00761ba0(void)
{
    extern int __cdecl atexit(void (*)(void));
    atexit((void (*)(void))0x00407870);
}

__attribute__((no_ret))
void __cdecl FUN_00761bb0__8VillagerFv(void)
{
    asm volatile (
        "mov                eax, dword ptr [ecx]\n\t"
        "jmp                dword ptr [eax + 0x460]\n\t"
        "int3\n\t"
        "int3\n\t"
        "int3\n\t"
        "int3\n\t"
        "int3\n\t"
        "int3\n\t"
        "int3\n\t"
        "int3"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((no_ret))
void __cdecl FUN_00761bc0__8VillagerFv(void)
{
    asm("mov                eax, dword ptr [ecx]");                          // 0x00761bc0    8b01
    asm("jmp                dword ptr [eax + 0x338]");                       // 0x00761bc2    ffa038030000
    asm("int3");                                                             // 0x00761bc8    cc
    asm("int3");                                                             // 0x00761bc9    cc
    asm("int3");                                                             // 0x00761bca    cc
    asm("int3");                                                             // 0x00761bcb    cc
    asm("int3");                                                             // 0x00761bcc    cc
    asm("int3");                                                             // 0x00761bcd    cc
    asm("int3");                                                             // 0x00761bce    cc
    asm("int3");                                                             // 0x00761bcf    cc
    __builtin_unreachable();

}

extern void __cdecl FUN_00761be0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x00761bd0(void)
{
    __attribute__((musttail)) return FUN_00761be0__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_00761be0__8VillagerFv(void)
{
    extern float __opaque_a asm("_villager_housewife_seconds_in_day_0x0099a9a8");
    extern float __opaque_b asm("_villager_housewife_num_days_in_year_0x0099a9a4");
    extern float __opaque_c asm("_villager_housewife_seconds_in_year_0x00db9e1c");
    __opaque_c = __opaque_a * __opaque_b;
}

__attribute__((prefer_neg_sbb, msvc6_regalloc))
bool32_t __fastcall HousewifeLookForWork__8VillagerFv(struct Villager* this)
{
    return GetAbode__8VillagerFv(this) != 0;
}

__attribute__((forced_callee_saves("esi"), force_this_esi, MOV32rr_REV, XOR32rr_REV))
bool32_t __fastcall HousewifeAtHome__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "test               byte ptr [esi + 0x000000e0], 0x04\n\t"
        "%{disp8%} je         LAB__addr_0x00761c36\n\t"
        "call               ?CheckNeededToMakeDinner@Villager@@QAEIXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00761c28\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00761c28:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CheckNeededForHouseWork@Villager@@QAEIXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00761c36\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00761c36:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((forced_callee_saves("esi"), force_this_esi, MOV32rr_REV, XOR32rr_REV))
bool32_t __fastcall CheckNeededForHouseWork__8VillagerFv(struct Villager* this)
{
    extern void* __attribute__((thiscall)) __opaque_GetAbode(struct Villager*) asm("?GetAbode@Villager@@QAEPAVAbode@@XZ");
    extern bool32_t __attribute__((thiscall)) __opaque_IsEnoughFoodForDinner(void*) asm("?IsEnoughFoodForDinner@Abode@@QAE_NXZ");

    void* abode = __opaque_GetAbode(this);
    bool32_t enough = __opaque_IsEnoughFoodForDinner(abode);

    bool32_t result;
    asm volatile (
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00761c67\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x65\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00761c67:\n\t"
        "test               byte ptr [esi + 0x000000e0], 0x04\n\t"
        "%{disp8%} je         LAB__addr_0x00761c89\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x6c\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], 0x0005\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00761c89:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) : "a"(enough) : "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall CheckNeededToMakeDinner__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "%{disp32%} mov       esi, dword ptr [eax + 0x000000a0]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x00761cb8\n"
        "LAB__addr_0x00761ca3:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsHungry@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00761cbd\n\t"
        "%{disp32%} mov       esi, dword ptr [esi + 0x000000e4]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x00761ca3\n"
        "LAB__addr_0x00761cb8:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00761cbd:\n\t"
        "test               byte ptr [esi + 0x000000e0], 0x04\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00761cd0\n\t"
        "call               ?HousewifeMakeDinner@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00761cd0:\n\t"
        "call               ?GoHome@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall HousewifeGotoStoragePit__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00761d49\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0xd4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00761d49\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?IsEnoughFoodForDinner@Abode@@QAE_NXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00761d49\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "push               0x66\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x104]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x00761d49:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GoHome@Villager@@QAEIXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall HousewifeArrivesAtStoragePit__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov.s              edi, eax\n\t"
        "test               edi, edi\n\t"
        "%{disp32%} je        LAB__addr_0x00761e79\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0xd4]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp32%} jne       LAB__addr_0x00761e79\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsEnoughFoodInStoragePitForDinner@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00761db5\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x6d\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], 0x0001\n\t"
        "call               ?HousewifeGossipsAroundStoragePit@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x00761db5:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAmountOfFoodRequiredForMeal@Villager@@QAEIXZ\n\t"
        "mov.s              ecx, esi\n\t"
        "mov.s              ebx, eax\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00761de2\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?CalculateFoodNeededForDinner@Abode@@QAEHXZ\n\t"
        "xor.s              ebx, ebx\n\t"
        "mov.s              bx, ax\n\t"
        "and                ebx, 0x0000ffff\n"
        "LAB__addr_0x00761de2:\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x98]\n\t"
        "cmp.s              ebx, eax\n\t"
        "%{disp8%} jbe        LAB__addr_0x00761e12\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x6d\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], 0x0001\n\t"
        "call               ?HousewifeGossipsAroundStoragePit@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x00761e12:\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} jbe        LAB__addr_0x00761e2e\n\t"
        "push               0x000000a3\n\t"
        "push               0x67\n\t"
        "push               ebx\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ArrivesAtStoragePitForResource@Villager@@QAEIW4RESOURCE_TYPE@@KW4VILLAGER_STATES@@1@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x00761e2e:\n\t"
        "cmp                word ptr [esi + 0x000000f4], 0x00\n\t"
        "%{disp8%} je         LAB__addr_0x00761e5e\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "push               0x67\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x104]\n\t"
        "push               eax\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x00761e5e:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x00761e79:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall HousewifePickupFromStoragePit__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "cmp                word ptr [esi + 0x000000f4], 0x00\n\t"
        "%{disp8%} je         LAB__addr_0x00761eeb\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00761eeb\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "push               0x68\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x104]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x00761eeb:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall HousewifeReturnHomeWithFood__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "call               ?ArrivesHome@Villager@@QAEIXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00761f52\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "mov.s              esi, eax\n\t"
        "mov                ebx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?DropFood@Villager@@QAEGG@Z\n\t"
        "movsx              eax, ax\n\t"
        "push               eax\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [ebx + 0x9c]\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                edi\n\t"
        "ret\n"
        "LAB__addr_0x00761f52:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                edi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((forced_callee_saves("esi"), force_this_esi, MOV32rr_REV))
bool32_t __fastcall HousewifeMakeDinner__8VillagerFv(struct Villager* this)
{
    extern void* __attribute__((thiscall)) __opaque_GetAbode(struct Villager*) asm("?GetAbode@Villager@@QAEPAVAbode@@XZ");
    extern bool32_t __attribute__((thiscall)) __opaque_IsEnoughFoodForDinner(void*) asm("?IsEnoughFoodForDinner@Abode@@QAE_NXZ");

    void* abode = __opaque_GetAbode(this);
    bool32_t enough = __opaque_IsEnoughFoodForDinner(abode);
    if (enough != 1) {
        asm volatile (
            "mov                edx, dword ptr [esi]\n\t"
            "push               0x65\n\t"
            "mov.s              ecx, esi\n\t"
            "call               dword ptr [edx + 0x8e8]\n\t"
            "mov                eax, 0x00000001\n\t"
            "pop                esi\n\t"
            "ret"
            ::: "eax", "ecx", "edx", "memory"
        );
        __builtin_unreachable();
    }
    asm volatile (
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x6a\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]"
        ::: "eax", "ecx", "edx", "memory"
    );
    return 1;
}

__attribute__((no_callee_saves, msvc6_schedule))
bool32_t __fastcall HousewifeServesDinner__8VillagerFv(struct Villager* this)
{
    const void* info = *(const void**)((char*)this + 0x28);
    int16_t field_val = *(int16_t*)((char*)info + 0x2b4);
    *(int16_t*)((char*)this + 0x58) = field_val;
    typedef void (__fastcall *VtFn)(struct Villager*, const void*, int);
    VtFn fn = ((VtFn*)(*(void**)this))[0x8e8 / 4];
    fn(this, 0, 0x6b);
    return 1;
}

__attribute__((forced_callee_saves("esi"), force_this_esi, MOV32rr_REV, insert_redundant_cmp, prefer_memory_dec))
bool32_t __fastcall HousewifeClearsAwayDinner__8VillagerFv(struct Villager* this)
{
    extern float __attribute__((thiscall)) __opaque_EatFoodHeld(struct Villager*) asm("?EatFoodHeld@Villager@@QAEIXZ");
    int16_t* counter = (int16_t*)((char*)this + 0x58);
    --(*counter);
    if (__builtin_expect(*counter == 0, 1)) {
        __opaque_EatFoodHeld(this);
        asm volatile (
            "mov                eax, dword ptr [esi]\n\t"
            "push               0x24\n\t"
            "mov.s              ecx, esi\n\t"
            "call               dword ptr [eax + 0x8e8]"
            ::: "eax", "ecx", "edx", "memory"
        );
    }
    return 1;
}

__attribute__((forced_callee_saves("esi"), MOV32rr_REV, insert_redundant_cmp))
bool32_t __fastcall HousewifeDoesHousework__8VillagerFv(struct Villager* this)
{
    extern bool32_t __fastcall __opaque_CheckNeededForSpecial(struct Villager*) asm("?CheckNeededForSpecial@Villager@@QAEIXZ");
    extern bool32_t __fastcall __opaque_GoHome(struct Villager*) asm("?GoHome@Villager@@QAEIXZ");
    bool32_t special = __opaque_CheckNeededForSpecial(this);
    if (special != 1) {
        int16_t* counter = (int16_t*)((char*)this + 0x58);
        --(*counter);
        if (__builtin_expect(*counter == 0, 1)) {
            __opaque_GoHome(this);
        }
    }
    return 1;
}

__attribute__((no_callee_saves))
bool32_t __fastcall HousewifeGossipsAroundStoragePit__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x1c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "dec                word ptr [esi + 0x58]\n\t"
        "%{disp8%} mov        ax, word ptr [esi + 0x58]\n\t"
        "test               ax, ax\n\t"
        "push               edi\n\t"
        "%{disp32%} jg        LAB__addr_0x00762194\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00762057\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0xd4]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0076205e\n"
        "LAB__addr_0x00762057:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GoHome@Villager@@QAEIXZ\n"
        "LAB__addr_0x0076205e:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x98]\n\t"
        "mov.s              ecx, esi\n\t"
        "mov.s              edi, eax\n\t"
        "call               ?GetAmountOfFoodRequiredForMeal@Villager@@QAEIXZ\n\t"
        "cmp.s              eax, edi\n\t"
        "%{disp8%} jae        LAB__addr_0x00762097\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x65\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?HousewifeGotoStoragePit@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x1c\n\t"
        "ret\n"
        "LAB__addr_0x00762097:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CheckNeededForSpecial@Villager@@QAEIXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp32%} je        LAB__addr_0x00762194\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "add                eax, 0x14\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "push               0x0000010f\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "push               0x00c2450c\n\t"
        "push               0x40c90fdb\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x2c], eax\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "%{disp32%} fld       dword ptr [_villager_housewife_float10p0_0x0099a9a0]\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float0p5]\n\t"
        "push               0x00000110\n\t"
        "push               0x00c2450c\n\t"
        "push               ecx\n\t"
        "fstp               dword ptr [esp]\n\t"
        "mov.s              edi, eax\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "add                esp, 0x0c\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x64]\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x08]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "add                esp, 0x0c\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "call               @__apl__9MapCoordsFRC9MapCoords@12\n\t"
        "push               0x19\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "call               _jmp_addr_0x006033b0\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00762164\n\t"
        "push               0x6d\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x1c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n"
        "LAB__addr_0x00762164:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       edx, dword ptr [ecx + 0x000002b0]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x0c]\n\t"
        "%{disp32%} fld       dword ptr [esi + 0x000000e8]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x2414]\n\t"
        "faddp              st(1), st\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], ax\n"
        "LAB__addr_0x00762194:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x1c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall HousewifeStartsGivingBirth__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       word ptr [esi + 0x000000f8], 0x0000\n\t"
        "%{disp32%} fld       dword ptr [data_bytes + 0x33ba0c]\n\t"
        "push               0x00000120\n\t"
        "push               0x00c2450c\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "push               eax\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x10]\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp32%} fld       dword ptr [data_bytes + 0x33ba0c]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x23d4]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float1p0]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], ax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x6f\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?HousewifeGivingBirth@Villager@@QAEIXZ\n\t"
        "pop                esi\n\t"
        "add                esp, 0x08"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
struct Villager* __fastcall ChildBorn__FR8Villager(struct Villager* this)
{
    struct Villager* result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "push               0x00000131\n\t"
        "push               0x00c2450c\n\t"
        "push               0x64\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x24]\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "%{disp32%} mov       eax, dword ptr [edi + 0x0000025c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x18]\n\t"
        "add                esp, 0x0c\n\t"
        "fcompp\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00762274\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} jmp        LAB__addr_0x00762279\n"
        "LAB__addr_0x00762274:\n\t"
        "mov                eax, 0x00000001\n"
        "LAB__addr_0x00762279:\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007622af\n\t"
        "push               0x00000137\n\t"
        "push               0x00c2450c\n\t"
        "push               0x6\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "add                esp, 0x0c\n\t"
        "inc                eax\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetTribe@Villager@@QAEPAVGTribeInfo@@XZ\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x10]\n\t"
        "push               ecx\n\t"
        "call               ?Find@GVillagerInfo@@SAPAV1@W4TRIBE_TYPE@@W4VILLAGER_NUMBER@@@Z\n\t"
        "mov.s              edi, eax\n\t"
        "add                esp, 0x08\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x007622af\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n"
        "LAB__addr_0x007622af:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x4a0]\n\t"
        "push               eax\n\t"
        "push               0x1\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n\t"
        "push               edi\n\t"
        "push               eax\n\t"
        "call               ?Create@Villager@@SAPAV1@ABUMapCoords@@PBVGVillagerInfo@@KH@Z\n\t"
        "mov.s              ebx, eax\n\t"
        "add                esp, 0x10\n\t"
        "test               ebx, ebx\n\t"
        "%{disp32%} je        LAB__addr_0x00762409\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "call               ?IsMultiplayerGame@GGame@@QBE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00762359\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00762359\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], 0x00000002\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "mov.s              edi, eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x18]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x10]\n\t"
        "add                edi, 0x000000f8\n\t"
        "push               edx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x0056f8d0\n\t"
        "%{disp8%} mov        edi, dword ptr [edi + 0x04]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x0c]\n\t"
        "cmp.s              eax, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076232f\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x18]\n\t"
        "cmp                ecx, dword ptr [eax + 0x0c]\n\t"
        "%{disp8%} jl         LAB__addr_0x0076232f\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00762337\n"
        "LAB__addr_0x0076232f:\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edi\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x18]\n"
        "LAB__addr_0x00762337:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov                edi, dword ptr [eax]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x000000fc]\n\t"
        "add                eax, 0x000000f8\n\t"
        "cmp.s              edi, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00762359\n\t"
        "push               0x1\n\t"
        "%{disp8%} lea        ecx, dword ptr [edi + 0x10]\n\t"
        "call               _jmp_addr_0x00775720\n"
        "LAB__addr_0x00762359:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00762375\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?AddVillagerToAbode@Abode@@QAEXPAVVillager@@@Z\n\t"
        "%{disp8%} jmp        LAB__addr_0x007623c7\n"
        "LAB__addr_0x00762375:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00762391\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?AddVillagerToTown@Town@@QAEIPAVVillager@@@Z\n\t"
        "%{disp8%} jmp        LAB__addr_0x007623c7\n"
        "LAB__addr_0x00762391:\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp32%} lea       ecx, dword ptr [eax + 0x00205bfc]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007623b6\n"
        "LAB__addr_0x007623a2:\n\t"
        "cmp.s              eax, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x007623b2\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x000000e4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007623a2\n\t"
        "%{disp8%} jmp        LAB__addr_0x007623b6\n"
        "LAB__addr_0x007623b2:\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007623c7\n"
        "LAB__addr_0x007623b6:\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "%{disp32%} mov       dword ptr [ebx + 0x000000e4], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + 0x04]\n\t"
        "inc                eax\n\t"
        "mov                dword ptr [ecx], ebx\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x04], eax\n"
        "LAB__addr_0x007623c7:\n\t"
        "%{disp32%} mov       dword ptr [ebx + 0x00000100], esi\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007623e8\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00000a44]\n\t"
        "%{disp8%} inc        dword ptr [eax + 0x48]\n"
        "LAB__addr_0x007623e8:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x4a4]\n\t"
        "test               al, al\n\t"
        "%{disp8%} je         LAB__addr_0x00762402\n\t"
        "mov                edx, dword ptr [ebx]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               dword ptr [edx + 0x69c]\n"
        "LAB__addr_0x00762402:\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?ChildDecideWhatToDo@Villager@@QAEIXZ\n"
        "LAB__addr_0x00762409:\n\t"
        "%{disp32%} mov       eax, dword ptr [data_bytes + 0x25e48c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00762418\n\t"
        "call               dword ptr [data_bytes + 0x25e494]\n"
        "LAB__addr_0x00762418:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov.s              eax, ebx\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall HousewifeGivingBirth__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "dec                word ptr [esi + 0x58]\n\t"
        "%{disp8%} mov        ax, word ptr [esi + 0x58]\n\t"
        "test               ax, ax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076248b\n\t"
        "push               edi\n\t"
        "push               esi\n\t"
        "call               ?ChildBorn@@YEPAVVillager@@AAV1@@Z\n\t"
        "mov.s              edi, eax\n\t"
        "add                esp, 0x04\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00762477\n\t"
        "push               0x0\n\t"
        "push               0x1\n\t"
        "push               0x1\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x2\n\t"
        "push               0x0\n\t"
        "push               0xa\n\t"
        "push               0x14\n\t"
        "call               _jmp_addr_0x0071ed40\n\t"
        "add                esp, 0x08\n\t"
        "push               eax\n\t"
        "add                edi, 0x14\n\t"
        "push               edi\n\t"
        "call               _jmp_addr_0x0071eb60\n\t"
        "add                esp, 0x24\n"
        "LAB__addr_0x00762477:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x70\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0076248b:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, trailing_asm("nop\nnop\nmov eax, 0x00000001\nret")))
bool32_t __fastcall HousewifeGivenBirth__8VillagerFv(struct Villager* this)
{
    *(int16_t*)((char*)this + 0xf8) = 0;
    extern bool32_t __fastcall __opaque_GoHome(struct Villager*) asm("?GoHome@Villager@@QAEIXZ");
    __attribute__((musttail)) return __opaque_GoHome(this);
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall WillHousewifeGetPregnant__8VillagerFP8Villager(struct Villager* this, const void* edx, struct Villager* param_1)
{
    bool32_t result;
    asm volatile (
        "push               ecx\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              ecx, esi\n\t"
        "mov.s              edi, eax\n\t"
        "call               ?IsPregnant@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x0076255e\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076255e\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076255e\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsSexuallyActive@Villager@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076255e\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x8\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "add                ecx, 0x34\n\t"
        "call               _jmp_addr_0x00746660\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "%{disp32%} mov       esi, dword ptr [edi + 0x000000a0]\n\t"
        "xor.s              ebx, ebx\n\t"
        "test               esi, esi\n\t"
        "%{disp32%} mov       bl, byte ptr [edi + 0x000000b7]\n\t"
        "%{disp8%} je         LAB__addr_0x00762536\n"
        "LAB__addr_0x0076251f:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsPregnant@Villager@@QAE_NXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0076252c\n\t"
        "inc                ebx\n"
        "LAB__addr_0x0076252c:\n\t"
        "%{disp32%} mov       esi, dword ptr [esi + 0x000000e4]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x0076251f\n"
        "LAB__addr_0x00762536:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x0c]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x0076255e\n\t"
        "%{disp8%} mov        eax, dword ptr [edi + 0x28]\n\t"
        "cmp                dword ptr [eax + 0x00000178], ebx\n\t"
        "%{disp8%} jbe        LAB__addr_0x0076255e\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "pop                ecx\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0076255e:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "pop                ecx"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall HousewifeGetsPregnant__8VillagerFP8Villager(struct Villager* this, const void* edx, struct Villager* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} mov       dx, word ptr [eax + 0x00000240]\n\t"
        "test               byte ptr [ecx + 0x000000e0], 0x04\n\t"
        "%{disp32%} mov       word ptr [ecx + 0x000000f8], dx\n\t"
        "%{disp8%} jne        LAB__addr_0x0076258f\n\t"
        "call               ?GoHome@Villager@@QAEIXZ\n\t"
        "LAB__addr_0x0076258f:"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall HousewifeCalledToMakeDinner__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "mov.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       edi, dword ptr [ecx * 0x4 + 0x00db9f2c]\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x007625ef\n\t"
        "%{disp32%} mov       dl, byte ptr [esi + 0x000000e0]\n\t"
        "and                dl, 0x04\n\t"
        "cmp                dl, 0x04\n\t"
        "%{disp8%} jne        LAB__addr_0x007625e8\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x69\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov.s              eax, edi\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007625e8:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GoHome@Villager@@QAEIXZ\n"
        "LAB__addr_0x007625ef:\n\t"
        "mov.s              eax, edi\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall HousewifeAskForMeal__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "%{disp32%} mov       esi, dword ptr [eax + 0x000000a0]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x0076263b\n"
        "LAB__addr_0x00762613:\n\t"
        "cmp.s              esi, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x00762625\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "push               0x69\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00762631\n"
        "LAB__addr_0x00762625:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?HousewifeCalledToMakeDinner@Villager@@QAEIXZ\n\t"
        "cmp                eax, 0x02\n\t"
        "%{disp8%} jne        LAB__addr_0x00762640\n"
        "LAB__addr_0x00762631:\n\t"
        "%{disp32%} mov       esi, dword ptr [esi + 0x000000e4]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x00762613\n"
        "LAB__addr_0x0076263b:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00762640:\n\t"
        "%{disp8%} mov        ecx, dword ptr [edi + 0x28]\n\t"
        "%{disp32%} mov       dx, word ptr [ecx + 0x000002ac]\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "push               0x00000080\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp8%} mov        word ptr [edi + 0x58], dx\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CheckSatisfyForChildren__8VillagerFv(struct Villager* this)
{
    return 0;
}

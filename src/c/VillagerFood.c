#include "Villager.h"

const float villager_food_num_days_in_year_0x0099a978 = 365.25f;
const float villager_food_seconds_in_day_0x0099a97c = 86400.0f;

float villager_food_seconds_in_year_0x00db9e08;

__attribute__((no_ret))
void __cdecl globl_ct_0x0075b8e0(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x0075b8f4\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x0075b8f4:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x0075b900"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

void __cdecl crt_global_destruction_register_0x0075b900(void)
{
    asm volatile (
        "push               0x00407870\n\t"
        "call               _atexit\n\t"
        "pop                ecx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

extern void __cdecl FUN_0075b920__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x0075b910(void)
{
    __attribute__((musttail)) return FUN_0075b920__8VillagerFv();
}

void __cdecl FUN_0075b920__8VillagerFv(void)
{
    asm volatile (
        "%{disp32%} fld  dword ptr [_villager_food_seconds_in_day_0x0099a97c]\n\t"
        "%{disp32%} fmul dword ptr [_villager_food_num_days_in_year_0x0099a978]\n\t"
        "%{disp32%} fstp dword ptr [_villager_food_seconds_in_year_0x00db9e08]"
        ::: "memory"
    );
}

__attribute__((no_callee_saves))
bool32_t __fastcall ShowPoisoned__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "test               byte ptr [esi + 0x000000e0], 0x04\n\t"
        "%{disp8%} je         LAB__addr_0x0075b96c\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "call               ?FindPosOutsideAbode@Villager@@QAEXPAVAbode@@@Z\n\t"
        "push               0x000000d4\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n"
        "LAB__addr_0x0075b96c:\n\t"
        "push               0x1\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PlayAnimThenSetState@Living@@QAEXEK@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ChangeStateToFindFoodToEat__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetAmountOfFoodRequiredForMeal@Villager@@QAEIXZ\n\t"
        "mov.s              edi, eax\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x000000e0]\n\t"
        "and                al, 0x04\n\t"
        "neg                al\n\t"
        "sbb.s              eax, eax\n\t"
        "neg                eax\n\t"
        "add                eax, 0x75\n\t"
        "test               edi, edi\n\t"
        "mov.s              ebp, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0075baba\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075ba26\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0xd4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075ba26\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp32%} mov       bx, word ptr [esi + 0x000000f4]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x98]\n\t"
        "movsx              ecx, bx\n\t"
        "add.s              eax, ecx\n\t"
        "cmp.s              eax, edi\n\t"
        "pop                ebx\n\t"
        ".byte              0x72, 0x27\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x000000e0]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "and                al, 0x04\n\t"
        "neg                al\n\t"
        "sbb.s              al, al\n\t"
        "and                al, 0x52\n\t"
        "add                al, 0x24\n\t"
        "mov.s              ecx, esi\n\t"
        "push               eax\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebp\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x0075ba26:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075ba75\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0xd4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075ba75\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x98]\n\t"
        "cmp.s              eax, edi\n\t"
        ".byte              0x72, 0x53\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x21\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebp\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x0075ba75:\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetResourceDropoffPos@Villager@@QAEPAVGameThingWithPos@@W4RESOURCE_TYPE@@@Z\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        edx, dword ptr [esi + 0x14]\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "call               @IsCloseToEqual__9MapCoordsCFRC9MapCoordsf@16\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075bab0\n\t"
        "push               0x22\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x10]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebp\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x0075bab0:\n\t"
        "cmp                word ptr [esi + 0x000000f4], 0x00\n\t"
        "%{disp8%} je         LAB__addr_0x0075bad1\n"
        "LAB__addr_0x0075baba:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               ebp\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebp\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x0075bad1:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebp\n\t"
        "add                esp, 0x0c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

float __fastcall CalculateLifeDesire__8VillagerFv(struct Living* this)
{
    void* dummy;
    float result;
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "call dword ptr [eax + 0x11c]\n\t"
        "%{disp32%} fsubr qword ptr [__real@8@3fff8000000000000000]"
        : "=t"(result), "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall CheckHungryAtHome__8VillagerFv(struct Villager* this)
{
    return 1;
}

__attribute__((no_callee_saves))
bool32_t __fastcall GetDesireToPickupFood__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} mov       cx, word ptr [ecx + 0x000000f4]\n\t"
        "sub                esp, 0x08\n\t"
        "cmp                cx, word ptr [eax + 0x000002d8]\n\t"
        "%{disp8%} jge        LAB__addr_0x0075bb41\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x000002d8]\n\t"
        "movsx              ecx, cx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x00], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], 0x00000000\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x00]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x00], edx\n\t"
        "%{disp8%} fidiv      dword ptr [esp + 0x00]\n\t"
        "%{disp32%} fsubr     dword ptr [_rdata_float1p0]\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x0075bb41:\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float0p0]\n\t"
        "add                esp, 0x08"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

float __fastcall GetDesireForFood__8VillagerFv(struct Villager* this)
{
    float result;
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [ecx + 0x000000e8]\n\t"
        "push               eax\n\t"
        "call               _POWER_f___FfUl"
        : "=t"(result) : "c"(this) : "eax", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x04)))
float __cdecl POWER_f___FfUl(float param_0, uint32_t param_1)
{
    float result;
    asm volatile (
        "%{disp8%} fld        dword ptr [esp + 0x04]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075bb77\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x04]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075bb7d\n"
        "LAB__addr_0x0075bb77:\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n"
        "LAB__addr_0x0075bb7d:\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x04]\n\t"
        "mov                eax, 0x00000002\n"
        "LAB__addr_0x0075bb86:\n\t"
        "dec                eax\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x04]\n\t"
        "%{disp8%} jne        LAB__addr_0x0075bb86\n\t"
        "%{disp32%} fsubr     dword ptr [_rdata_float1p0]"
        : "=t"(result) :: "eax", "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
void __fastcall GetDesireForLife__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x11c]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "fstp               dword ptr [esp]\n\t"
        "call               ?GetLifeDesireFromLife@Villager@@QAEMM@Z\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves))
float __fastcall GetLifeDesireFromLife__8VillagerFf(struct Villager* this, const void* edx, float param_1)
{
    float result;
    asm volatile (
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} fld       dword ptr [ecx + 0x0000035c]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x04]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075bbdc\n\t"
        "%{disp32%} fld       dword ptr [ecx + 0x0000035c]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075bbe0\n"
        "LAB__addr_0x0075bbdc:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x04]\n"
        "LAB__addr_0x0075bbe0:\n\t"
        "%{disp8%} fsubr      dword ptr [esp + 0x04]\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n\t"
        "%{disp32%} fsub      dword ptr [ecx + 0x0000035c]\n\t"
        "fdivp              st(1), st\n\t"
        "fld                st(0)\n\t"
        "fmulp              st(1), st\n\t"
        "%{disp32%} fsubr     dword ptr [_rdata_float1p0]"
        : "=t"(result) :: "eax", "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetAmountOfFoodRequiredForMeal__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetAmountOfFoodToEat@Villager@@QAEIXZ\n\t"
        "movsx              ecx, word ptr [esi + 0x000000f4]\n\t"
        "sub.s              eax, ecx\n\t"
        "xor.s              edx, edx\n\t"
        "test               eax, eax\n\t"
        "setle              dl\n\t"
        "pop                esi\n\t"
        "dec                edx\n\t"
        "and.s              eax, edx"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
uint32_t __fastcall GetAmountOfFoodToEat__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "call               ?GetDesireForFood@Villager@@QAEMXZ\n\t"
        "%{disp32%} mov       eax, dword ptr [edi + 0x000002d8]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], 0x00000000\n\t"
        "%{disp8%} fimul      dword ptr [esp + 0x08]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075bca8\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp32%} fld       dword ptr [eax + 0x0000014c]\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075bc78\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float0p0]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075bc8d\n"
        "LAB__addr_0x0075bc78:\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x0075bc8d\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n"
        "LAB__addr_0x0075bc8d:\n\t"
        "%{disp32%} fmul      dword ptr [__real@3e999999]\n\t"
        "%{disp32%} fsubr     dword ptr [_rdata_float1p0]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x08]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x0075bca8:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x08"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall CheckHungry__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "xor.s              ebx, ebx\n\t"
        "call               ?GetGameTurnsSinceLastChecked@Villager@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0075beef\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], eax\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        ax, word ptr [esi + 0x5a]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ebx\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x0c]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp32%} fmul      dword ptr [ecx + 0x000002bc]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], eax\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x0c]\n\t"
        "%{disp32%} fidiv     dword ptr [ecx + 0x00000104]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075bd24\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "%{disp8%} fld        dword ptr [eax + 0x74]\n\t"
        "%{disp8%} fdivr      dword ptr [esp + 0x08]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n"
        "LAB__addr_0x0075bd24:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x0c]\n\t"
        "%{disp32%} fcomp     qword ptr [__real@8@3fff8000000000000000]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x0075bd4f\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x174]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075bd4f\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x08]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n"
        "LAB__addr_0x0075bd4f:\n\t"
        "%{disp32%} fld       dword ptr [esi + 0x000000e8]\n\t"
        "%{disp8%} fsub       dword ptr [esp + 0x08]\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float0p0]\n\t"
        "%{disp32%} fst       dword ptr [esi + 0x000000e8]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075bd74\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float0p0]\n"
        "LAB__addr_0x0075bd74:\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} fst       dword ptr [esi + 0x000000e8]\n\t"
        "%{disp32%} fcomp     dword ptr [eax + 0x000002c0]\n\t"
        "push               edi\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075bd92\n\t"
        "mov                edi, 0x00000001\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075bda6\n"
        "LAB__addr_0x0075bd92:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "xor.s              edi, edi\n\t"
        "call               dword ptr [edx + 0x4a4]\n\t"
        "test               al, al\n\t"
        "%{disp32%} je        LAB__addr_0x0075bedf\n"
        "LAB__addr_0x0075bda6:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} fld       dword ptr [ecx + 0x000002c0]\n\t"
        "%{disp32%} fdivr     dword ptr [esi + 0x000000e8]\n\t"
        "%{disp32%} fsubr     dword ptr [_rdata_float1p0]\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} je         LAB__addr_0x0075bdd0\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n"
        "LAB__addr_0x0075bdd0:\n\t"
        "%{disp32%} fmul      dword ptr [ecx + 0x000002d0]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "push               ecx\n\t"
        "fstp               dword ptr [esp]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x5b8]\n\t"
        "fstp               st(0)\n\t"
        "test               edi, edi\n\t"
        "%{disp32%} je        LAB__addr_0x0075bedf\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xb04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "mov.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                edi, dword ptr [eax + eax * 0x2]\n\t"
        "shl                edi, 2\n\t"
        "%{disp32%} mov       eax, dword ptr [edi + 0x00db9f48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075be4d\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000e0]\n\t"
        "shr                eax, 9\n\t"
        "test               al, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075be44\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x000000f2]\n\t"
        "%{disp32%} lea       ecx, dword ptr [eax * 0x8 + 0x00000000]\n\t"
        "sub.s              ecx, eax\n\t"
        "cmp                dword ptr [ecx * 0x4 + 0x0099a204], 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075be4d\n"
        "LAB__addr_0x0075be44:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ChangeStateToFindFoodToEat@Villager@@QAEIXZ\n\t"
        "mov.s              ebx, eax\n"
        "LAB__addr_0x0075be4d:\n\t"
        "%{disp8%} mov        edx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} fld       dword ptr [esi + 0x000000e8]\n\t"
        "%{disp32%} fcomp     dword ptr [edx + 0x000002c4]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075be7a\n\t"
        "%{disp32%} mov       eax, dword ptr [edi + 0x00db9f4c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075be7a\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} jne        LAB__addr_0x0075be7a\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ChangeStateToFindFoodToEat@Villager@@QAEIXZ\n\t"
        "mov.s              ebx, eax\n"
        "LAB__addr_0x0075be7a:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x11c]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} je         LAB__addr_0x0075bedf\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xb04]\n\t"
        "cmp                al, -0x08\n\t"
        "%{disp8%} je         LAB__addr_0x0075beb5\n\t"
        "cmp                al, -0x07\n\t"
        "%{disp8%} je         LAB__addr_0x0075beb5\n\t"
        "cmp                al, -0x06\n\t"
        "%{disp8%} je         LAB__addr_0x0075beb5\n\t"
        "test               byte ptr [esi + 0x000000e0], 0x02\n\t"
        "mov                edi, 0x00000001\n\t"
        "%{disp8%} je         LAB__addr_0x0075beba\n"
        "LAB__addr_0x0075beb5:\n\t"
        "mov                edi, 0x00000004\n"
        "LAB__addr_0x0075beba:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x11c]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "fstp               dword ptr [esp]\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "push               eax\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?VillagerDead@Villager@@QAEXW4DEATH_REASON@@PAVGPlayer@@MH@Z\n\t"
        "mov                ebx, 0x00000001\n"
        "LAB__addr_0x0075bedf:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetGameTurnLastChecked@Villager@@QAEXXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov.s              eax, ebx\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x0075beef:\n\t"
        "pop                esi\n\t"
        "mov.s              eax, ebx\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall CheckSatisfyOwnFoodDesire__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?IsHungry@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075bf15\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ChangeStateToFindFoodToEat@Villager@@QAEIXZ\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0075bf15:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall EatFoodHeld__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetAmountOfFoodToEat@Villager@@QAEIXZ\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], eax\n\t"
        "movsx              eax, word ptr [esi + 0x000000f4]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], eax\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x08]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x04]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "fcomp              st(1)\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075bf67\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "fstp               st(0)\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], ecx\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075bf6b\n"
        "LAB__addr_0x0075bf67:\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x04]\n"
        "LAB__addr_0x0075bf6b:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x04]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "mov.s              ecx, esi\n\t"
        "push               eax\n\t"
        "call               ?DropFood@Villager@@QAEGG@Z\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x04]\n\t"
        "%{disp8%} fdiv       dword ptr [esp + 0x08]\n\t"
        "%{disp8%} mov        edx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} fmul      dword ptr [edx + 0x000002b8]\n\t"
        "%{disp32%} fadd      dword ptr [esi + 0x000000e8]\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float0p0]\n\t"
        "%{disp32%} fst       dword ptr [esi + 0x000000e8]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075bfb4\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000e8], 0x00000000\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075bfcb\n"
        "LAB__addr_0x0075bfb4:\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x0075bfcb\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000e8], 0x3f800000\n"
        "LAB__addr_0x0075bfcb:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075bfee\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x04]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x0073b5e0\n"
        "LAB__addr_0x0075bfee:\n\t"
        "%{disp32%} fld       dword ptr [esi + 0x000000e8]\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall EatFood__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?EatFoodHeld@Villager@@QAEIXZ\n\t"
        "fstp               st(0)\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x4a4]\n\t"
        "neg                al\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "sbb.s              eax, eax\n\t"
        "and                eax, 0x31\n\t"
        "add                eax, 0x000000a3\n\t"
        "push               eax\n\t"
        "call               ?PlayAnimThenSetState@Living@@QAEXEK@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall GetFoodFromHome__8VillagerFUl(struct Villager* this, const void* edx, unsigned long param_1)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              esi, eax\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x0075c084\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x98]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x0c]\n\t"
        "cmp.s              ecx, eax\n\t"
        ".byte              0x72, 0xe\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x98]\n\t"
        "mov.s              ecx, eax\n"
        "LAB__addr_0x0075c071:\n\t"
        "push               ecx\n\t"
        "push               0x0\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?GetResourceFrom@Villager@@QAEIPAVObject@@W4RESOURCE_TYPE@@F@Z\n\t"
        "mov.s              ecx, edi\n\t"
        "push               eax\n\t"
        "call               ?PickupFood@Villager@@QAEXF@Z\n"
        "LAB__addr_0x0075c084:\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall EatFoodAtHome__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "%{disp32%} mov       di, word ptr [esi + 0x000000f4]\n\t"
        "call               ?GetAmountOfFoodToEat@Villager@@QAEIXZ\n\t"
        "movsx              ecx, di\n\t"
        "sub.s              eax, ecx\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jle        LAB__addr_0x0075c0b1\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFoodFromHome@Villager@@QAEIK@Z\n\t"
        "LAB__addr_0x0075c0b1:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?EatFoodHeld@Villager@@QAEIXZ\n\t"
        "fstp               st(0)\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x4a4]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "neg                al\n\t"
        "mov.s              ecx, esi\n\t"
        "sbb.s              eax, eax\n\t"
        "and                eax, 0x000000ae\n\t"
        "add                eax, 0x26\n\t"
        "push               eax\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall HomelessEatDinner__8VillagerFv(struct Villager* this)
{
    return 1;
}

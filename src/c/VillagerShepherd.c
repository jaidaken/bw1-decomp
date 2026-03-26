#include "Villager.h"

const float villager_shepherd_num_days_in_year_0x0099aa04 = 365.25f;
const float villager_shepherd_seconds_in_day_0x0099aa08 = 86400.0f;

uint32_t villager_shepherd_uint_0x00db9e50;
float villager_shepherd_seconds_in_year_0x00db9e4c;


__attribute__((no_ret))
void __cdecl globl_ct_0x00768b80(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x00768b94\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x00768b94:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x00768ba0"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((prefer_pop_cleanup))
void __cdecl crt_global_destruction_register_0x00768ba0(void)
{
    extern int __cdecl atexit(void (*)(void));
    atexit((void (*)(void))0x00407870);
}

extern void __cdecl FUN_00768bc0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x00768bb0(void)
{
    __attribute__((musttail)) return FUN_00768bc0__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_00768bc0__8VillagerFv(void)
{
    extern float __opaque_a asm("_villager_shepherd_seconds_in_day_0x0099aa08");
    extern float __opaque_b asm("_villager_shepherd_num_days_in_year_0x0099aa04");
    extern float __opaque_c asm("_villager_shepherd_seconds_in_year_0x00db9e4c");
    __opaque_c = __opaque_a * __opaque_b;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall VillagerBecomesShepherd__8VillagerFP5Flock(struct Villager* this, const void* edx, struct Flock* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "test               eax, eax\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x00768c03\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00768c2a\n\t"
        "push               0x0\n\t"
        "push               -0x1\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetFlock@Town@@QAEIW4LIVING_TYPE@@H@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00768c2a\n"
        "LAB__addr_0x00768c03:\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x30]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00768c0e\n\t"
        "cmp.s              ecx, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x00768c2a\n"
        "LAB__addr_0x00768c0e:\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetFlock@Living@@QAEXPAVFlock@@@Z\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000b8]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x30], esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ShepherdGotoFlock@Villager@@QAEIXZ\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00768c2a:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ShepherdLookForFlock__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00768c80\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "push               -0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetFlock@Town@@QAEIW4LIVING_TYPE@@H@Z\n\t"
        "mov.s              edi, eax\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00768c80\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000b8]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00768c67\n\t"
        "push               0x1\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x0052fb50\n"
        "LAB__addr_0x00768c67:\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetFlock@Living@@QAEXPAVFlock@@@Z\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000b8]\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x30], esi\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00768c80:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall FindClosestFlockAnimal__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} lea        edi, dword ptr [esi + 0x14]\n\t"
        "push               0x42480000\n\t"
        "push               edi\n\t"
        "call               _jmp_addr_0x0052ffd0\n\t"
        "add                esp, 0x08\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00768cbb\n\t"
        "push               esi\n\t"
        "push               0x42c80000\n\t"
        "push               edi\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x00530050\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00768cbd\n\t"
        "LAB__addr_0x00768cbb:\n\t"
        "xor.s              eax, eax\n\t"
        "LAB__addr_0x00768cbd:\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ShepherdMoveFlockToWater__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               0xa\n\t"
        "call               ?GetJobInfo@Villager@@QBEPAVGJobInfo@@E@Z\n\t"
        "%{disp32%} mov       edi, dword ptr [esi + 0x000000b8]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              ebx, eax\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp32%} je        LAB__addr_0x00768dad\n\t"
        "test               edi, edi\n\t"
        "%{disp32%} je        LAB__addr_0x00768dad\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?GetNearestWaterPos@Abode@@QAE_NAAUMapCoords@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00768d3a\n\t"
        "push               0x43c80000\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?FindNearestDrinkingWater@Abode@@QAEXM@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00768dad\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x0c]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?GetNearestWaterPos@Abode@@QAE_NAAUMapCoords@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00768dad\n"
        "LAB__addr_0x00768d3a:\n\t"
        "%{disp8%} lea        edx, dword ptr [edi + 0x14]\n\t"
        "mov                ecx, dword ptr [edx]\n\t"
        "%{disp8%} lea        eax, dword ptr [edi + 0x60]\n\t"
        "mov                dword ptr [eax], ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [edx + 0x04]\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x04], ecx\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x08], edx\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?SetDomainCentrePos@Flock@@QAEXABUMapCoords@@@Z\n\t"
        "push               0x60\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000118], 0x0384\n\t"
        "%{disp32%} mov       word ptr [esi + 0x0000011a], 0x005e\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "%{disp8%} mov        edi, dword ptr [edi + 0x3c]\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00768d88\n\t"
        "%{disp8%} mov        edi, dword ptr [edi + 0x08]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00768d8a\n"
        "LAB__addr_0x00768d88:\n\t"
        "xor.s              edi, edi\n"
        "LAB__addr_0x00768d8a:\n\t"
        "xor.s              edx, edx\n\t"
        "%{disp8%} mov        dx, word ptr [edi + 0x5a]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "push               edx\n\t"
        "call               ?SetSpeed@Villager@@QAEXJH@Z\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetStateAnim@Living@@QAEXXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x00768dad:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000c0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ShepherdWaitForFlock__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "dec                word ptr [esi + 0x00000118]\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x00000118]\n\t"
        "test               ax, ax\n\t"
        "%{disp8%} jne        LAB__addr_0x00768e22\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x0000011a]\n\t"
        "test               ax, ax\n\t"
        "%{disp8%} je         LAB__addr_0x00768e0d\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               eax\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "%{disp32%} mov       word ptr [esi + 0x0000011a], 0x0000\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00768e0d:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x5f\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000118], 0x0014\n\t"
        "call               dword ptr [eax + 0x8e8]\n"
        "LAB__addr_0x00768e22:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ShepherdGotoFlock__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "%{disp32%} mov       esi, dword ptr [edi + 0x000000b8]\n\t"
        "xor.s              ecx, ecx\n\t"
        "cmp.s              esi, ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00768ea6\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x40]\n\t"
        "cmp.s              eax, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00768ea6\n\t"
        "cmp                dword ptr [eax + 0x08], ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00768ea6\n\t"
        "push               0xa\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?GetJobInfo@Villager@@QBEPAVGJobInfo@@E@Z\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetJobActivity@GJobInfo@@QBEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00768ead\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFlockPos@Flock@@QAEPAUMapCoords@@XZ\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "push               0x000000bf\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x00768ea6:\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?ShepherdLookForFlock@Villager@@QAEIXZ\n"
        "LAB__addr_0x00768ead:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ShepherdTakesControlOfFlock__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "%{disp32%} mov       esi, dword ptr [edi + 0x000000b8]\n\t"
        "push               0xa\n\t"
        "call               ?GetJobInfo@Villager@@QBEPAVGJobInfo@@E@Z\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetJobActivity@GJobInfo@@QBEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00768f1a\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x00768f1a\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFlockPos@Flock@@QAEPAUMapCoords@@XZ\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x40]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00768ef4\n\t"
        "%{disp8%} mov        ebx, dword ptr [eax + 0x08]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00768ef6\n"
        "LAB__addr_0x00768ef4:\n\t"
        "xor.s              ebx, ebx\n"
        "LAB__addr_0x00768ef6:\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x0052fa50\n\t"
        "push               0x5f\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp32%} mov       word ptr [edi + 0x00000118], 0x0032\n\t"
        "call               ?SetupMoveToObject@Living@@QAEIPAVObject@@E@Z\n\t"
        "pop                ebx\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00768f1a:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
__attribute__((split_word_stores, XOR32rr_REV))
bool32_t __fastcall ShepherdReleasesControlOfFlock__8VillagerFv(struct Villager* this)
{
    if (__builtin_expect(*(void**)((char*)this + 0xb8) == 0, 0)) {
        return 0;
    }
    register void* vt asm("eax");
    vt = *(void**)this;
    asm volatile (
        "push               0x60"
        : "+r"(vt) :: "memory"
    );
    *(uint32_t*)((char*)this + 0x118) = 0x00240014;
    asm volatile (
        "call               dword ptr [eax + 0x8e8]"
        :: "a"(vt), "c"(this) : "edx", "memory"
    );
    return 1;
}

__attribute__((no_callee_saves))
bool32_t __fastcall ExitShepherding__8VillagerFUc(struct Villager* this, const void* edx, unsigned char param_1)
{
    bool32_t result;
    asm volatile (
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "and                ecx, 0x000000ff\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x96c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00768fa7\n\t"
        "push               esi\n\t"
        "%{disp32%} mov       esi, dword ptr [edi + 0x000000b8]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x00768f93\n\t"
        "%{disp8%} lea        edx, dword ptr [esi + 0x60]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetDomainCentrePos@Flock@@QAEXABUMapCoords@@@Z\n\t"
        "push               0x1\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x0052fb50\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x30], 0x00000000\n"
        "LAB__addr_0x00768f93:\n\t"
        "pop                esi\n\t"
        "%{disp32%} mov       dword ptr [edi + 0x000000b8], 0x00000000\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                edi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00768fa7:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                edi"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ShepherdDecideWhatToDoWithFlock__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "dec                word ptr [esi + 0x00000118]\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x00000118]\n\t"
        "test               ax, ax\n\t"
        "%{disp32%} jne       LAB__addr_0x00769064\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000b8]\n\t"
        "cmp                dword ptr [eax + 0x48], 0x02\n\t"
        "%{disp8%} jae        LAB__addr_0x00768feb\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000c0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x00768feb:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "add                ecx, 0x34\n\t"
        "call               ?GetInfo@TownDesire@@QBEPAVGTownDesireInfo@@K@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "mov.s              edi, eax\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetDesire@Town@@QAEMW4TOWN_DESIRE_INFO@@@Z\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x08]\n\t"
        "%{disp8%} fcomp      dword ptr [edi + 0x18]\n\t"
        "pop                edi\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00769058\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000b8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00769058\n\t"
        "cmp                dword ptr [eax + 0x48], 0x02\n\t"
        "%{disp8%} ja         LAB__addr_0x00769041\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x04]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p5]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x00769058\n"
        "LAB__addr_0x00769041:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000be\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x00769058:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x5c\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x00769064:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "pop                ecx"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ShepherdMoveFlockBack__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               ebx\n\t"
        "mov.s              ebx, ecx\n\t"
        "push               esi\n\t"
        "%{disp32%} mov       esi, dword ptr [ebx + 0x000000b8]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x007690c5\n\t"
        "push               edi\n\t"
        "%{disp8%} lea        edi, dword ptr [esi + 0x60]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetDomainCentrePos@Flock@@QAEXABUMapCoords@@@Z\n\t"
        "push               0x000000c0\n\t"
        "push               edi\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "%{disp8%} mov        esi, dword ptr [esi + 0x3c]\n\t"
        "test               esi, esi\n\t"
        "pop                edi\n\t"
        "%{disp8%} je         LAB__addr_0x007690a4\n\t"
        "%{disp8%} mov        esi, dword ptr [esi + 0x08]\n\t"
        "%{disp8%} jmp        LAB__addr_0x007690a6\n"
        "LAB__addr_0x007690a4:\n\t"
        "xor.s              esi, esi\n"
        "LAB__addr_0x007690a6:\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        ax, word ptr [esi + 0x5a]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, ebx\n\t"
        "push               eax\n\t"
        "call               ?SetSpeed@Villager@@QAEXJH@Z\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?SetStateAnim@Living@@QAEXXZ\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "ret\n"
        "LAB__addr_0x007690c5:\n\t"
        "pop                esi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall ShepherdMoveFlockToFood__8VillagerFv(struct Villager* this)
{
    return 1;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ShepherdTakeAnimalForSlaughter__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "%{disp32%} mov       edi, dword ptr [esi + 0x000000b8]\n\t"
        "test               edi, edi\n\t"
        "%{disp32%} je        LAB__addr_0x00769180\n\t"
        "push               esi\n\t"
        "push               0x42c80000\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x00530050\n\t"
        "mov.s              ebx, eax\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x00769180\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00769180\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0xd4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00769180\n\t"
        "push               0x1\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x0052fb50\n\t"
        "push               0x1\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp8%} mov        dword ptr [edi + 0x30], 0x00000000\n\t"
        "call               _jmp_addr_0x0052fe10\n\t"
        "mov.s              edi, eax\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x0052fa50\n\t"
        "%{disp8%} mov        dword ptr [edi + 0x30], esi\n\t"
        "%{disp8%} mov        word ptr [edi + 0x52], 0x0004\n\t"
        "%{disp8%} mov        dword ptr [edi + 0x58], 0x00000001\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000e4\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000118], 0x0014\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "ret\n"
        "LAB__addr_0x00769180:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x5f\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000118], 0x0014\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ShepherdCheckAnimalForSlaughter__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x24\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "dec                word ptr [esi + 0x00000118]\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x00000118]\n\t"
        "test               ax, ax\n\t"
        "push               edi\n\t"
        "%{disp32%} mov       edi, dword ptr [esi + 0x000000b8]\n\t"
        "%{disp32%} jg        LAB__addr_0x0076937f\n\t"
        "test               edi, edi\n\t"
        "%{disp32%} je        LAB__addr_0x0076936a\n\t"
        "cmp                dword ptr [edi + 0x48], 0x02\n\t"
        "%{disp8%} jae        LAB__addr_0x007691ef\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x5f\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000118], 0x0014\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24\n\t"
        "ret\n"
        "LAB__addr_0x007691ef:\n\t"
        "push               esi\n\t"
        "push               0x40c00000\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SlaughterAnimalIsClose@Villager@@QAEIMPAVLiving@@@Z\n\t"
        "mov.s              ebx, eax\n\t"
        "test               ebx, ebx\n\t"
        "%{disp32%} je        LAB__addr_0x00769332\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0076937f\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0xd4]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0076937f\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x18]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x864]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x18]\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        edi, dword ptr [esi + 0x14]\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], 0x00000000\n\t"
        "call               ?GetDistanceInMetres@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp32%} fcom      dword ptr [rdata_bytes + 0x241c]\n\t"
        "add                esp, 0x08\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x007692b3\n\t"
        "push               0x4\n\t"
        "fstp               st(0)\n\t"
        "push               0x1\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x20]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x30]\n\t"
        "push               edi\n\t"
        "push               ecx\n\t"
        "call               _jmp_addr_0x0074ed60\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], edx\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "add                esp, 0x14\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x08]\n\t"
        "push               0x000000e4\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "push               eax\n\t"
        "%{disp8%} jmp        LAB__addr_0x00769308\n"
        "LAB__addr_0x007692b3:\n\t"
        "%{disp32%} fcomp     dword ptr [rdata_bytes + 0x1651c]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x007692f8\n\t"
        "push               0x41a00000\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x2c]\n\t"
        "push               edi\n\t"
        "push               edx\n\t"
        "call               _jmp_addr_0x0074ee20\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "add                esp, 0x10\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "push               0x000000e4\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "push               ecx\n\t"
        "%{disp8%} jmp        LAB__addr_0x00769308\n"
        "LAB__addr_0x007692f8:\n\t"
        "push               0x61\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x1c]\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000118], 0x0005\n\t"
        "push               edx\n"
        "LAB__addr_0x00769308:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        ax, word ptr [ebx + 0x5a]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "push               eax\n\t"
        "call               ?SetSpeed@Villager@@QAEXJH@Z\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetStateAnim@Living@@QAEXXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24\n\t"
        "ret\n"
        "LAB__addr_0x00769332:\n\t"
        "%{disp8%} mov        edi, dword ptr [edi + 0x3c]\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076933e\n\t"
        "%{disp8%} mov        edi, dword ptr [edi + 0x08]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00769340\n"
        "LAB__addr_0x0076933e:\n\t"
        "xor.s              edi, edi\n"
        "LAB__addr_0x00769340:\n\t"
        "add                edi, 0x14\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "push               edi\n\t"
        "push               ecx\n\t"
        "call               ?GetAngleFromXZ@GUtils@@SAGABUMapCoords@@0@Z\n\t"
        "add                esp, 0x08\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetGameAngle__13MobileWallHugFUs@10\n\t"
        "pop                edi\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000118], 0x0014\n\t"
        "pop                esi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24\n\t"
        "ret\n"
        "LAB__addr_0x0076936a:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x5f\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000118], 0x0014\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x0076937f:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall ShepherdSlaughterAnimal__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "dec                word ptr [esi + 0x00000118]\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x00000118]\n\t"
        "test               ax, ax\n\t"
        "%{disp32%} mov       ebx, dword ptr [esi + 0x000000b8]\n\t"
        "%{disp8%} jg         LAB__addr_0x00769420\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x00769420\n\t"
        "push               edi\n\t"
        "push               esi\n\t"
        "push               0x40800000\n\t"
        "call               ?SlaughterAnimalIsClose@Villager@@QAEIMPAVLiving@@@Z\n\t"
        "mov.s              edi, eax\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076940e\n\t"
        "push               0x1\n\t"
        "push               edi\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               _jmp_addr_0x0052fb50\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "push               0x3\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x660]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "mov.s              ecx, esi\n\t"
        "push               eax\n\t"
        "call               ?PickupFood@Villager@@QAEXF@Z\n\t"
        "push               0xf\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp8%} mov        word ptr [edi + 0x58], 0x0000\n\t"
        "call               @SetupMoveToPos__6LivingFRC9MapCoordsUc@13\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x60\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       word ptr [esi + 0x0000011a], 0x0020\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x0076940e:\n\t"
        "pop                edi\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000118], 0x0014\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "ret\n"
        "LAB__addr_0x00769420:\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
__attribute__((no_callee_saves))
bool32_t __fastcall SlaughterAnimalIsClose__8VillagerFfP6Living(struct Villager* this, const void* edx, float param_1, struct Living* param_2)
{
    bool32_t result;
    asm volatile (
        "mov.s              eax, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x000000b8]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00769452\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x08]\n\t"
        "push               edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x08]\n\t"
        "push               edx\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x00530050\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x00769452:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall ShepherdFetchStray__8VillagerFv(struct Villager* this)
{
    return 1;
}

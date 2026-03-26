#include "Villager.h"

const float villager_dance_num_days_in_year_0x0099a950 = 365.25f;
const float villager_dance_seconds_in_day_0x0099a954 = 86400.0f;

uint32_t villager_dance_uint_0x00db9df4;
float villager_dance_seconds_in_year_0x00db9df8;

__attribute__((no_ret))
void __cdecl globl_ct_0x00759810(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x00759824\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x00759824:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x00759830"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((prefer_pop_cleanup))
void __cdecl crt_global_destruction_register_0x00759830(void)
{
    extern int __cdecl atexit(void (*)(void));
    atexit((void (*)(void))0x00407870);
}

extern void __cdecl FUN_00759850__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x00759840(void)
{
    __attribute__((musttail)) return FUN_00759850__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_00759850__8VillagerFv(void)
{
    extern float __opaque_a asm("_villager_dance_seconds_in_day_0x0099a954");
    extern float __opaque_b asm("_villager_dance_num_days_in_year_0x0099a950");
    extern float __opaque_c asm("_villager_dance_seconds_in_year_0x00db9df8");
    __opaque_c = __opaque_a * __opaque_b;
}

extern void __cdecl FUN_00759880__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x00759870(void)
{
    __attribute__((musttail)) return FUN_00759880__8VillagerFv();
}

void __cdecl FUN_00759880__8VillagerFv(void)
{
    villager_dance_uint_0x00db9df4 = 0xffffffff;
}

__attribute__((no_callee_saves, XOR32rr_REV))
struct Villager* __fastcall FindImmediateNeighbour__8VillagerFv(struct Villager* this)
{
    struct Villager* result;
    asm volatile (
        "sub                esp, 0x14\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], eax\n\t"
        "mov                edi, 0x00000031\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x00000001\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], 0x00000001\n\t"
        "mov                ebx, 0x00000002\n"
        "LAB__addr_0x007598c9:\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "call               ?InBounds@MapCoords@@QBEIXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x007598f7\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "call               ?GetFirstObjectMobile@MapCoords@@QBEPAVObject@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007598f7\n"
        "LAB__addr_0x007598e4:\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x28]\n\t"
        "cmp                dword ptr [ecx + 0x10], ebx\n\t"
        "%{disp8%} jne        LAB__addr_0x007598f0\n\t"
        "cmp.s              eax, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x0075991a\n"
        "LAB__addr_0x007598f0:\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x20]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007598e4\n"
        "LAB__addr_0x007598f7:\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x0c]\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "dec                edi\n\t"
        "call               ?Spiral@GUtils@@SAPBUJustMapXZ@@AAJ0@Z\n\t"
        "add                esp, 0x08\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x18]\n\t"
        "call               @__apl__9MapCoordsFRC9JustMapXZ@12\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x007598c9\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x0075991a:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x14"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall DanceForEditingPurposes__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [ecx + 0x000000d8]\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x5c]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x18]\n\t"
        "push               edx\n\t"
        "push               0x00000099\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "call               ?PerformDance@Living@@QAEIABUMapCoords@@EK@Z\n\t"
        "mov                eax, 0x00000001"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall DanceButNotWorship__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [ecx + 0x000000d8]\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x5c]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x18]\n\t"
        "push               edx\n\t"
        "push               0x000000c1\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "call               ?PerformDance@Living@@QAEIABUMapCoords@@EK@Z\n\t"
        "mov                eax, 0x00000001"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall MoveToDancePos__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000d8]\n\t"
        "xor.s              eax, eax\n\t"
        "cmp.s              ecx, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007599a7\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x007599a7:\n\t"
        "cmp                dword ptr [ecx + 0x7c], eax\n\t"
        "%{disp8%} je         LAB__addr_0x007599e8\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x04]\n\t"
        "push               eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x00000000\n\t"
        "call               _jmp_addr_0x0050d5f0\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CalculateDancePosition@Living@@QAE_NABUMapCoords@@PAU2@@Z\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x04]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "%{disp32%} lea       ecx, dword ptr [esi + 0x00000080]\n\t"
        "mov                dword ptr [ecx], edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x04], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x08], edx\n"
        "LAB__addr_0x007599e8:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?MoveToPos@Living@@QAEHXZ\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ControlledByCreature__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x18\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000d8]\n\t"
        "xor.s              ecx, ecx\n\t"
        "cmp.s              eax, ecx\n\t"
        "push               edi\n\t"
        "%{disp8%} je         LAB__addr_0x00759a7c\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x14]\n\t"
        "cmp.s              edx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00759a7c\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "add                edx, 0x14\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CalculateDancePosition@Living@@QAE_NABUMapCoords@@PAU2@@Z\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x08]\n\t"
        "%{disp8%} lea        edi, dword ptr [esi + 0x14]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?__ne@MapCoords@@QBE_NABV1@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00759a7c\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000d8]\n\t"
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x14]\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "call               dword ptr [edx + 0x104]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               @__eq__9MapCoordsCFRC9MapCoords@12\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00759a7c\n\t"
        "push               0x000000cc\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x0c]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupMoveToPos@Villager@@QAE_NABUMapCoords@@W4VILLAGER_STATES@@@Z\n"
        "LAB__addr_0x00759a7c:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x18"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ExitControlledByCreature__8VillagerFUc(struct Villager* this, const void* edx, unsigned char param_1)
{
    bool32_t result;
    asm volatile (
        "push               ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x08]\n\t"
        "cmp                bl, 0x18\n\t"
        "push               ebp\n\t"
        "mov.s              ebp, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00759ada\n\t"
        "cmp                bl, 0x0a\n\t"
        "%{disp8%} je         LAB__addr_0x00759ada\n\t"
        "%{disp8%} mov        eax, dword ptr [ebp + 0x00]\n\t"
        "mov.s              ecx, ebx\n\t"
        "and                ecx, 0x000000ff\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               dword ptr [eax + 0x970]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00759ada\n\t"
        "cmp                bl, -0x34\n\t"
        "%{disp32%} je        LAB__addr_0x00759b71\n\t"
        "cmp                bl, 0x5a\n\t"
        "%{disp32%} je        LAB__addr_0x00759b71\n\t"
        "cmp                bl, -0x5d\n\t"
        "%{disp32%} je        LAB__addr_0x00759b71\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00759ada:\n\t"
        "%{disp32%} mov       ecx, dword ptr [_CreatureList]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x00759b68\n"
        "LAB__addr_0x00759ae8:\n\t"
        "%{disp8%} mov        edx, dword ptr [ecx + 0x04]\n\t"
        "%{disp32%} mov       eax, dword ptr [edx + 0x00001090]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00759b00\n"
        "LAB__addr_0x00759af5:\n\t"
        "cmp                dword ptr [eax + 0x04], ebp\n\t"
        "%{disp8%} je         LAB__addr_0x00759b08\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00759af5\n"
        "LAB__addr_0x00759b00:\n\t"
        "mov                ecx, dword ptr [ecx]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00759b68\n\t"
        "%{disp8%} jmp        LAB__addr_0x00759ae8\n"
        "LAB__addr_0x00759b08:\n\t"
        "push               esi\n\t"
        "%{disp8%} mov        esi, dword ptr [ecx + 0x04]\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00001090]\n\t"
        "add                esi, 0x00001090\n\t"
        "xor.s              ebx, ebx\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00759b4b\n\t"
        "push               edi\n"
        "LAB__addr_0x00759b1f:\n\t"
        "cmp                dword ptr [eax + 0x04], ebp\n\t"
        "mov                edi, dword ptr [eax]\n\t"
        "%{disp8%} jne        LAB__addr_0x00759b42\n\t"
        "cmp                eax, dword ptr [esi]\n\t"
        "%{disp8%} jne        LAB__addr_0x00759b2e\n\t"
        "mov                dword ptr [esi], edi\n\t"
        "%{disp8%} jmp        LAB__addr_0x00759b30\n"
        "LAB__addr_0x00759b2e:\n\t"
        "mov                dword ptr [ebx], edi\n"
        "LAB__addr_0x00759b30:\n\t"
        "%{disp8%} mov        edx, dword ptr [esi + 0x04]\n\t"
        "dec                edx\n\t"
        "push               eax\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x04], edx\n\t"
        "call               ??3@YAXPAX@Z\n\t"
        "add                esp, 0x04\n\t"
        "%{disp8%} jmp        LAB__addr_0x00759b44\n"
        "LAB__addr_0x00759b42:\n\t"
        "mov.s              ebx, eax\n"
        "LAB__addr_0x00759b44:\n\t"
        "test               edi, edi\n\t"
        "mov.s              eax, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x00759b1f\n\t"
        "pop                edi\n"
        "LAB__addr_0x00759b4b:\n\t"
        "%{disp8%} mov        eax, dword ptr [ebp + 0x00]\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               dword ptr [eax + 0x978]\n\t"
        "test               eax, eax\n\t"
        "pop                esi\n\t"
        "%{disp8%} je         LAB__addr_0x00759b68\n\t"
        "%{disp8%} mov        edx, dword ptr [ebp + 0x00]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               dword ptr [edx + 0xb08]\n"
        "LAB__addr_0x00759b68:\n\t"
        ".byte              0x66, 0x81, 0xa5, 0xb4, 0x0, 0x0, 0x0, 0xfb, 0xff\n"
        "LAB__addr_0x00759b71:\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((prefer_push_before_ecx))
void __fastcall SetStateAfterFinishingDance__8VillagerFv(struct Living* this)
{
    typedef void (__attribute__((thiscall)) *fn_t)(struct Living*, int);
    fn_t fn = ((fn_t*)(*(void**)this))[0x8e8 / 4];
    fn(this, 0xa3);
}

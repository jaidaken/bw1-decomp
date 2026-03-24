#include "Villager.h"
#include "VillagerStateTableInfo.h"
#include <float.h>

const float villager_states_float_max_0x0099aa0c = FLT_MAX;
const float villager_states_float10p0_0x0099aa10 = 10.0f;
const float villager_states_float_pi_0x0099aa14 = 3.1415927f;
const float villager_states_num_days_in_year_0x0099aa18 = 365.25f;
const float villager_states_seconds_in_day_0x0099aa1c = 86400.0f;

__attribute__((aligned(8))) struct RTTITypeDescriptor __RTTITypeDescriptor__23GVillagerStateTableInfo = {
    .pVFTable = &__vt__9type_info,
    .spare = 0,
    .name = ".?AVGVillagerStateTableInfo@@",
};
__attribute__((aligned(4))) char s_VillagerStates_cpp[] = "C:\\dev\\MP\\Black\\VillagerStates.cpp";

uint32_t villager_states_uint_0x00db9e58;
float villager_states_seconds_in_year_0x00db9e5c;
uint8_t villager_states_byte_0x00db9e60;
uint32_t villager_states_uint_0x00db9e64;
struct GVillagerStateTableInfo GVillagerStateTableInfos[VILLAGER_STATE_LAST_STATE];
float villager_states_float_0x00dcb154;
uint8_t villager_states_byte_0x00db9e58;
float villager_states_half_pi_0x00dcb15c;

__attribute__((no_ret))
void __cdecl globl_ct_0x00769470(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x00769484\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x00769484:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x00769490"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((prefer_pop_cleanup))
void __cdecl crt_global_destruction_register_0x00769490(void)
{
    extern int __cdecl atexit(void (*)(void));
    atexit((void (*)(void))0x00407870);
}

extern void __cdecl FUN_007694b0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x007694a0(void)
{
    __attribute__((musttail)) return FUN_007694b0__8VillagerFv();
}

void __cdecl FUN_007694b0__8VillagerFv(void)
{
    (void)villager_states_uint_0x00db9e58;
    (void)villager_states_seconds_in_year_0x00db9e5c;
    (void)villager_states_byte_0x00db9e60;
    (void)villager_states_uint_0x00db9e64;
    (void)GVillagerStateTableInfos;
    villager_states_float_0x00dcb154 = 0.125f;
}

extern void __cdecl FUN_007694d0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x007694c0(void)
{
    __attribute__((musttail)) return FUN_007694d0__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_007694d0__8VillagerFv(void)
{
    extern float __opaque_4d0_a asm("_villager_states_float_pi_0x0099aa14");
    extern float __opaque_4d0_b asm("_rdata_float0p5");
    extern float __opaque_4d0_c asm("_villager_states_half_pi_0x00dcb15c");
    __opaque_4d0_c = __opaque_4d0_a * __opaque_4d0_b;
}

extern void __cdecl FUN_00769500__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x007694f0(void)
{
    __attribute__((musttail)) return FUN_00769500__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_00769500__8VillagerFv(void)
{
    extern float __opaque_500_a asm("_villager_states_seconds_in_day_0x0099aa1c");
    extern float __opaque_500_b asm("_villager_states_num_days_in_year_0x0099aa18");
    extern float __opaque_500_c asm("_villager_states_seconds_in_year_0x00db9e5c");
    __opaque_500_c = __opaque_500_a * __opaque_500_b;
}

extern void __cdecl FUN_00769530__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x00769520(void)
{
    __attribute__((musttail)) return FUN_00769530__8VillagerFv();
}

void __cdecl FUN_00769530__8VillagerFv(void)
{
    (void)villager_states_uint_0x00db9e58;
    (void)villager_states_seconds_in_year_0x00db9e5c;
    (void)villager_states_byte_0x00db9e60;
    villager_states_uint_0x00db9e64 = 0xffffffff;
}

__attribute__((no_ret))
void __cdecl globl_ct_0x00769540(void)
{
    asm("call               _FUN_00769550__8VillagerFv");                    // 0x00769540    e80b000000
    asm("{disp32} jmp       _FUN_007695a0__8VillagerFv");                    // 0x00769545    e956000000
    __builtin_unreachable();
}

void __cdecl FUN_00769550__8VillagerFv(void)
{
    asm("mov                eax, OFFSET _GVillagerStateTableInfos");         // 0x00769550    b8689edb00
    asm("mov                ecx, 0x000000ff");                               // 0x00769555    b9ff000000
    asm("xor.s              edx, edx");                                      // 0x0076955a    33d2
    asm("LAB__addr_0x0076955c:");
    asm(".byte 0xc7, 0x00, 0x44, 0x9a\n.byte 0x8a, 0x00");                   // 0x0076955c    c700449a8a00 (movl               $??_7Base@@6B@, (%eax))
    asm("{disp8} mov        dword ptr [eax + 0x04], edx");                   // 0x00769562    895004
    asm("{disp8} mov        dword ptr [eax + 0x08], edx");                   // 0x00769565    895008
    asm("mov                dword ptr [eax], 0x0099aa24");                   // 0x00769568    c70024aa9900
    asm("add                eax, 0x00000114");                               // 0x0076956e    0514010000
    asm("dec                ecx");                                           // 0x00769573    49
    asm("{disp8} jne        LAB__addr_0x0076955c");                          // 0x00769574    75e6
}

__attribute__((no_callee_saves))
struct GBaseInfo* __fastcall GetBaseInfo__23GVillagerStateTableInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1)
{
    *param_1 = 0xff;
    return (struct GBaseInfo*)GVillagerStateTableInfos;
}

__attribute__((prefer_pop_cleanup))
void __cdecl FUN_007695a0__8VillagerFv(void)
{
    extern int __cdecl atexit(void (*)(void));
    atexit((void (*)(void))0x007695b0);
}

void __cdecl FUN_007695b0__8VillagerFv(void)
{
    asm("{disp32} mov       cl, byte ptr [_villager_states_byte_0x00db9e60]"); // 0x007695b0    8a0d609edb00
    asm("mov                al, 0x01");                                      // 0x007695b6    b001
    asm("test               al, cl");                                        // 0x007695b8    84c8
    asm("{disp8} jne        LAB__addr_0x007695e2");                          // 0x007695ba    7526
    asm("push               esi");                                           // 0x007695bc    56
    asm("or.s               cl, al");                                        // 0x007695bd    0ac8
    asm("push               edi");                                           // 0x007695bf    57
    asm("{disp32} mov       byte ptr [_villager_states_byte_0x00db9e60], cl"); // 0x007695c0    880d609edb00
    asm("mov                esi, 0x00dcb154");                               // 0x007695c6    be54b1dc00
    asm("mov                edi, 0x000000ff");                               // 0x007695cb    bfff000000
    asm("LAB__addr_0x007695d0:");
    asm("sub                esi, 0x00000114");                               // 0x007695d0    81ee14010000
    asm("mov.s              ecx, esi");                                      // 0x007695d6    8bce
    asm("call               _jmp_addr_0x00436960");                          // 0x007695d8    e883d3ccff
    asm("dec                edi");                                           // 0x007695dd    4f
    asm("{disp8} jne        LAB__addr_0x007695d0");                          // 0x007695de    75f0
    asm("pop                edi");                                           // 0x007695e0    5f
    asm("pop                esi");                                           // 0x007695e1    5e
    asm("LAB__addr_0x007695e2:");
}

__attribute__((no_callee_saves))
void __fastcall __dt__23GVillagerStateTableInfoFv(struct Base* this, const void* edx, uint32_t param_1)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               _jmp_addr_0x00436960\n\t"
        "test               byte ptr [esp + 0x08], 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0076960d\n\t"
        "push               0x00000114\n\t"
        "push               esi\n\t"
        "call               ??3Base@@SAXPAXK@Z\n\t"
        "add                esp, 0x08\n"
        "LAB__addr_0x0076960d:\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi"
        :: "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__23GVillagerStateTableInfo = {
    .pTypeDescriptor = &__RTTITypeDescriptor__23GVillagerStateTableInfo,
    .numContainedBases = 0x00000002,
    .where = {
        .mdisp = 0x00000000,
        .pdisp = 0xFFFFFFFF,
        .vdisp = 0x00000000,
    },
    .attributes = 0x0000000,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassArray __RTTIBaseClassArray__23GVillagerStateTableInfo = {
    .arrayOfBaseClassDescriptors = {
        &__RTTIBaseClassDescriptor__23GVillagerStateTableInfo,
        &__RTTIBaseClassDescriptor__9GBaseInfo,
        &__RTTIBaseClassDescriptor__4Base,
        NULL,
    }
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__23GVillagerStateTableInfo = {
  .signature = 0x00000000,
  .attributes = 0x00000000,
  .numBaseClasses = 0x00000003,
  .pBaseClassArray = &__RTTIBaseClassArray__23GVillagerStateTableInfo,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTICompleteObjectLocator __RTTICompleteObjectLocator__23GVillagerStateTableInfo = {
  .signature = 0x00000000,
  .offset = 0x00000000,
  .cdOffset = 0x00000000,
  .pTypeDescriptor = &__RTTITypeDescriptor__23GVillagerStateTableInfo,
  .pClassDescriptor = &__RTTIClassHierarchyDescriptor__23GVillagerStateTableInfo,
};

const struct RTTICompleteObjectLocator* const p__RTTICompleteObjectLocator__23GVillagerStateTableInfo = &__RTTICompleteObjectLocator__23GVillagerStateTableInfo;

const struct GBaseInfoVftable __vt__23GVillagerStateTableInfo = {
  Serialise__4BaseFR7Archive,
  __dt__23GVillagerStateTableInfoFv,
  Delete__4BaseFv,
  ToBeDeleted__4BaseFi,
  Get3DSoundPos__4BaseFP7LHPoint,
  CleanUpForSerialisation__4BaseFv,
  Dump__4BaseFv,
  GetDebugText__9GBaseInfoCFv,
  GetDebugColor__9GBaseInfoCFv,
  GetBaseInfo__23GVillagerStateTableInfoFRUl,
  UpdateValue__9GBaseInfoFfUlUl,
};

__attribute__((no_callee_saves, XOR32rr_REV))
uint32_t __fastcall GotoStoragePitForDropOff__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x10\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076967a\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0xd4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076967a\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x104]\n\t"
        "push               0x20\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x0c]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10\n\t"
        "ret\n"
        "LAB__addr_0x0076967a:\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x04]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetResourceHeld@Villager@@QAE_NAAW4RESOURCE_TYPE@@@Z\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007696a9\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007696a9\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10\n\t"
        "ret\n"
        "LAB__addr_0x007696a9:\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetResourceDropoffPos@Villager@@QAEPAVGameThingWithPos@@W4RESOURCE_TYPE@@@Z\n\t"
        "push               0x20\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x0c]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
uint32_t __fastcall ArrivesAtStoragePitForDropOff__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x14\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x08]\n\t"
        "mov.s              esi, ecx\n\t"
        "push               eax\n\t"
        "call               ?GetResourceHeld@Villager@@QAE_NAAW4RESOURCE_TYPE@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], eax\n\t"
        "%{disp32%} je        LAB__addr_0x007697d7\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov.s              edi, eax\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076974d\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0xd4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076974d\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x10]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?AtStructureAddResource@Villager@@QAEIPAVMultiMapFixed@@W4RESOURCE_TYPE@@AAK_N@Z\n\t"
        "cmp                eax, 0x24\n\t"
        "%{disp32%} je        LAB__addr_0x007697e6\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               0x000000a3\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x104]\n\t"
        "push               eax\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x14\n\t"
        "ret\n"
        "LAB__addr_0x0076974d:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007697d7\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        edx, dword ptr [esi + 0x14]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], 0x00000000\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetTemporaryResourceStorePotOrPos@Town@@QAEPAXABUMapCoords@@AAU2@W4RESOURCE_TYPE@@@Z\n\t"
        "mov.s              edi, eax\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x007697d7\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x85c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007697ff\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x9c]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007697f1\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x0c]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?DropFood@Villager@@QAEGG@Z\n"
        "LAB__addr_0x007697d7:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x007697e6:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x14\n\t"
        "ret\n"
        "LAB__addr_0x007697f1:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?DropWood@Villager@@QAEGG@Z\n\t"
        "%{disp8%} jmp        LAB__addr_0x007697d7\n"
        "LAB__addr_0x007697ff:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xb04]\n\t"
        "mov.s              ecx, esi\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x14"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall GotoStoragePitForFood__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076988a\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0xd4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076988a\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x04]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x104]\n\t"
        "push               0x22\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x08]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x0076988a:\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetResourceDropoffPos@Villager@@QAEPAVGameThingWithPos@@W4RESOURCE_TYPE@@@Z\n\t"
        "push               0x22\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall ArrivesAtStoragePitForFood__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               0x000000a3\n\t"
        "mov.s              esi, ecx\n\t"
        "push               0x000000a3\n\t"
        "call               ?GetAmountOfFoodRequiredForMeal@Villager@@QAEIXZ\n\t"
        "push               eax\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ArrivesAtStoragePitForResource@Villager@@QAEIW4RESOURCE_TYPE@@KW4VILLAGER_STATES@@1@Z\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ArrivesAtStoragePitForResource__8VillagerF13RESOURCE_TYPEUl15VILLAGER_STATES15VILLAGER_STATES(struct Villager* this, const void* edx, enum RESOURCE_TYPE param_1, unsigned long param_2, enum VILLAGER_STATES param_3, enum VILLAGER_STATES param_4)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x24\n\t"
        "push               ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x30]\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "xor.s              ebp, ebp\n\t"
        "cmp.s              ebx, ebp\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} jbe       LAB__addr_0x00769b0a\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x007699be\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0xd4]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x007699be\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x38]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x98]\n\t"
        "cmp.s              ebx, eax\n\t"
        ".byte              0x72, 0x14\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x98]\n\t"
        "mov.s              ebx, eax\n"
        "LAB__addr_0x0076993b:\n\t"
        "cmp.s              ebx, ebp\n\t"
        "%{disp8%} jbe        LAB__addr_0x007699a3\n\t"
        "push               ebp\n\t"
        "push               ebx\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?AtStructureRemoveResource@Villager@@QAEIPAVMultiMapFixed@@W4RESOURCE_TYPE@@KPA_N@Z\n\t"
        "cmp                eax, 0x24\n\t"
        "%{disp8%} jne        LAB__addr_0x00769960\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24\n\t"
        "ret                0x0010\n"
        "LAB__addr_0x00769960:\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x007699a3\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x40]\n\t"
        "cmp.s              edi, ebp\n\t"
        "%{disp8%} je         LAB__addr_0x007699a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "push               edi\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x2c]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x104]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24\n\t"
        "ret                0x0010\n"
        "LAB__addr_0x007699a3:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x44]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24\n\t"
        "ret                0x0010\n"
        "LAB__addr_0x007699be:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00769b0a\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ebp\n\t"
        "%{disp8%} mov        ebp, dword ptr [esp + 0x38]\n\t"
        "push               ebp\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], 0x00000000\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetTemporaryResourceStorePotOrPos@Town@@QAEPAXABUMapCoords@@AAU2@W4RESOURCE_TYPE@@@Z\n\t"
        "mov.s              edi, eax\n\t"
        "test               edi, edi\n\t"
        "%{disp32%} je        LAB__addr_0x00769b0a\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "push               esi\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x20]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x834]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x1c]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3400]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x24]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3400]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x1c]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3408]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3404]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x24]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3408]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], eax\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3404]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x28]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x2c], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x30], 0x00000000\n\t"
        "call               ?GetAltitude@LH3DIsland@@SAMABULH3DMapCoords@@@Z\n\t"
        "%{disp8%} fsubr      dword ptr [esp + 0x20]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x1c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x85c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00769ae4\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0xa0]\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x820]\n\t"
        "push               eax\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PickupResource@Villager@@QAEXW4RESOURCE_TYPE@@FE@Z\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x40]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00769ac9\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00769b10\n"
        "LAB__addr_0x00769ac9:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x44]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24\n\t"
        "ret                0x0010\n"
        "LAB__addr_0x00769ae4:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xb04]\n\t"
        "mov.s              ecx, esi\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000024\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24\n\t"
        "ret                0x0010\n"
        "LAB__addr_0x00769b0a:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x44]\n"
        "LAB__addr_0x00769b10:\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall ArrivesAtHomeWithFood__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00769b6a\n\t"
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
        "LAB__addr_0x00769b6a:\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?ArrivesHome@Villager@@QAEIXZ\n\t"
        "pop                edi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall CheckTrader__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x0000011c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00769b8f\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00769b8f:\n\t"
        "%{disp32%} fld       dword ptr [eax + 0x000001a0]\n\t"
        "%{disp32%} fadd      dword ptr [eax + 0x0000010c]\n\t"
        "%{disp32%} fadd      dword ptr [eax + 0x000000c8]\n\t"
        "%{disp32%} fld       dword ptr [eax + 0x0000019c]\n\t"
        "%{disp32%} fadd      dword ptr [eax + 0x00000108]\n\t"
        "%{disp32%} fadd      dword ptr [eax + 0x000000c4]\n\t"
        "fcomp              st(1)\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x00769bcc\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], 0x00000000\n\t"
        "push               0x0\n\t"
        "%{disp8%} jmp        LAB__addr_0x00769be5\n"
        "LAB__addr_0x00769bcc:\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x40\n\t"
        "%{disp8%} jne        LAB__addr_0x00769bfe\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], 0x00000001\n\t"
        "push               0x1\n"
        "LAB__addr_0x00769be5:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CheckTraderPickUpOrDropOff@Villager@@QAEIW4RESOURCE_TYPE@@@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00769bfe:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetTraderNothingToDo@Villager@@QAEIXZ\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CheckMissionary__8VillagerFv(struct Villager* this)
{
    return 0;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall CheckTraderPickUpOrDropOff__8VillagerF13RESOURCE_TYPE(struct Villager* this, const void* edx, enum RESOURCE_TYPE param_1)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x24\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x28]\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x24]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetResourceDropoffPos@Villager@@QAEPAVGameThingWithPos@@W4RESOURCE_TYPE@@@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              edi, eax\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x0000011c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetTown@Villager@@QAEXPAVTown@@@Z\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x30]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x18]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetResourceDropoffPos@Villager@@QAEPAVGameThingWithPos@@W4RESOURCE_TYPE@@@Z\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetTown@Villager@@QAEXPAVTown@@@Z\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x30]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetResourceHeld@Villager@@QAE_NAAW4RESOURCE_TYPE@@@Z\n\t"
        "%{disp32%} mov       ecx, dword ptr [edi + 0x00000274]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], eax\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "push               0x459c4000\n\t"
        "%{disp8%} fidiv      dword ptr [esp + 0x10]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x18]\n\t"
        "push               edx\n\t"
        "add                esi, 0x14\n\t"
        "push               esi\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n\t"
        "%{disp8%} fsub       dword ptr [esp + 0x14]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x18]\n\t"
        "call               ?GetDistanceInMetres@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "add                esp, 0x04\n\t"
        "fstp               dword ptr [esp]\n\t"
        "call               _GetDistanceModifier__6GUtilsFff@8\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "add                esp, 0x08\n\t"
        "push               0x459c4000\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x24]\n\t"
        "push               eax\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "push               esi\n\t"
        "call               ?GetDistanceInMetres@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x04]\n\t"
        "add                esp, 0x04\n\t"
        "call               _GetDistanceModifier__6GUtilsFff@8\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x14]\n\t"
        "add                esp, 0x08\n\t"
        "pop                edi\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x04]\n\t"
        "pop                esi\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "mov                eax, 0x000000df\n\t"
        "%{disp8%} je         LAB__addr_0x00769d0c\n\t"
        "mov                eax, 0x000000e0\n"
        "LAB__addr_0x00769d0c:\n\t"
        "add                esp, 0x24"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ArrivesAtStoragePitForTraderPickUp__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x14\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000118]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], eax\n\t"
        "%{disp8%} je         LAB__addr_0x00769d40\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00769d4b\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x14\n\t"
        "ret\n"
        "LAB__addr_0x00769d40:\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00000274]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00769d54\n"
        "LAB__addr_0x00769d4b:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00000278]\n"
        "LAB__addr_0x00769d54:\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x08]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x04]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "call               ?GetResourceHeld@Villager@@QAE_NAAW4RESOURCE_TYPE@@@Z\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x10]\n\t"
        "push               0x000000a3\n\t"
        "push               0x000000a3\n\t"
        "%{disp8%} fsubr      dword ptr [esp + 0x10]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "push               eax\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x10]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ArrivesAtStoragePitForResource@Villager@@QAEIW4RESOURCE_TYPE@@KW4VILLAGER_STATES@@1@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00769daf\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetTraderNothingToDo@Villager@@QAEIXZ\n"
        "LAB__addr_0x00769daf:\n\t"
        "pop                esi\n\t"
        "add                esp, 0x14"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ArrivesAtStoragePitForTraderDropOff__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp32%} mov       ebx, dword ptr [esi + 0x0000011c]\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "mov.s              edi, eax\n\t"
        "call               ?SetTown@Villager@@QAEXPAVTown@@@Z\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cx, word ptr [esi + 0x000000f6]\n\t"
        "xor.s              edx, edx\n\t"
        "%{disp32%} mov       dx, word ptr [esi + 0x000000f4]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edx\n\t"
        "call               ?ArrivesAtStoragePitForDropOff@Villager@@QAEIXZ\n\t"
        "%{disp8%} mov        bp, word ptr [esp + 0x18]\n\t"
        "sub                bp, word ptr [esi + 0x000000f6]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000f4]\n\t"
        "sub                word ptr [esp + 0x10], ax\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetTown@Villager@@QAEXPAVTown@@@Z\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00769e57\n\t"
        "movsx              edx, word ptr [esp + 0x10]\n\t"
        "movsx              ecx, bp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], ecx\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "%{disp32%} fsubr     dword ptr [edi + 0x0000070c]\n\t"
        "%{disp32%} fstp      dword ptr [edi + 0x0000070c]\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x18]\n\t"
        "%{disp32%} fsubr     dword ptr [edi + 0x00000708]\n\t"
        "%{disp32%} fstp      dword ptr [edi + 0x00000708]\n"
        "LAB__addr_0x00769e57:\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x00769e8b\n\t"
        "movsx              ecx, word ptr [esp + 0x10]\n\t"
        "movsx              eax, bp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], ecx\n\t"
        "%{disp32%} fadd      dword ptr [ebx + 0x0000070c]\n\t"
        "%{disp32%} fstp      dword ptr [ebx + 0x0000070c]\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x18]\n\t"
        "%{disp32%} fadd      dword ptr [ebx + 0x00000708]\n\t"
        "%{disp32%} fstp      dword ptr [ebx + 0x00000708]\n"
        "LAB__addr_0x00769e8b:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x14]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall SetTraderNothingToDo__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x0000011c]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "mov.s              edi, eax\n\t"
        "call               ?SetTown@Villager@@QAEXPAVTown@@@Z\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetDiscipleNothingToDo@Villager@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x00769ed1\n\t"
        "call               ?SetTown@Villager@@QAEXPAVTown@@@Z\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00769ed1:\n\t"
        "call               ?SetTown@Villager@@QAEXPAVTown@@@Z\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall SetupBreederDisciple__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x2c\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "mov.s              ebx, ecx\n\t"
        "call               ?IsPregnant@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00769f09\n\t"
        "mov                eax, dword ptr [ebx]\n\t"
        "push               0x24\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x2c\n\t"
        "ret\n"
        "LAB__addr_0x00769f09:\n\t"
        "mov                edx, dword ptr [ebx]\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "xor.s              ebp, ebp\n\t"
        "cmp.s              ecx, ebp\n\t"
        "%{disp32%} je        LAB__addr_0x0076a19d\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x0000061c]\n\t"
        "%{disp32%} mov       esi, dword ptr [ecx + 0x00000650]\n\t"
        "%{disp8%} mov        edx, dword ptr [ecx + 0x28]\n\t"
        "sub.s              eax, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x10]\n\t"
        "%{disp32%} fcomp     dword ptr [edx + 0x0000014c]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp32%} je        LAB__addr_0x0076a19d\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00000618]\n\t"
        "sub                eax, dword ptr [ecx + 0x00000644]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x10]\n\t"
        "%{disp32%} fld       dword ptr [edx + 0x0000014c]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x2418]\n\t"
        "fcompp\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp32%} jne       LAB__addr_0x0076a19d\n\t"
        "push               edi\n\t"
        "%{disp32%} mov       edi, dword ptr [ecx + 0x00000754]\n\t"
        "xor.s              esi, esi\n\t"
        "cmp.s              edi, ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x43960000\n\t"
        "%{disp8%} je         LAB__addr_0x00769fb9\n\t"
        "%{disp8%} lea        ebp, dword ptr [ebx + 0x14]\n"
        "LAB__addr_0x00769f8b:\n\t"
        "%{disp8%} lea        ecx, dword ptr [edi + 0x14]\n\t"
        "push               ecx\n\t"
        "push               ebp\n\t"
        "call               ?GetDistanceInMetres@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fcom       dword ptr [esp + 0x18]\n\t"
        "add                esp, 0x08\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00769fab\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "mov.s              esi, edi\n\t"
        "%{disp8%} jmp        LAB__addr_0x00769fad\n"
        "LAB__addr_0x00769fab:\n\t"
        "fstp               st(0)\n"
        "LAB__addr_0x00769fad:\n\t"
        "%{disp32%} mov       edi, dword ptr [edi + 0x0000009c]\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x00769f8b\n\t"
        "xor.s              ebp, ebp\n"
        "LAB__addr_0x00769fb9:\n\t"
        "cmp.s              esi, ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], 0x00000000\n\t"
        "pop                edi\n\t"
        "%{disp32%} jne       LAB__addr_0x0076a073\n\t"
        "push               ebp\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x24]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?GetResourceDropoffPos@Villager@@QAEPAVGameThingWithPos@@W4RESOURCE_TYPE@@@Z\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "push               0x00000159\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "push               0x00c24630\n\t"
        "push               0x40000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], eax\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fadd      dword ptr [rdata_bytes + 0x19c50]\n\t"
        "add                esp, 0x08\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               0x00000159\n\t"
        "push               0x00c24630\n\t"
        "push               0x40c90fdb\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "add                esp, 0x08\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x28]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               ecx\n\t"
        "call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "add                esp, 0x0c\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x30]\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "call               @__pl__9MapCoordsCFRC9MapCoords@16\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "push               0x000000e1\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], eax\n\t"
        "call               ?SetupMoveToPos@Villager@@QAE_NABUMapCoords@@W4VILLAGER_STATES@@@Z\n\t"
        "%{disp32%} jmp       LAB__addr_0x0076a17b\n"
        "LAB__addr_0x0076a073:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x2c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x104]\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        edx, dword ptr [esi + 0x14]\n\t"
        "push               edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], eax\n\t"
        "call               ?Get3DAngleFromXZ@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "push               0x00000160\n\t"
        "push               0x00c24630\n\t"
        "push               0x2\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "add                esp, 0x14\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x3f800000\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a0d0\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0xbf800000\n"
        "LAB__addr_0x0076a0d0:\n\t"
        "push               0x00000160\n\t"
        "push               0x00c24630\n\t"
        "push               0x3f490fdb\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x1c]\n\t"
        "add                esp, 0x0c\n\t"
        "push               0x00000161\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x10]\n\t"
        "push               0x00c24630\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "call               dword ptr [eax + 0x64]\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float0p5]\n\t"
        "push               ecx\n\t"
        "fstp               dword ptr [esp]\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x1c]\n\t"
        "add                esp, 0x0c\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x64]\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float0p5]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x10]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "add                esp, 0x0c\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x24]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "call               @__pl__9MapCoordsCFRC9MapCoords@16\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "push               0x000000e1\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x18]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "push               esi\n\t"
        "mov.s              ecx, ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], eax\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n"
        "LAB__addr_0x0076a17b:\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x14]\n\t"
        "push               edx\n\t"
        "%{disp32%} lea       ecx, dword ptr [ebx + 0x0000011c]\n\t"
        "%{disp32%} mov       dword ptr [ebx + 0x00000118], ebp\n\t"
        "call               ?Init@JustWholeMapXZ@@QAEXABUMapCoords@@@Z\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x2c\n\t"
        "ret\n"
        "LAB__addr_0x0076a19d:\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x2c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall BreederDisciple__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?IsPregnant@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a200\n\t"
        "push               eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "add                ecx, 0x34\n\t"
        "call               _jmp_addr_0x007465d0\n\t"
        "cmp                dword ptr [eax + 0x08], 0x10\n\t"
        "%{disp8%} je         LAB__addr_0x0076a200\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        ax, word ptr [esi + 0x58]\n\t"
        "test               ax, ax\n\t"
        "%{disp8%} lea        ecx, dword ptr [eax + -0x01]\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], cx\n\t"
        "%{disp8%} jg         LAB__addr_0x0076a20c\n\t"
        "push               0x000000e1\n\t"
        "%{disp32%} lea       edx, dword ptr [esi + 0x0000011c]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupWander@Villager@@QAEIAAUJustWholeMapXZ@@W4VILLAGER_STATES@@@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0076a200:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x24\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n"
        "LAB__addr_0x0076a20c:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall MissionaryDisciple__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "mov.s              esi, ecx\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n\t"
        "push               -0x1\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x0074dd70\n\t"
        "mov.s              edi, eax\n\t"
        "add                esp, 0x14\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076a27b\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "push               eax\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x00740fd0\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ForceMoveVillagerToAbode@Villager@@QAEXPAVAbode@@@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000ea\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0076a27b:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall EnterBreeder__8VillagerFUcUc(struct Villager* this, const void* edx, unsigned char param_1, unsigned char param_2)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x14]\n\t"
        "test               ch, -0x80\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a2c5\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "push               eax\n\t"
        "push               0x1e\n\t"
        "push               esi\n\t"
        "call               ?CreateReaction@Reaction@@SAPAV1@PAVGameThingWithPos@@EPAVGPlayer@@H@Z\n\t"
        "add                esp, 0x10\n\t"
        "LAB__addr_0x0076a2c5:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_tail_call))
bool32_t __fastcall ExitBreeder__8VillagerFUc(struct Villager* this, const void* edx, unsigned char param_1)
{
    extern void __cdecl jmp_addr_0x006e4780_fwd(void*, int) asm("_jmp_addr_0x006e4780");
    jmp_addr_0x006e4780_fwd(this, 0x1e);
    return 1;
}

__attribute__((no_callee_saves, XOR32rr_REV))
uint32_t __fastcall AtStructureRemoveResource__8VillagerFP13MultiMapFixed13RESOURCE_TYPEUlPb(struct Villager* this, const void* edx, struct MultiMapFixed* param_1, enum RESOURCE_TYPE param_2, unsigned long param_3, bool* param_4)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x18\n\t"
        "push               ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x24]\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x2c]\n\t"
        "mov.s              esi, ecx\n\t"
        "push               0x1\n\t"
        "xor.s              eax, eax\n\t"
        "push               esi\n\t"
        "push               ebx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x28]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], eax\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x8d4]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edx\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x08]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "call               dword ptr [eax + 0x60]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "call               @IsCloseToEqual__9MapCoordsCFRC9MapCoordsf@16\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a384\n\t"
        "%{disp8%} mov        ebp, dword ptr [esp + 0x34]\n\t"
        "push               ebp\n\t"
        "push               ebx\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetResourceFrom@Villager@@QAEIPAVObject@@W4RESOURCE_TYPE@@F@Z\n\t"
        "movsx              eax, ax\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a372\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x18\n\t"
        "ret                0x0010\n"
        "LAB__addr_0x0076a372:\n\t"
        "cmp.s              eax, ebp\n\t"
        "pop                edi\n\t"
        "sbb.s              eax, eax\n\t"
        "pop                esi\n\t"
        "and                eax, 0x23\n\t"
        "pop                ebp\n\t"
        "inc                eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x18\n\t"
        "ret                0x0010\n"
        "LAB__addr_0x0076a384:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xb04]\n\t"
        "mov.s              ecx, esi\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000024\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x18"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
uint32_t __fastcall AtStructureAddResource__8VillagerFP13MultiMapFixed13RESOURCE_TYPERUlb(struct Villager* this, const void* edx, struct MultiMapFixed* param_1, enum RESOURCE_TYPE param_2, unsigned long* param_3, bool param_4)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x18\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "xor.s              ebp, ebp\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], ebp\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x2c]\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "mov.s              ebx, eax\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "cmp.s              ebx, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a3df\n\t"
        "xor.s              ebx, ebx\n"
        "LAB__addr_0x0076a3df:\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x0076a3ec\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               _jmp_addr_0x0064a9c0\n\t"
        "mov.s              ebp, eax\n"
        "LAB__addr_0x0076a3ec:\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x30]\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "push               0x0\n\t"
        "push               esi\n\t"
        "push               ebx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x28]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x8d4]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edx\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x08]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "call               dword ptr [eax + 0x130]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "call               @IsCloseToEqual__9MapCoordsCFRC9MapCoordsf@16\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a484\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "xor.s              eax, eax\n\t"
        "test               ebp, ebp\n\t"
        "setne              al\n\t"
        "push               eax\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               ebp\n\t"
        "%{disp8%} mov        ebp, dword ptr [esp + 0x44]\n\t"
        "%{disp8%} mov        ecx, dword ptr [ebp + 0x00]\n\t"
        "push               ecx\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x9c]\n\t"
        "mov.s              edi, eax\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076a478\n\t"
        "push               edi\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?DropResource@Villager@@QAEGW4RESOURCE_TYPE@@G@Z\n\t"
        "%{disp8%} mov        dword ptr [ebp + 0x00], edi\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x18\n\t"
        "ret                0x0010\n"
        "LAB__addr_0x0076a478:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x18\n\t"
        "ret                0x0010\n"
        "LAB__addr_0x0076a484:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xb04]\n\t"
        "mov.s              ecx, esi\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x34]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                dword ptr [ecx], 0x00000000\n\t"
        "mov                eax, 0x00000024\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x18"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall SetDying__8VillagerFv(struct Object* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x000000b4]\n\t"
        "and                cl, 0x01\n\t"
        "cmp                cl, 0x01\n\t"
        "mov.s              edi, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076a506\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x5b0]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0xe\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "or                 byte ptr [esi + 0xb4], 1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?DeleteDependancys@Villager@@QAEXXZ\n\t"
        "or                 byte ptr [esi + 0xb4], 0x30\n\t"
        "LAB__addr_0x0076a506:\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076a530\n\t"
        "%{disp32%} mov       ecx, dword ptr [edi + 0x00000748]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0076a530\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0xd4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076a530\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       cx, word ptr [eax + 0x00000294]\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], cx\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076a53e\n\t"
        "LAB__addr_0x0076a530:\n\t"
        "%{disp8%} mov        edx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       ax, word ptr [edx + 0x00000290]\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], ax\n\t"
        "LAB__addr_0x0076a53e:\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x000000e0]\n\t"
        "mov                ecx, 0x00000040\n\t"
        "test               cl, al\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a55f\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "dec                dword ptr [eax + 0x00205a54]\n\t"
        "or                 word ptr [esi + 0xe0], cx\n\t"
        "LAB__addr_0x0076a55f:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall Dying__8VillagerFv(struct Living* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x444]\n\t"
        "cmp                eax, 0x07\n\t"
        "%{disp8%} je         LAB__addr_0x0076a58d\n\t"
        "push               0x1\n\t"
        "push               0xf\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PlayAnimThenSetState@Living@@QAEXEK@Z\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076a599\n"
        "LAB__addr_0x0076a58d:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0xf\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x0076a599:\n\t"
        "test               byte ptr [esi + 0x000000e0], 0x04\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a5cd\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076a5be\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00000748]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a5cd\n"
        "LAB__addr_0x0076a5be:\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x17\n\t"
        "push               esi\n\t"
        "call               ?CreateReaction@Reaction@@SAPAV1@PAVGameThingWithPos@@EPAVGPlayer@@H@Z\n\t"
        "add                esp, 0x10\n"
        "LAB__addr_0x0076a5cd:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall Dead__8VillagerFv(struct Living* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x44]\n\t"
        "test               ecx, ecx\n\t"
        "push               edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076a5f9\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "push               0x0\n\t"
        "call               dword ptr [eax + 0xc]\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x44], 0x00000000\n"
        "LAB__addr_0x0076a5f9:\n\t"
        "%{disp32%} mov       al, byte ptr [_villager_states_byte_0x00db9e58]\n\t"
        "test               al, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a626\n\t"
        "%{disp32%} mov       ecx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "or                 al, 1\n\t"
        "%{disp32%} mov       byte ptr [_villager_states_byte_0x00db9e58], al\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "mov                eax, 0x000001ff\n\t"
        "cmp.s              edx, eax\n\t"
        "%{disp8%} jg         LAB__addr_0x0076a61c\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x0076a61c:\n\t"
        "%{disp8%} mov        ecx, dword ptr [ecx + eax * 0x4 + 0x04]\n\t"
        "%{disp32%} mov       dword ptr [data_bytes + 0x405164], ecx\n"
        "LAB__addr_0x0076a626:\n\t"
        "test               byte ptr [esi + 0x25], 0x04\n\t"
        "%{disp32%} jne       LAB__addr_0x0076a770\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0xf8]\n\t"
        "cmp                eax, dword ptr [data_bytes + 0x405164]\n\t"
        "%{disp32%} je        LAB__addr_0x0076a750\n\t"
        "push               ecx\n\t"
        "mov.s              eax, esp\n\t"
        "push               0x3f800000\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "mov                dword ptr [eax], 0xffffffff\n\t"
        "call               ?CreateSmokyStuff@Object@@QAEIJMULH3DColor@@@Z\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "call               ?IsWater@MapCoords@@QBEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x0076a750\n\t"
        "%{disp32%} mov       eax, dword ptr [data_bytes + 0x4f3a80]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a6df\n\t"
        "%{disp32%} mov       eax, dword ptr [data_bytes + 0x517508]\n\t"
        "cmp                dword ptr [eax], 0x000000f4\n\t"
        "%{disp8%} jle        LAB__addr_0x0076a68c\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x000003d4]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076a68f\n"
        "LAB__addr_0x0076a68c:\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n"
        "LAB__addr_0x0076a68f:\n\t"
        "%{disp32%} mov       dword ptr [data_bytes + 0x4f3a80], ecx\n\t"
        "cmp                dword ptr [eax], 0x000000f7\n\t"
        "%{disp8%} jle        LAB__addr_0x0076a6a5\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x000003e0]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076a6a8\n"
        "LAB__addr_0x0076a6a5:\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n"
        "LAB__addr_0x0076a6a8:\n\t"
        "%{disp32%} mov       dword ptr [data_bytes + 0x4f3a84], ecx\n\t"
        "cmp                dword ptr [eax], 0x000000f5\n\t"
        "%{disp8%} jle        LAB__addr_0x0076a6be\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x000003d8]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076a6c1\n"
        "LAB__addr_0x0076a6be:\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n"
        "LAB__addr_0x0076a6c1:\n\t"
        "%{disp32%} mov       dword ptr [data_bytes + 0x4f3a88], ecx\n\t"
        "cmp                dword ptr [eax], 0x000000f8\n\t"
        "%{disp8%} jle        LAB__addr_0x0076a6d7\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x000003e4]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076a6da\n"
        "LAB__addr_0x0076a6d7:\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x04]\n"
        "LAB__addr_0x0076a6da:\n\t"
        "%{disp32%} mov       dword ptr [data_bytes + 0x4f3a8c], eax\n"
        "LAB__addr_0x0076a6df:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8d0]\n\t"
        "cmp                eax, dword ptr [edi + 0x00000138]\n\t"
        "%{disp8%} jae        LAB__addr_0x0076a720\n\t"
        "push               0x00000238\n\t"
        "push               0x00c24630\n\t"
        "push               0xc\n\t"
        "call               ___nw__FUl\n\t"
        "add                esp, 0x0c\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076a750\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       edx, dword ptr [ecx + 0x00000204]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "push               0x1\n\t"
        "push               edx\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, eax\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076a74b\n"
        "LAB__addr_0x0076a720:\n\t"
        "push               0x0000023b\n\t"
        "push               0x00c24630\n\t"
        "push               0xc\n\t"
        "call               ___nw__FUl\n\t"
        "mov.s              edi, eax\n\t"
        "add                esp, 0x0c\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076a750\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "push               0x0\n\t"
        "call               dword ptr [edx + 0x2c]\n\t"
        "push               eax\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x40]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n"
        "LAB__addr_0x0076a74b:\n\t"
        "call               _jmp_addr_0x00828790\n"
        "LAB__addr_0x0076a750:\n\t"
        "%{disp32%} mov       edx, dword ptr [data_bytes + 0x405164]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "push               edx\n\t"
        "push               edx\n\t"
        "call               dword ptr [eax + 0xf4]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "xor.s              edx, edx\n\t"
        "call               dword ptr [eax + 0xc4]\n"
        "LAB__addr_0x0076a770:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?Dead@PuzzleHorse@@UAE_NXZ\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall Drowning__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "test               byte ptr [esi + 0x25], 0x40\n\t"
        "%{disp8%} je         LAB__addr_0x0076a78f\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], 0x000a\n\t"
        "LAB__addr_0x0076a78f:\n\t"
        "dec                word ptr [esi + 0x58]\n\t"
        "%{disp8%} mov        ax, word ptr [esi + 0x58]\n\t"
        "test               ax, ax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a7d0\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x6c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076a7b9\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x6c]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a7bf\n\t"
        "LAB__addr_0x0076a7b9:\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000104]\n\t"
        "LAB__addr_0x0076a7bf:\n\t"
        "push               0x1\n\t"
        "push               0x3c23d70a\n\t"
        "push               eax\n\t"
        "push               0x6\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?VillagerDead@Villager@@QAEXW4DEATH_REASON@@PAVGPlayer@@MH@Z\n\t"
        "LAB__addr_0x0076a7d0:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall MakeScaredStiff__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x000002a8]\n\t"
        "push               0x0000025c\n\t"
        "push               0x00c24630\n\t"
        "push               eax\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x10]\n\t"
        "push               0x0000025c\n\t"
        "push               0x00c24630\n\t"
        "push               0x40a00000\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x1c]\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fadd      dword ptr [rdata_bytes + 0x2414]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x1c]\n\t"
        "add                esp, 0x18\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0076a869\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x000002a8]\n\t"
        "push               0x0000025c\n\t"
        "push               0x00c24630\n\t"
        "push               ecx\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x10]\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076a886\n"
        "LAB__addr_0x0076a869:\n\t"
        "push               0x0000025c\n\t"
        "push               0x00c24630\n\t"
        "push               0x40a00000\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fadd      dword ptr [rdata_bytes + 0x2414]\n\t"
        "add                esp, 0x0c\n"
        "LAB__addr_0x0076a886:\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x59\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], ax\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ScaredStiff@Villager@@QAEIXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x08"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, insert_redundant_cmp))
bool32_t __fastcall ScaredStiff__8VillagerFv(struct Villager* this)
{
    extern bool32_t __fastcall __opaque_GoHome(struct Villager*) asm("?GoHome@Villager@@QAEIXZ");
    int16_t* counter = (int16_t*)((char*)this + 0x58);
    --(*counter);
    if (__builtin_expect(*counter == 0, 1)) {
        __opaque_GoHome(this);
    }
    return 1;
}

__attribute__((no_callee_saves))
bool32_t __fastcall VagrantStart__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x28\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "%{disp8%} lea        edi, dword ptr [esi + 0x14]\n\t"
        "push               0x43480000\n\t"
        "mov.s              ecx, edi\n\t"
        "call               @GetNearestTown__9MapCoordsCFf@12\n\t"
        "mov.s              ebx, eax\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x0076a92a\n\t"
        "push               ebp\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?GetTribe@Town@@QBEPAVGTribeInfo@@XZ\n\t"
        "mov.s              ecx, esi\n\t"
        "mov.s              ebp, eax\n\t"
        "call               ?GetTribe@Villager@@QAEPAVGTribeInfo@@XZ\n\t"
        "cmp.s              ebp, eax\n\t"
        "pop                ebp\n\t"
        "%{disp8%} jne        LAB__addr_0x0076a92a\n\t"
        "push               esi\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?AddVillagerToTown@Town@@QAEIPAVVillager@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076a92a\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x28\n\t"
        "ret\n"
        "LAB__addr_0x0076a92a:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        ebx, dword ptr [esi + 0x28]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x11c]\n\t"
        "%{disp32%} fcomp     dword ptr [ebx + 0x0000035c]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0076a9c3\n\t"
        "push               0x0000027f\n\t"
        "push               0x00c24630\n\t"
        "push               0x40a00000\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "add                esp, 0x08\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               0x0000027f\n\t"
        "push               0x00c24630\n\t"
        "push               0x40c90fdb\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "add                esp, 0x08\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x30]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               eax\n\t"
        "call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "add                esp, 0x0c\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               @__pl__9MapCoordsCFRC9MapCoords@16\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x10]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetTentPos@Villager@@QAEPAVTown@@AAUMapCoords@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0076aa53\n\t"
        "push               0x000000ee\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x28\n\t"
        "ret\n"
        "LAB__addr_0x0076a9c3:\n\t"
        "push               0x00000287\n\t"
        "push               0x00c24630\n\t"
        "push               0x3f490fdb\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp32%} fsub      dword ptr [rdata_bytes + 0x1dca0]\n\t"
        "add                esp, 0x0c\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "call               dword ptr [edx + 0x508]\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x0c]\n\t"
        "push               0x00000288\n\t"
        "push               0x00c24630\n\t"
        "push               0x41a00000\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x18]\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x18]\n\t"
        "%{disp32%} fadd      dword ptr [rdata_bytes + 0x2414]\n\t"
        "add                esp, 0x08\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x2c]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "add                esp, 0x0c\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x20]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               @__pl__9MapCoordsCFRC9MapCoords@16\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "call               ?InBounds@MapCoords@@QBEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076aa53\n\t"
        "push               0x00000082\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x20]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n"
        "LAB__addr_0x0076aa53:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x28"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

extern bool32_t __fastcall GoHome(struct Villager* this) asm("?GoHome@Villager@@QAEIXZ");

bool32_t __fastcall MornDeath__8VillagerFv(struct Villager* this)
{
    __attribute__((musttail)) return GoHome(this);
}

bool32_t __fastcall EatOutside__8VillagerFv(struct Villager* this)
{
    return 1;
}

__attribute__((no_callee_saves))
float __fastcall GetImportance__8VillagerFv(struct Object* this)
{
    float result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x8d0]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x00], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x00]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3418]\n\t"
        "add                esp, 0x08"
        : "=t"(result) : "c"(this) : "eax", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall SetupInspectObject__8VillagerFP6Object(struct Villager* this, const void* edx, struct Object* param_1)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x3c\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x48]\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x0c]\n\t"
        "push               ecx\n\t"
        "%{disp32%} mov       dword ptr [edi + 0x00000118], esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x7f0]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0076aafc\n\t"
        "%{disp8%} lea        edx, dword ptr [esi + 0x14]\n\t"
        "mov                eax, dword ptr [edx]\n\t"
        "%{disp8%} mov        ecx, dword ptr [edx + 0x04]\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], edx\n"
        "LAB__addr_0x0076aafc:\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ebx, dword ptr [edi + 0x14]\n\t"
        "push               ebx\n\t"
        "call               ?GetDistanceInMetres@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x54]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "add                esp, 0x08\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x64]\n\t"
        "%{disp8%} fsubr      dword ptr [esp + 0x4c]\n\t"
        "%{disp32%} fcomp     dword ptr [rdata_bytes + 0x26e4]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp32%} jne       LAB__addr_0x0076ac1f\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x0c]\n\t"
        "push               ebx\n\t"
        "push               eax\n\t"
        "call               ?GetAngleFromXZ@GUtils@@SAGABUMapCoords@@0@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x54], eax\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x54]\n\t"
        "add                esp, 0x08\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x4c]\n\t"
        "call               dword ptr [edx + 0x64]\n\t"
        "%{disp32%} fadd      dword ptr [rdata_bytes + 0x26e4]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x4c]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x34]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "call               _jmp_addr_0x0074d620\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x3c]\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x10]\n\t"
        "mov.s              esi, eax\n\t"
        "call               _jmp_addr_0x006050d0\n\t"
        "fld                dword ptr [eax]\n\t"
        "fadd               dword ptr [esi]\n\t"
        "%{disp8%} fld        dword ptr [eax + 0x04]\n\t"
        "%{disp8%} fadd       dword ptr [esi + 0x04]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x1c]\n\t"
        "%{disp8%} fld        dword ptr [eax + 0x08]\n\t"
        "%{disp8%} fadd       dword ptr [esi + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x2c], 0x00000000\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x20]\n\t"
        "fld                st(0)\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3400]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x20]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3400]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], eax\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3408]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], eax\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3404]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x20]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3408]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x30], eax\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3404]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x30]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x34], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x38], 0x00000000\n\t"
        "call               ?GetAltitude@LH3DIsland@@SAMABULH3DMapCoords@@@Z\n\t"
        "%{disp8%} fsubr      dword ptr [esp + 0x1c]\n\t"
        "push               0x000000e9\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x28]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x30]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x3c\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0076ac1f:\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               0x000000e9\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x3c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall InspectObject__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "%{disp32%} mov       edi, dword ptr [esi + 0x00000118]\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076ac5a\n\t"
        "push               0x1\n\t"
        "push               edi\n\t"
        "call               ?LookAtObject@Living@@QAEIPAVGameThingWithPos@@K@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076aca3\n"
        "LAB__addr_0x0076ac5a:\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @IsReadyForNewAnimation__6LivingFUl@12\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076aca3\n\t"
        "cmp                byte ptr [esi + 0x000000f2], 0x04\n\t"
        "%{disp8%} jne        LAB__addr_0x0076ac94\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0076ac94\n\t"
        "test               byte ptr [edi + 0x24], 0x02\n\t"
        "%{disp8%} je         LAB__addr_0x0076ac94\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000118]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076ac87\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0076ac87:\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupBuildingObject@Villager@@QAEIPAVMultiMapFixed@@@Z\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0076aca3\n"
        "LAB__addr_0x0076ac94:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n"
        "LAB__addr_0x0076aca3:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
int __fastcall ExitInFlying__8VillagerF15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    int result;
    asm volatile (
        "%{disp8%} mov        al, byte ptr [esp + 0x04]\n\t"
        "cmp                al, 0x18\n\t"
        "%{disp8%} je         LAB__addr_0x0076accd\n\t"
        "cmp                al, 0x0b\n\t"
        "%{disp8%} je         LAB__addr_0x0076accd\n\t"
        "cmp                al, 0x0e\n\t"
        "%{disp8%} je         LAB__addr_0x0076accd\n\t"
        "cmp                al, 0x0f\n\t"
        "%{disp8%} je         LAB__addr_0x0076accd\n\t"
        "cmp                al, 0x10\n\t"
        "%{disp8%} je         LAB__addr_0x0076accd\n\t"
        "xor.s              eax, eax\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0076accd:\n\t"
        "mov                eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall EnterSex__8VillagerFUcUc(struct Villager* this, const void* edx, unsigned char param_1, unsigned char param_2)
{
    return 1;
}

__attribute__((no_callee_saves))
bool32_t __fastcall SetupWander__8VillagerFR14JustWholeMapXZ15VILLAGER_STATES(struct Villager* this, const void* edx, struct JustWholeMapXZ* param_1, enum VILLAGER_STATES param_2)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x10\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x14]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x0c]\n\t"
        "call               _jmp_addr_0x00603070\n\t"
        "push               0x000002f4\n\t"
        "push               0x00c24630\n\t"
        "push               0x40c90fdb\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "push               0x000002f5\n\t"
        "push               0x00c24630\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x18]\n\t"
        "push               0x41000000\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x1c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x30]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x30]\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x28]\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x0074d510\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x40]\n\t"
        "add                esp, 0x24\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x0c]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "push               0x000002f9\n\t"
        "push               0x00c24630\n\t"
        "push               0x28\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "add                esp, 0x0c\n\t"
        "add                eax, 0x1e\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], ax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall ExitSex__8VillagerFUc(struct Villager* this, const void* edx, unsigned char param_1)
{
    bool32_t result;
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
        "%{disp8%} jne        LAB__addr_0x0076add2\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000118]\n\t"
        "cmp.s              ecx, eax\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076add2\n\t"
        "cmp                ecx, dword ptr [data_bytes + 0x30db1c]\n\t"
        "%{disp8%} jbe        LAB__addr_0x0076add2\n\t"
        "%{disp32%} mov       dl, byte ptr [ecx + 0x0000008c]\n\t"
        "cmp                dl, byte ptr [esi + 0x0000008c]\n\t"
        "%{disp8%} jne        LAB__addr_0x0076add2\n\t"
        "%{disp32%} mov       dword ptr [ecx + 0x00000118], eax\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "push               0x7c\n\t"
        "call               dword ptr [eax + 0x8e8]\n"
        "LAB__addr_0x0076add2:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall InHand__8VillagerFv(struct Living* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076adfd\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "or                 byte ptr [eax + 0x7c], 0x10\n"
        "LAB__addr_0x0076adfd:\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "call               ?IsInACreaturesHand@Villager@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x0076af79\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @FindCloseObjectsForInteract__8VillagerFP35LHOrderedLinkedList_12SortedObject_RC9MapCoords@16\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0076af67\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x10]\n\t"
        "test               eax, eax\n\t"
        "mov.s              ebx, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0076af67\n"
        "LAB__addr_0x0076ae42:\n\t"
        "mov                edi, dword ptr [ebx]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x0063a1b0\n\t"
        "mov.s              ebp, eax\n\t"
        "test               ebp, ebp\n\t"
        "%{disp32%} je        LAB__addr_0x0076aedc\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x7f4]\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "push               esi\n\t"
        "push               ebp\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x644]\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp8%} mov        cx, word ptr [esi + 0x24]\n\t"
        "not                cx\n\t"
        "mov.s              ebp, eax\n\t"
        "shr                ecx, 0xa\n\t"
        "test               cl, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0076aebe\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076aebe\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076aebe\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x4a0]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076aebe\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xaf4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076aebe\n\t"
        "test               byte ptr [esi + 0x000000e0], -0x80\n\t"
        "%{disp8%} je         LAB__addr_0x0076aed3\n"
        "LAB__addr_0x0076aebe:\n\t"
        "cmp                ebp, 0x0b\n\t"
        "%{disp8%} jne        LAB__addr_0x0076aedc\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076aef9\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076aedc\n"
        "LAB__addr_0x0076aed3:\n\t"
        "cmp                ebp, 0x09\n\t"
        "%{disp8%} je         LAB__addr_0x0076aeec\n\t"
        "test               ebp, ebp\n\t"
        "%{disp8%} jne        LAB__addr_0x0076aef9\n"
        "LAB__addr_0x0076aedc:\n\t"
        "%{disp8%} mov        ebx, dword ptr [ebx + 0x04]\n\t"
        "test               ebx, ebx\n\t"
        "%{disp32%} je        LAB__addr_0x0076af67\n\t"
        "%{disp32%} jmp       LAB__addr_0x0076ae42\n"
        "LAB__addr_0x0076aeec:\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000011c], eax\n"
        "LAB__addr_0x0076aef9:\n\t"
        "push               0x0\n\t"
        "push               ebp\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetVillagerDisciple@Villager@@QAEIPAVGameThing@@W4VILLAGER_DISCIPLE@@H@Z\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x0076afc7\n"
        "LAB__addr_0x0076af10:\n\t"
        "mov                esi, dword ptr [ecx]\n\t"
        "xor.s              edx, edx\n\t"
        "test               ecx, ecx\n\t"
        "mov.s              eax, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x0076afc7\n"
        "LAB__addr_0x0076af1e:\n\t"
        "cmp                dword ptr [eax], esi\n\t"
        "%{disp8%} je         LAB__addr_0x0076af2d\n\t"
        "mov.s              edx, eax\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x04]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076af1e\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076af56\n"
        "LAB__addr_0x0076af2d:\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} jne        LAB__addr_0x0076af3a\n\t"
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ecx\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076af40\n"
        "LAB__addr_0x0076af3a:\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [edx + 0x04], ecx\n"
        "LAB__addr_0x0076af40:\n\t"
        "push               eax\n\t"
        "call               ??3@YAXPAX@Z\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x14]\n\t"
        "add                esp, 0x04\n\t"
        "dec                eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n"
        "LAB__addr_0x0076af56:\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x0076af10\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x0076af67:\n\t"
        "%{disp32%} mov       edx, dword ptr [esi + 0x0000010c]\n\t"
        "push               0x0\n\t"
        "push               edx\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetVillagerDisciple@Villager@@QAEIPAVGameThing@@W4VILLAGER_DISCIPLE@@H@Z\n"
        "LAB__addr_0x0076af79:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0076afc7\n"
        "LAB__addr_0x0076af81:\n\t"
        "mov                esi, dword ptr [ecx]\n\t"
        "xor.s              edx, edx\n\t"
        "test               ecx, ecx\n\t"
        "mov.s              eax, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0076afc7\n"
        "LAB__addr_0x0076af8b:\n\t"
        "cmp                dword ptr [eax], esi\n\t"
        "%{disp8%} je         LAB__addr_0x0076af9a\n\t"
        "mov.s              edx, eax\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x04]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076af8b\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076afc3\n"
        "LAB__addr_0x0076af9a:\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} jne        LAB__addr_0x0076afa7\n\t"
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ecx\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076afad\n"
        "LAB__addr_0x0076afa7:\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [edx + 0x04], ecx\n"
        "LAB__addr_0x0076afad:\n\t"
        "push               eax\n\t"
        "call               ??3@YAXPAX@Z\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x14]\n\t"
        "add                esp, 0x04\n\t"
        "dec                eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n"
        "LAB__addr_0x0076afc3:\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x0076af81\n"
        "LAB__addr_0x0076afc7:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall EnterInHand__8VillagerF15VILLAGER_STATES15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1, enum VILLAGER_STATES param_2)
{
    uint32_t result;
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [ecx + 0x000000f2]\n\t"
        "cmp                eax, 0x07\n\t"
        "%{disp8%} jne        LAB__addr_0x0076afef\n\t"
        "xor.s              eax, eax\n\t"
        "LAB__addr_0x0076afef:\n\t"
        "%{disp32%} mov       dword ptr [ecx + 0x0000010c], eax\n\t"
        "mov                eax, 0x00000001"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
int __fastcall ExitInHand__8VillagerF15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    int result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "push               eax\n\t"
        "call               ?ExitInHand@Living@@UAEHW4VILLAGER_STATES@@@Z\n\t"
        "mov.s              esi, eax\n\t"
        "cmp                esi, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0076b024\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076b024\n\t"
        "and                byte ptr [eax + 0x7c], -0x11\n"
        "LAB__addr_0x0076b024:\n\t"
        "pop                edi\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall IsInACreaturesHand__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [_CreatureList]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076b04d\n"
        "LAB__addr_0x0076b039:\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp32%} mov       edx, dword ptr [edx + 0x00000160]\n\t"
        "cmp                dword ptr [edx + 0x28], ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0076b050\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076b039\n"
        "LAB__addr_0x0076b04d:\n\t"
        "xor.s              eax, eax\n\t"
        "ret\n"
        "LAB__addr_0x0076b050:\n\t"
        "mov                eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall SetupWaitForCounter__8VillagerFUs15VILLAGER_STATES(struct Villager* this, const void* edx, unsigned short param_1, enum VILLAGER_STATES param_2)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x0c]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               ecx\n\t"
        "push               0x39\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8dc]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0076b086\n\t"
        "%{disp8%} mov        dx, word ptr [esp + 0x08]\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], dx\n\t"
        "pop                esi\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x0076b086:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
uint32_t __fastcall SetupPauseForASecond__8VillagerF15VILLAGER_STATES(struct Villager* this, const void* edx, enum VILLAGER_STATES state)
{
    uint32_t result;
    asm volatile (
        "%{disp8%} mov edx, dword ptr [esp + 0x04]\n\t"
        "mov eax, dword ptr [ecx]\n\t"
        "push edx\n\t"
        "push 0x000000ef\n\t"
        "call dword ptr [eax + 0x8dc]\n\t"
        "dec eax\n\t"
        "neg eax\n\t"
        ".byte 0x1b, 0xc0\n\t"
        "inc eax"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall PauseForASecond__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               0x1\n\t"
        "call               @IsReadyForNewAnimation__6LivingFUl@12\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076b0c5\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetTopStateToFinal@Living@@QAEXXZ\n\t"
        "LAB__addr_0x0076b0c5:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall SetupPanicReaction__8VillagerFP8ReactionR9MapCoords(struct Villager* this, const void* edx, struct Reaction* param_1, struct MapCoords* param_2)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x18\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "push               0x0\n\t"
        "call               ?SetupGoAndHideInNearbyBuilding@Villager@@QAEIPAVGameThingWithPos@@@Z\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp32%} je        LAB__addr_0x0076b1ad\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x30]\n\t"
        "push               esi\n\t"
        "%{disp32%} lea       ecx, dword ptr [edi + 0x0000010c]\n\t"
        "call               ?Init@JustWholeMapXZ@@QAEXABUMapCoords@@@Z\n\t"
        "%{disp8%} lea        ebx, dword ptr [edi + 0x14]\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "call               ?Get3DAngleFromXZ@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x38]\n\t"
        "push               0x0000038a\n\t"
        "push               0x00c24630\n\t"
        "push               0x3f490fdb\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x40]\n\t"
        "%{disp32%} fsub      dword ptr [rdata_bytes + 0x1dca0]\n\t"
        "add                esp, 0x14\n\t"
        "push               0x0000038b\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x34]\n\t"
        "push               0x00c24630\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x38]\n\t"
        "call               ?GetInfo@Reaction@@QBEPAVReactionInfo@@XZ\n\t"
        "mov.s              ecx, esi\n\t"
        "mov.s              ebp, eax\n\t"
        "call               ?GetInfo@Reaction@@QBEPAVReactionInfo@@XZ\n\t"
        "%{disp8%} fld        dword ptr [ebp + 0x44]\n\t"
        "%{disp8%} fsub       dword ptr [eax + 0x40]\n\t"
        "push               ecx\n\t"
        "fstp               dword ptr [esp]\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x2c]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetInfo@Reaction@@QBEPAVReactionInfo@@XZ\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} fadd       dword ptr [eax + 0x40]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x30]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x1c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x2c]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "add                esp, 0x0c\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               @__pl__9MapCoordsCFRC9MapCoords@16\n\t"
        "push               0x1\n\t"
        "push               0x000000f0\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x18]\n\t"
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x005f10b0\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n"
        "LAB__addr_0x0076b1ad:\n\t"
        "pop                edi\n\t"
        "add                esp, 0x18"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall PanicReaction__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               0x2\n\t"
        "%{disp32%} lea       eax, dword ptr [esi + 0x0000010c]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x0c]\n\t"
        "call               _jmp_addr_0x00603030\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @LookAtPos__6LivingFRC9MapCoordsUl@16\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076b1f2\n\t"
        "push               0x1\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PlayAnimThenSetState@Living@@QAEXEK@Z\n"
        "LAB__addr_0x0076b1f2:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall GotoCongregateInTownAfterEmergency__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x18\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076b214\n\t"
        "pop                esi\n\t"
        "add                esp, 0x18\n\t"
        "ret\n"
        "LAB__addr_0x0076b214:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetCongregationPos@Town@@QAEPAUMapCoords@@PAU2@@Z\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x0000061c]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00000618]\n\t"
        "add                eax, 0x00000610\n\t"
        "add.s              ecx, edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x04]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x2850c]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0076b296\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x0000061c]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00000618]\n\t"
        "add                eax, 0x00000610\n\t"
        "add.s              ecx, edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x04]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x2850c]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076b29c\n"
        "LAB__addr_0x0076b296:\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n"
        "LAB__addr_0x0076b29c:\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x1e658]\n\t"
        "push               ecx\n\t"
        "%{disp32%} fadd      dword ptr [rdata_bytes + 0x2414]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               0x000003a1\n\t"
        "push               0x00c24630\n\t"
        "push               0x40c90fdb\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "add                esp, 0x08\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x0c]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               edx\n\t"
        "call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "add                esp, 0x0c\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "call               @__apl__9MapCoordsFRC9MapCoords@12\n\t"
        "push               0x000000f3\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x18"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall CongregateInTownAfterEmergency__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076b34f\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?IsInStateOfEmergency@Town@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076b34f\n\t"
        "push               0x000003b0\n\t"
        "push               0x00c24630\n\t"
        "push               0xc\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "add                esp, 0x0c\n\t"
        "neg                eax\n\t"
        "sbb.s              eax, eax\n\t"
        "and                eax, 0x000000ce\n\t"
        "add                eax, 0x24\n\t"
        "push               0x1\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PlayAnimThenSetState@Living@@QAEXEK@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0076b34f:\n\t"
        "push               0x000003ac\n\t"
        "push               0x00c24630\n\t"
        "push               0x5\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "add                esp, 0x0c\n\t"
        "neg                eax\n\t"
        "sbb.s              eax, eax\n\t"
        "and                eax, 0x4f\n\t"
        "add                eax, 0x000000a3\n\t"
        "push               0x1\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PlayAnimThenSetState@Living@@QAEXEK@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall BeingEaten__8VillagerFv(struct Living* this)
{
    bool32_t result;
    asm volatile (
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "dec                word ptr [esi + 0x58]\n\t"
        "%{disp8%} mov        ax, word ptr [esi + 0x58]\n\t"
        "test               ax, ax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076b3e0\n\t"
        "test               byte ptr [esi + 0x25], 0x40\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], 0x0032\n\t"
        "%{disp8%} je         LAB__addr_0x0076b3ae\n\t"
        "push               0x1\n\t"
        "push               0xb\n\t"
        "call               ?PlayAnimThenSetState@Living@@QAEXEK@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x0076b3ae:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x11c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x04]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x5b0]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "push               eax\n\t"
        "push               0x3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?VillagerDead@Villager@@QAEXW4DEATH_REASON@@PAVGPlayer@@MH@Z\n"
        "LAB__addr_0x0076b3e0:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "pop                ecx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall GoAndChilloutOutsideHome__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x28\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              esi, eax\n\t"
        "test               esi, esi\n\t"
        "%{disp32%} je        LAB__addr_0x0076b4c1\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0076b4c1\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x28]\n\t"
        "%{disp32%} mov       edx, dword ptr [ecx + 0x00000144]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edx\n\t"
        "call               dword ptr [eax + 0x104]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x10]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x2414]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x14]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], edx\n\t"
        "fstp               dword ptr [esp]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x14]\n\t"
        "push               edx\n\t"
        "add                esi, 0x14\n\t"
        "push               esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x2c], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x30], ecx\n\t"
        "call               ?Get3DAngleFromXZ@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x04]\n\t"
        "add                esp, 0x04\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x30]\n\t"
        "push               eax\n\t"
        "call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "add                esp, 0x0c\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x20]\n\t"
        "call               @__apl__9MapCoordsFRC9MapCoords@12\n\t"
        "%{disp8%} lea        ebx, dword ptr [esp + 0x1c]\n\t"
        "push               ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x10]\n\t"
        "push               ebx\n\t"
        "%{disp8%} lea        ebx, dword ptr [esp + 0x18]\n\t"
        "push               ebx\n\t"
        "sub                esp, 0x10\n\t"
        "mov                eax, 0x00753d50\n\t"
        "mov.s              ebx, esp\n\t"
        "mov                dword ptr [ebx], eax\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp8%} mov        dword ptr [ebx + 0x04], ecx\n\t"
        "xor.s              edx, edx\n\t"
        "xor.s              esi, esi\n\t"
        "%{disp8%} mov        dword ptr [ebx + 0x08], edx\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp8%} mov        dword ptr [ebx + 0x0c], esi\n\t"
        "call               ?GetMeToMyChillOutPos@Villager@@QAEXP81@AEHPBXPAXAAUMapCoords@@@Z2MABU2@@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x28\n\t"
        "ret\n"
        "LAB__addr_0x0076b4c1:\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x28"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall SitAndChillout__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        ax, word ptr [esi + 0x58]\n\t"
        "test               ax, ax\n\t"
        "%{disp8%} lea        ecx, dword ptr [eax + -0x01]\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], cx\n\t"
        "%{disp8%} jg         LAB__addr_0x0076b566\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], 0x0000\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076b527\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?IsInStateOfEmergency@Town@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076b527\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000f2\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0076b527:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CheckNeededForSomething@Villager@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076b566\n\t"
        "push               0x000003ff\n\t"
        "push               0x00c24630\n\t"
        "push               0xa\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "add                esp, 0x0c\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076b558\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupNothingToDo@Villager@@QAEIXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0076b558:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       dx, word ptr [ecx + 0x00000396]\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], dx\n"
        "LAB__addr_0x0076b566:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall EnterSitAndChillOut__8VillagerFUcUc(struct Villager* this, const void* edx, unsigned char param_1, unsigned char param_2)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} mov       dx, word ptr [eax + 0x00000394]\n\t"
        "%{disp8%} mov        word ptr [ecx + 0x58], dx\n\t"
        "mov                eax, 0x00000001"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall GoAndChilloutInTown__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              esi, eax\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x0076b5f3\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetCongregationPos@Town@@QAEPAUMapCoords@@PAU2@@Z\n\t"
        "%{disp8%} mov        esi, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       esi, dword ptr [esi + 0x00000140]\n\t"
        "%{disp8%} lea        ebp, dword ptr [esp + 0x10]\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "%{disp8%} lea        esi, dword ptr [esp + 0x18]\n\t"
        "push               esi\n\t"
        "sub                esp, 0x10\n\t"
        "mov                eax, 0x00753c70\n\t"
        "mov.s              esi, esp\n\t"
        "mov                dword ptr [esi], eax\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x04], ecx\n\t"
        "xor.s              edx, edx\n\t"
        "xor.s              ebx, ebx\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x08], edx\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x0c], ebx\n\t"
        "call               ?GetMeToMyChillOutPos@Villager@@QAEXP81@AEHPBXPAXAAUMapCoords@@@Z2MABU2@@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x0076b5f3:\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV, ret_cleanup_override(0x1c)))
void __fastcall GetMeToMyChillOutPos__8VillagerFM8VillagerFPCvPvR9MapCoords_iR9MapCoordsfRC9MapCoords(struct Villager* this, const void* edx, int (__fastcall* callback)(const struct Villager * param_1, const void * param_2, struct MapCoords * param_3), const void* unused_1, const void* unused_2, const void* unused_3, struct MapCoords* param_5, float param_6, struct MapCoords* param_7)
{
    asm("sub                esp, 0x20");                                       // 0x0076b610    83ec20
    asm("push               ebx");                                             // 0x0076b613    53
    asm("push               ebp");                                             // 0x0076b614    55
    asm("push               esi");                                             // 0x0076b615    56
    asm("mov.s              esi, ecx");                                        // 0x0076b616    8bf1
    asm("{disp8} mov        ecx, dword ptr [esp + 0x40]");                     // 0x0076b618    8b4c2440
    asm("push               edi");                                             // 0x0076b61c    57
    asm("{disp8} lea        edi, dword ptr [esi + 0x14]");                     // 0x0076b61d    8d7e14
    asm("push               edi");                                             // 0x0076b620    57
    asm("call               _GetDistanceInMetres__6GUtilsFRC9MapCoordsRC9MapCoords_2");                            // 0x0076b621    e8aaa6e9ff
    asm("{disp8} fst        dword ptr [esp + 0x14]");                          // 0x0076b626    d9542414
    asm("{disp8} fcomp      dword ptr [esp + 0x48]");                          // 0x0076b62a    d85c2448
    asm("fnstsw             ax");                                              // 0x0076b62e    dfe0
    asm("test               ah, 0x41");                                        // 0x0076b630    f6c441
    asm("{disp8} jne        LAB__addr_0x0076b67b");                            // 0x0076b633    7546
    asm("{disp8} mov        ecx, dword ptr [esp + 0x38]");                     // 0x0076b635    8b4c2438
    asm("xor.s              edi, edi");                                        // 0x0076b639    33ff
    asm("{disp8} lea        eax, dword ptr [esp + 0x18]");                     // 0x0076b63b    8d442418
    asm("push               eax");                                             // 0x0076b63f    50
    asm("add.s              ecx, esi");                                        // 0x0076b640    03ce
    asm("{disp8} mov        dword ptr [esp + 0x1c], edi");                     // 0x0076b642    897c241c
    asm("{disp8} mov        dword ptr [esp + 0x20], edi");                     // 0x0076b646    897c2420
    asm("{disp8} mov        dword ptr [esp + 0x24], edi");                     // 0x0076b64a    897c2424
    asm("call               dword ptr [esp + 0x38]");                          // 0x0076b64e    ff542438
    asm("test               eax, eax");                                        // 0x0076b652    85c0
    asm("{disp32} je        LAB__addr_0x0076b7ce");                            // 0x0076b654    0f8474010000
    asm("mov                edx, dword ptr [esi]");                            // 0x0076b65a    8b16
    asm("mov.s              ecx, esi");                                        // 0x0076b65c    8bce
    asm("call               dword ptr [edx + 0xb04]");                         // 0x0076b65e    ff92040b0000
    asm("mov.s              ecx, esi");                                        // 0x0076b664    8bce
    asm("push               eax");                                             // 0x0076b666    50
    asm("{disp8} lea        eax, dword ptr [esp + 0x1c]");                     // 0x0076b667    8d44241c
    asm("push               eax");                                             // 0x0076b66b    50
    asm("call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13");  // 0x0076b66c    e81f72e8ff
    asm("pop                edi");                                             // 0x0076b671    5f
    asm("pop                esi");                                             // 0x0076b672    5e
    asm("pop                ebp");                                             // 0x0076b673    5d
    asm("pop                ebx");                                             // 0x0076b674    5b
    asm("add                esp, 0x20");                                       // 0x0076b675    83c420
    asm("ret                0x001c");                                          // 0x0076b678    c21c00
    asm("LAB__addr_0x0076b67b:");
    asm("mov                ecx, dword ptr [edi]");                            // 0x0076b67b    8b0f
    asm("{disp8} mov        edx, dword ptr [edi + 0x04]");                     // 0x0076b67d    8b5704
    asm("{disp8} mov        eax, dword ptr [edi + 0x08]");                     // 0x0076b680    8b4708
    asm("{disp8} mov        dword ptr [esp + 0x18], ecx");                     // 0x0076b683    894c2418
    asm("{disp8} mov        dword ptr [esp + 0x1c], edx");                     // 0x0076b687    8954241c
    asm("mov                edx, dword ptr [esi]");                            // 0x0076b68b    8b16
    asm("mov.s              ecx, esi");                                        // 0x0076b68d    8bce
    asm("{disp8} mov        dword ptr [esp + 0x20], eax");                     // 0x0076b68f    89442420
    asm("call               dword ptr [edx + 0x64]");                          // 0x0076b693    ff5264
    asm("{disp32} fmul      dword ptr [rdata_bytes + 0x1dc98]");               // 0x0076b696    d80d986c8c00
    asm("push               esi");                                             // 0x0076b69c    56
    asm("sub                esp, 0x10");                                       // 0x0076b69d    83ec10
    asm("mov.s              ebx, esp");                                        // 0x0076b6a0    8bdc
    asm("{disp8} fstp       dword ptr [esp + 0x24]");                          // 0x0076b6a2    d95c2424
    asm("mov                eax, 0x00761bb0");                                 // 0x0076b6a6    b8b01b7600
    asm("mov                dword ptr [ebx], eax");                            // 0x0076b6ab    8903
    asm("xor.s              ecx, ecx");                                        // 0x0076b6ad    33c9
    asm("{disp8} mov        dword ptr [ebx + 0x04], ecx");                     // 0x0076b6af    894b04
    asm("xor.s              edx, edx");                                        // 0x0076b6b2    33d2
    asm("{disp8} mov        dword ptr [ebx + 0x08], edx");                     // 0x0076b6b4    895308
    asm("xor.s              edi, edi");                                        // 0x0076b6b7    33ff
    asm("{disp8} mov        dword ptr [ebx + 0x0c], edi");                     // 0x0076b6b9    897b0c
    asm("{disp8} mov        ebx, dword ptr [esp + 0x24]");                     // 0x0076b6bc    8b5c2424
    asm("{disp8} lea        eax, dword ptr [esp + 0x2c]");                     // 0x0076b6c0    8d44242c
    asm("push               ebx");                                             // 0x0076b6c4    53
    asm("push               eax");                                             // 0x0076b6c5    50
    asm("call               ?CheckForClearArea@Town@@SA_NAAUMapCoords@@MP8Object@@AEHPBX1@ZPAV3@@Z");                     // 0x0076b6c6    e8055dfdff
    asm("add                esp, 0x1c");                                       // 0x0076b6cb    83c41c
    asm("test               eax, eax");                                        // 0x0076b6ce    85c0
    asm("{disp8} je         LAB__addr_0x0076b6fd");                            // 0x0076b6d0    742b
    asm("{disp8} mov        eax, dword ptr [esp + 0x4c]");                     // 0x0076b6d2    8b44244c
    asm("cmp.s              eax, edi");                                        // 0x0076b6d6    3bc7
    asm("{disp8} je         LAB__addr_0x0076b6e4");                            // 0x0076b6d8    740a
    asm("push               0x2");                                             // 0x0076b6da    6a02
    asm("push               eax");                                             // 0x0076b6dc    50
    asm("mov.s              ecx, esi");                                        // 0x0076b6dd    8bce
    asm("call               @LookAtPos__6LivingFRC9MapCoordsUl@16");           // 0x0076b6df    e86c0ee8ff
    asm("LAB__addr_0x0076b6e4:");
    asm("mov                edx, dword ptr [esi]");                            // 0x0076b6e4    8b16
    asm("push               0x000000f6");                                      // 0x0076b6e6    68f6000000
    asm("mov.s              ecx, esi");                                        // 0x0076b6eb    8bce
    asm("call               dword ptr [edx + 0x8e8]");                         // 0x0076b6ed    ff92e8080000
    asm("pop                edi");                                             // 0x0076b6f3    5f
    asm("pop                esi");                                             // 0x0076b6f4    5e
    asm("pop                ebp");                                             // 0x0076b6f5    5d
    asm("pop                ebx");                                             // 0x0076b6f6    5b
    asm("add                esp, 0x20");                                       // 0x0076b6f7    83c420
    asm("ret                0x001c");                                          // 0x0076b6fa    c21c00
    asm("LAB__addr_0x0076b6fd:");
    asm("{disp8} fld        dword ptr [esp + 0x48]");                          // 0x0076b6fd    d9442448
    asm("{disp32} fadd      dword ptr [rdata_bytes + 0x26e4]");                // 0x0076b701    d805e4b68a00
    asm("{disp8} fcomp      dword ptr [esp + 0x14]");                          // 0x0076b707    d85c2414
    asm("fnstsw             ax");                                              // 0x0076b70b    dfe0
    asm("test               ah, 0x01");                                        // 0x0076b70d    f6c401
    asm("{disp8} je         LAB__addr_0x0076b746");                            // 0x0076b710    7434
    asm("{disp8} mov        eax, dword ptr [esp + 0x44]");                     // 0x0076b712    8b442444
    asm("push               eax");                                             // 0x0076b716    50
    asm("{disp8} lea        ecx, dword ptr [esp + 0x1c]");                     // 0x0076b717    8d4c241c
    asm("push               ecx");                                             // 0x0076b71b    51
    asm("call               ?Get3DAngleFromXZ@GUtils@@SAMABUMapCoords@@0@Z");                                 // 0x0076b71c    e84f1bfeff
    asm("{disp8} fstp       dword ptr [esp + 0x50]");                          // 0x0076b721    d95c2450
    asm("{disp8} mov        edx, dword ptr [esp + 0x50]");                     // 0x0076b725    8b542450
    asm("push               0x40a00000");                                      // 0x0076b729    680000a040
    asm("push               edx");                                             // 0x0076b72e    52
    asm("{disp8} lea        eax, dword ptr [esp + 0x34]");                     // 0x0076b72f    8d442434
    asm("push               eax");                                             // 0x0076b733    50
    asm("call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z");   // 0x0076b734    e8471efeff
    asm("add                esp, 0x14");                                       // 0x0076b739    83c414
    asm("push               eax");                                             // 0x0076b73c    50
    asm("{disp8} lea        ecx, dword ptr [esp + 0x1c]");                     // 0x0076b73d    8d4c241c
    asm("call               @__apl__9MapCoordsFRC9MapCoords@12");              // 0x0076b741    e8ca9ce9ff
    asm("LAB__addr_0x0076b746:");
    asm("push               esi");                                             // 0x0076b746    56
    asm("sub                esp, 0x10");                                       // 0x0076b747    83ec10
    asm("mov.s              ebp, esp");                                        // 0x0076b74a    8bec
    asm("push               ebx");                                             // 0x0076b74c    53
    asm("mov                eax, 0x00761bb0");                                 // 0x0076b74d    b8b01b7600
    asm("{disp8} mov        dword ptr [ebp + 0x00], eax");                     // 0x0076b752    894500
    asm("xor.s              ecx, ecx");                                        // 0x0076b755    33c9
    asm("{disp8} mov        dword ptr [ebp + 0x04], ecx");                     // 0x0076b757    894d04
    asm("push               0x3f800000");                                      // 0x0076b75a    680000803f
    asm("xor.s              edx, edx");                                        // 0x0076b75f    33d2
    asm("{disp8} mov        dword ptr [ebp + 0x08], edx");                     // 0x0076b761    895508
    asm("push               0x40a00000");                                      // 0x0076b764    680000a040
    asm("{disp8} lea        ecx, dword ptr [esp + 0x38]");                     // 0x0076b769    8d4c2438
    asm("push               ecx");                                             // 0x0076b76d    51
    asm("{disp8} lea        edx, dword ptr [esp + 0x3c]");                     // 0x0076b76e    8d54243c
    asm("push               edx");                                             // 0x0076b772    52
    asm("{disp8} mov        dword ptr [ebp + 0x0c], edi");                     // 0x0076b773    897d0c
    asm("call               ?FindClearArea@Town@@SA_NAAUMapCoords@@0MMMP8Object@@AEHPBX1@ZPAV3@@Z");                               // 0x0076b776    e8755bfdff
    asm("add                esp, 0x28");                                       // 0x0076b77b    83c428
    asm("test               eax, eax");                                        // 0x0076b77e    85c0
    asm("{disp8} je         LAB__addr_0x0076b7a3");                            // 0x0076b780    7421
    asm("mov                eax, dword ptr [esi]");                            // 0x0076b782    8b06
    asm("mov.s              ecx, esi");                                        // 0x0076b784    8bce
    asm("call               dword ptr [eax + 0xb04]");                         // 0x0076b786    ff90040b0000
    asm("{disp8} lea        ecx, dword ptr [esp + 0x18]");                     // 0x0076b78c    8d4c2418
    asm("push               eax");                                             // 0x0076b790    50
    asm("push               ecx");                                             // 0x0076b791    51
    asm("mov.s              ecx, esi");                                        // 0x0076b792    8bce
    asm("call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13");  // 0x0076b794    e8f770e8ff
    asm("pop                edi");                                             // 0x0076b799    5f
    asm("pop                esi");                                             // 0x0076b79a    5e
    asm("pop                ebp");                                             // 0x0076b79b    5d
    asm("pop                ebx");                                             // 0x0076b79c    5b
    asm("add                esp, 0x20");                                       // 0x0076b79d    83c420
    asm("ret                0x001c");                                          // 0x0076b7a0    c21c00
    asm("LAB__addr_0x0076b7a3:");
    asm("{disp8} mov        eax, dword ptr [esp + 0x38]");                     // 0x0076b7a3    8b442438
    asm("{disp8} lea        edx, dword ptr [esp + 0x18]");                     // 0x0076b7a7    8d542418
    asm("push               edx");                                             // 0x0076b7ab    52
    asm("lea                ecx, dword ptr [eax + esi * 0x1]");                // 0x0076b7ac    8d0c30
    asm("call               dword ptr [esp + 0x38]");                          // 0x0076b7af    ff542438
    asm("test               eax, eax");                                        // 0x0076b7b3    85c0
    asm("{disp8} je         LAB__addr_0x0076b7ce");                            // 0x0076b7b5    7417
    asm("mov                edx, dword ptr [esi]");                            // 0x0076b7b7    8b16
    asm("mov.s              ecx, esi");                                        // 0x0076b7b9    8bce
    asm("call               dword ptr [edx + 0xb04]");                         // 0x0076b7bb    ff92040b0000
    asm("mov.s              ecx, esi");                                        // 0x0076b7c1    8bce
    asm("push               eax");                                             // 0x0076b7c3    50
    asm("{disp8} lea        eax, dword ptr [esp + 0x1c]");                     // 0x0076b7c4    8d44241c
    asm("push               eax");                                             // 0x0076b7c8    50
    asm("call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13");  // 0x0076b7c9    e8c270e8ff
    asm("LAB__addr_0x0076b7ce:");
    asm("pop                edi");                                             // 0x0076b7ce    5f
    asm("pop                esi");                                             // 0x0076b7cf    5e
    asm("pop                ebp");                                             // 0x0076b7d0    5d
    asm("pop                ebx");                                             // 0x0076b7d1    5b
    asm("add                esp, 0x20");                                       // 0x0076b7d2    83c420
}

extern bool32_t __fastcall ArrivesHome(struct Villager* this) asm("?ArrivesHome@Villager@@QAEIXZ");

bool32_t __fastcall ArrivesHomeFromWorship__8VillagerFv(struct Villager* this)
{
    __attribute__((musttail)) return ArrivesHome(this);
}

extern bool32_t __fastcall SleepInTent(struct Villager* this) asm("?SleepInTent@Villager@@QAEIXZ");

bool32_t __fastcall SleepInTentFromWorship__8VillagerFv(struct Villager* this)
{
    __attribute__((musttail)) return SleepInTent(this);
}

__attribute__((no_callee_saves))
bool32_t __fastcall BreederJustLanded__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x20\n\t"
        "push               ebx\n\t"
        "mov.s              ebx, ecx\n\t"
        "push               ebp\n\t"
        "%{disp8%} lea        ebp, dword ptr [ebx + 0x14]\n\t"
        "mov.s              eax, ebp\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [_villager_states_float_max_0x0099aa0c]\n\t"
        "push               esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], edx\n\t"
        "mov                edx, dword ptr [ebx]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "push               edi\n\t"
        "mov.s              ecx, ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x2c], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], 0x00000000\n\t"
        "call               dword ptr [edx + 0x450]\n\t"
        "mov.s              edi, eax\n\t"
        "neg                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "sbb.s              edi, edi\n\t"
        "inc                edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000009\n"
        "LAB__addr_0x0076b85a:\n\t"
        "push               0x0\n\t"
        "push               0x009cafc8\n\t"
        "push               0x009c7f50\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x2\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x3c]\n\t"
        "call               @FindType__9MapCoordsCF11OBJECT_TYPEP6Object@16\n\t"
        "push               eax\n\t"
        "call               ___RTDynamicCast\n\t"
        "mov.s              esi, eax\n\t"
        "add                esp, 0x14\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x0076b8ba\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsSexuallyActive@Villager@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076b8ba\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "cmp                dword ptr [eax + 0x000001f8], edi\n\t"
        "%{disp8%} jne        LAB__addr_0x0076b8ba\n\t"
        "push               ebp\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "call               _GetDistanceInMetres__6GUtilsFRC9MapCoordsRC9MapCoords_2\n\t"
        "%{disp8%} fcom       dword ptr [esp + 0x10]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0076b8b8\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], esi\n\t"
        "%{disp8%} jmp        LAB__addr_0x0076b8ba\n"
        "LAB__addr_0x0076b8b8:\n\t"
        "fstp               st(0)\n"
        "LAB__addr_0x0076b8ba:\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x24]\n\t"
        "push               edx\n\t"
        "call               ?Spiral@GUtils@@SAPBUJustMapXZ@@AAJ0@Z\n\t"
        "add                esp, 0x08\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x28]\n\t"
        "call               @__apl__9MapCoordsFRC9JustMapXZ@12\n\t"
        "dec                dword ptr [esp + 0x14]\n\t"
        "%{disp32%} jne       LAB__addr_0x0076b85a\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x18]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076b8fd\n\t"
        "push               eax\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?GoAndHaveSexWith@Villager@@QAEIPAV1@@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x20\n\t"
        "ret\n"
        "LAB__addr_0x0076b8fd:\n\t"
        "mov                eax, dword ptr [ebx]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x20"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}


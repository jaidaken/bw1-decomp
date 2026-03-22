// Villager.cpp

#include "Villager.h"
#include "VillagerInfo.h"
#include "TribeInfo.h"
#include "GameOSFile.h"
#include <stdint.h>

__attribute__((section(".bss"))) uint32_t villager_uint_0x00da6bc0;
__attribute__((section(".bss"))) uint8_t villager_byte_0x00da6bc4;
__attribute__((section(".bss"))) uint32_t villager_uint_0x00da6bc8;
__attribute__((section(".bss"))) uint8_t villager_byte_0x00da6bcc;
__attribute__((section(".bss"))) uint32_t villager_uint_0x00da6bd0;
__attribute__((section(".bss"))) uint8_t villager_byte_0x00da6bd4;
__attribute__((section(".bss"))) uint32_t villager_uint_0x00da6bd8;
__attribute__((section(".bss"))) uint8_t villager_byte_0x00da6bdc;
__attribute__((section(".bss"))) float villager_float_0x00da6be0;
__attribute__((section(".bss"))) float villager_seconds_in_year_0x00da6be4;
__attribute__((section(".bss"))) struct GVillagerInfo VillagerInfos[VILLAGER_INFO_LAST]; // 00da6be8-00db9db8
__attribute__((section(".bss"))) uint32_t villager_data_0x00db9db8;
__attribute__((section(".bss"))) uint32_t villager_data_0x00db9dbc;

const float villager_num_days_in_year_0x0099a1e4 = 365.25f;
const float villager_seconds_in_day_0x0099a1e8 = 86400.0f;
const float villager_float_0x0099a1ec = 10.0;
const float villager_float_0x0099a1f0 = 1000.0;
const float villager_float_0x0099a1f4 = 0.0;
const struct DiscipleInfo DiscipleInfos[VILLAGER_DISCIPLE_LAST] = {
    [VILLAGER_DISCIPLE_NONE]         = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, TOWN_DESIRE_INFO_NONE, 0x00000000},
    [VILLAGER_DISCIPLE_FARMER]       = {0x00000000, 0x00000001, 0x00000001, 0x00000001, 0x00000000, TOWN_DESIRE_INFO_FOR_FOOD, 0x00000001},
    [VILLAGER_DISCIPLE_FORESTER]     = {0x00000031, 0x00000001, 0x00000001, 0x00000001, 0x00000001, TOWN_DESIRE_INFO_FOR_WOOD, 0x00000000},
    [VILLAGER_DISCIPLE_FISHERMAN]    = {0x00000000, 0x00000001, 0x00000001, 0x00000001, 0x00000000, TOWN_DESIRE_INFO_FOR_FOOD, 0x00000000},
    [VILLAGER_DISCIPLE_BUILDER]      = {0x00000000, 0x00000001, 0x00000001, 0x00000001, 0x00000001, TOWN_DESIRE_INFO_TO_BUILD, 0x00000001},
    [VILLAGER_DISCIPLE_BREEDER]      = {0x000000fe, 0x00000000, 0x00000001, 0x00000001, 0x00000000, TOWN_DESIRE_INFO_FOR_CHILDREN, 0x00000001},
    [VILLAGER_DISCIPLE_PROTECTION]   = {0x00000000, 0x00000001, 0x00000001, 0x00000001, 0x00000000, TOWN_DESIRE_INFO_NONE, 0x00000000},
    [VILLAGER_DISCIPLE_MISSIONARY]   = {0x000000e2, 0x00000000, 0x00000001, 0x00000000, 0x00000000, TOWN_DESIRE_INFO_NONE, 0x00000000},
    [VILLAGER_DISCIPLE_CRAFTSMAN]    = {0x00000000, 0x00000001, 0x00000001, 0x00000001, 0x00000001, TOWN_DESIRE_INFO_NONE, 0x00000001},
    [VILLAGER_DISCIPLE_TRADER]       = {0x000000a3, 0x00000000, 0x00000001, 0x00000001, 0x00000000, TOWN_DESIRE_INFO_NONE, 0x00000000},
    [VILLAGER_DISCIPLE_CHANGE_HOUSE] = {0x000000a3, 0x00000000, 0x00000001, 0x00000000, 0x00000000, TOWN_DESIRE_INFO_NONE, 0x00000000},
    [VILLAGER_DISCIPLE_WORSHIP]      = {0x0000003a, 0x00000000, 0x00000000, 0x00000000, 0x00000000, TOWN_DESIRE_INFO_NONE, 0x00000000},
    [VILLAGER_DISCIPLE_FROM_VORTEX]  = {0x000000f4, 0x00000000, 0x00000000, 0x00000000, 0x00000000, TOWN_DESIRE_INFO_NONE, 0x00000000},
};
const uint32_t villager_uint_0x0099a364 = 0;
const struct {
    uint32_t field_0x0;
    uint32_t field_0x4;
    uint32_t field_0x8;
} villager_struct_0x0099a364[DEATH_REASON_LAST] = {
    [DEATH_REASON_NONE]                     = {0x00000000, 0x00000000, 0x00000000},
    [DEATH_REASON_STARVING]                 = {0x00000000, 0x00000000, 0x00000001},
    [DEATH_REASON_SPELL]                    = {0x00000001, 0x00000001, 0x00000001},
    [DEATH_REASON_ANIMAL]                   = {0x00000000, 0x00000001, 0x00000001},
    [DEATH_REASON_CHANT]                    = {0x00000000, 0x00000000, 0x00000001},
    [DEATH_REASON_PLAYER_INTERACTION]       = {0x00000001, 0x00000001, 0x00000000},
    [DEATH_REASON_PLAYER_INTERACTION_DROWN] = {0x00000001, 0x00000000, 0x00000000},
    [DEATH_REASON_SACRIFICE]                = {0x00000000, 0x00000000, 0x00000001},
    [DEATH_REASON_EXHAUSTION]               = {0x00000000, 0x00000000, 0x00000001},
    [DEATH_REASON_OLD_AGE]                  = {0x00000000, 0x00000000, 0x00000000},
};

uintptr_t villager_ptr_0x00c234e0 = 0x00da6a20;

char s_Last_00c23570[];
char s_Trader_00c23578[];
char s_Housewife_00c23580[];
char s_Leader_00c2358c[];
char s_Shepherd_00c23594[];
char s_Farmer_00c235a0[];
char s_Forester_00c235a8[];
char s_Fisherman_00c235b4[];
const char* VillagerJobStrs[VILLAGER_JOB_LAST + 1] =
{
    [VILLAGER_JOB_NONE]      = (const char*)0x00bef464,
    [VILLAGER_JOB_FISHERMAN] = s_Fisherman_00c235b4,
    [VILLAGER_JOB_FORESTER]  = s_Forester_00c235a8,
    [VILLAGER_JOB_FARMER]    = s_Farmer_00c235a0,
    [VILLAGER_JOB_SHEPHERD]  = s_Shepherd_00c23594,
    [VILLAGER_JOB_LEADER]    = s_Leader_00c2358c,
    [VILLAGER_JOB_HOUSEWIFE] = s_Housewife_00c23580,
    [VILLAGER_JOB_TRADER]    = s_Trader_00c23578,
    [VILLAGER_JOB_LAST]      = s_Last_00c23570,
};

char s_TRADER_00c23528[];
char s_LEADER_00c23530[];
char s_SHEPHERD_00c23538[];
char s_FARMER_00c23544[];
char s_FISHERMAN_00c2354c[];
char s_FORESTER_00c23558[];
char s_HOUSEWIFE_00c23564[];
const char* VillagerBasicInfoStrs[VILLAGER_BASIC_INFO_LAST + 1] =
{
    [VILLAGER_BASIC_INFO_HOUSEWIFE_FEMALE] = s_HOUSEWIFE_00c23564,
    [VILLAGER_BASIC_INFO_FORESTER_MALE]    = s_FORESTER_00c23558,
    [VILLAGER_BASIC_INFO_FISHERMAN_MALE]   = s_FISHERMAN_00c2354c,
    [VILLAGER_BASIC_INFO_FARMER_MALE]      = s_FARMER_00c23544,
    [VILLAGER_BASIC_INFO_SHEPHERD_MALE]    = s_SHEPHERD_00c23538,
    [VILLAGER_BASIC_INFO_LEADER_MALE]      = s_LEADER_00c23530,
    [VILLAGER_BASIC_INFO_TRADER_MALE]      = s_TRADER_00c23528,
    [VILLAGER_BASIC_INFO_LAST]             = (const char*)0x009c8cdc,
};
__attribute__((aligned(4))) char s_TRADER_00c23528[] = "TRADER";
__attribute__((aligned(4))) char s_LEADER_00c23530[] = "LEADER";
__attribute__((aligned(4))) char s_SHEPHERD_00c23538[] = "SHEPHERD";
__attribute__((aligned(4))) char s_FARMER_00c23544[] = "FARMER";
__attribute__((aligned(4))) char s_FISHERMAN_00c2354c[] = "FISHERMAN";
__attribute__((aligned(4))) char s_FORESTER_00c23558[] = "FORESTER";
__attribute__((aligned(4))) char s_HOUSEWIFE_00c23564[] = "HOUSEWIFE";
__attribute__((aligned(4))) char s_Last_00c23570[] = "Last";
__attribute__((aligned(4))) char s_Trader_00c23578[] = "Trader";
__attribute__((aligned(4))) char s_Housewife_00c23580[] = "Housewife";
__attribute__((aligned(4))) char s_Leader_00c2358c[] = "Leader";
__attribute__((aligned(4))) char s_Shepherd_00c23594[] = "Shepherd";
__attribute__((aligned(4))) char s_Farmer_00c235a0[] = "Farmer";
__attribute__((aligned(4))) char s_Forester_00c235a8[] = "Forester";
__attribute__((aligned(4))) char s_Fisherman_00c235b4[] = "Fisherman";

extern void __cdecl FUN_0074f7e0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x0074f7d0(void)
{
    __attribute__((musttail)) return FUN_0074f7e0__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_0074f7e0__8VillagerFv(void)
{
    extern float __opaque_sec_day asm("_villager_seconds_in_day_0x0099a1e8");
    extern float __opaque_days_year asm("_villager_num_days_in_year_0x0099a1e4");
    extern float __opaque_sec_year asm("_villager_seconds_in_year_0x00da6be4");
    __opaque_sec_year = __opaque_sec_day * __opaque_days_year;
}

extern void __cdecl FUN_0074f810__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x0074f800(void)
{
    __attribute__((musttail)) return FUN_0074f810__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_0074f810__8VillagerFv(void)
{
    extern float __opaque_a asm("_villager_float_0x0099a1ec");
    extern float __opaque_b asm("_abode_info_float_0x008a99f0");
    extern float __opaque_c asm("_villager_float_0x00da6be0");
    __opaque_c = __opaque_a * __opaque_b;
}

__attribute__((no_ret))
void __cdecl globl_ct_0x0074f830(void)
{
    asm("call               ??__EGVillagerInfo_ARRAY_00da6be8@@YAXXZ");                    // 0x0074f830    e80b000000
    asm("{disp32} jmp       _crt_global_destruction_register_VillagerInfo_ARRAY");         // 0x0074f835    e976000000
    __builtin_unreachable();
}

void __cdecl dynamic_ctor_VillagerInfos               (void) asm("??__EGVillagerInfo_ARRAY_00da6be8@@YAXXZ");
void __cdecl dynamic_ctor_VillagerInfos               (void)
{
    asm("push               esi");                                            // 0x0074f840    56
    asm("push               edi");                                            // 0x0074f841    57
    asm("mov                esi, OFFSET _VillagerInfos");                     // 0x0074f842    bee86bda00
    asm("mov                edi, 0x00000054"); /* VILLAGER_INFO_LAST */       // 0x0074f847    bf54000000
    asm("LAB__addr_0x0074f84c:");
    asm("{disp8} lea        ecx, dword ptr [esi + 0x08]");                    // 0x0074f84c    8d4e08
    asm("push               0x0");                                            // 0x0074f84f    6a00
    asm("mov                dword ptr [esi], 0x008a9a44");                    // 0x0074f851    c706449a8a00
    asm("{disp8} mov        dword ptr [ecx + -0x04], 0x00000000");            // 0x0074f857    c741fc00000000
    asm("call               _jmp_addr_0x0041bce0");                           // 0x0074f85e    e87dc4ccff
    asm("mov                dword ptr [esi], 0x0099a3e4");                    // 0x0074f863    c706e4a39900
    asm("add                esi, 0x000003a4");                                // 0x0074f869    81c6a4030000
    asm("dec                edi");                                            // 0x0074f86f    4f
    asm("{disp8} jne        LAB__addr_0x0074f84c");                           // 0x0074f870    75da
    asm("pop                edi");                                            // 0x0074f872    5f
    asm("pop                esi");                                            // 0x0074f873    5e
}

uint32_t __fastcall GetMesh__13GVillagerInfoCFv(const struct GObjectInfo* this)
{
    return ((const struct GVillagerInfo*)this)->stdDetail;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
struct GBaseInfo* __fastcall GetBaseInfo__13GVillagerInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1)
{
    struct GBaseInfo* result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "mov                dword ptr [eax], 0x00000054\n\t"
        "mov                eax, OFFSET _VillagerInfos"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((prefer_pop_cleanup))
void __cdecl crt_global_destruction_register_VillagerInfo_ARRAY(void)
{
    extern int __cdecl atexit(void (*)(void));
    atexit((void (*)(void))0x0074f8c0);
}

void __cdecl atexit_destroy_GVillagerInfo_array(void) asm("??__FGVillagerInfo_ARRAY_00da6be8@@YAXXZ");
void __cdecl atexit_destroy_GVillagerInfo_array(void)
{
    asm volatile (
        "%{disp32%} mov       cl, byte ptr [_villager_byte_0x00da6bdc]\n\t"
        "mov                al, 0x01\n\t"
        "test               al, cl\n\t"
        "%{disp8%} jne        LAB__addr_0x0074f8f2\n\t"
        "push               esi\n\t"
        "or.s               cl, al\n\t"
        "push               edi\n\t"
        "%{disp32%} mov       byte ptr [_villager_byte_0x00da6bdc], cl\n\t"
        "mov                esi, OFFSET _VillagerInfos + 0x131D0\n\t"
        "mov                edi, 0x00000054\n\t"
        "LAB__addr_0x0074f8e0:\n\t"
        "sub                esi, 0x000003a4\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x00436960\n\t"
        "dec                edi\n\t"
        "%{disp8%} jne        LAB__addr_0x0074f8e0\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "LAB__addr_0x0074f8f2:"
        :  :  : "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall __dt__13GVillagerInfoFv(struct Base* this, const void* edx, uint32_t param_1)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               _jmp_addr_0x00436960\n\t"
        "test               byte ptr [esp + 0x08], 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0074f91d\n\t"
        "push               0x000003a4\n\t"
        "push               esi\n\t"
        "call               ??3Base@@SAXPAXK@Z\n\t"
        "add                esp, 0x08\n"
        "LAB__addr_0x0074f91d:\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__13GVillagerInfo = {
    .pTypeDescriptor = &__RTTITypeDescriptor__13GVillagerInfo,
    .numContainedBases = 0x00000006,
    .where = {
        .mdisp = 0x00000000,
        .pdisp = 0xFFFFFFFF,
        .vdisp = 0x00000000,
    },
    .attributes = 0x0000000,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassArray __RTTIBaseClassArray__13GVillagerInfo = {
    .arrayOfBaseClassDescriptors = {
        &__RTTIBaseClassDescriptor__13GVillagerInfo,
        &__RTTIBaseClassDescriptor__11GLivingInfo,
        &__RTTIBaseClassDescriptor__18GMobileWallHugInfo,
        &__RTTIBaseClassDescriptor__11GMobileInfo,
        &__RTTIBaseClassDescriptor__11GObjectInfo,
        &__RTTIBaseClassDescriptor__9GBaseInfo,
        &__RTTIBaseClassDescriptor__4Base,
        NULL,
    }
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__13GVillagerInfo = {
  .signature = 0x00000000,
  .attributes = 0x00000000,
  .numBaseClasses = 0x00000007,
  .pBaseClassArray = &__RTTIBaseClassArray__13GVillagerInfo,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTICompleteObjectLocator __RTTICompleteObjectLocator__13GVillagerInfo = {
  .signature = 0x00000000,
  .offset = 0x00000000,
  .cdOffset = 0x00000000,
  .pTypeDescriptor = &__RTTITypeDescriptor__13GVillagerInfo,
  .pClassDescriptor = &__RTTIClassHierarchyDescriptor__13GVillagerInfo,
};

const struct RTTICompleteObjectLocator* const p__RTTICompleteObjectLocator__13GVillagerInfo = &__RTTICompleteObjectLocator__13GVillagerInfo;

const struct GObjectInfoVftable __vt__13GVillagerInfo = {
  Serialise__4BaseFR7Archive,
  __dt__13GVillagerInfoFv,
  Delete__4BaseFv,
  ToBeDeleted__4BaseFi,
  Get3DSoundPos__4BaseFP7LHPoint,
  CleanUpForSerialisation__4BaseFv,
  Dump__4BaseFv,
  GetDebugText__11GObjectInfoCFv,
  GetDebugColor__9GBaseInfoCFv,
  GetBaseInfo__13GVillagerInfoFRUl,
  UpdateValue__9GBaseInfoFfUlUl,
  GetMesh__13GVillagerInfoCFv,
  GetMesh__11GObjectInfoCF10TRIBE_TYPE,
  GetAlignmentType__11GObjectInfoCFv,
  GetFoodType__11GObjectInfoCFv,
};

struct RTTITypeDescriptor __RTTITypeDescriptor__13GVillagerInfo = {
    &__vt__9type_info,
    NULL,
    ".?AVGVillagerInfo@@"
};
__attribute__((aligned(4))) char s_Villager_cpp_00c235dc[] = "C:\\dev\\MP\\Black\\Villager.cpp";
__attribute__((aligned(4))) char s_Attitude_to_creature_00c235fc[] = "Attitude to creature: %s";
__attribute__((aligned(4))) char s_Respect_00c23618[] = "Respect";
__attribute__((aligned(4))) char s_Fear_00c23620[] = "Fear";
__attribute__((aligned(4))) char s_Curiosity_00c23628[] = "Curiosity";
__attribute__((aligned(4))) char s_Ignore_00c23634[] = "Ignore";
__attribute__((aligned(4))) char s_Novelty_00c2363c[] = "Novelty";
__attribute__((aligned(4))) char s_DebugText_00c23644[] = "Life=%f, food=%f[%d],%s (%d) Age=%d, f%dw%dr%d, Ptr=%p ";
__attribute__((aligned(4))) char s_VSA_VSC_STACK_00c2367c[] = "VSA:%x, VSC:%x\nSTACK ";

extern void __cdecl FUN_0074f940__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x0074f930(void)
{
    __attribute__((musttail)) return FUN_0074f940__8VillagerFv();
}

void __cdecl FUN_0074f940__8VillagerFv(void)
{
    extern uintptr_t __opaque_src asm("_villager_ptr_0x00c234e0");
    extern uint32_t __opaque_dst asm("_villager_uint_0x00da6bd8");
    __opaque_dst = __opaque_src;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0010)))
struct Villager* __fastcall __ct__8VillagerFRC9MapCoordsPC13GVillagerInfoUli(struct Villager* this, const void* edx, struct MapCoords* coords, struct GVillagerInfo* info, uint32_t age, bool skeleton)
{
    struct Villager* result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x14]\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               eax\n\t"
        "call               @__ct__6LivingFRC9MapCoordsPC11GLivingInfo@16\n\t"
        "xor.s              ebx, ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000e4], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000fc], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000010c], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000110], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000010c], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000110], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000110], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000114], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000010c], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000110], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000011c], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000011c], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000120], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000011c], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000120], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000124], ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000011c], ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "mov                dword ptr [esi], 0x008f7960\n\t"
        "call               ?SetToZero@Villager@@QAEXXZ\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x18]\n\t"
        "cmp                eax, dword ptr [edi + 0x00000138]\n\t"
        "%{disp8%} jae        LAB__addr_0x0074f9f7\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000100], ebx\n"
        "LAB__addr_0x0074f9f7:\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetAge@Villager@@UAEXK@Z\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       byte ptr [esi + 0x000000f0], bl\n\t"
        "cmp                dword ptr [edi + 0x000001f8], 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0074fa18\n\t"
        "%{disp32%} mov       word ptr [esi + 0x000000f8], bx\n"
        "LAB__addr_0x0074fa18:\n\t"
        "push               0x7e\n\t"
        "push               0x00c235dc\n\t"
        "push               0x3f19999a\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fadd      dword ptr [edi + 0x000002c0]\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0074fa5e\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "push               0x7e\n\t"
        "push               0x00c235dc\n\t"
        "push               0x3f19999a\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fadd      dword ptr [edi + 0x000002c0]\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp8%} jmp        LAB__addr_0x0074fa64\n"
        "LAB__addr_0x0074fa5e:\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n"
        "LAB__addr_0x0074fa64:\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} fstp      dword ptr [esi + 0x000000e8]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x000002dc]\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "%{disp32%} mov       edi, dword ptr [ecx + 0x00205a40]\n\t"
        "push               0x7f\n\t"
        "push               0x00c235dc\n\t"
        "push               edx\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "add                esp, 0x0c\n\t"
        "cmp.s              eax, edi\n\t"
        "%{disp8%} jae        LAB__addr_0x0074faae\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x000002dc]\n\t"
        "push               0x7f\n\t"
        "push               0x00c235dc\n\t"
        "push               eax\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp8%} jmp        LAB__addr_0x0074fab0\n"
        "LAB__addr_0x0074faae:\n\t"
        "mov.s              eax, edi\n"
        "LAB__addr_0x0074fab0:\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "%{disp32%} mov       edx, dword ptr [ecx + 0x00205a40]\n\t"
        "push               0x00000080\n\t"
        "sub.s              edx, eax\n\t"
        "push               0x00c235dc\n\t"
        "push               0x000001f4\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000ec], edx\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "add                esp, 0x0c\n\t"
        "inc                eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], ax\n\t"
        "call               ?IsWater@MapCoords@@QBEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0074faf0\n\t"
        "push               0x10\n\t"
        "%{disp8%} jmp        LAB__addr_0x0074faf2\n"
        "LAB__addr_0x0074faf0:\n\t"
        "push               0x55\n"
        "LAB__addr_0x0074faf2:\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetState@Villager@@UAEXKE@Z\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp32%} inc       dword ptr [eax + 0x00205a54]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x1c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetSkeleton@Villager@@QAEXH@Z\n\t"
        "pop                edi\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
void __fastcall SetToZero__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       word ptr [ecx + 0x000000e0], ax\n\t"
        "%{disp32%} mov       dword ptr [ecx + 0x000000e8], eax\n\t"
        "%{disp32%} mov       byte ptr [ecx + 0x000000f0], al\n\t"
        "%{disp32%} mov       word ptr [ecx + 0x000000f4], ax\n\t"
        "%{disp32%} mov       word ptr [ecx + 0x000000f6], ax\n\t"
        "%{disp32%} mov       dword ptr [ecx + 0x000000fc], eax\n\t"
        "%{disp32%} mov       dword ptr [ecx + 0x00000128], eax\n\t"
        "%{disp32%} mov       byte ptr [ecx + 0x000000f2], al\n\t"
        "%{disp32%} mov       dword ptr [ecx + 0x0000012c], eax\n\t"
        "%{disp32%} mov       dword ptr [ecx + 0x000000ec], eax\n\t"
        "%{disp32%} mov       dword ptr [ecx + 0x00000100], eax\n\t"
        "%{disp32%} mov       dword ptr [ecx + 0x00000104], eax\n\t"
        "%{disp32%} mov       dword ptr [ecx + 0x00000108], eax"
        :  : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall InitialiseScale__8VillagerFUl(struct Villager* this, const void* edx, unsigned long param_1)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x04]\n\t"
        "push               esi\n\t"
        "cmp                edx, dword ptr [eax + 0x00000138]\n\t"
        "%{disp8%} jae        LAB__addr_0x0074fba4\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + edx * 0x4 + 0x000002e4]\n\t"
        "mov                esi, dword ptr [ecx]\n\t"
        "push               eax\n\t"
        "call               dword ptr [esi + 0x124]\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0074fba4:\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "push               0x3f666666\n\t"
        "call               dword ptr [edx + 0x124]\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_ret))
void __fastcall __dt__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "test               byte ptr [ecx + 0x000000e0], 0x40\n\t"
        "mov                dword ptr [ecx], 0x008f7960\n\t"
        "%{disp8%} jne        LAB__addr_0x0074fbda\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "dec                dword ptr [eax + 0x00205a54]\n"
        "LAB__addr_0x0074fbda:\n\t"
        "%{disp32%} jmp       _jmp_addr_0x0060db00"
        : : "c"(this) : "eax", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV, no_callee_saves))
struct Villager* __cdecl Create__8VillagerFRC9MapCoordsPC13GVillagerInfoUli(struct MapCoords* coords, struct GVillagerInfo* info, uint32_t age, bool skeleton)
{
    struct Villager* result;
    asm volatile (
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "push               0x000000e7\n\t"
        "push               0x00c235dc\n\t"
        "push               0xa\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x28]\n\t"
        "%{disp8%} mov        ebp, dword ptr [esp + 0x24]\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x20]\n\t"
        "add                esp, 0x0c\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} ja         LAB__addr_0x0074fc25\n\t"
        "push               0x0\n\t"
        "push               esi\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               edi\n\t"
        "call               ?Create@SpecialVillager@@SAPAV1@ABUMapCoords@@PBVGVillagerInfo@@KHPAVGSpecialVillagerInfo@@@Z\n\t"
        "add                esp, 0x14\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0074fc25\n\t"
        "test               byte ptr [eax + 0x0a], 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0074fc5e\n"
        "LAB__addr_0x0074fc25:\n\t"
        "push               0x000000f3\n\t"
        "push               0x00c235dc\n\t"
        "push               0x00000130\n\t"
        "call               ?__nw@Base@@SAPAXK@Z\n\t"
        "add                esp, 0x0c\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0074fc63\n\t"
        "push               esi\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               edi\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ??0Villager@@QAE@ABUMapCoords@@PBVGVillagerInfo@@KH@Z\n\t"
        "mov.s              esi, eax\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x0074fc5c\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x658]\n"
        "LAB__addr_0x0074fc5c:\n\t"
        "mov.s              eax, esi\n"
        "LAB__addr_0x0074fc5e:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "ret\n"
        "LAB__addr_0x0074fc63:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall CallVirtualFunctionsForCreation__8VillagerFRC9MapCoords(struct Object* this, const void* edx, const struct MapCoords* param_1)
{
    asm volatile (
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [_villager_byte_0x00da6bd4]\n\t"
        "mov                al, 0x01\n\t"
        "test               al, cl\n\t"
        "push               edi\n\t"
        "%{disp8%} jne        LAB__addr_0x0074fca7\n\t"
        "mov.s              bl, cl\n\t"
        "%{disp32%} mov       ecx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "or.s               bl, al\n\t"
        "%{disp32%} mov       byte ptr [_villager_byte_0x00da6bd4], bl\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "mov                eax, 0x000001ff\n\t"
        "cmp.s              edx, eax\n\t"
        "%{disp8%} jg         LAB__addr_0x0074fc9e\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x0074fc9e:\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + eax * 0x4 + 0x04]\n\t"
        "%{disp32%} mov       dword ptr [_villager_uint_0x00da6bd0], eax\n"
        "LAB__addr_0x0074fca7:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CallVirtualFunctionsForCreation@Living@@UAEXABUMapCoords@@@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x4a0]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0074fcd6\n\t"
        "%{disp32%} mov       edx, dword ptr [_villager_uint_0x00da6bd0]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "push               edx\n\t"
        "push               edx\n\t"
        "call               dword ptr [eax + 0xf4]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0074fd37\n"
        "LAB__addr_0x0074fcd6:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8d0]\n\t"
        "cmp                eax, dword ptr [edi + 0x00000138]\n\t"
        "%{disp8%} jae        LAB__addr_0x0074fd37\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00000204]\n\t"
        "%{disp32%} mov       edx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "mov.s              ecx, eax\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jl         LAB__addr_0x0074fd04\n\t"
        "cmp                ecx, dword ptr [edx]\n\t"
        "%{disp8%} jl         LAB__addr_0x0074fd06\n"
        "LAB__addr_0x0074fd04:\n\t"
        "xor.s              ecx, ecx\n"
        "LAB__addr_0x0074fd06:\n\t"
        "%{disp8%} mov        ebx, dword ptr [edx + ecx * 0x4 + 0x04]\n\t"
        "mov.s              ecx, eax\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jl         LAB__addr_0x0074fd14\n\t"
        "cmp                ecx, dword ptr [edx]\n\t"
        "%{disp8%} jl         LAB__addr_0x0074fd16\n"
        "LAB__addr_0x0074fd14:\n\t"
        "xor.s              ecx, ecx\n"
        "LAB__addr_0x0074fd16:\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} mov        edi, dword ptr [edx + ecx * 0x4 + 0x04]\n\t"
        "%{disp8%} jl         LAB__addr_0x0074fd22\n\t"
        "cmp                eax, dword ptr [edx]\n\t"
        "%{disp8%} jl         LAB__addr_0x0074fd24\n"
        "LAB__addr_0x0074fd22:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x0074fd24:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + eax * 0x4 + 0x04]\n\t"
        "push               ebp\n\t"
        "mov                ebp, dword ptr [ecx]\n\t"
        "push               ebx\n\t"
        "push               edi\n\t"
        "call               dword ptr [ebp + 0xf4]\n\t"
        "pop                ebp\n"
        "LAB__addr_0x0074fd37:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0xb4]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "mov                edx, 0x00000001\n\t"
        "call               dword ptr [eax + 0xc4]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves))
void __fastcall DeleteDependancys__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              edi, eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008c]\n\t"
        "cmp                al, 0x0d\n\t"
        "%{disp8%} je         LAB__addr_0x0074fd9d\n\t"
        "cmp                al, 0x0e\n\t"
        "%{disp8%} je         LAB__addr_0x0074fd9d\n\t"
        "cmp                al, 0x0f\n\t"
        "%{disp8%} je         LAB__addr_0x0074fd9d\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0xd\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x0074fd9d:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetTopState@Living@@QBE?AW4VILLAGER_STATES@@XZ\n\t"
        "cmp                al, 0x1d\n\t"
        "%{disp8%} je         LAB__addr_0x0074fe01\n\t"
        "%{disp32%} mov       ebx, dword ptr [esi + 0x000000cc]\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x0074fe01\n\t"
        "%{disp8%} mov        eax, dword ptr [ebx + 0x28]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0074fe01\n"
        "LAB__addr_0x0074fdb9:\n\t"
        "cmp                dword ptr [eax + 0x04], esi\n\t"
        "%{disp8%} je         LAB__addr_0x0074fdc6\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0074fdb9\n\t"
        "%{disp8%} jmp        LAB__addr_0x0074fe01\n"
        "LAB__addr_0x0074fdc6:\n\t"
        "%{disp8%} mov        eax, dword ptr [ebx + 0x28]\n\t"
        "xor.s              ebp, ebp\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0074fe01\n"
        "LAB__addr_0x0074fdcf:\n\t"
        "cmp                dword ptr [eax + 0x04], esi\n\t"
        "mov                edi, dword ptr [eax]\n\t"
        "%{disp8%} jne        LAB__addr_0x0074fdf5\n\t"
        "cmp                eax, dword ptr [ebx + 0x28]\n\t"
        "%{disp8%} jne        LAB__addr_0x0074fde0\n\t"
        "%{disp8%} mov        dword ptr [ebx + 0x28], edi\n\t"
        "%{disp8%} jmp        LAB__addr_0x0074fde3\n"
        "LAB__addr_0x0074fde0:\n\t"
        "%{disp8%} mov        dword ptr [ebp + 0x00], edi\n"
        "LAB__addr_0x0074fde3:\n\t"
        "%{disp8%} mov        edx, dword ptr [ebx + 0x2c]\n\t"
        "dec                edx\n\t"
        "push               eax\n\t"
        "%{disp8%} mov        dword ptr [ebx + 0x2c], edx\n\t"
        "call               ??3@YAXPAX@Z\n\t"
        "add                esp, 0x04\n\t"
        "%{disp8%} jmp        LAB__addr_0x0074fdf7\n"
        "LAB__addr_0x0074fdf5:\n\t"
        "mov.s              ebp, eax\n"
        "LAB__addr_0x0074fdf7:\n\t"
        "test               edi, edi\n\t"
        "mov.s              eax, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x0074fdcf\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x10]\n"
        "LAB__addr_0x0074fe01:\n\t"
        "xor.s              ebx, ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000cc], ebx\n\t"
        "call               ?IsAMother@Villager@@QAE_NXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0074fe1c\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?FindChildrenAndOrphanThem@Villager@@QAEXXZ\n"
        "LAB__addr_0x0074fe1c:\n\t"
        "cmp.s              edi, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x0074fe30\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?RemoveDeletedVillagerFromAbode@Abode@@QAEXPAVVillager@@@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x0074fe30:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x14]\n\t"
        "cmp.s              ecx, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x0074fe46\n\t"
        "push               esi\n\t"
        "call               ?RemoveVillager@Town@@QAEXPAVVillager@@@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x0074fe46:\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp32%} lea       edx, dword ptr [eax + 0x00205bfc]\n\t"
        "mov                eax, dword ptr [edx]\n\t"
        "cmp.s              eax, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x0074feb2\n"
        "LAB__addr_0x0074fe57:\n\t"
        "cmp.s              eax, esi\n\t"
        "%{disp8%} je         LAB__addr_0x0074fe6d\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x000000e4]\n\t"
        "cmp.s              eax, ebx\n\t"
        "%{disp8%} jne        LAB__addr_0x0074fe57\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x0074fe6d:\n\t"
        "cmp.s              eax, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x0074feb2\n\t"
        "mov                eax, dword ptr [edx]\n\t"
        "cmp.s              eax, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x0074fe81\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000e4]\n\t"
        "mov                dword ptr [edx], ecx\n\t"
        "%{disp8%} jmp        LAB__addr_0x0074fea9\n"
        "LAB__addr_0x0074fe81:\n\t"
        "cmp.s              eax, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x0074feb2\n"
        "LAB__addr_0x0074fe85:\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x000000e4]\n\t"
        "cmp.s              ecx, esi\n\t"
        "%{disp8%} je         LAB__addr_0x0074fe9d\n\t"
        "mov.s              eax, ecx\n\t"
        "cmp.s              eax, ebx\n\t"
        "%{disp8%} jne        LAB__addr_0x0074fe85\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x0074fe9d:\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000e4]\n\t"
        "%{disp32%} mov       dword ptr [eax + 0x000000e4], ecx\n"
        "LAB__addr_0x0074fea9:\n\t"
        "dec                dword ptr [edx + 0x04]\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000e4], ebx\n"
        "LAB__addr_0x0074feb2:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall UnemployedJobs__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0074ff4b\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x00747c70\n\t"
        "mov.s              edi, eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x00747c60\n\t"
        "sub.s              edi, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x08]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x0074ff4b\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "%{disp8%} mov        ebx, dword ptr [eax + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} lea       edi, dword ptr [eax + 0x00205a40]\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x000006f0]\n\t"
        "mov                ecx, dword ptr [edi]\n\t"
        "%{disp8%} mov        eax, dword ptr [ebx + 0x50]\n\t"
        "sub.s              ecx, edx\n\t"
        "cmp.s              ecx, eax\n\t"
        "pop                ebx\n\t"
        "%{disp8%} jbe        LAB__addr_0x0074ff4b\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov                ecx, dword ptr [edi]\n\t"
        "%{disp32%} mov       dword ptr [eax + 0x000006f0], ecx\n"
        "LAB__addr_0x0074ff4b:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x08"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool __fastcall SetupJobLocation__8VillagerFv(struct Villager* this)
{
    return 0;
}

__attribute__((XOR32rr_REV, no_callee_saves))
uint32_t __fastcall ProcessState__8VillagerFv(struct Object* this)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x14\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} inc       word ptr [esi + 0x00000090]\n\t"
        "push               edi\n\t"
        "call               ?ProcessFoodSpeedup@Villager@@QAEXXZ\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008c]\n\t"
        "lea                eax, dword ptr [eax + eax * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "%{disp32%} lea       eax, dword ptr [eax + 0x00d09218]\n\t"
        "mov.s              edx, eax\n\t"
        "mov                ecx, dword ptr [edx]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} mov        edi, dword ptr [edx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edi\n\t"
        "%{disp8%} mov        edi, dword ptr [edx + 0x08]\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "%{disp8%} je         LAB__addr_0x0074ffcb\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        edi, dword ptr [eax + 0x08]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x0c]\n\t"
        "add.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "call               edx\n"
        "LAB__addr_0x0074ffcb:\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008d]\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x8]\n\t"
        "shl                ecx, 4\n\t"
        "%{disp32%} lea       eax, dword ptr [ecx + 0x00d09218]\n\t"
        "mov.s              edx, eax\n\t"
        "mov                ecx, dword ptr [edx]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} mov        edi, dword ptr [edx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edi\n\t"
        "%{disp8%} mov        edi, dword ptr [edx + 0x08]\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "%{disp8%} je         LAB__addr_0x00750013\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        edi, dword ptr [eax + 0x08]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x0c]\n\t"
        "add.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "call               edx\n"
        "LAB__addr_0x00750013:\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cx, word ptr [esi + 0x000000e0]\n\t"
        "shr                ecx, 0xb\n\t"
        "and                ecx, 0x01\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00750047\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @IsReadyForNewAnimation__6LivingFUl@12\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075003c\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?FinishedIntoOutOfAnimation@Villager@@QAEXXZ\n"
        "LAB__addr_0x0075003c:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x14\n\t"
        "ret\n"
        "LAB__addr_0x00750047:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CheckEveryTime@Villager@@QAEHXZ\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CallState@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x14"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
void __fastcall FinishedIntoOutOfAnimation__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "sub                esp, 0x14\n\t"
        "push               esi\n\t"
        "xor.s              eax, eax\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000e0]\n\t"
        "and                eax, 0x00001000\n\t"
        "cmp                eax, 0x00001000\n\t"
        "%{disp8%} jne        LAB__addr_0x007500ed\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x0000008c]\n\t"
        "push               ebx\n\t"
        "mov.s              eax, ecx\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                edx, dword ptr [eax + eax * 0x8]\n\t"
        "shl                edx, 4\n\t"
        "add                edx, 0x00d09208\n\t"
        "mov                eax, dword ptr [edx]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} mov        ebx, dword ptr [edx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [edx + 0x08]\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "pop                ebx\n\t"
        "%{disp8%} je         LAB__addr_0x007500ed\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x04], cl\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x04]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e0]\n\t"
        "cmp                eax, -0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007500ed\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8fc]\n\t"
        "and                word ptr [esi + 0x000000e0], -0x1001\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000090], 0x0000\n\t"
        "pop                esi\n\t"
        "add                esp, 0x14\n\t"
        "ret\n"
        "LAB__addr_0x007500ed:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetStateAnim@Living@@QAEXXZ\n\t"
        "and                word ptr [esi + 0x000000e0], -0x0801\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000090], 0x0000\n\t"
        "pop                esi\n\t"
        "add                esp, 0x14"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves))
enum ANIM_LIST __fastcall GetAnimId__8VillagerFv(struct Living* this)
{
    enum ANIM_LIST result;
    asm volatile (
        "sub                esp, 0x10\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008c]\n\t"
        "cmp                al, -0x01\n\t"
        "push               edi\n\t"
        "%{disp8%} jae        LAB__addr_0x00750125\n\t"
        "test               al, al\n\t"
        "%{disp8%} jne        LAB__addr_0x00750130\n"
        "LAB__addr_0x00750125:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000181\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10\n\t"
        "ret\n"
        "LAB__addr_0x00750130:\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetStateCarriedObject@Villager@@QAEXXZ\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x0000008c]\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "%{disp32%} lea       eax, dword ptr [eax + 0x00d091f8]\n\t"
        "mov.s              edi, eax\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} mov        ebx, dword ptr [edi + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [edi + 0x08]\n\t"
        "%{disp8%} mov        edi, dword ptr [edi + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edi\n\t"
        "pop                ebx\n\t"
        "%{disp8%} je         LAB__addr_0x00750187\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        edi, dword ptr [eax + 0x08]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x0c]\n\t"
        "add.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n\t"
        "call               edx\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10\n\t"
        "ret\n"
        "LAB__addr_0x00750187:\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx * 0x4 + 0x00db9e78]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
void __fastcall SetStateCarriedObject__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "cmp                al, 0x04\n\t"
        "%{disp32%} je        LAB__addr_0x00750299\n\t"
        "cmp                byte ptr [esi + 0x0000008c], -0x38\n\t"
        "%{disp32%} je        LAB__addr_0x00750299\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       byte ptr [esi + 0x000000f1], 0x01\n\t"
        "call               dword ptr [edx + 0x11c]\n\t"
        "%{disp32%} fcomp     dword ptr [edi + 0x00000380]\n\t"
        "pop                edi\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x00750225\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "movsx              ecx, word ptr [esi + 0x000000f6]\n\t"
        "cmp                ecx, dword ptr [eax + 0x0000026c]\n\t"
        "%{disp8%} jle        LAB__addr_0x00750204\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetWoodCarriedObject@Villager@@QAEIXZ\n\t"
        "%{disp32%} mov       byte ptr [esi + 0x000000f1], al\n\t"
        "%{disp8%} jmp        LAB__addr_0x00750225\n\t"
        "LAB__addr_0x00750204:\n\t"
        "movsx              edx, word ptr [esi + 0x000000f4]\n\t"
        "cmp                edx, dword ptr [eax + 0x00000270]\n\t"
        "%{disp8%} jle        LAB__addr_0x00750225\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?FUN_00753140@Villager@@QAEIXZ\n\t"
        "test               al, al\n\t"
        "%{disp8%} jne        LAB__addr_0x00750225\n\t"
        "%{disp32%} mov       byte ptr [esi + 0x000000f1], 0x06\n\t"
        "LAB__addr_0x00750225:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "mov.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx * 0x4 + 0x00db9f54]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00750275\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xb04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "mov.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                eax, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax * 0x4 + 0x00db9f54]\n\t"
        "%{disp32%} mov       byte ptr [esi + 0x000000f1], cl\n\t"
        "LAB__addr_0x00750275:\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x0000008c]\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                edx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [edx * 0x4 + 0x00db9f54]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00750299\n\t"
        "%{disp32%} mov       byte ptr [esi + 0x000000f1], al\n\t"
        "LAB__addr_0x00750299:\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves))
uint32_t __fastcall GetWoodCarriedObject__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       ax, word ptr [ecx + 0x000000e0]\n\t"
        "shr                eax, 0xe\n\t"
        "dec                eax\n\t"
        "%{disp8%} je         LAB__addr_0x007502c7\n\t"
        "dec                eax\n\t"
        "%{disp8%} je         LAB__addr_0x007502c1\n\t"
        "dec                eax\n\t"
        "%{disp8%} je         LAB__addr_0x007502bb\n\t"
        "mov                eax, 0x0000000c\n\t"
        "ret\n"
        "LAB__addr_0x007502bb:\n\t"
        "mov                eax, 0x0000000f\n\t"
        "ret\n"
        "LAB__addr_0x007502c1:\n\t"
        "mov                eax, 0x0000000e\n\t"
        "ret\n"
        "LAB__addr_0x007502c7:\n\t"
        "mov                eax, 0x0000000d"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008)))
uint32_t __fastcall DestroyedByEffect__8VillagerFP7GPlayerf(struct Object* this, const void* edx, struct GPlayer* param_1, float param_2)
{
    uint32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x04]\n\t"
        "push               0x1\n\t"
        "push               eax\n\t"
        "push               edx\n\t"
        "push               0x2\n\t"
        "call               ?VillagerDead@Villager@@QAEXW4DEATH_REASON@@PAVGPlayer@@MH@Z\n\t"
        "mov                eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
struct GPlayer* __fastcall GetPlayer__8VillagerFv(struct GameThing* this)
{
    struct GPlayer* result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075030a\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "add                eax, 0x2c\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0075030a:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

enum HOLD_TYPE __fastcall GetHoldType__8VillagerFv(struct Object* this)
{
    return 7;
}

__attribute__((suppress_fp_imm))
float __fastcall GetHoldLoweringMultiplier__8VillagerFv(struct Object* this)
{
    extern const float __opaque_rdata_0x3420 asm("_rdata_const_0x3420");
    return __opaque_rdata_0x3420;
}

__attribute__((XOR32rr_REV, no_callee_saves))
struct Villager* __fastcall GetSpouse__8VillagerFv(struct Villager* this)
{
    struct Villager* result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00750361\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetSpouse@Abode@@QAEPAVVillager@@PAV2@@Z\n\t"
        "mov.s              esi, eax\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x00750361\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00750361\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00750361:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0008)))
struct Villager* __fastcall LookAroundForVillagerInState__8VillagerF15VILLAGER_STATESUl(struct Villager* this, const void* edx, enum VILLAGER_STATES param_1, unsigned long param_2)
{
    struct Villager* result;
    asm volatile (
        "sub                esp, 0x10\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x20]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "mov                ecx, 0x00000001\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], edx\n\t"
        "mov.s              edi, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], ecx\n\t"
        "%{disp8%} je         LAB__addr_0x007503ff\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x20]\n"
        "LAB__addr_0x007503aa:\n\t"
        "push               0x0\n\t"
        "push               0x009cafc8\n\t"
        "push               0x009c7f50\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x20]\n\t"
        "call               ?GetFirstObjectMobile@MapCoords@@QBEPAVObject@@XZ\n\t"
        "push               eax\n\t"
        "call               ___RTDynamicCast\n\t"
        "add                esp, 0x14\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007503de\n\t"
        "cmp.s              eax, esi\n\t"
        "%{disp8%} je         LAB__addr_0x007503de\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [eax + 0x0000008c]\n\t"
        "cmp.s              ecx, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x00750401\n"
        "LAB__addr_0x007503de:\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x24]\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x10]\n\t"
        "push               eax\n\t"
        "dec                edi\n\t"
        "call               ?Spiral@GUtils@@SAPBUJustMapXZ@@AAJ0@Z\n\t"
        "add                esp, 0x08\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "call               @__apl__9MapCoordsFRC9JustMapXZ@12\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x007503aa\n"
        "LAB__addr_0x007503ff:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x00750401:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x10"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
int __fastcall CheckEveryTime__8VillagerFv(struct Villager* this)
{
    int result;
    asm volatile (
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x0000008c]\n\t"
        "push               edi\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "test               byte ptr [esi + 0x25], 0x04\n\t"
        "lea                eax, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} lea       edi, dword ptr [eax * 0x4 + _GVillagerStateTableInfos]\n\t"
        "%{disp32%} jne       LAB__addr_0x0075065c\n\t"
        "%{disp8%} mov        eax, dword ptr [edi + 0x24]\n\t"
        "test               eax, eax\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} je         LAB__addr_0x00750471\n\t"
        "%{disp32%} mov       eax, dword ptr [edi + 0x00000108]\n\t"
        "push               0x0\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x5b8]\n\t"
        "fstp               st(0)\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x0000008d]\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} lea       edi, dword ptr [ecx * 0x4 + _GVillagerStateTableInfos]\n\t"
        "%{disp8%} jmp        LAB__addr_0x007504a1\n"
        "LAB__addr_0x00750471:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xb04]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "and                eax, 0x000000ff\n\t"
        "mov.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                eax, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax * 0x4 + 0x00db9f70]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x5b8]\n\t"
        "fstp               st(0)\n"
        "LAB__addr_0x007504a1:\n\t"
        "%{disp32%} mov       eax, dword ptr [edi + 0x000000f4]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x007505fc\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x11c]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x40\n\t"
        "%{disp8%} je         LAB__addr_0x0075050c\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "cmp                al, -0x08\n\t"
        "%{disp8%} je         LAB__addr_0x007504ea\n\t"
        "cmp                al, -0x07\n\t"
        "%{disp8%} je         LAB__addr_0x007504ea\n\t"
        "cmp                al, -0x06\n\t"
        "%{disp8%} je         LAB__addr_0x007504ea\n\t"
        "test               byte ptr [esi + 0x000000e0], 0x02\n\t"
        "mov                edi, 0x00000008\n\t"
        "%{disp8%} je         LAB__addr_0x007504ef\n"
        "LAB__addr_0x007504ea:\n\t"
        "mov                edi, 0x00000004\n"
        "LAB__addr_0x007504ef:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "push               eax\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?VillagerDead@Villager@@QAEXW4DEATH_REASON@@PAVGPlayer@@MH@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "ret\n"
        "LAB__addr_0x0075050c:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetGameTurnsSinceLastChecked@Villager@@QAEIXZ\n\t"
        "mov.s              ebx, eax\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "cmp                ebx, dword ptr [eax + 0x000002dc]\n\t"
        "%{disp32%} jbe       LAB__addr_0x007505fc\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "push               ebp\n\t"
        "%{disp32%} mov       ebp, dword ptr [ecx + 0x00205a40]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x00436a80\n\t"
        "add.s              eax, ebp\n\t"
        "xor.s              edx, edx\n\t"
        "mov                ecx, 0x00000320\n\t"
        "div                ecx\n\t"
        "pop                ebp\n\t"
        "cmp.s              edx, ebx\n\t"
        "%{disp8%} jae        LAB__addr_0x00750557\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CheckDeathFromOldAge@Villager@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x0075065c\n"
        "LAB__addr_0x00750557:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        ebx, dword ptr [esi + 0x28]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x11c]\n\t"
        "%{disp32%} fcomp     dword ptr [ebx + 0x0000035c]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007505c9\n\t"
        "test               byte ptr [esi + 0x000000e0], 0x04\n\t"
        "%{disp8%} jne        LAB__addr_0x007505c9\n\t"
        "%{disp32%} mov       eax, dword ptr [edi + 0x000000f8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007505c9\n\t"
        "test               byte ptr [esi + 0x000000b4], -0x80\n\t"
        "%{disp8%} jne        LAB__addr_0x007505c9\n\t"
        "%{disp32%} mov       eax, dword ptr [edi + 0x000000e8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007505c9\n\t"
        "cmp                edi, 0x00dbb2e4\n\t"
        "%{disp8%} je         LAB__addr_0x007505a7\n\t"
        "cmp                edi, 0x00dbb3f8\n\t"
        "%{disp8%} jne        LAB__addr_0x007505bd\n"
        "LAB__addr_0x007505a7:\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} fld       dword ptr [esi + 0x000000e8]\n\t"
        "%{disp32%} fcomp     dword ptr [eax + 0x000002c0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x007505c9\n"
        "LAB__addr_0x007505bd:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x24\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x007505c9:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007505de\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CheckChildGrownUp@Villager@@QAEHXZ\n"
        "LAB__addr_0x007505de:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsWoman@Villager@@QAE_NXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x007505f1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?WomanSpecial@Villager@@QAEIXZ\n"
        "LAB__addr_0x007505f1:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CheckHungry@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "ret\n"
        "LAB__addr_0x007505fc:\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cx, word ptr [esi + 0x000000e0]\n\t"
        "shr                ecx, 9\n\t"
        "test               cl, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075065c\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x000000f2]\n\t"
        "%{disp32%} lea       edx, dword ptr [eax * 0x8 + 0x00000000]\n\t"
        "sub.s              edx, eax\n\t"
        "cmp                dword ptr [edx * 0x4 + 0x0099a204], 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0075065c\n\t"
        "cmp                byte ptr [esi + 0x0000008d], -0x23\n\t"
        "%{disp8%} jne        LAB__addr_0x0075065c\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075065c\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x000005e8]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075065c\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n"
        "LAB__addr_0x0075065c:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

uint32_t __fastcall GetGameTurnsSinceLastChecked__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00205a40]\n\t"
        "sub                eax, dword ptr [ecx + 0x000000ec]"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

int __fastcall GetGameTurnLastChecked__8VillagerFv(struct Villager* this)
{
    return this->last_check_turn;
}

void __fastcall SetGameTurnLastChecked__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00205a40]\n\t"
        "%{disp32%} mov       dword ptr [ecx + 0x000000ec], edx"
        :  : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0010)))
void __fastcall VillagerDead__8VillagerF12DEATH_REASONP7GPlayerfi(struct Villager* this, const void* edx, enum DEATH_REASON param_1, struct GPlayer* param_2, float param_3, int param_4)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "test               byte ptr [esi + 0x24], 0x40\n\t"
        "%{disp32%} jne       LAB__addr_0x00750930\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0xaf4]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x00750930\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x0c]\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x00750713\n\t"
        "cmp                ebx, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00750713\n\t"
        "cmp                ebx, 0x03\n\t"
        "%{disp8%} je         LAB__addr_0x00750713\n\t"
        "cmp                ebx, 0x04\n\t"
        "%{disp8%} je         LAB__addr_0x00750713\n\t"
        "cmp                ebx, 0x08\n\t"
        "%{disp8%} je         LAB__addr_0x00750713\n\t"
        "cmp                ebx, 0x09\n\t"
        "%{disp8%} je         LAB__addr_0x00750713\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "push               0x1\n\t"
        "push               0x0\n\t"
        "call               _jmp_addr_0x0064da80\n"
        "LAB__addr_0x00750713:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               ebp\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "mov.s              ebp, eax\n\t"
        "test               ebp, ebp\n\t"
        "%{disp8%} jne        LAB__addr_0x00750740\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [ecx + 0x00205a5b]\n\t"
        "lea                edx, dword ptr [eax + eax * 0x4]\n\t"
        "lea                edx, dword ptr [eax + edx * 0x8]\n\t"
        "lea                eax, dword ptr [eax + edx * 0x2]\n\t"
        "shl                eax, 5\n\t"
        "%{disp8%} lea        ebp, dword ptr [eax + ecx * 0x1 + 0x18]\n"
        "LAB__addr_0x00750740:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x18]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00750764\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [ecx + 0x00205a5b]\n\t"
        "lea                edx, dword ptr [eax + eax * 0x4]\n\t"
        "lea                edx, dword ptr [eax + edx * 0x8]\n\t"
        "lea                eax, dword ptr [eax + edx * 0x2]\n\t"
        "shl                eax, 5\n\t"
        "%{disp8%} lea        edx, dword ptr [eax + ecx * 0x1 + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n"
        "LAB__addr_0x00750764:\n\t"
        "call               _jmp_addr_0x00555880\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x18]\n\t"
        "mov.s              edi, eax\n\t"
        "push               edi\n\t"
        "call               ?IsMemberOfThisPlayer@GPlayer@@QAEIPAVGInterfaceStatus@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00750792\n\t"
        "lea                eax, dword ptr [ebx + ebx * 0x2]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax * 0x4 + _villager_struct_0x0099a364]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x007507c0\n\t"
        "%{disp8%} mov        ecx, dword ptr [edi + 0x30]\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x0071ce70\n\t"
        "%{disp8%} jmp        LAB__addr_0x007507c0\n"
        "LAB__addr_0x00750792:\n\t"
        "push               edi\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               ?IsMemberOfThisPlayer@GPlayer@@QAEIPAVGInterfaceStatus@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007507c0\n\t"
        "lea                ecx, dword ptr [ebx + ebx * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx * 0x4 + 0x0099a370]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007507c0\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "call               _jmp_addr_0x00555880\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x0071c810\n\t"
        "add                esp, 0x04\n"
        "LAB__addr_0x007507c0:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x20]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007507d5\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CreateDroppedResource@Villager@@QAEXPAULHPoint@@00@Z\n"
        "LAB__addr_0x007507d5:\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?DropWood@Villager@@QAEGG@Z\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?DropFood@Villager@@QAEGG@Z\n\t"
        "xor.s              edx, edx\n\t"
        "%{disp32%} mov       dx, word ptr [esi + 0x000000e0]\n\t"
        "shr                edx, 9\n\t"
        "test               dl, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00750805\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetVillagerDisciple@Villager@@QAEIPAVGameThing@@W4VILLAGER_DISCIPLE@@H@Z\n"
        "LAB__addr_0x00750805:\n\t"
        "test               ebp, ebp\n\t"
        "%{disp8%} je         LAB__addr_0x0075081d\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} mov        edi, dword ptr [ebp + 0x60]\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x004143b0\n"
        "LAB__addr_0x0075081d:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              edi, eax\n\t"
        "test               edi, edi\n\t"
        "%{disp32%} je        LAB__addr_0x007508f4\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x1c]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x18]\n\t"
        "push               eax\n\t"
        "push               ebx\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x0073e0a0\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x1c]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x18]\n\t"
        "push               edx\n\t"
        "push               eax\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x0073e440\n\t"
        "test               ebp, ebp\n\t"
        "%{disp32%} je        LAB__addr_0x007508f4\n\t"
        "cmp                ebx, 0x04\n\t"
        "%{disp8%} jne        LAB__addr_0x00750883\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "call               _jmp_addr_0x00555880\n\t"
        "mov.s              edi, eax\n\t"
        "push               edi\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               ?IsMemberOfThisPlayer@GPlayer@@QAEIPAVGInterfaceStatus@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007508f4\n\t"
        "%{disp8%} mov        ecx, dword ptr [edi + 0x30]\n\t"
        "call               _jmp_addr_0x0071cfe0\n\t"
        "%{disp8%} jmp        LAB__addr_0x007508f4\n"
        "LAB__addr_0x00750883:\n\t"
        "%{disp8%} mov        ecx, dword ptr [edi + 0x28]\n\t"
        "%{disp32%} mov       edx, dword ptr [edi + 0x00000618]\n\t"
        "cmp                edx, dword ptr [ecx + 0x00000150]\n\t"
        "%{disp8%} jbe        LAB__addr_0x007508cc\n\t"
        "lea                eax, dword ptr [ebx + ebx * 0x2]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax * 0x4 + 0x0099a36c]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x007508f4\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "call               _jmp_addr_0x00555880\n\t"
        "mov.s              edi, eax\n\t"
        "cmp                dword ptr [esp + 0x18], ebp\n\t"
        "%{disp8%} je         LAB__addr_0x007508f4\n\t"
        "push               edi\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               ?IsMemberOfThisPlayer@GPlayer@@QAEIPAVGInterfaceStatus@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007508f4\n\t"
        "%{disp8%} mov        ecx, dword ptr [edi + 0x30]\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x0071c990\n\t"
        "%{disp8%} jmp        LAB__addr_0x007508f4\n"
        "LAB__addr_0x007508cc:\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "call               _jmp_addr_0x00555880\n\t"
        "push               eax\n\t"
        "mov.s              ecx, ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], eax\n\t"
        "call               ?IsMemberOfThisPlayer@GPlayer@@QAEIPAVGInterfaceStatus@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007508f4\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x1c]\n\t"
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x30]\n\t"
        "push               edi\n\t"
        "call               ?HelpSpritesLowOnPeople@GGuidance@@QAEXAAVTown@@@Z\n"
        "LAB__addr_0x007508f4:\n\t"
        "%{disp32%} mov       dl, byte ptr [esi + 0x000000b4]\n\t"
        "and                dl, 0x01\n\t"
        "cmp                dl, 0x01\n\t"
        "pop                edi\n\t"
        "pop                ebp\n\t"
        "%{disp8%} je         LAB__addr_0x00750929\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x6a4]\n\t"
        "cmp                ebx, 0x07\n\t"
        "%{disp8%} jne        LAB__addr_0x00750929\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00000a44]\n\t"
        "%{disp32%} inc       dword ptr [eax + 0x00001124]\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], 0x0000\n"
        "LAB__addr_0x00750929:\n\t"
        "%{disp32%} mov       byte ptr [esi + 0x00000118], bl\n\t"
        "pop                ebx\n"
        "LAB__addr_0x00750930:\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x000c)))
void __fastcall CreateDroppedResource__8VillagerFP7LHPointP7LHPointP7LHPoint(struct Villager* this, const void* edx, struct LHPoint* param_1, struct LHPoint* param_2, struct LHPoint* param_3)
{
    asm volatile (
        "sub                esp, 0x24\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "%{disp32%} mov       cx, word ptr [edi + 0x000000f6]\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [edi + 0x000000f1]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp32%} jle       LAB__addr_0x00750a9a\n\t"
        "cmp                eax, 0x10\n\t"
        "%{disp32%} jge       LAB__addr_0x00750a9a\n\t"
        "%{disp8%} mov        edx, dword ptr [edi + 0x28]\n\t"
        "%{disp32%} mov       esi, dword ptr [edx + 0x0000026c]\n\t"
        "movsx              ecx, cx\n\t"
        "cmp.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "%{disp32%} jle       LAB__addr_0x00750a9a\n\t"
        "%{disp8%} lea        ecx, dword ptr [edi + 0x14]\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], edx\n\t"
        "%{disp8%} mov        edx, dword ptr [ecx + 0x04]\n\t"
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax * 0x4 + 0x00c5e19c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], edx\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0xf8]\n\t"
        "push               eax\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x3fc90fdb\n\t"
        "push               0x3f800000\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x38]\n\t"
        "push               0x00da49d8\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x00510bb0\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x2c]\n\t"
        "mov.s              esi, eax\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "add                esp, 0x20\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x664]\n\t"
        "%{disp8%} fdivr      dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x30]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} fstp      dword ptr [esi + 0x0000009c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], 0x00000000\n\t"
        "%{disp8%} je         LAB__addr_0x00750a23\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x34]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x00750a13\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n"
        "LAB__addr_0x00750a13:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "push               0x1\n\t"
        "push               0x0\n\t"
        "push               ecx\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x20]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00750a39\n"
        "LAB__addr_0x00750a23:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "push               0x1\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x20]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x24]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x20]\n"
        "LAB__addr_0x00750a39:\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x784]\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], eax\n\t"
        "%{disp8%} je         LAB__addr_0x00750a91\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x38]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00750a6d\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "add                eax, 0x00000090\n\t"
        "mov                dword ptr [eax], edx\n\t"
        "%{disp8%} mov        edx, dword ptr [ecx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x04], edx\n\t"
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x08], ecx\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n"
        "LAB__addr_0x00750a6d:\n\t"
        "or                 dword ptr [eax + 0x1d8], 0x10\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x08]\n\t"
        "push               0x1\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        ecx, dword ptr [edx + 0x28]\n\t"
        "call               _jmp_addr_0x007fcb80\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x00644800\n\t"
        "add                esp, 0x04\n"
        "LAB__addr_0x00750a91:\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?DropWood@Villager@@QAEGG@Z\n"
        "LAB__addr_0x00750a9a:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x24"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves))
bool32_t __fastcall HasSunk__8VillagerFv(struct Object* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00750abe\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00750abe:\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x0063a710\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00750af2\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x0063a710\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "mov.s              edi, eax\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00750af2\n\t"
        "push               0x0\n\t"
        "push               esi\n\t"
        "push               0x15\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x0063a710\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x004ea900\n"
        "LAB__addr_0x00750af2:\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       dl, byte ptr [esi + 0x000000b4]\n\t"
        "%{disp32%} mov       cx, word ptr [eax + 0x0000039a]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "and                dl, 0x01\n\t"
        "cmp                dl, 0x01\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], cx\n\t"
        "pop                edi\n\t"
        "%{disp8%} jne        LAB__addr_0x00750b30\n\t"
        "push               0xe\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       dx, word ptr [ecx + 0x00000290]\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], dx\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00750b30:\n\t"
        "push               0x10\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

void __fastcall TownDeleted__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} lea       ecx, dword ptr [eax + 0x00205bfc]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00750b78\n\t"
        "LAB__addr_0x00750b64:\n\t"
        "cmp.s              eax, esi\n\t"
        "%{disp8%} je         LAB__addr_0x00750b74\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x000000e4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00750b64\n\t"
        "%{disp8%} jmp        LAB__addr_0x00750b78\n\t"
        "LAB__addr_0x00750b74:\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00750b89\n\t"
        "LAB__addr_0x00750b78:\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000e4], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + 0x04]\n\t"
        "inc                eax\n\t"
        "mov                dword ptr [ecx], esi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x04], eax\n\t"
        "LAB__addr_0x00750b89:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x00000082\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetTown@Villager@@QAEXPAVTown@@@Z\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall DebugText__8VillagerFi(struct Villager* this, const void* edx, int param_1)
{
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [_global + 0x118]\n\t"
        "sub                esp, 0x000003d4\n\t"
        "test               eax, eax\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x00750dcf\n\t"
        "%{disp32%} mov       eax, dword ptr [esp + 0x000003dc]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x00750dcf\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "cmp                al, -0x01\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x04], al\n\t"
        "%{disp32%} jae       LAB__addr_0x00750c80\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "shl                ecx, 3\n\t"
        "sub.s              ecx, eax\n\t"
        "lea                ecx, dword ptr [ecx + ecx * 0x2]\n\t"
        "%{disp32%} lea       edx, dword ptr [ecx * 0x4 + 0x00db9ea0]\n\t"
        "push               edx\n\t"
        "%{disp32%} lea       eax, dword ptr [esp + 0x00000214]\n\t"
        "push               0x009c8c40\n\t"
        "push               eax\n\t"
        "call               _sprintf\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cx, word ptr [esi + 0x000000f6]\n\t"
        "xor.s              edx, edx\n\t"
        "%{disp32%} mov       dx, word ptr [esi + 0x000000f4]\n\t"
        "add                esp, 0x0c\n\t"
        "push               esi\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "push               edx\n\t"
        "call               dword ptr [eax + 0x8d0]\n\t"
        "movsx              ecx, word ptr [esi + 0x58]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "%{disp32%} lea       edx, dword ptr [esp + 0x00000224]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetGameTurnLastChecked@Villager@@QAEHXZ\n\t"
        "push               eax\n\t"
        "%{disp32%} fld       dword ptr [esi + 0x000000e8]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "sub                esp, 0x08\n\t"
        "mov.s              ecx, esi\n\t"
        "fstp               qword ptr [esp]\n\t"
        "call               dword ptr [eax + 0x11c]\n\t"
        "sub                esp, 0x08\n\t"
        "fstp               qword ptr [esp]\n\t"
        "%{disp32%} lea       ecx, dword ptr [esp + 0x00000174]\n\t"
        "push               0x00c23644\n\t"
        "push               ecx\n\t"
        "call               _sprintf\n\t"
        "add                esp, 0x34\n"
        "LAB__addr_0x00750c80:\n\t"
        "%{disp32%} lea       edx, dword ptr [esp + 0x00000148]\n\t"
        "push               edx\n\t"
        "push               0x00cd3b24\n\t"
        "call               _jmp_addr_0x00511d80\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "add                esp, 0x08\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              edx, eax\n\t"
        "test               edx, edx\n\t"
        "%{disp32%} je        LAB__addr_0x00750dcf\n\t"
        "%{disp32%} mov       eax, dword ptr [edx + 0x00000974]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jbe       LAB__addr_0x00750dcf\n\t"
        "%{disp32%} mov       ecx, dword ptr [_s_Novelty_00c2363c]\n\t"
        "%{disp32%} mov       eax, dword ptr [_s_Novelty_00c2363c + 4]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], eax\n\t"
        "push               edi\n\t"
        "xor.s              eax, eax\n\t"
        "mov                ecx, 0x0000000e\n\t"
        "%{disp8%} lea        edi, dword ptr [esp + 0x14]\n\t"
        "rep stosd\n\t"
        "%{disp32%} mov       ecx, dword ptr [_s_Ignore_00c23634]\n\t"
        "%{disp32%} mov       ax, word ptr [_s_Ignore_00c23634 + 4]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x4c], ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [_s_Ignore_00c23634 + 6]\n\t"
        "%{disp8%} mov        word ptr [esp + 0x50], ax\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x52], cl\n\t"
        "xor.s              eax, eax\n\t"
        "mov                ecx, 0x0000000e\n\t"
        "%{disp8%} lea        edi, dword ptr [esp + 0x53]\n\t"
        "rep stosd\n\t"
        "%{disp32%} mov       ecx, dword ptr [_s_Curiosity_00c23628 + 4]\n\t"
        "stosb\n\t"
        "%{disp32%} mov       eax, dword ptr [_s_Curiosity_00c23628]\n\t"
        "%{disp32%} mov       dword ptr [esp + 0x0000008c], eax\n\t"
        "%{disp32%} mov       ax, word ptr [_s_Curiosity_00c23628 + 8]\n\t"
        "%{disp32%} mov       dword ptr [esp + 0x00000090], ecx\n\t"
        "%{disp32%} mov       word ptr [esp + 0x00000094], ax\n\t"
        "xor.s              eax, eax\n\t"
        "mov                ecx, 0x0000000d\n\t"
        "%{disp32%} lea       edi, dword ptr [esp + 0x00000096]\n\t"
        "rep stosd\n\t"
        "%{disp32%} mov       ecx, dword ptr [_s_Fear_00c23620]\n\t"
        "stosw\n\t"
        "%{disp32%} mov       al, byte ptr [_s_Fear_00c23620 + 4]\n\t"
        "%{disp32%} mov       dword ptr [esp + 0x000000cc], ecx\n\t"
        "%{disp32%} mov       byte ptr [esp + 0x000000d0], al\n\t"
        "xor.s              eax, eax\n\t"
        "mov                ecx, 0x0000000e\n\t"
        "%{disp32%} lea       edi, dword ptr [esp + 0x000000d1]\n\t"
        "rep stosd\n\t"
        "%{disp32%} mov       ecx, dword ptr [_s_Respect_00c23618]\n\t"
        "stosw\n\t"
        "stosb\n\t"
        "%{disp32%} mov       eax, dword ptr [_s_Respect_00c23618 + 4]\n\t"
        "%{disp32%} mov       dword ptr [esp + 0x0000010c], ecx\n\t"
        "%{disp32%} mov       dword ptr [esp + 0x00000110], eax\n\t"
        "xor.s              eax, eax\n\t"
        "mov                ecx, 0x0000000e\n\t"
        "%{disp32%} lea       edi, dword ptr [esp + 0x00000114]\n\t"
        "rep stosd\n\t"
        "%{disp32%} mov       ecx, dword ptr [edx + 0x00000970]\n\t"
        "%{disp8%} mov        edx, dword ptr [ecx + 0x04]\n\t"
        "%{disp8%} mov        eax, dword ptr [edx + 0x14]\n\t"
        "shl                eax, 6\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + eax * 0x1 + 0x0c]\n\t"
        "push               ecx\n\t"
        "%{disp32%} lea       edx, dword ptr [esp + 0x000002e0]\n\t"
        "push               0x00c235fc\n\t"
        "push               edx\n\t"
        "call               _sprintf\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp32%} lea       eax, dword ptr [esp + 0x000002dc]\n\t"
        "push               eax\n\t"
        "push               0x00cd3b24\n\t"
        "call               _jmp_addr_0x00511d80\n\t"
        "add                esp, 0x08\n\t"
        "pop                edi\n"
        "LAB__addr_0x00750dcf:\n\t"
        "pop                esi\n\t"
        "add                esp, 0x000003d4"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall SetAbode__8VillagerFP5Abode(struct Villager* this, const void* edx, struct Town* town)
{
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "mov.s              esi, ecx\n\t"
        "push               0x0\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000128], edi\n\t"
        "call               ?SetTown@Villager@@QAEXPAVTown@@@Z\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00750e08\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetTown@Villager@@QAEXPAVTown@@@Z\n"
        "LAB__addr_0x00750e08:\n\t"
        "pop                edi\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008)))
bool32_t __fastcall GetRandomLookAhead__8VillagerFP9MapCoordsf(struct Villager* this, const void* edx, struct MapCoords* param_1, float param_2)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "push               ebx\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x40\n\t"
        "%{disp8%} je         LAB__addr_0x00750e4c\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x000002a4]\n\t"
        "push               0x000003f1\n\t"
        "push               0x00c235dc\n\t"
        "push               eax\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float1p0]\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n"
        "LAB__addr_0x00750e4c:\n\t"
        "%{disp8%} mov        di, word ptr [esi + 0x5c]\n\t"
        "push               0x000003f4\n\t"
        "push               0x00c235dc\n\t"
        "push               0x00000200\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x20]\n\t"
        "add                esi, 0x14\n\t"
        "%{disp32%} lea       edi, dword ptr [eax + edi * 0x1 + -0x00000100]\n\t"
        "mov.s              ecx, esi\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x1c]\n\t"
        "mov.s              edx, esi\n\t"
        "mov                dword ptr [edx], eax\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [edx + 0x04], eax\n\t"
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x08]\n\t"
        "and                edi, 0x000007ff\n\t"
        "push               ebx\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        dword ptr [edx + 0x08], ecx\n\t"
        "call               ?GetXByAngleMetersDistance@GUtils@@SAXGM@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "add.s              edx, eax\n\t"
        "push               ebx\n\t"
        "push               edi\n\t"
        "mov                dword ptr [esi], edx\n\t"
        "call               ?GetXByAngleMetersDistance@GUtils@@SAXGM@Z\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x04]\n\t"
        "add.s              edi, eax\n\t"
        "add                esp, 0x1c\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x04], edi\n\t"
        "call               ?InBounds@MapCoords@@QBEIXZ\n\t"
        "neg                eax\n\t"
        "pop                edi\n\t"
        "sbb.s              eax, eax\n\t"
        "pop                esi\n\t"
        "neg                eax\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008)))
void __fastcall SetSpeed__8VillagerFli(struct Villager* this, const void* edx, int base_speed, int scale_speed)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n\t"
        "sub                esp, 0x08\n\t"
        "test               eax, eax\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x00751014\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x3c]\n\t"
        "fstp               st(0)\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 4\n\t"
        "sub.s              eax, ecx\n\t"
        "cdq\n\t"
        "mov                ecx, 0x0000001f\n\t"
        "idiv               ecx\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "mov.s              ecx, esi\n\t"
        "sub                edx, 0x10\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x18]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x1bb10]\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float1p0]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x18]\n\t"
        "call               dword ptr [edx + 0x8d0]\n\t"
        "cmp                eax, dword ptr [edi + 0x00000138]\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} jae        LAB__addr_0x00750f7d\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8d0]\n\t"
        "%{disp32%} mov       ecx, dword ptr [edi + 0x00000138]\n\t"
        "sub.s              ecx, eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x08]\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float0p2]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3404]\n\t"
        "%{disp32%} fcom      dword ptr [rdata_bytes + 0x1ea44]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00750f74\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} fld       dword ptr [rdata_bytes + 0x1ea44]\n"
        "LAB__addr_0x00750f74:\n\t"
        "%{disp8%} fsubr      dword ptr [esp + 0x18]\n\t"
        "%{disp32%} jmp       LAB__addr_0x00751014\n"
        "LAB__addr_0x00750f7d:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8d0]\n\t"
        "cmp                eax, dword ptr [edi + 0x0000013c]\n\t"
        "%{disp8%} jbe        LAB__addr_0x00750fd9\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8d0]\n\t"
        "sub                eax, dword ptr [edi + 0x0000013c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x08]\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float0p2]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3404]\n\t"
        "%{disp32%} fcom      dword ptr [rdata_bytes + 0x1ea44]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00750f74\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} fld       dword ptr [rdata_bytes + 0x1ea44]\n\t"
        "%{disp8%} fsubr      dword ptr [esp + 0x18]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00751014\n"
        "LAB__addr_0x00750fd9:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetDesireForFood@Villager@@QAEMXZ\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3404]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} fsubr      dword ptr [esp + 0x18]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x18]\n\t"
        "call               dword ptr [edx + 0x11c]\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3404]\n\t"
        "cmp                dword ptr [eax + 0x000001f8], 0x01\n\t"
        "%{disp8%} fsubr      dword ptr [esp + 0x18]\n\t"
        "%{disp8%} jne        LAB__addr_0x00751014\n\t"
        "%{disp32%} fsub      dword ptr [__real@3e4ccccd]\n"
        "LAB__addr_0x00751014:\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x14]\n\t"
        "fmul               st, st(1)\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "fstp               st(0)\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetSpeed@MobileWallHug@@UAEXH@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x08"
        ::: "eax", "ecx", "edx", "memory"
    );
}

void __fastcall Birthday__8VillagerFv(struct Living* this)
{
    return;
}

__attribute__((XOR32rr_REV, no_callee_saves))
int __fastcall CheckChildGrownUp__8VillagerFv(struct Villager* this)
{
    int result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "call               dword ptr [eax + 0x8d0]\n\t"
        "cmp                eax, dword ptr [edi + 0x00000138]\n\t"
        ".byte              0x72, 0x6f\n\t"
        ".byte              0x66, 0x81, 0xa6, 0xe0, 0x0, 0x0, 0x0, 0xf7, 0xff\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00000138]\n\t"
        "cmp                eax, 0x12\n\t"
        "%{disp8%} jae        LAB__addr_0x00751083\n\t"
        "mov                eax, 0x00000012\n"
        "LAB__addr_0x00751083:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8d4]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007510b2\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?ChildToAdult@Abode@@QAEXPAVVillager@@@Z\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ChildBecomesAdult@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007510b2:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007510cc\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?ChildToAdult@Town@@QAEXPAVVillager@@@Z\n"
        "LAB__addr_0x007510cc:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ChildBecomesAdult@Villager@@QAEIXZ\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007510d6:\n\t"
        "%{disp32%} mov       edx, dword ptr [_game]\n\t"
        "%{disp32%} mov       ecx, dword ptr [_GGameInfo_00d019f8 + 0xc]\n\t"
        "%{disp32%} mov       eax, dword ptr [edx + 0x00205a40]\n\t"
        "shr                ecx, 2\n\t"
        "xor.s              edx, edx\n\t"
        "div                ecx\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} jne        LAB__addr_0x00751105\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8d0]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetScaleForAge@Villager@@QAEXK@Z\n"
        "LAB__addr_0x00751105:\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsAMother__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x000001f8]\n\t"
        "xor.s              ecx, ecx\n\t"
        "cmp                edx, 0x01\n\t"
        "sete               cl\n\t"
        "mov.s              eax, ecx\n\t"
        "ret\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "sub                esp, 0x14\n\t"
        "xor.s              eax, eax\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x00], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "%{disp8%} mov        word ptr [esp + 0x10], cx\n\t"
        "mov                ecx, 0x00da6ddc\n"
        "LAB__addr_0x00751151:\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "%{disp8%} inc        word ptr [esp + edx * 0x2 + 0x00]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + edx * 0x2 + 0x00]\n\t"
        "add                ecx, 0x000003a4\n\t"
        "%{disp32%} lea       edx, dword ptr [ecx + -0x000001f4]\n\t"
        "cmp                edx, OFFSET _VillagerInfos + 0x131D0\n\t"
        ".byte              0x72, 0xe1\n\t"
        "push               esi\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x04]\n\t"
        "mov                esi, 0x00000009\n"
        "LAB__addr_0x0075117a:\n\t"
        "xor.s              ecx, ecx\n\t"
        "mov                cx, word ptr [edx]\n\t"
        "cmp.s              ecx, eax\n\t"
        "%{disp8%} jbe        LAB__addr_0x00751185\n\t"
        "mov.s              eax, ecx\n"
        "LAB__addr_0x00751185:\n\t"
        "add                edx, 0x02\n\t"
        "dec                esi\n\t"
        "%{disp8%} jne        LAB__addr_0x0075117a\n\t"
        "pop                esi\n\t"
        "add                esp, 0x14"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008), no_tail_call))
bool32_t __fastcall StartMoveToObject__8VillagerFP6Object15VILLAGER_STATES(struct Villager* this, const void* edx, struct Object* param_1, enum VILLAGER_STATES param_2)
{
    // Local int-typed declaration to avoid movzx on the byte param
    extern bool __fastcall SetupMoveToObject_dword(struct Living*, const void*, struct Object*, int) asm("?SetupMoveToObject@Living@@QAEIPAVObject@@E@Z");
    SetupMoveToObject_dword((struct Living*)this, edx, param_1, param_2);
    return 1;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0008)))
uint16_t __fastcall DropResource__8VillagerF13RESOURCE_TYPEUs(struct Villager* this, const void* edx, enum RESOURCE_TYPE param_1, unsigned short param_2)
{
    uint16_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x007511c6\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "call               ?DropWood@Villager@@QAEGG@Z\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x007511c6:\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007511d7\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x08]\n\t"
        "push               edx\n\t"
        "call               ?DropFood@Villager@@QAEGG@Z\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x007511d7:\n\t"
        "xor.s              ax, ax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint16_t __fastcall DropFood__8VillagerFUs(struct Villager* this, const void* edx, unsigned short param_1)
{
    uint16_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "test               di, di\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x007511f9\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000f4]\n\t"
        "cmp.s              di, ax\n\t"
        "%{disp8%} jbe        LAB__addr_0x00751204\n"
        "LAB__addr_0x007511f9:\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000f4]\n\t"
        "mov.s              edi, eax\n"
        "LAB__addr_0x00751204:\n\t"
        "sub.s              eax, edi\n\t"
        "%{disp32%} mov       word ptr [esi + 0x000000f4], ax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751238\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "add                eax, 0x00000708\n\t"
        "mov.s              ecx, edi\n\t"
        "and                ecx, 0x0000ffff\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x0c]\n\t"
        "fsubr              dword ptr [eax]\n\t"
        "fstp               dword ptr [eax]\n"
        "LAB__addr_0x00751238:\n\t"
        "mov.s              ax, di\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint16_t __fastcall DropWood__8VillagerFUs(struct Villager* this, const void* edx, unsigned short param_1)
{
    uint16_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "test               di, di\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00751259\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000f6]\n\t"
        "cmp.s              di, ax\n\t"
        "%{disp8%} jbe        LAB__addr_0x00751264\n"
        "LAB__addr_0x00751259:\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000f6]\n\t"
        "mov.s              edi, eax\n"
        "LAB__addr_0x00751264:\n\t"
        "sub.s              eax, edi\n\t"
        "%{disp32%} mov       word ptr [esi + 0x000000f6], ax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751298\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "add                eax, 0x0000070c\n\t"
        "mov.s              ecx, edi\n\t"
        "and                ecx, 0x0000ffff\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], ecx\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x0c]\n\t"
        "fsubr              dword ptr [eax]\n\t"
        "fstp               dword ptr [eax]\n"
        "LAB__addr_0x00751298:\n\t"
        "mov.s              ax, di\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsEnoughFoodInStoragePitForDinner__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007512d5\n\t"
        "push               edi\n\t"
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
        "pop                edi\n\t"
        "%{disp8%} ja         LAB__addr_0x007512d5\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007512d5:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x000c)))
struct Pot* __fastcall FindPotAroundToGoto__8VillagerF13RESOURCE_TYPERUli(struct Villager* this, const void* edx, enum RESOURCE_TYPE param_1, unsigned long* param_2, int param_3)
{
    struct Pot* result;
    asm volatile (
        "sub                esp, 0x18\n\t"
        "push               ebx\n\t"
        "%{disp8%} lea        ebx, dword ptr [ecx + 0x14]\n\t"
        "mov.s              eax, ebx\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "push               ebp\n\t"
        "%{disp8%} mov        ebp, dword ptr [esp + 0x24]\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x30]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], eax\n\t"
        "mov                eax, 0x00000001\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x00000000\n\t"
        "mov                dword ptr [edi], 0xffffffff\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x30], 0x00000009\n"
        "LAB__addr_0x0075132b:\n\t"
        "push               0x0\n\t"
        "push               0x009c8eb0\n\t"
        "push               0x009c7f50\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x15\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x34]\n\t"
        "call               @FindType__9MapCoordsCF11OBJECT_TYPEP6Object@16\n\t"
        "push               eax\n\t"
        "call               ___RTDynamicCast\n\t"
        "mov.s              esi, eax\n\t"
        "add                esp, 0x14\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x007513ba\n"
        "LAB__addr_0x00751355:\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "cmp                dword ptr [eax + 0x00000118], ebp\n\t"
        "%{disp8%} je         LAB__addr_0x00751365\n\t"
        "cmp                ebp, -0x02\n\t"
        "%{disp8%} jne        LAB__addr_0x00751391\n"
        "LAB__addr_0x00751365:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x34]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00751378\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x70]\n\t"
        "cmp                ecx, dword ptr [eax + 0x0000011c]\n\t"
        "%{disp8%} jae        LAB__addr_0x00751391\n"
        "LAB__addr_0x00751378:\n\t"
        "%{disp8%} lea        edx, dword ptr [esi + 0x14]\n\t"
        "push               edx\n\t"
        "push               ebx\n\t"
        "call               ?FastDistance@GUtils@@SAHABUMapCoords@@0@Z\n\t"
        "mov                ecx, dword ptr [edi]\n\t"
        "add                esp, 0x08\n\t"
        "cmp.s              eax, ecx\n\t"
        "%{disp8%} jae        LAB__addr_0x00751391\n\t"
        "mov                dword ptr [edi], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], esi\n"
        "LAB__addr_0x00751391:\n\t"
        "push               0x0\n\t"
        "push               0x009c8eb0\n\t"
        "push               0x009c7f50\n\t"
        "push               0x0\n\t"
        "push               esi\n\t"
        "push               0x15\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x34]\n\t"
        "call               @FindType__9MapCoordsCF11OBJECT_TYPEP6Object@16\n\t"
        "push               eax\n\t"
        "call               ___RTDynamicCast\n\t"
        "mov.s              esi, eax\n\t"
        "add                esp, 0x14\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x00751355\n"
        "LAB__addr_0x007513ba:\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "push               ecx\n\t"
        "call               ?Spiral@GUtils@@SAPBUJustMapXZ@@AAJ0@Z\n\t"
        "add                esp, 0x08\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x20]\n\t"
        "call               @__apl__9MapCoordsFRC9JustMapXZ@12\n\t"
        "dec                dword ptr [esp + 0x30]\n\t"
        "%{disp32%} jne       LAB__addr_0x0075132b\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x10]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x18"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x000c)))
void __fastcall PickupResource__8VillagerF13RESOURCE_TYPEsUc(struct Villager* this, const void* edx, enum RESOURCE_TYPE param_1, short param_2, unsigned char param_3)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "test               eax, eax\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x10]\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x00751433\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "add                word ptr [esi + 0x000000f4], di\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751487\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "movsx              ecx, di\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "add                eax, 0x00000708\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x14]\n\t"
        "fadd               dword ptr [eax]\n\t"
        "fstp               dword ptr [eax]\n\t"
        "mov.s              ax, di\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret                0x000c\n"
        "LAB__addr_0x00751433:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "add                word ptr [esi + 0x000000f6], di\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751460\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "movsx              ecx, di\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ecx\n\t"
        "add                eax, 0x0000070c\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x10]\n\t"
        "fadd               dword ptr [eax]\n\t"
        "fstp               dword ptr [eax]\n"
        "LAB__addr_0x00751460:\n\t"
        "%{disp8%} mov        dl, byte ptr [esp + 0x14]\n\t"
        "and                dl, 0x03\n\t"
        "xor.s              ax, ax\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cx, word ptr [esi + 0x000000e0]\n\t"
        "mov.s              al, dl\n\t"
        "and                ecx, 0x00003fff\n\t"
        "shl                eax, 0xe\n\t"
        "or.s               eax, ecx\n\t"
        "%{disp32%} mov       word ptr [esi + 0x000000e0], ax\n"
        "LAB__addr_0x00751487:\n\t"
        "mov.s              ax, di\n\t"
        "pop                edi\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall PickupFood__8VillagerFs(struct Villager* this, const void* edx, short param_1)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "push               0x0\n\t"
        "push               eax\n\t"
        "push               0x0\n\t"
        "call               ?PickupResource@Villager@@QAEXW4RESOURCE_TYPE@@FE@Z"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008)))
void __fastcall PickupWood__8VillagerFsUc(struct Villager* this, const void* edx, short param_1, unsigned char param_2)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x04]\n\t"
        "push               eax\n\t"
        "push               edx\n\t"
        "push               0x1\n\t"
        "call               ?PickupResource@Villager@@QAEXW4RESOURCE_TYPE@@FE@Z"
        ::: "eax", "ecx", "edx", "memory"
    );
}

int __fastcall GetFoodCapacity__8VillagerFv(struct Villager* this)
{
    int result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} mov       cx, word ptr [ecx + 0x000000f4]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00000264]\n\t"
        "sub.s              eax, ecx"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

int __fastcall GetWoodCapacity__8VillagerFv(struct Villager* this)
{
    int result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} mov       cx, word ptr [ecx + 0x000000f6]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00000268]\n\t"
        "sub.s              eax, ecx"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004), no_tail_call))
void __fastcall RemoveFromDance__8VillagerFi(struct Living* this, const void* edx, int param_1)
{
    RemoveFromDance__6LivingFi(this, edx, param_1);
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsRandomlyLazy__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               esi\n\t"
        "%{disp8%} mov        esi, dword ptr [ecx + 0x28]\n\t"
        "push               0x00000566\n\t"
        "push               0x00c235dc\n\t"
        "push               0x64\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x10]\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp32%} fld       dword ptr [esi + 0x00000288]\n\t"
        "pop                esi\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x241c]\n\t"
        "fcompp\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0075156a\n\t"
        "mov                eax, 0x00000001\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x0075156a:\n\t"
        "xor.s              eax, eax\n\t"
        "add                esp, 0x08"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall GetResourceHeld__8VillagerFR13RESOURCE_TYPE(struct Villager* this, const void* edx, enum RESOURCE_TYPE* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        edx, dword ptr [esp + 0x04]\n\t"
        "mov                dword ptr [edx], 0xffffffff\n\t"
        "%{disp32%} mov       ax, word ptr [ecx + 0x000000f6]\n\t"
        "cmp                word ptr [ecx + 0x000000f4], ax\n\t"
        "%{disp8%} jbe        LAB__addr_0x0075159c\n\t"
        "xor.s              eax, eax\n\t"
        "mov                dword ptr [edx], 0x00000000\n\t"
        "%{disp32%} mov       ax, word ptr [ecx + 0x000000f4]\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0075159c:\n\t"
        "test               ax, ax\n\t"
        "%{disp8%} je         LAB__addr_0x007515b3\n\t"
        "xor.s              eax, eax\n\t"
        "mov                dword ptr [edx], 0x00000001\n\t"
        "%{disp32%} mov       ax, word ptr [ecx + 0x000000f6]\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007515b3:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall DecideWhatToDo__8VillagerFv(struct Living* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007515f4\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?IsInStateOfEmergency@Town@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007515f4\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000f2\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007515f4:\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000e0]\n\t"
        "mov.s              ecx, eax\n\t"
        "shr                ecx, 9\n\t"
        "test               cl, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0075160c\n\t"
        "test               ah, 0x04\n\t"
        "%{disp8%} je         LAB__addr_0x00751687\n"
        "LAB__addr_0x0075160c:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?DiscipleDecideWhatToDo@Villager@@QAE_NXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00751666\n\t"
        "test               byte ptr [esi + 0x000000e1], 0x04\n\t"
        "%{disp8%} je         LAB__addr_0x0075162a\n\t"
        "%{disp32%} mov       byte ptr [esi + 0x000000f2], 0x00\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0075162a:\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x000000f2]\n\t"
        "%{disp32%} lea       edx, dword ptr [eax * 0x8 + 0x00000000]\n\t"
        "sub.s              edx, eax\n\t"
        "%{disp32%} mov       eax, dword ptr [edx * 0x4 + 0x0099a1fc]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x007516d9\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "push               eax\n\t"
        "push               0x18\n\t"
        "push               esi\n\t"
        "call               ?CreateReaction@Reaction@@SAPAV1@PAVGameThingWithPos@@EPAVGPlayer@@H@Z\n\t"
        "add                esp, 0x10\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00751666:\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000e0]\n\t"
        "test               ah, 0x04\n\t"
        "%{disp8%} je         LAB__addr_0x00751687\n\t"
        "and                eax, 0x0000f9ff\n\t"
        "%{disp32%} mov       byte ptr [esi + 0x000000f2], 0x00\n\t"
        "%{disp32%} mov       word ptr [esi + 0x000000e0], ax\n"
        "LAB__addr_0x00751687:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} je         LAB__addr_0x007516ad\n\t"
        "call               ?ChildDecideWhatToDo@Villager@@QAEIXZ\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007516ad:\n\t"
        "call               ?CheckNeededForSomething@Villager@@QAEIXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007516d9\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CheckTakeResourcesToStoragePit@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007516d9\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupNothingToDo@Villager@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007516d9\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x24\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x007516d9:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall CheckTakeResourcesToStoragePit__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "movsx              edx, word ptr [ecx + 0x000000f6]\n\t"
        "cmp                edx, dword ptr [eax + 0x0000026c]\n\t"
        "%{disp8%} jg         LAB__addr_0x00751704\n\t"
        "movsx              edx, word ptr [ecx + 0x000000f4]\n\t"
        "cmp                edx, dword ptr [eax + 0x00000270]\n\t"
        "%{disp8%} jg         LAB__addr_0x00751704\n\t"
        "xor.s              eax, eax\n\t"
        "ret\n"
        "LAB__addr_0x00751704:\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "push               0x1f\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov                eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_ret))
bool __fastcall DiscipleDecideWhatToDo__8VillagerFv(struct Villager* this)
{
    asm("push               ecx");                                            // 0x00751720    51
    asm("push               esi");                                            // 0x00751721    56
    asm("xor.s              eax, eax");                                       // 0x00751722    33c0
    asm("mov.s              esi, ecx");                                       // 0x00751724    8bf1
    asm("{disp32} mov       al, byte ptr [esi + 0x000000f2]");                // 0x00751726    8a86f2000000
    asm("push               edi");                                            // 0x0075172c    57
    asm("{disp8} lea        ecx, dword ptr [eax + -0x01]");                   // 0x0075172d    8d48ff
    asm("cmp                ecx, 0x0b");                                      // 0x00751730    83f90b
    asm("{disp32} ja        LAB__addr_0x007518e7");                           // 0x00751733    0f87ae010000
    asm("jmp                dword ptr [ecx*4 + 0x75193c]");                   // 0x00751739    ff248d3c197500
    asm("mov                eax, dword ptr [esi]");                           // 0x00751740    8b06
    asm("mov.s              ecx, esi");                                       // 0x00751742    8bce
    asm("call               dword ptr [eax + 0x48]");                         // 0x00751744    ff5048
    asm("test               eax, eax");                                       // 0x00751747    85c0
    asm("{disp32} je        LAB__addr_0x007518e7");                           // 0x00751749    0f8498010000
    asm("mov                edx, dword ptr [esi]");                           // 0x0075174f    8b16
    asm("{disp8} lea        ecx, dword ptr [esp + 0x08]");                    // 0x00751751    8d4c2408
    asm("push               ecx");                                            // 0x00751755    51
    asm("push               esi");                                            // 0x00751756    56
    asm("mov.s              ecx, esi");                                       // 0x00751757    8bce
    asm("call               dword ptr [edx + 0x48]");                         // 0x00751759    ff5248
    asm("mov.s              ecx, eax");                                       // 0x0075175c    8bc8
    asm("call               _jmp_addr_0x0073e870");                           // 0x0075175e    e80dd1feff
    asm("mov.s              edi, eax");                                       // 0x00751763    8bf8
    asm("test               edi, edi");                                       // 0x00751765    85ff
    asm("{disp32} je        LAB__addr_0x007518e7");                           // 0x00751767    0f847a010000
    asm("push               0x0");                                            // 0x0075176d    6a00
    asm("mov.s              ecx, edi");                                       // 0x0075176f    8bcf
    asm("call               ?GetFieldActivity@Field@@QAEHH@Z");                           // 0x00751771    e8da7bddff
    asm("cmp                eax, 0x02");                                      // 0x00751776    83f802
    asm("{disp8} jne        LAB__addr_0x007517a3");                           // 0x00751779    7528
    asm("{disp8} mov        eax, dword ptr [esi + 0x28]");                    // 0x0075177b    8b4628
    asm("{disp32} mov       cx, word ptr [esi + 0x000000f4]");                // 0x0075177e    668b8ef4000000
    asm("cmp                cx, word ptr [eax + 0x00000270]");                // 0x00751785    663b8870020000
    asm("{disp8} jle        LAB__addr_0x007517a3");                           // 0x0075178c    7e15
    asm("mov                edx, dword ptr [esi]");                           // 0x0075178e    8b16
    asm("push               0x1f");                                           // 0x00751790    6a1f
    asm("mov.s              ecx, esi");                                       // 0x00751792    8bce
    asm("call               dword ptr [edx + 0x8e8]");                        // 0x00751794    ff92e8080000
    asm("pop                edi");                                            // 0x0075179a    5f
    asm("mov                eax, 0x00000001");                                // 0x0075179b    b801000000
    asm("pop                esi");                                            // 0x007517a0    5e
    asm("pop                ecx");                                            // 0x007517a1    59
    asm("ret");                                                               // 0x007517a2    c3
    asm("LAB__addr_0x007517a3:");
    asm("push               edi");                                            // 0x007517a3    57
    asm("mov.s              ecx, esi");                                       // 0x007517a4    8bce
    asm("call               ?VillagerBecomesFarmer@Villager@@QAEIPAVField@@@Z");                           // 0x007517a6    e855840000
    asm("cmp                eax, 0x01");                                      // 0x007517ab    83f801
    asm("{disp32} jne       LAB__addr_0x007518e7");                           // 0x007517ae    0f8533010000
    asm("pop                edi");                                            // 0x007517b4    5f
    asm("pop                esi");                                            // 0x007517b5    5e
    asm("pop                ecx");                                            // 0x007517b6    59
    asm("ret");                                                               // 0x007517b7    c3
    asm("mov.s              ecx, esi");                                       // 0x007517b8    8bce
    asm("call               ?CheckSatisfyWoodDesire@Villager@@QAEIXZ");                           // 0x007517ba    e8e1dc0000
    asm("cmp                eax, 0x01");                                      // 0x007517bf    83f801
    asm("{disp32} jne       LAB__addr_0x007518e7");                           // 0x007517c2    0f851f010000
    asm("pop                edi");                                            // 0x007517c8    5f
    asm("pop                esi");                                            // 0x007517c9    5e
    asm("pop                ecx");                                            // 0x007517ca    59
    asm("ret");                                                               // 0x007517cb    c3
    asm("mov.s              ecx, esi");                                       // 0x007517cc    8bce
    asm("call               ?FishermanLookForWater@Villager@@QAEIXZ");                           // 0x007517ce    e8ed9c0000
    asm("cmp                eax, 0x01");                                      // 0x007517d3    83f801
    asm("{disp32} jne       LAB__addr_0x007518e7");                           // 0x007517d6    0f850b010000
    asm("pop                edi");                                            // 0x007517dc    5f
    asm("pop                esi");                                            // 0x007517dd    5e
    asm("pop                ecx");                                            // 0x007517de    59
    asm("ret");                                                               // 0x007517df    c3
    asm("mov.s              ecx, esi");                                       // 0x007517e0    8bce
    asm("call               ?CheckNeededForBuilding@Villager@@QAEIXZ");                           // 0x007517e2    e8596b0000
    asm("cmp                eax, 0x01");                                      // 0x007517e7    83f801
    asm("{disp32} jne       LAB__addr_0x007518e7");                           // 0x007517ea    0f85f7000000
    asm("pop                edi");                                            // 0x007517f0    5f
    asm("pop                esi");                                            // 0x007517f1    5e
    asm("pop                ecx");                                            // 0x007517f2    59
    asm("ret");                                                               // 0x007517f3    c3
    asm("mov.s              ecx, esi");                                       // 0x007517f4    8bce
    asm("call               ?SetupBreederDisciple@Villager@@QAEIXZ");                           // 0x007517f6    e8e5860100
    asm("cmp                eax, 0x01");                                      // 0x007517fb    83f801
    asm("{disp32} jne       LAB__addr_0x007518e7");                           // 0x007517fe    0f85e3000000
    asm("pop                edi");                                            // 0x00751804    5f
    asm("pop                esi");                                            // 0x00751805    5e
    asm("pop                ecx");                                            // 0x00751806    59
    asm("ret");                                                               // 0x00751807    c3
    asm("mov.s              ecx, esi");                                       // 0x00751808    8bce
    asm("call               ?CheckSatisfySupplyWorkshop@Villager@@QAEIXZ");                           // 0x0075180a    e8917b0000
    asm("test               eax, eax");                                       // 0x0075180f    85c0
    asm("{disp32} je        LAB__addr_0x007518e7");                           // 0x00751811    0f84d0000000
    asm("pop                edi");                                            // 0x00751817    5f
    asm("mov                eax, 0x00000001");                                // 0x00751818    b801000000
    asm("pop                esi");                                            // 0x0075181d    5e
    asm("pop                ecx");                                            // 0x0075181e    59
    asm("ret");                                                               // 0x0075181f    c3
    asm("mov.s              ecx, esi");                                       // 0x00751820    8bce
    asm("call               ?CheckTrader@Villager@@QAEIXZ");                           // 0x00751822    e859830100
    asm("cmp                eax, 0x01");                                      // 0x00751827    83f801
    asm("{disp32} jne       LAB__addr_0x007518e7");                           // 0x0075182a    0f85b7000000
    asm("pop                edi");                                            // 0x00751830    5f
    asm("pop                esi");                                            // 0x00751831    5e
    asm("pop                ecx");                                            // 0x00751832    59
    asm("ret");                                                               // 0x00751833    c3
    asm("mov                eax, dword ptr [esi]");                           // 0x00751834    8b06
    asm("mov.s              ecx, esi");                                       // 0x00751836    8bce
    asm("call               dword ptr [eax + 0x1c]");                         // 0x00751838    ff501c
    asm("push               0x0");                                            // 0x0075183b    6a00
    asm("push               0x0");                                            // 0x0075183d    6a00
    asm("push               esi");                                            // 0x0075183f    56
    asm("mov.s              ecx, esi");                                       // 0x00751840    8bce
    asm("mov.s              edi, eax");                                       // 0x00751842    8bf8
    asm("call               ?SetVillagerDisciple@Villager@@QAEIPAVGameThing@@W4VILLAGER_DISCIPLE@@H@Z");                           // 0x00751844    e8b7470000
    asm("push               0x0");                                            // 0x00751849    6a00
    asm("push               0x0");                                            // 0x0075184b    6a00
    asm("push               0x0");                                            // 0x0075184d    6a00
    asm("{disp8} lea        ecx, dword ptr [esi + 0x14]");                    // 0x0075184f    8d4e14
    asm("push               -0x1");                                           // 0x00751852    6aff
    asm("push               ecx");                                            // 0x00751854    51
    asm("call               _jmp_addr_0x0074dd70");                           // 0x00751855    e816c5ffff
    asm("add                esp, 0x14");                                      // 0x0075185a    83c414
    asm("push               eax");                                            // 0x0075185d    50
    asm("mov.s              ecx, esi");                                       // 0x0075185e    8bce
    asm("call               ?CheckMoveHouse@Villager@@QAEIPAVObject@@@Z");    // 0x00751860    e81b590000
    asm("cmp                eax, 0x01");                                      // 0x00751865    83f801
    asm("{disp8} jne        LAB__addr_0x007518e7");                           // 0x00751868    757d
    asm("mov                edx, dword ptr [esi]");                           // 0x0075186a    8b16
    asm("push               0x000000ea");                                     // 0x0075186c    68ea000000
    asm("mov.s              ecx, esi");                                       // 0x00751871    8bce
    asm("call               dword ptr [edx + 0x8e8]");                        // 0x00751873    ff92e8080000
    asm("mov                eax, dword ptr [esi]");                           // 0x00751879    8b06
    asm("mov.s              ecx, esi");                                       // 0x0075187b    8bce
    asm("call               dword ptr [eax + 0x1c]");                         // 0x0075187d    ff501c
    asm("cmp.s              edi, eax");                                       // 0x00751880    3bf8
    asm("{disp8} je         LAB__addr_0x00751896");                           // 0x00751882    7412
    asm("mov                edx, dword ptr [esi]");                           // 0x00751884    8b16
    asm("push               0x1");                                            // 0x00751886    6a01
    asm("push               0xd");                                            // 0x00751888    6a0d
    asm("mov.s              ecx, esi");                                       // 0x0075188a    8bce
    asm("call               dword ptr [edx + 0x1c]");                         // 0x0075188c    ff521c
    asm("mov.s              ecx, eax");                                       // 0x0075188f    8bc8
    asm("call               _jmp_addr_0x0064da80");                           // 0x00751891    e8eac1efff
    asm("LAB__addr_0x00751896:");
    asm("pop                edi");                                            // 0x00751896    5f
    asm("mov                eax, 0x00000001");                                // 0x00751897    b801000000
    asm("pop                esi");                                            // 0x0075189c    5e
    asm("pop                ecx");                                            // 0x0075189d    59
    asm("ret");                                                               // 0x0075189e    c3
    asm("mov                eax, dword ptr [esi]");                           // 0x0075189f    8b06
    asm("push               0x3a");                                           // 0x007518a1    6a3a
    asm("mov.s              ecx, esi");                                       // 0x007518a3    8bce
    asm("call               dword ptr [eax + 0x8e8]");                        // 0x007518a5    ff90e8080000
    asm("pop                edi");                                            // 0x007518ab    5f
    asm("mov                eax, 0x00000001");                                // 0x007518ac    b801000000
    asm("pop                esi");                                            // 0x007518b1    5e
    asm("pop                ecx");                                            // 0x007518b2    59
    asm("ret");                                                               // 0x007518b3    c3
    asm("mov                edx, dword ptr [esi]");                           // 0x007518b4    8b16
    asm("{disp32} lea       ecx, dword ptr [eax * 0x8 + 0x00000000]");        // 0x007518b6    8d0cc500000000
    asm("sub.s              ecx, eax");                                       // 0x007518bd    2bc8
    asm("xor.s              eax, eax");                                       // 0x007518bf    33c0
    asm("{disp32} mov       al, byte ptr [ecx * 0x4 + _DiscipleInfos]");      // 0x007518c1    8a048df8a19900
    asm("mov.s              ecx, esi");                                       // 0x007518c8    8bce
    asm("push               eax");                                            // 0x007518ca    50
    asm("call               dword ptr [edx + 0x8e8]");                        // 0x007518cb    ff92e8080000
    asm("push               0x0");                                            // 0x007518d1    6a00
    asm("push               0x0");                                            // 0x007518d3    6a00
    asm("push               0x0");                                            // 0x007518d5    6a00
    asm("mov.s              ecx, esi");                                       // 0x007518d7    8bce
    asm("call               ?SetVillagerDisciple@Villager@@QAEIPAVGameThing@@W4VILLAGER_DISCIPLE@@H@Z");                           // 0x007518d9    e822470000
    asm("pop                edi");                                            // 0x007518de    5f
    asm("mov                eax, 0x00000001");                                // 0x007518df    b801000000
    asm("pop                esi");                                            // 0x007518e4    5e
    asm("pop                ecx");                                            // 0x007518e5    59
    asm("ret");                                                               // 0x007518e6    c3
    asm("LAB__addr_0x007518e7:");
    asm("mov                edx, dword ptr [esi]");                           // 0x007518e7    8b16
    asm("mov.s              ecx, esi");                                       // 0x007518e9    8bce
    asm("call               dword ptr [edx + 0xb04]");                        // 0x007518eb    ff92040b0000
    asm("cmp                al, -0x23");                                      // 0x007518f1    3cdd
    asm("{disp8} je         LAB__addr_0x00751934");                           // 0x007518f3    743f
    asm("xor.s              eax, eax");                                       // 0x007518f5    33c0
    asm("{disp32} mov       ax, word ptr [esi + 0x000000e0]");                // 0x007518f7    668b86e0000000
    asm("shr                eax, 9");                                         // 0x007518fe    c1e809
    asm("test               al, 0x01");                                       // 0x00751901    a801
    asm("{disp8} je         LAB__addr_0x00751934");                           // 0x00751903    742f
    asm("xor.s              eax, eax");                                       // 0x00751905    33c0
    asm("{disp32} mov       al, byte ptr [esi + 0x000000f2]");                // 0x00751907    8a86f2000000
    asm("{disp32} lea       ecx, dword ptr [eax * 0x8 + 0x00000000]");        // 0x0075190d    8d0cc500000000
    asm("sub.s              ecx, eax");                                       // 0x00751914    2bc8
    asm("cmp                dword ptr [ecx * 0x4 + 0x0099a204], 0x01");       // 0x00751916    833c8d04a2990001
    asm("{disp8} jne        LAB__addr_0x00751934");                           // 0x0075191e    7514
    asm("mov.s              ecx, esi");                                       // 0x00751920    8bce
    asm("call               ?SetDiscipleNothingToDo@Villager@@QAEIXZ");      // 0x00751922    e849270000
    asm("test               eax, eax");                                       // 0x00751927    85c0
    asm("{disp8} je         LAB__addr_0x00751934");                           // 0x00751929    7409
    asm("pop                edi");                                            // 0x0075192b    5f
    asm("mov                eax, 0x00000001");                                // 0x0075192c    b801000000
    asm("pop                esi");                                            // 0x00751931    5e
    asm("pop                ecx");                                            // 0x00751932    59
    asm("ret");                                                               // 0x00751933    c3
    asm("LAB__addr_0x00751934:");
    asm("pop                edi");                                            // 0x00751934    5f
    asm("xor.s              eax, eax");                                       // 0x00751935    33c0
    asm("pop                esi");                                            // 0x00751937    5e
    asm("pop                ecx");                                            // 0x00751938    59
    asm("ret");                                                               // 0x00751939    c3
    // Snippet: db, [0x0075193a, 0x0075193c)
    asm(".byte 0x8b, 0xff");                  // 0x0075193a
    // Snippet: jmptbl, [0x0075193c, 0x0075196c)
    asm(".byte 0x40, 0x17, 0x75, 0x00");      // 0x0075193c
    asm(".byte 0xb8, 0x17, 0x75, 0x00");      // 0x00751940
    asm(".byte 0xcc, 0x17, 0x75, 0x00");      // 0x00751944
    asm(".byte 0xe0, 0x17, 0x75, 0x00");      // 0x00751948
    asm(".byte 0xf4, 0x17, 0x75, 0x00");      // 0x0075194c
    asm(".byte 0xe7, 0x18, 0x75, 0x00");      // 0x00751950
    asm(".byte 0x34, 0x19, 0x75, 0x00");      // 0x00751954
    asm(".byte 0x08, 0x18, 0x75, 0x00");      // 0x00751958
    asm(".byte 0x20, 0x18, 0x75, 0x00");      // 0x0075195c
    asm(".byte 0x34, 0x18, 0x75, 0x00");      // 0x00751960
    asm(".byte 0x9f, 0x18, 0x75, 0x00");      // 0x00751964
    asm(".byte 0xb4, 0x18, 0x75, 0x00");      // 0x00751968
    // Snippet: db, [0x0075196c, 0x00751970)
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
bool __fastcall GetPrayerSite__8VillagerFv(struct Villager* this)
{
    return 0;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall RestartDance__8VillagerF15VILLAGER_STATES(struct Villager* this, const void* edx, enum VILLAGER_STATES param_1)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "xor.s              eax, eax\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x978]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007519d6\n\t"
        "%{disp32%} mov       edx, dword ptr [esi + 0x000000d8]\n\t"
        "%{disp8%} mov        eax, dword ptr [edx + 0x14]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x04]\n\t"
        "push               ecx\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?CalculateDancePosition@Living@@QAE_NABUMapCoords@@PAU2@@Z\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x14]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x08]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupMoveToPos@Villager@@QAE_NABUMapCoords@@W4VILLAGER_STATES@@@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007519d6:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
int __cdecl GetInfoFromText__13GVillagerInfoFPc(char* text)
{
    int result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], OFFSET _VillagerInfos\n\t"
        "mov                ebp, 0x00da57b8\n"
        "LAB__addr_0x007519fc:\n\t"
        "%{disp8%} mov        eax, dword ptr [ebp + 0x00]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax * 0x4 + 0x00c22fdc]\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x1c]\n\t"
        "or                 ecx, 0xffffffff\n\t"
        "xor.s              eax, eax\n\t"
        "mov.s              edi, edx\n\t"
        "repne scasb\n\t"
        "not                ecx\n\t"
        "dec                ecx\n\t"
        "mov.s              edi, ecx\n\t"
        "push               edi\n\t"
        "push               edx\n\t"
        "push               ebx\n\t"
        "call               __strnicmp\n\t"
        "add                esp, 0x0c\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00751a58\n\t"
        "cmp                byte ptr [edi + ebx * 0x1], 0x5f\n\t"
        "%{disp8%} jne        LAB__addr_0x00751a58\n\t"
        "%{disp8%} lea        ebx, dword ptr [edi + ebx * 0x1 + 0x01]\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x10]\n\t"
        "xor.s              esi, esi\n"
        "LAB__addr_0x00751a37:\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?GetTribeTextArray@GTribeInfo@@QAEPADXZ\n\t"
        "push               eax\n\t"
        "push               ebx\n\t"
        "call               __strcmpi\n\t"
        "add                esp, 0x08\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751a87\n\t"
        "inc                esi\n\t"
        "add                edi, 0x000003a4\n\t"
        "cmp                esi, 0x07\n\t"
        ".byte              0x72, 0xdf\n"
        "LAB__addr_0x00751a58:\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x14]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "inc                esi\n\t"
        "add                ebp, 0x1c\n\t"
        "add                ecx, 0x0000197c\n\t"
        "cmp                ebp, 0x00da58b4\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ecx\n\t"
        ".byte              0x72, 0x82\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000054\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x00751a87:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x14]\n\t"
        "%{disp32%} lea       eax, dword ptr [ecx * 0x8 + 0x00000000]\n\t"
        "pop                edi\n\t"
        "sub.s              eax, ecx\n\t"
        "add.s              eax, esi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

char* __fastcall GetTribeTextArray__10GTribeInfoFv(struct GTribeInfo* this)
{
    return (char*)VillagerBasicInfoStrs[((struct GVillagerInfo*)this)->villagerNumber];
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
char* __fastcall GetVillagerText__8VillagerFPc(struct Villager* this, const void* edx, char* param_1)
{
    char* result;
    asm volatile (
        "push               esi\n\t"
        "%{disp8%} mov        esi, dword ptr [ecx + 0x28]\n\t"
        "push               edi\n\t"
        "call               ?GetTribe@Villager@@QAEPAVGTribeInfo@@XZ\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x10]\n\t"
        "%{disp32%} mov       edi, dword ptr [eax * 0x4 + 0x00c22fdc]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetTribeTextArray@GTribeInfo@@QAEPADXZ\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "push               edi\n\t"
        "push               0x009c8054\n\t"
        "push               esi\n\t"
        "call               _sprintf\n\t"
        "add                esp, 0x10\n\t"
        "pop                edi\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0008)))
uint32_t __fastcall SaveObject__8VillagerFR8LHOSFileRC9MapCoords(struct Object* this, const void* edx, struct LHOSFile* param_1, const struct MapCoords* param_2)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x0000020c\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?CheckAndSetSaved@GameThing@@QAE_NXZ\n\t"
        "mov.s              ebx, eax\n\t"
        "test               ebx, ebx\n\t"
        "%{disp32%} je        LAB__addr_0x00751cdf\n\t"
        "%{disp32%} mov       ebp, dword ptr [esp + 0x00000224]\n\t"
        "test               ebp, ebp\n\t"
        "%{disp8%} lea        edi, dword ptr [esi + 0x14]\n\t"
        "%{disp8%} je         LAB__addr_0x00751b28\n\t"
        "push               ebp\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x20]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x006055c0\n\t"
        "%{disp8%} jmp        LAB__addr_0x00751b2a\n"
        "LAB__addr_0x00751b28:\n\t"
        "mov.s              eax, edi\n"
        "LAB__addr_0x00751b2a:\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "cmp                dword ptr [ecx + 0x000001f4], -0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00751ba9\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751b64\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp32%} mov       ebp, dword ptr [eax + 0x000005b4]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00751b67\n"
        "LAB__addr_0x00751b64:\n\t"
        "or                 ebp, 0xffffffff\n"
        "LAB__addr_0x00751b67:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8d0]\n\t"
        "push               eax\n\t"
        "sub                edi, OFFSET _VillagerInfos\n\t"
        "mov                eax, 0x8ca29c05\n\t"
        "imul               edi\n\t"
        "add.s              edx, edi\n\t"
        "sar                edx, 9\n\t"
        "mov.s              eax, edx\n\t"
        "shr                eax, 0x1f\n\t"
        "add.s              edx, eax\n\t"
        "push               edx\n\t"
        "%{disp32%} lea       ecx, dword ptr [esp + 0x000000f8]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "call               ?ConvertToText@MapCoords@@QAEPADPAD@Z\n\t"
        "push               eax\n\t"
        "push               ebp\n\t"
        "push               0x11\n\t"
        "%{disp32%} jmp       LAB__addr_0x00751ca7\n"
        "LAB__addr_0x00751ba9:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00751c5a\n\t"
        "test               ebp, ebp\n\t"
        "%{disp32%} jne       LAB__addr_0x00751c5a\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x864]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edx\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x08]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "call               dword ptr [eax + 0x8d0]\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       ecx, dword ptr [esp + 0x00000158]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetVillagerText@Villager@@QAEPADPAD@Z\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       edx, dword ptr [esp + 0x000001c0]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?ConvertToText@MapCoords@@QAEPADPAD@Z\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       eax, dword ptr [esp + 0x000000fc]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x20]\n\t"
        "call               ?ConvertToText@MapCoords@@QAEPADPAD@Z\n\t"
        "push               eax\n\t"
        "push               0x12\n\t"
        "call               ?GetCommandAsText@GSetup@@SAPADW4SCRIPT_FEATURE_COMMANDS@@@Z\n\t"
        "add                esp, 0x04\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x3c]\n\t"
        "push               ecx\n\t"
        "call               _sprintf\n\t"
        "or                 ecx, 0xffffffff\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} lea        edi, dword ptr [esp + 0x40]\n\t"
        "repne scasb\n\t"
        "%{disp32%} mov       eax, dword ptr [esp + 0x00000238]\n\t"
        "not                ecx\n\t"
        "dec                ecx\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x44]\n\t"
        "push               edx\n\t"
        "push               eax\n\t"
        "%{disp8%} jmp        LAB__addr_0x00751cd6\n"
        "LAB__addr_0x00751c5a:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751c74\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp32%} mov       edi, dword ptr [eax + 0x000005b4]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00751c77\n"
        "LAB__addr_0x00751c74:\n\t"
        "or                 edi, 0xffffffff\n"
        "LAB__addr_0x00751c77:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8d0]\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       eax, dword ptr [esp + 0x00000158]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetVillagerText@Villager@@QAEPADPAD@Z\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       ecx, dword ptr [esp + 0x000000f8]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "call               ?ConvertToText@MapCoords@@QAEPADPAD@Z\n\t"
        "push               eax\n\t"
        "push               edi\n\t"
        "push               0x10\n"
        "LAB__addr_0x00751ca7:\n\t"
        "call               ?GetCommandAsText@GSetup@@SAPADW4SCRIPT_FEATURE_COMMANDS@@@Z\n\t"
        "add                esp, 0x04\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x3c]\n\t"
        "push               edx\n\t"
        "call               _sprintf\n\t"
        "or                 ecx, 0xffffffff\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} lea        edi, dword ptr [esp + 0x40]\n\t"
        "repne scasb\n\t"
        "not                ecx\n\t"
        "dec                ecx\n\t"
        "push               ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esp + 0x0000023c]\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x44]\n\t"
        "push               eax\n\t"
        "push               ecx\n"
        "LAB__addr_0x00751cd6:\n\t"
        "push               esi\n\t"
        "call               ?WriteToFile@GSetup@@SAIPAXAAVLHOSFile@@0K@Z\n\t"
        "add                esp, 0x28\n"
        "LAB__addr_0x00751cdf:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov.s              eax, ebx\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0000020c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsFunctional__8VillagerFv(struct GameThing* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00751d12\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008c]\n\t"
        "cmp                al, 0x0d\n\t"
        ".byte              0x72, 0x4\n\t"
        "cmp                al, 0x0e\n\t"
        "%{disp8%} jbe        LAB__addr_0x00751d12\n"
        "LAB__addr_0x00751d0b:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00751d12:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
struct GJobInfo* __fastcall GetJobInfo__8VillagerCFUc(const struct Villager* this, const void* edx, unsigned char param_1)
{
    struct GJobInfo* result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x4]\n\t"
        "lea                edx, dword ptr [eax + ecx * 0x2]\n\t"
        "%{disp32%} lea       eax, dword ptr [edx * 0x8 + 0x00d19cc8]"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool __fastcall FUN00751d40__8VillagerFv(struct Villager* this)
{
    return 0;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsAvailable__8VillagerFv(struct GameThing* this)
{
    bool32_t result;
    asm volatile (
        "test               byte ptr [ecx + 0x0a], 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00751d68\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "cmp                al, 0x0e\n\t"
        "%{disp8%} je         LAB__addr_0x00751d68\n\t"
        "mov                eax, 0x00000001\n\t"
        "ret\n"
        "LAB__addr_0x00751d68:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall IsEffectReceiver__8VillagerFP12EffectValues(struct Object* this, const void* edx, struct EffectValues* param_1)
{
    uint32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751d98\n\t"
        "%{disp8%} fld        dword ptr [eax + 0x14]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x00751d98\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0xaf4]\n\t"
        "neg                eax\n\t"
        "sbb.s              eax, eax\n\t"
        "inc                eax\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00751d98:\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0x530]"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
struct Citadel* __fastcall GetCitadel__8VillagerFv(struct GameThingWithPos* this)
{
    struct Citadel* result;
    asm volatile (
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751dc7\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751dc7\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00000a48]\n\t"
        "ret\n"
        "LAB__addr_0x00751dc7:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
enum VILLAGER_STATES __fastcall GetFinalState__8VillagerCFv(const struct Living* this)
{
    enum VILLAGER_STATES result;
    asm volatile (
        "push               ecx\n\t"
        "%{disp32%} mov       al, byte ptr [ecx + 0x0000008c]\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x00], al\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x00]\n\t"
        "push               esi\n\t"
        "and                edx, 0x000000ff\n\t"
        "lea                esi, dword ptr [edx + edx * 0x2]\n\t"
        "shl                esi, 3\n\t"
        "sub.s              esi, edx\n\t"
        "lea                edx, dword ptr [esi + esi * 0x2]\n\t"
        "%{disp32%} mov       esi, dword ptr [edx * 0x4 + 0x00db9e84]\n\t"
        "test               esi, esi\n\t"
        "pop                esi\n\t"
        "%{disp8%} jne        LAB__addr_0x00751e03\n\t"
        "%{disp32%} mov       al, byte ptr [ecx + 0x0000008d]\n"
        "LAB__addr_0x00751e03:\n\t"
        "pop                ecx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

void __fastcall ResetStateAfterReacting__8VillagerFv(struct Living* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?PopFromPrevious@Villager@@QAEXXZ\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "mov.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx * 0x4 + 0x00db9f30]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751e4e\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "LAB__addr_0x00751e4e:\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV))
void __fastcall PopFromPrevious__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x0000008e]\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                eax, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax * 0x4 + 0x00db9e98]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "cmp                eax, 0x2e\n\t"
        "%{disp8%} jne        LAB__addr_0x00751e8f\n\t"
        "push               0x000000a3\n\t"
        "push               0x0\n\t"
        "%{disp32%} lea       ecx, dword ptr [esi + 0x0000008c]\n\t"
        "call               @SetState__12LivingActionFUlUc@16\n\t"
        "LAB__addr_0x00751e8f:\n\t"
        "push               0x0\n\t"
        "push               0x2\n\t"
        "%{disp32%} lea       ecx, dword ptr [esi + 0x0000008c]\n\t"
        "call               @SetState__12LivingActionFUlUc@16\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((no_ret))
__attribute__((no_ret, trailing_asm("ret\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nmov eax, dword ptr [ecx]\npush 0x0\npush 0x00bfed78\npush 0x009c7f80\npush 0x0\npush 0x3\ncall dword ptr [eax + 0x48]\nmov.s ecx, eax\ncall _jmp_addr_0x0073d7d0\nmov.s ecx, eax\ncall _jmp_addr_0x0066c9d0\npush eax\ncall ___RTDynamicCast\nadd esp, 0x14\nret")))
struct Football* __fastcall GetFootball__8VillagerFv(struct Villager* this)
{
    return this->football;
}

struct GTribeInfo* __fastcall GetTribe__8VillagerFv(struct Villager* this)
{
    void* dummy;
    struct GTribeInfo* result;
    asm volatile (
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x000001f4]\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "push               eax\n\t"
        "call               ?GetTribe@GGame@@QAEPAVGTribeInfo@@W4TRIBE_TYPE@@@Z"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

struct Town* __fastcall GetTown__8VillagerFv(struct GameThing* this)
{
    return ((struct Villager*)this)->town;
}

struct StoragePit* __fastcall GetStoragePit__8VillagerFv(struct Villager* this)
{
    void* dummy;
    struct StoragePit* result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751f2e\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetStoragePit@Town@@QAEPAVStoragePit@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00751f35\n\t"
        "LAB__addr_0x00751f2e:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "LAB__addr_0x00751f35:\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

enum VILLAGER_STATES __fastcall GetVillagerAvailableState__8VillagerFv(struct Villager* this)
{
    void* dummy;
    enum VILLAGER_STATES result;
    asm volatile (
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "mov.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx * 0x4 + 0x00db9f20]"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

enum VILLAGER_STATES __fastcall FUN_00751f70__8VillagerFv(struct Villager* this)
{
    void* dummy;
    enum VILLAGER_STATES result;
    asm volatile (
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "mov.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx * 0x4 + 0x00db9f28]"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

void __fastcall ArriveHome__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00751fc1\n\t"
        "or                 byte ptr [esi + 0xe0], 4\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?ArriveHome@Abode@@QAEXXZ\n\t"
        "LAB__addr_0x00751fc1:\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV))
void __fastcall LeaveHome__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000e0]\n\t"
        "test               al, 0x04\n\t"
        "%{disp8%} je         LAB__addr_0x00752003\n\t"
        "and                eax, 0x0000dffb\n\t"
        "%{disp32%} mov       word ptr [esi + 0x000000e0], ax\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00752003\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?LeaveHome@Abode@@QAEXXZ\n\t"
        "LAB__addr_0x00752003:\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
int __fastcall SetTopState__8VillagerFUc(struct Living* this, const void* edx, enum VILLAGER_STATES state)
{
    int result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "call               ?CanPauseForASecond@Villager@@QAEIE@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x007520b5\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x11c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x4a4]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x0c]\n\t"
        "test               al, al\n\t"
        "%{disp8%} je         LAB__addr_0x0075204c\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float0p5]\n"
        "LAB__addr_0x0075204c:\n\t"
        "%{disp32%} fsubr     dword ptr [_rdata_float1p0]\n\t"
        "mov                eax, 0x00000002\n\t"
        "fld                st(0)\n"
        "LAB__addr_0x00752059:\n\t"
        "dec                eax\n\t"
        "fmul               st, st(1)\n\t"
        "%{disp8%} jne        LAB__addr_0x00752059\n\t"
        "push               0x0000076b\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "push               0x00c235dc\n\t"
        "push               0x3f800000\n\t"
        "fstp               st(0)\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float0p5]\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "add                esp, 0x0c\n\t"
        "fsubp              st(1), st\n\t"
        "%{disp32%} fcomp     dword ptr [eax + 0x00000368]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007520b5\n\t"
        "mov.s              ecx, edi\n\t"
        "and                ecx, 0x000000ff\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupPauseForASecond@Villager@@QAEIW4VILLAGER_STATES@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007520b5\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007520b5:\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetTopState__6LivingFUc@12\n\t"
        "mov.s              edi, eax\n\t"
        "cmp                edi, 0x2f\n\t"
        "%{disp8%} jne        LAB__addr_0x007520d3\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x90c]\n"
        "LAB__addr_0x007520d3:\n\t"
        "mov.s              eax, edi\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008)))
int __fastcall SetCurrentAndDestinationState__8VillagerFUcUc(struct Living* this, const void* edx, enum VILLAGER_STATES current, enum VILLAGER_STATES destination)
{
    int result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetCurrentAndDestinationState__6LivingFUcUc@16\n\t"
        "mov.s              edi, eax\n\t"
        "cmp                edi, 0x2f\n\t"
        "%{disp8%} jne        LAB__addr_0x0075210b\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x000000a3\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x90c]\n"
        "LAB__addr_0x0075210b:\n\t"
        "mov.s              eax, edi\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall CanPauseForASecond__8VillagerFUc(struct Villager* this, const void* edx, enum VILLAGER_STATES state)
{
    uint32_t result;
    asm volatile (
        "cmp                byte ptr [ecx + 0x0000008c], -0x11\n\t"
        "%{disp8%} je         LAB__addr_0x00752156\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                edx, dword ptr [eax + eax * 0x2]\n\t"
        "shl                edx, 3\n\t"
        "sub.s              edx, eax\n\t"
        "lea                eax, dword ptr [edx + edx * 0x2]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax * 0x4 + 0x00db9f3c]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} je         LAB__addr_0x00752156\n\t"
        "test               byte ptr [ecx + 0x25], 0x04\n\t"
        "%{disp8%} jne        LAB__addr_0x00752156\n\t"
        "mov                eax, 0x00000001\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00752156:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_ret, trailing_asm("ret\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\npush esi\nmov.s esi, ecx\nmov eax, dword ptr [esi]\ncall dword ptr [eax + 0x48]\n{disp8} mov cx, word ptr [esi + 0x16]\ncmp cx, word ptr [eax + 0x0000072a]\n.byte 0x72, 0x26\n{disp8} mov si, word ptr [esi + 0x1a]\ncmp si, word ptr [eax + 0x0000072e]\n.byte 0x72, 0x19\ncmp cx, word ptr [eax + 0x00000736]\n{disp8} ja LAB__addr_0x007521ab\ncmp si, word ptr [eax + 0x0000073a]\n{disp8} ja LAB__addr_0x007521ab\nmov eax, 0x00000001\npop esi\nret\nLAB__addr_0x007521ab:\nxor.s eax, eax\npop esi\nret")))
struct Abode* __fastcall GetAbode__8VillagerFv(const struct Villager* this)
{
    return this->home;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall ToBeDeleted__8VillagerFi(struct Base* this, const void* edx, int param_1)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?DeleteDependancys@Villager@@QAEXXZ\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @ToBeDeleted__6LivingFi@12\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves))
uint32_t __fastcall CallState__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x10\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [ecx + 0x0000008c]\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "lea                eax, dword ptr [eax + eax * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "add                eax, 0x00d09198 /* _VillagerStateTable */\n\t"
        "mov.s              esi, eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} mov        edx, dword ptr [esi + 0x04]\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x08]\n\t"
        "%{disp8%} mov        esi, dword ptr [esi + 0x0c]\n\t"
        "add.s              ecx, edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], esi\n\t"
        "call               eax\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsPregnant__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        edx, dword ptr [ecx + 0x28]\n\t"
        "push               esi\n\t"
        "%{disp32%} mov       esi, dword ptr [edx + 0x000001f8]\n\t"
        "mov                eax, 0x00000001\n\t"
        "cmp.s              esi, eax\n\t"
        "pop                esi\n\t"
        "%{disp8%} jne        LAB__addr_0x0075222e\n\t"
        "cmp                word ptr [ecx + 0x000000f8], 0x00\n\t"
        "%{disp8%} jne        LAB__addr_0x00752230\n"
        "LAB__addr_0x0075222e:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x00752230:"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
uint32_t __fastcall WomanSpecial__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?IsPregnant@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075227d\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        ax, word ptr [esi + 0x24]\n\t"
        "not                ax\n\t"
        "shr                eax, 0xa\n\t"
        "test               al, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075227d\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetGameTurnsSinceLastChecked@Villager@@QAEIXZ\n\t"
        "sub                word ptr [esi + 0x000000f8], ax\n\t"
        "cmp                word ptr [esi + 0x000000f8], 0x00\n\t"
        "%{disp8%} jg         LAB__addr_0x0075227d\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?HousewifeStartsGivingBirth@Villager@@QAEIXZ\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0075227d:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsVillagerAvailable__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "test               byte ptr [esi + 0x25], 0x04\n\t"
        "%{disp8%} jne        LAB__addr_0x007522b1\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x18c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007522b1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetVillagerAvailableState@Villager@@QAE?AW4VILLAGER_STATES@@XZ\n\t"
        "and                eax, 0x01\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007522b1:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsAvailableToBeSummonedByCreature__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x978]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075230e\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075230e\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000e0]\n\t"
        "shr                eax, 9\n\t"
        "test               al, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0075230e\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x11c]\n\t"
        "%{disp32%} fcomp     dword ptr [edi + 0x0000035c]\n\t"
        "pop                edi\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x0075230e\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0075230e:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall CallExitStateFunction__8VillagerF15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       bl, byte ptr [esi + 0x0000008c]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x14], bl\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x10], al\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x14]\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                eax, dword ptr [eax + eax * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00d091b8]\n\t"
        "test               edx, edx\n\t"
        "mov                edi, 0x00000001\n\t"
        "mov.s              ebp, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00752370\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x1c]\n\t"
        "push               ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091bc]\n\t"
        "add.s              ecx, esi\n\t"
        "call               edx\n\t"
        "mov.s              edi, eax\n"
        "LAB__addr_0x00752370:\n\t"
        "cmp                bl, byte ptr [esp + 0x10]\n\t"
        "%{disp8%} je         LAB__addr_0x007523a0\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x10]\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                eax, dword ptr [eax + eax * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00d091b8]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} je         LAB__addr_0x007523a0\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x1c]\n\t"
        "push               ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091bc]\n\t"
        "add.s              ecx, esi\n\t"
        "call               edx\n\t"
        "mov.s              ebp, eax\n"
        "LAB__addr_0x007523a0:\n\t"
        "cmp                edi, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x007523b5\n\t"
        "cmp.s              ebp, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x007523b5\n\t"
        "mov.s              eax, edi\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007523b5:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x08"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall CallEntryStateFunction__Uc__8VillagerFUc(struct Living* this, const void* edx, enum VILLAGER_STATES state)
{
    uint32_t result;
    asm volatile (
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x08], al\n\t"
        "mov.s              eax, edi\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                eax, dword ptr [eax + eax * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00d091a8]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} je         LAB__addr_0x00752411\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "push               edi\n\t"
        "push               ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091ac]\n\t"
        "add.s              ecx, esi\n\t"
        "call               edx\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00752429\n"
        "LAB__addr_0x00752411:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x938]\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00752429:\n\t"
        "xor.s              ecx, ecx\n\t"
        "cmp                eax, 0x23\n\t"
        "sete               cl\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov.s              eax, ecx\n\t"
        "pop                ecx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0008)))
uint32_t __fastcall CallEntryStateFunction__UcUc__8VillagerFUcUc(struct Living* this, const void* edx, enum VILLAGER_STATES current, enum VILLAGER_STATES destination)
{
    uint32_t result;
    asm volatile (
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x08], al\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x10]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x90c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007524bc\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x14]\n\t"
        "mov.s              eax, edi\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                eax, dword ptr [eax + eax * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00d091a8]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} je         LAB__addr_0x00752494\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "push               edi\n\t"
        "push               ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091ac]\n\t"
        "add.s              ecx, esi\n\t"
        "call               edx\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x007524ac\n"
        "LAB__addr_0x00752494:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x938]\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x007524ac:\n\t"
        "cmp                eax, 0x23\n\t"
        "%{disp8%} jne        LAB__addr_0x007524bc\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x007524bc:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "pop                ecx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0008)))
bool32_t __fastcall IsStateEntryFunctionSameAs__8VillagerCFUlUl(const struct Villager* this, const void* edx, unsigned long param_1, unsigned long param_2)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "lea                eax, dword ptr [eax + eax * 0x8]\n\t"
        "lea                ecx, dword ptr [ecx + ecx * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00d091a8]\n\t"
        "shl                ecx, 4\n\t"
        "cmp                edx, dword ptr [ecx + 0x00d091a8]\n\t"
        "%{disp8%} jne        LAB__addr_0x00752528\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} je         LAB__addr_0x00752520\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00d091ac]\n\t"
        "cmp                edx, dword ptr [ecx + 0x00d091ac]\n\t"
        "%{disp8%} jne        LAB__addr_0x00752528\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00d091b0]\n\t"
        "cmp                edx, dword ptr [ecx + 0x00d091b0]\n\t"
        "%{disp8%} jne        LAB__addr_0x00752528\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00d091b4]\n\t"
        "cmp                eax, dword ptr [ecx + 0x00d091b4]\n\t"
        "%{disp8%} jne        LAB__addr_0x00752528\n"
        "LAB__addr_0x00752520:\n\t"
        "mov                eax, 0x00000001\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x00752528:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall IsStateExitFunctionSameAs__8VillagerCF15VILLAGER_STATES(const struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    bool32_t result;
    asm volatile (
        "mov                eax, dword ptr [ecx]\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x8]\n\t"
        "shl                ecx, 4\n\t"
        "add                ecx, 0x00d091b8\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "%{disp8%} mov        esi, dword ptr [ecx + 0x04]\n\t"
        "%{disp8%} mov        edi, dword ptr [ecx + 0x08]\n\t"
        "%{disp8%} mov        ebx, dword ptr [ecx + 0x0c]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "cmp                edx, dword ptr [eax + 0x00d091b8]\n\t"
        "%{disp8%} jne        LAB__addr_0x00752585\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} je         LAB__addr_0x007525a3\n\t"
        "cmp                esi, dword ptr [eax + 0x00d091bc]\n\t"
        "%{disp8%} jne        LAB__addr_0x00752585\n\t"
        "cmp                edi, dword ptr [eax + 0x00d091c0]\n\t"
        "%{disp8%} jne        LAB__addr_0x00752585\n\t"
        "cmp                ebx, dword ptr [eax + 0x00d091c4]\n\t"
        "%{disp8%} je         LAB__addr_0x007525a3\n"
        "LAB__addr_0x00752585:\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                edx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [edx * 0x4 + 0x00db9e84]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007525a3\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007525a3:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_ret))
bool __fastcall IsReactiveState__8VillagerFUl(struct Villager* this, const void* edx, unsigned long param_1)
{
    asm volatile (
        "%{disp8%} mov        ecx, dword ptr [esp + 0x04]\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                eax, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax * 0x4 + 0x00db9f30]\n\t"
        "xor.s              ecx, ecx\n\t"
        "test               edx, edx\n\t"
        "setne              cl\n\t"
        "mov.s              eax, ecx\n\t"
        "ret\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "mov.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} lea       eax, dword ptr [ecx * 0x4 + 0x00db9ea0]\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV, no_callee_saves, suppress_fp_imm, msvc6_regalloc))
bool32_t __fastcall IsHungry__8VillagerFv(struct Villager* this)
{
    const struct GVillagerInfo* info = *(const struct GVillagerInfo* volatile*)((char*)this + 0x28);
    float hunger = *(float volatile*)((char*)this + 0xe8);
    float threshold = *(float*)((char*)info + 0x2c0);
    bool32_t result = !(hunger > threshold);
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsWoman__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "cmp                dword ptr [eax + 0x000001f8], 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0075263e\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075263e\n\t"
        "mov                eax, 0x00000001\n\t"
        "ret\n"
        "LAB__addr_0x0075263e:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
struct GVillagerInfo* __cdecl Find__13GVillagerInfoF10TRIBE_TYPE15VILLAGER_NUMBER(enum TRIBE_TYPE type, int villager_number)
{
    struct GVillagerInfo* result;
    asm volatile (
        "%{disp8%} mov        edx, dword ptr [esp + 0x08]\n\t"
        "push               esi\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x08]\n\t"
        "mov                eax, OFFSET _VillagerInfos\n\t"
        "mov                ecx, 0x00da6de4\n"
        "LAB__addr_0x00752663:\n\t"
        "cmp                dword ptr [ecx + -0x08], esi\n\t"
        "%{disp8%} jne        LAB__addr_0x0075266c\n\t"
        "cmp                dword ptr [ecx], edx\n\t"
        "%{disp8%} je         LAB__addr_0x00752681\n"
        "LAB__addr_0x0075266c:\n\t"
        "add                ecx, 0x000003a4\n\t"
        "add                eax, 0x000003a4\n\t"
        "cmp                ecx, 0x00db9fb4\n\t"
        ".byte              0x72, 0xe4\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x00752681:\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x000c)))
bool32_t __fastcall MakeVillagesMeet__8VillagerFP8Villager15VILLAGER_STATESf(struct Villager* this, const void* edx, struct Villager* param_1, enum VILLAGER_STATES param_2, float param_3)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x18\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x28]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x24]\n\t"
        "push               ecx\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x6b8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007526db\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?MakeVillagerFaceObject@Villager@@QAEIPAVObject@@@Z\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?MakeVillagerFaceObject@Villager@@QAEIPAVObject@@@Z\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x28]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x18\n\t"
        "ret                0x000c\n"
        "LAB__addr_0x007526db:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x2c]\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ebx, dword ptr [edi + 0x14]\n\t"
        "push               ebx\n\t"
        "%{disp8%} lea        ebp, dword ptr [esi + 0x14]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x18]\n\t"
        "push               ebp\n\t"
        "push               edx\n\t"
        "call               ?GetMidPoint@GUtils@@SAXAAUMapCoords@@0M@Z\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x40]\n\t"
        "add                esp, 0x10\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupMoveToPos@Villager@@QAE_NABUMapCoords@@W4VILLAGER_STATES@@@Z\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x34]\n\t"
        "push               edx\n\t"
        "push               ebp\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x24]\n\t"
        "push               ebx\n\t"
        "push               eax\n\t"
        "call               ?GetMidPoint@GUtils@@SAXAAUMapCoords@@0M@Z\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x40]\n\t"
        "add                esp, 0x10\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x14]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], eax\n\t"
        "call               ?SetupMoveToPos@Villager@@QAE_NABUMapCoords@@W4VILLAGER_STATES@@@Z\n\t"
        "pop                ebp\n\t"
        "%{disp32%} mov       dword ptr [edi + 0x00000118], esi\n\t"
        "pop                ebx\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], edi\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x18"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall MakeVillagerFaceObject__8VillagerFP6Object(struct Villager* this, const void* edx, struct Object* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "push               ecx\n\t"
        "call               ?Get3DAngleFromXZ@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x10]\n\t"
        "push               edx\n\t"
        "call               ?ConvertAngle3DToGame@GUtils@@SAIM@Z\n\t"
        "add                esp, 0x0c\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetGameAngle__13MobileWallHugFUs@10\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
int __fastcall ExitReaction__8VillagerF15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    int result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               esi\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x70]\n\t"
        "call               _jmp_addr_0x0060a9f0\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "shl                ecx, 3\n\t"
        "sub.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax * 0x4 + 0x00db9f30]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x007527d5\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x998]\n"
        "LAB__addr_0x007527d5:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall ExitDance__8VillagerFUc(struct Villager* this, const void* edx, unsigned char param_1)
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
        "%{disp8%} jne        LAB__addr_0x00752810\n\t"
        "cmp                bl, 0x05\n\t"
        "%{disp8%} je         LAB__addr_0x00752810\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xb08]\n"
        "LAB__addr_0x00752810:\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall IsAvailableForWorshipSite__8VillagerFi(struct Villager* this, const void* edx, int param_1)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?IsVillagerAvailable@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00752858\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       ax, word ptr [esi + 0x000000e0]\n\t"
        "shr                eax, 9\n\t"
        "test               al, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00752844\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00752858\n"
        "LAB__addr_0x00752844:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsAtOrOnTheWayToWorshipSite@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00752858\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00752858:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsAtOrOnTheWayToWorshipSite__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "cmp                eax, 0x000000c9\n\t"
        "%{disp8%} je         LAB__addr_0x00752885\n\t"
        "cmp                eax, 0x000000ca\n\t"
        "%{disp8%} je         LAB__addr_0x00752885\n\t"
        "cmp                eax, 0x000000fb\n\t"
        "%{disp8%} jne        LAB__addr_0x0075288d\n"
        "LAB__addr_0x00752885:\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008e]\n"
        "LAB__addr_0x0075288d:\n\t"
        "test               byte ptr [esi + 0x000000e0], 0x02\n\t"
        "pop                esi\n\t"
        "%{disp8%} jne        LAB__addr_0x007528a4\n\t"
        "cmp                eax, 0x3b\n\t"
        "%{disp8%} je         LAB__addr_0x007528a4\n\t"
        "cmp                eax, 0x2e\n\t"
        "%{disp8%} je         LAB__addr_0x007528a4\n\t"
        "xor.s              eax, eax\n\t"
        "ret\n"
        "LAB__addr_0x007528a4:\n\t"
        "mov                eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

uint32_t __fastcall DebugShowTime__8VillagerFUlUcUc(struct Living* this, const void* edx, uint32_t param_1, uint8_t param_2, uint8_t param_3)
{
    uint32_t result;
    asm volatile (
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0xb04]"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall SetAge__8VillagerFUl(struct Living* this, const void* edx, uint32_t age)
{
    asm volatile (
        "%{disp32%} mov       al, byte ptr [_villager_byte_0x00da6bcc]\n\t"
        "test               al, 0x01\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x007528f6\n\t"
        "%{disp32%} mov       ecx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "mov.s              bl, al\n\t"
        "or                 bl, 1\n\t"
        "%{disp32%} mov       byte ptr [_villager_byte_0x00da6bcc], bl\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "mov                eax, 0x000001ff\n\t"
        "cmp.s              edx, eax\n\t"
        "%{disp8%} jg         LAB__addr_0x007528ed\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x007528ed:\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + eax * 0x4 + 0x04]\n\t"
        "%{disp32%} mov       dword ptr [_villager_uint_0x00da6bc8], eax\n"
        "LAB__addr_0x007528f6:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       edi, dword ptr [ecx + 0x00000138]\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x14]\n\t"
        "cmp.s              ebx, edi\n\t"
        ".byte              0x72, 0x12\n\t"
        "cmp                ebx, 0x12\n\t"
        "%{disp8%} jae        LAB__addr_0x00752911\n\t"
        "mov                ebx, 0x00000012\n"
        "LAB__addr_0x00752911:\n\t"
        "cmp.s              ebx, edi\n\t"
        "%{disp32%} jae       LAB__addr_0x007529b6\n"
        "LAB__addr_0x00752919:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "or                 byte ptr [esi + 0xe0], 8\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8d0]\n\t"
        "cmp.s              eax, edi\n\t"
        "%{disp32%} jb        LAB__addr_0x00752a62\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x40]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00752a62\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x4a0]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00752963\n"
        "LAB__addr_0x0075294b:\n\t"
        "%{disp32%} mov       edx, dword ptr [_villager_uint_0x00da6bc8]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "push               edx\n\t"
        "push               edx\n\t"
        "call               dword ptr [eax + 0xf4]\n\t"
        "%{disp32%} jmp       LAB__addr_0x00752a62\n"
        "LAB__addr_0x00752963:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x0000020c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       edx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "%{disp8%} jl         LAB__addr_0x0075297a\n\t"
        "cmp                eax, dword ptr [edx]\n\t"
        "%{disp8%} jl         LAB__addr_0x0075297c\n"
        "LAB__addr_0x0075297a:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x0075297c:\n\t"
        "%{disp8%} mov        eax, dword ptr [edx + eax * 0x4 + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00000208]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jl         LAB__addr_0x00752992\n\t"
        "cmp                eax, dword ptr [edx]\n\t"
        "%{disp8%} jl         LAB__addr_0x00752994\n"
        "LAB__addr_0x00752992:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x00752994:\n\t"
        "%{disp8%} mov        edi, dword ptr [edx + eax * 0x4 + 0x04]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00000204]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jl         LAB__addr_0x007529a6\n\t"
        "cmp                eax, dword ptr [edx]\n\t"
        "%{disp8%} jl         LAB__addr_0x007529a8\n"
        "LAB__addr_0x007529a6:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x007529a8:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                ebp, dword ptr [ecx]\n\t"
        "push               dword ptr [esp + 0x14]\n\t"
        "%{disp32%} jmp       LAB__addr_0x00752a57\n"
        "LAB__addr_0x007529b6:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        ".byte              0x66, 0x81, 0xa6, 0xe0, 0x0, 0x0, 0x0, 0xf7, 0xff\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8d0]\n\t"
        "cmp.s              eax, edi\n\t"
        "%{disp32%} jae       LAB__addr_0x00752a62\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x40]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00752a62\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x4a0]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x0075294b\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x2\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x60c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       ecx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "%{disp8%} jl         LAB__addr_0x00752a08\n\t"
        "cmp                eax, dword ptr [ecx]\n\t"
        "%{disp8%} jl         LAB__addr_0x00752a0a\n"
        "LAB__addr_0x00752a08:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x00752a0a:\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + eax * 0x4 + 0x04]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "call               dword ptr [edx + 0x60c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       ecx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "%{disp8%} jl         LAB__addr_0x00752a2c\n\t"
        "cmp                eax, dword ptr [ecx]\n\t"
        "%{disp8%} jl         LAB__addr_0x00752a2e\n"
        "LAB__addr_0x00752a2c:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x00752a2e:\n\t"
        "%{disp8%} mov        edi, dword ptr [ecx + eax * 0x4 + 0x04]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x60c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       edx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "%{disp8%} jl         LAB__addr_0x00752a4c\n\t"
        "cmp                eax, dword ptr [edx]\n\t"
        "%{disp8%} jl         LAB__addr_0x00752a4e\n"
        "LAB__addr_0x00752a4c:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x00752a4e:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                ebp, dword ptr [ecx]\n\t"
        "push               dword ptr [esp + 0x14]\n"
        "LAB__addr_0x00752a57:\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + eax * 0x4 + 0x04]\n\t"
        "push               edi\n\t"
        "call               dword ptr [ebp + 0xf4]\n"
        "LAB__addr_0x00752a62:\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?InitialiseScale@Villager@@QAEXK@Z\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetScaleForAge@Villager@@QAEXK@Z\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetAge__6LivingFUl@12\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall SetScaleForAge__8VillagerFUl(struct Villager* this, const void* edx, unsigned long param_1)
{
    asm volatile (
        "push               ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x08]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "cmp                ebx, dword ptr [edi + 0x00000138]\n\t"
        "%{disp8%} jae        LAB__addr_0x00752af5\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x120]\n\t"
        "%{disp32%} fsubr     dword ptr [edi + ebx * 0x4 + 0x000002ec]\n\t"
        "mov                edi, dword ptr [esi]\n\t"
        "push               0x0000092f\n\t"
        "%{disp32%} fmul      dword ptr [__real@3f400000]\n\t"
        "push               0x00c235dc\n\t"
        "push               ecx\n\t"
        "fstp               dword ptr [esp]\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x1c]\n\t"
        "add                esp, 0x0c\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x120]\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "fstp               dword ptr [esp]\n\t"
        "call               dword ptr [edi + 0x124]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00752af5:\n\t"
        "push               0x00000933\n\t"
        "push               0x00c235dc\n\t"
        "push               0x3dcccccd\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp32%} fsubr     dword ptr [rdata_bytes + 0x33f4]\n\t"
        "add                esp, 0x0c\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float1p0]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "call               dword ptr [eax + 0x120]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x10]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00752b56\n\t"
        "push               0x00000933\n\t"
        "push               0x00c235dc\n\t"
        "push               0x3dcccccd\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fsubr     dword ptr [rdata_bytes + 0x33f4]\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float1p0]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00752b60\n"
        "LAB__addr_0x00752b56:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x120]\n"
        "LAB__addr_0x00752b60:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x124]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall SetStateWhenTappedOnAbode__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00752bc1\n\t"
        "test               byte ptr [esi + 0x000000e0], 0x04\n\t"
        "%{disp8%} je         LAB__addr_0x00752bc1\n\t"
        "push               0x0\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?FindPosOutsideAbode@Villager@@QAEXPAVAbode@@@Z\n\t"
        "push               0x000000a3\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x08]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupAfterTapOnAbode@Villager@@QAEXAAUMapCoords@@W4VILLAGER_STATES@@@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x00752bc1:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0008)))
uint32_t __fastcall ValidToApplyThisToObject__8VillagerFP16GInterfaceStatusP6Object(struct Object* this, const void* edx, struct GInterfaceStatus* param_1, struct Object* param_2)
{
    uint32_t result;
    asm volatile (
        "push               esi\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x0c]\n\t"
        "push               edi\n\t"
        "push               0x0\n\t"
        "push               0x009c8ee8\n\t"
        "push               0x009c7f50\n\t"
        "push               0x0\n\t"
        "push               esi\n\t"
        "mov.s              edi, ecx\n\t"
        "call               ___RTDynamicCast\n\t"
        "add                esp, 0x14\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00752bfd\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x00752bfd:\n\t"
        "push               0x0\n\t"
        "push               0x00be0360\n\t"
        "push               0x009c7f50\n\t"
        "push               0x0\n\t"
        "push               esi\n\t"
        "call               ___RTDynamicCast\n\t"
        "add                esp, 0x14\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00752c2f\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x0c]\n\t"
        "push               edi\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x005fc4b0\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00752c2f\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x00752c2f:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x000c)))
uint32_t __fastcall ApplyThisToObject__8VillagerFP16GInterfaceStatusP6ObjectP23GestureSystemPacketData(struct Object* this, const void* edx, struct GInterfaceStatus* param_1, struct Object* param_2, struct GestureSystemPacketData* param_3)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x00000198\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp32%} mov       edi, dword ptr [esp + 0x000001b0]\n\t"
        "push               0x0\n\t"
        "push               0x009c8ee8\n\t"
        "push               0x009c7f50\n\t"
        "push               0x0\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ___RTDynamicCast\n\t"
        "mov.s              ebp, eax\n\t"
        "add                esp, 0x14\n\t"
        "test               ebp, ebp\n\t"
        "%{disp32%} je        LAB__addr_0x00752fc2\n\t"
        "%{disp32%} mov       ecx, dword ptr [ebp + 0x00000100]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x890]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00752fb0\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp8%} mov        cx, word ptr [esi + 0x24]\n\t"
        "not                cx\n\t"
        "shr                ecx, 0xe\n\t"
        "test               cl, 0x01\n\t"
        "%{disp32%} je        LAB__addr_0x00752fb0\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x5c0]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "%{disp32%} mov       edi, dword ptr [esp + 0x000001ac]\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "%{disp32%} mov       ebx, dword ptr [ebp + 0x00000100]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00752cdd\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x10]\n\t"
        "%{disp32%} fmul      qword ptr [__real@3ff4000000000000]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n"
        "LAB__addr_0x00752cdd:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x10]\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp32%} fadd      dword ptr [ebx + 0x000000f0]\n\t"
        "%{disp32%} fstp      dword ptr [ebx + 0x000000f0]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x10]\n\t"
        "%{disp32%} fadd      dword ptr [ebx + 0x000000f4]\n\t"
        "%{disp32%} fstp      dword ptr [ebx + 0x000000f4]\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00752d15\n\t"
        "push               0x0\n\t"
        "push               esi\n\t"
        "push               0x28\n\t"
        "push               edi\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x004ea900\n"
        "LAB__addr_0x00752d15:\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp8%} je         LAB__addr_0x00752d2c\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n"
        "LAB__addr_0x00752d2c:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x11c]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x1c]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               ecx\n\t"
        "push               0x7\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?VillagerDead@Villager@@QAEXW4DEATH_REASON@@PAVGPlayer@@MH@Z\n\t"
        "%{disp8%} lea        edx, dword ptr [ebp + 0x14]\n\t"
        "mov                eax, dword ptr [edx]\n\t"
        "%{disp8%} mov        ecx, dword ptr [edx + 0x04]\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], eax\n\t"
        "%{disp8%} mov        eax, dword ptr [ebp + 0x00]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], ecx\n\t"
        "mov.s              ecx, ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x2c], edx\n\t"
        "call               dword ptr [eax + 0x42c]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x2c]\n\t"
        "push               0x0\n\t"
        "fadd               st, st(1)\n\t"
        "push               0x3f800000\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x34]\n\t"
        "push               0x1b\n\t"
        "push               ecx\n\t"
        "fstp               st(0)\n\t"
        "call               _jmp_addr_0x0063e540\n\t"
        "mov.s              ebp, eax\n\t"
        "add                esp, 0x10\n\t"
        "test               ebp, ebp\n\t"
        "%{disp8%} je         LAB__addr_0x00752dac\n\t"
        "%{disp8%} mov        edx, dword ptr [ebp + 0x00]\n\t"
        "mov                eax, dword ptr [ebx]\n\t"
        "mov.s              ecx, ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], edx\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x14]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               dword ptr [edx + 0x20]\n"
        "LAB__addr_0x00752dac:\n\t"
        "test               edi, edi\n\t"
        "%{disp32%} je        LAB__addr_0x00752eb5\n\t"
        "%{disp32%} mov       ecx, dword ptr [edi + 0x000000cc]\n\t"
        "%{disp32%} mov       eax, dword ptr [edi + 0x000000c8]\n\t"
        "%{disp32%} mov       edx, dword ptr [edi + 0x000000d0]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x40]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], edx\n\t"
        "call               dword ptr [rdata_bytes + 0x75c]\n\t"
        "%{disp32%} mov       ecx, dword ptr [_global]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x000003ac]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x44], eax\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x1c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x74], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x70], edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x20]\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x40]\n\t"
        "mov                ebx, 0x00000001\n\t"
        "push               eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x68], 0x000000b3\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x64], esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x4c], ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x7c], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x50], 0x00000000\n\t"
        "call               @PlaySoundEffect__6GAudioFP20LH_SamplePlayOptions@12\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00752e65\n\t"
        "%{disp32%} mov       ecx, dword ptr [_global]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x000003bc]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x40]\n\t"
        "push               edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x48], eax\n\t"
        "call               @PlaySoundEffect__6GAudioFP20LH_SamplePlayOptions@12\n\t"
        "push               0xa\n\t"
        "push               0xd\n\t"
        "call               _jmp_addr_0x0071ed40\n\t"
        "add                esp, 0x08\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x64], eax\n\t"
        "%{disp8%} jmp        LAB__addr_0x00752eab\n"
        "LAB__addr_0x00752e65:\n\t"
        "%{disp32%} mov       eax, dword ptr [_global]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x000003b0]\n\t"
        "%{disp8%} mov        edx, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x44], ecx\n\t"
        "cmp                dword ptr [edx + 0x000001f8], ebx\n\t"
        "%{disp8%} jne        LAB__addr_0x00752e88\n\t"
        "push               0x6\n\t"
        "push               0x00000218\n\t"
        "%{disp8%} jmp        LAB__addr_0x00752e8f\n"
        "LAB__addr_0x00752e88:\n\t"
        "push               0x8\n\t"
        "push               0x000000dd\n"
        "LAB__addr_0x00752e8f:\n\t"
        "call               _jmp_addr_0x0071ed40\n\t"
        "%{disp32%} mov       ecx, dword ptr [_global]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x6c], eax\n\t"
        "add                esp, 0x08\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x40]\n\t"
        "push               eax\n\t"
        "call               @PlaySoundEffect__6GAudioFP20LH_SamplePlayOptions@12\n"
        "LAB__addr_0x00752eab:\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x40]\n\t"
        "call               dword ptr [rdata_bytes + 0x758]\n"
        "LAB__addr_0x00752eb5:\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "call               _jmp_addr_0x00555880\n\t"
        "cmp.s              edi, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x00752f95\n\t"
        "push               0x000009a6\n\t"
        "push               0x00c235dc\n\t"
        "push               0x000000a0\n\t"
        "call               ___nw__FUl\n\t"
        "xor.s              ebx, ebx\n\t"
        "add                esp, 0x0c\n\t"
        "cmp.s              eax, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x00752f01\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x14], ebx\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x18], ebx\n\t"
        "mov                dword ptr [eax], 0x008c589c\n\t"
        "%{disp32%} mov       ecx, dword ptr [_DAT_00ed92e8]\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x04], ecx\n\t"
        "%{disp32%} mov       dword ptr [_DAT_00ed92e8], eax\n\t"
        "mov.s              ebx, eax\n"
        "LAB__addr_0x00752f01:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x10]\n\t"
        "sub                esp, 0x08\n\t"
        "fstp               qword ptr [esp]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x38]\n\t"
        "push               0x00bf3aa4\n\t"
        "push               edx\n\t"
        "call               _sprintf\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "add                esp, 0x10\n\t"
        "call               ?MyInterface@GGame@@QAEPAVGInterface@@XZ\n\t"
        "mov.s              edi, eax\n\t"
        "%{disp32%} mov       eax, dword ptr [edi + 0x000003c0]\n\t"
        "add                edi, 0x000003b8\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n\t"
        "call               ?GetAltitude@LH3DIsland@@SAMABULH3DMapCoords@@@Z\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x14]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x10]\n\t"
        "mov                al, -0x01\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x1c]\n\t"
        "push               ecx\n\t"
        "fild               dword ptr [edi]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x34]\n\t"
        "push               edx\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x18], 0x00\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float_coord_to_point]\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x19], 0x00\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x1a], al\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x1b], al\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x20]\n\t"
        "%{disp8%} fild       dword ptr [edi + 0x04]\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float_coord_to_point]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x28]\n\t"
        "call               _CHAR2WCHAR__FPc\n\t"
        "add                esp, 0x04\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x20]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               _jmp_addr_0x00833a00\n"
        "LAB__addr_0x00752f95:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xc]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000003\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x00000198\n\t"
        "ret                0x000c\n"
        "LAB__addr_0x00752fb0:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000017\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x00000198\n\t"
        "ret                0x000c\n"
        "LAB__addr_0x00752fc2:\n\t"
        "push               0x0\n\t"
        "push               0x00be0360\n\t"
        "push               0x009c7f50\n\t"
        "push               0x0\n\t"
        "push               edi\n\t"
        "call               ___RTDynamicCast\n\t"
        "mov.s              edi, eax\n\t"
        "add                esp, 0x14\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x0075300a\n\t"
        "%{disp32%} mov       ebx, dword ptr [esp + 0x000001ac]\n\t"
        "push               esi\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x005fc4b0\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0075300a\n\t"
        "push               esi\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x005fc4f0\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x00000198\n\t"
        "ret                0x000c\n"
        "LAB__addr_0x0075300a:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x00000198"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

uint32_t __fastcall GetScriptObjectType__8VillagerFv(struct GameThingWithPos* this)
{
    uint32_t result;
    asm volatile (
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x458]\n\t"
        "neg                eax\n\t"
        "sbb.s              eax, eax\n\t"
        "neg                eax\n\t"
        "add                eax, 0x04"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall IsTouching_2__8VillagerCFP9MapCoords(const struct Object* this, const void* edx, struct MapCoords* param_1)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x13c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x130]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x08]\n\t"
        "pop                esi\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x00753074\n\t"
        "mov                eax, 0x00000001\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00753074:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall InterfaceSetInMagicHand__8VillagerFP16GInterfaceStatus(struct Object* this, const void* edx, struct GInterfaceStatus* param_1)
{
    uint32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "or                 byte ptr [esi + 0xe0], 0x20\n\t"
        "cmp                byte ptr [esi + 0x0000008d], 0x7b\n\t"
        "push               edi\n\t"
        "%{disp8%} jne        LAB__addr_0x007530c0\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000118]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007530c0\n\t"
        "%{disp32%} mov       dword ptr [eax + 0x00000118], 0x00000000\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000118]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x8c8]\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], 0x00000000\n"
        "LAB__addr_0x007530c0:\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               ebp\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "mov.s              ebp, eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "cmp.s              eax, ebp\n\t"
        "pop                ebp\n\t"
        "%{disp8%} jne        LAB__addr_0x007530fa\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsSexuallyActive@Villager@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007530fa\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "push               eax\n\t"
        "push               0x20\n\t"
        "push               esi\n\t"
        "call               ?CreateReaction@Reaction@@SAPAV1@PAVGameThingWithPos@@EPAVGPlayer@@H@Z\n\t"
        "add                esp, 0x10\n"
        "LAB__addr_0x007530fa:\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?InterfaceSetInMagicHand@Living@@UAEIPAVGInterfaceStatus@@@Z\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008)))
void __fastcall SetSpeedInMetres__8VillagerFfi(struct GameThingWithPos* this, const void* edx, float param_1, int param_2)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "call               _jmp_addr_0x0074dce0\n\t"
        "add                esp, 0x04\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetSpeed@Villager@@QAEXJH@Z\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves))
uint32_t __fastcall FUN_00753140__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "push               ecx\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x00], al\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x00]\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                eax, dword ptr [eax + eax * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091b8]\n\t"
        "cmp                ecx, 0x007597b0\n\t"
        "%{disp8%} jne        LAB__addr_0x00753190\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075318c\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091bc]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x00753190\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091c0]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x00753190\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00d091c4]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x00753190\n"
        "LAB__addr_0x0075318c:\n\t"
        "mov                al, 0x01\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x00753190:\n\t"
        "xor.s              al, al\n\t"
        "pop                ecx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsVagrant__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00205bfc]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007531bd\n"
        "LAB__addr_0x007531af:\n\t"
        "cmp.s              eax, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x007531bd\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x000000e4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007531af\n"
        "LAB__addr_0x007531bd:\n\t"
        "xor.s              ecx, ecx\n\t"
        "test               eax, eax\n\t"
        "setne              cl\n\t"
        "mov.s              eax, ecx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
void __fastcall ReleaseFromScript__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "push               ecx\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x14]\n\t"
        "test               ch, -0x80\n\t"
        "%{disp32%} jne       LAB__addr_0x00753335\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000b8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00753209\n\t"
        "cmp                dword ptr [eax + 0x30], esi\n\t"
        "%{disp8%} jne        LAB__addr_0x007531fb\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x30], 0x00000000\n"
        "LAB__addr_0x007531fb:\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000b8]\n\t"
        "push               0x0\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x0052fb50\n"
        "LAB__addr_0x00753209:\n\t"
        "test               byte ptr [esi + 0x24], 0x44\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} jne       LAB__addr_0x007532e6\n\t"
        "call               dword ptr [edx + 0x11c]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "mov.s              ecx, esi\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} je         LAB__addr_0x00753283\n\t"
        "call               dword ptr [eax + 0x6c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075323e\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00753240\n"
        "LAB__addr_0x0075323e:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x00753240:\n\t"
        "push               0x1\n\t"
        "push               0x0\n\t"
        "push               eax\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?VillagerDead@Villager@@QAEXW4DEATH_REASON@@PAVGPlayer@@MH@Z\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008c]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        byte ptr [esp + 0x04], al\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "and                eax, 0x000000ff\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x970]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x00753335\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0xf\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x00753283:\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00753297\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8c8]\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x00753297:\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp32%} lea       ecx, dword ptr [eax + 0x00205bfc]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007532bc\n"
        "LAB__addr_0x007532a8:\n\t"
        "cmp.s              eax, esi\n\t"
        "%{disp8%} je         LAB__addr_0x007532b8\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x000000e4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007532a8\n\t"
        "%{disp8%} jmp        LAB__addr_0x007532bc\n"
        "LAB__addr_0x007532b8:\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007532cd\n"
        "LAB__addr_0x007532bc:\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000e4], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + 0x04]\n\t"
        "inc                eax\n\t"
        "mov                dword ptr [ecx], esi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x04], eax\n"
        "LAB__addr_0x007532cd:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x00000082\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?VagrantStart@Villager@@QAEIXZ\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x007532e6:\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00753335\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp32%} lea       ecx, dword ptr [eax + 0x00205bfc]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00753324\n"
        "LAB__addr_0x007532fe:\n\t"
        "cmp.s              eax, esi\n\t"
        "%{disp8%} je         LAB__addr_0x00753320\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x000000e4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007532fe\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000e4], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + 0x04]\n\t"
        "inc                eax\n\t"
        "mov                dword ptr [ecx], esi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x04], eax\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x00753320:\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00753335\n"
        "LAB__addr_0x00753324:\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000e4], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + 0x04]\n\t"
        "inc                eax\n\t"
        "mov                dword ptr [ecx], esi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x04], eax\n"
        "LAB__addr_0x00753335:\n\t"
        "pop                esi\n\t"
        "pop                ecx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves))
void __fastcall TestSpecial__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075336f\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?RemoveVillager@Town@@QAEXPAVVillager@@@Z\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetTown@Villager@@QAEXPAVTown@@@Z\n\t"
        "and                word ptr [esi + 0x000000b4], -0x0401\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0075336f:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ReleaseFromScript@Villager@@QAEXXZ\n\t"
        "and                word ptr [esi + 0x000000b4], -0x0401\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x000c)))
uint32_t __fastcall GetResourceFrom__8VillagerFP6Object13RESOURCE_TYPEs(struct Villager* this, const void* edx, struct Object* param_1, enum RESOURCE_TYPE param_2, short param_3)
{
    uint32_t result;
    asm volatile (
        "push               ebx\n\t"
        "push               ebp\n\t"
        "%{disp8%} mov        ebp, dword ptr [esp + 0x10]\n\t"
        "push               esi\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x10]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "movsx              ecx, word ptr [esp + 0x1c]\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               ecx\n\t"
        "push               ebp\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xa0]\n\t"
        "mov.s              ebx, eax\n\t"
        "test               bx, bx\n\t"
        "%{disp8%} je         LAB__addr_0x00753402\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x820]\n\t"
        "push               eax\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?PickupResource@Villager@@QAEXW4RESOURCE_TYPE@@FE@Z\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x4a8]\n\t"
        "test               al, al\n\t"
        "%{disp8%} je         LAB__addr_0x007533e8\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x878]\n"
        "LAB__addr_0x007533e8:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x4a4]\n\t"
        "test               al, al\n\t"
        "%{disp8%} je         LAB__addr_0x00753402\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x69c]\n"
        "LAB__addr_0x00753402:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov.s              ax, bx\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall SetFoodSpeedup__8VillagerFb(struct Living* this, const void* edx, bool param_1)
{
    asm volatile (
        "%{disp8%} mov        al, byte ptr [esp + 0x04]\n\t"
        "test               al, al\n\t"
        "%{disp8%} je         LAB__addr_0x00753422\n\t"
        "%{disp32%} mov       byte ptr [ecx + 0x000000f0], -0x01\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00753422:\n\t"
        "%{disp32%} mov       byte ptr [ecx + 0x000000f0], 0x00"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV))
void __fastcall ProcessFoodSpeedup__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x87c]\n\t"
        "test               al, al\n\t"
        "%{disp8%} je         LAB__addr_0x0075345e\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00205a40]\n\t"
        "xor.s              edx, edx\n\t"
        "mov                ecx, 0x0000000a\n\t"
        "div                ecx\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} jne        LAB__addr_0x0075345e\n\t"
        "dec                byte ptr [esi + 0x000000f0]\n\t"
        "LAB__addr_0x0075345e:\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004), no_tail_call))
void __fastcall IncreaseLife__8VillagerFf(struct Object* this, const void* edx, float param_1)
{
    extern void __attribute__((thiscall)) IncreaseLife_Object_fwd(struct Object*, float) asm("?IncreaseLife@Object@@UAEXM@Z");
    IncreaseLife_Object_fwd(this, param_1);
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008)))
void __fastcall FindPosOutsideAbode__8VillagerFP5Abode(struct Villager* this, const void* edx, struct Abode* param_1)
{
    asm volatile (
        "sub                esp, 0x28\n\t"
        "push               esi\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x34]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x00753483\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              esi, eax\n"
        "LAB__addr_0x00753483:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x14]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x104]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        edx, dword ptr [esi + 0x14]\n\t"
        "push               edx\n\t"
        "call               ?Get3DAngleFromXZ@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x3c]\n\t"
        "push               0x00000a96\n\t"
        "push               0x00c235dc\n\t"
        "push               0x3fc00000\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fadd      dword ptr [__real@3fc00000]\n\t"
        "push               0x00000a97\n\t"
        "push               0x00c235dc\n\t"
        "push               0x3f490fdb\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x24]\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x24]\n\t"
        "%{disp32%} fsubr     dword ptr [rdata_bytes + 0x1dca0]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x38]\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x58]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x58]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x58]\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "add                esp, 0x2c\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x28]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x104]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               @__pl__9MapCoordsCFRC9MapCoords@16\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x30]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x08]\n\t"
        "mov.s              ecx, eax\n\t"
        "mov                dword ptr [ecx], edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x04], edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x08], edx\n\t"
        "pop                esi\n\t"
        "add                esp, 0x28"
        ::: "eax", "ecx", "edx", "memory"
    );
}

struct Abode* __fastcall FUN_00753540__8VillagerFv(const struct Villager* this)
{
    void* dummy;
    struct Abode* result;
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [_global + 0x14c]\n\t"
        "test               eax, eax\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00753558\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "LAB__addr_0x00753558:\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008)))
void __fastcall AdjustTownModifier__8VillagerF15VILLAGER_STATESi(struct Villager* this, const void* edx, enum VILLAGER_STATES state, int param_2)
{
    asm volatile (
        "mov                eax, dword ptr [ecx]\n\t"
        "sub                esp, 0x00000408\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              edi, eax\n\t"
        "test               edi, edi\n\t"
        "%{disp32%} je        LAB__addr_0x0075367c\n\t"
        "%{disp32%} mov       ecx, dword ptr [esp + 0x00000414]\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                eax, dword ptr [eax + eax * 0x2]\n\t"
        "shl                eax, 2\n\t"
        "%{disp32%} mov       esi, dword ptr [eax + 0x00db9e7c]\n\t"
        "cmp                esi, -0x01\n\t"
        "%{disp32%} je        LAB__addr_0x0075367c\n\t"
        "%{disp32%} fld       dword ptr [eax + 0x00db9e80]\n\t"
        "%{disp32%} mov       eax, dword ptr [esp + 0x00000418]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007535b4\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n\t"
        "%{disp8%} jmp        LAB__addr_0x007535ba\n"
        "LAB__addr_0x007535b4:\n\t"
        "%{disp32%} fld       dword ptr [rdata_bytes + 0x2678]\n"
        "LAB__addr_0x007535ba:\n\t"
        "fld                st(0)\n\t"
        "fmul               st, st(2)\n\t"
        "%{disp32%} fadd      dword ptr [edi + esi * 0x4 + 0x00000510]\n\t"
        "%{disp32%} fstp      dword ptr [edi + esi * 0x4 + 0x00000510]\n\t"
        "%{disp32%} fadd      dword ptr [edi + esi * 0x4 + 0x00000554]\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x08]\n\t"
        "fstp               st(1)\n\t"
        "%{disp32%} fstp      dword ptr [edi + esi * 0x4 + 0x00000554]\n\t"
        "%{disp32%} mov       eax, dword ptr [_global + 0x154]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0075367c\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "call               _jmp_addr_0x0048f820\n\t"
        "%{disp32%} mov       edx, dword ptr [edi + esi * 0x4 + 0x00000510]\n\t"
        "add                esp, 0x04\n\t"
        "push               eax\n\t"
        "push               edx\n\t"
        "call               _jmp_addr_0x0048f820\n\t"
        "add                esp, 0x04\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x14]\n\t"
        "push               0x00c2367c\n\t"
        "push               eax\n\t"
        "call               dword ptr [__imp___0LHSPrintf__QAA_PADZZ@4]\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "%{disp32%} mov       edx, dword ptr [ecx + 0x002502d8]\n\t"
        "add                esp, 0x10\n\t"
        "push               eax\n\t"
        "push               edx\n\t"
        "call               _fprintf\n\t"
        "%{disp32%} mov       eax, dword ptr [_global + 0x154]\n\t"
        "add                esp, 0x08\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075367c\n\t"
        "call               dword ptr [rdata_bytes + 0x354]\n\t"
        "push               eax\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x002502d8]\n\t"
        "push               ecx\n\t"
        "call               _fprintf\n\t"
        "%{disp32%} mov       eax, dword ptr [_global + 0x154]\n\t"
        "add                esp, 0x08\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075367c\n\t"
        "%{disp32%} mov       edx, dword ptr [_game]\n\t"
        "%{disp32%} mov       eax, dword ptr [edx + 0x002502d8]\n\t"
        "push               0x009cf590\n\t"
        "push               eax\n\t"
        "call               _fprintf\n\t"
        "add                esp, 0x08\n"
        "LAB__addr_0x0075367c:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x00000408"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0008)))
void __fastcall SetState__8VillagerFUlUc(struct Living* this, const void* edx, enum LIVING_ACTION_INDEX index, enum VILLAGER_STATES state)
{
    asm volatile (
        "push               ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x08]\n\t"
        "cmp                ebx, 0x02\n\t"
        "push               ebp\n\t"
        "%{disp8%} mov        ebp, dword ptr [esp + 0x10]\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x007536bf\n\t"
        "mov.s              eax, ebp\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "shl                ecx, 3\n\t"
        "sub.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax * 0x4 + 0x00db9e88]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x00753734\n"
        "LAB__addr_0x007536bf:\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cl, byte ptr [ebx + edi * 0x1 + 0x0000008c]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ebp\n\t"
        "and                esi, 0x000000ff\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                edx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [edx * 0x4 + 0x00db9e84]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007536f5\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x007536f5\n\t"
        "push               0x0\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?AdjustTownModifier@Villager@@QAEXW4VILLAGER_STATES@@H@Z\n"
        "LAB__addr_0x007536f5:\n\t"
        "lea                eax, dword ptr [esi + esi * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, esi\n\t"
        "lea                eax, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax * 0x4 + 0x00db9e84]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00753719\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x00753719\n\t"
        "push               0x1\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?AdjustTownModifier@Villager@@QAEXW4VILLAGER_STATES@@H@Z\n"
        "LAB__addr_0x00753719:\n\t"
        "test               ebx, ebx\n\t"
        "pop                esi\n\t"
        "%{disp8%} jne        LAB__addr_0x0075372b\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               ebx\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x938]\n"
        "LAB__addr_0x0075372b:\n\t"
        "push               ebp\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               @SetState__6LivingFUlUc@16\n"
        "LAB__addr_0x00753734:\n\t"
        "pop                edi\n\t"
        "pop                ebp\n\t"
        "pop                ebx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

void __fastcall SetStateSpeed__8VillagerFv(struct Living* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "mov.s              ecx, esi\n\t"
        "push               eax\n\t"
        "call               ?SetStateSpeed@Villager@@QAEXE@Z\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall SetStateSpeed__8VillagerFUc(struct Villager* this, const void* edx, unsigned char param_1)
{
    asm volatile (
        "sub                esp, 0x10\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "test               byte ptr [esi + 0x25], 0x04\n\t"
        "%{disp32%} jne       LAB__addr_0x00753b48\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x978]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x00753b48\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              edi, eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "mov.s              ecx, eax\n\t"
        "xor.s              ebp, ebp\n\t"
        "cmp.s              ecx, ebp\n\t"
        "%{disp8%} je         LAB__addr_0x007537be\n\t"
        "%{disp32%} fld       dword ptr [ecx + 0x000000c8]\n\t"
        "%{disp32%} fcomp     dword ptr [__real@3dcccccd]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x007537b6\n\t"
        "%{disp32%} fld       dword ptr [ecx + 0x000000c8]\n\t"
        "%{disp8%} jmp        LAB__addr_0x007537c4\n"
        "LAB__addr_0x007537b6:\n\t"
        "%{disp32%} fld       dword ptr [__real@3dcccccd]\n\t"
        "%{disp8%} jmp        LAB__addr_0x007537c4\n"
        "LAB__addr_0x007537be:\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n"
        "LAB__addr_0x007537c4:\n\t"
        "cmp.s              edi, ebp\n\t"
        "%{disp32%} fld       dword ptr [_GameBlock_ARRAY_00d189d8 + 0x18b8]\n\t"
        "fmul               st, st(1)\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} je        LAB__addr_0x007538a7\n\t"
        "cmp.s              ecx, ebp\n\t"
        "%{disp32%} je        LAB__addr_0x007538a7\n\t"
        "%{disp32%} mov       edx, dword ptr [_game]\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [edx + 0x00205a5b]\n\t"
        "lea                ebx, dword ptr [eax + eax * 0x4]\n\t"
        "lea                ebx, dword ptr [eax + ebx * 0x8]\n\t"
        "lea                eax, dword ptr [eax + ebx * 0x2]\n\t"
        "shl                eax, 5\n\t"
        "%{disp8%} lea        edx, dword ptr [eax + edx * 0x1 + 0x18]\n\t"
        "cmp.s              ecx, edx\n\t"
        "%{disp32%} je        LAB__addr_0x007538a7\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x0073bab0\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x0073e4b0\n\t"
        "%{disp8%} fsubr      dword ptr [esp + 0x14]\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x00753838\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3404]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075383a\n"
        "LAB__addr_0x00753838:\n\t"
        "fstp               st(0)\n"
        "LAB__addr_0x0075383a:\n\t"
        "%{disp32%} fld       dword ptr [_GameBlock_ARRAY_00d189d8 + 0x18c4]\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float1p0]\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x18]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x40\n\t"
        "%{disp8%} je         LAB__addr_0x00753895\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "fstp               st(0)\n\t"
        "cmp                dword ptr [ecx + 0x00205a0c], ebp\n\t"
        "%{disp8%} jne        LAB__addr_0x00753886\n\t"
        "call               ?IsMultiplayerGame@GGame@@QBE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00753886\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00205a08]\n\t"
        "cmp                eax, 0x05\n\t"
        "%{disp8%} ja         LAB__addr_0x00753891\n\t"
        "%{disp8%} mov        ecx, dword ptr [edi + 0x28]\n\t"
        "%{disp32%} fld       dword ptr [ecx + eax * 0x4 + 0x00000170]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00753895\n"
        "LAB__addr_0x00753886:\n\t"
        "%{disp8%} mov        edx, dword ptr [edi + 0x28]\n\t"
        "%{disp32%} fld       dword ptr [edx + 0x0000016c]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00753895\n"
        "LAB__addr_0x00753891:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n"
        "LAB__addr_0x00753895:\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x14]\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float1p0]\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n"
        "LAB__addr_0x007538a7:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "%{disp8%} mov        ebx, dword ptr [esi + 0x28]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x11c]\n\t"
        "%{disp32%} fcomp     dword ptr [ebx + 0x00000380]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} je         LAB__addr_0x007538f0\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "push               0x00000b18\n\t"
        "push               0x00c235dc\n\t"
        "push               0x3e4ccccd\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fadd      dword ptr [rdata_bytes + 0x1ea44]\n\t"
        "%{disp32%} fimul     dword ptr [edi + 0x00000114]\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "%{disp32%} jmp       LAB__addr_0x00753b36\n"
        "LAB__addr_0x007538f0:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        ebx, dword ptr [esi + 0x28]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x11c]\n\t"
        "%{disp32%} fcomp     dword ptr [ebx + 0x0000037c]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} je         LAB__addr_0x00753939\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "push               0x00000b1c\n\t"
        "push               0x00c235dc\n\t"
        "push               0x3e800000\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float0p5]\n\t"
        "%{disp32%} fimul     dword ptr [edi + 0x00000104]\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "%{disp32%} jmp       LAB__addr_0x00753b36\n"
        "LAB__addr_0x00753939:\n\t"
        "cmp.s              edi, ebp\n\t"
        "%{disp8%} je         LAB__addr_0x0075397b\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?IsInStateOfEmergency@Town@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075397b\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x28]\n\t"
        "push               0x00000b20\n\t"
        "push               0x00c235dc\n\t"
        "push               0x3f000000\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fadd      dword ptr [__real@3f400000]\n\t"
        "%{disp32%} fimul     dword ptr [edi + 0x00000108]\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "%{disp32%} jmp       LAB__addr_0x00753b15\n"
        "LAB__addr_0x0075397b:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x24]\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n\t"
        "%{disp8%} mov        ebx, dword ptr [esi + 0x28]\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "shl                ecx, 3\n\t"
        "sub.s              ecx, eax\n\t"
        "cmp.s              edi, ebp\n\t"
        "lea                edx, dword ptr [ecx + ecx * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [edx * 0x4 + 0x00db9e9c]\n\t"
        "%{disp32%} mov       ecx, dword ptr [ebx + eax * 0x4 + 0x00000104]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "%{disp8%} je         LAB__addr_0x007539f8\n\t"
        "%{disp32%} mov       edx, dword ptr [ebx + 0x0000036c]\n\t"
        "fstp               st(0)\n\t"
        "%{disp8%} lea        ecx, dword ptr [edi + 0x34]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], edx\n\t"
        "call               _jmp_addr_0x00747150\n\t"
        "%{disp32%} fdiv      dword ptr [ebx + 0x00000370]\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007539df\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float0p0]\n\t"
        "%{disp8%} jmp        LAB__addr_0x007539f4\n"
        "LAB__addr_0x007539df:\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float0p5]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x007539f4\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float0p5]\n"
        "LAB__addr_0x007539f4:\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x24]\n"
        "LAB__addr_0x007539f8:\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x000000f2]\n\t"
        "cmp                cl, 0x09\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} jne        LAB__addr_0x00753a1a\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00000278]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ebp\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x18]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00753a2c\n"
        "LAB__addr_0x00753a1a:\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00000268]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ebp\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x18]\n"
        "LAB__addr_0x00753a2c:\n\t"
        "cmp                cl, 0x09\n\t"
        "%{disp8%} jne        LAB__addr_0x00753a45\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00000274]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ebp\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x18]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00753a57\n"
        "LAB__addr_0x00753a45:\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00000264]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ebp\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x18]\n"
        "LAB__addr_0x00753a57:\n\t"
        "movsx              ecx, word ptr [esi + 0x000000f6]\n\t"
        "%{disp32%} fld       dword ptr [eax + 0x00000374]\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float1p0]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], ecx\n\t"
        "movsx              edx, word ptr [esi + 0x000000f4]\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x24]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "fdiv               st, st(3)\n\t"
        "fsubp              st(1), st\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x24]\n\t"
        "%{disp32%} fld       dword ptr [eax + 0x00000378]\n\t"
        "%{disp32%} fadd      dword ptr [_rdata_float1p0]\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x18]\n\t"
        "fdiv               st, st(2)\n\t"
        "fsubp              st(1), st\n\t"
        "fstp               st(2)\n\t"
        "fstp               st(0)\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x24]\n\t"
        "%{disp32%} fcomp     dword ptr [__real@3f400000]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00753ab8\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], 0x3f400000\n\t"
        "%{disp8%} jmp        LAB__addr_0x00753ad1\n"
        "LAB__addr_0x00753ab8:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x24]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x00753ad1\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], 0x3f800000\n"
        "LAB__addr_0x00753ad1:\n\t"
        "%{disp32%} fcom      dword ptr [__real@3f400000]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00753ae8\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} fld       dword ptr [__real@3f400000]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00753afd\n"
        "LAB__addr_0x00753ae8:\n\t"
        "%{disp32%} fcom      dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x00753afd\n\t"
        "fstp               st(0)\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float1p0]\n"
        "LAB__addr_0x00753afd:\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x14]\n\t"
        "fmul               st, st(1)\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x24]\n\t"
        "fmul               st, st(2)\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "fstp               st(0)\n\t"
        "fstp               st(0)\n"
        "LAB__addr_0x00753b15:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x87c]\n\t"
        "test               al, al\n\t"
        "%{disp8%} je         LAB__addr_0x00753b32\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x10]\n\t"
        "%{disp32%} fmul      dword ptr [ecx + 0x0000039c]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00753b36\n"
        "LAB__addr_0x00753b32:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x10]\n"
        "LAB__addr_0x00753b36:\n\t"
        "push               0x1\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetSpeed@Villager@@QAEXJH@Z\n\t"
        "pop                edi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n"
        "LAB__addr_0x00753b48:\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_ret))
uint32_t __fastcall SetupNothingToDo__8VillagerFv(struct Villager* this)
{
    asm("sub                esp, 0x0c");                                     // 0x00753b50    83ec0c
    asm("push               ebx");                                           // 0x00753b53    53
    asm("push               esi");                                           // 0x00753b54    56
    asm("mov.s              esi, ecx");                                      // 0x00753b55    8bf1
    asm("mov                eax, dword ptr [esi]");                          // 0x00753b57    8b06
    asm("push               edi");                                           // 0x00753b59    57
    asm("call               dword ptr [eax + 0x48]");                        // 0x00753b5a    ff5048
    asm("mov.s              ecx, esi");                                      // 0x00753b5d    8bce
    asm("mov.s              ebx, eax");                                      // 0x00753b5f    8bd8
    asm("call               ?GetAbode@Villager@@QAEPAVAbode@@XZ");           // 0x00753b61    e8fae5ffff
    asm("push               0x00000b46");                                    // 0x00753b66    68460b0000
    asm("push               0x00c235dc");                                    // 0x00753b6b    68dc35c200
    asm("push               0x9");                                           // 0x00753b70    6a09
    asm("mov.s              edi, eax");                                      // 0x00753b72    8bf8
    asm("call               ?GameRand@GRand@@SAHJ@Z");                       // 0x00753b74    e897a9f8ff
    asm("add                esp, 0x0c");                                     // 0x00753b79    83c40c
    asm("cmp                eax, 0x08");                                     // 0x00753b7c    83f808
    asm("{disp32} ja        LAB__addr_0x00753c3f");                          // 0x00753b7f    0f87ba000000
    asm("xor.s              ecx, ecx");                                      // 0x00753b85    33c9
    asm("{disp32} mov       cl, byte ptr [eax + 0x00753c64]");               // 0x00753b87    8a88643c7500
    asm("jmp                dword ptr [ecx*4 + 0x753c58]");                  // 0x00753b8d    ff248d583c7500
    asm("test               edi, edi");                                      // 0x00753b94    85ff
    asm("{disp8} je         LAB__addr_0x00753ba6");                          // 0x00753b96    740e
    asm("mov                edx, dword ptr [edi]");                          // 0x00753b98    8b17
    asm("mov.s              ecx, edi");                                      // 0x00753b9a    8bcf
    asm("call               dword ptr [edx + 0xd4]");                        // 0x00753b9c    ff92d4000000
    asm("test               eax, eax");                                      // 0x00753ba2    85c0
    asm("{disp8} jne        LAB__addr_0x00753bbf");                          // 0x00753ba4    7519
    asm("LAB__addr_0x00753ba6:");
    asm("push               0x00000b4b");                                    // 0x00753ba6    684b0b0000
    asm("push               0x00c235dc");                                    // 0x00753bab    68dc35c200
    asm("push               0x64");                                          // 0x00753bb0    6a64
    asm("call               ?GameRand@GRand@@SAHJ@Z");                       // 0x00753bb2    e859a9f8ff
    asm("add                esp, 0x0c");                                     // 0x00753bb7    83c40c
    asm("cmp                eax, 0x0a");                                     // 0x00753bba    83f80a
    asm("{disp8} jae        LAB__addr_0x00753bd7");                          // 0x00753bbd    7318
    asm("LAB__addr_0x00753bbf:");
    asm("mov                eax, dword ptr [esi]");                          // 0x00753bbf    8b06
    asm("push               0x24");                                          // 0x00753bc1    6a24
    asm("mov.s              ecx, esi");                                      // 0x00753bc3    8bce
    asm("call               dword ptr [eax + 0x8e8]");                       // 0x00753bc5    ff90e8080000
    asm("pop                edi");                                           // 0x00753bcb    5f
    asm("pop                esi");                                           // 0x00753bcc    5e
    asm("mov                eax, 0x00000001");                               // 0x00753bcd    b801000000
    asm("pop                ebx");                                           // 0x00753bd2    5b
    asm("add                esp, 0x0c");                                     // 0x00753bd3    83c40c
    asm("ret");                                                              // 0x00753bd6    c3
    asm("LAB__addr_0x00753bd7:");
    asm("test               edi, edi");                                      // 0x00753bd7    85ff
    asm("{disp8} je         LAB__addr_0x00753bf6");                          // 0x00753bd9    741b
    asm("mov                edx, dword ptr [esi]");                          // 0x00753bdb    8b16
    asm("push               0x000000f5");                                    // 0x00753bdd    68f5000000
    asm("mov.s              ecx, esi");                                      // 0x00753be2    8bce
    asm("call               dword ptr [edx + 0x8e8]");                       // 0x00753be4    ff92e8080000
    asm("pop                edi");                                           // 0x00753bea    5f
    asm("pop                esi");                                           // 0x00753beb    5e
    asm("mov                eax, 0x00000001");                               // 0x00753bec    b801000000
    asm("pop                ebx");                                           // 0x00753bf1    5b
    asm("add                esp, 0x0c");                                     // 0x00753bf2    83c40c
    asm("ret");                                                              // 0x00753bf5    c3
    asm("LAB__addr_0x00753bf6:");
    asm("test               ebx, ebx");                                      // 0x00753bf6    85db
    asm("{disp8} je         LAB__addr_0x00753c3f");                          // 0x00753bf8    7445
    asm("{disp8} lea        eax, dword ptr [esp + 0x0c]");                   // 0x00753bfa    8d44240c
    asm("push               eax");                                           // 0x00753bfe    50
    asm("mov.s              ecx, esi");                                      // 0x00753bff    8bce
    asm("{disp8} mov        dword ptr [esp + 0x10], 0x00000000");            // 0x00753c01    c744241000000000
    asm("{disp8} mov        dword ptr [esp + 0x14], 0x00000000");            // 0x00753c09    c744241400000000
    asm("{disp8} mov        dword ptr [esp + 0x18], 0x00000000");            // 0x00753c11    c744241800000000
    asm("call               ?GetChillOutPos@Villager@@QAEIAAUMapCoords@@@Z");// 0x00753c19    e852000000
    asm("test               eax, eax");                                      // 0x00753c1e    85c0
    asm("{disp8} je         LAB__addr_0x00753c3f");                          // 0x00753c20    741d
    asm("push               0x000000f6");                                    // 0x00753c22    68f6000000
    asm("{disp8} lea        ecx, dword ptr [esp + 0x10]");                   // 0x00753c27    8d4c2410
    asm("push               ecx");                                           // 0x00753c2b    51
    asm("mov.s              ecx, esi");                                      // 0x00753c2c    8bce
    asm("call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13");// 0x00753c2e    e85dece9ff
    asm("pop                edi");                                           // 0x00753c33    5f
    asm("pop                esi");                                           // 0x00753c34    5e
    asm("mov                eax, 0x00000001");                               // 0x00753c35    b801000000
    asm("pop                ebx");                                           // 0x00753c3a    5b
    asm("add                esp, 0x0c");                                     // 0x00753c3b    83c40c
    asm("ret");                                                              // 0x00753c3e    c3
    asm("LAB__addr_0x00753c3f:");
    asm("mov                edx, dword ptr [esi]");                          // 0x00753c3f    8b16
    asm("push               0x24");                                          // 0x00753c41    6a24
    asm("mov.s              ecx, esi");                                      // 0x00753c43    8bce
    asm("call               dword ptr [edx + 0x8e8]");                       // 0x00753c45    ff92e8080000
    asm("pop                edi");                                           // 0x00753c4b    5f
    asm("pop                esi");                                           // 0x00753c4c    5e
    asm("mov                eax, 0x00000001");                               // 0x00753c4d    b801000000
    asm("pop                ebx");                                           // 0x00753c52    5b
    asm("add                esp, 0x0c");                                     // 0x00753c53    83c40c
    asm("ret");                                                              // 0x00753c56    c3
    // Snippet: db, [0x00753c57, 0x00753c58)
    asm(".byte 0x90");                        // 0x00753c57
    // Snippet: jmptbl, [0x00753c58, 0x00753c64)
    asm(".byte 0x94, 0x3b, 0x75, 0x00");      // 0x00753c58
    asm(".byte 0xd7, 0x3b, 0x75, 0x00");      // 0x00753c5c
    asm(".byte 0xf6, 0x3b, 0x75, 0x00");      // 0x00753c60
    // Snippet: ijmptbl, [0x00753c64, 0x00753c6d)
    asm(".byte 0x00, 0x01, 0x01, 0x01");      // 0x00753c64
    asm(".byte 0x02, 0x02, 0x02, 0x02");      // 0x00753c68
    asm(".byte 0x02");                        // 0x00753c6c
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall GetChillOutPos__8VillagerFR9MapCoords(struct Villager* this, const void* edx, struct MapCoords* coords)
{
    uint32_t result;
    asm volatile (
        "sub               esp, 0x2c\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "mov.s             edi, ecx\n\t"
        "mov               eax, dword ptr [edi]\n\t"
        "call              dword ptr [eax + 0x48]\n\t"
        "mov.s             esi, eax\n\t"
        "test              esi, esi\n\t"
        "%{disp32%} je       LAB__addr_0x00753d45\n\t"
        "%{disp8%} lea       ecx, dword ptr [esp + 0x10]\n\t"
        "push              ecx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?GetCongregationPos@Town@@QAEPAUMapCoords@@PAU2@@Z\n\t"
        "%{disp8%} mov       edx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} fld      dword ptr [edx + 0x00000140]\n\t"
        "add               edi, 0x14\n\t"
        "%{disp32%} fmul     dword ptr [rdata_bytes + 0x3404]\n\t"
        "%{disp8%} lea       eax, dword ptr [esp + 0x10]\n\t"
        "push              edi\n\t"
        "push              eax\n\t"
        "%{disp8%} fstp      dword ptr [esp + 0x10]\n\t"
        "call              ?Get3DAngleFromXZ@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fstp      dword ptr [esp + 0x14]\n\t"
        "push              0x00000b7c\n\t"
        "push              0x00c235dc\n\t"
        "push              0x3f490fdb\n\t"
        "call              ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fsub     dword ptr [rdata_bytes + 0x1dca0]\n\t"
        "add               esp, 0x14\n\t"
        "push              0x00000b7d\n\t"
        "%{disp8%} fadd      dword ptr [esp + 0x10]\n\t"
        "push              0x00c235dc\n\t"
        "push              ecx\n\t"
        "%{disp8%} fstp      dword ptr [esp + 0x18]\n\t"
        "%{disp8%} fld       dword ptr [esp + 0x14]\n\t"
        "%{disp32%} fmul     dword ptr [rdata_bytes + 0x56ec8]\n\t"
        "fstp              dword ptr [esp]\n\t"
        "call              ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp8%} mov       ecx, dword ptr [esp + 0x18]\n\t"
        "%{disp8%} fadd      dword ptr [esp + 0x14]\n\t"
        "add               esp, 0x08\n\t"
        "%{disp8%} lea       edx, dword ptr [esp + 0x20]\n\t"
        "fstp              dword ptr [esp]\n\t"
        "push              ecx\n\t"
        "push              edx\n\t"
        "call              ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "add               esp, 0x0c\n\t"
        "push              eax\n\t"
        "%{disp8%} lea       eax, dword ptr [esp + 0x2c]\n\t"
        "push              eax\n\t"
        "%{disp8%} lea       ecx, dword ptr [esp + 0x18]\n\t"
        "call              @__pl__9MapCoordsCFRC9MapCoords@16\n\t"
        "mov               edx, dword ptr [eax]\n\t"
        "%{disp8%} mov       ecx, dword ptr [esp + 0x38]\n\t"
        "mov               dword ptr [ecx], edx\n\t"
        "%{disp8%} mov       edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov       dword ptr [ecx + 0x04], edx\n\t"
        "%{disp8%} mov       eax, dword ptr [eax + 0x08]\n\t"
        "pop               edi\n\t"
        "%{disp8%} mov       dword ptr [ecx + 0x08], eax\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi\n\t"
        "add               esp, 0x2c\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00753d45:\n\t"
        "pop               edi\n\t"
        "xor.s             eax, eax\n\t"
        "pop               esi\n\t"
        "add               esp, 0x2c\n\t"
        "ret               0x0004\n\t"
        "nop\n\t"
        "sub               esp, 0x10\n\t"
        "push              esi\n\t"
        "mov.s             esi, ecx\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "call              dword ptr [eax + 0x48]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00753dbb\n\t"
        "%{disp8%} mov       ecx, dword ptr [eax + 0x28]\n\t"
        "%{disp32%} fld      dword ptr [ecx + 0x00000144]\n\t"
        "mov.s             ecx, esi\n\t"
        "%{disp32%} fmul     dword ptr [_rdata_float0p5]\n\t"
        "%{disp8%} fstp      dword ptr [esp + 0x04]\n\t"
        "call              ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00753dbb\n\t"
        "%{disp8%} fld       dword ptr [esp + 0x04]\n\t"
        "%{disp8%} mov       edx, dword ptr [esp + 0x04]\n\t"
        "push              ecx\n\t"
        "fstp              dword ptr [esp]\n\t"
        "push              edx\n\t"
        "push              0x40400000\n\t"
        "%{disp8%} lea       ecx, dword ptr [esp + 0x14]\n\t"
        "push              ecx\n\t"
        "mov.s             ecx, eax\n\t"
        "call              ?GetPosOutside@Abode@@QAEPAUMapCoords@@PAU2@MMM@Z\n\t"
        "mov               ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov       edx, dword ptr [esp + 0x18]\n\t"
        "mov               dword ptr [edx], ecx\n\t"
        "%{disp8%} mov       ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov       dword ptr [edx + 0x04], ecx\n\t"
        "%{disp8%} mov       eax, dword ptr [eax + 0x08]\n\t"
        "%{disp8%} mov       dword ptr [edx + 0x08], eax\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi\n\t"
        "add               esp, 0x10\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00753dbb:\n\t"
        "xor.s             eax, eax\n\t"
        "pop               esi\n\t"
        "add               esp, 0x10"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall VillagerCreated__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "xor.s             eax, eax\n\t"
        "%{disp8%} mov       ax, word ptr [ecx + 0x58]\n\t"
        "test              ax, ax\n\t"
        "%{disp8%} lea       edx, dword ptr [eax + -0x01]\n\t"
        "%{disp8%} mov       word ptr [ecx + 0x58], dx\n\t"
        "%{disp8%} jne       LAB__addr_0x00753df3\n\t"
        "%{disp8%} mov       word ptr [ecx + 0x58], ax\n\t"
        "mov               eax, dword ptr [ecx]\n\t"
        "push              0x000000a3\n\t"
        "call              dword ptr [eax + 0x8e8]\n\t"
        "LAB__addr_0x00753df3:\n\t"
        "mov               eax, 0x00000001"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

uint32_t __fastcall RemoveFromGame__8VillagerFv(struct Object* this)
{
    void* dummy;
    uint32_t result;
    asm volatile (
        "push              esi\n\t"
        "mov.s             esi, ecx\n\t"
        "call              ?DeleteDependancys@Villager@@QAEXXZ\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?RemoveFromGame@Living@@UAEIXZ\n\t"
        "pop               esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008)))
struct GameThingWithPos* __fastcall GetResourceDropoffPos__8VillagerF13RESOURCE_TYPE(struct Villager* this, const void* edx, enum RESOURCE_TYPE param_1)
{
    struct GameThingWithPos* result;
    asm volatile (
        "sub               esp, 0x0c\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "mov.s             esi, ecx\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "push              edi\n\t"
        "call              dword ptr [eax + 0x48]\n\t"
        "mov.s             ecx, esi\n\t"
        "mov.s             ebx, eax\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x0c], 0x00000000\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x10], 0x00000000\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x14], 0x00000000\n\t"
        "call              ?GetStoragePit@Villager@@QAEPAVStoragePit@@XZ\n\t"
        "mov.s             edi, eax\n\t"
        "test              edi, edi\n\t"
        "%{disp8%} je        LAB__addr_0x00753e7c\n\t"
        "mov               edx, dword ptr [edi]\n\t"
        "mov.s             ecx, edi\n\t"
        "call              dword ptr [edx + 0xd4]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00753e7c\n"
        "LAB__addr_0x00753e62:\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x1c]\n\t"
        "mov               eax, dword ptr [edi]\n\t"
        "push              esi\n\t"
        "mov.s             ecx, edi\n\t"
        "call              dword ptr [eax + 0x104]\n\t"
        "pop               edi\n\t"
        "mov.s             eax, esi\n\t"
        "pop               esi\n\t"
        "pop               ebx\n\t"
        "add               esp, 0x0c\n\t"
        "ret               0x0008\n"
        "LAB__addr_0x00753e7c:\n\t"
        "test              ebx, ebx\n\t"
        "%{disp8%} je        LAB__addr_0x00753ed3\n\t"
        "mov.s             ecx, ebx\n\t"
        "call              ?GetStoragePit@Town@@QAEPAVStoragePit@@XZ\n\t"
        "mov.s             edi, eax\n\t"
        "test              edi, edi\n\t"
        "%{disp8%} je        LAB__addr_0x00753e9b\n\t"
        "mov               edx, dword ptr [edi]\n\t"
        "mov.s             ecx, edi\n\t"
        "call              dword ptr [edx + 0xd4]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} jne       LAB__addr_0x00753e62\n"
        "LAB__addr_0x00753e9b:\n\t"
        "%{disp8%} mov       ecx, dword ptr [esp + 0x20]\n\t"
        "push              ecx\n\t"
        "%{disp8%} lea       edx, dword ptr [esp + 0x10]\n\t"
        "push              edx\n\t"
        "add               esi, 0x14\n\t"
        "push              esi\n\t"
        "mov.s             ecx, ebx\n\t"
        "call              ?GetTemporaryResourceStorePotOrPos@Town@@QAEPAXABUMapCoords@@AAU2@W4RESOURCE_TYPE@@@Z\n\t"
        "%{disp8%} mov       eax, dword ptr [esp + 0x1c]\n\t"
        "%{disp8%} mov       edx, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ecx, eax\n\t"
        "mov               dword ptr [ecx], edx\n\t"
        "%{disp8%} mov       edx, dword ptr [esp + 0x10]\n\t"
        "pop               edi\n\t"
        "%{disp8%} mov       dword ptr [ecx + 0x04], edx\n\t"
        "%{disp8%} mov       edx, dword ptr [esp + 0x10]\n\t"
        "pop               esi\n\t"
        "%{disp8%} mov       dword ptr [ecx + 0x08], edx\n\t"
        "pop               ebx\n\t"
        "add               esp, 0x0c\n\t"
        "ret               0x0008\n"
        "LAB__addr_0x00753ed3:\n\t"
        "%{disp8%} mov       eax, dword ptr [esp + 0x1c]\n\t"
        "add               esi, 0x14\n\t"
        "mov               edx, dword ptr [esi]\n\t"
        "mov.s             ecx, eax\n\t"
        "mov               dword ptr [ecx], edx\n\t"
        "%{disp8%} mov       edx, dword ptr [esi + 0x04]\n\t"
        "%{disp8%} mov       dword ptr [ecx + 0x04], edx\n\t"
        "%{disp8%} mov       edx, dword ptr [esi + 0x08]\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "%{disp8%} mov       dword ptr [ecx + 0x08], edx\n\t"
        "pop               ebx\n\t"
        "add               esp, 0x0c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall IsFinalState__8VillagerF15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov       eax, dword ptr [esp + 0x04]\n\t"
        "and               eax, 0x000000ff\n\t"
        "lea               ecx, dword ptr [eax + eax * 0x2]\n\t"
        "shl               ecx, 3\n\t"
        "sub.s             ecx, eax\n\t"
        "lea               eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "%{disp32%} mov      eax, dword ptr [eax * 0x4 + 0x00db9e84]"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
enum HELP_TEXT __fastcall GetQueryFirstEnumText__8VillagerFv(struct GameThingWithPos* this)
{
    enum HELP_TEXT result;
    asm volatile (
        "push              esi\n\t"
        "mov.s             esi, ecx\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "call              dword ptr [eax + 0xb04]\n\t"
        "and               eax, 0x000000ff\n\t"
        "mov.s             ecx, eax\n\t"
        "lea               eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl               eax, 3\n\t"
        "sub.s             eax, ecx\n\t"
        "lea               ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov      eax, dword ptr [ecx * 0x4 + 0x00db9f78]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} jne       LAB__addr_0x00753f8e\n\t"
        "xor.s             edx, edx\n\t"
        "%{disp32%} mov      dx, word ptr [esi + 0x000000e0]\n\t"
        "shr               edx, 9\n\t"
        "test              dl, 0x01\n\t"
        "%{disp8%} je        LAB__addr_0x00753f87\n\t"
        "%{disp32%} mov      al, byte ptr [esi + 0x000000f2]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} jl        LAB__addr_0x00753f6f\n\t"
        "cmp               eax, 0x07\n\t"
        "%{disp8%} jg        LAB__addr_0x00753f6f\n\t"
        "add               eax, 0x00000c39\n\t"
        "pop               esi\n\t"
        "ret\n"
        "LAB__addr_0x00753f6f:\n\t"
        "cmp               eax, 0x09\n\t"
        "%{disp8%} jne       LAB__addr_0x00753f7b\n\t"
        "mov               eax, 0x00000ad2\n\t"
        "pop               esi\n\t"
        "ret\n"
        "LAB__addr_0x00753f7b:\n\t"
        "cmp               eax, 0x08\n\t"
        "%{disp8%} jne       LAB__addr_0x00753f87\n\t"
        "mov               eax, 0x00000c39\n\t"
        "pop               esi\n\t"
        "ret\n"
        "LAB__addr_0x00753f87:\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?GetQueryFirstEnumText@Object@@UAE?AW4HELP_TEXT@@XZ\n"
        "LAB__addr_0x00753f8e:\n\t"
        "pop               esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
enum HELP_TEXT __fastcall GetQueryLastEnumText__8VillagerFv(struct GameThingWithPos* this)
{
    enum HELP_TEXT result;
    asm volatile (
        "push              esi\n\t"
        "mov.s             esi, ecx\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "push              edi\n\t"
        "call              dword ptr [eax + 0xb04]\n\t"
        "and               eax, 0x000000ff\n\t"
        "mov.s             ecx, eax\n\t"
        "lea               eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl               eax, 3\n\t"
        "sub.s             eax, ecx\n\t"
        "lea               ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov      edi, dword ptr [ecx * 0x4 + 0x00db9f78]\n\t"
        "test              edi, edi\n\t"
        "%{disp8%} jne       LAB__addr_0x00754007\n\t"
        "xor.s             edx, edx\n\t"
        "%{disp32%} mov      dx, word ptr [esi + 0x000000e0]\n\t"
        "shr               edx, 9\n\t"
        "test              dl, 0x01\n\t"
        "%{disp8%} je        LAB__addr_0x00753ffd\n\t"
        "xor.s             eax, eax\n\t"
        "%{disp32%} mov      al, byte ptr [esi + 0x000000f2]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} jl        LAB__addr_0x00753fe3\n\t"
        "cmp               eax, 0x07\n\t"
        "%{disp8%} jg        LAB__addr_0x00753fe3\n\t"
        "pop               edi\n\t"
        "add               eax, 0x00000c39\n\t"
        "pop               esi\n\t"
        "ret\n"
        "LAB__addr_0x00753fe3:\n\t"
        "cmp               eax, 0x09\n\t"
        "%{disp8%} jne       LAB__addr_0x00753ff0\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000ad2\n\t"
        "pop               esi\n\t"
        "ret\n"
        "LAB__addr_0x00753ff0:\n\t"
        "cmp               eax, 0x08\n\t"
        "%{disp8%} jne       LAB__addr_0x00753ffd\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000c39\n\t"
        "pop               esi\n\t"
        "ret\n"
        "LAB__addr_0x00753ffd:\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?GetQueryLastEnumText@Object@@UAE?AW4HELP_TEXT@@XZ\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "ret\n"
        "LAB__addr_0x00754007:\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "mov.s             ecx, esi\n\t"
        "call              dword ptr [eax + 0xb04]\n\t"
        "and               eax, 0x000000ff\n\t"
        "mov.s             ecx, eax\n\t"
        "lea               eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl               eax, 3\n\t"
        "sub.s             eax, ecx\n\t"
        "lea               ecx, dword ptr [eax + eax * 0x2]\n\t"
        "cmp               dword ptr [ecx * 0x4 + 0x00db9f78], edi\n\t"
        "%{disp8%} jbe       LAB__addr_0x00754049\n\t"
        "xor.s             ecx, ecx\n\t"
        "%{disp32%} mov      cl, byte ptr [esi + 0x0000008c]\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "lea               eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl               eax, 3\n\t"
        "sub.s             eax, ecx\n\t"
        "lea               edx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov      eax, dword ptr [edx * 0x4 + 0x00db9f78]\n\t"
        "ret\n"
        "LAB__addr_0x00754049:\n\t"
        "mov.s             eax, edi\n\t"
        "pop               edi\n\t"
        "pop               esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

extern uint32_t __fastcall GetFOVHelpMessageSet_Object(struct GameThingWithPos* this) asm("?GetFOVHelpMessageSet@Object@@UAEIXZ");

uint32_t __fastcall GetFOVHelpMessageSet__8VillagerFv(struct GameThingWithPos* this)
{
    __attribute__((musttail)) return GetFOVHelpMessageSet_Object(this);
}

extern uint32_t __fastcall GetFOVHelpCondition_Object(struct GameThingWithPos* this) asm("?GetFOVHelpCondition@Object@@UAEIXZ");

uint32_t __fastcall GetFOVHelpCondition__8VillagerFv(struct GameThingWithPos* this)
{
    __attribute__((musttail)) return GetFOVHelpCondition_Object(this);
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall SetDiscipleNothingToDo__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub               esp, 0x0c\n\t"
        "push              esi\n\t"
        "%{disp8%} lea       eax, dword ptr [esp + 0x04]\n\t"
        "mov.s             esi, ecx\n\t"
        "push              eax\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x08], 0x00000000\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x0c], 0x00000000\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x10], 0x00000000\n\t"
        "call              ?FindDisciplePrayerPos@Villager@@QAEIPAUMapCoords@@@Z\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x007540bd\n\t"
        "push              0x000000dd\n\t"
        "%{disp8%} lea       ecx, dword ptr [esp + 0x08]\n\t"
        "push              ecx\n\t"
        "mov.s             ecx, esi\n\t"
        "%{disp8%} mov       word ptr [esi + 0x58], 0x0000\n\t"
        "call              @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi\n\t"
        "add               esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x007540bd:\n\t"
        "xor.s             eax, eax\n\t"
        "pop               esi\n\t"
        "add               esp, 0x0c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall DiscipleNothingToDo__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push              esi\n\t"
        "mov.s             esi, ecx\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "call              dword ptr [eax + 0x48]\n\t"
        "%{disp32%} mov      ecx, dword ptr [eax + 0x000005e8]\n\t"
        "test              ecx, ecx\n\t"
        "%{disp8%} je        LAB__addr_0x007540fa\n\t"
        "push              0x00000c35\n\t"
        "push              0x00c235dc\n\t"
        "push              0xa\n\t"
        "call              ?GameRand@GRand@@SAHJ@Z\n\t"
        "add               esp, 0x0c\n\t"
        "%{disp8%} mov       word ptr [esi + 0x58], ax\n"
        "LAB__addr_0x007540fa:\n\t"
        "dec               word ptr [esi + 0x58]\n\t"
        "%{disp8%} mov       ax, word ptr [esi + 0x58]\n\t"
        "test              ax, ax\n\t"
        "%{disp8%} jg        LAB__addr_0x00754132\n\t"
        "push              0x1\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @IsReadyForNewAnimation__6LivingFUl@12\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x0075412c\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?DiscipleDecideWhatToDo@Villager@@QAE_NXZ\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} jne       LAB__addr_0x00754132\n\t"
        "%{disp8%} mov       word ptr [esi + 0x58], 0x012c\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi\n\t"
        "ret\n"
        "LAB__addr_0x0075412c:\n\t"
        "%{disp8%} mov       word ptr [esi + 0x58], 0x0001\n"
        "LAB__addr_0x00754132:\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall EnterDiscipleNothingToDo__8VillagerFUcUc(struct Villager* this, const void* edx, unsigned char param_1, unsigned char param_2)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push              esi\n\t"
        "mov.s             esi, ecx\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "call              dword ptr [eax + 0x48]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00754174\n\t"
        "mov               edx, dword ptr [esi]\n\t"
        "mov.s             ecx, esi\n\t"
        "call              dword ptr [edx + 0x48]\n\t"
        "%{disp32%} mov      ecx, dword ptr [eax + 0x000009a4]\n\t"
        "test              ecx, ecx\n\t"
        "%{disp8%} je        LAB__addr_0x00754174\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "mov.s             ecx, esi\n\t"
        "call              dword ptr [eax + 0x48]\n\t"
        "%{disp32%} mov      ecx, dword ptr [eax + 0x000009a4]\n\t"
        "push              0x2\n\t"
        "push              ecx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?LookAtObject@Living@@QAEIPAVGameThingWithPos@@K@Z\n\t"
        "LAB__addr_0x00754174:\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall FindDisciplePrayerPos__8VillagerFP9MapCoords(struct Villager* this, const void* edx, struct MapCoords* param_1)
{
    bool32_t result;
    asm volatile (
        "sub               esp, 0x20\n\t"
        "push              ebx\n\t"
        "mov.s             ebx, ecx\n\t"
        "mov               eax, dword ptr [ebx]\n\t"
        "push              esi\n\t"
        "call              dword ptr [eax + 0x48]\n\t"
        "test              eax, eax\n\t"
        "%{disp32%} je       LAB__addr_0x0075426a\n\t"
        "%{disp32%} mov      esi, dword ptr [eax + 0x000009a4]\n\t"
        "test              esi, esi\n\t"
        "%{disp32%} je       LAB__addr_0x00754246\n\t"
        "push              edi\n\t"
        "add               ebx, 0x14\n\t"
        "%{disp8%} lea       edi, dword ptr [esi + 0x14]\n\t"
        "push              ebx\n\t"
        "push              edi\n\t"
        "call              ?Get3DAngleFromXZ@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fstp      dword ptr [esp + 0x14]\n\t"
        "push              0x00000c5b\n\t"
        "push              0x00c235dc\n\t"
        "push              0x3fc90fdb\n\t"
        "call              ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} fsub     dword ptr [rdata_bytes + 0x1dc9c]\n\t"
        "push              0x00000c5c\n\t"
        "push              0x00c235dc\n\t"
        "%{disp8%} fadd      dword ptr [esp + 0x28]\n\t"
        "push              0x40800000\n\t"
        "%{disp8%} fstp      dword ptr [esp + 0x30]\n\t"
        "call              ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "mov               edx, dword ptr [esi]\n\t"
        "%{disp8%} fstp      dword ptr [esp + 0x2c]\n\t"
        "add               esp, 0x20\n\t"
        "mov.s             ecx, esi\n\t"
        "call              dword ptr [edx + 0x64]\n\t"
        "%{disp8%} fadd      dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov       ecx, dword ptr [esp + 0x10]\n\t"
        "%{disp8%} lea       edx, dword ptr [esp + 0x14]\n\t"
        "%{disp8%} fstp      dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov       eax, dword ptr [esp + 0x0c]\n\t"
        "push              eax\n\t"
        "push              ecx\n\t"
        "push              edx\n\t"
        "call              ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z\n\t"
        "add               esp, 0x0c\n\t"
        "push              eax\n\t"
        "%{disp8%} lea       eax, dword ptr [esp + 0x24]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, edi\n\t"
        "call              @__pl__9MapCoordsCFRC9MapCoords@16\n\t"
        "mov               edx, dword ptr [eax]\n\t"
        "%{disp8%} mov       ecx, dword ptr [esp + 0x30]\n\t"
        "mov               dword ptr [ecx], edx\n\t"
        "%{disp8%} mov       edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov       dword ptr [ecx + 0x04], edx\n\t"
        "%{disp8%} mov       eax, dword ptr [eax + 0x08]\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "%{disp8%} mov       dword ptr [ecx + 0x08], eax\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx\n\t"
        "add               esp, 0x20\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00754246:\n\t"
        "%{disp8%} mov       ecx, dword ptr [esp + 0x2c]\n\t"
        "add               eax, 0x14\n\t"
        "mov               edx, dword ptr [eax]\n\t"
        "mov               dword ptr [ecx], edx\n\t"
        "%{disp8%} mov       edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov       dword ptr [ecx + 0x04], edx\n\t"
        "%{disp8%} mov       eax, dword ptr [eax + 0x08]\n\t"
        "pop               esi\n\t"
        "%{disp8%} mov       dword ptr [ecx + 0x08], eax\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx\n\t"
        "add               esp, 0x20\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x0075426a:\n\t"
        "pop               esi\n\t"
        "xor.s             eax, eax\n\t"
        "pop               ebx\n\t"
        "add               esp, 0x20"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall Save__8VillagerFR10GameOSFile(struct GameThing* this, const void* edx, struct GameOSFile* param_1)
{
    uint32_t result;
    asm volatile (
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x08]\n\t"
        "push              edi\n\t"
        "mov.s             edi, ecx\n\t"
        "push              esi\n\t"
        "call              ?Save@Living@@UAEIAAVGameOSFile@@@Z\n\t"
        "test              eax, eax\n\t"
        "%{disp32%} je       LAB__addr_0x0075456d\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "push              ebx\n\t"
        "push              ebp\n\t"
        "xor.s             ebp, ebp\n\t"
        "cmp.s             eax, ebp\n\t"
        "%{disp32%} je       LAB__addr_0x007544b2\n\t"
        "push              ebp\n\t"
        "push              0x2\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x000000e0]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007542c3\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x007542c3:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [ebx]\n\t"
        "add               eax, 0x02\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp32%} je       LAB__addr_0x007544b2\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x000000e8]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754300\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x00754300:\n\t"
        "%{disp32%} mov      edx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [ebx]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             edx, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], edx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp32%} je       LAB__addr_0x007544b2\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x000000ec]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x0075433d\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x0075433d:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [ebx]\n\t"
        "add               edx, 0x04\n\t"
        "add.s             ecx, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp32%} je       LAB__addr_0x007544b2\n\t"
        "push              ebp\n\t"
        "push              0x1\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x000000f0]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x0075437a\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x0075437a:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [ebx]\n\t"
        "inc               eax\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp32%} je       LAB__addr_0x007544b2\n\t"
        "push              ebp\n\t"
        "push              0x1\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x000000f1]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007543b5\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x007543b5:\n\t"
        "%{disp32%} mov      edx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [ebx]\n\t"
        "inc               ecx\n\t"
        "add.s             edx, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], edx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp32%} je       LAB__addr_0x007544b2\n\t"
        "push              ebp\n\t"
        "push              0x1\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x000000f2]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007543f0\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x007543f0:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [ebx]\n\t"
        "inc               edx\n\t"
        "add.s             ecx, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp32%} je       LAB__addr_0x007544b2\n\t"
        "push              ebp\n\t"
        "push              0x2\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x000000f4]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x0075442b\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x0075442b:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [ebx]\n\t"
        "add               eax, 0x02\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp8%} je        LAB__addr_0x007544b2\n\t"
        "push              ebp\n\t"
        "push              0x2\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x000000f6]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754464\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x00754464:\n\t"
        "%{disp32%} mov      edx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [ebx]\n\t"
        "add               ecx, 0x2\n\t"
        "add.s             edx, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], edx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp8%} je        LAB__addr_0x007544b2\n\t"
        "push              ebp\n\t"
        "push              0x2\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x000000f8]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x0075449d\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x0075449d:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [ebx]\n\t"
        "add               edx, 0x02\n\t"
        "add.s             eax, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x007544b2:\n\t"
        "%{disp32%} mov      eax, dword ptr [edi + 0x00000128]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "%{disp32%} mov      ecx, dword ptr [edi + 0x0000012c]\n\t"
        "push              ecx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "%{disp32%} mov      edx, dword ptr [edi + 0x00000100]\n\t"
        "push              edx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x14], ebp\n\t"
        "%{disp8%} je        LAB__addr_0x00754559\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "%{disp8%} lea       eax, dword ptr [esp + 0x1c]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754502\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x00754502:\n\t"
        "%{disp8%} mov       ecx, dword ptr [esp + 0x14]\n\t"
        "%{disp32%} mov      edx, dword ptr [esi + 0x00000214]\n\t"
        "and               ecx, 0x000000ff\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             edx, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], edx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp8%} je        LAB__addr_0x00754559\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "%{disp8%} lea       edx, dword ptr [esp + 0x1c]\n\t"
        "push              edx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x0075453f\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x0075453f:\n\t"
        "%{disp8%} mov       eax, dword ptr [esp + 0x14]\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "and               eax, 0x000000ff\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00754559:\n\t"
        "push              esi\n\t"
        "mov.s             ecx, edi\n\t"
        "call              ?SaveStateFunction@Villager@@QAEIAAVGameOSFile@@@Z\n\t"
        "pop               ebp\n\t"
        "pop               ebx\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x0075456d:\n\t"
        "pop               edi\n\t"
        "xor.s             eax, eax\n\t"
        "pop               esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall Load__8VillagerFR10GameOSFile(struct GameThing* this, const void* edx, struct GameOSFile* param_1)
{
    uint32_t result;
    asm volatile (
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              esi\n\t"
        "call              ?Load@Living@@UAEIAAVGameOSFile@@@Z\n\t"
        "test              eax, eax\n\t"
        "%{disp32%} je       LAB__addr_0x00754861\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "push              ebp\n\t"
        "xor.s             ebp, ebp\n\t"
        "cmp.s             eax, ebp\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x000000e0]\n\t"
        "%{disp8%} je        LAB__addr_0x007545d4\n\t"
        "push              ebp\n\t"
        "push              0x2\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007545bf\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x007545bf:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x02\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x007545d4:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x000000e8]\n\t"
        "%{disp8%} je        LAB__addr_0x0075460d\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007545f8\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x007545f8:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x0075460d:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x000000ec]\n\t"
        "%{disp8%} je        LAB__addr_0x00754646\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754631\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x00754631:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [edi]\n\t"
        "add               edx, 0x04\n\t"
        "add.s             eax, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00754646:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x000000f0]\n\t"
        "%{disp8%} je        LAB__addr_0x0075467d\n\t"
        "push              ebp\n\t"
        "push              0x1\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x0075466a\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x0075466a:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "inc               eax\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x0075467d:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x000000f1]\n\t"
        "%{disp8%} je        LAB__addr_0x007546b4\n\t"
        "push              ebp\n\t"
        "push              0x1\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007546a1\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x007546a1:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "inc               ecx\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x007546b4:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x000000f2]\n\t"
        "%{disp8%} je        LAB__addr_0x007546eb\n\t"
        "push              ebp\n\t"
        "push              0x1\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007546d8\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x007546d8:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [edi]\n\t"
        "inc               edx\n\t"
        "add.s             eax, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x007546eb:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x000000f4]\n\t"
        "%{disp8%} je        LAB__addr_0x00754724\n\t"
        "push              ebp\n\t"
        "push              0x2\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x0075470f\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x0075470f:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x02\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00754724:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x000000f6]\n\t"
        "%{disp8%} je        LAB__addr_0x0075475d\n\t"
        "push              ebp\n\t"
        "push              0x2\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754748\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x00754748:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x2\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x0075475d:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x000000f8]\n\t"
        "%{disp8%} je        LAB__addr_0x00754796\n\t"
        "push              ebp\n\t"
        "push              0x2\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754781\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x00754781:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [edi]\n\t"
        "add               edx, 0x02\n\t"
        "add.s             eax, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00754796:\n\t"
        "%{disp32%} lea      eax, dword ptr [ebx + 0x00000128]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "%{disp32%} lea      ecx, dword ptr [ebx + 0x0000012c]\n\t"
        "push              ecx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "%{disp32%} lea      edx, dword ptr [ebx + 0x00000100]\n\t"
        "push              edx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x14], ebp\n\t"
        "%{disp8%} je        LAB__addr_0x0075483d\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "%{disp8%} lea       eax, dword ptr [esp + 0x1c]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007547e6\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x007547e6:\n\t"
        "%{disp8%} mov       ecx, dword ptr [esp + 0x14]\n\t"
        "%{disp32%} mov      edx, dword ptr [esi + 0x00000214]\n\t"
        "and               ecx, 0x000000ff\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             edx, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], edx\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp8%} je        LAB__addr_0x0075483d\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "%{disp8%} lea       edx, dword ptr [esp + 0x1c]\n\t"
        "push              edx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754823\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x00754823:\n\t"
        "%{disp8%} mov       eax, dword ptr [esp + 0x14]\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "and               eax, 0x000000ff\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x0075483d:\n\t"
        "push              esi\n\t"
        "mov.s             ecx, ebx\n\t"
        "call              ?LoadStateFunction@Villager@@QAEIAAVGameOSFile@@@Z\n\t"
        "mov               edx, dword ptr [ebx]\n\t"
        "mov.s             ecx, ebx\n\t"
        "call              dword ptr [edx + 0x508]\n\t"
        "%{disp32%} fstp     dword ptr [ebx + 0x00000108]\n\t"
        "pop               edi\n\t"
        "pop               ebp\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00754861:\n\t"
        "pop               esi\n\t"
        "xor.s             eax, eax\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
void __fastcall ResolveLoad__8VillagerFv(struct GameThing* this)
{
    void* dummy;
    asm volatile (
        "push              esi\n\t"
        "push              edi\n\t"
        "mov.s             esi, ecx\n\t"
        "call              ?ResolveLoad@Living@@UAEXXZ\n\t"
        "%{disp8%} mov       ecx, dword ptr [esi + 0x40]\n\t"
        "mov               edi, dword ptr [ecx]\n\t"
        "xor.s             eax, eax\n\t"
        "%{disp32%} mov      al, byte ptr [esi + 0x000000f2]\n\t"
        "%{disp32%} lea      edx, dword ptr [eax * 0x8 + 0x00000000]\n\t"
        "sub.s             edx, eax\n\t"
        "%{disp32%} mov      edx, dword ptr [edx * 0x4 + 0x0099a200]\n\t"
        "call              dword ptr [edi + 0xcc]\n\t"
        "pop               edi\n\t"
        "pop               esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0008)))
bool32_t __fastcall CallSaveStateFunction__8VillagerFR10GameOSFile10STATE_TYPE(struct Villager* this, const void* edx, struct GameOSFile* param_1, enum STATE_TYPE param_2)
{
    bool32_t result;
    asm volatile (
        "sub               esp, 0x10\n\t"
        "%{disp8%} mov       edx, dword ptr [esp + 0x18]\n\t"
        "xor.s             eax, eax\n\t"
        "%{disp32%} mov      al, byte ptr [edx + ecx * 0x1 + 0x0000008c]\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "lea               eax, dword ptr [eax + eax * 0x8]\n\t"
        "shl               eax, 4\n\t"
        "%{disp32%} lea      eax, dword ptr [eax + 0x00d091c8]\n\t"
        "mov.s             esi, eax\n\t"
        "mov               edx, dword ptr [esi]\n\t"
        "test              edx, edx\n\t"
        "%{disp8%} mov       edi, dword ptr [esi + 0x04]\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x0c], edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esi + 0x08]\n\t"
        "%{disp8%} mov       esi, dword ptr [esi + 0x0c]\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x10], edi\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x14], esi\n\t"
        "%{disp8%} je        LAB__addr_0x007548ff\n\t"
        "%{disp8%} mov       esi, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov       edi, dword ptr [eax + 0x08]\n\t"
        "mov               edx, dword ptr [eax]\n\t"
        "%{disp8%} mov       eax, dword ptr [eax + 0x0c]\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x14], eax\n\t"
        "%{disp8%} mov       eax, dword ptr [esp + 0x1c]\n\t"
        "push              eax\n\t"
        "add.s             ecx, esi\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x14], edi\n\t"
        "call              edx\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "add               esp, 0x10\n\t"
        "ret               0x0008\n"
        "LAB__addr_0x007548ff:\n\t"
        "pop               edi\n\t"
        "xor.s             eax, eax\n\t"
        "pop               esi\n\t"
        "add               esp, 0x10"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0008)))
bool32_t __fastcall CallLoadStateFunction__8VillagerFR10GameOSFile10STATE_TYPE(struct Villager* this, const void* edx, struct GameOSFile* param_1, enum STATE_TYPE param_2)
{
    bool32_t result;
    asm volatile (
        "sub               esp, 0x10\n\t"
        "%{disp8%} mov       edx, dword ptr [esp + 0x18]\n\t"
        "xor.s             eax, eax\n\t"
        "%{disp32%} mov      al, byte ptr [edx + ecx * 0x1 + 0x0000008c]\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "lea               eax, dword ptr [eax + eax * 0x8]\n\t"
        "shl               eax, 4\n\t"
        "%{disp32%} lea      eax, dword ptr [eax + 0x00d091d8]\n\t"
        "mov.s             esi, eax\n\t"
        "mov               edx, dword ptr [esi]\n\t"
        "test              edx, edx\n\t"
        "%{disp8%} mov       edi, dword ptr [esi + 0x04]\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x0c], edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esi + 0x08]\n\t"
        "%{disp8%} mov       esi, dword ptr [esi + 0x0c]\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x10], edi\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x14], esi\n\t"
        "%{disp8%} je        LAB__addr_0x0075496f\n\t"
        "%{disp8%} mov       esi, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov       edi, dword ptr [eax + 0x08]\n\t"
        "mov               edx, dword ptr [eax]\n\t"
        "%{disp8%} mov       eax, dword ptr [eax + 0x0c]\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x14], eax\n\t"
        "%{disp8%} mov       eax, dword ptr [esp + 0x1c]\n\t"
        "push              eax\n\t"
        "add.s             ecx, esi\n\t"
        "%{disp8%} mov       dword ptr [esp + 0x14], edi\n\t"
        "call              edx\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "add               esp, 0x10\n\t"
        "ret               0x0008\n"
        "LAB__addr_0x0075496f:\n\t"
        "pop               edi\n\t"
        "xor.s             eax, eax\n\t"
        "pop               esi\n\t"
        "add               esp, 0x10"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveStateFunction__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "push              ebx\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x10]\n\t"
        "push              0x0\n\t"
        "mov.s             esi, ecx\n\t"
        "push              edi\n\t"
        "call              ?CallSaveStateFunction@Villager@@QAEIAAVGameOSFile@@W4STATE_TYPE@@@Z\n\t"
        "push              0x1\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "mov.s             ebx, eax\n\t"
        "call              ?CallSaveStateFunction@Villager@@QAEIAAVGameOSFile@@W4STATE_TYPE@@@Z\n\t"
        "or.s              eax, ebx\n\t"
        "neg               eax\n\t"
        "pop               edi\n\t"
        "sbb.s             eax, eax\n\t"
        "pop               esi\n\t"
        "neg               eax\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadStateFunction__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "push              ebx\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x10]\n\t"
        "push              0x0\n\t"
        "mov.s             esi, ecx\n\t"
        "push              edi\n\t"
        "call              ?CallLoadStateFunction@Villager@@QAEIAAVGameOSFile@@W4STATE_TYPE@@@Z\n\t"
        "push              0x1\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "mov.s             ebx, eax\n\t"
        "call              ?CallLoadStateFunction@Villager@@QAEIAAVGameOSFile@@W4STATE_TYPE@@@Z\n\t"
        "or.s              eax, ebx\n\t"
        "%{disp8%} jbe       LAB__addr_0x007549dc\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x007549dc:\n\t"
        "push              0x00000cdd\n\t"
        "push              0x00c235dc\n\t"
        "push              0x14\n\t"
        "call              ?GameRand@GRand@@SAHJ@Z\n\t"
        "add               esp, 0x0c\n\t"
        "inc               eax\n\t"
        "pop               edi\n\t"
        "%{disp8%} mov       word ptr [esi + 0x58], ax\n\t"
        "pop               esi\n\t"
        "xor.s             eax, eax\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveBuilding__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x08]\n\t"
        "push              edi\n\t"
        "mov.s             edi, ecx\n\t"
        "%{disp32%} mov      eax, dword ptr [edi + 0x000000fc]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00754a55\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "add               edi, 0x00000118\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754a40\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00754a40:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00754a55:\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadBuilding__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x08]\n\t"
        "push              edi\n\t"
        "mov.s             edi, ecx\n\t"
        "%{disp32%} lea      eax, dword ptr [edi + 0x000000fc]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "add               edi, 0x00000118\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00754ab5\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754aa0\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00754aa0:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00754ab5:\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveDance__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "mov.s             ebx, ecx\n\t"
        "%{disp8%} je        LAB__addr_0x00754b47\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x10]\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000118]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754af3\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00754af3:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00754b47\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000011c]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754b32\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00754b32:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00754b47:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadDance__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000118]\n\t"
        "%{disp8%} je        LAB__addr_0x00754ba8\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754b93\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00754b93:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00754ba8:\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000011c]\n\t"
        "%{disp8%} je        LAB__addr_0x00754be7\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754bd2\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00754bd2:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00754be7:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveWorship__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00754c4f\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x0c]\n\t"
        "push              0x0\n\t"
        "%{disp32%} lea      esi, dword ptr [ecx + 0x00000118]\n\t"
        "push              0x4\n\t"
        "push              esi\n\t"
        "mov.s             ecx, edi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754c30\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00754c30:\n\t"
        "%{disp32%} mov      ecx, dword ptr [edi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [esi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [edi + 0x00000214], ecx\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00754c4f:\n\t"
        "mov               eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadWorship__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ecx + 0x00000118]\n\t"
        "%{disp8%} je        LAB__addr_0x00754caf\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754c90\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00754c90:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               edi\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00754caf:\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               edi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveDead__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00754d0d\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x0c]\n\t"
        "push              0x0\n\t"
        "%{disp32%} lea      esi, dword ptr [ecx + 0x00000118]\n\t"
        "push              0x1\n\t"
        "push              esi\n\t"
        "mov.s             ecx, edi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754cf0\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00754cf0:\n\t"
        "%{disp32%} mov      ecx, dword ptr [edi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [esi]\n\t"
        "inc               eax\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [edi + 0x00000214], ecx\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00754d0d:\n\t"
        "mov               eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadDead__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ecx + 0x00000118]\n\t"
        "%{disp8%} je        LAB__addr_0x00754d6d\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "push              0x0\n\t"
        "push              0x1\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754d50\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00754d50:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "inc               eax\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               edi\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00754d6d:\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               edi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveInHand__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00754dcf\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x0c]\n\t"
        "push              0x0\n\t"
        "%{disp32%} lea      esi, dword ptr [ecx + 0x0000010c]\n\t"
        "push              0x4\n\t"
        "push              esi\n\t"
        "mov.s             ecx, edi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754db0\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00754db0:\n\t"
        "%{disp32%} mov      ecx, dword ptr [edi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [esi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [edi + 0x00000214], ecx\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00754dcf:\n\t"
        "mov               eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadInHand__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ecx + 0x0000010c]\n\t"
        "%{disp8%} je        LAB__addr_0x00754e2f\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754e10\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00754e10:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               edi\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00754e2f:\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               edi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004), no_tail_call))
bool32_t __fastcall SaveFishing__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    struct GameThing* thing = *(struct GameThing**)((char*)this + 0x118);
    WritePtr__10GameOSFileFP9GameThing(param_1, edx, thing);
    return 1;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004), no_tail_call))
bool32_t __fastcall LoadFishing__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    extern void __attribute__((thiscall)) __opaque_ReadPtr(struct GameOSFile*, struct GameThing**) asm("__thunk_call_ReadPtr");
    __opaque_ReadPtr(param_1, (struct GameThing**)((char*)this + 0x118));
    return 1;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveFarming__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "%{disp8%} je        LAB__addr_0x00754ec9\n\t"
        "push              esi\n\t"
        "push              0x0\n\t"
        "push              0xc\n\t"
        "%{disp32%} lea      esi, dword ptr [ebx + 0x0000011c]\n\t"
        "push              esi\n\t"
        "mov.s             ecx, edi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754eb3\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00754eb3:\n\t"
        "%{disp32%} mov      ecx, dword ptr [edi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [esi]\n\t"
        "pop               esi\n\t"
        "add               eax, 0x0c\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [edi + 0x00000214], ecx\n"
        "LAB__addr_0x00754ec9:\n\t"
        "%{disp32%} mov      ecx, dword ptr [ebx + 0x00000118]\n\t"
        "push              ecx\n\t"
        "mov.s             ecx, edi\n\t"
        "call              ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadFarming__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000011c]\n\t"
        "%{disp8%} je        LAB__addr_0x00754f38\n\t"
        "push              0x0\n\t"
        "push              0xc\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754f23\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00754f23:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x0c\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00754f38:\n\t"
        "add               ebx, 0x00000118\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveFootball__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "push              edi\n\t"
        "mov.s             edi, ecx\n\t"
        "%{disp32%} je       LAB__addr_0x00755024\n\t"
        "push              0x0\n\t"
        "push              0x1\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x00000118]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754f97\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00754f97:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [ebx]\n\t"
        "inc               eax\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00755024\n\t"
        "push              0x0\n\t"
        "push              0x1\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x00000119]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00754fd4\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00754fd4:\n\t"
        "%{disp32%} mov      edx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [ebx]\n\t"
        "inc               ecx\n\t"
        "add.s             edx, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], edx\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00755024\n\t"
        "push              0x0\n\t"
        "push              0x1\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x0000011a]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755011\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755011:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [ebx]\n\t"
        "inc               edx\n\t"
        "add.s             eax, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755024:\n\t"
        "%{disp32%} mov      eax, dword ptr [edi + 0x0000011c]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadFootball__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000118]\n\t"
        "%{disp8%} je        LAB__addr_0x00755086\n\t"
        "push              0x0\n\t"
        "push              0x1\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755073\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755073:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "inc               eax\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00755086:\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000119]\n\t"
        "%{disp8%} je        LAB__addr_0x007550c3\n\t"
        "push              0x0\n\t"
        "push              0x1\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007550b0\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x007550b0:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "inc               ecx\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x007550c3:\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000011a]\n\t"
        "%{disp8%} je        LAB__addr_0x00755100\n\t"
        "push              0x0\n\t"
        "push              0x1\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007550ed\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x007550ed:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [edi]\n\t"
        "inc               edx\n\t"
        "add.s             eax, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755100:\n\t"
        "add               ebx, 0x0000011c\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveShepherd__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "mov.s             ebx, ecx\n\t"
        "%{disp8%} je        LAB__addr_0x007551a7\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x10]\n\t"
        "push              0x0\n\t"
        "push              0x2\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000118]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755153\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755153:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x02\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x007551a7\n\t"
        "push              0x0\n\t"
        "push              0x2\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000011a]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755192\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755192:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x2\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x007551a7:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadShepherd__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000118]\n\t"
        "%{disp8%} je        LAB__addr_0x00755208\n\t"
        "push              0x0\n\t"
        "push              0x2\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007551f3\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x007551f3:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x02\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00755208:\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000011a]\n\t"
        "%{disp8%} je        LAB__addr_0x00755247\n\t"
        "push              0x0\n\t"
        "push              0x2\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755232\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755232:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x2\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755247:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveInScript__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "push              ebx\n\t"
        "push              ebp\n\t"
        "push              esi\n\t"
        "xor.s             ebp, ebp\n\t"
        "cmp.s             eax, ebp\n\t"
        "push              edi\n\t"
        "mov.s             edi, ecx\n\t"
        "%{disp32%} je       LAB__addr_0x00755359\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x14]\n\t"
        "push              ebp\n\t"
        "push              0x8\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x0000010c]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755295\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x00755295:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [ebx]\n\t"
        "add               eax, 0x08\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp32%} je       LAB__addr_0x00755359\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x00000118]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007552d2\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x007552d2:\n\t"
        "%{disp32%} mov      edx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [ebx]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             edx, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], edx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp8%} je        LAB__addr_0x00755359\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x0000011c]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x0075530b\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x0075530b:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [ebx]\n\t"
        "add               edx, 0x04\n\t"
        "add.s             ecx, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp8%} je        LAB__addr_0x00755359\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "add               edi, 0x00000120\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755344\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x00755344:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00755359:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "pop               ebp\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadInScript__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "push              ebx\n\t"
        "push              ebp\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x10]\n\t"
        "xor.s             ebp, ebp\n\t"
        "cmp.s             eax, ebp\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000010c]\n\t"
        "%{disp8%} je        LAB__addr_0x007553b6\n\t"
        "push              ebp\n\t"
        "push              0x8\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007553a1\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x007553a1:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x08\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x007553b6:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000118]\n\t"
        "%{disp8%} je        LAB__addr_0x007553ef\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007553da\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x007553da:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x007553ef:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000011c]\n\t"
        "%{disp8%} je        LAB__addr_0x00755428\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755413\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x00755413:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [edi]\n\t"
        "add               edx, 0x04\n\t"
        "add.s             eax, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755428:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000120]\n\t"
        "%{disp8%} je        LAB__addr_0x00755461\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x0075544c\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x0075544c:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00755461:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "pop               ebp\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveScriptPos__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "push              ebx\n\t"
        "push              ebp\n\t"
        "push              esi\n\t"
        "xor.s             ebp, ebp\n\t"
        "cmp.s             eax, ebp\n\t"
        "push              edi\n\t"
        "mov.s             edi, ecx\n\t"
        "%{disp32%} je       LAB__addr_0x00755569\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x14]\n\t"
        "push              ebp\n\t"
        "push              0x8\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x0000010c]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007554a5\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x007554a5:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [ebx]\n\t"
        "add               eax, 0x08\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp32%} je       LAB__addr_0x00755569\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x00000118]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007554e2\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x007554e2:\n\t"
        "%{disp32%} mov      edx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [ebx]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             edx, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], edx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp8%} je        LAB__addr_0x00755569\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      ebx, dword ptr [edi + 0x0000011c]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x0075551b\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x0075551b:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [ebx]\n\t"
        "add               edx, 0x04\n\t"
        "add.s             ecx, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "cmp               dword ptr [_DAT_00bec990], ebp\n\t"
        "%{disp8%} je        LAB__addr_0x00755569\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "add               edi, 0x00000120\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755554\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], ebp\n"
        "LAB__addr_0x00755554:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00755569:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "pop               ebp\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadScriptPos__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "push              ebx\n\t"
        "push              ebp\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x10]\n\t"
        "xor.s             ebp, ebp\n\t"
        "cmp.s             eax, ebp\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000010c]\n\t"
        "%{disp8%} je        LAB__addr_0x007555c6\n\t"
        "push              ebp\n\t"
        "push              0x8\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007555b1\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x007555b1:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x08\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x007555c6:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000118]\n\t"
        "%{disp8%} je        LAB__addr_0x007555ff\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007555ea\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x007555ea:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x007555ff:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000011c]\n\t"
        "%{disp8%} je        LAB__addr_0x00755638\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755623\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x00755623:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             edx, edx\n\t"
        "mov               dl, byte ptr [edi]\n\t"
        "add               edx, 0x04\n\t"
        "add.s             eax, edx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755638:\n\t"
        "cmp               dword ptr [_DAT_00bec994], ebp\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000120]\n\t"
        "%{disp8%} je        LAB__addr_0x00755671\n\t"
        "push              ebp\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x0075565c\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], ebp\n"
        "LAB__addr_0x0075565c:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00755671:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "pop               ebp\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveFire__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "%{disp8%} je        LAB__addr_0x007556c9\n\t"
        "push              esi\n\t"
        "push              0x0\n\t"
        "push              0x8\n\t"
        "%{disp32%} lea      esi, dword ptr [ebx + 0x0000010c]\n\t"
        "push              esi\n\t"
        "mov.s             ecx, edi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007556b3\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x007556b3:\n\t"
        "%{disp32%} mov      ecx, dword ptr [edi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [esi]\n\t"
        "pop               esi\n\t"
        "add               eax, 0x08\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [edi + 0x00000214], ecx\n"
        "LAB__addr_0x007556c9:\n\t"
        "%{disp32%} mov      ecx, dword ptr [ebx + 0x00000114]\n\t"
        "push              ecx\n\t"
        "mov.s             ecx, edi\n\t"
        "call              ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadFire__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000010c]\n\t"
        "%{disp8%} je        LAB__addr_0x00755738\n\t"
        "push              0x0\n\t"
        "push              0x8\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755723\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755723:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x08\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00755738:\n\t"
        "add               ebx, 0x00000114\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveDiscipleNothingToDo__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "cmp               byte ptr [ecx + 0x000000f2], 0x09\n\t"
        "%{disp8%} jne       LAB__addr_0x00755773\n\t"
        "%{disp8%} mov       eax, dword ptr [esp + 0x04]\n\t"
        "push              eax\n\t"
        "call              ?SaveTrader@Villager@@QAEIAAVGameOSFile@@@Z\n"
        "LAB__addr_0x00755773:\n\t"
        "mov               eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadDiscipleNothingToDo__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "cmp               byte ptr [ecx + 0x000000f2], 0x09\n\t"
        "%{disp8%} jne       LAB__addr_0x00755793\n\t"
        "%{disp8%} mov       eax, dword ptr [esp + 0x04]\n\t"
        "push              eax\n\t"
        "call              ?LoadTrader@Villager@@QAEIAAVGameOSFile@@@Z\n"
        "LAB__addr_0x00755793:\n\t"
        "mov               eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveTrader__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "%{disp8%} je        LAB__addr_0x007557e9\n\t"
        "push              esi\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      esi, dword ptr [ebx + 0x00000118]\n\t"
        "push              esi\n\t"
        "mov.s             ecx, edi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007557d3\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x007557d3:\n\t"
        "%{disp32%} mov      ecx, dword ptr [edi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [esi]\n\t"
        "pop               esi\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [edi + 0x00000214], ecx\n"
        "LAB__addr_0x007557e9:\n\t"
        "%{disp32%} mov      ecx, dword ptr [ebx + 0x0000011c]\n\t"
        "push              ecx\n\t"
        "mov.s             ecx, edi\n\t"
        "call              ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadTrader__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000118]\n\t"
        "%{disp8%} je        LAB__addr_0x00755858\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755843\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755843:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00755858:\n\t"
        "add               ebx, 0x0000011c\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004), no_tail_call))
bool32_t __fastcall SaveInspectObject__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    struct GameThing* thing = *(struct GameThing**)((char*)this + 0x118);
    WritePtr__10GameOSFileFP9GameThing(param_1, edx, thing);
    return 1;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004), no_tail_call))
bool32_t __fastcall LoadInspectObject__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    extern void __attribute__((thiscall)) __opaque_ReadPtr(struct GameOSFile*, struct GameThing**) asm("__thunk_call_ReadPtr");
    __opaque_ReadPtr(param_1, (struct GameThing**)((char*)this + 0x118));
    return 1;
}

bool32_t __fastcall SaveReaction__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    return 1;
}

bool32_t __fastcall LoadReaction__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    return 1;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveClearArea__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "mov.s             ebx, ecx\n\t"
        "%{disp8%} je        LAB__addr_0x00755967\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x10]\n\t"
        "push              0x0\n\t"
        "push              0x8\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000118]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755913\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755913:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x08\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00755967\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000120]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755952\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755952:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755967:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadClearArea__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000118]\n\t"
        "%{disp8%} je        LAB__addr_0x007559c8\n\t"
        "push              0x0\n\t"
        "push              0x8\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007559b3\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x007559b3:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x08\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x007559c8:\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000120]\n\t"
        "%{disp8%} je        LAB__addr_0x00755a07\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x007559f2\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x007559f2:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755a07:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveBreeder__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x08]\n\t"
        "push              edi\n\t"
        "mov.s             edi, ecx\n\t"
        "%{disp32%} mov      eax, dword ptr [edi + 0x00000118]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00755a75\n\t"
        "push              0x0\n\t"
        "push              0x8\n\t"
        "add               edi, 0x0000011c\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755a60\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755a60:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x8\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755a75:\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadBreeder__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x08]\n\t"
        "push              edi\n\t"
        "mov.s             edi, ecx\n\t"
        "%{disp32%} lea      eax, dword ptr [edi + 0x00000118]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "add               edi, 0x0000011c\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00755ad5\n\t"
        "push              0x0\n\t"
        "push              0x8\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755ac0\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755ac0:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x8\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755ad5:\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004), no_tail_call))
bool32_t __fastcall SaveForesting__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    struct GameThing* thing = *(struct GameThing**)((char*)this + 0x118);
    WritePtr__10GameOSFileFP9GameThing(param_1, edx, thing);
    return 1;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004), no_tail_call))
bool32_t __fastcall LoadForesting__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    extern void __attribute__((thiscall)) __opaque_ReadPtr(struct GameOSFile*, struct GameThing**) asm("__thunk_call_ReadPtr");
    __opaque_ReadPtr(param_1, (struct GameThing**)((char*)this + 0x118));
    return 1;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveFootPath__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "push              esi\n\t"
        "mov.s             esi, ecx\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x000000c8]\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x0c]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, edi\n\t"
        "call              ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x000000cc]\n\t"
        "push              ecx\n\t"
        "mov.s             ecx, edi\n\t"
        "call              ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadFootPath__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "push              esi\n\t"
        "mov.s             esi, ecx\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x0c]\n\t"
        "%{disp32%} lea      eax, dword ptr [esi + 0x000000c8]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, edi\n\t"
        "call              @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "add               esi, 0x000000cc\n\t"
        "push              esi\n\t"
        "mov.s             ecx, edi\n\t"
        "call              @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveInspectionReaction__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "mov.s             ebx, ecx\n\t"
        "%{disp8%} je        LAB__addr_0x00755c07\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x10]\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000010c]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755bb3\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755bb3:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00755c07\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000110]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755bf2\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755bf2:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755c07:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall LoadInspectionReaction__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000010c]\n\t"
        "%{disp8%} je        LAB__addr_0x00755c68\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755c53\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755c53:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00755c68:\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000110]\n\t"
        "%{disp8%} je        LAB__addr_0x00755ca7\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755c92\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755c92:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755ca7:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall SaveMagicTreeReaction__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "mov.s             ebx, ecx\n\t"
        "%{disp8%} je        LAB__addr_0x00755d47\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x10]\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000010c]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755cf3\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755cf3:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00755d47\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000110]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755d32\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755d32:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755d47:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall LoadMagicTreeReaction__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    uint32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000010c]\n\t"
        "%{disp8%} je        LAB__addr_0x00755da8\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755d93\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755d93:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00755da8:\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000110]\n\t"
        "%{disp8%} je        LAB__addr_0x00755de7\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755dd2\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755dd2:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x4\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755de7:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall SaveHideInBuilding__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    uint32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "mov.s             ebx, ecx\n\t"
        "%{disp8%} je        LAB__addr_0x00755e87\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x10]\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000010c]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755e33\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755e33:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00755e87\n\t"
        "push              0x0\n\t"
        "push              0x8\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000110]\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755e72\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755e72:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x8\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755e87:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall LoadHideInBuilding__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    uint32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              ebx\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s             ebx, ecx\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x0000010c]\n\t"
        "%{disp8%} je        LAB__addr_0x00755ee8\n\t"
        "push              0x0\n\t"
        "push              0x4\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755ed3\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755ed3:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x04\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n"
        "LAB__addr_0x00755ee8:\n\t"
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "%{disp32%} lea      edi, dword ptr [ebx + 0x00000110]\n\t"
        "%{disp8%} je        LAB__addr_0x00755f27\n\t"
        "push              0x0\n\t"
        "push              0x8\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755f12\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755f12:\n\t"
        "%{disp32%} mov      eax, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             ecx, ecx\n\t"
        "mov               cl, byte ptr [edi]\n\t"
        "add               ecx, 0x8\n\t"
        "add.s             eax, ecx\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], eax\n"
        "LAB__addr_0x00755f27:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall SaveShieldReaction__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    uint32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec990]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00755f8f\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x0c]\n\t"
        "push              0x0\n\t"
        "%{disp32%} lea      esi, dword ptr [ecx + 0x0000010c]\n\t"
        "push              0x8\n\t"
        "push              esi\n\t"
        "mov.s             ecx, edi\n\t"
        "call              @Write__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755f70\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec990], 0x00000000\n"
        "LAB__addr_0x00755f70:\n\t"
        "%{disp32%} mov      ecx, dword ptr [edi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [esi]\n\t"
        "add               eax, 0x08\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [edi + 0x00000214], ecx\n\t"
        "pop               edi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               esi\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00755f8f:\n\t"
        "mov               eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall LoadShieldReaction__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    uint32_t result;
    asm volatile (
        "%{disp32%} mov      eax, dword ptr [_DAT_00bec994]\n\t"
        "test              eax, eax\n\t"
        "push              edi\n\t"
        "%{disp32%} lea      edi, dword ptr [ecx + 0x0000010c]\n\t"
        "%{disp8%} je        LAB__addr_0x00755fef\n\t"
        "push              esi\n\t"
        "%{disp8%} mov       esi, dword ptr [esp + 0x0c]\n\t"
        "push              0x0\n\t"
        "push              0x8\n\t"
        "push              edi\n\t"
        "mov.s             ecx, esi\n\t"
        "call              @Read__8LHOSFileFPvUlPUl@20\n\t"
        "cmp               eax, 0x03\n\t"
        "%{disp8%} jne       LAB__addr_0x00755fd0\n\t"
        "%{disp32%} mov      dword ptr [_DAT_00bec994], 0x00000000\n"
        "LAB__addr_0x00755fd0:\n\t"
        "%{disp32%} mov      ecx, dword ptr [esi + 0x00000214]\n\t"
        "xor.s             eax, eax\n\t"
        "mov               al, byte ptr [edi]\n\t"
        "add               eax, 0x08\n\t"
        "add.s             ecx, eax\n\t"
        "%{disp32%} mov      dword ptr [esi + 0x00000214], ecx\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               edi\n\t"
        "ret               0x0004\n"
        "LAB__addr_0x00755fef:\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               edi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x000c)))
uint32_t __fastcall SetVillagerDisciple__8VillagerFP9GameThing17VILLAGER_DISCIPLEi(struct Villager* this, const void* edx, struct GameThing* param_1, enum VILLAGER_DISCIPLE param_2, int param_3)
{
    uint32_t result;
    asm volatile (
        "push              ebx\n\t"
        "%{disp8%} mov       ebx, dword ptr [esp + 0x0c]\n\t"
        "test              ebx, ebx\n\t"
        "push              esi\n\t"
        "mov.s             esi, ecx\n\t"
        "%{disp8%} jl        LAB__addr_0x00756011\n\t"
        "cmp               ebx, 0x0d\n\t"
        "%{disp8%} jl        LAB__addr_0x00756018\n"
        "LAB__addr_0x00756011:\n\t"
        "pop               esi\n\t"
        "xor.s             eax, eax\n\t"
        "pop               ebx\n\t"
        "ret               0x000c\n"
        "LAB__addr_0x00756018:\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "mov.s             ecx, esi\n\t"
        "call              dword ptr [eax + 0x48]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00756059\n\t"
        "xor.s             eax, eax\n\t"
        "%{disp32%} mov      al, byte ptr [esi + 0x000000f2]\n\t"
        "cmp.s             eax, ebx\n\t"
        "%{disp8%} je        LAB__addr_0x00756059\n\t"
        "mov               edx, dword ptr [esi]\n\t"
        "push              eax\n\t"
        "mov.s             ecx, esi\n\t"
        "call              dword ptr [edx + 0x48]\n\t"
        "mov.s             ecx, eax\n\t"
        "add               ecx, 0x00000610\n\t"
        "call              ?DecrementNumOfDisciples@TownStats@@QAEXW4VILLAGER_DISCIPLE@@@Z\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "push              ebx\n\t"
        "mov.s             ecx, esi\n\t"
        "call              dword ptr [eax + 0x48]\n\t"
        "mov.s             ecx, eax\n\t"
        "add               ecx, 0x00000610\n\t"
        "call              ?IncrementNumOfDisciples@TownStats@@QAEXW4VILLAGER_DISCIPLE@@@Z\n"
        "LAB__addr_0x00756059:\n\t"
        "test              ebx, ebx\n\t"
        "%{disp8%} je        LAB__addr_0x007560ab\n\t"
        "xor.s             ecx, ecx\n\t"
        "%{disp32%} mov      cx, word ptr [esi + 0x000000e0]\n\t"
        "%{disp32%} lea      edx, dword ptr [ebx * 0x8 + 0x00000000]\n\t"
        "sub.s             edx, ebx\n\t"
        "and               ecx, 0x0000fbff\n\t"
        "or                ecx, 0x200\n\t"
        "%{disp32%} mov      word ptr [esi + 0x000000e0], cx\n\t"
        "%{disp8%} mov       ecx, dword ptr [esi + 0x40]\n\t"
        "mov               eax, dword ptr [ecx]\n\t"
        "%{disp32%} mov      edx, dword ptr [edx * 0x4 + 0x0099a200]\n\t"
        "call              dword ptr [eax + 0xcc]\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "mov.s             ecx, esi\n\t"
        "call              dword ptr [eax + 0x1c]\n\t"
        "%{disp32%} mov      byte ptr [esi + 0x000000f2], bl\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx\n\t"
        "ret               0x000c\n"
        "LAB__addr_0x007560ab:\n\t"
        "%{disp8%} mov       ecx, dword ptr [esi + 0x40]\n\t"
        "and               word ptr [esi + 0x000000e0], -0x0601\n\t"
        "mov               eax, dword ptr [ecx]\n\t"
        "xor.s             edx, edx\n\t"
        "call              dword ptr [eax + 0xcc]\n\t"
        "%{disp32%} mov      byte ptr [esi + 0x000000f2], bl\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000001\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0008)))
uint32_t __fastcall GetDiscipleStateIfInteractedWith__8VillagerFP16GInterfaceStatusP8Villager(struct Object* this, const void* edx, struct GInterfaceStatus* param_1, struct Villager* param_2)
{
    uint32_t result;
    asm volatile (
        "push              ebx\n\t"
        "push              esi\n\t"
        "push              edi\n\t"
        "%{disp8%} mov       edi, dword ptr [esp + 0x14]\n\t"
        "mov.s             esi, ecx\n\t"
        "cmp.s             edi, esi\n\t"
        "%{disp8%} jne       LAB__addr_0x007560fb\n\t"
        "xor.s             eax, eax\n\t"
        "%{disp32%} mov      al, byte ptr [esi + 0x000000f2]\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "pop               ebx\n\t"
        "ret               0x0008\n"
        "LAB__addr_0x007560fb:\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "mov.s             ecx, esi\n\t"
        "call              dword ptr [eax + 0xd4]\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00756168\n\t"
        "%{disp8%} mov       ecx, dword ptr [esp + 0x10]\n\t"
        "mov               edx, dword ptr [ecx]\n\t"
        "call              dword ptr [edx + 0x1c]\n\t"
        "mov.s             ebx, eax\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "mov.s             ecx, esi\n\t"
        "call              dword ptr [eax + 0x1c]\n\t"
        "cmp.s             ebx, eax\n\t"
        "%{disp8%} jne       LAB__addr_0x00756168\n\t"
        "mov               edx, dword ptr [edi]\n\t"
        "mov.s             ecx, edi\n\t"
        "call              dword ptr [edx + 0x1c]\n\t"
        "mov.s             ebx, eax\n\t"
        "mov               eax, dword ptr [esi]\n\t"
        "mov.s             ecx, esi\n\t"
        "call              dword ptr [eax + 0x1c]\n\t"
        "cmp.s             ebx, eax\n\t"
        "%{disp8%} jne       LAB__addr_0x00756168\n\t"
        "mov.s             ecx, esi\n\t"
        "call              ?IsSexuallyActive@Villager@@QAEIXZ\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00756168\n\t"
        "mov.s             ecx, edi\n\t"
        "call              ?IsSexuallyActive@Villager@@QAEIXZ\n\t"
        "test              eax, eax\n\t"
        "%{disp8%} je        LAB__addr_0x00756168\n\t"
        "%{disp8%} mov       edx, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} mov       ecx, dword ptr [edi + 0x28]\n\t"
        "%{disp32%} mov      eax, dword ptr [edx + 0x000001f8]\n\t"
        "cmp               eax, dword ptr [ecx + 0x000001f8]\n\t"
        "%{disp8%} je        LAB__addr_0x00756168\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "mov               eax, 0x00000005\n\t"
        "pop               ebx\n\t"
        "ret               0x0008\n"
        "LAB__addr_0x00756168:\n\t"
        "pop               edi\n\t"
        "pop               esi\n\t"
        "xor.s             eax, eax\n\t"
        "pop               ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_ret))
uint32_t __fastcall ShowDiscipleIcon__8VillagerF17VILLAGER_DISCIPLE(struct Villager* this, const void* edx, enum VILLAGER_DISCIPLE param_1)
{
    asm("{disp8} mov       eax, dword ptr [ecx + 0x40]");                   // 0x00756170    8b4140
    asm("{disp8} mov       ecx, dword ptr [esp + 0x04]");                   // 0x00756173    8b4c2404
    asm("{disp32} mov      dword ptr [_DAT_00eb99e4], eax");                // 0x00756177    a3e499eb00
    asm("{disp8} lea       eax, dword ptr [ecx + -0x01]");                  // 0x0075617c    8d41ff
    asm("cmp               eax, 0x09");                                     // 0x0075617f    83f809
    asm("{disp8} ja        LAB__addr_0x007561fd");                          // 0x00756182    7779
    asm("jmp               dword ptr [eax*4 + 0x756200]");                  // 0x00756184    ff248500627500
    asm("{disp32} mov      dword ptr [_DAT_00eb99e8], 0x00000000");         // 0x0075618b    c705e899eb0000000000
    asm("ret               0x0004");                                        // 0x00756195    c20400
    asm("{disp32} mov      dword ptr [_DAT_00eb99e8], 0x00000001");         // 0x00756198    c705e899eb0001000000
    asm("ret               0x0004");                                        // 0x007561a2    c20400
    asm("{disp32} mov      dword ptr [_DAT_00eb99e8], 0x00000002");         // 0x007561a5    c705e899eb0002000000
    asm("ret               0x0004");                                        // 0x007561af    c20400
    asm("{disp32} mov      dword ptr [_DAT_00eb99e8], 0x00000003");         // 0x007561b2    c705e899eb0003000000
    asm("ret               0x0004");                                        // 0x007561bc    c20400
    asm("{disp32} mov      dword ptr [_DAT_00eb99e8], 0x00000004");         // 0x007561bf    c705e899eb0004000000
    asm("ret               0x0004");                                        // 0x007561c9    c20400
    asm("{disp32} mov      dword ptr [_DAT_00eb99e8], 0x00000006");         // 0x007561cc    c705e899eb0006000000
    asm("ret               0x0004");                                        // 0x007561d6    c20400
    asm("{disp32} mov      dword ptr [_DAT_00eb99e8], 0x00000007");         // 0x007561d9    c705e899eb0007000000
    asm("ret               0x0004");                                        // 0x007561e3    c20400
    asm("{disp32} mov      dword ptr [_DAT_00eb99e8], 0x00000005");         // 0x007561e6    c705e899eb0005000000
    asm("ret               0x0004");                                        // 0x007561f0    c20400
    asm("{disp32} mov      dword ptr [_DAT_00eb99e8], 0x00000008");         // 0x007561f3    c705e899eb0008000000
    asm("LAB__addr_0x007561fd:");
    asm("ret               0x0004");                                        // 0x007561fd    c20400
    // Snippet: jmptbl, [0x00756200, 0x00756228)
    asm(".byte 0x98, 0x61, 0x75, 0x00");      // 0x00756200
    asm(".byte 0xb2, 0x61, 0x75, 0x00");      // 0x00756204
    asm(".byte 0xcc, 0x61, 0x75, 0x00");      // 0x00756208
    asm(".byte 0xbf, 0x61, 0x75, 0x00");      // 0x0075620c
    asm(".byte 0xa5, 0x61, 0x75, 0x00");      // 0x00756210
    asm(".byte 0xe6, 0x61, 0x75, 0x00");      // 0x00756214
    asm(".byte 0x8b, 0x61, 0x75, 0x00");      // 0x00756218
    asm(".byte 0xd9, 0x61, 0x75, 0x00");      // 0x0075621c
    asm(".byte 0xe6, 0x61, 0x75, 0x00");      // 0x00756220
    asm(".byte 0xf3, 0x61, 0x75, 0x00");      // 0x00756224
    __builtin_unreachable();
}

void __fastcall DebugValidateState__8VillagerFv(struct Villager* this)
{
    return;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall ForceMoveVillagerToAbode__8VillagerFP5Abode(struct Villager* this, const void* edx, struct Abode* abode)
{
    asm volatile (
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x14]\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "mov.s              ebx, eax\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ebp, eax\n\t"
        "cmp.s              ebx, ebp\n\t"
        "%{disp8%} je         LAB__addr_0x007562aa\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x0075626a\n\t"
        "push               esi\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?RemoveVillager@Town@@QAEXPAVVillager@@@Z\n"
        "LAB__addr_0x0075626a:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00756284\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x8a0]\n\t"
        "%{disp8%} jmp        LAB__addr_0x0075628e\n"
        "LAB__addr_0x00756284:\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [eax + 0x89c]\n"
        "LAB__addr_0x0075628e:\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x007562aa\n\t"
        "push               esi\n\t"
        "mov.s              ecx, ebp\n\t"
        "call               ?AddVillagerToTown@Town@@QAEIPAVVillager@@@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007562aa:\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?AddVillagerToAbode@Abode@@QAEXPAVVillager@@@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall SetSkeleton__8VillagerFi(struct GameThingWithPos* this, const void* edx, int index)
{
    asm volatile (
        "%{disp32%} mov       al, byte ptr [_villager_byte_0x00da6bc4]\n\t"
        "test               al, 0x01\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x007562f6\n\t"
        "%{disp32%} mov       ecx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "mov.s              bl, al\n\t"
        "or                 bl, 1\n\t"
        "%{disp32%} mov       byte ptr [_villager_byte_0x00da6bc4], bl\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "mov                eax, 0x000001ff\n\t"
        "cmp.s              edx, eax\n\t"
        "%{disp8%} jg         LAB__addr_0x007562ed\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x007562ed:\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + eax * 0x4 + 0x04]\n\t"
        "%{disp32%} mov       dword ptr [_villager_uint_0x00da6bc0], eax\n"
        "LAB__addr_0x007562f6:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp8%} mov        cl, byte ptr [esp + 0x14]\n\t"
        "xor.s              edx, edx\n\t"
        "%{disp32%} mov       dx, word ptr [esi + 0x000000b4]\n\t"
        "and                ecx, 0x01\n\t"
        "shl                ecx, 6\n\t"
        "and                edx, 0x0000ffbf\n\t"
        "or.s               ecx, edx\n\t"
        "%{disp32%} mov       word ptr [esi + 0x000000b4], cx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x4a0]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00756348\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x00756429\n\t"
        "%{disp32%} mov       edx, dword ptr [_villager_uint_0x00da6bc0]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "push               edx\n\t"
        "push               edx\n\t"
        "call               dword ptr [eax + 0xf4]\n\t"
        "%{disp32%} jmp       LAB__addr_0x00756429\n"
        "LAB__addr_0x00756348:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       edi, dword ptr [ecx + 0x00000138]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8d0]\n\t"
        "cmp.s              eax, edi\n\t"
        "%{disp8%} jae        LAB__addr_0x007563b5\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x00756429\n\t"
        "%{disp8%} mov        edx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [edx + 0x0000020c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       edi, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "%{disp8%} jl         LAB__addr_0x00756381\n\t"
        "cmp                eax, dword ptr [edi]\n\t"
        "%{disp8%} jl         LAB__addr_0x00756383\n"
        "LAB__addr_0x00756381:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x00756383:\n\t"
        "%{disp8%} mov        ebx, dword ptr [edi + eax * 0x4 + 0x04]\n\t"
        "%{disp32%} mov       eax, dword ptr [edx + 0x00000208]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jl         LAB__addr_0x00756395\n\t"
        "cmp                eax, dword ptr [edi]\n\t"
        "%{disp8%} jl         LAB__addr_0x00756397\n"
        "LAB__addr_0x00756395:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x00756397:\n\t"
        "%{disp32%} mov       edx, dword ptr [edx + 0x00000204]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} mov        eax, dword ptr [edi + eax * 0x4 + 0x04]\n\t"
        "%{disp8%} jl         LAB__addr_0x007563a9\n\t"
        "cmp                edx, dword ptr [edi]\n\t"
        "%{disp8%} jl         LAB__addr_0x007563ab\n"
        "LAB__addr_0x007563a9:\n\t"
        "xor.s              edx, edx\n"
        "LAB__addr_0x007563ab:\n\t"
        "mov                ebp, dword ptr [ecx]\n\t"
        "%{disp8%} mov        edx, dword ptr [edi + edx * 0x4 + 0x04]\n\t"
        "push               ebx\n\t"
        "push               eax\n\t"
        "%{disp8%} jmp        LAB__addr_0x00756423\n"
        "LAB__addr_0x007563b5:\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x40]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00756429\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x2\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x60c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       ecx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "%{disp8%} jl         LAB__addr_0x007563d6\n\t"
        "cmp                eax, dword ptr [ecx]\n\t"
        "%{disp8%} jl         LAB__addr_0x007563d8\n"
        "LAB__addr_0x007563d6:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x007563d8:\n\t"
        "%{disp8%} mov        ebx, dword ptr [ecx + eax * 0x4 + 0x04]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x60c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       ecx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "%{disp8%} jl         LAB__addr_0x007563f6\n\t"
        "cmp                eax, dword ptr [ecx]\n\t"
        "%{disp8%} jl         LAB__addr_0x007563f8\n"
        "LAB__addr_0x007563f6:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x007563f8:\n\t"
        "%{disp8%} mov        edi, dword ptr [ecx + eax * 0x4 + 0x04]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x60c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       edx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "%{disp8%} jl         LAB__addr_0x00756416\n\t"
        "cmp                eax, dword ptr [edx]\n\t"
        "%{disp8%} jl         LAB__addr_0x00756418\n"
        "LAB__addr_0x00756416:\n\t"
        "xor.s              eax, eax\n"
        "LAB__addr_0x00756418:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                ebp, dword ptr [ecx]\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + eax * 0x4 + 0x04]\n\t"
        "push               ebx\n\t"
        "push               edi\n"
        "LAB__addr_0x00756423:\n\t"
        "call               dword ptr [ebp + 0xf4]\n"
        "LAB__addr_0x00756429:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8d0]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetScaleForAge@Villager@@QAEXK@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

extern void __fastcall InsertMapObject__6ObjectFv(struct Object* this) __attribute__((noinline));

void __fastcall InsertMapObject__8VillagerFv(struct Object* this)
{
    __attribute__((musttail)) return InsertMapObject__6ObjectFv(this);
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsReachable__8VillagerFv(struct Object* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0075646e\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0075646e:\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x000000e0]\n\t"
        "and                cl, 0x04\n\t"
        "cmp                cl, 0x04\n\t"
        "%{disp8%} jne        LAB__addr_0x00756480\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00756480:\n\t"
        "%{disp8%} mov        dl, byte ptr [esi + 0x24]\n\t"
        "and                dl, 0x04\n\t"
        "cmp                dl, 0x04\n\t"
        "%{disp8%} jne        LAB__addr_0x0075648f\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0075648f:\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x0000008c]\n\t"
        "xor.s              eax, eax\n\t"
        "cmp                cl, -0x14\n\t"
        "setne              al\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((prefer_neg_sbb, no_tail_call))
uint32_t __fastcall ValidForPlaceInHand__8VillagerFP16GInterfaceStatus(struct Object* this, const void* edx, struct GInterfaceStatus* param_1)
{
    typedef uint32_t (__attribute__((thiscall)) *fn_t)(struct Object*);
    fn_t fn = ((fn_t*)(*(void**)this))[0x530 / 4];
    return fn(this) != 0;
}

bool __fastcall CanBecomeAPhysicsObject__8VillagerFv(struct Object* this)
{
    typedef bool (__fastcall *fn_t)(struct Object*);
    fn_t fn = ((fn_t*)(*(void**)this))[0x530 / 4];
    __attribute__((musttail)) return fn(this);
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0018)))
uint32_t __fastcall AddResource__8VillagerF13RESOURCE_TYPEUlP16GInterfaceStatusbRC9MapCoordsi(struct GameThing* this, const void* edx, enum RESOURCE_TYPE param_1, uint32_t param_2, struct GInterfaceStatus* param_3, bool param_4, const struct MapCoords* param_5, int param_6)
{
    uint32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "test               eax, eax\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x007564ff\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "call               ?PickupFood@Villager@@QAEXF@Z\n\t"
        "%{disp8%} mov        al, byte ptr [esp + 0x14]\n\t"
        "test               al, al\n\t"
        "%{disp8%} je         LAB__addr_0x00756512\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x69c]\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret                0x0018\n"
        "LAB__addr_0x007564ff:\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00756512\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x0c]\n\t"
        "push               0x0\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PickupWood@Villager@@QAEXFE@Z\n"
        "LAB__addr_0x00756512:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, expand_movzx))
enum VILLAGER_STATES __fastcall LookAtPreviousStateReactToTownEmergency__8VillagerFv(struct Villager* this)
{
    return this->base.super.action.states[LIVING_ACTION_INDEX_PREVIOUS];
}

void __fastcall SetTown__8VillagerFP4Town(struct Villager* this, const void* edx, struct Town* town)
{
    this->town = town;
}

bool32_t __fastcall ScriptInCrowd__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               0x1\n\t"
        "call               @IsReadyForNewAnimation__6LivingFUl@12\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075655e\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetStateAnim@Living@@QAEXXZ\n\t"
        "%{disp32%} mov       word ptr [esi + 0x00000090], 0x0000\n\t"
        "LAB__addr_0x0075655e:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall SaveLanded__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    return 1;
}

bool32_t __fastcall LoadLanded__8VillagerFR10GameOSFile(struct Villager* this, const void* edx, struct GameOSFile* param_1)
{
    return 1;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
int __fastcall CallIntoAnimationFunction__8VillagerF15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    int result;
    asm volatile (
        "sub                esp, 0x10\n\t"
        "xor.s              eax, eax\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008c]\n\t"
        "push               edi\n\t"
        "lea                eax, dword ptr [eax + eax * 0x8]\n\t"
        "shl                eax, 4\n\t"
        "%{disp32%} lea       eax, dword ptr [eax + 0x00d09208]\n\t"
        "mov.s              edx, eax\n\t"
        "mov                ecx, dword ptr [edx]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} mov        edi, dword ptr [edx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], edi\n\t"
        "%{disp8%} mov        edi, dword ptr [edx + 0x08]\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], edx\n\t"
        "%{disp8%} je         LAB__addr_0x0075660f\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        edi, dword ptr [eax + 0x08]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x1c]\n\t"
        "push               eax\n\t"
        "push               0x1\n\t"
        "add.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edi\n\t"
        "call               edx\n\t"
        "cmp                eax, -0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00756612\n\t"
        "xor.s              ecx, ecx\n\t"
        "%{disp32%} mov       cx, word ptr [esi + 0x000000e0]\n\t"
        "pop                edi\n\t"
        "and                ecx, 0x0000efff\n\t"
        "or                 ecx, 0x800\n\t"
        "%{disp32%} mov       word ptr [esi + 0x000000e0], cx\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0075660f:\n\t"
        "or                 eax, -0x1\n"
        "LAB__addr_0x00756612:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
int __fastcall CallOutofAnimationFunction__8VillagerF15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    int result;
    asm volatile (
        "sub                esp, 0x10\n\t"
        "push               ebx\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x20]\n\t"
        "mov.s              esi, ecx\n\t"
        "mov.s              eax, edi\n\t"
        "and                eax, 0x000000ff\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "shl                ecx, 3\n\t"
        "sub.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax * 0x4 + 0x00db9f68]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x007566a9\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [esi + 0x0000008c]\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x8]\n\t"
        "shl                ecx, 4\n\t"
        "%{disp32%} lea       eax, dword ptr [ecx + 0x00d09208]\n\t"
        "mov.s              edx, eax\n\t"
        "mov                ecx, dword ptr [edx]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} mov        ebx, dword ptr [edx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [edx + 0x08]\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edx\n\t"
        "%{disp8%} je         LAB__addr_0x007566a9\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        ebx, dword ptr [eax + 0x08]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x0c]\n\t"
        "push               edi\n\t"
        "push               0x0\n\t"
        "add.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], eax\n\t"
        "call               edx\n\t"
        "cmp                eax, -0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007566ac\n\t"
        "or                 byte ptr [esi + 0xe1], 0x18\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x10\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007566a9:\n\t"
        "or                 eax, -0x1\n"
        "LAB__addr_0x007566ac:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x10"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
struct MissionaryControl* __fastcall __ct__17MissionaryControlFv(struct MissionaryControl* this)
{
    void* dummy;
    struct MissionaryControl* result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ??0GameThing@@QAE@XZ\n\t"
        "xor.s              edi, edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x14], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x18], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x1c], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x20], edi\n\t"
        "mov.s              ecx, esi\n\t"
        "mov                dword ptr [esi], 0x008c31a0\n\t"
        "call               ?SetToZero@GameThingWithPos@@QAEXXZ\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x30], edi\n\t"
        "pop                edi\n\t"
        "mov                dword ptr [esi], 0x0099a424\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
struct GPlayer* __fastcall GetPlayer__17MissionaryControlFv(struct GameThing* this)
{
    struct GPlayer* result;
    asm volatile (
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x2c]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075670c\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "%{disp8%} jmp        dword ptr [eax + 0x1c]\n"
        "LAB__addr_0x0075670c:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

const char* __fastcall GetText__17MissionaryControlFv(struct GameThingWithPos* this)
{
    return (const char*)0xc236b8;
}

uint32_t __fastcall GetSaveType__17MissionaryControlFv(struct GameThing* this)
{
    return 0x9e;
}

char* __fastcall GetDebugText__17MissionaryControlFv(struct GameThing* this)
{
    return (char*)0xc236cc;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall __dt__17MissionaryControlFUi(struct Base* this, const void* edx, uint32_t param_1)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ??1MissionaryControl@@UAE@XZ\n\t"
        "test               byte ptr [esp + 0x08], 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0075675a\n\t"
        "push               0x34\n\t"
        "push               esi\n\t"
        "call               ??3Base@@SAXPAXK@Z\n\t"
        "add                esp, 0x08\n"
        "LAB__addr_0x0075675a:\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0008)))
struct MissionaryControl* __fastcall __ct__17MissionaryControlFP8VillagerP7GPlayer(struct MissionaryControl* this, const void* edx, struct Villager* param_1, struct GPlayer* param_2)
{
    struct MissionaryControl* result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ??0GameThing@@QAE@XZ\n\t"
        "xor.s              edi, edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x14], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x18], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x1c], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x20], edi\n\t"
        "mov.s              ecx, esi\n\t"
        "mov                dword ptr [esi], 0x008c31a0\n\t"
        "call               ?SetToZero@GameThingWithPos@@QAEXXZ\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x0c]\n\t"
        "push               edi\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x30], edi\n\t"
        "push               0x27\n\t"
        "push               esi\n\t"
        "mov                dword ptr [esi], 0x0099a424\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x28], eax\n\t"
        "call               ?CreateReaction@Reaction@@SAPAV1@PAVGameThingWithPos@@EPAVGPlayer@@H@Z\n\t"
        "add                esp, 0x10\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x2c], eax\n\t"
        "pop                edi\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_ret))
void __fastcall __dt__17MissionaryControlFv(struct MissionaryControl* this)
{
    asm volatile (
        "mov                dword ptr [ecx], 0x0099a424\n\t"
        "%{disp32%} jmp       _jmp_addr_0x0056fa80"
        : : "c"(this) : "eax", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((no_callee_saves))
float __fastcall GetImpressiveValue__17MissionaryControlFv(struct MissionaryControl* this)
{
    float result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007567d7\n\t"
        "%{disp32%} fld       dword ptr [_GameBlock_ARRAY_00d189d8 + 0x18b4]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x28]\n\t"
        "%{disp32%} fmul      dword ptr [eax + 0x000003a0]\n\t"
        "ret\n"
        "LAB__addr_0x007567d7:\n\t"
        "%{disp32%} fld       dword ptr [_rdata_float0p0]"
        : "=t"(result) :: "eax", "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
void __fastcall Process__17MissionaryControlFv(struct MissionaryControl* this)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "push               edi\n\t"
        "xor.s              edi, edi\n\t"
        "cmp.s              ecx, edi\n\t"
        "%{disp8%} je         LAB__addr_0x007567f2\n\t"
        "cmp                dword ptr [esi + 0x2c], edi\n\t"
        "%{disp8%} jne        LAB__addr_0x007567fd\n"
        "LAB__addr_0x007567f2:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xc]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007567fd:\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0x2c]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00756845\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "cmp                byte ptr [eax + 0x000000f2], 0x07\n\t"
        "%{disp8%} jne        LAB__addr_0x00756845\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x2c]\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0x2c]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00756831\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xc]\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x28], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x2c], edi\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00756831:\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xfc]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00756845:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0xc]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x2c]\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x28], edi\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00756865\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x2c]\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "push               edi\n\t"
        "call               dword ptr [edx + 0xc]\n"
        "LAB__addr_0x00756865:\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x2c], edi\n\t"
        "pop                edi\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall ToBeDeleted__17MissionaryControlFi(struct Base* this, const void* edx, int param_1)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x0075688e\n\t"
        "cmp                byte ptr [ecx + 0x000000f2], 0x07\n\t"
        "%{disp8%} jne        LAB__addr_0x0075688e\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "call               ?SetVillagerDisciple@Villager@@QAEIPAVGameThing@@W4VILLAGER_DISCIPLE@@H@Z\n"
        "LAB__addr_0x0075688e:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ToBeDeleted@GameThingWithPos@@UAEXH@Z\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall Load__17MissionaryControlFR10GameOSFile(struct GameThing* this, const void* edx, struct GameOSFile* param_1)
{
    uint32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "call               ?Load@GameThingWithPos@@QAEIAAVGameOSFile@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007568d2\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x28]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "add                esi, 0x2c\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007568d2:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
uint32_t __fastcall Save__17MissionaryControlFR10GameOSFile(struct GameThing* this, const void* edx, struct GameOSFile* param_1)
{
    uint32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "call               ?Save@GameThingWithPos@@UAEXPAUGameOSFile@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00756912\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x2c]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00756912:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008)))
float __fastcall GetImpressiveValue__17MissionaryControlFP6LivingP8Reaction(struct GameThingWithPos* this, const void* edx, struct Living* param_1, struct Reaction* param_2)
{
    float result;
    asm volatile (
        "push               ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x0c]\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x10]\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?GetDefaultReactionMultiplier@Reaction@@QAEMPAVLiving@@@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetImpressiveValue@MissionaryControl@@QAEMXZ\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "add                esi, 0x14\n\t"
        "%{disp8%} lea        eax, dword ptr [edi + 0x14]\n\t"
        "push               esi\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x18]\n\t"
        "push               eax\n\t"
        "call               ?GetDistanceInMetres@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x18]\n\t"
        "add                esp, 0x08\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?GetInfo@Reaction@@QBEPAVReactionInfo@@XZ\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x2c]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "call               ?DistanceChangeToBelief@GBelief@@SAMMM@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x18]\n\t"
        "add                esp, 0x08\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?GetBoredomMultiplier@GameThingWithPos@@QAEHPAVReaction@@@Z\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x10]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "%{disp8%} fmul       dword ptr [esp + 0x0c]\n\t"
        "pop                ebx"
        : "=t"(result) :: "eax", "ecx", "edx", "memory"
    );
    return result;
}

void __fastcall FUN_00756990__8VillagerFv(struct MissionaryControl* this)
{
    return;
}

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__17MissionaryControl = {
    .pTypeDescriptor = &__RTTITypeDescriptor__17MissionaryControl,
    .numContainedBases = 0x00000003,
    .where = {
        .mdisp = 0x00000000,
        .pdisp = 0xFFFFFFFF,
        .vdisp = 0x00000000,
    },
    .attributes = 0x0000000,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassArray __RTTIBaseClassArray__17MissionaryControl = {
    .arrayOfBaseClassDescriptors = {
        &__RTTIBaseClassDescriptor__17MissionaryControl,
        &__RTTIBaseClassDescriptor__16GameThingWithPos,
        &__RTTIBaseClassDescriptor__9GameThing,
        &__RTTIBaseClassDescriptor__4Base,
        NULL,
    }
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__17MissionaryControl = {
  .signature = 0x00000000,
  .attributes = 0x00000000,
  .numBaseClasses = 0x00000004,
  .pBaseClassArray = &__RTTIBaseClassArray__17MissionaryControl,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTICompleteObjectLocator __RTTICompleteObjectLocator__17MissionaryControl = {
  .signature = 0x00000000,
  .offset = 0x00000000,
  .cdOffset = 0x00000000,
  .pTypeDescriptor = &__RTTITypeDescriptor__17MissionaryControl,
  .pClassDescriptor = &__RTTIClassHierarchyDescriptor__17MissionaryControl,
};

const struct RTTICompleteObjectLocator* const p__RTTICompleteObjectLocator__17MissionaryControl = &__RTTICompleteObjectLocator__17MissionaryControl;

const struct GameThingWithPosVftable __vt__17MissionaryControl = {
  Serialise__4BaseFR7Archive,
  __dt__17MissionaryControlFUi,
  Delete__4BaseFv,
  ToBeDeleted__17MissionaryControlFi,
  Get3DSoundPos__16GameThingWithPosFP7LHPoint,
  CleanUpForSerialisation__4BaseFv,
  Dump__4BaseFv,
  GetPlayer__17MissionaryControlFv,
  SetPlayer__9GameThingFP7GPlayer,
  CalculateInfluence__9GameThingFRC9MapCoords,
  RemoveDance__9GameThingFv,
  IsAvailable__9GameThingFv,
  IsCreature__9GameThingFP8Creature,
  IsCreature__9GameThingFv,
  IsCreatureNotTooNear__9GameThingFP8Creature,
  GetDrawImportance__9GameThingFv,
  GetMaxAlignmentChangePerGameTurn__9GameThingFv,
  GetComputerSeen__9GameThingFv,
  GetTown__9GameThingFv,
  GetVillagerActivityDesire__9GameThingFP8Villager,
  SetVillagerActivity__9GameThingFP8Villager,
  UpdateVillagerActivityEffect__9GameThingFP8Villager,
  MaintainSpell__9GameThingFP5Spellf,
  UpdateSpellInfo__9GameThingFP5SpellP15PSysProcessInfo,
  GetRadius__9GameThingFv,
  Get2DRadius__9GameThingFv,
  GetPlayerWhoLastPickedMeUp__9GameThingFv,
  GetPlayerWhoLastDroppedMe__9GameThingFv,
  IsFootpathLink__9GameThingFv,
  GetFootpathLink__9GameThingFv,
  AddFootpathLink__9GameThingFP9GFootpath,
  GetNearestPathTo__9GameThingFRC9MapCoordsfi,
  UseFootpathIfNecessary__16GameThingWithPosFP6LivingRC9MapCoordsUc,
  AddFootpath__9GameThingFP9GFootpath,
  RemoveFootpath__9GameThingFP9GFootpath,
  JustAddResource__9GameThingF13RESOURCE_TYPEUlb,
  JustRemoveResource__9GameThingF13RESOURCE_TYPEUlPb,
  JustGetResource__9GameThingF13RESOURCE_TYPEUlPb,
  GetResource__9GameThingF13RESOURCE_TYPE,
  AddResource__9GameThingF13RESOURCE_TYPEUlP16GInterfaceStatusbRC9MapCoordsi,
  RemoveResource__9GameThingF13RESOURCE_TYPEUlP16GInterfaceStatusPb,
  CastCreature__9GameThingFv,
  CastPlayer__9GameThingFv,
  CastOneOffSpellSeed__9GameThingFv,
  CastAbode__9GameThingFv,
  CastMultiMapFixed__9GameThingFv,
  CastSpellIcon__9GameThingFv,
  CastTree__9GameThingFv,
  IsDeletedOnNewMap__9GameThingFv,
  GetNumberOfInstanceForGlobalList__9GameThingFv,
  GetTownArtifactValue__9GameThingFv,
  CanBecomeArtifact__9GameThingFv,
  DrawInHand__9GameThingFP16GInterfaceStatus,
  IsFunctional__9GameThingFv,
  GetDebugText__17MissionaryControlFv,
  GetSampleForAttack__9GameThingFv,
  GetGuidanceResourceType__9GameThingFv,
  GetShowNeedsPos__9GameThingFUlP9MapCoords,
  Load__17MissionaryControlFR10GameOSFile,
  Save__17MissionaryControlFR10GameOSFile,
  GetSaveType__17MissionaryControlFv,
  SaveExtraData__9GameThingFR10GameOSFile,
  ResolveLoad__9GameThingFv,
  SetPos__16GameThingWithPosFRC9MapCoords,
  GetPos__16GameThingWithPosFv,
  GetArrivePos__16GameThingWithPosFv,
  PhysicsEditorCreate__16GameThingWithPosFi,
  GetCreatureBeliefType__16GameThingWithPosFv,
  GetCreatureBeliefListType__16GameThingWithPosFv,
  GetCitadel__16GameThingWithPosFv,
  GetOrigin__16GameThingWithPosFv,
  GetLife__16GameThingWithPosFv,
  GetScale__16GameThingWithPosFv,
  SetScale__16GameThingWithPosFf,
  GetPower__16GameThingWithPosCFv,
  GetPSysPower__16GameThingWithPosCFv,
  GetSpeedInMetres__16GameThingWithPosCFv,
  SetSpeedInMetres__16GameThingWithPosFfi,
  GetRunningSpeedInMetres__16GameThingWithPosFv,
  GetDistanceFromObject__16GameThingWithPosFRC9MapCoords,
  GetDefaultSpeedInMetres__16GameThingWithPosFv,
  SetHeight__16GameThingWithPosFf,
  SetMaxHeight__16GameThingWithPosFf,
  GetMaxHeight__16GameThingWithPosFv,
  GetPSysBeamTargetPos__16GameThingWithPosFP7LHPoint,
  GetSpeedInMetresPerSecond__16GameThingWithPosCFv,
  SetSpeedInMetresPerSecond__16GameThingWithPosFfi,
  GetRunningSpeedInMetresPerSecond__16GameThingWithPosFv,
  GetDefaultSpeedInMetresPerSecond__16GameThingWithPosFv,
  IsAnimate__16GameThingWithPosFv,
  GetMovementDirection__16GameThingWithPosFP7LHPoint,
  GetPhysicsMovementDirection__16GameThingWithPosFP7LHPoint,
  GetInteractPos__16GameThingWithPosFv,
  IsMoving__16GameThingWithPosCFv,
  IsObjectInMap__16GameThingWithPosFv,
  IsDrowning__16GameThingWithPosFv,
  IsCannotBePickedUp__16GameThingWithPosCFv,
  GetOverwritePickUpToolTip__16GameThingWithPosFv,
  IsStompable__16GameThingWithPosFv,
  IsAvailableForStateChange__16GameThingWithPosFv,
  IsInteractable__16GameThingWithPosFv,
  GetOverwriteInteractableToolTip__16GameThingWithPosFv,
  GetOverwriteDropToolTip__16GameThingWithPosFv,
  GetOverwriteTapToolTip__16GameThingWithPosFv,
  IsCastShadowAtNight__16GameThingWithPosFv,
  CleanupWhenDeleted__16GameThingWithPosFi,
  GetImpressiveType__16GameThingWithPosFv,
  GetImpressiveIntensity__16GameThingWithPosF15IMPRESSIVE_TYPE,
  GetImpressiveValue__17MissionaryControlFP6LivingP8Reaction,
  GetUpdateOfBoredomValue__16GameThingWithPosFP8ReactionP16GameThingWithPos,
  IsTown__16GameThingWithPosFv,
  IsTown__16GameThingWithPosFP8Creature,
  IsActivityObjectWhichAngerAppliesTo__16GameThingWithPosFP8Creature,
  IsActivityObjectWhichCompassionAppliesTo__16GameThingWithPosFP8Creature,
  IsActivityObjectWhichPlayfulnessAppliesTo__16GameThingWithPosFP8Creature,
  IsTownBelongingToAnotherPlayer__16GameThingWithPosFP8Creature,
  TrueFunction__16GameThingWithPosFv,
  FalseFunction__16GameThingWithPosFv,
  IsNotLiving__16GameThingWithPosFv,
  IsSuitableForCreatureActivity__16GameThingWithPosFv,
  IsTownCentre__16GameThingWithPosFv,
  IsTotemStatue__16GameThingWithPosFv,
  IsTownDesireFlag__16GameThingWithPosFv,
  IsRock__16GameThingWithPosFP8Creature,
  IsRock__16GameThingWithPosFv,
  IsSpellDispenser__16GameThingWithPosFv,
  IsMist__16GameThingWithPosFv,
  IsQueryIcon__16GameThingWithPosFv,
  IsStreetLight__16GameThingWithPosFv,
  IsStreetLantern__16GameThingWithPosFv,
  IsAbode__16GameThingWithPosFv,
  IsField__16GameThingWithPosFP8Creature,
  IsField__16GameThingWithPosFv,
  IsBuildingMaterial__16GameThingWithPosFv,
  IsMagicFireBall__16GameThingWithPosFv,
  IsSuitableForCreatureAction__16GameThingWithPosFv,
  IsCitadelHeart__16GameThingWithPosFv,
  IsDamaged__16GameThingWithPosFv,
  CanBeHealedByCreature__16GameThingWithPosFP8Creature,
  CanBeEatenByCreature__16GameThingWithPosFP8Creature,
  CanCreatureEatMe__16GameThingWithPosFP8Creature,
  CanBeAttackedByCreature__16GameThingWithPosFP8Creature,
  CanBeFrighteningToCreature__16GameThingWithPosFP8Creature,
  CanBeHelpedByCreature__16GameThingWithPosFP8Creature,
  CanBePlayedWithByCreature__16GameThingWithPosFP8Creature,
  CanBeImpressedByCreature__16GameThingWithPosFP8Creature,
  CanBeInspectedByCreature__16GameThingWithPosFP8Creature,
  CanBePoodUponByCreature__16GameThingWithPosFP8Creature,
  CanBeBefriendedByCreature__16GameThingWithPosFP8Creature,
  CanBeSleptNextToByCreature__16GameThingWithPosFP8Creature,
  CanBePickedUpByCreature__16GameThingWithPosFP8Creature,
  CanBeStrokedByCreature__16GameThingWithPosFP8Creature,
  CanBeKissedByCreature__16GameThingWithPosFP8Creature,
  CanBeSetOnFire__16GameThingWithPosFP8Creature,
  CanBeStompedOnByCreature__16GameThingWithPosFP8Creature,
  CanBeThrownByCreature__16GameThingWithPosFP8Creature,
  CanBeGivenToVillager__16GameThingWithPosFP8Creature,
  CanBePutInAStoragePit__16GameThingWithPosFP8Creature,
  CanBeDestroyedByStoning__16GameThingWithPosFP8Creature,
  CanBeStonedAndEatenByCreature__16GameThingWithPosFP8Creature,
  CanBeExaminedByCreature__16GameThingWithPosFP8Creature,
  CanBeFoughtByCreature__16GameThingWithPosFP8Creature,
  CanReceiveGifts__16GameThingWithPosFP8Creature,
  CanActAsAContainer__16GameThingWithPosFP8Creature,
  IsBeingBuilt__16GameThingWithPosFP8Creature,
  NeedsRepair__16GameThingWithPosFP8Creature,
  IsOnFire__16GameThingWithPosFP8Creature,
  IsNotOnFire__16GameThingWithPosFP8Creature,
  CanBeUsedForBuilding__16GameThingWithPosFP8Creature,
  IsMushroom__16GameThingWithPosFP8Creature,
  CanBeUsedForRepair__16GameThingWithPosFP8Creature,
  CanBeGivenToTown__16GameThingWithPosFP8Creature,
  CanBeUsedToHoldWater__16GameThingWithPosFP8Creature,
  CanBePutInFoodPile__16GameThingWithPosFP8Creature,
  CanBePutInWoodPile__16GameThingWithPosFP8Creature,
  CanHaveMagicFoodCastOnMe__16GameThingWithPosFP8Creature,
  CanHaveMagicWoodCastOnMe__16GameThingWithPosFP8Creature,
  CanBeBroughtBackToCitadel__16GameThingWithPosFP8Creature,
  IsVillager__16GameThingWithPosFP8Creature,
  IsVillagerFarFromHome__16GameThingWithPosFP8Creature,
  IsVillagerInTownWithoutManyBreeders__16GameThingWithPosFP8Creature,
  IsVillagerNotWorshipping__16GameThingWithPosFP8Creature,
  IsVillagerBelongingToOtherPlayer__16GameThingWithPosFP8Creature,
  IsCow__16GameThingWithPosFP8Creature,
  CanBePoodOn__16GameThingWithPosFP8Creature,
  IsVillagerWhoHasNotBeenImpressedRecently__16GameThingWithPosFP8Creature,
  IsVillagerWhoHasNotBeenDancedWithRecently__16GameThingWithPosFP8Creature,
  DoesVillagerBelongToATownWhichIsAlreadyImpressed__16GameThingWithPosFP8Creature,
  DoesTotemBelongToATownWhichIsVeryImpressedIndeed__16GameThingWithPosFP8Creature,
  IsDominantCreature__16GameThingWithPosFP8Creature,
  CanBeDancedWith__16GameThingWithPosFP8Creature,
  IsAggressive__16GameThingWithPosFP8Creature,
  IsStoragePit__16GameThingWithPosFP8Creature,
  IsWorshipSite__16GameThingWithPosFP8Creature,
  IsWorshipSite__16GameThingWithPosFv,
  GetWorshipSite__16GameThingWithPosFv,
  IsWorkshop__16GameThingWithPosFP8Creature,
  IsWorkshop__16GameThingWithPosFv,
  IsBuildingWhichIsBeingBuilt__16GameThingWithPosFP8Creature,
  IsStoragePitWithFoodInIt__16GameThingWithPosFP8Creature,
  IsFieldWhichNeedsWatering__16GameThingWithPosFP8Creature,
  IsFieldWithFoodInIt__16GameThingWithPosFP8Creature,
  IsFieldBelongingToAnotherPlayer__16GameThingWithPosFP8Creature,
  IsStoragePitBelongingToAnotherPlayer__16GameThingWithPosFP8Creature,
  IsStoragePitBelongingToMyPlayer__16GameThingWithPosFP8Creature,
  BenefitsFromHavingWaterSprinkledOnIt__16GameThingWithPosFP8Creature,
  IsTree__16GameThingWithPosFv,
  IsTree__16GameThingWithPosFP8Creature,
  IsTreeNotTooNearPlannedForest__16GameThingWithPosFP8Creature,
  IsTreeBigEnoughForCreature__16GameThingWithPosFP8Creature,
  IsAFoodPileOutsideStoragePit__16GameThingWithPosFP8Creature,
  IsAWoodPileOutsideStoragePit__16GameThingWithPosFP8Creature,
  IsDoingSomethingInteresting__16GameThingWithPosFP8Creature,
  CanBeUsedForBuildingHomeByCreature__16GameThingWithPosFP8Creature,
  IsPickupableRock__16GameThingWithPosFP8Creature,
  IsCitadelPart__16GameThingWithPosFP8Creature,
  IsCitadelPart__16GameThingWithPosFv,
  IsPlayingFootball__16GameThingWithPosFP8Creature,
  IsPlayingFootballAndMySideHasJustScored__16GameThingWithPosFP8Creature,
  IsPlayingFootballAndOtherSideHasJustScored__16GameThingWithPosFP8Creature,
  CanBeBroughtHomeByCreature__16GameThingWithPosFP8Creature,
  IsAnimalBelongingToOtherPlayer__16GameThingWithPosFP8Creature,
  IsOneOffSpellBelongingToOtherPlayer__16GameThingWithPosFP8Creature,
  IsOneOffSpellAggressive__16GameThingWithPosFP8Creature,
  IsOneOffSpellCompassionate__16GameThingWithPosFP8Creature,
  IsOneOffSpellPlayful__16GameThingWithPosFP8Creature,
  IsOneOffSpellToRestoreHealth__16GameThingWithPosFP8Creature,
  CanBeKickedByCreature__16GameThingWithPosFP8Creature,
  CanBeStolenByCreature__16GameThingWithPosFP8Creature,
  IsStealableByCreature__16GameThingWithPosFP8Creature,
  IsStealableSpell__16GameThingWithPosFP8Creature,
  IsStealableScaffold__16GameThingWithPosFP8Creature,
  IsTownBelongingToOtherPlayer__16GameThingWithPosFP8Creature,
  IsTotemWithStealableSpell__16GameThingWithPosFP8Creature,
  IsCreatureAvailableForJointActivity__16GameThingWithPosFP8Creature,
  IsCreatureNotAvailableForJointActivity__16GameThingWithPosFP8Creature,
  IsToyAwayFromHome__16GameThingWithPosFP8Creature,
  IsToy__16GameThingWithPosFP8Creature,
  IsToyBall__16GameThingWithPosFP8Creature,
  IsToyDie__16GameThingWithPosFP8Creature,
  IsToyCuddly__16GameThingWithPosFP8Creature,
  IsLiving__16GameThingWithPosFv,
  IsLiving__16GameThingWithPosFP8Creature,
  IsFence__16GameThingWithPosFv,
  IsSpellIcon__16GameThingWithPosFv,
  NothingScareyNearMe__16GameThingWithPosFP8Creature,
  CanBeUsedForThrowingDamageByCreature__16GameThingWithPosFP8Creature,
  IsCreatureWhoSeemsFriendly__16GameThingWithPosFP8Creature,
  CanBeThrownInTheSeaPlayfully__16GameThingWithPosFP8Creature,
  GetCreatureMimicType__16GameThingWithPosFv,
  GetHowMuchCreatureWantsToLookAtMe__16GameThingWithPosFv,
  IsFlock__16GameThingWithPosCFv,
  IsDance__16GameThingWithPosCFv,
  IsReward__16GameThingWithPosCFv,
  IsScriptContainer__16GameThingWithPosCFv,
  IsWeather__16GameThingWithPosCFv,
  IsSpell__16GameThingWithPosCFv,
  IsDeletedWhenReleasedFromScript__16GameThingWithPosFv,
  IsMobileWallHug__16GameThingWithPosCFv,
  IsActive__16GameThingWithPosCFv,
  IsObjectTurningTooFastForCameraToFollowSmoothly__16GameThingWithPosFv,
  CalculateWhereIWillBeAfterNSeconds__16GameThingWithPosFfP7LHPoint,
  AttitudeToCreatureEating__16GameThingWithPosFv,
  GetText__17MissionaryControlFv,
  CalculateDesireForFood__16GameThingWithPosFv,
  CalculateDesireForRest__16GameThingWithPosFv,
  CalculatePeopleHidingIndicator__16GameThingWithPosFv,
  GetHeight__16GameThingWithPosFv,
  IsReadyForNewScriptAction__16GameThingWithPosFv,
  ForDrawFXGetNumVertices__16GameThingWithPosFv,
  ForDrawFXGetVertexPos__16GameThingWithPosFlP7LHPoint,
  SetInScript__16GameThingWithPosFi,
  SetControlledByScript__16GameThingWithPosFi,
  GetDeathReason__16GameThingWithPosFv,
  IsInScript__16GameThingWithPosFv,
  IsMaleVillager__16GameThingWithPosFv,
  IsFemaleVillager__16GameThingWithPosFv,
  IsAnimal__16GameThingWithPosFv,
  IsAChild__16GameThingWithPosFv,
  IsHouse__16GameThingWithPosFv,
  IsObject__16GameThingWithPosCFv,
  IsFootball__16GameThingWithPosFv,
  IsCitadel__16GameThingWithPosFv,
  IsForest__16GameThingWithPosFv,
  IsMobileObject__16GameThingWithPosFv,
  IsMobileStatic__16GameThingWithPosFv,
  IsAnyKindOfTree__16GameThingWithPosFv,
  IsDeadTree__16GameThingWithPosFv,
  IsPileFood__16GameThingWithPosFv,
  IsFeature__16GameThingWithPosFv,
  IsScriptMarker__16GameThingWithPosFv,
  IsScriptHighlight__16GameThingWithPosFv,
  IsWonder__16GameThingWithPosFv,
  IsInfluenceRing__16GameThingWithPosFv,
  IsPuzzleGame__16GameThingWithPosFv,
  IsScaffold__16GameThingWithPosFv,
  IsSkeleton__16GameThingWithPosCFv,
  IsPoisoned__16GameThingWithPosFv,
  IsSpeedUp__16GameThingWithPosFv,
  IsParticleContainer__16GameThingWithPosFv,
  IsSacrificeAltar__16GameThingWithPosFv,
  IsPot__16GameThingWithPosFv,
  IsComputerPlayer__16GameThingWithPosFv,
  CanBeThrownByPlayer__16GameThingWithPosFv,
  SetSkeleton__16GameThingWithPosFi,
  IsSpellSeed__16GameThingWithPosFv,
  IsSpellShield__16GameThingWithPosFv,
  IsPileResource__16GameThingWithPosFv,
  IsScriptTimer__16GameThingWithPosFv,
  CreateBuildingSite__16GameThingWithPosFv,
  GetQueryFirstEnumText__16GameThingWithPosFv,
  GetQueryLastEnumText__16GameThingWithPosFv,
  GetFOVHelpMessageSet__16GameThingWithPosFv,
  GetFOVHelpCondition__16GameThingWithPosFv,
  GetScriptObjectType__16GameThingWithPosFv,
  GetFacingDirection__16GameThingWithPosFv,
  SetAffectedByWind__16GameThingWithPosFi,
  GetReactionPower__16GameThingWithPosFv,
  GetSpellCastPos__16GameThingWithPosFv,
  CleanUpBeforeReset__16GameThingWithPosFv,
};

__attribute__((aligned(8))) struct RTTITypeDescriptor __RTTITypeDescriptor__17MissionaryControl = {
    &__vt__9type_info,
    NULL,
    ".?AVMissionaryControl@@"
};

__attribute__((aligned(4))) char s_MissionaryControl_00c236b8[] = "MissionaryControl";
__attribute__((aligned(4))) char s_MissionaryControl_00c236cc[] = "MissionaryControl:";


void __fastcall MoveToObjectValidate__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?FUN_00756990@Villager@@QAEXXZ\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x60]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x007569c0\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007569c0\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x60], 0x00000000\n\t"
        "LAB__addr_0x007569c0:\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

void __fastcall MoveOnStructureValidate__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?FUN_00756990@Villager@@QAEXXZ\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000c0]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x007569f5\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007569f5\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000c0], 0x00000000\n\t"
        "LAB__addr_0x007569f5:\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

void __fastcall ReactionValidate__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00756a3d\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00756a3d\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000094]\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + 0x24]\n\t"
        "lea                eax, dword ptr [eax + eax * 0x4]\n\t"
        "lea                edx, dword ptr [eax + eax * 0x4]\n\t"
        "%{disp32%} mov       eax, dword ptr [edx * 0x4 + 0x00d4f6d8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00756a44\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000bc]\n\t"
        "test               byte ptr [eax + 0x24], 0x04\n\t"
        "%{disp8%} je         LAB__addr_0x00756a44\n\t"
        "LAB__addr_0x00756a3d:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PopFromPrevious@Villager@@QAEXXZ\n\t"
        "LAB__addr_0x00756a44:\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

void __fastcall SexValidate__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000118]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00756a71\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00756a71\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], 0x00000000\n\t"
        "LAB__addr_0x00756a71:\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

void __fastcall WallhugAndReactionValidate__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?FUN_00756990@Villager@@QAEXXZ\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ReactionValidate@Villager@@QAEXXZ\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

void __fastcall ClosestObjectValidate__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000118]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00756ac1\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00756ac1\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], 0x00000000\n\t"
        "LAB__addr_0x00756ac1:\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
struct MapCoords* __fastcall GetFinalDestPos__8VillagerFP9MapCoords(struct Living* this, const void* edx, struct MapCoords* param_1)
{
    struct MapCoords* result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "push               eax\n\t"
        "call               @GetFinalDestPos__6LivingFP9MapCoords@12"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0008)))
uint32_t __fastcall ThrowObjectFromHand__8VillagerFP16GInterfaceStatusi(struct Object* this, const void* edx, struct GInterfaceStatus* param_1, int param_2)
{
    uint32_t result;
    asm volatile (
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x14]\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x10]\n\t"
        "%{disp8%} je         LAB__addr_0x00756b21\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x1c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00756b14\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x1c]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?IsMemberOfThisPlayer@GPlayer@@QAEIPAVGInterfaceStatus@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00756b21\n"
        "LAB__addr_0x00756b14:\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetVillagerDisciple@Villager@@QAEIPAVGameThing@@W4VILLAGER_DISCIPLE@@H@Z\n"
        "LAB__addr_0x00756b21:\n\t"
        "push               edi\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ThrowObjectFromHand@Object@@UAEIPAVGInterfaceStatus@@H@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsDrowning__8VillagerFv(struct GameThingWithPos* this)
{
    bool32_t result;
    asm volatile (
        "%{disp32%} mov       dl, byte ptr [ecx + 0x0000008c]\n\t"
        "xor.s              eax, eax\n\t"
        "cmp                dl, 0x10\n\t"
        "sete               al"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
void __fastcall SetLife__8VillagerFf(struct Object* this, const void* edx, float param_1)
{
    asm("push               esi");                                           // 0x00756b40    56
    asm("mov.s              esi, ecx");                                      // 0x00756b41    8bf1
    asm("mov                eax, dword ptr [esi]");                          // 0x00756b43    8b06
    asm("call               dword ptr [eax + 0x11c]");                       // 0x00756b45    ff901c010000
    asm("{disp32} fcomp     dword ptr [__real@3f333333]");                   // 0x00756b4b    d81d38b28a00
    asm("fnstsw             ax");                                            // 0x00756b51    dfe0
    asm("test               ah, 0x41");                                      // 0x00756b53    f6c441
    asm("{disp8} jne        LAB__addr_0x00756b80");                          // 0x00756b56    7528
    asm("{disp8} fld        dword ptr [esp + 0x08]");                        // 0x00756b58    d9442408
    asm("{disp32} fcomp     dword ptr [__real@3f333333]");                   // 0x00756b5c    d81d38b28a00
    asm("fnstsw             ax");                                            // 0x00756b62    dfe0
    asm("test               ah, 0x01");                                      // 0x00756b64    f6c401
    asm("{disp8} je         LAB__addr_0x00756b80");                          // 0x00756b67    7417
    asm("mov.s              ecx, esi");                                      // 0x00756b69    8bce
    asm("call               ?FUN_00756bc0@Villager@@UAEXM@Z");               // 0x00756b6b    e850000000
    asm("{disp8} mov        eax, dword ptr [esp + 0x08]");                   // 0x00756b70    8b442408
    asm("push               eax");                                           // 0x00756b74    50
    asm("mov.s              ecx, esi");                                      // 0x00756b75    8bce
    asm("call               @SetLife__6ObjectFf@12");                        // 0x00756b77    e8c435eeff
    asm("pop                esi");                                           // 0x00756b7c    5e
    asm("ret                0x0004");                                        // 0x00756b7d    c20400
    asm("LAB__addr_0x00756b80:");
    asm("mov                edx, dword ptr [esi]");                          // 0x00756b80    8b16
    asm("mov.s              ecx, esi");                                      // 0x00756b82    8bce
    asm("call               dword ptr [edx + 0x11c]");                       // 0x00756b84    ff921c010000
    asm("{disp32} fcomp     dword ptr [__real@3f333333]");                   // 0x00756b8a    d81d38b28a00
    asm("fnstsw             ax");                                            // 0x00756b90    dfe0
    asm("test               ah, 0x01");                                      // 0x00756b92    f6c401
    asm("{disp8} je         LAB__addr_0x00756baf");                          // 0x00756b95    7418
    asm("{disp8} fld        dword ptr [esp + 0x08]");                        // 0x00756b97    d9442408
    asm("{disp32} fcomp     dword ptr [__real@3f333333]");                   // 0x00756b9b    d81d38b28a00
    asm("fnstsw             ax");                                            // 0x00756ba1    dfe0
    asm("test               ah, 0x41");                                      // 0x00756ba3    f6c441
    asm("{disp8} jne        LAB__addr_0x00756baf");                          // 0x00756ba6    7507
    asm("mov.s              ecx, esi");                                      // 0x00756ba8    8bce
    asm("call               LAB__addr_0x00756bd0");                          // 0x00756baa    e821000000
    asm("LAB__addr_0x00756baf:");
    asm("{disp8} mov        eax, dword ptr [esp + 0x08]");                   // 0x00756baf    8b442408
    asm("push               eax");                                           // 0x00756bb3    50
    asm("mov.s              ecx, esi");                                      // 0x00756bb4    8bce
    asm("call               @SetLife__6ObjectFf@12");                        // 0x00756bb6    e88535eeff
    asm("pop                esi");                                           // 0x00756bbb    5e
}

__attribute__((no_ret))
void __fastcall FUN_00756bc0__8VillagerFf(struct Villager* this, const void* edx, float param_1)
{
    asm("mov                eax, dword ptr [ecx]");                          // 0x00756bc0    8b01
    asm("call               dword ptr [eax + 0x48]");                        // 0x00756bc2    ff5048
    asm("test               eax, eax");                                      // 0x00756bc5    85c0
    asm("{disp8} je         LAB__addr_0x00756bcf");                          // 0x00756bc7    7406
    asm("{disp32} inc       dword ptr [eax + 0x00000714]");                  // 0x00756bc9    ff8014070000
    asm("LAB__addr_0x00756bcf:");
    asm("ret");                                                              // 0x00756bcf    c3
    asm("LAB__addr_0x00756bd0:");
    asm("mov                eax, dword ptr [ecx]");                          // 0x00756bd0    8b01
    asm("call               dword ptr [eax + 0x48]");                        // 0x00756bd2    ff5048
    asm("test               eax, eax");                                      // 0x00756bd5    85c0
    asm("{disp8} je         LAB__addr_0x00756bdf");                          // 0x00756bd7    7406
    asm("dec                dword ptr [eax + 0x00000714]");                  // 0x00756bd9    ff8814070000
    asm("LAB__addr_0x00756bdf:");
    asm("ret");                                                              // 0x00756bdf    c3
    __builtin_unreachable();
}

void __fastcall FindChildrenAndOrphanThem__8VillagerFv(struct Villager* this)
{
    void* dummy;
    asm volatile (
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              ebp, eax\n\t"
        "test               ebp, ebp\n\t"
        "%{disp8%} je         LAB__addr_0x00756c4e\n\t"
        "push               ebx\n\t"
        "%{disp32%} mov       ebx, dword ptr [ebp + 0x00000754]\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} je         LAB__addr_0x00756c29\n\t"
        "LAB__addr_0x00756bfb:\n\t"
        "%{disp32%} mov       esi, dword ptr [ebx + 0x000000a0]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x00756c1f\n\t"
        "LAB__addr_0x00756c05:\n\t"
        "cmp                dword ptr [esi + 0x00000100], edi\n\t"
        "%{disp8%} jne        LAB__addr_0x00756c15\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?MakeChildOrphaned@Villager@@QAEIPAV1@@Z\n\t"
        "LAB__addr_0x00756c15:\n\t"
        "%{disp32%} mov       esi, dword ptr [esi + 0x000000e4]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x00756c05\n\t"
        "LAB__addr_0x00756c1f:\n\t"
        "%{disp32%} mov       ebx, dword ptr [ebx + 0x0000009c]\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} jne        LAB__addr_0x00756bfb\n\t"
        "LAB__addr_0x00756c29:\n\t"
        "%{disp32%} mov       esi, dword ptr [ebp + 0x00000768]\n\t"
        "test               esi, esi\n\t"
        "pop                ebx\n\t"
        "%{disp8%} je         LAB__addr_0x00756c4e\n\t"
        "LAB__addr_0x00756c34:\n\t"
        "cmp                dword ptr [esi + 0x00000100], edi\n\t"
        "%{disp8%} jne        LAB__addr_0x00756c44\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?MakeChildOrphaned@Villager@@QAEIPAV1@@Z\n\t"
        "LAB__addr_0x00756c44:\n\t"
        "%{disp32%} mov       esi, dword ptr [esi + 0x000000e4]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x00756c34\n\t"
        "LAB__addr_0x00756c4e:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsMovingForAnimation__8VillagerFv(struct Living* this)
{
    bool32_t result;
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [ecx + 0x0000008c]\n\t"
        "mov.s              ecx, eax\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx * 0x4 + 0x00db9e8c]"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}


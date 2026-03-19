#include "AbodeInfo.h"

__attribute__((aligned(8)))
struct RTTITypeDescriptor __RTTITypeDescriptor__10GAbodeInfo = {
    .pVFTable = &__vt__9type_info,
    .spare = 0,
    .name = ".?AVGAbodeInfo@@",
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__10GAbodeInfo = {
    .pTypeDescriptor = &__RTTITypeDescriptor__10GAbodeInfo,
    .numContainedBases = 0x00000004,
    .where = {
        .mdisp = 0x00000000,
        .pdisp = 0xFFFFFFFF,
        .vdisp = 0x00000000,
    },
    .attributes = 0x0000000,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassArray __RTTIBaseClassArray__10GAbodeInfo = {
    .arrayOfBaseClassDescriptors = {
        (void*)0x009a6368,
        &__RTTIBaseClassDescriptor__18GMultiMapFixedInfo,
        &__RTTIBaseClassDescriptor__11GObjectInfo,
        &__RTTIBaseClassDescriptor__9GBaseInfo,
        &__RTTIBaseClassDescriptor__4Base,
        NULL,
    }
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__10GAbodeInfo = {
  .signature = 0x00000000,
  .attributes = 0x00000000,
  .numBaseClasses = 0x00000005,
  .pBaseClassArray = &__RTTIBaseClassArray__10GAbodeInfo,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTICompleteObjectLocator __RTTICompleteObjectLocator__10GAbodeInfo = {
  .signature = 0x00000000,
  .offset = 0x00000000,
  .cdOffset = 0x00000000,
  .pTypeDescriptor = &__RTTITypeDescriptor__10GAbodeInfo,
  .pClassDescriptor = &__RTTIClassHierarchyDescriptor__10GAbodeInfo,
};

__attribute__((no_callee_saves, trailing_asm(".byte 0x90, 0x25, 0xa2, 0x03")))
void __cdecl crt_global_destruction_register_for_AbodeInfos__10GAbodeInfoFv(void)
{
    asm("push 0x004012e0");
    asm("call _atexit");
    // atexit(dynamic_atexit_destructor_for_AbodeInfos__10GAbodeInfoFv);
    __asm__("pop ecx");                      // 0x004012da    59
    // SEH?
}

void __cdecl dynamic_atexit_destructor_for_AbodeInfos__10GAbodeInfoFv(void)
{
    asm volatile (
        "%{disp32%} mov       cl, byte ptr [_abode_info_bool_00c3c680]\n\t"
        "mov                al, 0x01\n\t"
        "test               al, cl\n\t"
        "%{disp8%} jne        LAB__addr_0x00401312\n\t"
        "push               esi\n\t"
        "or.s               cl, al\n\t"
        "push               edi\n\t"
        "%{disp32%} mov       byte ptr [_abode_info_bool_00c3c680], cl\n\t"
        "mov                esi, OFFSET _AbodeInfos + 0x93 * 0x1c8;\n\t"
        "mov                edi, 0x93\n\t"
        "LAB__addr_0x00401300:\n\t"
        "sub                esi, 0x1c8\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x00436960\n\t"
        "dec                edi\n\t"
        "%{disp8%} jne        LAB__addr_0x00401300\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "LAB__addr_0x00401312:"
        :  :  : "eax", "ecx", "edx", "memory"
    );
}

void __fastcall __dt__10GAbodeInfoFUi(struct Base* this, const void* edx, uint32_t param_1)
{
    asm("push               esi");                                          // 0x00401320    56
    asm("mov.s              esi, ecx");                                     // 0x00401321    8bf1
    asm("call               _jmp_addr_0x00436960");                         // 0x00401323    e838560300
    asm("test               byte ptr [esp + 0x08], 0x01");                  // 0x00401328    f644240801
    asm("{disp8} je         LAB__addr_0x0040133d");                         // 0x0040132d    740e
    asm("push               0x000001c8");                                   // 0x0040132f    68c8010000
    asm("push               esi");                                          // 0x00401334    56
    asm("call               ??3Base@@SAXPAXK@Z");                         // 0x00401335    e836560300
    asm("add                esp, 0x08");                                    // 0x0040133a    83c408
    asm("LAB__addr_0x0040133d:");
    asm("mov.s              eax, esi");                                     // 0x0040133d    8bc6
    asm("pop                esi");                                          // 0x0040133f    5e
}

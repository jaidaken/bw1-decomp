#include "PlannedAbode.h"

__attribute__((aligned(8)))
struct RTTITypeDescriptor __RTTITypeDescriptor__12PlannedAbode = {
    .pVFTable = &__vt__9type_info,
    .spare = 0,
    .name = ".?AVPlannedAbode@@",
};

__attribute__((aligned(4)))
char debug_text_PlannedAbode[] = "Planned Abode\0";

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__12PlannedAbode = {
    .pTypeDescriptor = &__RTTITypeDescriptor__12PlannedAbode,
    .numContainedBases = 0x00000004,
    .where = {
        .mdisp = 0x00000000,
        .pdisp = 0xFFFFFFFF,
        .vdisp = 0x00000000,
    },
    .attributes = 0x0000000,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassArray __RTTIBaseClassArray__12PlannedAbode = {
    .arrayOfBaseClassDescriptors = {
        (void*)0x009a64b0,
        &__RTTIBaseClassDescriptor__20PlannedMultiMapFixed,
        &__RTTIBaseClassDescriptor__16GameThingWithPos,
        &__RTTIBaseClassDescriptor__9GameThing,
        &__RTTIBaseClassDescriptor__4Base,
        NULL,
    }
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__12PlannedAbode = {
  .signature = 0x00000000,
  .attributes = 0x00000000,
  .numBaseClasses = 0x00000005,
  .pBaseClassArray = &__RTTIBaseClassArray__12PlannedAbode,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTICompleteObjectLocator __RTTICompleteObjectLocator__12PlannedAbode = {
  .signature = 0x00000000,
  .offset = 0x00000000,
  .cdOffset = 0x00000000,
  .pTypeDescriptor = &__RTTITypeDescriptor__12PlannedAbode,
  .pClassDescriptor = &__RTTIClassHierarchyDescriptor__12PlannedAbode,
};

struct Town* __fastcall GetTown__12PlannedAbodeFv(struct GameThing* this)
{
    return ((struct PlannedAbode*)this)->town;
}

uint32_t __fastcall GetSaveType__12PlannedAbodeFv(struct GameThing* this)
{
    return 0x61;
}

char* __fastcall GetDebugText__12PlannedAbodeFv(struct GameThing* this)
{
    return debug_text_PlannedAbode;
}

__attribute__((no_callee_saves))
void __fastcall __dt__12PlannedAbodeFUi(struct Base* this, const void* edx, uint32_t param_1)
{
    asm volatile (
        "push esi\n\t"
        "mov.s esi, ecx\n\t"
        "call _jmp_addr_0x0056fa80\n\t"
        "test byte ptr [esp + 0x08], 0x01\n\t"
        "%{disp8%} je 0f\n\t"
        "push 0x4c\n\t"
        "push esi\n\t"
        "call ??3Base@@SAXPAXK@Z\n\t"
        "add esp, 0x08\n"
        "0:\n\t"
        "mov.s eax, esi\n\t"
        "pop esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

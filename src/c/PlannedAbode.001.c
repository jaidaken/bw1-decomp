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

__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void __fastcall __dt__12PlannedAbodeFUi(struct Base* this, const void* edx, uint32_t param_1)
{}

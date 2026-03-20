#include "PlannedMultiMapFixed.h"

__attribute__((aligned(8)))
struct RTTITypeDescriptor __RTTITypeDescriptor__20PlannedMultiMapFixed = {
    .pVFTable = &__vt__9type_info,
    .spare = 0,
    .name = ".?AVPlannedMultiMapFixed@@",
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__20PlannedMultiMapFixed = {
    .pTypeDescriptor = &__RTTITypeDescriptor__20PlannedMultiMapFixed,
    .numContainedBases = 0x00000003,
    .where = {
        .mdisp = 0x00000000,
        .pdisp = 0xFFFFFFFF,
        .vdisp = 0x00000000,
    },
    .attributes = 0x0000000,
};

float __fastcall GetScale__20PlannedMultiMapFixedFv(struct GameThingWithPos* this)
{
    return ((const struct PlannedMultiMapFixed*)this)->scale;
}

__attribute__((no_callee_saves, msvc6_regalloc, trailing_asm("call dword ptr [?GetTransportInfo@LHConnection@@QAE?AW4LH_RETURN@@PAVLHTransportInfo@@H@Z]")))
void __fastcall SetScale__20PlannedMultiMapFixedFf(struct GameThingWithPos* this, const void* edx, float scale)
{
    ((struct PlannedMultiMapFixed*)this)->scale = scale;
}

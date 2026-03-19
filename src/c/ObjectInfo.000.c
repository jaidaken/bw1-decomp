#include "ObjectInfo.h"

#include "Object.h"

__attribute__((aligned(8)))
struct RTTITypeDescriptor __RTTITypeDescriptor__11GObjectInfo = {
    .pVFTable = &__vt__9type_info,
    .spare = 0,
    .name = ".?AVGObjectInfo@@",
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__11GObjectInfo = {
    .pTypeDescriptor = &__RTTITypeDescriptor__11GObjectInfo,
    .numContainedBases = 0x00000002,
    .where = {
        .mdisp = 0x00000000,
        .pdisp = 0xFFFFFFFF,
        .vdisp = 0x00000000,
    },
    .attributes = 0x0000000,
};

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetMesh__11GObjectInfoCF10TRIBE_TYPE(const struct GObjectInfo* this, const void* edx, enum TRIBE_TYPE tribe)
{
    return 0;
}

__attribute__((no_callee_saves, trailing_asm("mov eax, 0xfffff9cc\npop ecx\nadd.s eax, ecx\nmov eax, dword ptr [eax]\njmp eax")))
enum ALIGNMENT_TYPE __fastcall GetAlignmentType__11GObjectInfoCFv(const struct GObjectInfo* this)
{
    return this->alignmentType;
}

__attribute__((no_callee_saves, trailing_asm("mov eax, 0xfffffa5c\npop ecx\nadd.s eax, ecx\nmov eax, dword ptr [eax]\njmp eax")))
enum FOOD_TYPE __fastcall GetFoodType__11GObjectInfoCFv(const struct GObjectInfo* this)
{
    return this->food_type;
}

const char* __fastcall GetDebugText__11GObjectInfoCFv(const struct GBaseInfo* this)
{
    return ((const struct GObjectInfo*)this)->debugString;
}
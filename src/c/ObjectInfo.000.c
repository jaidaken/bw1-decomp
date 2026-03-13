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

enum ALIGNMENT_TYPE __fastcall GetAlignmentType__11GObjectInfoCFv(const struct GObjectInfo* this)
{
    enum ALIGNMENT_TYPE result = this->alignmentType;
    asm volatile (
        "ret\n\t"
        "mov                eax, 0xfffff9cc\n\t"
        "pop                ecx\n\t"
        "add.s              eax, ecx\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "jmp                eax"
        :: "a"(result) : "memory"
    );
    __builtin_unreachable();
}

enum FOOD_TYPE __fastcall GetFoodType__11GObjectInfoCFv(const struct GObjectInfo* this)
{
    enum FOOD_TYPE result = this->food_type;
    asm volatile (
        "ret\n\t"
        "mov                eax, 0xfffffa5c\n\t"
        "pop                ecx\n\t"
        "add.s              eax, ecx\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "jmp                eax"
        :: "a"(result) : "memory"
    );
    __builtin_unreachable();
}

const char* __fastcall GetDebugText__11GObjectInfoCFv(const struct GBaseInfo* this)
{
    return ((const struct GObjectInfo*)this)->debugString;
}
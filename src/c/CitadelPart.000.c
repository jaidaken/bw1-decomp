#include "CitadelPart.h"

// CitadelPart::Process - return 1
uint32_t __fastcall Process__11CitadelPartFv(struct Object* this)
{
    return 1;
}

// CitadelPart::ConvertToPlanned - return 0 (xor.s)
__attribute__((XOR32rr_REV))
struct PlannedMultiMapFixed* __fastcall ConvertToPlanned__11CitadelPartFv(struct MultiMapFixed* this)
{
    return (struct PlannedMultiMapFixed*)0;
}

// CitadelPart::Get3DType - return 1
enum LH3DObject__ObjectType __fastcall Get3DType__11CitadelPartFv(struct Object* this)
{
    return 1;
}

// CitadelPart::SaveObject - return 0 with ret 0x0008 (xor.s, thiscall with 2 stack args)
__attribute__((XOR32rr_REV))
uint32_t __fastcall SaveObject__11CitadelPartFR8LHOSFileRC9MapCoords(struct Object* this, const void* edx, struct LHOSFile* param_1, const struct MapCoords* param_2)
{
    return 0;
}

// CitadelPart::GetSaveType - return 0x36
uint32_t __fastcall GetSaveType__11CitadelPartFv(struct GameThing* this)
{
    return 0x36;
}

// CitadelPart::GetDebugText - return string address
char* __fastcall GetDebugText__11CitadelPartFv(struct GameThing* this)
{
    return (char*)0x009ceb34;
}

// CitadelPart::ShouldFootpathsGoRound - return 1 (bool but 32-bit in original)
uint32_t __fastcall ShouldFootpathsGoRound__11CitadelPartFv_impl(struct Object* this) asm("?ShouldFootpathsGoRound@CitadelPart@@UAE_NXZ");
uint32_t __fastcall ShouldFootpathsGoRound__11CitadelPartFv_impl(struct Object* this)
{
    return 1;
}

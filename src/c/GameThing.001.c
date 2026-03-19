#include "GameThing.h"

float __fastcall GetDrawImportance__9GameThingFv(struct GameThing* this)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

float __fastcall GetRadius__9GameThingFv(struct GameThing* this)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

float __fastcall Get2DRadius__9GameThingFv(struct GameThing* this)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsFootpathLink__9GameThingFv(struct GameThing* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
struct GFootpathLink* __fastcall GetFootpathLink__9GameThingFv(struct GameThing* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetNearestPathTo__9GameThingFRC9MapCoordsfi(struct GameThing* this, const void* edx, const struct MapCoords* param_1, float param_2, int param_3)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall AddFootpath__9GameThingFP9GFootpath(struct GameThing* this, const void* edx, struct GFootpath* param_1)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall RemoveFootpath__9GameThingFP9GFootpath(struct GameThing* this, const void* edx, struct GFootpath* param_1)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetResource__9GameThingF13RESOURCE_TYPE(struct GameThing* this, const void* edx, enum RESOURCE_TYPE type)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall AddResource__9GameThingF13RESOURCE_TYPEUlP16GInterfaceStatusbRC9MapCoordsi(struct GameThing* this, const void* edx, enum RESOURCE_TYPE type, uint32_t param_2, struct GInterfaceStatus* param_3, bool param_4, const struct MapCoords* coords, int param_6)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall RemoveResource__9GameThingF13RESOURCE_TYPEUlP16GInterfaceStatusPb(struct GameThing* this, const void* edx, enum RESOURCE_TYPE type, uint32_t param_2, struct GInterfaceStatus* param_3, bool* param_4)
{
    return 0;
}

__attribute__((XOR32rr_REV))
struct Abode* __fastcall CastAbode__9GameThingFv(struct GameThing* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
struct MultiMapFixed* __fastcall CastMultiMapFixed__9GameThingFv(struct GameThing* this)
{
    return 0;
}

uint16_t __fastcall GetNumberOfInstanceForGlobalList__9GameThingFv(struct GameThing* this)
{
    return 1;
}

float __fastcall GetTownArtifactValue__9GameThingFv(struct GameThing* this)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

__attribute__((XOR32rr_REV, prefer_xor8, no_bool_mask))
bool __fastcall CanBecomeArtifact__9GameThingFv(struct GameThing* this)
{
    return false;
}

void __fastcall DrawInHand__9GameThingFP16GInterfaceStatus(struct GameThing* this, const void* edx, struct GInterfaceStatus* param_1)
{
    return;
}

__attribute__((no_ret))
bool32_t __fastcall IsFunctional__9GameThingFv(struct GameThing* this)
{
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "%{disp8%} jmp dword ptr [eax + 0x2c]"
        : : "c"(this) : "eax", "edx", "memory"
    );
    __builtin_unreachable();
}

void __fastcall ResolveLoad__9GameThingFv(struct GameThing* this)
{
    return;
}

#include "Abode.h"

extern const char debug_text_Abode[7];

__attribute__((MOV32rr_REV))
struct Abode* __fastcall CastAbode__5AbodeFv(struct GameThing* this)
{
    return ((struct Abode*)this);
}

__attribute__((expand_movzx))
bool32_t __fastcall GetShouldNotBeAddedToPlanned__5AbodeFv(struct MultiMapFixed* this)
{
    return (*(uint8_t*)((char*)this + offsetof(struct Abode, field_0x7c)) >> 2) & 1;
}

void __fastcall SetShouldNotBeAddedToPlanned__5AbodeFi(struct MultiMapFixed* this, const void* edx, bool value)
{
    asm(
        "{disp8} mov        al, byte ptr [esp + 0x04]\n" // 0x00401660    8a442404
        "{disp8} mov        dl, byte ptr [ecx + 0x7c]\n" // 0x00401664    8a517c
        "and                al, 0x01                 \n" // 0x00401667    2401
        "shl                al, 2                    \n" // 0x00401669    c0e002
        "and                dl, -0x05                \n" // 0x0040166c    80e2fb
        "or.s               al, dl                   \n" // 0x0040166f    0ac2
        "{disp8} mov        byte ptr [ecx + 0x7c], al\n" // 0x00401671    88417c
    );
}

void __fastcall RestartBeingFunctional__5AbodeFv(struct Abode* this)
{
}

void __fastcall SetTown__5AbodeFP4Town(struct MultiMapFixed* this, const void* edx, struct Town* town)
{
    ((struct Abode*)this)->town = town;
}

__attribute__((no_callee_saves, suppress_fp_imm, msvc6_regalloc))
bool32_t __fastcall IsRepaired__5AbodeFv(struct MultiMapFixed* this)
{
    extern const float __opaque_rdata_float1p0 asm("_rdata_float1p0");
    typedef float (__attribute__((thiscall)) *GetRepairFn)(const struct MultiMapFixed*);
    GetRepairFn fn = ((GetRepairFn*)(*(void**)this))[0x884 / 4];
    float level = fn(this);
    return !(level < __opaque_rdata_float1p0);
}

__attribute__((no_callee_saves, suppress_fp_imm, msvc6_regalloc))
bool32_t __fastcall IsBuilt__5AbodeFv(struct MultiMapFixed* this)
{
    extern const float __opaque_rdata_float1p0 asm("_rdata_float1p0");
    uint8_t flags = *(uint8_t*)((char*)this + 0x58);
    if ((flags & 0x02) == 0x02)
        return 0;
    typedef float (__attribute__((thiscall)) *GetBuildFn)(const struct MultiMapFixed*);
    GetBuildFn fn = ((GetBuildFn*)(*(void**)this))[0x880 / 4];
    float progress = fn(this);
    if (progress < __opaque_rdata_float1p0)
        return 0;
    return 1;
}

__attribute__((XOR32rr_REV))
bool __fastcall CausesTownEmergencyIfDamaged__5AbodeFv(struct Abode* this)
{
    return false;
}

struct LH3DMesh* __fastcall GetDestructionMesh__5AbodeFv(struct MultiMapFixed* this)
{
    return ((struct Abode*)this)->destruction_mesh;
}

bool32_t __fastcall IsAbode__5AbodeFv(struct GameThingWithPos* this)
{
    return true;
}

bool32_t __fastcall IsCastShadowAtNight__5AbodeFv(struct GameThingWithPos* this)
{
    return true;
}

struct Town * __fastcall GetTown__5AbodeFv(struct GameThing* this)
{
    return ((struct Abode*)this)->town;
}

uint32_t __fastcall GetCreatureBeliefType__5AbodeFv(struct GameThingWithPos* this)
{
    return 3;
}

uint32_t __fastcall GetCreatureMimicType__5AbodeFv(struct GameThingWithPos* this)
{
    return 5;
}

uint32_t __fastcall GetOrigin__5AbodeFv(struct GameThingWithPos* this)
{
    return 1;
}

__attribute__((no_callee_saves))
struct MapCoords* __fastcall GetArrivePos__5AbodeFv(struct GameThingWithPos* this, const void* edx, struct MapCoords* coords)
{
    struct MapCoords* result;
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "push esi\n\t"
        "%{disp8%} mov esi, dword ptr [esp + 0x08]\n\t"
        "push esi\n\t"
        "call dword ptr [eax + 0x864]\n\t"
        "mov.s eax, esi\n\t"
        "pop esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall IsHouse__5AbodeFv(struct GameThingWithPos* this)
{
    return true;
}

uint32_t __fastcall GetSaveType__5AbodeFv(struct GameThing* this)
{
    return 7;
}

char* __fastcall GetDebugText__5AbodeFv(struct GameThing* this)
{
    return (char*)0x009c7fb4;
}

__attribute__((msvc6_sdtor("??1Abode@@UAE@XZ,??3Base@@SAXPAXK@Z,196,")))
void __fastcall __dt__5AbodeFUi(struct Base* this, const void* edx, uint32_t param_1)
{}

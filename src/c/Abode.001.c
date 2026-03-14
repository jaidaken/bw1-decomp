#include "Abode.h"

extern const char debug_text_Abode[7];

__attribute__((MOV32rr_REV))
struct Abode* __fastcall CastAbode__5AbodeFv(struct GameThing* this)
{
    return ((struct Abode*)this);
}

#if HAS_EXPAND_MOVZX
__attribute__((expand_movzx))
bool32_t __fastcall GetShouldNotBeAddedToPlanned__5AbodeFv(struct MultiMapFixed* this)
{
    return (*((uint8_t*)this + 0x7c) >> 2) & 1;
}
#else
bool32_t __fastcall GetShouldNotBeAddedToPlanned__5AbodeFv(struct MultiMapFixed* this)
{
    bool32_t result;
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        al, byte ptr [ecx + 0x7c]\n\t"
        "shr                eax, 2\n\t"
        "and                eax, 0x01"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}
#endif

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

bool __fastcall IsRepaired__5AbodeFv(struct MultiMapFixed* this)
{
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "call dword ptr [eax + 0x884]\n\t"
        "%{disp32%} fcomp dword ptr [_rdata_float1p0]\n\t"
        "fnstsw ax\n\t"
        "test ah, 0x01\n\t"
        "%{disp8%} jne 0f\n\t"
        "mov eax, 0x00000001\n\t"
        "ret\n"
        "0:\n\t"
        "xor.s eax, eax\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

bool __fastcall IsBuilt__5AbodeFv(struct MultiMapFixed* this)
{
    asm volatile (
        "%{disp8%} mov al, byte ptr [ecx + 0x58]\n\t"
        "and al, 0x02\n\t"
        "cmp al, 0x02\n\t"
        "%{disp8%} je 0f\n\t"
        "mov edx, dword ptr [ecx]\n\t"
        "call dword ptr [edx + 0x880]\n\t"
        "%{disp32%} fcomp dword ptr [_rdata_float1p0]\n\t"
        "fnstsw ax\n\t"
        "test ah, 0x01\n\t"
        "%{disp8%} jne 0f\n\t"
        "mov eax, 0x00000001\n\t"
        "ret\n"
        "0:\n\t"
        "xor.s eax, eax\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
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

struct MapCoords* __fastcall GetArrivePos__5AbodeFv(struct GameThingWithPos* this, const void* edx, struct MapCoords* coords)
{
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "push esi\n\t"
        "%{disp8%} mov esi, dword ptr [esp + 0x08]\n\t"
        "push esi\n\t"
        "call dword ptr [eax + 0x864]\n\t"
        "mov.s eax, esi\n\t"
        "pop esi\n\t"
        "ret 0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
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

void __fastcall __dt__5AbodeFUi(struct Base* this, const void* edx, uint32_t param_1)
{
    asm volatile (
        "push esi\n\t"
        "mov.s esi, ecx\n\t"
        "call ??1Abode@@UAE@XZ\n\t"
        "test byte ptr [esp + 0x08], 0x01\n\t"
        "%{disp8%} je 0f\n\t"
        "push 0x000000c4\n\t"
        "push esi\n\t"
        "call ??3Base@@SAXPAXK@Z\n\t"
        "add esp, 0x08\n"
        "0:\n\t"
        "mov.s eax, esi\n\t"
        "pop esi\n\t"
        "ret 0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

#include "GameThingWithPos.h"


struct MapCoords* __fastcall GetArrivePos__16GameThingWithPosFv(struct GameThingWithPos* this, const void* edx, struct MapCoords* param_1)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "add                ecx, 0x14\n\t"
        "push               esi\n\t"
        "mov                esi, dword ptr [ecx]\n\t"
        "mov.s              edx, eax\n\t"
        "mov                dword ptr [edx], esi\n\t"
        "%{disp8%} mov        esi, dword ptr [ecx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [edx + 0x04], esi\n\t"
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [edx + 0x08], ecx\n\t"
        "pop                esi\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

uint32_t __fastcall GetCreatureBeliefType__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0x15;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetOrigin__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

float __fastcall GetLife__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    extern const float rdata_float1p0;
    return rdata_float1p0;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsMoving__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return 0;
}

#if HAS_EXPAND_MOVZX
__attribute__((expand_movzx))
bool32_t __fastcall IsObjectInMap__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return *((uint8_t*)this + 0x24) & 1;
}
#else
bool32_t __fastcall IsObjectInMap__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        al, byte ptr [ecx + 0x24]\n\t"
        "and                eax, 0x01\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}
#endif

__attribute__((XOR32rr_REV))
bool __fastcall IsDrowning__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsCastShadowAtNight__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

void __fastcall CleanupWhenDeleted__16GameThingWithPosFi(struct GameThingWithPos* this, const void* edx, int param_1)
{
    return;
}

float __fastcall GetImpressiveValue__16GameThingWithPosFP6LivingP8Reaction(struct GameThingWithPos* this, const void* edx, struct Living* param_1, struct Reaction* param_2)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsAbode__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsBuildingMaterial__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsSuitableForCreatureAction__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeEatenByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeAttackedByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeFrighteningToCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeHelpedByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBePlayedWithByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeImpressedByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeInspectedByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBePoodUponByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeSleptNextToByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBePickedUpByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeStrokedByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeSetOnFire__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeStompedOnByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeThrownByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBePutInAStoragePit__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeDestroyedByStoning__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeExaminedByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsBeingBuilt__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall NeedsRepair__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsOnFire__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBePutInFoodPile__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBePutInWoodPile__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeBroughtBackToCitadel__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBePoodOn__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsBuildingWhichIsBeingBuilt__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeKickedByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

uint32_t __fastcall GetCreatureMimicType__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0xa;
}

float __fastcall GetHowMuchCreatureWantsToLookAtMe__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

float __fastcall GetHeight__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

__attribute__((XOR32rr_REV))
void __fastcall SetInScript__16GameThingWithPosFi(struct GameThingWithPos* this, const void* edx, int32_t param_1)
{
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        al, byte ptr [esp + 0x04]\n\t"
        "xor.s              edx, edx\n\t"
        "%{disp8%} mov        dx, word ptr [ecx + 0x24]\n\t"
        "and                eax, 0x01\n\t"
        "shl                eax, 9\n\t"
        "and                edx, 0x0000fdff\n\t"
        "or.s               eax, edx\n\t"
        "%{disp8%} mov        word ptr [ecx + 0x24], ax\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsHouse__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsObject__16GameThingWithPosCFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
enum HELP_TEXT __fastcall GetQueryFirstEnumText__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
enum HELP_TEXT __fastcall GetQueryLastEnumText__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

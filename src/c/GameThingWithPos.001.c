#include "GameThingWithPos.h"


__attribute__((forced_callee_saves("esi"), prefer_base_adjust, delayed_callee_save("esi:after_first_add")))
struct MapCoords* __fastcall GetArrivePos__16GameThingWithPosFv(struct GameThingWithPos* this, const void* edx, struct MapCoords* param_1)
{
    register uint32_t tmp asm("esi");
    register struct MapCoords* out asm("edx");
    tmp = *(uint32_t*)((char*)this + 0x14);
    asm volatile("mov.s %0, %1" : "=d"(out) : "a"(param_1) : "memory");
    *(uint32_t*)((char*)out + 0x00) = tmp;
    tmp = *(uint32_t*)((char*)this + 0x18);
    asm volatile("" :: "S"(tmp));
    *(uint32_t*)((char*)out + 0x04) = tmp;
    *(uint32_t*)((char*)out + 0x08) = *(uint32_t*)((char*)this + 0x1c);
    return param_1;
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
bool32_t __fastcall IsMoving__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((expand_movzx))
bool32_t __fastcall IsObjectInMap__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return *(uint8_t*)((char*)this + offsetof(struct GameThingWithPos, field_0x24)) & 1;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsDrowning__16GameThingWithPosFv(struct GameThingWithPos* this)
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

__attribute__((XOR32rr_REV, no_callee_saves, expand_movzx, prefer_byte_param_load("4")))
void __fastcall SetInScript__16GameThingWithPosFi(struct GameThingWithPos* this, const void* edx, int32_t param_1)
{
    register uint32_t bit asm("eax") = (uint32_t)param_1;
    register uint32_t flags asm("edx") = *(uint16_t*)((char*)this + 0x24);
    asm volatile(
        "and %0, 0x01\n\t"
        "shl %0, 9\n\t"
        "and %1, 0x0000fdff\n\t"
        "or.s %0, %1"
        : "+a"(bit), "+d"(flags));
    *(uint16_t*)((char*)this + 0x24) = (uint16_t)bit;
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

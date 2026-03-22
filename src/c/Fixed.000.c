#include "Fixed.h"

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeFrighteningToCreature__11FixedObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return false;
}

bool32_t __fastcall CanBeSleptNextToByCreature__11FixedObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return true;
}

bool32_t __fastcall CanBeDestroyedByStoning__11FixedObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return true;
}

__attribute__((expand_movzx, no_test_sete_fold))
bool32_t __fastcall CanBeSetOnFire__11FixedObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return (~*(uint8_t*)((char*)this + 0x0a) >> 3) & 1;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBePickedUpByCreature__11FixedObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return false;
}

bool32_t __fastcall CanBeCrushed__11FixedObjectFv(struct Object* this)
{
    return true;
}

bool32_t __fastcall VillagerMustAvoid__11FixedObjectFP8Villager(struct Object* this, const void* edx, struct Villager* param_1)
{
    return true;
}

struct GameThing* __fastcall GetTownArtifact__11FixedObjectFv(struct Object* this)
{
    return ((struct Fixed*)this)->town_artifact;
}

__attribute__((no_callee_saves, XOR32rr_REV, trailing_asm("call ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9")))
bool32_t __fastcall IsTownArtifact__11FixedObjectFv(struct Object* this)
{
    return *(uint32_t*)((char*)this + 0x54) != 0;
}

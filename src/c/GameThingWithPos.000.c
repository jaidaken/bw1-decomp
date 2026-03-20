#include "GameThingWithPos.h"

const float rdata_float0p0 = 0.0f;                                 // [0x1398] 0x008a9000 + 0x1398 = 0x008aa398
const float rdata_float0p0005 = 0.0005f;                           // [0x139c] 0x008a9000 + 0x139c = 0x008aa39c
const float rdata_float1p05 = 1.05;                                // [0x13a0] 0x008a9000 + 0x13a0 = 0x008aa3a0
const float rdata_float_coord_to_point = 10.0f / ((float)0x10000); // [0x13a4] 0x008a9000 + 0x13a4 = 0x008aa3a4
const float rdata_floatn0p8 = -0.8;                                // [0x13a8] 0x008a9000 + 0x13a8 = 0x008aa3a8
const float rdata_float0p2 = 0.2;                                  // [0x13ac] 0x008a9000 + 0x13ac = 0x008aa3ac
const float rdata_float0p001 = 0.001;                              // [0x13b0] 0x008a9000 + 0x13b0 = 0x008aa3b0
const float rdata_float0p5 = 0.5;                                  // [0x13b4] 0x008a9000 + 0x13b4 = 0x008aa3b4

__attribute__((aligned(8)))
struct RTTITypeDescriptor __RTTITypeDescriptor__16GameThingWithPos = {
    .pVFTable = &__vt__9type_info,
    .spare = 0,
    .name = ".?AVGameThingWithPos@@",
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__16GameThingWithPos = {
    .pTypeDescriptor = &__RTTITypeDescriptor__16GameThingWithPos,
    .numContainedBases = 0x00000002,
    .where = {
        .mdisp = 0x00000000,
        .pdisp = 0xFFFFFFFF,
        .vdisp = 0x00000000,
    },
    .attributes = 0x0000000,
};

__attribute__((no_callee_saves, trailing_asm("call               dword ptr [__imp__BinkCopyToBuffer@28]"), ret_cleanup_override(0x0004)))
void __fastcall SetPos__16GameThingWithPosFRC9MapCoords(struct GameThingWithPos* this, const void* edx, const struct MapCoords* param_2)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "mov                edx, dword ptr [eax]\n\t"
        "add                ecx, 0x14\n\t"
        "mov                dword ptr [ecx], edx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x04], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x08], eax"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
struct MapCoords* __fastcall GetPos__16GameThingWithPosFv(const struct GameThingWithPos* this, const void* edx, struct MapCoords* param_1)
{
    struct MapCoords* result;
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
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, trailing_asm("call               dword ptr [__imp__GetOpenFileNameA@4]")))
void __fastcall PhysicsEditorCreate__16GameThingWithPosFi(struct GameThingWithPos* this, const void* edx, int param_1)
{
    this->coords.altitude = 0.0f;
}

uint32_t __fastcall GetCreatureBeliefListType__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 1;
}

__attribute__((XOR32rr_REV))
struct Citadel* __fastcall GetCitadel__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

void __fastcall SetHeight__16GameThingWithPosFf(struct GameThingWithPos* this, const void* edx, float height)
{
    return;
}

void __fastcall SetMaxHeight__16GameThingWithPosFf(struct GameThingWithPos* this, const void* edx, float height)
{
    return;
}

float __fastcall GetMaxHeight__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    extern const float __opaque_rdata_float0p0 asm("_rdata_float0p0");
    return __opaque_rdata_float0p0;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsAnimate__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall GetInteractPos__16GameThingWithPosFv(struct GameThingWithPos* this, const void* edx, struct LHPoint* pos)
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
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

#if HAS_EXPAND_MOVZX
__attribute__((expand_movzx))
bool32_t __fastcall IsCannotBePickedUp__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return (*(uint16_t*)((char*)this + offsetof(struct GameThingWithPos, field_0x24)) >> 13) & 1;
}
#else
bool32_t __fastcall IsCannotBePickedUp__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    bool32_t result;
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        ax, word ptr [ecx + 0x24]\n\t"
        "shr                eax, 0xd\n\t"
        "and                eax, 0x01"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}
#endif

__attribute__((XOR32rr_REV))
bool __fastcall IsStompable__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

bool32_t __fastcall IsAvailableForStateChange__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    uint32_t val;
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        al, byte ptr [ecx + 0x24]\n\t"
        "not                al"
        : "=a"(val) : "c"(this) : "edx", "memory"
    );
    return (val >> 2) & 1;
}

float __fastcall GetImpressiveIntensity__16GameThingWithPosF15IMPRESSIVE_TYPE(struct GameThingWithPos* this, const void* edx, enum IMPRESSIVE_TYPE type)
{
    extern const float rdata_float1p0;
    return rdata_float1p0;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsTown__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* param_1)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsActivityObjectWhichAngerAppliesTo__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* param_1)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsActivityObjectWhichCompassionAppliesTo__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* param_1)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsActivityObjectWhichPlayfulnessAppliesTo__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* param_1)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsTownBelongingToAnotherPlayer__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* param_1)
{
    return 0;
}

bool32_t __fastcall TrueFunction__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 1;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall FalseFunction__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

bool32_t __fastcall IsNotLiving__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 1;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsSuitableForCreatureActivity__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsTown__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsTownCentre__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsTotemStatue__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsTownDesireFlag__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsRock__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsSpellDispenser__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsMist__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsQueryIcon__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsStreetLight__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsStreetLantern__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsField__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsMagicFireBall__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsCitadelHeart__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsDamaged__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    bool32_t result;
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "call dword ptr [eax + 0x11c]\n\t"
        "%{disp32%} fcomp dword ptr [_rdata_float1p0]\n\t"
        "fnstsw ax\n\t"
        "test ah, 0x01\n\t"
        "%{disp8%} je 0f\n\t"
        "mov eax, 0x00000001\n\t"
        "ret\n"
        "0:\n\t"
        "xor.s eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeHealedByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeBefriendedByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeKissedByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeGivenToVillager__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall CanBeStonedAndEatenByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x258]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00401c3e\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x278]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00401c3e\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00401c3e:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeFoughtByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanReceiveGifts__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanActAsAContainer__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall IsNotOnFire__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov edx, dword ptr [esp + 0x04]\n\t"
        "mov eax, dword ptr [ecx]\n\t"
        "push edx\n\t"
        "call dword ptr [eax + 0x298]\n\t"
        "neg eax\n\t"
        ".byte 0x1b, 0xc0\n\t"
        "inc eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeUsedForBuilding__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsMushroom__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeUsedForRepair__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeGivenToTown__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeUsedToHoldWater__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanHaveMagicFoodCastOnMe__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanHaveMagicWoodCastOnMe__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsVillager__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsVillagerFarFromHome__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsVillagerInTownWithoutManyBreeders__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsVillagerNotWorshipping__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsVillagerBelongingToOtherPlayer__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsCow__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsVillagerWhoHasNotBeenImpressedRecently__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsVillagerWhoHasNotBeenDancedWithRecently__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall DoesVillagerBelongToATownWhichIsAlreadyImpressed__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall DoesTotemBelongToATownWhichIsVeryImpressedIndeed__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsDominantCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeDancedWith__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsAggressive__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsStoragePit__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsWorshipSite__16GameThingWithPosFv(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsWorshipSite__16GameThingWithPosFP8Creature(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
struct WorshipSite* __fastcall GetWorshipSite__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsWorkshop__16GameThingWithPosFv(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsStoragePitWithFoodInIt__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsField__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsFieldWhichNeedsWatering__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsFieldWithFoodInIt__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsFieldBelongingToAnotherPlayer__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsStoragePitBelongingToAnotherPlayer__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsStoragePitBelongingToMyPlayer__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall BenefitsFromHavingWaterSprinkledOnIt__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsTree__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsTreeNotTooNearPlannedForest__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsTreeBigEnoughForCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsAFoodPileOutsideStoragePit__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsAWoodPileOutsideStoragePit__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsDoingSomethingInteresting__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall CanBeUsedForBuildingHomeByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x1f0]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00401f49\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x2a0]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00401f49\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x004e3ee0\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00401f49\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00401f49:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, trailing_asm("call ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9"), ret_cleanup_override(0x0004)))
bool32_t __fastcall IsRock__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    bool32_t result;
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "call dword ptr [eax + 0x1f0]"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall IsPickupableRock__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x1f0]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00401f8b\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x258]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00401f8b\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00401f8b:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsCitadelPart__16GameThingWithPosFv(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsPlayingFootball__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsPlayingFootballAndMySideHasJustScored__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsPlayingFootballAndOtherSideHasJustScored__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsAnimalBelongingToOtherPlayer__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsOneOffSpellBelongingToOtherPlayer__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsOneOffSpellAggressive__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsOneOffSpellCompassionate__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsOneOffSpellPlayful__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsOneOffSpellToRestoreHealth__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeStolenByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsStealableSpell__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsStealableScaffold__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsTownBelongingToOtherPlayer__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsTotemWithStealableSpell__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsCreatureAvailableForJointActivity__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsCreatureNotAvailableForJointActivity__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsToyAwayFromHome__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsToy__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsToyBall__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsToyDie__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsToyCuddly__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((no_callee_saves, trailing_asm("call ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9"), ret_cleanup_override(0x0004)))
bool32_t __fastcall IsLiving__16GameThingWithPosFP8Creature(const struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    bool32_t result;
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "call dword ptr [eax + 0x3c4]"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsFence__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsSpellIcon__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeUsedForThrowingDamageByCreature__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsCreatureWhoSeemsFriendly__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeThrownInTheSeaPlayfully__16GameThingWithPosFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsFlock__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsDance__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsReward__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsScriptContainer__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsWeather__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsSpell__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsDeletedWhenReleasedFromScript__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsMobileWallHug__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsActive__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsObjectTurningTooFastForCameraToFollowSmoothly__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

float __fastcall CalculateDesireForFood__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    extern const float __opaque_rdata_float0p0 asm("_rdata_float0p0");
    return __opaque_rdata_float0p0;
}

float __fastcall CalculateDesireForRest__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    extern const float __opaque_rdata_float0p0 asm("_rdata_float0p0");
    return __opaque_rdata_float0p0;
}

float __fastcall CalculatePeopleHidingIndicator__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    extern const float __opaque_rdata_float0p0 asm("_rdata_float0p0");
    return __opaque_rdata_float0p0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsReadyForNewScriptAction__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
void __fastcall SetControlledByScript__16GameThingWithPosFi(struct GameThingWithPos* this, const void* edx, int32_t param_1)
{
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        al, byte ptr [esp + 0x04]\n\t"
        "xor.s              edx, edx\n\t"
        "%{disp8%} mov        dx, word ptr [ecx + 0x24]\n\t"
        "and                eax, 0x01\n\t"
        "shl                eax, 0xa\n\t"
        "and                edx, 0x0000fbff\n\t"
        "or.s               eax, edx\n\t"
        "%{disp8%} mov        word ptr [ecx + 0x24], ax"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV))
enum DEATH_REASON __fastcall GetDeathReason__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

#if HAS_EXPAND_MOVZX
__attribute__((expand_movzx))
bool32_t __fastcall IsInScript__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return (*(uint16_t*)((char*)this + offsetof(struct GameThingWithPos, field_0x24)) >> 9) & 1;
}
#else
bool32_t __fastcall IsInScript__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    bool32_t result;
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        ax, word ptr [ecx + 0x24]\n\t"
        "shr                eax, 9\n\t"
        "and                eax, 0x01"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}
#endif

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsMaleVillager__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsFemaleVillager__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsAnimal__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsAChild__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsFootball__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsCitadel__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsForest__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsMobileObject__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsMobileStatic__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsTree__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsAnyKindOfTree__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsDeadTree__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsLiving__16GameThingWithPosFv(const struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsCitadelPart__16GameThingWithPosFP8Creature(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsPileFood__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsFeature__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsScriptMarker__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsScriptHighlight__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsWorkshop__16GameThingWithPosFP8Creature(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsInfluenceRing__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsPuzzleGame__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsScaffold__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsSkeleton__16GameThingWithPosCFv(const struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV, prefer_xor8))
bool32_t __fastcall IsPoisoned__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV, prefer_xor8))
bool32_t __fastcall IsSpeedUp__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsParticleContainer__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsSacrificeAltar__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsPot__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsComputerPlayer__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

void __fastcall SetSkeleton__16GameThingWithPosFi(struct GameThingWithPos* this, const void* edx, int index)
{
    return;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsSpellSeed__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsSpellShield__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsPileResource__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsScriptTimer__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 0;
}

float __fastcall GetFacingDirection__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    extern const float __opaque_rdata_float0p0 asm("_rdata_float0p0");
    return __opaque_rdata_float0p0;
}

void __fastcall SetAffectedByWind__16GameThingWithPosFi(struct GameThingWithPos* this, const void* edx, int param_1)
{
    return;
}

float __fastcall GetReactionPower__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    extern const float rdata_float1p0;
    return rdata_float1p0;
}

void __fastcall CleanUpBeforeReset__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return;
}


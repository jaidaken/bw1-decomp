#include "Windmill.h"

__attribute__((aligned(8)))
struct RTTITypeDescriptor __RTTITypeDescriptor__8Windmill = {
    .pVFTable = &__vt__9type_info,
    .spare = 0,
    .name = ".?AVWindmill@@",
};

__attribute__((aligned(4)))
char windmill_column[] asm("??_C@_09ABCDEFGH@Windmill?$AA@") = "Windmill:\0";
__attribute__((aligned(4)))
char windmill_underscore_join[] = "%s_%s\0";

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__8Windmill = {
    .pTypeDescriptor = &__RTTITypeDescriptor__8Windmill,
    .numContainedBases = 0x00000007,
    .where = {
        .mdisp = 0x00000000,
        .pdisp = 0xFFFFFFFF,
        .vdisp = 0x00000000,
    },
    .attributes = 0x0000000,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassArray __RTTIBaseClassArray__8Windmill = {
    .arrayOfBaseClassDescriptors = {
        (void*)0x009a6508,
        &__RTTIBaseClassDescriptor__5Abode,
        &__RTTIBaseClassDescriptor__13MultiMapFixed,
        &__RTTIBaseClassDescriptor__11FixedObject,
        &__RTTIBaseClassDescriptor__6Object,
        &__RTTIBaseClassDescriptor__16GameThingWithPos,
        &__RTTIBaseClassDescriptor__9GameThing,
        &__RTTIBaseClassDescriptor__4Base,
        NULL,
    }
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__8Windmill = {
  .signature = 0x00000000,
  .attributes = 0x00000000,
  .numBaseClasses = 0x00000008,
  .pBaseClassArray = &__RTTIBaseClassArray__8Windmill,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTICompleteObjectLocator __RTTICompleteObjectLocator__8Windmill = {
  .signature = 0x00000000,
  .offset = 0x00000000,
  .cdOffset = 0x00000000,
  .pTypeDescriptor = &__RTTITypeDescriptor__8Windmill,
  .pClassDescriptor = &__RTTIClassHierarchyDescriptor__8Windmill,
};

__attribute__((XOR32rr_REV))
struct Windmill* __cdecl Create__8WindmillFRC9MapCoordsPC10GAbodeInfoP4Townfffi(const struct MapCoords* coords, const struct GAbodeInfo* info, struct Town* town, float y_angle, float scale, float food, int wood)
{
    asm volatile (
        "push               esi\n\t"
        "push               0x000005c4\n\t"
        "push               0x009c7fbc\n\t"
        "push               0x000000c4\n\t"
        "call               ?__nw@Base@@SAPAXK@Z\n\t"
        "mov.s              esi, eax\n\t"
        "add                esp, 0x0c\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x004058ed\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x20]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x1c]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x18]\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x1c]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x1c]\n\t"
        "push               edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x1c]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ??0Abode@@QAE@ABUMapCoords@@PBVGAbodeInfo@@PAVTown@@MMMH@Z\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "mov                dword ptr [esi], 0x008aa8e4\n\t"
        "call               dword ptr [rdata_bytes + 0x1f3c]\n\t"
        "pop                edi\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x004058ed:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

uint32_t __fastcall GetSaveType__8WindmillFv(struct GameThing* this)
{
    return 0xf8;
}

char* __fastcall GetDebugText__8WindmillFv(struct GameThing* this)
{
    return (char*)0x009c8048;  // ??_C@_09ABCDEFGH@Windmill?$AA@
}

void __fastcall __dt__8WindmillFv(struct Base* this, const void* edx, uint32_t param_1)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ??1Abode@@UAE@XZ\n\t"
        "test               byte ptr [esp + 0x08], 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0040593d\n\t"
        "push               0x000000c4\n\t"
        "push               esi\n\t"
        "call               ??3Base@@SAXPAXK@Z\n\t"
        "add                esp, 0x08\n"
        "LAB__addr_0x0040593d:\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
void __fastcall CallVirtualFunctionsForCreation__8WindmillFRC9MapCoords(struct Object* this, const void* edx, const struct MapCoords* param_1)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               eax\n\t"
        "call               ?CallVirtualFunctionsForCreation@Abode@@UAEXABUMapCoords@@@Z\n\t"
        "test               byte ptr [esi + 0x0a], 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0040597c\n\t"
        "push               0x0\n\t"
        "push               0x1\n\t"
        "push               0x1\n\t"
        "push               0x0\n\t"
        "push               -0x1\n\t"
        "push               0x2\n\t"
        "push               0x0\n\t"
        "push               0xd\n\t"
        "push               esi\n\t"
        "call               ?Create@SoundTag@@SAPAV1@PAVGameThingWithPos@@K_NKKHHW4AUDIO_SFX_BANK_TYPE@@H@Z\n\t"
        "add                esp, 0x24\n"
        "LAB__addr_0x0040597c:\n\t"
        "pop                esi\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

const struct RTTICompleteObjectLocator* const p__RTTICompleteObjectLocator__8Windmill = &__RTTICompleteObjectLocator__8Windmill;

const struct AbodeVftable __vt__8Windmill = {
  Serialise__4BaseFR7Archive,
  __dt__8WindmillFv,
  Delete__5AbodeFv,
  ToBeDeleted__5AbodeFi,
  Get3DSoundPos__16GameThingWithPosFP7LHPoint,
  CleanUpForSerialisation__4BaseFv,
  Dump__4BaseFv,
  GetPlayer__5AbodeFv,
  SetPlayer__9GameThingFP7GPlayer,
  CalculateInfluence__9GameThingFRC9MapCoords,
  RemoveDance__9GameThingFv,
  IsAvailable__9GameThingFv,
  IsCreature__9GameThingFP8Creature,
  IsCreature__9GameThingFv,
  IsCreatureNotTooNear__9GameThingFP8Creature,
  GetDrawImportance__6ObjectFv,
  GetMaxAlignmentChangePerGameTurn__9GameThingFv,
  GetComputerSeen__9GameThingFv,
  GetTown__5AbodeFv,
  GetVillagerActivityDesire__9GameThingFP8Villager,
  SetVillagerActivity__9GameThingFP8Villager,
  UpdateVillagerActivityEffect__9GameThingFP8Villager,
  MaintainSpell__9GameThingFP5Spellf,
  UpdateSpellInfo__9GameThingFP5SpellP15PSysProcessInfo,
  GetRadius__6ObjectFv,
  Get2DRadius__6ObjectFv,
  GetPlayerWhoLastPickedMeUp__9GameThingFv,
  GetPlayerWhoLastDroppedMe__9GameThingFv,
  IsFootpathLink__13MultiMapFixedFv,
  GetFootpathLink__13MultiMapFixedFv,
  AddFootpathLink__9GameThingFP9GFootpath,
  GetNearestPathTo__13MultiMapFixedFRC9MapCoordsfi,
  UseFootpathIfNecessary__13MultiMapFixedFP6LivingRC9MapCoordsUc,
  AddFootpath__13MultiMapFixedFP9GFootpath,
  RemoveFootpath__13MultiMapFixedFP9GFootpath,
  JustAddResource__5AbodeF13RESOURCE_TYPEUlb,
  JustRemoveResource__5AbodeF13RESOURCE_TYPEUlPb,
  JustGetResource__9GameThingF13RESOURCE_TYPEUlPb,
  GetResource__5AbodeF13RESOURCE_TYPE,
  AddResource__5AbodeF13RESOURCE_TYPEUlP16GInterfaceStatusbRC9MapCoordsi,
  RemoveResource__5AbodeF13RESOURCE_TYPEUlP16GInterfaceStatusPb,
  CastCreature__9GameThingFv,
  CastPlayer__9GameThingFv,
  CastOneOffSpellSeed__9GameThingFv,
  CastAbode__5AbodeFv,
  CastMultiMapFixed__13MultiMapFixedFv,
  CastSpellIcon__9GameThingFv,
  CastTree__9GameThingFv,
  IsDeletedOnNewMap__9GameThingFv,
  GetNumberOfInstanceForGlobalList__5AbodeFv,
  GetTownArtifactValue__11FixedObjectFv,
  CanBecomeArtifact__6ObjectFv,
  DrawInHand__6ObjectFP16GInterfaceStatus,
  IsFunctional__5AbodeFv,
  GetDebugText__8WindmillFv,
  GetSampleForAttack__9GameThingFv,
  GetGuidanceResourceType__9GameThingFv,
  GetShowNeedsPos__9GameThingFUlP9MapCoords,
  Load__5AbodeFR10GameOSFile,
  Save__5AbodeFR10GameOSFile,
  GetSaveType__8WindmillFv,
  SaveExtraData__9GameThingFR10GameOSFile,
  ResolveLoad__6ObjectFv,
  SetPos__16GameThingWithPosFRC9MapCoords,
  GetPos__16GameThingWithPosFv,
  GetArrivePos__5AbodeFv,
  PhysicsEditorCreate__16GameThingWithPosFi,
  GetCreatureBeliefType__5AbodeFv,
  GetCreatureBeliefListType__16GameThingWithPosFv,
  GetCitadel__16GameThingWithPosFv,
  GetOrigin__5AbodeFv,
  GetLife__6ObjectFv,
  GetScale__6ObjectFv,
  SetScale__6ObjectFf,
  GetPower__16GameThingWithPosCFv,
  GetPSysPower__16GameThingWithPosCFv,
  GetSpeedInMetres__16GameThingWithPosCFv,
  SetSpeedInMetres__16GameThingWithPosFfi,
  GetRunningSpeedInMetres__16GameThingWithPosFv,
  GetDistanceFromObject__6ObjectFRC9MapCoords,
  GetDefaultSpeedInMetres__16GameThingWithPosFv,
  SetHeight__16GameThingWithPosFf,
  SetMaxHeight__16GameThingWithPosFf,
  GetMaxHeight__16GameThingWithPosFv,
  GetPSysBeamTargetPos__16GameThingWithPosFP7LHPoint,
  GetSpeedInMetresPerSecond__16GameThingWithPosCFv,
  SetSpeedInMetresPerSecond__16GameThingWithPosFfi,
  GetRunningSpeedInMetresPerSecond__16GameThingWithPosFv,
  GetDefaultSpeedInMetresPerSecond__16GameThingWithPosFv,
  IsAnimate__16GameThingWithPosFv,
  GetMovementDirection__16GameThingWithPosFP7LHPoint,
  GetPhysicsMovementDirection__6ObjectFP7LHPoint,
  GetInteractPos__16GameThingWithPosFv,
  IsMoving__6ObjectCFv,
  IsObjectInMap__13MultiMapFixedFv,
  IsDrowning__6ObjectFv,
  IsCannotBePickedUp__16GameThingWithPosCFv,
  GetOverwritePickUpToolTip__16GameThingWithPosFv,
  IsStompable__16GameThingWithPosFv,
  IsAvailableForStateChange__16GameThingWithPosFv,
  IsInteractable__5AbodeFv,
  GetOverwriteInteractableToolTip__16GameThingWithPosFv,
  GetOverwriteDropToolTip__16GameThingWithPosFv,
  GetOverwriteTapToolTip__16GameThingWithPosFv,
  IsCastShadowAtNight__5AbodeFv,
  CleanupWhenDeleted__6ObjectFi,
  GetImpressiveType__16GameThingWithPosFv,
  GetImpressiveIntensity__16GameThingWithPosF15IMPRESSIVE_TYPE,
  GetImpressiveValue__6ObjectFP6LivingP8Reaction,
  GetUpdateOfBoredomValue__6ObjectFP8ReactionP16GameThingWithPos,
  IsTown__16GameThingWithPosFv,
  IsTown__16GameThingWithPosFP8Creature,
  IsActivityObjectWhichAngerAppliesTo__16GameThingWithPosFP8Creature,
  IsActivityObjectWhichCompassionAppliesTo__16GameThingWithPosFP8Creature,
  IsActivityObjectWhichPlayfulnessAppliesTo__16GameThingWithPosFP8Creature,
  IsTownBelongingToAnotherPlayer__16GameThingWithPosFP8Creature,
  TrueFunction__16GameThingWithPosFv,
  FalseFunction__16GameThingWithPosFv,
  IsNotLiving__16GameThingWithPosFv,
  IsSuitableForCreatureActivity__16GameThingWithPosFv,
  IsTownCentre__16GameThingWithPosFv,
  IsTotemStatue__16GameThingWithPosFv,
  IsTownDesireFlag__16GameThingWithPosFv,
  IsRock__16GameThingWithPosFP8Creature,
  IsRock__16GameThingWithPosFv,
  IsSpellDispenser__16GameThingWithPosFv,
  IsMist__16GameThingWithPosFv,
  IsQueryIcon__16GameThingWithPosFv,
  IsStreetLight__16GameThingWithPosFv,
  IsStreetLantern__16GameThingWithPosFv,
  IsAbode__5AbodeFv,
  IsField__16GameThingWithPosFP8Creature,
  IsField__16GameThingWithPosFv,
  IsBuildingMaterial__6ObjectFv,
  IsMagicFireBall__16GameThingWithPosFv,
  IsSuitableForCreatureAction__6ObjectFv,
  IsCitadelHeart__16GameThingWithPosFv,
  IsDamaged__16GameThingWithPosFv,
  CanBeHealedByCreature__16GameThingWithPosFP8Creature,
  CanBeEatenByCreature__6ObjectFP8Creature,
  CanCreatureEatMe__16GameThingWithPosFP8Creature,
  CanBeAttackedByCreature__6ObjectFP8Creature,
  CanBeFrighteningToCreature__11FixedObjectFP8Creature,
  CanBeHelpedByCreature__6ObjectFP8Creature,
  CanBePlayedWithByCreature__6ObjectFP8Creature,
  CanBeImpressedByCreature__6ObjectFP8Creature,
  CanBeInspectedByCreature__6ObjectFP8Creature,
  CanBePoodUponByCreature__6ObjectFP8Creature,
  CanBeBefriendedByCreature__16GameThingWithPosFP8Creature,
  CanBeSleptNextToByCreature__11FixedObjectFP8Creature,
  CanBePickedUpByCreature__11FixedObjectFP8Creature,
  CanBeStrokedByCreature__6ObjectFP8Creature,
  CanBeKissedByCreature__16GameThingWithPosFP8Creature,
  CanBeSetOnFire__11FixedObjectFP8Creature,
  CanBeStompedOnByCreature__5AbodeFP8Creature,
  CanBeThrownByCreature__6ObjectFP8Creature,
  CanBeGivenToVillager__16GameThingWithPosFP8Creature,
  CanBePutInAStoragePit__6ObjectFP8Creature,
  CanBeDestroyedByStoning__11FixedObjectFP8Creature,
  CanBeStonedAndEatenByCreature__16GameThingWithPosFP8Creature,
  CanBeExaminedByCreature__6ObjectFP8Creature,
  CanBeFoughtByCreature__16GameThingWithPosFP8Creature,
  CanReceiveGifts__16GameThingWithPosFP8Creature,
  CanActAsAContainer__16GameThingWithPosFP8Creature,
  IsBeingBuilt__13MultiMapFixedFP8Creature,
  NeedsRepair__13MultiMapFixedFP8Creature,
  IsOnFire__6ObjectFP8Creature,
  IsNotOnFire__16GameThingWithPosFP8Creature,
  CanBeUsedForBuilding__16GameThingWithPosFP8Creature,
  IsMushroom__16GameThingWithPosFP8Creature,
  CanBeUsedForRepair__16GameThingWithPosFP8Creature,
  CanBeGivenToTown__16GameThingWithPosFP8Creature,
  CanBeUsedToHoldWater__16GameThingWithPosFP8Creature,
  CanBePutInFoodPile__6ObjectFP8Creature,
  CanBePutInWoodPile__6ObjectFP8Creature,
  CanHaveMagicFoodCastOnMe__16GameThingWithPosFP8Creature,
  CanHaveMagicWoodCastOnMe__16GameThingWithPosFP8Creature,
  CanBeBroughtBackToCitadel__6ObjectFP8Creature,
  IsVillager__16GameThingWithPosFP8Creature,
  IsVillagerFarFromHome__16GameThingWithPosFP8Creature,
  IsVillagerInTownWithoutManyBreeders__16GameThingWithPosFP8Creature,
  IsVillagerNotWorshipping__16GameThingWithPosFP8Creature,
  IsVillagerBelongingToOtherPlayer__16GameThingWithPosFP8Creature,
  IsCow__16GameThingWithPosFP8Creature,
  CanBePoodOn__6ObjectFP8Creature,
  IsVillagerWhoHasNotBeenImpressedRecently__16GameThingWithPosFP8Creature,
  IsVillagerWhoHasNotBeenDancedWithRecently__16GameThingWithPosFP8Creature,
  DoesVillagerBelongToATownWhichIsAlreadyImpressed__16GameThingWithPosFP8Creature,
  DoesTotemBelongToATownWhichIsVeryImpressedIndeed__16GameThingWithPosFP8Creature,
  IsDominantCreature__16GameThingWithPosFP8Creature,
  CanBeDancedWith__16GameThingWithPosFP8Creature,
  IsAggressive__16GameThingWithPosFP8Creature,
  IsStoragePit__16GameThingWithPosFP8Creature,
  IsWorshipSite__16GameThingWithPosFP8Creature,
  IsWorshipSite__16GameThingWithPosFv,
  GetWorshipSite__16GameThingWithPosFv,
  IsWorkshop__16GameThingWithPosFP8Creature,
  IsWorkshop__16GameThingWithPosFv,
  IsBuildingWhichIsBeingBuilt__13MultiMapFixedFP8Creature,
  IsStoragePitWithFoodInIt__16GameThingWithPosFP8Creature,
  IsFieldWhichNeedsWatering__16GameThingWithPosFP8Creature,
  IsFieldWithFoodInIt__16GameThingWithPosFP8Creature,
  IsFieldBelongingToAnotherPlayer__16GameThingWithPosFP8Creature,
  IsStoragePitBelongingToAnotherPlayer__16GameThingWithPosFP8Creature,
  IsStoragePitBelongingToMyPlayer__16GameThingWithPosFP8Creature,
  BenefitsFromHavingWaterSprinkledOnIt__16GameThingWithPosFP8Creature,
  IsTree__16GameThingWithPosFv,
  IsTree__16GameThingWithPosFP8Creature,
  IsTreeNotTooNearPlannedForest__16GameThingWithPosFP8Creature,
  IsTreeBigEnoughForCreature__16GameThingWithPosFP8Creature,
  IsAFoodPileOutsideStoragePit__16GameThingWithPosFP8Creature,
  IsAWoodPileOutsideStoragePit__16GameThingWithPosFP8Creature,
  IsDoingSomethingInteresting__16GameThingWithPosFP8Creature,
  CanBeUsedForBuildingHomeByCreature__16GameThingWithPosFP8Creature,
  IsPickupableRock__16GameThingWithPosFP8Creature,
  IsCitadelPart__16GameThingWithPosFP8Creature,
  IsCitadelPart__16GameThingWithPosFv,
  IsPlayingFootball__16GameThingWithPosFP8Creature,
  IsPlayingFootballAndMySideHasJustScored__16GameThingWithPosFP8Creature,
  IsPlayingFootballAndOtherSideHasJustScored__16GameThingWithPosFP8Creature,
  CanBeBroughtHomeByCreature__16GameThingWithPosFP8Creature,
  IsAnimalBelongingToOtherPlayer__16GameThingWithPosFP8Creature,
  IsOneOffSpellBelongingToOtherPlayer__16GameThingWithPosFP8Creature,
  IsOneOffSpellAggressive__16GameThingWithPosFP8Creature,
  IsOneOffSpellCompassionate__16GameThingWithPosFP8Creature,
  IsOneOffSpellPlayful__16GameThingWithPosFP8Creature,
  IsOneOffSpellToRestoreHealth__16GameThingWithPosFP8Creature,
  CanBeKickedByCreature__5AbodeFP8Creature,
  CanBeStolenByCreature__16GameThingWithPosFP8Creature,
  IsStealableByCreature__16GameThingWithPosFP8Creature,
  IsStealableSpell__16GameThingWithPosFP8Creature,
  IsStealableScaffold__16GameThingWithPosFP8Creature,
  IsTownBelongingToOtherPlayer__16GameThingWithPosFP8Creature,
  IsTotemWithStealableSpell__16GameThingWithPosFP8Creature,
  IsCreatureAvailableForJointActivity__16GameThingWithPosFP8Creature,
  IsCreatureNotAvailableForJointActivity__16GameThingWithPosFP8Creature,
  IsToyAwayFromHome__16GameThingWithPosFP8Creature,
  IsToy__16GameThingWithPosFP8Creature,
  IsToyBall__16GameThingWithPosFP8Creature,
  IsToyDie__16GameThingWithPosFP8Creature,
  IsToyCuddly__16GameThingWithPosFP8Creature,
  IsLiving__16GameThingWithPosFv,
  IsLiving__16GameThingWithPosFP8Creature,
  IsFence__16GameThingWithPosFv,
  IsSpellIcon__16GameThingWithPosFv,
  NothingScareyNearMe__16GameThingWithPosFP8Creature,
  CanBeUsedForThrowingDamageByCreature__16GameThingWithPosFP8Creature,
  IsCreatureWhoSeemsFriendly__16GameThingWithPosFP8Creature,
  CanBeThrownInTheSeaPlayfully__16GameThingWithPosFP8Creature,
  GetCreatureMimicType__5AbodeFv,
  GetHowMuchCreatureWantsToLookAtMe__5AbodeFv,
  IsFlock__16GameThingWithPosCFv,
  IsDance__16GameThingWithPosCFv,
  IsReward__16GameThingWithPosCFv,
  IsScriptContainer__16GameThingWithPosCFv,
  IsWeather__16GameThingWithPosCFv,
  IsSpell__16GameThingWithPosCFv,
  IsDeletedWhenReleasedFromScript__16GameThingWithPosFv,
  IsMobileWallHug__16GameThingWithPosCFv,
  IsActive__16GameThingWithPosCFv,
  IsObjectTurningTooFastForCameraToFollowSmoothly__16GameThingWithPosFv,
  CalculateWhereIWillBeAfterNSeconds__5AbodeFfP7LHPoint,
  AttitudeToCreatureEating__16GameThingWithPosFv,
  GetText__6ObjectFv,
  CalculateDesireForFood__16GameThingWithPosFv,
  CalculateDesireForRest__16GameThingWithPosFv,
  CalculatePeopleHidingIndicator__16GameThingWithPosFv,
  GetHeight__6ObjectFv,
  IsReadyForNewScriptAction__16GameThingWithPosFv,
  ForDrawFXGetNumVertices__16GameThingWithPosFv,
  ForDrawFXGetVertexPos__16GameThingWithPosFlP7LHPoint,
  SetInScript__6ObjectFi,
  SetControlledByScript__16GameThingWithPosFi,
  GetDeathReason__16GameThingWithPosFv,
  IsInScript__16GameThingWithPosFv,
  IsMaleVillager__16GameThingWithPosFv,
  IsFemaleVillager__16GameThingWithPosFv,
  IsAnimal__16GameThingWithPosFv,
  IsAChild__16GameThingWithPosFv,
  IsHouse__5AbodeFv,
  IsObject__6ObjectCFv,
  IsFootball__16GameThingWithPosFv,
  IsCitadel__16GameThingWithPosFv,
  IsForest__16GameThingWithPosFv,
  IsMobileObject__16GameThingWithPosFv,
  IsMobileStatic__16GameThingWithPosFv,
  IsAnyKindOfTree__16GameThingWithPosFv,
  IsDeadTree__16GameThingWithPosFv,
  IsPileFood__16GameThingWithPosFv,
  IsFeature__16GameThingWithPosFv,
  IsScriptMarker__16GameThingWithPosFv,
  IsScriptHighlight__16GameThingWithPosFv,
  IsWonder__5AbodeFv,
  IsInfluenceRing__16GameThingWithPosFv,
  IsPuzzleGame__16GameThingWithPosFv,
  IsScaffold__16GameThingWithPosFv,
  IsSkeleton__16GameThingWithPosCFv,
  IsPoisoned__16GameThingWithPosFv,
  IsSpeedUp__16GameThingWithPosFv,
  IsParticleContainer__16GameThingWithPosFv,
  IsSacrificeAltar__16GameThingWithPosFv,
  IsPot__16GameThingWithPosFv,
  IsComputerPlayer__16GameThingWithPosFv,
  CanBeThrownByPlayer__16GameThingWithPosFv,
  SetSkeleton__16GameThingWithPosFi,
  IsSpellSeed__16GameThingWithPosFv,
  IsSpellShield__16GameThingWithPosFv,
  IsPileResource__16GameThingWithPosFv,
  IsScriptTimer__16GameThingWithPosFv,
  CreateBuildingSite__13MultiMapFixedFv,
  GetQueryFirstEnumText__6ObjectFv,
  GetQueryLastEnumText__6ObjectFv,
  GetFOVHelpMessageSet__6ObjectFv,
  GetFOVHelpCondition__6ObjectFv,
  GetScriptObjectType__5AbodeFv,
  GetFacingDirection__16GameThingWithPosFv,
  SetAffectedByWind__16GameThingWithPosFi,
  GetReactionPower__16GameThingWithPosFv,
  GetSpellCastPos__16GameThingWithPosFv,
  CleanUpBeforeReset__16GameThingWithPosFv,
  DestroyedByBeam__5AbodeFv,
  GetXAngle__6ObjectFv,
  GetYAngle__6ObjectFv,
  GetZAngle__6ObjectFv,
  SetFocus__6ObjectFRC7LHPoint,
  SetXYZAngles__6ObjectFfff,
  SetXYZAnglesAndScale__6ObjectFffff,
  SetJustScale__6ObjectFf,
  SetYJustAngle__6ObjectFf,
  SetYAngle__6ObjectFf,
  UpdateFrom3DPosition__6ObjectFv,
  MoveAlongPath__6ObjectFv,
  IsReachable__6ObjectFv,
  BlocksTownClearArea__6ObjectCFv,
  Create3DObject__11FixedObjectFv,
  GetMapChild__13MultiMapFixedFRC7MapCell,
  SetMapChild__13MultiMapFixedFP6ObjectP7MapCell,
  InsertMapObject__5AbodeFv,
  RemoveMapObject__13MultiMapFixedFv,
  InsertMapObjectToCell__11FixedObjectFP7MapCell,
  RemoveMapObjectFromCell__6ObjectFP7MapCell,
  IsObjectInMap__6ObjectFP7MapCell,
  IsObjectInMapCheck__6ObjectFv,
  MoveMapObject__13MultiMapFixedFRC9MapCoords,
  ActualMoveMapObject__6ObjectFRC9MapCoords,
  GetPtr__6ObjectFv,
  GetMeshRadius__6ObjectCFv,
  Get3DObjectForPSys__6ObjectFv,
  GetPSysFireFlameMatrix__6ObjectFP8LHMatrix,
  GetPSysFireLocalRndFlamePos__5AbodeFP7LHPointPl,
  GetPSysFireWorldFlamePos__6ObjectFRC7LHPointlP7LHPoint,
  GetPSysFireLocalFlameScale__6ObjectFv,
  GetPSysFireMaxFlames__6ObjectFv,
  GetSpotEffectPower__6ObjectFv,
  GetAggressorValueFromDamage__6ObjectFf,
  GetHoldType__6ObjectFv,
  GetHoldRadius__6ObjectFv,
  GetHoldLoweringMultiplier__6ObjectFv,
  GetHoldYRotate__6ObjectFv,
  HandShouldFeelWithMeshIntersect__6ObjectFv,
  SetSpecularColor__6ObjectFUl,
  GetSpecularColor__6ObjectFv,
  SetBeliefSprite__6ObjectFP12BeliefSprite,
  GetBeliefSprite__6ObjectFv,
  SetLife__6ObjectFf,
  IsAlive__6ObjectFv,
  ReduceLife__5AbodeFfP7GPlayer,
  IncreaseLife__5AbodeFf,
  GetSacrificeValue__6ObjectFv,
  ReduceLifeDueToBurning__6ObjectFfP7GPlayer,
  FillInEffectDefenceMultiplier__6ObjectFR13EffectNumbers,
  ApplyEffect__6ObjectFR12EffectValuesi,
  GetDamageEffect__6ObjectFR12EffectValues,
  GetHealEffect__6ObjectFR12EffectValues,
  GetActualObjectToEffect__6ObjectFP7GPlayerb,
  DrawValue__6ObjectFlf,
  ScaffoldMoved__6ObjectFP8Scaffold,
  GetHeatCapacity__6ObjectFv,
  GetFireGPHXDrawn__6ObjectFPbPbPbPb,
  GetRainCoolingMultiplier__6ObjectFv,
  GetDefaultFireCentrePos__6ObjectFP9MapCoords,
  GetDefaultFireRadius__6ObjectFv,
  DestroyedByEffect__5AbodeFP7GPlayerf,
  Process__5AbodeFv,
  ProcessBySpell__6ObjectFP5Spell,
  ApplySingleEffect__6ObjectF11EFFECT_TYPEfP9GameThingRC9MapCoords,
  GetMesh__5AbodeCFv,
  GetDetailMesh__6ObjectCF12DETAIL_LEVEL,
  Draw__8WindmillFv,
  DrawOutOfMap__6ObjectFb,
  IsG3DObjectDrawnInHand__6ObjectFv,
  GetDrawRegion__6ObjectFP8LHRegion,
  ProcessState__6ObjectFv,
  GetProjectileSpeed__6ObjectFv,
  CanBePickedUp__6ObjectFv,
  CanBeCrushed__11FixedObjectFv,
  GetTopPos__6ObjectFv,
  GetVillagerHugRadius__6ObjectFv,
  GetWeight__6ObjectFv,
  GetWorldMatrix__6ObjectFP8LHMatrix,
  CanBeSuckedIntoVortex__6ObjectFP15LandscapeVortex,
  GetDiscipleStateIfInteractedWith__5AbodeFP16GInterfaceStatusP8Villager,
  GetWorkingPos__6ObjectFP6Object,
  GetHeightForHandAboveInteractObject__6ObjectFv,
  GetHandHelpMessageSet__6ObjectFv,
  GetHandHelpCondition__6ObjectFv,
  CallVirtualFunctionsForCreation__8WindmillFRC9MapCoords,
  Get3DType__6ObjectFv,
  GetFoodValue__6ObjectF9FOOD_TYPE,
  GetWoodValue__6ObjectFv,
  GetFoodType__6ObjectFv,
  GetImpressiveValue__6ObjectFv,
  IsSpellSeedReturnPoint__6ObjectCFv,
  IsABeliever__6ObjectFv,
  AsMultiMapFixed__13MultiMapFixedFv,
  ApplyWaterSpell__6ObjectFP10SpellWater,
  IsResourceStore__13MultiMapFixedF13RESOURCE_TYPE,
  DeleteObjectAndTakeResource__13MultiMapFixedFP6ObjectP16GInterfaceStatus,
  GetRadiusMultiplierForApplyingPotToPos__6ObjectFv,
  DoCreatureMimicAfterAddingResource__13MultiMapFixedF13RESOURCE_TYPER16GInterfaceStatus,
  GetResourceType__6ObjectFv,
  GetDefaultResource__6ObjectFv,
  SetPoisonedResource__6ObjectF13RESOURCE_TYPEi,
  SetPoisoned__6ObjectFi,
  IsLockedInInteract__6ObjectFv,
  SetDying__6ObjectFv,
  IsAttackable__6ObjectFP6Object,
  IsAllied__6ObjectFP6Object,
  IsTouching__6ObjectFRC9MapCoordsRC9MapCoords,
  IsTouching__6ObjectFRC9MapCoords,
  IsTouching__6ObjectFP6Objectf,
  StartOnFire__13MultiMapPFixedFv,
  EndOnFire__6ObjectFv,
  GetDistanceFromObject__6ObjectFP6Object,
  GetTribalPower__6ObjectF10TRIBE_TYPE,
  ValidForLockedSelectProcess__11FixedObjectFP16GInterfaceStatus,
  NetworkFriendlyStartLockedSelect__11FixedObjectFP16GInterfaceStatus,
  NetworkUnfriendlyStartLockedSelect__6ObjectFv,
  IsReadyForNetworkUnfriendlyLockedSelect__6ObjectFv,
  NetworkUnfriendlyLockedSelect__6ObjectFP21ControlHandUpdateInfo,
  GetReadyForNetworkUnfriendlyEndLockedSelect__6ObjectFv,
  IsReadyForNetworkUnfriendlyEndLockedSelect__6ObjectFv,
  NetworkUnfriendlyEndLockedSelect__6ObjectFv,
  NetworkFriendlyEndLockedSelect__6ObjectFP16GInterfaceStatus,
  ValidAsInterfaceTarget__6ObjectFv,
  ValidAsInterfaceLeashTarget__6ObjectFv,
  SelectOnlyAfterRecSystem__6ObjectFv,
  ValidForPlaceInHand__6ObjectFP16GInterfaceStatus,
  InterfaceSetInMagicHand__11FixedObjectFP16GInterfaceStatus,
  InterfaceSetOutMagicHand__6ObjectFP16GInterfaceStatus,
  ValidToRemoveFromHand__6ObjectFP16GInterfaceStatusRC9MapCoords,
  RemoveFromHand__6ObjectFP16GInterfaceStatusRC9MapCoords,
  ValidToShakeFromHand__6ObjectFv,
  InterfaceMustBeInInfluenceForInteraction__6ObjectFv,
  IsTuggable__6ObjectFv,
  ValidToApplyThisToObject__6ObjectFP16GInterfaceStatusP6Object,
  ApplyThisToObject__6ObjectFP16GInterfaceStatusP6ObjectP23GestureSystemPacketData,
  ValidToApplyThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoords,
  ApplyThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoordsP23GestureSystemPacketData,
  ValidForLockedApplyProcess__6ObjectFP16GInterfaceStatus,
  ApplyUnlockProcess__6ObjectFP16GInterfaceStatus,
  IsInterfacePowerUpWhenInHand__6ObjectCFv,
  ApplyOnlyAfterRecSystem__6ObjectFv,
  ApplyOnlyAfterReleased__6ObjectFv,
  InterfaceValidToTap__5AbodeFP16GInterfaceStatus,
  InterfaceTap__5AbodeFP16GInterfaceStatus,
  InterfaceValidToGiveObject__6ObjectFP16GInterfaceStatusP6Object,
  InterfaceGiveObject__6ObjectFP16GInterfaceStatusP6Object,
  InterfaceValidToInteractAsMapCoordsObject__6ObjectFP16GInterfaceStatus,
  InterfaceInteractAsMapCoordsObject__6ObjectFP16GInterfaceStatus,
  ThrowObjectFromHand__6ObjectFP16GInterfaceStatusi,
  ValidToSelectFightThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoords,
  ValidToApplyFightThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoords,
  SelectFightThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoords,
  ApplyFightThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoords,
  ValidToFightThisToObject__6ObjectFP16GInterfaceStatusRC9MapCoords,
  FightThisToObject__6ObjectFP16GInterfaceStatusP6Object,
  IsEffectReceiver__6ObjectFP12EffectValues,
  CanBeDestroyedBySpell__6ObjectFP5Spell,
  GetImportance__6ObjectFv,
  InitialisePhysicsFromHand__6ObjectFR7LHPointR7LHPointP16GInterfaceStatusP6Objecti,
  InitialisePhysics__6ObjectFRC7LHPointRC7LHPointP6ObjectbP16GInterfaceStatus,
  GetPhysicsConstantsType__5AbodeFv,
  SetUpPhysOb__5AbodeFP6PhysOb,
  EndPhysics__11FixedObjectFP13PhysicsObjectb,
  DropSfx__6ObjectFv,
  GetBoundingSphere__6ObjectFR7LHPointRf,
  InteractsWithPhysicsObjects__13MultiMapFixedFv,
  ChecksVerticesVObjects__5AbodeFv,
  ShouldPhysicsRaiseObjectUntilNotIntersectingThis__6ObjectFP6Object,
  PhysicallyDestroysAbodes__6ObjectFv,
  ReactToPhysicsImpact__5AbodeFP13PhysicsObjectb,
  CanBecomeAPhysicsObject__5AbodeFv,
  GetAlwaysRemainsInPhysicsInternalSystem__6ObjectFv,
  HasSunk__6ObjectFv,
  CreatureMustAvoid__13MultiMapFixedFP8Creature,
  AddToRoutePlan__6ObjectFP8RPHolderP8CreatureiPFi7Point2Dfi_v,
  GetRoutePlanRadius__6ObjectFP8Creature,
  VillagerMustAvoid__11FixedObjectFP8Villager,
  IsFireMan__6ObjectFv,
  IsARootedObject__6ObjectFv,
  GetCollideSoundType__6ObjectFv,
  IsSolidToNewAbode__13MultiMapFixedFv,
  RemoveFromGame__6ObjectFv,
  GetLandingPointCount__6ObjectFv,
  GetLandingPoint__6ObjectFUcP7LHPoint,
  GetTastiness__6ObjectFv,
  IsScary__6ObjectFv,
  GetInspectObjectPos__5AbodeFP8VillagerP9MapCoords,
  DiscipleInHandNear__5AbodeFR8VillagerR16GInterfaceStatus,
  GetSpecialPos__11FixedObjectFUlP9MapCoords,
  GetTownArtifact__11FixedObjectFv,
  IsTownArtifact__11FixedObjectFv,
  ProcessInHand__6ObjectFv,
  ProcessInInteract__6ObjectFP16GInterfaceStatus,
  GetObjectCollide__6ObjectFv,
  CalculateForceAppliedBy__6ObjectFP6Living,
  IsPushable__6ObjectFv,
  PushObject__6ObjectFP6LivingR9MapCoords,
  PushObject__6ObjectFP6Living,
  GetCarriedTreeType__6ObjectFv,
  GetFacingPitch__6ObjectFv,
  SetHeadPos__6ObjectFP9MapCoords,
  SaveObject__5AbodeFR8LHOSFileRC9MapCoords,
  IsAPotFromABuildingSite__6ObjectFv,
  GetNearestEdgeOfObject__6ObjectFP6Object,
  GetNearestPosOfObject__6ObjectFP6Object,
  GetNearestEdgeToPos__6ObjectFRC9MapCoords,
  GetNearestEdge__6ObjectFff,
  GetImmersionTexture__6ObjectFv,
  GetInHandImmersionTexture__6ObjectFv,
  ShouldFootpathsGoRound__5AbodeFv,
  InitialiseIsFixedForMapList__6ObjectFv,
  StandAnimation__6ObjectFv,
  GetCollideData__13MultiMapFixedFv,
  InsertMapObjectToCellAssumeFixed__11FixedObjectFP7MapCell,
  IsObjectFullyInMap__13MultiMapFixedFv,
  GetDoorPos__13MultiMapFixedFv,
  GetInfluence__5AbodeFv,
  IsPlaytimeStructure__13MultiMapFixedFv,
  IsPlaytimeStarted__13MultiMapFixedFv,
  AddPlaytimeVillager__13MultiMapFixedFP8Villager,
  CheckMapObject__13MultiMapFixedFv,
  GetResourceDropPosForComputerPlayer__13MultiMapFixedF13RESOURCE_TYPE,
  GetPercentBuilt__13MultiMapFixedFv,
  GetPercentRepaired__13MultiMapFixedFv,
  GetPercentRepairedFromWhenDamaged__13MultiMapFixedFv,
  IsRepaired__5AbodeFv,
  IsBuilt__5AbodeFv,
  GetPercentRepairedForNonFunctional__5AbodeFv,
  GetPercentForDrawBuilding__13MultiMapFixedFv,
  GetPercentAbodeFullWithAdults__5AbodeFv,
  GetPercentAbodeFullWithChildren__5AbodeFv,
  IsDrawBuilding__13MultiMapFixedFv,
  Built__5AbodeFv,
  Repaired__5AbodeFv,
  GetBuildingSiteWood__13MultiMapFixedFPUl,
  GetDestructionMesh__5AbodeFv,
  RemoveDamage__5AbodeFv,
  GetBuildingObject__13MultiMapFixedFv,
  IsCivic__5AbodeFv,
  GetAbodeType__5AbodeFv,
  SetPower__13MultiMapFixedFf,
  GetResourcePos__13MultiMapFixedF13RESOURCE_TYPEl,
  IsPoisonedResource__13MultiMapFixedF13RESOURCE_TYPE,
  GetResourceNearestEdge__13MultiMapFixedF13RESOURCE_TYPEP6Objecti,
  GetDesireToBeRepaired__5AbodeFv,
  AddToPlayer__13MultiMapFixedFv,
  RemoveFromPlayer__13MultiMapFixedFv,
  DoResourceAdding__5AbodeF13RESOURCE_TYPEUlP16GInterfaceStatusbRC9MapCoordsi,
  DoResourceRemoving__5AbodeF13RESOURCE_TYPEUlP16GInterfaceStatusPb,
  CalulateAmountOverMaximum__13MultiMapFixedF13RESOURCE_TYPE,
  SetTown__5AbodeFP4Town,
  RemovePotFromStructure__13MultiMapFixedFP12PotStructure,
  GetShouldNotBeAddedToPlanned__5AbodeFv,
  SetShouldNotBeAddedToPlanned__5AbodeFi,
  BuildBy__13MultiMapFixedFf,
  ConvertToPlanned__5AbodeFv,
  CreateCollideData__13MultiMapFixedFv,
  MoveAbodeToPlannedAbodes__5AbodeFv,
  DeleteDependancys__5AbodeFv,
  MakeFunctional__5AbodeFv,
  StopBeingFunctional__5AbodeFP7GPlayer,
  RestartBeingFunctional__5AbodeFv,
  CausesTownEmergencyIfDamaged__5AbodeFv,
  CanBeHiddenIn__5AbodeFv,
  GetTribe__5AbodeFv,
};

const float rdata_float_6_2831855 asm("__real@40c90fdb") = 6.2831855f;
const float rdata_float_0_00075075077 asm("__real@3a440441") = 0.00075075077f;
const float rdata_float_0_0022522523 asm("__real@3b130c31") = 0.0022522523f;
const double rdata_double_0_100000001490116119385 asm("__real@3fb999999999999a") = 0.100000001490116119385;

__attribute__((section(".bss"))) struct LH3DObject* windmill_lh3d_object_00c4cc70;
__attribute__((section(".bss"))) float windmill_float_00c4cc74;
__attribute__((section(".bss"))) float windmill_float_00c4cc78;
__attribute__((section(".bss"))) int windmill_int_00c4cc7c;

__attribute__((XOR32rr_REV))
void __fastcall Open__8WindmillFv(struct Windmill* this)
{
    asm volatile (
        "push               esi\n\t"
        "xor.s              ecx, ecx\n\t"
        "call               @Create__10LH3DObjectFQ210LH3DObject10ObjectType@4\n\t"
        "%{disp32%} mov       edx, dword ptr [?g_current_pack@LH3DMesh@@2PAULH3DPack@@A]\n\t"
        "%{disp32%} mov       dword ptr [_windmill_lh3d_object_00c4cc70], eax\n\t"
        "mov                esi, dword ptr [edx]\n\t"
        "mov                ecx, 0x00000085\n\t"
        "cmp.s              esi, ecx\n\t"
        "%{disp8%} jg         LAB__addr_0x004059a0\n\t"
        "xor.s              ecx, ecx\n"
        "LAB__addr_0x004059a0:\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + ecx * 0x4 + 0x04]\n\t"
        "mov                esi, dword ptr [eax]\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, eax\n\t"
        "call               dword ptr [esi + 0xf4]\n\t"
        "%{disp32%} mov       ecx, dword ptr [_windmill_lh3d_object_00c4cc70]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "mov                edx, 0x00000001\n\t"
        "pop                esi\n\t"
        "%{disp8%} jmp        dword ptr [eax + 0x58]"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

void __fastcall Close__8WindmillFv(struct Windmill* this)
{
    asm volatile (
        "%{disp32%} mov       ecx, dword ptr [_windmill_lh3d_object_00c4cc70]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x004059e9\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 4]\n\t"
        "%{disp32%} mov       dword ptr [_windmill_lh3d_object_00c4cc70], 0x00000000\n"
        "LAB__addr_0x004059e9:\n\t"
        "ret\n\t"
        "call               dword ptr [__imp__RegSetValueExA@4]"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

void __fastcall PreDraw__8WindmillFv(struct Windmill* this)
{
    asm volatile (
        "%{disp32%} fild      dword ptr [data_bytes + 0x4e3ec0]\n\t"
        "%{disp32%} fld       dword ptr [_windmill_float_00c4cc78]\n\t"
        "fcos\n\t"
        "fabs\n\t"
        "%{disp32%} fmul      qword ptr [__real@3fb999999999999a]\n\t"
        "fld                st(1)\n\t"
        "%{disp32%} fmul      dword ptr [__real@3b130c31]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp32%} fsubr     dword ptr [_windmill_float_00c4cc74]\n\t"
        "%{disp32%} fstp      dword ptr [_windmill_float_00c4cc74]\n\t"
        "%{disp32%} fmul      dword ptr [__real@3a440441]\n\t"
        "%{disp32%} fadd      dword ptr [_windmill_float_00c4cc78]\n\t"
        "%{disp32%} fcom      dword ptr [__real@40c90fdb]\n\t"
        "%{disp32%} fst       dword ptr [_windmill_float_00c4cc78]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x00405a55\n"
        "LAB__addr_0x00405a3b:\n\t"
        "%{disp32%} fsub      dword ptr [__real@40c90fdb]\n\t"
        "%{disp32%} fcom      dword ptr [__real@40c90fdb]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} je         LAB__addr_0x00405a3b\n\t"
        "%{disp32%} fstp      dword ptr [_windmill_float_00c4cc78]\n\t"
        "ret\n"
        "LAB__addr_0x00405a55:\n\t"
        "fstp               st(0)\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

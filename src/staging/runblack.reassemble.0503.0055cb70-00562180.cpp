#include "PlannedMultiMapFixed.h"
#include "StoragePit.h"
#include "Spell.h"
#include "SpellWithObjects.h"
#include "SpellResource.h"
#include "SpellWater.h"
#include "GameThingWithPos.h"
#include "MobileObject.h"
#include "Poo.h"
#include "FieldCrop.h"
#include "OneOffSpellSeed.h"
#include "SpellHeal.h"
#include "SpellForest.h"
#include "SpellFlock.h"
#include "SpellFlockFlying.h"
#include "SpellFlockGround.h"
#include "SpellIcon.h"
#include "Pot.h"
#include "PotStructure.h"
#include "PileResource.h"
#include "PileFood.h"
#include "PileWood.h"
#include "MobileStatic.h"
#include "VortexObjectInfo.h"
#include "SpellTeleport.h"
#include "Tree.h"
#include "TownDesireFlags.h"
#include "TownCentre.h"
#include "PlannedTownCentre.h"
#include "WorshipSite.h"
#include "ShowNeeds.h"
#include "ShowNeedsVisuals.h"
#include "Stream.h"
#include "Waterfall.h"
#include "Climate.h"
#include "WeatherThing.h"
#include "Graveyard.h"
#include "TownSpellIcon.h"
#include "Scaffold.h"
#include "Mist.h"
#include "JPSysInterface.h"
#include "PSysInterface.h"
#include "Particle3DPnt.h"
#include "Particle3DSprite.h"
#include "ParticleChainJoint.h"
#include "SpellPointInf.h"
#include "ParticleContainer.h"
#include "SpecialVillager.h"
#include "ScriptMarker.h"
#include "TotemStatue.h"
#include "Wonder.h"
#include "Whale.h"
#include "ScriptTimer.h"
#include "Rock.h"
#include "StreetLight.h"
#include "StreetLantern.h"
#include "Totem.h"
#include "HanoiBlock.h"
#include "PuzzleGame.h"
#include "GameOSFile.h"

extern "C" char sdtor_vt_PSysInterface;
extern "C" void sdtor_dtor_PSysInterface();
extern "C" char sdtor_vt_Particle3DPnt;
extern "C" void sdtor_dtor_Particle3DPnt();
extern "C" char sdtor_vt_ParticleChainJoint;
extern "C" void sdtor_dtor_ParticleChainJoint();
extern "C" void sdtor_op_del();

// win1.41 0055cbd0 mac inlined PlannedMultiMapFixed::GetSaveType(void)
uint32_t PlannedMultiMapFixed::GetSaveType()
{
    return 56;
}

// win1.41 0055cbe0 mac 10111890 PlannedMultiMapFixed::GetDebugText(void)
char* PlannedMultiMapFixed::GetDebugText()
{
    return 0;
}

// win1.41 0055cbf0 mac 103e4400 PlannedMultiMapFixed::~PlannedMultiMapFixed(void)
PlannedMultiMapFixed::~PlannedMultiMapFixed()
{
}

// win1.41 0055ccb0 mac inlined StoragePit::GetArrivePos(MapCoords *)
MapCoords* StoragePit::GetArrivePos(MapCoords* param_1)
{
    return 0;
}

// win1.41 0055ccd0 mac 101513a0 StoragePit::Get3DType(void)
LH3DObject::ObjectType StoragePit::Get3DType()
{
    return (LH3DObject::ObjectType)0;
}

// win1.41 0055cce0 mac 101513e0 StoragePit::CausesTownEmergencyIfDamaged(void)
bool StoragePit::CausesTownEmergencyIfDamaged()
{
    __asm mov eax, 1
}

// win1.41 0055ccf0 mac 10151430 StoragePit::IsCastShadowAtNight(void)
bool32_t StoragePit::IsCastShadowAtNight()
{
    return 0;
}

// win1.41 0055cd00 mac 10151470 StoragePit::CanActAsAContainer(Creature *)
bool32_t StoragePit::CanActAsAContainer(Creature* param_1)
{
    return 1;
}

// win1.41 0055cd10 mac 101514c0 StoragePit::CanBeEatenByCreature(Creature *)
bool32_t StoragePit::CanBeEatenByCreature(Creature* param_1)
{
    return 1;
}

// win1.41 0055cd20 mac 10151510 StoragePit::IsResourceStore(RESOURCE_TYPE)
bool32_t StoragePit::IsResourceStore(RESOURCE_TYPE param_1)
{
    return 1;
}

// win1.41 0055cd30 mac 10151560 StoragePit::GetSaveType(void)
uint32_t StoragePit::GetSaveType()
{
    return 8;
}

// win1.41 0055cd40 mac 101515a0 StoragePit::GetDebugText(void)
char* StoragePit::GetDebugText()
{
    return "StoragePit";
}

// win1.41 0055cd50 mac 10153360 StoragePit::_dt(void)
StoragePit::~StoragePit()
{
}

// win1.41 0055cd80 mac inlined Spell::GetSpellCastPos(MapCoords *)
void Spell::GetSpellCastPos(MapCoords* param_1)
{
}

// win1.41 0055cdb0 mac 103b1c00 Spell::GetLife(void)
float Spell::GetLife()
{
    return 0;
}

// win1.41 0055cdc0 mac 103b1c30 Spell::IsFunctional(void)
bool Spell::IsFunctional()
{
    return 0;
}

// win1.41 0055cdf0 mac 100d40a0 Spell::GetPlayer(void)
GPlayer* Spell::GetPlayer()
{
    return 0;
}

// win1.41 0055ce00 mac 103b1ce0 Spell::HasEnoughChantsAndLifeForRecast(void)
void Spell::HasEnoughChantsAndLifeForRecast()
{
}

// win1.41 0055ce10 mac 103b1d30 Spell::UpdateStruckReaction(void)
void Spell::UpdateStruckReaction()
{
}

// win1.41 0055ce20 mac 103b1d70 Spell::SetUpDestroyedReaction(void)
void Spell::SetUpDestroyedReaction()
{
}

// win1.41 0055ce30 mac 103b1db0 Spell::GetCreatureCastOn(void)
uint32_t Spell::GetCreatureCastOn()
{
    return 0;
}

// win1.41 0055ce40 mac 10280a00 Spell::CloseDown(void)
void Spell::CloseDown()
{
}

// win1.41 0055ce50 mac 103b1df0 Spell::IsSpell( const(void))
bool32_t Spell::IsSpell() const
{
    return 1;
}

// win1.41 0055ce60 mac 103b1e20 Spell::AdjustSpellSeedPos(MapCoords *)
void Spell::AdjustSpellSeedPos(MapCoords* param_1)
{
}

// win1.41 0055ce70 mac 103b1e60 Spell::IsSpellCreature(void)
bool Spell::IsSpellCreature()
{
    __asm xor eax, eax
}

// win1.41 0055ce80 mac 103b1ea0 Spell::IsSpellStormAndTornado(void)
bool Spell::IsSpellStormAndTornado()
{
    __asm xor eax, eax
}

// win1.41 0055ce90 mac 103b1ee0 Spell::SetMaxObjectsToCreate(long)
void Spell::SetMaxObjectsToCreate(int param_1)
{
}

// win1.41 0055cea0 mac inlined SpellWithObjects::GetMaxObjectsToCreate(void)
int SpellWithObjects::GetMaxObjectsToCreate()
{
    return -1;
}

// win1.41 0055ceb0 mac 103b1f60 Spell::GetCreatureBeliefListType(void)
uint32_t Spell::GetCreatureBeliefListType()
{
    return 1;
}

// win1.41 0055cec0 mac 103b1fa0 Spell::GetCreatureBeliefType(void)
uint32_t Spell::GetCreatureBeliefType()
{
    return 10;
}

// win1.41 0055ced0 mac 103b1fe0 Spell::CanBeFrighteningToCreature(Creature *)
bool32_t Spell::CanBeFrighteningToCreature(Creature* param_1)
{
    return 1;
}

// win1.41 0055cee0 mac 103b2030 Spell::IsSuitableForCreatureAction(void)
bool32_t Spell::IsSuitableForCreatureAction()
{
    return 1;
}

// win1.41 0055cef0 mac 103b2070 Spell::GetOrigin(void)
uint32_t Spell::GetOrigin()
{
    return 2;
}

// win1.41 0055cf00 mac 103b20a0 Spell::GetText(void)
const char* Spell::GetText()
{
    return "Spell";
}

// win1.41 0055cf10 mac 103b20d0 Spell::GetReactionPower(void)
float Spell::GetReactionPower()
{
    return 0;
}

// win1.41 0055cf20 mac 103b2120 Spell::GetImpressiveIntensity(IMPRESSIVE_TYPE)
float Spell::GetImpressiveIntensity(IMPRESSIVE_TYPE param_1)
{
    return 0;
}

// win1.41 0055cf50 mac 103b1b10 SpellWithObjects::GetSetObjectsDyingOnCloseDown(void)
bool SpellWithObjects::GetSetObjectsDyingOnCloseDown()
{
    return true;
}

// win1.41 0055cf60 mac 10519d90 SpellWithObjects::GetSaveType(void)
uint32_t SpellWithObjects::GetSaveType()
{
    return 20;
}

// win1.41 0055cf70 mac 10519dd0 SpellWithObjects::GetDebugText(void)
char* SpellWithObjects::GetDebugText()
{
    return "SpellWithObjects";
}

// win1.41 0055cf80 mac 1030e320 SpellWithObjects::_dt(void)
SpellWithObjects::~SpellWithObjects()
{
}

// win1.41 0055cfb0 mac 1051fe70 SpellResource::GetSaveType(void)
uint32_t SpellResource::GetSaveType()
{
    return 10;
}

// win1.41 0055cfc0 mac 1051feb0 SpellResource::GetDebugText(void)
char* SpellResource::GetDebugText()
{
    return "SpellResource";
}

// win1.41 0055cfd0 mac 1051fdd0 SpellResource::_dt(void)
SpellResource::~SpellResource()
{
}

// win1.41 0055d000 mac 1051ef10 SpellWater::GetSaveType(void)
uint32_t SpellWater::GetSaveType()
{
    return 12;
}

// win1.41 0055d010 mac 1051ef50 SpellWater::GetDebugText(void)
char* SpellWater::GetDebugText()
{
    return "SpellWater";
}

// win1.41 0055d020 mac 1051ee70 SpellWater::_dt(void)
SpellWater::~SpellWater()
{
}

// win1.41 0055d050 mac 101bb2c0 GameThingWithPos::GameThingWithPos(void)
GameThingWithPos::GameThingWithPos()
{
}

// win1.41 0055d080 mac 103bdd30 MobileObject::_dt(void)
MobileObject::~MobileObject()
{
}

// win1.41 0055d0a0 mac 103be1b0 Poo::GetSaveType(void)
uint32_t Poo::GetSaveType()
{
    return 107;
}

// win1.41 0055d0b0 mac 103be1e0 Poo::GetDebugText(void)
char* Poo::GetDebugText()
{
    return "Poo";
}

// win1.41 0055d0c0 mac 103be130 Poo::_dt(void)
Poo::~Poo()
{
}

// win1.41 0055d0e0 mac 103baae0 FieldCrop::PhysicsEditorCreate(int)
void FieldCrop::PhysicsEditorCreate(int param_1)
{
}

// win1.41 0055d0f0 mac 103bab20 FieldCrop::GetSaveType(void)
uint32_t FieldCrop::GetSaveType()
{
    return 108;
}

// win1.41 0055d100 mac 103bab60 FieldCrop::GetDebugText(void)
char* FieldCrop::GetDebugText()
{
    return "FieldCrop";
}

// win1.41 0055d110 mac 103bb4e0 FieldCrop::_dt(void)
FieldCrop::~FieldCrop()
{
}

// win1.41 0055d130 mac 10526310 OneOffSpellSeed::CastOneOffSpellSeed(void)
SpellSeed* OneOffSpellSeed::CastOneOffSpellSeed()
{
    return 0;
}

// win1.41 0055d140 mac 10526350 OneOffSpellSeed::GetComputerSeen(void)
bool OneOffSpellSeed::GetComputerSeen()
{
    return 0;
}

// win1.41 0055d150 mac 10526390 OneOffSpellSeed::GetSaveType(void)
uint32_t OneOffSpellSeed::GetSaveType()
{
    return 37;
}

// win1.41 0055d160 mac 105263d0 OneOffSpellSeed::GetDebugText(void)
char* OneOffSpellSeed::GetDebugText()
{
    return "OneOffSpellSeed";
}

// win1.41 0055d170 mac 10526280 OneOffSpellSeed::_dt(void)
OneOffSpellSeed::~OneOffSpellSeed()
{
}

// win1.41 0055d190 mac 10533dc0 SpellHeal::GetSaveType(void)
uint32_t SpellHeal::GetSaveType()
{
    return 18;
}

// win1.41 0055d1a0 mac 10533e00 SpellHeal::GetDebugText(void)
char* SpellHeal::GetDebugText()
{
    return "SpellHeal";
}

// win1.41 0055d1b0 mac 10533d20 SpellHeal::_dt(void)
SpellHeal::~SpellHeal()
{
}

// win1.41 0055d1e0 mac 1051ff90 SpellForest::CloseDown(void)
void SpellForest::CloseDown()
{
}

// win1.41 0055d200 mac 10520050 SpellForest::GetSaveType(void)
uint32_t SpellForest::GetSaveType()
{
    return 15;
}

// win1.41 0055d210 mac 10520090 SpellForest::GetDebugText(void)
char* SpellForest::GetDebugText()
{
    return "SpellForest";
}

// win1.41 0055d220 mac 1051fef0 SpellForest::_dt(void)
SpellForest::~SpellForest()
{
}

// win1.41 0055d250 mac 1030e480 SpellFlock::_dt(void)
SpellFlock::~SpellFlock()
{
}

// win1.41 0055d280 mac 1051ec50 SpellFlockFlying::GetSaveType(void)
uint32_t SpellFlockFlying::GetSaveType()
{
    return 13;
}

// win1.41 0055d290 mac 1051ec90 SpellFlockFlying::GetDebugText(void)
char* SpellFlockFlying::GetDebugText()
{
    return "SpellFlockFlying";
}

// win1.41 0055d2a0 mac 1051dac0 SpellFlockFlying::_dt(void)
SpellFlockFlying::~SpellFlockFlying()
{
}

// win1.41 0055d2d0 mac 1051bf40 SpellFlockGround::GetSaveType(void)
uint32_t SpellFlockGround::GetSaveType()
{
    return 14;
}

// win1.41 0055d2e0 mac 1051bf80 SpellFlockGround::GetDebugText(void)
char* SpellFlockGround::GetDebugText()
{
    return "SpellFlockGround";
}

// win1.41 0055d2f0 mac 1051bea0 SpellFlockGround::_dt(void)
SpellFlockGround::~SpellFlockGround()
{
}

// win1.41 0055d370 mac 10525d20 SpellIcon::CastSpellIcon(void)
SpellIcon* SpellIcon::CastSpellIcon()
{
    return 0;
}

// win1.41 0055d380 mac inlined SpellIcon::SetSpecularColor(LH3DColor)
void SpellIcon::SetSpecularColor(LH3DColor param_1)
{
}

// // win1.41 0055d390 mac 10525da0 SpellIcon::GetSpecularColor(void)
// LH3DColor SpellIcon::GetSpecularColor()
// {
//     return LH3DColor();
// }

// win1.41 0055d3a0 mac 1049e650 SpellIcon::GetWorshipSite(void)
WorshipSite* SpellIcon::GetWorshipSite()
{
    return 0;
}

// win1.41 0055d3b0 mac 10525de0 SpellIcon::IsRepaired(void)
bool SpellIcon::IsRepaired()
{
    return 0;
}

// win1.41 0055d3d0 mac 100c7990 SpellIcon::IsBuilt(void)
bool SpellIcon::IsBuilt()
{
    return 0;
}

// win1.41 0055d400 mac 10525e50 SpellIcon::IsSpellSeedReturnPoint( const(void))
bool SpellIcon::IsSpellSeedReturnPoint() const
{
    __asm mov eax, 1
}

// win1.41 0055d410 mac 10525e90 SpellIcon::ValidAsInterfaceLeashTarget(void)
bool32_t SpellIcon::ValidAsInterfaceLeashTarget()
{
    return 0;
}

// win1.41 0055d420 mac 10525ee0 SpellIcon::GetCreatureBeliefType(void)
uint32_t SpellIcon::GetCreatureBeliefType()
{
    return 17;
}

// win1.41 0055d430 mac 10525f20 SpellIcon::CanBeFrighteningToCreature(Creature *)
bool32_t SpellIcon::CanBeFrighteningToCreature(Creature* param_1)
{
    return 0;
}

// win1.41 0055d440 mac 10525f70 SpellIcon::GetMesh( const(void))
int SpellIcon::GetMesh() const
{
    return 0;
}

// win1.41 0055d450 mac 10525fd0 SpellIcon::IsSpellIcon(void)
bool32_t SpellIcon::IsSpellIcon()
{
    return 1;
}

// win1.41 0055d460 mac 10526010 SpellIcon::GetSaveType(void)
uint32_t SpellIcon::GetSaveType()
{
    return 129;
}

// win1.41 0055d470 mac 10526050 SpellIcon::GetDebugText(void)
char* SpellIcon::GetDebugText()
{
    return "SpellIcon";
}

// win1.41 0055d480 mac 10525750 SpellIcon::_dt(void)
SpellIcon::~SpellIcon()
{
}

// win1.41 0055d4c0 mac 100d32d0 Pot::GetResourceType(void)
RESOURCE_TYPE Pot::GetResourceType()
{
    return (RESOURCE_TYPE)0;
}

// win1.41 0055d4d0 mac 10116190 Pot::GetDefaultResource(void)
int Pot::GetDefaultResource()
{
    return 0;
}

// win1.41 0055d4e0 mac 1000ea20 Pot::IsPoisoned(void)
bool32_t Pot::IsPoisoned()
{
    return 0;
}

// win1.41 0055d4f0 mac 101161d0 Pot::IsSpeedUp(void)
bool32_t Pot::IsSpeedUp()
{
    return 0;
}

// win1.41 0055d500 mac 10116210 Pot::IsPot(void)
bool32_t Pot::IsPot()
{
    return 1;
}

// win1.41 0055d510 mac 100011f0 Pot::SetPoisoned(int)
void Pot::SetPoisoned(int param_1)
{
}

// win1.41 0055d530 mac inlined PotStructure::SetSpeedUp(int)
void PotStructure::SetSpeedUp(int param_1)
{
}

// win1.41 0055d550 mac 10116280 Pot::SetPoisonedResource(RESOURCE_TYPE, int)
void Pot::SetPoisonedResource(RESOURCE_TYPE param_1, int param_2)
{
}

// win1.41 0055d580 mac 101162d0 Pot::GetCreatureBeliefType(void)
uint32_t Pot::GetCreatureBeliefType()
{
    return 16;
}

// win1.41 0055d590 mac 10116310 Pot::IsAPotFromABuildingSite(void)
bool Pot::IsAPotFromABuildingSite()
{
    return 0;
}

// win1.41 0055d5a0 mac 10116350 Pot::GetSaveType(void)
uint32_t Pot::GetSaveType()
{
    return 88;
}

// win1.41 0055d5b0 mac 10116380 Pot::GetDebugText(void)
char* Pot::GetDebugText()
{
    return "Pot";
}

// win1.41 0055d5c0 mac 1011c9c0 Pot::_dt(void)
Pot::~Pot()
{
}

// win1.41 0055d620 mac 10115fe0 PotStructure::SetPlayer(GPlayer *)
void PotStructure::SetPlayer(GPlayer* param_1)
{
}

// win1.41 0055d630 mac 10116020 PotStructure::SetMultiMapFixed(MultiMapFixed *)
void PotStructure::SetMultiMapFixed(MultiMapFixed* param_1)
{
}

// win1.41 0055d640 mac 101160a0 PotStructure::CanBeThrownByPlayer(void)
bool32_t PotStructure::CanBeThrownByPlayer()
{
    return 0;
}

// win1.41 0055d650 mac 101160f0 PotStructure::_dt(void)
PotStructure::~PotStructure()
{
}

// win1.41 0055d680 mac 1011d530 PileResource::IsLockedInInteract(void)
bool PileResource::IsLockedInInteract()
{
    __asm mov eax, 1
}

// win1.41 0055d690 mac 1011d570 PileFood::IsPileFood(void)
bool32_t PileFood::IsPileFood()
{
    return 1;
}

// win1.41 0055d6a0 mac 1011d4b0 PileWood::GetSaveType(void)
uint32_t PileWood::GetSaveType()
{
    return 90;
}

// win1.41 0055d6b0 mac 1011d4f0 PileWood::GetDebugText(void)
char* PileWood::GetDebugText()
{
    return "PileWood";
}

// win1.41 0055d6c0 mac 10116ea0 PileWood::_dt(void)
PileWood::~PileWood()
{
}

// win1.41 0055d710 mac 103af0f0 MobileStatic::GetCreatureMimicType(void)
uint32_t MobileStatic::GetCreatureMimicType()
{
    return 8;
}

// win1.41 0055d720 mac 103af140 MobileStatic::PhysicsEditorCreate(int)
void MobileStatic::PhysicsEditorCreate(int param_1)
{
}

// win1.41 0055d730 mac 103c12f0 MobileStatic::ValidForPlaceInHand(GInterfaceStatus *)
bool32_t MobileStatic::ValidForPlaceInHand(GInterfaceStatus* param_1)
{
    return 1;
}

// win1.41 0055d740 mac 103b9720 MobileStatic::GetSaveType(void)
uint32_t MobileStatic::GetSaveType()
{
    return 84;
}

// win1.41 0055d750 mac 103b9760 MobileStatic::GetDebugText(void)
char* MobileStatic::GetDebugText()
{
    return "MobileStatic";
}

// win1.41 0055d760 mac 103c0dd0 MobileStatic::_dt(void)
MobileStatic::~MobileStatic()
{
}

// win1.41 0055d810 mac 103b2c70 VortexObjectInfo::GetSaveType(void)
uint32_t VortexObjectInfo::GetSaveType()
{
    return 202;
}

// win1.41 0055d820 mac 103b2cb0 VortexObjectInfo::GetDebugText(void)
char* VortexObjectInfo::GetDebugText()
{
    return "VortexObjectInfo";
}

// win1.41 0055d830 mac 103b2be0 VortexObjectInfo::_dt(void)
VortexObjectInfo::~VortexObjectInfo()
{
}

// win1.41 0055d850 mac 103b1a90 SpellTeleport::GetSaveType(void)
uint32_t SpellTeleport::GetSaveType()
{
    return 21;
}

// win1.41 0055d860 mac 103b1ad0 SpellTeleport::GetDebugText(void)
char* SpellTeleport::GetDebugText()
{
    return "SpellTeleport";
}

// win1.41 0055d870 mac 103b19e0 SpellTeleport::_dt(void)
SpellTeleport::~SpellTeleport()
{
}

// win1.41 0055d8a0 mac 101594d0 Tree::GetMesh( const(void))
int Tree::GetMesh() const
{
    return 0;
}

// win1.41 0055d8b0 mac 10159520 Tree::CanBePickedUp(void)
bool Tree::CanBePickedUp()
{
    return 0;
}

// win1.41 0055d8c0 mac 10159560 Tree::GetPlayer(void)
GPlayer* Tree::GetPlayer()
{
    return 0;
}

// win1.41 0055d8d0 mac 10159590 Tree::GetReactionPower(void)
float Tree::GetReactionPower()
{
    return 0;
}

// win1.41 0055d8e0 mac 101595f0 Tree::CastTree(void)
Tree* Tree::CastTree()
{
    return 0;
}

// win1.41 0055d8f0 mac 10159620 Tree::IsResourceStore(RESOURCE_TYPE)
bool32_t Tree::IsResourceStore(RESOURCE_TYPE param_1)
{
    return 0;
}

// win1.41 0055d900 mac 10159670 Tree::GetCarriedTreeType(void)
uint32_t Tree::GetCarriedTreeType()
{
    return 0;
}

// win1.41 0055d910 mac 100f0c30 Tree::GetForest(void)
Forest* Tree::GetForest()
{
    return 0;
}

// win1.41 0055d920 mac inlined Tree::IsTree_0(Creature *)
bool32_t Tree::IsTree(Creature* param_1)
{
    return 1;
}

// win1.41 0055d930 mac 10159740 Tree::CanBePlayedWithByCreature(Creature *)
bool32_t Tree::CanBePlayedWithByCreature(Creature* param_1)
{
    return 1;
}

// win1.41 0055d940 mac 10159790 Tree::BenefitsFromHavingWaterSprinkledOnIt(Creature *)
bool32_t Tree::BenefitsFromHavingWaterSprinkledOnIt(Creature* param_1)
{
    return 1;
}

// win1.41 0055d950 mac 101597f0 Tree::GetCreatureBeliefType(void)
uint32_t Tree::GetCreatureBeliefType()
{
    return 5;
}

// win1.41 0055d960 mac 10159830 Tree::GetCreatureMimicType(void)
uint32_t Tree::GetCreatureMimicType()
{
    return 6;
}

// win1.41 0055d970 mac 10159870 Tree::CanBeUsedForBuilding(Creature *)
bool32_t Tree::CanBeUsedForBuilding(Creature* param_1)
{
    return 1;
}

// win1.41 0055d980 mac 101598c0 Tree::CanBeUsedForRepair(Creature *)
bool32_t Tree::CanBeUsedForRepair(Creature* param_1)
{
    return 1;
}

// win1.41 0055d990 mac 10159900 Tree::CanBeDestroyedByStoning(Creature *)
bool32_t Tree::CanBeDestroyedByStoning(Creature* param_1)
{
    return 0;
}

// win1.41 0055d9a0 mac 10159950 Tree::CanBeAttackedByCreature(Creature *)
bool32_t Tree::CanBeAttackedByCreature(Creature* param_1)
{
    return 1;
}

// win1.41 0055d9b0 mac 101599a0 Tree::CanBeThrownInTheSeaPlayfully(Creature *)
bool32_t Tree::CanBeThrownInTheSeaPlayfully(Creature* param_1)
{
    return 1;
}

// win1.41 0055d9c0 mac 101599f0 Tree::IsAnyKindOfTree(void)
bool32_t Tree::IsAnyKindOfTree()
{
    return 1;
}

// win1.41 0055d9d0 mac inlined Tree::IsTree_1(void)
bool32_t Tree::IsTree()
{
    return 1;
}

// win1.41 0055d9e0 mac 10159a30 Tree::HandShouldFeelWithMeshIntersect(void)
bool32_t Tree::HandShouldFeelWithMeshIntersect()
{
    return 0;
}

// win1.41 0055d9f0 mac 10159a80 Tree::GetComputerSeen(void)
bool Tree::GetComputerSeen()
{
    return 0;
}

// win1.41 0055da10 mac 10159b10 Tree::IsCastShadowAtNight(void)
bool32_t Tree::IsCastShadowAtNight()
{
    return 1;
}

// win1.41 0055da20 mac 10159b50 Tree::GetSaveType(void)
uint32_t Tree::GetSaveType()
{
    return 79;
}

// win1.41 0055da30 mac 10159b80 Tree::GetDebugText(void)
char* Tree::GetDebugText()
{
    return "Tree";
}

// win1.41 0055da40 mac 10159150 Tree::_dt(void)
Tree::~Tree()
{
}

// win1.41 0055da70 mac 103540e0 TownDesireFlags::GetTown(void)
Town* TownDesireFlags::GetTown()
{
    return 0;
}

// win1.41 0055da80 mac 1055bf60 TownDesireFlags::GetMesh( const(void))
int TownDesireFlags::GetMesh() const
{
    return 0;
}

// win1.41 0055da90 mac 1055bfa0 TownDesireFlags::SaveObject(LHOSFile &, MapCoords const &)
uint32_t TownDesireFlags::SaveObject(LHOSFile& file, const MapCoords& coords)
{
    return 0;
}

// win1.41 0055daa0 mac 1055bff0 TownDesireFlags::IsTownDesireFlag(void)
bool32_t TownDesireFlags::IsTownDesireFlag()
{
    return 1;
}

// win1.41 0055dab0 mac 1055c030 TownDesireFlags::IsEffectReceiver(EffectValues *)
bool32_t TownDesireFlags::IsEffectReceiver(EffectValues* param_1)
{
    return 0;
}

// win1.41 0055dac0 mac 1055c080 TownDesireFlags::GetSaveType(void)
uint32_t TownDesireFlags::GetSaveType()
{
    return 76;
}

// win1.41 0055dad0 mac 1055c0c0 TownDesireFlags::GetDebugText(void)
char* TownDesireFlags::GetDebugText()
{
    return "TownDesireFlags";
}

// win1.41 0055dae0 mac 1055db90 TownDesireFlags::_dt(void)
TownDesireFlags::~TownDesireFlags()
{
}

// win1.41 0055db10 mac 1055bcb0 TownCentre::InterfaceValidToTap(GInterfaceStatus *)
uint32_t TownCentre::InterfaceValidToTap(GInterfaceStatus* param_1)
{
    return 0;
}

// win1.41 0055db20 mac 1055bd00 TownCentre::Get3DType(void)
LH3DObject::ObjectType TownCentre::Get3DType()
{
    return (LH3DObject::ObjectType)0;
}

// win1.41 0055db30 mac 1055bd40 TownCentre::CausesTownEmergencyIfDamaged(void)
bool TownCentre::CausesTownEmergencyIfDamaged()
{
    __asm mov eax, 1
}

// win1.41 0055db40 mac 1055bd90 TownCentre::CanActAsAContainer(Creature *)
bool32_t TownCentre::CanActAsAContainer(Creature* param_1)
{
    return 0;
}

// win1.41 0055db50 mac 1055bde0 TownCentre::IsStoragePit(Creature *)
bool32_t TownCentre::IsStoragePit(Creature* param_1)
{
    return 0;
}

// win1.41 0055db60 mac 1055be20 TownCentre::IsCastShadowAtNight(void)
bool32_t TownCentre::IsCastShadowAtNight()
{
    return 0;
}

// win1.41 0055db70 mac 1055be60 TownCentre::IsTownCentre(void)
bool32_t TownCentre::IsTownCentre()
{
    return 1;
}

// win1.41 0055db80 mac 1055bea0 TownCentre::CanBeHiddenIn(void)
bool TownCentre::CanBeHiddenIn()
{
    __asm xor eax, eax
}

// win1.41 0055db90 mac 1055bee0 TownCentre::GetSaveType(void)
uint32_t TownCentre::GetSaveType()
{
    return 96;
}

// win1.41 0055dba0 mac 1055bf20 TownCentre::GetDebugText(void)
char* TownCentre::GetDebugText()
{
    return "TownCentre";
}

// win1.41 0055dbb0 mac 1055ba70 TownCentre::_dt(void)
TownCentre::~TownCentre()
{
}

// win1.41 0055dbf0 mac 10559920 PlannedTownCentre::GetSaveType(void)
uint32_t PlannedTownCentre::GetSaveType()
{
    return 98;
}

// win1.41 0055dc00 mac 10559960 PlannedTownCentre::GetDebugText(void)
char* PlannedTownCentre::GetDebugText()
{
    return "PlannedTownCentre";
}

// win1.41 0055dc10 mac 10559840 PlannedTownCentre::_dt(void)
PlannedTownCentre::~PlannedTownCentre()
{
}

// win1.41 0055dc30 mac inlined WorshipSite::GetInteractPos(LHPoint *)
void WorshipSite::GetInteractPos(LHPoint* param_1)
{
}

// win1.41 0055dc50 mac 105b3d80 WorshipSite::RemoveDance(void)
void WorshipSite::RemoveDance()
{
}

// win1.41 0055dc60 mac 105b3dc0 WorshipSite::InteractsWithPhysicsObjects(void)
bool WorshipSite::InteractsWithPhysicsObjects()
{
    return 0;
}

// win1.41 0055dc70 mac 105b3e10 WorshipSite::GetAbodeType(void)
ABODE_TYPE WorshipSite::GetAbodeType()
{
    return (ABODE_TYPE)0;
}

// win1.41 0055dc80 mac 105b3e50 WorshipSite::IsSuitableForCreatureAction(void)
bool32_t WorshipSite::IsSuitableForCreatureAction()
{
    return 0;
}

// win1.41 0055dc90 mac inlined WorshipSite::IsWorshipSite_0(Creature *)
bool32_t WorshipSite::IsWorshipSite(Creature* param_1)
{
    return 1;
}

// win1.41 0055dca0 mac inlined WorshipSite::IsWorshipSite_1(void)
bool32_t WorshipSite::IsWorshipSite()
{
    return 1;
}

// win1.41 0055dcb0 mac 105b3f30 WorshipSite::GetWorshipSite(void)
WorshipSite* WorshipSite::GetWorshipSite()
{
    return 0;
}

// win1.41 0055dcc0 mac 105b3f70 WorshipSite::GetMesh( const(void))
int WorshipSite::GetMesh() const
{
    return 0;
}

// win1.41 0055dcd0 mac 105b3fc0 WorshipSite::GetSaveType(void)
uint32_t WorshipSite::GetSaveType()
{
    return 60;
}

// win1.41 0055dce0 mac 105b4000 WorshipSite::GetDebugText(void)
char* WorshipSite::GetDebugText()
{
    return "WorshipSite";
}

// win1.41 0055dcf0 mac 105b3620 WorshipSite::_dt(void)
WorshipSite::~WorshipSite()
{
}

// win1.41 0055dd20 mac 10146330 ShowNeeds::GetSaveType(void)
uint32_t ShowNeeds::GetSaveType()
{
    return 62;
}

// win1.41 0055dd30 mac 10146370 ShowNeeds::GetDebugText(void)
char* ShowNeeds::GetDebugText()
{
    return "ShowNeeds";
}

// win1.41 0055dd40 mac 101462a0 ShowNeeds::_dt(void)
ShowNeeds::~ShowNeeds()
{
}

// win1.41 0055dd60 mac 101448f0 ShowNeedsVisuals::GetMesh( const(void))
int ShowNeedsVisuals::GetMesh() const
{
    return 0;
}

// win1.41 0055dd70 mac 101449a0 ShowNeedsVisuals::SetScale(float)
void ShowNeedsVisuals::SetScale(float param_1)
{
}

// win1.41 0055dd80 mac 101449e0 ShowNeedsVisuals::GetScale(void)
float ShowNeedsVisuals::GetScale()
{
    return 0;
}

// win1.41 0055dd90 mac 10144a20 ShowNeedsVisuals::GetText(void)
const char* ShowNeedsVisuals::GetText()
{
    return "ShowNeedsVisuals";
}

// win1.41 0055dda0 mac 10144a60 ShowNeedsVisuals::SaveObject(LHOSFile &, MapCoords const &)
uint32_t ShowNeedsVisuals::SaveObject(LHOSFile& file, const MapCoords& coords)
{
    return 0;
}

// win1.41 0055ddb0 mac 10144ab0 ShowNeedsVisuals::GetSaveType(void)
uint32_t ShowNeedsVisuals::GetSaveType()
{
    return 61;
}

// win1.41 0055ddc0 mac 10144af0 ShowNeedsVisuals::GetDebugText(void)
char* ShowNeedsVisuals::GetDebugText()
{
    return "ShowNeedsVisuals";
}

// win1.41 0055ddd0 mac 10144860 ShowNeedsVisuals::_dt(void)
ShowNeedsVisuals::~ShowNeedsVisuals()
{
}

// win1.41 0055de00 mac 101551e0 GStream::GetSaveType(void)
uint32_t GStream::GetSaveType()
{
    return 71;
}

// win1.41 0055de10 mac 10155220 GStream::GetDebugText(void)
char* GStream::GetDebugText()
{
    return "GStream";
}

// win1.41 0055de20 mac 101549b0 GStream::_dt(void)
GStream::~GStream()
{
}

// win1.41 0055de40 mac 101533f0 GWaterfall::GetSaveType(void)
uint32_t GWaterfall::GetSaveType()
{
    return 64;
}

// win1.41 0055de50 mac 10153430 GWaterfall::GetDebugText(void)
char* GWaterfall::GetDebugText()
{
    return "GWaterfall";
}

// win1.41 0055de60 mac 10154270 GWaterfall::_dt(void)
GWaterfall::~GWaterfall()
{
}

// win1.41 0055dec0 mac 1059ef10 GClimate::GetSaveType(void)
uint32_t GClimate::GetSaveType()
{
    return 252;
}

// win1.41 0055ded0 mac 1059ef50 GClimate::GetDebugText(void)
char* GClimate::GetDebugText()
{
    return "GClimate";
}

// win1.41 0055dee0 mac 105a2870 GClimate::_dt(void)
GClimate::~GClimate()
{
}

// win1.41 0055df10 mac 105a3ea0 WeatherThing::IsWeather( const(void))
bool32_t WeatherThing::IsWeather() const
{
    return 1;
}

// win1.41 0055df20 mac 105a3ee0 WeatherThing::SetAffectedByWind(int)
void WeatherThing::SetAffectedByWind(int param_1)
{
}

// win1.41 0055df30 mac 105a3f20 WeatherThing::GetText(void)
const char* WeatherThing::GetText()
{
    return "WeatherThing";
}

// win1.41 0055df40 mac 105a3f60 WeatherThing::GetSaveType(void)
uint32_t WeatherThing::GetSaveType()
{
    return 67;
}

// win1.41 0055df50 mac 105a3fa0 WeatherThing::GetDebugText(void)
char* WeatherThing::GetDebugText()
{
    return "WeatherThing";
}

// win1.41 0055df60 mac 105a3e00 WeatherThing::_dt(void)
WeatherThing::~WeatherThing()
{
}

// win1.41 0055df90 mac inlined Graveyard::GetArrivePos(MapCoords *)
MapCoords* Graveyard::GetArrivePos(MapCoords* param_1)
{
    return 0;
}

// win1.41 0055dfb0 mac 100f4400 Graveyard::Get3DType(void)
LH3DObject::ObjectType Graveyard::Get3DType()
{
    return (LH3DObject::ObjectType)0;
}

// win1.41 0055dfc0 mac 100f4440 Graveyard::CanBeHiddenIn(void)
bool Graveyard::CanBeHiddenIn()
{
    __asm xor eax, eax
}

// win1.41 0055dfd0 mac 100f4480 Graveyard::CanActAsAContainer(Creature *)
bool32_t Graveyard::CanActAsAContainer(Creature* param_1)
{
    return 0;
}

// win1.41 0055dfe0 mac 100f44d0 Graveyard::IsStoragePit(Creature *)
bool32_t Graveyard::IsStoragePit(Creature* param_1)
{
    return 0;
}

// win1.41 0055dff0 mac 100f4510 Graveyard::GetSaveType(void)
uint32_t Graveyard::GetSaveType()
{
    return 81;
}

// win1.41 0055e000 mac 100f4550 Graveyard::GetDebugText(void)
char* Graveyard::GetDebugText()
{
    return "Graveyard";
}

// win1.41 0055e010 mac 100f42d0 Graveyard::_dt(void)
Graveyard::~Graveyard()
{
}

// win1.41 0055e040 mac 10560ac0 TownSpellIcon::GetTown(void)
Town* TownSpellIcon::GetTown()
{
    return 0;
}

// win1.41 0055e050 mac 10561ce0 TownSpellIcon::GetSaveType(void)
uint32_t TownSpellIcon::GetSaveType()
{
    return 85;
}

// win1.41 0055e060 mac 10561d20 TownSpellIcon::GetDebugText(void)
char* TownSpellIcon::GetDebugText()
{
    return "TownSpellIcon";
}

// win1.41 0055e070 mac 10561b50 TownSpellIcon::_dt(void)
TownSpellIcon::~TownSpellIcon()
{
}

// win1.41 0055e0f0 mac 1013e590 Scaffold::GetResourceType(void)
RESOURCE_TYPE Scaffold::GetResourceType()
{
    return (RESOURCE_TYPE)0;
}

// win1.41 0055e100 mac 1013e5d0 Scaffold::IsScaffold(void)
bool32_t Scaffold::IsScaffold()
{
    return 1;
}

// win1.41 0055e110 mac 1013e610 Scaffold::InteractsWithPhysicsObjects(void)
bool Scaffold::InteractsWithPhysicsObjects()
{
    return true;
}

// win1.41 0055e120 mac 1013e660 Scaffold::GetTown(void)
Town* Scaffold::GetTown()
{
    return 0;
}

// win1.41 0055e130 mac 1013e690 Scaffold::GetSaveType(void)
uint32_t Scaffold::GetSaveType()
{
    return 95;
}

// win1.41 0055e140 mac 1013e6d0 Scaffold::GetDebugText(void)
char* Scaffold::GetDebugText()
{
    return "Scaffold";
}

// win1.41 0055e150 mac 10143e00 Scaffold::_dt(void)
Scaffold::~Scaffold()
{
}

// win1.41 0055eb70 mac 10104680 Mist::GetPlayer(void)
GPlayer* Mist::GetPlayer()
{
    return 0;
}

// win1.41 0055eb80 mac 101046b0 Mist::GetText(void)
const char* Mist::GetText()
{
    return "Mist";
}

// win1.41 0055eb90 mac 101046e0 Mist::IsMist(void)
bool32_t Mist::IsMist()
{
    return 1;
}

// win1.41 0055eba0 mac 10104710 Mist::GetCreatureBeliefType(void)
uint32_t Mist::GetCreatureBeliefType()
{
    return 18;
}

// win1.41 0055ebb0 mac 10104750 Mist::GetSaveType(void)
uint32_t Mist::GetSaveType()
{
    return 72;
}

// win1.41 0055ebc0 mac 10104780 Mist::GetDebugText(void)
char* Mist::GetDebugText()
{
    return "Mist";
}

// win1.41 0055ebd0 mac 101045f0 Mist::_dt(void)
Mist::~Mist()
{
}

// win1.41 0055ecb0 mac 10423d40 GJPSysInterface::GetSaveType(void)
uint32_t GJPSysInterface::GetSaveType()
{
    return 165;
}

// win1.41 0055ecc0 mac 10423d80 GJPSysInterface::GetDebugText(void)
char* GJPSysInterface::GetDebugText()
{
    return "GJPSysInterface";
}

// win1.41 0055ecd0 mac 100a0c00 GJPSysInterface::CloseDown(void)
void GJPSysInterface::CloseDown()
{
}

// win1.41 0055ecf0 mac 100722f0 GJPSysInterface::SetOrigin(LHPoint const &)
void GJPSysInterface::SetOrigin(const LHPoint* param_1)
{
}

// win1.41 0055ed00 mac 10423f20 GJPSysInterface::SetOriginAndMoveAllAtoms(LHPoint const &)
void GJPSysInterface::SetOriginAndMoveAllAtoms(const LHPoint* param_1)
{
}

// win1.41 0055ed10 mac 10026c40 GJPSysInterface::GetOrigin(void)
LHPoint* GJPSysInterface::GetOrigin()
{
    return 0;
}

// win1.41 0055ed20 mac 10001030 GJPSysInterface::SetPlayer(GPlayer *)
void GJPSysInterface::SetPlayer(GPlayer* param_1)
{
}

// win1.41 0055ed30 mac 10017fc0 GJPSysInterface::SetMagnitude(float)
void GJPSysInterface::SetMagnitude(float param_1)
{
}

// win1.41 0055ed40 mac 10424080 GJPSysInterface::SetAge(float)
void GJPSysInterface::SetAge(float param_1)
{
}

// win1.41 0055ed50 mac 104240c0 GJPSysInterface::SetAlpha(unsigned char)
void GJPSysInterface::SetAlpha(uint8_t param_1)
{
}

// win1.41 0055ed60 mac inlined GJPSysInterface::AddTarget(GameThing *)
void GJPSysInterface::AddTarget(GameThing* param_1)
{
}

// win1.41 0055ed80 mac inlined GJPSysInterface::AddTarget__1(LHPoint const &)
void GJPSysInterface::AddTarget(const LHPoint& param_1)
{
}

// win1.41 0055eda0 mac inlined GJPSysInterface::Draw(float, bool)
void GJPSysInterface::Draw(float param_1, bool param_2)
{
}

// win1.41 0055edc0 mac 10026de0 GJPSysInterface::AddDrawing(float, LHPoint const &)
void GJPSysInterface::AddDrawing(float param_1, const LHPoint* param_2)
{
}

// win1.41 0055ede0 mac 103b65b0 GJPSysInterface::_dt(void)
GJPSysInterface::~GJPSysInterface()
{
}

// win1.41 0055ee30 mac 101109b0 PSysInterface::_dt(void)
PSysInterface::~PSysInterface()
{
}

__declspec(naked) void __cdecl sdtor_PSysInterface() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_PSysInterface
        call sdtor_dtor_PSysInterface
        test byte ptr [esp + 8], 1
        je short skip_PSysInterface
        push 014h
        push esi
        call sdtor_op_del
        add esp, 8
    skip_PSysInterface:
        mov eax, esi
        pop esi
        ret 4
    }
}

// win1.41 0055eef0 mac inlined Particle3DPnt::GetSaveType(void)
uint32_t Particle3DPnt::GetSaveType()
{
    return 168;
}

// win1.41 0055ef00 mac inlined Particle3DPnt::GetDebugText(void)
char* Particle3DPnt::GetDebugText()
{
    return 0;
}

// win1.41 0055ef20 mac inlined Particle3DPnt::_dt(void)
Particle3DPnt::~Particle3DPnt()
{
}

__declspec(naked) void __cdecl sdtor_Particle3DPnt() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_Particle3DPnt
        call sdtor_dtor_Particle3DPnt
        test byte ptr [esp + 8], 1
        je short skip_Particle3DPnt
        push 018h
        push esi
        call sdtor_op_del
        add esp, 8
    skip_Particle3DPnt:
        mov eax, esi
        pop esi
        ret 4
    }
}

// win1.41 0055f050 mac inlined Particle3DSprite::GetDebugText(void)
char* Particle3DSprite::GetDebugText()
{
    return 0;
}

// win1.41 0055f070 mac inlined Particle3DSprite::_dt(void)
Particle3DSprite::~Particle3DSprite()
{
}

// win1.41 0055f0c0 mac 10422d60 ParticleChainJoint::GetSaveType(void)
uint32_t ParticleChainJoint::GetSaveType()
{
    return 179;
}

// win1.41 0055f0d0 mac 10422da0 ParticleChainJoint::GetDebugText(void)
char* ParticleChainJoint::GetDebugText()
{
    return "ParticleChainJoint";
}

// win1.41 0055f0e0 mac 10422de0 ParticleChainJoint::_dt(void)
ParticleChainJoint::~ParticleChainJoint()
{
}

__declspec(naked) void __cdecl sdtor_ParticleChainJoint() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_ParticleChainJoint
        call sdtor_dtor_ParticleChainJoint
        test byte ptr [esp + 8], 1
        je short skip_ParticleChainJoint
        push 028h
        push esi
        call sdtor_op_del
        add esp, 8
    skip_ParticleChainJoint:
        mov eax, esi
        pop esi
        ret 4
    }
}

// win1.41 0055f430 mac 1041f900 SpellPointInf::GetSaveType(void)
uint32_t SpellPointInf::GetSaveType()
{
    return 184;
}

// win1.41 0055f440 mac 1041f940 SpellPointInf::GetDebugText(void)
char* SpellPointInf::GetDebugText()
{
    return "SpellPointInf";
}

// win1.41 0055f450 mac 1041f870 SpellPointInf::_dt(void)
SpellPointInf::~SpellPointInf()
{
}

// win1.41 00560f40 mac 1010fde0 GParticleContainer::GetText(void)
const char* GParticleContainer::GetText()
{
    return "GParticleContainer";
}

// win1.41 00560f50 mac 1010fe20 GParticleContainer::IsParticleContainer(void)
bool32_t GParticleContainer::IsParticleContainer()
{
    return 1;
}

// win1.41 00560f60 mac 1010fe70 GParticleContainer::GetSaveType(void)
uint32_t GParticleContainer::GetSaveType()
{
    return 110;
}

// win1.41 00560f70 mac 1010feb0 GParticleContainer::GetDebugText(void)
char* GParticleContainer::GetDebugText()
{
    return "GParticleContainer";
}

// win1.41 00560f80 mac 1010fd40 GParticleContainer::_dt(void)
GParticleContainer::~GParticleContainer()
{
}

// win1.41 00560fc0 mac 10147c80 SpecialVillager::GetSaveType(void)
uint32_t SpecialVillager::GetSaveType()
{
    return 118;
}

// win1.41 00560fd0 mac 10147cc0 SpecialVillager::GetDebugText(void)
char* SpecialVillager::GetDebugText()
{
    return "SpecialVillager";
}

// win1.41 00560fe0 mac 10147590 SpecialVillager::_dt(void)
SpecialVillager::~SpecialVillager()
{
}

// win1.41 00561010 mac 105014d0 ScriptMarker::GetText(void)
const char* ScriptMarker::GetText()
{
    return "ScriptMarker";
}

// win1.41 00561020 mac 10501510 ScriptMarker::IsScriptMarker(void)
bool32_t ScriptMarker::IsScriptMarker()
{
    return 1;
}

// win1.41 00561030 mac 10501550 ScriptMarker::PhysicsEditorCreate(int)
void ScriptMarker::PhysicsEditorCreate(int param_1)
{
}

// win1.41 00561040 mac 10501590 ScriptMarker::IsDeletedWhenReleasedFromScript(void)
bool32_t ScriptMarker::IsDeletedWhenReleasedFromScript()
{
    return 1;
}

// win1.41 00561050 mac 105015e0 ScriptMarker::GetSaveType(void)
uint32_t ScriptMarker::GetSaveType()
{
    return 124;
}

// win1.41 00561060 mac 10501620 ScriptMarker::GetDebugText(void)
char* ScriptMarker::GetDebugText()
{
    return "ScriptMarker";
}

// win1.41 00561070 mac 10501430 ScriptMarker::_dt(void)
ScriptMarker::~ScriptMarker()
{
}

// win1.41 00561090 mac 10543660 TotemStatue::IsRepaired(void)
bool TotemStatue::IsRepaired()
{
    return 0;
}

// win1.41 005610b0 mac 1001a9a0 TotemStatue::IsBuilt(void)
bool TotemStatue::IsBuilt()
{
    return 0;
}

// win1.41 005610e0 mac 10543c30 TotemStatue::GetMesh( const(void))
int TotemStatue::GetMesh() const
{
    return 0;
}

// win1.41 005610f0 mac 10543cd0 TotemStatue::GetCreatureBeliefType(void)
uint32_t TotemStatue::GetCreatureBeliefType()
{
    return 23;
}

// win1.41 00561100 mac 10543d20 TotemStatue::CanBeImpressedByCreature(Creature *)
bool32_t TotemStatue::CanBeImpressedByCreature(Creature* param_1)
{
    return 1;
}

// win1.41 00561110 mac 10543d70 TotemStatue::CanBePlayedWithByCreature(Creature *)
bool32_t TotemStatue::CanBePlayedWithByCreature(Creature* param_1)
{
    return 1;
}

// win1.41 00561120 mac 10543dc0 TotemStatue::HandShouldFeelWithMeshIntersect(void)
bool32_t TotemStatue::HandShouldFeelWithMeshIntersect()
{
    return 0;
}

// win1.41 00561130 mac 10543e10 TotemStatue::IsEffectReceiver(EffectValues *)
bool32_t TotemStatue::IsEffectReceiver(EffectValues* param_1)
{
    return 0;
}

// win1.41 00561140 mac 10543e60 TotemStatue::SaveObject(LHOSFile &, MapCoords const &)
uint32_t TotemStatue::SaveObject(LHOSFile& file, const MapCoords& coords)
{
    return 0;
}

// win1.41 00561150 mac 10543eb0 TotemStatue::IsTotemStatue(void)
bool32_t TotemStatue::IsTotemStatue()
{
    return 1;
}

// win1.41 00561160 mac 10543ef0 TotemStatue::GetSaveType(void)
uint32_t TotemStatue::GetSaveType()
{
    return 127;
}

// win1.41 00561170 mac 10543f30 TotemStatue::GetDebugText(void)
char* TotemStatue::GetDebugText()
{
    return "TotemStatue";
}

// win1.41 00561180 mac 105457d0 TotemStatue::_dt(void)
TotemStatue::~TotemStatue()
{
}

// win1.41 005611b0 mac inlined Wonder::GetArrivePos(MapCoords *)
MapCoords* Wonder::GetArrivePos(MapCoords* param_1)
{
    return 0;
}

// win1.41 005611e0 mac 10161200 Wonder::CanActAsAContainer(Creature *)
bool32_t Wonder::CanActAsAContainer(Creature* param_1)
{
    return 0;
}

// win1.41 005611f0 mac 10161250 Wonder::IsStoragePit(Creature *)
bool32_t Wonder::IsStoragePit(Creature* param_1)
{
    return 0;
}

// win1.41 00561200 mac 10161290 Wonder::GetSaveType(void)
uint32_t Wonder::GetSaveType()
{
    return 128;
}

// win1.41 00561210 mac 101612d0 Wonder::GetDebugText(void)
char* Wonder::GetDebugText()
{
    return "Wonder";
}

// win1.41 00561220 mac 10161090 Wonder::_dt(void)
Wonder::~Wonder()
{
}

// win1.41 00561270 mac 1015ff50 Whale::InteractsWithPhysicsObjects(void)
bool Whale::InteractsWithPhysicsObjects()
{
    return true;
}

// win1.41 00561280 mac 1015ff90 Whale::PhysicsEditorCreate(int)
void Whale::PhysicsEditorCreate(int param_1)
{
}

// win1.41 00561290 mac 1015ff10 Whale::CanBecomeAPhysicsObject(void)
bool Whale::CanBecomeAPhysicsObject()
{
    __asm xor eax, eax
}

// win1.41 005612a0 mac 1015ffd0 Whale::GetSaveType(void)
uint32_t Whale::GetSaveType()
{
    return 151;
}

// win1.41 005612b0 mac 10160000 Whale::GetDebugText(void)
char* Whale::GetDebugText()
{
    return "Whale";
}

// win1.41 005612c0 mac 1015fe80 Whale::_dt(void)
Whale::~Whale()
{
}

// win1.41 005612e0 mac 105061e0 ScriptTimer::GetText(void)
const char* ScriptTimer::GetText()
{
    return "ScriptTimer";
}

// win1.41 005612f0 mac 1002b150 ScriptTimer::IsScriptTimer(void)
bool32_t ScriptTimer::IsScriptTimer()
{
    return 1;
}

// win1.41 00561300 mac 105062c0 ScriptTimer::IsDeletedWhenReleasedFromScript(void)
bool32_t ScriptTimer::IsDeletedWhenReleasedFromScript()
{
    return 1;
}

// win1.41 00561310 mac 10506310 ScriptTimer::GetSaveType(void)
uint32_t ScriptTimer::GetSaveType()
{
    return 125;
}

// win1.41 00561320 mac 10506350 ScriptTimer::GetDebugText(void)
char* ScriptTimer::GetDebugText()
{
    return "ScriptTimer";
}

// win1.41 00561330 mac 10506140 ScriptTimer::_dt(void)
ScriptTimer::~ScriptTimer()
{
}

// win1.41 00561370 mac 100c41a0 Rock::InteractsWithPhysicsObjects(void)
bool Rock::InteractsWithPhysicsObjects()
{
    return true;
}

// win1.41 00561380 mac 100c41e0 Rock::GetSaveType(void)
uint32_t Rock::GetSaveType()
{
    return 111;
}

// win1.41 00561390 mac 100c4210 Rock::GetDebugText(void)
char* Rock::GetDebugText()
{
    return "Rock";
}

// win1.41 005613a0 mac 100b4de0 Rock::_dt(void)
Rock::~Rock()
{
}

// win1.41 005613d0 mac 10535700 GStreetLight::GetPlayer(void)
GPlayer* GStreetLight::GetPlayer()
{
    return 0;
}

// win1.41 005613e0 mac 10535740 GStreetLight::GetText(void)
const char* GStreetLight::GetText()
{
    return "GStreetLight";
}

// win1.41 005613f0 mac 10535780 GStreetLight::IsStreetLight(void)
bool32_t GStreetLight::IsStreetLight()
{
    return 1;
}

// win1.41 00561400 mac 105357c0 GStreetLight::GetSaveType(void)
uint32_t GStreetLight::GetSaveType()
{
    return 255;
}

// win1.41 00561410 mac 10535800 GStreetLight::GetDebugText(void)
char* GStreetLight::GetDebugText()
{
    return "GStreetLight";
}

// win1.41 00561420 mac 10535660 GStreetLight::_dt(void)
GStreetLight::~GStreetLight()
{
}

// win1.41 00561440 mac 10534740 GStreetLantern::IsStreetLantern(void)
bool32_t GStreetLantern::IsStreetLantern()
{
    return 1;
}

// win1.41 00561450 mac 10534780 GStreetLantern::GetSaveType(void)
uint32_t GStreetLantern::GetSaveType()
{
    return 254;
}

// win1.41 00561460 mac 105347c0 GStreetLantern::GetDebugText(void)
char* GStreetLantern::GetDebugText()
{
    return "GStreetLantern";
}

// win1.41 00561470 mac 105353e0 GStreetLantern::_dt(void)
GStreetLantern::~GStreetLantern()
{
}

// win1.41 00561500 mac 101336f0 Totem::CanBeImpressedByCreature(Creature *)
bool32_t Totem::CanBeImpressedByCreature(Creature* param_1)
{
    return 1;
}

// win1.41 00561510 mac 10133740 Totem::CanBePlayedWithByCreature(Creature *)
bool32_t Totem::CanBePlayedWithByCreature(Creature* param_1)
{
    return 1;
}

// win1.41 00561520 mac 10133790 Totem::IsEffectReceiver(EffectValues *)
bool32_t Totem::IsEffectReceiver(EffectValues* param_1)
{
    return 0;
}

// win1.41 00561530 mac 101337e0 Totem::IsCastShadowAtNight(void)
bool32_t Totem::IsCastShadowAtNight()
{
    return 0;
}

// win1.41 00561560 mac 105427b0 Totem::GetSaveType(void)
uint32_t Totem::GetSaveType()
{
    return 43;
}

// win1.41 00561570 mac 105427e0 Totem::GetDebugText(void)
char* Totem::GetDebugText()
{
    return "Totem";
}

// win1.41 00561580 mac 10126730 Totem::_dt(void)
Totem::~Totem()
{
}

// win1.41 005617f0 mac 1011ec50 HanoiBlock::SaveObject(LHOSFile &, MapCoords const &)
uint32_t HanoiBlock::SaveObject(LHOSFile& file, const MapCoords& coords)
{
    return 0;
}

// win1.41 00561800 mac 1011eca0 HanoiBlock::CanBecomeAPhysicsObject(void)
bool HanoiBlock::CanBecomeAPhysicsObject()
{
    return 0;
}

// win1.41 00561820 mac 1011ed30 HanoiBlock::GetInHandImmersionTexture(void)
IMMERSION_EFFECT_TYPE HanoiBlock::GetInHandImmersionTexture()
{
    return (IMMERSION_EFFECT_TYPE)0;
}

// win1.41 00561830 mac 1011ed80 HanoiBlock::GetSaveType(void)
uint32_t HanoiBlock::GetSaveType()
{
    return 48;
}

// win1.41 00561840 mac 1011edc0 HanoiBlock::GetDebugText(void)
char* HanoiBlock::GetDebugText()
{
    return "HanoiBlock";
}

// win1.41 00561850 mac 1011ebc0 HanoiBlock::_dt(void)
HanoiBlock::~HanoiBlock()
{
}

// win1.41 00561b10 mac inlined PuzzleGame::GetPos( const(MapCoords *))
MapCoords* PuzzleGame::GetPos(MapCoords* param_1) const
{
    return 0;
}

// win1.41 00561b30 mac 10133980 PuzzleGame::GetText(void)
const char* PuzzleGame::GetText()
{
    return "PuzzleGame";
}

// win1.41 00561b40 mac 101339c0 PuzzleGame::IsPuzzleGame(void)
bool32_t PuzzleGame::IsPuzzleGame()
{
    return 1;
}

// win1.41 00561b50 mac 10133a00 PuzzleGame::GetSaveType(void)
uint32_t PuzzleGame::GetSaveType()
{
    return 44;
}

// win1.41 00561b60 mac 10133a40 PuzzleGame::GetDebugText(void)
char* PuzzleGame::GetDebugText()
{
    return "PuzzleGame";
}

// win1.41 00561b70 mac 10133820 PuzzleGame::_dt(void)
PuzzleGame::~PuzzleGame()
{
}

// win1.41 00561c60 mac 103049e0 GameOSFile::ResolveAllLoads(void)
void GameOSFile::ResolveAllLoads()
{
}

// win1.41 00561e10 mac 10304650 GameOSFile::WritePtr(GameThing *)
void GameOSFile::WritePtr(GameThing* param_1)
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00732c00();
extern "C" void sdtor_opd_1();
extern "C" void jmp_addr_0x0056fa80();
extern "C" void jmp_addr_0x00606ed0();
extern "C" void jmp_addr_0x00607e10();
extern "C" void jmp_addr_0x007239b0();
extern "C" void jmp_addr_0x00726080();
extern "C" void jmp_addr_0x0066d100();
extern "C" void jmp_addr_0x0066f1a0();
extern "C" void jmp_addr_0x00608750();
extern "C" void jmp_addr_0x00636640();
extern "C" void jmp_addr_0x006759c0();
extern "C" void jmp_addr_0x00675940();
extern "C" void jmp_addr_0x00749ed0();
extern "C" void jmp_addr_0x007469d0();
extern "C" void jmp_addr_0x00743ae0();
extern "C" void jmp_addr_0x0077aa30();
extern "C" void jmp_addr_0x00734160();
extern "C" void jmp_addr_0x007713d0();
extern "C" void sdtor_dt_15();
extern "C" void jmp_addr_0x00748ad0();
extern "C" void jmp_addr_0x00748c50();
extern "C" void jmp_addr_0x006e83d0();
extern "C" void jmp_addr_0x00650c40();
extern "C" char sdtor_vt_3;
extern "C" void jmp_addr_0x006c80c0();
extern "C" void jmp_addr_0x006c9e00();
extern "C" char sdtor_vt_4;
extern "C" char sdtor_vt_5;
extern "C" void jmp_addr_0x00682fa0();
extern "C" void jmp_addr_0x0069fef0();
extern "C" void jmp_addr_0x006a2a30();
extern "C" void jmp_addr_0x006d18a0();
extern "C" void jmp_addr_0x006d4900();
extern "C" void jmp_addr_0x0071f170();
extern "C" void jmp_addr_0x00737bf0();
extern "C" void jmp_addr_0x007347c0();
extern "C" void jmp_addr_0x0041fdc0();
extern "C" void jmp_addr_0x00417b80();
extern "C" void jmp_addr_0x0066e0e0();
extern "C" void jmp_addr_0x00664380();

__declspec(naked) void __cdecl sdtor_StoragePit() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00732c00
        test byte ptr [esp + 8], 1
        je short skip_StoragePit
        push 0x000000dc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_StoragePit:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellWithObjects() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_SpellWithObjects
        push 0x000000f4
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellWithObjects:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellResource() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_SpellResource
        push 0x000000f0
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellResource:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellWater() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_SpellWater
        push 0x000000f4
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellWater:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MobileObject() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00606ed0
        test byte ptr [esp + 8], 1
        je short skip_MobileObject
        push 0x68
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_MobileObject:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Poo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00606ed0
        test byte ptr [esp + 8], 1
        je short skip_Poo
        push 0x68
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Poo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_FieldCrop() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00607e10
        test byte ptr [esp + 8], 1
        je short skip_FieldCrop
        push 0x68
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_FieldCrop:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_OneOffSpellSeed() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00606ed0
        test byte ptr [esp + 8], 1
        je short skip_OneOffSpellSeed
        push 0x7c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_OneOffSpellSeed:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellHeal() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_SpellHeal
        push 0x000000ec
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellHeal:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellForest() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_SpellForest
        push 0x000000f8
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellForest:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellFlock() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_SpellFlock
        push 0x00000110
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellFlock:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellFlockFlying() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x007239b0
        test byte ptr [esp + 8], 1
        je short skip_SpellFlockFlying
        push 0x00000120
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellFlockFlying:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellFlockGround() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_SpellFlockGround
        push 0x00000110
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellFlockGround:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellIcon() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00726080
        test byte ptr [esp + 8], 1
        je short skip_SpellIcon
        push 0x00000110
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellIcon:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Pot() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0066d100
        test byte ptr [esp + 8], 1
        je short skip_Pot
        push 0x78
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Pot:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PotStructure() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0066d100
        test byte ptr [esp + 8], 1
        je short skip_PotStructure
        push 0x00000084
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PotStructure:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PileWood() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0066f1a0
        test byte ptr [esp + 8], 1
        je short skip_PileWood
        push 0x000000b4
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PileWood:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MobileStatic() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00608750
        test byte ptr [esp + 8], 1
        je short skip_MobileStatic
        push 0x00000088
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_MobileStatic:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GBaseOnly() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00636640
        test byte ptr [esp + 8], 1
        je short skip_GBaseOnly
        push 0x5c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GBaseOnly:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_VortexObjectInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_VortexObjectInfo
        push 0x60
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_VortexObjectInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellTeleport() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_SpellTeleport
        push 0x000000f4
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellTeleport:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Tree() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00749ed0
        test byte ptr [esp + 8], 1
        je short skip_Tree
        push 0x6c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Tree:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_TownDesireFlags() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x007469d0
        test byte ptr [esp + 8], 1
        je short skip_TownDesireFlags
        push 0x00000098
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_TownDesireFlags:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_TownCentre() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00743ae0
        test byte ptr [esp + 8], 1
        je short skip_TownCentre
        push 0x000000e8
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_TownCentre:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PlannedTownCentre() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_PlannedTownCentre
        push 0x4c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PlannedTownCentre:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_WorshipSite() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0077aa30
        test byte ptr [esp + 8], 1
        je short skip_WorshipSite
        push 0x00000128
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_WorshipSite:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_ShowNeeds() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_ShowNeeds
        push 0x24
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_ShowNeeds:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_ShowNeedsVisuals() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00636640
        test byte ptr [esp + 8], 1
        je short skip_ShowNeedsVisuals
        push 0x00000094
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_ShowNeedsVisuals:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GStream() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_GStream
        push 0x28
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GStream:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GWaterfall() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00734160
        test byte ptr [esp + 8], 1
        je short skip_GWaterfall
        push 0x58
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GWaterfall:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GClimate() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x007713d0
        test byte ptr [esp + 8], 1
        je short skip_GClimate
        push 0x00000088
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GClimate:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_WeatherThing() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_WeatherThing
        push 0x00000088
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_WeatherThing:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Graveyard() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_15
        test byte ptr [esp + 8], 1
        je short skip_Graveyard
        push 0x000000c8
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Graveyard:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_TownSpellIcon() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00748ad0
        test byte ptr [esp + 8], 1
        je short skip_TownSpellIcon
        push 0x00000118
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_TownSpellIcon:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_TownCentreSpellIcon() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00748c50
        test byte ptr [esp + 8], 1
        je short skip_TownCentreSpellIcon
        push 0x00000128
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_TownCentreSpellIcon:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Scaffold() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x006e83d0
        test byte ptr [esp + 8], 1
        je short skip_Scaffold
        push 0x0000009c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Scaffold:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PlayerSubActionArgument() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_PlayerSubActionArgument
        push 0x74
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PlayerSubActionArgument:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PlayerSubAction() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00650c40
        test byte ptr [esp + 8], 1
        je short skip_PlayerSubAction
        push 0x20
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PlayerSubAction:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PlayerActionState() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_PlayerActionState
        push 0x0000028c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PlayerActionState:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GComputerAttitudeToPlayer() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_GComputerAttitudeToPlayer
        push 0x18
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GComputerAttitudeToPlayer:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GComputerSeen() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_GComputerSeen
        push 0x1c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GComputerSeen:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GComputerPlayer() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_GComputerPlayer
        push 0x000001fc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GComputerPlayer:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Mist() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_Mist
        push 0x54
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Mist:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_InfluenceRing() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_InfluenceRing
        push 0x44
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_InfluenceRing:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_RenderParticle() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_3
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_RenderParticle
        push 0x18
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_RenderParticle:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_RenderParticleGoldenShower() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x006c80c0
        test byte ptr [esp + 8], 1
        je short skip_RenderParticleGoldenShower
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_RenderParticleGoldenShower:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Particle3DSprite() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x006c9e00
        test byte ptr [esp + 8], 1
        je short skip_Particle3DSprite
        push 0x30
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_Particle3DSprite:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_SimpleBeam() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_SimpleBeam
        push 0x40
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_SimpleBeam:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_BaseAtomModifierData() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_BaseAtomModifierData
        push 0x20
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_BaseAtomModifierData:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_BaseCollectionModifierData() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_BaseCollectionModifierData
        push 0x20
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_BaseCollectionModifierData:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_Plasma() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_Plasma
        push 0x5c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_Plasma:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellPointInf() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_SpellPointInf
        push 0x34
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_SpellPointInf:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_ManaPathNew() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_ManaPathNew
        push 0x00000088
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_ManaPathNew:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_BeliefSprite() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_BeliefSprite
        push 0x30
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_BeliefSprite:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_LightSheetOnObject() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_LightSheetOnObject
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_LightSheetOnObject:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_AR_FadeOutOnceConditionTrue() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_AR_FadeOutOnceConditionTrue
        push 0x30
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_AR_FadeOutOnceConditionTrue:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_AddSoundToAtom() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_AddSoundToAtom
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_AddSoundToAtom:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_RemoveSoundFromAtom() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_RemoveSoundFromAtom
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_RemoveSoundFromAtom:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_AttatchFireBallToAtom() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00682fa0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_AttatchFireBallToAtom
        push 0x2c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_AttatchFireBallToAtom:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomDataRipple_AT_UpdateRuleGravityWithFloor() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomDataRipple_AT_UpdateRuleGravityWithFloor
        push 0x2c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomDataRipple_AT_UpdateRuleGravityWithFloor:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_BankedTurning() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_BankedTurning
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_BankedTurning:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_HandSprinkle() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0069fef0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_HandSprinkle
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_HandSprinkle:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_AddDefensiveSphere() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x006a2a30
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_AddDefensiveSphere
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_AddDefensiveSphere:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UpdateRuleShieldSpark() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UpdateRuleShieldSpark
        push 0x60
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UpdateRuleShieldSpark:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_SphereSurfaceTracer() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_SphereSurfaceTracer
        push 0x30
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_SphereSurfaceTracer:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_ForestPath() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_ForestPath
        push 0x30
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_ForestPath:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_VapourEndEffect() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_VapourEndEffect
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_VapourEndEffect:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_AddSubCollectionsToAtom() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_AddSubCollectionsToAtom
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_AddSubCollectionsToAtom:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_CreateNewBaseAtom() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_CreateNewBaseAtom
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_CreateNewBaseAtom:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_CheckShieldDeflections() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_CheckShieldDeflections
        push 0x30
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_CheckShieldDeflections:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_EmitterRule() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_EmitterRule
        push 0x2c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_EmitterRule:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_EmitterRuleLightningSprite() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_EmitterRuleLightningSprite
        push 0x34
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_EmitterRuleLightningSprite:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_WillowWisp() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_WillowWisp
        push 0x38
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_WillowWisp:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_ER_BurstFromParentAtom() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_ER_BurstFromParentAtom
        push 0x2c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_ER_BurstFromParentAtom:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_ParentAtomData_AT_ER_GlintsOnTarget() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_ParentAtomData_AT_ER_GlintsOnTarget
        push 0x34
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_ParentAtomData_AT_ER_GlintsOnTarget:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_ER_GlintsOnTarget() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_ER_GlintsOnTarget
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_ER_GlintsOnTarget:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_ER_EmitFromParentAtom() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_ER_EmitFromParentAtom
        push 0x2c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_ER_EmitFromParentAtom:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_SideSpin() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_SideSpin
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_SideSpin:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_InitialSpin() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_InitialSpin
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_InitialSpin:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_FollowTargets() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_FollowTargets
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_FollowTargets:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_FollowTargets() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_FollowTargets
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_FollowTargets:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_LightningForkFlicker() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_LightningForkFlicker
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_LightningForkFlicker:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_RemoveRuleAfterConditionTrue() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_RemoveRuleAfterConditionTrue
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_RemoveRuleAfterConditionTrue:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_OrientSpriteWithRandomAngle() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_OrientSpriteWithRandomAngle
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_OrientSpriteWithRandomAngle:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_OrientWithVelocity() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_OrientWithVelocity
        push 0x34
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_OrientWithVelocity:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_CreatureSpell() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_CreatureSpell
        push 0x2c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_CreatureSpell:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_CreatureSpellItch() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_CreatureSpellItch
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_CreatureSpellItch:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_CreatureSpellFreeze() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_CreatureSpellFreeze
        push 0x2c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_CreatureSpellFreeze:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_CreatureSpellGeneric() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_CreatureSpellGeneric
        push 0x44
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_CreatureSpellGeneric:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_CreatureSpellGeneric() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_CreatureSpellGeneric
        push 0x34
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_CreatureSpellGeneric:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_CreatureSpellCompassion() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_CreatureSpellCompassion
        push 0x2c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_CreatureSpellCompassion:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_Tornado() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x006d18a0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_Tornado
        push 0x74
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_Tornado:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_DebrisCollectionData_AT_UR_Tornado() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_DebrisCollectionData_AT_UR_Tornado
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_DebrisCollectionData_AT_UR_Tornado:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_FlyingCollectionData_AT_UR_Tornado() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_FlyingCollectionData_AT_UR_Tornado
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_FlyingCollectionData_AT_UR_Tornado:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_FlyingAtomData_AT_UR_Tornado() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_FlyingAtomData_AT_UR_Tornado
        push 0x2c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_FlyingAtomData_AT_UR_Tornado:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_CloudGather() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x006d4900
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_CloudGather
        push 0x58
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_CloudGather:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_CloudGather() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_CloudGather
        push 0x38
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_CloudGather:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_CloudMoverNew() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_CloudMoverNew
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_CloudMoverNew:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_VortexAttract() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_VortexAttract
        push 0x3c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_VortexAttract:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_Explosion() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_Explosion
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_Explosion:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_OrientSpriteWithVelocity() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_OrientSpriteWithVelocity
        push 0x38
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_OrientSpriteWithVelocity:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_AtomsAtEPTarget() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_AtomsAtEPTarget
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_AtomsAtEPTarget:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_Flocking() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_Flocking
        push 0x30
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_Flocking:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GParticleContainer() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_GParticleContainer
        push 0x40
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GParticleContainer:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpecialVillager() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0071f170
        test byte ptr [esp + 8], 1
        je short skip_SpecialVillager
        push 0x00000134
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpecialVillager:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_ScriptMarker() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_ScriptMarker
        push 0x28
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_ScriptMarker:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_TotemStatue() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00737bf0
        test byte ptr [esp + 8], 1
        je short skip_TotemStatue
        push 0x000000d8
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_TotemStatue:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Wonder() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_15
        test byte ptr [esp + 8], 1
        je short skip_Wonder
        push 0x000000c8
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Wonder:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Whale() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00606ed0
        test byte ptr [esp + 8], 1
        je short skip_Whale
        push 0x74
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Whale:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_ScriptTimer() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_ScriptTimer
        push 0x30
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_ScriptTimer:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Rock() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00608750
        test byte ptr [esp + 8], 1
        je short skip_Rock
        push 0x00000094
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Rock:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GStreetLight() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_GStreetLight
        push 0x2c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GStreetLight:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GStreetLantern() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x007347c0
        test byte ptr [esp + 8], 1
        je short skip_GStreetLantern
        push 0x64
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GStreetLantern:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GComputerSpellCast() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_GComputerSpellCast
        push 0x1c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GComputerSpellCast:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Totem() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_15
        test byte ptr [esp + 8], 1
        je short skip_Totem
        push 0x000000e4
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Totem:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PuzzleLion() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0041fdc0
        test byte ptr [esp + 8], 1
        je short skip_PuzzleLion
        push 0x00000154
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PuzzleLion:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PuzzleVillager() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_PuzzleVillager
        push 0x00000154
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PuzzleVillager:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PuzzleSheep() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_PuzzleSheep
        push 0x00000154
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PuzzleSheep:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_HanoiBlock() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00606ed0
        test byte ptr [esp + 8], 1
        je short skip_HanoiBlock
        push 0x00000080
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_HanoiBlock:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PuzzleTotem() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_15
        test byte ptr [esp + 8], 1
        je short skip_PuzzleTotem
        push 0x000000fc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PuzzleTotem:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PuzzleGrain() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0066e0e0
        test byte ptr [esp + 8], 1
        je short skip_PuzzleGrain
        push 0x000000c0
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PuzzleGrain:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PuzzleMobileObject() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00606ed0
        test byte ptr [esp + 8], 1
        je short skip_PuzzleMobileObject
        push 0x6c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PuzzleMobileObject:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PuzzleGame() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_PuzzleGame
        push 0x00000588
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PuzzleGame:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GComputerPlayerQueue() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00664380
        test byte ptr [esp + 8], 1
        je short skip_GComputerPlayerQueue
        push 0x00000128
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GComputerPlayerQueue:
        mov eax, esi
        pop esi
        ret 4
    }
}

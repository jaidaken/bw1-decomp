#include "Animal.h"
#include "FeatureInfo.h"
#include "AnimatedStaticInfo.h"
#include "MultiMapFixed.h"
#include "Feature.h"
#include "WorshipSiteUpgrade.h"
#include "AnimatedStatic.h"

// win1.41 0041a040 mac 10168030 Animal::CallVirtualFunctionsForCreation(MapCoords const &)
void Animal::CallVirtualFunctionsForCreation(const MapCoords& param_1)
{
}

// win1.41 0041a130 mac 10167d20 Animal::SaveObject(LHOSFile &, MapCoords const &)
uint32_t Animal::SaveObject(LHOSFile& file, const MapCoords& coords)
{
    return 0;
}

// win1.41 0041a240 mac 1007c570 Animal::GetFinalState( const(void))
VILLAGER_STATES Animal::GetFinalState() const
{
    return (VILLAGER_STATES)0;
}

// win1.41 0041a280 mac 10167c30 Animal::ResetStateAfterReacting(void)
void Animal::ResetStateAfterReacting()
{
}

// win1.41 0041a2b0 mac 1007c6d0 Animal::SetStateSpeed(void)
void Animal::SetStateSpeed()
{
}

// win1.41 0041a2c0 mac inlined Animal::CallExitStateFunction(VILLAGER_STATES)
uint32_t Animal::CallExitStateFunction(VILLAGER_STATES param_1)
{
    return 0;
}

// win1.41 0041a310 mac inlined Animal::CallEntryStateFunctionUc(VILLAGER_STATES)
uint32_t Animal::CallEntryStateFunction(VILLAGER_STATES param_1)
{
    return 0;
}

// win1.41 0041a370 mac inlined Animal::CallEntryStateFunctionUcUc(VILLAGER_STATES, VILLAGER_STATES)
uint32_t Animal::CallEntryStateFunction(VILLAGER_STATES param_1, VILLAGER_STATES param_2)
{
    return 0;
}

// win1.41 0041a3f0 mac 1000bfc0 Animal::SetNewWander(MapCoords const &, long, long)
void Animal::SetNewWander(const MapCoords& param_1, int param_2, int param_3)
{
}

// win1.41 0041abb0 mac 10087bd0 Animal::KeepFlockMemberWithinFlockArea(void)
uint32_t Animal::KeepFlockMemberWithinFlockArea()
{
    return 0;
}

// win1.41 0041acc0 mac 10166b90 Animal::DecideWhatToDo(void)
bool Animal::DecideWhatToDo()
{
    return 0;
}

// win1.41 0041b100 mac inlined Animal::IsStateExitFunctionSameAs( const(VILLAGER_STATES))
bool Animal::IsStateExitFunctionSameAs(VILLAGER_STATES param_1) const
{
    return 0;
}

// win1.41 0041b170 mac inlined Animal::ExitReaction(VILLAGER_STATES)
int Animal::ExitReaction(VILLAGER_STATES param_1)
{
    return 0;
}

// win1.41 0041b1b0 mac 101666a0 Animal::DestroyedByEffect(GPlayer *, float)
bool32_t Animal::DestroyedByEffect(GPlayer* param_1, float param_2)
{
    return 0;
}

// win1.41 0041b1c0 mac 101665d0 Animal::DebugShowTime(unsigned long, unsigned char, unsigned char)
uint32_t Animal::DebugShowTime(unsigned long param_1, uint8_t param_2, uint8_t param_3)
{
    return 0;
}

// win1.41 0041b200 mac 101662b0 Animal::GetScriptObjectType(void)
uint32_t Animal::GetScriptObjectType()
{
    return 6;
}

// win1.41 0041b210 mac 10055c50 Animal::IsPosValidForTurnAngle(MapCoords const &)
bool Animal::IsPosValidForTurnAngle(const MapCoords& param_1)
{
    return 0;
}

// win1.41 0041b320 mac 10166000 Animal::ValidToApplyThisToObject(GInterfaceStatus *, Object *)
uint32_t Animal::ValidToApplyThisToObject(GInterfaceStatus* param_1, Object* param_2)
{
    return 0;
}

// win1.41 0041b360 mac 10165e60 Animal::ApplyThisToObject(GInterfaceStatus *, Object *, GestureSystemPacketData *)
uint32_t Animal::ApplyThisToObject(GInterfaceStatus* param_1, Object* param_2, GestureSystemPacketData* param_3)
{
    return 0;
}

// win1.41 0041b430 mac inlined Animal::IsFinalState(VILLAGER_STATES)
bool32_t Animal::IsFinalState(VILLAGER_STATES param_1)
{
    return 0;
}

// win1.41 0041b460 mac 101659a0 Animal::Save(GameOSFile &)
bool32_t Animal::Save(GameOSFile& param_1)
{
    return 0;
}

// win1.41 0041b710 mac 10165620 Animal::Load(GameOSFile &)
bool32_t Animal::Load(GameOSFile& param_1)
{
    return 0;
}

// win1.41 0041b9a0 mac 101655d0 Animal::ResolveLoad(void)
void Animal::ResolveLoad()
{
}

// win1.41 0041bb00 mac 101650c0 Animal::IsChild(void)
bool Animal::IsChild()
{
    return 0;
}

// win1.41 0041bc10 mac 10164e30 Animal::ReactToPhysicsImpact(PhysicsObject *, bool)
void Animal::ReactToPhysicsImpact(PhysicsObject* param_1, bool param_2)
{
}

// win1.41 0041bc80 mac 10164dc0 Animal::GetDefaultResource(void)
int Animal::GetDefaultResource()
{
    return 0;
}

// win1.41 004203a0 mac 101765e0 Animal::ReactToFirePriority(Reaction *, Reaction *)
uint8_t Animal::ReactToFirePriority(Reaction* param_1, Reaction* param_2)
{
    return 0;
}

// win1.41 004203b0 mac 10176560 Animal::ReactToFallingTreePriority(Reaction *, Reaction *)
uint8_t Animal::ReactToFallingTreePriority(Reaction* param_1, Reaction* param_2)
{
    return 0;
}

// win1.41 00420410 mac 101763d0 Animal::SetupFleeFromPredator(GameThingWithPos *, Reaction *)
void Animal::SetupFleeFromPredator(GameThingWithPos* param_1, Reaction* param_2)
{
}

// win1.41 00420440 mac 10176350 Animal::SetupReactToCreature(GameThingWithPos *, Reaction *)
void Animal::SetupReactToCreature(GameThingWithPos* param_1, Reaction* param_2)
{
}

// win1.41 00420460 mac 101762d0 Animal::SetupReactToFire(GameThingWithPos *, Reaction *)
void Animal::SetupReactToFire(GameThingWithPos* param_1, Reaction* param_2)
{
}

// win1.41 00420480 mac 10176250 Animal::SetupReactToFallingTree(GameThingWithPos *, Reaction *)
void Animal::SetupReactToFallingTree(GameThingWithPos* param_1, Reaction* param_2)
{
}

// win1.41 004204a0 mac 101760c0 Animal::SetupReactToFlyingObject(GameThingWithPos *, Reaction *)
void Animal::SetupReactToFlyingObject(GameThingWithPos* param_1, Reaction* param_2)
{
}

// win1.41 00420550 mac 10175d80 Animal::GetFleeingPositionFromMovingObject(MapCoords *, GameThingWithPos *, float)
void Animal::GetFleeingPositionFromMovingObject(MapCoords* param_1, GameThingWithPos* param_2, float param_3)
{
}

// win1.41 00421e80 mac inlined GFeatureInfo::GetAbodeType( const(void))
ABODE_TYPE GFeatureInfo::GetAbodeType() const
{
    return (ABODE_TYPE)0;
}

// win1.41 00421e90 mac inlined GFeatureInfo::GetAbodeNumber( const(void))
ABODE_NUMBER GFeatureInfo::GetAbodeNumber() const
{
    return (ABODE_NUMBER)0;
}

// win1.41 00421ea0 mac 100a5310 GFeatureInfo::GetMesh( const(void))
uint32_t GFeatureInfo::GetMesh() const
{
    return 0;
}

// win1.41 00421eb0 mac 100a7c10 GFeatureInfo::GetBaseInfo(unsigned long &)
GBaseInfo* GFeatureInfo::GetBaseInfo(uint32_t& param_1)
{
    return 0;
}

// win1.41 00421f20 mac 100a67f0 GAnimatedStaticInfo::_dt(void)
GAnimatedStaticInfo::~GAnimatedStaticInfo()
{
}

// win1.41 00421fe0 mac 105b8ff0 MultiMapFixed::GetArrivePos(void)
MapCoords* MultiMapFixed::GetArrivePos(MapCoords* coords)
{
    return 0;
}

// win1.41 00422000 mac 100a5570 MultiMapFixed::GetPercentAbodeFullWithAdults(void)
float MultiMapFixed::GetPercentAbodeFullWithAdults()
{
    return 0;
}

// win1.41 00422010 mac 100a55c0 MultiMapFixed::GetPercentAbodeFullWithChildren(void)
float MultiMapFixed::GetPercentAbodeFullWithChildren()
{
    return 0;
}

// win1.41 00422020 mac 100a5620 MultiMapFixed::GetDestructionMesh(void)
LH3DMesh* MultiMapFixed::GetDestructionMesh()
{
    return 0;
}

// win1.41 00422030 mac 100a5660 MultiMapFixed::RemoveDamage(void)
void MultiMapFixed::RemoveDamage()
{
}

// win1.41 00422040 mac 100a56a0 MultiMapFixed::IsCivic(void)
bool MultiMapFixed::IsCivic()
{
    __asm xor eax, eax
}

// win1.41 00422050 mac 100a56e0 MultiMapFixed::IsWonder(void)
bool32_t MultiMapFixed::IsWonder()
{
    return 0;
}

// win1.41 00422060 mac 100a5720 MultiMapFixed::GetAbodeType(void)
ABODE_TYPE MultiMapFixed::GetAbodeType()
{
    return (ABODE_TYPE)0;
}

// win1.41 00422070 mac 100a5760 MultiMapFixed::DoResourceAdding(RESOURCE_TYPE, unsigned long, GInterfaceStatus *, bool, MapCoords const &, int)
uint32_t MultiMapFixed::DoResourceAdding(RESOURCE_TYPE type, GInterfaceStatus* iface, bool param_3, MapCoords* param_4, int param_5)
{
    return 0;
}

// win1.41 00422080 mac 100a57d0 MultiMapFixed::DoResourceRemoving(RESOURCE_TYPE, unsigned long, GInterfaceStatus *, bool *)
uint32_t MultiMapFixed::DoResourceRemoving(RESOURCE_TYPE type, uint32_t param_2, GInterfaceStatus* iface, bool param_4)
{
    return 0;
}

// win1.41 00422090 mac inlined MultiMapFixed::SetTown(void)
void MultiMapFixed::SetTown(Town* town)
{
}

// win1.41 004220a0 mac 100a5880 MultiMapFixed::GetTown(void)
Town* MultiMapFixed::GetTown()
{
    return 0;
}

// win1.41 004220b0 mac 100a58c0 MultiMapFixed::GetShouldNotBeAddedToPlanned(void)
bool MultiMapFixed::GetShouldNotBeAddedToPlanned()
{
    __asm xor eax, eax
}

// win1.41 004220c0 mac 100a5910 MultiMapFixed::SetShouldNotBeAddedToPlanned(int)
void MultiMapFixed::SetShouldNotBeAddedToPlanned(bool value)
{
}

// win1.41 004220d0 mac 100a52b0 Feature::GetMesh( const(void))
int Feature::GetMesh() const
{
    return 0;
}

// win1.41 004220e0 mac 100a5350 Feature::IsFeature(void)
bool32_t Feature::IsFeature()
{
    return 1;
}

// win1.41 004220f0 mac inlined WorshipSiteUpgrade::IsRepaired(void)
bool WorshipSiteUpgrade::IsRepaired()
{
    return 0;
}

// win1.41 00422110 mac inlined WorshipSiteUpgrade::IsBuilt(void)
bool WorshipSiteUpgrade::IsBuilt()
{
    return 0;
}

// win1.41 00422140 mac 100a5490 Feature::GetCreatureBeliefType(void)
uint32_t Feature::GetCreatureBeliefType()
{
    return 15;
}

// win1.41 00422150 mac 100a54d0 Feature::CanBePickedUpByCreature(Creature *)
bool32_t Feature::CanBePickedUpByCreature(Creature* param_1)
{
    return 0;
}

// win1.41 004221a0 mac 100a5e20 AnimatedStatic::_dt(void)
AnimatedStatic::~AnimatedStatic()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00417b80();
extern "C" void sdtor_opd_1();
extern "C" char sdtor_vt_0;
extern "C" void jmp_addr_0x0041fdc0();
extern "C" void jmp_addr_0x00436960();
extern "C" void jmp_addr_0x00422e30();

__declspec(naked) void __cdecl sdtor_PieceVillager() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_PieceVillager
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PieceVillager:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Cow() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Cow
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Cow:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Sheep() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Sheep
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Sheep:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PieceSheep() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_PieceSheep
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PieceSheep:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Goat() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Goat
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Goat:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Horse() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Horse
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Horse:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PieceHorse() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_PieceHorse
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PieceHorse:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Zebra() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Zebra
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Zebra:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Pig() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Pig
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Pig:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PiecePig() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_PiecePig
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PiecePig:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Tortoise() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Tortoise
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Tortoise:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PieceTortoise() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_PieceTortoise
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PieceTortoise:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Dove() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_0
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Dove
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Dove:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellDove() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_0
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_SpellDove
        push 0x00000178
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellDove:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Crow() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_0
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Crow
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Crow:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Swallow() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_0
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Swallow
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Swallow:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Pigeon() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_0
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Pigeon
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Pigeon:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Seagull() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_0
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Seagull
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Seagull:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Bat() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_0
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Bat
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Bat:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellBat() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_0
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_SpellBat
        push 0x00000178
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellBat:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Vulture() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_0
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_Vulture
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Vulture:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Leopard() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0041fdc0
        test byte ptr [esp + 8], 1
        je short skip_Leopard
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Leopard:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Lion() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0041fdc0
        test byte ptr [esp + 8], 1
        je short skip_Lion
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Lion:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PieceLion() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0041fdc0
        test byte ptr [esp + 8], 1
        je short skip_PieceLion
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PieceLion:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_SpellWolf() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0041fdc0
        test byte ptr [esp + 8], 1
        je short skip_SpellWolf
        push 0x0000019c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_SpellWolf:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Tiger() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0041fdc0
        test byte ptr [esp + 8], 1
        je short skip_Tiger
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Tiger:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Wolf() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0041fdc0
        test byte ptr [esp + 8], 1
        je short skip_Wolf
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Wolf:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PieceWolf() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0041fdc0
        test byte ptr [esp + 8], 1
        je short skip_PieceWolf
        push 0x00000148
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PieceWolf:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GAnimatedStaticInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_GAnimatedStaticInfo
        push 0x0000012c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GAnimatedStaticInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AnimatedStatic() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00422e30
        test byte ptr [esp + 8], 1
        je short skip_AnimatedStatic
        push 0x00000098
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AnimatedStatic:
        mov eax, esi
        pop esi
        ret 4
    }
}

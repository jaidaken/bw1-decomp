#include "PSysInterface.h"
#include "PSysBase.h"
#include "JPSysInterface.h"
#include "PSysManager.h"
#include "Particle3DPnt.h"
#include "ParticleLightMap.h"
#include "ParticleChainJoint.h"
#include "Particle3DSprite.h"
#include "Chain.h"
#include "SpellPointInf.h"
#include "DefensiveShield.h"
#include "DefensiveSphere.h"
#include "TownCentre.h"
#include "ParticleBaseMeshCreator.h"
#include "ParticleCreator.h"
#include "Particle3DObj.h"

// win1.41 0068e910 mac 100053c0 PSysInterface::Create(Spell *, PARTICLE_TYPE, LHPoint const &, LHPoint const &, float, PSysInterface::NET_GAME_TYPE)
PSysInterface* PSysInterface::Create(Spell* spell, PARTICLE_TYPE particle_type, LHPoint* param_3, LHPoint* param_4, float param_5, PSysInterface::NET_GAME_TYPE game_type)
{
    return 0;
}

// win1.41 006944b0 mac 1041db80 PSysBase::Load(GameOSFile &)
bool32_t PSysBase::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 006944d0 mac 1041dae0 GJPSysInterface::Load(GameOSFile &)
bool32_t GJPSysInterface::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 00694500 mac 1041d6f0 PSysManager::Load(GameOSFile &)
bool32_t PSysManager::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 00695010 mac inlined Particle3DPnt::Load(GameOSFile &)
bool32_t Particle3DPnt::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 00695180 mac 1041c890 ParticleLightMap::Load(GameOSFile &)
bool32_t ParticleLightMap::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 006959d0 mac 1041c0e0 ParticleChainJoint::Load(GameOSFile &)
bool32_t ParticleChainJoint::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 00695ac0 mac inlined Particle3DSprite::Load(GameOSFile &)
bool32_t Particle3DSprite::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 00695c10 mac 1041bda0 Chain::Load(GameOSFile &)
bool32_t Chain::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 00698240 mac 104192e0 SpellPointInf::Load(GameOSFile &)
bool32_t SpellPointInf::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 00699ca0 mac 10417a80 DefensiveShield::Load(GameOSFile &)
bool32_t DefensiveShield::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 00699cd0 mac 104179f0 DefensiveSphere::Load(GameOSFile &)
bool32_t DefensiveSphere::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 0069bc10 mac 104274c0 TownCentre::CreatePSys(void)
void TownCentre::CreatePSys()
{
}

// win1.41 0069bcc0 mac 1002d390 TownCentre::ProcessPSys(void)
void TownCentre::ProcessPSys()
{
}

// win1.41 0069bd60 mac 10066090 TownCentre::DrawPSys(void)
void TownCentre::DrawPSys()
{
}

// win1.41 006a8900 mac 1043f270 ParticleBaseMeshCreator::_dt(void)
ParticleBaseMeshCreator::~ParticleBaseMeshCreator()
{
}

// win1.41 006a9400 mac 103dfee0 ParticleCreator::_dt(void)
ParticleCreator::~ParticleCreator()
{
}

// win1.41 006b34c0 mac 10457740 ParticleCreator::DefineProperties(PropertyList *)
void ParticleCreator::DefineProperties(PropertyList* param_1)
{
}

// win1.41 006b37a0 mac 10457110 ParticleBaseMeshCreator::DefineProperties(PropertyList *)
void ParticleBaseMeshCreator::DefineProperties(PropertyList* param_1)
{
}

// win1.41 006c7a50 mac inlined Particle3DObj::GetDebugText(void)
char* Particle3DObj::GetDebugText()
{
    return "Particle3DObj";
}

// win1.41 006c7a60 mac inlined Particle3DObj::_dt(void)
Particle3DObj::~Particle3DObj()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void sdtor_dt_46();
extern "C" void jmp_addr_0x00675940();
extern "C" void jmp_addr_0x006759c0();
extern "C" char sdtor_vt_4;
extern "C" char sdtor_vt_5;
extern "C" void sdtor_dt_47();
extern "C" void sdtor_dt_48();
extern "C" void sdtor_dt_49();
extern "C" void sdtor_dt_50();
extern "C" void jmp_addr_0x00580a90();
extern "C" void sdtor_opd_0();
extern "C" char sdtor_vt_8;
extern "C" void sdtor_dt_51();
extern "C" void sdtor_dt_52();
extern "C" void jmp_addr_0x006c7a80();

__declspec(naked) void __cdecl sdtor_UR_Lightning_CollectionData() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_46
        test byte ptr [esp + 8], 1
        je short skip_UR_Lightning_CollectionData
        push 0x000000c0
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_UR_Lightning_CollectionData:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_LightningStrike() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_LightningStrike
        push 0x30
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_LightningStrike:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_TownCentreBelief() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_TownCentreBelief
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_TownCentreBelief:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_TownCentreBelief() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_TownCentreBelief
        push 0x3c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_TownCentreBelief:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_LightSheetOnObject() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_47
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_LightSheetOnObject
        push 0x30
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_LightSheetOnObject:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_VolFXOnObject() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_48
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_VolFXOnObject
        push 0x34
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_VolFXOnObject:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GJAnimVolFX() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_49
        test byte ptr [esp + 8], 1
        je short skip_GJAnimVolFX
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_GJAnimVolFX:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_HealSpellChakra() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_50
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_HealSpellChakra
        push 0x38
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_HealSpellChakra:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CollectionData_AT_ER_MultiPickup() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_ER_MultiPickup
        push 0x2c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_ER_MultiPickup:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_ER_MultiPickup() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_ER_MultiPickup
        push 0x2c
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_ER_MultiPickup:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_ParticleCreator() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00580a90
        test byte ptr [esp + 8], 1
        je short skip_ParticleCreator
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_ParticleCreator:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_FloatProvider() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_8
        call jmp_addr_0x00580a90
        test byte ptr [esp + 8], 1
        je short skip_FloatProvider
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_FloatProvider:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_DrawOffset() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_51
        test byte ptr [esp + 8], 1
        je short skip_DrawOffset
        push 0x18
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_DrawOffset:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_DrawOffsetLT() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_51
        test byte ptr [esp + 8], 1
        je short skip_DrawOffsetLT
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_DrawOffsetLT:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_DrawOffsetDecay() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_52
        test byte ptr [esp + 8], 1
        je short skip_DrawOffsetDecay
        push 0x40
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_DrawOffsetDecay:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Particle3DObj() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x006c7a80
        test byte ptr [esp + 8], 1
        je short skip_Particle3DObj
        push 0x28
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_Particle3DObj:
        mov eax, esi
        pop esi
        ret 4
    }
}

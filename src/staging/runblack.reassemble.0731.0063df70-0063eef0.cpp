#include "SpotVisualInfo.h"
#include "ParticleContainer.h"
#include "PBall.h"

// win1.41 0063e020 mac 10110f10 GSpotVisualInfo::GetBaseInfo(unsigned long &)
GBaseInfo* GSpotVisualInfo::GetBaseInfo(uint32_t& param_1)
{
    return 0;
}

// win1.41 0063e070 mac 101102f0 GSpotVisualInfo::_dt(void)
GSpotVisualInfo::~GSpotVisualInfo()
{
}

// win1.41 0063e1d0 mac 10110830 GParticleContainer::ToBeDeleted(int)
void GParticleContainer::ToBeDeleted(int param_1)
{
}

// win1.41 0063e3c0 mac 10000fb0 GParticleContainer::SetPlayer(GPlayer *)
void GParticleContainer::SetPlayer(GPlayer* param_1)
{
}

// win1.41 0063e3f0 mac 10110510 GParticleContainer::SetScale(float)
void GParticleContainer::SetScale(float param_1)
{
}

// win1.41 0063e5d0 mac 101100b0 GParticleContainer::Save(GameOSFile &)
bool32_t GParticleContainer::Save(GameOSFile& file)
{
    return 0;
}

// win1.41 0063e6d0 mac 1010ff00 GParticleContainer::Load(GameOSFile &)
bool32_t GParticleContainer::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 0063e950 mac inlined PBall::_dt(void)
PBall::~PBall()
{
}

// win1.41 0063e980 mac inlined PBall::Draw(void)
void PBall::Draw()
{
}

// win1.41 0063e990 mac inlined PBall::Process(void)
uint32_t PBall::Process()
{
    return 0;
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00436960();
extern "C" void sdtor_opd_1();
extern "C" void sdtor_dt_35();

__declspec(naked) void __cdecl sdtor_GSpotVisualInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_GSpotVisualInfo
        push 0x54
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GSpotVisualInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GPBallInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_GPBallInfo
        push 0x0000011c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GPBallInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PBall() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_35
        test byte ptr [esp + 8], 1
        je short skip_PBall
        push 0x74
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PBall:
        mov eax, esi
        pop esi
        ret 4
    }
}

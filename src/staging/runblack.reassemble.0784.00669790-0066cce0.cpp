#include "PlayerMessage.h"
#include "PlayerProfile.h"
#include "PlaytimeInfo.h"
#include "Playtime.h"
#include "PotInfo.h"

// win1.41 0066b5e0 mac inlined PlayerMessage::ProcessTurn(void)
int PlayerMessage::ProcessTurn()
{
    return 0;
}

// win1.41 0066b610 mac inlined PlayerMessage::Display(void)
void PlayerMessage::Display()
{
}

// win1.41 0066b7a0 mac 104cbec0 PlayerProfile::SetCurrentProfile(wchar_t *)
void PlayerProfile::SetCurrentProfile(char16_t* name)
{
}

// win1.41 0066bfb0 mac 104cb130 PlayerProfile::ProfileExists(wchar_t *)
uint32_t PlayerProfile::ProfileExists(char16_t* name)
{
    return 0;
}

// win1.41 0066c2d0 mac 10115f30 GPlaytimeInfo::GetBaseInfo(unsigned long &)
GBaseInfo* GPlaytimeInfo::GetBaseInfo(uint32_t& param_1)
{
    return 0;
}

// win1.41 0066c330 mac 10115d70 GPlaytimeInfo::_dt(void)
GPlaytimeInfo::~GPlaytimeInfo()
{
}

// win1.41 0066c410 mac inlined Playtime::_dt(void)
Playtime::~Playtime()
{
}

// win1.41 0066cbd0 mac 1011d400 GPotInfo::GetBaseInfo(unsigned long &)
GBaseInfo* GPotInfo::GetBaseInfo(uint32_t& param_1)
{
    return 0;
}

// win1.41 0066cc40 mac 10117210 GPotInfo::_dt(void)
GPotInfo::~GPotInfo()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00436960();
extern "C" void sdtor_opd_1();
extern "C" void jmp_addr_0x0056fa80();

__declspec(naked) void __cdecl sdtor_GPlaytimeInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_GPlaytimeInfo
        push 0x24
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GPlaytimeInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PlaytimeElement() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_PlaytimeElement
        push 0x44
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PlaytimeElement:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GPotInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_GPotInfo
        push 0x00000144
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GPotInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

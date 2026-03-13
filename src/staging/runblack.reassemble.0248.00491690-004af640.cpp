#include "CreatureActionInfo.h"
#include "CreatureInitialDesireInfo.h"
#include "CreatureAgenda.h"

// win1.41 00491750 mac 1022ebc0 CreatureActionInfo::GetBaseInfo(unsigned long &)
GBaseInfo* CreatureActionInfo::GetBaseInfo(uint32_t& param_1)
{
    return 0;
}

// win1.41 004917c0 mac 1022eaa0 CreatureActionInfo::_dt(void)
CreatureActionInfo::~CreatureActionInfo()
{
}

// win1.41 00491830 mac 1022ec70 CreatureInitialDesireInfo::GetBaseInfo(unsigned long &)
GBaseInfo* CreatureInitialDesireInfo::GetBaseInfo(uint32_t& param_1)
{
    return 0;
}

// win1.41 004918a0 mac 1022e850 CreatureInitialDesireInfo::_dt(void)
CreatureInitialDesireInfo::~CreatureInitialDesireInfo()
{
}

// win1.41 004aca70 mac 10217d60 CreatureAgenda::ConstructSubActionsForAttackerThrowBallAtGoal(unsigned long)
bool32_t CreatureAgenda::ConstructSubActionsForAttackerThrowBallAtGoal(unsigned long param_1)
{
    return 0;
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00436960();
extern "C" void sdtor_opd_1();

__declspec(naked) void __cdecl sdtor_CreatureActionInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureActionInfo
        push 0x00000110
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureActionInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureInitialDesireInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureInitialDesireInfo
        push 0x000001c0
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureInitialDesireInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureDesireActionEntry() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureDesireActionEntry
        push 0x00000088
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureDesireActionEntry:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureDesireAttributeEntry() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureDesireAttributeEntry
        push 0x38
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureDesireAttributeEntry:
        mov eax, esi
        pop esi
        ret 4
    }
}

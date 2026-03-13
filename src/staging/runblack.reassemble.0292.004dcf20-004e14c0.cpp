#include "CreatureInitialSourceInfo.h"
#include "CreatureSourceBoundsInfo.h"
#include "CreatureExplorationMap.h"
#include "CreatureLearning.h"
#include "CreaturePreviousLesson.h"

// win1.41 004dd260 mac 1025eee0 CreatureInitialSourceInfo::GetBaseInfo(unsigned long &)
GBaseInfo* CreatureInitialSourceInfo::GetBaseInfo(uint32_t& param_1)
{
    return 0;
}

// win1.41 004dd2c0 mac 1025d520 CreatureInitialSourceInfo::_dt(void)
CreatureInitialSourceInfo::~CreatureInitialSourceInfo()
{
}

// win1.41 004dd3a0 mac 1025ee20 CreatureSourceBoundsInfo::GetBaseInfo(unsigned long &)
GBaseInfo* CreatureSourceBoundsInfo::GetBaseInfo(uint32_t& param_1)
{
    return 0;
}

// win1.41 004dd400 mac 1025eab0 CreatureSourceBoundsInfo::_dt(void)
CreatureSourceBoundsInfo::~CreatureSourceBoundsInfo()
{
}

// win1.41 004df5c0 mac 10246800 CreatureExplorationMap::_dt(void)
CreatureExplorationMap::~CreatureExplorationMap()
{
}

// win1.41 004e0290 mac 10265060 CreatureLearning::CreatureLearning(Creature *)
// CreatureLearning::CreatureLearning(Creature* creature)
// {
// }

// win1.41 004e03a0 mac 10245f80 CreaturePreviousLesson::_dt(void)
CreaturePreviousLesson::~CreaturePreviousLesson()
{
}

// win1.41 004e03d0 mac 10246a10 CreatureLearning::_dt(void)
CreatureLearning::~CreatureLearning()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00436960();
extern "C" void sdtor_opd_1();

__declspec(naked) void __cdecl sdtor_CreatureDesireSourceTable() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureDesireSourceTable
        push 0x000000a4
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureDesireSourceTable:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureInitialSourceInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureInitialSourceInfo
        push 0x54
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureInitialSourceInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureSourceBoundsInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureSourceBoundsInfo
        push 0x1c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureSourceBoundsInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureExplorationRegionEntry() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureExplorationRegionEntry
        push 0x1c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureExplorationRegionEntry:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureGlobalExplorationMap() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureGlobalExplorationMap
        push ebx
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureGlobalExplorationMap:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureExplorationMap() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureExplorationMap
        push 0x00002418
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureExplorationMap:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreaturePreviousLesson() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreaturePreviousLesson
        push 0x0000120c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreaturePreviousLesson:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureLearning() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureLearning
        push 0x00016168
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureLearning:
        mov eax, esi
        pop esi
        ret 4
    }
}

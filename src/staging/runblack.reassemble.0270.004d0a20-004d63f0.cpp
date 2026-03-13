#include "MobileStatic.h"
#include "Animal.h"
#include "Creature.h"
#include "Villager.h"
#include "Citadel.h"
#include "Abode.h"
#include "Tree.h"
#include "CreatureMentalDebug.h"
#include "CreatureMental.h"
#include "CreatureAgenda.h"
#include "CreatureCommandState.h"

// win1.41 004d1af0 mac 10243160 MobileStatic::GetHowMuchCreatureWantsToLookAtMe(void)
float MobileStatic::GetHowMuchCreatureWantsToLookAtMe()
{
    return 0;
}

// win1.41 004d1b20 mac 102430c0 Animal::GetHowMuchCreatureWantsToLookAtMe(void)
float Animal::GetHowMuchCreatureWantsToLookAtMe()
{
    return 0;
}

// win1.41 004d1b30 mac 10243070 Creature::GetHowMuchCreatureWantsToLookAtMe(void)
float Creature::GetHowMuchCreatureWantsToLookAtMe()
{
    return 0;
}

// win1.41 004d1b40 mac 10243020 Villager::GetHowMuchCreatureWantsToLookAtMe(void)
float Villager::GetHowMuchCreatureWantsToLookAtMe()
{
    return 0;
}

// win1.41 004d1b50 mac 10242fd0 Citadel::GetHowMuchCreatureWantsToLookAtMe(void)
float Citadel::GetHowMuchCreatureWantsToLookAtMe()
{
    return 0;
}

// win1.41 004d1b60 mac 10242f80 Abode::GetHowMuchCreatureWantsToLookAtMe(void)
float Abode::GetHowMuchCreatureWantsToLookAtMe()
{
    return 0;
}

// win1.41 004d1b70 mac 10242f30 Tree::GetHowMuchCreatureWantsToLookAtMe(void)
float Tree::GetHowMuchCreatureWantsToLookAtMe()
{
    return 0;
}

// win1.41 004d2540 mac 10246630 CreatureMentalDebug::_dt(void)
CreatureMentalDebug::~CreatureMentalDebug()
{
}

// win1.41 004d2560 mac 10245b60 CreatureMental::_dt(void)
CreatureMental::~CreatureMental()
{
}

// win1.41 004d34b0 mac 102471c0 CreatureAgenda::CreatureAgenda(Creature *, CreatureInfo const *)
// CreatureAgenda::CreatureAgenda(const CreatureInfo* info)
// {
// }

// win1.41 004d35e0 mac 10245e50 CreatureCommandState::_dt(void)
CreatureCommandState::~CreatureCommandState()
{
}

// win1.41 004d3600 mac 10246c50 CreatureAgenda::_dt(void)
CreatureAgenda::~CreatureAgenda()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00436960();
extern "C" void sdtor_opd_1();
extern "C" void jmp_addr_0x004d8a20();
extern "C" void sdtor_dt_11();

__declspec(naked) void __cdecl sdtor_CreatureBeliefList() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefList
        push 0x14
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefList:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureBeliefs() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004d8a20
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefs
        push 0x00000270
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefs:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureMentalDebug() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureMentalDebug
        push 0x4c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureMentalDebug:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureMental() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_11
        test byte ptr [esp + 8], 1
        je short skip_CreatureMental
        push 0x00020d40
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureMental:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureCommandState() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureCommandState
        push 0x2c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureCommandState:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureAgenda() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureAgenda
        push 0x00001af8
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureAgenda:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeCreatureDominantDesire() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeCreatureDominantDesire
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeCreatureDominantDesire:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeCreatureHeight() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeCreatureHeight
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeCreatureHeight:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeCreatureSpellKnowledge() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeCreatureSpellKnowledge
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeCreatureSpellKnowledge:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeCreatureWhatHeIsCarrying() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeCreatureWhatHeIsCarrying
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeCreatureWhatHeIsCarrying:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeForestSize() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeForestSize
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeForestSize:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeMobileObjectType() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeMobileObjectType
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeMobileObjectType:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeAbodeType() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeAbodeType
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeAbodeType:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeAbodeBeingBuilt() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeAbodeBeingBuilt
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeAbodeBeingBuilt:
        mov eax, esi
        pop esi
        ret 4
    }
}

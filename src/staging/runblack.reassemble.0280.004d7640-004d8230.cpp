#include "CreatureMental.h"

// win1.41 004d7bd0 mac 10253c90 CreatureMental::AddBeliefAboutObject(Creature *, GameThingWithPos *)
void* CreatureMental::AddBeliefAboutObject(Creature* param_1, GameThingWithPos* param_2)
{
    return 0;
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x004d8b50();
extern "C" void sdtor_opd_1();
extern "C" void jmp_addr_0x00436960();

__declspec(naked) void __cdecl sdtor_CreatureBelief() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004d8b50
        test byte ptr [esp + 8], 1
        je short skip_CreatureBelief
        push 0x4c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBelief:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AllocatedBeliefList() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AllocatedBeliefList
        push 0x18
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AllocatedBeliefList:
        mov eax, esi
        pop esi
        ret 4
    }
}

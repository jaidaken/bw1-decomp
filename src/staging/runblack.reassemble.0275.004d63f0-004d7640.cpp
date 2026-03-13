
// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x004daab0();
extern "C" void sdtor_opd_1();
extern "C" void jmp_addr_0x004dac30();
extern "C" void jmp_addr_0x004daaf0();
extern "C" void jmp_addr_0x004dab30();
extern "C" void jmp_addr_0x004dacb0();
extern "C" void jmp_addr_0x004dab70();
extern "C" void jmp_addr_0x004dabb0();
extern "C" void jmp_addr_0x004dac70();
extern "C" void jmp_addr_0x004dacf0();

__declspec(naked) void __cdecl sdtor_CreatureBeliefSmall() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004daab0
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefSmall
        push 0x68
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefSmall:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureBeliefAboutVillager() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004dac30
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefAboutVillager
        push 0x78
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefAboutVillager:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureBeliefAboutTown() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004daaf0
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefAboutTown
        push 0x78
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefAboutTown:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureBeliefAboutFlock() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004dab30
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefAboutFlock
        push 0x68
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefAboutFlock:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureBeliefAboutCitadel() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004dacb0
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefAboutCitadel
        push 0x68
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefAboutCitadel:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureBeliefAboutCreature() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004dab70
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefAboutCreature
        push 0x7c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefAboutCreature:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureBeliefAboutForest() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004dabb0
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefAboutForest
        push 0x6c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefAboutForest:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureBeliefAboutAbode() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004dac70
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefAboutAbode
        push 0x78
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefAboutAbode:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureBeliefAboutContext() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004dacf0
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefAboutContext
        push 0x4c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefAboutContext:
        mov eax, esi
        pop esi
        ret 4
    }
}

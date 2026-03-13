
// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void sdtor_dt_12();
extern "C" void sdtor_opd_1();
extern "C" void jmp_addr_0x00436960();
extern "C" void jmp_addr_0x004dc070();

__declspec(naked) void __cdecl sdtor_CreatureBeliefAboutMobileObject() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_12
        test byte ptr [esp + 8], 1
        je short skip_CreatureBeliefAboutMobileObject
        push 0x6c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureBeliefAboutMobileObject:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureDesireDependency() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureDesireDependency
        push 0x000000b0
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureDesireDependency:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureDesireForType() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureDesireForType
        push 0x54
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureDesireForType:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureDevelopmentPhaseEntry() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureDevelopmentPhaseEntry
        push 0x00000084
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureDevelopmentPhaseEntry:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureDevelopmentDurationEntry() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureDevelopmentDurationEntry
        push 0x48
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureDevelopmentDurationEntry:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureDesires() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004dc070
        test byte ptr [esp + 8], 1
        je short skip_CreatureDesires
        push 0x00000708
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureDesires:
        mov eax, esi
        pop esi
        ret 4
    }
}

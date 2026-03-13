
// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00417b80();
extern "C" void sdtor_opd_1();

__declspec(naked) void __cdecl sdtor_PuzzleHorse() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_PuzzleHorse
        push 0x00000154
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PuzzleHorse:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PuzzleTortoise() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_PuzzleTortoise
        push 0x00000154
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PuzzleTortoise:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PuzzleCow() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_PuzzleCow
        push 0x00000154
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PuzzleCow:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_PuzzlePig() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00417b80
        test byte ptr [esp + 8], 1
        je short skip_PuzzlePig
        push 0x00000154
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_PuzzlePig:
        mov eax, esi
        pop esi
        ret 4
    }
}

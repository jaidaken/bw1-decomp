
// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x0056fa80();
extern "C" void sdtor_opd_1();

__declspec(naked) void __cdecl sdtor_ChessGamePuzzle() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_ChessGamePuzzle
        push 0x00000138
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_ChessGamePuzzle:
        mov eax, esi
        pop esi
        ret 4
    }
}

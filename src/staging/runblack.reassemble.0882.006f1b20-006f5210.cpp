
// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00436960();
extern "C" void sdtor_opd_1();

__declspec(naked) void __cdecl sdtor_GScriptOpposingCreature() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_GScriptOpposingCreature
        push 0x1c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GScriptOpposingCreature:
        mov eax, esi
        pop esi
        ret 4
    }
}

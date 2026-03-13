#include "CPUCheck.h"

// win1.41 00471a80 mac 100c00a0 CPUCheck::~CPUCheck(void)
CPUCheck::~CPUCheck()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00471aa0();
extern "C" void sdtor_opd_0();

__declspec(naked) void __cdecl sdtor_CPUCheck() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00471aa0
        test byte ptr [esp + 8], 1
        je short skip_CPUCheck
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_CPUCheck:
        mov eax, esi
        pop esi
        ret 4
    }
}

#include "JobInfo.h"

// win1.41 005e16c0 mac 100fe6d0 GJobInfo::GetBaseInfo(unsigned long &)
GBaseInfo* GJobInfo::GetBaseInfo(uint32_t& param_1)
{
    return 0;
}

// win1.41 005e1720 mac 100fe5c0 GJobInfo::_dt(void)
GJobInfo::~GJobInfo()
{
}

// win1.41 005e1740 mac 100fe450 GJobInfo::GetJobActivity(void) const
uint32_t GJobInfo::GetJobActivity() const
{
    return 0;
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00436960();
extern "C" void sdtor_opd_1();
extern "C" void jmp_addr_0x004369d0();

__declspec(naked) void __cdecl sdtor_GJobInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_GJobInfo
        push 0x58
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GJobInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GKeyInput() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_GKeyInput
        push ebp
        push esi
        call jmp_addr_0x004369d0
        add esp, 8
    skip_GKeyInput:
        mov eax, esi
        pop esi
        ret 4
    }
}

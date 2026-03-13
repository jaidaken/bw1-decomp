#include "BaseInfo.h"
#include "Mobile.h"
#include "Reaction.h"
#include "Living.h"

// win1.41 0055c770 mac 10043c50 BaseInfo::IsClear(void) const
bool BaseInfo::IsClear() const
{
    return 0;
}

// win1.41 0055c790 mac 100c0890 Mobile::Mobile(void)
Mobile::Mobile()
{
}

// win1.41 0055c7b0 mac 10099cb0 Reaction::GetPlayer(void)
GPlayer* Reaction::GetPlayer()
{
    return 0;
}

// win1.41 0055c7c0 mac 10134150 Reaction::SetPlayer(GPlayer *)
void Reaction::SetPlayer(GPlayer* param_1)
{
}

// win1.41 0055c7d0 mac 10049510 Reaction::GetRadius(void)
float Reaction::GetRadius()
{
    return 0;
}

// win1.41 0055c7e0 mac 10134280 Reaction::GetSaveType(void)
uint32_t Reaction::GetSaveType()
{
    return 38;
}

// win1.41 0055c7f0 mac 101342c0 Reaction::GetDebugText(void)
char* Reaction::GetDebugText()
{
    return "Reaction";
}

// win1.41 0055c800 mac 10136550 Reaction::_dt(void)
Reaction::~Reaction()
{
}

// win1.41 0055c820 mac 1030ed90 Living::Living(void)
// Living::Living()
// {
// }

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x006e3a60();
extern "C" void sdtor_opd_1();

__declspec(naked) void __cdecl sdtor_Reaction() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x006e3a60
        test byte ptr [esp + 8], 1
        je short skip_Reaction
        push 0x44
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Reaction:
        mov eax, esi
        pop esi
        ret 4
    }
}

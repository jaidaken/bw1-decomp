#include "SetupButton.h"
#include "SetupSlider.h"

// win1.41 004097a0 mac 100c7c90 SetupButton::Draw(bool, bool)
void SetupButton::Draw(bool hovered, bool selected)
{
}

// // win1.41 004098b0 mac 103dd710 SetupButton::SetupButton(int, int, int, int, int, wchar_t *, int)
// SetupButton::SetupButton(int id, int x, int y, int width, int height, const char16_t* label, int param_8)
// {
// }

// win1.41 00409900 mac 101104d0 SetupButton::MouseDown(int, int, bool)
void SetupButton::MouseDown(int x, int y, bool param_3)
{
}

// win1.41 00409910 mac 10172660 SetupButton::MouseUp(int, int, bool)
void SetupButton::MouseUp(int x, int y, bool param_3)
{
}

// win1.41 00409920 mac 1034a2d0 SetupButton::KeyDown(int, int)
void SetupButton::KeyDown(LHKey key, LHKeyMod mod)
{
}

// win1.41 00409940 mac 10594240 SetupButton::~SetupButton(void)
SetupButton::~SetupButton()
{
}

// win1.41 00409960 mac 10103d10 SetupSlider::KeyDown(int, int)
void SetupSlider::KeyDown(LHKey key, LHKeyMod mod)
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void sdtor_dt_0();
extern "C" void sdtor_opd_0();

__declspec(naked) void __cdecl sdtor_SetupButton() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_0
        test byte ptr [esp + 8], 1
        je short skip_SetupButton
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_SetupButton:
        mov eax, esi
        pop esi
        ret 4
    }
}

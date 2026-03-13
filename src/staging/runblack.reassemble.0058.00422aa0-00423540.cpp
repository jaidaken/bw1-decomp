#include "Feature.h"
#include "lionhead/lh3dlib/development/LH3DObject.h"

// Extern references for manual scalar deleting destructor.
// These symbols are renamed by cl_wrapper.py after compilation:
//   _sdtor_vt_Feature  -> ??_7Feature@@6B@  (vtable)
//   _sdtor_dtor_Feature -> ??1Feature@@UAE@XZ (destructor)
//   _sdtor_op_del      -> ??3Base@@SAXPAXI@Z (operator delete, then I->K rename)
extern "C" char sdtor_vt_Feature;
extern "C" void sdtor_dtor_Feature();
extern "C" void sdtor_op_del();

// win1.41 00422e70 mac 100d1840 Feature::GetSaveType(void)
uint32_t Feature::GetSaveType()
{
    return 116;
}

// win1.41 00422e80 mac 100d1880 Feature::GetDebugText(void)
char* Feature::GetDebugText()
{
    return "Feature";
}

// win1.41 00422e90 mac 100a7a50 Feature::_dt(void)
Feature::~Feature()
{
}

// Manual scalar deleting destructor with vtable write.
// MSVC 6.0 (original) emits mov [esi], vtable before calling the destructor.
// MSVC 12.0 (staging) does not. This naked function replaces the auto-generated ??_G.
// Symbol ?sdtor_Feature@@YAXXZ is renamed to ??_GFeature@@UAEPAXI@Z by cl_wrapper.py.
__declspec(naked) void __cdecl sdtor_Feature() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_Feature
        call sdtor_dtor_Feature
        test byte ptr [esp + 8], 1
        je short skip_Feature
        push 07Ch
        push esi
        call sdtor_op_del
        add esp, 8
    skip_Feature:
        mov eax, esi
        pop esi
        ret 4
    }
}

// win1.41 00423140 mac 10041480 LH3DObject::SetPosition(const LHPoint&, float, float)
void LH3DObject::SetPosition(LHPoint* point, float y_angle, float scale)
{
}

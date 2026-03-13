#include "Landscape.h"
#include "Language.h"
#include "LeashStatus.h"

// win1.41 005e3f60 mac 1001d960 GLandscape::PreDraw(void)
uint32_t GLandscape::PreDraw()
{
    return 0;
}

// win1.41 005e42e0 mac 1004d770 GLandscape::Draw(void)
uint32_t GLandscape::Draw()
{
    return 0;
}

// win1.41 005e52e0 mac 10379f50 GLandscape::Open(char *)
void GLandscape::Open(const char* path)
{
}

// win1.41 005e6750 mac 1019cef0 GLanguage::GLanguage(void)
GLanguage::GLanguage()
{
}

// win1.41 005e6770 mac 1017a5a0 GLanguage::_dt(void)
GLanguage::~GLanguage()
{
}

// win1.41 005e71d0 mac 1037b4b0 GLeashStatus::SaveExtraData(GameOSFile &)
void GLeashStatus::SaveExtraData(GameOSFile& param_1)
{
}

// win1.41 005e7230 mac 1037b1a0 GLeashStatus::Save(GameOSFile &)
bool32_t GLeashStatus::Save(GameOSFile& file)
{
    return 0;
}

// win1.41 005e7430 mac 1037aeb0 GLeashStatus::Load(GameOSFile &)
bool32_t GLeashStatus::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 005e7630 mac 1037ae50 GLeashStatus::GetPlayer(void)
GPlayer* GLeashStatus::GetPlayer()
{
    return 0;
}

// win1.41 005e7650 mac 1037ae10 GLeashStatus::ResolveLoad(void)
void GLeashStatus::ResolveLoad()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x005e6790();
extern "C" void sdtor_opd_1();

__declspec(naked) void __cdecl sdtor_GLanguage() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x005e6790
        test byte ptr [esp + 8], 1
        je short skip_GLanguage
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GLanguage:
        mov eax, esi
        pop esi
        ret 4
    }
}

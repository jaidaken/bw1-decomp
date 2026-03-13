#include "ScriptTimer.h"
#include "SecretCreature.h"
#include "Settings.h"

// win1.41 00711600 mac 10506a30 ScriptTimer::GetScriptObjectType(void)
uint32_t ScriptTimer::GetScriptObjectType()
{
    return 17;
}

// win1.41 00711700 mac 105064b0 ScriptTimer::Save(GameOSFile &)
bool32_t ScriptTimer::Save(GameOSFile& file)
{
    return 0;
}

// win1.41 007117b0 mac 10506390 ScriptTimer::Load(GameOSFile &)
bool32_t ScriptTimer::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 00711d60 mac 101441a0 SecretCreature::_dt(void)
SecretCreature::~SecretCreature()
{
}

// win1.41 00714af0 mac 105e8db0 Settings::ParseConfigFile(char*)
void Settings::ParseConfigFile(char* path)
{
}

// win1.41 00714c20 mac 105e8d50 Settings::InitialiseToDefaults(void)
void Settings::InitialiseToDefaults()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void sdtor_dt_68();
extern "C" void sdtor_opd_0();

__declspec(naked) void __cdecl sdtor_SecretCreature() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_68
        test byte ptr [esp + 8], 1
        je short skip_SecretCreature
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_SecretCreature:
        mov eax, esi
        pop esi
        ret 4
    }
}

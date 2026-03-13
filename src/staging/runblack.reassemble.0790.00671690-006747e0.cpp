#include "PSysManager.h"
#include "JPSysInterface.h"

// win1.41 00672c90 mac 10423cc0 PSysManager::GetSaveType(void)
uint32_t PSysManager::GetSaveType()
{
    return 164;
}

// win1.41 00672ca0 mac 10423d00 PSysManager::GetDebugText(void)
char* PSysManager::GetDebugText()
{
    return "PSysManager";
}

// win1.41 00672cb0 mac 103dcfb0 PSysManager::_dt(void)
PSysManager::~PSysManager()
{
}

// win1.41 006735c0 mac 103dc100 PSysManager::GetPlayer(void)
GPlayer* PSysManager::GetPlayer()
{
    return 0;
}

// win1.41 00673690 mac inlined GJPSysInterface::Process(PSysProcessInfo *)
void GJPSysInterface::Process(PSysProcessInfo* param_1)
{
}

// win1.41 006736b0 mac inlined GJPSysInterface::Process(PSysProcessInfo *const, unsigned int)
uint32_t GJPSysInterface::Process(const PSysProcessInfo* param_1, uint32_t param_2)
{
    return 0;
}

// win1.41 00673700 mac inlined GJPSysInterface::Draw(bool)
void GJPSysInterface::Draw(bool param_1)
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void sdtor_dt_38();
extern "C" void jmp_addr_0x00675940();
extern "C" void sdtor_dt_39();

__declspec(naked) void __cdecl sdtor_PSysManager() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_38
        test byte ptr [esp + 8], 1
        je short skip_PSysManager
        push 0x000000e4
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_PSysManager:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomCore() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_39
        test byte ptr [esp + 8], 1
        je short skip_AtomCore
        push 0x00000130
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomCore:
        mov eax, esi
        pop esi
        ret 4
    }
}

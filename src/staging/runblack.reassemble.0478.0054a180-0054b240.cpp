#include "SetupMultiplayerMain.h"
#include "FurnitureInfo.h"
#include "Furniture.h"

extern "C" char sdtor_vt_Furniture;
extern "C" void sdtor_dtor_Furniture();
extern "C" void sdtor_op_del();

// win1.41 0054a180 mac 105cde40 SetupMultiplayerMain::InitSubDialogs(void)
void SetupMultiplayerMain::InitSubDialogs()
{
}

// win1.41 0054a350 mac 100f2c30 GFurnitureInfo::GetBaseInfo(unsigned long &)
GBaseInfo* GFurnitureInfo::GetBaseInfo(uint32_t& param_1)
{
    return 0;
}

// win1.41 0054a3c0 mac 100f2b20 GFurnitureInfo::_dt(void)
GFurnitureInfo::~GFurnitureInfo()
{
}

// win1.41 0054a440 mac inlined Furniture::SaveObject(LHOSFile &, MapCoords const &)
uint32_t Furniture::SaveObject(LHOSFile& file, const MapCoords& coords)
{
    return 0;
}

// win1.41 0054a450 mac inlined Furniture::GetSaveType(void)
uint32_t Furniture::GetSaveType()
{
    return 0;
}

// win1.41 0054a460 mac inlined Furniture::GetDebugText(void)
char* Furniture::GetDebugText()
{
    return "Furniture";
}

// win1.41 0054a470 mac inlined Furniture::_dt(void)
Furniture::~Furniture()
{
}

__declspec(naked) void __cdecl sdtor_Furniture() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_Furniture
        call sdtor_dtor_Furniture
        test byte ptr [esp + 8], 1
        je short skip_Furniture
        push 054h
        push esi
        call sdtor_op_del
        add esp, 8
    skip_Furniture:
        mov eax, esi
        pop esi
        ret 4
    }
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00436960();
extern "C" void sdtor_opd_1();

__declspec(naked) void __cdecl sdtor_GFurnitureInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_GFurnitureInfo
        push 0x00000104
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GFurnitureInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

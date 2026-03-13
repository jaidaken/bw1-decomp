#include "Creche.h"
#include "DanceInfo.h"
#include "Dance.h"
#include "FootpathLink.h"
#include "GroupBehaviour.h"
#include "DanceGroup.h"

// win1.41 0050a990 mac inlined Creche::GetArrivePos(MapCoords *)
MapCoords* Creche::GetArrivePos(MapCoords* param_1)
{
    return 0;
}

// win1.41 0050a9b0 mac 102a3c40 Creche::CanActAsAContainer(Creature *)
bool32_t Creche::CanActAsAContainer(Creature* param_1)
{
    return 0;
}

// win1.41 0050a9c0 mac 102a3c90 Creche::IsStoragePit(Creature *)
bool32_t Creche::IsStoragePit(Creature* param_1)
{
    return 0;
}

// win1.41 0050a9d0 mac 102a3cd0 Creche::Get3DType(void)
LH3DObject::ObjectType Creche::Get3DType()
{
    return (LH3DObject::ObjectType)0;
}

// win1.41 0050a9e0 mac 102a3d00 Creche::GetSaveType(void)
uint32_t Creche::GetSaveType()
{
    return 80;
}

// win1.41 0050a9f0 mac 102a3d40 Creche::GetDebugText(void)
char* Creche::GetDebugText()
{
    return "Creche";
}

// win1.41 0050aa00 mac 102a3b10 Creche::_dt(void)
Creche::~Creche()
{
}

// win1.41 0050aa30 mac 102a40f0 Creche::ToBeDeleted(int)
void Creche::ToBeDeleted(int param_1)
{
}

// win1.41 0050aa50 mac 102a3fd0 Creche::DeleteDependancys(void)
void Creche::DeleteDependancys()
{
}

// win1.41 0050ab50 mac 102a3de0 Creche::MakeFunctional(void)
void Creche::MakeFunctional()
{
}

// win1.41 0050ab90 mac 102a3d80 Creche::ReduceLife(float, GPlayer *)
void Creche::ReduceLife(float param_1, GPlayer* param_2)
{
}

// win1.41 0050b600 mac 102aa810 GDanceInfo::GetBaseInfo(unsigned long &)
GBaseInfo* GDanceInfo::GetBaseInfo(uint32_t& param_1)
{
    return 0;
}

// win1.41 0050b670 mac 102a8e60 GDanceInfo::_dt(void)
GDanceInfo::~GDanceInfo()
{
}

// win1.41 0050b6a0 mac 102aa620 Dance::Dance(MapCoords const &, GDanceInfo const *, GameThingWithPos *, unsigned long, int, Town *)
Dance::Dance(const MapCoords* param_1, GDanceInfo* info, const GameThingWithPos* param_3, uint32_t param_4, int param_5, Town* town)
{
}

// win1.41 0050b710 mac 102a80e0 Dance::IsScriptContainer( const(void))
bool32_t Dance::IsScriptContainer() const
{
    return 1;
}

// win1.41 0050b720 mac 102a8120 Dance::GetFootpathLink(void)
GFootpathLink* Dance::GetFootpathLink()
{
    return 0;
}

// win1.41 0050b730 mac 102a8160 Dance::IsDance( const(void))
bool32_t Dance::IsDance() const
{
    return 1;
}

// win1.41 0050b740 mac 102a8190 Dance::GetText(void)
const char* Dance::GetText()
{
    return "Dance";
}

// win1.41 0050b750 mac 102a81c0 Dance::GetSaveType(void)
uint32_t Dance::GetSaveType()
{
    return 39;
}

// win1.41 0050b760 mac 102a81f0 Dance::GetDebugText(void)
char* Dance::GetDebugText()
{
    return "Dance";
}

// win1.41 0050b770 mac 102aa200 Dance::_dt(void)
Dance::~Dance()
{
}

// win1.41 0050b970 mac 102a9e90 Dance::ToBeDeleted(int)
void Dance::ToBeDeleted(int param_1)
{
}

// win1.41 0050bb30 mac 102a9db0 Dance::CleanUpBeforeReset(void)
void Dance::CleanUpBeforeReset()
{
}

// win1.41 0050bb40 mac 102a9d60 Dance::StartDance(void)
void Dance::StartDance()
{
}

// win1.41 0050bb90 mac 102a9810 Dance::Process(void)
void Dance::Process()
{
}

// win1.41 0050c250 mac 102a9370 Dance::Get3DSoundPos(LHPoint *)
int Dance::Get3DSoundPos(LHPoint* param_1)
{
    return 0;
}

// win1.41 0050c310 mac 102a9230 Dance::GetAngle(void)
float Dance::GetAngle()
{
    return 0;
}

// win1.41 0050c3c0 mac 102a9110 Dance::GetScriptObjectType(void)
uint32_t Dance::GetScriptObjectType()
{
    return 10;
}

// win1.41 0050c480 mac 102a8960 Dance::Save(GameOSFile &)
bool32_t Dance::Save(GameOSFile& file)
{
    return 0;
}

// win1.41 0050c760 mac 102a85a0 Dance::Load(GameOSFile &)
bool32_t Dance::Load(GameOSFile& file)
{
    return 0;
}

// win1.41 0050ca60 mac 102a83d0 Dance::AddFootpath(GFootpath *)
uint32_t Dance::AddFootpath(GFootpath* param_1)
{
    return 0;
}

// win1.41 0050cad0 mac 100ef190 GFootpathLink::GetSaveType(void)
uint32_t GFootpathLink::GetSaveType()
{
    return 2;
}

// win1.41 0050cae0 mac 100ef1d0 GFootpathLink::GetDebugText(void)
char* GFootpathLink::GetDebugText()
{
    return "GFootpathLink";
}

// win1.41 0050caf0 mac 100ef100 GFootpathLink::_dt(void)
GFootpathLink::~GFootpathLink()
{
}

// win1.41 0050cb10 mac 102a8330 Dance::RemoveFootpath(GFootpath *)
uint32_t Dance::RemoveFootpath(GFootpath* param_1)
{
    return 0;
}

// win1.41 0050cb40 mac inlined Dance::GetArrivePos(MapCoords *)
MapCoords* Dance::GetArrivePos(MapCoords* param_1)
{
    return 0;
}

// win1.41 0050cc40 mac 100f4e30 GroupBehaviour::GetAngle(void)
float GroupBehaviour::GetAngle()
{
    return 0;
}

// win1.41 0050cee0 mac 102aaa20 DanceGroup::GetSaveType(void)
uint32_t DanceGroup::GetSaveType()
{
    return 123;
}

// win1.41 0050cef0 mac 102aaa60 DanceGroup::GetDebugText(void)
char* DanceGroup::GetDebugText()
{
    return "DanceGroup";
}

// win1.41 0050cf00 mac 102aa590 DanceGroup::_dt(void)
DanceGroup::~DanceGroup()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void sdtor_dt_15();
extern "C" void sdtor_opd_1();
extern "C" void jmp_addr_0x00606ed0();
extern "C" void jmp_addr_0x00436960();
extern "C" void sdtor_dt_16();
extern "C" void jmp_addr_0x0056fa80();
extern "C" void sdtor_dt_17();

__declspec(naked) void __cdecl sdtor_Creche() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_15
        test byte ptr [esp + 8], 1
        je short skip_Creche
        push 0x000000c4
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Creche:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Creed() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00606ed0
        test byte ptr [esp + 8], 1
        je short skip_Creed
        push 0x6c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Creed:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GDanceInfo() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_GDanceInfo
        push 0x000000b0
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GDanceInfo:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Dance() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_16
        test byte ptr [esp + 8], 1
        je short skip_Dance
        push 0x0000012c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Dance:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_GFootpathLink() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_GFootpathLink
        push 0x1c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_GFootpathLink:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_DanceEditState() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_17
        test byte ptr [esp + 8], 1
        je short skip_DanceEditState
        push 0x000000e8
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_DanceEditState:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_DanceGroup() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x0056fa80
        test byte ptr [esp + 8], 1
        je short skip_DanceGroup
        push 0x0000017c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_DanceGroup:
        mov eax, esi
        pop esi
        ret 4
    }
}

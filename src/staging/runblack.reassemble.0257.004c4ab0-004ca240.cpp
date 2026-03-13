#include "Creature.h"
#include "CreatureAttitudeToPlayer.h"

// win1.41 004c5e50 mac 10231ab0 Creature::FalseFunction(void)
bool32_t Creature::FalseFunction()
{
    return 0;
}

// win1.41 004c5fe0 mac 102345e0 Creature::FightThisToObject(GInterfaceStatus *, Object *)
uint32_t Creature::FightThisToObject(GInterfaceStatus* param_1, Object* param_2)
{
    return 0;
}

// win1.41 004c6460 mac 10233f70 Creature::SelectFightThisToMapCoord(GInterfaceStatus *, MapCoords const &)
uint32_t Creature::SelectFightThisToMapCoord(GInterfaceStatus* param_1, const MapCoords* param_2)
{
    return 0;
}

// win1.41 004c64d0 mac 10233ea0 Creature::ApplyFightThisToMapCoord(GInterfaceStatus *, MapCoords const &)
uint32_t Creature::ApplyFightThisToMapCoord(GInterfaceStatus* param_1, const MapCoords* param_2)
{
    return 0;
}

// win1.41 004c81a0 mac 10235cc0 CreatureAttitudeToPlayer::_dt(void)
CreatureAttitudeToPlayer::~CreatureAttitudeToPlayer()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00436960();
extern "C" void sdtor_opd_1();

__declspec(naked) void __cdecl sdtor_CreatureCommand() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureCommand
        push 0x1c
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureCommand:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureAttitudeToPlayer() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureAttitudeToPlayer
        push 0x00001db4
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureAttitudeToPlayer:
        mov eax, esi
        pop esi
        ret 4
    }
}

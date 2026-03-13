#include "PSysHandFX.h"

// win1.41 0068c9d0 mac 1040e720 PSysHandFX::CreateHandFX(void)
HandFX* PSysHandFX::CreateHandFX()
{
    return 0;
}

// win1.41 0068def0 mac 1040c1a0 PSysHandFX::CreateTribalPowerColumn(TRIBE_TYPE, LHPoint const &, unsigned long)
void PSysHandFX::CreateTribalPowerColumn(TRIBE_TYPE type, LHPoint* param_2, uint32_t param_3)
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x006759c0();
extern "C" char sdtor_vt_5;
extern "C" void jmp_addr_0x00675940();
extern "C" void sdtor_dt_44();
extern "C" char sdtor_vt_4;
extern "C" void sdtor_dt_45();

__declspec(naked) void __cdecl sdtor_CollectionData_AT_UR_RingSpin() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_CollectionData_AT_UR_RingSpin
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_CollectionData_AT_UR_RingSpin:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_UR_GesturingRecognised() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_44
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_UR_GesturingRecognised
        push 0x000000c8
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_UR_GesturingRecognised:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_ParentCollectionData_AT_ZR_ChainGesture() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_5
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_ParentCollectionData_AT_ZR_ChainGesture
        push 0x24
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_ParentCollectionData_AT_ZR_ChainGesture:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AtomData_AT_ZR_ChainGesture() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_4
        call jmp_addr_0x006759c0
        test byte ptr [esp + 8], 1
        je short skip_AtomData_AT_ZR_ChainGesture
        push 0x48
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_AtomData_AT_ZR_ChainGesture:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_Band_AT_PHandFX() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_45
        test byte ptr [esp + 8], 1
        je short skip_Band_AT_PHandFX
        push 0x48
        push esi
        call jmp_addr_0x00675940
        add esp, 8
    skip_Band_AT_PHandFX:
        mov eax, esi
        pop esi
        ret 4
    }
}

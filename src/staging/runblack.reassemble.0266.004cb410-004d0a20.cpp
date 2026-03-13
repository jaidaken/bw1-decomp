#include "CreatureContext.h"
#include "CreatureVisionState.h"

// win1.41 004cfe60 mac 101da7e0 CreatureContext::_dt(void)
CreatureContext::~CreatureContext()
{
}

// win1.41 004d0370 mac 10245880 CreatureVisionState::_dt(void)
CreatureVisionState::~CreatureVisionState()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void jmp_addr_0x00436960();
extern "C" void sdtor_opd_1();
extern "C" void jmp_addr_0x004d4500();

__declspec(naked) void __cdecl sdtor_Attribute() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_Attribute
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_Attribute:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeAllegiance() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeAllegiance
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeAllegiance:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeOrigin() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeOrigin
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeOrigin:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeAnimate() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeAnimate
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeAnimate:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeType() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeType
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeType:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeLife() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeLife
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeLife:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeVillagerJob() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeVillagerJob
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeVillagerJob:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeSex() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeSex
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeSex:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeOnFire() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeOnFire
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeOnFire:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributePlayerNumber() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributePlayerNumber
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributePlayerNumber:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeIsHarderThanMe() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeIsHarderThanMe
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeIsHarderThanMe:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeCreatureType() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeCreatureType
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeCreatureType:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureLearningEpisode() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x004d4500
        test byte ptr [esp + 8], 1
        je short skip_CreatureLearningEpisode
        push 0x14
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureLearningEpisode:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeTribe() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeTribe
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeTribe:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeTownReligiousBeliefInYou() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeTownReligiousBeliefInYou
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeTownReligiousBeliefInYou:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeWhatTownNeedsMost() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeWhatTownNeedsMost
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeWhatTownNeedsMost:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_AttributeTownSize() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_AttributeTownSize
        push 0xc
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_AttributeTownSize:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_CreatureVisionState() {
    __asm {
        push esi
        mov esi, ecx
        call jmp_addr_0x00436960
        test byte ptr [esp + 8], 1
        je short skip_CreatureVisionState
        push 0x48
        push esi
        call sdtor_opd_1
        add esp, 8
    skip_CreatureVisionState:
        mov eax, esi
        pop esi
        ret 4
    }
}

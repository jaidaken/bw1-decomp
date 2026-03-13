#include <stdint.h>

typedef int bool32_t;

struct Villager { char pad[0x200]; };

// Test: push esi; mov esi,ecx; call X; mov ecx,esi; call Y; pop esi; ret
extern void __fastcall DeleteDependancys_Villager(struct Villager* this) asm("?DeleteDependancys@Villager@@QAEXXZ");
extern uint32_t __fastcall RemoveFromGame_Living(struct Villager* this) asm("?RemoveFromGame@Living@@UAEIXZ");

void __fastcall test_two_calls(struct Villager* this)
{
    DeleteDependancys_Villager(this);
    RemoveFromGame_Living(this);
}

// Test: mov [ecx+0x58], 0 (word); mov eax, 1; ret 8
void __fastcall test_word_set_ret1(struct Villager* this, const void* edx, uint8_t p1, uint8_t p2)
{
    *(uint16_t*)((char*)this + 0x58) = 0;
    // return 1; — but return type is void
}

// Same as return-1 pattern
__attribute__((XOR32rr_REV))
bool32_t __fastcall test_word_set_ret1_v2(struct Villager* this, const void* edx, uint8_t p1, uint8_t p2)
{
    *(uint16_t*)((char*)this + 0x58) = 0;
    return 1;
}

// Test: call func; neg eax; sbb eax,eax; neg eax; ret
// (HousewifeLookForWork pattern - pointer to bool conversion)
extern void* __fastcall GetAbode(struct Villager* this) asm("?GetAbode@Villager@@QAEPAVAbode@@XZ");

bool32_t __fastcall test_ptr_to_bool(struct Villager* this)
{
    return GetAbode(this) != 0;
}

bool32_t __fastcall test_ptr_to_bool_v2(struct Villager* this)
{
    return !!GetAbode(this);
}

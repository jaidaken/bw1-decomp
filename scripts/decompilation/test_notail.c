#include <stdint.h>

typedef int bool32_t;

struct Villager { char pad[0x200]; };

// Test 1: disable_tail_calls to prevent tail call optimization on second call
extern void __fastcall Delete(struct Villager* this) asm("?DeleteDependancys@Villager@@QAEXXZ");
extern uint32_t __fastcall RemoveFromGameLiving(struct Villager* this) asm("?RemoveFromGame@Living@@UAEIXZ");

__attribute__((disable_tail_calls))
void __fastcall test_two_calls_notail(struct Villager* this)
{
    Delete(this);
    RemoveFromGameLiving(this);
}

// Test 2: GetPlayer LEA chain - multiplication by 2656
// Expected: lea edx,[eax+eax*4]; lea edx,[eax+edx*8]; lea eax,[eax+edx*2]; shl eax,5; lea eax,[eax+ecx+0x18]; ret 4
struct GPlayer { char data[2656]; };
struct GGame {
    char pad[0x18];
    struct GPlayer players[8];
};

struct GPlayer* __fastcall test_get_player(struct GGame* this, const void* edx, int name)
{
    return &this->players[name];
}

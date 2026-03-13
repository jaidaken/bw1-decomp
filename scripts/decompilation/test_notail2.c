#include <stdint.h>

typedef int bool32_t;

struct Villager { char pad[0x200]; };

extern void __fastcall Delete(struct Villager* this) asm("?DeleteDependancys@Villager@@QAEXXZ");
extern uint32_t __fastcall RemoveFromGameLiving(struct Villager* this) asm("?RemoveFromGame@Living@@UAEIXZ");

// Test with both attributes
__attribute__((disable_tail_calls, MOV32rr_REV))
void __fastcall test_two_calls_full(struct Villager* this)
{
    Delete(this);
    RemoveFromGameLiving(this);
}

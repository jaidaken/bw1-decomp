// Reward - Simple constant return and field getter functions
// Extracted from runblack.reassemble.0878.006de220-006f1b20.asm

#include "Reward.h"

// win1.41 006e5650 mac 10138ed0 Reward::IsReward( const(void))
uint32_t __fastcall IsReward__6RewardCFv(const struct GameThingWithPos* this)
{
    return 1;
}

// win1.41 006e5660 mac 10138f00 Reward::IsActive( const(void))
uint32_t __fastcall IsActive__6RewardCFv(const struct GameThingWithPos* this)
{
    return *(uint32_t*)((char*)this + 0x7c);
}

// win1.41 006e5670 mac 10138f30 Reward::GetSaveType(void)
uint32_t __fastcall GetSaveType__6RewardFv(struct GameThing* this)
{
    return 0x46;
}

// win1.41 006e5680 mac 10138f70 Reward::GetDebugText(void)
char* __fastcall GetDebugText__6RewardFv(struct GameThing* this)
{
    return (char*)0x00c0bf00;
}

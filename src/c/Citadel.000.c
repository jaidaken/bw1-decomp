#include "Citadel.h"
#include "Container.h"

// Container::GetPlayer - field getter at offset 0x2c
struct GPlayer* __fastcall GetPlayer__9ContainerFv(struct GameThing* this)
{
    return *(struct GPlayer**)((char*)this + 0x2c);
}

// Citadel::GetCreatureBeliefType - return 2
uint32_t __fastcall GetCreatureBeliefType__7CitadelFv(struct GameThingWithPos* this)
{
    return 2;
}

// Citadel::GetCreatureBeliefListType - return 0 (xor.s)
__attribute__((XOR32rr_REV))
uint32_t __fastcall GetCreatureBeliefListType__7CitadelFv(struct GameThingWithPos* this)
{
    return 0;
}

// Citadel::GetOrigin - return 2
uint32_t __fastcall GetOrigin__7CitadelFv(struct GameThingWithPos* this)
{
    return 2;
}

// Citadel::IsSuitableForCreatureActivity - return 1
uint32_t __fastcall IsSuitableForCreatureActivity__7CitadelFv(struct GameThingWithPos* this)
{
    return 1;
}

// Citadel::GetText - return string address
const char* __fastcall GetText__7CitadelFv(struct GameThingWithPos* this)
{
    return (const char*)0x009ce038;
}

// Citadel::IsCitadel - return 1
uint32_t __fastcall IsCitadel__7CitadelFv(struct GameThingWithPos* this)
{
    return 1;
}

// Citadel::GetSaveType - return 0x35
uint32_t __fastcall GetSaveType__7CitadelFv(struct GameThing* this)
{
    return 0x35;
}

// Citadel::GetDebugText - return string address
char* __fastcall GetDebugText__7CitadelFv(struct GameThing* this)
{
    return (char*)0x009ce860;
}

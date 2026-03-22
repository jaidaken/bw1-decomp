#include "Abode.h"

__attribute__((msvc6_regalloc, prefer_sete_ecx))
bool32_t __fastcall IsWonder__5AbodeFv(struct GameThingWithPos* this)
{
    return *(uint32_t*)((char*)*(void**)((char*)this + 0x28) + 0x120) == 0x100;
}

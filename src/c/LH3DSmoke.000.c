// LH3DSmoke::Release - cleanup function
// Address: 0x007f8d10 - 0x007f8d25

#include "libs/lionhead/lh3dlib/development/LH3DSmoke.h"

// 0x007f8d10: push esi; mov.s esi, ecx; mov ecx, [esi+0x10]; call Release@LH3DSprite;
//             push esi; call Free@LH3DMem; add esp, 4; pop esi; ret (+ 10 nops)
__attribute__((forced_callee_saves("esi"), force_this_esi, MOV32rr_REV,
               trailing_asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop")))
void __fastcall Release__9LH3DSmokeFv(struct LH3DSmoke* this)
{
    extern void __fastcall __opaque_SpriteRelease(void*) asm("?Release@LH3DSprite@@QAEXXZ");
    extern void __cdecl __opaque_Free(void*) asm("?Free@LH3DMem@@SAXPAX@Z");
    __opaque_SpriteRelease(this->sprite);
    __opaque_Free(this);
}

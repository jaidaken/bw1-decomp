#include "Abode.h"

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsWonder__5AbodeFv(struct GameThingWithPos* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00000120]\n\t"
        "xor.s              ecx, ecx\n\t"
        "cmp                edx, 0x00000100\n\t"
        "sete               cl\n\t"
        "mov.s              eax, ecx"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

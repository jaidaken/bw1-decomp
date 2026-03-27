// LH3DComplexObject virtual function overrides: simple getters/setters
// Address range: 0x0080b870 - 0x0080b90f

#include "libs/lionhead/lh3dlib/development/LH3DComplexObject.h"

// 0x0080b870: mov eax, [ecx + 0x80]; ret (+ 9 nops)
__attribute__((no_callee_saves, trailing_asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop")))
void* __fastcall FUN_0080b870(struct LH3DComplexObject* this)
{
    return *(void**)((char*)this + 0x80);
}

// 0x0080b880: mov [ecx + 0x84], edx; ret (+ 9 nops)
__attribute__((no_callee_saves, trailing_asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop")))
void __fastcall FUN_0080b880(struct LH3DComplexObject* this, uint32_t* value)
{
    *(uint32_t**)((char*)this + 0x84) = value;
}

// 0x0080b890: mov eax, [ecx + 0x84]; ret (+ 9 nops)
__attribute__((no_callee_saves, trailing_asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop")))
uint32_t* __fastcall FUN_0080b890(struct LH3DComplexObject* this)
{
    return *(uint32_t**)((char*)this + 0x84);
}

// 0x0080b8a0: mov [ecx + 0x88], edx; ret (+ 9 nops)
__attribute__((no_callee_saves, trailing_asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop")))
void __fastcall FUN_0080b8a0(struct LH3DComplexObject* this, void* value)
{
    *(void**)((char*)this + 0x88) = value;
}

// 0x0080b8b0: mov eax, [ecx + 0x88]; ret (+ 9 nops)
__attribute__((no_callee_saves, trailing_asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop")))
void* __fastcall FUN_0080b8b0(struct LH3DComplexObject* this)
{
    return *(void**)((char*)this + 0x88);
}

// 0x0080b8c0: mov [ecx + 0x8c], edx; ret (+ 9 nops)
__attribute__((no_callee_saves, trailing_asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop")))
void __fastcall FUN_0080b8c0(struct LH3DComplexObject* this, uint32_t value)
{
    asm volatile (
        "%{disp32%} mov dword ptr [ecx + 0x0000008c], edx"
        :: "c"(this), "d"(value) : "memory"
    );
}

// 0x0080b8d0: mov eax, [ecx + 0x8c]; ret (+ 9 nops)
__attribute__((no_callee_saves, trailing_asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop")))
uint32_t __fastcall FUN_0080b8d0(struct LH3DComplexObject* this)
{
    uint32_t result;
    asm volatile (
        "%{disp32%} mov eax, dword ptr [ecx + 0x0000008c]"
        : "=a"(result) : "c"(this) : "memory"
    );
    return result;
}

// 0x0080b8e0: mov eax, [esp+4]; mov [ecx + 0x90], eax; ret 4 (+ 3 nops)
__attribute__((no_callee_saves, no_ret, trailing_asm("nop\nnop\nnop")))
void __attribute__((thiscall)) FUN_0080b8e0(struct LH3DComplexObject* this, float value)
{
    asm volatile (
        "%{disp8%} mov eax, dword ptr [esp + 0x04]\n\t"
        "%{disp32%} mov dword ptr [ecx + 0x00000090], eax\n\t"
        "ret 0x0004"
        :: "c"(this) : "eax", "memory"
    );
    __builtin_unreachable();
}

// 0x0080b8f0: fld [ecx + 0x90]; ret (+ 9 nops)
__attribute__((no_callee_saves, trailing_asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop")))
float __fastcall FUN_0080b8f0(struct LH3DComplexObject* this)
{
    float result;
    asm volatile (
        "%{disp32%} fld dword ptr [ecx + 0x00000090]"
        : "=t"(result) : "c"(this) : "memory"
    );
    return result;
}

// 0x0080b900: mov eax, 1; ret (+ 10 nops)
__attribute__((no_callee_saves, trailing_asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop")))
uint32_t __fastcall FUN_0080b900(struct LH3DComplexObject* this)
{
    return 1;
}

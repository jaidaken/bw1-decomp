#include "libs/lionhead/lh3dlib/development/LHMatrix.h"

__attribute__((XOR32rr_REV))
void __fastcall SetIdentity__8LHMatrixFv(struct LHMatrix* this)
{
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x2c], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x28], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x24], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x1c], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x18], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x14], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x0c], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x08], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x04], eax\n\t"
        "mov                eax, 0x3f800000\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x20], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x10], eax\n\t"
        "mov                dword ptr [ecx], eax\n\t"
        "ret\n\t"
        "call               ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
void __fastcall Translation__8LHMatrixFv(struct LHMatrix* this, const struct LHPoint* translation)
{
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x2c], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x28], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x24], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x1c], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x18], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x14], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x0c], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x08], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x04], eax\n\t"
        "mov                eax, 0x3f800000\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x20], eax\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x10], eax\n\t"
        "mov                dword ptr [ecx], eax\n\t"
        "mov                eax, dword ptr [edx]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x24], eax\n\t"
        "%{disp8%} mov        eax, dword ptr [edx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x28], eax\n\t"
        "%{disp8%} mov        edx, dword ptr [edx + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x2c], edx"
        :  : "c"(this) : "eax", "edx", "memory"
    );
}

void __fastcall PostTranslation__8LHMatrixFRC7LHPoint(struct LHMatrix* this, struct LHPoint* translation)
{
    asm volatile (
        "fld                dword ptr [edx]\n\t"
        "%{disp8%} fadd       dword ptr [ecx + 0x24]\n\t"
        "%{disp8%} fstp       dword ptr [ecx + 0x24]\n\t"
        "%{disp8%} fld        dword ptr [edx + 0x04]\n\t"
        "%{disp8%} fadd       dword ptr [ecx + 0x28]\n\t"
        "%{disp8%} fstp       dword ptr [ecx + 0x28]\n\t"
        "%{disp8%} fld        dword ptr [edx + 0x08]\n\t"
        "%{disp8%} fadd       dword ptr [ecx + 0x2c]\n\t"
        "%{disp8%} fstp       dword ptr [ecx + 0x2c]\n\t"
        "ret\n\t"
        "call               ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

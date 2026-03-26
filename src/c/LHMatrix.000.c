#include "libs/lionhead/lh3dlib/development/LHMatrix.h"

__attribute__((no_callee_saves, XOR32rr_REV, store_order("0x2c,0x28,0x24,0x1c,0x18,0x14,0x0c,0x08,0x04,0x20,0x10,0x00"), trailing_asm("call               ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9")))
void __fastcall SetIdentity__8LHMatrixFv(struct LHMatrix* this)
{
    register unsigned int zero asm("eax");
    asm volatile("" : "=a"(zero) : "0"(0));
    unsigned int* p = (unsigned int*)this->m;
    p[11] = zero;
    p[10] = zero;
    p[9] = zero;
    p[7] = zero;
    p[6] = zero;
    p[5] = zero;
    p[3] = zero;
    p[2] = zero;
    p[1] = zero;
    asm volatile("" : "=a"(zero) : "0"(0x3f800000));
    p[8] = zero;
    p[4] = zero;
    p[0] = zero;
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

__attribute__((no_callee_saves, prefer_fmul_mem, trailing_asm("call               ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9")))
void __fastcall PostTranslation__8LHMatrixFRC7LHPoint(struct LHMatrix* this, struct LHPoint* translation)
{
    *(float*)((char*)this + 0x24) += *(float*)((char*)translation + 0x00);
    *(float*)((char*)this + 0x28) += *(float*)((char*)translation + 0x04);
    *(float*)((char*)this + 0x2c) += *(float*)((char*)translation + 0x08);
}

#include "libs/lionhead/lh3dlib/development/LHMatrix.h"

__attribute__((no_callee_saves, XOR32rr_REV, prefer_register_store, store_order("0x2c,0x28,0x24,0x1c,0x18,0x14,0x0c,0x08,0x04,0x20,0x10,0x00"), trailing_asm("call               ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9")))
void __fastcall SetIdentity__8LHMatrixFv(struct LHMatrix* this)
{
    unsigned int* p = (unsigned int*)this->m;
    p[11] = 0;
    p[10] = 0;
    p[9] = 0;
    p[7] = 0;
    p[6] = 0;
    p[5] = 0;
    p[3] = 0;
    p[2] = 0;
    p[1] = 0;
    p[8] = 0x3f800000;
    p[4] = 0x3f800000;
    p[0] = 0x3f800000;
}

__attribute__((XOR32rr_REV, no_callee_saves, prefer_register_store, prefer_source_register_reuse, store_order("0x2c,0x28,0x24,0x1c,0x18,0x14,0x0c,0x08,0x04,0x20,0x10,0x00")))
void __fastcall Translation__8LHMatrixFv(struct LHMatrix* this, const struct LHPoint* translation)
{
    unsigned int* p = (unsigned int*)this->m;
    p[11] = 0;
    p[10] = 0;
    p[9] = 0;
    p[7] = 0;
    p[6] = 0;
    p[5] = 0;
    p[3] = 0;
    p[2] = 0;
    p[1] = 0;
    p[8] = 0x3f800000;
    p[4] = 0x3f800000;
    p[0] = 0x3f800000;
    *(unsigned int*)((char*)this + 0x24) = *(const unsigned int*)((const char*)translation + 0x00);
    *(unsigned int*)((char*)this + 0x28) = *(const unsigned int*)((const char*)translation + 0x04);
    *(unsigned int*)((char*)this + 0x2c) = *(const unsigned int*)((const char*)translation + 0x08);
}

__attribute__((no_callee_saves, prefer_fmul_mem, trailing_asm("call               ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9")))
void __fastcall PostTranslation__8LHMatrixFRC7LHPoint(struct LHMatrix* this, struct LHPoint* translation)
{
    *(float*)((char*)this + 0x24) += *(float*)((char*)translation + 0x00);
    *(float*)((char*)this + 0x28) += *(float*)((char*)translation + 0x04);
    *(float*)((char*)this + 0x2c) += *(float*)((char*)translation + 0x08);
}

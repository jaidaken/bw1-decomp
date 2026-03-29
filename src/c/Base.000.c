#include "Base.h"

#include "reversing_utils/re_rtti.h"

struct RTTITypeDescriptor __RTTITypeDescriptor__4Base = {
    .pVFTable = &__vt__9type_info,
    .spare = 0,
    .name = ".?AVBase@@",
};

// Inlined so that the first object file to be compiles (AbodeInfo.o is before Base.o) has these definitions first

void __fastcall Serialise__4BaseFR7Archive(struct Base* this, const void* edx, struct Archive* param_1)
{
}

__attribute__((no_callee_saves, trailing_asm(".byte 0x45, 0x16, 0xa1, 0x03")))
void __fastcall Delete__4BaseFv(struct Base* this)
{
    if (this)
    {
        // this->vftable->__dt(this, edx, 1);
        asm("mov  eax, dword ptr [ecx]");  // 0x004011c4    8b01
        asm("push 0x1");                   // 0x004011c6    6a01
        asm("call dword ptr [eax + 4]");   // 0x004011c8    ff5004
    }
}

__attribute__((no_tail_call))
void __fastcall ToBeDeleted__4BaseFi(struct Base* this, const void* edx, int param_1)
{
    typedef void (__attribute__((thiscall)) *fn_t)(struct Base*);
    fn_t fn = ((fn_t*)(*(void**)this))[8 / 4];
    fn(this);
}

__attribute__((XOR32rr_REV))
int __fastcall Get3DSoundPos__4BaseFP7LHPoint(struct Base* this, const void* edx, struct LHPoint* param_1)
{
  return 0;
}

void __fastcall CleanUpForSerialisation__4BaseFv(struct Base* this)
{
}

void __fastcall Dump__4BaseFv(struct Base* this)
{
}

__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,8,")))
void __fastcall __dt__4BaseFUi(struct Base* this, const void* edx, uint32_t param_1)
{}

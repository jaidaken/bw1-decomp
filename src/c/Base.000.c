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

void __fastcall __dt__4BaseFUi(struct Base* this, const void* edx, uint32_t param_1)
{
    asm("push             esi");                               // 0x00401210    56
    asm("mov.s            esi, ecx");                          // 0x00401211    8bf1
    asm("call             _jmp_addr_0x00436960");              // 0x00401213    e848570300
    asm("test             byte ptr [esp + 0x08], 0x01");       // 0x00401218    f644240801
    asm("{disp8} je       LAB__addr_0x0040122a");              // 0x0040121d    740b
    asm("push             0x8");                               // 0x0040121f    6a08
    asm("push             esi");                               // 0x00401221    56
    asm("call             ??3Base@@SAXPAXK@Z");              // 0x00401222    e849570300
    asm("add              esp, 0x08");                         // 0x00401227    83c408
    asm("LAB__addr_0x0040122a:");
    asm("mov.s            eax, esi");                          // 0x0040122a    8bc6
    asm("pop              esi");                               // 0x0040122c    5e
}

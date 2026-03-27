// CAnim trivial default constructor
// Original: mov.s eax, ecx; ret; 13x nop (16-byte aligned)

struct CAnim;

__attribute__((MOV32rr_REV, trailing_nops(13)))
struct CAnim* __fastcall ctor__5CAnimFv(struct CAnim* this) asm("??0CAnim@@QAE@XZ");

__attribute__((MOV32rr_REV, trailing_nops(13)))
struct CAnim* __fastcall ctor__5CAnimFv(struct CAnim* this)
{
    return this;
}

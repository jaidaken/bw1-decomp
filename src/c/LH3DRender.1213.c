// LH3DRender global constructors (static initializers)
// Extracted from runblack.reassemble.1213.0081e1f0-0082a2c0.asm
// Address range: [0x0081e320, 0x0081e360)

#include <stdint.h>

extern char data_bytes[];

// ============================================================================
// globl_ct_0x0081e320: empty init guard (jmp to ret)
// ============================================================================

extern void __cdecl jmp_addr_0x0081e330(void) __attribute__((noinline));

void __cdecl globl_ct_0x0081e320(void)
{
    __attribute__((musttail)) return jmp_addr_0x0081e330();
}

void __cdecl jmp_addr_0x0081e330(void)
{
    asm volatile ("" ::: "memory");
}

// ============================================================================
// globl_ct_0x0081e340: copy data_bytes[0x2721dc] to data_bytes[0x4e43c4]
// ============================================================================

extern void __cdecl jmp_addr_0x0081e350(void) __attribute__((noinline));

void __cdecl globl_ct_0x0081e340(void)
{
    __attribute__((musttail)) return jmp_addr_0x0081e350();
}

void __cdecl jmp_addr_0x0081e350(void)
{
    *(uint32_t*)(data_bytes + 0x4e43c4) = *(uint32_t*)(data_bytes + 0x2721dc);
}

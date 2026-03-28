// LH3DTech global constructors (static initializers)
// Extracted from runblack.reassemble.1199.0080b870-0081b370.asm
// Address range: [0x00818900, 0x008189f0)

#include <stdint.h>

extern char data_bytes[];

// ============================================================================
// globl_ct_0x00818900: empty init guard (jmp to ret)
// ============================================================================

extern void __cdecl jmp_addr_0x00818910(void) __attribute__((noinline));

void __cdecl globl_ct_0x00818900(void)
{
    __attribute__((musttail)) return jmp_addr_0x00818910();
}

__attribute__((optnone))
void __cdecl jmp_addr_0x00818910(void)
{
}

// ============================================================================
// globl_ct_0x00818920: store 3 float constants to data_bytes+0x4dbc88
// ============================================================================

extern void __cdecl jmp_addr_0x00818930(void) __attribute__((noinline));

void __cdecl globl_ct_0x00818920(void)
{
    __attribute__((musttail)) return jmp_addr_0x00818930();
}

void __cdecl jmp_addr_0x00818930(void)
{
    *(uint32_t*)(data_bytes + 0x4dbc88) = 0xc8f42400;
    *(uint32_t*)(data_bytes + 0x4dbc8c) = 0x48f42400;
    *(uint32_t*)(data_bytes + 0x4dbc90) = 0xc8f42400;
}

// ============================================================================
// globl_ct_0x00818950: copy 3 dwords from data_bytes+0x4dbc88 to +0x4e3e90
// ============================================================================

extern void __cdecl jmp_addr_0x00818960(void) __attribute__((noinline));

void __cdecl globl_ct_0x00818950(void)
{
    __attribute__((musttail)) return jmp_addr_0x00818960();
}

void __cdecl jmp_addr_0x00818960(void)
{
    uint32_t a = *(uint32_t*)(data_bytes + 0x4dbc88);
    uint32_t b = *(uint32_t*)(data_bytes + 0x4dbc8c);
    uint32_t c = *(uint32_t*)(data_bytes + 0x4dbc90);
    *(uint32_t*)(data_bytes + 0x4e3e90) = a;
    *(uint32_t*)(data_bytes + 0x4e3e94) = b;
    *(uint32_t*)(data_bytes + 0x4e3e98) = c;
}

// ============================================================================
// globl_ct_0x00818990: store 3 constants (0, 1.0f, 0) to data_bytes+0x4e3e80
// ============================================================================

extern void __cdecl jmp_addr_0x008189a0(void) __attribute__((noinline));

void __cdecl globl_ct_0x00818990(void)
{
    __attribute__((musttail)) return jmp_addr_0x008189a0();
}

void __cdecl jmp_addr_0x008189a0(void)
{
    *(uint32_t*)(data_bytes + 0x4e3e80) = 0x00000000;
    *(uint32_t*)(data_bytes + 0x4e3e84) = 0x3f800000;
    *(uint32_t*)(data_bytes + 0x4e3e88) = 0x00000000;
}

// ============================================================================
// globl_ct_0x008189c0: store 3 constants (1.0f, 0, 0) to data_bytes+0x4e3e70
// ============================================================================

extern void __cdecl jmp_addr_0x008189d0(void) __attribute__((noinline));

void __cdecl globl_ct_0x008189c0(void)
{
    __attribute__((musttail)) return jmp_addr_0x008189d0();
}

__attribute__((trailing_asm("nop")))
void __cdecl jmp_addr_0x008189d0(void)
{
    *(uint32_t*)(data_bytes + 0x4e3e70) = 0x3f800000;
    *(uint32_t*)(data_bytes + 0x4e3e74) = 0x00000000;
    *(uint32_t*)(data_bytes + 0x4e3e78) = 0x00000000;
}

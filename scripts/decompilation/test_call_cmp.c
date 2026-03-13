#include <stdint.h>

typedef int bool32_t;

struct Info {
    char pad[0x120];
    uint32_t abodeType;
};

// Simulates GetInfo returning a static pointer
extern struct Info* __cdecl GetInfo(void) asm("?GetInfo@PlannedAbode@@SAPAVGPlannedAbodeInfo@@XZ");

// Test: call GetInfo; mov edx,[eax+0x120]; xor ecx,ecx; cmp edx,0x100; sete cl; mov eax,ecx; ret
__attribute__((XOR32rr_REV))
bool32_t __fastcall test_call_compare(void* this)
{
    return GetInfo()->abodeType == 0x100;
}

// Test: call GetInfo; mov eax,[eax+0x120]; and eax,[esp+4]; neg; sbb; neg; ret 4
__attribute__((XOR32rr_REV))
bool32_t __fastcall test_call_and_bool(void* this, const void* edx, uint32_t mask)
{
    return (GetInfo()->abodeType & mask) != 0;
}

// Test: call GetInfo; mov edx,[eax+0x1f8]; xor ecx,ecx; test edx,edx; sete cl; mov eax,ecx; ret
struct Info2 {
    char pad[0x1f8];
    uint32_t sex;
};
extern struct Info2* __cdecl GetInfo2(void) asm("?GetInfo2@@SAPAVGInfo2@@XZ");

__attribute__((XOR32rr_REV))
uint32_t __fastcall test_call_test_zero(void* this)
{
    return GetInfo2()->sex == 0;
}

#include <stdint.h>

typedef int bool32_t;

struct Object {
    char pad[0x28];
    void* info;
};

struct AbodeInfo {
    char pad[0x120];
    uint32_t abodeType;
};

struct VillagerInfo {
    char pad[0x1f8];
    uint32_t sex;
};

// Test: xor ecx; cmp; sete cl; mov eax, ecx; ret
__attribute__((XOR32rr_REV))
bool32_t __fastcall test_is_wonder(struct Object* this)
{
    return ((struct AbodeInfo*)this->info)->abodeType == 0x100;
}

// Test: xor ecx; test edx,edx; sete cl; mov eax,ecx; ret
__attribute__((XOR32rr_REV))
uint32_t __fastcall test_is_male(struct Object* this)
{
    return ((struct VillagerInfo*)this->info)->sex == 0;
}

// Test: xor ecx; cmp edx,1; sete cl; mov eax,ecx; ret
__attribute__((XOR32rr_REV))
uint32_t __fastcall test_is_female(struct Object* this)
{
    return ((struct VillagerInfo*)this->info)->sex == 1;
}

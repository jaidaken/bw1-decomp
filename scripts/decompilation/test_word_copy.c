#include <stdint.h>

typedef int bool32_t;

struct Object {
    char pad[0x28];
    void* info;
};

struct MobileWallHug {
    char pad[0x58];
    int16_t turns_until_next_state_change;
};

struct VillagerInfo {
    char pad[0x394];
    int16_t sit_duration;
};

// Test: mov eax,[ecx+0x28]; mov dx,[eax+0x394]; mov [ecx+0x58],dx; mov eax,1; ret 8
bool32_t __fastcall test_word_copy_ret1(struct Object* this, const void* edx, unsigned char p1, unsigned char p2)
{
    ((struct MobileWallHug*)this)->turns_until_next_state_change =
        ((struct VillagerInfo*)this->info)->sit_duration;
    return 1;
}

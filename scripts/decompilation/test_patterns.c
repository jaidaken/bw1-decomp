// Test file for call wrapper patterns
#include <stdint.h>
#include <stdbool.h>

typedef int bool32_t;

struct MapCoords { float x, y, z; };

// Pattern: forward stack param to another function (push+call+ret)
extern float __fastcall target_with_param(void* this, const void* edx, const struct MapCoords* p);
float __fastcall test_forward_param(void* this, const void* edx, const struct MapCoords* p)
{
    return target_with_param(this, edx, p);
}

// Same but without musttail
extern float __fastcall target_with_param2(void* this, const void* edx, const struct MapCoords* p);
__attribute__((noinline))
float __fastcall test_forward_param_noinline(void* this, const void* edx, const struct MapCoords* p)
{
    return target_with_param2(this, edx, p);
}

// Pattern: push constant args, call function
extern bool32_t __fastcall target_two_ints(void* this, const void* edx, int a, int b);
bool32_t __fastcall test_push_constants(void* this)
{
    return target_two_ints(this, 0, 0x25, 0xEE);
}

// Pattern: call static func, read field at large offset
struct BigInfo { char pad[0x120]; int field_120; };
extern struct BigInfo* __cdecl get_big_info(void);
int __fastcall test_call_read_field(void* this)
{
    return get_big_info()->field_120;
}

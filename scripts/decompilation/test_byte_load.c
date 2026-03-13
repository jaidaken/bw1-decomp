#include <stdint.h>

// Test: can clang generate "mov al, [addr]" (opcode a0) for returning a global byte?

extern char data_bytes[];

// Pattern 1: direct byte return from global array
uint8_t test_byte_from_array(void* this, const void* edx, void* p1, void* p2)
{
    return *(uint8_t*)(data_bytes + 0x38a598);
}

// Pattern 2: separate global variable
extern uint8_t some_byte_global;
uint8_t test_byte_global(void* this, const void* edx, void* p1, void* p2)
{
    return some_byte_global;
}

// Pattern 3: cast to uint8_t
extern char some_char_global;
uint8_t test_char_global(void* this, const void* edx, void* p1, void* p2)
{
    return (uint8_t)some_char_global;
}

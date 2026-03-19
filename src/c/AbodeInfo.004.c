#include "AbodeInfo.h"

__attribute__((no_callee_saves))
bool32_t __fastcall IsOkToCreateAtPos__10GAbodeInfoCFRC9MapCoordsffP4Town(const struct GAbodeInfo* this, const void* edx, const struct MapCoords* coords, float param_2, float param_3, struct Town* town)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x14]\n\t"
        "push               edx\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "push               eax\n\t"
        "call               dword ptr [edx + 0x2c]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x00603860\n\t"
        "neg                eax\n\t"
        "sbb.s              eax, eax\n\t"
        "neg                eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

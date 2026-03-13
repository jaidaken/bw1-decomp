#include "PlannedAbode.h"

const double rdata_double_1_25 asm("__real@3ff4000000000000") = 1.25;

struct PlannedAbode* __fastcall __ct__12PlannedAbodeFP5Abode(struct PlannedAbode* this, const void* edx, struct Abode* abode)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x00648820\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x48], 0x00000000\n\t"
        "mov                dword ptr [esi], 0x008aa3bc\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

void __fastcall Init__12PlannedAbodeFP4Town(struct PlannedAbode* this, const void* edx, struct Town* town)
{
    asm volatile (
        "mov.s eax, ecx\n\t"
        "%{disp8%} mov ecx, dword ptr [esp + 0x04]\n\t"
        "test ecx, ecx\n\t"
        "%{disp8%} mov dword ptr [eax + 0x48], ecx\n\t"
        "%{disp8%} je 0f\n\t"
        "push eax\n\t"
        "call ?AddPlanned@Town@@QAEXPAVPlannedMultiMapFixed@@@Z\n"
        "0:\n\t"
        "ret 0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
struct PlannedAbode* __cdecl CreateNoInit__12PlannedAbodeFRC9MapCoordsPC10GAbodeInfoP4Townff(struct MapCoords* coords, struct GMultiMapFixedInfo* info, struct Town* town, float param_4, float param_5)
{
    asm volatile (
        "push               0x0000054f\n\t"
        "push               0x009c7fbc\n\t"
        "push               0x4c\n\t"
        "call               ?__nw@Base@@SAPAXK@Z\n\t"
        "add                esp, 0x0c\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x004055f9\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x14]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "push               edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "push               edx\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ??0PlannedAbode@@QAE@ABUMapCoords@@PBVGAbodeInfo@@PAVTown@@MMMH@Z\n\t"
        "ret\n"
        "LAB__addr_0x004055f9:\n\t"
        "xor.s              eax, eax\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
struct PlannedAbode* __cdecl Create__12PlannedAbodeFRC9MapCoordsPC10GAbodeInfoP4Townff(struct MapCoords* coords, struct GMultiMapFixedInfo* info, struct Town* town, float param_4, float param_5)
{
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "push               0x00000557\n\t"
        "push               0x009c7fbc\n\t"
        "push               0x4c\n\t"
        "call               ?__nw@Base@@SAPAXK@Z\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x20]\n\t"
        "add                esp, 0x0c\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00405649\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x1c]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x18]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x14]\n\t"
        "push               edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x14]\n\t"
        "push               edi\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ??0PlannedAbode@@QAE@ABUMapCoords@@PBVGAbodeInfo@@PAVTown@@MMMH@Z\n\t"
        "mov.s              esi, eax\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?Init@PlannedAbode@@QAEXPAVTown@@@Z\n\t"
        "pop                edi\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00405649:\n\t"
        "xor.s              esi, esi\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?Init@PlannedAbode@@QAEXPAVTown@@@Z\n\t"
        "pop                edi\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
struct PlannedAbode* __cdecl Create__12PlannedAbodeFP5Abode(struct Abode* abode)
{
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "push               0x00000560\n\t"
        "push               0x009c7fbc\n\t"
        "push               0x4c\n\t"
        "call               ?__nw@Base@@SAPAXK@Z\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x18]\n\t"
        "add                esp, 0x0c\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0040568a\n\t"
        "push               edi\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ??0PlannedAbode@@QAE@PAVAbode@@@Z\n\t"
        "mov.s              esi, eax\n\t"
        "%{disp8%} jmp        LAB__addr_0x0040568c\n"
        "LAB__addr_0x0040568a:\n\t"
        "xor.s              esi, esi\n"
        "LAB__addr_0x0040568c:\n\t"
        "%{disp8%} mov        eax, dword ptr [edi + 0x64]\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x38], eax\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "%{disp8%} mov        dword ptr [edi + 0x64], 0x00000000\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?Init@PlannedAbode@@QAEXPAVTown@@@Z\n\t"
        "pop                edi\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

void __fastcall ToBeDeleted__12PlannedAbodeFi(struct Base* this, const void* edx, int param_1)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x48]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x004056c0\n\t"
        "push               esi\n\t"
        "call               ?RemovePlanned@Town@@QAEXPAVPlannedMultiMapFixed@@@Z\n"
        "LAB__addr_0x004056c0:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ToBeDeleted@GameThingWithPos@@UAEXH@Z\n\t"
        "pop                esi\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

struct GPlannedAbodeInfo* __cdecl GetInfo__12PlannedAbodeFv(void)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x40]\n\t"
        "ret\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x2c], eax\n\t"
        "ret                0x0004\n\t"
        "call               dword ptr [__imp__CoFileTimeToDosDateTime@4]"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

bool32_t __fastcall FUN_004056f0__12PlannedAbodeFP4Town(struct PlannedAbode* this, const void* edx, int param_1)
{
    asm volatile (
        "call ?GetInfo@PlannedAbode@@SAPAVGPlannedAbodeInfo@@XZ\n\t"
        "%{disp32%} mov eax, dword ptr [eax + 0x00000120]\n\t"
        "and eax, dword ptr [esp + 0x04]\n\t"
        "neg eax\n\t"
        ".byte 0x1b, 0xc0\n\t"
        "neg eax\n\t"
        "ret 0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
struct MultiMapFixed* __fastcall CreatePlanned__12PlannedAbodeFf(struct PlannedMultiMapFixed* this, const void* edx, float param_1)
{
    asm volatile (
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x48]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], ecx\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x120]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetInfo@PlannedAbode@@SAPAVGPlannedAbodeInfo@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?IsOkToCreateAtPos@GAbodeInfo@@QBE_NPBUMapCoords@@MMPAVTown@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0040575c\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x0c]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x504]\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0040575c:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
struct MultiMapFixed* __fastcall CreatePlannedNoFixedCheck__12PlannedAbodeFf(struct PlannedMultiMapFixed* this, const void* edx, float param_1)
{
    asm volatile (
        "push               ecx\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x48]\n\t"
        "push               0x1\n\t"
        "push               0x1\n\t"
        "push               ecx\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], eax\n\t"
        "call               dword ptr [edx + 0x120]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x1c]\n\t"
        "push               ecx\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               eax\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetInfo@PlannedAbode@@SAPAVGPlannedAbodeInfo@@XZ\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "push               ecx\n\t"
        "call               ?Create@Abode@@SAPAV1@PBUMapCoords@@PBVGAbodeInfo@@PAVTown@@MMIIMHH@Z\n\t"
        "mov.s              edi, eax\n\t"
        "add                esp, 0x28\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x004057e1\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x508]\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x30]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x004057d0\n\t"
        "or                 byte ptr [edi + 0x58], 4\n"
        "LAB__addr_0x004057d0:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xc]\n\t"
        "mov.s              eax, edi\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x004057e1:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

bool32_t __fastcall IsOkToBuild__12PlannedAbodeFv(struct PlannedAbode* this)
{
    asm volatile (
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], eax\n\t"
        "call               ?GetInfo@PlannedAbode@@SAPAVGPlannedAbodeInfo@@XZ\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "mov.s              edi, eax\n\t"
        "call               dword ptr [edx + 0x120]\n\t"
        "%{disp32%} fmul      qword ptr [__real@3ff4000000000000]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "push               ecx\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x2c]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "call               ?IsSuitableForFixed@MapCoords@@QBEXW4MESH_LIST@@MM@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall Save__12PlannedAbodeFR10GameOSFile(struct GameThing* this, const void* edx, struct GameOSFile* file)
{
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "call               ?Save@PlannedMultiMapFixed@@QAEIAAVGGameOSFile@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00405857\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x48]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?WritePtr@GameOSFile@@QAEXPAVGameThing@@@Z\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00405857:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall Load__12PlannedAbodeFR10GameOSFile(struct GameThing* this, const void* edx, struct GameOSFile* file)
{
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "mov.s              esi, ecx\n\t"
        "push               edi\n\t"
        "call               ?Load@PlannedMultiMapFixed@@QAEIAAVGGameOSFile@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00405887\n\t"
        "add                esi, 0x48\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               @ReadPtr__10GameOSFileFPP9GameThing@12\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00405887:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

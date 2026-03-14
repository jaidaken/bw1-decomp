#include "Villager.h"
#include "VillagerInfo.h"

extern const char debug_text_Villager[10];

__attribute__((XOR32rr_REV))
struct Villager* __fastcall __ct__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ??0MobileWallHug@@QAE@XZ\n\t"
        "%{disp32%} lea       ecx, dword ptr [esi + 0x0000008c]\n\t"
        "call               ??0LivingAction@@QAE@XZ\n\t"
        "xor.s              edi, edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000094], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000098], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000a4], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000b8], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000bc], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000d8], edi\n\t"
        "mov.s              ecx, esi\n\t"
        "mov                dword ptr [esi], 0x008cd394\n\t"
        "call               ?SetToZero@Living@@QAEXXZ\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000e4], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000fc], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000010c], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000110], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000010c], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000110], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000110], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000114], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000010c], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000110], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000011c], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000011c], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000120], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000011c], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000120], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000124], edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000011c], edi\n\t"
        "mov.s              ecx, esi\n\t"
        "mov                dword ptr [esi], 0x008f7960\n\t"
        "call               ?SetToZero@Villager@@QAEXXZ\n\t"
        "pop                edi\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi\n\t"
        "ret\n\t"
        "call               ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

#if HAS_EXPAND_MOVZX
__attribute__((expand_movzx))
bool32_t __fastcall IsChild__8VillagerFv(struct Living* this)
{
    return (*((uint8_t*)this + 0xe0) >> 3) & 1;
}
#else
bool32_t __fastcall IsChild__8VillagerFv(struct Living* this)
{
    bool32_t result;
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [ecx + 0x000000e0]\n\t"
        "shr                eax, 3\n\t"
        "and                eax, 0x01"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}
#endif

__attribute__((XOR32rr_REV))
bool __fastcall IsFoodSpeedUp__8VillagerFv(struct Living* this)
{
    asm volatile (
        "%{disp32%} mov       dl, byte ptr [ecx + 0x000000f0]\n\t"
        "xor.s              eax, eax\n\t"
        "test               dl, dl\n\t"
        "setne              al\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

bool32_t __fastcall IsABeliever__8VillagerFv(struct Object* this)
{
    return true;
}

bool __fastcall IsTouching_3__8VillagerCFP6Objectf(const struct Object* this, const void* edx, struct Object* param_1, float param_2)
{
    asm volatile (
        "%{disp8%} mov eax, dword ptr [esp + 0x08]\n\t"
        "%{disp8%} mov edx, dword ptr [esp + 0x04]\n\t"
        "push eax\n\t"
        "push edx\n\t"
        "call ?IsTouching@Object@@UAE_NPAV1@M@Z\n\t"
        "ret 0x0008"
        :: "c"(this) : "eax", "edx", "memory"
    );
    __builtin_unreachable();
}

int __fastcall GetMesh__8VillagerCFv(const struct Object* this)
{
    int result = *(int*)((char*)*(void**)((char*)this + 0x28) + 0x214);
    asm volatile (
        "ret\n\t"
        "call               dword ptr [__imp__BinkService@4]"
        :: "a"(result) : "memory"
    );
    __builtin_unreachable();
}

int __fastcall GetDetailMesh__8VillagerFi(struct Object* this, const void* edx, int param_1)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x04]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + ecx * 0x4 + 0x00000210]\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

bool __fastcall IsScriptState__8VillagerCF15VILLAGER_STATES(const struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    asm volatile (
        "%{disp8%} mov        ecx, dword ptr [esp + 0x04]\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                eax, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax * 0x4 + 0x00db9e90]\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

bool __fastcall IsScriptInterruptableState__8VillagerCF15VILLAGER_STATES(const struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    asm volatile (
        "%{disp8%} mov        ecx, dword ptr [esp + 0x04]\n\t"
        "lea                eax, dword ptr [ecx + ecx * 0x2]\n\t"
        "shl                eax, 3\n\t"
        "sub.s              eax, ecx\n\t"
        "lea                eax, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax * 0x4 + 0x00db9e94]\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

uint32_t __fastcall GetTastiness__8VillagerFv(struct Object* this)
{
    return 2;
}

__attribute__((XOR32rr_REV))
const char* __fastcall GetVillagerName__8VillagerFv(struct Villager* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool __fastcall CanBePickedUp__8VillagerFv(struct Object* this)
{
    asm volatile (
        "test               byte ptr [ecx + 0x000000e0], 0x04\n\t"
        "%{disp8%} je         LAB__addr_0x0055ca5c\n\t"
        "xor.s              eax, eax\n\t"
        "ret\n"
        "LAB__addr_0x0055ca5c:\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        ax, word ptr [ecx + 0x24]\n\t"
        "not                ax\n\t"
        "shr                eax, 0xd\n\t"
        "and                eax, 0x01\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

uint32_t __fastcall GetCreatureBeliefType__8VillagerFv(struct GameThingWithPos* this)
{
    return 6;
}

uint32_t __fastcall CanBeImpressedByCreature__8VillagerFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* param_1)
{
    void* dummy;
    uint32_t result;
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "call dword ptr [eax + 0x978]\n\t"
        "neg eax\n\t"
        ".byte 0x1b, 0xc0\n\t"
        "inc eax"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

uint32_t __fastcall CanReceiveGifts__8VillagerFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* param_1)
{
    return 1;
}

uint32_t __fastcall CanBeHelpedByCreature__8VillagerFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* param_1)
{
    asm volatile (
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x628]\n\t"
        "ret                0x0004\n\t"
        "call               ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

uint32_t __fastcall IsVillager__8VillagerFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* param_1)
{
    return 1;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall IsMaleVillager__8VillagerFv(struct GameThingWithPos* this)
{
    void* dummy;
    uint32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x000001f8]\n\t"
        "xor.s              ecx, ecx\n\t"
        "test               edx, edx\n\t"
        "sete               cl\n\t"
        "mov.s              eax, ecx"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall IsFemaleVillager__8VillagerFv(struct GameThingWithPos* this)
{
    void* dummy;
    uint32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x000001f8]\n\t"
        "xor.s              ecx, ecx\n\t"
        "cmp                edx, 0x01\n\t"
        "sete               cl\n\t"
        "mov.s              eax, ecx"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

uint32_t __fastcall IsAChild__8VillagerFv(struct GameThingWithPos* this)
{
    void* dummy;
    uint32_t result;
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "call dword ptr [eax + 0xaf8]\n\t"
        "dec eax\n\t"
        "neg eax\n\t"
        ".byte 0x1b, 0xc0\n\t"
        "inc eax"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

#if HAS_EXPAND_MOVZX
__attribute__((XOR32rr_REV, expand_movzx))
enum DEATH_REASON __fastcall GetDeathReason__8VillagerFv(struct GameThingWithPos* this)
{
    return *(uint8_t*)((char*)this + 0x118);
}
#else
__attribute__((XOR32rr_REV))
enum DEATH_REASON __fastcall GetDeathReason__8VillagerFv(struct GameThingWithPos* this)
{
    enum DEATH_REASON result;
    asm volatile (
        "xor.s              eax, eax\n\t"
        "%{disp32%} mov       al, byte ptr [ecx + 0x00000118]"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}
#endif

uint32_t __fastcall GetSaveType__8VillagerFv(struct GameThing* this)
{
    return 6;
}

char* __fastcall GetDebugText__8VillagerFv(struct GameThing* this)
{
    return (char*)0x00bed194;
}

void __fastcall __dt__8VillagerFUi(struct Base* this, const void* edx, uint32_t param_1)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ??1Villager@@UAE@XZ\n\t"
        "test               byte ptr [esp + 0x08], 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x0055cb5d\n\t"
        "push               0x00000130\n\t"
        "push               esi\n\t"
        "call               ??3Base@@SAXPAXK@Z\n\t"
        "add                esp, 0x08\n"
        "LAB__addr_0x0055cb5d:\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

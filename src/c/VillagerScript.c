#include "Villager.h"

const float villager_script_num_days_in_year_0x0099a9f8 = 365.25f;
const float villager_script_seconds_in_day_0x0099a9fc = 86400.0f;
const float villager_script_float0p7_0x0099aa00 = 0.7f;

__attribute__((aligned(4))) char s_VillagerScript_cpp[] = "C:\\dev\\MP\\Black\\VillagerScript.cpp";

uint32_t villager_script_uint_0x00db9e44;
uint32_t villager_script_uint_0x00db9e48;
float villager_script_seconds_in_year_0x00db9e4c;

__attribute__((no_ret))
void __cdecl globl_ct_0x007685b0(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x007685c4\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x007685c4:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x007685d0"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

void __cdecl crt_global_destruction_register_0x007685d0(void)
{
    asm volatile (
        "push               0x00407870\n\t"
        "call               _atexit\n\t"
        "pop                ecx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

extern void __cdecl FUN_007685f0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x007685e0(void)
{
    __attribute__((musttail)) return FUN_007685f0__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_007685f0__8VillagerFv(void)
{
    extern float __opaque_a asm("_villager_script_seconds_in_day_0x0099a9fc");
    extern float __opaque_b asm("_villager_script_num_days_in_year_0x0099a9f8");
    extern float __opaque_c asm("_villager_script_seconds_in_year_0x00db9e4c");
    __opaque_c = __opaque_a * __opaque_b;
}

extern void __cdecl FUN_00768620__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x00768610(void)
{
    __attribute__((musttail)) return FUN_00768620__8VillagerFv();
}

void __cdecl FUN_00768620__8VillagerFv(void)
{
    (void)villager_script_uint_0x00db9e44;
    villager_script_uint_0x00db9e48 = 0xffffffff;
}

uint32_t __fastcall IsReadyForNewScriptAction__8VillagerFv(struct GameThingWithPos* this)
{
    void* dummy;
    uint32_t result;
    asm volatile (
        "call ?GetTopState@Living@@QBE?AW4VILLAGER_STATES@@XZ\n\t"
        "sub al, 0x04\n\t"
        "neg al\n\t"
        ".byte 0x1b, 0xc0\n\t"
        "inc eax"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall CannotExitState__6LivingFUc(struct Living* this, const void* edx, unsigned char param_1)
{
    bool32_t result;
    asm volatile (
        "mov                eax, dword ptr [ecx]\n\t"
        "push               ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x08]\n\t"
        "mov.s              edx, ebx\n\t"
        "and                edx, 0x000000ff\n\t"
        "push               edx\n\t"
        "call               dword ptr [eax + 0x96c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00768668\n\t"
        "cmp                bl, 0x18\n\t"
        "%{disp8%} je         LAB__addr_0x00768668\n\t"
        "cmp                bl, 0x0a\n\t"
        "%{disp8%} je         LAB__addr_0x00768668\n\t"
        "pop                ebx\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00768668:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall SetupScriptWanderToPos__8VillagerFRC9MapCoordsfUsUs(struct Villager* this, const void* edx, const struct MapCoords* param_1, float param_2, unsigned short param_3, unsigned short param_4)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       ecx, dword ptr [esi + 0x0000010c]\n\t"
        "call               ?Init@JustWholeMapXZ@@QAEXABUMapCoords@@@Z\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x14]\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000118], ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "and                ecx, 0x0000ffff\n\t"
        "%{disp8%} lea        edx, dword ptr [ecx + 0x01]\n\t"
        "and                eax, 0x0000ffff\n\t"
        "cmp.s              edx, eax\n\t"
        "%{disp8%} jle        LAB__addr_0x007686b9\n\t"
        "mov.s              eax, edx\n"
        "LAB__addr_0x007686b9:\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000011c], ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000120], eax\n\t"
        "call               ?SetupNewScriptWander@Villager@@QAEIXZ\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall SetupNewScriptWander__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x18\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000110]\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x0000010c]\n\t"
        "push               edi\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ecx\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "call               _jmp_addr_0x00603070\n\t"
        "push               0x3c\n\t"
        "push               0x00c245e0\n\t"
        "push               0x40c90fdb\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000118]\n\t"
        "push               0x3d\n\t"
        "mov.s              ecx, eax\n\t"
        "push               0x00c245e0\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x20]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], eax\n\t"
        "call               ?GameFloatRand@GRand@@SAMM@Z\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x24]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x20]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x20]\n\t"
        "push               edx\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x34]\n\t"
        "push               ecx\n\t"
        "call               _jmp_addr_0x0074d510\n\t"
        "add                esp, 0x24\n\t"
        "push               0x000000c7\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x18]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "%{disp32%} mov       edi, dword ptr [esi + 0x0000011c]\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000120]\n\t"
        "push               0x41\n\t"
        "sub.s              eax, edi\n\t"
        "push               0x00c245e0\n\t"
        "push               eax\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "add                esp, 0x0c\n\t"
        "add.s              eax, edi\n\t"
        "pop                edi\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], ax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x18"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
int __fastcall ExitNoChangeState__6LivingF15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    int result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "and                edi, 0x000000ff\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x964]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007687be\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x968]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007687be\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x96c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007687be\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007687be:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
uint32_t __fastcall EnterScriptWander__6LivingF15VILLAGER_STATES15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1, enum VILLAGER_STATES param_2)
{
    uint32_t result;
    asm volatile (
        "%{disp8%} mov        edx, dword ptr [esp + 0x08]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "push               edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x08]\n\t"
        "push               edx\n\t"
        "call               dword ptr [eax + 0x940]"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall ScriptWanderAroundPos__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000b0]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00768808\n\t"
        "call               ?Create@DataForScriptRemind@@SAPAV1@XZ\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000b0], eax\n\t"
        "LAB__addr_0x00768808:\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} mov        ax, word ptr [esi + 0x58]\n\t"
        "test               ax, ax\n\t"
        "%{disp8%} lea        ecx, dword ptr [eax + -0x01]\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], cx\n\t"
        "%{disp8%} jg         LAB__addr_0x00768821\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupNewScriptWander@Villager@@QAEIXZ\n\t"
        "LAB__addr_0x00768821:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
int __fastcall ExitScriptWander__6LivingF15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    int result;
    asm volatile (
        "%{disp8%} mov        edx, dword ptr [esp + 0x04]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "push               edx\n\t"
        "call               dword ptr [eax + 0x914]"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
uint32_t __fastcall EnterPlayAnim__6LivingF15VILLAGER_STATES15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1, enum VILLAGER_STATES param_2)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "xor.s              ebp, ebp\n\t"
        "push               ebp\n\t"
        "push               0x009cafc8\n\t"
        "push               0x009c8de8\n\t"
        "mov.s              esi, ecx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "call               ___RTDynamicCast\n\t"
        "mov.s              ebx, eax\n\t"
        "add                esp, 0x14\n\t"
        "cmp.s              ebx, ebp\n\t"
        "%{disp32%} je        LAB__addr_0x0076895d\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x24]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x20]\n\t"
        "and                edi, 0x000000ff\n\t"
        "push               edi\n\t"
        "and                eax, 0x000000ff\n\t"
        "push               eax\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               ?IsStateEntryFunctionSameAs@Villager@@QBEIKK@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x0076895d\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000b0]\n\t"
        "cmp.s              ecx, ebp\n\t"
        "%{disp32%} je        LAB__addr_0x0076895d\n\t"
        "cmp                dword ptr [ecx + 0x44], edi\n\t"
        "%{disp32%} jne       LAB__addr_0x0076895d\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x005ef2a0\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "%{disp32%} lea       ecx, dword ptr [ebx + 0x00000080]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], ebp\n\t"
        "call               ?__ne@MapCoords@@QBE_NABV1@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076890b\n\t"
        "push               ebp\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @AreWeThere__13MobileWallHugFf@12\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076890b\n\t"
        "%{disp32%} mov       edx, dword ptr [esi + 0x000000b0]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x24]\n\t"
        "%{disp8%} mov        dword ptr [edx + 0x24], ebp\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000b0]\n\t"
        "push               ecx\n\t"
        "%{disp32%} lea       edx, dword ptr [esi + 0x00000080]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x44], ebp\n\t"
        "call               @SetupMoveToPos__6LivingFRC9MapCoordsUc@13\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000023\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x0076890b:\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000b0]\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x44], ebp\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000b0]\n\t"
        "%{disp8%} mov        eax, dword ptr [ecx + 0x3c]\n\t"
        "%{disp32%} mov       ecx, dword ptr [data_bytes + 0x517508]\n\t"
        "cmp                eax, dword ptr [ecx]\n\t"
        "%{disp8%} jge        LAB__addr_0x00768931\n\t"
        "cmp.s              eax, ebp\n\t"
        "%{disp8%} jl         LAB__addr_0x00768931\n\t"
        "%{disp8%} mov        edi, dword ptr [ecx + eax * 0x4 + 0x04]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00768934\n"
        "LAB__addr_0x00768931:\n\t"
        "%{disp8%} mov        edi, dword ptr [ecx + 0x04]\n"
        "LAB__addr_0x00768934:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0x184]\n\t"
        "cmp.s              edi, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0076895d\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "mov.s              edx, edi\n\t"
        "call               dword ptr [eax + 0x180]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "xor.s              edx, edx\n\t"
        "call               dword ptr [eax + 0x188]\n"
        "LAB__addr_0x0076895d:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall ScriptPlayAnim__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000120]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jbe        LAB__addr_0x007689af\n\t"
        "dec                eax\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000120], eax\n\t"
        "push               0x1\n\t"
        "%{disp8%} jbe        LAB__addr_0x00768991\n\t"
        "push               0x000000c8\n\t"
        "%{disp8%} jmp        LAB__addr_0x00768993\n\t"
        "LAB__addr_0x00768991:\n\t"
        "push               0x4\n\t"
        "LAB__addr_0x00768993:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PlayAnimThenSetState@Living@@QAEXEK@Z\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000b0]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007689af\n\t"
        "call               ?Create@DataForScriptRemind@@SAPAV1@XZ\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x000000b0], eax\n\t"
        "LAB__addr_0x007689af:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
int __fastcall ExitPlayAnim__6LivingF15VILLAGER_STATES(struct Living* this, const void* edx, enum VILLAGER_STATES param_1)
{
    int result;
    asm volatile (
        "%{disp8%} mov        edx, dword ptr [esp + 0x04]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "push               edx\n\t"
        "call               dword ptr [eax + 0x914]"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall IsScriptAnimationComplete__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetTopState@Living@@QBE?AW4VILLAGER_STATES@@XZ\n\t"
        "cmp                al, 0x17\n\t"
        "%{disp8%} jne        LAB__addr_0x007689e0\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007689e0:\n\t"
        "cmp                al, -0x38\n\t"
        "%{disp8%} jne        LAB__addr_0x007689f3\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x00000120]\n\t"
        "xor.s              eax, eax\n\t"
        "test               ecx, ecx\n\t"
        "sete               al\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007689f3:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall ScriptAnimation__8VillagerFv(struct Villager* this)
{
    return (bool32_t)this->football;
}

bool32_t __fastcall WeakOnGround__8VillagerFv(struct Villager* this)
{
    return 1;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ScriptGoAndMoveAlongPath__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x24\n\t"
        "push               ebx\n\t"
        "mov.s              ebx, ecx\n\t"
        "push               0x0\n\t"
        "call               @AreWeThere__13MobileWallHugFf@12\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00768a67\n\t"
        "%{disp32%} mov       eax, dword ptr [ebx + 0x000000ac]\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x20]\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x1c]\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               _jmp_addr_0x005ee520\n\t"
        "%{disp32%} mov       eax, dword ptr [ebx + 0x000000ac]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x18]\n\t"
        "fstp               dword ptr [esp]\n\t"
        "push               0x4\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, ebx\n\t"
        "call               _jmp_addr_0x005ee100\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24\n\t"
        "ret\n"
        "LAB__addr_0x00768a67:\n\t"
        "push               esi\n\t"
        "%{disp32%} mov       esi, dword ptr [ebx + 0x000000ac]\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x20]\n\t"
        "test               eax, eax\n\t"
        "push               edi\n\t"
        "%{disp8%} je         LAB__addr_0x00768ac8\n\t"
        "%{disp8%} fld        dword ptr [esi + 0x24]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} mov        esi, dword ptr [esi + 0x14]\n\t"
        "%{disp8%} jge        LAB__addr_0x00768a89\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} jmp        LAB__addr_0x00768a9b\n"
        "LAB__addr_0x00768a89:\n\t"
        "%{disp8%} mov        edx, dword ptr [esi + 0x04]\n\t"
        "%{disp32%} mov       ecx, dword ptr [edx + 0x00000208]\n\t"
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x10]\n\t"
        "cmp.s              eax, ecx\n\t"
        "%{disp8%} jl         LAB__addr_0x00768a9b\n\t"
        "mov.s              eax, ecx\n"
        "LAB__addr_0x00768a9b:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x04]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x24]\n\t"
        "push               edx\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x00844280\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x0c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00768b2f\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x04]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00000204]\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x0c]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x08]\n\t"
        "push               edx\n\t"
        "push               eax\n\t"
        "%{disp8%} jmp        LAB__addr_0x00768b24\n"
        "LAB__addr_0x00768ac8:\n\t"
        "%{disp8%} mov        edi, dword ptr [esi + 0x14]\n\t"
        "%{disp8%} mov        edx, dword ptr [edi + 0x04]\n\t"
        "%{disp32%} mov       eax, dword ptr [edx + 0x00000208]\n\t"
        "%{disp8%} fild       dword ptr [eax + 0x10]\n\t"
        "%{disp8%} fsub       dword ptr [esi + 0x24]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jge        LAB__addr_0x00768ae7\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} jmp        LAB__addr_0x00768af9\n"
        "LAB__addr_0x00768ae7:\n\t"
        "%{disp8%} mov        ecx, dword ptr [edi + 0x04]\n\t"
        "%{disp32%} mov       edx, dword ptr [ecx + 0x00000208]\n\t"
        "%{disp8%} mov        ecx, dword ptr [edx + 0x10]\n\t"
        "cmp.s              eax, ecx\n\t"
        "%{disp8%} jl         LAB__addr_0x00768af9\n\t"
        "mov.s              eax, ecx\n"
        "LAB__addr_0x00768af9:\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x24]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [edi + 0x04]\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x00844280\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x0c]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} je         LAB__addr_0x00768b2f\n\t"
        "%{disp8%} mov        eax, dword ptr [edi + 0x04]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x00000204]\n\t"
        "mov                eax, dword ptr [eax]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x0c]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [edi + 0x08]\n\t"
        "push               edx\n\t"
        "push               eax\n"
        "LAB__addr_0x00768b24:\n\t"
        "%{disp32%} mov       ecx, dword ptr [ecx + 0x00000208]\n\t"
        "call               _jmp_addr_0x008439c0\n"
        "LAB__addr_0x00768b2f:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x0c]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3400]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x14]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3400]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "push               0x000000f7\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x1c]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], 0x00000000\n\t"
        "call               ?SetupMoveToPos@Villager@@QAE_NABUMapCoords@@W4VILLAGER_STATES@@@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x24"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

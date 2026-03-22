#include "Villager.h"

const float villager_playtime_float10p0_0x0099a9c0 = 10.0f;
const float villager_playtime_num_days_in_year_0x0099a9c4 = 365.25f;
const float villager_playtime_seconds_in_day_0x0099a9c8 = 86400.0f;

float villager_playtime_seconds_in_year_0x00db9e2c;

__attribute__((no_ret))
void __cdecl globl_ct_0x00763080(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x00762694\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x00762694:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x007630a0"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((prefer_pop_cleanup))
void __cdecl crt_global_destruction_register_0x007630a0(void)
{
    extern int __cdecl atexit(void (*)(void));
    atexit((void (*)(void))0x00407870);
}

extern void __cdecl FUN_007630c0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x007630b0(void)
{
    __attribute__((musttail)) return FUN_007630c0__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_007630c0__8VillagerFv(void)
{
    extern float __opaque_a asm("_villager_playtime_seconds_in_day_0x0099a9c8");
    extern float __opaque_b asm("_villager_playtime_num_days_in_year_0x0099a9c4");
    extern float __opaque_c asm("_villager_playtime_seconds_in_year_0x00db9e2c");
    __opaque_c = __opaque_a * __opaque_b;
}

__attribute__((no_callee_saves, prefer_neg_sbb, no_tail_call))
bool32_t __fastcall IsPlaytime__8VillagerFv(struct Villager* this)
{
    typedef uint32_t (__attribute__((thiscall)) *fn_t)(struct Villager*);
    fn_t fn = ((fn_t*)(*(void**)this))[0x48 / 4];
    return fn(this) != 0;
}

bool32_t __fastcall CheckPlaytimeAvailableToPlayPFootball__8VillagerFv(struct Villager* this)
{
    return 1;
}

bool32_t __fastcall CheckPlaytimeSettingUpPlayPFootball__8VillagerFv(struct Villager* this)
{
    return 1;
}

bool32_t __fastcall MoveToFootballPitchConstruction__8VillagerFv(struct Villager* this)
{
    return 1;
}

__attribute__((no_tail_call))
bool32_t __fastcall FootballWalkToPosition__8VillagerFv(struct Villager* this)
{
    extern int __fastcall MoveTo__14MobileWallHugFv(struct Villager*) asm("?MoveTo@MobileWallHug@@QAEHXZ");
    MoveTo__14MobileWallHugFv(this);
    return 1;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CheckSatisfyPlaytimeDesire__8VillagerFv(struct Villager* this)
{
    return 0;
}

bool32_t __fastcall WaitForKickOff__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetFootball@Villager@@QAEPAVFootball@@XZ\n\t"
        "cmp                dword ptr [eax + 0x00000200], 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0076315d\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x49\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "LAB__addr_0x0076315d:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall FootballMatchPaused__8VillagerFv(struct Villager* this)
{
    void* dummy;
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?GetFootball@Villager@@QAEPAVFootball@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007631a6\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFootball@Villager@@QAEPAVFootball@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetBall@Football@@QAEPAXXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007631a6\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFootball@Villager@@QAEPAVFootball@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetBall@Football@@QAEPAXXZ\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?LookAtObject@Living@@QAEIPAVGameThingWithPos@@K@Z\n\t"
        "LAB__addr_0x007631a6:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall FootballMexicanWave__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007631c8\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8c8]\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007631c8:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFootball@Villager@@QAEPAVFootball@@XZ\n\t"
        "push               0x2\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?LookAtObject@Living@@QAEIPAVGameThingWithPos@@K@Z\n\t"
        "push               0x1\n\t"
        "push               0x53\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?PlayAnimThenSetState@Living@@QAEXEK@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall FootballWatchMatch__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076320a\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8c8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0076320a:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFootball@Villager@@QAEPAVFootball@@XZ\n\t"
        "mov.s              edi, eax\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?GetBall@Football@@QAEPAXXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x0076322b\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8c8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0076322b:\n\t"
        "%{disp32%} mov       ecx, dword ptr [edi + 0x00000200]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x00763242\n\t"
        "push               0x1\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?LookAtObject@Living@@QAEIPAVGameThingWithPos@@K@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00763242:\n\t"
        "cmp                ecx, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00763253\n\t"
        "push               ecx\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?LookAtObject@Living@@QAEIPAVGameThingWithPos@@K@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00763253:\n\t"
        "cmp                ecx, 0x04\n\t"
        "%{disp8%} jne        LAB__addr_0x00763277\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        ".byte              0x66, 0x81, 0xa6, 0xe0, 0x0, 0x0, 0x0, 0x7f, 0xff\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8c8]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00763277\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GoHome@Villager@@QAEIXZ\n"
        "LAB__addr_0x00763277:\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall ExitFootball__8VillagerFUc(struct Villager* this, const void* edx, unsigned char param_1)
{
    bool32_t result;
    asm volatile (
        "push               ebx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               esi\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x70]\n\t"
        "call               _jmp_addr_0x0060a9f0\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x0c]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, ebx\n\t"
        "and                ecx, 0x000000ff\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x96c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007632f7\n\t"
        "cmp                bl, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007632f7\n\t"
        "cmp                bl, 0x02\n\t"
        "%{disp8%} je         LAB__addr_0x007632f7\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetFootball@Villager@@QAEPAVFootball@@XZ\n\t"
        "mov.s              edi, eax\n\t"
        "cmp                dword ptr [edi + 0x00000254], esi\n\t"
        "%{disp8%} jne        LAB__addr_0x007632ce\n\t"
        "%{disp32%} mov       dword ptr [edi + 0x00000254], 0x00000000\n"
        "LAB__addr_0x007632ce:\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x005325d0\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007632e3\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x005326e0\n"
        "LAB__addr_0x007632e3:\n\t"
        ".byte              0x66, 0x81, 0xa6, 0xe0, 0x0, 0x0, 0x0, 0x7f, 0xff\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007632f7:\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}


#include "Villager.h"
#include "Town.h"
#include <float.h>

const float villager_reaction_to_creature_float_max_0x0099a9e0 = FLT_MAX;
const float villager_reaction_to_creature_float10p0_0x0099a9e4 = 10.0f;
const float villager_reaction_to_creature_num_days_in_year_0x0099a9e8 = 365.25f;
const float villager_reaction_to_creature_seconds_in_day_0x0099a9ec = 86400.0f;
const float villager_reaction_to_creature_float0p7_0x0099a9f0 = 0.7f;
const float villager_reaction_to_creature_float0p5_0x0099a9f4 = 0.5f;

__attribute__((aligned(4))) char s_VillagerReactionToCreature_cpp[] = "C:\\dev\\MP\\Black\\VillagerReactionToCreature.cpp";

uint32_t villager_reaction_to_creature_uint_0x00db9e38;
uint32_t villager_reaction_to_creature_uint_0x00db9e3c;
float villager_reaction_to_creature_seconds_in_year_0x00db9e40;

__attribute__((no_ret))
void __cdecl globl_ct_0x007675b0(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x007675c4\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x007675c4:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x007675d0"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

void __cdecl crt_global_destruction_register_0x007675d0(void)
{
    asm volatile (
        "push               0x00407870\n\t"
        "call               _atexit\n\t"
        "pop                ecx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

extern void __cdecl FUN_007675f0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x007675e0(void)
{
    __attribute__((musttail)) return FUN_007675f0__8VillagerFv();
}

void __cdecl FUN_007675f0__8VillagerFv(void)
{
    asm volatile (
        "%{disp32%} fld  dword ptr [_villager_reaction_to_creature_seconds_in_day_0x0099a9ec]\n\t"
        "%{disp32%} fmul dword ptr [_villager_reaction_to_creature_num_days_in_year_0x0099a9e8]\n\t"
        "%{disp32%} fstp dword ptr [_villager_reaction_to_creature_seconds_in_year_0x00db9e40]"
        ::: "memory"
    );
}

extern void __cdecl FUN_00767620__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x00767610(void)
{
    __attribute__((musttail)) return FUN_00767620__8VillagerFv();
}

void __cdecl FUN_00767620__8VillagerFv(void)
{
    (void)villager_reaction_to_creature_uint_0x00db9e38;
    villager_reaction_to_creature_uint_0x00db9e3c = 0xffffffff;
}

__attribute__((no_callee_saves, trailing_asm(".byte 0xa6, 0x76, 0x76, 0x00\n.byte 0xba, 0x76, 0x76, 0x00\n.byte 0xa6, 0x76, 0x76, 0x00\n.byte 0x8c, 0x76, 0x76, 0x00\n.byte 0xa6, 0x76, 0x76, 0x00\n.byte 0x90, 0x90, 0x90, 0x90\n.byte 0x90, 0x90, 0x90, 0x90\n.byte 0x90, 0x90, 0x90, 0x90")))
void __fastcall SetupReactToCreature__8VillagerFP16GameThingWithPosP8Reaction(struct Living* this, const void* edx, struct GameThingWithPos* param_1, struct Reaction* param_2)
{
    asm("{disp8} mov        eax, dword ptr [esp + 0x04]");                   // 0x00767630    8b442404
    asm("push               ebx");                                           // 0x00767634    53
    asm("push               esi");                                           // 0x00767635    56
    asm("push               edi");                                           // 0x00767636    57
    asm("push               0x0");                                           // 0x00767637    6a00
    asm("push               0x009c8060");                                    // 0x00767639    6860809c00
    asm("push               0x009c7f30");                                    // 0x0076763e    68307f9c00
    asm("push               0x0");                                           // 0x00767643    6a00
    asm("push               eax");                                           // 0x00767645    50
    asm("mov.s              esi, ecx");                                      // 0x00767646    8bf1
    asm("call               ___RTDynamicCast");                              // 0x00767648    e8cce30500
    asm("mov.s              edi, eax");                                      // 0x0076764d    8bf8
    asm("mov                edx, dword ptr [edi]");                          // 0x0076764f    8b17
    asm("add                esp, 0x14");                                     // 0x00767651    83c414
    asm("mov.s              ecx, edi");                                      // 0x00767654    8bcf
    asm("call               dword ptr [edx + 0x2c]");                        // 0x00767656    ff522c
    asm("test               eax, eax");                                      // 0x00767659    85c0
    asm("{disp8} je         LAB__addr_0x007676ba");                          // 0x0076765b    745d
    asm("{disp32} mov       dword ptr [esi + 0x000000bc], edi");             // 0x0076765d    89bebc000000
    asm("mov                eax, dword ptr [esi]");                          // 0x00767663    8b06
    asm("mov.s              ecx, esi");                                      // 0x00767665    8bce
    asm("call               dword ptr [eax + 0x48]");                        // 0x00767667    ff5048
    asm("mov.s              ebx, eax");                                      // 0x0076766a    8bd8
    asm("test               ebx, ebx");                                      // 0x0076766c    85db
    asm("{disp8} je         LAB__addr_0x007676a6");                          // 0x0076766e    7436
    asm("push               edi");                                           // 0x00767670    57
    asm("mov.s              ecx, ebx");                                      // 0x00767671    8bcb
    asm("call               _jmp_addr_0x00743720");                          // 0x00767673    e8a8c0fdff
    asm("push               edi");                                           // 0x00767678    57
    asm("mov.s              ecx, ebx");                                      // 0x00767679    8bcb
    asm("call               _jmp_addr_0x007436f0");                          // 0x0076767b    e870c0fdff
    asm("cmp                eax, 0x04");                                     // 0x00767680    83f804
    asm("{disp8} ja         LAB__addr_0x007676ba");                          // 0x00767683    7735
    asm("jmp                dword ptr [eax*4 + 0x7676c0]");                  // 0x00767685    ff2485c0767600
    asm("{disp8} mov        eax, dword ptr [esp + 0x14]");                   // 0x0076768c    8b442414
    asm("mov                edx, dword ptr [esi]");                          // 0x00767690    8b16
    asm("push               0x0000009f");                                    // 0x00767692    689f000000
    asm("push               eax");                                           // 0x00767697    50
    asm("mov.s              ecx, esi");                                      // 0x00767698    8bce
    asm("call               dword ptr [edx + 0x990]");                       // 0x0076769a    ff9290090000
    asm("pop                edi");                                           // 0x007676a0    5f
    asm("pop                esi");                                           // 0x007676a1    5e
    asm("pop                ebx");                                           // 0x007676a2    5b
    asm("ret                0x0008");                                        // 0x007676a3    c20800
    asm("LAB__addr_0x007676a6:");
    asm("{disp8} mov        eax, dword ptr [esp + 0x14]");                   // 0x007676a6    8b442414
    asm("mov                edx, dword ptr [esi]");                          // 0x007676aa    8b16
    asm("push               0x00000092");                                    // 0x007676ac    6892000000
    asm("push               eax");                                           // 0x007676b1    50
    asm("mov.s              ecx, esi");                                      // 0x007676b2    8bce
    asm("call               dword ptr [edx + 0x990]");                       // 0x007676b4    ff9290090000
    asm("LAB__addr_0x007676ba:");
    asm("pop                edi");                                           // 0x007676ba    5f
    asm("pop                esi");                                           // 0x007676bb    5e
    asm("pop                ebx");                                           // 0x007676bc    5b
    // Snippet: jmptbl, [0x007676c0, 0x007676d4)
    // Snippet: db, [0x007676d4, 0x007676e0)
}

__attribute__((no_callee_saves, XOR32rr_REV, trailing_asm(".byte 0x8e, 0x77, 0x76, 0x00\n.byte 0x7d, 0x78, 0x76, 0x00\n.byte 0xb8, 0x77, 0x76, 0x00\n.byte 0xc6, 0x77, 0x76, 0x00\n.byte 0xec, 0x77, 0x76, 0x00\n.byte 0x90, 0x90, 0x90, 0x90")))
uint8_t __fastcall ReactToCreaturePriority__8VillagerFP8ReactionP8Reaction(struct Living* this, const void* edx, struct Reaction* param_1, struct Reaction* param_2)
{
    asm("sub                esp, 0x08");                                // 0x007676e0    83ec08
    asm("push               ebx");                                      // 0x007676e3    53
    asm("push               esi");                                      // 0x007676e4    56
    asm("push               edi");                                      // 0x007676e5    57
    asm("mov.s              edi, ecx");                                 // 0x007676e6    8bf9
    asm("mov                eax, dword ptr [edi]");                     // 0x007676e8    8b07
    asm("call               dword ptr [eax + 0x978]");                  // 0x007676ea    ff9078090000
    asm("test               eax, eax");                                 // 0x007676f0    85c0
    asm("{disp32} jne       LAB__addr_0x0076787d");                     // 0x007676f2    0f8585010000
    asm("{disp8} mov        ebx, dword ptr [esp + 0x18]");              // 0x007676f8    8b5c2418
    asm("{disp8} mov        eax, dword ptr [ebx + 0x14]");              // 0x007676fc    8b4314
    asm("push               0x0");                                      // 0x007676ff    6a00
    asm("push               0x009c8060");                               // 0x00767701    6860809c00
    asm("push               0x009c7f30");                               // 0x00767706    68307f9c00
    asm("push               0x0");                                      // 0x0076770b    6a00
    asm("push               eax");                                      // 0x0076770d    50
    asm("call               ___RTDynamicCast");                         // 0x0076770e    e806e30500
    asm("mov.s              esi, eax");                                 // 0x00767713    8bf0
    asm("add                esp, 0x14");                                // 0x00767715    83c414
    asm("test               esi, esi");                                 // 0x00767718    85f6
    asm("{disp32} je        LAB__addr_0x0076787d");                     // 0x0076771a    0f845d010000
    asm("{disp32} mov       eax, dword ptr [esi + 0x000012c0]");        // 0x00767720    8b86c0120000
    asm("test               eax, eax");                                 // 0x00767726    85c0
    asm("{disp32} jne       LAB__addr_0x0076787d");                     // 0x00767728    0f854f010000
    asm("{disp32} mov       eax, dword ptr [esi + 0x0000106c]");        // 0x0076772e    8b866c100000
    asm("test               eax, eax");                                 // 0x00767734    85c0
    asm("{disp32} jne       LAB__addr_0x0076787d");                     // 0x00767736    0f8541010000
    asm("{disp8} lea        ecx, dword ptr [esi + 0x14]");              // 0x0076773c    8d4e14
    asm("push               ecx");                                      // 0x0076773f    51
    asm("{disp8} lea        edx, dword ptr [edi + 0x14]");              // 0x00767740    8d5714
    asm("push               edx");                                      // 0x00767743    52
    asm("call               _jmp_addr_0x0074cd50");                     // 0x00767744    e80756feff
    asm("{disp8} fstp       dword ptr [esp + 0x20]");                   // 0x00767749    d95c2420
    asm("add                esp, 0x08");                                // 0x0076774d    83c408
    asm("mov.s              ecx, ebx");                                 // 0x00767750    8bcb
    asm("call               ?GetInfo@Reaction@@QBEPAVReactionInfo@@XZ");// 0x00767752    e8a9cff7ff
    asm("{disp8} fld        dword ptr [esp + 0x18]");                   // 0x00767757    d9442418
    asm("{disp8} fcomp      dword ptr [eax + 0x44]");                   // 0x0076775b    d85844
    asm("fnstsw             ax");                                       // 0x0076775e    dfe0
    asm("test               ah, 0x41");                                 // 0x00767760    f6c441
    asm("{disp32} je        LAB__addr_0x0076787d");                     // 0x00767763    0f8414010000
    asm("mov                eax, dword ptr [edi]");                     // 0x00767769    8b07
    asm("mov.s              ecx, edi");                                 // 0x0076776b    8bcf
    asm("call               dword ptr [eax + 0x48]");                   // 0x0076776d    ff5048
    asm("mov.s              ebx, eax");                                 // 0x00767770    8bd8
    asm("test               ebx, ebx");                                 // 0x00767772    85db
    asm("{disp8} je         LAB__addr_0x007677b8");                     // 0x00767774    7442
    asm("push               esi");                                      // 0x00767776    56
    asm("mov.s              ecx, ebx");                                 // 0x00767777    8bcb
    asm("call               _jmp_addr_0x007436f0");                     // 0x00767779    e872bffdff
    asm("cmp                eax, 0x04");                                // 0x0076777e    83f804
    asm("{disp32} ja        LAB__addr_0x0076787d");                     // 0x00767781    0f87f6000000
    asm("jmp                dword ptr [eax*4 + 0x767888]");             // 0x00767787    ff248588787600
    asm("{disp32} mov       ecx, dword ptr [data_bytes + 0x389918]");   // 0x0076778e    8b0d18f9d400
    asm("{disp8} mov        dword ptr [esp + 0x0c], ecx");              // 0x00767794    894c240c
    asm("{disp8} mov        dword ptr [esp + 0x10], 0x00000000");       // 0x00767798    c744241000000000
    asm("{disp8} fild       qword ptr [esp + 0x0c]");                   // 0x007677a0    df6c240c
    asm("{disp32} fmul      dword ptr [__real@3fc00000]");              // 0x007677a4    d80d4cb28a00
    asm("call               _jmp_addr_0x007a1400");                     // 0x007677aa    e8519c0300
    asm("pop                edi");                                      // 0x007677af    5f
    asm("pop                esi");                                      // 0x007677b0    5e
    asm("pop                ebx");                                      // 0x007677b1    5b
    asm("add                esp, 0x08");                                // 0x007677b2    83c408
    asm("ret                0x0008");                                   // 0x007677b5    c20800
    asm("LAB__addr_0x007677b8:");
    asm("{disp32} mov       al, byte ptr [data_bytes + 0x389918]");     // 0x007677b8    a018f9d400
    asm("pop                edi");                                      // 0x007677bd    5f
    asm("pop                esi");                                      // 0x007677be    5e
    asm("pop                ebx");                                      // 0x007677bf    5b
    asm("add                esp, 0x08");                                // 0x007677c0    83c408
    asm("ret                0x0008");                                   // 0x007677c3    c20800
    asm("{disp32} mov       edx, dword ptr [data_bytes + 0x3896c0]");   // 0x007677c6    8b15c0f6d400
    asm("{disp8} mov        dword ptr [esp + 0x0c], edx");              // 0x007677cc    8954240c
    asm("{disp8} mov        dword ptr [esp + 0x10], 0x00000000");       // 0x007677d0    c744241000000000
    asm("{disp8} fild       qword ptr [esp + 0x0c]");                   // 0x007677d8    df6c240c
    asm("fadd.s             st(0), st(0)");                             // 0x007677dc    dcc0
    asm("call               _jmp_addr_0x007a1400");                     // 0x007677de    e81d9c0300
    asm("pop                edi");                                      // 0x007677e3    5f
    asm("pop                esi");                                      // 0x007677e4    5e
    asm("pop                ebx");                                      // 0x007677e5    5b
    asm("add                esp, 0x08");                                // 0x007677e6    83c408
    asm("ret                0x0008");                                   // 0x007677e9    c20800
    asm("mov                eax, dword ptr [ebx]");                     // 0x007677ec    8b03
    asm("mov.s              ecx, ebx");                                 // 0x007677ee    8bcb
    asm("call               dword ptr [eax + 0x1c]");                   // 0x007677f0    ff501c
    asm("mov.s              edx, eax");                                 // 0x007677f3    8bd0
    asm("mov                eax, dword ptr [esi]");                     // 0x007677f5    8b06
    asm("mov.s              ecx, esi");                                 // 0x007677f7    8bce
    asm("{disp8} mov        dword ptr [esp + 0x18], edx");              // 0x007677f9    89542418
    asm("call               dword ptr [eax + 0x1c]");                   // 0x007677fd    ff501c
    asm("{disp8} mov        ecx, dword ptr [esp + 0x18]");              // 0x00767800    8b4c2418
    asm("cmp.s              ecx, eax");                                 // 0x00767804    3bc8
    asm("{disp8} jne        LAB__addr_0x0076786f");                     // 0x00767806    7567
    asm("xor.s              edx, edx");                                 // 0x00767808    33d2
    asm("{disp32} mov       dx, word ptr [edi + 0x000000e0]");          // 0x0076780a    668b97e0000000
    asm("shr                edx, 9");                                   // 0x00767811    c1ea09
    asm("test               dl, 0x01");                                 // 0x00767814    f6c201
    asm("{disp8} jne        LAB__addr_0x0076787d");                     // 0x00767817    7564
    asm("mov                eax, dword ptr [edi]");                     // 0x00767819    8b07
    asm("mov.s              ecx, edi");                                 // 0x0076781b    8bcf
    asm("call               dword ptr [eax + 0xb04]");                  // 0x0076781d    ff90040b0000
    asm("and                eax, 0x000000ff");                          // 0x00767823    25ff000000
    asm("mov.s              ecx, eax");                                 // 0x00767828    8bc8
    asm("lea                eax, dword ptr [ecx + ecx * 0x2]");         // 0x0076782a    8d0449
    asm("shl                eax, 3");                                   // 0x0076782d    c1e003
    asm("sub.s              eax, ecx");                                 // 0x00767830    2bc1
    asm("lea                eax, dword ptr [eax + eax * 0x2]");         // 0x00767832    8d0440
    asm("shl                eax, 2");                                   // 0x00767835    c1e002
    asm("{disp32} mov       ecx, dword ptr [eax + 0x00db9e7c]");        // 0x00767838    8b887c9edb00
    asm("test               ecx, ecx");                                 // 0x0076783e    85c9
    asm("{disp8} jl         LAB__addr_0x0076786f");                     // 0x00767840    7c2d
    asm("cmp                ecx, 0x11");                                // 0x00767842    83f911
    asm("{disp8} jge        LAB__addr_0x0076786f");                     // 0x00767845    7d28
    asm("{disp32} fld       dword ptr [ebx + ecx * 0x4 + 0x0000019c]"); // 0x00767847    d9848b9c010000
    asm("{disp32} fadd      dword ptr [ebx + ecx * 0x4 + 0x00000108]"); // 0x0076784e    d8848b08010000
    asm("{disp32} fadd      dword ptr [ebx + ecx * 0x4 + 0x000000c4]"); // 0x00767855    d8848bc4000000
    asm("{disp32} fmul      dword ptr [eax + 0x00db9e80]");             // 0x0076785c    d888809edb00
    asm("{disp32} fcomp     dword ptr [_rdata_float0p0]");              // 0x00767862    d81d98a38a00
    asm("fnstsw             ax");                                       // 0x00767868    dfe0
    asm("test               ah, 0x41");                                 // 0x0076786a    f6c441
    asm("{disp8} je         LAB__addr_0x0076787d");                     // 0x0076786d    740e
    asm("LAB__addr_0x0076786f:");
    asm("{disp32} mov       al, byte ptr [data_bytes + 0x389788]");     // 0x0076786f    a088f7d400
    asm("pop                edi");                                      // 0x00767874    5f
    asm("pop                esi");                                      // 0x00767875    5e
    asm("pop                ebx");                                      // 0x00767876    5b
    asm("add                esp, 0x08");                                // 0x00767877    83c408
    asm("ret                0x0008");                                   // 0x0076787a    c20800
    asm("LAB__addr_0x0076787d:");
    asm("pop                edi");                                      // 0x0076787d    5f
    asm("pop                esi");                                      // 0x0076787e    5e
    asm("xor.s              al, al");                                   // 0x0076787f    32c0
    asm("pop                ebx");                                      // 0x00767881    5b
    asm("add                esp, 0x08");                                // 0x00767882    83c408
    // Snippet: jmptbl, [0x00767888, 0x0076789c)
    // Snippet: db, [0x0076789c, 0x007678a0)
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall InspectCreatureReaction__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x0076795a\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0076795a\n\t"
        "push               ebx\n\t"
        "push               edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000010c], 0x41a00000\n\t"
        "%{disp32%} mov       edi, dword ptr [data_bytes + 0x33ba38]\n\t"
        "xor.s              edx, edx\n\t"
        "mov                eax, 0x000003e8\n\t"
        "div                edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x0c], eax\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x0c]\n\t"
        "%{disp32%} fmul      dword ptr [__real@3fc00000]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "mov.s              ebx, eax\n\t"
        "xor.s              edx, edx\n\t"
        "mov                eax, 0x000003e8\n\t"
        "div                edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], 0x00000000\n\t"
        "push               0x000000a0\n\t"
        "push               0x00c245b0\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], eax\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x14]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x19c50]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "push               eax\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "add                esp, 0x0c\n\t"
        "add.s              eax, ebx\n\t"
        "push               0x00000093\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000110], eax\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?UpdateAttitudeToCreature@Villager@@QAEXXZ\n\t"
        "pop                edi\n\t"
        "pop                ebx\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x0076795a:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x99c]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x08"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall PerformInspectCreatureReaction__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x007679ac\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007679ac\n\t"
        "%{disp32%} fld       dword ptr [esi + 0x0000010c]\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000110]\n\t"
        "dec                eax\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float1p0]\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000110], eax\n\t"
        "mov.s              ecx, eax\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007679bd\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x007679ee\n"
        "LAB__addr_0x007679ac:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x99c]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007679bd:\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} jne        LAB__addr_0x007679de\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x00000094\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?UpdateAttitudeToCreature@Villager@@QAEXXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007679de:\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "push               0x1\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?LookAtObject@Living@@QAEIPAVGameThingWithPos@@K@Z\n"
        "LAB__addr_0x007679ee:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?UpdateAttitudeToCreature@Villager@@QAEXXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ApproachCreatureReaction__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x14\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "xor.s              ebp, ebp\n\t"
        "cmp.s              ecx, ebp\n\t"
        "%{disp32%} je        LAB__addr_0x00767b83\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00767b83\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000bc]\n\t"
        "push               ebx\n\t"
        "push               edi\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        edi, dword ptr [esi + 0x14]\n\t"
        "push               edi\n\t"
        "call               _jmp_addr_0x0074cd50\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x18]\n\t"
        "%{disp32%} fsub      dword ptr [esi + 0x0000010c]\n\t"
        "add                esp, 0x08\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp32%} jne       LAB__addr_0x00767aeb\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000bc]\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "push               edi\n\t"
        "call               ?GetAngleFromXZ@GUtils@@SAGABUMapCoords@@0@Z\n\t"
        "%{disp32%} fld       dword ptr [esi + 0x0000010c]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "add                esp, 0x04\n\t"
        "fsub               st, st(1)\n\t"
        "mov.s              ebx, eax\n\t"
        "fstp               dword ptr [esp]\n\t"
        "fstp               st(0)\n\t"
        "call               _jmp_addr_0x0074e1d0\n\t"
        "push               eax\n\t"
        "push               ebx\n\t"
        "call               _jmp_addr_0x0074d3e0\n\t"
        "%{disp32%} fld       dword ptr [esi + 0x0000010c]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x1c]\n\t"
        "add                esp, 0x08\n\t"
        "fsub               st, st(1)\n\t"
        "mov.s              ebp, eax\n\t"
        "fstp               dword ptr [esp]\n\t"
        "fstp               st(0)\n\t"
        "call               _jmp_addr_0x0074e200\n\t"
        "push               eax\n\t"
        "push               ebx\n\t"
        "call               _jmp_addr_0x0074d400\n\t"
        "mov                ecx, dword ptr [edi]\n\t"
        "%{disp8%} mov        edx, dword ptr [edi + 0x04]\n\t"
        "%{disp8%} mov        edi, dword ptr [edi + 0x08]\n\t"
        "add.s              ecx, ebp\n\t"
        "add                esp, 0x0c\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], ecx\n\t"
        "push               0x00000094\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x1c]\n\t"
        "add.s              edx, eax\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], edx\n\t"
        "call               ?SetupMoveToCreatureReaction@Villager@@QAEXABUMapCoords@@E@Z\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?UpdateAttitudeToCreature@Villager@@QAEXXZ\n\t"
        "pop                edi\n\t"
        "pop                ebx\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebp\n\t"
        "add                esp, 0x14\n\t"
        "ret\n"
        "LAB__addr_0x00767aeb:\n\t"
        "%{disp32%} mov       edi, dword ptr [data_bytes + 0x33ba38]\n\t"
        "xor.s              edx, edx\n\t"
        "mov                eax, 0x000003e8\n\t"
        "div                edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ebp\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x10]\n\t"
        "%{disp32%} fmul      dword ptr [__real@3fc00000]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "mov.s              ebx, eax\n\t"
        "xor.s              edx, edx\n\t"
        "mov                eax, 0x000003e8\n\t"
        "div                edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ebp\n\t"
        "push               0x000000e7\n\t"
        "push               0x00c245b0\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x18]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x23750]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "push               eax\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "%{disp32%} fld       dword ptr [esi + 0x0000010c]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "%{disp32%} fsub      dword ptr [rdata_bytes + 0x19c70]\n\t"
        "add                esp, 0x0c\n\t"
        "add.s              eax, ebx\n\t"
        "push               0x00000093\n\t"
        "%{disp32%} fstp      dword ptr [esi + 0x0000010c]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000110], eax\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?UpdateAttitudeToCreature@Villager@@QAEXXZ\n\t"
        "pop                edi\n\t"
        "pop                ebx\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebp\n\t"
        "add                esp, 0x14\n\t"
        "ret\n"
        "LAB__addr_0x00767b83:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x99c]\n\t"
        "pop                esi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebp\n\t"
        "add                esp, 0x14"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall InitialiseRespectCreatureReaction__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x24\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x00767c6a\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00767c6a\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000bc]\n\t"
        "push               0x0\n\t"
        "push               0x009c8060\n\t"
        "push               0x009c7f30\n\t"
        "push               0x0\n\t"
        "push               eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], 0x00000000\n\t"
        "call               ___RTDynamicCast\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "add                esp, 0x14\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x20]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x834]\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], ecx\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x10]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3400]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], eax\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3400]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], eax\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "push               0x000000a0\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "call               ?SetupMoveToCreatureReaction@Villager@@QAEXABUMapCoords@@E@Z\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?UpdateAttitudeToCreature@Villager@@QAEXXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x24\n\t"
        "ret\n"
        "LAB__addr_0x00767c6a:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x99c]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x24"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall TurnToFaceCreatureReaction__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00767cce\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00767cce\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000bc]\n\t"
        "push               0x2\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?LookAtObject@Living@@QAEIPAVGameThingWithPos@@K@Z\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00767cc0\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0000009c\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        word ptr [esi + 0x58], 0x0000\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x00767cc0:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?UpdateAttitudeToCreature@Villager@@QAEXXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00767cce:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x99c]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall PerformRespectCreatureReaction__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x08\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x00767d9d\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00767d9d\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000bc]\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "push               ecx\n\t"
        "call               ?GetAngleFromXZ@GUtils@@SAGABUMapCoords@@0@Z\n\t"
        "xor.s              edx, edx\n\t"
        "%{disp8%} mov        dx, word ptr [esi + 0x5c]\n\t"
        "add                esp, 0x08\n\t"
        "sub.s              eax, edx\n\t"
        "cdq\n\t"
        "xor.s              eax, edx\n\t"
        "sub.s              eax, edx\n\t"
        "cmp                eax, 0x00000100\n\t"
        "%{disp8%} jbe        LAB__addr_0x00767d44\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x000000a0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x00767d44:\n\t"
        "%{disp8%} inc        word ptr [esi + 0x58]\n\t"
        "xor.s              edx, edx\n\t"
        "mov                eax, 0x000003e8\n\t"
        "div                dword ptr [data_bytes + 0x33ba38]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], 0x00000000\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        di, word ptr [esi + 0x58]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x08], eax\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x08]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x2418]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "movsx              ecx, di\n\t"
        "cmp.s              ecx, eax\n\t"
        "pop                edi\n\t"
        "%{disp8%} jle        LAB__addr_0x00767d8c\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0000009d\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x00767d8c:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?UpdateAttitudeToCreature@Villager@@QAEXXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x08\n\t"
        "ret\n"
        "LAB__addr_0x00767d9d:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x99c]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x08"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall FinishRespectCreatureReaction__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00767de7\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00767de7\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x99c]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00767de7:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x99c]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall FleeingFromCreatureReaction__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x10\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x00767f4f\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00767f4f\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetReaction@Living@@QAEXXZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?GetInfo@Reaction@@QBEPAVReactionInfo@@XZ\n\t"
        "%{disp8%} fld        dword ptr [eax + 0x2c]\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000bc]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x1dc98]\n\t"
        "add                eax, 0x14\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n\t"
        "push               ecx\n\t"
        "call               _jmp_addr_0x0074cd50\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x0c]\n\t"
        "%{disp32%} fmul      dword ptr [__real@3fc00000]\n\t"
        "add                esp, 0x08\n\t"
        "fcompp\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp32%} jne       LAB__addr_0x00767f4f\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x04]\n\t"
        "%{disp32%} mov       edx, dword ptr [esi + 0x000000bc]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x10]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], 0x00000000\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], 0x00000000\n\t"
        "call               dword ptr [eax + 0xb00]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "call               ?InBounds@MapCoords@@QBEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00767f3e\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0xa4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00767f21\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00000164]\n\t"
        "%{disp32%} mov       eax, dword ptr [eax + 0x00000f58]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00767f21\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x30]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00767f21\n\t"
        "push               0x00000161\n\t"
        "push               0x00c245b0\n\t"
        "push               0xa\n\t"
        "call               ?GameRand@GRand@@SAHJ@Z\n\t"
        "add                esp, 0x0c\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00767f59\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00000108]\n\t"
        "cdq\n\t"
        "sub.s              eax, edx\n\t"
        "push               0x1\n\t"
        "sar                eax, 1\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetSpeed@Villager@@QAEXJH@Z\n\t"
        "push               0x0000009f\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x0c]\n\t"
        "push               edx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetupMoveToCreatureReaction@Villager@@QAEXABUMapCoords@@E@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10\n\t"
        "ret\n"
        "LAB__addr_0x00767f21:\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x28]\n\t"
        "%{disp32%} mov       ecx, dword ptr [eax + 0x00000108]\n\t"
        "push               0x1\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetSpeed@Villager@@QAEXJH@Z\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10\n\t"
        "ret\n"
        "LAB__addr_0x00767f3e:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?UpdateAttitudeToCreature@Villager@@QAEXXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10\n\t"
        "ret\n"
        "LAB__addr_0x00767f4f:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x99c]\n"
        "LAB__addr_0x00767f59:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x10"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall MoveTowardsCreatureReaction__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x000000bc]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00767fcb\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00767fcb\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?MoveTo@MobileWallHug@@QAEHXZ\n\t"
        "cmp                eax, 0x0a\n\t"
        "%{disp8%} jne        LAB__addr_0x00767fbd\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x860]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n\t"
        "push               eax\n\t"
        "call               ?GetDistanceInMetres@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp32%} fcomp     dword ptr [_villager_reaction_to_creature_float0p5_0x0099a9f4]\n\t"
        "add                esp, 0x08\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} je         LAB__addr_0x00767fbd\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SetTopStateToFinal@Living@@QAEXXZ\n"
        "LAB__addr_0x00767fbd:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?UpdateAttitudeToCreature@Villager@@QAEXXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00767fcb:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x99c]\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
struct LivingMapCell* __fastcall __ct__13LivingMapCellFR9JustMapXZ(struct LivingMapCell* this, const void* edx, struct JustMapXZ* param_1)
{
    struct LivingMapCell* result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "mov.s              ebx, ecx\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "xor.s              eax, eax\n\t"
        "mov                ecx, 0x0000000a\n\t"
        "mov.s              edi, ebx\n\t"
        "rep stosd\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x20]\n\t"
        "call               _jmp_addr_0x005e1950\n\t"
        "%{disp8%} mov        esi, dword ptr [eax + 0x04]\n\t"
        "test               esi, esi\n\t"
        "mov                ecx, 0x00000001\n\t"
        "%{disp8%} jne        LAB__addr_0x0076800d\n\t"
        "mov                esi, dword ptr [eax]\n\t"
        "xor.s              ecx, ecx\n"
        "LAB__addr_0x0076800d:\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "mov.s              ebp, eax\n\t"
        "%{disp32%} je        LAB__addr_0x007680c1\n"
        "LAB__addr_0x0076801b:\n\t"
        "%{disp8%} fild       dword ptr [esi + 0x14]\n\t"
        "%{disp32%} fmul      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x341c]\n\t"
        "fld                st(0)\n\t"
        "%{disp32%} fdiv      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "fsubr              st, st(1)\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x1e658]\n\t"
        "%{disp32%} fdiv      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "fstp               st(0)\n\t"
        "%{disp8%} fild       dword ptr [esi + 0x18]\n\t"
        "mov.s              edi, eax\n\t"
        "%{disp32%} fmul      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x341c]\n\t"
        "fld                st(0)\n\t"
        "%{disp32%} fdiv      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "fsubr              st, st(1)\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x1e658]\n\t"
        "%{disp32%} fdiv      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "fstp               st(0)\n\t"
        "mov.s              ecx, eax\n\t"
        "shr                ecx, 3\n\t"
        "mov.s              edx, ebx\n\t"
        "add.s              edx, ecx\n\t"
        "mov.s              ecx, eax\n\t"
        "and                ecx, 0x07\n\t"
        "mov                al, 0x01\n\t"
        "shl                al, cl\n\t"
        "mov                cl, byte ptr [edx + edi * 0x2]\n\t"
        "lea                edx, dword ptr [edx + edi * 0x2]\n\t"
        "push               ebp\n\t"
        "or.s               cl, al\n\t"
        "mov                byte ptr [edx], cl\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x53c]\n\t"
        "mov.s              esi, eax\n\t"
        "test               esi, esi\n\t"
        "%{disp32%} jne       LAB__addr_0x0076801b\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x14]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007680c1\n\t"
        "%{disp8%} mov        esi, dword ptr [ebp + 0x00]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], 0x00000000\n\t"
        "%{disp32%} jne       LAB__addr_0x0076801b\n"
        "LAB__addr_0x007680c1:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov.s              eax, ebx\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall FindFreePosition__13LivingMapCellFR9JustMapXZRC9MapCoordsP9MapCoords(struct LivingMapCell* this, const void* edx, struct JustMapXZ* param_1, const struct MapCoords* param_2, struct MapCoords* param_3)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x2c\n\t"
        "%{disp32%} mov       eax, dword ptr [_villager_reaction_to_creature_float_max_0x0099a9e0]\n\t"
        "push               ebx\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x34]\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x14], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "xor.s              edi, edi\n"
        "LAB__addr_0x007680ea:\n\t"
        "xor.s              esi, esi\n\t"
        "lea                ebp, dword ptr [edi + edi * 0x1]\n"
        "LAB__addr_0x007680ef:\n\t"
        "mov.s              ecx, esi\n\t"
        "and                ecx, 0x07\n\t"
        "mov.s              eax, esi\n\t"
        "shr                eax, 3\n\t"
        "mov                edx, 0x00000001\n\t"
        "shl                edx, cl\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x14]\n\t"
        "add.s              eax, ebp\n\t"
        "mov                al, byte ptr [eax + ecx * 0x1]\n\t"
        "test               al, dl\n\t"
        "%{disp32%} jne       LAB__addr_0x007681d0\n\t"
        "movsx              ecx, word ptr [ebx]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x40], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x24], 0x00000000\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x40]\n\t"
        "%{disp32%} fmul      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x20]\n\t"
        "%{disp32%} fmul      dword ptr [_villager_reaction_to_creature_float0p5_0x0099a9f4]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3408]\n\t"
        "%{disp32%} fdiv      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "movsx              edx, word ptr [ebx + 0x02]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x40], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x2c], 0x00000000\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x40]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x30], eax\n\t"
        "%{disp32%} fmul      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x28]\n\t"
        "%{disp32%} fmul      dword ptr [_villager_reaction_to_creature_float0p5_0x0099a9f4]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3408]\n\t"
        "%{disp32%} fdiv      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x30]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x34], eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x38], 0x00000000\n\t"
        "call               ?CollideCollideWithFixe@MapCoords@@QBEHXZ\n\t"
        "test               al, 0x08\n\t"
        "%{disp8%} jne        LAB__addr_0x007681d0\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x44]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x34]\n\t"
        "push               ecx\n\t"
        "call               ?GetDistanceInMetres@GUtils@@SAMABUMapCoords@@0@Z\n\t"
        "%{disp8%} fcom       dword ptr [esp + 0x18]\n\t"
        "add                esp, 0x08\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x007681ce\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], esi\n\t"
        "%{disp8%} jmp        LAB__addr_0x007681d0\n"
        "LAB__addr_0x007681ce:\n\t"
        "fstp               st(0)\n"
        "LAB__addr_0x007681d0:\n\t"
        "inc                esi\n\t"
        "cmp                esi, 0x14\n\t"
        "%{disp32%} jb        LAB__addr_0x007680ef\n\t"
        "inc                edi\n\t"
        "cmp                edi, 0x14\n\t"
        "%{disp32%} jb        LAB__addr_0x007680ea\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x10]\n\t"
        "%{disp32%} fcomp     dword ptr [_villager_reaction_to_creature_float_max_0x0099a9e0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp32%} je        LAB__addr_0x00768288\n\t"
        "movsx              edx, word ptr [ebx]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x40], edx\n\t"
        "xor.s              edi, edi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], eax\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x40]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x2c], edi\n\t"
        "%{disp32%} fmul      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x28]\n\t"
        "%{disp32%} fmul      dword ptr [_villager_reaction_to_creature_float0p5_0x0099a9f4]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3408]\n\t"
        "%{disp32%} fdiv      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x48]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x1c]\n\t"
        "mov                dword ptr [esi], eax\n\t"
        "movsx              ecx, word ptr [ebx + 0x02]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x40], ecx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x28], edx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x2c], edi\n\t"
        "%{disp8%} fild       dword ptr [esp + 0x40]\n\t"
        "%{disp32%} fmul      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "%{disp8%} fild       qword ptr [esp + 0x28]\n\t"
        "%{disp32%} fmul      dword ptr [_villager_reaction_to_creature_float0p5_0x0099a9f4]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp32%} fmul      dword ptr [rdata_bytes + 0x3408]\n\t"
        "%{disp32%} fdiv      dword ptr [_villager_reaction_to_creature_float10p0_0x0099a9e4]\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "pop                edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x04], eax\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x2c\n\t"
        "ret                0x000c\n"
        "LAB__addr_0x00768288:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "xor.s              eax, eax\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x2c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
void __fastcall CalculateNearestFreeDestination__8VillagerFP9MapCoords(struct Villager* this, const void* edx, struct MapCoords* param_1)
{
    asm volatile (
        "sub                esp, 0x7c\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x1c]\n\t"
        "mov                edx, 0x00000008\n"
        "LAB__addr_0x007682b0:\n\t"
        "mov                word ptr [eax], 0x0000\n\t"
        "%{disp8%} mov        word ptr [eax + 0x02], 0x0000\n\t"
        "add                eax, 0x04\n\t"
        "dec                edx\n\t"
        "%{disp8%} jne        LAB__addr_0x007682b0\n\t"
        "xor.s              esi, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x3c], esi\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x40]\n\t"
        "mov                edx, 0x00000008\n"
        "LAB__addr_0x007682d0:\n\t"
        "mov                word ptr [eax], si\n\t"
        "%{disp8%} mov        word ptr [eax + 0x02], si\n\t"
        "add                eax, 0x04\n\t"
        "dec                edx\n\t"
        "%{disp8%} jne        LAB__addr_0x007682d0\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x60], esi\n\t"
        "%{disp8%} lea        esi, dword ptr [ecx + 0x14]\n\t"
        "push               esi\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], esi\n\t"
        "call               _jmp_addr_0x005e17c0\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        cx, word ptr [esp + 0x18]\n\t"
        "mov.s              eax, esp\n\t"
        "mov                word ptr [eax], cx\n\t"
        "%{disp8%} mov        dx, word ptr [esp + 0x1a]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x20]\n\t"
        "%{disp8%} mov        word ptr [eax + 0x02], dx\n\t"
        "call               @Push__LHStack__JustMapXZFPJustMapXZ@12\n"
        "LAB__addr_0x0076830f:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x3c]\n\t"
        "dec                eax\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x3c], eax\n\t"
        "%{disp8%} mov        cx, word ptr [esp + eax * 0x4 + 0x1c]\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + eax * 0x4 + 0x1c]\n\t"
        "%{disp8%} mov        word ptr [esp + 0x10], cx\n\t"
        "%{disp8%} mov        ax, word ptr [eax + 0x02]\n\t"
        "%{disp8%} mov        word ptr [esp + 0x12], ax\n\t"
        "push               ecx\n\t"
        "mov.s              eax, esp\n\t"
        "mov                word ptr [eax], cx\n\t"
        "%{disp8%} mov        cx, word ptr [esp + 0x16]\n\t"
        "%{disp8%} mov        word ptr [eax + 0x02], cx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x44]\n\t"
        "call               @Push__LHStack__JustMapXZFPJustMapXZ@12\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x10]\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x68]\n\t"
        "call               ??0LivingMapCell@@QAE@AAUJustMapXZ@@@Z\n\t"
        "%{disp32%} mov       eax, dword ptr [esp + 0x00000090]\n\t"
        "push               eax\n\t"
        "push               esi\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x18]\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x70]\n\t"
        "call               ?FindFreePosition@LivingMapCell@@QAEIAAUJustMapXZ@@ABUMapCoords@@PAU3@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x007683db\n\t"
        "%{disp8%} mov        ebp, dword ptr [esp + 0x60]\n\t"
        "mov                esi, 0x00da59fe\n"
        "LAB__addr_0x00768379:\n\t"
        "%{disp8%} mov        ax, word ptr [esi + -0x02]\n\t"
        "%{disp8%} mov        cx, word ptr [esp + 0x12]\n\t"
        "add                ax, word ptr [esp + 0x10]\n\t"
        "add                cx, word ptr [esi]\n\t"
        "xor.s              edi, edi\n\t"
        "test               ebp, ebp\n\t"
        "%{disp8%} jbe        LAB__addr_0x007683b0\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x42]\n\t"
        "mov.s              ebx, ebp\n"
        "LAB__addr_0x00768396:\n\t"
        "cmp                word ptr [edx + -0x02], ax\n\t"
        "%{disp8%} jne        LAB__addr_0x007683a6\n\t"
        "cmp                word ptr [edx], cx\n\t"
        "%{disp8%} jne        LAB__addr_0x007683a6\n\t"
        "mov                edi, 0x00000001\n"
        "LAB__addr_0x007683a6:\n\t"
        "add                edx, 0x04\n\t"
        "dec                ebx\n\t"
        "%{disp8%} jne        LAB__addr_0x00768396\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x007683c7\n"
        "LAB__addr_0x007683b0:\n\t"
        "push               ecx\n\t"
        "mov.s              edx, esp\n\t"
        "%{disp8%} mov        word ptr [edx + 0x02], cx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x20]\n\t"
        "mov                word ptr [edx], ax\n\t"
        "call               @Push__LHStack__JustMapXZFPJustMapXZ@12\n\t"
        "%{disp8%} mov        ebp, dword ptr [esp + 0x60]\n"
        "LAB__addr_0x007683c7:\n\t"
        "add                esi, 0x04\n\t"
        "cmp                esi, 0x00da5a0e\n\t"
        ".byte              0x72, 0xa7\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x18]\n\t"
        "%{disp32%} jmp       LAB__addr_0x0076830f\n"
        "LAB__addr_0x007683db:\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "add                esp, 0x7c"
        :: "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((no_ret))
void __fastcall UpdateAttitudeToCreature__8VillagerFv(struct Villager* this)
{
    asm volatile (
        "%{disp32%} jmp       ?UpdateReactiveStateFromAttitudeToCreature@Villager@@QAEIXZ"
        : : "c"(this) : "eax", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((no_callee_saves))
bool32_t __fastcall UpdateReactiveStateFromAttitudeToCreature__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?CheckNeededForWorship@Villager@@QAEMXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp32%} je        LAB__addr_0x00768500\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x000000bc]\n\t"
        "push               0x0\n\t"
        "push               0x009c8060\n\t"
        "push               0x009c7f30\n\t"
        "push               0x0\n\t"
        "push               eax\n\t"
        "call               ___RTDynamicCast\n\t"
        "mov.s              edi, eax\n\t"
        "add                esp, 0x14\n\t"
        "test               edi, edi\n\t"
        "%{disp32%} je        LAB__addr_0x00768500\n\t"
        "%{disp32%} mov       eax, dword ptr [edi + 0x000010a0]\n\t"
        "test               eax, eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} je         LAB__addr_0x0076848d\n\t"
        "call               dword ptr [eax + 0x99c]\n\t"
        "%{disp32%} mov       ecx, dword ptr [_game]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00205bdc]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} mov       edi, dword ptr [edi + 0x000010a0]\n\t"
        "%{disp32%} je        LAB__addr_0x00768500\n"
        "LAB__addr_0x00768467:\n\t"
        "cmp                dword ptr [eax + 0x14], edi\n\t"
        "%{disp8%} je         LAB__addr_0x00768476\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x40]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00768467\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00768476:\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00768500\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               eax\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x9ec]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0076848d:\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00768500\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x007436f0\n\t"
        "dec                eax\n\t"
        "%{disp8%} je         LAB__addr_0x007684f6\n\t"
        "sub                eax, 0x02\n\t"
        "%{disp8%} je         LAB__addr_0x007684d6\n\t"
        "dec                eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00768500\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "cmp                al, -0x65\n\t"
        ".byte              0x72, 0x8\n\t"
        "cmp                al, -0x63\n\t"
        "%{disp8%} jbe        LAB__addr_0x00768500\n\t"
        "cmp                al, -0x60\n\t"
        "%{disp8%} je         LAB__addr_0x00768500\n"
        "LAB__addr_0x007684c4:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0000009b\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007684d6:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xb04]\n\t"
        "cmp                al, -0x61\n\t"
        "%{disp8%} je         LAB__addr_0x00768500\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0000009f\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x007684f6:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x99c]\n"
        "LAB__addr_0x00768500:\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
void __fastcall SetupMoveToCreatureReaction__8VillagerFRC9MapCoordsUc(struct Villager* this, const void* edx, const struct MapCoords* param_1, unsigned char param_2)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x08]\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "push               eax\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13\n\t"
        "push               0x000000a7\n\t"
        "push               0x0\n\t"
        "%{disp32%} lea       ecx, dword ptr [esi + 0x0000008c]\n\t"
        "call               @SetState__12LivingActionFUlUc@16\n\t"
        "pop                esi"
        :: "c"(this) : "eax", "edx", "memory"
    );
}

uint32_t __fastcall AttitudeToCreatureNone__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 1;
}

uint32_t __fastcall AttitudeToCreatureFear__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 3;
}

uint32_t __fastcall AttitudeToCreatureRespect__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 4;
}

uint32_t __fastcall AttitudeToCreatureEating__16GameThingWithPosFv(struct GameThingWithPos* this)
{
    return 1;
}

uint32_t __fastcall AttitudeToCreatureEating__6LivingFv(struct GameThingWithPos* this)
{
    void* dummy;
    uint32_t result;
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "push 0x0\n\t"
        "call dword ptr [eax + 0x2c8]\n\t"
        "neg eax\n\t"
        ".byte 0x1b, 0xc0\n\t"
        "and eax, 0x02\n\t"
        "inc eax"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
void __fastcall Push__LHStack__JustMapXZFPJustMapXZ(struct LHStack__JustMapXZ* this, const void* edx, struct JustMapXZ* val)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x20]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x04]\n\t"
        "mov                dword ptr [ecx + eax * 0x4], edx\n\t"
        "%{disp8%} inc        dword ptr [ecx + 0x20]"
        ::: "eax", "ecx", "edx", "memory"
    );
}

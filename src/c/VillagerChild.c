#include "Villager.h"

const float rdata_float10p0_0x0099a934 = 10.0f;
const float villager_child_num_days_in_year_0x0099a938 = 365.25f;
const float villager_child_seconds_in_day_0x0099a93c = 86400.0f;

char s_VillagerChild_cpp[] = "C:\\dev\\MP\\Black\\VillagerChild.cpp";

uint32_t villager_child_uint_0x00db9dd0;
float villager_child_seconds_in_year_0x00db9dd4;

__attribute__((no_ret))
void __cdecl globl_ct_0x00757860(void)
{
    asm volatile (
        "%{disp32%} mov cl, byte ptr [_DAT_00fac934]\n\t"
        "mov al, 0x01\n\t"
        "test al, cl\n\t"
        "%{disp8%} jne LAB__addr_0x00757874\n\t"
        "or.s cl, al\n\t"
        "%{disp32%} mov byte ptr [_DAT_00fac934], cl\n"
        "LAB__addr_0x00757874:\n\t"
        "%{disp32%} jmp _crt_global_destruction_register_0x00757880"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((prefer_pop_cleanup))
void __cdecl crt_global_destruction_register_0x00757880(void)
{
    extern int __cdecl atexit(void (*)(void));
    atexit((void (*)(void))0x00407870);
}

extern void __cdecl FUN_007578a0__8VillagerFv(void) __attribute__((noinline));

void __cdecl globl_ct_0x00757890(void)
{
    __attribute__((musttail)) return FUN_007578a0__8VillagerFv();
}

__attribute__((prefer_fmul_mem))
void __cdecl FUN_007578a0__8VillagerFv(void)
{
    extern float __opaque_a asm("_villager_child_seconds_in_day_0x0099a93c");
    extern float __opaque_b asm("_villager_child_num_days_in_year_0x0099a938");
    extern float __opaque_c asm("_villager_child_seconds_in_year_0x00db9dd4");
    __opaque_c = __opaque_a * __opaque_b;
}

__attribute__((no_callee_saves))
bool32_t __fastcall ChildFollowsMother__8VillagerFv(struct Villager* this)
{
    asm("sub                esp, 0x20");                                     // 0x007578c0    83ec20
    asm("push               esi");                                           // 0x007578c3    56
    asm("mov.s              esi, ecx");                                      // 0x007578c4    8bf1
    asm("{disp8} mov        dword ptr [esp + 0x0c], 0x00000000");            // 0x007578c6    c744240c00000000
    asm("{disp8} mov        dword ptr [esp + 0x10], 0x00000000");            // 0x007578ce    c744241000000000
    asm("{disp8} mov        dword ptr [esp + 0x14], 0x00000000");            // 0x007578d6    c744241400000000
    asm("call               ?CheckChild@Villager@@QAEIXZ");                  // 0x007578de    e89d050000
    asm("test               eax, eax");                                      // 0x007578e3    85c0
    asm("{disp32} jne       LAB__addr_0x007579d9");                          // 0x007578e5    0f85ee000000
    asm("mov.s              ecx, esi");                                      // 0x007578eb    8bce
    asm("call               LAB__addr_0x00757c80");                          // 0x007578ed    e88e030000
    asm("cmp                eax, 0x01");                                     // 0x007578f2    83f801
    asm("{disp32} je        LAB__addr_0x007579d9");                          // 0x007578f5    0f84de000000
    asm("mov.s              ecx, esi");                                      // 0x007578fb    8bce
    asm("call               ?ChildGotoCreche@Villager@@QAEIXZ");             // 0x007578fd    e8ee000000
    asm("test               eax, eax");                                      // 0x00757902    85c0
    asm("{disp32} jne       LAB__addr_0x007579d9");                          // 0x00757904    0f85cf000000
    asm("{disp32} mov       ecx, dword ptr [esi + 0x00000100]");             // 0x0075790a    8b8e00010000
    asm("test               ecx, ecx");                                      // 0x00757910    85c9
    asm("{disp8} je         LAB__addr_0x0075793c");                          // 0x00757912    7428
    asm("mov                eax, dword ptr [ecx]");                          // 0x00757914    8b01
    asm("call               dword ptr [eax + 0x2c]");                        // 0x00757916    ff502c
    asm("test               eax, eax");                                      // 0x00757919    85c0
    asm("{disp8} je         LAB__addr_0x0075793c");                          // 0x0075791b    741f
    asm("{disp32} mov       ecx, dword ptr [esi + 0x00000100]");             // 0x0075791d    8b8e00010000
    asm("add                ecx, 0x14");                                     // 0x00757923    83c114
    asm("mov                edx, dword ptr [ecx]");                          // 0x00757926    8b11
    asm("{disp8} mov        dword ptr [esp + 0x0c], edx");                   // 0x00757928    8954240c
    asm("{disp8} mov        eax, dword ptr [ecx + 0x04]");                   // 0x0075792c    8b4104
    asm("{disp8} mov        dword ptr [esp + 0x10], eax");                   // 0x0075792f    89442410
    asm("{disp8} mov        ecx, dword ptr [ecx + 0x08]");                   // 0x00757933    8b4908
    asm("{disp8} mov        dword ptr [esp + 0x14], ecx");                   // 0x00757936    894c2414
    asm("{disp8} jmp        LAB__addr_0x00757969");                          // 0x0075793a    eb2d
    asm("LAB__addr_0x0075793c:");
    asm("mov.s              ecx, esi");                                      // 0x0075793c    8bce
    asm("call               ?GetAbode@Villager@@QAEPAVAbode@@XZ");           // 0x0075793e    e81da8ffff
    asm("test               eax, eax");                                      // 0x00757943    85c0
    asm("mov.s              ecx, esi");                                      // 0x00757945    8bce
    asm("{disp32} je        LAB__addr_0x007579d4");                          // 0x00757947    0f8487000000
    asm("call               ?GetAbode@Villager@@QAEPAVAbode@@XZ");           // 0x0075794d    e80ea8ffff
    asm("add                eax, 0x14");                                     // 0x00757952    83c014
    asm("mov                edx, dword ptr [eax]");                          // 0x00757955    8b10
    asm("{disp8} mov        dword ptr [esp + 0x0c], edx");                   // 0x00757957    8954240c
    asm("{disp8} mov        ecx, dword ptr [eax + 0x04]");                   // 0x0075795b    8b4804
    asm("{disp8} mov        dword ptr [esp + 0x10], ecx");                   // 0x0075795e    894c2410
    asm("{disp8} mov        edx, dword ptr [eax + 0x08]");                   // 0x00757962    8b5008
    asm("{disp8} mov        dword ptr [esp + 0x14], edx");                   // 0x00757965    89542414
    asm("LAB__addr_0x00757969:");
    asm("push               0x39");                                          // 0x00757969    6a39
    asm("push               0x00c236e0");                                    // 0x0075796b    68e036c200
    asm("push               0x40c90fdb");                                    // 0x00757970    68db0fc940
    asm("call               ?GameFloatRand@GRand@@SAMM@Z");                  // 0x00757975    e8b66bf8ff
    asm("{disp8} fstp       dword ptr [esp + 0x14]");                        // 0x0075797a    d95c2414
    asm("{disp32} fld       dword ptr [_rdata_float10p0_0x0099a934]");       // 0x0075797e    d90534a99900
    asm("{disp8} mov        ecx, dword ptr [esp + 0x14]");                   // 0x00757984    8b4c2414
    asm("{disp32} fmul      dword ptr [_rdata_float0p5]");                   // 0x00757988    d80db4a38a00
    asm("{disp8} lea        edx, dword ptr [esp + 0x24]");                   // 0x0075798e    8d542424
    asm("{disp8} fstp       dword ptr [esp + 0x10]");                        // 0x00757992    d95c2410
    asm("{disp8} mov        eax, dword ptr [esp + 0x10]");                   // 0x00757996    8b442410
    asm("push               eax");                                           // 0x0075799a    50
    asm("push               ecx");                                           // 0x0075799b    51
    asm("push               edx");                                           // 0x0075799c    52
    asm("call               ?GetPosFromAngle@GUtils@@SAPAUMapCoords@@MM@Z"); // 0x0075799d    e8de5bffff
    asm("add                esp, 0x18");                                     // 0x007579a2    83c418
    asm("push               eax");                                           // 0x007579a5    50
    asm("{disp8} lea        ecx, dword ptr [esp + 0x10]");                   // 0x007579a6    8d4c2410
    asm("call               @__apl__9MapCoordsFRC9MapCoords@12");            // 0x007579aa    e861daeaff
    asm("{disp8} lea        ecx, dword ptr [esp + 0x0c]");                   // 0x007579af    8d4c240c
    asm("call               _jmp_addr_0x00603840");                          // 0x007579b3    e888beeaff
    asm("test               eax, eax");                                      // 0x007579b8    85c0
    asm("{disp8} je         LAB__addr_0x007579d9");                          // 0x007579ba    741d
    asm("push               0x72");                                          // 0x007579bc    6a72
    asm("{disp8} lea        eax, dword ptr [esp + 0x10]");                   // 0x007579be    8d442410
    asm("push               eax");                                           // 0x007579c2    50
    asm("mov.s              ecx, esi");                                      // 0x007579c3    8bce
    asm("call               @SetupMoveToWithHug__6LivingFRC9MapCoordsUc@13");// 0x007579c5    e8c6aee9ff
    asm("mov                eax, 0x00000001");                               // 0x007579ca    b801000000
    asm("pop                esi");                                           // 0x007579cf    5e
    asm("add                esp, 0x20");                                     // 0x007579d0    83c420
    asm("ret");                                                              // 0x007579d3    c3
    asm("LAB__addr_0x007579d4:");
    asm("call               ?CheckNeedNewAbode@Villager@@QAEIXZ");           // 0x007579d4    e8b7050000
    asm("LAB__addr_0x007579d9:");
    asm("mov                eax, 0x00000001");                               // 0x007579d9    b801000000
    asm("pop                esi");                                           // 0x007579de    5e
    asm("add                esp, 0x20");                                     // 0x007579df    83c420
}

__attribute__((no_callee_saves, XOR32rr_REV))
uint32_t __fastcall ChildGotoCreche__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "sub                esp, 0x0c\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00757a44\n\t"
        "mov                edx, dword ptr [edi]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "%{disp32%} mov       esi, dword ptr [eax + 0x00000744]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x00757a44\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0xd4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00757a44\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x71\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x864]\n\t"
        "push               eax\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               @SetupMoveToOnFootpath__6LivingFR16GameThingWithPosRC9MapCoordsUc@17\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c\n\t"
        "ret\n"
        "LAB__addr_0x00757a44:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "add                esp, 0x0c"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV, trailing_asm("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nLAB__addr_0x00757c80:\n{disp32} jmp       ?CheckNeededForTownDesire@Villager@@QAEIXZ")))
void __cdecl GetNextDstPromemade__FP6CrecheRlP9MapCoordsRC9MapCoords(struct Creche* param_1, long* param_2, struct MapCoords* param_3, const struct MapCoords* param_4)
{
    asm("{disp8} mov        eax, dword ptr [esp + 0x08]");                   // 0x00757a50    8b442408
    asm("mov                eax, dword ptr [eax]");                          // 0x00757a54    8b00
    asm("{disp8} mov        ecx, dword ptr [esp + 0x04]");                   // 0x00757a56    8b4c2404
    asm("{disp8} mov        ecx, dword ptr [ecx + 0x40]");                   // 0x00757a5a    8b4940
    asm("mov                edx, dword ptr [ecx]");                          // 0x00757a5d    8b11
    asm("sub                esp, 0x20");                                     // 0x00757a5f    83ec20
    asm("push               ebx");                                           // 0x00757a62    53
    asm("push               ebp");                                           // 0x00757a63    55
    asm("push               esi");                                           // 0x00757a64    56
    asm("mov.s              esi, eax");                                      // 0x00757a65    8bf0
    asm("sar                eax, 0x10");                                     // 0x00757a67    c1f810
    asm("push               edi");                                           // 0x00757a6a    57
    asm("and                esi, 0x0000ffff");                               // 0x00757a6b    81e6ffff0000
    asm("mov.s              ebx, eax");                                      // 0x00757a71    8bd8
    asm("xor.s              ebp, ebp");                                      // 0x00757a73    33ed
    asm("call               dword ptr [edx + 0xf8]");                        // 0x00757a75    ff92f8000000
    asm("mov.s              edi, eax");                                      // 0x00757a7b    8bf8
    asm("{disp8} mov        eax, dword ptr [edi + 0x04]");                   // 0x00757a7d    8b4704
    asm("test               eax, 0x00100000");                               // 0x00757a80    a900001000
    asm("{disp8} je         LAB__addr_0x00757b02");                          // 0x00757a85    747b
    asm("test               ah, -0x80");                                     // 0x00757a87    f6c480
    asm("{disp8} je         LAB__addr_0x00757a98");                          // 0x00757a8a    740c
    asm("{disp8} mov        ecx, dword ptr [edi + 0x48]");                   // 0x00757a8c    8b4f48
    asm("{disp8} mov        ecx, dword ptr [ecx + 0x08]");                   // 0x00757a8f    8b4908
    asm("{disp8} mov        dword ptr [esp + 0x14], ecx");                   // 0x00757a92    894c2414
    asm("{disp8} jmp        LAB__addr_0x00757aa0");                          // 0x00757a96    eb08
    asm("LAB__addr_0x00757a98:");
    asm("{disp8} mov        dword ptr [esp + 0x14], 0x00000000");            // 0x00757a98    c744241400000000
    asm("LAB__addr_0x00757aa0:");
    asm("test               eax, 0x00040000");                               // 0x00757aa0    a900000400
    asm("{disp8} je         LAB__addr_0x00757abc");                          // 0x00757aa5    7415
    asm("mov.s              ecx, edi");                                      // 0x00757aa7    8bcf
    asm("call               ?GetSizeFootprintData_dup1@LH3DMesh@@QAEIXZ");   // 0x00757aa9    e8e2c0caff
    asm("{disp8} mov        ecx, dword ptr [edi + 0x48]");                   // 0x00757aae    8b4f48
    asm("mov                edx, dword ptr [eax + ecx * 0x1]");              // 0x00757ab1    8b1408
    asm("add.s              eax, ecx");                                      // 0x00757ab4    03c1
    asm("{disp8} mov        dword ptr [esp + 0x10], edx");                   // 0x00757ab6    89542410
    asm("{disp8} jmp        LAB__addr_0x00757ac4");                          // 0x00757aba    eb08
    asm("LAB__addr_0x00757abc:");
    asm("{disp8} mov        dword ptr [esp + 0x10], 0x00000000");            // 0x00757abc    c744241000000000
    asm("LAB__addr_0x00757ac4:");
    asm("test               dword ptr [edi + 0x04], 0x00080000");            // 0x00757ac4    f7470400000800
    asm("{disp8} je         LAB__addr_0x00757ad8");                          // 0x00757acb    740b
    asm("mov.s              ecx, edi");                                      // 0x00757acd    8bcf
    asm("call               ?GetSizeNameData@LH3DMesh@@QAEIXZ");             // 0x00757acf    e89cbccaff
    asm("mov                eax, dword ptr [eax]");                          // 0x00757ad4    8b00
    asm("{disp8} jmp        LAB__addr_0x00757ada");                          // 0x00757ad6    eb02
    asm("LAB__addr_0x00757ad8:");
    asm("xor.s              eax, eax");                                      // 0x00757ad8    33c0
    asm("LAB__addr_0x00757ada:");
    asm("{disp8} mov        edi, dword ptr [edi + 0x48]");                   // 0x00757ada    8b7f48
    asm("{disp8} mov        ecx, dword ptr [esp + 0x10]");                   // 0x00757add    8b4c2410
    asm("add.s              edi, eax");                                      // 0x00757ae1    03f8
    asm("{disp8} mov        eax, dword ptr [esp + 0x14]");                   // 0x00757ae3    8b442414
    asm("add.s              edi, ecx");                                      // 0x00757ae7    03f9
    asm("add.s              edi, eax");                                      // 0x00757ae9    03f8
    asm("{disp8} je         LAB__addr_0x00757b02");                          // 0x00757aeb    7415
    asm("{disp8} mov        edi, dword ptr [edi + 0x04]");                   // 0x00757aed    8b7f04
    asm("mov                eax, 0x66666667");                               // 0x00757af0    b867666666
    asm("imul               edi");                                           // 0x00757af5    f7ef
    asm("sar                edx, 1");                                        // 0x00757af7    d1fa
    asm("mov.s              eax, edx");                                      // 0x00757af9    8bc2
    asm("shr                eax, 0x1f");                                     // 0x00757afb    c1e81f
    asm("add.s              edx, eax");                                      // 0x00757afe    03d0
    asm("mov.s              ebp, edx");                                      // 0x00757b00    8bea
    asm("LAB__addr_0x00757b02:");
    asm("{disp8} mov        edi, dword ptr [esp + 0x34]");                   // 0x00757b02    8b7c2434
    asm("mov                edx, dword ptr [edi]");                          // 0x00757b06    8b17
    asm("{disp8} lea        eax, dword ptr [esp + 0x18]");                   // 0x00757b08    8d442418
    asm("push               eax");                                           // 0x00757b0c    50
    asm("mov.s              ecx, edi");                                      // 0x00757b0d    8bcf
    asm("call               dword ptr [edx + 0x864]");                       // 0x00757b0f    ff9264080000
    asm("{disp8} mov        ecx, dword ptr [esp + 0x40]");                   // 0x00757b15    8b4c2440
    asm("push               eax");                                           // 0x00757b19    50
    asm("call               @__eq__9MapCoordsCFRC9MapCoords@12");            // 0x00757b1a    e841dbeaff
    asm("test               eax, eax");                                      // 0x00757b1f    85c0
    asm("{disp8} je         LAB__addr_0x00757b43");                          // 0x00757b21    7420
    asm("push               0x6b");                                          // 0x00757b23    6a6b
    asm("push               0x00c236e0");                                    // 0x00757b25    68e036c200
    asm("push               ebp");                                           // 0x00757b2a    55
    asm("call               ?GameRand@GRand@@SAHJ@Z");                       // 0x00757b2b    e8e069f8ff
    asm("mov.s              esi, eax");                                      // 0x00757b30    8bf0
    asm("add                esp, 0x0c");                                     // 0x00757b32    83c40c
    asm("test               esi, esi");                                      // 0x00757b35    85f6
    asm("{disp8} jl         LAB__addr_0x00757b3d");                          // 0x00757b37    7c04
    asm("cmp.s              esi, ebp");                                      // 0x00757b39    3bf5
    asm("{disp8} jl         LAB__addr_0x00757b3f");                          // 0x00757b3b    7c02
    asm("LAB__addr_0x00757b3d:");
    asm("xor.s              esi, esi");                                      // 0x00757b3d    33f6
    asm("LAB__addr_0x00757b3f:");
    asm("xor.s              ebx, ebx");                                      // 0x00757b3f    33db
    asm("{disp8} jmp        LAB__addr_0x00757b83");                          // 0x00757b41    eb40
    asm("LAB__addr_0x00757b43:");
    asm("test               esi, esi");                                      // 0x00757b43    85f6
    asm("{disp8} jge        LAB__addr_0x00757b4b");                          // 0x00757b45    7d04
    asm("xor.s              esi, esi");                                      // 0x00757b47    33f6
    asm("{disp8} jmp        LAB__addr_0x00757b52");                          // 0x00757b49    eb07
    asm("LAB__addr_0x00757b4b:");
    asm("cmp.s              esi, ebp");                                      // 0x00757b4b    3bf5
    asm("{disp8} jl         LAB__addr_0x00757b52");                          // 0x00757b4d    7c03
    asm("{disp8} lea        esi, dword ptr [ebp + -0x01]");                  // 0x00757b4f    8d75ff
    asm("LAB__addr_0x00757b52:");
    asm("inc                ebx");                                           // 0x00757b52    43
    asm("{disp8} jns        LAB__addr_0x00757b59");                          // 0x00757b53    7904
    asm("xor.s              ebx, ebx");                                      // 0x00757b55    33db
    asm("{disp8} jmp        LAB__addr_0x00757b83");                          // 0x00757b57    eb2a
    asm("LAB__addr_0x00757b59:");
    asm("cmp                ebx, 0x09");                                     // 0x00757b59    83fb09
    asm("{disp32} jle       LAB__addr_0x00757c2c");                          // 0x00757b5c    0f8eca000000
    asm("push               0x00000081");                                    // 0x00757b62    6881000000
    asm("push               0x00c236e0");                                    // 0x00757b67    68e036c200
    asm("push               ebp");                                           // 0x00757b6c    55
    asm("xor.s              ebx, ebx");                                      // 0x00757b6d    33db
    asm("call               ?GameRand@GRand@@SAHJ@Z");                       // 0x00757b6f    e89c69f8ff
    asm("mov.s              esi, eax");                                      // 0x00757b74    8bf0
    asm("add                esp, 0x0c");                                     // 0x00757b76    83c40c
    asm("test               esi, esi");                                      // 0x00757b79    85f6
    asm("{disp8} jl         LAB__addr_0x00757b81");                          // 0x00757b7b    7c04
    asm("cmp.s              esi, ebp");                                      // 0x00757b7d    3bf5
    asm("{disp8} jl         LAB__addr_0x00757b83");                          // 0x00757b7f    7c02
    asm("LAB__addr_0x00757b81:");
    asm("xor.s              esi, esi");                                      // 0x00757b81    33f6
    asm("LAB__addr_0x00757b83:");
    asm("mov.s              eax, ebx");                                      // 0x00757b83    8bc3
    asm("LAB__addr_0x00757b85:");
    asm("test               ebp, ebp");                                      // 0x00757b85    85ed
    asm("{disp32} je        LAB__addr_0x00757c41");                          // 0x00757b87    0f84b4000000
    asm("{disp8} mov        ecx, dword ptr [edi + 0x40]");                   // 0x00757b8d    8b4f40
    asm("mov                edi, dword ptr [ecx]");                          // 0x00757b90    8b39
    asm("{disp8} lea        edx, dword ptr [esp + 0x18]");                   // 0x00757b92    8d542418
    asm("push               edx");                                           // 0x00757b96    52
    asm("lea                eax, dword ptr [eax + esi * 0x4]");              // 0x00757b97    8d04b0
    asm("mov.s              edx, esi");                                      // 0x00757b9a    8bd6
    asm("add.s              edx, eax");                                      // 0x00757b9c    03d0
    asm("call               dword ptr [edi + 0x1cc]");                       // 0x00757b9e    ff97cc010000
    asm("push               0x00000090");                                    // 0x00757ba4    6890000000
    asm("push               0x00c236e0");                                    // 0x00757ba9    68e036c200
    asm("push               0x3f800000");                                    // 0x00757bae    680000803f
    asm("call               ?GameFloatRand@GRand@@SAMM@Z");                  // 0x00757bb3    e87869f8ff
    asm("{disp32} fsub      dword ptr [_rdata_float0p5]");                   // 0x00757bb8    d825b4a38a00
    asm("push               0x00000090");                                    // 0x00757bbe    6890000000
    asm("push               0x00c236e0");                                    // 0x00757bc3    68e036c200
    asm("push               0x3f800000");                                    // 0x00757bc8    680000803f
    asm("{disp8} fstp       dword ptr [esp + 0x4c]");                        // 0x00757bcd    d95c244c
    asm("call               ?GameFloatRand@GRand@@SAMM@Z");                  // 0x00757bd1    e85a69f8ff
    asm("{disp32} fsub      dword ptr [_rdata_float0p5]");                   // 0x00757bd6    d825b4a38a00
    asm("{disp8} fld        dword ptr [esp + 0x30]");                        // 0x00757bdc    d9442430
    asm("add                esp, 0x18");                                     // 0x00757be0    83c418
    asm("{disp8} lea        ecx, dword ptr [esp + 0x18]");                   // 0x00757be3    8d4c2418
    asm("fadd               st, st(1)");                                     // 0x00757be7    d8c1
    asm("push               ecx");                                           // 0x00757be9    51
    asm("{disp8} lea        ecx, dword ptr [esp + 0x28]");                   // 0x00757bea    8d4c2428
    asm("{disp8} fstp       dword ptr [esp + 0x1c]");                        // 0x00757bee    d95c241c
    asm("fstp               st(0)");                                         // 0x00757bf2    ddd8
    asm("{disp8} fld        dword ptr [esp + 0x24]");                        // 0x00757bf4    d9442424
    asm("{disp8} fadd       dword ptr [esp + 0x38]");                        // 0x00757bf8    d8442438
    asm("{disp8} fstp       dword ptr [esp + 0x24]");                        // 0x00757bfc    d95c2424
    asm("call               @__ct__9MapCoordsFRC7LHPoint@12");               // 0x00757c00    e85bb5eaff
    asm("mov                ecx, dword ptr [eax]");                          // 0x00757c05    8b08
    asm("{disp8} mov        edx, dword ptr [esp + 0x3c]");                   // 0x00757c07    8b54243c
    asm("mov                dword ptr [edx], ecx");                          // 0x00757c0b    890a
    asm("{disp8} mov        ecx, dword ptr [eax + 0x04]");                   // 0x00757c0d    8b4804
    asm("{disp8} mov        dword ptr [edx + 0x04], ecx");                   // 0x00757c10    894a04
    asm("{disp8} mov        eax, dword ptr [eax + 0x08]");                   // 0x00757c13    8b4008
    asm("{disp8} mov        ecx, dword ptr [esp + 0x38]");                   // 0x00757c16    8b4c2438
    asm("shl                ebx, 0x10");                                     // 0x00757c1a    c1e310
    asm("pop                edi");                                           // 0x00757c1d    5f
    asm("or.s               ebx, esi");                                      // 0x00757c1e    0bde
    asm("pop                esi");                                           // 0x00757c20    5e
    asm("{disp8} mov        dword ptr [edx + 0x08], eax");                   // 0x00757c21    894208
    asm("pop                ebp");                                           // 0x00757c24    5d
    asm("mov                dword ptr [ecx], ebx");                          // 0x00757c25    8919
    asm("pop                ebx");                                           // 0x00757c27    5b
    asm("add                esp, 0x20");                                     // 0x00757c28    83c420
    asm("ret");                                                              // 0x00757c2b    c3
    asm("LAB__addr_0x00757c2c:");
    asm("cmp                ebx, 0x04");                                     // 0x00757c2c    83fb04
    asm("{disp32} jle       LAB__addr_0x00757b83");                          // 0x00757c2f    0f8e4effffff
    asm("mov                eax, 0x00000009");                               // 0x00757c35    b809000000
    asm("sub.s              eax, ebx");                                      // 0x00757c3a    2bc3
    asm("{disp32} jmp       LAB__addr_0x00757b85");                          // 0x00757c3c    e944ffffff
    asm("LAB__addr_0x00757c41:");
    asm("mov                edx, dword ptr [edi]");                          // 0x00757c41    8b17
    asm("{disp8} lea        eax, dword ptr [esp + 0x24]");                   // 0x00757c43    8d442424
    asm("push               eax");                                           // 0x00757c47    50
    asm("mov.s              ecx, edi");                                      // 0x00757c48    8bcf
    asm("call               dword ptr [edx + 0x864]");                       // 0x00757c4a    ff9264080000
    asm("mov                edx, dword ptr [eax]");                          // 0x00757c50    8b10
    asm("{disp8} mov        ecx, dword ptr [esp + 0x3c]");                   // 0x00757c52    8b4c243c
    asm("mov                dword ptr [ecx], edx");                          // 0x00757c56    8911
    asm("{disp8} mov        edx, dword ptr [eax + 0x04]");                   // 0x00757c58    8b5004
    asm("{disp8} mov        dword ptr [ecx + 0x04], edx");                   // 0x00757c5b    895104
    asm("{disp8} mov        eax, dword ptr [eax + 0x08]");                   // 0x00757c5e    8b4008
    asm("shl                ebx, 0x10");                                     // 0x00757c61    c1e310
    asm("pop                edi");                                           // 0x00757c64    5f
    asm("or.s               ebx, esi");                                      // 0x00757c65    0bde
    asm("{disp8} mov        dword ptr [ecx + 0x08], eax");                   // 0x00757c67    894108
    asm("{disp8} mov        ecx, dword ptr [esp + 0x34]");                   // 0x00757c6a    8b4c2434
    asm("pop                esi");                                           // 0x00757c6e    5e
    asm("pop                ebp");                                           // 0x00757c6f    5d
    asm("mov                dword ptr [ecx], ebx");                          // 0x00757c70    8919
    asm("pop                ebx");                                           // 0x00757c72    5b
    asm("add                esp, 0x20");                                     // 0x00757c73    83c420
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall ChildAtCreche__8VillagerFv(struct Villager* this)
{
    asm("sub                esp, 0x38");                                     // 0x00757c90    83ec38
    asm("push               ebx");                                           // 0x00757c93    53
    asm("push               esi");                                           // 0x00757c94    56
    asm("xor.s              ebx, ebx");                                      // 0x00757c95    33db
    asm("push               edi");                                           // 0x00757c97    57
    asm("mov.s              esi, ecx");                                      // 0x00757c98    8bf1
    asm("{disp8} mov        dword ptr [esp + 0x0c], ebx");                   // 0x00757c9a    895c240c
    asm("{disp8} mov        dword ptr [esp + 0x10], ebx");                   // 0x00757c9e    895c2410
    asm("{disp8} mov        dword ptr [esp + 0x14], ebx");                   // 0x00757ca2    895c2414
    asm("call               ?CheckChild@Villager@@QAEIXZ");                  // 0x00757ca6    e8d5010000
    asm("cmp                eax, 0x01");                                     // 0x00757cab    83f801
    asm("{disp8} jne        LAB__addr_0x00757cb7");                          // 0x00757cae    7507
    asm("pop                edi");                                           // 0x00757cb0    5f
    asm("pop                esi");                                           // 0x00757cb1    5e
    asm("pop                ebx");                                           // 0x00757cb2    5b
    asm("add                esp, 0x38");                                     // 0x00757cb3    83c438
    asm("ret");                                                              // 0x00757cb6    c3
    asm("LAB__addr_0x00757cb7:");
    asm("mov                eax, dword ptr [esi]");                          // 0x00757cb7    8b06
    asm("mov.s              ecx, esi");                                      // 0x00757cb9    8bce
    asm("call               dword ptr [eax + 0x48]");                        // 0x00757cbb    ff5048
    asm("mov.s              edi, eax");                                      // 0x00757cbe    8bf8
    asm("cmp.s              edi, ebx");                                      // 0x00757cc0    3bfb
    asm("{disp32} je        LAB__addr_0x00757e6d");                          // 0x00757cc2    0f84a5010000
    asm("mov.s              ecx, esi");                                      // 0x00757cc8    8bce
    asm("call               LAB__addr_0x00757c80");                          // 0x00757cca    e8b1ffffff
    asm("cmp                eax, 0x01");                                     // 0x00757ccf    83f801
    asm("{disp8} jne        LAB__addr_0x00757cdb");                          // 0x00757cd2    7507
    asm("pop                edi");                                           // 0x00757cd4    5f
    asm("pop                esi");                                           // 0x00757cd5    5e
    asm("pop                ebx");                                           // 0x00757cd6    5b
    asm("add                esp, 0x38");                                     // 0x00757cd7    83c438
    asm("ret");                                                              // 0x00757cda    c3
    asm("LAB__addr_0x00757cdb:");
    asm("{disp32} mov       edi, dword ptr [edi + 0x00000744]");             // 0x00757cdb    8bbf44070000
    asm("mov                ecx, OFFSET _GGameInfo_00d019f8");               // 0x00757ce1    b9f819d000
    asm("call               ?GetVisualTime@GGameInfo@@QAEMXZ");              // 0x00757ce6    e8b5f8dfff
    asm("push               ecx");                                           // 0x00757ceb    51
    asm("fstp               dword ptr [esp]");                               // 0x00757cec    d91c24
    asm("call               ?Time2SkyType@LH3DSky@@QAEMM@Z");                // 0x00757cef    e8bc241100
    asm("add                esp, 0x04");                                     // 0x00757cf4    83c404
    asm("cmp.s              edi, ebx");                                      // 0x00757cf7    3bfb
    asm("{disp32} je        LAB__addr_0x00757e6b");                          // 0x00757cf9    0f846c010000
    asm("{disp32} fcomp     qword ptr [__real@8@333333333333f33f]");         // 0x00757cff    dc1d58878d00
    asm("fnstsw             ax");                                            // 0x00757d05    dfe0
    asm("test               ah, 0x41");                                      // 0x00757d07    f6c441
    asm("{disp8} je         LAB__addr_0x00757d1a");                          // 0x00757d0a    740e
    asm("mov                edx, dword ptr [edi]");                          // 0x00757d0c    8b17
    asm("mov.s              ecx, edi");                                      // 0x00757d0e    8bcf
    asm("call               dword ptr [edx + 0xd4]");                        // 0x00757d10    ff92d4000000
    asm("test               eax, eax");                                      // 0x00757d16    85c0
    asm("{disp8} jne        LAB__addr_0x00757d98");                          // 0x00757d18    757e
    asm("LAB__addr_0x00757d1a:");
    asm("mov.s              ecx, esi");                                      // 0x00757d1a    8bce
    asm("call               ?GetAbode@Villager@@QAEPAVAbode@@XZ");           // 0x00757d1c    e83fa4ffff
    asm("cmp.s              eax, ebx");                                      // 0x00757d21    3bc3
    asm("{disp8} je         LAB__addr_0x00757d50");                          // 0x00757d23    742b
    asm("{disp32} mov       eax, dword ptr [eax + 0x000000a0]");             // 0x00757d25    8b80a0000000
    asm("cmp.s              eax, ebx");                                      // 0x00757d2b    3bc3
    asm("{disp32} je        LAB__addr_0x00757e6d");                          // 0x00757d2d    0f843a010000
    asm("test               byte ptr [eax + 0x000000e0], 0x04");             // 0x00757d33    f680e000000004
    asm("{disp32} je        LAB__addr_0x00757e6d");                          // 0x00757d3a    0f842d010000
    asm("mov.s              ecx, esi");                                      // 0x00757d40    8bce
    asm("call               ?GoHome@Villager@@QAEIXZ");                     // 0x00757d42    e829850000
    asm("pop                edi");                                           // 0x00757d47    5f
    asm("pop                esi");                                           // 0x00757d48    5e
    asm("xor.s              eax, eax");                                      // 0x00757d49    33c0
    asm("pop                ebx");                                           // 0x00757d4b    5b
    asm("add                esp, 0x38");                                     // 0x00757d4c    83c438
    asm("ret");                                                              // 0x00757d4f    c3
    asm("LAB__addr_0x00757d50:");
    asm("mov                eax, dword ptr [edi]");                          // 0x00757d50    8b07
    asm("push               0x3a83126f");                                    // 0x00757d52    686f12833a
    asm("push               esi");                                           // 0x00757d57    56
    asm("mov.s              ecx, edi");                                      // 0x00757d58    8bcf
    asm("call               dword ptr [eax + 0x6b8]");                       // 0x00757d5a    ff90b8060000
    asm("test               eax, eax");                                      // 0x00757d60    85c0
    asm("{disp32} je        LAB__addr_0x00757e6d");                          // 0x00757d62    0f8405010000
    asm("{disp8} lea        ecx, dword ptr [esi + 0x14]");                   // 0x00757d68    8d4e14
    asm("push               ecx");                                           // 0x00757d6b    51
    asm("{disp8} lea        edx, dword ptr [esp + 0x10]");                   // 0x00757d6c    8d542410
    asm("push               edx");                                           // 0x00757d70    52
    asm("{disp32} lea       eax, dword ptr [esi + 0x000000c4]");             // 0x00757d71    8d86c4000000
    asm("push               eax");                                           // 0x00757d77    50
    asm("push               edi");                                           // 0x00757d78    57
    asm("call               ?GetNextDstPromemade@@YAXPAVCreche@@AAJPAUMapCoords@@ABU2@@Z");                          // 0x00757d79    e8d2fcffff
    asm("add                esp, 0x10");                                     // 0x00757d7e    83c410
    asm("push               0x71");                                          // 0x00757d81    6a71
    asm("{disp8} lea        ecx, dword ptr [esp + 0x10]");                   // 0x00757d83    8d4c2410
    asm("push               ecx");                                           // 0x00757d87    51
    asm("mov.s              ecx, esi");                                      // 0x00757d88    8bce
    asm("call               ?SetupMoveToPos@Villager@@QAE_NABUMapCoords@@W4VILLAGER_STATES@@@Z");                          // 0x00757d8a    e871ba0000
    asm("pop                edi");                                           // 0x00757d8f    5f
    asm("pop                esi");                                           // 0x00757d90    5e
    asm("xor.s              eax, eax");                                      // 0x00757d91    33c0
    asm("pop                ebx");                                           // 0x00757d93    5b
    asm("add                esp, 0x38");                                     // 0x00757d94    83c438
    asm("ret");                                                              // 0x00757d97    c3
    asm("LAB__addr_0x00757d98:");
    asm("mov                edx, dword ptr [edi]");                          // 0x00757d98    8b17
    asm("{disp8} lea        eax, dword ptr [esp + 0x24]");                   // 0x00757d9a    8d442424
    asm("push               eax");                                           // 0x00757d9e    50
    asm("mov.s              ecx, edi");                                      // 0x00757d9f    8bcf
    asm("{disp8} mov        dword ptr [esp + 0x34], ebx");                   // 0x00757da1    895c2434
    asm("{disp8} mov        dword ptr [esp + 0x38], ebx");                   // 0x00757da5    895c2438
    asm("{disp8} mov        dword ptr [esp + 0x3c], 0x00000013");            // 0x00757da9    c744243c13000000
    asm("{disp8} mov        dword ptr [esp + 0x40], ebx");                   // 0x00757db1    895c2440
    asm("{disp8} mov        dword ptr [esp + 0x44], 0x00000052");            // 0x00757db5    c744244452000000
    asm("call               dword ptr [edx + 0x10]");                        // 0x00757dbd    ff5210
    asm("{disp32} mov       ecx, dword ptr [_game]");                        // 0x00757dc0    8b0d5c19d000
    asm("call               ?GetCamera@GGame@@QAEPAVGCamera@@XZ");           // 0x00757dc6    e8b543dfff
    asm("{disp8} fld        dword ptr [esp + 0x24]");                        // 0x00757dcb    d9442424
    asm("{disp32} mov       ecx, dword ptr [_g_camera + 0]");                // 0x00757dcf    8b0db81dea00
    asm("{disp32} mov       edx, dword ptr [_g_camera + 4]");                // 0x00757dd5    8b15bc1dea00
    asm("{disp32} mov       eax, dword ptr [_g_camera + 8]");                // 0x00757ddb    a1c01dea00
    asm("{disp8} mov        dword ptr [esp + 0x18], ecx");                   // 0x00757de0    894c2418
    asm("{disp8} fsub       dword ptr [esp + 0x18]");                        // 0x00757de4    d8642418
    asm("{disp8} fld        dword ptr [esp + 0x28]");                        // 0x00757de8    d9442428
    asm("{disp8} mov        dword ptr [esp + 0x1c], edx");                   // 0x00757dec    8954241c
    asm("{disp8} fsub       dword ptr [esp + 0x1c]");                        // 0x00757df0    d864241c
    asm("{disp8} mov        dword ptr [esp + 0x20], eax");                   // 0x00757df4    89442420
    asm("{disp8} fld        dword ptr [esp + 0x2c]");                        // 0x00757df8    d944242c
    asm("{disp32} mov       ecx, dword ptr [_global]");                      // 0x00757dfc    8b0d203bcd00
    asm("{disp8} fsub       dword ptr [esp + 0x20]");                        // 0x00757e02    d8642420
    asm("{disp32} mov       edx, dword ptr [ecx + 0x000003b0]");             // 0x00757e06    8b91b0030000
    asm("fld                st(0)");                                         // 0x00757e0c    d9c0
    asm("push               ebx");                                           // 0x00757e0e    53
    asm("fmul               st, st(1)");                                     // 0x00757e0f    d8c9
    asm("push               ebx");                                           // 0x00757e11    53
    asm("fld                st(2)");                                         // 0x00757e12    d9c2
    asm("push               ebx");                                           // 0x00757e14    53
    asm("fmul               st, st(3)");                                     // 0x00757e15    d8cb
    asm("push               edx");                                           // 0x00757e17    52
    asm("push               ebx");                                           // 0x00757e18    53
    asm("faddp              st(1), st");                                     // 0x00757e19    dec1
    asm("fld                st(3)");                                         // 0x00757e1b    d9c3
    asm("{disp8} lea        eax, dword ptr [esp + 0x44]");                   // 0x00757e1d    8d442444
    asm("fmul               st, st(4)");                                     // 0x00757e21    d8cc
    asm("push               eax");                                           // 0x00757e23    50
    asm("push               ecx");                                           // 0x00757e24    51
    asm("faddp              st(1), st");                                     // 0x00757e25    dec1
    asm("fsqrt");                                                            // 0x00757e27    d9fa
    asm("fstp               st(3)");                                         // 0x00757e29    dddb
    asm("fstp               st(0)");                                         // 0x00757e2b    ddd8
    asm("fstp               st(0)");                                         // 0x00757e2d    ddd8
    asm("fstp               dword ptr [esp]");                               // 0x00757e2f    d91c24
    asm("push               edi");                                           // 0x00757e32    57
    asm("call               _jmp_addr_0x0042a4b0");                          // 0x00757e33    e87826cdff
    asm("{disp8} lea        ecx, dword ptr [esi + 0x14]");                   // 0x00757e38    8d4e14
    asm("push               ecx");                                           // 0x00757e3b    51
    asm("{disp8} lea        edx, dword ptr [esp + 0x10]");                   // 0x00757e3c    8d542410
    asm("push               edx");                                           // 0x00757e40    52
    asm("{disp32} lea       eax, dword ptr [esi + 0x000000c4]");             // 0x00757e41    8d86c4000000
    asm("push               eax");                                           // 0x00757e47    50
    asm("push               edi");                                           // 0x00757e48    57
    asm("call               ?GetNextDstPromemade@@YAXPAVCreche@@AAJPAUMapCoords@@ABU2@@Z");                          // 0x00757e49    e802fcffff
    asm("add                esp, 0x10");                                     // 0x00757e4e    83c410
    asm("push               0x71");                                          // 0x00757e51    6a71
    asm("{disp8} lea        ecx, dword ptr [esp + 0x10]");                   // 0x00757e53    8d4c2410
    asm("push               ecx");                                           // 0x00757e57    51
    asm("mov.s              ecx, esi");                                      // 0x00757e58    8bce
    asm("call               ?SetupMoveToPos@Villager@@QAE_NABUMapCoords@@W4VILLAGER_STATES@@@Z");                          // 0x00757e5a    e8a1b90000
    asm("pop                edi");                                           // 0x00757e5f    5f
    asm("pop                esi");                                           // 0x00757e60    5e
    asm("mov                eax, 0x00000001");                               // 0x00757e61    b801000000
    asm("pop                ebx");                                           // 0x00757e66    5b
    asm("add                esp, 0x38");                                     // 0x00757e67    83c438
    asm("ret");                                                              // 0x00757e6a    c3
    asm("LAB__addr_0x00757e6b:");
    asm("fstp               st(0)");                                         // 0x00757e6b    ddd8
    asm("LAB__addr_0x00757e6d:");
    asm("pop                edi");                                           // 0x00757e6d    5f
    asm("pop                esi");                                           // 0x00757e6e    5e
    asm("xor.s              eax, eax");                                      // 0x00757e6f    33c0
    asm("pop                ebx");                                           // 0x00757e71    5b
    asm("add                esp, 0x38");                                     // 0x00757e72    83c438
}

__attribute__((no_callee_saves, XOR32rr_REV))
uint32_t __fastcall CheckChild__8VillagerFv(struct Villager* this)
{
    uint32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} jne        LAB__addr_0x00757e98\n\t"
        "call               ?GoHome@Villager@@QAEIXZ\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00757e98:\n\t"
        "call               ?IsMotherAlive@Villager@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00757ea7\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000100], eax\n"
        "LAB__addr_0x00757ea7:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsHungry@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00757ebb\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GoHome@Villager@@QAEIXZ\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00757ebb:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves))
bool32_t __fastcall ChildDecideWhatToDo__8VillagerFv(struct Villager* this)
{
    asm("push               esi");                                           // 0x00757ec0    56
    asm("mov.s              esi, ecx");                                      // 0x00757ec1    8bf1
    asm("call               ?CheckChild@Villager@@QAEIXZ");                  // 0x00757ec3    e8b8ffffff
    asm("cmp                eax, 0x01");                                     // 0x00757ec8    83f801
    asm("{disp8} je         LAB__addr_0x00757ef0");                          // 0x00757ecb    7423
    asm("mov.s              ecx, esi");                                      // 0x00757ecd    8bce
    asm("call               LAB__addr_0x00757c80");                          // 0x00757ecf    e8acfdffff
    asm("cmp                eax, 0x01");                                     // 0x00757ed4    83f801
    asm("{disp8} je         LAB__addr_0x00757ef0");                          // 0x00757ed7    7417
    asm("mov.s              ecx, esi");                                      // 0x00757ed9    8bce
    asm("call               ?ChildGotoCreche@Villager@@QAEIXZ");             // 0x00757edb    e810fbffff
    asm("test               eax, eax");                                      // 0x00757ee0    85c0
    asm("{disp8} jne        LAB__addr_0x00757ef0");                          // 0x00757ee2    750c
    asm("mov                eax, dword ptr [esi]");                          // 0x00757ee4    8b06
    asm("push               0x72");                                          // 0x00757ee6    6a72
    asm("mov.s              ecx, esi");                                      // 0x00757ee8    8bce
    asm("call               dword ptr [eax + 0x8e8]");                       // 0x00757eea    ff90e8080000
    asm("LAB__addr_0x00757ef0:");
    asm("mov                eax, 0x00000001");                               // 0x00757ef0    b801000000
    asm("pop                esi");                                           // 0x00757ef5    5e
}

__attribute__((no_tail_call))
bool32_t __fastcall CheckChildActivity__8VillagerFv(struct Villager* this)
{
    extern bool32_t __fastcall __opaque_ChildDecideWhatToDo(struct Villager*) asm("__thunk_call_ChildDecideWhatToDo");
    __opaque_ChildDecideWhatToDo(this);
    return 1;
}

__attribute__((forced_callee_saves("esi"), force_this_esi, MOV32rr_REV, prefer_push_before_ecx))
bool32_t __fastcall ChildBecomesAdult__8VillagerFv(struct Villager* this)
{
    *(uint32_t*)((char*)this + 0x100) = 0;
    extern void __fastcall __opaque_CheckNeedNewAbode(struct Villager*) asm("__thunk_call_CheckNeedNewAbode");
    __opaque_CheckNeedNewAbode(this);
    typedef void (__attribute__((thiscall)) *fn_t)(struct Villager*, int);
    fn_t fn = ((fn_t*)(*(void**)this))[0x8e8 / 4];
    fn(this, 0xea);
    return 1;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall IsMotherAlive__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "%{disp32%} mov       esi, dword ptr [edi + 0x00000100]\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x00757f89\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x2c]\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00757f89\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} mov        edx, dword ptr [edi + 0x28]\n\t"
        "%{disp32%} mov       eax, dword ptr [ecx + 0x000001f4]\n\t"
        "cmp                eax, dword ptr [edx + 0x000001f4]\n\t"
        "%{disp8%} jne        LAB__addr_0x00757f89\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsAMother@Villager@@QAE_NXZ\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00757f89\n\t"
        "%{disp32%} mov       cl, byte ptr [esi + 0x000000b4]\n\t"
        "and.s              cl, al\n\t"
        "cmp.s              cl, al\n\t"
        "%{disp8%} je         LAB__addr_0x00757f89\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x00757f89:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
bool32_t __fastcall CheckNeedNewAbode__8VillagerFv(struct Villager* this)
{
    bool32_t result;
    asm volatile (
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} jne       LAB__addr_0x0075806f\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00757fc5\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?IsTooCrowded@Abode@@QAEIXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x0075806f\n"
        "LAB__addr_0x00757fc5:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp32%} je        LAB__addr_0x00758060\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x04], 0x00000000\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00757ffa\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbode@Villager@@QAEPAVAbode@@XZ\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?CalculateScoreForAddingVillagerToAbode@Abode@@QAEMPAVVillager@@@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x04]\n"
        "LAB__addr_0x00757ffa:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               eax\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?FindAbodeWithSpaceInTown@Town@@QAEPAVAbode@@PAVVillager@@M@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0075803e\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?MoveVillagerToAbode@Villager@@QAEXPAVAbode@@@Z\n\t"
        "cmp                eax, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x0075803e\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsVillagerAvailable@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00758036\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x24\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x8e8]\n"
        "LAB__addr_0x00758036:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x0075803e:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?IsVillagerInHomelessList@Town@@QAEIPAVVillager@@@Z\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00758058\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?MakeHomeless@Villager@@QAEIXZ\n"
        "LAB__addr_0x00758058:\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x00758060:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?VagrantStart@Villager@@QAEIXZ\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret\n"
        "LAB__addr_0x0075806f:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "pop                ecx"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
void __fastcall MoveVillagerToAbode__8VillagerFP5Abode(struct Villager* this, const void* edx, struct Abode* abode)
{
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "mov                eax, dword ptr [edi]\n\t"
        "call               dword ptr [eax + 0xaf8]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x0c]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} je         LAB__addr_0x007580a6\n\t"
        "call               ?GetRoomLeftForChildren@Abode@@QAEHXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jg         LAB__addr_0x007580b6\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007580a6:\n\t"
        "call               ?GetRoomLeftForAdults@Abode@@QAEHXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jg         LAB__addr_0x007580b6\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x007580b6:\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?ForceMoveVillagerToAbode@Villager@@QAEXPAVAbode@@@Z\n\t"
        "pop                edi\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi"
        :: "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((no_callee_saves, XOR32rr_REV))
uint32_t __fastcall MakeChildOrphaned__8VillagerFP8Villager(struct Villager* this, const void* edx, struct Villager* param_1)
{
    uint32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x00000100]\n\t"
        "cmp                eax, dword ptr [esp + 0x08]\n\t"
        "%{disp8%} jne        LAB__addr_0x0075810c\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IsVillagerAvailable@Villager@@QAE_NXZ\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x007580f9\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x00000083\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x8e8]\n"
        "LAB__addr_0x007580f9:\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000100], 0x00000000\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x0075810c:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}

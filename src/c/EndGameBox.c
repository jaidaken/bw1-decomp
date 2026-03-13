#include "EndGameBox.h"

// win1.41 0056e130 SetSelectedTab helper - loops 7 tabs, sets selected flag
void __fastcall SetSelectedTab_EndGameBox(struct DialogBoxBase* this, const void* edx, int selected_tab) asm("_jmp_addr_0x0056e130");
void __fastcall SetSelectedTab_EndGameBox(struct DialogBoxBase* this, const void* edx, int selected_tab)
{
    asm("push              ebx");                                           // 0x0056e130
    asm("push              esi");                                           // 0x0056e131
    asm("{disp8} mov       esi, dword ptr [esp + 0x0c]");                   // 0x0056e132
    asm("push              edi");                                           // 0x0056e136
    asm("mov.s             edi, ecx");                                      // 0x0056e137
    asm("xor.s             eax, eax");                                      // 0x0056e139
    asm("{disp8} lea       edx, dword ptr [edi + 0x18]");                   // 0x0056e13b
    asm("LAB__addr_0x0056e13e:");
    asm("mov               ebx, dword ptr [edx]");                          // 0x0056e13e
    asm("xor.s             ecx, ecx");                                      // 0x0056e140
    asm("cmp.s             eax, esi");                                      // 0x0056e142
    asm("sete              cl");                                            // 0x0056e144
    asm("inc               eax");                                           // 0x0056e147
    asm("add               edx, 0x04");                                     // 0x0056e148
    asm("cmp               eax, 0x07");                                     // 0x0056e14b
    asm("{disp32} mov      dword ptr [ebx + 0x00000244], ecx");             // 0x0056e14e
    asm("{disp8} jl        LAB__addr_0x0056e13e");                          // 0x0056e154
    asm("{disp8} mov       dword ptr [edi + 0x10], esi");                   // 0x0056e156
    asm("pop               edi");                                           // 0x0056e159
    asm("pop               esi");                                           // 0x0056e15a
    asm("pop               ebx");                                           // 0x0056e15b
    asm("ret               0x0004");                                        // 0x0056e15c
    asm(".byte 0x90");                                                      // 0x0056e15f nop padding
    __builtin_unreachable();
}

// win1.41 0056e160 EndGameBox::Init - creates tab buttons, labels, big buttons, bar graph
void __fastcall Init__10EndGameBoxFUlUlPFiP8SetupBoxP12SetupControlii_v(struct DialogBoxBase* this, const void* edx, uint32_t param_1, uint32_t param_2, void (__stdcall* param_3)(int param_1, struct SetupBox * param_2, struct SetupControl * param_3, int param_4, int param_5))
{
    asm("sub               esp, 0x10");                                     // 0x0056e160
    asm("{disp8} mov       eax, dword ptr [esp + 0x1c]");                   // 0x0056e163
    asm("push              ebx");                                           // 0x0056e167
    asm("push              ebp");                                           // 0x0056e168
    asm("push              esi");                                           // 0x0056e169
    asm("{disp8} mov       esi, dword ptr [esp + 0x20]");                   // 0x0056e16a
    asm("push              edi");                                           // 0x0056e16e
    asm("mov.s             edi, ecx");                                      // 0x0056e16f
    asm("{disp8} mov       ecx, dword ptr [esp + 0x28]");                   // 0x0056e171
    asm("push              eax");                                           // 0x0056e175
    asm("push              ecx");                                           // 0x0056e176
    asm("push              esi");                                           // 0x0056e177
    asm("mov.s             ecx, edi");                                      // 0x0056e178
    asm("call              @Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v@20"); // 0x0056e17a
    asm("xor.s             ebp, ebp");                                      // 0x0056e17f
    asm("{disp8} mov       dword ptr [esp + 0x10], esi");                   // 0x0056e181
    asm("{disp8} mov       dword ptr [esp + 0x14], ebp");                   // 0x0056e185
    asm("{disp8} fild      qword ptr [esp + 0x10]");                        // 0x0056e189
    asm("shr               esi, 1");                                        // 0x0056e18d
    asm("mov               edx, 0x00000190");                               // 0x0056e18f
    asm("sub.s             edx, esi");                                      // 0x0056e194
    asm("{disp32} fmul     dword ptr [rdata_bytes + 0x56f3c]");             // 0x0056e196
    asm("{disp8} mov       dword ptr [esp + 0x18], edx");                   // 0x0056e19c
    asm("{disp8} mov       dword ptr [esp + 0x1c], ebp");                   // 0x0056e1a0
    asm("{disp32} mov      dword ptr [data_bytes + 0x34006c], edi");        // 0x0056e1a4
    asm("{disp8} fstp      dword ptr [esp + 0x10]");                        // 0x0056e1aa
    asm("{disp8} mov       dword ptr [edi + 0x10], ebp");                   // 0x0056e1ae
    asm("{disp8} fild      qword ptr [esp + 0x18]");                        // 0x0056e1b1
    asm("xor.s             esi, esi");                                      // 0x0056e1b5
    asm("{disp8} fstp      dword ptr [esp + 0x24]");                        // 0x0056e1b7
    // Tab creation loop
    asm("LAB__addr_0x0056e1bb:");
    asm("mov.s             eax, esi");                                      // 0x0056e1bb
    asm("sub.s             eax, ebp");                                      // 0x0056e1bd
    asm("{disp8} je        LAB__addr_0x0056e21c");                          // 0x0056e1bf
    asm("dec               eax");                                           // 0x0056e1c1
    asm("{disp8} je        LAB__addr_0x0056e1f0");                          // 0x0056e1c2
    asm("dec               eax");                                           // 0x0056e1c4
    asm("{disp8} je        LAB__addr_0x0056e1d1");                          // 0x0056e1c5
    asm("{disp8} mov       dword ptr [esp + 0x2c], 0x00c4cd30");            // 0x0056e1c7
    asm("{disp8} jmp       LAB__addr_0x0056e242");                          // 0x0056e1cf
    // Case 2: version > 0x19f8
    asm("LAB__addr_0x0056e1d1:");
    asm("cmp               dword ptr [data_bytes + 0x351cac], 0x000019f8"); // 0x0056e1d1
    asm("{disp32} mov      eax, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e1db
    asm("{disp8} jbe       LAB__addr_0x0056e1e7");                          // 0x0056e1e0
    asm("add               eax, 0x000137a0");                               // 0x0056e1e2
    asm("LAB__addr_0x0056e1e7:");
    asm("{disp8} mov       ecx, dword ptr [eax + 0x08]");                   // 0x0056e1e7
    asm("{disp8} mov       dword ptr [esp + 0x2c], ecx");                   // 0x0056e1ea
    asm("{disp8} jmp       LAB__addr_0x0056e242");                          // 0x0056e1ee
    // Case 1: version check for crash site
    asm("LAB__addr_0x0056e1f0:");
    asm("cmp               dword ptr [data_bytes + 0x351c9c], 0x13");       // 0x0056e1f0
    asm("{disp8} ja        LAB__addr_0x0056e207");                          // 0x0056e1f7
    // Wine/Proton: null deref when DirectPlay uninitialized (patched by wine_fix_patch.py)
    asm("{disp32} mov      eax, dword ptr [data_bytes + 0x351c98]");        // 0x0056e1f9
    asm("{disp8} mov       eax, dword ptr [eax + 0x08]");                   // 0x0056e1fe
    asm("{disp8} mov       dword ptr [esp + 0x2c], eax");                   // 0x0056e201
    asm("{disp8} jmp       LAB__addr_0x0056e242");                          // 0x0056e205
    asm("LAB__addr_0x0056e207:");
    asm("{disp32} mov      edx, dword ptr [data_bytes + 0x351c98]");        // 0x0056e207
    asm("{disp32} lea      eax, dword ptr [edx + 0x000000e4]");             // 0x0056e20d
    asm("{disp8} mov       eax, dword ptr [eax + 0x08]");                   // 0x0056e213
    asm("{disp8} mov       dword ptr [esp + 0x2c], eax");                   // 0x0056e216
    asm("{disp8} jmp       LAB__addr_0x0056e242");                          // 0x0056e21a
    // Case 0: version check
    asm("LAB__addr_0x0056e21c:");
    asm("cmp               dword ptr [data_bytes + 0x351cac], 0x00001a0e"); // 0x0056e21c
    asm("{disp8} ja        LAB__addr_0x0056e22f");                          // 0x0056e226
    asm("{disp32} mov      eax, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e228
    asm("{disp8} jmp       LAB__addr_0x0056e23b");                          // 0x0056e22d
    asm("LAB__addr_0x0056e22f:");
    asm("{disp32} mov      ecx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e22f
    asm("{disp32} lea      eax, dword ptr [ecx + 0x000138a8]");             // 0x0056e235
    asm("LAB__addr_0x0056e23b:");
    asm("{disp8} mov       edx, dword ptr [eax + 0x08]");                   // 0x0056e23b
    asm("{disp8} mov       dword ptr [esp + 0x2c], edx");                   // 0x0056e23e
    // Allocate and construct SetupTabButton
    asm("LAB__addr_0x0056e242:");
    asm("push              0x00000232");                                    // 0x0056e242
    asm("push              0x00bef098");                                    // 0x0056e247
    asm("push              0x00000254");                                    // 0x0056e24c
    asm("call              ___nw__FUl");                                    // 0x0056e251
    asm("mov.s             ebx, eax");                                      // 0x0056e256
    asm("add               esp, 0x0c");                                     // 0x0056e258
    asm("cmp.s             ebx, ebp");                                      // 0x0056e25b
    asm("{disp8} je        LAB__addr_0x0056e2bc");                          // 0x0056e25d
    asm("{disp8} fld       dword ptr [esp + 0x24]");                        // 0x0056e25f
    asm("call              _jmp_addr_0x007a1400");                          // 0x0056e263
    asm("{disp8} fld       dword ptr [esp + 0x24]");                        // 0x0056e268
    asm("mov.s             ebp, eax");                                      // 0x0056e26c
    asm("{disp8} fadd      dword ptr [esp + 0x10]");                        // 0x0056e26e
    asm("xor.s             eax, eax");                                      // 0x0056e272
    asm("cmp               esi, 0x06");                                     // 0x0056e274
    asm("sete              al");                                            // 0x0056e277
    asm("xor.s             ecx, ecx");                                      // 0x0056e27a
    asm("test              esi, esi");                                      // 0x0056e27c
    asm("sete              cl");                                            // 0x0056e27e
    asm("xor.s             edx, edx");                                      // 0x0056e281
    asm("push              eax");                                           // 0x0056e283
    asm("{disp8} mov       eax, dword ptr [esp + 0x30]");                   // 0x0056e284
    asm("push              ecx");                                           // 0x0056e288
    asm("cmp               esi, dword ptr [edi + 0x10]");                   // 0x0056e289
    asm("sete              dl");                                            // 0x0056e28c
    asm("push              edx");                                           // 0x0056e28f
    asm("push              eax");                                           // 0x0056e290
    asm("push              0x28");                                          // 0x0056e291
    asm("call              _jmp_addr_0x007a1400");                          // 0x0056e293
    asm("{disp8} mov       ecx, dword ptr [esp + 0x3c]");                   // 0x0056e298
    asm("sub.s             eax, ebp");                                      // 0x0056e29c
    asm("push              eax");                                           // 0x0056e29e
    asm("shr               ecx, 1");                                        // 0x0056e29f
    asm("mov               edx, 0x00000104");                               // 0x0056e2a1
    asm("sub.s             edx, ecx");                                      // 0x0056e2a6
    asm("push              edx");                                           // 0x0056e2a8
    asm("push              ebp");                                           // 0x0056e2a9
    asm("{disp32} lea      eax, dword ptr [esi + 0x000008fc]");             // 0x0056e2aa
    asm("push              eax");                                           // 0x0056e2b0
    asm("mov.s             ecx, ebx");                                      // 0x0056e2b1
    asm("call              @__ct__14SetupTabButtonFiiiiiPwiii@35");          // 0x0056e2b3
    asm("xor.s             ebp, ebp");                                      // 0x0056e2b8
    asm("{disp8} jmp       LAB__addr_0x0056e2be");                          // 0x0056e2ba
    asm("LAB__addr_0x0056e2bc:");
    asm("xor.s             eax, eax");                                      // 0x0056e2bc
    asm("LAB__addr_0x0056e2be:");
    asm("{disp8} fld       dword ptr [esp + 0x24]");                        // 0x0056e2be
    asm("{disp8} mov       dword ptr [edi + esi * 0x4 + 0x18], eax");       // 0x0056e2c2
    asm("{disp8} fadd      dword ptr [esp + 0x10]");                        // 0x0056e2c6
    asm("inc               esi");                                           // 0x0056e2ca
    asm("cmp               esi, 0x07");                                     // 0x0056e2cb
    asm("{disp8} fstp      dword ptr [esp + 0x24]");                        // 0x0056e2ce
    asm("{disp32} jl       LAB__addr_0x0056e1bb");                          // 0x0056e2d2
    // After tab loop - create score_label (SetupControl at offset 0x38)
    asm("call              _jmp_addr_0x00407a20");                          // 0x0056e2d8
    asm("{disp8} mov       ecx, dword ptr [edi + 0x04]");                   // 0x0056e2dd
    asm("push              0x00000236");                                    // 0x0056e2e0
    asm("push              0x00bef098");                                    // 0x0056e2e5
    asm("push              0x00000244");                                    // 0x0056e2ea
    asm("{disp32} mov      dword ptr [ecx + 0x000000ac], eax");             // 0x0056e2ef
    asm("call              ___nw__FUl");                                    // 0x0056e2f5
    asm("mov.s             esi, eax");                                      // 0x0056e2fa
    asm("add               esp, 0x0c");                                     // 0x0056e2fc
    asm("cmp.s             esi, ebp");                                      // 0x0056e2ff
    asm("mov               ebx, 0x00000004");                               // 0x0056e301
    asm("{disp8} je        LAB__addr_0x0056e33f");                          // 0x0056e306
    asm("push              0x00c4cd30");                                    // 0x0056e308
    asm("push              0x000000e4");                                    // 0x0056e30d
    asm("push              0x000002d0");                                    // 0x0056e312
    asm("push              0x50");                                          // 0x0056e317
    asm("push              0x28");                                          // 0x0056e319
    asm("push              0x1");                                           // 0x0056e31b
    asm("mov.s             ecx, esi");                                      // 0x0056e31d
    asm("call              ??0SetupControl@@QAE@HHHHHPA_W@Z");              // 0x0056e31f
    asm("mov               dword ptr [esi], 0x008ab5c0");                   // 0x0056e324
    asm("{disp32} mov      dword ptr [esi + 0x0000023c], ebx");             // 0x0056e32a
    asm("{disp32} mov      byte ptr [esi + 0x0000022a], 0x00");             // 0x0056e330
    asm("{disp32} mov      dword ptr [esi + 0x00000240], ebp");             // 0x0056e337
    asm("{disp8} jmp       LAB__addr_0x0056e341");                          // 0x0056e33d
    asm("LAB__addr_0x0056e33f:");
    asm("xor.s             esi, esi");                                      // 0x0056e33f
    // Create status_label (SetupControl at offset 0x3c)
    asm("LAB__addr_0x0056e341:");
    asm("push              0x00000237");                                    // 0x0056e341
    asm("push              0x00bef098");                                    // 0x0056e346
    asm("push              0x00000244");                                    // 0x0056e34b
    asm("{disp8} mov       dword ptr [edi + 0x38], esi");                   // 0x0056e350
    asm("call              ___nw__FUl");                                    // 0x0056e353
    asm("mov.s             esi, eax");                                      // 0x0056e358
    asm("add               esp, 0x0c");                                     // 0x0056e35a
    asm("cmp.s             esi, ebp");                                      // 0x0056e35d
    asm("{disp8} je        LAB__addr_0x0056e398");                          // 0x0056e35f
    asm("push              0x00c4cd30");                                    // 0x0056e361
    asm("push              0x32");                                          // 0x0056e366
    asm("push              0x000002d0");                                    // 0x0056e368
    asm("push              0x000000c8");                                    // 0x0056e36d
    asm("push              0x28");                                          // 0x0056e372
    asm("push              0x1");                                           // 0x0056e374
    asm("mov.s             ecx, esi");                                      // 0x0056e376
    asm("call              ??0SetupControl@@QAE@HHHHHPA_W@Z");              // 0x0056e378
    asm("mov               dword ptr [esi], 0x008ab5c0");                   // 0x0056e37d
    asm("{disp32} mov      dword ptr [esi + 0x0000023c], ebx");             // 0x0056e383
    asm("{disp32} mov      byte ptr [esi + 0x0000022a], 0x00");             // 0x0056e389
    asm("{disp32} mov      dword ptr [esi + 0x00000240], ebp");             // 0x0056e390
    asm("{disp8} jmp       LAB__addr_0x0056e39a");                          // 0x0056e396
    asm("LAB__addr_0x0056e398:");
    asm("xor.s             esi, esi");                                      // 0x0056e398
    // Create detail_label (SetupControl at offset 0x40)
    asm("LAB__addr_0x0056e39a:");
    asm("push              0x00000238");                                    // 0x0056e39a
    asm("push              0x00bef098");                                    // 0x0056e39f
    asm("push              0x00000244");                                    // 0x0056e3a4
    asm("{disp8} mov       dword ptr [edi + 0x3c], esi");                   // 0x0056e3a9
    asm("call              ___nw__FUl");                                    // 0x0056e3ac
    asm("mov.s             esi, eax");                                      // 0x0056e3b1
    asm("add               esp, 0x0c");                                     // 0x0056e3b3
    asm("cmp.s             esi, ebp");                                      // 0x0056e3b6
    asm("{disp8} je        LAB__addr_0x0056e416");                          // 0x0056e3b8
    asm("cmp               dword ptr [data_bytes + 0x351cac], 0x00000dec"); // 0x0056e3ba
    asm("{disp8} ja        LAB__addr_0x0056e3cd");                          // 0x0056e3c4
    asm("{disp32} mov      eax, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e3c6
    asm("{disp8} jmp       LAB__addr_0x0056e3d9");                          // 0x0056e3cb
    asm("LAB__addr_0x0056e3cd:");
    asm("{disp32} mov      edx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e3cd
    asm("{disp32} lea      eax, dword ptr [edx + 0x0000a710]");             // 0x0056e3d3
    asm("LAB__addr_0x0056e3d9:");
    asm("{disp8} mov       eax, dword ptr [eax + 0x08]");                   // 0x0056e3d9
    asm("push              eax");                                           // 0x0056e3dc
    asm("push              0x28");                                          // 0x0056e3dd
    asm("push              0x000000c8");                                    // 0x0056e3df
    asm("push              0x00000212");                                    // 0x0056e3e4
    asm("push              0x0000012c");                                    // 0x0056e3e9
    asm("push              0x1");                                           // 0x0056e3ee
    asm("mov.s             ecx, esi");                                      // 0x0056e3f0
    asm("call              ??0SetupControl@@QAE@HHHHHPA_W@Z");              // 0x0056e3f2
    asm("mov               dword ptr [esi], 0x008ab5c0");                   // 0x0056e3f7
    asm("{disp32} mov      dword ptr [esi + 0x0000023c], 0x00000001");      // 0x0056e3fd
    asm("{disp32} mov      byte ptr [esi + 0x0000022a], 0x00");             // 0x0056e407
    asm("{disp32} mov      dword ptr [esi + 0x00000240], ebp");             // 0x0056e40e
    asm("{disp8} jmp       LAB__addr_0x0056e418");                          // 0x0056e414
    asm("LAB__addr_0x0056e416:");
    asm("xor.s             esi, esi");                                      // 0x0056e416
    // Store detail_label, call GetSmallTextSize, create image_label (offset 0x34)
    asm("LAB__addr_0x0056e418:");
    asm("{disp8} mov       dword ptr [edi + 0x40], esi");                   // 0x0056e418
    asm("call              _GetSmallTextSize__Fv");                         // 0x0056e41b
    asm("{disp8} mov       ecx, dword ptr [edi + 0x40]");                   // 0x0056e420
    asm("push              0x0000023a");                                    // 0x0056e423
    asm("push              0x00bef098");                                    // 0x0056e428
    asm("push              0x00000244");                                    // 0x0056e42d
    asm("{disp8} mov       dword ptr [ecx + 0x20], eax");                   // 0x0056e432
    asm("call              ___nw__FUl");                                    // 0x0056e435
    asm("mov.s             esi, eax");                                      // 0x0056e43a
    asm("add               esp, 0x0c");                                     // 0x0056e43c
    asm("cmp.s             esi, ebp");                                      // 0x0056e43f
    asm("{disp8} je        LAB__addr_0x0056e47a");                          // 0x0056e441
    asm("push              0x00c4cd30");                                    // 0x0056e443
    asm("push              0x31");                                          // 0x0056e448
    asm("push              0x000002d0");                                    // 0x0056e44a
    asm("push              0x000000fa");                                    // 0x0056e44f
    asm("push              0x28");                                          // 0x0056e454
    asm("push              0x1");                                           // 0x0056e456
    asm("mov.s             ecx, esi");                                      // 0x0056e458
    asm("call              ??0SetupControl@@QAE@HHHHHPA_W@Z");              // 0x0056e45a
    asm("mov               dword ptr [esi], 0x008ab5c0");                   // 0x0056e45f
    asm("{disp32} mov      dword ptr [esi + 0x0000023c], ebx");             // 0x0056e465
    asm("{disp32} mov      byte ptr [esi + 0x0000022a], 0x00");             // 0x0056e46b
    asm("{disp32} mov      dword ptr [esi + 0x00000240], ebp");             // 0x0056e472
    asm("{disp8} jmp       LAB__addr_0x0056e47c");                          // 0x0056e478
    asm("LAB__addr_0x0056e47a:");
    asm("xor.s             esi, esi");                                      // 0x0056e47a
    // Store score_label (offset 0x34), set text size, create alignment_label (offset 0x44)
    asm("LAB__addr_0x0056e47c:");
    asm("mov               eax, 0x00000001");                               // 0x0056e47c
    asm("{disp8} mov       dword ptr [edi + 0x34], esi");                   // 0x0056e481
    asm("{disp8} mov       dword ptr [esi + 0x1c], eax");                   // 0x0056e484
    asm("{disp8} mov       edx, dword ptr [edi + 0x38]");                   // 0x0056e487
    asm("push              0x00000240");                                    // 0x0056e48a
    asm("{disp8} mov       dword ptr [edx + 0x1c], eax");                   // 0x0056e48f
    asm("{disp8} mov       ecx, dword ptr [edi + 0x3c]");                   // 0x0056e492
    asm("push              0x00bef098");                                    // 0x0056e495
    asm("push              0x00000244");                                    // 0x0056e49a
    asm("{disp8} mov       dword ptr [ecx + 0x1c], eax");                   // 0x0056e49f
    asm("call              ___nw__FUl");                                    // 0x0056e4a2
    asm("mov.s             esi, eax");                                      // 0x0056e4a7
    asm("add               esp, 0x0c");                                     // 0x0056e4a9
    asm("cmp.s             esi, ebp");                                      // 0x0056e4ac
    asm("{disp8} je        LAB__addr_0x0056e505");                          // 0x0056e4ae
    asm("cmp               dword ptr [data_bytes + 0x351cac], 0x00001a8d"); // 0x0056e4b0
    asm("{disp8} ja        LAB__addr_0x0056e4c3");                          // 0x0056e4ba
    asm("{disp32} mov      eax, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e4bc
    asm("{disp8} jmp       LAB__addr_0x0056e4cf");                          // 0x0056e4c1
    asm("LAB__addr_0x0056e4c3:");
    asm("{disp32} mov      edx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e4c3
    asm("{disp32} lea      eax, dword ptr [edx + 0x00013e9c]");             // 0x0056e4c9
    asm("LAB__addr_0x0056e4cf:");
    asm("{disp8} mov       eax, dword ptr [eax + 0x08]");                   // 0x0056e4cf
    asm("push              eax");                                           // 0x0056e4d2
    asm("push              0x28");                                          // 0x0056e4d3
    asm("push              0x000002d0");                                    // 0x0056e4d5
    asm("push              0x0000014a");                                    // 0x0056e4da
    asm("push              0x28");                                          // 0x0056e4df
    asm("push              0x1");                                           // 0x0056e4e1
    asm("mov.s             ecx, esi");                                      // 0x0056e4e3
    asm("call              ??0SetupControl@@QAE@HHHHHPA_W@Z");              // 0x0056e4e5
    asm("mov               dword ptr [esi], 0x008ab5c0");                   // 0x0056e4ea
    asm("{disp32} mov      dword ptr [esi + 0x0000023c], ebx");             // 0x0056e4f0
    asm("{disp32} mov      byte ptr [esi + 0x0000022a], 0x00");             // 0x0056e4f6
    asm("{disp32} mov      dword ptr [esi + 0x00000240], ebp");             // 0x0056e4fd
    asm("{disp8} jmp       LAB__addr_0x0056e507");                          // 0x0056e503
    asm("LAB__addr_0x0056e505:");
    asm("xor.s             esi, esi");                                      // 0x0056e505
    // Create VBarGraph (offset 0x48)
    asm("LAB__addr_0x0056e507:");
    asm("push              0x00000243");                                    // 0x0056e507
    asm("push              0x00bef098");                                    // 0x0056e50c
    asm("push              0x00000284");                                    // 0x0056e511
    asm("{disp8} mov       dword ptr [edi + 0x44], esi");                   // 0x0056e516
    asm("call              ___nw__FUl");                                    // 0x0056e519
    asm("add               esp, 0x0c");                                     // 0x0056e51e
    asm("cmp.s             eax, ebp");                                      // 0x0056e521
    asm("{disp8} je        LAB__addr_0x0056e548");                          // 0x0056e523
    asm("push              0x00c4cd30");                                    // 0x0056e525
    asm("push              0x000000af");                                    // 0x0056e52a
    asm("push              0x000000f0");                                    // 0x0056e52f
    asm("push              0x00000177");                                    // 0x0056e534
    asm("push              0x00000118");                                    // 0x0056e539
    asm("push              ebp");                                           // 0x0056e53e
    asm("mov.s             ecx, eax");                                      // 0x0056e53f
    asm("call              @__ct__14SetupVBarGraphFiiiiiPw@32");             // 0x0056e541
    asm("{disp8} jmp       LAB__addr_0x0056e54a");                          // 0x0056e546
    asm("LAB__addr_0x0056e548:");
    asm("xor.s             eax, eax");                                      // 0x0056e548
    // Store bar_graph, set text sizes, create BigButton 1 (offset 0x4c)
    asm("LAB__addr_0x0056e54a:");
    asm("{disp8} mov       ecx, dword ptr [edi + 0x34]");                   // 0x0056e54a
    asm("{disp8} mov       dword ptr [edi + 0x48], eax");                   // 0x0056e54d
    asm("mov               eax, 0x00000031");                               // 0x0056e550
    asm("push              0x0000024b");                                    // 0x0056e555
    asm("{disp8} mov       dword ptr [ecx + 0x20], eax");                   // 0x0056e55a
    asm("{disp8} mov       edx, dword ptr [edi + 0x38]");                   // 0x0056e55d
    asm("push              0x00bef098");                                    // 0x0056e560
    asm("push              0x0000025c");                                    // 0x0056e565
    asm("{disp8} mov       dword ptr [edx + 0x20], eax");                   // 0x0056e56a
    asm("call              ___nw__FUl");                                    // 0x0056e56d
    asm("add               esp, 0x0c");                                     // 0x0056e572
    asm("cmp.s             eax, ebp");                                      // 0x0056e575
    asm("{disp8} je        LAB__addr_0x0056e5af");                          // 0x0056e577
    asm("cmp               dword ptr [data_bytes + 0x351cac], 0x00001a38"); // 0x0056e579
    asm("{disp32} mov      ecx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e583
    asm("{disp8} jbe       LAB__addr_0x0056e591");                          // 0x0056e589
    asm("add               ecx, 0x00013aa0");                               // 0x0056e58b
    asm("LAB__addr_0x0056e591:");
    asm("{disp8} mov       ecx, dword ptr [ecx + 0x08]");                   // 0x0056e591
    asm("push              0x2");                                           // 0x0056e594
    asm("push              ebp");                                           // 0x0056e596
    asm("push              0x28");                                          // 0x0056e597
    asm("push              ecx");                                           // 0x0056e599
    asm("push              0x00000212");                                    // 0x0056e59a
    asm("push              0x14");                                          // 0x0056e59f
    asm("push              0x000003e7");                                    // 0x0056e5a1
    asm("mov.s             ecx, eax");                                      // 0x0056e5a6
    asm("call              @__ct__14SetupBigButtonFiiiPwiii@36");            // 0x0056e5a8
    asm("{disp8} jmp       LAB__addr_0x0056e5b1");                          // 0x0056e5ad
    asm("LAB__addr_0x0056e5af:");
    asm("xor.s             eax, eax");                                      // 0x0056e5af
    // Create BigButton 3 (offset 0x54)
    asm("LAB__addr_0x0056e5b1:");
    asm("push              0x0000024c");                                    // 0x0056e5b1
    asm("push              0x00bef098");                                    // 0x0056e5b6
    asm("push              0x0000025c");                                    // 0x0056e5bb
    asm("{disp8} mov       dword ptr [edi + 0x4c], eax");                   // 0x0056e5c0
    asm("call              ___nw__FUl");                                    // 0x0056e5c3
    asm("add               esp, 0x0c");                                     // 0x0056e5c8
    asm("cmp.s             eax, ebp");                                      // 0x0056e5cb
    asm("{disp8} je        LAB__addr_0x0056e60d");                          // 0x0056e5cd
    asm("cmp               dword ptr [data_bytes + 0x351cac], 0x00001ab5"); // 0x0056e5cf
    asm("{disp8} ja        LAB__addr_0x0056e5e3");                          // 0x0056e5d9
    asm("{disp32} mov      ecx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e5db
    asm("{disp8} jmp       LAB__addr_0x0056e5ef");                          // 0x0056e5e1
    asm("LAB__addr_0x0056e5e3:");
    asm("{disp32} mov      edx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e5e3
    asm("{disp32} lea      ecx, dword ptr [edx + 0x0001407c]");             // 0x0056e5e9
    asm("LAB__addr_0x0056e5ef:");
    asm("{disp8} mov       ecx, dword ptr [ecx + 0x08]");                   // 0x0056e5ef
    asm("push              0x2");                                           // 0x0056e5f2
    asm("push              ebp");                                           // 0x0056e5f4
    asm("push              0x28");                                          // 0x0056e5f5
    asm("push              ecx");                                           // 0x0056e5f7
    asm("push              0x00000212");                                    // 0x0056e5f8
    asm("push              0x14");                                          // 0x0056e5fd
    asm("push              0x000003e7");                                    // 0x0056e5ff
    asm("mov.s             ecx, eax");                                      // 0x0056e604
    asm("call              @__ct__14SetupBigButtonFiiiPwiii@36");            // 0x0056e606
    asm("{disp8} jmp       LAB__addr_0x0056e60f");                          // 0x0056e60b
    asm("LAB__addr_0x0056e60d:");
    asm("xor.s             eax, eax");                                      // 0x0056e60d
    // Create BigButton 2 (offset 0x50)
    asm("LAB__addr_0x0056e60f:");
    asm("push              0x0000024d");                                    // 0x0056e60f
    asm("push              0x00bef098");                                    // 0x0056e614
    asm("push              0x0000025c");                                    // 0x0056e619
    asm("{disp8} mov       dword ptr [edi + 0x54], eax");                   // 0x0056e61e
    asm("call              ___nw__FUl");                                    // 0x0056e621
    asm("add               esp, 0x0c");                                     // 0x0056e626
    asm("cmp.s             eax, ebp");                                      // 0x0056e629
    asm("{disp8} je        LAB__addr_0x0056e667");                          // 0x0056e62b
    asm("cmp               dword ptr [data_bytes + 0x351cac], 0x00000de4"); // 0x0056e62d
    asm("{disp32} mov      ecx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e637
    asm("{disp8} jbe       LAB__addr_0x0056e645");                          // 0x0056e63d
    asm("add               ecx, 0x0000a6b0");                               // 0x0056e63f
    asm("LAB__addr_0x0056e645:");
    asm("{disp8} mov       ecx, dword ptr [ecx + 0x08]");                   // 0x0056e645
    asm("push              0x3");                                           // 0x0056e648
    asm("push              0x1");                                           // 0x0056e64a
    asm("push              0x28");                                          // 0x0056e64c
    asm("push              ecx");                                           // 0x0056e64e
    asm("push              0x00000212");                                    // 0x0056e64f
    asm("push              0x000002e4");                                    // 0x0056e654
    asm("push              0x000003e7");                                    // 0x0056e659
    asm("mov.s             ecx, eax");                                      // 0x0056e65e
    asm("call              @__ct__14SetupBigButtonFiiiPwiii@36");            // 0x0056e660
    asm("{disp8} jmp       LAB__addr_0x0056e669");                          // 0x0056e665
    asm("LAB__addr_0x0056e667:");
    asm("xor.s             eax, eax");                                      // 0x0056e667
    // Set button callbacks and return
    asm("LAB__addr_0x0056e669:");
    asm("{disp8} mov       edx, dword ptr [edi + 0x4c]");                   // 0x0056e669
    asm("{disp8} mov       dword ptr [edi + 0x50], eax");                   // 0x0056e66c
    asm("{disp32} mov      dword ptr [edx + 0x00000238], 0x0056e720");      // 0x0056e66f
    asm("{disp8} mov       eax, dword ptr [edi + 0x54]");                   // 0x0056e679
    asm("{disp32} mov      dword ptr [eax + 0x00000238], 0x0056e6a0");      // 0x0056e67c
    asm("{disp8} mov       ecx, dword ptr [edi + 0x50]");                   // 0x0056e686
    asm("pop               edi");                                           // 0x0056e689
    asm("pop               esi");                                           // 0x0056e68a
    asm("pop               ebp");                                           // 0x0056e68b
    asm("{disp32} mov      dword ptr [ecx + 0x00000238], 0x0056e6b0");      // 0x0056e68c
    asm("pop               ebx");                                           // 0x0056e696
    asm("add               esp, 0x10");                                     // 0x0056e697
    asm("ret               0x000c");                                        // 0x0056e69a
    // Padding nops
    asm(".byte 0x90");                                                      // 0x0056e69d
    asm(".byte 0x90");                                                      // 0x0056e69e
    asm(".byte 0x90");                                                      // 0x0056e69f
    // Callback thunk 1 at 0x0056e6a0: button_2 click -> DialogBoxBase function
    asm("{disp32} jmp      _jmp_addr_0x00513640");                          // 0x0056e6a0
    asm(".byte 0x90, 0x90, 0x90, 0x90");                                    // 0x0056e6a5
    asm(".byte 0x90, 0x90, 0x90, 0x90");                                    // 0x0056e6a9
    asm(".byte 0x90, 0x90, 0x90");                                          // 0x0056e6ad
    // Callback 2 at 0x0056e6b0: button_3 click handler
    asm("call              _jmp_addr_0x00513640");                          // 0x0056e6b0
    asm("{disp32} mov      ecx, dword ptr [_game]");                        // 0x0056e6b5
    asm("{disp32} mov      eax, dword ptr [ecx + 0x00205a0c]");             // 0x0056e6bb
    asm("test              eax, eax");                                      // 0x0056e6c1
    asm("{disp8} je        LAB__addr_0x0056e6d0");                          // 0x0056e6c3
    asm("{disp32} mov      dword ptr [ecx + 0x00250180], 0x00000005");      // 0x0056e6c5
    asm("ret");                                                             // 0x0056e6cf
    asm("LAB__addr_0x0056e6d0:");
    asm("push              esi");                                           // 0x0056e6d0
    asm("call              _jmp_addr_0x005559b0");                          // 0x0056e6d1
    asm("{disp32} mov      ecx, dword ptr [_game]");                        // 0x0056e6d6
    asm("mov.s             esi, eax");                                      // 0x0056e6dc
    asm("call              _jmp_addr_0x00555a10");                          // 0x0056e6de
    asm("cmp.s             eax, esi");                                      // 0x0056e6e3
    asm("pop               esi");                                           // 0x0056e6e5
    asm("{disp8} jne       LAB__addr_0x0056e710");                          // 0x0056e6e6
    asm("{disp32} mov      ecx, dword ptr [_game]");                        // 0x0056e6e8
    asm("call              ?MyInterface@GGame@@QAEPAVGInterface@@XZ");       // 0x0056e6ee
    asm("{disp32} mov      eax, dword ptr [eax + 0x000001bc]");             // 0x0056e6f3
    asm("{disp32} mov      ecx, dword ptr [eax + 0x000001fc]");             // 0x0056e6f9
    asm("test              ecx, ecx");                                      // 0x0056e6ff
    asm("{disp8} je        LAB__addr_0x0056e710");                          // 0x0056e701
    asm("{disp32} mov      ecx, dword ptr [data_bytes + 0x30ab0c]");        // 0x0056e703
    asm("{disp8} mov       dword ptr [ecx + 0x64], 0x00000000");            // 0x0056e709
    asm("LAB__addr_0x0056e710:");
    asm("{disp32} mov      ecx, dword ptr [_game]");                        // 0x0056e710
    asm("{disp32} jmp      _jmp_addr_0x00555400");                          // 0x0056e716
    // Padding nops
    asm(".byte 0x90, 0x90, 0x90, 0x90, 0x90");                              // 0x0056e71b
    // Callback thunk 3 at 0x0056e720: button_1 click -> DialogBoxBase function
    asm("{disp32} jmp      _jmp_addr_0x00513640");                          // 0x0056e720
    asm(".byte 0x90, 0x90, 0x90, 0x90");                                    // 0x0056e725
    asm(".byte 0x90, 0x90, 0x90, 0x90");                                    // 0x0056e729
    asm(".byte 0x90, 0x90, 0x90");                                          // 0x0056e72d
    __builtin_unreachable();
}

// win1.41 0056e730 EndGameBox::Destroy - calls parent destroy and zeroes global
void __fastcall Destroy__10EndGameBoxFv(struct DialogBoxBase* this)
{
    asm volatile (
        "call              ?Destroy@DialogBoxBase@@UAEXXZ\n\t"
        "%{disp32%} mov      dword ptr [data_bytes + 0x34006c], 0x00000000"
        ::: "eax", "ecx", "edx", "memory"
    );
}

// win1.41 0056e740 EndGameBox::InitControls - populates UI text, graph data, visibility
void __fastcall InitControls__10EndGameBoxFv(struct DialogBoxBase* this)
{
    asm("sub               esp, 0x0000080c");                               // 0x0056e740
    asm("push              ebp");                                           // 0x0056e746
    asm("push              esi");                                           // 0x0056e747
    asm("push              edi");                                           // 0x0056e748
    asm("xor.s             ebp, ebp");                                      // 0x0056e749
    asm("mov.s             esi, ecx");                                      // 0x0056e74b
    asm("push              ebp");                                           // 0x0056e74d
    asm("{disp8} mov       dword ptr [esi + 0x10], ebp");                   // 0x0056e74e
    asm("call              _jmp_addr_0x0056e130");                          // 0x0056e751
    asm("{disp8} mov       eax, dword ptr [esi + 0x64]");                   // 0x0056e756
    asm("cmp               eax, 0x03");                                     // 0x0056e759
    asm("mov               edi, 0x00001aba");                               // 0x0056e75c
    asm("{disp8} ja        LAB__addr_0x0056e7af");                          // 0x0056e761
    // Switch via jump table
    asm("jmp               dword ptr [eax*4 + 0x56ea7c]");                  // 0x0056e763
    // Case 0: check flags and player number
    asm("{disp8} mov       al, byte ptr [esi + 0x5c]");                     // 0x0056e76a
    asm("test              al, al");                                        // 0x0056e76d
    asm("{disp8} jne       LAB__addr_0x0056e77d");                          // 0x0056e76f
    asm("{disp8} mov       al, byte ptr [esi + 0x5d]");                     // 0x0056e771
    asm("test              al, al");                                        // 0x0056e774
    asm("mov               edi, 0x00001a68");                               // 0x0056e776
    asm("{disp8} jne       LAB__addr_0x0056e782");                          // 0x0056e77b
    asm("LAB__addr_0x0056e77d:");
    asm("mov               edi, 0x00000dc7");                               // 0x0056e77d
    asm("LAB__addr_0x0056e782:");
    asm("{disp32} mov      ecx, dword ptr [_game]");                        // 0x0056e782
    asm("xor.s             eax, eax");                                      // 0x0056e788
    asm("{disp32} mov      al, byte ptr [ecx + 0x00205a59]");               // 0x0056e78a
    asm("lea               edx, dword ptr [eax + eax * 0x4]");              // 0x0056e790
    asm("lea               edx, dword ptr [eax + edx * 0x8]");              // 0x0056e793
    asm("lea               eax, dword ptr [eax + edx * 0x2]");              // 0x0056e796
    asm("shl               eax, 5");                                        // 0x0056e799
    asm("{disp8} lea       ecx, dword ptr [eax + ecx * 0x1 + 0x18]");       // 0x0056e79c
    asm("call              ?GetPlayerNumber@GPlayer@@QBEEXZ");              // 0x0056e7a0
    asm("cmp               eax, 0x04");                                     // 0x0056e7a5
    asm(".byte             0x72, 0x51");                                    // 0x0056e7a8  jb LAB__addr_0x0056e7fb
    asm("mov               edi, 0x00000dc7");                               // 0x0056e7aa
    // String table lookup
    asm("LAB__addr_0x0056e7af:");
    asm("cmp               edi, dword ptr [data_bytes + 0x351cac]");        // 0x0056e7af
    asm("{disp8} jae       LAB__addr_0x0056e7bf");                          // 0x0056e7b5
    asm("cmp.s             edi, ebp");                                      // 0x0056e7b7
    asm("{disp32} ja       LAB__addr_0x0056e846");                          // 0x0056e7b9
    asm("LAB__addr_0x0056e7bf:");
    asm("{disp32} mov      eax, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e7bf
    asm("{disp32} jmp      LAB__addr_0x0056e852");                          // 0x0056e7c4
    // Case 2: check player alignment
    asm("{disp32} mov      ecx, dword ptr [_game]");                        // 0x0056e7c9
    asm("xor.s             eax, eax");                                      // 0x0056e7cf
    asm("{disp32} mov      al, byte ptr [ecx + 0x00205a59]");               // 0x0056e7d1
    asm("lea               edx, dword ptr [eax + eax * 0x4]");              // 0x0056e7d7
    asm("lea               edx, dword ptr [eax + edx * 0x8]");              // 0x0056e7da
    asm("lea               eax, dword ptr [eax + edx * 0x2]");              // 0x0056e7dd
    asm("shl               eax, 5");                                        // 0x0056e7e0
    asm("cmp               byte ptr [eax + ecx * 0x1 + 0x000000cd], 0x04"); // 0x0056e7e3
    asm("{disp8} jae       LAB__addr_0x0056e809");                          // 0x0056e7eb
    asm("mov               edi, 0x0000108f");                               // 0x0056e7ed
    asm("{disp8} jmp       LAB__addr_0x0056e7af");                          // 0x0056e7f2
    // Case 3:
    asm("mov               edi, 0x00001aba");                               // 0x0056e7f4
    asm("{disp8} jmp       LAB__addr_0x0056e7af");                          // 0x0056e7f9
    // Case 0 continued: version < 0x1a0e
    asm("LAB__addr_0x0056e7fb:");
    asm("cmp               edi, 0x00001a0e");                               // 0x0056e7fb
    asm("{disp8} jne       LAB__addr_0x0056e7af");                          // 0x0056e801
    asm("{disp32} mov      ecx, dword ptr [_game]");                        // 0x0056e803
    asm("LAB__addr_0x0056e809:");
    asm("call              _jmp_addr_0x00555180");                          // 0x0056e809
    asm("cmp               dword ptr [data_bytes + 0x351cac], 0x00001a0e"); // 0x0056e80e
    asm("{disp32} mov      ecx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e818
    asm("{disp8} jbe       LAB__addr_0x0056e826");                          // 0x0056e81e
    asm("add               ecx, 0x000138a8");                               // 0x0056e820
    asm("LAB__addr_0x0056e826:");
    asm("{disp8} mov       edx, dword ptr [ecx + 0x08]");                   // 0x0056e826
    asm("add               eax, 0x000008e4");                               // 0x0056e829
    asm("push              eax");                                           // 0x0056e82e
    asm("{disp8} mov       eax, dword ptr [esi + 0x38]");                   // 0x0056e82f
    asm("push              edx");                                           // 0x0056e832
    asm("add               eax, 0x24");                                     // 0x0056e833
    asm("push              0x00bef0c0");                                    // 0x0056e836
    asm("push              eax");                                           // 0x0056e83b
    asm("call              _swprintf");                                     // 0x0056e83c
    asm("add               esp, 0x10");                                     // 0x0056e841
    asm("{disp8} jmp       LAB__addr_0x0056e865");                          // 0x0056e844
    asm("LAB__addr_0x0056e846:");
    asm("{disp32} mov      edx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e846
    asm("lea               ecx, dword ptr [edi + edi * 0x2]");              // 0x0056e84c
    asm("lea               eax, dword ptr [edx + ecx * 0x4]");              // 0x0056e84f
    asm("LAB__addr_0x0056e852:");
    asm("{disp8} mov       eax, dword ptr [eax + 0x08]");                   // 0x0056e852
    asm("{disp8} mov       ecx, dword ptr [esi + 0x38]");                   // 0x0056e855
    asm("push              eax");                                           // 0x0056e858
    asm("add               ecx, 0x24");                                     // 0x0056e859
    asm("push              ecx");                                           // 0x0056e85c
    asm("call              _wcscpy");                                       // 0x0056e85d
    asm("add               esp, 0x08");                                     // 0x0056e862
    // Status text
    asm("LAB__addr_0x0056e865:");
    asm("{disp8} mov       al, byte ptr [esi + 0x5c]");                     // 0x0056e865
    asm("test              al, al");                                        // 0x0056e868
    asm("{disp32} mov      eax, dword ptr [data_bytes + 0x351cac]");        // 0x0056e86a
    asm("{disp8} je        LAB__addr_0x0056e88d");                          // 0x0056e86f
    asm("cmp               eax, 0x00001abd");                               // 0x0056e871
    asm("{disp8} ja        LAB__addr_0x0056e87f");                          // 0x0056e876
    asm("{disp32} mov      eax, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e878
    asm("{disp8} jmp       LAB__addr_0x0056e8a7");                          // 0x0056e87d
    asm("LAB__addr_0x0056e87f:");
    asm("{disp32} mov      edx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e87f
    asm("{disp32} lea      eax, dword ptr [edx + 0x000140dc]");             // 0x0056e885
    asm("{disp8} jmp       LAB__addr_0x0056e8a7");                          // 0x0056e88b
    asm("LAB__addr_0x0056e88d:");
    asm("cmp               eax, 0x00001ab8");                               // 0x0056e88d
    asm("{disp8} ja        LAB__addr_0x0056e89b");                          // 0x0056e892
    asm("{disp32} mov      eax, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e894
    asm("{disp8} jmp       LAB__addr_0x0056e8a7");                          // 0x0056e899
    asm("LAB__addr_0x0056e89b:");
    asm("{disp32} mov      edx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e89b
    asm("{disp32} lea      eax, dword ptr [edx + 0x000140a0]");             // 0x0056e8a1
    asm("LAB__addr_0x0056e8a7:");
    asm("{disp8} mov       eax, dword ptr [eax + 0x08]");                   // 0x0056e8a7
    asm("{disp8} mov       ecx, dword ptr [esi + 0x3c]");                   // 0x0056e8aa
    asm("push              eax");                                           // 0x0056e8ad
    asm("add               ecx, 0x24");                                     // 0x0056e8ae
    asm("push              ecx");                                           // 0x0056e8b1
    asm("call              _wcscpy");                                       // 0x0056e8b2
    // Mode check and display
    asm("{disp8} mov       eax, dword ptr [esi + 0x64]");                   // 0x0056e8b7
    asm("mov               edi, 0x00000001");                               // 0x0056e8ba
    asm("add               esp, 0x08");                                     // 0x0056e8bf
    asm("cmp.s             eax, edi");                                      // 0x0056e8c2
    asm("{disp8} jne       LAB__addr_0x0056e8da");                          // 0x0056e8c4
    asm("{disp32} mov      ecx, dword ptr [_game]");                        // 0x0056e8c6
    asm("call              _jmp_addr_0x00555880");                          // 0x0056e8cc
    asm("{disp8} mov       ecx, dword ptr [eax + 0x30]");                   // 0x0056e8d1
    asm("push              ebp");                                           // 0x0056e8d4
    asm("call              _jmp_addr_0x0071d0b0");                          // 0x0056e8d5
    // Show/hide controls via vtable calls
    asm("LAB__addr_0x0056e8da:");
    asm("{disp8} mov       ecx, dword ptr [esi + 0x50]");                   // 0x0056e8da
    asm("mov               edx, dword ptr [ecx]");                          // 0x0056e8dd
    asm("push              edi");                                           // 0x0056e8df
    asm("call              dword ptr [edx + 8]");                           // 0x0056e8e0
    asm("{disp8} mov       ecx, dword ptr [esi + 0x54]");                   // 0x0056e8e3
    asm("mov               eax, dword ptr [ecx]");                          // 0x0056e8e6
    asm("push              edi");                                           // 0x0056e8e8
    asm("call              dword ptr [eax + 8]");                           // 0x0056e8e9
    asm("{disp8} mov       ecx, dword ptr [esi + 0x4c]");                   // 0x0056e8ec
    asm("mov               edx, dword ptr [ecx]");                          // 0x0056e8ef
    asm("push              edi");                                           // 0x0056e8f1
    asm("call              dword ptr [edx + 8]");                           // 0x0056e8f2
    asm("{disp8} mov       ecx, dword ptr [esi + 0x34]");                   // 0x0056e8f5
    asm("mov               eax, dword ptr [ecx]");                          // 0x0056e8f8
    asm("push              edi");                                           // 0x0056e8fa
    asm("call              dword ptr [eax + 8]");                           // 0x0056e8fb
    asm("{disp8} mov       ecx, dword ptr [esi + 0x3c]");                   // 0x0056e8fe
    asm("mov               edx, dword ptr [ecx]");                          // 0x0056e901
    asm("push              edi");                                           // 0x0056e903
    asm("call              dword ptr [edx + 8]");                           // 0x0056e904
    asm("{disp8} mov       ecx, dword ptr [esi + 0x44]");                   // 0x0056e907
    asm("mov               eax, dword ptr [ecx]");                          // 0x0056e90a
    asm("push              edi");                                           // 0x0056e90c
    asm("call              dword ptr [eax + 8]");                           // 0x0056e90d
    asm("{disp8} mov       ecx, dword ptr [esi + 0x48]");                   // 0x0056e910
    asm("mov               edx, dword ptr [ecx]");                          // 0x0056e913
    asm("push              edi");                                           // 0x0056e915
    asm("call              dword ptr [edx + 8]");                           // 0x0056e916
    asm("{disp8} mov       ecx, dword ptr [esi + 0x40]");                   // 0x0056e919
    asm("mov               eax, dword ptr [ecx]");                          // 0x0056e91c
    asm("push              ebp");                                           // 0x0056e91e
    asm("call              dword ptr [eax + 8]");                           // 0x0056e91f
    // Call internal update function
    asm("mov.s             ecx, esi");                                      // 0x0056e922
    asm("call              _jmp_addr_0x0056eaf0");                          // 0x0056e924
    asm("{disp32} mov      ecx, dword ptr [_game]");                        // 0x0056e929
    asm("cmp               dword ptr [ecx + 0x000059a8], edi");             // 0x0056e92f
    asm("{disp8} jne       LAB__addr_0x0056e93c");                          // 0x0056e935
    asm("cmp               dword ptr [esi + 0x64], ebp");                   // 0x0056e937
    asm("{disp8} jne       LAB__addr_0x0056e943");                          // 0x0056e93a
    asm("LAB__addr_0x0056e93c:");
    asm("mov.s             ecx, esi");                                      // 0x0056e93c
    asm("call              _jmp_addr_0x0056ea90");                          // 0x0056e93e
    // Check field_0x5e and mode
    asm("LAB__addr_0x0056e943:");
    asm("{disp8} mov       al, byte ptr [esi + 0x5e]");                     // 0x0056e943
    asm("test              al, al");                                        // 0x0056e946
    asm("{disp8} jne       LAB__addr_0x0056e961");                          // 0x0056e948
    asm("cmp               dword ptr [esi + 0x64], ebp");                   // 0x0056e94a
    asm("{disp8} je        LAB__addr_0x0056e961");                          // 0x0056e94d
    asm("{disp32} mov      edx, dword ptr [_game]");                        // 0x0056e94f
    asm("{disp32} mov      ecx, dword ptr [edx + 0x00205b80]");             // 0x0056e955
    asm("call              dword ptr [rdata_bytes + 0x46c]");               // 0x0056e95b
    // Score calculation
    asm("LAB__addr_0x0056e961:");
    asm("{disp32} mov      ecx, dword ptr [_game]");                        // 0x0056e961
    asm("call              _jmp_addr_0x00555a10");                          // 0x0056e967
    asm("{disp32} mov      ecx, dword ptr [data_bytes + 0x30ab0c]");        // 0x0056e96c
    asm("{disp32} mov      eax, dword ptr [eax + 0x000001f4]");             // 0x0056e972
    asm("{disp8} mov       dl, byte ptr [ecx + 0x5c]");                     // 0x0056e978
    asm("dec               eax");                                           // 0x0056e97b
    asm("test              dl, dl");                                        // 0x0056e97c
    asm("{disp8} je        LAB__addr_0x0056e98c");                          // 0x0056e97e
    asm("{disp8} mov       eax, dword ptr [esi + 0x58]");                   // 0x0056e980
    asm("{disp32} fld      dword ptr [ecx + eax * 0x4 + 0x000000ac]");      // 0x0056e983
    asm("{disp8} jmp       LAB__addr_0x0056e996");                          // 0x0056e98a
    asm("LAB__addr_0x0056e98c:");
    asm("{disp8} mov       edx, dword ptr [esi + 0x58]");                   // 0x0056e98c
    asm("lea               eax, dword ptr [eax + edx * 0x4]");              // 0x0056e98f
    asm("{disp8} fld       dword ptr [ecx + eax * 0x4 + 0x6c]");            // 0x0056e992
    // Format score string
    asm("LAB__addr_0x0056e996:");
    asm("cmp               dword ptr [data_bytes + 0x351cac], 0x00001a26"); // 0x0056e996
    asm("{disp8} ja        LAB__addr_0x0056e9a9");                          // 0x0056e9a0
    asm("{disp32} mov      eax, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e9a2
    asm("{disp8} jmp       LAB__addr_0x0056e9b5");                          // 0x0056e9a7
    asm("LAB__addr_0x0056e9a9:");
    asm("{disp32} mov      ecx, dword ptr [data_bytes + 0x351ca8]");        // 0x0056e9a9
    asm("{disp32} lea      eax, dword ptr [ecx + 0x000139c8]");             // 0x0056e9af
    asm("LAB__addr_0x0056e9b5:");
    asm("{disp8} mov       eax, dword ptr [eax + 0x08]");                   // 0x0056e9b5
    asm("sub               esp, 0x08");                                     // 0x0056e9b8
    asm("fstp              qword ptr [esp]");                               // 0x0056e9bb
    asm("push              eax");                                           // 0x0056e9be
    asm("{disp8} lea       edx, dword ptr [esp + 0x20]");                   // 0x0056e9bf
    asm("push              edx");                                           // 0x0056e9c3
    asm("call              dword ptr [__imp___0LHSPrintfW__QAA_PAGZZ@4]");  // 0x0056e9c4
    asm("push              eax");                                           // 0x0056e9ca
    asm("{disp8} mov       eax, dword ptr [esi + 0x34]");                   // 0x0056e9cb
    asm("add               eax, 0x24");                                     // 0x0056e9ce
    asm("push              eax");                                           // 0x0056e9d1
    asm("call              _wcscpy");                                       // 0x0056e9d2
    // Player number check for visibility
    asm("{disp32} mov      ecx, dword ptr [_game]");                        // 0x0056e9d7
    asm("xor.s             eax, eax");                                      // 0x0056e9dd
    asm("{disp32} mov      al, byte ptr [ecx + 0x00205a59]");               // 0x0056e9df
    asm("add               esp, 0x18");                                     // 0x0056e9e5
    asm("lea               edx, dword ptr [eax + eax * 0x4]");              // 0x0056e9e8
    asm("lea               edx, dword ptr [eax + edx * 0x8]");              // 0x0056e9eb
    asm("lea               eax, dword ptr [eax + edx * 0x2]");              // 0x0056e9ee
    asm("shl               eax, 5");                                        // 0x0056e9f1
    asm("{disp8} lea       ecx, dword ptr [eax + ecx * 0x1 + 0x18]");       // 0x0056e9f4
    asm("call              ?GetPlayerNumber@GPlayer@@QBEEXZ");              // 0x0056e9f8
    asm("cmp               eax, 0x04");                                     // 0x0056e9fd
    asm(".byte             0x72, 0x12");                                    // 0x0056ea00  jb LAB__addr_0x0056ea14
    asm("{disp8} mov       ecx, dword ptr [esi + 0x34]");                   // 0x0056ea02
    asm("mov               edx, dword ptr [ecx]");                          // 0x0056ea05
    asm("push              edi");                                           // 0x0056ea07
    asm("call              dword ptr [edx + 8]");                           // 0x0056ea08
    asm("{disp8} mov       ecx, dword ptr [esi + 0x3c]");                   // 0x0056ea0b
    asm("mov               eax, dword ptr [ecx]");                          // 0x0056ea0e
    asm("push              edi");                                           // 0x0056ea10
    asm("call              dword ptr [eax + 8]");                           // 0x0056ea11
    // VBarGraph data population loop
    asm("LAB__addr_0x0056ea14:");
    asm("{disp8} mov       ecx, dword ptr [esi + 0x48]");                   // 0x0056ea14
    asm("mov               edx, dword ptr [ecx]");                          // 0x0056ea17
    asm("call              dword ptr [edx + 0x34]");                        // 0x0056ea19
    asm("{disp8} mov       eax, dword ptr [esi + 0x68]");                   // 0x0056ea1c
    asm("xor.s             edi, edi");                                      // 0x0056ea1f
    asm("cmp               word ptr [eax], bp");                            // 0x0056ea21
    asm("{disp8} jbe       LAB__addr_0x0056ea65");                          // 0x0056ea24
    asm("push              ebx");                                           // 0x0056ea26
    asm("mov               ebx, 0x000000ac");                               // 0x0056ea27
    asm("LAB__addr_0x0056ea2c:");
    asm("{disp8} mov       edx, dword ptr [eax + ebp * 0x1 + 0x04]");       // 0x0056ea2c
    asm("{disp32} mov      ecx, dword ptr [data_bytes + 0x30ab0c]");        // 0x0056ea30
    asm("fld               dword ptr [ebx + ecx * 0x1]");                   // 0x0056ea36
    asm("{disp8} mov       ecx, dword ptr [esi + 0x48]");                   // 0x0056ea39
    asm("{disp8} mov       dword ptr [esp + 0x10], edx");                   // 0x0056ea3c
    asm("{disp8} fstp      dword ptr [esp + 0x14]");                        // 0x0056ea40
    asm("mov               eax, dword ptr [ecx]");                          // 0x0056ea44
    asm("{disp8} lea       edx, dword ptr [esp + 0x10]");                   // 0x0056ea46
    asm("push              edx");                                           // 0x0056ea4a
    asm("call              dword ptr [eax + 0x3c]");                        // 0x0056ea4b
    asm("{disp8} mov       eax, dword ptr [esi + 0x68]");                   // 0x0056ea4e
    asm("xor.s             ecx, ecx");                                      // 0x0056ea51
    asm("mov               cx, word ptr [eax]");                            // 0x0056ea53
    asm("inc               edi");                                           // 0x0056ea56
    asm("add               ebx, 0x04");                                     // 0x0056ea57
    asm("add               ebp, 0x0000114c");                               // 0x0056ea5a
    asm("cmp.s             edi, ecx");                                      // 0x0056ea60
    asm("{disp8} jl        LAB__addr_0x0056ea2c");                          // 0x0056ea62
    asm("pop               ebx");                                           // 0x0056ea64
    // Final VBarGraph vtable call and cleanup
    asm("LAB__addr_0x0056ea65:");
    asm("{disp8} mov       esi, dword ptr [esi + 0x48]");                   // 0x0056ea65
    asm("mov               edx, dword ptr [esi]");                          // 0x0056ea68
    asm("push              0x0");                                           // 0x0056ea6a
    asm("mov.s             ecx, esi");                                      // 0x0056ea6c
    asm("call              dword ptr [edx + 0x38]");                        // 0x0056ea6e
    asm("pop               edi");                                           // 0x0056ea71
    asm("pop               esi");                                           // 0x0056ea72
    asm("pop               ebp");                                           // 0x0056ea73
    asm("add               esp, 0x0000080c");                               // 0x0056ea74
    asm("ret");                                                             // 0x0056ea7a
    // Trailing nop
    asm(".byte 0x90");                                                      // 0x0056ea7b
    // Jump table for switch at 0x0056e763 (4 entries: cases 0-3)
    asm(".byte 0x6a, 0xe7, 0x56, 0x00");                                   // 0x0056ea7c  case 0 -> 0x0056e76a
    asm(".byte 0xf4, 0xe7, 0x56, 0x00");                                   // 0x0056ea80  case 1 -> 0x0056e7f4
    asm(".byte 0xc9, 0xe7, 0x56, 0x00");                                   // 0x0056ea84  case 2 -> 0x0056e7c9
    asm(".byte 0xf4, 0xe7, 0x56, 0x00");                                   // 0x0056ea88  case 3 -> 0x0056e7f4
    // Trailing padding
    asm(".byte 0x90, 0x90, 0x90, 0x90");                                   // 0x0056ea8c
    __builtin_unreachable();
}

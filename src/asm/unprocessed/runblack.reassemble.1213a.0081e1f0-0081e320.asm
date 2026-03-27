.intel_syntax noprefix
.align 16

.extern rdata_bytes
.extern data_bytes
.extern ?GetSizeUV2Data@LH3DMesh@@QAEIXZ
.extern ?GetSizeFootprintData_dup1@LH3DMesh@@QAEIXZ
.extern ?GetSizeNameData_dup1@LH3DMesh@@QAEIXZ
.extern _SetRenderState__10LH3DRenderF18D3DRENDERSTATETYPEUl
.extern _jmp_addr_0x00418a50
.extern @__ct__7LHPointFfff@20
.extern _jmp_addr_0x004427b0
.extern _jmp_addr_0x0044cf90
.extern _jmp_addr_0x0044e9f0
.extern _jmp_addr_0x0045a7d0
.extern _jmp_addr_0x004605f0
.extern _jmp_addr_0x004a1ba0
.extern _jmp_addr_0x004c2b90
.extern _jmp_addr_0x007a1400
.extern  ??3@YAXPAX@Z
.extern _LHFileLength__FPcPUl
.extern _LHLoadData__FPcPvUlPUl
.extern _jmp_addr_0x007bd030
.extern _atexit
.extern _sprintf
.extern _wcsncpy
.extern _wcslen
.extern ??2@YAPAXI@Z
.extern _malloc
.extern _free
.extern _localtime
.extern _time
.extern _jmp_addr_0x007ddc40
.extern _jmp_addr_0x007ded40
.extern _jmp_addr_0x007faaf0
.extern _jmp_addr_0x007fae60
.extern _jmp_addr_0x007faff0
.extern ?SetInverse@LHMatrix@@QAEXAAU1@@Z
.extern _jmp_addr_0x007ff610
.extern _jmp_addr_0x00800c10
.extern _jmp_addr_0x00800d90
.extern _jmp_addr_0x00801870
.extern _jmp_addr_0x00801a70
.extern _jmp_addr_0x00801c90
.extern ?GetAltitude@LH3DIsland@@SAMABULH3DMapCoords@@@Z
.extern ?Create@LH3DIsland@@SAIXZ
.extern _Release__10LH3DIslandFv@0
.extern _jmp_addr_0x00804830
.extern _jmp_addr_0x00804860
.extern ?CreateFromHD@LH3DMesh@@SAPAV1@PBD_N@Z
.extern @Release__8LH3DMeshFv@4
.extern @Create__10LH3DObjectFQ210LH3DObject10ObjectType@4
.extern _jmp_addr_0x00819490
.extern _jmp_addr_0x0081a760
.extern _Report3D__FPCce
.extern _jmp_addr_0x0081c090
.extern _Random__Fff@8
.extern _jmp_addr_0x0082a4f0
.extern _DrawAndClip2D__F16D3DPRIMITIVETYPEUlP8Vertex3DUlPUsUl
.extern _jmp_addr_0x0082a8e0
.extern _jmp_addr_0x0082ab40
.extern @__ct__Q210NewCollide3ObjFfP7LHPoint@16
.extern @__ct__Q210NewCollide3ObjFP7LHPointfff@24
.extern @__dt__Q210NewCollide3ObjFv@4
.extern ?StartFrame@LH3DRender@@SAXXZ
.extern ?RegisterFinishFrameCallback@LH3DRender@@QAEXK_NP6AXPAX@Z1@Z
.extern _jmp_addr_0x0082f3b0
.extern ?FinishFrame@LH3DRender@@QAEXXZ
.extern ?DrawTriangle@LH3DRender@@SAXPAUVertex3D@@KPAGK@Z
.extern _CreateMaterial__10LH3DRenderFQ212LH3DMaterial10RenderModeP11LH3DTexture
.extern ?SetD3DTillingOn@LH3DRender@@SAXH@Z
.extern ?SetD3DTillingOff@LH3DRender@@SAXH@Z
.extern @GetStringWidth__13GatheringTextFPwif@20
.extern @DrawTextRaw__13GatheringTextFPwiffffP9LH3DColoriP9LH3DColorff@52
.extern _jmp_addr_0x008379e0
.extern ?Release@LH3DTexture@@QAEXXZ
.extern _jmp_addr_0x00837df0
.extern _jmp_addr_0x00838af0
.extern _jmp_addr_0x00838eb0
.extern _jmp_addr_0x008398a0
.extern _jmp_addr_0x00839980
.extern _jmp_addr_0x00839bc0
.extern _jmp_addr_0x00839f10
.extern ?SetTransform@LH3DAnim@@SAMPAULHMatrix@@PAULH3DMesh@@AAU2@@Z
.extern ?CreatePack@LH3DAnim@@SAXXZ
.extern _jmp_addr_0x0083f310
.extern ?Create@LH3DSprite@@SAPAV1@JH@Z
.extern ?Release@LH3DSprite@@QAEXXZ
.extern ?Draw@LH3DSprite@@QAEXXZ
.extern _jmp_addr_0x00840c70
.extern _jmp_addr_0x00840cc0
.extern _jmp_addr_0x00841170
.extern _jmp_addr_0x00841260
.extern ?Alloc@LH3DMem@@SAPAXJ@Z
.extern ?Free@LH3DMem@@SAXPAX@Z
.extern _jmp_addr_0x008485e0
.extern _jmp_addr_0x0084ba90
.extern _jmp_addr_0x00856d40
.extern _jmp_addr_0x00858ba0
.extern _jmp_addr_0x00868c80
.extern _jmp_addr_0x0086c220
.extern _jmp_addr_0x008745a0
.extern _jmp_addr_0x008745e0
.extern _jmp_addr_0x00874850
.extern _jmp_addr_0x008786d0
.extern _jmp_addr_0x0087f6d0
.extern _jmp_addr_0x0087f880
.extern _jmp_addr_0x0087f950
.extern _jmp_addr_0x0087fc90
.extern _jmp_addr_0x00883560
.extern _jmp_addr_0x00884100
.extern _jmp_addr_0x00884570

.globl _jmp_addr_0x0081e1f0

start_0x0081e1f0_0x0081e320:
// Snippet: asm, [0x0081e1f0, 0x0081e320)
_jmp_addr_0x0081e1f0:    {disp8} mov        eax, dword ptr [esp + 0x08]                          // 0x0081e1f0    8b442408
                         mov                ecx, dword ptr [eax]                                 // 0x0081e1f4    8b08
                         {disp32} mov       dword ptr [data_bytes + 0x4e3e90], ecx               // 0x0081e1f6    890d909eea00
                         {disp8} mov        edx, dword ptr [eax + 0x04]                          // 0x0081e1fc    8b5004
                         {disp32} mov       dword ptr [data_bytes + 0x4e3e94], edx               // 0x0081e1ff    8915949eea00
                         {disp8} mov        eax, dword ptr [eax + 0x08]                          // 0x0081e205    8b4008
                         push               0x00ec7f58                                           // 0x0081e208    68587fec00
                         {disp32} mov       dword ptr [data_bytes + 0x4e3e98], eax               // 0x0081e20d    a3989eea00
                         {disp32} mov       dword ptr [data_bytes + 0x501f94], eax               // 0x0081e212    a3947fec00
                         {disp32} mov       eax, dword ptr [_Direct3DDevice7]                    // 0x0081e217    a138a6ec00
                         push               0x0                                                  // 0x0081e21c    6a00
                         {disp32} mov       dword ptr [data_bytes + 0x501f8c], ecx               // 0x0081e21e    890d8c7fec00
                         {disp32} mov       dword ptr [data_bytes + 0x501f90], edx               // 0x0081e224    8915907fec00
                         mov                ecx, dword ptr [eax]                                 // 0x0081e22a    8b08
                         push               eax                                                  // 0x0081e22c    50
                         call               dword ptr [ecx + 0x48]                               // 0x0081e22d    ff5148
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e90]                    // 0x0081e230    d905909eea00
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e94]                    // 0x0081e236    d905949eea00
                         {disp32} mov       edx, dword ptr [data_bytes + 0x4e3e90]               // 0x0081e23c    8b15909eea00
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e98]                    // 0x0081e242    d905989eea00
                         {disp32} mov       eax, dword ptr [data_bytes + 0x4e3e94]               // 0x0081e248    a1949eea00
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e58]                    // 0x0081e24d    d905589eea00
                         {disp32} mov       dword ptr [data_bytes + 0x4e3e80], edx               // 0x0081e253    8915809eea00
                         fmul               st, st(1)                                            // 0x0081e259    d8c9
                         {disp32} mov       ecx, dword ptr [data_bytes + 0x4e3e98]               // 0x0081e25b    8b0d989eea00
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e4c]                    // 0x0081e261    d9054c9eea00
                         {disp32} mov       dword ptr [data_bytes + 0x4e3e84], eax               // 0x0081e267    a3849eea00
                         fmul               st, st(3)                                            // 0x0081e26c    d8cb
                         {disp8} mov        eax, dword ptr [esp + 0x04]                          // 0x0081e26e    8b442404
                         {disp32} mov       dword ptr [data_bytes + 0x4e3e88], ecx               // 0x0081e272    890d889eea00
                         faddp              st(1), st                                            // 0x0081e278    dec1
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e40]                    // 0x0081e27a    d905409eea00
                         fmul               st, st(4)                                            // 0x0081e280    d8cc
                         faddp              st(1), st                                            // 0x0081e282    dec1
                         {disp32} fadd      dword ptr [data_bytes + 0x4e3e64]                    // 0x0081e284    d805649eea00
                         {disp32} fstp      dword ptr [data_bytes + 0x4e3e80]                    // 0x0081e28a    d91d809eea00
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e5c]                    // 0x0081e290    d9055c9eea00
                         fmul               st, st(1)                                            // 0x0081e296    d8c9
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e50]                    // 0x0081e298    d905509eea00
                         fmul               st, st(3)                                            // 0x0081e29e    d8cb
                         faddp              st(1), st                                            // 0x0081e2a0    dec1
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e44]                    // 0x0081e2a2    d905449eea00
                         fmul               st, st(4)                                            // 0x0081e2a8    d8cc
                         faddp              st(1), st                                            // 0x0081e2aa    dec1
                         {disp32} fadd      dword ptr [data_bytes + 0x4e3e68]                    // 0x0081e2ac    d805689eea00
                         {disp32} fstp      dword ptr [data_bytes + 0x4e3e84]                    // 0x0081e2b2    d91d849eea00
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e60]                    // 0x0081e2b8    d905609eea00
                         fmul               st, st(1)                                            // 0x0081e2be    d8c9
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e54]                    // 0x0081e2c0    d905549eea00
                         fmul               st, st(3)                                            // 0x0081e2c6    d8cb
                         faddp              st(1), st                                            // 0x0081e2c8    dec1
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e48]                    // 0x0081e2ca    d905489eea00
                         fmul               st, st(4)                                            // 0x0081e2d0    d8cc
                         faddp              st(1), st                                            // 0x0081e2d2    dec1
                         {disp32} fadd      dword ptr [data_bytes + 0x4e3e6c]                    // 0x0081e2d4    d8056c9eea00
                         {disp32} fstp      dword ptr [data_bytes + 0x4e3e88]                    // 0x0081e2da    d91d889eea00
                         fstp               st(0)                                                // 0x0081e2e0    ddd8
                         fstp               st(0)                                                // 0x0081e2e2    ddd8
                         fstp               st(0)                                                // 0x0081e2e4    ddd8
                         {disp32} fld       dword ptr [data_bytes + 0x4e3e90]                    // 0x0081e2e6    d905909eea00
                         fstp               dword ptr [eax]                                      // 0x0081e2ec    d918
                         {disp32} mov       edx, dword ptr [data_bytes + 0x4e3e94]               // 0x0081e2ee    8b15949eea00
                         {disp8} mov        dword ptr [eax + 0x04], edx                          // 0x0081e2f4    895004
                         {disp32} mov       ecx, dword ptr [data_bytes + 0x4e3e98]               // 0x0081e2f7    8b0d989eea00
                         {disp8} mov        dword ptr [eax + 0x08], ecx                          // 0x0081e2fd    894808
                         ret                                                                     // 0x0081e300    c3
                         nop                                                                     // 0x0081e301    90
                         nop                                                                     // 0x0081e302    90
                         nop                                                                     // 0x0081e303    90
                         nop                                                                     // 0x0081e304    90
                         nop                                                                     // 0x0081e305    90
                         nop                                                                     // 0x0081e306    90
                         nop                                                                     // 0x0081e307    90
                         nop                                                                     // 0x0081e308    90
                         nop                                                                     // 0x0081e309    90
                         nop                                                                     // 0x0081e30a    90
                         nop                                                                     // 0x0081e30b    90
                         nop                                                                     // 0x0081e30c    90
                         nop                                                                     // 0x0081e30d    90
                         nop                                                                     // 0x0081e30e    90
                         nop                                                                     // 0x0081e30f    90
                         ret                                                                     // 0x0081e310    c3
                         nop                                                                     // 0x0081e311    90
                         nop                                                                     // 0x0081e312    90
                         nop                                                                     // 0x0081e313    90
                         nop                                                                     // 0x0081e314    90
                         nop                                                                     // 0x0081e315    90
                         nop                                                                     // 0x0081e316    90
                         nop                                                                     // 0x0081e317    90
                         nop                                                                     // 0x0081e318    90
                         nop                                                                     // 0x0081e319    90
                         nop                                                                     // 0x0081e31a    90
                         nop                                                                     // 0x0081e31b    90
                         nop                                                                     // 0x0081e31c    90
                         nop                                                                     // 0x0081e31d    90
                         nop                                                                     // 0x0081e31e    90
                         nop                                                                     // 0x0081e31f    90

.intel_syntax noprefix
.align 16

.extern _fscanf
.extern _fgetc

.globl @Read__7CatInfoFPQ23std5_FILE@12

@Read__7CatInfoFPQ23std5_FILE@12:    push               esi
                         push               edi
                         {disp8} mov        edi, dword ptr [esp + 0x0c]
                         mov.s              esi, ecx
.Lbl_addr_0x004c4978:    push               edi
                         call               _fgetc
                         add                esp, 0x04
                         cmp                al, 0x45
                         {disp8} je         .Lbl_addr_0x004c49a1
                         cmp                al, 0x3d
                         {disp8} je         .Lbl_addr_0x004c49a1
                         cmp                al, 0x2d
                         {disp8} je         .Lbl_addr_0x004c49a1
                         cmp                al, 0x43
                         {disp8} je         .Lbl_addr_0x004c49a1
                         cmp                al, 0x4e
                         {disp8} je         .Lbl_addr_0x004c49a1
                         cmp                al, 0x4c
                         {disp8} je         .Lbl_addr_0x004c49a1
                         cmp                al, 0x57
                         {disp8} je         .Lbl_addr_0x004c49a1
                         cmp                al, 0x44
                         {disp8} jne        .Lbl_addr_0x004c4978
.Lbl_addr_0x004c49a1:    cmp                al, 0x45
                         mov                dword ptr [esi], 0x00000000
                         {disp32} je        .Lbl_addr_0x004c4a77
.Lbl_addr_0x004c49af:    cmp                al, 0x3d
                         {disp32} je        .Lbl_addr_0x004c4a77
                         movsx              eax, al
                         add                eax, -0x43
                         cmp                eax, 0x14
                         {disp8} ja         .Lbl_addr_0x004c4a1c
                         xor.s              ecx, ecx
                         {disp32} mov       cl, byte ptr [eax + 0x004c4a94]
                         jmp                dword ptr [ecx*4 + 0x4c4a7c]
                         mov                edx, dword ptr [esi]
                         {disp32} mov       dword ptr [esi + edx * 0x4 + 0x00000304], 0x00000010
                         {disp8} jmp        .Lbl_addr_0x004c4a29
                         mov                eax, dword ptr [esi]
                         {disp32} mov       dword ptr [esi + eax * 0x4 + 0x00000304], 0x00000001
                         {disp8} jmp        .Lbl_addr_0x004c4a29
                         mov                ecx, dword ptr [esi]
                         {disp32} mov       dword ptr [esi + ecx * 0x4 + 0x00000304], 0x00000002
                         {disp8} jmp        .Lbl_addr_0x004c4a29
                         mov                edx, dword ptr [esi]
                         {disp32} mov       dword ptr [esi + edx * 0x4 + 0x00000304], 0x00000006
                         {disp8} jmp        .Lbl_addr_0x004c4a29
                         mov                eax, dword ptr [esi]
                         {disp32} mov       dword ptr [esi + eax * 0x4 + 0x00000304], 0x00000009
                         {disp8} jmp        .Lbl_addr_0x004c4a29
.Lbl_addr_0x004c4a1c:    mov                ecx, dword ptr [esi]
                         {disp32} mov       dword ptr [esi + ecx * 0x4 + 0x00000304], 0x00000000
.Lbl_addr_0x004c4a29:    mov                edx, dword ptr [esi]
                         shl                edx, 5
                         {disp8} lea        eax, dword ptr [edx + esi * 0x1 + 0x04]
                         push               eax
                         push               0x009c8c40
                         push               edi
                         call               _fscanf
                         mov                eax, dword ptr [esi]
                         add                esp, 0x0c
                         inc                eax
                         mov                dword ptr [esi], eax
.Lbl_addr_0x004c4a46:    push               edi
                         call               _fgetc
                         add                esp, 0x04
                         cmp                al, 0x45
                         {disp8} je         .Lbl_addr_0x004c4a77
                         cmp                al, 0x3d
                         {disp8} je         .Lbl_addr_0x004c4a6f
                         cmp                al, 0x2d
                         {disp8} je         .Lbl_addr_0x004c4a6f
                         cmp                al, 0x43
                         {disp8} je         .Lbl_addr_0x004c4a6f
                         cmp                al, 0x4e
                         {disp8} je         .Lbl_addr_0x004c4a6f
                         cmp                al, 0x4c
                         {disp8} je         .Lbl_addr_0x004c4a6f
                         cmp                al, 0x57
                         {disp8} je         .Lbl_addr_0x004c4a6f
                         cmp                al, 0x44
                         {disp8} jne        .Lbl_addr_0x004c4a46
.Lbl_addr_0x004c4a6f:    cmp                al, 0x45
                         {disp32} jne       .Lbl_addr_0x004c49af
.Lbl_addr_0x004c4a77:    pop                edi
                         pop                esi
                         ret                0x0004

// Snippet: jmptbl, [0x004c4a7c, 0x004c4a94)
.byte 0xe0, 0x49, 0x4c, 0x00
.byte 0xd1, 0x49, 0x4c, 0x00
.byte 0xfe, 0x49, 0x4c, 0x00
.byte 0xef, 0x49, 0x4c, 0x00
.byte 0x0d, 0x4a, 0x4c, 0x00
.byte 0x1c, 0x4a, 0x4c, 0x00

// Snippet: ijmptbl, [0x004c4a94, 0x004c4aa9)
.byte 0x00, 0x01, 0x05, 0x05
.byte 0x05, 0x05, 0x05, 0x05
.byte 0x05, 0x02, 0x05, 0x03
.byte 0x05, 0x05, 0x05, 0x05
.byte 0x05, 0x05, 0x05, 0x05
.byte 0x04

// Snippet: db, [0x004c4aa9, 0x004c4ab0)
.byte 0x90, 0x90, 0x90, 0x90
.byte 0x90, 0x90, 0x90

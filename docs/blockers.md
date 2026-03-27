# CRT Guard Pattern - Must Stay as ASM Volatile

## Background

MSVC 6.0 static initializer guards use this exact byte sequence (40 instances across 27 files):

```
8a 0d xx xx xx xx    mov cl, byte ptr [guard]     ; load guard byte into CL
b0 01                mov al, 0x01                 ; constant 1 into AL
84 c8                test al, cl                  ; check guard & 1
75 xx                jne skip                     ; already initialized
0a c8                or.s cl, al                  ; set guard bit (reversed OR)
88 0d xx xx xx xx    mov byte ptr [guard], cl     ; store back
                     skip:
e9 xx xx xx xx       jmp register_atexit          ; unconditional tail jump
```

The equivalent C would be:
```c
static char guard;
if (!(guard & 1)) { guard |= 1; /* init code */ }
```

## Investigation Summary

Tested with `register char g asm("cl")` and `register char one asm("al")` constraints,
volatile memory access, and `-Os` optimization. The closest achievable C output:

```
8a 0d xx xx xx xx    mov cl, byte ptr [guard]     -- MATCH
b0 01                mov al, 0x01                 -- MATCH
84 c1                test cl, al                  -- WRONG ModR/M (c1 vs c8)
0f 85 xx xx xx xx    jne external_target          -- WRONG (near jne to tail call, not short jne to local skip)
08 c1                or cl, al                    -- fixable via X86ReversedOps pass
88 0d xx xx xx xx    mov byte ptr [guard], cl     -- MATCH
e9 xx xx xx xx       jmp external_target          -- second jmp (tail duplication)
```

## Three Unfixable Issues

### 1. Branch Structure / Tail Call Duplication

LLVM's branch folding transforms:
```
jne local_skip       ; 75 xx (2 bytes)
<guard set code>
local_skip:
jmp target           ; e9 xx xx xx xx (5 bytes)
```
into:
```
jne target           ; 0f 85 xx xx xx xx (6 bytes)
<guard set code>
jmp target           ; e9 xx xx xx xx (5 bytes)
```

The compiler threads the branch through the skip label directly to the tail call target.
This changes both the branch encoding (short vs near) and produces two jumps to the
same external target instead of one. No per-function attribute can suppress this -
it is a fundamental part of LLVM's block placement and branch folding pipeline.

### 2. TEST Operand Order (ModR/M Encoding)

`test al, cl` and `test cl, al` are semantically identical (TEST is commutative) but
produce different ModR/M bytes:
- MSVC:  `84 C8` (reg=CL, rm=AL)
- Clang: `84 C1` (reg=AL, rm=CL)

Unlike ADD/OR/SUB which have `_REV` instruction variants, TEST has only one opcode (0x84).
The operand order in the ModR/M byte is determined by instruction selection and there is
no existing pass to swap it. Building a pass for this would be possible but fragile -
it would need to detect the specific guard pattern context to know when to swap.

### 3. no_ret Function Shape

The guard functions use `__attribute__((no_ret))` - they have no return instruction and
no epilogue. The entire function body is the guard check followed by an unconditional
`jmp` to the atexit registrar. A C function cannot naturally produce this shape because:
- The compiler always generates a return path (even with `__builtin_unreachable()`)
- Tail call optimization interacts with branch folding to produce the wrong structure
- The `noreturn` attribute changes the tail call into a `call` instead of `jmp`

## Conclusion

The CRT guard pattern must remain as `asm volatile` blocks. The three issues above are
architectural constraints of LLVM's code generation pipeline that cannot be resolved
through attributes or additional machine-level passes without extremely invasive changes.

The existing asm volatile approach works correctly and produces byte-exact output.
The ~40 instances across 27 files are a small, well-understood set that does not
benefit from conversion to C.

## Existing Pass Coverage (for reference)

If the structural issues could be resolved, these encoding details ARE handled:
- `or.s cl, al` (reversed OR, opcode 0x0A): `X86ReversedOps` pass with `msvc6_regalloc`
- `{disp32}` on memory operands: assembler prefix support
- `mov cl, byte ptr` (no zero-extend): `X86SuppressMovzx` pass strips the XOR
- Register assignment (CL/AL): achievable via `register char asm("cl")` constraints

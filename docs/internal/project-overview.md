# bw1-decomp Project Overview

## What This Project Is

bw1-decomp is a byte-exact decompilation of Black & White (2001). The goal is to recompile the game from source and produce a binary identical to the original `runblack.exe`, byte for byte.

Target MD5: `174b1a64e74b2321f3c38ccc8a511e78`

The original was compiled with MSVC 6.0 (1998), a compiler too old for modern build systems. The project uses a multi-compiler pipeline to reconstruct the binary:

- **C files** (75 files, ~64K lines) -- compiled by a custom Clang/LLVM fork
- **C++ staging files** (409 files) -- compiled by MSVC 12.0 via `cl_wrapper.py`
- **ASM files** (367 files) -- assembled directly (original binary code, not yet decompiled)

The decompilation pipeline is: **ASM -> staging C++ (MSVC 12.0) -> C (custom Clang)**

---

## The Two Forks

### 1. LLVM Fork (`llvm-project/`)

A fork of LLVM 20 (Clang + lld) with custom X86 passes and attributes that make Clang produce byte-identical output to MSVC 6.0. The two compilers make fundamentally different code generation choices -- these attributes bridge the gap.

#### Encoding Mismatch Attributes

These are X86 MachineFunctionPasses that run in `addPreEmitPass()` and transform the compiler's instruction selection to match MSVC 6.0 patterns:

| Attribute | Encoding Mismatch | What the pass does |
|-----------|------------------|--------------------|
| `expand_movzx` | `movzx eax,[mem]` vs `xor eax,eax; mov al,[mem]` | Expands MOVZX into two-instruction sequence |
| `prefer_xor8` | `xor eax,eax` (32-bit) vs `xor al,al` (8-bit) | Converts self-xor to 8-bit form |
| `suppress_fp_imm` | `fldz`/`fld1` vs constant pool load | Replaces FP immediates with memory loads |
| `prefer_or_minus_one` | `mov eax,-1` vs `or eax,-1` | Uses OR to set all bits |
| `prefer_inc_dec_byte` | load-modify-store vs `inc/dec [mem]` | Uses byte-level INC/DEC |
| `no_test_sete_fold` | `test+sete` vs `not+shr+and` | Prevents LLVM's test-sete folding |
| `prefer_neg_sbb` | `xor+test+sete` vs `neg+sbb+inc` | Boolean NOT via NEG/SBB/INC |
| `prefer_sete_ecx` | `sete al` vs `sete cl` | Routes set-equal through ECX |
| `prefer_fmul_mem` | `fld+fmulp` vs `fmul [mem]` | Memory-form FPU multiply |
| `prefer_pop_cleanup` | `add esp,4` vs `pop ecx` | Stack cleanup via POP |
| `no_bool_mask` | LLVM adds `and al,1` | Suppresses bool return narrowing |
| `MOV32rr_REV` | Opcode `89` vs `8b` | Uses reversed MOV encoding |
| `XOR32rr_REV` | Opcode `31` vs `33` | Uses reversed XOR encoding |

#### Frame Lowering Attributes

These control function prologues and epilogues (push/pop sequences, stack allocation, ret instructions):

| Attribute | Purpose |
|-----------|---------|
| `no_callee_saves` | Suppresses entire prologue/epilogue (no push, pop, sub esp) |
| `forced_callee_saves` | Controls exact register push/pop sequence and order |
| `no_ret` | Suppresses the compiler-generated `ret` instruction entirely |
| `ret_cleanup_override` | Forces a specific `ret N` value regardless of calling convention |

#### Code Emission Attributes

These emit specific byte patterns at function boundaries:

| Attribute | Purpose |
|-----------|---------|
| `trailing_bytes` | Emits raw bytes after function body (for dead code without relocations) |
| `trailing_asm` | Emits assembly after function body via MC layer (handles relocations) |
| `msvc6_sdtor` | Emits complete MSVC 6.0 scalar deleting destructor body |

#### Assembler/Linker Extensions

| Feature | Purpose |
|---------|---------|
| `.no_pad` directive | Sets `IMAGE_SCN_TYPE_NO_PAD` COFF section flag |
| lld PE header flags | `--linkerversion`, `--sizeofcode`, `--dllcharacteristicsvalue`, `--baseofdata` |

### 2. Game Source (`bw1-decomp/`)

The decompiled game source. Key directories:

```
src/c/              -- 75 C source files (compiled by custom Clang)
src/staging/        -- 409 C++ stubs (compiled by MSVC 12.0)
src/asm/unprocessed/ -- 367 ASM files (assembled directly)
black/              -- Headers with struct layouts + asm("?MSVC_mangled") labels
libs/               -- Utility libraries (reversing_utils, zlib)
scripts/            -- Build scripts, analysis tools, decompilation aids
```

---

## How Functions Are Structured

Every function in the C source files falls into one of these patterns:

### Pure C (no inline asm)
```c
float __fastcall GetScale__6ObjectFv(struct GameThingWithPos* this)
{
    return ((struct Object*)this)->scale;
}
```
The compiler generates everything. These functions match MSVC 6.0 output using the encoding attributes listed above.

### C-wrapper with asm body (no_callee_saves)
```c
__attribute__((no_callee_saves))
int __fastcall GetDetailMesh__8VillagerFi(struct Object* this, const void* edx, int param_1)
{
    int result;
    asm volatile (
        "{disp8} mov eax, dword ptr [ecx + 0x28]\n\t"
        "{disp8} mov ecx, dword ptr [esp + 0x04]\n\t"
        "{disp32} mov eax, dword ptr [eax + ecx * 0x4 + 0x00000210]"
        : "=a"(result) : "c"(this) : "edx", "memory"
    );
    return result;
}
```
The asm controls the instruction sequence (for byte-exact matching), but the compiler generates the `ret N` from `return result;`. The `no_callee_saves` attribute prevents the compiler from adding its own prologue/epilogue.

### Jmp-ending functions (no_ret)
```c
__attribute__((no_ret))
bool __fastcall IsReachable__6ObjectFv(struct Object* this)
{
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "{disp8} jmp dword ptr [eax + 0x2c]"
        :: "c"(this) : "eax", "edx", "memory"
    );
    __builtin_unreachable();
}
```
The function ends with `jmp` (not `ret`). `no_ret` prevents the compiler from adding a `ret` instruction. `__builtin_unreachable()` prevents dead return-value code.

### Trailing dead code (trailing_asm)
```c
__attribute__((no_callee_saves, trailing_asm("call dword ptr [__imp__DirectDrawCreate@4]")))
void __fastcall SetJustScale__6ObjectFf(struct Object* this, const void* edx, float scale)
{
    asm volatile (
        "{disp8} mov eax, dword ptr [esp + 0x04]\n\t"
        "{disp8} mov dword ptr [ecx + 0x50], eax"
        :: "c"(this) : "eax", "edx", "memory"
    );
}
```
Dead code after `ret` (never executed, but must exist for byte-exact matching) is emitted via the `trailing_asm` attribute.

### Musttail thunks (opaque linker aliases)
```c
void __fastcall DeleteDependancys__5AbodeFv(struct Abode* this)
{
    extern void __fastcall __thunk_target_DeleteDependancys(struct Abode*)
        asm("__thunk_target_DeleteDependancys");
    __attribute__((musttail)) return __thunk_target_DeleteDependancys(this);
}
```
With linker flag: `/alternatename:__thunk_target_DeleteDependancys=?RemoveAllVillagersFromAbode@Abode@@QAEXXZ`

The opaque local extern prevents Clang from reordering functions (which it does when it sees a direct call to a forward-declared function in the same TU).

---

## Key Type Conventions

### `bool32_t`

`typedef uint32_t bool32_t;` (defined in `re_common.h`)

MSVC 6.0 returns "booleans" as `unsigned int` (mangled as `I`). If C code declares the return as `bool`, Clang adds `test eax, eax; setne al` to narrow to a proper `bool`. Using `bool32_t` avoids this narrowing, matching the original codegen.

Rule: if MSVC mangling has `I` but C says `bool`, change to `bool32_t`.

### `__fastcall` calling convention

All member functions use `__fastcall`:
- `this` in ECX (first parameter)
- `edx` as dummy (second parameter, unused)
- Additional parameters on the stack
- Callee cleans stack parameters via `ret N`

### asm labels

Function declarations in headers use `asm("?MSVC_mangled_name")` to map C function names to MSVC-mangled linker symbols:
```c
void __fastcall RemoveAllVillagersFromAbode__5AbodeFv(struct Abode* this)
    asm("?RemoveAllVillagersFromAbode@Abode@@QAEXXZ");
```

### rdata constants

Named float constants defined as C globals:
```c
const float rdata_float0p0 = 0.0f;  // [0x1398]
```

Unnamed rdata constants referenced via `.set` aliases in `rdata.000.dllimports.asm`:
```asm
.set _rdata_const_0x3400, rdata_bytes + 0x3400
.globl _rdata_const_0x3400
```
Used from C as:
```c
extern const float __opaque_name asm("_rdata_const_0x3400");
```

---

## Current State (as of 2026-03-19)

### What's done
- All 825 functions in C files have LLVM attributes controlling codegen
- 765 use `no_callee_saves` (compiler generates `ret`)
- 60 use `no_ret` (compiler generates nothing, asm provides terminator)
- 58 rdata constant labels created
- 3 jmp_thunks converted via musttail
- Binary matches MD5 exactly

### Three layers of decompilation progress
1. **ASM files -> C files**: Done for ~825 functions. ~367 ASM files remain with functions not yet in C.
2. **C functions with asm ret -> compiler-controlled ret**: Done (this session). All 825 functions.
3. **C functions with asm body -> pure C**: Next phase. Requires matching MSVC 6.0 instruction selection per-function.

### What's left

**Near-term: Convert asm bodies to pure C**
The 825 functions still have inline asm for their instruction bodies. Converting to pure C requires the compiler to generate identical instruction sequences. Difficulty varies:
- LOW: ~15 functions (field getters, simple returns)
- LOW-MEDIUM: ~31 (vtable dispatch, neg/sbb patterns)
- MEDIUM: ~332 (bitfields, FPU, struct copies)
- HIGH+: ~663 (complex logic, large functions)

**Medium-term: Eliminate staging C++ files**
409 staging `.cpp` files compiled by MSVC 12.0. Each class must be decompiled from C++ to C. When all are converted, MSVC 12.0 and its tooling can be dropped entirely.

**Long-term: Convert remaining ASM files**
367 ASM files contain functions not yet decompiled. These are the bulk of the game -- potentially thousands of functions.

---

## Build Commands

```bash
# Byte-exact release build (verifies MD5)
cmake --workflow --preset release

# Debug build (for Ghidra, IDA Pro, live debugging)
cmake --workflow --preset relwithdebinfo

# Rebuild LLVM fork (after modifying attributes/passes)
cd llvm-project/build && ninja -j$(nproc) install
```

## Verification

The build automatically prints the MD5 checksum. Expected:
```
174b1a64e74b2321f3c38ccc8a511e78  runblack-reassembled.exe
```

Every change must be verified against this hash. If it doesn't match, revert immediately.

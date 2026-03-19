# objdiff.py

Byte-level diff tool for comparing compiled C functions against the original binary. When an MD5 mismatch occurs after writing a C replacement for an ASM function, objdiff shows exactly which instruction bytes differ and suggests which `__attribute__` to add.

Located at `bw1-decomp/scripts/decompilation/objdiff.py`.

## When to Use

**After step 4 of the decompilation workflow** — you wrote the C function, built, and MD5 doesn't match. objdiff is the diagnostic step before you start guessing at attributes.

```
1. Pick function from ASM        (classifier/find_decompilable)
2. Write C equivalent            (decision_flowchart.md)
3. Build                         (cmake --workflow --preset release)
4. MD5 matches? -> done
5. MD5 doesn't match? -> objdiff <-- YOU ARE HERE
6. Apply suggested attributes
7. Rebuild -> goto 4
```

Also use batch mode to check progress on an entire C file before/after a session.

## Usage

### Single function diff

```bash
python3 scripts/decompilation/objdiff.py src/c/Object.000.c "?StandAnimation@Object@@UAEIXZ"
```

The symbol is the MSVC-mangled name from `.globl` directives in ASM files or `asm("?Name@Class@@...")` labels in `black/*.h` headers.

### Batch mode (all functions in a file)

```bash
python3 scripts/decompilation/objdiff.py src/c/Object.000.c
```

Prints a one-line summary per function: MATCH, MISMATCH, or NO_REF.

## Reading the Output

### Single function diff

```
objdiff: ?IsBallFree@Ball@@QAE_NXZ
============================================================
Compiled: 14 bytes (5 instructions)
Expected: 12 bytes (4 instructions)

  >> Expected: 33 c0                          xor eax, eax
  >> Got:      0f b6 41 08                    movzx eax, byte ptr [ecx + 8]
     -> TRY: expand_movzx — expected xor (33)+mov, got movzx (0F B6)

  -- Expected: 8a 41 08                       mov al, [ecx + 8]
  -- Got:      (gap)

     Expected: c3                             ret
     Got:      c3                             ret

  Function-level suggestions:
     -> TRY: expand_movzx — compiled has 1 movzx (0F B6), expected has 0

  Suggested attributes:
    __attribute__((expand_movzx))
```

| Marker | Meaning |
|--------|---------|
| `  ` (spaces) | Instructions match (relocations automatically masked) |
| `>>` | Instructions differ — check the `-> TRY:` suggestions |
| `--` | Instruction exists in expected but not in compiled (gap) |
| `++` | Instruction exists in compiled but not in expected (gap) |

The diff uses Needleman-Wunsch alignment, so extra/missing instructions appear as gaps at the correct position rather than offsetting everything after them.

### Relocation masking

The compiled `.o` file has unresolved relocations — call targets show as `e8 00 00 00 00` and data references show section-relative offsets instead of final virtual addresses. objdiff automatically detects these by parsing `llvm-objdump -dr` relocation entries and masks them during comparison.

Relocation bytes display as `xx` in the output:

```
     Expected: e8 5b 4e fa ff                 call ?Destroy@DialogBoxBase@@UAEXXZ
     Got:      e8 xx xx xx xx                 calll 0x605
```

This means the `call` opcode byte matches (`e8`) and the 4-byte displacement is a linker relocation — not a real mismatch. Only non-relocation byte differences show as `>>`.

### Batch mode

```
objdiff batch: src/c/EndGameBox.c (4 functions)
==============================================================================
  _jmp_addr_0x0056e130                                     MATCH        47 bytes
  ?Init@EndGameBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupCo...  MISMATCH   1231 vs 1341 bytes
  ?Destroy@EndGameBox@@UAEXXZ                              MISMATCH      6 vs 16 bytes
  ?InitControls@EndGameBox@@UAEXXZ                         MISMATCH    807 vs 827 bytes
==============================================================================
Summary: 1 MATCH, 3 MISMATCH, 0 NO_REF (4 total)
```

| Status | Meaning |
|--------|---------|
| MATCH | Compiled bytes identical to original (relocations masked) — this function is done |
| MISMATCH | Bytes differ — run single-function mode for details. Note: functions using `trailing_asm` or `trailing_bytes` will show as MISMATCH due to extra bytes in the ASM reference that don't appear in the `.o` file (they're emitted at link time). Use single-function mode to verify whether the mismatch is real. |
| NO_REF | No ASM reference found (function already fully lifted, or new) |

## What It Detects

objdiff has three suggestion layers, covering all custom LLVM attributes:

### Per-instruction: opcode pairs

Detects reversed ModR/M encodings (MSVC uses the opposite register direction):

| Expected | Got | Suggestion |
|----------|-----|-----------|
| `03` (ADD) | `01` | `msvc6_regalloc` |
| `0B` (OR) | `09` | `msvc6_regalloc` |
| `33` (XOR) | `31` | `XOR32rr_REV` |
| `8B` (MOV) | `89` | `MOV32rr_REV` |
| `32` (xor al) | `33` (xor eax) | `prefer_xor8` |

### Per-instruction: byte patterns

Detects multi-byte instruction differences:

| Expected | Got | Suggestion |
|----------|-----|-----------|
| `83 C8 FF` (or eax,-1) | `B8 FF FF FF FF` (mov eax,-1) | `prefer_or_minus_one` |
| `59` (pop ecx) | `83 C4 04` (add esp,4) | `prefer_pop_cleanup` |
| `D9 EE` (fldz) | `D9 05 xx` (fld [mem]) | `suppress_fp_imm` |
| xor (33/32) | `0F B6` (movzx) | `expand_movzx` |
| `0F 94 C1` (sete cl) | `0F 94 C0` (sete al) | `prefer_sete_ecx` |
| `F7 D8` (neg eax) | `33` (xor) | `prefer_neg_sbb` |
| `F6 D0` (not al) | `A8` (test al,imm) | `no_test_sete_fold` |
| any | `24 01` (and al,1) | `no_bool_mask` |
| any | `DE C9` (fmulp) | `prefer_fmul_mem` |
| `FE` (inc/dec byte) | `0F B6` (movzx) | `prefer_inc_dec_byte` |

### Function-level: prologue/epilogue/counts

Detects structural differences across the whole function:

| Pattern | Suggestion |
|---------|-----------|
| Compiled has push esi/edi/ebx, expected doesn't | `no_callee_saves` |
| Both have pushes but different registers | `forced_callee_saves` |
| Compiled ends with ret, expected doesn't | `no_ret` |
| Both end with `ret N` but different N | `ret_cleanup_override` |
| More `movzx` (0F B6) in compiled than expected | `expand_movzx` |
| `fmulp` (DE C9) in compiled but not expected | `prefer_fmul_mem` |
| `inc/dec byte` (FE) in expected but not compiled | `prefer_inc_dec_byte` |

### Not auto-detectable

These attributes cannot be suggested by byte comparison and must be applied manually:

| Attribute | Why |
|-----------|-----|
| `trailing_bytes` | Raw bytes after ret are outside the function body comparison |
| `trailing_asm` | Assembly with relocations after function body |
| `msvc6_sdtor` | Replaces the entire function with a scalar deleting destructor |

## How It Works

1. **Compiled bytes**: Extracted from the `.o` file via `llvm-objdump -dr` (disassembly with relocations)
2. **Relocation masking**: `IMAGE_REL_I386_REL32` (call targets) and `IMAGE_REL_I386_DIR32` (data addresses) entries are parsed. The 4 bytes at each relocation offset are marked as "don't care" and displayed as `xx`. This eliminates false mismatches from unresolved linker relocations.
3. **Expected bytes**: Read from `src/asm/unprocessed/*.asm` files (the `// 0xADDRESS HEXBYTES` comments on each instruction line). These contain final linked addresses.
4. **Symbol index**: On first use, all 367 ASM files are scanned once to build a symbol-to-file index (~15K symbols, ~1.3s). Subsequent lookups are instant.
5. **Alignment**: Needleman-Wunsch sequence alignment on instruction byte tuples (match=+2, mismatch=-1, gap=-2). The scoring uses relocation-aware comparison so that instructions differing only in relocation bytes are treated as matches. Falls back to simple index alignment for functions >500 instructions.
6. **Suggestions**: Three layers checked in order — opcode pairs, byte patterns, then function-level analysis.

## Typical Workflow Example

```bash
# 1. Write C function for Ball::IsBallFree
# 2. Build
cmake --workflow --preset release

# 3. MD5 doesn't match. What's wrong?
python3 scripts/decompilation/objdiff.py src/c/Ball.000.c "?IsBallFree@Ball@@QAE_NXZ"

# Output says: expand_movzx, no_bool_mask
# 4. Add attributes:
#   __attribute__((expand_movzx, no_bool_mask))
#   bool32_t __thiscall Ball_IsBallFree(struct Ball* this) { ... }

# 5. Rebuild and verify
cmake --workflow --preset release
md5sum cmake-build-presets/release/runblack-reassembled.exe
```

```bash
# Check progress on an entire file
python3 scripts/decompilation/objdiff.py src/c/Ball.000.c
# Summary: 12 MATCH, 3 MISMATCH, 2 NO_REF (17 total)
```

## Tests

```bash
cd bw1-decomp/scripts/decompilation
python3 -m unittest test_objdiff -v
# 55 tests covering: opcode suggestions, pattern suggestions,
# function-level suggestions, alignment, symbol index, and relocation masking
```

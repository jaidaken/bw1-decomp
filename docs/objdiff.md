# objdiff.py — Byte-Level Function Diff Tool

## When to Use

Step 5 of the decompilation workflow: **your MD5 doesn't match after writing a C replacement**.

```
1. Pick function from classifier → 2. Read asm → 3. Write C → 4. Build
→ 5. MD5 mismatch? → RUN OBJDIFF → 6. Apply suggested attributes → repeat
```

Do NOT use objdiff preemptively. Build first, check MD5. Only run objdiff when
something is wrong and you need to know exactly what.

## Usage

### Single Function

```bash
python3 scripts/decompilation/objdiff.py src/c/Object.000.c "?StandAnimation@Object@@UAEIXZ"
```

The symbol is the MSVC-mangled name. Find it in:
- `.globl` directives in `src/asm/unprocessed/*.asm`
- `asm("?Name@Class@@...")` labels in `black/*.h` headers

### Batch Mode

```bash
python3 scripts/decompilation/objdiff.py src/c/Object.000.c
```

Diffs ALL functions in the file that have both a compiled object and an ASM reference.
Reports match/mismatch counts and lists suggested attributes for each mismatch.

## Reading the Output

```
objdiff: ?GetRoomLeftForAdults@Abode@@QAEHXZ
============================================================
Compiled: 13 bytes (5 instructions)
Expected: 14 bytes (5 instructions)

  MISMATCH — 13 compiled vs 14 expected bytes

     Expected: 8b 41 28                       mov eax, dword ptr [ecx + 0x28]
     Got:      8b 41 28                       movl 0x28(%ecx), %eax

  >> Expected: 8b 80 74 01 00 00              mov eax, dword ptr [eax + 0x00000174]
  >> Got:      8b 80 74 01 00 00              movl 0x174(%eax), %eax

  >> Expected: 33 d2                          xor.s edx, edx
  >> Got:      0f b6 89 b4 00 00 00           movzbl 0xb4(%ecx), %ecx
     -> TRY: expand_movzx (xor+mov vs movzx)

  >> Expected: 8a 91 b4 00 00 00              mov dl, byte ptr [ecx + 0x000000b4]
  >> Got:      2b c1                          subl %ecx, %eax

  >> Expected: 2b c2                          sub.s eax, edx
  >> Got:      (missing)
     -> TRY: msvc6_regalloc — reversed SUB (2B vs 29)
```

### Markers

| Marker | Meaning |
|--------|---------|
| `  ` (blank) | Bytes match exactly |
| `>>` | Bytes differ — check the `-> TRY:` suggestion |
| `--` | Expected instruction exists but compiled output is missing (compiled is shorter) |
| `++` | Compiled has extra instruction not in expected (compiled is longer) |

### Alignment

The tool compares instruction-by-instruction. If the compiler generates a different
NUMBER of instructions (e.g., `movzx` = 1 instruction vs `xor+mov` = 2 instructions),
subsequent lines will misalign. The Needleman-Wunsch alignment algorithm handles this
by inserting gaps.

## Attribute Suggestion Table

### Layer 1: Opcode Byte Suggestions

Triggered when the first byte of an instruction differs. These are single-opcode
differences between MSVC 6.0 and LLVM encodings.

| Expected | Got | Attribute | Encoding Difference |
|----------|-----|-----------|-------------------|
| `03` | `01` | `msvc6_regalloc` | Reversed ADD (MRMSrcReg vs MRMDestReg) |
| `0B` | `09` | `msvc6_regalloc` | Reversed OR |
| `13` | `11` | `msvc6_regalloc` | Reversed ADC |
| `1B` | `19` | `msvc6_regalloc` | Reversed SBB |
| `23` | `21` | `msvc6_regalloc` | Reversed AND |
| `2B` | `29` | `msvc6_regalloc` | Reversed SUB |
| `33` | `31` | `XOR32rr_REV` | Reversed XOR |
| `3B` | `39` | `msvc6_regalloc` | Reversed CMP |
| `8B` | `89` | `MOV32rr_REV` | Reversed MOV |

These also detect the reverse direction (got REV when expected canonical).

### Layer 2: Multi-Byte Pattern Suggestions

Triggered when a specific byte sequence matches a known MSVC 6.0 idiom.

| Expected Pattern | Got Pattern | Attribute |
|-----------------|-------------|-----------|
| `83 C8 FF` (or eax,-1) | `B8 FF FF FF FF` (mov eax,-1) | `prefer_or_minus_one` |
| `59` (pop ecx) | `83 C4 04` (add esp,4) | `prefer_pop_cleanup` |
| `D9 EE` (fldz) | any | `suppress_fp_imm` |
| `D9 E8` (fld1) | any | `suppress_fp_imm` |

### Layer 3: Instruction Sequence Suggestions

Triggered when a sequence of opcodes matches a known pattern transformation.

| Expected Sequence | Got Sequence | Attribute |
|-------------------|-------------|-----------|
| `xor reg,reg` + `mov r8,[mem]` | `movzx reg,[mem]` | `expand_movzx` |
| `neg` + `sbb` + `inc` | `xor` + `test` + `sete` | `prefer_neg_sbb` |
| `fcomp` + `fnstsw` + `test ah` | `fucompp` + `fnstsw` + `sahf` | `prefer_fcomp_fnstsw` (NOT YET IMPLEMENTED) |
| `inc byte [mem]` | `movzx` + `add` + `mov` | `prefer_inc_dec_byte` |

## Attributes NOT Auto-Detected

These attributes affect codegen but their effect isn't detectable from a simple
byte diff because they change structural properties, not specific byte patterns:

| Attribute | Why Not Detectable |
|-----------|-------------------|
| `no_callee_saves` | Changes prologue/epilogue, not body instructions |
| `forced_callee_saves` | Changes push/pop sequence, context-dependent |
| `no_ret` | Removes ret instruction entirely |
| `ret_cleanup_override(N)` | Changes ret operand, could be many causes |
| `trailing_asm("...")` | Dead code after ret, not a byte mismatch |
| `trailing_bytes("...")` | Same — structural, not byte-level |
| `no_bool_mask` | Removes `and al,1` — detectable but context-dependent |
| `msvc6_sdtor("...")` | Generates entire function body |
| `no_test_sete_fold` | Multiple possible rewrites |
| `prefer_sete_ecx` | Register choice, not opcode |
| `prefer_fmul_mem` | Instruction count change |

## How It Works Internally

### 1. Symbol Lookup

Given a MSVC-mangled symbol name, the tool searches:
- **Compiled bytes**: Runs `llvm-objdump -d` on the object file in
  `cmake-build-presets/release/CMakeFiles/runblack-reassembled-src-001.dir/`.
  Finds the function by matching the symbol name in the disassembly output.
  Stops at the next function label or NOP padding.

- **Expected bytes**: Searches all 367 files in `src/asm/unprocessed/*.asm`
  for a label matching the symbol. Reads instruction byte encodings from
  the `// 0xADDRESS HEXBYTES` comments on each line. Stops at the next
  function label or NOP padding.

### 2. Alignment

Instructions are compared pair-by-pair. If instruction counts differ,
the Needleman-Wunsch sequence alignment algorithm inserts gaps to minimize
the total byte difference. This prevents a single extra/missing instruction
from misaligning the entire diff.

### 3. Suggestion Engine

For each mismatched instruction pair, the engine checks three layers:
1. **Opcode byte lookup** in `OPCODE_SUGGESTIONS` dict
2. **Multi-byte pattern match** against `PATTERN_SUGGESTIONS` list
3. **Sequence pattern match** against `SEQUENCE_SUGGESTIONS` list

Suggestions are printed as `-> TRY: attribute_name — description`.

## Typical Workflow

```bash
# 1. You wrote a pure C version of GetRoomLeftForAdults
# 2. Build fails MD5 check
cmake --workflow --preset release
# MD5: 005f624eac7f0bb4ff3823d010cb78a8  (WRONG!)

# 3. Run objdiff
python3 scripts/decompilation/objdiff.py src/c/Abode.004.c \
    "?GetRoomLeftForAdults@Abode@@QAEHXZ"

# Output shows:
#   >> Expected: 33 d2  xor.s edx, edx
#   >> Got:      0f b6 89 b4 00 00 00  movzbl 0xb4(%ecx), %ecx
#      -> TRY: expand_movzx (xor+mov vs movzx)
#
#   >> Expected: 2b c2  sub.s eax, edx
#   >> Got:      2b c1  subl %ecx, %eax
#      -> TRY: msvc6_regalloc — reversed SUB (2B vs 29)

# 4. Add suggested attributes
__attribute__((XOR32rr_REV, expand_movzx, msvc6_regalloc))
int __fastcall GetRoomLeftForAdults__5AbodeFv(struct Abode* this) { ... }

# 5. Rebuild, re-run objdiff if still wrong, iterate
```

## Running Tests

```bash
# Quick smoke test: diff a known-good pure C function
python3 scripts/decompilation/objdiff.py src/c/Object.000.c \
    "?StandAnimation@Object@@UAEIXZ"
# Should show: MATCH! All 4 bytes identical.

# Test ASM byte extraction
python3 -c "
import sys; sys.path.insert(0, 'scripts/decompilation')
from objdiff import find_asm_function
result = find_asm_function('?IsBallFree@Ball@@QAE_NXZ')
for b, asm in result:
    print(f'{b.hex(\" \"):30s} {asm}')
"
# Should print 5 instructions with hex bytes

# Batch test: diff all functions in a file
python3 scripts/decompilation/objdiff.py src/c/Abode.001.c
```

## File Location

`scripts/decompilation/objdiff.py`

Dependencies: Python 3, `llvm-objdump` (from the LLVM fork at `llvm-project/install/bin/`)

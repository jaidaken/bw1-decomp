# Decompilation Session Handoff

## Project

Byte-exact decompilation of Black & White (2001) `runblack.exe` v1.20
- **Target MD5**: `174b1a64e74b2321f3c38ccc8a511e78`
- **Build**: `source .venv/bin/activate && cmake --workflow --preset release`
- **Toolchain**: Custom LLVM `bw1-decomp-013` on NixOS — do NOT update mid-session
- **Verification**: `md5sum build/runblack.exe` must match target after every change

## Current State (2026-03-11)

| Metric | Count | % |
|--------|------:|---:|
| Total functions | 1576 | 100% |
| Decompiled (pure C) | 504 | 32.0% |
| asm volatile blocks | 965 | 61.2% |
| Individual asm | 75 | 4.8% |
| Mixed (C + asm) | 32 | 2.0% |

### Decompilable Now
- **3 jmp thunks** — use `musttail` pattern
- **25 float const returns** — BLOCKED (needs LLVM patch for `fld [rdata]` vs `fldz`)

### Key Files (by remaining asm count)
1. `Villager.c` — 252 functions (217 volatile, 25 decompiled)
2. `VillagerReaction.c` — 119 functions (106 volatile)
3. `VillagerFootball.c` — 78 functions (62 volatile)
4. `VillagerStates.c` — 70 functions (54 volatile)
5. `VillagerHome.c` — 62 functions (47 volatile)

## Scripts

| Script | Purpose | Command |
|--------|---------|---------|
| `classify_asm_functions.py` | Classify all asm functions by difficulty | `python scripts/decompilation/classify_asm_functions.py` |
| `find_decompilable.py` | Find functions matching known-working C patterns | `python scripts/decompilation/find_decompilable.py` |
| `find_all_decompilable.py` | Find decompilable by hex byte patterns | `python scripts/decompilation/find_all_decompilable.py` |
| `progress_report.py` | Progress report with per-file breakdown | `python scripts/decompilation/progress_report.py` |
| `compare_function.py` | Compare a single function's output | `python scripts/decompilation/compare_function.py` |
| `objdiff.py` | Byte-level diff with attribute suggestions | `python scripts/decompilation/objdiff.py src/c/File.c "?Symbol@@..."` |
| `objdiff.py` (batch) | Diff all functions in a C file | `python scripts/decompilation/objdiff.py src/c/File.c` |

## Memory Files

Located in `~/.claude/projects/-home-jaidaken-bw1-decomp/memory/`:
- `MEMORY.md` — Project overview, loaded every session
- `patterns.md` — All confirmed working + blocked decompilation patterns
- `structs.md` — Key struct offsets (Object, Villager, Abode, etc.)

## Critical Rules

### 1. `%{disp}` Escaping in asm volatile
```c
// WRONG — silently stripped by inline asm parser:
asm volatile ("{disp8} mov eax, [ecx + 0x04]" ...);

// CORRECT — escaped curly braces:
asm volatile ("%{disp8%} mov eax, dword ptr [ecx + 0x04]" ...);
```
Individual `asm("{disp8} ...")` does NOT need escaping (only asm volatile).

### 2. Backward Labels in Intel Syntax
```c
// WRONG — backward refs (0b) don't work in Intel syntax:
asm volatile ("jne 0b" ...);

// CORRECT — use original label names:
asm volatile ("jne LAB__addr_0x00404b76" ...);
```
Forward local labels (`0:` / `jne 0f`) DO work.

### 3. sbb Encoding
```c
// WRONG — `sbb eax, eax` emits 0x19 0xc0:
asm volatile ("sbb eax, eax" ...);

// CORRECT — use .byte for 0x1b 0xc0 (sbb.s):
asm volatile (".byte 0x1b, 0xc0" ...);
```

### 4. Verified Return Type Requirements
- `bool` return → compiler adds `and al, 1` (use `bool32_t` or include `ret` in asm)
- `XOR32rr_REV` attribute needed for `xor eax, eax` (vs `xor eax, eax` with wrong encoding)
- `MOV32rr_REV` attribute needed for `mov eax, ecx` return-this pattern

### 5. Build Verification
```bash
source .venv/bin/activate
cmake --workflow --preset release
md5sum build/runblack.exe
# Must be: 174b1a64e74b2321f3c38ccc8a511e78
```

## Blocked Categories

| Pattern | Count | Blocker |
|---------|------:|---------|
| Float const return (`fld [rdata]`) | 25 | LLVM generates different instruction |
| Bitfield accessor (`xor eax; mov al`) | 43+ | LLVM generates `movzx` instead |
| Return -1 (`or eax, -1`) | 2 | LLVM generates `mov eax, -1` |
| String address (`mov eax, OFFSET`) | ~5 | LLVM generates `mov eax, [addr]` |
| Inc/dec byte | ~5 | LLVM generates `add byte, 1` |
| Memory-destination add | ~3 | LLVM generates load-add-store |
| Trailing code after ret | many | Cannot reproduce in C |

## Decompilation Workflow

1. Pick a function from classifier output (LOW difficulty first)
2. Read the asm and identify the pattern (see `patterns.md`)
3. Write the C equivalent following the confirmed pattern
4. Build and verify MD5 matches
5. If MD5 doesn't match, run `objdiff.py` to see exact byte differences and suggested attributes
6. Apply suggested `__attribute__`s, rebuild, repeat until MD5 matches
7. If pattern is new, add to `patterns.md`

## What NOT to Do

- Don't update the LLVM toolchain
- Don't change function signatures without verifying the entire binary
- Don't assume a pattern works — always verify with MD5
- Don't use `asm volatile` without `%{disp%}` escaping
- Don't commit changes that break the MD5 match

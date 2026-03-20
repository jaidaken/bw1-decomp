# LLVM Fixes Needed for ASM-to-C Conversion

These fixes are needed in the LLVM fork to unblock more function conversions.
All are in `llvm-project/llvm/lib/Target/X86/`.

## 1. ISel Crash on Indirect Calls (blocks 455 functions)

**File:** Unknown - likely in X86ISelDAGToDAG.cpp or ScheduleDAGRRList
**Symptom:** SmallVector overflow in `SUnit::ComputeHeight()` when compiling C
function pointer calls. Affects both `no_ret` (jmp) and `no_callee_saves` (call+ret) patterns.
**Reproducer:** Any function with `((struct Vtable*)(*(void**)this))->Method(this);`
**Priority:** Highest - blocks all vtable dispatch conversion

## 2. CMP [mem], 0 vs MOV reg,[mem]; TEST reg,reg (blocks ~66 functions)

**File:** New pass needed (e.g., X86PreferTestReg.cpp)
**Symptom:** LLVM generates `cmp byte [ecx+N], 0; setne al` instead of
`mov dl, [ecx+N]; test dl, dl; setne al`. The `IsProfitableToFold` disable
doesn't prevent this because it's not a load fold - it's a compare-immediate.
**Pattern to match:** `CMP8mi/CMP32mi [mem], 0` -> `MOV8rm/MOV32rm reg, [mem]; TEST8rr/TEST32rr reg, reg`
**Priority:** High - blocks all non-zero-check boolification patterns

## 3. PreferNegSbb: Add COND_NE support -- DONE

**Status:** FIXED in commit 344c031b09dd (bw1-decomp branch).
Added COND_NE support (neg+sbb+neg) and Pattern C (different register + MOV).
Converted HousewifeLookForWork successfully. MD5 verified.

Of the 13 remaining neg_sbb functions:
- 9 have vtable calls (blocked by ISel crash #1)
- 4 have named calls, but 3 use `sub/dec` before the sbb (equality comparison
  with constant), which generates `cmp eax,N; sete` instead of `sub N; neg; sbb; inc`

## 4. CMP reg, imm; SETE vs SUB imm; NEG; SBB; INC (blocks ~3 named-call neg_sbb)

**File:** New pass or PreferNegSbb extension
**Symptom:** LLVM generates `cmp eax, 4; sete cl` for `== 4` comparisons.
MSVC 6.0 generates `sub al, 4; neg al; sbb eax, eax; inc eax`.
**Pattern:** For `== N` where N is a small constant: replace `CMP+SETE` with
`SUB N; NEG; SBB; INC`. This is the full MSVC 6.0 equality idiom.
**Priority:** Low - only 3 functions (IsReadyForNewScriptAction, FUN_004056f0,
CheckSatisfySuppyWorship) plus GetNextPlayerAndNeutral which has unique logic.

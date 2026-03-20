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

## 3. PreferNegSbb: Add COND_NE support (blocks ~14 neg_sbb functions)

**File:** X86PreferNegSbb.cpp (line 97-103)
**Symptom:** Pass only matches `XOR+TEST+SETE` (== 0), not `XOR+TEST+SETNE` (!= 0).
**Fix:** Add a second pattern that matches SETNE and generates `NEG+SBB+NEG`
instead of `NEG+SBB+INC`. The SBB gives -1 for non-zero, NEG turns -1 to 1.
For SETE (== 0): neg+sbb+inc (current, correct)
For SETNE (!= 0): neg+sbb+neg (new, needed)
**Priority:** Medium - 14 functions have this pattern

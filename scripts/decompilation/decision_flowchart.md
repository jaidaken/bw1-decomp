# Decompilation Decision Flowchart

## Step 1: Identify the Function Pattern

Read the asm (volatile or individual) and identify the instruction sequence:

```
START
  |
  v
How many instructions before ret?
  |
  ├── 1 instruction
  │   ├── jmp target            → Pattern: JMP THUNK (go to Step 2A)
  │   └── other                 → Stay as asm
  │
  ├── 2 instructions
  │   ├── mov eax, [ecx+N]; ret         → Pattern: FIELD GETTER (Step 2B)
  │   ├── fld [ecx+N]; ret              → Pattern: FLOAT FIELD GETTER (Step 2B)
  │   ├── fld [_rdata_X]; ret           → BLOCKED: float const return
  │   ├── lea eax, [ecx+N]; ret         → Pattern: LEA ADDR GETTER (Step 2B)
  │   ├── mov al, 0x01; ret             → Pattern: RETURN TRUE (Step 2C)
  │   ├── xor eax, eax; ret             → Pattern: RETURN ZERO (Step 2C)
  │   ├── mov eax, ecx; ret             → Pattern: RETURN THIS (Step 2C)
  │   └── or eax, -1; ret               → BLOCKED: return -1
  │
  ├── 3 instructions
  │   ├── mov eax,[esp+4]; mov [ecx+N],eax; ret     → Pattern: FIELD SETTER (Step 2D)
  │   ├── mov eax,[ecx+A]; mov eax,[eax+B]; ret     → Pattern: DOUBLE DEREF (Step 2E)
  │   ├── mov eax,[ecx+A]; fld [eax+B]; ret         → Pattern: INFO FLOAT GETTER (Step 2E)
  │   ├── mov eax,[ecx+A]; add eax,B; ret           → Pattern: INFO ADDR GETTER (Step 2E)
  │   ├── mov [ecx+N],0; mov eax,1; ret             → Pattern: SET NULL RETURN 1 (Step 2F)
  │   ├── mov word [ecx+N],imm; mov eax,1; ret      → Pattern: WORD SET RETURN 1 (Step 2F)
  │   ├── mov eax,[ecx]; jmp [eax+N]                → Pattern: VTABLE DISPATCH (Step 2G)
  │   ├── mov eax,[ecx]; call [eax+N]; ret           → Pattern: VTABLE CALL (Step 2G)
  │   ├── xor eax,eax; mov al,[ecx+N]; ret           → BLOCKED: bitfield accessor
  │   └── mov eax,[esp+4]; mov eax,[ecx+eax*4+N]; ret → Pattern: ARRAY GETTER (Step 2D)
  │
  ├── 4-6 instructions
  │   ├── Has .byte 0x1b, 0xc0?       → Pattern: NEG/SBB (Step 2H)
  │   ├── Has call + ret?             → Pattern: CALL WRAPPER (Step 2I)
  │   ├── Has push + call [eax+N]?    → Pattern: VTABLE+ARGS (Step 2G)
  │   └── other                       → Analyze individually
  │
  └── 7+ instructions                 → Complex function, analyze individually
```

## Step 2: Apply the Pattern

### 2A: JMP THUNK
```c
// Requirement: musttail + noinline on target declaration
extern RetType __fastcall Target(Type* this) __attribute__((noinline));
RetType __fastcall Wrapper(Type* this) {
    __attribute__((musttail)) return Target(this);
}
```
**Check**: Is target in same file? If yes, add `noinline` to the DEFINITION too.

### 2B: FIELD GETTER
```c
// int/ptr field:
return this->field;
// float field:
return this->float_field;
// LEA addr:
return &this->struct_field;  // (or array field that decays to pointer)
```
**Lookup**: Check `structs.md` for offset-to-field mapping.

### 2C: RETURN CONSTANT
```c
// return true (mov al, 0x01):
return true;  // bool return type

// return 0 (xor eax, eax):
return 0;  // needs __attribute__((XOR32rr_REV))

// return this (mov eax, ecx):
return this;  // needs __attribute__((MOV32rr_REV))
```

### 2D: FIELD SETTER / ARRAY GETTER
```c
// setter:
this->field = param;

// array indexed getter:
return this->array[param];
```

### 2E: DOUBLE DEREFERENCE
```c
// ptr->field:
return this->ptr->field;

// info float getter (mov eax,[ecx+0x28] is info pointer):
return ((const struct GVillagerInfo*)((struct Object*)this)->info)->floatField;

// info addr getter:
return this->info->charArrayField;  // array decays to pointer
```

### 2F: SET + RETURN
```c
this->field = NULL;  // or 0, or imm16
return 1;
```

### 2G: VTABLE DISPATCH (use asm volatile wrapper)
```c
// Pure vtable jmp (mov eax,[ecx]; jmp [eax+N]):
type __fastcall Wrapper(struct T* this) {
    void* dummy; type result;
    asm volatile ("mov eax, dword ptr [ecx]\n\t"
        "call dword ptr [eax + 0xNNN]"  // use call, not jmp
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory");
    return result;
}

// With pushed arguments:
// Add push instructions before the call
// Use "=c"(dummy) to save/restore ecx via esi
```

### 2H: NEG/SBB BOOLIFICATION
```c
bool32_t __fastcall Wrapper(struct T* this) {
    void* dummy; bool32_t result;
    asm volatile ("call ?Func@...\n\t"
        "neg eax\n\t.byte 0x1b, 0xc0\n\tneg eax"
        : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory");
    return result;
}
```
**Variants**: dec/neg/sbb/inc, neg/sbb/and/inc, sub al/neg al/sbb/inc

### 2I: CALL WRAPPER
```c
// For same-file callees with __builtin_unreachable:
void* dummy;
asm volatile ("call ?Callee@Class@@..."
    : "=c"(dummy) : "c"(this) : "eax", "edx", "memory");
return CrossFileCallee(this);
```

## Step 3: Verify

```bash
source .venv/bin/activate
cmake --workflow --preset release
md5sum build/runblack.exe
# Must be: 174b1a64e74b2321f3c38ccc8a511e78
```

If MD5 doesn't match:
1. Run `compare_function.py` to find the specific byte difference
2. Check `%{disp%}` escaping in asm volatile
3. Check return type (bool vs bool32_t vs uint32_t)
4. Check attribute requirements (XOR32rr_REV, MOV32rr_REV, etc.)
5. Revert and try a different approach

## Step 4: Update Documentation

- If new pattern confirmed → add to `patterns.md`
- If new struct offset discovered → add to `structs.md`
- Run `progress_report.py` to update counts

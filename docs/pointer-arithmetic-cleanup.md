# Pointer Arithmetic Cleanup Plan

Raw pointer arithmetic like `*((uint8_t*)this + 0x7c)` should be replaced with
proper struct field access. The C code should be readable, not just byte-equivalent
to the ASM.

## Inventory: 18 instances across 8 files

### Abode.001.c (1 instance)

| Line | Current Code | Offset | Struct Field | Replacement |
|------|-------------|--------|--------------|-------------|
| 15 | `(*((uint8_t*)this + 0x7c) >> 2) & 1` | 0x7c | `Abode.field_0x7c` | `(this->field_0x7c >> 2) & 1` - needs field renamed once purpose is known |

### Abode.004.c (5 instances)

| Line | Current Code | Offset | Struct Field | Replacement |
|------|-------------|--------|--------------|-------------|
| 987 | `*(int*)((char*)*(void**)((char*)this + 0x28) + 0x174)` | 0x28 + 0x174 | `Object.info` -> `GObjectInfo` at 0x174 | `*(int*)((char*)this->base.super_object.info + 0x174)` then name the GObjectInfo field |
| 988 | `*((uint8_t*)this + 0xb4)` | 0xb4 | `Abode.adult_count` (at 0xb4) | `this->adult_count` |
| 995 | `*(int*)((char*)*(void**)((char*)this + 0x28) + 0x178)` | 0x28 + 0x178 | `Object.info` -> `GObjectInfo` at 0x178 | Same pattern as 987, name the GObjectInfo fields |
| 996 | `*((uint8_t*)this + 0xb7)` | 0xb7 | `Abode.field_0xb7` | `this->field_0xb7` - likely `child_count` |
| 1008 | `*(int*)((char*)*(void**)((char*)this + 0x28) + 0x110)` | 0x28 + 0x110 | `Object.info` -> `GObjectInfo` at 0x110 | Name the GObjectInfo field |

### Abode.006.c (2 instances)

| Line | Current Code | Offset | Struct Field | Replacement |
|------|-------------|--------|--------------|-------------|
| 450 | `(*((uint8_t*)this + 0xb6))++` | 0xb6 | `Abode.field_0xb6` | `this->field_0xb6++` |
| 456 | `(*((uint8_t*)this + 0xb6))--` | 0xb6 | `Abode.field_0xb6` | `this->field_0xb6--` |

### Abode.008.c (2 instances)

| Line | Current Code | Offset | Struct Field | Replacement |
|------|-------------|--------|--------------|-------------|
| 13 | `*(enum ABODE_TYPE*)((char*)*(void**)((char*)this + 0x28) + 0x120)` | 0x28 + 0x120 | `Object.info` -> `GObjectInfo` at 0x120 | `this->base.super_object.info->abode_type` (name the field) |
| 1541 | `*(float*)((char*)(*(void**)((char*)this + 0x28)) + 0x1b8)` | 0x28 + 0x1b8 | `Object.info` -> `GObjectInfo` at 0x1b8 | Name the GObjectInfo field |

### GameThingWithPos.000.c (3 instances)

| Line | Current Code | Offset | Struct Field | Replacement |
|------|-------------|--------|--------------|-------------|
| 71 | `*(uint32_t*)((char*)this + 0x1c) = 0` | 0x1c | Part of `GameThingWithPos.coords` (MapCoords at 0x14, 0x1c is z component) | `this->coords.z = 0` or similar |
| 130 | `(*(uint16_t*)((char*)this + 0x24) >> 13) & 1` | 0x24 | `GameThingWithPos.field_0x24` | `(this->field_0x24 >> 13) & 1` - bitfield, name the flag |
| 1010 | `(*(uint16_t*)((char*)this + 0x24) >> 9) & 1` | 0x24 | `GameThingWithPos.field_0x24` | `(this->field_0x24 >> 9) & 1` - bitfield, name the flag |

### GameThingWithPos.001.c (1 instance)

| Line | Current Code | Offset | Struct Field | Replacement |
|------|-------------|--------|--------------|-------------|
| 52 | `*((uint8_t*)this + 0x24) & 1` | 0x24 | `GameThingWithPos.field_0x24` (low byte) | `this->field_0x24 & 1` |

### Object.000.c (1 instance)

| Line | Current Code | Offset | Struct Field | Replacement |
|------|-------------|--------|--------------|-------------|
| 544 | `*(bool32_t*)((char*)*(void**)((char*)this + 0x28) + 0xc0)` | 0x28 + 0xc0 | `Object.info` -> `GObjectInfo` at 0xc0 | `this->info->field_0xc0` (name the bool field) |

### Villager.0502.c (3 instances)

| Line | Current Code | Offset | Struct Field | Replacement |
|------|-------------|--------|--------------|-------------|
| 61 | `(*((uint8_t*)this + 0xe0) >> 3) & 1` | 0xe0 | `Villager.field_0xe0` (low byte of uint16_t) | `(this->field_0xe0 >> 3) & 1` - bitfield flag |
| 115 | `*(int*)((char*)*(void**)((char*)this + 0x28) + 0x214)` | 0x28 + 0x214 | `Object.info` -> some info struct at 0x214 | Name the info field |
| 291 | `*(uint8_t*)((char*)this + 0x118)` | 0x118 | Inside Villager struct, between `fire_effect` (0x114) and `target_thing` (0x118) | Verify offset, use field name |

### Villager.c (1 instance)

| Line | Current Code | Offset | Struct Field | Replacement |
|------|-------------|--------|--------------|-------------|
| 10994 | `*(uint8_t*)((char*)this + 0x8e)` | 0x8e | Inside `Living.action` (LivingAction at 0x8c, +2 into it) | Name the LivingAction field at offset 0x2 |

## Common Patterns

### Pattern 1: Direct field access (10 instances)
```c
// Before:
*((uint8_t*)this + 0xb4)
// After:
this->adult_count
```
These are simple - the struct already has a field at that offset. Just use it.

### Pattern 2: Chained pointer through info (7 instances)
```c
// Before:
*(int*)((char*)*(void**)((char*)this + 0x28) + 0x174)
// After:
this->info->max_adults   // once GObjectInfo fields are named
```
All go through offset 0x28 which is `Object.info` (a `GObjectInfo*`). The second
offset indexes into `GObjectInfo`. Fixing these requires expanding the `GObjectInfo`
struct definition with named fields.

### Pattern 3: Bitfield access (4 instances)
```c
// Before:
(*(uint16_t*)((char*)this + 0x24) >> 13) & 1
// After:
this->flags.is_something   // or (this->flags >> 13) & 1 with named constant
```
These access individual bits within a flags field. Even if we keep the shift+mask,
using the named field and a `#define` for the bit position is better.

## Priority Order

1. **Pattern 1 (direct field access)** - Easiest. The struct fields exist, just
   need to use `this->field` syntax instead of pointer arithmetic. Some fields
   need renaming once purpose is understood from context.

2. **Pattern 3 (bitfield access)** - Medium. Replace pointer arithmetic with
   field access, add `#define` constants for bit positions. Consider whether
   the field should be a proper bitfield struct.

3. **Pattern 2 (chained info pointer)** - Hardest. Requires expanding `GObjectInfo`
   struct definition with named fields at offsets 0xc0, 0x110, 0x120, 0x174,
   0x178, 0x1b8, 0x214. This is the most impactful fix since it affects 7
   instances and reveals what data the game stores in its object info tables.

## Byte-Matching Constraint

Each replacement must produce identical bytes. The key rule: if the struct layout
matches the original (fields at correct offsets with correct types), then
`this->field` compiles to the same `mov` instruction as the pointer arithmetic.
Verify with MD5 after each file is changed.

Fields that are currently `field_0xNN` should be renamed as their purpose becomes
clear from usage context (e.g., `field_0xb4` in Abode is clearly `adult_count`
based on the function `GetRoomLeftForAdults`).

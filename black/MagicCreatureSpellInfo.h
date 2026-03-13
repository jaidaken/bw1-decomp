#ifndef BW1_DECOMP_MAGIC_CREATURE_SPELL_INFO_INCLUDED_H
#define BW1_DECOMP_MAGIC_CREATURE_SPELL_INFO_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "MagicInfo.h" /* For struct GMagicInfo */

#ifdef __cplusplus

// Forward Declares

class Base;

// win1.41 009cd030 mac inlined GMagicCreatureSpellInfo::`RTTI Type Descriptor'
// win1.41 009a81f0 mac inlined GMagicCreatureSpellInfo::`RTTI Base Class Descriptor'
// win1.41 009a8208 mac inlined GMagicCreatureSpellInfo::`RTTI Base Class Array'
// win1.41 009a8220 mac inlined GMagicCreatureSpellInfo::`RTTI Class Hierarchy Descriptor'
class GMagicCreatureSpellInfo: public GMagicInfo
{
public:
    uint32_t field_0x58; /* 0x58 */
    uint32_t field_0x5c; /* 0x5c */
    uint32_t field_0x60; /* 0x60 */
    uint32_t field_0x64; /* 0x64 */
    uint32_t field_0x68; /* 0x68 */
    uint32_t field_0x6c; /* 0x6c */
    uint32_t field_0x70; /* 0x70 */
    uint32_t field_0x74; /* 0x74 */
    uint32_t field_0x78; /* 0x78 */
    uint32_t field_0x7c; /* 0x7c */
    uint32_t field_0x80; /* 0x80 */
    uint32_t field_0x84; /* 0x84 */
    uint32_t field_0x88; /* 0x88 */
    uint32_t field_0x8c; /* 0x8c */
    uint32_t field_0x90; /* 0x90 */
    uint32_t field_0x94; /* 0x94 */
    uint32_t field_0x98; /* 0x98 */

    // Override methods

    // win1.41 00435800 mac 103aba10 GMagicCreatureSpellInfo::_dt(void)
    virtual ~GMagicCreatureSpellInfo();
};

#else // __cplusplus

// Forward Declares

struct Base;

struct GMagicCreatureSpellInfo
{
  struct GMagicInfo super;  /* 0x0 */
  uint32_t field_0x58; /* 0x58 */
  uint32_t field_0x5c; /* 0x5c */
  uint32_t field_0x60; /* 0x60 */
  uint32_t field_0x64; /* 0x64 */
  uint32_t field_0x68; /* 0x68 */
  uint32_t field_0x6c; /* 0x6c */
  uint32_t field_0x70; /* 0x70 */
  uint32_t field_0x74; /* 0x74 */
  uint32_t field_0x78; /* 0x78 */
  uint32_t field_0x7c; /* 0x7c */
  uint32_t field_0x80; /* 0x80 */
  uint32_t field_0x84; /* 0x84 */
  uint32_t field_0x88; /* 0x88 */
  uint32_t field_0x8c; /* 0x8c */
  uint32_t field_0x90; /* 0x90 */
  uint32_t field_0x94; /* 0x94 */
  uint32_t field_0x98; /* 0x98 */
};
static_assert(sizeof(struct GMagicCreatureSpellInfo) == 0x9c, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 009cd030 mac inlined GMagicCreatureSpellInfo::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__23GMagicCreatureSpellInfo asm("??_R0?AVGMagicCreatureSpellInfo@@@8");
// win1.41 009a81f0 mac inlined GMagicCreatureSpellInfo::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__23GMagicCreatureSpellInfo asm("??_R1A@?0A@A@GMagicCreatureSpellInfo@@8");
// win1.41 009a8208 mac inlined GMagicCreatureSpellInfo::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__23GMagicCreatureSpellInfo asm("??_R2GMagicCreatureSpellInfo@@8");
// win1.41 009a8220 mac inlined GMagicCreatureSpellInfo::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__23GMagicCreatureSpellInfo asm("??_R3GMagicCreatureSpellInfo@@8");

// Override methods

// win1.41 00435800 mac 103aba10 GMagicCreatureSpellInfo::_dt(void)
void __fastcall __dt__23GMagicCreatureSpellInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGMagicCreatureSpellInfo@@UAEPAXI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_MAGIC_CREATURE_SPELL_INFO_INCLUDED_H */

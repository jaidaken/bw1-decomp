#ifndef BW1_DECOMP_ANIMAL_STATE_TABLE_INFO_INCLUDED_H
#define BW1_DECOMP_ANIMAL_STATE_TABLE_INFO_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "BaseInfo.h" /* For struct GBaseInfo */

#ifdef __cplusplus

// Forward Declares

class Base;

// win1.41 009c8d88 mac inlined GAnimalStateTableInfo::`RTTI Type Descriptor'
// win1.41 009a6b98 mac inlined GAnimalStateTableInfo::`RTTI Base Class Descriptor'
// win1.41 009a6bb0 mac inlined GAnimalStateTableInfo::`RTTI Base Class Array'
// win1.41 009a6bc0 mac inlined GAnimalStateTableInfo::`RTTI Class Hierarchy Descriptor'
class GAnimalStateTableInfo: public GBaseInfo
{
public:
    uint32_t field_0x10; /* 0x10 */
    uint32_t field_0x14; /* 0x14 */
    uint32_t field_0x18; /* 0x18 */
    uint32_t field_0x1c; /* 0x1c */
    uint32_t field_0x20; /* 0x20 */
    uint32_t field_0x24; /* 0x24 */
    uint32_t field_0x28; /* 0x28 */
    uint32_t field_0x2c; /* 0x2c */
    uint32_t field_0x30; /* 0x30 */
    uint32_t field_0x34; /* 0x34 */
    uint32_t field_0x38; /* 0x38 */
    uint32_t field_0x3c; /* 0x3c */
    uint32_t field_0x40; /* 0x40 */
    uint32_t field_0x44; /* 0x44 */
    uint32_t field_0x48; /* 0x48 */
    uint32_t field_0x4c; /* 0x4c */
    uint32_t field_0x50; /* 0x50 */
    uint32_t field_0x54; /* 0x54 */
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
    uint32_t field_0x9c; /* 0x9c */
    uint32_t field_0xa0; /* 0xa0 */
    uint32_t field_0xa4; /* 0xa4 */
    uint32_t field_0xa8; /* 0xa8 */
    uint32_t field_0xac; /* 0xac */
    uint32_t field_0xb0; /* 0xb0 */
    uint32_t field_0xb4; /* 0xb4 */

    // Override methods

    // win1.41 00416e80 mac 1016b620 GAnimalStateTableInfo::_dt(void)
    virtual ~GAnimalStateTableInfo();
    // win1.41 00416e10 mac 1016cd20 GAnimalStateTableInfo::GetBaseInfo(unsigned long &)
    virtual GBaseInfo* GetBaseInfo(uint32_t& param_1);
};

#else // __cplusplus

// Forward Declares

struct Base;

struct GAnimalStateTableInfo
{
  struct GBaseInfo super;  /* 0x0 */
  uint32_t field_0x10; /* 0x10 */
  uint32_t field_0x14; /* 0x14 */
  uint32_t field_0x18; /* 0x18 */
  uint32_t field_0x1c; /* 0x1c */
  uint32_t field_0x20; /* 0x20 */
  uint32_t field_0x24; /* 0x24 */
  uint32_t field_0x28; /* 0x28 */
  uint32_t field_0x2c; /* 0x2c */
  uint32_t field_0x30; /* 0x30 */
  uint32_t field_0x34; /* 0x34 */
  uint32_t field_0x38; /* 0x38 */
  uint32_t field_0x3c; /* 0x3c */
  uint32_t field_0x40; /* 0x40 */
  uint32_t field_0x44; /* 0x44 */
  uint32_t field_0x48; /* 0x48 */
  uint32_t field_0x4c; /* 0x4c */
  uint32_t field_0x50; /* 0x50 */
  uint32_t field_0x54; /* 0x54 */
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
  uint32_t field_0x9c; /* 0x9c */
  uint32_t field_0xa0; /* 0xa0 */
  uint32_t field_0xa4; /* 0xa4 */
  uint32_t field_0xa8; /* 0xa8 */
  uint32_t field_0xac; /* 0xac */
  uint32_t field_0xb0; /* 0xb0 */
  uint32_t field_0xb4; /* 0xb4 */
};
static_assert(sizeof(struct GAnimalStateTableInfo) == 0xb8, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 009c8d88 mac inlined GAnimalStateTableInfo::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__21GAnimalStateTableInfo asm("??_R0?AVGAnimalStateTableInfo@@@8");
// win1.41 009a6b98 mac inlined GAnimalStateTableInfo::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__21GAnimalStateTableInfo asm("??_R1A@?0A@A@GAnimalStateTableInfo@@8");
// win1.41 009a6bb0 mac inlined GAnimalStateTableInfo::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__21GAnimalStateTableInfo asm("??_R2GAnimalStateTableInfo@@8");
// win1.41 009a6bc0 mac inlined GAnimalStateTableInfo::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__21GAnimalStateTableInfo asm("??_R3GAnimalStateTableInfo@@8");

// Override methods

// win1.41 00416e80 mac 1016b620 GAnimalStateTableInfo::_dt(void)
void __fastcall __dt__21GAnimalStateTableInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGAnimalStateTableInfo@@UAEPAXI@Z");
// win1.41 00416e10 mac 1016cd20 GAnimalStateTableInfo::GetBaseInfo(unsigned long &)
struct GBaseInfo* __fastcall GetBaseInfo__21GAnimalStateTableInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1) asm("?GetBaseInfo@GAnimalStateTableInfo@@UAEPAVGBaseInfo@@AAI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_ANIMAL_STATE_TABLE_INFO_INCLUDED_H */

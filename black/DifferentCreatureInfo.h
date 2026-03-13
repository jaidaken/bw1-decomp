#ifndef BW1_DECOMP_DIFFERENT_CREATURE_INFO_INCLUDED_H
#define BW1_DECOMP_DIFFERENT_CREATURE_INFO_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "BaseInfo.h" /* For struct GBaseInfo */

#ifdef __cplusplus

// Forward Declares

class Base;

// win1.41 009cf900 mac inlined DifferentCreatureInfo::`RTTI Type Descriptor'
// win1.41 009a9400 mac inlined DifferentCreatureInfo::`RTTI Base Class Descriptor'
// win1.41 009a9418 mac inlined DifferentCreatureInfo::`RTTI Base Class Array'
// win1.41 009a9428 mac inlined DifferentCreatureInfo::`RTTI Class Hierarchy Descriptor'
class DifferentCreatureInfo: public GBaseInfo
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

    // Override methods

    // win1.41 00472d50 mac 101d2170 DifferentCreatureInfo::_dt(void)
    virtual ~DifferentCreatureInfo();
    // win1.41 00472cf0 mac 101e2a50 DifferentCreatureInfo::GetBaseInfo(unsigned long &)
    virtual GBaseInfo* GetBaseInfo(uint32_t& param_1);
};

#else // __cplusplus

// Forward Declares

struct Base;

struct DifferentCreatureInfo
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
};
static_assert(sizeof(struct DifferentCreatureInfo) == 0x6c, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 009cf900 mac inlined DifferentCreatureInfo::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__21DifferentCreatureInfo asm("??_R0?AVDifferentCreatureInfo@@@8");
// win1.41 009a9400 mac inlined DifferentCreatureInfo::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__21DifferentCreatureInfo asm("??_R1A@?0A@A@DifferentCreatureInfo@@8");
// win1.41 009a9418 mac inlined DifferentCreatureInfo::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__21DifferentCreatureInfo asm("??_R2DifferentCreatureInfo@@8");
// win1.41 009a9428 mac inlined DifferentCreatureInfo::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__21DifferentCreatureInfo asm("??_R3DifferentCreatureInfo@@8");

// Override methods

// win1.41 00472d50 mac 101d2170 DifferentCreatureInfo::_dt(void)
void __fastcall __dt__21DifferentCreatureInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GDifferentCreatureInfo@@UAEPAXI@Z");
// win1.41 00472cf0 mac 101e2a50 DifferentCreatureInfo::GetBaseInfo(unsigned long &)
struct GBaseInfo* __fastcall GetBaseInfo__21DifferentCreatureInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1) asm("?GetBaseInfo@DifferentCreatureInfo@@UAEPAVGBaseInfo@@AAI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_DIFFERENT_CREATURE_INFO_INCLUDED_H */

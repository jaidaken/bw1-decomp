#ifndef BW1_DECOMP_CLIMATE_RAIN_INFO_INCLUDED_H
#define BW1_DECOMP_CLIMATE_RAIN_INFO_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "BaseInfo.h" /* For struct GBaseInfo */

#ifdef __cplusplus

// Forward Declares

class Base;

// win1.41 00c24968 mac inlined GClimateRainInfo::`RTTI Type Descriptor'
// win1.41 009ba0e0 mac inlined GClimateRainInfo::`RTTI Base Class Descriptor'
// win1.41 009ba0f8 mac inlined GClimateRainInfo::`RTTI Base Class Array'
// win1.41 009ba108 mac inlined GClimateRainInfo::`RTTI Class Hierarchy Descriptor'
class GClimateRainInfo: public GBaseInfo
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

    // Override methods

    // win1.41 00773ce0 mac 105a3a30 GClimateRainInfo::_dt(void)
    virtual ~GClimateRainInfo();
    // win1.41 00773c90 mac 105a39e0 GClimateRainInfo::GetBaseInfo(unsigned long &)
    virtual GBaseInfo* GetBaseInfo(uint32_t& param_1);
};

#else // __cplusplus

// Forward Declares

struct Base;

struct GClimateRainInfo
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
};
static_assert(sizeof(struct GClimateRainInfo) == 0xa4, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 00c24968 mac inlined GClimateRainInfo::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__16GClimateRainInfo asm("??_R0?AVGClimateRainInfo@@@8");
// win1.41 009ba0e0 mac inlined GClimateRainInfo::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__16GClimateRainInfo asm("??_R1A@?0A@A@GClimateRainInfo@@8");
// win1.41 009ba0f8 mac inlined GClimateRainInfo::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__16GClimateRainInfo asm("??_R2GClimateRainInfo@@8");
// win1.41 009ba108 mac inlined GClimateRainInfo::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__16GClimateRainInfo asm("??_R3GClimateRainInfo@@8");

// Override methods

// win1.41 00773ce0 mac 105a3a30 GClimateRainInfo::_dt(void)
void __fastcall __dt__16GClimateRainInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGClimateRainInfo@@UAEPAXI@Z");
// win1.41 00773c90 mac 105a39e0 GClimateRainInfo::GetBaseInfo(unsigned long &)
struct GBaseInfo* __fastcall GetBaseInfo__16GClimateRainInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1) asm("?GetBaseInfo@GClimateRainInfo@@UAEPAVGBaseInfo@@AAI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_CLIMATE_RAIN_INFO_INCLUDED_H */

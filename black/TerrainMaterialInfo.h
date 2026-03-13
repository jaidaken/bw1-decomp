#ifndef BW1_DECOMP_TERRAIN_MATERIAL_INFO_INCLUDED_H
#define BW1_DECOMP_TERRAIN_MATERIAL_INFO_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "BaseInfo.h" /* For struct GBaseInfo */

#ifdef __cplusplus

// Forward Declares

class Base;

// win1.41 00c22ae0 mac inlined GTerrainMaterialInfo::`RTTI Type Descriptor'
// win1.41 009b9940 mac inlined GTerrainMaterialInfo::`RTTI Base Class Descriptor'
// win1.41 009b9958 mac inlined GTerrainMaterialInfo::`RTTI Base Class Array'
// win1.41 009b9968 mac inlined GTerrainMaterialInfo::`RTTI Class Hierarchy Descriptor'
class GTerrainMaterialInfo: public GBaseInfo
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

    // Override methods

    // win1.41 00735290 mac 105420c0 GTerrainMaterialInfo::_dt(void)
    virtual ~GTerrainMaterialInfo();
    // win1.41 00735230 mac 10542330 GTerrainMaterialInfo::GetBaseInfo(unsigned long &)
    virtual GBaseInfo* GetBaseInfo(uint32_t& param_1);
};

#else // __cplusplus

// Forward Declares

struct Base;

struct GTerrainMaterialInfo
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
};
static_assert(sizeof(struct GTerrainMaterialInfo) == 0x70, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 00c22ae0 mac inlined GTerrainMaterialInfo::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__20GTerrainMaterialInfo asm("??_R0?AVGTerrainMaterialInfo@@@8");
// win1.41 009b9940 mac inlined GTerrainMaterialInfo::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__20GTerrainMaterialInfo asm("??_R1A@?0A@A@GTerrainMaterialInfo@@8");
// win1.41 009b9958 mac inlined GTerrainMaterialInfo::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__20GTerrainMaterialInfo asm("??_R2GTerrainMaterialInfo@@8");
// win1.41 009b9968 mac inlined GTerrainMaterialInfo::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__20GTerrainMaterialInfo asm("??_R3GTerrainMaterialInfo@@8");

// Override methods

// win1.41 00735290 mac 105420c0 GTerrainMaterialInfo::_dt(void)
void __fastcall __dt__20GTerrainMaterialInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGTerrainMaterialInfo@@UAEPAXI@Z");
// win1.41 00735230 mac 10542330 GTerrainMaterialInfo::GetBaseInfo(unsigned long &)
struct GBaseInfo* __fastcall GetBaseInfo__20GTerrainMaterialInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1) asm("?GetBaseInfo@GTerrainMaterialInfo@@UAEPAVGBaseInfo@@AAI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_TERRAIN_MATERIAL_INFO_INCLUDED_H */

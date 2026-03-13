#ifndef BW1_DECOMP_SPOT_VISUAL_INFO_INCLUDED_H
#define BW1_DECOMP_SPOT_VISUAL_INFO_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "BaseInfo.h" /* For struct GBaseInfo */

#ifdef __cplusplus

// Forward Declares

class Base;

// win1.41 00bfe000 mac inlined GSpotVisualInfo::`RTTI Type Descriptor'
// win1.41 009b2e80 mac inlined GSpotVisualInfo::`RTTI Base Class Descriptor'
// win1.41 009b2e98 mac inlined GSpotVisualInfo::`RTTI Base Class Array'
// win1.41 009b2ea8 mac inlined GSpotVisualInfo::`RTTI Class Hierarchy Descriptor'
class GSpotVisualInfo: public GBaseInfo
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

    // Override methods

    // win1.41 0063e070 mac 101102f0 GSpotVisualInfo::_dt(void)
    virtual ~GSpotVisualInfo();
    // win1.41 0063e020 mac 10110f10 GSpotVisualInfo::GetBaseInfo(unsigned long &)
    virtual GBaseInfo* GetBaseInfo(uint32_t& param_1);
};

#else // __cplusplus

// Forward Declares

struct Base;

struct GSpotVisualInfo
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
};
static_assert(sizeof(struct GSpotVisualInfo) == 0x54, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 00bfe000 mac inlined GSpotVisualInfo::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__15GSpotVisualInfo asm("??_R0?AVGSpotVisualInfo@@@8");
// win1.41 009b2e80 mac inlined GSpotVisualInfo::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__15GSpotVisualInfo asm("??_R1A@?0A@A@GSpotVisualInfo@@8");
// win1.41 009b2e98 mac inlined GSpotVisualInfo::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__15GSpotVisualInfo asm("??_R2GSpotVisualInfo@@8");
// win1.41 009b2ea8 mac inlined GSpotVisualInfo::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__15GSpotVisualInfo asm("??_R3GSpotVisualInfo@@8");

// Override methods

// win1.41 0063e070 mac 101102f0 GSpotVisualInfo::_dt(void)
void __fastcall __dt__15GSpotVisualInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGSpotVisualInfo@@UAEPAXI@Z");
// win1.41 0063e020 mac 10110f10 GSpotVisualInfo::GetBaseInfo(unsigned long &)
struct GBaseInfo* __fastcall GetBaseInfo__15GSpotVisualInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1) asm("?GetBaseInfo@GSpotVisualInfo@@UAEPAVGBaseInfo@@AAI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_SPOT_VISUAL_INFO_INCLUDED_H */

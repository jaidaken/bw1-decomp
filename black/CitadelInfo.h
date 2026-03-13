#ifndef BW1_DECOMP_CITADEL_INFO_INCLUDED_H
#define BW1_DECOMP_CITADEL_INFO_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "ContainerInfo.h" /* For struct GContainerInfo */

#ifdef __cplusplus

// Forward Declares

class Base;
class GBaseInfo;

// win1.41 009ce810 mac inlined GCitadelInfo::`RTTI Type Descriptor'
// win1.41 009a8d68 mac inlined GCitadelInfo::`RTTI Base Class Descriptor'
// win1.41 009a8d80 mac inlined GCitadelInfo::`RTTI Base Class Array'
// win1.41 009a8d98 mac inlined GCitadelInfo::`RTTI Class Hierarchy Descriptor'
class GCitadelInfo: public GContainerInfo
{
public:
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

    // win1.41 004629d0 mac 101bb390 GCitadelInfo::_dt(void)
    virtual ~GCitadelInfo();
    // win1.41 00462980 mac 101bb430 GCitadelInfo::GetBaseInfo(unsigned long &)
    virtual GBaseInfo* GetBaseInfo(uint32_t& param_1);
};

#else // __cplusplus

// Forward Declares

struct Base;
struct GBaseInfo;

struct GCitadelInfo
{
  struct GContainerInfo super;  /* 0x0 */
  uint32_t field_0x14;  /* 0x14 */
  uint32_t field_0x18;  /* 0x18 */
  uint32_t field_0x1c;  /* 0x1c */
  uint32_t field_0x20;  /* 0x20 */
  uint32_t field_0x24;  /* 0x24 */
  uint32_t field_0x28;  /* 0x28 */
  uint32_t field_0x2c;  /* 0x2c */
  uint32_t field_0x30;  /* 0x30 */
  uint32_t field_0x34;  /* 0x34 */
  uint32_t field_0x38;  /* 0x38 */
  uint32_t field_0x3c;  /* 0x3c */
  uint32_t field_0x40;  /* 0x40 */
  uint32_t field_0x44;  /* 0x44 */
  uint32_t field_0x48;  /* 0x48 */
  uint32_t field_0x4c;  /* 0x4c */
  uint32_t field_0x50;  /* 0x50 */
};
static_assert(sizeof(struct GCitadelInfo) == 0x54, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 009ce810 mac inlined GCitadelInfo::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__12GCitadelInfo asm("??_R0?AVGCitadelInfo@@@8");
// win1.41 009a8d68 mac inlined GCitadelInfo::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__12GCitadelInfo asm("??_R1A@?0A@A@GCitadelInfo@@8");
// win1.41 009a8d80 mac inlined GCitadelInfo::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__12GCitadelInfo asm("??_R2GCitadelInfo@@8");
// win1.41 009a8d98 mac inlined GCitadelInfo::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__12GCitadelInfo asm("??_R3GCitadelInfo@@8");

// Override methods

// win1.41 004629d0 mac 101bb390 GCitadelInfo::_dt(void)
void __fastcall __dt__12GCitadelInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGCitadelInfo@@UAEPAXI@Z");
// win1.41 00462980 mac 101bb430 GCitadelInfo::GetBaseInfo(unsigned long &)
struct GBaseInfo* __fastcall GetBaseInfo__12GCitadelInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1) asm("?GetBaseInfo@GCitadelInfo@@UAEPAVGBaseInfo@@AAI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_CITADEL_INFO_INCLUDED_H */

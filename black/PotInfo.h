#ifndef BW1_DECOMP_POT_INFO_INCLUDED_H
#define BW1_DECOMP_POT_INFO_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "MobileObjectInfo.h" /* For struct GMobileObjectInfo */

#ifdef __cplusplus

// Forward Declares

class Base;
class GBaseInfo;

// win1.41 00c02018 mac inlined GPotInfo::`RTTI Type Descriptor'
// win1.41 009b33e8 mac inlined GPotInfo::`RTTI Base Class Descriptor'
// win1.41 009b3400 mac inlined GPotInfo::`RTTI Base Class Array'
// win1.41 009b3420 mac inlined GPotInfo::`RTTI Class Hierarchy Descriptor'
class GPotInfo: public GMobileObjectInfo
{
public:
    uint32_t field_0x114; /* 0x114 */
    uint32_t field_0x118; /* 0x118 */
    uint32_t field_0x11c; /* 0x11c */
    uint32_t field_0x120; /* 0x120 */
    uint32_t field_0x124; /* 0x124 */
    uint32_t field_0x128; /* 0x128 */
    uint32_t field_0x12c; /* 0x12c */
    uint32_t field_0x130; /* 0x130 */
    uint32_t field_0x134; /* 0x134 */
    uint32_t field_0x138; /* 0x138 */
    uint32_t field_0x13c; /* 0x13c */
    uint32_t field_0x140; /* 0x140 */

    // Override methods

    // win1.41 0066cc40 mac 10117210 GPotInfo::_dt(void)
    virtual ~GPotInfo();
    // win1.41 0066cbd0 mac 1011d400 GPotInfo::GetBaseInfo(unsigned long &)
    virtual GBaseInfo* GetBaseInfo(uint32_t& param_1);
};

#else // __cplusplus

// Forward Declares

struct Base;
struct GBaseInfo;

struct GPotInfo
{
  struct GMobileObjectInfo super;  /* 0x0 */
  uint32_t field_0x114; /* 0x114 */
  uint32_t field_0x118; /* 0x118 */
  uint32_t field_0x11c; /* 0x11c */
  uint32_t field_0x120; /* 0x120 */
  uint32_t field_0x124; /* 0x124 */
  uint32_t field_0x128; /* 0x128 */
  uint32_t field_0x12c; /* 0x12c */
  uint32_t field_0x130; /* 0x130 */
  uint32_t field_0x134; /* 0x134 */
  uint32_t field_0x138; /* 0x138 */
  uint32_t field_0x13c; /* 0x13c */
  uint32_t field_0x140; /* 0x140 */
};
static_assert(sizeof(struct GPotInfo) == 0x144, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 00c02018 mac inlined GPotInfo::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__8GPotInfo asm("??_R0?AVGPotInfo@@@8");
// win1.41 009b33e8 mac inlined GPotInfo::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__8GPotInfo asm("??_R1A@?0A@A@GPotInfo@@8");
// win1.41 009b3400 mac inlined GPotInfo::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__8GPotInfo asm("??_R2GPotInfo@@8");
// win1.41 009b3420 mac inlined GPotInfo::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__8GPotInfo asm("??_R3GPotInfo@@8");

// Override methods

// win1.41 0066cc40 mac 10117210 GPotInfo::_dt(void)
void __fastcall __dt__8GPotInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGPotInfo@@UAEPAXI@Z");
// win1.41 0066cbd0 mac 1011d400 GPotInfo::GetBaseInfo(unsigned long &)
struct GBaseInfo* __fastcall GetBaseInfo__8GPotInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1) asm("?GetBaseInfo@GPotInfo@@UAEPAVGBaseInfo@@AAI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_POT_INFO_INCLUDED_H */

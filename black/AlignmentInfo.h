#ifndef BW1_DECOMP_ALIGNMENT_INFO_INCLUDED_H
#define BW1_DECOMP_ALIGNMENT_INFO_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "BaseInfo.h" /* For struct GBaseInfo */

#ifdef __cplusplus

// Forward Declares

class Base;

// win1.41 009c8340 mac inlined GAlignmentInfo::`RTTI Type Descriptor'
// win1.41 009a69c8 mac inlined GAlignmentInfo::`RTTI Base Class Descriptor'
// win1.41 009a69e0 mac inlined GAlignmentInfo::`RTTI Base Class Array'
// win1.41 009a69f0 mac inlined GAlignmentInfo::`RTTI Class Hierarchy Descriptor'
class GAlignmentInfo: public GBaseInfo
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

    // Override methods

    // win1.41 00414120 mac 100a42b0 GAlignmentInfo::_dt(void)
    virtual ~GAlignmentInfo();
    // win1.41 004140c0 mac 100a4bb0 GAlignmentInfo::GetBaseInfo(unsigned long &)
    virtual GBaseInfo* GetBaseInfo(uint32_t& param_1);
};

#else // __cplusplus

// Forward Declares

struct Base;

struct GAlignmentInfo
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
};
static_assert(sizeof(struct GAlignmentInfo) == 0x48, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 009c8340 mac inlined GAlignmentInfo::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__14GAlignmentInfo asm("??_R0?AVGAlignmentInfo@@@8");
// win1.41 009a69c8 mac inlined GAlignmentInfo::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__14GAlignmentInfo asm("??_R1A@?0A@A@GAlignmentInfo@@8");
// win1.41 009a69e0 mac inlined GAlignmentInfo::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__14GAlignmentInfo asm("??_R2GAlignmentInfo@@8");
// win1.41 009a69f0 mac inlined GAlignmentInfo::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__14GAlignmentInfo asm("??_R3GAlignmentInfo@@8");

// Override methods

// win1.41 00414120 mac 100a42b0 GAlignmentInfo::_dt(void)
void __fastcall __dt__14GAlignmentInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGAlignmentInfo@@UAEPAXI@Z");
// win1.41 004140c0 mac 100a4bb0 GAlignmentInfo::GetBaseInfo(unsigned long &)
struct GBaseInfo* __fastcall GetBaseInfo__14GAlignmentInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1) asm("?GetBaseInfo@GAlignmentInfo@@UAEPAVGBaseInfo@@AAI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_ALIGNMENT_INFO_INCLUDED_H */

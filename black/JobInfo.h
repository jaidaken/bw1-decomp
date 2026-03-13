#ifndef BW1_DECOMP_JOB_INFO_INCLUDED_H
#define BW1_DECOMP_JOB_INFO_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "BaseInfo.h" /* For struct GBaseInfo */

#ifdef __cplusplus

// Forward Declares

class Base;

// win1.41 00bf3328 mac inlined GJobInfo::`RTTI Type Descriptor'
// win1.41 009b17d8 mac inlined GJobInfo::`RTTI Base Class Descriptor'
// win1.41 009b17f0 mac inlined GJobInfo::`RTTI Base Class Array'
// win1.41 009b1800 mac inlined GJobInfo::`RTTI Class Hierarchy Descriptor'
class GJobInfo: public GBaseInfo
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

    // Override methods

    // win1.41 005e1720 mac 100fe5c0 GJobInfo::_dt(void)
    virtual ~GJobInfo();
    // win1.41 005e16c0 mac 100fe6d0 GJobInfo::GetBaseInfo(unsigned long &)
    virtual GBaseInfo* GetBaseInfo(uint32_t& param_1);

    // Non-virtual methods

    // win1.41 005e1740 mac 100fe450 GJobInfo::GetJobActivity(void) const
    uint32_t GetJobActivity() const;
};

#else // __cplusplus

// Forward Declares

struct Base;

struct GJobInfo
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
};
static_assert(sizeof(struct GJobInfo) == 0x58, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 00bf3328 mac inlined GJobInfo::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__8GJobInfo asm("??_R0?AVGJobInfo@@@8");
// win1.41 009b17d8 mac inlined GJobInfo::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__8GJobInfo asm("??_R1A@?0A@A@GJobInfo@@8");
// win1.41 009b17f0 mac inlined GJobInfo::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__8GJobInfo asm("??_R2GJobInfo@@8");
// win1.41 009b1800 mac inlined GJobInfo::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__8GJobInfo asm("??_R3GJobInfo@@8");

// Non-virtual methods

// win1.41 005e1740 mac 100fe450 GJobInfo::GetJobActivity(void) const
uint32_t __fastcall GetJobActivity__8GJobInfoCFv(const struct GJobInfo* this) asm("?GetJobActivity@GJobInfo@@QBEIXZ");

// Override methods

// win1.41 005e1720 mac 100fe5c0 GJobInfo::_dt(void)
void __fastcall __dt__8GJobInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGJobInfo@@UAEPAXI@Z");
// win1.41 005e16c0 mac 100fe6d0 GJobInfo::GetBaseInfo(unsigned long &)
struct GBaseInfo* __fastcall GetBaseInfo__8GJobInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1) asm("?GetBaseInfo@GJobInfo@@UAEPAVGBaseInfo@@AAI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_JOB_INFO_INCLUDED_H */

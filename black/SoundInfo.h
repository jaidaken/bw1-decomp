#ifndef BW1_DECOMP_SOUND_INFO_INCLUDED_H
#define BW1_DECOMP_SOUND_INFO_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "BaseInfo.h" /* For struct GBaseInfo */

#ifdef __cplusplus

// Forward Declares

class Base;

// win1.41 00c223b0 mac inlined GSoundInfo::`RTTI Type Descriptor'
// win1.41 009b91a8 mac inlined GSoundInfo::`RTTI Base Class Descriptor'
// win1.41 009b91c0 mac inlined GSoundInfo::`RTTI Base Class Array'
// win1.41 009b91d0 mac inlined GSoundInfo::`RTTI Class Hierarchy Descriptor'
class GSoundInfo: public GBaseInfo
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

    // Override methods

    // win1.41 0071d6b0 mac 105135d0 GSoundInfo::_dt(void)
    virtual ~GSoundInfo();
    // win1.41 0071d660 mac 10513590 GSoundInfo::GetBaseInfo(unsigned long &)
    virtual GBaseInfo* GetBaseInfo(uint32_t& param_1);
};

#else // __cplusplus

// Forward Declares

struct Base;

struct GSoundInfo
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
};
static_assert(sizeof(struct GSoundInfo) == 0x4c, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 00c223b0 mac inlined GSoundInfo::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__10GSoundInfo asm("??_R0?AVGSoundInfo@@@8");
// win1.41 009b91a8 mac inlined GSoundInfo::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__10GSoundInfo asm("??_R1A@?0A@A@GSoundInfo@@8");
// win1.41 009b91c0 mac inlined GSoundInfo::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__10GSoundInfo asm("??_R2GSoundInfo@@8");
// win1.41 009b91d0 mac inlined GSoundInfo::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__10GSoundInfo asm("??_R3GSoundInfo@@8");

// Override methods

// win1.41 0071d6b0 mac 105135d0 GSoundInfo::_dt(void)
void __fastcall __dt__10GSoundInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGSoundInfo@@UAEPAXI@Z");
// win1.41 0071d660 mac 10513590 GSoundInfo::GetBaseInfo(unsigned long &)
struct GBaseInfo* __fastcall GetBaseInfo__10GSoundInfoFRUl(struct GBaseInfo* this, const void* edx, uint32_t* param_1) asm("?GetBaseInfo@GSoundInfo@@UAEPAVGBaseInfo@@AAI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_SOUND_INFO_INCLUDED_H */

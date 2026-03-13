#ifndef BW1_DECOMP_CHAIN_INCLUDED_H
#define BW1_DECOMP_CHAIN_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "PSysBase.h" /* For struct PSysBase */

#ifdef __cplusplus

// Forward Declares

class Base;
class GameOSFile;
class GameThing;

// win1.41 00c095a8 mac inlined Chain::`RTTI Type Descriptor'
// win1.41 009b8078 mac inlined Chain::`RTTI Base Class Descriptor'
// win1.41 009b8090 mac inlined Chain::`RTTI Base Class Array'
// win1.41 009b80a8 mac inlined Chain::`RTTI Class Hierarchy Descriptor'
class Chain: public PSysBase
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

    // Override methods

    // win1.41 006c8810 mac 1047b970 Chain::_dt(void)
    virtual ~Chain();
    // win1.41 006c8800 mac 10422b00 Chain::GetDebugText(void)
    virtual char* GetDebugText();
    // win1.41 00695c10 mac 1041bda0 Chain::Load(GameOSFile &)
    virtual bool32_t Load(GameOSFile& param_1);
    // win1.41 006cc780 mac 10483590 Chain::Save(GameOSFile &)
    virtual bool32_t Save(GameOSFile& param_1);
    // win1.41 006c87f0 mac 10422ad0 Chain::GetSaveType(void)
    virtual uint32_t GetSaveType();
};

#else // __cplusplus

// Forward Declares

struct Base;
struct GameOSFile;
struct GameThing;

struct Chain
{
  struct PSysBase super;  /* 0x0 */
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
};
static_assert(sizeof(struct Chain) == 0x50, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 00c095a8 mac inlined Chain::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__5Chain asm("??_R0?AVChain@@@8");
// win1.41 009b8078 mac inlined Chain::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__5Chain asm("??_R1A@?0A@A@Chain@@8");
// win1.41 009b8090 mac inlined Chain::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__5Chain asm("??_R2Chain@@8");
// win1.41 009b80a8 mac inlined Chain::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__5Chain asm("??_R3Chain@@8");

// Override methods

// win1.41 006c8810 mac 1047b970 Chain::_dt(void)
void __fastcall __dt__5ChainFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GChain@@UAEPAXI@Z");
// win1.41 006c8800 mac 10422b00 Chain::GetDebugText(void)
char* __fastcall GetDebugText__5ChainFv(struct GameThing* this) asm("?GetDebugText@Chain@@UAEPADXZ");
// win1.41 00695c10 mac 1041bda0 Chain::Load(GameOSFile &)
uint32_t __fastcall Load__5ChainFR10GameOSFile(struct GameThing* this, const void* edx, struct GameOSFile* param_1) asm("?Load@Chain@@UAEIAAVGameOSFile@@@Z");
// win1.41 006cc780 mac 10483590 Chain::Save(GameOSFile &)
uint32_t __fastcall Save__5ChainFR10GameOSFile(struct GameThing* this, const void* edx, struct GameOSFile* param_1) asm("?Save@Chain@@UAEIAAVGameOSFile@@@Z");
// win1.41 006c87f0 mac 10422ad0 Chain::GetSaveType(void)
uint32_t __fastcall GetSaveType__5ChainFv(struct GameThing* this) asm("?GetSaveType@Chain@@UAEIXZ");

#endif // __cplusplus

#endif /* BW1_DECOMP_CHAIN_INCLUDED_H */

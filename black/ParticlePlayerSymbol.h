#ifndef BW1_DECOMP_PARTICLE_PLAYER_SYMBOL_INCLUDED_H
#define BW1_DECOMP_PARTICLE_PLAYER_SYMBOL_INCLUDED_H

#include <assert.h> /* For static_assert */
#include <stdint.h> /* For uint32_t */

#include <reversing_utils/re_rtti.h> /* For struct RTTIBaseClassArray, struct RTTIBaseClassDescriptor, struct RTTIClassHierarchyDescriptor, struct RTTITypeDescriptor */

#include "PSysRenderParticle.h" /* For struct RenderParticle */

#ifdef __cplusplus

// Forward Declares

class Base;

// win1.41 00c09640 mac inlined ParticlePlayerSymbol::`RTTI Type Descriptor'
// win1.41 009b81e0 mac inlined ParticlePlayerSymbol::`RTTI Base Class Descriptor'
// win1.41 009b81f8 mac inlined ParticlePlayerSymbol::`RTTI Base Class Array'
// win1.41 009b8210 mac inlined ParticlePlayerSymbol::`RTTI Class Hierarchy Descriptor'
class ParticlePlayerSymbol: public RenderParticle
{
public:
    uint32_t field_0x18; /* 0x18 */
    uint32_t field_0x1c; /* 0x1c */

    // Override methods

    // win1.41 006c9d50 mac 1047a0b0 ParticlePlayerSymbol::_dt(void)
    virtual ~ParticlePlayerSymbol();
};

#else // __cplusplus

// Forward Declares

struct Base;

struct ParticlePlayerSymbol
{
  struct RenderParticle super;  /* 0x0 */
  uint32_t field_0x18;  /* 0x18 */
  uint32_t field_0x1c;  /* 0x1c */
};
static_assert(sizeof(struct ParticlePlayerSymbol) == 0x20, "Data type is of wrong size");

// Object Oriented datastructures

// win1.41 00c09640 mac inlined ParticlePlayerSymbol::`RTTI Type Descriptor'
extern struct RTTITypeDescriptor __RTTITypeDescriptor__20ParticlePlayerSymbol asm("??_R0?AVParticlePlayerSymbol@@@8");
// win1.41 009b81e0 mac inlined ParticlePlayerSymbol::`RTTI Base Class Descriptor'
extern const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__20ParticlePlayerSymbol asm("??_R1A@?0A@A@ParticlePlayerSymbol@@8");
// win1.41 009b81f8 mac inlined ParticlePlayerSymbol::`RTTI Base Class Array'
extern const struct RTTIBaseClassArray __RTTIBaseClassArray__20ParticlePlayerSymbol asm("??_R2ParticlePlayerSymbol@@8");
// win1.41 009b8210 mac inlined ParticlePlayerSymbol::`RTTI Class Hierarchy Descriptor'
extern const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__20ParticlePlayerSymbol asm("??_R3ParticlePlayerSymbol@@8");

// Override methods

// win1.41 006c9d50 mac 1047a0b0 ParticlePlayerSymbol::_dt(void)
void __fastcall __dt__20ParticlePlayerSymbolFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GParticlePlayerSymbol@@UAEPAXI@Z");

#endif // __cplusplus

#endif /* BW1_DECOMP_PARTICLE_PLAYER_SYMBOL_INCLUDED_H */

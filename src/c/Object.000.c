#include "Object.h"
#include "ObjectInfo.h"

__attribute__((aligned(8)))
struct RTTITypeDescriptor __RTTITypeDescriptor__6Object = {
    .pVFTable = &__vt__9type_info,
    .spare = 0,
    .name = ".?AVObject@@",
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__6Object = {
    .pTypeDescriptor = &__RTTITypeDescriptor__6Object,
    .numContainedBases = 0x00000003,
    .where = {
        .mdisp = 0x00000000,
        .pdisp = 0xFFFFFFFF,
        .vdisp = 0x00000000,
    },
    .attributes = 0x0000000,
};

float __fastcall GetXAngle__6ObjectFv(struct Object* this)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

float __fastcall GetYAngle__6ObjectFv(struct Object* this)
{
    return this->y_angle;
}

float __fastcall GetZAngle__6ObjectFv(struct Object* this)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

float __fastcall GetScale__6ObjectFv(struct GameThingWithPos* this)
{
    return ((struct Object*)this)->scale;
}

__attribute__((no_callee_saves, trailing_asm("call               dword ptr [__imp__DirectDrawCreate@4]"), ret_cleanup_override(0x0004)))
void __fastcall SetJustScale__6ObjectFf(struct Object* this, const void* edx, float scale)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x50], eax"
        ::: "eax", "ecx", "edx", "memory"
    );
}

void __fastcall UpdateFrom3DPosition__6ObjectFv(struct Object* this)
{
    return;
}

uint32_t __fastcall MoveAlongPath__6ObjectFv(struct Object* this)
{
    return 1;
}

__attribute__((no_ret))
bool __fastcall IsReachable__6ObjectFv(struct Object* this)
{
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "%{disp8%} jmp dword ptr [eax + 0x2c]"
        : : "c"(this) : "eax", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((MOV32rr_REV))
struct Object* __fastcall GetPtr__6ObjectFv(struct Object* this)
{
    return this;
}

struct Game3DObject* __fastcall Get3DObjectForPSys__6ObjectFv(struct Object* this)
{
    return this->game_3d_object;
}

float __fastcall GetSpotEffectPower__6ObjectFv(const struct Object* this)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

float __fastcall GetHoldYRotate__6ObjectFv(struct Object* this)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

bool32_t __fastcall HandShouldFeelWithMeshIntersect__6ObjectFv(struct Object* this)
{
    return 1;
}

void __fastcall SetSpecularColor__6ObjectFUl(struct Object* this, const void* edx, struct LH3DColor color)
{
    return;
}

__attribute__((XOR32rr_REV))
struct LH3DColor __fastcall GetSpecularColor__6ObjectFv(struct Object* this)
{
    struct LH3DColor result = {};
    return result;
}

void __fastcall SetBeliefSprite__6ObjectFP12BeliefSprite(struct Object* this, const void* edx, struct LH3DSprite* sprite)
{
    return;
}

__attribute__((XOR32rr_REV))
struct LH3DSprite* __fastcall GetBeliefSprite__6ObjectFv(struct Object* this)
{
    return 0;
}

float __fastcall GetLife__6ObjectFv(struct GameThingWithPos* this)
{
    return ((struct Object*)this)->life;
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsAlive__6ObjectFv(struct Object* this)
{
    bool32_t result;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x11c]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x0040263a\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x2c]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0040263a\n\t"
        "mov                eax, 0x00000001\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x0040263a:\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

void __fastcall ScaffoldMoved__6ObjectFP8Scaffold(struct Object* this, const void* edx, struct Scaffold* scaffold)
{
    return;
}

uint32_t __fastcall ProcessBySpell__6ObjectFP5Spell(struct Object* this, const void* edx, struct Spell* spell)
{
    return 1;
}

__attribute__((no_callee_saves, trailing_asm("call ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z + 9"), ret_cleanup_override(0x0004)))
int __fastcall GetDetailMesh__6ObjectCF12DETAIL_LEVEL(struct Object* this, const void* edx, int detail)
{
    int result;
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "call dword ptr [eax + 0x608]"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool __fastcall IsG3DObjectDrawnInHand__6ObjectFv(struct Object* this)
{
    return true;
}

void __fastcall GetDrawRegion__6ObjectFP8LHRegion(struct Object* this, const void* edx, struct LHRegion* param_1)
{
    return;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall ProcessState__6ObjectFv(struct Object* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool __fastcall CanBePickedUp__6ObjectFv(struct Object* this)
{
    return 0;
}

float __fastcall GetVillagerHugRadius__6ObjectFv(struct Object* this)
{
    float result;
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "call dword ptr [eax + 0x64]\n\t"
        "%{disp32%} fmul dword ptr [_rdata_float1p05]\n\t"
        "%{disp32%} fadd dword ptr [_rdata_float0p0005]"
        : "=t"(result) : "c"(this) : "eax", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, ret_cleanup_override(0x0004)))
float __fastcall GetFoodValue__6ObjectF9FOOD_TYPE(struct Object* this, const void* edx, enum FOOD_TYPE type)
{
    float result;
    asm volatile (
        "push esi\n\t"
        "mov.s esi, ecx\n\t"
        "mov eax, dword ptr [esi]\n\t"
        "call dword ptr [eax + 0x668]\n\t"
        "test dword ptr [esp + 0x08], eax\n\t"
        "%{disp8%} je 0f\n\t"
        "%{disp8%} mov ecx, dword ptr [esi + 0x28]\n\t"
        "%{disp8%} fld dword ptr [ecx + 0x68]\n\t"
        "pop esi\n\t"
        "ret 0x0004\n"
        "0:\n\t"
        "%{disp32%} fld dword ptr [_rdata_float0p0]\n\t"
        "pop esi"
        : "=t"(result) :: "eax", "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_ret))
enum FOOD_TYPE __fastcall GetFoodType__6ObjectFv(struct Object* this)
{
    asm volatile (
        "%{disp8%} mov ecx, dword ptr [ecx + 0x28]\n\t"
        "mov eax, dword ptr [ecx]\n\t"
        "%{disp8%} jmp dword ptr [eax + 0x38]"
        : : "c"(this) : "eax", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV, no_callee_saves))
bool32_t __fastcall IsMoving__6ObjectCFv(const struct GameThingWithPos* this)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x14]\n\t"
        "cmp                eax, dword ptr [ecx + 0x2c]\n\t"
        "%{disp8%} jne        LAB__addr_0x00402723\n\t"
        "%{disp8%} mov        edx, dword ptr [ecx + 0x18]\n\t"
        "cmp                edx, dword ptr [ecx + 0x30]\n\t"
        "%{disp8%} jne        LAB__addr_0x00402723\n\t"
        "xor.s              eax, eax\n\t"
        "ret\n"
        "LAB__addr_0x00402723:\n\t"
        "mov                eax, 0x00000001"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsSpellSeedReturnPoint__6ObjectCFv(const struct Object* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall IsABeliever__6ObjectFv(struct Object* this)
{
    return 0;
}

__attribute__((prefer_or_minus_one))
enum RESOURCE_TYPE __fastcall GetResourceType__6ObjectFv(struct Object* this)
{
    return (enum RESOURCE_TYPE)-1;
}

__attribute__((XOR32rr_REV))
int __fastcall GetDefaultResource__6ObjectFv(struct Object* this)
{
    return 0;
}

void __fastcall SetPoisonedResource__6ObjectF13RESOURCE_TYPEi(struct Object* this, const void* edx, enum RESOURCE_TYPE type, int param_2)
{
    return;
}

void __fastcall SetPoisoned__6ObjectFi(struct Object* this, const void* edx, int param_1)
{
    return;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsLockedInInteract__6ObjectFv(struct Object* this)
{
    return 0;
}

bool32_t __fastcall SetDying__6ObjectFv(struct Object* this)
{
    void* dummy;
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "push 0x0\n\t"
        "call dword ptr [eax + 0xc]"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
    return 1;
}

void __fastcall EndOnFire__6ObjectFv(struct Object* this)
{
    return;
}

float __fastcall GetDistanceFromObject__6ObjectFRC9MapCoords(struct GameThingWithPos* this, const void* edx, const struct MapCoords* target)
{
    void* dummy;
    float result;
    asm volatile (
        "push eax\n\t"
        "call ?GetDistanceFromObject@GameThingWithPos@@UBEMPAUMapCoords@@@Z"
        : "=t"(result), "=c"(dummy) : "c"(this), "a"(target) : "edx", "memory"
    );
    return result;
}

bool32_t __fastcall NetworkUnfriendlyStartLockedSelect__6ObjectFv(struct Object* this)
{
    return 1;
}

bool32_t __fastcall IsReadyForNetworkUnfriendlyLockedSelect__6ObjectFv(struct Object* this)
{
    return 1;
}

bool32_t __fastcall NetworkUnfriendlyLockedSelect__6ObjectFP21ControlHandUpdateInfo(struct Object* this, const void* edx, struct ControlHandUpdateInfo* param_1)
{
    return 1;
}

bool32_t __fastcall GetReadyForNetworkUnfriendlyEndLockedSelect__6ObjectFv(struct Object* this)
{
    return 1;
}

bool32_t __fastcall IsReadyForNetworkUnfriendlyEndLockedSelect__6ObjectFv(struct Object* this)
{
    return 1;
}

bool32_t __fastcall NetworkUnfriendlyEndLockedSelect__6ObjectFv(struct Object* this)
{
    return 1;
}

bool32_t __fastcall NetworkFriendlyEndLockedSelect__6ObjectFP16GInterfaceStatus(struct Object* this, const void* edx, struct GInterfaceStatus* status)
{
    return 1;
}

bool32_t __fastcall ValidAsInterfaceTarget__6ObjectFv(struct Object* this)
{
    return 1;
}

bool32_t __fastcall ValidAsInterfaceLeashTarget__6ObjectFv(struct Object* this)
{
    return 1;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall SelectOnlyAfterRecSystem__6ObjectFv(struct Object* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall ValidForPlaceInHand__6ObjectFP16GInterfaceStatus(struct Object* this, const void* edx, struct GInterfaceStatus* status)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall ValidToRemoveFromHand__6ObjectFP16GInterfaceStatusRC9MapCoords(struct Object* this, const void* edx, struct GInterfaceStatus* status, const struct MapCoords* param_2)
{
    return 0;
}

uint32_t __fastcall RemoveFromHand__6ObjectFP16GInterfaceStatusRC9MapCoords(struct Object* this, const void* edx, struct GInterfaceStatus* status, const struct MapCoords* param_2)
{
    return 0x17;
}

bool32_t __fastcall InterfaceMustBeInInfluenceForInteraction__6ObjectFv(struct Object* this)
{
    return 1;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall ValidToApplyThisToObject__6ObjectFP16GInterfaceStatusP6Object(struct Object* this, const void* edx, struct GInterfaceStatus* status, struct Object* param_2)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall ApplyThisToObject__6ObjectFP16GInterfaceStatusP6ObjectP23GestureSystemPacketData(struct Object* this, const void* edx, struct GInterfaceStatus* status, struct Object* param_2, struct GestureSystemPacketData* param_3)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall ValidToApplyThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoords(struct Object* this, const void* edx, struct GInterfaceStatus* status, const struct MapCoords* param_2)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall ApplyThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoordsP23GestureSystemPacketData(struct Object* this, const void* edx, struct GInterfaceStatus* status, const struct MapCoords* param_2, struct GestureSystemPacketData* param_3)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall ValidForLockedApplyProcess__6ObjectFP16GInterfaceStatus(struct Object* this, const void* edx, struct GInterfaceStatus* status)
{
    return 0;
}

uint32_t __fastcall ApplyUnlockProcess__6ObjectFP16GInterfaceStatus(struct Object* this, const void* edx, struct GInterfaceStatus* status)
{
    return 1;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall IsInterfacePowerUpWhenInHand__6ObjectCFv(const struct Object* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall ApplyOnlyAfterRecSystem__6ObjectFv(struct Object* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall ApplyOnlyAfterReleased__6ObjectFv(struct Object* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall InterfaceValidToGiveObject__6ObjectFP16GInterfaceStatusP6Object(struct Object* this, const void* edx, struct GInterfaceStatus* status, struct Object* param_2)
{
    return 0;
}

uint32_t __fastcall InterfaceGiveObject__6ObjectFP16GInterfaceStatusP6Object(struct Object* this, const void* edx, struct GInterfaceStatus* status, struct Object* param_2)
{
    return 0x16;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall InterfaceValidToInteractAsMapCoordsObject__6ObjectFP16GInterfaceStatus(struct Object* this, const void* edx, struct GInterfaceStatus* status)
{
    return 0;
}

uint32_t __fastcall InterfaceInteractAsMapCoordsObject__6ObjectFP16GInterfaceStatus(struct Object* this, const void* edx, struct GInterfaceStatus* status)
{
    return 1;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall ValidToSelectFightThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoords(struct Object* this, const void* edx, struct GInterfaceStatus* status, const struct MapCoords* param_2)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall ValidToApplyFightThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoords(struct Object* this, const void* edx, struct GInterfaceStatus* status, const struct MapCoords* param_2)
{
    return 0;
}

uint32_t __fastcall SelectFightThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoords(struct Object* this, const void* edx, struct GInterfaceStatus* status, const struct MapCoords* param_2)
{
    return 1;
}

uint32_t __fastcall ApplyFightThisToMapCoord__6ObjectFP16GInterfaceStatusRC9MapCoords(struct Object* this, const void* edx, struct GInterfaceStatus* status, const struct MapCoords* param_2)
{
    return 1;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall ValidToFightThisToObject__6ObjectFP16GInterfaceStatusRC9MapCoords(struct Object* this, const void* edx, struct GInterfaceStatus* status, const struct MapCoords* param_2)
{
    return 0;
}

uint32_t __fastcall FightThisToObject__6ObjectFP16GInterfaceStatusP6Object(struct Object* this, const void* edx, struct GInterfaceStatus* status, struct Object* param_2)
{
    return 1;
}

bool32_t __fastcall IsEffectReceiver__6ObjectFP12EffectValues(struct Object* this, const void* edx, struct EffectValues* param_1)
{
    return 1;
}

bool32_t __fastcall IsObject__6ObjectCFv(struct GameThingWithPos* this)
{
    return 1;
}

__attribute__((XOR32rr_REV, prefer_xor8))
uint32_t __fastcall PhysicallyDestroysAbodes__6ObjectFv(struct Object* this)
{
    return 0;
}

__attribute__((XOR32rr_REV, prefer_xor8, no_bool_mask))
bool __fastcall GetAlwaysRemainsInPhysicsInternalSystem__6ObjectFv(struct Object* this)
{
    return false;
}

__attribute__((no_callee_saves, trailing_asm("call               dword ptr [__imp__DirectInputCreateA@4]")))
bool32_t __fastcall IsSuitableForCreatureAction__6ObjectFv(struct GameThingWithPos* this)
{
    bool32_t result = *(bool32_t*)((char*)*(void**)((char*)this + 0x28) + 0xc0);
    return result;
}

bool32_t __fastcall CanBePoodOn__6ObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 1;
}

__attribute__((XOR32rr_REV, no_callee_saves, ret_cleanup_override(0x0004)))
bool32_t __fastcall CanBeAttackedByCreature__6ObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    bool32_t result;
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [ecx + 0x28]\n\t"
        "%{disp32%} mov       edx, dword ptr [eax + 0x000000c4]\n\t"
        "test               edx, edx\n\t"
        "%{disp8%} je         LAB__addr_0x00402a5b\n\t"
        "cmp                dword ptr [esp + 0x04], ecx\n\t"
        "%{disp8%} je         LAB__addr_0x00402a5b\n\t"
        "mov                eax, 0x00000001\n\t"
        "ret                0x0004\n"
        "LAB__addr_0x00402a5b:\n\t"
        "xor.s              eax, eax"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

bool32_t __fastcall CanBePlayedWithByCreature__6ObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return ((struct Object*)this)->info->canCreaturePlayWithMe;
}

__attribute__((XOR32rr_REV))
bool32_t __fastcall CanBeImpressedByCreature__6ObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 0;
}

bool32_t __fastcall CanBeHelpedByCreature__6ObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 1;
}

bool32_t __fastcall CanBeExaminedByCreature__6ObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    return 1;
}

bool32_t __fastcall IsOnFire__6ObjectFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* creature)
{
    void* dummy;
    bool32_t result;
    asm volatile ("call _jmp_addr_0x00637cc0" : "=a"(result), "=c"(dummy) : "c"(this) : "edx", "memory");
    return result;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetTastiness__6ObjectFv(struct Object* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsScary__6ObjectFv(struct Object* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetObjectCollide__6ObjectFv(struct Object* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsPushable__6ObjectFv(struct Object* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetCarriedTreeType__6ObjectFv(struct Object* this)
{
    return 0;
}

float __fastcall GetFacingPitch__6ObjectFv(struct Object* this)
{
    extern const float rdata_float0p0;
    return rdata_float0p0;
}

__attribute__((no_callee_saves, trailing_asm("call               dword ptr [__imp___ChangeParameters_CImmPeriodic__QAEHKKKJJJKPAUFEELIT_ENVELOPE___Z@4]"), ret_cleanup_override(0x0004)))
void __fastcall SetHeadPos__6ObjectFP9MapCoords(struct Object* this, const void* edx, struct MapCoords* param_1)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "add                ecx, 0x14\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "mov                dword ptr [eax], edx\n\t"
        "%{disp8%} mov        edx, dword ptr [ecx + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x04], edx\n\t"
        "%{disp8%} mov        ecx, dword ptr [ecx + 0x08]\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x08], ecx"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV))
bool __fastcall IsAPotFromABuildingSite__6ObjectFv(struct Object* this)
{
    return 0;
}

const char* __fastcall GetText__6ObjectFv(struct GameThingWithPos* this)
{
    return ((struct Object*)this)->info->debugString;
}

__attribute__((prefer_or_minus_one))
uint32_t __fastcall StandAnimation__6ObjectFv(struct Object* this)
{
    return 0xFFFFFFFF;
}

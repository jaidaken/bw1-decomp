#include "Citadel.h"
#include "CitadelHeart.h"
#include "CitadelPart.h"
#include "CitadelEntrance.h"
#include "PlannedCitadelPart.h"
#include "PlannedCitadelHeart.h"
#include "PlannedTownCitadelHeart.h"
#include "PSysBase.h"
#include "Plasma.h"
#include "FireGraphic.h"
#include "WorshipSiteInfo.h"
#include "ContainerInfo.h"
#include "Container.h"
#include "PlannedMultiMapFixed.h"

// Forward declarations with asm labels for functions not declared in headers
uint32_t __fastcall GetSaveType__12UR_PlasmaInfFv(struct GameThing* this) asm("?GetSaveType@UR_PlasmaInf@@UAEIXZ");
char* __fastcall GetDebugText__12UR_PlasmaInfFv(struct GameThing* this) asm("?GetDebugText@UR_PlasmaInf@@UAEPADXZ");
uint32_t __fastcall GetSaveType_SpritePos_FireGraphic(struct GameThing* this) asm("?GetSaveType@SpritePos@FireGraphic@@UAEIXZ");
enum ABODE_TYPE __fastcall GetAbodeType_GWorshipSiteInfo(const struct MultiMapFixed* this) asm("?GetAbodeType@GWorshipSiteInfo@@UBE?AW4ABODE_TYPE@@XZ");

void __fastcall __dt__12GCitadelInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGCitadelInfo@@UAEPAXI@Z");

void __fastcall __dt__17GCitadelHeartInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGCitadelHeartInfo@@UAEPAXI@Z");

void __fastcall __dt__8LeashObjFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GLeashObj@@UAEPAXI@Z");

void __fastcall __dt__19PlannedCitadelHeartFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GPlannedCitadelHeart@@UAEPAXI@Z");

void __fastcall __dt__8PSysBaseFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GPSysBase@@UAEPAXI@Z");

void __fastcall __dt__12UR_PlasmaInfFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GUR_PlasmaInf@@UAEPAXI@Z");

void __fastcall __dt__23PlannedTownCitadelHeartFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GPlannedTownCitadelHeart@@UAEPAXI@Z");

void __fastcall __dt__11CitadelPartFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GCitadelPart@@UAEPAXI@Z");

void __fastcall __dt__18PlannedCitadelPartFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GPlannedCitadelPart@@UAEPAXI@Z");

void __fastcall __dt__14GContainerInfoFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GGContainerInfo@@UAEPAXI@Z");

void __fastcall __dt__9ContainerFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GContainer@@UAEPAXI@Z");

void __fastcall __dt__7CitadelFv(struct Base* this, const void* edx, uint32_t param_1) asm("??_GCitadel@@UAEPAXI@Z");

// ====== Citadel getters ======

uint32_t __fastcall GetCreatureBeliefType__7CitadelFv(struct GameThingWithPos* this)
{
    return 2;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetCreatureBeliefListType__7CitadelFv(struct GameThingWithPos* this)
{
    return 0;
}

uint32_t __fastcall GetOrigin__7CitadelFv(struct GameThingWithPos* this)
{
    return 2;
}

uint32_t __fastcall IsSuitableForCreatureActivity__7CitadelFv(struct GameThingWithPos* this)
{
    return 1;
}

const char* __fastcall GetText__7CitadelFv(struct GameThingWithPos* this)
{
    return (const char*)0x009ce038;
}

uint32_t __fastcall IsCitadel__7CitadelFv(struct GameThingWithPos* this)
{
    return 1;
}

uint32_t __fastcall GetSaveType__7CitadelFv(struct GameThing* this)
{
    return 0x35;
}

char* __fastcall GetDebugText__7CitadelFv(struct GameThing* this)
{
    return (char*)0x009ce860;
}

// ====== Citadel sdtor ======

__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,128,")))
void __fastcall __dt__7CitadelFv(struct Base* this, const void* edx, uint32_t param_1)
{}

// ====== CitadelHeart getters ======

enum LH3DObject__ObjectType __fastcall Get3DType__12CitadelHeartFv(struct Object* this)
{
    return 8;
}

enum ABODE_TYPE __fastcall GetAbodeType__12CitadelHeartFv(struct MultiMapFixed* this)
{
    return 0x804;
}

__attribute__((XOR32rr_REV))
bool __fastcall ShouldFootpathsGoRound__12CitadelHeartFv(struct Object* this)
{
    return 0;
}

uint32_t __fastcall IsCitadelHeart__12CitadelHeartFv(struct GameThingWithPos* this)
{
    return 1;
}

uint32_t __fastcall GetSaveType__12CitadelHeartFv(struct GameThing* this)
{
    return 0x3a;
}

char* __fastcall GetDebugText__12CitadelHeartFv(struct GameThing* this)
{
    return (char*)0x009cea00;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetPhysicsConstantsType__12CitadelHeartFv(struct Object* this)
{
    return 0;
}

uint32_t __fastcall GetScriptObjectType__12CitadelHeartFv(struct GameThingWithPos* this)
{
    return 0x12;
}

// ====== CitadelPart getters ======

uint32_t __fastcall GetCreatureBeliefType__11CitadelPartFv(struct GameThingWithPos* this)
{
    return 4;
}

uint32_t __fastcall IsCitadelPart_0__11CitadelPartFv(struct GameThingWithPos* this)
{
    return 1;
}

uint32_t __fastcall IsCitadelPart_1__11CitadelPartFP8Creature(struct GameThingWithPos* this, const void* edx, struct Creature* param_1)
{
    return 1;
}

uint32_t __fastcall Process__11CitadelPartFv(struct Object* this)
{
    return 1;
}

__attribute__((XOR32rr_REV))
struct PlannedMultiMapFixed* __fastcall ConvertToPlanned__11CitadelPartFv(struct MultiMapFixed* this)
{
    return 0;
}

enum LH3DObject__ObjectType __fastcall Get3DType__11CitadelPartFv(struct Object* this)
{
    return 1;
}

uint32_t __fastcall GetSaveType__11CitadelPartFv(struct GameThing* this)
{
    return 0x36;
}

char* __fastcall GetDebugText__11CitadelPartFv(struct GameThing* this)
{
    return (char*)0x009ceb34;
}

bool __fastcall ShouldFootpathsGoRound__11CitadelPartFv(struct Object* this)
{
    return 1;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall SaveObject__11CitadelPartFR8LHOSFileRC9MapCoords(struct Object* this, const void* edx, struct LHOSFile* param_1, const struct MapCoords* param_2)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall CanBeDestroyedBySpell_1__11CitadelPartFP5Spell(struct Object* this, const void* edx, struct Spell* param_1)
{
    return 0;
}

// ====== CitadelEntrance getters ======

uint32_t __fastcall GetSaveType__15CitadelEntranceFv(struct GameThing* this)
{
    return 0x110;
}

char* __fastcall GetDebugText__15CitadelEntranceFv(struct GameThing* this)
{
    return (char*)0x009ceb20;
}

enum HELP_TEXT __fastcall GetQueryFirstEnumText__15CitadelEntranceFv(struct GameThingWithPos* this)
{
    return 0x7d0;
}

uint32_t __fastcall SaveObject__15CitadelEntranceFR8LHOSFileRC9MapCoords(struct Object* this, const void* edx, struct LHOSFile* param_1, const struct MapCoords* param_2)
{
    return 1;
}

// ====== LeashObj getters ======

__attribute__((XOR32rr_REV))
uint32_t __fastcall ValidAsInterfaceLeashTarget__8LeashObjFv(struct Object* this)
{
    return 0;
}

const char* __fastcall GetText__8LeashObjFv(struct GameThingWithPos* this)
{
    return (const char*)0x009ce9f4;
}

// ====== PlannedCitadelPart getters ======

uint32_t __fastcall GetSaveType__18PlannedCitadelPartFv(struct GameThing* this)
{
    return 0x37;
}

char* __fastcall GetDebugText__18PlannedCitadelPartFv(struct GameThing* this)
{
    return (char*)0x009cea5c;
}

// ====== PlannedTownCitadelHeart getters ======

__attribute__((XOR32rr_REV))
bool __fastcall IsCivic__23PlannedTownCitadelHeartFv(struct PlannedMultiMapFixed* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall IsWonder__23PlannedTownCitadelHeartFv(struct GameThingWithPos* this)
{
    return 0;
}

enum ABODE_TYPE __fastcall GetAbodeType__23PlannedTownCitadelHeartFv(struct PlannedMultiMapFixed* this)
{
    return 0x804;
}

uint32_t __fastcall GetSaveType__23PlannedTownCitadelHeartFv(struct GameThing* this)
{
    return 0x39;
}

char* __fastcall GetDebugText__23PlannedTownCitadelHeartFv(struct GameThing* this)
{
    return (char*)0x009ceae0;
}

// ====== PSysBase/UR_PlasmaInf getters ======

char* __fastcall GetDebugText__8PSysBaseFv(struct GameThing* this)
{
    return (char*)0x009ceaa8;
}

uint32_t __fastcall GetSaveType__12UR_PlasmaInfFv(struct GameThing* this)
{
    return 0xba;
}

char* __fastcall GetDebugText__12UR_PlasmaInfFv(struct GameThing* this)
{
    return (char*)0x009ceaa8;
}

// ====== FireGraphic ======

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetSaveType_SpritePos_FireGraphic(struct GameThing* this)
{
    return 0;
}

// ====== GWorshipSiteInfo ======

enum ABODE_TYPE __fastcall GetAbodeType_GWorshipSiteInfo(const struct MultiMapFixed* this)
{
    return 0x804;
}

// ====== PlannedMultiMapFixed ======

__attribute__((XOR32rr_REV))
bool __fastcall IsCivic__20PlannedMultiMapFixedFv(struct PlannedMultiMapFixed* this)
{
    return 0;
}

__attribute__((XOR32rr_REV))
bool __fastcall IsWonder__20PlannedMultiMapFixedFv(struct GameThingWithPos* this)
{
    return 0;
}

enum ABODE_TYPE __fastcall GetAbodeType__20PlannedMultiMapFixedFv(struct PlannedMultiMapFixed* this)
{
    return 1;
}

// ====== Scalar deleting destructors ======

__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,84,")))
void __fastcall __dt__12GCitadelInfoFv(struct Base* this, const void* edx, uint32_t param_1)
{}

__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,344,")))
void __fastcall __dt__17GCitadelHeartInfoFv(struct Base* this, const void* edx, uint32_t param_1)
{}

__attribute__((msvc6_sdtor("_jmp_addr_0x00636640,??3Base@@SAXPAXK@Z,120,")))
void __fastcall __dt__8LeashObjFv(struct Base* this, const void* edx, uint32_t param_1)
{}

__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void __fastcall __dt__19PlannedCitadelHeartFv(struct Base* this, const void* edx, uint32_t param_1)
{}

__attribute__((msvc6_sdtor("_jmp_addr_0x006759c0,_jmp_addr_0x00675940,20,")))
void __fastcall __dt__8PSysBaseFv(struct Base* this, const void* edx, uint32_t param_1)
{}

__attribute__((msvc6_sdtor("_jmp_addr_0x006759c0,_jmp_addr_0x00675940,80,")))
void __fastcall __dt__12UR_PlasmaInfFv(struct Base* this, const void* edx, uint32_t param_1)
{}

__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void __fastcall __dt__23PlannedTownCitadelHeartFv(struct Base* this, const void* edx, uint32_t param_1)
{}

__attribute__((msvc6_sdtor("_jmp_addr_0x00469530,??3Base@@SAXPAXK@Z,140,")))
void __fastcall __dt__11CitadelPartFv(struct Base* this, const void* edx, uint32_t param_1)
{}

__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void __fastcall __dt__18PlannedCitadelPartFv(struct Base* this, const void* edx, uint32_t param_1)
{}

__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,20,")))
void __fastcall __dt__14GContainerInfoFv(struct Base* this, const void* edx, uint32_t param_1)
{}

__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,48,")))
void __fastcall __dt__9ContainerFv(struct Base* this, const void* edx, uint32_t param_1)
{}

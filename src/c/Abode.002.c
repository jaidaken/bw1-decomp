#include "Abode.h"

__attribute__((aligned(8)))
struct RTTITypeDescriptor __RTTITypeDescriptor__5Abode = {
    .pVFTable = &__vt__9type_info,
    .spare = 0,
    .name = ".?AVAbode@@",
};

char abode_column[] = "Abode:\0";
char abode_file[] = "C:\\dev\\MP\\Black\\Abode.cpp\0";

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassDescriptor __RTTIBaseClassDescriptor__5Abode = {
    .pTypeDescriptor = &__RTTITypeDescriptor__5Abode,
    .numContainedBases = 0x00000006,
    .where = {
        .mdisp = 0x00000000,
        .pdisp = 0xFFFFFFFF,
        .vdisp = 0x00000000,
    },
    .attributes = 0x0000000,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIBaseClassArray __RTTIBaseClassArray__5Abode = {
    .arrayOfBaseClassDescriptors = {
        &__RTTIBaseClassDescriptor__5Abode,
        &__RTTIBaseClassDescriptor__13MultiMapFixed,
        &__RTTIBaseClassDescriptor__11FixedObject,
        &__RTTIBaseClassDescriptor__6Object,
        &__RTTIBaseClassDescriptor__16GameThingWithPos,
        &__RTTIBaseClassDescriptor__9GameThing,
        &__RTTIBaseClassDescriptor__4Base,
        NULL,
    }
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTIClassHierarchyDescriptor __RTTIClassHierarchyDescriptor__5Abode = {
  .signature = 0x00000000,
  .attributes = 0x00000000,
  .numBaseClasses = 0x00000007,
  .pBaseClassArray = &__RTTIBaseClassArray__5Abode,
};

__attribute__((section(".rdata$r"), aligned(8)))
const struct RTTICompleteObjectLocator __RTTICompleteObjectLocator__5Abode = {
  .signature = 0x00000000,
  .offset = 0x00000000,
  .cdOffset = 0x00000000,
  .pTypeDescriptor = &__RTTITypeDescriptor__5Abode,
  .pClassDescriptor = &__RTTIClassHierarchyDescriptor__5Abode,
};

void __fastcall __dt__5AbodeFv(struct Abode* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [esi + 0x0000008c]\n\t"
        "test               ecx, ecx\n\t"
        "push               edi\n\t"
        "mov                dword ptr [esi], 0x008a9a64\n\t"
        "%{disp8%} je         LAB__addr_0x00402b83\n\t"
        "call               ?Release@LH3DSmoke@@QAEXXZ\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000008c], 0x00000000\n\t"
        "LAB__addr_0x00402b83:\n\t"
        "%{disp32%} mov       edi, dword ptr [esi + 0x00000090]\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00402ba7\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ??1FragMesh@@QAE@XZ\n\t"
        "push               edi\n\t"
        "call                ??3@YAXPAX@Z\n\t"
        "add                esp, 0x04\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x00000090], 0x00000000\n\t"
        "LAB__addr_0x00402ba7:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x0052e280\n\t"
        "pop                edi\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((XOR32rr_REV, store_order("0xb6,0xb4,0xb7,0x94,0xbc,0xc0,0x8c,0x90,0x7c,0xb0,0xb5,0xb9")))
void __fastcall SetToZero__5AbodeFv(struct Abode* this)
{
    uint32_t zero = 0;
    asm volatile("" : "=a"(zero) : "0"(zero));
    *(uint8_t*)((char*)this + 0xb6) = (uint8_t)zero;
    *(uint8_t*)((char*)this + 0xb4) = (uint8_t)zero;
    *(uint8_t*)((char*)this + 0xb7) = (uint8_t)zero;
    *(uint32_t*)((char*)this + 0x94) = zero;
    *(uint32_t*)((char*)this + 0xbc) = zero;
    *(uint32_t*)((char*)this + 0xc0) = zero;
    *(uint32_t*)((char*)this + 0x8c) = zero;
    *(uint32_t*)((char*)this + 0x90) = zero;
    *(uint8_t*)((char*)this + 0x7c) = (uint8_t)zero;
    *(uint32_t*)((char*)this + 0xb0) = zero;
    *(uint8_t*)((char*)this + 0xb5) = (uint8_t)zero;
    *(uint8_t*)((char*)this + 0xb9) = (uint8_t)zero;
}

void __fastcall Delete__5AbodeFv(struct Base* this)
{
    void* dummy;
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x910]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00402c4c\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x14]\n\t"
        "test               ch, -0x80\n\t"
        "%{disp8%} jne        LAB__addr_0x00402c3d\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x90c]\n\t"
        "LAB__addr_0x00402c3d:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x00739a60\n\t"
        "LAB__addr_0x00402c4c:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?Delete@Object@@UAEXH@Z\n\t"
        "pop                esi"
        : "=c"(dummy) : "c"(this) : "eax", "edx", "memory"
    );
}

__attribute__((no_callee_saves))
void __fastcall ToBeDeleted__5AbodeFi(struct Base* this, const void* edx, int param_1)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "mov.s              edi, eax\n\t"
        "call               dword ptr [edx + 0x910]\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00402c98\n\t"
        "%{disp32%} mov       eax, dword ptr [_game]\n\t"
        "%{disp8%} mov        ecx, dword ptr [eax + 0x14]\n\t"
        "test               ch, -0x80\n\t"
        "%{disp8%} jne        LAB__addr_0x00402c98\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x90c]\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               _jmp_addr_0x00739a60\n"
        "LAB__addr_0x00402c98:\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?DeleteAbodeSurroundingObjects@Abode@@QAEXXZ\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x0c]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ToBeDeleted@MultiMapFixed@@UAEXH@Z\n\t"
        "pop                edi\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((forced_callee_saves("esi,edi"), force_this_esi, MOV32rr_REV, prefer_push_imm))
void __fastcall DestroyedByBeam__5AbodeFv(struct Object* this)
{
    void** vtable = *(void***)this;
    register void** vt asm("edi") = vtable;
    asm volatile("" :: "r"(vt));

    typedef float (__attribute__((thiscall)) *fn1_t)(struct Object*, int);
    fn1_t fn1 = ((fn1_t*)vt)[0x11c / 4];
    float val = fn1(this, 0);

    asm volatile (
        "push ecx\n\t"
        "mov.s ecx, esi\n\t"
        "fstp dword ptr [esp]\n\t"
        "call dword ptr [edi + 0x5b8]\n\t"
        "fstp st(0)"
        :: "t"(val) : "eax", "ecx", "edx", "memory", "st"
    );
}

__attribute__((no_callee_saves, no_tail_call))
bool32_t __fastcall GetInspectObjectPos__5AbodeFP8VillagerP9MapCoords(struct Object* this, const void* edx, struct Villager* param_1, struct MapCoords* pos)
{
    return GetInspectObjectPos__6ObjectFP8VillagerP9MapCoords(this, edx, param_1, pos);
}

__attribute__((no_callee_saves))
bool32_t __fastcall GetPSysFireLocalRndFlamePos__5AbodeFP7LHPointPl(struct Object* this, const void* edx, struct LHPoint* point, int32_t* param_2)
{
    bool32_t result;
    asm volatile (
        "sub                esp, 0x30\n\t"
        "push               esi\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x38]\n\t"
        "push               edi\n\t"
        "mov.s              edi, ecx\n\t"
        "%{disp32%} mov       ecx, dword ptr [edi + 0x00000090]\n\t"
        "test               ecx, ecx\n\t"
        "%{disp32%} je        LAB__addr_0x00402da3\n\t"
        "push               0x006de590\n\t"
        "push               esi\n\t"
        "call               _jmp_addr_0x0076d4c0\n\t"
        "test               al, al\n\t"
        "%{disp32%} je        LAB__addr_0x00402da3\n\t"
        "%{disp8%} mov        edx, dword ptr [edi + 0x40]\n\t"
        "add                edx, 0x14\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x08]\n\t"
        "call               ?SetInverse@LHMatrix@@QAEXAAU1@@Z\n\t"
        "fld                dword ptr [esi]\n\t"
        "%{disp8%} fld        dword ptr [esi + 0x04]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x40]\n\t"
        "%{disp8%} fld        dword ptr [esi + 0x08]\n\t"
        "pop                edi\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x1c]\n\t"
        "fmul               st, st(1)\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x10]\n\t"
        "fmul               st, st(3)\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x04]\n\t"
        "fmul               st, st(4)\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x28]\n\t"
        "fstp               dword ptr [esi]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x20]\n\t"
        "fmul               st, st(1)\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x14]\n\t"
        "fmul               st, st(3)\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "fmul               st, st(4)\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x04]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x24]\n\t"
        "fmul               st, st(1)\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "fmul               st, st(3)\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x0c]\n\t"
        "fmul               st, st(4)\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x30]\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x08]\n\t"
        "mov                dword ptr [eax], 0x00000000\n\t"
        "mov                al, 0x01\n\t"
        "fstp               st(0)\n\t"
        "pop                esi\n\t"
        "fstp               st(0)\n\t"
        "fstp               st(0)\n\t"
        "add                esp, 0x30\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x00402da3:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x40]\n\t"
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?GetPSysFireLocalRndFlamePos@Object@@UAEIPAULHPoint@@PAH@Z\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "add                esp, 0x30"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((XOR32rr_REV))
uint32_t __fastcall GetPhysicsConstantsType__5AbodeFv(struct Object* this)
{
    return 0;
}

__attribute__((no_callee_saves))
void __fastcall SetUpPhysOb__5AbodeFP6PhysOb(struct Object* this, const void* edx, struct PhysOb* param_1)
{
    asm volatile (
        "%{disp32%} mov       eax, dword ptr [ecx + 0x00000090]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00402de0\n\t"
        "mov                dword ptr [eax], 0x00000000\n"
        "LAB__addr_0x00402de0:\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "push               esi\n\t"
        "push               0x0\n\t"
        "call               dword ptr [eax + 0x788]\n\t"
        "%{disp8%} mov        esi, dword ptr [esp + 0x0c]\n\t"
        "lea                ecx, dword ptr [eax + eax * 0x2]\n\t"
        "%{disp32%} lea       edx, dword ptr [ecx * 0x8 + 0x00cc63e0]\n\t"
        "push               edx\n\t"
        "push               0x44fa0000\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x007fb810\n\t"
        "mov.s              ecx, esi\n\t"
        "call               _jmp_addr_0x007fbac0\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves, XOR32rr_REV, trailing_asm(".byte 0x90\n.byte 0xaa, 0x2e, 0x40, 0x00\n.byte 0x58, 0x2e, 0x40, 0x00\n.byte 0x81, 0x2e, 0x40, 0x00\n.byte 0xd3, 0x2e, 0x40, 0x00\n.byte 0xfc, 0x2e, 0x40, 0x00\n.byte 0xfb, 0x2f, 0x40, 0x00\n.byte 0x00, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x01, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x02, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x03, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x05, 0x05\n.byte 0x05, 0x05, 0x04, 0x90\n.byte 0x90, 0x90, 0x90, 0x90")))
struct Abode* __cdecl Create__5AbodeFRC9MapCoordsPC10GAbodeInfoP4TownffUlUlfii(const struct MapCoords* coords, const struct GAbodeInfo* info, struct Town* town, float y_angle, float scale, uint32_t param_6, uint32_t param_7, float food, int wood, int param_10)
{
    asm("{disp8} mov        eax, dword ptr [esp + 0x08]");              // 0x00402e20    8b442408
    asm("{disp32} mov       ecx, dword ptr [eax + 0x00000120]");        // 0x00402e24    8b8820010000
    asm("cmp                ecx, 0x00000100");                          // 0x00402e2a    81f900010000
    asm("push               esi");                                      // 0x00402e30    56
    asm("{disp32} jg        LAB__addr_0x00402f4e");                     // 0x00402e31    0f8f17010000
    asm("{disp32} je        LAB__addr_0x00402f25");                     // 0x00402e37    0f84e8000000
    asm("add                ecx, -0xa");                                // 0x00402e3d    83c1f6
    asm("cmp                ecx, 0x7a");                                // 0x00402e40    83f97a
    asm("{disp32} ja        LAB__addr_0x00402ffb");                     // 0x00402e43    0f87b2010000
    asm("xor.s              edx, edx");                                 // 0x00402e49    33d2
    asm("{disp32} mov       dl, byte ptr [ecx + 0x004030b0]");          // 0x00402e4b    8a91b0304000
    asm("jmp                dword ptr [edx*4 + 0x403098]");             // 0x00402e51    ff249598304000
    asm("{disp8} mov        ecx, dword ptr [esp + 0x28]");              // 0x00402e58    8b4c2428
    asm("{disp8} mov        edx, dword ptr [esp + 0x24]");              // 0x00402e5c    8b542424
    asm("push               ecx");                                      // 0x00402e60    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402e61    8b4c241c
    asm("push               edx");                                      // 0x00402e65    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x00402e66    8b54241c
    asm("push               ecx");                                      // 0x00402e6a    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402e6b    8b4c241c
    asm("push               edx");                                      // 0x00402e6f    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x18]");              // 0x00402e70    8b542418
    asm("push               ecx");                                      // 0x00402e74    51
    asm("push               eax");                                      // 0x00402e75    50
    asm("push               edx");                                      // 0x00402e76    52
    asm("call               _jmp_addr_0x007374c0");                     // 0x00402e77    e844463300
    asm("{disp32} jmp       LAB__addr_0x0040306d");                     // 0x00402e7c    e9ec010000
    asm("{disp8} mov        ecx, dword ptr [esp + 0x28]");              // 0x00402e81    8b4c2428
    asm("{disp8} mov        edx, dword ptr [esp + 0x24]");              // 0x00402e85    8b542424
    asm("push               ecx");                                      // 0x00402e89    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402e8a    8b4c241c
    asm("push               edx");                                      // 0x00402e8e    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x00402e8f    8b54241c
    asm("push               ecx");                                      // 0x00402e93    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402e94    8b4c241c
    asm("push               edx");                                      // 0x00402e98    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x18]");              // 0x00402e99    8b542418
    asm("push               ecx");                                      // 0x00402e9d    51
    asm("push               eax");                                      // 0x00402e9e    50
    asm("push               edx");                                      // 0x00402e9f    52
    asm("call               _jmp_addr_0x00732d60");                     // 0x00402ea0    e8bbfe3200
    asm("{disp32} jmp       LAB__addr_0x0040306d");                     // 0x00402ea5    e9c3010000
    asm("{disp8} mov        ecx, dword ptr [esp + 0x28]");              // 0x00402eaa    8b4c2428
    asm("{disp8} mov        edx, dword ptr [esp + 0x24]");              // 0x00402eae    8b542424
    asm("push               ecx");                                      // 0x00402eb2    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402eb3    8b4c241c
    asm("push               edx");                                      // 0x00402eb7    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x00402eb8    8b54241c
    asm("push               ecx");                                      // 0x00402ebc    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402ebd    8b4c241c
    asm("push               edx");                                      // 0x00402ec1    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x18]");              // 0x00402ec2    8b542418
    asm("push               ecx");                                      // 0x00402ec6    51
    asm("push               eax");                                      // 0x00402ec7    50
    asm("push               edx");                                      // 0x00402ec8    52
    asm("call               ?Create@Windmill@@SAPAVAbode@@ABUMapCoords@@PBVGAbodeInfo@@PAVTown@@MMMH@Z");  // 0x00402ec9    e8c2290000
    asm("{disp32} jmp       LAB__addr_0x0040306d");                     // 0x00402ece    e99a010000
    asm("{disp8} mov        ecx, dword ptr [esp + 0x28]");              // 0x00402ed3    8b4c2428
    asm("{disp8} mov        edx, dword ptr [esp + 0x24]");              // 0x00402ed7    8b542424
    asm("push               ecx");                                      // 0x00402edb    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402edc    8b4c241c
    asm("push               edx");                                      // 0x00402ee0    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x00402ee1    8b54241c
    asm("push               ecx");                                      // 0x00402ee5    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402ee6    8b4c241c
    asm("push               edx");                                      // 0x00402eea    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x18]");              // 0x00402eeb    8b542418
    asm("push               ecx");                                      // 0x00402eef    51
    asm("push               eax");                                      // 0x00402ef0    50
    asm("push               edx");                                      // 0x00402ef1    52
    asm("call               _jmp_addr_0x0050aad0");                     // 0x00402ef2    e8d97b1000
    asm("{disp32} jmp       LAB__addr_0x0040306d");                     // 0x00402ef7    e971010000
    asm("{disp8} mov        ecx, dword ptr [esp + 0x28]");              // 0x00402efc    8b4c2428
    asm("{disp8} mov        edx, dword ptr [esp + 0x24]");              // 0x00402f00    8b542424
    asm("push               ecx");                                      // 0x00402f04    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402f05    8b4c241c
    asm("push               edx");                                      // 0x00402f09    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x00402f0a    8b54241c
    asm("push               ecx");                                      // 0x00402f0e    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402f0f    8b4c241c
    asm("push               edx");                                      // 0x00402f13    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x18]");              // 0x00402f14    8b542418
    asm("push               ecx");                                      // 0x00402f18    51
    asm("push               eax");                                      // 0x00402f19    50
    asm("push               edx");                                      // 0x00402f1a    52
    asm("call               _jmp_addr_0x00779590");                     // 0x00402f1b    e870663700
    asm("{disp32} jmp       LAB__addr_0x0040306d");                     // 0x00402f20    e948010000
    asm("LAB__addr_0x00402f25:");
    asm("{disp8} mov        ecx, dword ptr [esp + 0x28]");              // 0x00402f25    8b4c2428
    asm("{disp8} mov        edx, dword ptr [esp + 0x24]");              // 0x00402f29    8b542424
    asm("push               ecx");                                      // 0x00402f2d    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402f2e    8b4c241c
    asm("push               edx");                                      // 0x00402f32    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x00402f33    8b54241c
    asm("push               ecx");                                      // 0x00402f37    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402f38    8b4c241c
    asm("push               edx");                                      // 0x00402f3c    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x18]");              // 0x00402f3d    8b542418
    asm("push               ecx");                                      // 0x00402f41    51
    asm("push               eax");                                      // 0x00402f42    50
    asm("push               edx");                                      // 0x00402f43    52
    asm("call               ?Create@Wonder@@SAPAV1@ABUMapCoords@@PBVGAbodeInfo@@PAVTown@@MMMH@Z");  // 0x00402f44    e8375f3700
    asm("{disp32} jmp       LAB__addr_0x0040306d");                     // 0x00402f49    e91f010000
    asm("LAB__addr_0x00402f4e:");
    asm("cmp                ecx, 0x00001004");                          // 0x00402f4e    81f904100000
    asm("{disp32} jg        LAB__addr_0x00402feb");                     // 0x00402f54    0f8f91000000
    asm("{disp8} je         LAB__addr_0x00402fc2");                     // 0x00402f5a    7466
    asm("cmp                ecx, 0x00000204");                          // 0x00402f5c    81f904020000
    asm("{disp8} je         LAB__addr_0x00402f99");                     // 0x00402f62    7435
    asm("cmp                ecx, 0x00000404");                          // 0x00402f64    81f904040000
    asm("{disp32} jne       LAB__addr_0x00402ffb");                     // 0x00402f6a    0f858b000000
    asm("{disp8} mov        ecx, dword ptr [esp + 0x28]");              // 0x00402f70    8b4c2428
    asm("{disp8} mov        edx, dword ptr [esp + 0x24]");              // 0x00402f74    8b542424
    asm("push               ecx");                                      // 0x00402f78    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402f79    8b4c241c
    asm("push               edx");                                      // 0x00402f7d    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x00402f7e    8b54241c
    asm("push               ecx");                                      // 0x00402f82    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402f83    8b4c241c
    asm("push               edx");                                      // 0x00402f87    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x18]");              // 0x00402f88    8b542418
    asm("push               ecx");                                      // 0x00402f8c    51
    asm("push               eax");                                      // 0x00402f8d    50
    asm("push               edx");                                      // 0x00402f8e    52
    asm("call               ?Create@TownCentre@@SAPAV1@ABUMapCoords@@PBVGAbodeInfo@@PAVTown@@MMMH@Z");                     // 0x00402f8f    e8fc0c3400
    asm("{disp32} jmp       LAB__addr_0x0040306d");                     // 0x00402f94    e9d4000000
    asm("LAB__addr_0x00402f99:");
    asm("{disp8} mov        ecx, dword ptr [esp + 0x28]");              // 0x00402f99    8b4c2428
    asm("{disp8} mov        edx, dword ptr [esp + 0x24]");              // 0x00402f9d    8b542424
    asm("push               ecx");                                      // 0x00402fa1    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402fa2    8b4c241c
    asm("push               edx");                                      // 0x00402fa6    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x00402fa7    8b54241c
    asm("push               ecx");                                      // 0x00402fab    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402fac    8b4c241c
    asm("push               edx");                                      // 0x00402fb0    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x18]");              // 0x00402fb1    8b542418
    asm("push               ecx");                                      // 0x00402fb5    51
    asm("push               eax");                                      // 0x00402fb6    50
    asm("push               edx");                                      // 0x00402fb7    52
    asm("call               _jmp_addr_0x00595d70");                     // 0x00402fb8    e8b32d1900
    asm("{disp32} jmp       LAB__addr_0x0040306d");                     // 0x00402fbd    e9ab000000
    asm("LAB__addr_0x00402fc2:");
    asm("{disp8} mov        ecx, dword ptr [esp + 0x28]");              // 0x00402fc2    8b4c2428
    asm("{disp8} mov        edx, dword ptr [esp + 0x24]");              // 0x00402fc6    8b542424
    asm("push               ecx");                                      // 0x00402fca    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402fcb    8b4c241c
    asm("push               edx");                                      // 0x00402fcf    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x00402fd0    8b54241c
    asm("push               ecx");                                      // 0x00402fd4    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00402fd5    8b4c241c
    asm("push               edx");                                      // 0x00402fd9    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x18]");              // 0x00402fda    8b542418
    asm("push               ecx");                                      // 0x00402fde    51
    asm("push               eax");                                      // 0x00402fdf    50
    asm("push               edx");                                      // 0x00402fe0    52
    asm("call               _jmp_addr_0x005315a0");                     // 0x00402fe1    e8bae51200
    asm("{disp32} jmp       LAB__addr_0x0040306d");                     // 0x00402fe6    e982000000
    asm("LAB__addr_0x00402feb:");
    asm("cmp                ecx, 0x00002004");                          // 0x00402feb    81f904200000
    asm("{disp8} je         LAB__addr_0x00403049");                     // 0x00402ff1    7456
    asm("cmp                ecx, 0x00004004");                          // 0x00402ff3    81f904400000
    asm("{disp8} je         LAB__addr_0x00403021");                     // 0x00402ff9    7426
    asm("LAB__addr_0x00402ffb:");
    asm("{disp8} mov        ecx, dword ptr [esp + 0x28]");              // 0x00402ffb    8b4c2428
    asm("{disp8} mov        edx, dword ptr [esp + 0x24]");              // 0x00402fff    8b542424
    asm("push               ecx");                                      // 0x00403003    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00403004    8b4c241c
    asm("push               edx");                                      // 0x00403008    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x00403009    8b54241c
    asm("push               ecx");                                      // 0x0040300d    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x0040300e    8b4c241c
    asm("push               edx");                                      // 0x00403012    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x18]");              // 0x00403013    8b542418
    asm("push               ecx");                                      // 0x00403017    51
    asm("push               eax");                                      // 0x00403018    50
    asm("push               edx");                                      // 0x00403019    52
    asm("call               ?CreateWithoutSpecial@Abode@@SAPAVAbode@@ABUMapCoords@@PBVGAbodeInfo@@PAVTown@@MMMH@Z");                     // 0x0040301a    e871010000
    asm("{disp8} jmp        LAB__addr_0x0040306d");                     // 0x0040301f    eb4c
    asm("LAB__addr_0x00403021:");
    asm("{disp8} mov        eax, dword ptr [esp + 0x28]");              // 0x00403021    8b442428
    asm("{disp8} mov        ecx, dword ptr [esp + 0x24]");              // 0x00403025    8b4c2424
    asm("{disp8} mov        edx, dword ptr [esp + 0x14]");              // 0x00403029    8b542414
    asm("push               eax");                                      // 0x0040302d    50
    asm("{disp8} mov        eax, dword ptr [esp + 0x14]");              // 0x0040302e    8b442414
    asm("push               ecx");                                      // 0x00403032    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x10]");              // 0x00403033    8b4c2410
    asm("push               edx");                                      // 0x00403037    52
    asm("push               eax");                                      // 0x00403038    50
    asm("push               0x00ccf1c4");                               // 0x00403039    68c4f1cc00
    asm("push               ecx");                                      // 0x0040303e    51
    asm("call               ?Create@Field@@SAPAV1@ABUMapCoords@@PBVGFieldTypeInfo@@PAVTown@@MMH@Z");                     // 0x0040303f    e83c521200
    asm("add                esp, 0x18");                                // 0x00403044    83c418
    asm("pop                esi");                                      // 0x00403047    5e
    asm("ret");                                                         // 0x00403048    c3
    asm("LAB__addr_0x00403049:");
    asm("{disp8} mov        edx, dword ptr [esp + 0x28]");              // 0x00403049    8b542428
    asm("{disp8} mov        ecx, dword ptr [esp + 0x24]");              // 0x0040304d    8b4c2424
    asm("push               edx");                                      // 0x00403051    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x00403052    8b54241c
    asm("push               ecx");                                      // 0x00403056    51
    asm("{disp8} mov        ecx, dword ptr [esp + 0x1c]");              // 0x00403057    8b4c241c
    asm("push               edx");                                      // 0x0040305b    52
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x0040305c    8b54241c
    asm("push               ecx");                                      // 0x00403060    51
    asm("push               edx");                                      // 0x00403061    52
    asm("push               eax");                                      // 0x00403062    50
    asm("{disp8} mov        eax, dword ptr [esp + 0x20]");              // 0x00403063    8b442420
    asm("push               eax");                                      // 0x00403067    50
    asm("call               _jmp_addr_0x007228d0");                     // 0x00403068    e863f83100
    asm("LAB__addr_0x0040306d:");
    asm("mov.s              esi, eax");                                 // 0x0040306d    8bf0
    asm("add                esp, 0x1c");                                // 0x0040306f    83c41c
    asm("test               esi, esi");                                 // 0x00403072    85f6
    asm("{disp8} je         LAB__addr_0x00403093");                     // 0x00403074    741d
    asm("{disp8} mov        ecx, dword ptr [esp + 0x20]");              // 0x00403076    8b4c2420
    asm("{disp8} mov        edx, dword ptr [esp + 0x1c]");              // 0x0040307a    8b54241c
    asm("{disp8} mov        eax, dword ptr [esp + 0x2c]");              // 0x0040307e    8b44242c
    asm("push               ecx");                                      // 0x00403082    51
    asm("push               edx");                                      // 0x00403083    52
    asm("push               eax");                                      // 0x00403084    50
    asm("mov.s              ecx, esi");                                 // 0x00403085    8bce
    asm("call               ?Init@Abode@@QAEXHII@Z");                   // 0x00403087    e8a4000000
    asm("mov.s              ecx, esi");                                 // 0x0040308c    8bce
    asm("call               ?CreateAbodeSurroundingObjects@Abode@@QAEXXZ");  // 0x0040308e    e86d0d0000
    asm("LAB__addr_0x00403093:");
    asm("mov.s              eax, esi");                                 // 0x00403093    8bc6
    asm("pop                esi");                                      // 0x00403095    5e
    // Snippet: db, [0x00403097, 0x00403098)
    // Snippet: jmptbl, [0x00403098, 0x004030b0)
    // Snippet: ijmptbl, [0x004030b0, 0x00403130)
}

__attribute__((no_callee_saves))
void __fastcall Init__5AbodeFiUlUl(struct Abode* this, const void* edx, int param_1, uint32_t food_amount, uint32_t wood_amount)
{
    asm volatile (
        "push               esi\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x18]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "push               ecx\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x9c]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x10]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               0x0\n\t"
        "push               eax\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x9c]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x890]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0040317d\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x914]\n"
        "LAB__addr_0x0040317d:\n\t"
        "pop                esi"
        ::: "eax", "ecx", "edx", "memory"
    );
}

__attribute__((no_callee_saves, XOR32rr_REV))
struct Abode* __cdecl CreateWithoutSpecial__5AbodeFRC9MapCoordsPC10GAbodeInfoP4Townfffi(const struct MapCoords* coords, const struct GAbodeInfo* info, struct Town* town, float y_angle, float scale, float food, int wood)
{
    struct Abode* result;
    asm volatile (
        "push               esi\n\t"
        "push               edi\n\t"
        "push               0x0000013c\n\t"
        "push               0x009c7fbc\n\t"
        "push               0x000000c4\n\t"
        "call               ?__nw@Base@@SAPAXK@Z\n\t"
        "add                esp, 0x0c\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x004031ed\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x24]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x20]\n\t"
        "%{disp8%} mov        edi, dword ptr [esp + 0x0c]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x20]\n\t"
        "push               edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x20]\n\t"
        "push               ecx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x20]\n\t"
        "push               edx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x20]\n\t"
        "push               ecx\n\t"
        "push               edx\n\t"
        "push               edi\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ??0Abode@@QAE@ABUMapCoords@@PBVGAbodeInfo@@PAVTown@@MMMH@Z\n\t"
        "mov.s              esi, eax\n\t"
        "test               esi, esi\n\t"
        "%{disp8%} je         LAB__addr_0x004031e8\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x658]\n"
        "LAB__addr_0x004031e8:\n\t"
        "pop                edi\n\t"
        "mov.s              eax, esi\n\t"
        "pop                esi\n\t"
        "ret\n"
        "LAB__addr_0x004031ed:\n\t"
        "pop                edi\n\t"
        "xor.s              eax, eax\n\t"
        "pop                esi"
        : "=a"(result) :: "ecx", "edx", "memory"
    );
    return result;
}

__attribute__((no_callee_saves, XOR32rr_REV))
void __fastcall CallVirtualFunctionsForCreation__5AbodeFRC9MapCoords(struct Object* this, const void* edx, const struct MapCoords* coords)
{
    asm volatile (
        "%{disp8%} mov        eax, dword ptr [esp + 0x04]\n\t"
        "sub                esp, 0x20\n\t"
        "push               esi\n\t"
        "push               edi\n\t"
        "mov.s              esi, ecx\n\t"
        "push               eax\n\t"
        "call               ?CallVirtualFunctionsForCreation@MultiMapFixed@@UAEXABUMapCoords@@@Z\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                eax, dword ptr [ecx]\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x1c]\n\t"
        "call               dword ptr [eax + 0x1c0]\n\t"
        "xor.s              edi, edi\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0040326b\n\t"
        "push               edi\n\t"
        "call               ?Create@LH3DSmoke@@SAPAV1@PBULHPoint@@@Z\n\t"
        "add                esp, 0x04\n\t"
        "cmp.s              eax, edi\n\t"
        "%{disp32%} mov       dword ptr [esi + 0x0000008c], eax\n\t"
        "%{disp8%} je         LAB__addr_0x0040326b\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x1c]\n\t"
        "mov                dword ptr [eax], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x20]\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x04], edx\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x24]\n\t"
        "%{disp8%} mov        dword ptr [eax + 0x08], ecx\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x310]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x0040326b\n\t"
        "%{disp32%} mov       eax, dword ptr [esi + 0x0000008c]\n\t"
        "%{disp32%} mov       dword ptr [eax + 0x0000010c], 0x00808080\n"
        "LAB__addr_0x0040326b:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "mov                edx, dword ptr [ecx]\n\t"
        "call               dword ptr [edx + 0x1f4]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x004032d7\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x64]\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float0p2]\n\t"
        "fchs\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_floatn0p8]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x004032ab\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x64]\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float0p2]\n\t"
        "fchs\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} jmp        LAB__addr_0x004032b3\n"
        "LAB__addr_0x004032ab:\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x2c], 0xbf4ccccd\n"
        "LAB__addr_0x004032b3:\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "call               ?GetAltitudeFondation@Game3DObject@@QBEMXZ\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x2c]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x41\n\t"
        "%{disp8%} jne        LAB__addr_0x004032d0\n\t"
        "%{disp8%} mov        ecx, dword ptr [esi + 0x40]\n\t"
        "call               ?GetAltitudeFondation@Game3DObject@@QBEMXZ\n\t"
        "%{disp8%} jmp        LAB__addr_0x004032d4\n"
        "LAB__addr_0x004032d0:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x2c]\n"
        "LAB__addr_0x004032d4:\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x1c]\n"
        "LAB__addr_0x004032d7:\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x120]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x30]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x508]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x1c]\n\t"
        "%{disp8%} lea        ebx, dword ptr [esi + 0x14]\n\t"
        "%{disp8%} mov        esi, dword ptr [esi + 0x40]\n\t"
        "mov.s              ecx, ebx\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x10], eax\n\t"
        "call               ?GetAltitude@LH3DIsland@@SAMABULH3DMapCoords@@@Z\n\t"
        "%{disp8%} fadd       dword ptr [esp + 0x10]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x18]\n\t"
        "fild               dword ptr [ebx]\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float_coord_to_point]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "%{disp8%} fild       dword ptr [ebx + 0x04]\n\t"
        "pop                ebx\n\t"
        "%{disp32%} fmul      dword ptr [_rdata_float_coord_to_point]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x18]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x2c]\n\t"
        "fnstsw             ax\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float1p0]\n\t"
        "test               ah, 0x40\n\t"
        "fnstsw             ax\n\t"
        "%{disp32%} jne       LAB__addr_0x0040349b\n\t"
        "test               ah, 0x40\n\t"
        "%{disp32%} jne       LAB__addr_0x0040340f\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x40], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x3c], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x38], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x30], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x2c], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x28], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x20], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x1c], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x18], edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x34], ecx\n\t"
        "mov.s              edx, ecx\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x24], edx\n\t"
        "mov.s              eax, ecx\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x14], eax\n\t"
        "%{disp8%} fadd       dword ptr [esi + 0x38]\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x38]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x14]\n\t"
        "%{disp8%} fadd       dword ptr [esi + 0x3c]\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x3c]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "%{disp8%} fadd       dword ptr [esi + 0x40]\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x40]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "fcos\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "fsin\n\t"
        "fld                st(0)\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x14]\n\t"
        "fld                st(1)\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x2c]\n\t"
        "fld                st(3)\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x14]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x14]\n\t"
        "fld                st(2)\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x2c]\n\t"
        "fsub               st, st(1)\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x2c]\n\t"
        "fstp               st(0)\n\t"
        "fld                st(0)\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x18]\n\t"
        "fld                st(1)\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x30]\n\t"
        "fld                st(3)\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x18]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x18]\n\t"
        "fld                st(2)\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x30]\n\t"
        "fsub               st, st(1)\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x30]\n\t"
        "fstp               st(0)\n\t"
        "fld                st(0)\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x1c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x34]\n\t"
        "fld                st(1)\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x1c]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x1c]\n\t"
        "%{disp8%} fmul       dword ptr [esi + 0x34]\n\t"
        "%{disp8%} fsub       dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} fstp       dword ptr [esi + 0x34]\n\t"
        "%{disp32%} jmp       LAB__addr_0x004034e3\n"
        "LAB__addr_0x0040340f:\n\t"
        "%{disp8%} lea        edi, dword ptr [esi + 0x14]\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?SetIdentity@LHMatrix@@QAEXXZ\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "fcos\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x14]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        dword ptr [edi + 0x24], ecx\n\t"
        "%{disp8%} mov        dword ptr [edi + 0x28], edx\n\t"
        "%{disp8%} mov        dword ptr [edi + 0x2c], eax\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x08]\n\t"
        "fsin\n\t"
        "fld                st(0)\n\t"
        "fmul               dword ptr [edi]\n\t"
        "fld                st(1)\n\t"
        "%{disp8%} fmul       dword ptr [edi + 0x18]\n\t"
        "fld                st(3)\n\t"
        "fmul               dword ptr [edi]\n\t"
        "faddp              st(1), st\n\t"
        "fstp               dword ptr [edi]\n\t"
        "fld                st(2)\n\t"
        "%{disp8%} fmul       dword ptr [edi + 0x18]\n\t"
        "fsub               st, st(1)\n\t"
        "%{disp8%} fstp       dword ptr [edi + 0x18]\n\t"
        "fstp               st(0)\n\t"
        "fld                st(0)\n\t"
        "%{disp8%} fmul       dword ptr [edi + 0x04]\n\t"
        "fld                st(2)\n\t"
        "%{disp8%} fmul       dword ptr [edi + 0x04]\n\t"
        "fld                st(2)\n\t"
        "%{disp8%} fmul       dword ptr [edi + 0x1c]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fstp       dword ptr [edi + 0x04]\n\t"
        "fld                st(2)\n\t"
        "%{disp8%} fmul       dword ptr [edi + 0x1c]\n\t"
        "fsub               st, st(1)\n\t"
        "%{disp8%} fstp       dword ptr [edi + 0x1c]\n\t"
        "fstp               st(0)\n\t"
        "fld                st(0)\n\t"
        "%{disp8%} fmul       dword ptr [edi + 0x08]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "fld                st(1)\n\t"
        "%{disp8%} fmul       dword ptr [edi + 0x08]\n\t"
        "fxch               st(1)\n\t"
        "%{disp8%} fmul       dword ptr [edi + 0x20]\n\t"
        "faddp              st(1), st\n\t"
        "%{disp8%} fstp       dword ptr [edi + 0x08]\n\t"
        "%{disp8%} fmul       dword ptr [edi + 0x20]\n\t"
        "%{disp8%} fsub       dword ptr [esp + 0x0c]\n\t"
        "%{disp8%} fstp       dword ptr [edi + 0x20]\n\t"
        "%{disp8%} jmp        LAB__addr_0x004034e3\n"
        "LAB__addr_0x0040349b:\n\t"
        "test               ah, 0x40\n\t"
        "%{disp8%} jne        LAB__addr_0x004034d7\n\t"
        "%{disp8%} mov        edx, dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "mov.s              eax, edx\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x20], edx\n\t"
        "mov                dword ptr [ecx], edx\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x10]\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x2c], edi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x28], edi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x24], edi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x1c], edi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x18], edi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x14], edi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x0c], edi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x08], edi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x04], edi\n\t"
        "%{disp8%} mov        dword ptr [ecx + 0x10], eax\n\t"
        "call               ?PostTranslation@LHMatrix@@QAEXAAULHPoint@@@Z\n\t"
        "%{disp8%} jmp        LAB__addr_0x004034e3\n"
        "LAB__addr_0x004034d7:\n\t"
        "%{disp8%} lea        edx, dword ptr [esp + 0x10]\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "call               ?Translation@LHMatrix@@QAEXABVLHPoint@@@Z\n"
        "LAB__addr_0x004034e3:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x2c]\n\t"
        "%{disp8%} mov        ecx, dword ptr [esp + 0x08]\n\t"
        "pop                edi\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x44], eax\n\t"
        "%{disp8%} mov        dword ptr [esi + 0x48], ecx\n\t"
        "pop                esi\n\t"
        "add                esp, 0x20"
        ::: "eax", "ecx", "edx", "memory"
    );
}

#include "Abode.h"
#include "Town.h"

const float rdata_float_1000_0 asm("__real@447a0000") = 1000.0f;
const float rdata_float_0_1 asm("__real@3dcccccd") = 0.1f;
const float rdata_float_1_1 asm("__real@3f8ccccd") = 1.1f;
const float rdata_float_300_0 asm("__real@43960000") = 300.0f;

char* __fastcall GetAbodeText__5AbodeFPc(struct Abode* this, const void* edx, char* buff)
{
    asm volatile (
        "mov eax, dword ptr [ecx]\n\t"
        "push esi\n\t"
        "%{disp8%} mov esi, dword ptr [ecx + 0x28]\n\t"
        "push edi\n\t"
        "call dword ptr [eax + 0x928]\n\t"
        "%{disp8%} mov ecx, dword ptr [eax + 0x10]\n\t"
        "%{disp32%} mov edi, dword ptr [ecx * 0x4 + 0x00c22fdc]\n\t"
        "mov.s ecx, esi\n\t"
        "call ?GetDescription@GAbodeInfo@@QAEPBDXZ\n\t"
        "%{disp8%} mov esi, dword ptr [esp + 0x0c]\n\t"
        "push eax\n\t"
        "push edi\n\t"
        "push 0x009c8054\n\t"
        "push esi\n\t"
        "call _sprintf\n\t"
        "add esp, 0x10\n\t"
        "pop edi\n\t"
        "mov.s eax, esi\n\t"
        "pop esi\n\t"
        "ret 0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
size_t __fastcall SaveObject__5AbodeFR8LHOSFileRC9MapCoords(struct Object* this, const void* edx, struct LHOSFile* param_1, const struct MapCoords* param_2)
{
    asm volatile (
        "sub                esp, 0x00000278\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "call               ?CheckAndSetSaved@GameThing@@QAE_NXZ\n\t"
        "mov.s              ebp, eax\n\t"
        "test               ebp, ebp\n\t"
        "%{disp32%} je        LAB__addr_0x00405d68\n\t"
        "push               ebx\n\t"
        "%{disp32%} mov       ebx, dword ptr [esp + 0x0000028c]\n\t"
        "test               ebx, ebx\n\t"
        "push               edi\n\t"
        "%{disp8%} je         LAB__addr_0x00405be6\n\t"
        "push               ebx\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x28]\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        ecx, dword ptr [esi + 0x14]\n\t"
        "call               _jmp_addr_0x006055c0\n\t"
        "%{disp8%} jmp        LAB__addr_0x00405be9\n"
        "LAB__addr_0x00405be6:\n\t"
        "%{disp8%} lea        eax, dword ptr [esi + 0x14]\n"
        "LAB__addr_0x00405be9:\n\t"
        "mov                ecx, dword ptr [eax]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x18], ecx\n\t"
        "%{disp8%} mov        edx, dword ptr [eax + 0x04]\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x1c], edx\n\t"
        "%{disp8%} mov        eax, dword ptr [eax + 0x08]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} mov        dword ptr [esp + 0x20], eax\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00405c1b\n\t"
        "test               ebx, ebx\n\t"
        "%{disp8%} jne        LAB__addr_0x00405c1b\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "%{disp32%} mov       edi, dword ptr [eax + 0x000005b4]\n\t"
        "%{disp8%} jmp        LAB__addr_0x00405c1e\n"
        "LAB__addr_0x00405c1b:\n\t"
        "or                 edi, 0xffffffff\n"
        "LAB__addr_0x00405c1e:\n\t"
        "test               byte ptr [esi + 0x58], 0x02\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "%{disp8%} je         LAB__addr_0x00405ca1\n\t"
        "call               dword ptr [edx + 0x120]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x508]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x98]\n\t"
        "push               eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x98]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "%{disp32%} fmul      dword ptr [__real@447a0000]\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "%{disp32%} fmul      dword ptr [__real@447a0000]\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       ecx, dword ptr [esp + 0x00000108]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbodeText@Abode@@QAEPADPAD@Z\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       edx, dword ptr [esp + 0x000001d4]\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x30]\n\t"
        "call               ?ConvertToText@MapCoords@@QAEPADPAD@Z\n\t"
        "push               eax\n\t"
        "push               edi\n\t"
        "push               0x8\n\t"
        "%{disp8%} jmp        LAB__addr_0x00405d18\n"
        "LAB__addr_0x00405ca1:\n\t"
        "call               dword ptr [edx + 0x120]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x508]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x14]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "push               0x1\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x98]\n\t"
        "push               eax\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               0x0\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x98]\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x14]\n\t"
        "%{disp32%} fmul      dword ptr [__real@447a0000]\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x1c]\n\t"
        "%{disp32%} fmul      dword ptr [__real@447a0000]\n\t"
        "push               eax\n\t"
        "call               _jmp_addr_0x007a1400\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       ecx, dword ptr [esp + 0x00000108]\n\t"
        "push               ecx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?GetAbodeText@Abode@@QAEPADPAD@Z\n\t"
        "push               eax\n\t"
        "%{disp32%} lea       edx, dword ptr [esp + 0x000001d4]\n\t"
        "push               edx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x30]\n\t"
        "call               ?ConvertToText@MapCoords@@QAEPADPAD@Z\n\t"
        "push               eax\n\t"
        "push               edi\n\t"
        "push               0x7\n"
        "LAB__addr_0x00405d18:\n\t"
        "call               ?GetCommandAsText@GSetup@@SAPADW4SCRIPT_FEATURE_COMMANDS@@@Z\n\t"
        "add                esp, 0x04\n\t"
        "push               eax\n\t"
        "%{disp8%} lea        eax, dword ptr [esp + 0x50]\n\t"
        "push               eax\n\t"
        "call               _sprintf\n\t"
        "or                 ecx, 0xffffffff\n\t"
        "xor.s              eax, eax\n\t"
        "%{disp8%} lea        edi, dword ptr [esp + 0x54]\n\t"
        "repne scasb\n\t"
        "%{disp32%} mov       edi, dword ptr [esp + 0x000002b0]\n\t"
        "not                ecx\n\t"
        "dec                ecx\n\t"
        "push               ecx\n\t"
        "%{disp8%} lea        ecx, dword ptr [esp + 0x58]\n\t"
        "push               ecx\n\t"
        "push               edi\n\t"
        "push               esi\n\t"
        "call               ?WriteToFile@GSetup@@SAIPAXAAVLHOSFile@@0K@Z\n\t"
        "add                esp, 0x34\n\t"
        "push               ebx\n\t"
        "push               edi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?SaveObject@MultiMapFixed@@UAEIPAVLHOSFile@@PBUMapCoords@@@Z\n\t"
        "pop                edi\n\t"
        "pop                ebx\n\t"
        "pop                esi\n\t"
        "mov.s              eax, ebp\n\t"
        "pop                ebp\n\t"
        "add                esp, 0x00000278\n\t"
        "ret                0x0008\n"
        "LAB__addr_0x00405d68:\n\t"
        "pop                esi\n\t"
        "mov.s              eax, ebp\n\t"
        "pop                ebp\n\t"
        "add                esp, 0x00000278\n\t"
        "ret                0x0008"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

int __fastcall FUN_00405d80__5AbodeFv(struct Abode* this)
{
    return 1;
}

__attribute__((XOR32rr_REV))
void __fastcall ReduceLife__5AbodeFfP7GPlayer(struct Object* this, const void* edx, float value, struct GPlayer* player)
{
    asm volatile (
        "push               ecx\n\t"
        "push               ebx\n\t"
        "push               ebp\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "call               dword ptr [eax + 0x11c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x0c]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x894]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x0c]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00405dbe\n\t"
        "mov                ebp, 0x00000001\n\t"
        "%{disp8%} jmp        LAB__addr_0x00405dc0\n"
        "LAB__addr_0x00405dbe:\n\t"
        "xor.s              ebp, ebp\n"
        "LAB__addr_0x00405dc0:\n\t"
        "%{disp8%} mov        ebx, dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x14]\n\t"
        "push               ebx\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?ReduceLife@MultiMapFixed@@UAEXMPAVGPlayer@@@Z\n\t"
        "%{disp8%} fst        dword ptr [esp + 0x18]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp32%} je        LAB__addr_0x00405ec5\n\t"
        "push               edi\n\t"
        "%{disp32%} mov       edi, dword ptr [esi + 0x000000a0]\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00405e02\n"
        "LAB__addr_0x00405df1:\n\t"
        "mov.s              ecx, edi\n\t"
        "call               ?SetStateWhenTappedOnAbode@Villager@@QAE_NXZ\n\t"
        "%{disp32%} mov       edi, dword ptr [edi + 0x000000e4]\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} jne        LAB__addr_0x00405df1\n"
        "LAB__addr_0x00405e02:\n\t"
        "test               ebp, ebp\n\t"
        "pop                edi\n\t"
        "%{disp8%} je         LAB__addr_0x00405e45\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x894]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x18]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00405e45\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x918]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x920]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00405e5e\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               ?SetInStateOfEmergency@Town@@QAEXXZ\n\t"
        "%{disp8%} jmp        LAB__addr_0x00405e5e\n"
        "LAB__addr_0x00405e45:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x0c]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float1p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00405e5e\n\t"
        "push               ebx\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?FUN_004073f0@Abode@@UAEXPAVGPlayer@@@Z\n"
        "LAB__addr_0x00405e5e:\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x74]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} jne        LAB__addr_0x00405e86\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x48]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00405e7f\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               esi\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x48]\n\t"
        "mov.s              ecx, eax\n\t"
        "call               _jmp_addr_0x0073b8e0\n"
        "LAB__addr_0x00405e7f:\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x74]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00405ead\n"
        "LAB__addr_0x00405e86:\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x890]\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je         LAB__addr_0x00405ead\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "%{disp8%} mov        eax, dword ptr [esi + 0x74]\n\t"
        "%{disp32%} fmul      dword ptr [__real@3f8ccccd]\n\t"
        "%{disp32%} fsub      dword ptr [__real@3dcccccd]\n\t"
        "%{disp32%} fstp      dword ptr [eax + 0x00000640]\n"
        "LAB__addr_0x00405ead:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "%{disp32%} fcomp     dword ptr [_rdata_float0p0]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x40\n\t"
        "%{disp8%} je         LAB__addr_0x00405ec5\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?FUN_00405d80@Abode@@QAEHXZ\n"
        "LAB__addr_0x00405ec5:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x18]\n\t"
        "pop                esi\n\t"
        "pop                ebp\n\t"
        "pop                ebx\n\t"
        "pop                ecx\n\t"
        "ret                0x0008"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
void __fastcall IncreaseLife__5AbodeFf(struct Object* this, const void* edx, float value)
{
    asm volatile (
        "push               ecx\n\t"
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "push               edi\n\t"
        "call               dword ptr [eax + 0x11c]\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x08]\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x894]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x08]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} jne        LAB__addr_0x00405efd\n\t"
        "mov                edi, 0x00000001\n\t"
        "%{disp8%} jmp        LAB__addr_0x00405eff\n"
        "LAB__addr_0x00405efd:\n\t"
        "xor.s              edi, edi\n"
        "LAB__addr_0x00405eff:\n\t"
        "%{disp8%} mov        eax, dword ptr [esp + 0x10]\n\t"
        "push               eax\n\t"
        "mov.s              ecx, esi\n\t"
        "call               ?IncreaseLife@Object@@UAEXM@Z\n\t"
        "%{disp8%} fstp       dword ptr [esp + 0x10]\n\t"
        "test               edi, edi\n\t"
        "%{disp8%} je         LAB__addr_0x00405f32\n\t"
        "mov                edx, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [edx + 0x894]\n\t"
        "%{disp8%} fcomp      dword ptr [esp + 0x10]\n\t"
        "fnstsw             ax\n\t"
        "test               ah, 0x01\n\t"
        "%{disp8%} je         LAB__addr_0x00405f32\n\t"
        "mov                eax, dword ptr [esi]\n\t"
        "mov.s              ecx, esi\n\t"
        "call               dword ptr [eax + 0x91c]\n"
        "LAB__addr_0x00405f32:\n\t"
        "%{disp8%} fld        dword ptr [esp + 0x10]\n\t"
        "pop                edi\n\t"
        "pop                esi\n\t"
        "pop                ecx\n\t"
        "ret                0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

enum TRIBE_TYPE __fastcall GetTribeType__5AbodeCFv(struct Abode* this)
{
    return this->town->tribe_type;
}

__attribute__((XOR32rr_REV))
struct GTribeInfo* __fastcall GetTribe__5AbodeFv(struct Abode* this)
{
    asm volatile (
        "push esi\n\t"
        "mov.s esi, ecx\n\t"
        "mov eax, dword ptr [esi]\n\t"
        "call dword ptr [eax + 0x48]\n\t"
        "test eax, eax\n\t"
        "%{disp8%} je 0f\n\t"
        "mov edx, dword ptr [esi]\n\t"
        "mov.s ecx, esi\n\t"
        "call dword ptr [edx + 0x48]\n\t"
        "mov.s ecx, eax\n\t"
        "call ?GetTribe@Town@@QBEPAVGTribeInfo@@XZ\n\t"
        "pop esi\n\t"
        "ret\n"
        "0:\n\t"
        "xor.s eax, eax\n\t"
        "pop esi\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

struct GPlayer* __fastcall GetPlayer__5AbodeFv(struct GameThing* this)
{
    asm volatile (
        "push esi\n\t"
        "mov.s esi, ecx\n\t"
        "mov eax, dword ptr [esi]\n\t"
        "call dword ptr [eax + 0x48]\n\t"
        "test eax, eax\n\t"
        "%{disp8%} je 0f\n\t"
        "mov edx, dword ptr [esi]\n\t"
        "mov.s ecx, esi\n\t"
        "call dword ptr [edx + 0x48]\n\t"
        "mov edx, dword ptr [eax]\n\t"
        "mov.s ecx, eax\n\t"
        "call dword ptr [edx + 0x1c]\n\t"
        "pop esi\n\t"
        "ret\n"
        "0:\n\t"
        "mov.s ecx, esi\n\t"
        "call ?GetPlayer@GameThing@@QAEPAVGPlayer@@XZ\n\t"
        "pop esi\n\t"
        "ret"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((prefer_inc_dec_byte))
void __fastcall ArriveHome__5AbodeFv(struct Abode* this)
{
    this->field_0xb6++;
}

__attribute__((prefer_inc_dec_byte))
void __fastcall LeaveHome__5AbodeFv(struct Abode* this)
{
    this->field_0xb6--;
}

__attribute__((XOR32rr_REV))
bool GetNearestWaterPos__5AbodeFR9MapCoords(struct Abode* this, const void* edx, struct MapCoords* coords)
{
    asm volatile (
        "%{disp8%} mov dl, byte ptr [ecx + 0x7c]\n\t"
        "mov eax, 0x00000001\n\t"
        "test al, dl\n\t"
        "%{disp8%} je 0f\n\t"
        "%{disp8%} mov edx, dword ptr [esp + 0x04]\n\t"
        "add ecx, 0x00000080\n\t"
        "push esi\n\t"
        "mov esi, dword ptr [ecx]\n\t"
        "mov dword ptr [edx], esi\n\t"
        "%{disp8%} mov esi, dword ptr [ecx + 0x04]\n\t"
        "%{disp8%} mov dword ptr [edx + 0x04], esi\n\t"
        "%{disp8%} mov ecx, dword ptr [ecx + 0x08]\n\t"
        "%{disp8%} mov dword ptr [edx + 0x08], ecx\n\t"
        "pop esi\n\t"
        "ret 0x0004\n"
        "0:\n\t"
        "xor.s eax, eax\n\t"
        "ret 0x0004"
        ::: "eax", "ecx", "edx", "memory"
    );
    __builtin_unreachable();
}

__attribute__((XOR32rr_REV))
bool __fastcall IsCivic__5AbodeFv(struct MultiMapFixed* this)
{
    asm("{disp8} mov        eax, dword ptr [ecx + 0x28]");                   // 0x00405ff0    8b4128
    asm("{disp32} mov       eax, dword ptr [eax + 0x00000120]");             // 0x00405ff3    8b8020010000
    asm("cmp                eax, 0x00000100");                               // 0x00405ff9    3d00010000
    asm("{disp8} jg         LAB__addr_0x00406019");                          // 0x00405ffe    7f19
    asm("{disp8} je         LAB__addr_0x0040603d");                          // 0x00406000    743b
    asm("add                eax, -0x14");                                    // 0x00406002    83c0ec
    asm("cmp                eax, 0x70");                                     // 0x00406005    83f870
    asm("{disp8} ja         LAB__addr_0x0040603a");                          // 0x00406008    7730
    asm("xor.s              ecx, ecx");                                      // 0x0040600a    33c9
    asm("{disp32} mov       cl, byte ptr [eax + 0x0040604c]");               // 0x0040600c    8a884c604000
    asm("jmp                dword ptr [ecx*4 + 0x406044]");                  // 0x00406012    ff248d44604000
    asm("LAB__addr_0x00406019:");
    asm("cmp                eax, 0x00001004");                               // 0x00406019    3d04100000
    asm("{disp8} jg         LAB__addr_0x00406033");                          // 0x0040601e    7f13
    asm("{disp8} je         LAB__addr_0x0040603d");                          // 0x00406020    741b
    asm("cmp                eax, 0x00000204");                               // 0x00406022    3d04020000
    asm("{disp8} je         LAB__addr_0x0040603d");                          // 0x00406027    7414
    asm("cmp                eax, 0x00000404");                               // 0x00406029    3d04040000
    asm("{disp8} je         LAB__addr_0x0040603d");                          // 0x0040602e    740d
    asm("xor.s              eax, eax");                                      // 0x00406030    33c0
    asm("ret");                                                              // 0x00406032    c3
    asm("LAB__addr_0x00406033:");
    asm("cmp                eax, 0x00002004");                               // 0x00406033    3d04200000
    asm("{disp8} je         LAB__addr_0x0040603d");                          // 0x00406038    7403
    asm("LAB__addr_0x0040603a:");
    asm("xor.s              eax, eax");                                      // 0x0040603a    33c0
    asm("ret");                                                              // 0x0040603c    c3
    asm("LAB__addr_0x0040603d:");
    asm("mov                eax, 0x00000001");                               // 0x0040603d    b801000000
    asm("ret");                                                              // 0x00406042    c3
    asm("nop");                                                              // 0x00406043    90
    // Snippet: jmptbl, [0x00406044, 0x0040604c)
    asm(".byte 0x3d, 0x60, 0x40, 0x00");      // 0x00406044
    asm(".byte 0x3a, 0x60, 0x40, 0x00");      // 0x00406048
    // Snippet: ijmptbl, [0x0040604c, 0x004060bd)
    asm(".byte 0x00, 0x01, 0x01, 0x01");      // 0x0040604c
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406050
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406054
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406058
    asm(".byte 0x00, 0x01, 0x01, 0x01");      // 0x0040605c
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406060
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406064
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406068
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x0040606c
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406070
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406074
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406078
    asm(".byte 0x00, 0x01, 0x01, 0x01");      // 0x0040607c
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406080
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406084
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406088
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x0040608c
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406090
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406094
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x00406098
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x0040609c
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x004060a0
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x004060a4
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x004060a8
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x004060ac
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x004060b0
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x004060b4
    asm(".byte 0x01, 0x01, 0x01, 0x01");      // 0x004060b8
    asm(".byte 0x00");                        // 0x004060bc
    __builtin_unreachable();
}

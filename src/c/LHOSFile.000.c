#include "lionhead/lhfile/ver3.0/LHOSFile.h"

extern char rdata_bytes[];

// win1.41 007bc650 mac 10164fc0 LHOSFile::LHOSFile(void)
// Bytes: 8bc1 c7006cf89900 c7400400000000 c3
__attribute__((no_callee_saves, no_ret))
struct LHOSFile* __fastcall __ct__8LHOSFileFv(struct LHOSFile* this)
{
    asm volatile (
        "mov.s              eax, ecx\n\t"
        "mov                dword ptr [eax], offset rdata_bytes + 0xf686c\n\t"
        "%{disp8%} mov      dword ptr [eax + 0x04], 0x00000000\n\t"
        "ret"
        ::: "eax", "memory"
    );
}

// win1.41 007bc660 mac 10164ef0 LHOSFile::~LHOSFile(bool)
// Scalar deleting destructor: calls dtor, conditionally calls 1-arg delete
void __dt__8LHOSFileFb_decl(void) __asm__("___dt__8LHOSFileFb");
__attribute__((msvc6_sdtor("??_DLHOSFile@@QAEXXZ,??3@YAXPAX@Z,0,"), trailing_asm("nop\nnop")))
void __dt__8LHOSFileFb_decl(void) {}

// win1.41 007bc680 mac inlined LHOSFile::~LHOSFile(void)
// Bytes: 56 8bf1 8b4604 c7066cf89900 85c0 740e 50 ff15c4928a00 c7460400000000 5e c3
void __dt__8LHOSFileFv_impl(void) __asm__("??_DLHOSFile@@QAEXXZ");
__attribute__((no_callee_saves, no_ret))
void __dt__8LHOSFileFv_impl(void)
{
    asm volatile (
        "push               esi\n\t"
        "mov.s              esi, ecx\n\t"
        "%{disp8%} mov      eax, dword ptr [esi + 0x04]\n\t"
        "mov                dword ptr [esi], offset rdata_bytes + 0xf686c\n\t"
        "test               eax, eax\n\t"
        "%{disp8%} je       LAB__dt_skip\n\t"
        "push               eax\n\t"
        "call               dword ptr [__imp__CloseHandle@4]\n\t"
        "%{disp8%} mov      dword ptr [esi + 0x04], 0x00000000\n"
        "LAB__dt_skip:\n\t"
        "pop                esi\n\t"
        "ret"
        ::: "eax", "esi", "memory"
    );
}

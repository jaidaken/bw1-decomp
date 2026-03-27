#include "lionhead/lhfile/ver3.0/LHOSFile.h"

extern char rdata_bytes[];

// win1.41 007bc650 mac 10164fc0 LHOSFile::LHOSFile(void)
// Bytes: 8bc1 c7006cf89900 c7400400000000 c3
__attribute__((no_callee_saves, MOV32rr_REV))
struct LHOSFile* __fastcall __ct__8LHOSFileFv(struct LHOSFile* this)
{
    register struct LHOSFile* result asm("eax");
    asm volatile ("" : "=r"(result) : "0"(this));
    *(uint32_t*)((char*)result + 0x00) = (uint32_t)(rdata_bytes + 0xf686c);
    *(uint32_t*)((char*)result + 0x04) = 0;
    return result;
}

// win1.41 007bc660 mac 10164ef0 LHOSFile::~LHOSFile(bool)
// Scalar deleting destructor: calls dtor, conditionally calls 1-arg delete
void __dt__8LHOSFileFb_decl(void) __asm__("___dt__8LHOSFileFb");
__attribute__((msvc6_sdtor("??_DLHOSFile@@QAEXXZ,??3@YAXPAX@Z,0,"), trailing_asm("nop\nnop")))
void __dt__8LHOSFileFb_decl(void) {}

// win1.41 007bc680 mac inlined LHOSFile::~LHOSFile(void)
// Bytes: 56 8bf1 8b4604 c7066cf89900 85c0 740e 50 ff15c4928a00 c7460400000000 5e c3
void __fastcall __dt__8LHOSFileFv_impl(struct LHOSFile* this) __asm__("??_DLHOSFile@@QAEXXZ");
__attribute__((forced_callee_saves("esi"), force_this_esi, MOV32rr_REV))
void __fastcall __dt__8LHOSFileFv_impl(struct LHOSFile* this)
{
    extern __attribute__((dllimport)) int __stdcall CloseHandle(void*);

    void* handle = *(void**)((char*)this + 0x04);
    *(uint32_t*)((char*)this + 0x00) = (uint32_t)(rdata_bytes + 0xf686c);
    if (handle) {
        CloseHandle(handle);
        *(uint32_t*)((char*)this + 0x04) = 0;
    }
}

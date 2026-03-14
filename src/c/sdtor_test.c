// Scalar deleting destructor test file.
// Replaces __declspec(naked) asm in staging .cpp files with msvc6_sdtor attribute.
//
// To test: build with the custom LLVM fork, then verify MD5 match.
// Once verified, remove the corresponding entries from:
//   - staging/runblack.reassemble.0049.0041a040-00422300.cpp (the naked functions)
//   - scripts/source_code/sdtor_rename_data.py (HIDE_AUTO + RENAME_MANUAL entries)

// --- standard_2arg: dtor + 2-arg delete, no vtable ---
// Was: sdtor_Cow in staging .cpp, renamed via sdtor_rename_data.py
void sdtor_Cow(void) __asm__("??_GCow@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Cow(void) {}

// --- vtable_write_2arg: vtable write + dtor + 2-arg delete ---
// Was: sdtor_Dove in staging .cpp
void sdtor_Dove(void) __asm__("??_GDove@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,??_7Dove@@6B@")))
void sdtor_Dove(void) {}

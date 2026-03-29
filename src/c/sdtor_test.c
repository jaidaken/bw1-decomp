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

// --- standard_2arg: same pattern for other animals (no vtable write) ---
void sdtor_PieceVillager(void) __asm__("??_GPieceVillager@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_PieceVillager(void) {}

void sdtor_Sheep(void) __asm__("??_GSheep@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Sheep(void) {}

void sdtor_PieceSheep(void) __asm__("??_GPieceSheep@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_PieceSheep(void) {}

void sdtor_Goat(void) __asm__("??_GGoat@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Goat(void) {}

void sdtor_Horse(void) __asm__("??_GHorse@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Horse(void) {}

void sdtor_PieceHorse(void) __asm__("??_GPieceHorse@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_PieceHorse(void) {}

void sdtor_Zebra(void) __asm__("??_GZebra@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Zebra(void) {}

void sdtor_Pig(void) __asm__("??_GPig@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Pig(void) {}

void sdtor_PiecePig(void) __asm__("??_GPiecePig@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_PiecePig(void) {}

void sdtor_Tortoise(void) __asm__("??_GTortoise@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Tortoise(void) {}

void sdtor_PieceTortoise(void) __asm__("??_GPieceTortoise@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_PieceTortoise(void) {}

// --- vtable_write_2arg: vtable write + dtor + 2-arg delete ---
// Was: sdtor_Dove in staging .cpp
void sdtor_Dove(void) __asm__("??_GDove@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,??_7Dove@@6B@")))
void sdtor_Dove(void) {}

// --- vtable_write_2arg: flying animals with Dove vtable ---
void sdtor_SpellDove(void) __asm__("??_GSpellDove@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,376,??_7Dove@@6B@")))
void sdtor_SpellDove(void) {}

void sdtor_Crow(void) __asm__("??_GCrow@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,??_7Dove@@6B@")))
void sdtor_Crow(void) {}

void sdtor_Swallow(void) __asm__("??_GSwallow@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,??_7Dove@@6B@")))
void sdtor_Swallow(void) {}

void sdtor_Pigeon(void) __asm__("??_GPigeon@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,??_7Dove@@6B@")))
void sdtor_Pigeon(void) {}

void sdtor_Seagull(void) __asm__("??_GSeagull@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,??_7Dove@@6B@")))
void sdtor_Seagull(void) {}

void sdtor_Bat(void) __asm__("??_GBat@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,??_7Dove@@6B@")))
void sdtor_Bat(void) {}

void sdtor_SpellBat(void) __asm__("??_GSpellBat@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,376,??_7Dove@@6B@")))
void sdtor_SpellBat(void) {}

void sdtor_Vulture(void) __asm__("??_GVulture@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,??_7Dove@@6B@")))
void sdtor_Vulture(void) {}

// --- different dtor (predator/wolf animals) ---
void sdtor_Leopard(void) __asm__("??_GLeopard@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0041fdc0,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Leopard(void) {}

void sdtor_Lion(void) __asm__("??_GLion@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0041fdc0,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Lion(void) {}

void sdtor_PieceLion(void) __asm__("??_GPieceLion@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0041fdc0,??3Base@@SAXPAXK@Z,328,")))
void sdtor_PieceLion(void) {}

void sdtor_SpellWolf(void) __asm__("??_GSpellWolf@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0041fdc0,??3Base@@SAXPAXK@Z,412,")))
void sdtor_SpellWolf(void) {}

void sdtor_Tiger(void) __asm__("??_GTiger@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0041fdc0,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Tiger(void) {}

void sdtor_Wolf(void) __asm__("??_GWolf@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0041fdc0,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Wolf(void) {}

void sdtor_PieceWolf(void) __asm__("??_GPieceWolf@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0041fdc0,??3Base@@SAXPAXK@Z,328,")))
void sdtor_PieceWolf(void) {}

// --- other sdtors from staging 0049 ---
void sdtor_GAnimatedStaticInfo(void) __asm__("??_GGAnimatedStaticInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,300,")))
void sdtor_GAnimatedStaticInfo(void) {}

void sdtor_AnimatedStatic(void) __asm__("??_GAnimatedStatic@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00422e30,??3Base@@SAXPAXK@Z,152,")))
void sdtor_AnimatedStatic(void) {}

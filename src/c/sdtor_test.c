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

// --- Setup* classes: 1-arg delete, all share SetupControl dtor ---
void sdtor_SetupControl(void) __asm__("??_GSetupControl@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupControl(void) {}

void sdtor_SetupButton(void) __asm__("??_GSetupButton@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupButton(void) {}

void sdtor_SetupSlider(void) __asm__("??_GSetupSlider@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupSlider(void) {}

void sdtor_SetupMultiList(void) __asm__("??_GSetupMultiList@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0040b4c0,??3@YAXPAX@Z,0,")))
void sdtor_SetupMultiList(void) {}

void sdtor_SetupEdit(void) __asm__("??_GSetupEdit@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupEdit(void) {}

void sdtor_SetupBigButton(void) __asm__("??_GSetupBigButton@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupBigButton(void) {}

void sdtor_SetupHLineGraph(void) __asm__("??_GSetupHLineGraph@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupHLineGraph(void) {}

void sdtor_SetupVBarGraph(void) __asm__("??_GSetupVBarGraph@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupVBarGraph(void) {}

void sdtor_SetupTabButton(void) __asm__("??_GSetupTabButton@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupTabButton(void) {}

void sdtor_SetupPicture(void) __asm__("??_GSetupPicture@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupPicture(void) {}

void sdtor_SetupColourPicker(void) __asm__("??_GSetupColourPicker@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupColourPicker(void) {}

void sdtor_SetupCheckBox(void) __asm__("??_GSetupCheckBox@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupCheckBox(void) {}

void sdtor_SetupStaticText(void) __asm__("??_GSetupStaticText@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupStaticText(void) {}

void sdtor_SetupHSBarGraph(void) __asm__("??_GSetupHSBarGraph@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupHSBarGraph(void) {}

void sdtor_SetupStaticTextNoHit(void) __asm__("??_GSetupStaticTextNoHit@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupStaticTextNoHit(void) {}

void sdtor_SetupMP3Button(void) __asm__("??_GSetupMP3Button@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1SetupControl@@UAE@XZ,??3@YAXPAX@Z,0,")))
void sdtor_SetupMP3Button(void) {}

// --- misc sdtors from staging 0073 ---
void sdtor_GArena(void) __asm__("??_GGArena@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void sdtor_GArena(void) {}

void sdtor_ArenaSpellIcon(void) __asm__("??_GArenaSpellIcon@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00425410,??3Base@@SAXPAXK@Z,116,")))
void sdtor_ArenaSpellIcon(void) {}

void sdtor_GArrowInfo(void) __asm__("??_GGArrowInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,304,")))
void sdtor_GArrowInfo(void) {}

void sdtor_Arrow(void) __asm__("??_GArrow@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00606ed0,??3Base@@SAXPAXK@Z,108,")))
void sdtor_Arrow(void) {}

void sdtor_TownArtifact(void) __asm__("??_GTownArtifact@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,64,")))
void sdtor_TownArtifact(void) {}

// --- manual sdtors (original 11, all with vtable write) ---
void sdtor_Feature(void) __asm__("??_GFeature@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Feature@@UAE@XZ,??3Base@@SAXPAXK@Z,124,??_7Feature@@6B@")))
void sdtor_Feature(void) {}

void sdtor_CitadelBuildingSite(void) __asm__("??_GCitadelBuildingSite@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1CitadelBuildingSite@@UAE@XZ,??3Base@@SAXPAXK@Z,1628,??_7CitadelBuildingSite@@6B@")))
void sdtor_CitadelBuildingSite(void) {}

void sdtor_Mobile(void) __asm__("??_GMobile@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Mobile@@UAE@XZ,??3Base@@SAXPAXK@Z,88,??_7Mobile@@6B@")))
void sdtor_Mobile(void) {}

void sdtor_Flowers(void) __asm__("??_GFlowers@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Flowers@@UAE@XZ,??3Base@@SAXPAXK@Z,124,??_7Flowers@@6B@")))
void sdtor_Flowers(void) {}

void sdtor_Furniture(void) __asm__("??_GFurniture@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Furniture@@UAE@XZ,??3Base@@SAXPAXK@Z,84,??_7Furniture@@6B@")))
void sdtor_Furniture(void) {}

void sdtor_GestureSystem(void) __asm__("??_GGestureSystem@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1GestureSystem@@UAE@XZ,??3Base@@SAXPAXK@Z,3224,??_7GestureSystem@@6B@")))
void sdtor_GestureSystem(void) {}

void sdtor_PSysInterface(void) __asm__("??_GPSysInterface@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1PSysInterface@@UAE@XZ,??3Base@@SAXPAXK@Z,20,??_7PSysInterface@@6B@")))
void sdtor_PSysInterface(void) {}

void sdtor_Particle3DPnt(void) __asm__("??_GParticle3DPnt@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Particle3DPnt@@UAE@XZ,??3Base@@SAXPAXK@Z,24,??_7Particle3DPnt@@6B@")))
void sdtor_Particle3DPnt(void) {}

void sdtor_ParticleChainJoint(void) __asm__("??_GParticleChainJoint@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1ParticleChainJoint@@UAE@XZ,??3Base@@SAXPAXK@Z,40,??_7ParticleChainJoint@@6B@")))
void sdtor_ParticleChainJoint(void) {}

void sdtor_TownStats(void) __asm__("??_GTownStats@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1TownStats@@UAE@XZ,??3Base@@SAXPAXK@Z,280,??_7TownStats@@6B@")))
void sdtor_TownStats(void) {}

void sdtor_WorshipSiteUpgrade(void) __asm__("??_GWorshipSiteUpgrade@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1WorshipSiteUpgrade@@UAE@XZ,??3Base@@SAXPAXK@Z,132,??_7WorshipSiteUpgrade@@6B@")))
void sdtor_WorshipSiteUpgrade(void) {}

// --- batch-generated sdtor conversions ---
void sdtor_GAlignmentInfo(void) __asm__("??_GGAlignmentInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,72,")))
void sdtor_GAlignmentInfo(void) {}

void sdtor_GAnimalInfo(void) __asm__("??_GGAnimalInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,716,")))
void sdtor_GAnimalInfo(void) {}

void sdtor_GAnimalStateTableInfo(void) __asm__("??_GGAnimalStateTableInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,184,")))
void sdtor_GAnimalStateTableInfo(void) {}

void sdtor_Animal(void) __asm__("??_GAnimal@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,328,")))
void sdtor_Animal(void) {}

void sdtor_ThingMusicInfo(void) __asm__("??_GThingMusicInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,56,")))
void sdtor_ThingMusicInfo(void) {}

void sdtor_GLeashSelectorInfo(void) __asm__("??_GGLeashSelectorInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,260,")))
void sdtor_GLeashSelectorInfo(void) {}

void sdtor_GBaseInfo(void) __asm__("??_GGBaseInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,16,")))
void sdtor_GBaseInfo(void) {}

void sdtor_LHReleasedOSFile(void) __asm__("??_GLHReleasedOSFile@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??_DLHOSFile@@QAEXXZ,??3@YAXPAX@Z,0,")))
void sdtor_LHReleasedOSFile(void) {}

void sdtor_GMagicInfo(void) __asm__("??_GGMagicInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,88,")))
void sdtor_GMagicInfo(void) {}

void sdtor_GMagicHealInfo(void) __asm__("??_GGMagicHealInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,96,")))
void sdtor_GMagicHealInfo(void) {}

void sdtor_GMagicTeleportInfo(void) __asm__("??_GGMagicTeleportInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,92,")))
void sdtor_GMagicTeleportInfo(void) {}

void sdtor_GMagicForestInfo(void) __asm__("??_GGMagicForestInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,108,")))
void sdtor_GMagicForestInfo(void) {}

void sdtor_GMagicResourceInfo(void) __asm__("??_GGMagicResourceInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,112,")))
void sdtor_GMagicResourceInfo(void) {}

void sdtor_GMagicStormAndTornadoInfo(void) __asm__("??_GGMagicStormAndTornadoInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,108,")))
void sdtor_GMagicStormAndTornadoInfo(void) {}

void sdtor_GMagicShieldInfo(void) __asm__("??_GGMagicShieldInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,116,")))
void sdtor_GMagicShieldInfo(void) {}

void sdtor_GMagicWaterInfo(void) __asm__("??_GGMagicWaterInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,88,")))
void sdtor_GMagicWaterInfo(void) {}

void sdtor_GMagicFlockFlyingInfo(void) __asm__("??_GGMagicFlockFlyingInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,100,")))
void sdtor_GMagicFlockFlyingInfo(void) {}

void sdtor_GMagicFlockGroundInfo(void) __asm__("??_GGMagicFlockGroundInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,104,")))
void sdtor_GMagicFlockGroundInfo(void) {}

void sdtor_GMagicCreatureSpellInfo(void) __asm__("??_GGMagicCreatureSpellInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,156,")))
void sdtor_GMagicCreatureSpellInfo(void) {}

void sdtor_GMagicObjectInfo(void) __asm__("??_GGMagicObjectInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,92,")))
void sdtor_GMagicObjectInfo(void) {}

void sdtor_GMagicRadiusSpellInfo(void) __asm__("??_GGMagicRadiusSpellInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,100,")))
void sdtor_GMagicRadiusSpellInfo(void) {}

void sdtor_GBallInfo(void) __asm__("??_GGBallInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,320,")))
void sdtor_GBallInfo(void) {}

void sdtor_Ball(void) __asm__("??_GBall@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00435b10,??3Base@@SAXPAXK@Z,184,")))
void sdtor_Ball(void) {}

void sdtor_GBeliefInfo(void) __asm__("??_GGBeliefInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,40,")))
void sdtor_GBeliefInfo(void) {}

void sdtor_GBigForestInfo(void) __asm__("??_GGBigForestInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,296,")))
void sdtor_GBigForestInfo(void) {}

void sdtor_BigForest(void) __asm__("??_GBigForest@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00438e50,??3Base@@SAXPAXK@Z,136,")))
void sdtor_BigForest(void) {}

void sdtor_Bonfire(void) __asm__("??_GBonfire@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00608750,??3Base@@SAXPAXK@Z,152,")))
void sdtor_Bonfire(void) {}

void sdtor_BuildingSite(void) __asm__("??_GBuildingSite@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0043b8d0,??3Base@@SAXPAXK@Z,1604,")))
void sdtor_BuildingSite(void) {}

void sdtor_StandardBuildingSite(void) __asm__("??_GStandardBuildingSite@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0043d750,??3Base@@SAXPAXK@Z,1608,")))
void sdtor_StandardBuildingSite(void) {}

void sdtor_WorkshopBuildingSite(void) __asm__("??_GWorkshopBuildingSite@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0043d9a0,??3Base@@SAXPAXK@Z,1604,")))
void sdtor_WorkshopBuildingSite(void) {}

void sdtor_GCamera(void) __asm__("??_GGCamera@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,472,")))
void sdtor_GCamera(void) {}

void sdtor_GCitadelInfo(void) __asm__("??_GGCitadelInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,84,")))
void sdtor_GCitadelInfo(void) {}

void sdtor_Citadel(void) __asm__("??_GCitadel@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,128,")))
void sdtor_Citadel(void) {}

void sdtor_GCitadelHeartInfo(void) __asm__("??_GGCitadelHeartInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,344,")))
void sdtor_GCitadelHeartInfo(void) {}

void sdtor_LeashObj(void) __asm__("??_GLeashObj@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00636640,??3Base@@SAXPAXK@Z,120,")))
void sdtor_LeashObj(void) {}

void sdtor_CitadelHeart(void) __asm__("??_GCitadelHeart@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00464bf0,??3Base@@SAXPAXK@Z,232,")))
void sdtor_CitadelHeart(void) {}

void sdtor_PlannedCitadelHeart(void) __asm__("??_GPlannedCitadelHeart@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void sdtor_PlannedCitadelHeart(void) {}

void sdtor_PlannedTownCitadelHeart(void) __asm__("??_GPlannedTownCitadelHeart@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void sdtor_PlannedTownCitadelHeart(void) {}

void sdtor_CitadelEntrance(void) __asm__("??_GCitadelEntrance@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00636640,??3Base@@SAXPAXK@Z,104,??_7CitadelEntrance@@6B@")))
void sdtor_CitadelEntrance(void) {}

void sdtor_CitadelPart(void) __asm__("??_GCitadelPart@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00469530,??3Base@@SAXPAXK@Z,140,")))
void sdtor_CitadelPart(void) {}

void sdtor_PlannedCitadelPart(void) __asm__("??_GPlannedCitadelPart@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void sdtor_PlannedCitadelPart(void) {}

void sdtor_GContainerInfo(void) __asm__("??_GGContainerInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,20,")))
void sdtor_GContainerInfo(void) {}

void sdtor_Container(void) __asm__("??_GContainer@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,48,")))
void sdtor_Container(void) {}

void sdtor_CPUCheck(void) __asm__("??_GCPUCheck@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00471aa0,??3@YAXPAX@Z,0,")))
void sdtor_CPUCheck(void) {}

void sdtor_CreatureInfo(void) __asm__("??_GCreatureInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,916,")))
void sdtor_CreatureInfo(void) {}

void sdtor_DifferentCreatureInfo(void) __asm__("??_GDifferentCreatureInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,108,")))
void sdtor_DifferentCreatureInfo(void) {}

void sdtor_CreaturePlan(void) __asm__("??_GCreaturePlan@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004f12d0,??3Base@@SAXPAXK@Z,48,")))
void sdtor_CreaturePlan(void) {}

void sdtor_CreatureSubAction(void) __asm__("??_GCreatureSubAction@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,96,")))
void sdtor_CreatureSubAction(void) {}

void sdtor_GAlignment(void) __asm__("??_GGAlignment@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,16,")))
void sdtor_GAlignment(void) {}

void sdtor_Creature(void) __asm__("??_GCreature@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00475170,??3Base@@SAXPAXK@Z,4808,")))
void sdtor_Creature(void) {}

void sdtor_MobileWallHug(void) __asm__("??_GMobileWallHug@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0060db00,??3Base@@SAXPAXK@Z,140,")))
void sdtor_MobileWallHug(void) {}

void sdtor_Living(void) __asm__("??_GLiving@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0060db00,??3Base@@SAXPAXK@Z,224,")))
void sdtor_Living(void) {}

void sdtor_CreatureActionInfo(void) __asm__("??_GCreatureActionInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,272,")))
void sdtor_CreatureActionInfo(void) {}

void sdtor_CreatureInitialDesireInfo(void) __asm__("??_GCreatureInitialDesireInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,448,")))
void sdtor_CreatureInitialDesireInfo(void) {}

void sdtor_CreatureDesireActionEntry(void) __asm__("??_GCreatureDesireActionEntry@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,136,")))
void sdtor_CreatureDesireActionEntry(void) {}

void sdtor_CreatureDesireAttributeEntry(void) __asm__("??_GCreatureDesireAttributeEntry@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,56,")))
void sdtor_CreatureDesireAttributeEntry(void) {}

void sdtor_CreatureCommand(void) __asm__("??_GCreatureCommand@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,28,")))
void sdtor_CreatureCommand(void) {}

void sdtor_CreatureAttitudeToPlayer(void) __asm__("??_GCreatureAttitudeToPlayer@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,7604,")))
void sdtor_CreatureAttitudeToPlayer(void) {}

void sdtor_Attribute(void) __asm__("??_GAttribute@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_Attribute(void) {}

void sdtor_AttributeAllegiance(void) __asm__("??_GAttributeAllegiance@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeAllegiance(void) {}

void sdtor_AttributeOrigin(void) __asm__("??_GAttributeOrigin@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeOrigin(void) {}

void sdtor_AttributeAnimate(void) __asm__("??_GAttributeAnimate@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeAnimate(void) {}

void sdtor_AttributeType(void) __asm__("??_GAttributeType@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeType(void) {}

void sdtor_AttributeLife(void) __asm__("??_GAttributeLife@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeLife(void) {}

void sdtor_AttributeVillagerJob(void) __asm__("??_GAttributeVillagerJob@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeVillagerJob(void) {}

void sdtor_AttributeSex(void) __asm__("??_GAttributeSex@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeSex(void) {}

void sdtor_AttributeOnFire(void) __asm__("??_GAttributeOnFire@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeOnFire(void) {}

void sdtor_AttributePlayerNumber(void) __asm__("??_GAttributePlayerNumber@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributePlayerNumber(void) {}

void sdtor_AttributeIsHarderThanMe(void) __asm__("??_GAttributeIsHarderThanMe@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeIsHarderThanMe(void) {}

void sdtor_AttributeCreatureType(void) __asm__("??_GAttributeCreatureType@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeCreatureType(void) {}

void sdtor_CreatureLearningEpisode(void) __asm__("??_GCreatureLearningEpisode@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004d4500,??3Base@@SAXPAXK@Z,20,")))
void sdtor_CreatureLearningEpisode(void) {}

void sdtor_AttributeTribe(void) __asm__("??_GAttributeTribe@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeTribe(void) {}

void sdtor_AttributeTownReligiousBeliefInYou(void) __asm__("??_GAttributeTownReligiousBeliefInYou@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeTownReligiousBeliefInYou(void) {}

void sdtor_AttributeWhatTownNeedsMost(void) __asm__("??_GAttributeWhatTownNeedsMost@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeWhatTownNeedsMost(void) {}

void sdtor_AttributeTownSize(void) __asm__("??_GAttributeTownSize@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeTownSize(void) {}

void sdtor_CreatureVisionState(void) __asm__("??_GCreatureVisionState@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,72,")))
void sdtor_CreatureVisionState(void) {}

void sdtor_CreatureBeliefList(void) __asm__("??_GCreatureBeliefList@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,20,")))
void sdtor_CreatureBeliefList(void) {}

void sdtor_CreatureBeliefs(void) __asm__("??_GCreatureBeliefs@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004d8a20,??3Base@@SAXPAXK@Z,624,")))
void sdtor_CreatureBeliefs(void) {}

void sdtor_CreatureMentalDebug(void) __asm__("??_GCreatureMentalDebug@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,76,")))
void sdtor_CreatureMentalDebug(void) {}

void sdtor_CreatureMental(void) __asm__("??_GCreatureMental@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x004d2590,??3Base@@SAXPAXK@Z,134464,")))
void sdtor_CreatureMental(void) {}

void sdtor_CreatureCommandState(void) __asm__("??_GCreatureCommandState@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,44,")))
void sdtor_CreatureCommandState(void) {}

void sdtor_CreatureAgenda(void) __asm__("??_GCreatureAgenda@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,6904,")))
void sdtor_CreatureAgenda(void) {}

void sdtor_AttributeCreatureDominantDesire(void) __asm__("??_GAttributeCreatureDominantDesire@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeCreatureDominantDesire(void) {}

void sdtor_AttributeCreatureHeight(void) __asm__("??_GAttributeCreatureHeight@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeCreatureHeight(void) {}

void sdtor_AttributeCreatureSpellKnowledge(void) __asm__("??_GAttributeCreatureSpellKnowledge@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeCreatureSpellKnowledge(void) {}

void sdtor_AttributeCreatureWhatHeIsCarrying(void) __asm__("??_GAttributeCreatureWhatHeIsCarrying@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeCreatureWhatHeIsCarrying(void) {}

void sdtor_AttributeForestSize(void) __asm__("??_GAttributeForestSize@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeForestSize(void) {}

void sdtor_AttributeMobileObjectType(void) __asm__("??_GAttributeMobileObjectType@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeMobileObjectType(void) {}

void sdtor_AttributeAbodeType(void) __asm__("??_GAttributeAbodeType@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeAbodeType(void) {}

void sdtor_AttributeAbodeBeingBuilt(void) __asm__("??_GAttributeAbodeBeingBuilt@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_AttributeAbodeBeingBuilt(void) {}

void sdtor_CreatureBeliefSmall(void) __asm__("??_GCreatureBeliefSmall@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004daab0,??3Base@@SAXPAXK@Z,104,")))
void sdtor_CreatureBeliefSmall(void) {}

void sdtor_CreatureBeliefAboutVillager(void) __asm__("??_GCreatureBeliefAboutVillager@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004dac30,??3Base@@SAXPAXK@Z,120,")))
void sdtor_CreatureBeliefAboutVillager(void) {}

void sdtor_CreatureBeliefAboutTown(void) __asm__("??_GCreatureBeliefAboutTown@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004daaf0,??3Base@@SAXPAXK@Z,120,")))
void sdtor_CreatureBeliefAboutTown(void) {}

void sdtor_CreatureBeliefAboutFlock(void) __asm__("??_GCreatureBeliefAboutFlock@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004dab30,??3Base@@SAXPAXK@Z,104,")))
void sdtor_CreatureBeliefAboutFlock(void) {}

void sdtor_CreatureBeliefAboutCitadel(void) __asm__("??_GCreatureBeliefAboutCitadel@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004dacb0,??3Base@@SAXPAXK@Z,104,")))
void sdtor_CreatureBeliefAboutCitadel(void) {}

void sdtor_CreatureBeliefAboutCreature(void) __asm__("??_GCreatureBeliefAboutCreature@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004dab70,??3Base@@SAXPAXK@Z,124,")))
void sdtor_CreatureBeliefAboutCreature(void) {}

void sdtor_CreatureBeliefAboutForest(void) __asm__("??_GCreatureBeliefAboutForest@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004dabb0,??3Base@@SAXPAXK@Z,108,")))
void sdtor_CreatureBeliefAboutForest(void) {}

void sdtor_CreatureBeliefAboutAbode(void) __asm__("??_GCreatureBeliefAboutAbode@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004dac70,??3Base@@SAXPAXK@Z,120,")))
void sdtor_CreatureBeliefAboutAbode(void) {}

void sdtor_CreatureBeliefAboutContext(void) __asm__("??_GCreatureBeliefAboutContext@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004dacf0,??3Base@@SAXPAXK@Z,76,")))
void sdtor_CreatureBeliefAboutContext(void) {}

void sdtor_CreatureBelief(void) __asm__("??_GCreatureBelief@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004d8b50,??3Base@@SAXPAXK@Z,76,")))
void sdtor_CreatureBelief(void) {}

void sdtor_AllocatedBeliefList(void) __asm__("??_GAllocatedBeliefList@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,24,")))
void sdtor_AllocatedBeliefList(void) {}

void sdtor_CreatureBeliefAboutMobileObject(void) __asm__("??_GCreatureBeliefAboutMobileObject@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x004dabf0,??3Base@@SAXPAXK@Z,108,")))
void sdtor_CreatureBeliefAboutMobileObject(void) {}

void sdtor_CreatureDesireDependency(void) __asm__("??_GCreatureDesireDependency@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,176,")))
void sdtor_CreatureDesireDependency(void) {}

void sdtor_CreatureDesireForType(void) __asm__("??_GCreatureDesireForType@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,84,")))
void sdtor_CreatureDesireForType(void) {}

void sdtor_CreatureDevelopmentPhaseEntry(void) __asm__("??_GCreatureDevelopmentPhaseEntry@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,132,")))
void sdtor_CreatureDevelopmentPhaseEntry(void) {}

void sdtor_CreatureDevelopmentDurationEntry(void) __asm__("??_GCreatureDevelopmentDurationEntry@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,72,")))
void sdtor_CreatureDevelopmentDurationEntry(void) {}

void sdtor_CreatureDesires(void) __asm__("??_GCreatureDesires@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004dc070,??3Base@@SAXPAXK@Z,1800,")))
void sdtor_CreatureDesires(void) {}

void sdtor_CreatureDesireSourceTable(void) __asm__("??_GCreatureDesireSourceTable@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,164,")))
void sdtor_CreatureDesireSourceTable(void) {}

void sdtor_CreatureInitialSourceInfo(void) __asm__("??_GCreatureInitialSourceInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,84,")))
void sdtor_CreatureInitialSourceInfo(void) {}

void sdtor_CreatureSourceBoundsInfo(void) __asm__("??_GCreatureSourceBoundsInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,28,")))
void sdtor_CreatureSourceBoundsInfo(void) {}

void sdtor_CreatureExplorationRegionEntry(void) __asm__("??_GCreatureExplorationRegionEntry@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,28,")))
void sdtor_CreatureExplorationRegionEntry(void) {}

void sdtor_CreatureExplorationMap(void) __asm__("??_GCreatureExplorationMap@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,9240,")))
void sdtor_CreatureExplorationMap(void) {}

void sdtor_CreaturePreviousLesson(void) __asm__("??_GCreaturePreviousLesson@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,4620,")))
void sdtor_CreaturePreviousLesson(void) {}

void sdtor_CreatureLearning(void) __asm__("??_GCreatureLearning@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,90472,")))
void sdtor_CreatureLearning(void) {}

void sdtor_CreatureLearningContext(void) __asm__("??_GCreatureLearningContext@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x004e1d50,??3Base@@SAXPAXK@Z,24,")))
void sdtor_CreatureLearningContext(void) {}

void sdtor_CreatureActionsKnownAbout(void) __asm__("??_GCreatureActionsKnownAbout@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x004e2250,??3Base@@SAXPAXK@Z,24,")))
void sdtor_CreatureActionsKnownAbout(void) {}

void sdtor_CreatureActionKnownAbout(void) __asm__("??_GCreatureActionKnownAbout@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_CreatureActionKnownAbout(void) {}

void sdtor_CreatureActionKnownAboutEntry(void) __asm__("??_GCreatureActionKnownAboutEntry@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,104,")))
void sdtor_CreatureActionKnownAboutEntry(void) {}

void sdtor_CreatureMagicActionKnownAboutEntry(void) __asm__("??_GCreatureMagicActionKnownAboutEntry@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,112,")))
void sdtor_CreatureMagicActionKnownAboutEntry(void) {}

void sdtor_CreatureTimeToWait(void) __asm__("??_GCreatureTimeToWait@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,20,")))
void sdtor_CreatureTimeToWait(void) {}

void sdtor_CreatureObjectsInspected(void) __asm__("??_GCreatureObjectsInspected@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,104,")))
void sdtor_CreatureObjectsInspected(void) {}

void sdtor_CreatureMimicInfo(void) __asm__("??_GCreatureMimicInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,192,")))
void sdtor_CreatureMimicInfo(void) {}

void sdtor_CreatureMimicState(void) __asm__("??_GCreatureMimicState@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,60,")))
void sdtor_CreatureMimicState(void) {}

void sdtor_GCreaturePenInfo(void) __asm__("??_GGCreaturePenInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,324,")))
void sdtor_GCreaturePenInfo(void) {}

void sdtor_CreaturePen(void) __asm__("??_GCreaturePen@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x004eef00,??3Base@@SAXPAXK@Z,152,")))
void sdtor_CreaturePen(void) {}

void sdtor_PlannedCreaturePen(void) __asm__("??_GPlannedCreaturePen@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void sdtor_PlannedCreaturePen(void) {}

void sdtor_CreatureDamageMap(void) __asm__("??_GCreatureDamageMap@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,16,")))
void sdtor_CreatureDamageMap(void) {}

void sdtor_CreaturePhysical(void) __asm__("??_GCreaturePhysical@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,116,")))
void sdtor_CreaturePhysical(void) {}

void sdtor_CreaturePreviousActions(void) __asm__("??_GCreaturePreviousActions@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,1320,")))
void sdtor_CreaturePreviousActions(void) {}

void sdtor_Creche(void) __asm__("??_GCreche@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Abode@@UAE@XZ,??3Base@@SAXPAXK@Z,196,")))
void sdtor_Creche(void) {}

void sdtor_Creed(void) __asm__("??_GCreed@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00606ed0,??3Base@@SAXPAXK@Z,108,")))
void sdtor_Creed(void) {}

void sdtor_GDanceInfo(void) __asm__("??_GGDanceInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,176,")))
void sdtor_GDanceInfo(void) {}

void sdtor_Dance(void) __asm__("??_GDance@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0050b960,??3Base@@SAXPAXK@Z,300,")))
void sdtor_Dance(void) {}

void sdtor_GFootpathLink(void) __asm__("??_GGFootpathLink@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,28,")))
void sdtor_GFootpathLink(void) {}

void sdtor_DanceEditState(void) __asm__("??_GDanceEditState@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0050cc80,??3Base@@SAXPAXK@Z,232,")))
void sdtor_DanceEditState(void) {}

void sdtor_DanceGroup(void) __asm__("??_GDanceGroup@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,380,")))
void sdtor_DanceGroup(void) {}

void sdtor_DanceKeyFrame(void) __asm__("??_GDanceKeyFrame@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,36,")))
void sdtor_DanceKeyFrame(void) {}

void sdtor_GData(void) __asm__("??_GGData@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,40,")))
void sdtor_GData(void) {}

void sdtor_DeadTree(void) __asm__("??_GDeadTree@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00608750,??3Base@@SAXPAXK@Z,160,")))
void sdtor_DeadTree(void) {}

void sdtor_FelledTree(void) __asm__("??_GFelledTree@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00608750,??3Base@@SAXPAXK@Z,160,")))
void sdtor_FelledTree(void) {}

void sdtor_GEffectInfo(void) __asm__("??_GGEffectInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,52,")))
void sdtor_GEffectInfo(void) {}

void sdtor_GMagicEffectInfo(void) __asm__("??_GGMagicEffectInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,284,")))
void sdtor_GMagicEffectInfo(void) {}

void sdtor_EffectValues(void) __asm__("??_GEffectValues@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,64,")))
void sdtor_EffectValues(void) {}

void sdtor_GFeatureInfo(void) __asm__("??_GGFeatureInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,292,")))
void sdtor_GFeatureInfo(void) {}

void sdtor_PlannedFeature(void) __asm__("??_GPlannedFeature@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void sdtor_PlannedFeature(void) {}

void sdtor_GFlowersInfo(void) __asm__("??_GGFlowersInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,296,")))
void sdtor_GFlowersInfo(void) {}

void sdtor_GFieldInfo(void) __asm__("??_GGFieldInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,332,")))
void sdtor_GFieldInfo(void) {}

void sdtor_GFieldTypeInfo(void) __asm__("??_GGFieldTypeInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,340,")))
void sdtor_GFieldTypeInfo(void) {}

void sdtor_Field(void) __asm__("??_GField@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Abode@@UAE@XZ,??3Base@@SAXPAXK@Z,292,")))
void sdtor_Field(void) {}

void sdtor_FireFly(void) __asm__("??_GFireFly@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0052a490,??3Base@@SAXPAXK@Z,196,")))
void sdtor_FireFly(void) {}

void sdtor_GFishFarmInfo(void) __asm__("??_GGFishFarmInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,296,")))
void sdtor_GFishFarmInfo(void) {}

void sdtor_FishFarm(void) __asm__("??_GFishFarm@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0052c5f0,??3Base@@SAXPAXK@Z,152,")))
void sdtor_FishFarm(void) {}

void sdtor_GSingleMapFixedInfo(void) __asm__("??_GGSingleMapFixedInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,260,")))
void sdtor_GSingleMapFixedInfo(void) {}

void sdtor_SingleMapFixed(void) __asm__("??_GSingleMapFixed@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0052eac0,??3Base@@SAXPAXK@Z,92,")))
void sdtor_SingleMapFixed(void) {}

void sdtor_Flock(void) __asm__("??_GFlock@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,144,")))
void sdtor_Flock(void) {}

void sdtor_GFootballPositionInfo(void) __asm__("??_GGFootballPositionInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,36,")))
void sdtor_GFootballPositionInfo(void) {}

void sdtor_Football(void) __asm__("??_GFootball@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Abode@@UAE@XZ,??3Base@@SAXPAXK@Z,792,")))
void sdtor_Football(void) {}

void sdtor_GFootpathNode(void) __asm__("??_GGFootpathNode@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,48,")))
void sdtor_GFootpathNode(void) {}

void sdtor_GFootpath(void) __asm__("??_GGFootpath@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00534ea0,??3Base@@SAXPAXK@Z,36,")))
void sdtor_GFootpath(void) {}

void sdtor_GFootpathLinkSave(void) __asm__("??_GGFootpathLinkSave@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,36,")))
void sdtor_GFootpathLinkSave(void) {}

void sdtor_GFootpathFinder(void) __asm__("??_GGFootpathFinder@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00539020,??3Base@@SAXPAXK@Z,409800,")))
void sdtor_GFootpathFinder(void) {}

void sdtor_GForestInfo(void) __asm__("??_GGForestInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,24,")))
void sdtor_GForestInfo(void) {}

void sdtor_GFurnitureInfo(void) __asm__("??_GGFurnitureInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,260,")))
void sdtor_GFurnitureInfo(void) {}

void sdtor_GKeyBuffer(void) __asm__("??_GGKeyBuffer@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x005e1a90,??3Base@@SAXPAXK@Z,16,")))
void sdtor_GKeyBuffer(void) {}

void sdtor_GSoundMap(void) __asm__("??_GGSoundMap@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,272,")))
void sdtor_GSoundMap(void) {}

void sdtor_GPlayerInfo(void) __asm__("??_GGPlayerInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,144,")))
void sdtor_GPlayerInfo(void) {}

void sdtor_TerrainMapTypeInfo(void) __asm__("??_GTerrainMapTypeInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,20,")))
void sdtor_TerrainMapTypeInfo(void) {}

void sdtor_GameArea(void) __asm__("??_GGameArea@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00557240,??3Base@@SAXPAXK@Z,28,")))
void sdtor_GameArea(void) {}

void sdtor_GGameInfo(void) __asm__("??_GGGameInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,88,")))
void sdtor_GGameInfo(void) {}

void sdtor_GameOSFile(void) __asm__("??_GGameOSFile@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00558050,??3@YAXPAX@Z,0,")))
void sdtor_GameOSFile(void) {}

void sdtor_Reaction(void) __asm__("??_GReaction@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x006e3a60,??3Base@@SAXPAXK@Z,68,")))
void sdtor_Reaction(void) {}

void sdtor_StoragePit(void) __asm__("??_GStoragePit@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00732c00,??3Base@@SAXPAXK@Z,220,")))
void sdtor_StoragePit(void) {}

void sdtor_SpellWithObjects(void) __asm__("??_GSpellWithObjects@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,244,")))
void sdtor_SpellWithObjects(void) {}

void sdtor_SpellResource(void) __asm__("??_GSpellResource@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,240,")))
void sdtor_SpellResource(void) {}

void sdtor_SpellWater(void) __asm__("??_GSpellWater@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,244,")))
void sdtor_SpellWater(void) {}

void sdtor_MobileObject(void) __asm__("??_GMobileObject@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00606ed0,??3Base@@SAXPAXK@Z,104,")))
void sdtor_MobileObject(void) {}

void sdtor_Poo(void) __asm__("??_GPoo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00606ed0,??3Base@@SAXPAXK@Z,104,")))
void sdtor_Poo(void) {}

void sdtor_FieldCrop(void) __asm__("??_GFieldCrop@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00607e10,??3Base@@SAXPAXK@Z,104,")))
void sdtor_FieldCrop(void) {}

void sdtor_OneOffSpellSeed(void) __asm__("??_GOneOffSpellSeed@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00606ed0,??3Base@@SAXPAXK@Z,124,")))
void sdtor_OneOffSpellSeed(void) {}

void sdtor_SpellHeal(void) __asm__("??_GSpellHeal@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,236,")))
void sdtor_SpellHeal(void) {}

void sdtor_SpellForest(void) __asm__("??_GSpellForest@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,248,")))
void sdtor_SpellForest(void) {}

void sdtor_SpellFlock(void) __asm__("??_GSpellFlock@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,272,")))
void sdtor_SpellFlock(void) {}

void sdtor_SpellFlockFlying(void) __asm__("??_GSpellFlockFlying@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x007239b0,??3Base@@SAXPAXK@Z,288,")))
void sdtor_SpellFlockFlying(void) {}

void sdtor_SpellFlockGround(void) __asm__("??_GSpellFlockGround@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,272,")))
void sdtor_SpellFlockGround(void) {}

void sdtor_SpellIcon(void) __asm__("??_GSpellIcon@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00726080,??3Base@@SAXPAXK@Z,272,")))
void sdtor_SpellIcon(void) {}

void sdtor_Pot(void) __asm__("??_GPot@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0066d100,??3Base@@SAXPAXK@Z,120,")))
void sdtor_Pot(void) {}

void sdtor_PotStructure(void) __asm__("??_GPotStructure@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0066d100,??3Base@@SAXPAXK@Z,132,")))
void sdtor_PotStructure(void) {}

void sdtor_PileWood(void) __asm__("??_GPileWood@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0066f1a0,??3Base@@SAXPAXK@Z,180,")))
void sdtor_PileWood(void) {}

void sdtor_MobileStatic(void) __asm__("??_GMobileStatic@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00608750,??3Base@@SAXPAXK@Z,136,")))
void sdtor_MobileStatic(void) {}

void sdtor_GBaseOnly(void) __asm__("??_GGBaseOnly@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00636640,??3Base@@SAXPAXK@Z,92,")))
void sdtor_GBaseOnly(void) {}

void sdtor_SpellTeleport(void) __asm__("??_GSpellTeleport@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,244,")))
void sdtor_SpellTeleport(void) {}

void sdtor_Tree(void) __asm__("??_GTree@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00749ed0,??3Base@@SAXPAXK@Z,108,")))
void sdtor_Tree(void) {}

void sdtor_TownDesireFlags(void) __asm__("??_GTownDesireFlags@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x007469d0,??3Base@@SAXPAXK@Z,152,")))
void sdtor_TownDesireFlags(void) {}

void sdtor_TownCentre(void) __asm__("??_GTownCentre@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00743ae0,??3Base@@SAXPAXK@Z,232,")))
void sdtor_TownCentre(void) {}

void sdtor_PlannedTownCentre(void) __asm__("??_GPlannedTownCentre@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void sdtor_PlannedTownCentre(void) {}

void sdtor_WorshipSite(void) __asm__("??_GWorshipSite@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0077aa30,??3Base@@SAXPAXK@Z,296,")))
void sdtor_WorshipSite(void) {}

void sdtor_ShowNeeds(void) __asm__("??_GShowNeeds@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,36,")))
void sdtor_ShowNeeds(void) {}

void sdtor_ShowNeedsVisuals(void) __asm__("??_GShowNeedsVisuals@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00636640,??3Base@@SAXPAXK@Z,148,")))
void sdtor_ShowNeedsVisuals(void) {}

void sdtor_GStream(void) __asm__("??_GGStream@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,40,")))
void sdtor_GStream(void) {}

void sdtor_GWaterfall(void) __asm__("??_GGWaterfall@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00734160,??3Base@@SAXPAXK@Z,88,")))
void sdtor_GWaterfall(void) {}

void sdtor_GClimate(void) __asm__("??_GGClimate@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x007713d0,??3Base@@SAXPAXK@Z,136,")))
void sdtor_GClimate(void) {}

void sdtor_WeatherThing(void) __asm__("??_GWeatherThing@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,136,")))
void sdtor_WeatherThing(void) {}

void sdtor_Graveyard(void) __asm__("??_GGraveyard@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Abode@@UAE@XZ,??3Base@@SAXPAXK@Z,200,")))
void sdtor_Graveyard(void) {}

void sdtor_TownSpellIcon(void) __asm__("??_GTownSpellIcon@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00748ad0,??3Base@@SAXPAXK@Z,280,")))
void sdtor_TownSpellIcon(void) {}

void sdtor_TownCentreSpellIcon(void) __asm__("??_GTownCentreSpellIcon@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00748c50,??3Base@@SAXPAXK@Z,296,")))
void sdtor_TownCentreSpellIcon(void) {}

void sdtor_Scaffold(void) __asm__("??_GScaffold@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x006e83d0,??3Base@@SAXPAXK@Z,156,")))
void sdtor_Scaffold(void) {}

void sdtor_PlayerSubActionArgument(void) __asm__("??_GPlayerSubActionArgument@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,116,")))
void sdtor_PlayerSubActionArgument(void) {}

void sdtor_PlayerSubAction(void) __asm__("??_GPlayerSubAction@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00650c40,??3Base@@SAXPAXK@Z,32,")))
void sdtor_PlayerSubAction(void) {}

void sdtor_PlayerActionState(void) __asm__("??_GPlayerActionState@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,652,")))
void sdtor_PlayerActionState(void) {}

void sdtor_GComputerAttitudeToPlayer(void) __asm__("??_GGComputerAttitudeToPlayer@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,24,")))
void sdtor_GComputerAttitudeToPlayer(void) {}

void sdtor_GComputerSeen(void) __asm__("??_GGComputerSeen@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,28,")))
void sdtor_GComputerSeen(void) {}

void sdtor_GComputerPlayer(void) __asm__("??_GGComputerPlayer@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,508,")))
void sdtor_GComputerPlayer(void) {}

void sdtor_Mist(void) __asm__("??_GMist@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,84,")))
void sdtor_Mist(void) {}

void sdtor_InfluenceRing(void) __asm__("??_GInfluenceRing@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,68,")))
void sdtor_InfluenceRing(void) {}

void sdtor_GParticleContainer(void) __asm__("??_GGParticleContainer@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,64,")))
void sdtor_GParticleContainer(void) {}

void sdtor_SpecialVillager(void) __asm__("??_GSpecialVillager@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0071f170,??3Base@@SAXPAXK@Z,308,")))
void sdtor_SpecialVillager(void) {}

void sdtor_ScriptMarker(void) __asm__("??_GScriptMarker@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,40,")))
void sdtor_ScriptMarker(void) {}

void sdtor_TotemStatue(void) __asm__("??_GTotemStatue@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00737bf0,??3Base@@SAXPAXK@Z,216,")))
void sdtor_TotemStatue(void) {}

void sdtor_Wonder(void) __asm__("??_GWonder@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Abode@@UAE@XZ,??3Base@@SAXPAXK@Z,200,")))
void sdtor_Wonder(void) {}

void sdtor_Whale(void) __asm__("??_GWhale@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00606ed0,??3Base@@SAXPAXK@Z,116,")))
void sdtor_Whale(void) {}

void sdtor_ScriptTimer(void) __asm__("??_GScriptTimer@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,48,")))
void sdtor_ScriptTimer(void) {}

void sdtor_Rock(void) __asm__("??_GRock@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00608750,??3Base@@SAXPAXK@Z,148,")))
void sdtor_Rock(void) {}

void sdtor_GStreetLight(void) __asm__("??_GGStreetLight@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,44,")))
void sdtor_GStreetLight(void) {}

void sdtor_GStreetLantern(void) __asm__("??_GGStreetLantern@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x007347c0,??3Base@@SAXPAXK@Z,100,")))
void sdtor_GStreetLantern(void) {}

void sdtor_GComputerSpellCast(void) __asm__("??_GGComputerSpellCast@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,28,")))
void sdtor_GComputerSpellCast(void) {}

void sdtor_Totem(void) __asm__("??_GTotem@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Abode@@UAE@XZ,??3Base@@SAXPAXK@Z,228,")))
void sdtor_Totem(void) {}

void sdtor_PuzzleLion(void) __asm__("??_GPuzzleLion@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0041fdc0,??3Base@@SAXPAXK@Z,340,")))
void sdtor_PuzzleLion(void) {}

void sdtor_PuzzleVillager(void) __asm__("??_GPuzzleVillager@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,340,")))
void sdtor_PuzzleVillager(void) {}

void sdtor_PuzzleSheep(void) __asm__("??_GPuzzleSheep@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,340,")))
void sdtor_PuzzleSheep(void) {}

void sdtor_HanoiBlock(void) __asm__("??_GHanoiBlock@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00606ed0,??3Base@@SAXPAXK@Z,128,")))
void sdtor_HanoiBlock(void) {}

void sdtor_PuzzleTotem(void) __asm__("??_GPuzzleTotem@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Abode@@UAE@XZ,??3Base@@SAXPAXK@Z,252,")))
void sdtor_PuzzleTotem(void) {}

void sdtor_PuzzleGrain(void) __asm__("??_GPuzzleGrain@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0066e0e0,??3Base@@SAXPAXK@Z,192,")))
void sdtor_PuzzleGrain(void) {}

void sdtor_PuzzleMobileObject(void) __asm__("??_GPuzzleMobileObject@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00606ed0,??3Base@@SAXPAXK@Z,108,")))
void sdtor_PuzzleMobileObject(void) {}

void sdtor_PuzzleGame(void) __asm__("??_GPuzzleGame@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,1416,")))
void sdtor_PuzzleGame(void) {}

void sdtor_GComputerPlayerQueue(void) __asm__("??_GGComputerPlayerQueue@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00664380,??3Base@@SAXPAXK@Z,296,")))
void sdtor_GComputerPlayerQueue(void) {}

void sdtor_GameStats(void) __asm__("??_GGameStats@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00564b30,??3Base@@SAXPAXK@Z,4392,")))
void sdtor_GameStats(void) {}

void sdtor_Persistent(void) __asm__("??_GPersistent@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00580a90,??3@YAXPAX@Z,0,")))
void sdtor_Persistent(void) {}

void sdtor_GroupBehaviour(void) __asm__("??_GGroupBehaviour@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00596230,??3Base@@SAXPAXK@Z,232,")))
void sdtor_GroupBehaviour(void) {}

void sdtor_HelpProfile(void) __asm__("??_GHelpProfile@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,13144,")))
void sdtor_HelpProfile(void) {}

void sdtor_HelpSpiritInfo(void) __asm__("??_GHelpSpiritInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,504,")))
void sdtor_HelpSpiritInfo(void) {}

void sdtor_HelpSpirit(void) __asm__("??_GHelpSpirit@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00636640,??3Base@@SAXPAXK@Z,100,")))
void sdtor_HelpSpirit(void) {}

void sdtor_HelpSystemInfo(void) __asm__("??_GHelpSystemInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,32,")))
void sdtor_HelpSystemInfo(void) {}

void sdtor_HelpSystem(void) __asm__("??_GHelpSystem@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x005c5680,??3Base@@SAXPAXK@Z,17940,")))
void sdtor_HelpSystem(void) {}

void sdtor_GToolTipsInfo(void) __asm__("??_GGToolTipsInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,28,")))
void sdtor_GToolTipsInfo(void) {}

void sdtor_HelpText(void) __asm__("??_GHelpText@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x005cb070,??3Base@@SAXPAXK@Z,188,")))
void sdtor_HelpText(void) {}

void sdtor_GInfluenceInfo(void) __asm__("??_GGInfluenceInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,28,")))
void sdtor_GInfluenceInfo(void) {}

void sdtor_GInterfaceMessageBuffer(void) __asm__("??_GGInterfaceMessageBuffer@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x005d9e20,??3Base@@SAXPAXK@Z,20,")))
void sdtor_GInterfaceMessageBuffer(void) {}

void sdtor_GInterface(void) __asm__("??_GGInterface@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x005ce3a0,??3Base@@SAXPAXK@Z,1148,")))
void sdtor_GInterface(void) {}

void sdtor_GInterfaceFlags(void) __asm__("??_GGInterfaceFlags@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,20,")))
void sdtor_GInterfaceFlags(void) {}

void sdtor_InterfaceHandState(void) __asm__("??_GInterfaceHandState@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,12,")))
void sdtor_InterfaceHandState(void) {}

void sdtor_GInterfaceCollide(void) __asm__("??_GGInterfaceCollide@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,48,")))
void sdtor_GInterfaceCollide(void) {}

void sdtor_GLeashStatus(void) __asm__("??_GGLeashStatus@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,60,")))
void sdtor_GLeashStatus(void) {}

void sdtor_GInterfaceStatus(void) __asm__("??_GGInterfaceStatus@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x005db9c0,??3Base@@SAXPAXK@Z,308,")))
void sdtor_GInterfaceStatus(void) {}

void sdtor_GJobInfo(void) __asm__("??_GGJobInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,88,")))
void sdtor_GJobInfo(void) {}

void sdtor_GLanguage(void) __asm__("??_GGLanguage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x005e6790,??3Base@@SAXPAXK@Z,12,")))
void sdtor_GLanguage(void) {}

void sdtor_DataPath(void) __asm__("??_GDataPath@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x005ef0b0,??3Base@@SAXPAXK@Z,48,")))
void sdtor_DataPath(void) {}

void sdtor_DataForScriptRemind(void) __asm__("??_GDataForScriptRemind@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,72,")))
void sdtor_DataForScriptRemind(void) {}

void sdtor_MagicFood(void) __asm__("??_GMagicFood@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x005faa70,??3Base@@SAXPAXK@Z,192,")))
void sdtor_MagicFood(void) {}

void sdtor_GMagicHand(void) __asm__("??_GGMagicHand@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x005faf60,??3Base@@SAXPAXK@Z,28,")))
void sdtor_GMagicHand(void) {}

void sdtor_GMagicLivingInfo(void) __asm__("??_GGMagicLivingInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,520,")))
void sdtor_GMagicLivingInfo(void) {}

void sdtor_MagicTeleport(void) __asm__("??_GMagicTeleport@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x005fc300,??3Base@@SAXPAXK@Z,164,")))
void sdtor_MagicTeleport(void) {}

void sdtor_MagicTree(void) __asm__("??_GMagicTree@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00749ed0,??3Base@@SAXPAXK@Z,116,")))
void sdtor_MagicTree(void) {}

void sdtor_GVortexInfo(void) __asm__("??_GGVortexInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,64,")))
void sdtor_GVortexInfo(void) {}

void sdtor_MagicWood(void) __asm__("??_GMagicWood@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00600eb0,??3Base@@SAXPAXK@Z,184,")))
void sdtor_MagicWood(void) {}

void sdtor_GMap(void) __asm__("??_GGMap@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x006010f0,??3Base@@SAXPAXK@Z,2097232,")))
void sdtor_GMap(void) {}

void sdtor_Meeting(void) __asm__("??_GMeeting@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,64,")))
void sdtor_Meeting(void) {}

void sdtor_GSpeedThreshold(void) __asm__("??_GGSpeedThreshold@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,24,")))
void sdtor_GSpeedThreshold(void) {}

void sdtor_GMobileObjectInfo(void) __asm__("??_GGMobileObjectInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,276,")))
void sdtor_GMobileObjectInfo(void) {}

void sdtor_GMobileStaticInfo(void) __asm__("??_GGMobileStaticInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,300,")))
void sdtor_GMobileStaticInfo(void) {}

void sdtor_MPFEPublicChatMessage(void) __asm__("??_GMPFEPublicChatMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEPublicChatMessage(void) {}

void sdtor_MPFEPrivateChatMessage(void) __asm__("??_GMPFEPrivateChatMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEPrivateChatMessage(void) {}

void sdtor_MPFEAskJoinMessage(void) __asm__("??_GMPFEAskJoinMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEAskJoinMessage(void) {}

void sdtor_MPFEReplyToJoinMessage(void) __asm__("??_GMPFEReplyToJoinMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEReplyToJoinMessage(void) {}

void sdtor_MPFEInviteToTeamMessage(void) __asm__("??_GMPFEInviteToTeamMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEInviteToTeamMessage(void) {}

void sdtor_MPFEReplyToInviteMessage(void) __asm__("??_GMPFEReplyToInviteMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEReplyToInviteMessage(void) {}

void sdtor_MPFECancelStartMessage(void) __asm__("??_GMPFECancelStartMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFECancelStartMessage(void) {}

void sdtor_MPFEKickMessageRequest(void) __asm__("??_GMPFEKickMessageRequest@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEKickMessageRequest(void) {}

void sdtor_MPFEKickMessage(void) __asm__("??_GMPFEKickMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEKickMessage(void) {}

void sdtor_MPFEDatabaseID(void) __asm__("??_GMPFEDatabaseID@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEDatabaseID(void) {}

void sdtor_MPFEReadyMessage(void) __asm__("??_GMPFEReadyMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEReadyMessage(void) {}

void sdtor_MPFETeamsReadyList(void) __asm__("??_GMPFETeamsReadyList@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFETeamsReadyList(void) {}

void sdtor_MPFEHasCreature(void) __asm__("??_GMPFEHasCreature@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEHasCreature(void) {}

void sdtor_MPFEClanList(void) __asm__("??_GMPFEClanList@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEClanList(void) {}

void sdtor_MPFEChangeClanRequest(void) __asm__("??_GMPFEChangeClanRequest@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEChangeClanRequest(void) {}

void sdtor_MPFECondtionUpdateMessage(void) __asm__("??_GMPFECondtionUpdateMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFECondtionUpdateMessage(void) {}

void sdtor_MPFEFileTransferMessage(void) __asm__("??_GMPFEFileTransferMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEFileTransferMessage(void) {}

void sdtor_MPFEStartGameOkayToStartMessage(void) __asm__("??_GMPFEStartGameOkayToStartMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEStartGameOkayToStartMessage(void) {}

void sdtor_MPFEStartGameReadyMessage(void) __asm__("??_GMPFEStartGameReadyMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEStartGameReadyMessage(void) {}

void sdtor_MPFEStartGameTransferFilesMessage(void) __asm__("??_GMPFEStartGameTransferFilesMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEStartGameTransferFilesMessage(void) {}

void sdtor_MPFEStartGameNowMessage(void) __asm__("??_GMPFEStartGameNowMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEStartGameNowMessage(void) {}

void sdtor_MPFEDisconnectNowMessage(void) __asm__("??_GMPFEDisconnectNowMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEDisconnectNowMessage(void) {}

void sdtor_MPFEChangedMapMessage(void) __asm__("??_GMPFEChangedMapMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEChangedMapMessage(void) {}

void sdtor_MPFEMapErrorMessage(void) __asm__("??_GMPFEMapErrorMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEMapErrorMessage(void) {}

void sdtor_MPFEChangedTeamRequestMessage(void) __asm__("??_GMPFEChangedTeamRequestMessage@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEChangedTeamRequestMessage(void) {}

void sdtor_MPFEUserTeamList(void) __asm__("??_GMPFEUserTeamList@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??3@YAXPAX@Z,??3@YAXPAX@Z,0,??_7MPFEMessageObject@@6B@")))
void sdtor_MPFEUserTeamList(void) {}

void sdtor_GObjectInfo(void) __asm__("??_GGObjectInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,256,")))
void sdtor_GObjectInfo(void) {}

void sdtor_GSpotVisualInfo(void) __asm__("??_GGSpotVisualInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,84,")))
void sdtor_GSpotVisualInfo(void) {}

void sdtor_GPBallInfo(void) __asm__("??_GGPBallInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,284,")))
void sdtor_GPBallInfo(void) {}

void sdtor_PBall(void) __asm__("??_GPBall@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0063e970,??3Base@@SAXPAXK@Z,116,")))
void sdtor_PBall(void) {}

void sdtor_GPFootballInfo(void) __asm__("??_GGPFootballInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,292,")))
void sdtor_GPFootballInfo(void) {}

void sdtor_GPFootballPositionInfo(void) __asm__("??_GGPFootballPositionInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,36,")))
void sdtor_GPFootballPositionInfo(void) {}

void sdtor_PPlannedFootball(void) __asm__("??_GPPlannedFootball@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void sdtor_PPlannedFootball(void) {}

void sdtor_PFootball(void) __asm__("??_GPFootball@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x006439c0,??3Base@@SAXPAXK@Z,188,")))
void sdtor_PFootball(void) {}

void sdtor_GPlayer(void) __asm__("??_GGPlayer@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00648ee0,??3Base@@SAXPAXK@Z,2656,")))
void sdtor_GPlayer(void) {}

void sdtor_GPlaytimeInfo(void) __asm__("??_GGPlaytimeInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,36,")))
void sdtor_GPlaytimeInfo(void) {}

void sdtor_PlaytimeElement(void) __asm__("??_GPlaytimeElement@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,68,")))
void sdtor_PlaytimeElement(void) {}

void sdtor_GPotInfo(void) __asm__("??_GGPotInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,324,")))
void sdtor_GPotInfo(void) {}

void sdtor_PileFood(void) __asm__("??_GPileFood@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0066e0e0,??3Base@@SAXPAXK@Z,188,")))
void sdtor_PileFood(void) {}

void sdtor_PileResource(void) __asm__("??_GPileResource@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0066d100,??3Base@@SAXPAXK@Z,180,")))
void sdtor_PileResource(void) {}

void sdtor_GPrayerSiteInfo(void) __asm__("??_GGPrayerSiteInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,296,")))
void sdtor_GPrayerSiteInfo(void) {}

void sdtor_GPrayerIconInfo(void) __asm__("??_GGPrayerIconInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,264,")))
void sdtor_GPrayerIconInfo(void) {}

void sdtor_PrayerSite(void) __asm__("??_GPrayerSite@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0052e280,??3Base@@SAXPAXK@Z,144,")))
void sdtor_PrayerSite(void) {}

void sdtor_PrayerIcon(void) __asm__("??_GPrayerIcon@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0052eac0,??3Base@@SAXPAXK@Z,100,")))
void sdtor_PrayerIcon(void) {}

void sdtor_GMagicFireBallInfo(void) __asm__("??_GGMagicFireBallInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,268,")))
void sdtor_GMagicFireBallInfo(void) {}

void sdtor_MagicFireBall(void) __asm__("??_GMagicFireBall@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00682be0,??3Base@@SAXPAXK@Z,96,")))
void sdtor_MagicFireBall(void) {}

void sdtor_ParticleCreator(void) __asm__("??_GParticleCreator@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00580a90,??3@YAXPAX@Z,0,")))
void sdtor_ParticleCreator(void) {}

void sdtor_FloatProvider(void) __asm__("??_GFloatProvider@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00580a90,??3@YAXPAX@Z,0,??_7FloatProvider@@6B@")))
void sdtor_FloatProvider(void) {}

void sdtor_PuzzleHorse(void) __asm__("??_GPuzzleHorse@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,340,")))
void sdtor_PuzzleHorse(void) {}

void sdtor_PuzzleTortoise(void) __asm__("??_GPuzzleTortoise@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,340,")))
void sdtor_PuzzleTortoise(void) {}

void sdtor_PuzzleCow(void) __asm__("??_GPuzzleCow@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,340,")))
void sdtor_PuzzleCow(void) {}

void sdtor_PuzzlePig(void) __asm__("??_GPuzzlePig@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00417b80,??3Base@@SAXPAXK@Z,340,")))
void sdtor_PuzzlePig(void) {}

void sdtor_ChessGamePuzzle(void) __asm__("??_GChessGamePuzzle@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,312,")))
void sdtor_ChessGamePuzzle(void) {}

void sdtor_ChessPion(void) __asm__("??_GChessPion@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00422e30,??3Base@@SAXPAXK@Z,156,")))
void sdtor_ChessPion(void) {}

void sdtor_ChessTower(void) __asm__("??_GChessTower@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00422e30,??3Base@@SAXPAXK@Z,156,")))
void sdtor_ChessTower(void) {}

void sdtor_ChessKnight(void) __asm__("??_GChessKnight@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00422e30,??3Base@@SAXPAXK@Z,156,")))
void sdtor_ChessKnight(void) {}

void sdtor_ChessMad(void) __asm__("??_GChessMad@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00422e30,??3Base@@SAXPAXK@Z,156,")))
void sdtor_ChessMad(void) {}

void sdtor_ChessQueen(void) __asm__("??_GChessQueen@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00422e30,??3Base@@SAXPAXK@Z,156,")))
void sdtor_ChessQueen(void) {}

void sdtor_ChessKing(void) __asm__("??_GChessKing@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00422e30,??3Base@@SAXPAXK@Z,156,")))
void sdtor_ChessKing(void) {}

void sdtor_GSquadInfo(void) __asm__("??_GGSquadInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,40,")))
void sdtor_GSquadInfo(void) {}

void sdtor_GRankInfo(void) __asm__("??_GGRankInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,28,")))
void sdtor_GRankInfo(void) {}

void sdtor_Rank(void) __asm__("??_GRank@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,32,??_7Rank@@6B@")))
void sdtor_Rank(void) {}

void sdtor_ReactionInfo(void) __asm__("??_GReactionInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,100,")))
void sdtor_ReactionInfo(void) {}

void sdtor_GRewardInfo(void) __asm__("??_GGRewardInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,304,")))
void sdtor_GRewardInfo(void) {}

void sdtor_GRewardProgress(void) __asm__("??_GGRewardProgress@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,44,")))
void sdtor_GRewardProgress(void) {}

void sdtor_Reward(void) __asm__("??_GReward@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x006e56c0,??3Base@@SAXPAXK@Z,168,")))
void sdtor_Reward(void) {}

void sdtor_GScaffoldInfo(void) __asm__("??_GGScaffoldInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,296,")))
void sdtor_GScaffoldInfo(void) {}

void sdtor_GScript(void) __asm__("??_GGScript@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x006eb840,??3Base@@SAXPAXK@Z,188,")))
void sdtor_GScript(void) {}

void sdtor_GScriptOpposingCreature(void) __asm__("??_GGScriptOpposingCreature@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,28,")))
void sdtor_GScriptOpposingCreature(void) {}

void sdtor_GScriptHighlightInfo(void) __asm__("??_GGScriptHighlightInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,272,")))
void sdtor_GScriptHighlightInfo(void) {}

void sdtor_ScriptHighlight(void) __asm__("??_GScriptHighlight@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00709940,??3Base@@SAXPAXK@Z,140,")))
void sdtor_ScriptHighlight(void) {}

void sdtor_SecretCreature(void) __asm__("??_GSecretCreature@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00711d80,??3@YAXPAX@Z,0,")))
void sdtor_SecretCreature(void) {}

void sdtor_GShowNeedsInfo(void) __asm__("??_GGShowNeedsInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,276,")))
void sdtor_GShowNeedsInfo(void) {}

void sdtor_GConfirmation(void) __asm__("??_GGConfirmation@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0071a500,??3Base@@SAXPAXK@Z,36,")))
void sdtor_GConfirmation(void) {}

void sdtor_GHelpSpritesGuidance(void) __asm__("??_GGHelpSpritesGuidance@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,152,")))
void sdtor_GHelpSpritesGuidance(void) {}

void sdtor_GGuidance(void) __asm__("??_GGGuidance@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0071ab60,??3Base@@SAXPAXK@Z,236,")))
void sdtor_GGuidance(void) {}

void sdtor_GSoundInfo(void) __asm__("??_GGSoundInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,76,")))
void sdtor_GSoundInfo(void) {}

void sdtor_Spell(void) __asm__("??_GSpell@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,236,")))
void sdtor_Spell(void) {}

void sdtor_SpellCreature(void) __asm__("??_GSpellCreature@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,244,")))
void sdtor_SpellCreature(void) {}

void sdtor_SpellDispenser(void) __asm__("??_GSpellDispenser@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("??1Abode@@UAE@XZ,??3Base@@SAXPAXK@Z,220,")))
void sdtor_SpellDispenser(void) {}

void sdtor_GSpellIconInfo(void) __asm__("??_GGSpellIconInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,300,")))
void sdtor_GSpellIconInfo(void) {}

void sdtor_SpellSeed(void) __asm__("??_GSpellSeed@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00636640,??3Base@@SAXPAXK@Z,160,")))
void sdtor_SpellSeed(void) {}

void sdtor_GSpellSystemInfo(void) __asm__("??_GGSpellSystemInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,76,")))
void sdtor_GSpellSystemInfo(void) {}

void sdtor_GSpellSeedInfo(void) __asm__("??_GGSpellSeedInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,400,")))
void sdtor_GSpellSeedInfo(void) {}

void sdtor_SpellShield(void) __asm__("??_GSpellShield@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,268,")))
void sdtor_SpellShield(void) {}

void sdtor_GMapShieldInfo(void) __asm__("??_GGMapShieldInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,264,")))
void sdtor_GMapShieldInfo(void) {}

void sdtor_MapShield(void) __asm__("??_GMapShield@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0052eac0,??3Base@@SAXPAXK@Z,104,")))
void sdtor_MapShield(void) {}

void sdtor_MagicShield(void) __asm__("??_GMagicShield@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0052eac0,??3Base@@SAXPAXK@Z,104,")))
void sdtor_MagicShield(void) {}

void sdtor_PhysicalShield(void) __asm__("??_GPhysicalShield@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0052eac0,??3Base@@SAXPAXK@Z,256,")))
void sdtor_PhysicalShield(void) {}

void sdtor_SpellStormAndTornado(void) __asm__("??_GSpellStormAndTornado@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,248,")))
void sdtor_SpellStormAndTornado(void) {}

void sdtor_GSpookyVoiceInfo(void) __asm__("??_GGSpookyVoiceInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,52,")))
void sdtor_GSpookyVoiceInfo(void) {}

void sdtor_GSpookyVoices(void) __asm__("??_GGSpookyVoices@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0072e270,??3Base@@SAXPAXK@Z,28,")))
void sdtor_GSpookyVoices(void) {}

void sdtor_FireEffect(void) __asm__("??_GFireEffect@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0072ebd0,??3Base@@SAXPAXK@Z,80,")))
void sdtor_FireEffect(void) {}

void sdtor_GTerrainMaterialInfo(void) __asm__("??_GGTerrainMaterialInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,112,")))
void sdtor_GTerrainMaterialInfo(void) {}

void sdtor_GTotemStatueInfo(void) __asm__("??_GGTotemStatueInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,292,")))
void sdtor_GTotemStatueInfo(void) {}

void sdtor_GTownInfo(void) __asm__("??_GGTownInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,396,")))
void sdtor_GTownInfo(void) {}

void sdtor_GBelief(void) __asm__("??_GGBelief@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,464,")))
void sdtor_GBelief(void) {}

void sdtor_TownCreatureInfo(void) __asm__("??_GTownCreatureInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,32,")))
void sdtor_TownCreatureInfo(void) {}

void sdtor_GTownDesireInfo(void) __asm__("??_GGTownDesireInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,144,")))
void sdtor_GTownDesireInfo(void) {}

void sdtor_TownDesire(void) __asm__("??_GTownDesire@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00745760,??3Base@@SAXPAXK@Z,1380,")))
void sdtor_TownDesire(void) {}

void sdtor_GTreeInfo(void) __asm__("??_GGTreeInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,320,")))
void sdtor_GTreeInfo(void) {}

void sdtor_GTribeInfo(void) __asm__("??_GGTribeInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,28,")))
void sdtor_GTribeInfo(void) {}

void sdtor_GVirtualInfluence(void) __asm__("??_GGVirtualInfluence@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0076cd30,??3Base@@SAXPAXK@Z,96,")))
void sdtor_GVirtualInfluence(void) {}

void sdtor_Fragment(void) __asm__("??_GFragment@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00608750,??3Base@@SAXPAXK@Z,168,")))
void sdtor_Fragment(void) {}

void sdtor_VortexSave(void) __asm__("??_GVortexSave@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0076f9c0,??3Base@@SAXPAXK@Z,36,")))
void sdtor_VortexSave(void) {}

void sdtor_WayPoint(void) __asm__("??_GWayPoint@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x00770bb0,??3Base@@SAXPAXK@Z,44,")))
void sdtor_WayPoint(void) {}

void sdtor_GWeatherInfo(void) __asm__("??_GGWeatherInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,100,")))
void sdtor_GWeatherInfo(void) {}

void sdtor_GWeather(void) __asm__("??_GGWeather@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0083f630,??3@YAXPAX@Z,0,")))
void sdtor_GWeather(void) {}

void sdtor_GClimateInfo(void) __asm__("??_GGClimateInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,160,")))
void sdtor_GClimateInfo(void) {}

void sdtor_GClimateRainInfo(void) __asm__("??_GGClimateRainInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,164,")))
void sdtor_GClimateRainInfo(void) {}

void sdtor_Workshop(void) __asm__("??_GWorkshop@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x007793b0,??3Base@@SAXPAXK@Z,232,")))
void sdtor_Workshop(void) {}

void sdtor_GWorshipSiteInfo(void) __asm__("??_GGWorshipSiteInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,352,")))
void sdtor_GWorshipSiteInfo(void) {}

void sdtor_PlannedWorshipSite(void) __asm__("??_GPlannedWorshipSite@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,80,")))
void sdtor_PlannedWorshipSite(void) {}

void sdtor_GWorshipSiteUpgradeInfo(void) __asm__("??_GGWorshipSiteUpgradeInfo@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x00436960,??3Base@@SAXPAXK@Z,296,")))
void sdtor_GWorshipSiteUpgradeInfo(void) {}

void sdtor_PlannedWorshipSiteUpgrade(void) __asm__("??_GPlannedWorshipSiteUpgrade@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x0056fa80,??3Base@@SAXPAXK@Z,76,")))
void sdtor_PlannedWorshipSiteUpgrade(void) {}

void sdtor_WorshipSpellIcon(void) __asm__("??_GWorshipSpellIcon@@UAEPAXI@Z");
__attribute__((msvc6_sdtor(".Lbl_addr_0x0077f1e0,??3Base@@SAXPAXK@Z,320,")))
void sdtor_WorshipSpellIcon(void) {}

void sdtor_InnerCamera(void) __asm__("??_GInnerCamera@@UAEPAXI@Z");
__attribute__((msvc6_sdtor("_jmp_addr_0x007974c0,??3@YAXPAX@Z,0,")))
void sdtor_InnerCamera(void) {}

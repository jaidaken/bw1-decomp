#include "SetupHSBarGraph.h"
#include "StatsBox.h"

// win1.41 0056d960 mac 100cd050 SetupHSBarGraph::~SetupHSBarGraph(void)
SetupHSBarGraph::~SetupHSBarGraph()
{
}

// win1.41 0056d980 mac 1031d840 StatsBox::Destroy(void)
void StatsBox::Destroy()
{
}

// win1.41 0056d990 mac 1031d780 StatsBox::InitControls(void)
void StatsBox::InitControls()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void sdtor_dt_0();
extern "C" void sdtor_opd_0();

__declspec(naked) void __cdecl sdtor_SetupHSBarGraph() {
    __asm {
        push esi
        mov esi, ecx
        call sdtor_dt_0
        test byte ptr [esp + 8], 1
        je short skip_SetupHSBarGraph
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_SetupHSBarGraph:
        mov eax, esi
        pop esi
        ret 4
    }
}

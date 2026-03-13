#include "MPFEPublicChatMessage.h"
#include "MPFEPrivateChatMessage.h"
#include "MPFEAskJoinMessage.h"
#include "MPFEReplyToJoinMessage.h"
#include "MPFEInviteToTeamMessage.h"
#include "MPFEReplyToInviteMessage.h"
#include "MPFECancelStartMessage.h"
#include "MPFEKickMessageRequest.h"
#include "MPFEKickMessage.h"
#include "MPFEDatabaseID.h"
#include "MPFEReadyMessage.h"
#include "MPFETeamsReadyList.h"
#include "MPFEHasCreature.h"
#include "MPFEChannelSelector.h"

// win1.41 00626e00 mac 10398090 MPFEPublicChatMessage::_dt(void)
MPFEPublicChatMessage::~MPFEPublicChatMessage()
{
}

// win1.41 00626ed0 mac 10398140 MPFEPrivateChatMessage::_dt(void)
MPFEPrivateChatMessage::~MPFEPrivateChatMessage()
{
}

// win1.41 00626f90 mac 10397e50 MPFEAskJoinMessage::_dt(void)
MPFEAskJoinMessage::~MPFEAskJoinMessage()
{
}

// win1.41 006270a0 mac 10394150 MPFEReplyToJoinMessage::_dt(void)
MPFEReplyToJoinMessage::~MPFEReplyToJoinMessage()
{
}

// win1.41 00627410 mac 103977c0 MPFEInviteToTeamMessage::_dt(void)
MPFEInviteToTeamMessage::~MPFEInviteToTeamMessage()
{
}

// win1.41 006274f0 mac 10397500 MPFEReplyToInviteMessage::_dt(void)
MPFEReplyToInviteMessage::~MPFEReplyToInviteMessage()
{
}

// win1.41 00627640 mac 1039ba50 MPFECancelStartMessage::_dt(void)
MPFECancelStartMessage::~MPFECancelStartMessage()
{
}

// win1.41 00627790 mac 10397a60 MPFEKickMessageRequest::_dt(void)
MPFEKickMessageRequest::~MPFEKickMessageRequest()
{
}

// win1.41 00627980 mac 1039a1a0 MPFEKickMessage::_dt(void)
MPFEKickMessage::~MPFEKickMessage()
{
}

// win1.41 00627b00 mac 1039bb00 MPFEDatabaseID::_dt(void)
MPFEDatabaseID::~MPFEDatabaseID()
{
}

// win1.41 00627d80 mac inlined MPFEReadyMessage::_dt(void)
MPFEReadyMessage::~MPFEReadyMessage()
{
}

// win1.41 00627ee0 mac inlined MPFETeamsReadyList::_dt(void)
MPFETeamsReadyList::~MPFETeamsReadyList()
{
}

// win1.41 00628010 mac inlined MPFEHasCreature::_dt(void)
MPFEHasCreature::~MPFEHasCreature()
{
}

// win1.41 00628330 mac 1039f0c0 MPFEChannelSelector::MPFEChannelSelector(void)
MPFEChannelSelector::MPFEChannelSelector()
{
}

// win1.41 00628430 mac 1039e800 MPFEChannelSelector::Show(void)
void MPFEChannelSelector::Show()
{
}

// win1.41 00628450 mac 1039e270 MPFEChannelSelector::Init(unsigned long, unsigned long, void (*)(int, SetupBox *, SetupControl *, int, int))
void MPFEChannelSelector::Init(unsigned long param_1, unsigned long param_2, DialogBoxInitCallback param_3)
{
}

// win1.41 00628e20 mac 1039e230 MPFEChannelSelector::Destroy(void)
void MPFEChannelSelector::Destroy()
{
}

// win1.41 00628e30 mac 1039df20 MPFEChannelSelector::InitControls(void)
void MPFEChannelSelector::InitControls()
{
}

// ============================================================
// Scalar deleting destructor replacements (auto-generated)
// ============================================================

extern "C" void sdtor_dt_34();
extern "C" char sdtor_vt_7;
extern "C" void sdtor_opd_0();

__declspec(naked) void __cdecl sdtor_MPFEPublicChatMessage() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFEPublicChatMessage
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFEPublicChatMessage:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFEPrivateChatMessage() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFEPrivateChatMessage
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFEPrivateChatMessage:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFEAskJoinMessage() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFEAskJoinMessage
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFEAskJoinMessage:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFEReplyToJoinMessage() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFEReplyToJoinMessage
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFEReplyToJoinMessage:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFEInviteToTeamMessage() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFEInviteToTeamMessage
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFEInviteToTeamMessage:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFEReplyToInviteMessage() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFEReplyToInviteMessage
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFEReplyToInviteMessage:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFECancelStartMessage() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFECancelStartMessage
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFECancelStartMessage:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFEKickMessageRequest() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFEKickMessageRequest
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFEKickMessageRequest:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFEKickMessage() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFEKickMessage
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFEKickMessage:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFEDatabaseID() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFEDatabaseID
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFEDatabaseID:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFEReadyMessage() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFEReadyMessage
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFEReadyMessage:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFETeamsReadyList() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFETeamsReadyList
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFETeamsReadyList:
        mov eax, esi
        pop esi
        ret 4
    }
}

__declspec(naked) void __cdecl sdtor_MPFEHasCreature() {
    __asm {
        push esi
        mov esi, ecx
        mov dword ptr [esi], offset sdtor_vt_7
        call sdtor_dt_34
        test byte ptr [esp + 8], 1
        je short skip_MPFEHasCreature
        push esi
        call sdtor_opd_0
        add esp, 4
    skip_MPFEHasCreature:
        mov eax, esi
        pop esi
        ret 4
    }
}

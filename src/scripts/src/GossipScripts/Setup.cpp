/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include "Setup.h"
#define SKIP_ALLOCATOR_SHARING 1
#include <ScriptSetup.h>

extern "C" SCRIPT_DECL uint32 _exp_get_script_type()
{
	return SCRIPT_TYPE_MISC;
}

extern "C" SCRIPT_DECL void _exp_script_register(ScriptMgr* mgr)
{
    SetupInnkeepers(mgr);
    SetupGuardGossip(mgr);
	SetupTrainerScript(mgr);
	SetupMulgoreGossip(mgr);
	SetupShattrathGossip(mgr);
	SetupTanarisGossip(mgr);
	SetupMoongladeGossip(mgr);
	SetupStormwindGossip(mgr);
	SetupBoreanTundraGossip(mgr);
	SetupWyrmrestTempleGossip(mgr);
}

#ifdef WIN32

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    return TRUE;
}

#endif

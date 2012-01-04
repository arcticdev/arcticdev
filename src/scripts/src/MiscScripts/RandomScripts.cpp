/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include "Setup.h"

void GuardsOnSalute(Player* pPlayer, Unit* pUnit)
{
	if ( pPlayer == NULL || pUnit == NULL )
		return;

	// Check if we are friendly with our Guards (they will salute only when You are)
	if(((pUnit->GetEntry() == 68 || pUnit->GetEntry() == 1976) && pPlayer->GetStandingRank(72) >= FRIENDLY) || ( pUnit->GetEntry() == 3296 && pPlayer->GetStandingRank(76) >= FRIENDLY))
	{
		uint32 EmoteChance = RandomUInt(100);
		if(EmoteChance < 33) // 1/3 chance to get Salute from Guard
			pUnit->Emote(EMOTE_ONESHOT_SALUTE);
	}
}

void GaurdsOnKiss(Player* pPlayer, Unit* pUnit)
{
	if ( pPlayer == NULL || pUnit == NULL )
		return;

	// Check if we are friendly with our Guards (they will bow only when You are)
	if (((pUnit->GetEntry() == 68 || pUnit->GetEntry() == 1976) && pPlayer->GetStandingRank(72) >= FRIENDLY) || (pUnit->GetEntry() == 3296 && pPlayer->GetStandingRank(76) >= FRIENDLY))
	{
		uint32 EmoteChance = RandomUInt(100);
		if(EmoteChance < 33) // 1/3 chance to get Bow from Guard
			pUnit->Emote(EMOTE_ONESHOT_BOW);
	}
}

void GuardsOnWave(Player* pPlayer, Unit* pUnit)
{
	if ( pPlayer == NULL || pUnit == NULL )
		return;

	// Check if we are friendly with our Guards (they will wave only when You are)
	if (((pUnit->GetEntry() == 68 || pUnit->GetEntry() == 1976) && pPlayer->GetStandingRank(72) >= FRIENDLY) || (pUnit->GetEntry() == 3296 && pPlayer->GetStandingRank(76) >= FRIENDLY))
	{
		uint32 EmoteChance = RandomUInt(100);
		if(EmoteChance < 33) // 1/3 chance to get Bow from Guard
			pUnit->Emote(EMOTE_ONESHOT_WAVE);
	}
}

void OnEmote(Player* pPlayer, uint32 Emote, Unit* pUnit)
{
	pUnit = pPlayer->GetMapMgr()->GetUnit(pPlayer->GetSelection());
	if (!pUnit || !pUnit->isAlive() || pUnit->GetAIInterface()->GetNextTarget())
		return;

	// Switch For Emote Name (You do EmoteName to Script Name link).
	switch(Emote)
	{
	case EMOTE_ONESHOT_SALUTE: // <- Its EMOTE name.
		GuardsOnSalute(pPlayer, pUnit); // <- Its Link.
		break;

	case EMOTE_ONESHOT_KISS:
		GaurdsOnKiss(pPlayer, pUnit);
		break;
	
	case EMOTE_ONESHOT_WAVE:
		GuardsOnWave(pPlayer, pUnit);
		break;
	}
}

void SetupRandomScripts(ScriptMgr * mgr)
{	// Register Hook Event here
	mgr->register_hook(SERVER_HOOK_EVENT_ON_EMOTE, (void *)&OnEmote);
}
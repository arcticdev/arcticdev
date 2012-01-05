/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include "Setup.h"
#include "../Common/EasyFunctions.h"
#include "../Common/Base.h"

bool PoweringOurDefenses(uint32 i, Spell* pSpell)
{
	if(!pSpell->u_caster->IsPlayer())
    return true;

	Player* plr = TO_PLAYER(pSpell->u_caster);
	if( !plr )
		return true;

	QuestLogEntry *qle = plr->GetQuestLogForEntry( 8490 );
	if( !qle )
		return true;

	// Angelis : Need to script the scourge attack

	if( qle && qle->GetMobCount(0) < qle->GetQuest()->required_mobcount[0] )
	{
		qle->SetMobCount(0, qle->GetMobCount(0)+1);
		qle->SendUpdateAddKill(0);
		qle->UpdatePlayerFields();
	}
	return true;
}

void SetupEversongWoods(ScriptMgr * mgr)
{
	mgr->register_dummy_spell(28247, &PoweringOurDefenses);
}

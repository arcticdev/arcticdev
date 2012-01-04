/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include "Setup.h"
#include "../Common/EasyFunctions.h"
#include "../Common/Base.h"

// -----------------------------------------------------------------------------
// Quest 12532 - Flown the Coop!
// Quest 12702 - Chicken Party! (by bartus

bool ChickenNet( uint32 i, Spell* pSpell )
{
	if( !pSpell->u_caster->IsPlayer() )
        return true;

	Player* pPlayer = TO_PLAYER( pSpell->u_caster );

	QuestLogEntry *qle = pPlayer->GetQuestLogForEntry( 12532 );
	if( qle == NULL )
	{
		QuestLogEntry *qle = pPlayer->GetQuestLogForEntry( 12702 );
		if( qle == NULL )
			return true;
	}

	
	if( !pSpell->GetUnitTarget()->IsCreature() )
		return true;

	Creature* Chicken = TO_CREATURE( pSpell->GetUnitTarget() );

	if( Chicken != NULL && Chicken->GetEntry() == 28161 )
	{
		Chicken->Despawn( 5000, 360000 );
		pPlayer->CastSpell( pSpell->u_caster, dbcSpell.LookupEntry( 51037 ), true );
	}

   return true;
}


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void SetupSholazarBasin( ScriptMgr * mgr )
{
   mgr->register_dummy_spell(51959, &ChickenNet);
}
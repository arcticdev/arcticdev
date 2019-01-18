/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include "Setup.h"
#include "../Common/EasyFunctions.h"

class ThePathoftheAdept : public GameObjectAIScript
{
public:
	ThePathoftheAdept(GameObject* goinstance) : GameObjectAIScript(goinstance) {}
	static GameObjectAIScript *Create(GameObject* GO) { return new ThePathoftheAdept(GO); }

	void OnActivate(Player* pPlayer)
	{
		if(!pPlayer)
			return;

		QuestLogEntry *qle = pPlayer->GetQuestLogForEntry(9692);
		if(qle == NULL)
			return;

		Creature* zelemar = sEAS.SpawnCreature(pPlayer, 17830, pPlayer->GetPositionX()+5, pPlayer->GetPositionY()+5, pPlayer->GetPositionZ(), pPlayer->GetOrientation(), 0);
		zelemar->Despawn(6*60*1000, 0);
	}
};


class PathoftheAdept : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* plr, bool AutoSend)
	{
		if(!plr)
			return;

		GossipMenu *Menu;
		Creature* lord = TO_CREATURE(pObject);
		if (lord == NULL)
			return;

			objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
			if(plr->GetQuestLogForEntry(9692))
			Menu->AddItem( 0, "Take Insignia", 1);

		if(AutoSend)
			Menu->SendTo(plr);
	}

	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(!plr)
			return;

		Creature* lord = TO_CREATURE(pObject);
		if (lord == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;

			case 1:
			{
				sEAS.AddItem(24226, plr);
				return;
			}break;
		}
	}

	void Destroy()
	{
		delete this;
	}
};


class LordDawnstar : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(LordDawnstar);
	LordDawnstar(Creature* pCreature) : CreatureAIScript(pCreature) {}

	void OnLoad()
	{
		_unit->SetUInt32Value(UNIT_NPC_FLAGS, 1);
		_unit->SetStandState(7);
		_unit->setDeathState(CORPSE);
		_unit->GetAIInterface()->m_canMove = false;
	}
};


void SetupSilvermoonCity(ScriptMgr * mgr)
{
	GossipScript *LordGossip = (GossipScript*) new PathoftheAdept();
	mgr->register_gameobject_script(182024, &ThePathoftheAdept::Create);
	mgr->register_gossip_script(17832, LordGossip);
	mgr->register_creature_script(17832, &LordDawnstar::Create);
}

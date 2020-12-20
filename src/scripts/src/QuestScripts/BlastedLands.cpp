/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include "Setup.h"
#include "../Common/EasyFunctions.h"

#define SendQuickMenu(textid) objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), textid, plr); \
	Menu->SendTo(plr);

class HeroesofOld : public QuestScript
{	
public:
  void OnQuestStart(Player* mTarget, QuestLogEntry * qLogEntry)
  {
	  if( mTarget == NULL || mTarget->GetMapMgr() == NULL || mTarget->GetMapMgr()->GetInterface() == NULL )
		  return;

	Creature* spawncheckcr = mTarget->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(mTarget->GetPositionX(), mTarget->GetPositionY(), mTarget->GetPositionZ(), 7750);

	if(!spawncheckcr)
	{
		Creature* general = sEAS.SpawnCreature(mTarget, 7750, -10619, -2997, 28.8, 4, 0);
		general->Despawn(3*60*1000, 0);
	}

	GameObject* spawncheckgobj = mTarget->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(mTarget->GetPositionX(), mTarget->GetPositionY(),mTarget->GetPositionZ(), 141980);

	if(!spawncheckgobj)
	{
		GameObject* generalsbox = sEAS.SpawnGameobject(mTarget, 141980, -10622, -2994, 28.6, 4, 4, 0, 0, 0, 0);
		sEAS.GameobjectDelete(generalsbox, 3*60*1000);
	}
  }
};



class HeroesofOld1 : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player* plr, bool AutoSend)
	{
		if(!plr)
			return;

		GossipMenu *Menu;
		Creature* general = TO_CREATURE(pObject);
		if (general == NULL)
			return;

		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 1, plr);
		if(plr->GetQuestLogForEntry(2702) || plr->HasFinishedQuest(2702))
			Menu->AddItem( 0, "I need to speak with Corporal.", 1);
	 
		if(AutoSend)
			Menu->SendTo(plr);
	}
 
	void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * EnteredCode)
	{
		if(!plr)
			return;

		Creature* general = TO_CREATURE(pObject);
		if (general == NULL)
			return;

		switch (IntId)
		{
			case 0:
				GossipHello(pObject, plr, true);
				break;
 
			case 1:
			{
				Creature* spawncheckcr = plr->GetMapMgr()->GetInterface()->GetCreatureNearestCoords(plr->GetPositionX(), plr->GetPositionY(), plr->GetPositionZ(), 7750);

				if(!spawncheckcr)
				{
					Creature* general = sEAS.SpawnCreature(plr, 7750, -10619, -2997, 28.8, 4, 0);
					general->Despawn(3*60*1000, 0);
				}

				GameObject* spawncheckgobj = plr->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(plr->GetPositionX(), plr->GetPositionY(), plr->GetPositionZ(), 141980);

				if(!spawncheckgobj)
				{
					GameObject* generalsbox = sEAS.SpawnGameobject(plr, 141980, -10622, -2994, 28.6, 4, 4, 0, 0, 0, 0);
					sEAS.GameobjectDelete(generalsbox, 3*60*1000);
				}
			}
		}
	}
 
	void Destroy()
	{
		delete this;
	}
};

void SetupBlastedLands(ScriptMgr * mgr)
{
	QuestScript *HeroesoO = (QuestScript*) new HeroesofOld();
	mgr->register_quest_script(2702, HeroesoO);

	GossipScript * gossip1 = (GossipScript*) new HeroesofOld1();
	mgr->register_gossip_script(7572, gossip1);
}

/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include "Setup.h"

class PortalEffectSunwellIsle : public GameObjectAIScript
  {
  public:
          PortalEffectSunwellIsle(GameObject* goinstance) : GameObjectAIScript(goinstance) {}
          void OnActivate(Player* pPlayer)
          {
                if(pPlayer->getLevel() >= 70) 
                {
                  //pPlayer->SafeTeleport(530, 4080, 12803.374023f, -6907.089844f, 41.114765f, 2.251736f);
					pPlayer->CastSpell(pPlayer, dbcSpell.LookupEntry(44870), true);
                }
                else if(pPlayer->getLevel() <= 69)
                {
					pPlayer->BroadcastMessage("You must be level 70 to use this!");
                }
          }
          static GameObjectAIScript *Create(GameObject* GO) { return new PortalEffectSunwellIsle(GO); }
  };
GameObjectAIScript * create_go(GameObject* GO) { return new PortalEffectSunwellIsle(GO); }
void SetupQDGoHandlers(ScriptMgr * mgr)
{

      mgr->register_gameobject_script(187056, &PortalEffectSunwellIsle::Create);
   
}

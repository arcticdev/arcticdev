/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include "Setup.h"

// Erelas Ambersky
#define GOSSIP_ERELAS_AMBERSKY    "Tell me more about these hippogryphs."

class ErelasAmbersky_Gossip : public GossipScript
{
public:
    void GossipHello(Object* pObject, Player* plr, bool AutoSend)
    {
        GossipMenu *Menu;
		objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2153, plr);
			
			Menu->AddItem( 0, GOSSIP_ERELAS_AMBERSKY, 1);

        if(AutoSend)
            Menu->SendTo(plr);
    }

    void GossipSelectOption(Object* pObject, Player* plr, uint32 Id, uint32 IntId, const char * Code)
    {
		if(pObject->GetTypeId()!=TYPEID_UNIT)
			return;

		GossipMenu * Menu;
        switch(IntId)
        {
        case 1:
			{
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 2154, plr);
				Menu->SendTo(plr);
            }break;
		}
    }

    void Destroy()
    {
        delete this;
    }
};

void SetupTeldrassilGossip(ScriptMgr * mgr)
{
	GossipScript * ErelasAmberskyGossip = (GossipScript*) new ErelasAmbersky_Gossip;
	
	mgr->register_gossip_script(7916, ErelasAmberskyGossip); // Erelas Ambersky
}

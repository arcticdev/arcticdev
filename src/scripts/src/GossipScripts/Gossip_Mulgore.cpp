/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include "Setup.h"

// Skorn Whitecloud
#define GOSSIP_SKORN_WHITECLOUD    "Tell me a story, Skorn."

class SkornWhitecloud_Gossip : public GossipScript
{
public:
    void GossipHello(Object* pObject, Player* plr, bool AutoSend)
    {
        GossipMenu *Menu;
        objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 522, plr);
        Menu->AddItem( 0, GOSSIP_SKORN_WHITECLOUD, 1);
        
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
				objmgr.CreateGossipMenuForPlayer(&Menu, pObject->GetGUID(), 523, plr);
				Menu->SendTo(plr);
            }break;
		}
    }

    void Destroy()
    {
        delete this;
    }
};

void SetupMulgoreGossip(ScriptMgr * mgr)
{
	GossipScript * SkornWhitecloudGossip = (GossipScript*) new SkornWhitecloud_Gossip;
	mgr->register_gossip_script(3052, SkornWhitecloudGossip); // Skorn Whitecloud

}

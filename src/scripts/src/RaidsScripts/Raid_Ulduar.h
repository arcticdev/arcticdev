/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include "Setup.h"
#include "../Common/Base.h"

// Ulduar Teleporter
class SCRIPT_DECL UlduarTeleporter : public GossipScript
{
public:
	void GossipHello(Object* pObject, Player*  Plr, bool AutoSend);
	void GossipSelectOption(Object* pObject, Player* Plr, uint32 Id, uint32 IntId, const char * Code);

	void GossipEnd(Object*  pObject, Player* Plr)
	{
		GossipScript::GossipEnd(pObject, Plr);
	};
	void Destroy()
	{
		delete this;
	};
};

void SetupUlduar(ScriptMgr* mgr);

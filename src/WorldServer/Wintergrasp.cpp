/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

Wintergrasp::Wintergrasp(WintergraspInternal* WGI, MapMgr* mgr) : Internal(*WGI)
{
	for(int i = 0; i < 3; ++i)
		playercount[i] = 0;

	Player* plr = NULL;
	WGID = Internal.WGCounter;

	for(PlayerStorageMap::iterator itr =  mgr->m_PlayerStorage.begin(); itr != mgr->m_PlayerStorage.end(); ++itr)
	{
		plr = itr->second;
		if((plr->GetAreaID() == WINTERGRASP) || (plr->GetZoneId() == WINTERGRASP))
		{
			WGPlayers.insert(plr);
			plr->WinterGrasp = this;
			++playercount[2]; // Total
			++playercount[plr->GetTeam()];
		}
	}
	if(WGPlayers.size() != playercount[2])
		printf("Player disfunction occured!\n");

	Init();
}

Wintergrasp::~Wintergrasp()
{
	Internal.m_wintergrasp = 2; // We are ending Wintergrasp.
	// Handle deletion and removal.
	Internal.EndWintergrasp();
}

void Wintergrasp::Init()
{
	Internal.StartWintergrasp();
	Internal.SendInitWorldStates();
	Internal.UpdateClock();
}

void Wintergrasp::End()
{
}

void Wintergrasp::OnAddPlayer(Player* plr)
{
	printf("Pie flavor'd bastard!\n");
	++playercount[2];
	++playercount[plr->GetTeam()];
	WGPlayers.insert(plr);
	plr->WinterGrasp = this;
	Internal.SendInitWorldStates(plr);
}

void Wintergrasp::OnRemovePlayer(Player* plr)
{
	printf("Pie flavor'd bastard left!\n");
	--playercount[2];
	--playercount[plr->GetTeam()];
	WGPlayers.erase(plr);
	plr->WinterGrasp = NULL;
}

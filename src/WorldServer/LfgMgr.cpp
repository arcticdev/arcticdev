/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#include "StdAfx.h"

uint32 LfgDungeonTypes[MAX_DUNGEONS];
initialiseSingleton( LfgMgr );

LfgMgr::LfgMgr()
{
	DBCFile f;
	if(f.open("DBC/LFGDungeons.dbc"))
	{
		for(uint32 i = 0; i < f.getRecordCount(); ++i)
		{
			DBCFile::Record r = f.getRecord(i);
			uint32 id = r.getUInt(0);
			uint32 typ = r.getUInt(20);

			if(id >= MAX_DUNGEONS)
				printf("!! WARNING !! LFGDungeons contains an out of range dungeon id %u.\n", id);
			else
				LfgDungeonTypes[id] = typ;
		}
	}
	else
		printf("!! WARNING !! LFGDungeons.dbc not found, LFG tool will not function correctly.\n");
}

LfgMgr::~LfgMgr()
{
}

bool LfgMgr::AttemptLfgJoin(Player* pl, uint32 LfgDungeonId)
{
	if( pl == NULL )
		return false;

	if( !pl->IsInWorld() )
		return false;
	return false;
}

void LfgMgr::SetPlayerInLFGqueue(Player* pl,uint32 LfgDungeonId)
{
	if( pl == NULL )
		return;

	if( LfgDungeonId >= MAX_DUNGEONS )
		return;

	m_lock.Acquire();

	// there are either no groups free or we don't have autojoin enabled, put us in the queue.
	m_lookingForGroup[LfgDungeonId].push_back(pl);

	// release the lock
	m_lock.Release();
}

void LfgMgr::RemovePlayerFromLfgQueues(Player* pl)
{
	if( pl == NULL )
		return;

	m_lock.Acquire();
	for(uint32 i = 0; i < MAX_LFG_QUEUE_ID; ++i)
	{
		if(pl->LfgDungeonId[i] != 0)
		{
			if( pl->LfgDungeonId[i] < MAX_DUNGEONS )
				m_lookingForGroup[pl->LfgDungeonId[i]].remove(pl);

			if(pl->m_Autojoin)
				pl->SendMeetingStoneQueue(pl->LfgDungeonId[i], 0);

			pl->LfgDungeonId[i] = 0;
			pl->LfgType[i] = 0;
		}
	}

	if(pl->LfmDungeonId)
	{
		if( pl->LfmDungeonId < MAX_DUNGEONS )
			m_lookingForMore[pl->LfmDungeonId].remove(pl);

		pl->LfmDungeonId = 0;
		pl->LfmType = 0;
	}

	m_lock.Release();
}

void LfgMgr::RemovePlayerFromLfgQueue( Player* plr, uint32 LfgDungeonId )
{
	if( plr == NULL )
		return;

	if( LfgDungeonId >= MAX_DUNGEONS )
		return;

	m_lock.Acquire();
	m_lookingForGroup[LfgDungeonId].remove( plr );
	m_lock.Release();

	if( plr->m_Autojoin )
		plr->SendMeetingStoneQueue( LfgDungeonId, 0 );
}

void LfgMgr::UpdateLfgQueue(uint32 LfgDungeonId)
{
	if( LfgDungeonId > MAX_DUNGEONS )
		return;

	LfgPlayerList possibleGroupLeaders;
	LfgPlayerList possibleMembers;
	LfgPlayerList::iterator itr;
	LfgPlayerList::iterator it2;
	LfgPlayerList::iterator it3;
	Player* plr;
	uint32 i;
	//LfgMatch * pMatch;

	// only update on autojoinable dungeons
	if(LfgDungeonTypes[LfgDungeonId] != LFG_DUNGEON && LfgDungeonTypes[LfgDungeonId] != LFG_HEROIC_DUNGEON)
		return;

	m_lock.Acquire();
	for(itr = m_lookingForGroup[LfgDungeonId].begin(); itr != m_lookingForGroup[LfgDungeonId].end(); itr++)
	{
        plr = *itr;

		if(plr->m_lfgInviterGuid || plr->m_lfgMatch != NULL)
			continue;

		// possible member?
		if(plr->m_Autojoin)
			possibleMembers.push_back(plr);
	}

	for(itr = m_lookingForMore[LfgDungeonId].begin(); itr != m_lookingForMore[LfgDungeonId].end(); itr++)
	{
		if(plr->GetGroup())
		{
			// check if this is a suitable candidate for a group for others to join
			if(plr->m_AutoAddMem && plr->IsGroupLeader() && !plr->GetGroup()->IsFull() && plr->GetGroup()->GetGroupType() == GROUP_TYPE_PARTY)
			{
				possibleGroupLeaders.push_back(plr);
				continue;
			}

			if(plr->m_lfgInviterGuid || plr->m_lfgMatch != NULL)
				continue;

			// just a guy in a group
			continue;
		}
	}

	// look through our members, as well as our groups and see if we can add anyone to any groups
	// if not, if we have enough members, create a new group for them.

	if(possibleMembers.size() > 0)
	{
		for(itr = possibleGroupLeaders.begin(); itr != possibleGroupLeaders.end(); itr++)
		{
			for(it2 = possibleMembers.begin(); it2 != possibleMembers.end();)
			{
				if((*itr)->GetGroup()->IsFull())
				{
					++it2;
					continue;
				}

				// found a group for him, lets insert him.
				if((*itr)->GetGroup()->AddMember((*it2)->m_playerInfo))
				{
					(*it2)->m_lfgInviterGuid = (*itr)->GetLowGUID();

					it3 = it2;
					++it2;

					possibleMembers.erase(it2);
				}
				else
					++it2;
			}
		}
	}

	// do we still have any members left over (enough to form a group)
	while(possibleMembers.size() > 1)
	{
		Group * pGroup = new Group(true);
		for(i = 0; i < 5 && possibleMembers.size() > 0; ++i)
		{
			pGroup->AddMember( possibleMembers.front()->m_playerInfo );
			possibleMembers.front()->SendMeetingStoneQueue( LfgDungeonId, 0 );
			m_lookingForGroup[LfgDungeonId].remove( possibleMembers.front() );
			possibleMembers.pop_front();
		}
	}

	m_lock.Release();
}

void LfgMgr::SendLfgList( Player* plr, uint32 Dungeon )
{
	return; 
}

void LfgMgr::SetPlayerInLfmList(Player* pl, uint32 LfgDungeonId)
{
	if( pl == NULL )
		return;

	if( !pl->IsInWorld() )
		return;

	if( LfgDungeonId >= MAX_DUNGEONS )
		return;

	m_lock.Acquire();
	m_lookingForMore[LfgDungeonId].push_back(pl);
	m_lock.Release();
}

void LfgMgr::RemovePlayerFromLfmList(Player* pl, uint32 LfmDungeonId)
{
	if( pl == NULL )
		return;

	if( !pl->IsInWorld() )
		return;

	if( LfmDungeonId >= MAX_DUNGEONS )
		return;

	m_lock.Acquire();
	m_lookingForMore[LfmDungeonId].remove(pl);
	m_lock.Release();
}

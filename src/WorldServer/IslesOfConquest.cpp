/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

//////////////////////////////////////////////////////////////////////////
// http://www.wowwiki.com/Isle_of_Conquest                              //
//////////////////////////////////////////////////////////////////////////

/*IslesOfConquest::IslesOfConquest()
{
    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_WS_START_TWO_MINUTES;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_WS_START_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_WS_START_HALF_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_WS_HAS_BEGUN;
}
*/
IslesOfConquest::~IslesOfConquest()
{
}

/*void IslesOfConquest::Update(uint32 diff)
{
}
*/
void IslesOfConquest::StartingEventCloseDoors()
{
}

void IslesOfConquest::StartingEventOpenDoors()
{
}

void IslesOfConquest::AddPlayer(Player* plr)
{/*
    BattleGround::AddPlayer(plr);
    BattleGroundICScore* sc = new BattleGroundICScore;

    m_PlayerScores[plr->GetGUID()] = sc;*/
}

void IslesOfConquest::RemovePlayer(Player*, uint64)
{
}

void IslesOfConquest::HandleAreaTrigger(Player*, uint32)
{/*
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;*/
}

void IslesOfConquest::UpdatePlayerScore(Player*, uint32 type, uint32 value)
{/*
    std::map<uint64, BattleGroundScore*>::iterator itr = m_PlayerScores.find(Source->GetGUID());

    if(itr == m_PlayerScores.end())
        return;

    BattleGround::UpdatePlayerScore(Source,type,value);*/
}

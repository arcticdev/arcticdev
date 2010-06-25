/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

set<uint32> m_completedRealmFirstAchievements;

//Конструктор и деструктор для динамических строк в объектах
void *AchievementInterface::operator new(size_t size)
{
	sLog.outDebug("New AchievementInterface dynamic string in object.");
	return malloc(size);
}

void AchievementInterface::operator delete(void* p)
{
	sLog.outDebug("Delete AchievementInterface dynamic string in object.");
	free(p);
}

AchievementInterface::AchievementInterface(PlayerPointer plr)
{
	m_player = plr;
	m_achievementInspectPacket = NULL;
}

AchievementInterface::~AchievementInterface()
{
	m_player = NULLPLR;

	if( m_achivementDataMap.size() > 0 )
	{
		std::map<uint32,AchievementData*>::iterator itr = m_achivementDataMap.begin();
		for(; itr != m_achivementDataMap.end(); ++itr)
		{
			delete itr->second;
		}
	}

	if( m_achievementInspectPacket )
		delete m_achievementInspectPacket;
}

void AchievementInterface::LoadFromDB( QueryResult * pResult )
{
	if( !pResult ) // У нас нет никаких достижений пока. :)
		return;

	do 
	{
		Field * fields = pResult->Fetch();
		uint32 achievementid = fields[1].GetUInt32();
		string criteriaprogress = fields[2].GetString();
		bool completed = (fields[3].GetUInt32() > 0);

		AchievementEntry * ae = dbcAchievement.LookupEntry( achievementid );
		AchievementData * ad = new AchievementData;
		memset(ad, 0, sizeof(AchievementData));

		ad->id = achievementid;
		ad->num_criterias = ae->AssociatedCriteriaCount;
		ad->completed = completed;
		ad->date = fields[3].GetUInt32();
		
		if( ad->completed && string(ae->name).find(REALMFIRSTAAA) != string::npos )
			m_completedRealmFirstAchievements.insert( ae->ID );

		vector<string> Delim = StrSplit( criteriaprogress, "," );
		for( uint32 i = 0; i < 32; ++i)
		{
			if( i >= Delim.size() )
				continue;

			string posValue = Delim[i];
			if( !posValue.size() )
				continue;

			uint32 r = atoi(posValue.c_str());
			ad->counter[i] = r;

			// printf("Loaded achievement: %u, %s\n", ae->ID, ad->completed ? "completed" : "incomplete" );
		}

		m_achivementDataMap.insert( make_pair( achievementid, ad) );
	} while ( pResult->NextRow() );
}

void AchievementInterface::SaveToDB(QueryBuffer * buffer)
{
	bool NewBuffer = false;
	if( !buffer )
	{
		buffer = new QueryBuffer;
		NewBuffer = true;
	}

	map<uint32,AchievementData*>::iterator itr = m_achivementDataMap.begin();
	for(; itr != m_achivementDataMap.end(); ++itr)
	{
		AchievementData * ad = itr->second;
		if( !ad->m_isDirty )
			continue;

		std::stringstream ss;
		ss << "REPLACE INTO achievements (player,achievementid,progress,completed) VALUES (";
		ss << GetPlayer()->GetLowGUID() << ",";
		ss << ad->id << ",";
		ss << "'";
		for(uint32 i = 0; i < ad->num_criterias; ++i)
		{
			ss << ad->counter[i] << ",";
		}
		ss << "',";
		ss << ad->date << ")";
		buffer->AddQueryStr( ss.str().c_str() );

		ad->m_isDirty = false;
	}

	if( NewBuffer )
		CharacterDatabase.AddQueryBuffer( buffer );
}

WorldPacket* AchievementInterface::BuildAchievementData(bool forInspect)
{
	if(forInspect && m_achievementInspectPacket)
		return m_achievementInspectPacket;

	WorldPacket * data = new WorldPacket(forInspect ? SMSG_RESPOND_INSPECT_ACHIEVEMENTS : SMSG_ALL_ACHIEVEMENT_DATA, 400);
	if(forInspect)
		*data << GetPlayer()->GetNewGUID();

	std::map<uint32,AchievementData*>::iterator itr = m_achivementDataMap.begin();
	for(; itr != m_achivementDataMap.end(); ++itr)
	{
		if( itr->second->completed )
		{
			*data << uint32(itr->first);
			*data << uint32( unixTimeToTimeBitfields(itr->second->date) );
		}
	}

	*data << int32(-1);
	itr = m_achivementDataMap.begin(); // Re-loop, luls
	for(; itr != m_achivementDataMap.end(); ++itr)
	{
		if( !itr->second->completed )
		{
			AchievementEntry * ae = dbcAchievement.LookupEntry( itr->second->id );
			// Loop over the associated criteria
			for(uint32 i = 0; i < ae->AssociatedCriteriaCount; ++i)
			{
				*data << uint32( ae->AssociatedCriteria[i] );
				uint32 counterVar = itr->second->counter[i];
				FastGUIDPack( *data, counterVar );
				*data << GetPlayer()->GetNewGUID();
				*data << uint32(0);
				*data << uint32( unixTimeToTimeBitfields( time(NULL) ) );
				*data << uint32(0);
				*data << uint32(0);
			}
		}
	}
	*data << int32(-1);

	if(forInspect)
		m_achievementInspectPacket = data;

	return data;
}

void AchievementInterface::GiveRewardsForAchievement(AchievementEntry * ae)
{
	AchievementReward * ar = AchievementRewardStorage.LookupEntry( ae->ID );
	if(!ar) return;

	// Reward: Item
	if( ar->ItemID )
	{
		// Just use the in-game mail system and mail it to him.
		MailMessage msg;
		memset(&msg, 0, sizeof(MailMessage));
		
		ItemPointer pItem = objmgr.CreateItem( ar->ItemID, NULLPLR );
		if(!pItem) return;

		pItem->SaveToDB( INVENTORY_SLOT_NOT_SET, 0, true, NULL );
		msg.items.push_back(pItem->GetUInt32Value(OBJECT_FIELD_GUID));

		msg.body = string(ar->text);
		msg.subject = string(ar->subject);

		msg.sender_guid = uint64(ar->sender);
		msg.player_guid = uint64(GetPlayer()->GetGuid());
		msg.delivery_time = (uint32)UNIXTIME;
		msg.expire_time = 0; // This message NEVER expires.
		
		// BLooD_LorD:fixed deliver message system, implemented UDB support
		sMailSystem.DeliverMessage(&msg);

		pItem->Destructor();
		pItem = NULLITEM;
	}
}

void AchievementInterface::EventAchievementEarned(AchievementData * pData)
{
	const char *msg = PLAYERSHAEAAA;
	pData->completed = true;
	pData->date = (uint32)time(NULL);

	AchievementEntry * ae = dbcAchievement.LookupEntry(pData->id);

	GiveRewardsForAchievement(ae);

	WorldPacket * data = BuildAchievementEarned(pData);

	if( GetPlayer()->IsInWorld() )
		GetPlayer()->GetSession()->SendPacket( data );
	else
		GetPlayer()->CopyAndSendDelayedPacket( data );

	delete data;

	HandleAchievementCriteriaRequiresAchievement(pData->id);

	// Realm First Achievements
	if( string(ae->name).find(REALMFIRSTAAA) != string::npos  ) // flags are wrong lol
	{
		m_completedRealmFirstAchievements.insert( ae->ID );

		// Send to my team
		WorldPacket data(SMSG_SERVER_FIRST_ACHIEVEMENT, 60);
		data << GetPlayer()->GetName();
		data << GetPlayer()->GetGUID();
		data << ae->ID;
		data << uint32(1);
		sWorld.SendFactionMessage(&data, GetPlayer()->GetTeam());

		// Send to the other team (no clickable link)
		WorldPacket data2(SMSG_SERVER_FIRST_ACHIEVEMENT, 60);
		data2 << GetPlayer()->GetName();
		data2 << GetPlayer()->GetGUID();
		data2 << ae->ID;
		data2 << uint32(0);
		sWorld.SendFactionMessage(&data2, GetPlayer()->GetTeam() ? 0 : 1);
	}
   else
   {
       // Send Achievement message to player and nearby players
       WorldPacket data(SMSG_MESSAGECHAT, 200);
       data << uint8(CHAT_MSG_ACHIEVEMENT);
       data << uint32(LANG_UNIVERSAL);
       data << uint64(GetPlayer()->GetGUID());
       data << uint32(5);
       data << uint64(GetPlayer()->GetGUID());
       data << uint32(strlen(msg)+1);
       data << msg;
       data << uint8(0);
       data << uint32(ae->ID);
       GetPlayer()->GetSession()->SendPacket(&data);
  
      
       unordered_set<PlayerPointer >::iterator inRangeItr = GetPlayer()->GetInRangePlayerSetBegin();
       unordered_set<PlayerPointer >::iterator inRangeItrLast = GetPlayer()->GetInRangePlayerSetEnd();
      
       for(; inRangeItr != inRangeItrLast; ++inRangeItr)
       {
           if((*inRangeItr) && (*inRangeItr)->GetSession() &&  !(*inRangeItr)->Social_IsIgnoring( GetPlayer()->GetLowGUID() ) )
           {
               (*inRangeItr)->GetSession()->SendPacket(&data);
          
           }
       }
      
       // Send Achievement message to every group (raid or party) member currently on the server except to the achiever
       Group* group = GetPlayer()->GetGroup();
       if(group)
       {
           if(group->GetGroupType()==GROUP_TYPE_PARTY || group->GetGroupType()==GROUP_TYPE_RAID)
           {
                   WorldPacket data(SMSG_MESSAGECHAT, 200);
                   data << uint8(CHAT_MSG_ACHIEVEMENT);// maybe this must be somthing like CHAT_MSG_PARTY_ACHIEVEMENT OR CHAT_MSG_RAID_ACHIEVEMENT
                   data << uint32(LANG_UNIVERSAL);
                   data << uint64(GetPlayer()->GetGUID());
                   data << uint32(5);
                   data << uint64(GetPlayer()->GetGUID());
                   data << uint32(strlen(msg)+1);
                   data << msg;
                   data << uint8(0);
                   data << uint32(ae->ID);
                   group->SendPacketToAllButOne(&data,GetPlayer());
           }
       }
      
       // Send Achievement message to every guild member currently on the server except to the achiever
       if(GetPlayer()->IsInGuild())
       {
               Guild* guild = GetPlayer()->GetGuild();
               WorldPacket data(SMSG_MESSAGECHAT, 200);
               data << uint8(CHAT_MSG_GUILD_ACHIEVEMENT);
               data << uint32(LANG_UNIVERSAL);
               data << uint64(GetPlayer()->GetGUID());
               data << uint32(5);
               data << uint64(GetPlayer()->GetGUID());
               data << uint32(strlen(msg)+1);
               data << msg;
               data << uint8(0);
               data << uint32(ae->ID);
               guild->SendPacketToAllButOne(&data,GetPlayer());
       }
  
   }
  
}

WorldPacket* AchievementInterface::BuildAchievementEarned(AchievementData * pData)
{
	pData->m_isDirty = true;
	WorldPacket * data = new WorldPacket(SMSG_ACHIEVEMENT_EARNED, 40);
	*data << GetPlayer()->GetNewGUID();
	*data << pData->id;
	*data << uint32( unixTimeToTimeBitfields(time(NULL)) );
	*data << uint32(0);

	if( m_achievementInspectPacket )
	{
		delete m_achievementInspectPacket;
		m_achievementInspectPacket = NULL;
	}

	return data;
}

AchievementData* AchievementInterface::CreateAchievementDataEntryForAchievement(AchievementEntry * ae)
{
	AchievementData * ad = new AchievementData;
	memset(ad, 0, sizeof(AchievementData));
	ad->id = ae->ID;
	ad->num_criterias = ae->AssociatedCriteriaCount;
	m_achivementDataMap.insert( make_pair( ad->id, ad ) );
	return ad;
}

bool AchievementInterface::CanCompleteAchievement(AchievementData * ad)
{
	// don't allow GMs to complete achievements
	if( GetPlayer()->GetSession()->HasGMPermissions() )
		return false;

	if( ad->completed ) return false;

	bool hasCompleted = false;
	AchievementEntry * ach = dbcAchievement.LookupEntry(ad->id);
	if( ach->categoryId == 1 ) // We cannot complete statistics
		return false;

	// realm first achievements
	if( m_completedRealmFirstAchievements.find(ad->id) != m_completedRealmFirstAchievements.end() )
		return false;

	bool failedOne = false;
	for(uint32 i = 0; i < ad->num_criterias; ++i)
	{
		bool thisFail = false;
		AchievementCriteriaEntry * ace = dbcAchivementCriteria.LookupEntry(ach->AssociatedCriteria[i]);
		uint32 ReqCount = ace->raw.field4 ? ace->raw.field4 : 1;

		if( ace->groupFlag & ACHIEVEMENT_CRITERIA_GROUP_NOT_IN_GROUP && GetPlayer()->GetGroup() )
			return false;

		if( ace->timeLimit && ace->timeLimit < ad->completionTimeLast )
			thisFail = true;

		if( ad->counter[i] < ReqCount )
			thisFail = true;

		if( ach->factionFlag == ACHIEVEMENT_FACTION_ALLIANCE && GetPlayer()->GetTeam() == 1 )
			thisFail = true;

		if( ach->factionFlag == ACHIEVEMENT_FACTION_HORDE && GetPlayer()->GetTeam() == 0 )
			thisFail = true;

		if( thisFail && ace->completionFlag & ACHIEVEMENT_CRITERIA_COMPLETE_ONE_FLAG )
			failedOne = true;
		else if(thisFail)
			return false;

		if( !thisFail && ace->completionFlag & ACHIEVEMENT_CRITERIA_COMPLETE_ONE_FLAG )
			hasCompleted = true;
	}

	if( failedOne && !hasCompleted )
		return false;

	return true;
}

AchievementData* AchievementInterface::GetAchievementDataByAchievementID(uint32 ID)
{
	map<uint32,AchievementData*>::iterator itr = m_achivementDataMap.find( ID );
	if( itr != m_achivementDataMap.end() )
		return itr->second;
	else
	{
		AchievementEntry * ae = dbcAchievement.LookupEntryForced(ID);
		if(!ae)
		{
			printf(NOACHIEVEMAAA, ID);
		}
		return CreateAchievementDataEntryForAchievement(ae);
	}
}

void AchievementInterface::SendCriteriaUpdate(AchievementData * ad, uint32 idx)
{
	ad->m_isDirty = true;
	ad->date = (uint32)time(NULL);
	WorldPacket data(SMSG_CRITERIA_UPDATE, 50);
	AchievementEntry * ae = dbcAchievement.LookupEntry(ad->id);
	data << uint32(ae->AssociatedCriteria[idx]);
	FastGUIDPack( data, (uint64)ad->counter[idx] );
	data << GetPlayer()->GetNewGUID();   
	data << uint32(0);
	data << uint32(unixTimeToTimeBitfields(time(NULL)));
	data << uint32(0);
	data << uint32(0); 

	if( !GetPlayer()->IsInWorld() )
		GetPlayer()->CopyAndSendDelayedPacket(&data);
	else
		GetPlayer()->GetSession()->SendPacket(&data);

	if( m_achievementInspectPacket )
	{
		delete m_achievementInspectPacket;
		m_achievementInspectPacket = NULL;
	}
}

void AchievementInterface::HandleAchievementCriteriaConditionDeath()
{
	// We died, so reset all our achievements that have ACHIEVEMENT_CRITERIA_CONDITION_NO_DEATH
	if( !m_achivementDataMap.size() )
		return;

	map<uint32,AchievementData*>::iterator itr = m_achivementDataMap.begin();
	for(; itr != m_achivementDataMap.end(); ++itr)
	{
		AchievementData * ad = itr->second;
		if(ad->completed) continue;
		AchievementEntry * ae = dbcAchievement.LookupEntry( ad->id );
		for(uint32 i = 0; i < ad->num_criterias; ++i)
		{
			uint32 CriteriaID = ae->AssociatedCriteria[i];
			AchievementCriteriaEntry * ace = dbcAchivementCriteria.LookupEntry( CriteriaID );
			if( ad->counter[i] && ace->raw.additionalRequirement1_type & ACHIEVEMENT_CRITERIA_CONDITION_NO_DEATH )
			{
				ad->counter[i] = 0;
				SendCriteriaUpdate(ad, i); break;
			}
		}
	}
}

void AchievementInterface::HandleAchievementCriteriaKillCreature(uint32 killedMonster)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
	{
		return;
	}
	
	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqKill = ace->kill_creature.creatureID;
		uint32 ReqCount = ace->kill_creature.creatureCount;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;


		// Wrong monster, continue on, kids.
		if( ReqKill != killedMonster )
			continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaWinBattleground(uint32 bgMapId, uint32 scoreMargin, uint32 time, BattlegroundPointer bg)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_WIN_BG );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqBGMap = ace->win_bg.bgMapID;
		uint32 ReqCount = ace->win_bg.winCount;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;
		// Wrong BG, continue on, kids.
		if( ReqBGMap != bgMapId )
			continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		ad->completionTimeLast = time;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				if( compareCriteria->raw.additionalRequirement1_type && scoreMargin < compareCriteria->raw.additionalRequirement1_type ) // BG Score Requirement.
					continue;

				// AV stuff :P
				if( bg->GetType() == BATTLEGROUND_ALTERAC_VALLEY )
				{
					AlteracValleyPointer pAV(TO_ALTERACVALLEY(bg));
					if( pAchievementEntry->ID == 225 ||  pAchievementEntry->ID == 1164) // AV: Everything Counts
					{
						continue; // We do not support mines yet in AV
					}

					if( pAchievementEntry->ID == 220 ) // AV: Stormpike Perfection
					{
						bool failure = false;
						// We must control all Alliance nodes and Horde nodes (towers only)
						for(uint32 i = 0; i < AV_NUM_CONTROL_POINTS; ++i)
						{
							if( pAV->GetNode(i)->IsGraveyard() )
								continue;

							if( pAV->GetNode(i)->GetState() != AV_NODE_STATE_ALLIANCE_CONTROLLED )
								failure = true;
						}
						if( failure ) continue;
					}

					if( pAchievementEntry->ID == 873 ) // AV: Frostwolf Perfection
					{
						bool failure = false;
						// We must control all Alliance nodes and Horde nodes (towers only)
						for(uint32 i = 0; i < AV_NUM_CONTROL_POINTS; ++i)
						{
							if( pAV->GetNode(i)->IsGraveyard() )
								continue;

							if( pAV->GetNode(i)->GetState() != AV_NODE_STATE_HORDE_CONTROLLED )
								failure = true;
						}
						if( failure ) continue;
					}
				}

				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaRequiresAchievement(uint32 achievementId)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ACHIEVEMENT );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqAchievement = ace->complete_achievement.linkedAchievement;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		if( ReqAchievement != achievementId )
			continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;

		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaLevelUp(uint32 level)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_REACH_LEVEL );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqLevel = ace->reach_level.level;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		if( level < ReqLevel )
			continue;

		// Realm first to 80 stuff has race and class requirements. Let the hacking begin.
		if( string(pAchievementEntry->name).find(REALMFIRSTAAA) != string::npos )
		{
		    static const char* classNames[] = { "", WARRIORSAAA, PALADINAAAA, HUNTERAAAAA, ROGURAAAAAA, PRISTAAAAAA, DEATHKNIGAI, SHAMANAAAAA, MAGEAAAAAAA, WARLOCKAAAA, "", DRUIDSAAAAA };
			static const char* raceNames[] = { "", HUMANAAAAAA, ORCSAAAAAAA, DRARTSAAAAA, NIGHTELFAAA, FORSAKENAAA, TAURENSAAAA, GNOMESAAAAA, TROLLSAAAAA, "", BLOODELDSAA, DRAENEISAAA };

			uint32 ReqClass = 0;
			uint32 ReqRace = 0;
			for(uint32 i = 0; i < 12; ++i)
			{
				if(strlen(classNames[i]) > 0 && string(pAchievementEntry->name).find(classNames[i]) != string::npos )
				{
					// We require this class
					ReqClass = i;
					break;
				}
			}
			for(uint32 i = 0; i < 12; ++i)
			{
				if(strlen(raceNames[i]) > 0 && string(pAchievementEntry->name).find(raceNames[i]) != string::npos )
				{
					// We require this race
					ReqRace = i;
					break;
				}
			}

			if( ReqClass && GetPlayer()->getClass() != ReqClass )
				continue;

			if( ReqRace && GetPlayer()->getRace() != ReqRace )
				continue;
		}

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;

		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = GetPlayer()->getLevel() > ReqLevel ? ReqLevel : GetPlayer()->getLevel();
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaOwnItem(uint32 itemId, uint32 stack)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_OWN_ITEM );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqItemId = ace->own_item.itemID;
		uint32 ReqItemCount = ace->own_item.itemCount;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		if( itemId != ReqItemId )
			continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if( ad->completed )
			continue;

		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + stack;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}

	HandleAchievementCriteriaLootItem(itemId, stack);
}

void AchievementInterface::HandleAchievementCriteriaLootItem(uint32 itemId, uint32 stack)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_LOOT_ITEM );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqItemId = ace->loot_item.itemID;
		uint32 ReqItemCount = ace->loot_item.itemCount;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		if( itemId != ReqItemId )
			continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;

		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + stack;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaQuestCount(uint32 questCount)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUEST_COUNT );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqQuestCount = ace->complete_quest_count.totalQuestCount;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;

		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = questCount;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaHonorableKillClass(uint32 classId)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_HK_CLASS );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqClass = ace->hk_class.classID;
		uint32 ReqCount = ace->hk_class.count;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		if( ReqClass != classId )
			continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaHonorableKillRace(uint32 raceId)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_HK_RACE );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqRace = ace->hk_race.raceID;
		uint32 ReqCount = ace->hk_race.count;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		if( ReqRace != raceId )
			continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaTalentResetCostTotal(uint32 cost)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + cost;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaTalentResetCount()
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaBuyBankSlot(bool retroactive)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_BUY_BANK_SLOT );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqSlots = ace->buy_bank_slot.numberOfSlots; // We don't actually use this. :P

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				if( retroactive )
				{
					uint32 bytes = GetPlayer()->GetUInt32Value(PLAYER_BYTES_2);
					uint32 slots = (uint8)(bytes >> 16);
					ad->counter[i] = slots > ReqSlots ? ReqSlots : slots;
				}
				else
					ad->counter[i] = ad->counter[i] + 1;

				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaFlightPathsTaken()
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_FLIGHT_PATHS_TAKEN );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaExploreArea(uint32 areaId, uint32 explorationFlags)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_EXPLORE_AREA );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqFlags = ace->explore_area.areaReference;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		WorldMapOverlayEntry * wmoe = dbcWorldMapOverlay.LookupEntryForced( ReqFlags );
		if(!wmoe) continue;

		AreaTable * at = dbcArea.LookupEntryForced(wmoe->AreaTableID);
		if(!at || !(ReqFlags & at->explorationFlag) )
			continue;

		uint32 offset = at->explorationFlag / 32;
		offset += PLAYER_EXPLORED_ZONES_1;

		uint32 val = (uint32)(1 << (at->explorationFlag % 32));
		uint32 currFields = GetPlayer()->GetUInt32Value(offset);

		// Not explored /sadface
		if( !(currFields & val) )
			continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;

		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaHonorableKill()
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_EARN_HONORABLE_KILL );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqKills = ace->honorable_kill.killCount;

		if( GetPlayer()->m_killsLifetime < ReqKills )
			continue;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

#define SCRIPTOK_FALSE { scriptOk = false; break; }
void AchievementInterface::HandleAchievementCriteriaDoEmote(uint32 emoteId, UnitPointer pTarget)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_DO_EMOTE );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqEmote = ace->do_emote.emoteID;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		if(ReqEmote != emoteId)
			continue; // Wrong emote, newb!

		// Target information is not stored, so we'll have to do this one by one...
		// --unless the target's name is the description of the criteria! Bahahaha
		bool scriptOk = false;
		if( pTarget && pTarget->IsCreature() )
		{
			CreaturePointer pCreature = TO_CREATURE(pTarget);
			if( !(!ace->name || strlen(ace->name) == 0 || !pCreature->GetCreatureName() || stricmp(pCreature->GetCreatureName()->Name, ace->name) != 0) )
			{
				scriptOk = true;
			}
		}

		string name = string(pAchievementEntry->name);
		if( name.find(TOTALAAAAAAAA) != string::npos )
		{
			// It's a statistic, like: "Total Times /Lol'd"
			scriptOk = true;
		}

		// Script individual ones here...
		if( ace->ID == 2379 ) // Make Love, Not Warcraft
		{
			if( !pTarget || !pTarget->IsPlayer() || !pTarget->isDead() || !isHostile(pTarget, GetPlayer()) )
				SCRIPTOK_FALSE

			scriptOk = true;
		}
		else if( ace->ID == 6261 ) // Winter Veil: A Frosty Shake 
		{
		    if( GetPlayer()->GetZoneId() != 4395 ) // Not in Dalaran
				SCRIPTOK_FALSE
			
			if( !pTarget || !pTarget->HasAura(21848) ) // Not a Snowman
				SCRIPTOK_FALSE

			scriptOk = true;
		}

		if( !scriptOk ) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaCompleteQuestsInZone(uint32 zoneId)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqZone = ace->complete_quests_in_zone.zoneID;
		uint32 ReqCount = ace->complete_quests_in_zone.questCount;

		if( ReqZone != zoneId )
			continue;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;

		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaReachSkillLevel(uint32 skillId, uint32 skillLevel)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_REACH_SKILL_LEVEL );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqSkill = ace->reach_skill_level.skillID;
		uint32 ReqLevel = ace->reach_skill_level.skillLevel;

		if( ReqSkill != skillId )
			continue;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;

		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = skillLevel;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaWinDuel()
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_WIN_DUEL );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		//uint32 ReqDuels = ace->win_duel.duelCount;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaLoseDuel()
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_LOSE_DUEL );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		//uint32 ReqDuels = ace->win_duel.duelCount;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i] = ad->counter[i] + 1;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaKilledByCreature(uint32 killedMonster)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_CREATURE );
	if( itr == objmgr.m_achievementCriteriaMap.end() )
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 ReqCreature = ace->killed_by_creature.creatureEntry;

		if( ReqCreature != killedMonster )
			continue;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i]++;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaKilledByPlayer()
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_KILLED_BY_PLAYER );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i]++;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}

void AchievementInterface::HandleAchievementCriteriaDeath()
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_DEATH );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i]++;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}

	HandleAchievementCriteriaDeathAtMap(GetPlayer()->GetMapId());
}

void AchievementInterface::HandleAchievementCriteriaDeathAtMap(uint32 mapId)
{
	AchievementCriteriaMap::iterator itr = objmgr.m_achievementCriteriaMap.find( ACHIEVEMENT_CRITERIA_TYPE_DEATH_AT_MAP );
	if(itr == objmgr.m_achievementCriteriaMap.end())
		return;

	AchievementCriteriaSet * acs = itr->second;
	if( !acs ) // We have no achievements for this criteria :(
		return;

	AchievementCriteriaSet::iterator citr = acs->begin();
	for(; citr != acs->end(); ++citr)
	{
		AchievementCriteriaEntry * ace = (*citr);
		uint32 AchievementID = ace->referredAchievement;
		uint32 MapID = ace->death_at_map.mapID;

		if( mapId != MapID )
			continue;

		AchievementEntry * pAchievementEntry = dbcAchievement.LookupEntryForced(AchievementID);
		if(!pAchievementEntry) continue;

		AchievementCriteriaEntry * compareCriteria = NULL;
		AchievementData * ad = GetAchievementDataByAchievementID(AchievementID);
		if(ad->completed)
			continue;
		// Figure out our associative ID.
		for(uint32 i = 0; i < pAchievementEntry->AssociatedCriteriaCount; ++i)
		{
			compareCriteria = dbcAchivementCriteria.LookupEntry( pAchievementEntry->AssociatedCriteria[i] );			
			if( compareCriteria == ace )
			{
				ad->counter[i]++;
				SendCriteriaUpdate(ad, i); break;
			}
		}

		if( CanCompleteAchievement(ad) )
			EventAchievementEarned(ad);
	}
}


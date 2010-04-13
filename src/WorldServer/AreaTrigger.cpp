/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

const char * AreaTriggerFailureMessages[] = 
{
	"-",
	"This instance is currently not available",                                         // AREA_TRIGGER_FAILURE_UNAVAILABLE	
	"You must have the \"Burning Crusade\" expansion to access this content.",          // AREA_TRIGGER_FAILURE_NO_BC
	"Heroic mode currently not available for this instance.",                           // AREA_TRIGGER_FAILURE_NO_HEROIC
	"You must be in a raid group to pass through here.",                                // AREA_TRIGGER_FAILURE_NO_RAID
	"You must complete the quest \"%s\" to pass through here.",                         // AREA_TRIGGER_FAILURE_NO_ATTUNE_Q	
	"You must have item \"%s\" to pass through here.",                                  // AREA_TRIGGER_FAILURE_NO_ATTUNE_I	
	"You must have reached level %u before you can pass through here.",                 // AREA_TRIGGER_FAILURE_LEVEL
	"You must be in a party to pass through here.",                                     // AREA_TRIGGER_FAILURE_NO_GROUP
	"You do not have a required key(s) \"%s\" to pass through here.",                   // AREA_TRIGGER_FAILURE_NO_KEY
	"You must have reached level %u before you can enter heroic mode.",                 // AREA_TRIGGER_FAILURE_LEVEL_HEROIC
	"Don\'t have any idea why you can\'t pass through here.",                           // AREA_TRIGGER_FAILURE_NO_CHECK
	"You must have the \"Wrath of the Lich King\" expansion to access this content.",   // AREA_TRIGGER_FAILURE_NO_WOTLK
	"You are in queue for this raid group.",                                            // AREA_TRIGGER_FAILURE_IN_QUEUE
	"Another group is already active inside.",											// AREA_TRIGGER_FAILURE_WRONG_GROUP
};

void WorldSession::HandleAreaTriggerOpcode(WorldPacket & recv_data)
{
	CHECK_INWORLD_RETURN;
	CHECK_PACKET_SIZE(recv_data, 4);
	uint32 id ;
	recv_data >> id;
	_HandleAreaTriggerOpcode(id);
}

uint32 CheckTriggerPrerequsites(AreaTrigger * pAreaTrigger, WorldSession * pSession, PlayerPointer pPlayer, MapInfo * pMapInfo)
{
	if(pAreaTrigger->required_level && pPlayer->getLevel() < pAreaTrigger->required_level)
		return AREA_TRIGGER_FAILURE_LEVEL;

	if(!pMapInfo || !pMapInfo->HasFlag(WMI_INSTANCE_ENABLED))
		return AREA_TRIGGER_FAILURE_UNAVAILABLE;

	if(!pSession->HasFlag(ACCOUNT_FLAG_XPACK_01) && pMapInfo->HasFlag(WMI_INSTANCE_XPACK_01))
		return AREA_TRIGGER_FAILURE_NO_BC;

	// These can be overridden by cheats/GM
	if(!pPlayer->triggerpass_cheat)
	{
		if( (pMapInfo->type == INSTANCE_RAID || pMapInfo->type == INSTANCE_MULTIMODE ) && !pPlayer->GetGroup())
			return AREA_TRIGGER_FAILURE_NO_GROUP;

		if( pPlayer->iInstanceType >= MODE_HEROIC && pMapInfo->type != INSTANCE_MULTIMODE && pMapInfo->type != INSTANCE_NULL)
			return AREA_TRIGGER_FAILURE_NO_HEROIC;

		if( pMapInfo->type == INSTANCE_RAID && pPlayer->GetGroup()->GetGroupType() != GROUP_TYPE_RAID )
			return AREA_TRIGGER_FAILURE_NO_RAID;

		if( pMapInfo && pMapInfo->required_quest && !( pPlayer->HasFinishedDailyQuest(pMapInfo->required_quest) || pPlayer->HasFinishedDailyQuest(pMapInfo->required_quest)))
			return AREA_TRIGGER_FAILURE_NO_ATTUNE_Q;

		if(pMapInfo && pMapInfo->required_item && !pPlayer->GetItemInterface()->GetItemCount(pMapInfo->required_item, true))
			return AREA_TRIGGER_FAILURE_NO_ATTUNE_I;

		// we try to enter a heroic instance
		if( pPlayer->iInstanceType >= MODE_HEROIC && pMapInfo->type != INSTANCE_NULL )
		{
			// All Northerend heroic instances are automatically unlocked when reaching lvl 80, no keys needed here.
			if(pMapInfo->HasFlag(WMI_INSTANCE_XPACK_02) && pPlayer->getLevel()>= 80)
					return AREA_TRIGGER_FAILURE_OK;
			else
			{
				int minLvl = 70;
				if ( pMapInfo->HasFlag(WMI_INSTANCE_XPACK_02) )
					minLvl = 80;
				if( pPlayer->iInstanceType >= MODE_HEROIC && (int)pPlayer->getLevel() <  minLvl)
					return AREA_TRIGGER_FAILURE_LEVEL_HEROIC;

				// do we need a key?
				bool reqkey = (pMapInfo->heroic_key[0]||pMapInfo->heroic_key[1])?true:false;

				// do we have a key?
				bool haskey = (pPlayer->GetItemInterface()->GetItemCount(pMapInfo->heroic_key[0], false) || pPlayer->GetItemInterface()->GetItemCount(pMapInfo->heroic_key[1], false))?true:false;

				if(reqkey && !haskey)
					return AREA_TRIGGER_FAILURE_NO_KEY;
			}
		}
	}
	else
		return AREA_TRIGGER_FAILURE_OK;

	// Raid queue
	if( pMapInfo->type == INSTANCE_RAID || ( pPlayer->iInstanceType >= MODE_HEROIC && pMapInfo->type == INSTANCE_MULTIMODE ) )
	{
		if( ! pPlayer->triggerpass_cheat && pPlayer->m_playerInfo && pMapInfo->playerlimit >= 5 &&
			(int32)((pMapInfo->playerlimit - 5)/5) < pPlayer->m_playerInfo->subGroup)
			return AREA_TRIGGER_FAILURE_IN_QUEUE;
	}

	return AREA_TRIGGER_FAILURE_OK;
}

void WorldSession::_HandleAreaTriggerOpcode(uint32 id)
{		
	DEBUG_LOG( "WorldSession","HandleAreaTriggerOpcode: %u", id);

	// Are we REALLY here?
	CHECK_INWORLD_RETURN;

	// Search quest log, find any exploration quests
	sQuestMgr.OnPlayerExploreArea(GetPlayer(),id);

	AreaTrigger* pAreaTrigger = AreaTriggerStorage.LookupEntry( id );

	sHookInterface.OnAreaTrigger(_player, id);
	CALL_INSTANCE_SCRIPT_EVENT( _player->GetMapMgr(), OnAreaTrigger )( _player, id );

	// if in BG handle is triggers
	if( _player->m_bg )
	{
		_player->m_bg->HookOnAreaTrigger(_player, id);
		return;
	}

	// Hook for Scripted Areatriggers
	_player->GetMapMgr()->HookOnAreaTrigger(_player, id);

	if( _player->GetSession()->CanUseCommand('z') )
	{
		if( pAreaTrigger != NULL )
			sChatHandler.BlueSystemMessage( this, "[%sSystem%s] |rEntered areatrigger: %s%u (%s).", MSG_COLOR_WHITE, MSG_COLOR_LIGHTBLUE, MSG_COLOR_SUBWHITE, id, pAreaTrigger->Name );
		else
			sChatHandler.BlueSystemMessage( this, "[%sSystem%s] |rEntered areatrigger: %s%u", MSG_COLOR_WHITE, MSG_COLOR_LIGHTBLUE, MSG_COLOR_SUBWHITE, id);
	}

	if( pAreaTrigger == NULL )
	{
		OUT_DEBUG("Missing AreaTrigger: %u", id);
		return;
	}

	switch(pAreaTrigger->Type)
	{
	case ATTYPE_INSTANCE:
		{
			if(_player->GetPlayerStatus() != TRANSFER_PENDING) // only ports if player is out of pendings
			{
				MapInfo * pMi = WorldMapInfoStorage.LookupEntry(pAreaTrigger->Mapid);
				MapEntry* map = dbcMap.LookupEntry(pAreaTrigger->Mapid);
				if(!pMi)
					return;

				// do we meet the map requirements?
				uint8 reason = CheckTeleportPrerequisites(pAreaTrigger, this, _player, pAreaTrigger->Mapid);
				if(reason != AREA_TRIGGER_FAILURE_OK)
				{
					const char * pReason = AreaTriggerFailureMessages[reason];
					char msg[200];
					WorldPacket data(SMSG_AREA_TRIGGER_MESSAGE, 50);
					data << uint32(0);

					switch (reason)
					{
					case AREA_TRIGGER_FAILURE_LEVEL:
						{
							snprintf(msg,200,pReason,pAreaTrigger->required_level);
							data << msg;
						}break;
					case AREA_TRIGGER_FAILURE_NO_ATTUNE_I:
						{
							ItemPrototype * pItem = ItemPrototypeStorage.LookupEntry(pMi->required_item);
							snprintf(msg, 200, pReason, pItem ? pItem->Name1 : "UNKNOWN");
							data << msg;
						}break;
					case AREA_TRIGGER_FAILURE_NO_ATTUNE_Q:
						{
							Quest * pQuest = QuestStorage.LookupEntry(pMi->required_quest);
							snprintf(msg, 200, pReason, pQuest ? pQuest->title : "UNKNOWN");

							data << msg;
						}break;
					case AREA_TRIGGER_FAILURE_NO_KEY:
						{
							string temp_msg[2];
							string tmp_msg;
							for(uint32 i = 0; i < 2; ++i) 
							{
								if (pMi->heroic_key[i] && _player->GetItemInterface()->GetItemCount(pMi->heroic_key[i], false)==0)
								{
									ItemPrototype * pKey = ItemPrototypeStorage.LookupEntry(pMi->heroic_key[i]);
									if(pKey)
										temp_msg[i] += pKey->Name1;
									else
										temp_msg[i] += "UNKNOWN";
								}
							}
							tmp_msg += temp_msg[0];
							if(temp_msg[0].size() && temp_msg[1].size())
								tmp_msg += "\" and \"";
							tmp_msg += temp_msg[1];

							snprintf(msg, 200, pReason, tmp_msg.c_str());
							data << msg;
						}break;
					case AREA_TRIGGER_FAILURE_LEVEL_HEROIC:
						{
							snprintf(msg, 200, pReason, pMi->HasFlag(WMI_INSTANCE_XPACK_02) ? 80 : 70);
							data << msg;
						}break;
					default:
						{
							data << pReason;
						}break;
					}

					data << uint8(0);
					SendPacket(&data);
					return;
				}

				if( _player->IsMounted())
					TO_UNIT(_player)->Dismount();

				uint32 InstanceID = 0;
				// Try to find a saved instance and
				// do not handle Hyjal Inn (trigger 4319), since we need a unique mapid when generating our instance_id.

				if( id != 4319 && pMi && ( map->israid() || _player->iRaidType >= MODE_25PLAYER_NORMAL && pMi->type == INSTANCE_MULTIMODE ) )
				{
					// Do we have a saved instance we should use?
					Instance * in = NULL;
					in = sInstanceMgr.GetSavedInstance( pMi->mapid,_player->GetLowGUID(), _player->iRaidType );
					if( in != NULL  && in->m_instanceId )
					{
						//If we are the first to enter this instance, also set our current group id.
						if( in->m_mapMgr == NULL || (!in->m_mapMgr->HasPlayers() && _player->GetGroupID() != in->m_creatorGroup))
							in->m_creatorGroup =_player->GetGroupID();
						InstanceID = in->m_instanceId;
					}
				}

				// Save our entry point and try to teleport to our instance
				_player->SaveEntryPoint(pAreaTrigger->Mapid);
				_player->SafeTeleport(pAreaTrigger->Mapid, InstanceID, LocationVector(pAreaTrigger->x, pAreaTrigger->y, pAreaTrigger->z, pAreaTrigger->o));
			}
		}break;
	case ATTYPE_QUESTTRIGGER:
		{

		}break;
	case ATTYPE_INN:
		{
			if( _player->IsMounted())
				TO_UNIT(_player)->Dismount();

			// Inn
			if (!_player->m_isResting) 
				_player->ApplyPlayerRestState(true);
		}break;
	case ATTYPE_TELEPORT:
		{
			if( _player->GetPlayerStatus() != TRANSFER_PENDING) // only ports if player is out of pendings
			{
				if( _player->IsMounted() )
					TO_UNIT(_player)->Dismount();

				_player->SaveEntryPoint(pAreaTrigger->Mapid);
				_player->SafeTeleport(pAreaTrigger->Mapid, 0, LocationVector(pAreaTrigger->x, pAreaTrigger->y, pAreaTrigger->z, pAreaTrigger->o));
			}
		}break;
	default:break;
	}
}

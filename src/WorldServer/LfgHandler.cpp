/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

void WorldSession::HandleSetLookingForGroupComment(WorldPacket& recvPacket)
{
	std::string comment;
	recvPacket >> comment;
	GetPlayer()->Lfgcomment = comment;
}

void WorldSession::HandleEnableAutoJoin(WorldPacket& recvPacket)
{
}

void WorldSession::HandleDisableAutoJoin(WorldPacket& recvPacket)
{
	uint32 i;
	_player->m_Autojoin = false;

	for(i = 0; i < MAX_LFG_QUEUE_ID; ++i)
	{
		if(_player->LfgDungeonId[i] != 0)
		{
			if(LfgDungeonTypes[_player->LfgDungeonId[i]] == LFG_TYPE_DUNGEON || LfgDungeonTypes[_player->LfgDungeonId[i]] == LFG_TYPE_HEROIC_DUNGEON)
				_player->SendMeetingStoneQueue(_player->LfgDungeonId[i], 0);
		}
	}
}

void WorldSession::HandleEnableAutoAddMembers(WorldPacket& recvPacket)
{
	uint32 i;
	_player->m_AutoAddMem = true;

	for(i = 0; i < MAX_LFG_QUEUE_ID; ++i)
	{
		if(_player->LfgDungeonId[i] != 0)
		{
			sLfgMgr.UpdateLfgQueue(_player->LfgDungeonId[i]);
		}
	}
}

void WorldSession::HandleDisableAutoAddMembers(WorldPacket& recvPacket)
{
	_player->m_AutoAddMem = false;	
}

void WorldSession::HandleMsgLookingForGroup(WorldPacket& recvPacket)
{
	/* this is looking for more */
	uint32 LfgType,LfgDungeonId,unk1;
	recvPacket >> LfgType >> LfgDungeonId >> unk1;
	
	if(LfgDungeonId > MAX_DUNGEONS)
		return;

	if(LfgDungeonId)
		sLfgMgr.SendLfgList(_player, LfgDungeonId);
}

void WorldSession::HandleSetLookingForGroup(WorldPacket& recvPacket)
{
	uint32 LfgQueueId;
	uint16 LfgDungeonId;
	uint8 LfgType,unk1;
	uint32 i;
	
	recvPacket >> LfgQueueId >> LfgDungeonId >> unk1 >> LfgType;
	
	if(LfgDungeonId >= MAX_DUNGEONS || LfgQueueId >= MAX_LFG_QUEUE_ID || LfgType != LfgDungeonTypes[LfgDungeonId]) // last one is for cheaters
		return;
	
	if(_player->LfgDungeonId[LfgQueueId] != 0)
		sLfgMgr.RemovePlayerFromLfgQueue(_player, _player->LfgDungeonId[LfgQueueId]);
	
	_player->LfgDungeonId[LfgQueueId]=LfgDungeonId;
	_player->LfgType[LfgQueueId]=LfgType;

	if(LfgDungeonId)
	{
		sLfgMgr.SetPlayerInLFGqueue(_player, LfgDungeonId);

		if(LfgType == LFG_TYPE_HEROIC_DUNGEON || LfgType == LFG_TYPE_DUNGEON)
		{
			sLfgMgr.UpdateLfgQueue(LfgDungeonId);
			if(_player->m_Autojoin)
				_player->SendMeetingStoneQueue(LfgDungeonId, 1);
		}
	}
	else
	{
		for(i = 0; i < 3; ++i)
		{
			if(_player->LfgDungeonId[i] != 0)
				break;
		}

		if( i == 3 )
			_player->PartLFGChannel();
	}
}

void WorldSession::HandleSetLookingForMore(WorldPacket& recvPacket)
{
	uint16 LfgDungeonId;
	uint8 LfgType,unk1;

	recvPacket >> LfgDungeonId >> unk1 >> LfgType;
	if( LfgDungeonId >= MAX_DUNGEONS )
		return;

	// remove from an existing queue
	if(LfgDungeonId != _player->LfmDungeonId && _player->LfmDungeonId)
		sLfgMgr.RemovePlayerFromLfmList(_player, _player->LfmDungeonId);

	_player->LfmDungeonId = LfgDungeonId;
	_player->LfmType = LfgType;

	if(LfgDungeonId)
		sLfgMgr.SetPlayerInLfmList(_player, LfgDungeonId);
}

void WorldSession::HandleLfgClear(WorldPacket & recvPacket)
{
	sLfgMgr.RemovePlayerFromLfgQueues(_player);
}

void WorldSession::HandleLfgInviteAccept(WorldPacket & recvPacket)
{
}

/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

void WorldSession::HandleAttackSwingOpcode( WorldPacket & recv_data )
{
	if(!_player->IsInWorld()) return;
	CHECK_PACKET_SIZE(recv_data, 8);
	uint64 guid;
	recv_data >> guid;

	if(!guid)
	{
		// does this mean cancel combat?
		HandleAttackStopOpcode(recv_data);
		return;
	}

	// AttackSwing
	DEBUG_LOG( WOWWORLDAI, CMSGWATAAI );

	if(GetPlayer()->IsPacified() || GetPlayer()->IsStunned() || GetPlayer()->IsFeared())
		return;

	UnitPointer pEnemy = _player->GetMapMgr()->GetUnit(guid);

	if(!pEnemy)
	{
		OUT_DEBUG(WORLDI64AI, guid);
		return;
	}

	if(pEnemy->isDead() || _player->isDead()) // haxors :(
		return;

	// Faction "Hack" by Deathshit
	if( !isAttackable( GetPlayer(), pEnemy, false ) && !pEnemy->IsInRangeOppFactSet(_player) && !pEnemy->CombatStatus.DidDamageTo(GetPlayer()->GetGUID()))
	{
		GetPlayer()->BroadcastMessage(FACTOINEAI);
		GetPlayer()->Kick(5000);
		return;
	}

	GetPlayer()->smsg_AttackStart(pEnemy);
	GetPlayer()->EventAttackStart();

}

void WorldSession::HandleAttackStopOpcode( WorldPacket & recv_data )
{
	if(!_player->IsInWorld()) return;
	uint64 guid = GetPlayer()->GetSelection();
	UnitPointer pEnemy = NULLUNIT;

	if(guid)
	{
		pEnemy = _player->GetMapMgr()->GetUnit(guid);
		if(pEnemy)
		{
			GetPlayer()->EventAttackStop();
			GetPlayer()->smsg_AttackStop(pEnemy);

		}
	}
}


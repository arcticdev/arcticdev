/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
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

    // printf("Got ATTACK SWING: %08X %08X\n", GUID_HIPART(guid), GUID_LOPART(guid));
	UnitPointer pEnemy = _player->GetMapMgr()->GetUnit(guid);
	//printf("Pointer: %08X\n", pEnemy);

	if(!pEnemy)
	{
		OUT_DEBUG(WORLDI64AI, guid);
		return;
	}

	if(pEnemy->isDead() || _player->isDead())		// haxors :(
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

	// Set PVP Flag.
	/*if(pEnemy->IsPlayer() && isHostile(_player, pEnemy))
	{
		// don't in duel.. this should be done in dealdamage anyway :S
		if( TO_PLAYER( pEnemy )->GetTeam() != _player->GetTeam() )
			_player->SetPvPFlag();
	}*/
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

			/*WorldPacket data(SMSG_ATTACKSTOP, 20);
			data << _player->GetNewGUID();
			data << uint8(0);
			data << uint32(0);
			SendPacket(&data);*/
		}
	}
}


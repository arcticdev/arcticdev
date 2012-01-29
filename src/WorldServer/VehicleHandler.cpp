/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

void WorldSession::HandleVehicleDismiss(WorldPacket & recv_data)
{
	if(GetPlayer() == NULL || GetPlayer()->m_CurrentVehicle == NULL)
		return;

	HandleMovementOpcodes(recv_data);
	GetPlayer()->m_CurrentVehicle->RemovePassenger(GetPlayer()); 
}

void WorldSession::HandleSpellClick( WorldPacket & recv_data )
{

	if(GetPlayer() == NULL || GetPlayer()->m_CurrentVehicle || GetPlayer()->GetMapMgr() == NULL)
		return;

	CHECK_PACKET_SIZE(recv_data, 8);

	uint64 guid = 0;
	recv_data >> guid;

	Vehicle* pVehicle = GetPlayer()->GetMapMgr()->GetVehicle(GET_LOWGUID_PART(guid));
	if(!pVehicle)
		return;

	if(pVehicle->HasPassenger(_player))
		pVehicle->RemovePassenger(_player);
	pVehicle->AddPassenger(_player);
}

void WorldSession::HandleBoardPlayerVehicleOpcode(WorldPacket &recv_data)
{
}

void WorldSession::HandleEjectPassengerOpcode(WorldPacket &recv_data)
{
	CHECK_INWORLD_RETURN;
	CHECK_PACKET_SIZE(recv_data, 2);

	uint64 guid;
	
	recv_data >> guid;

	Unit* pPlayer = TO_UNIT(GetPlayer());
	Unit* pUnit = GetPlayer()->GetMapMgr()->GetVehicle(GET_LOWGUID_PART(guid));

	pPlayer->m_CurrentVehicle->RemovePassenger(pPlayer);
}

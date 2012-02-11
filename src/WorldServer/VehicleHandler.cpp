/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

/* This function handles the packet sent from the client when we
leave a vehicle, it removes us server side from our current
vehicle*/
void WorldSession::HandleVehicleDismiss(WorldPacket & recv_data)
{
	if(GetPlayer() == NULL || !GetPlayer()->m_CurrentVehicle)
		return;

	if(recv_data.rpos() != recv_data.wpos())
		HandleMovementOpcodes(recv_data);

	GetPlayer()->m_CurrentVehicle->RemovePassenger(GetPlayer());
}

/* This function handles the packet from the client which is
sent when we click on an npc with the flag UNIT_FLAG_SPELLCLICK
and checks if there is room for us then adds us as a passenger
to that vehicle*/
void WorldSession::HandleSpellClick( WorldPacket & recv_data )
{
	if (GetPlayer() == NULL || GetPlayer()->m_CurrentVehicle)
		return;

    CHECK_PACKET_SIZE(recv_data, 8);

    uint64 guid;
    recv_data >> guid;

	Vehicle* pVehicle = GetPlayer()->GetMapMgr()->GetVehicle(GET_LOWGUID_PART(guid));
	Unit* pPlayer = TO_UNIT(GetPlayer());

	if(!pVehicle)
		return;
	
	if(!pVehicle->GetMaxPassengerCount())
		return;

	if(!pVehicle->GetMaxSeat())
		return;

	// just in case.
	if( sEventMgr.HasEvent( pVehicle, EVENT_VEHICLE_SAFE_DELETE ) )
		return;

	if(pVehicle->HasPassenger(pPlayer))
		pVehicle->RemovePassenger(pPlayer);

	pVehicle->AddPassenger(pPlayer);
}

/* This function handles the packet sent from the client when we
change a seat on a vehicle. If the seat has a unit passenger and unit
is a vehicle, we will enter the passenger.*/
void WorldSession::HandleRequestSeatChange( WorldPacket & recv_data )
{
	WoWGuid Vehicleguid;
	uint8 RequestedSeat;

	if(recv_data.GetOpcode() == CMSG_REQUEST_VEHICLE_SWITCH_SEAT)
	{
		recv_data >> Vehicleguid;
		recv_data >> RequestedSeat;
	}
	else
	{
		HandleMovementOpcodes(recv_data);
		recv_data >> Vehicleguid;
		recv_data >> RequestedSeat;
	}

	uint64 guid = Vehicleguid.GetOldGuid();
	Vehicle* vehicle = GetPlayer()->GetMapMgr()->GetVehicle(GET_LOWGUID_PART(guid));

	if(vehicle = GetPlayer()->m_CurrentVehicle)
	{
		if(RequestedSeat == GetPlayer()->GetSeatID())
		{
			OUT_DEBUG("Return, Matching Seats. Requsted: %u, current: %u", RequestedSeat, GetPlayer()->GetSeatID());
			return;
		}
	}

	Unit* existpassenger = vehicle->GetPassenger(RequestedSeat);
	if(existpassenger && (existpassenger != GetPlayer()))
	{
		if(existpassenger->IsVehicle())
		{
			Vehicle* vehpassenger = TO_VEHICLE(existpassenger);
			if(vehpassenger->IsFull())
				return;
			else
				vehpassenger->AddPassenger(GetPlayer());
		}
		else
			return;
	}

	GetPlayer()->EnterVehicle(vehicle, RequestedSeat, false);
}

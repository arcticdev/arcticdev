/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _VEHICLE_H
#define _VEHICLE_H

enum VehiclePowerType
{
   POWER_STEAM  = 61,
   POWER_PYRITE = 41,
};

class SERVER_DECL Vehicle : public Creature
{
public:
	Vehicle(uint64 guid);
	~Vehicle();

	void InitSeats(uint32 vehicleEntry, Player* pRider = NULL);
	virtual void Update(uint32 time);
	bool Load(CreatureSpawn *spawn, uint32 mode, MapInfo *info);
	void Load(CreatureProto * proto_, float x, float y, float z, float o = 0.0f);
	void Despawn(uint32 delay, uint32 respawntime);
	void Remove();
	void SafeDelete();
	void MoveVehicle(float x, float y, float z, float o);
	void AddPassenger(Unit* pPassenger);
	void RemovePassenger(Unit* pPassenger);
	void RemoveAllPassengers();
	bool HasPassenger(Unit* pPassenger);
	void SendSpells(uint32 entry,uint8 slot, Player* plr);
	void setDeathState(DeathState s);
	void SetSpeed(PlayerSpeedType SpeedType, float value);

	//---------------------------------------
	// Accessors
	//---------------------------------------

	uint32 GetMaxPassengerCount() { return m_maxPassengers; }
	uint32 GetPassengerCount() { return m_passengerCount; }

	uint32 GetVehicleEntry() { return m_vehicleEntry; }
	void SetVehicleEntry(uint32 entry) { m_vehicleEntry = entry; }
	void SetVehiclePassenger(uint8 i, Unit* value) { m_passengers[i] = value; }	
	VehicleSeatEntry* GetVehicleSeatEntry(uint8 slot) { return m_vehicleSeats[slot]; } 

	Unit* GetControllingUnit() { return m_passengers[0]; }
	Unit* GetPassengerUnit(uint8 i) { return m_passengers[i]; }
	void SetControllingUnit(Unit* pUnit) { m_controllingUnit = pUnit; }

	uint8 GetPassengerSlot(Unit* pPassenger);

	//---------------------------------------
	// End accessors
	//---------------------------------------

	bool IsFull() { return m_passengerCount == m_maxPassengers; }

	
	bool Initialised;
	bool m_CreatedFromSpell;
	uint32 m_mountSpell;
	

protected:
	void _BuildMovementUpdate( ByteBuffer *data, Player* target );
	void _AddToSlot(Unit* pPassenger, uint8 slot);

	void SendMsgMoveTeleportAck( WorldPacket &data, Player* plr );
	void SendMonsterMoveTransport( Unit* pPassenger, uint8 slot );
	Unit* m_controllingUnit;

	Unit* m_passengers[8];
	uint8 m_passengerCount;
	uint8 m_maxPassengers;
	uint32 m_vehicleEntry;
	VehicleSeatEntry * m_vehicleSeats[8];
};

#endif
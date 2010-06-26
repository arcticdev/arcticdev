/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _VEHICLE_H
#define _VEHICLE_H

class SERVER_DECL Vehicle : public Creature
{
public:
	Vehicle(uint64 guid);
	~Vehicle();

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

	virtual void Destructor();

	void Init();
	void InitSeats(uint32 vehicleEntry, PlayerPointer pRider = NULLPLR);
	virtual void Update(uint32 time);
	bool Load(CreatureSpawn *spawn, uint32 mode, MapInfo *info);
	void Load(CreatureProto * proto_, float x, float y, float z, float o = 0.0f);
	void Despawn(uint32 delay, uint32 respawntime);
	void DeleteMe();
	void SafeDelete();
	void MoveVehicle(float x, float y, float z, float o);
	void AddPassenger(UnitPointer pPassenger);
	void RemovePassenger(UnitPointer pPassenger);
	bool HasPassenger(UnitPointer pPassenger);
	void SendSpells(uint32 entry, PlayerPointer plr);
	void setDeathState(DeathState s);
	void SetSpeed(uint8 SpeedType, float value);

	//---------------------------------------
	// Accessors
	//---------------------------------------
	
	uint32 GetMaxPassengerCount() { return m_maxPassengers; }
	uint32 GetPassengerCount() { return m_passengerCount; }

	uint32 GetVehicleEntry() { return m_vehicleEntry; }
	void SetVehicleEntry(uint32 entry) { m_vehicleEntry = entry; }

	UnitPointer GetControllingUnit() { return m_passengers[0]; }
	void SetControllingUnit(UnitPointer pUnit) { m_controllingUnit = pUnit; }

	uint8 GetPassengerSlot(UnitPointer pPassenger);
	
	//---------------------------------------
	// End accessors
	//---------------------------------------

	bool IsFull() { return m_passengerCount == m_maxPassengers; }

	VehicleSeatEntry * m_vehicleSeats[8];
	bool Initialised;
	bool m_CreatedFromSpell;
	uint32 m_mountSpell;

private:
	void _AddToSlot(UnitPointer pPassenger, uint8 slot);

protected:
	UnitPointer m_controllingUnit;

	UnitPointer m_passengers[8];

	uint8 m_passengerCount;
	uint8 m_maxPassengers;
	uint32 m_vehicleEntry;
};

#endif

/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

class SERVER_DECL Vehicle : public Creature
{
public:
	Vehicle(uint64 guid);
	~Vehicle();

	void Init();
	void InitSeats(uint32 vehicleEntry, Player* pRider = NULL);
	virtual void Update(uint32 time);
	bool Load(CreatureSpawn *spawn, uint32 mode, MapInfo *info);
	void Load(CreatureProto * proto_, float x, float y, float z, float o = 0.0f);
	void Despawn(uint32 delay, uint32 respawntime);
	void DeleteMe();
	void SafeDelete();
	void MoveVehicle(float x, float y, float z, float o);
	void AddPassenger(Unit* pPassenger);
	void AddPassenger(Unit* pPassenger, uint8 requestedseat, bool force = false);
	void RemovePassenger(Unit* pPassenger);
	bool HasPassenger(Unit* pPassenger);
	void SendSpells(uint32 entry, Player* plr);
	void setDeathState(DeathState s);
	void SetSpeed(uint8 SpeedType, float value);
	void ChangeSeats(Unit* pPassenger, uint8 seatid);

	//////////////////////////////////////////////////////////////////////////
	// Accessors                                                            //
	//////////////////////////////////////////////////////////////////////////

	uint32 GetMaxPassengerCount() { return m_maxPassengers; }
	uint32 GetPassengerCount() { return m_passengerCount; }

	uint32 GetVehicleEntry() { return m_vehicleEntry; }
	void SetVehicleEntry(uint32 entry) { m_vehicleEntry = entry; }

	Unit* GetControllingUnit() { return m_passengers[0]; }
	void SetControllingUnit(Unit* pUnit) { m_controllingUnit = pUnit; }

	int8 GetMaxSeat() { return m_seatSlotMax; }
	Unit* GetPassenger(uint8 seat)
	{
		if(seat >= 8)
			return NULL;

		return m_passengers[seat] ? m_passengers[seat] : NULL;
	}

	uint8 GetPassengerSlot(Unit* pPassenger);
	void InstallAccessories();

	//////////////////////////////////////////////////////////////////////////
	// End accessors                                                        //
	//////////////////////////////////////////////////////////////////////////

	bool IsFull() { return m_passengerCount >= m_maxPassengers; }

	VehicleSeatEntry* m_vehicleSeats[8];
	bool seatisusable[8];
	bool Initialised;
	bool m_CreatedFromSpell;
	uint32 m_mountSpell;

private:
	void _AddToSlot(Unit* pPassenger, uint8 slot);

protected:
	uint64 vehicleguid;
	Unit* m_controllingUnit;
	Unit* m_passengers[8];

	uint8 m_passengerCount;
	uint8 m_maxPassengers;
	int8 m_seatSlotMax;
	uint32 m_vehicleEntry;
};

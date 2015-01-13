/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2014 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

enum VehicleFlags
{
	VEHICLE_FLAG_NO_STRAFE						= 0x00000001, // Sets MOVEFLAG2_NO_STRAFE
	VEHICLE_FLAG_NO_JUMPING						= 0x00000002, // Sets MOVEFLAG2_NO_JUMPING
	VEHICLE_FLAG_FULLSPEEDTURNING				= 0x00000004, // Sets MOVEFLAG2_FULLSPEEDTURNING
	VEHICLE_FLAG_ALLOW_PITCHING					= 0x00000010, // Sets MOVEFLAG2_ALLOW_PITCHING
	VEHICLE_FLAG_FULLSPEEDPITCHING				= 0x00000020, // Sets MOVEFLAG2_FULLSPEEDPITCHING
	VEHICLE_FLAG_CUSTOM_PITCH					= 0x00000040, // If set use pitchMin and pitchMax from DBC, otherwise pitchMin = -pi/2, pitchMax = pi/2
	VEHICLE_FLAG_ADJUST_AIM_ANGLE				= 0x00000400, // Lua_IsVehicleAimAngleAdjustable
	VEHICLE_FLAG_ADJUST_AIM_POWER				= 0x00000800, // Lua_IsVehicleAimPowerAdjustable
};

enum VehicleSeatFlags
{
	VEHICLE_SEAT_FLAG_HIDE_PASSENGER			= 0x00000200, // Passenger is hidden
	VEHICLE_SEAT_FLAG_UNK11						= 0x00000400, // needed for CGCamera__SyncFreeLookFacing
	VEHICLE_SEAT_FLAG_CAN_CONTROL				= 0x00000800, // Lua_UnitInVehicleControlSeat
	VEHICLE_SEAT_FLAG_CAN_ATTACK				= 0x00004000, // Can attack, cast spells and use items from vehicle?
	VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT			= 0x02000000, // Lua_CanExitVehicle - can enter and exit at free will
	VEHICLE_SEAT_FLAG_CAN_SWITCH				= 0x04000000, // Lua_CanSwitchVehicleSeats
	VEHICLE_SEAT_FLAG_CAN_CAST					= 0x20000000, // Lua_UnitHasVehicleUI
};

enum VehicleSeatFlagsB
{
	VEHICLE_SEAT_FLAG_B_NONE					= 0x00000000,
	VEHICLE_SEAT_FLAG_B_USABLE_FORCED			= 0x00000002,
	VEHICLE_SEAT_FLAG_B_TARGETS_IN_RAIDUI		= 0x00000008, // Lua_UnitTargetsVehicleInRaidUI
	VEHICLE_SEAT_FLAG_B_EJECTABLE				= 0x00000020, // ejectable
	VEHICLE_SEAT_FLAG_B_USABLE_FORCED_2			= 0x00000040,
	VEHICLE_SEAT_FLAG_B_USABLE_FORCED_3			= 0x00000100,
	VEHICLE_SEAT_FLAG_B_CANSWITCH				= 0x04000000, // can switch seats
	VEHICLE_SEAT_FLAG_B_VEHICLE_PLAYERFRAME_UI	= 0x80000000, // Lua_UnitHasVehiclePlayerFrameUI - actually checked for flagsb &~ 0x80000000
};

class SERVER_DECL Vehicle : public Creature
{
public:
	Vehicle(uint64 guid);
	~Vehicle();
	virtual void Destructor();

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

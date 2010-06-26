/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */
 
#ifndef _OBJECT_H
#define _OBJECT_H

#include "LootMgr.h"

class Unit;
class Spell;
class Aura;
class DynamicObject;

enum HIGHGUID_TYPE
{
	HIGHGUID_TYPE_VEHICLE			= 0xF1500000,
	HIGHGUID_TYPE_UNIT				= 0xF1300000,
	HIGHGUID_TYPE_PET				= 0xF1400000,
	HIGHGUID_TYPE_GAMEOBJECT		= 0xF1100000,
	HIGHGUID_TYPE_ITEM				= 0x40000000,
	HIGHGUID_TYPE_CONTAINER			= 0x50000000,			// confirm this pl0x
	HIGHGUID_TYPE_PLAYER			= 0x00000000,
	HIGHGUID_TYPE_DYNAMICOBJECT		= 0x60000000,
	HIGHGUID_TYPE_TRANSPORTER		= 0x1FC00000,
	HIGHGUID_TYPE_WAYPOINT			= 0x10000000,
	HIGHGUID_TYPE_CORPSE			= 0x30000000,
	HIGHGUID_TYPE_MASK				= 0xFFF00000,
	LOWGUID_ENTRY_MASK				= 0x00FFFFFF,
};

#define GET_TYPE_FROM_GUID(x) (GUID_HIPART((x)) & HIGHGUID_TYPE_MASK)
#define GET_LOWGUID_PART(x) (GUID_LOPART((x)) & LOWGUID_ENTRY_MASK)

// TODO: fix that type mess

enum TYPE 
{
	TYPE_OBJECT		    = 1,
	TYPE_ITEM		    = 2,
	TYPE_CONTAINER	    = 4,
	TYPE_UNIT		    = 8,
	TYPE_PLAYER		    = 16,
	TYPE_GAMEOBJECT	    = 32,
	TYPE_DYNAMICOBJECT  = 64,
	TYPE_CORPSE		    = 128,
	TYPE_AIGROUP		= 256,
	TYPE_AREATRIGGER	= 512,
};

enum TYPEID 
{
	TYPEID_OBJECT		 = 0,  // +
	TYPEID_ITEM		     = 1,  // +
	TYPEID_CONTAINER	 = 2,  // +
	TYPEID_UNIT		     = 3,  // +
	TYPEID_PLAYER		 = 4,  // +
	TYPEID_GAMEOBJECT	 = 5,  // +
	TYPEID_DYNAMICOBJECT = 6,  // +
	TYPEID_CORPSE		 = 7,  // +
	TYPEID_AIGROUP	     = 8,  // +
	TYPEID_AREATRIGGER   = 9,  // +
	TYPEID_UNUSED		 = 10, // + used to signal invalid reference (object dealocated but someone is still using it)
};

enum OBJECT_UPDATE_TYPE 
{
	UPDATETYPE_VALUES = 0,
	//  8 bytes - GUID
	//  Goto Update Block
	UPDATETYPE_MOVEMENT = 1,
	//  8 bytes - GUID
	//  Goto Position Update
	UPDATETYPE_CREATE_OBJECT = 2,
	//  8 bytes - GUID
	//  1 byte - Object Type (*)
	//  Goto Position Update
	//  Goto Update Block
	UPDATETYPE_CREATE_YOURSELF = 3, // looks like 3 & 4 do the same thing
	//  4 bytes - Count
	//  Loop Count Times:
	//  8 bytes - GUID
	UPDATETYPE_OUT_OF_RANGE_OBJECTS = 4, // <- this is correct, not sure about 3
	//  4 bytes - Count
	//  Loop Count Times:
	//  8 bytes - GUID

	UPDATETYPE_NEAR_OBJECTS = 5,
	//  4 bytes - Count
	//  Loop Count Times:
	//  8 bytes - GUID
};

typedef struct
{ 
	uint32 school_type;
	int32 full_damage;
	uint32 resisted_damage;
} dealdamage;

enum PHASEMODE
{
	ALL_PHASES = -1,
	PHASE_1,
	PHASE_2,
	PHASE_3, // should be enough for the emulator to know about, but we can have more :P
};

class WorldPacket;
class ByteBuffer;
class WorldSession;
class Player;
class MapCell;
class MapMgr;

//////////////////////////////////////////////////////////////////////
//  Object
//  Base object for every item, unit, player, corpse, container, etc
//////////////////////////////////////////////////////////////////////
class SERVER_DECL Object : public EventableObject, public std::tr1::enable_shared_from_this<Object>
{
public:
	typedef unordered_set< ObjectPointer > InRangeSet;
	typedef std::map<string, void*> ExtensionSet;

	virtual ~Object ( );
	virtual void Destructor();
	virtual void Init();

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

	virtual void Update ( uint32 time ) { }
  // True if object exists in world
 
	
	ARCTIC_INLINE bool IsInWorld() { return m_mapMgr != NULL; }
	virtual void AddToWorld();
	virtual void AddToWorld(MapMgrPointer pMapMgr);
	void PushToWorld(MapMgrPointer );
	virtual void OnPushToWorld() { }
	virtual void OnPrePushToWorld() { }
	virtual void RemoveFromWorld(bool free_guid);

	ARCTIC_INLINE void ObjLock() { m_objlock.Acquire(); }
	ARCTIC_INLINE void ObjUnlock() { m_objlock.Release(); }

	// guid always comes first
	ARCTIC_INLINE const uint64& GetGUID() const { return *((uint64*)m_uint32Values); }
	ARCTIC_INLINE const WoWGuid& GetNewGUID() const { return m_wowGuid; }
	ARCTIC_INLINE uint32 GetEntry(){return m_uint32Values[OBJECT_FIELD_ENTRY];}
	
	ARCTIC_INLINE const uint32 GetEntryFromGUID() const	{ return uint32( (*(uint64*)m_uint32Values >> 24) & 0xFFFFFFFF ); }
	ARCTIC_INLINE const uint32 GetTypeFromGUID() const { return (m_uint32Values[1] & HIGHGUID_TYPE_MASK); }
	ARCTIC_INLINE const uint32 GetUIdFromGUID() const { return (m_uint32Values[0] & LOWGUID_ENTRY_MASK); }
	ARCTIC_INLINE const uint32 GetLowGUID() const { return (m_uint32Values[0]); }

	// type
	bool m_isVehicle;
	ARCTIC_INLINE const uint8& GetTypeId() const { return m_objectTypeId; }
	ARCTIC_INLINE bool IsUnit()	{ return ( m_objectTypeId == TYPEID_UNIT || m_objectTypeId == TYPEID_PLAYER ); }
	ARCTIC_INLINE bool IsPlayer() { return m_objectTypeId == TYPEID_PLAYER; }
	ARCTIC_INLINE bool IsCreature() { return m_objectTypeId == TYPEID_UNIT; }
	ARCTIC_INLINE bool IsVehicle() { return m_isVehicle; }
	ARCTIC_INLINE bool IsGameObject() { return m_objectTypeId == TYPEID_GAMEOBJECT; }
	bool IsPet();
	bool IsGiveXPorHonor(PlayerPointer plr, UnitPointer Target);

	// This includes any nested objects we have, inventory for example.
	virtual uint32 __fastcall BuildCreateUpdateBlockForPlayer( ByteBuffer *data, PlayerPointer target );
	uint32 __fastcall BuildValuesUpdateBlockForPlayer( ByteBuffer *buf, PlayerPointer target );
	uint32 __fastcall BuildValuesUpdateBlockForPlayer( ByteBuffer * buf, UpdateMask * mask );
	uint32 __fastcall BuildOutOfRangeUpdateBlock( ByteBuffer *buf );

	WorldPacket* BuildFieldUpdatePacket(uint32 index,uint32 value);
	void BuildFieldUpdatePacket(PlayerPointer Target, uint32 Index, uint32 Value);
	void BuildFieldUpdatePacket(ByteBuffer * buf, uint32 Index, uint32 Value);

	void DealDamage(UnitPointer pVictim, uint32 damage, uint32 targetEvent, uint32 unitEvent, uint32 spellId);
	

	virtual void DestroyForPlayer( PlayerPointer target ) const;

	void BuildHeartBeatMsg( WorldPacket *data ) const;
	WorldPacket * BuildTeleportAckMsg( const LocationVector & v);
	bool IsBeingTeleported() { return mSemaphoreTeleport; }
	void SetSemaphoreTeleport(bool semphsetting) { mSemaphoreTeleport = semphsetting; }

	bool SetPosition( float newX, float newY, float newZ, float newOrientation, bool allowPorting = false );
	bool SetPosition( const LocationVector & v, bool allowPorting = false);
	void SetRotation( uint64 guid );

	void CastSpell(ObjectPointer Target, SpellEntry* Sp, bool triggered);
	void CastSpell(ObjectPointer Target, uint32 SpellID, bool triggered);
	void CastSpell(uint64 targetGuid, SpellEntry* Sp, bool triggered);
	void CastSpell(uint64 targetGuid, uint32 SpellID, bool triggered);

	ARCTIC_INLINE const float& GetPositionX( ) const { return m_position.x; }
	ARCTIC_INLINE const float& GetPositionY( ) const { return m_position.y; }
	ARCTIC_INLINE const float& GetPositionZ( ) const { return m_position.z; }
	ARCTIC_INLINE const float& GetOrientation( ) const { return m_position.o; }
	ARCTIC_INLINE void SetOrientation( float &o ) { m_position.o = o; }

	ARCTIC_INLINE const float& GetSpawnX( ) const { return m_spawnLocation.x; }
	ARCTIC_INLINE const float& GetSpawnY( ) const { return m_spawnLocation.y; }
	ARCTIC_INLINE const float& GetSpawnZ( ) const { return m_spawnLocation.z; }
	ARCTIC_INLINE const float& GetSpawnO( ) const { return m_spawnLocation.o; }
	ARCTIC_INLINE void SetSpawnX(float x) { m_spawnLocation.x = x; }
	ARCTIC_INLINE void SetSpawnY(float y) { m_spawnLocation.y = y; }
	ARCTIC_INLINE void SetSpawnZ(float z) { m_spawnLocation.z = z; }
	ARCTIC_INLINE void SetSpawnO(float o) { m_spawnLocation.o = o; }

	ARCTIC_INLINE const LocationVector & GetPosition() { return m_position; }
	ARCTIC_INLINE LocationVector & GetPositionNC() { return m_position; }
	ARCTIC_INLINE LocationVector * GetPositionV() { return &m_position; }

	//Distance Calculation
	float CalcDistance(ObjectPointer Ob);
	float CalcDistance(float ObX, float ObY, float ObZ);
	float CalcDistance(ObjectPointer Oa, ObjectPointer Ob);
	float CalcDistance(ObjectPointer Oa, float ObX, float ObY, float ObZ);
	float CalcDistance(float OaX, float OaY, float OaZ, float ObX, float ObY, float ObZ);

	// Only for MapMgr use
	ARCTIC_INLINE MapCell* GetMapCell() const { return m_mapCell; }
	// Only for MapMgr use
	ARCTIC_INLINE void SetMapCell(MapCell* cell) { m_mapCell = cell; }
	// Only for MapMgr use
	ARCTIC_INLINE MapMgrPointer GetMapMgr() const { return m_mapMgr; }

	ARCTIC_INLINE void SetMapId(uint32 newMap) { m_mapId = newMap; }
	void SetZoneId(uint32 newZone);

	ARCTIC_INLINE const uint32 GetMapId( ) const { return m_mapId; }
	ARCTIC_INLINE const uint32& GetZoneId( ) const { return m_zoneId; }

	// Get uint32 property
	ARCTIC_INLINE const uint32& GetUInt32Value( uint32 index ) const { return m_uint32Values[ index ]; }

	// Get uint64 property
	ARCTIC_INLINE const uint64& GetUInt64Value( uint32 index ) const { return *((uint64*)&(m_uint32Values[ index ])); }

	// Get float property
	ARCTIC_INLINE const float& GetFloatValue( uint32 index ) const { return m_floatValues[ index ]; }

	void __fastcall ModFloatValue(const uint32 index, const float value );
	void ModSignedInt32Value(uint32 index, int32 value);
	void ModUnsigned32Value(uint32 index, int32 mod);
	uint32 GetModPUInt32Value(const uint32 index, const int32 value);

	// Set uint32 property
	void SetByte(uint32 index, uint32 index1,uint8 value);

	ARCTIC_INLINE uint8 GetByte(uint32 i,uint32 i1) { return ((uint8*)m_uint32Values)[i*4+i1]; }
	
	ARCTIC_INLINE void SetNewGuid(uint32 Guid)
	{
		uint64 new_full_guid = Guid;
		if( m_objectTypeId == TYPEID_GAMEOBJECT )
			new_full_guid |= ((uint64)GetEntry() << 24) | ((uint64)HIGHGUID_TYPE_GAMEOBJECT << 32);

		if( m_objectTypeId == TYPEID_UNIT )
			new_full_guid |= ((uint64)GetEntry() << 24) | ((uint64)HIGHGUID_TYPE_UNIT << 32);

		SetUInt64Value(OBJECT_FIELD_GUID, new_full_guid);
		m_wowGuid.Init(GetGUID());
	}

	void EventSetUInt32Value(uint32 index, uint32 value);
	void __fastcall SetUInt32Value( const uint32 index, const uint32 value );

	// Set uint64 property
	void __fastcall SetUInt64Value( const uint32 index, const uint64 value );

	// Set float property
	void __fastcall SetFloatValue( const uint32 index, const float value );

	void __fastcall SetFlag( const uint32 index, uint32 newFlag );

	void __fastcall RemoveFlag( const uint32 index, uint32 oldFlag );

	void __fastcall SetByteFlag( const uint32 index, const uint32 flag, uint8 newFlag);
	bool __fastcall HasByteFlag( const uint32 index, const uint32 flag, uint8 checkFlag);
	void __fastcall RemoveByteFlag(const uint32 index, const uint32 flag, uint8 checkFlag);

	ARCTIC_INLINE bool HasFlag( const uint32 index, uint32 flag ) const { return (m_uint32Values[ index ] & flag) != 0;	}

	void ClearUpdateMask( )
	{
		m_updateMask.Clear();
		m_objectUpdated = false;
	}

	bool HasUpdateField(uint32 index) { return m_updateMask.GetBit(index); }

	//use it to check if a object is in range of another
	bool isInRange(ObjectPointer target, float range);

	// Use it to Check if a object is in front of another one
	bool isInFront(ObjectPointer target);
	bool isInBack(ObjectPointer target);
	
	// Check to see if an object is in front of a target in a specified arc (in degrees)
	bool isInArc(ObjectPointer target , float degrees); 

	// Calculates the angle between two Positions.
	float calcAngle( float Position1X, float Position1Y, float Position2X, float Position2Y );
	float calcRadAngle( float Position1X, float Position1Y, float Position2X, float Position2Y );

	// converts to 360 > x > 0..
	float getEasyAngle( float angle );

	ARCTIC_INLINE const float GetDistanceSq(ObjectPointer obj)
	{
		if(obj->GetMapId() != m_mapId) return 40000.0f; //enough for out of range
		return m_position.DistanceSq(obj->GetPosition());
	}

	ARCTIC_INLINE float GetDistanceSq(LocationVector & comp)
	{
		return comp.DistanceSq(m_position);
	}

	ARCTIC_INLINE float CalcDistance(LocationVector & comp)
	{
		return comp.Distance(m_position);
	}

	ARCTIC_INLINE const float GetDistanceSq(float x, float y, float z)
	{
		return m_position.DistanceSq(x, y, z);
	}

	ARCTIC_INLINE const float GetDistance2dSq( ObjectPointer obj )
	{
		if( obj->GetMapId() != m_mapId )
			return 40000.0f; // enough for out of range
		return m_position.Distance2DSq( obj->m_position );
	}

	ARCTIC_INLINE float GetDistance2dSq(float x, float y)
	{
		return m_position.Distance2DSq( x, y );
	}


	// In-range object management, not sure if we need it
	ARCTIC_INLINE bool IsInRangeSet( ObjectPointer pObj )
	{
		return !( m_objectsInRange.find( pObj ) == m_objectsInRange.end() );
	}
	
	virtual void AddInRangeObject(ObjectPointer pObj)
	{
		if( pObj == NULL )
			return;

		m_objectsInRange.insert( pObj );

		if( pObj->GetTypeId() == TYPEID_PLAYER )
			m_inRangePlayers.insert( TO_PLAYER(pObj) );
	}

	ARCTIC_INLINE void RemoveInRangeObject( ObjectPointer pObj )
	{
		if( pObj == NULL )
			return;

		OnRemoveInRangeObject( pObj );
		m_objectsInRange.erase( pObj );
	}

	ARCTIC_INLINE bool HasInRangeObjects()
	{
		return ( m_objectsInRange.size() > 0 );
	}

	virtual void OnRemoveInRangeObject( ObjectPointer pObj )
	{
		if( pObj->GetTypeId() == TYPEID_PLAYER )
			m_inRangePlayers.erase( TO_PLAYER(pObj) );
	}

	virtual void ClearInRangeSet()
	{
		m_objectsInRange.clear();
		m_inRangePlayers.clear();
		m_oppFactsInRange.clear();
	}

	ARCTIC_INLINE size_t GetInRangeCount() { return m_objectsInRange.size(); }
	ARCTIC_INLINE size_t GetInRangePlayersCount() { return m_inRangePlayers.size();}
	ARCTIC_INLINE InRangeSet::iterator GetInRangeSetBegin() { return m_objectsInRange.begin(); }
	ARCTIC_INLINE InRangeSet::iterator GetInRangeSetEnd() { return m_objectsInRange.end(); }
	ARCTIC_INLINE InRangeSet::iterator FindInRangeSet(ObjectPointer obj) { return m_objectsInRange.find(obj); }

	void RemoveInRangeObject(InRangeSet::iterator itr)
	{ 
		OnRemoveInRangeObject(*itr);
		m_objectsInRange.erase(itr);
	}

	ARCTIC_INLINE bool RemoveIfInRange( ObjectPointer obj )
	{
		InRangeSet::iterator itr = m_objectsInRange.find(obj);
		if( obj->GetTypeId() == TYPEID_PLAYER )
			m_inRangePlayers.erase( TO_PLAYER(obj) );

		if( itr == m_objectsInRange.end() )
			return false;
		
		m_objectsInRange.erase( itr );
		return true;
	}

	ARCTIC_INLINE void AddInRangePlayer( ObjectPointer obj )
	{
		m_inRangePlayers.insert( TO_PLAYER(obj) );
	}

	ARCTIC_INLINE void RemoveInRangePlayer( ObjectPointer obj )
	{
		m_inRangePlayers.erase( TO_PLAYER(obj) );
	}

	bool IsInRangeOppFactSet(ObjectPointer pObj) { return (m_oppFactsInRange.count(pObj) > 0); }
	void UpdateOppFactionSet();
	ARCTIC_INLINE unordered_set<ObjectPointer >::iterator GetInRangeOppFactsSetBegin() { return m_oppFactsInRange.begin(); }
	ARCTIC_INLINE unordered_set<ObjectPointer >::iterator GetInRangeOppFactsSetEnd() { return m_oppFactsInRange.end(); }
	ARCTIC_INLINE unordered_set<PlayerPointer  >::iterator GetInRangePlayerSetBegin() { return m_inRangePlayers.begin(); }
	ARCTIC_INLINE unordered_set<PlayerPointer  >::iterator GetInRangePlayerSetEnd() { return m_inRangePlayers.end(); }
	ARCTIC_INLINE unordered_set<PlayerPointer  > * GetInRangePlayerSet() { return &m_inRangePlayers; };

	void __fastcall SendMessageToSet(WorldPacket *data, bool self,bool myteam_only=false);
	ARCTIC_INLINE void SendMessageToSet(StackPacket * data, bool self) { OutPacketToSet(data->GetOpcode(), (uint16)data->GetSize(), data->GetBufferPointer(), self); }
	void OutPacketToSet(uint16 Opcode, uint16 Len, const void * Data, bool self);

	// Fill values with data from a space seperated string of uint32s.
	void LoadValues(const char* data);

	ARCTIC_INLINE uint16 GetValuesCount() const { return m_valuesCount; }

	// Blizzard seem to send those for all object types. weird.
	float m_walkSpeed;
	float m_runSpeed;
	float m_backWalkSpeed;
	float m_swimSpeed;
	float m_backSwimSpeed;
	float m_turnRate;
	float m_flySpeed;
	float m_backFlySpeed;

	float m_base_runSpeed;
	float m_base_walkSpeed;

	void SpellNonMeleeDamageLog(UnitPointer pVictim, uint32 spellID, uint32 damage, bool allowProc, bool static_damage = false, bool no_remove_auras = false, uint32 AdditionalCritChance = 0);
	
	///////////////////////////////////////////////////////////////////////////////////////////
	// SpellLog packets just to keep the code cleaner and better to read                     //
	///////////////////////////////////////////////////////////////////////////////////////////
	void SendSpellLog(ObjectPointer Caster, ObjectPointer Target,uint32 Ability, uint8 SpellLogType);
	void SendSpellNonMeleeDamageLog( ObjectPointer Caster, UnitPointer Target, uint32 SpellID, uint32 Damage, uint8 School, uint32 AbsorbedDamage, uint32 ResistedDamage, bool PhysicalDamage, uint32 BlockedDamage, bool CriticalHit, bool bToSet );
	void SendAttackerStateUpdate( UnitPointer Target, dealdamage *dmg, uint32 realdamage, uint32 abs, uint32 blocked_damage, uint32 hit_status, uint32 vstate );

	// Dynamic objects
	DynamicObjectPointer dynObj;

	// object faction
	void _setFaction();
	uint32 _getFaction(){return m_faction->Faction;}
	
	FactionTemplateDBC *m_faction;
	FactionDBC *m_factionDBC;

	ARCTIC_INLINE void SetInstanceID(int32 instance) { m_instanceId = instance; }
	ARCTIC_INLINE int32 GetInstanceID() { return m_instanceId; }

	int32 event_GetInstanceID();

	bool Active;
	bool CanActivate();
	void Activate(MapMgrPointer mgr);
	void Deactivate(MapMgrPointer mgr);
	bool m_inQueue;
	ARCTIC_INLINE void SetMapMgr(MapMgrPointer mgr) { m_mapMgr = mgr; }

	void Delete()
	{
		if(IsInWorld())
			RemoveFromWorld(true);
		Destructor();
	}

	ARCTIC_INLINE size_t GetInRangeOppFactCount() { return m_oppFactsInRange.size(); }
	void PlaySoundToSet(uint32 sound_entry);
	void EventSpellHit(SpellPointer pSpell);

	bool PhasedCanInteract(ObjectPointer pObj);
	bool HasPhase() { return m_phaseMode != 0; }
	void EnablePhase(int32 phaseMode);
	void DisablePhase(int32 phaseMode);
	void SetPhase(int32 phase); // Don't fucking use this.

	AuraPointer m_phaseAura;

protected:
	Object (  );

	// void _Create (uint32 guidlow, uint32 guidhigh);
	void _Create( uint32 mapid, float x, float y, float z, float ang);

	// Mark values that need updating for specified player.
	virtual void _SetUpdateBits(UpdateMask *updateMask, PlayerPointer target) const;
	// Mark values that player should get when he/she/it sees object for first time.
	virtual void _SetCreateBits(UpdateMask *updateMask, PlayerPointer target) const;

	void _BuildMovementUpdate( ByteBuffer *data, uint16 flags, uint32 flags2, PlayerPointer target );
	void _BuildValuesUpdate( ByteBuffer *data, UpdateMask *updateMask, PlayerPointer target );

	/* Main Function called by isInFront(); */
	bool inArc(float Position1X, float Position1Y, float FOV, float Orientation, float Position2X, float Position2Y );

	int32 m_phaseMode;
	int32 m_phaseMapId; // -1 = Disregard?
	LocationVector m_phaseLocation;
	uint32 m_phaseDistanceLimit;

	Mutex m_objlock;

	// WoWGuid class
	WoWGuid m_wowGuid;

	 // Type id.
	uint8 m_objectTypeId;

	// Zone id.
	uint32 m_zoneId;
	// Continent/map id.
	uint32 m_mapId;
	// Map manager
	MapMgrPointer m_mapMgr;
	// Current map cell
	MapCell *m_mapCell;

	LocationVector m_position;
	LocationVector m_lastMapUpdatePosition;
	LocationVector m_spawnLocation;

	// Semaphores - needed to forbid two operations on the same object at the same very time (may cause crashing\lack of data)
	bool mSemaphoreTeleport;

	// Object properties.
	union {
		uint32* m_uint32Values;
		float* m_floatValues;
	};

	// Number of properties
	uint32 m_valuesCount;

	// List of object properties that need updating.
	UpdateMask m_updateMask;

	// True if object was updated
	bool m_objectUpdated;

	// Set of Objects in range.
	// TODO: that functionality should be moved into WorldServer.
	unordered_set<ObjectPointer > m_objectsInRange;
	unordered_set<PlayerPointer > m_inRangePlayers;
	unordered_set<ObjectPointer > m_oppFactsInRange;
   
	int32 m_instanceId;

	ExtensionSet * m_extensions;
	void _SetExtension(const string& name, void* ptr);		// so we can set from scripts. :)

	bool m_sharedPtrDestructed;

public:

	template<typename T>
		void SetExtension(const string& name, T ptr)
	{
		_SetExtension(name, ((void*)ptr));
	}

	template<typename T>
		T GetExtension(const string& name)
	{
		if( m_extensions == NULL )
			return ((T)NULL);
		else
		{
			ExtensionSet::iterator itr = m_extensions->find( name );
			if( itr == m_extensions->end() )
				return ((T)NULL);
			else
				return ((T)itr->second);
		}
	}

	bool m_loadedFromDB;

	//////////////////////////////////////////////////////////////////////////
	// ACCESSOR FUNCTIONS                                                   //
	//////////////////////////////////////////////////////////////////////////
	// Stats
	ARCTIC_INLINE uint32 GetStrength() { return m_uint32Values[UNIT_FIELD_STRENGTH]; }
	ARCTIC_INLINE uint32 GetAgility() { return m_uint32Values[UNIT_FIELD_AGILITY]; }
	ARCTIC_INLINE uint32 GetStamina() { return m_uint32Values[UNIT_FIELD_STAMINA]; }
	ARCTIC_INLINE uint32 GetIntellect() { return m_uint32Values[UNIT_FIELD_INTELLECT]; }
	ARCTIC_INLINE uint32 GetSpirit() { return m_uint32Values[UNIT_FIELD_SPIRIT]; }

	// Health
	ARCTIC_INLINE uint32 GetHealth() { return m_uint32Values[UNIT_FIELD_HEALTH]; }
	ARCTIC_INLINE uint32 GetMaxHealth() { return m_uint32Values[UNIT_FIELD_MAXHEALTH]; }

	bool IsInLineOfSight(ObjectPointer pObj);
	int32 GetSpellBaseCost(SpellEntry *sp);

	//////////////////////////////////////////////////////////////////////////
	// END ACCESSOR FUNCTIONS                                               //
	//////////////////////////////////////////////////////////////////////////

	// declaration to fix scripting
	ARCTIC_INLINE Loot* GetLoot() { return &m_loot; }

public:
	// loooooot
	Loot m_loot;
	bool m_looted;

	// empties loot vector
	void ClearLoot();
};

#endif


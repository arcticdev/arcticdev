/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#pragma once

#include "Pathfinding/Detour/DetourNavMesh.h"

class MapCell;
class Map;
class Object;
class MapScriptInterface;
class WorldSession;
class GameObject;
class Creature;
class Player;
class Pet;
class Vehicle;
class Transporter;
class Corpse;
class CBattleground;
class Instance;
class InstanceScript;

typedef unordered_set<Object*> ObjectSet;
typedef unordered_set<Object*> UpdateQueue;
typedef unordered_set<Player*> PUpdateQueue;
typedef unordered_set<Player*> PlayerSet;
typedef HM_NAMESPACE::hash_map<uint32, Object*> StorageMap;
typedef unordered_set<uint64> CombatProgressMap;
typedef unordered_set<Vehicle*> VehicleSet;
typedef unordered_set<Creature*> CreatureSet;
typedef unordered_set<GameObject*> GameObjectSet;
typedef HM_NAMESPACE::hash_map<uint32, Vehicle*> VehicleSqlIdMap;
typedef HM_NAMESPACE::hash_map<uint32, Creature*> CreatureSqlIdMap;
typedef HM_NAMESPACE::hash_map<uint32, GameObject*> GameObjectSqlIdMap;

#define MAX_TRANSPORTERS_PER_MAP 25
#define RESERVE_EXPAND_SIZE 1024

class Transporter;

#define CALL_INSTANCE_SCRIPT_EVENT( Mgr, Func ) if ( Mgr != NULL && Mgr->GetScript() != NULL ) Mgr->GetScript()->Func

class SERVER_DECL MapMgr : public CellHandler <MapCell>, public EventableObject,public ThreadContext
{
	friend class UpdateObjectThread;
	friend class ObjectUpdaterThread;
	friend class MapCell;
	friend class MapScriptInterface;

public:
	// This will be done in regular way soon
	Mutex m_objectinsertlock;
	ObjectSet m_objectinsertpool;
	void AddObject(Object*);

	//////////////////////////////////////////////////////////////////////////
	// Local (mapmgr) storage/generation of GameObjects                     //
	//////////////////////////////////////////////////////////////////////////

	typedef HM_NAMESPACE::hash_map<const uint32, GameObject* > GameObjectMap;
	GameObjectMap m_gameObjectStorage;
	uint32 m_GOHighGuid;
	GameObject* CreateGameObject(uint32 entry);

	ARCTIC_INLINE const uint32 GenerateGameobjectGuid()
	{
		m_GOHighGuid &= 0x00FFFFFF;
		return ++m_GOHighGuid;
	}

	ARCTIC_INLINE GameObject* GetGameObject(const uint32 guid)
	{
		GameObjectMap::iterator itr = m_gameObjectStorage.find(guid);
		return (itr != m_gameObjectStorage.end()) ? m_gameObjectStorage[guid] : NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	// Local (mapmgr) storage/generation of Vehicles                        //
	//////////////////////////////////////////////////////////////////////////

	uint32 m_VehicleArraySize;
	uint32 m_VehicleHighGuid;
	HM_NAMESPACE::unordered_map<const uint32,Vehicle*> m_VehicleStorage;
	Vehicle* CreateVehicle(uint32 entry);

	__inline Vehicle* GetVehicle(const uint32 guid)
	{
		return guid <= m_VehicleHighGuid ? m_VehicleStorage[guid] : NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	// Local (mapmgr) storage/generation of Creatures                       //
	//////////////////////////////////////////////////////////////////////////

	uint32 m_CreatureArraySize;
	uint32 m_CreatureHighGuid;
	HM_NAMESPACE::unordered_map<const uint32,Creature*> m_CreatureStorage;
	Creature* CreateCreature(uint32 entry);

	__inline Creature* GetCreature(const uint32 guid)
	{
		return guid <= m_CreatureHighGuid ? m_CreatureStorage[guid] : NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	// Local (mapmgr) storage/generation of DynamicObjects                  //
	//////////////////////////////////////////////////////////////////////////

	uint32 m_DynamicObjectHighGuid;
	typedef HM_NAMESPACE::hash_map<const uint32, DynamicObject*> DynamicObjectStorageMap;
	DynamicObjectStorageMap m_DynamicObjectStorage;
	DynamicObject* CreateDynamicObject();

	ARCTIC_INLINE DynamicObject* GetDynamicObject(const uint32 guid)
	{
		DynamicObjectStorageMap::iterator itr = m_DynamicObjectStorage.find(guid);
		return (itr != m_DynamicObjectStorage.end()) ? m_DynamicObjectStorage[guid] : NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	// Local (mapmgr) storage of pets                                       //
	//////////////////////////////////////////////////////////////////////////

	typedef HM_NAMESPACE::hash_map<const uint32, Pet*> PetStorageMap;
	PetStorageMap m_PetStorage;
	__inline Pet* GetPet(const uint32 guid)
	{
		PetStorageMap::iterator itr = m_PetStorage.find(guid);
		return (itr != m_PetStorage.end()) ? m_PetStorage[guid] : NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	// Local (mapmgr) storage of players for faster lookup                  //
	//////////////////////////////////////////////////////////////////////////

    // double typedef lolz// a compile breaker..
	typedef HM_NAMESPACE::hash_map<const uint32, Player*> PlayerStorageMap;

	PlayerStorageMap m_PlayerStorage;
	__inline Player* GetPlayer(const uint32 guid)
	{
		PlayerStorageMap::iterator itr = m_PlayerStorage.find(guid);
		return (itr != m_PlayerStorage.end()) ? m_PlayerStorage[guid] : NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	// Local (mapmgr) storage of combats in progress                        //
	//////////////////////////////////////////////////////////////////////////

	CombatProgressMap _combatProgress;
	void AddCombatInProgress(uint64 guid)
	{
		_combatProgress.insert(guid);
	}
	void RemoveCombatInProgress(uint64 guid)
	{
		_combatProgress.erase(guid);
	}
	ARCTIC_INLINE bool IsCombatInProgress()
	{
		// temporary disabled until AI updates list correctly.
		return false;

		//if all players are out, list should be empty.
		if(!HasPlayers())
			_combatProgress.clear();
		return (_combatProgress.size() > 0);
	}

	//////////////////////////////////////////////////////////////////////////
	// Lookup Wrappers                                                      //
	//////////////////////////////////////////////////////////////////////////

	Unit* GetUnit(const uint64 & guid);
	Object* _GetObject(const uint64 & guid);

	bool run();
	bool Do();

	MapMgr(Map *map, uint32 mapid, uint32 instanceid);
	~MapMgr();
	void Init();
	void Destructor();

	void PushObject(Object* obj);
	void PushStaticObject(Object* obj);
	void RemoveObject(Object* obj, bool free_guid);
	void ChangeObjectLocation(Object* obj); // update inrange lists
	void ChangeFarsightLocation(Player* plr, Unit* farsight, bool apply);
	void ChangeFarsightLocation(Player* plr, float X, float Y, bool apply);

	// Mark object as updated
	void ObjectUpdated(Object* obj);
	void UpdateCellActivity(uint32 x, uint32 y, int radius);

	// Terrain Functions
	ARCTIC_INLINE float  GetLandHeight(float x, float y) { return GetBaseMap()->GetLandHeight(x, y); }
	ARCTIC_INLINE float  GetWaterHeight(float x, float y) { return GetBaseMap()->GetWaterHeight(x, y); }
	ARCTIC_INLINE uint8  GetWaterType(float x, float y) { return GetBaseMap()->GetWaterType(x, y); }
	ARCTIC_INLINE uint8  GetWalkableState(float x, float y) { return GetBaseMap()->GetWalkableState(x, y); }
	ARCTIC_INLINE uint16 GetAreaID(float x, float y, float z = 0)
	{
		uint16 aid = GetBaseMap()->GetAreaID(x, y);
		if(GetMapId() == 571)
		{
			// dirty fix for Dalaran sanctuary
			if( z > 500.0f && (aid == 4551 || aid == 4553 || aid == 4556 || aid == 2817) )
				return 4395;
		}
		return aid;
	}

	ARCTIC_INLINE uint32 GetMapId() { return _mapId; }

	void AddForcedCell(MapCell * c);
	void RemoveForcedCell(MapCell * c);

	void PushToProcessed(Player* plr);

	ARCTIC_INLINE bool HasPlayers() { return (m_PlayerStorage.size() > 0); }
	void TeleportPlayers();

	ARCTIC_INLINE uint32 GetInstanceID() { return m_instanceID; }
	ARCTIC_INLINE MapInfo *GetMapInfo() { return pMapInfo; }

	ARCTIC_INLINE void SetCollision(bool enable) { collision = enable; }
	ARCTIC_INLINE bool IsCollisionEnabled() { return collision; }

	ARCTIC_INLINE MapScriptInterface * GetInterface() { return ScriptInterface; }
	virtual int32 event_GetInstanceID() { return m_instanceID; }

	void LoadAllCells();
	ARCTIC_INLINE size_t GetPlayerCount() { return m_PlayerStorage.size(); }

	void _PerformObjectDuties();
	uint32 mLoopCounter;
	uint32 lastGameobjectUpdate;
	uint32 lastUnitUpdate;
	void EventCorpseDespawn(uint64 guid);

	time_t InactiveMoveTime;
    uint32 iInstanceMode;

	void UnloadCell(uint32 x,uint32 y);
	void EventRespawnVehicle(Vehicle* v, MapCell * p);
	void EventRespawnCreature(Creature* c, MapCell * p);
	void EventRespawnGameObject(GameObject* o, MapCell * c);
	void SendMessageToCellPlayers(Object* obj, WorldPacket * packet, uint32 cell_radius = 2);
	void SendChatMessageToCellPlayers(Object* obj, WorldPacket * packet, uint32 cell_radius, uint32 langpos, int32 lang, WorldSession * originator);

	Instance * pInstance;
	void BeginInstanceExpireCountdown();
	void HookOnAreaTrigger(Player* plr, uint32 id);

	// better hope to clear any references to us when calling this :P
	void InstanceShutdown()
	{
		pInstance = NULL;
		Terminate();
	}

	// kill the worker thread only
	void KillThread()
	{
		pInstance = NULL;
		thread_kill_only = true;
		Terminate();
		while(thread_running)
			Sleep(100);
	}

protected:

	// Collect and send updates to clients
	void _UpdateObjects();

private:
	// Objects that exist on map
	uint32 _mapId;
	set<Object* > _mapWideStaticObjects;

	bool _CellActive(uint32 x, uint32 y);
	void UpdateInRangeSet(Object* obj, Player* plObj, MapCell* cell);

public:
	// Distance a Player can "see" other objects and receive updates from them (!! ALREADY dist*dist !!)
	float m_UpdateDistance;
	bool collisionloaded;

private:
	/* Map Information */
	bool collision;
	MapInfo *pMapInfo;
	uint32 m_instanceID;

	MapScriptInterface * ScriptInterface;

	/* Update System */
	FastMutex m_updateMutex; // use a user-mode mutex for extra speed
	UpdateQueue _updates;
	PUpdateQueue _processQueue;

	/* Sessions */
	SessionSet MapSessions;

public:
#ifdef WIN32
	DWORD threadid;
#endif

	GameObjectSet activeGameObjects;
	CreatureSet activeCreatures;
	VehicleSet activeVehicles;
	EventableObjectHolder eventHolder;
	CBattleground* m_battleground;
	unordered_set<Corpse*> m_corpses;
	VehicleSqlIdMap _sqlids_vehicles;
	CreatureSqlIdMap _sqlids_creatures;
	GameObjectSqlIdMap _sqlids_gameobjects;

	Vehicle* GetSqlIdVehicle(uint32 sqlid);
	Creature* GetSqlIdCreature(uint32 sqlid);
	GameObject* GetSqlIdGameObject(uint32 sqlid);
	deque<uint32> _reusable_guids_creature;
	deque<uint32> _reusable_guids_vehicle;

	bool forced_expire;
	bool thread_kill_only;
	bool thread_running;

	// world state manager stuff
	WorldStateManager* m_stateManager;

	// bytebuffer caching
	ByteBuffer m_updateBuffer;
	ByteBuffer m_createBuffer;
	ByteBuffer m_updateBuildBuffer;
	ByteBuffer m_compressionBuffer;

public:

	// get!
	ARCTIC_INLINE WorldStateManager& GetStateManager() { return *m_stateManager; }

	// send packet functions for state manager
	void SendPacketToPlayers(int32 iZoneMask, int32 iFactionMask, WorldPacket *pData);
	void SendPacketToPlayers(int32 iZoneMask, int32 iFactionMask, StackPacket *pData);
	void EventSendPacketToPlayers(int32 iZoneMask, int32 iFactionMask, WorldPacket *pData);
	void SendPvPCaptureMessage(int32 iZoneMask, uint32 ZoneId, const char * Format, ...);

	// auras :< (world pvp)
	void RemoveAuraFromPlayers(int32 iFactionMask, uint32 uAuraId);
	void RemovePositiveAuraFromPlayers(int32 iFactionMask, uint32 uAuraId);
	void CastSpellOnPlayers(int32 iFactionMask, uint32 uSpellId);


public:

	// stored iterators for safe checking
	PetStorageMap::iterator __pet_iterator;
	PlayerStorageMap::iterator __player_iterator;

	VehicleSet::iterator __vehicle_iterator;
	CreatureSet::iterator __creature_iterator;
	GameObjectSet::iterator __gameobject_iterator;

	SessionSet::iterator __session_iterator_1;
	SessionSet::iterator __session_iterator_2;

	// Script related
	InstanceScript* GetScript() { return mInstanceScript; };
	void LoadInstanceScript();
	void CallScriptUpdate();

protected:

	InstanceScript* mInstanceScript;
};

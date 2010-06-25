/*
 * Moon++ Scripts for Ascent MMORPG Server
 * Copyright (C) 2005-2007 Ascent Team <http://www.ascentemu.com/>
 * Copyright (C) 2007-2008 Moon++ Team <http://www.moonplusplus.info/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.mOrg/licenses/>.
 */

#ifndef _INSTANCE_SCRIPT_BASE_H_
#define _INSTANCE_SCRIPT_BASE_H_

#include "StdAfx.h"

#include <string>
#include <vector>
#include <map>

#define INVALIDATE_TIMER			-1
#define DEFAULT_UPDATE_FREQUENCY	1000	//milliseconds

#define MOONSCRIPT_INSTANCE_FACTORY_FUNCTION( ClassName, ParentClassName ) \
public:\
	ADD_INSTANCE_FACTORY_FUNCTION( ClassName );\
	typedef ParentClassName ParentClass;

enum EncounterState
{
	State_NotStarted			= 0,
	State_InProgress			= 1,
	State_Finished				= 2,
};

enum InstanceType
{
	Type_Default				= INSTANCE_NULL,
	Type_Raid					= INSTANCE_RAID,
	Type_NonRaid				= INSTANCE_NONRAID,
	Type_PvP					= INSTANCE_PVP,
	Type_MultiMode				= INSTANCE_MULTIMODE
};

enum InstanceMode
{
	Mode_Normal					= MODE_NORMAL,
	Mode_Heroic					= MODE_HEROIC,
	Mode_Epic					= MODE_EPIC
};

enum DataType
{
	Data_EncounterState			= 0,
	Data_EncounterProgress		= 1,
	Data_UnspecifiedType		= 2
};

enum GameObjectState
{
	State_Active				= 0,	// Door: open
	State_Inactive				= 1
};

struct BossData
{
	BossData( EncounterState pState )
	{
		mSqlId = mGuid = 0;
		mState = pState;
	};

	BossData( uint32 pId = 0, uint64 pGuid = 0, EncounterState pState = State_NotStarted )
	{
		mSqlId = pId;
		mGuid = pGuid;
		mState = pState;
	};

	~BossData()
	{
	};

	uint32			mSqlId;
	uint64			mGuid;
	EncounterState	mState;
};

class MoonInstanceScript;

typedef std::map< uint32, BossData >							EncounterMap;
typedef std::map< uint32, GameObjectState >						GameObjectEntryMap;
typedef std::vector< uint32 >									IdVector;
typedef std::set< uint32 >										IdSet;
typedef std::map< uint32, IdVector >							EntryIdMap;
typedef std::pair< int32, int32 >								TimerPair;
typedef std::vector< TimerPair >								TimerArray;
typedef std::tr1::hash_map< uint32, GameObjectPointer >			GameObjectMap;
typedef std::tr1::unordered_set< UnitPointer >					UnitSet;
typedef std::tr1::unordered_set< PlayerPointer >				PlayerSet;
typedef std::tr1::unordered_set< CreaturePointer >				CreatureSet;
typedef std::tr1::unordered_set< GameObjectPointer >			GameObjectSet;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Class MoonInstanceScript
class MoonInstanceScript : public InstanceScript
{
public:
	MoonInstanceScript( MapMgrPointer pMapMgr );
	virtual ~MoonInstanceScript();

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

	// Creature
	CreaturePointer				GetCreatureBySqlId( uint32 pSqlId );
	CreaturePointer				GetCreatureByGuid( uint32 pGuid );
	CreaturePointer				FindClosestCreatureOnMap( uint32 pEntry, float pX, float pY, float pZ );
	CreaturePointer				SpawnCreature( uint32 pEntry, float pX, float pY, float pZ, float pO );
	CreaturePointer				SpawnCreature( uint32 pEntry, float pX, float pY, float pZ, float pO, uint32 pFactionId );
	CreatureSet					FindCreaturesOnMap( uint32 pEntry );

	// GameObject
	GameObjectPointer			GetGameObjectBySqlId( uint32 pSqlId );
	GameObjectPointer			GetGameObjectByGuid( uint32 pGuid );
	GameObjectPointer			FindClosestGameObjectOnMap( uint32 pEntry, float pX, float pY, float pZ );
	GameObjectPointer			SpawnGameObject( uint32 pEntry, float pX, float pY, float pZ, float pO );
	GameObjectSet				FindGameObjectsOnMap( uint32 pEntry );
	void						AddGameObjectStateByEntry( uint32 pEntry, GameObjectState pState, bool pUseQuery = false );
	void						AddGameObjectStateById( uint32 pId, GameObjectState pState );

	// Distance calculation
	float						GetRangeToObject( ObjectPointer pObjectA, ObjectPointer pObjectB );
	float						GetRangeToObject( ObjectPointer pObject, float pX, float pY, float pZ );
	float						GetRangeToObject( float pX1, float pY1, float pZ1, float pX2, float pY2, float pZ2 );

	// Player and instance - reimplementation for easier calling
	bool						HasPlayers();
	size_t						GetPlayerCount();
	PlayerPointer				GetPlayerByGuid( uint32 pGuid );
	bool						IsCombatInProgress();

	// Timers - reimplementation from MoonScriptCreatureAI
	uint32						AddTimer( int32 pDurationMillisec );
	int32						GetTimer( int32 pTimerId );
	void						RemoveTimer( int32& pTimerId );
	void						ResetTimer( int32 pTimerId, int32 pDurationMillisec );
	bool						IsTimerFinished( int32 pTimerId );
	void						CancelAllTimers();

	// Update Event
	void						RegisterScriptUpdateEvent();
	void						SetUpdateEventFreq( uint32 pUpdateFreq );
	uint32						GetUpdateEventFreq();

	// Cells
	void						SetCellForcedStates( float pMinX, float pMaxX, float pMinY, float pMaxY, bool pActivate = true );

	// Player
	virtual void				OnPlayerDeath( PlayerPointer pVictim, UnitPointer pKiller );

	// Area and AreaTrigger
	virtual void				OnPlayerEnter( PlayerPointer pPlayer );
	virtual void				OnAreaTrigger( PlayerPointer pPlayer, uint32 pAreaId );
	virtual void				OnZoneChange( PlayerPointer pPlayer, uint32 pNewZone, uint32 pOldZone );

	// Data get / set - idea taken from ScriptDev2
	virtual void				SetInstanceData( uint32 pType, uint32 pIndex, uint32 pData );
	virtual uint32				GetInstanceData( uint32 pType, uint32 pIndex );

	// Creature / GameObject
	virtual void				OnCreatureDeath( CreaturePointer pVictim, UnitPointer pKiller );
	virtual void				OnCreaturePushToWorld( CreaturePointer pCreature );
	virtual void				OnGameObjectActivate( GameObjectPointer pGameObject, PlayerPointer pPlayer );
	virtual void				OnGameObjectPushToWorld( GameObjectPointer pGameObject );

	// Reimplemented events
	virtual GameObjectPointer	GetObjectForOpenLock( PlayerPointer pCaster, SpellPointer pSpell, SpellEntry* pSpellEntry );
	virtual void				SetLockOptions( uint32 pEntryId, GameObjectPointer pGameObject );
	virtual uint32				GetRespawnTimeForCreature( uint32 pEntryId, CreaturePointer pCreature);
	virtual void				OnLoad();
	virtual void				UpdateEvent();
	virtual void				Destroy();

protected:

	// Encounter generators
	void						BuildEncounterMap();
	void						BuildEncounterMapWithEntries( IdVector pEntries );
	void						BuildEncounterMapWithIds( IdVector pIds );
	IdVector					BuildIdVector( uint32 pCount, ... );
	IdSet						BuildIdSet( uint32 pCount, ... );

	EncounterMap				mEncounters;
	GameObjectEntryMap			mGameObjects;
	uint32						mUpdateFrequency;
	TimerArray					mTimers;
	int32						mTimerIdCounter;
};

#endif /* _INSTANCE_SCRIPT_BASE_H_ */

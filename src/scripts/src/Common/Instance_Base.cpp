/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#include "Instance_Base.h"

ArcTicInstanceScript::ArcTicInstanceScript( MapMgr* pMapMgr ) : InstanceScript( pMapMgr )
{
	mUpdateFrequency = DEFAULT_UPDATE_FREQUENCY;
};

ArcTicInstanceScript::~ArcTicInstanceScript()
{
};

Creature* ArcTicInstanceScript::GetCreatureBySqlId( uint32 pSqlId )
{
	if ( pSqlId == 0 )
		return NULL;

	return mInstance->GetSqlIdCreature( pSqlId );
};

Creature* ArcTicInstanceScript::GetCreatureByGuid( uint32 pGuid )
{
	if ( pGuid == 0 )
		return NULL;

	return mInstance->GetCreature( pGuid );
};

Creature* ArcTicInstanceScript::FindClosestCreatureOnMap( uint32 pEntry, float pX, float pY, float pZ )
{
	CreatureSet Creatures = FindCreaturesOnMap( pEntry );

	if ( Creatures.size() == 0 )
		return NULL;
	if ( Creatures.size() == 1 )
		return *( Creatures.begin() );

	Creature* NearestCreature = NULL;
	float Distance, NearestDistance = 99999;
	for ( CreatureSet::iterator Iter = Creatures.begin(); Iter != Creatures.end(); ++Iter )
	{
		Distance = GetRangeToObject( *Iter, pX, pY, pZ );
		if ( Distance < NearestDistance )
		{
			NearestDistance = Distance;
			NearestCreature = ( *Iter );
		};
	};

	return NearestCreature;
};

Creature* ArcTicInstanceScript::SpawnCreature( uint32 pEntry, float pX, float pY, float pZ, float pO )
{
	Creature* NewCreature = mInstance->GetInterface()->SpawnCreature( pEntry, pX, pY, pZ, pO, true, true, NULL, NULL);
	return NewCreature;
};

Creature* ArcTicInstanceScript::SpawnCreature( uint32 pEntry, float pX, float pY, float pZ, float pO, uint32 pFactionId )
{
	Creature* NewCreature = mInstance->GetInterface()->SpawnCreature( pEntry, pX, pY, pZ, pO, true, true, NULL, NULL);
	if ( NewCreature != NULL )
		NewCreature->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, pFactionId);

	return NewCreature;
};

CreatureSet ArcTicInstanceScript::FindCreaturesOnMap( uint32 pEntry )
{
	Creature* CurrentCreature = NULL;
	CreatureSet ReturnSet;
	for ( uint32 i = 0; i != mInstance->m_CreatureHighGuid; ++i )
	{
		CurrentCreature = mInstance->m_CreatureStorage[ i ];
		if ( CurrentCreature != NULL )
		{ 
			if ( CurrentCreature->GetEntry() == pEntry )
				ReturnSet.insert( CurrentCreature );
		};
	};

	return ReturnSet;
};

GameObject* ArcTicInstanceScript::FindClosestGameObjectOnMap( uint32 pEntry, float pX, float pY, float pZ )
{
	GameObjectSet GameObjects = FindGameObjectsOnMap( pEntry );

	if ( GameObjects.size() == 0 )
		return NULL;
	if ( GameObjects.size() == 1 )
		return *( GameObjects.begin() );

	GameObject* NearestObject = NULL;
	float Distance, NearestDistance = 99999;
	for ( GameObjectSet::iterator Iter = GameObjects.begin(); Iter != GameObjects.end(); ++Iter )
	{
		Distance = GetRangeToObject( *Iter, pX, pY, pZ );
		if ( Distance < NearestDistance )
		{
			NearestDistance = Distance;
			NearestObject = ( *Iter );
		};
	};

	return NearestObject;
};

GameObject* ArcTicInstanceScript::SpawnGameObject( uint32 pEntry, float pX, float pY, float pZ, float pO )
{
	GameObject* pNewGO = mInstance->GetInterface()->SpawnGameObject( pEntry, pX, pY, pZ, pO, true, NULL, NULL );
	return pNewGO;
};

GameObjectSet ArcTicInstanceScript::FindGameObjectsOnMap( uint32 pEntry )
{
	GameObject* CurrentObject = NULL;
	GameObjectSet ReturnSet;
	for ( GameObjectMap::iterator Iter = mInstance->m_gameObjectStorage.begin(); Iter != mInstance->m_gameObjectStorage.end(); ++Iter )
	{
		CurrentObject = ( *Iter ).second;
		if ( CurrentObject != NULL )
		{ 
			if ( CurrentObject->GetEntry() == pEntry )
				ReturnSet.insert( CurrentObject );
		};
	};

	return ReturnSet;
};

GameObject* ArcTicInstanceScript::GetGameObjectBySqlId( uint32 pSqlId )
{
	if ( pSqlId == 0 )
		return NULL;

	return mInstance->GetSqlIdGameObject( pSqlId );
};

GameObject* ArcTicInstanceScript::GetGameObjectByGuid( uint32 pGuid )
{
	if ( pGuid == 0 )
		return NULL;

	return mInstance->GetGameObject( pGuid );
};

void ArcTicInstanceScript::AddGameObjectStateByEntry( uint32 pEntry, GameObjectState pState, bool pUseQuery )
{
	if ( pEntry == 0 )
		return;

	GameObjectEntryMap::iterator Iter = mGameObjects.find( pEntry );
	if ( Iter != mGameObjects.end() )
		( *Iter ).second = pState;
	else
		mGameObjects.insert( GameObjectEntryMap::value_type( pEntry, pState ) );

	GameObject* CurrentObject = NULL;
	if ( !pUseQuery )
	{
		for ( GameObjectMap::iterator Iter = mInstance->m_gameObjectStorage.begin(); Iter != mInstance->m_gameObjectStorage.end(); ++Iter )
		{
			CurrentObject = ( *Iter ).second;
			if ( CurrentObject == NULL || CurrentObject->GetEntry() != pEntry )
				continue;

			CurrentObject->SetState( pState );
		};
	}
	else
	{
		QueryResult* Result = WorldDatabase.Query( "SELECT id FROM gameobject_spawns WHERE entry = %u", pEntry );
		if ( Result != NULL )
		{
			do
			{
				CurrentObject = GetGameObjectBySqlId( Result->Fetch()[ 0 ].GetUInt32() );
				if ( CurrentObject != NULL )
					CurrentObject->SetState( pState );
			}
			while ( Result->NextRow() );

			delete Result;
		};
	};
};

void ArcTicInstanceScript::AddGameObjectStateById( uint32 pId, GameObjectState pState )
{
	if ( pId == 0 )
		return;

	GameObject* StateObject = GetGameObjectBySqlId( pId );
	GameObjectEntryMap::iterator Iter;
	if ( StateObject != NULL )
	{
		StateObject->SetState( pState );
		Iter = mGameObjects.find( StateObject->GetEntry() );
		if ( Iter != mGameObjects.end() )
			( *Iter ).second = pState;
		else
			mGameObjects.insert( GameObjectEntryMap::value_type( StateObject->GetEntry(), pState ) );
	}
	else
	{
		QueryResult* Result = WorldDatabase.Query( "SELECT entry FROM gameobject_spawns WHERE id = %u", pId );
		if ( Result != NULL )
		{
			uint32 Entry = Result->Fetch()[ 0 ].GetUInt32();
			Iter = mGameObjects.find( Entry );
			if ( Iter != mGameObjects.end() )
				( *Iter ).second = pState;
			else
				mGameObjects.insert( GameObjectEntryMap::value_type( Entry, pState ) );

			delete Result;
		};
	};
};

float ArcTicInstanceScript::GetRangeToObject( Object* pObjectA, Object* pObjectB )
{
	if ( pObjectA == NULL || pObjectB == NULL )
		return 0.0f;

	return GetRangeToObject( pObjectA->GetPositionX(), pObjectA->GetPositionY(), pObjectA->GetPositionZ(), pObjectB->GetPositionX(), pObjectB->GetPositionY(), pObjectB->GetPositionZ() );
};

float ArcTicInstanceScript::GetRangeToObject( Object* pObject, float pX, float pY, float pZ )
{
	if ( pObject == NULL )
		return 0.0f;

	return GetRangeToObject( pObject->GetPositionX(), pObject->GetPositionY(), pObject->GetPositionZ(), pX, pY, pZ );
};

float ArcTicInstanceScript::GetRangeToObject( float pX1, float pY1, float pZ1, float pX2, float pY2, float pZ2 )
{
	float dX = pX1 - pX2;
	float dY = pY1 - pY2;
	float dZ = pZ1 - pZ2;

	return sqrtf( dX * dX + dY * dY + dZ * dZ );
};

bool ArcTicInstanceScript::HasPlayers()
{
	return mInstance->GetPlayerCount() > 0;
};

size_t ArcTicInstanceScript::GetPlayerCount()
{
	return mInstance->GetPlayerCount();
};

Player* ArcTicInstanceScript::GetPlayerByGuid( uint32 pGuid )
{
	if ( pGuid == 0 )
		return NULL;

	return mInstance->GetPlayer( pGuid );
};

bool ArcTicInstanceScript::IsCombatInProgress()
{
	return mInstance->_combatProgress.size() > 0;
};

uint32 ArcTicInstanceScript::AddTimer( int32 pDurationMillisec )
{
	int32 Index = mTimerIdCounter++;
	mTimers.push_back( std::make_pair( Index, pDurationMillisec ) );
	return Index;
}

int32 ArcTicInstanceScript::GetTimer( int32 pTimerId )
{
	for ( TimerArray::iterator TimerIter = mTimers.begin(); TimerIter != mTimers.end(); ++TimerIter )
	{
		if ( TimerIter->first == pTimerId )
			return TimerIter->second;
	};

	return 0;
};

void ArcTicInstanceScript::RemoveTimer( int32& pTimerId )
{
	for ( TimerArray::iterator TimerIter = mTimers.begin(); TimerIter != mTimers.end(); ++TimerIter )
	{
		if ( TimerIter->first == pTimerId )
		{
			mTimers.erase( TimerIter );
			pTimerId = INVALIDATE_TIMER;
			break;
		};
	};
};

void ArcTicInstanceScript::ResetTimer( int32 pTimerId, int32 pDurationMillisec )
{
	for ( TimerArray::iterator TimerIter = mTimers.begin(); TimerIter != mTimers.end(); ++TimerIter )
	{
		if ( TimerIter->first == pTimerId )
		{
			TimerIter->second = pDurationMillisec;
			break;
		};
	};
};

bool ArcTicInstanceScript::IsTimerFinished( int32 pTimerId )
{
	for ( TimerArray::iterator TimerIter = mTimers.begin(); TimerIter != mTimers.end(); ++TimerIter )
	{
		if ( TimerIter->first == pTimerId )
			return ( TimerIter->second <= 0 ) ? true : false;
	};
	return false;
};

void ArcTicInstanceScript::CancelAllTimers()
{
	mTimers.clear();
	mTimerIdCounter = 0;
};

void ArcTicInstanceScript::RegisterScriptUpdateEvent()
{
	RegisterUpdateEvent( mUpdateFrequency );
};

void ArcTicInstanceScript::SetUpdateEventFreq( uint32 pUpdateFreq )
{
	if ( mUpdateFrequency != pUpdateFreq )
	{
		mUpdateFrequency = pUpdateFreq;
		ModifyUpdateEvent( mUpdateFrequency );
	};
};

uint32 ArcTicInstanceScript::GetUpdateEventFreq()
{
	return mUpdateFrequency;
};

void ArcTicInstanceScript::SetCellForcedStates( float pMinX, float pMaxX, float pMinY, float pMaxY, bool pActivate )
{
	if ( pMinX == pMaxX || pMinY == pMaxY )
		return;

	float Y = pMinY;
	while ( pMinX < pMaxX )
	{
		while ( pMinY < pMaxY )
		{
			MapCell* CurrentCell = mInstance->GetCellByCoords( pMinX, pMinY );
			if ( pActivate && CurrentCell == NULL )
			{
				CurrentCell = mInstance->CreateByCoords( pMinX, pMinY );
				if ( CurrentCell != NULL )
					CurrentCell->Init( mInstance->GetPosX( pMinX ), mInstance->GetPosY( pMinY ), mInstance->GetMapId(), mInstance );
			};

			if ( CurrentCell != NULL )
			{
				if ( pActivate )
					mInstance->AddForcedCell( CurrentCell );
				else
					mInstance->RemoveForcedCell( CurrentCell );
			};

			pMinY += 40.0f;
		};

		pMinY = Y;
		pMinX += 40.0f;
	};
};

void ArcTicInstanceScript::OnPlayerDeath( Player* pVictim, Unit* pKiller )
{
};

void ArcTicInstanceScript::OnPlayerEnter( Player* pPlayer )
{
};

void ArcTicInstanceScript::OnAreaTrigger( Player* pPlayer, uint32 pAreaId )
{
};

void ArcTicInstanceScript::OnZoneChange( Player* pPlayer, uint32 pNewZone, uint32 pOldZone )
{
};

void ArcTicInstanceScript::SetInstanceData( uint32 pType, uint32 pIndex, uint32 pData )
{
};

uint32 ArcTicInstanceScript::GetInstanceData( uint32 pType, uint32 pIndex )
{
	return 0;
};

void ArcTicInstanceScript::OnCreatureDeath( Creature* pVictim, Unit* pKiller )
{
};

void ArcTicInstanceScript::OnCreaturePushToWorld( Creature* pCreature )
{
};

void ArcTicInstanceScript::OnGameObjectActivate( GameObject* pGameObject, Player* pPlayer )
{
};

void ArcTicInstanceScript::OnGameObjectPushToWorld( GameObject* pGameObject )
{
	// Dunno how part of those would happen
	if ( mGameObjects.size() == 0 || pGameObject == NULL )
		return;

	GameObjectEntryMap::iterator Iter = mGameObjects.find( pGameObject->GetEntry() );
	if ( Iter != mGameObjects.end() )
		pGameObject->SetState( ( *Iter ).second );
};

GameObject* ArcTicInstanceScript::GetObjectForOpenLock( Player* pCaster, Spell* pSpell, SpellEntry* pSpellEntry )
{
	return NULL;
};

void ArcTicInstanceScript::SetLockOptions( uint32 pEntryId, GameObject* pGameObject )
{
};

uint32 ArcTicInstanceScript::GetRespawnTimeForCreature( uint32 pEntryId, Creature* pCreature)
{
	return 240000;
};

void ArcTicInstanceScript::OnLoad()
{
};

void ArcTicInstanceScript::UpdateEvent()
{
	uint32 CurrentTime = static_cast< uint32 >( time( NULL ) );
	for ( TimerArray::iterator TimerIter = mTimers.begin(); TimerIter != mTimers.end(); ++TimerIter )
	{
		TimerIter->second -= mUpdateFrequency;
	};
};

void ArcTicInstanceScript::Destroy()
{
	delete this;
};

void ArcTicInstanceScript::BuildEncounterMap()
{
	if ( mInstance->pInstance == NULL )
		return;

	QueryResult* KillResult = WorldDatabase.Query( "SELECT id, entry FROM creature_spawns WHERE map = %u AND entry IN ( SELECT entry FROM creature_names WHERE rank = 3 )", mInstance->GetMapId() );
	if ( KillResult != NULL )
	{
		uint32 Id = 0, Entry = 0;
		Field* CurrentField = NULL;
		EncounterMap::iterator EncounterIter;
		EncounterState State = State_NotStarted;
		bool StartedInstance = mInstance->pInstance->m_killedNpcs.size() > 0;
		do
		{
			CurrentField = KillResult->Fetch();
			Id = CurrentField[ 0 ].GetUInt32();
			Entry = CurrentField[ 1 ].GetUInt32();

			EncounterIter = mEncounters.find( Entry );
			if ( EncounterIter != mEncounters.end() )
				continue;

			if ( StartedInstance )
			{
				if ( mInstance->pInstance->m_killedNpcs.find( Id ) != mInstance->pInstance->m_killedNpcs.end() )
					State = State_Finished;
				else
					State = State_NotStarted;
			};

			mEncounters.insert( EncounterMap::value_type( Entry, BossData( Id, 0, State ) ) );
		}
		while ( KillResult->NextRow() );

		delete KillResult;
	};
};

// Dynamic data creation that still involves MySQL
void ArcTicInstanceScript::BuildEncounterMapWithEntries( IdVector pEntries )
{
	if ( mInstance->pInstance == NULL || pEntries.size() == 0 )
		return;

	std::stringstream Query;
	Query << "SELECT id, entry FROM creature_spawns WHERE entry IN ( ";
	Query << pEntries[ 0 ];
	for ( size_t i = 1; i < pEntries.size(); ++i )
	{
		Query << ", ";
		Query << pEntries[ i ];
	};

	Query << " )";
	QueryResult* KillResult = WorldDatabase.Query( Query.str().c_str() );
	if ( KillResult != NULL )
	{
		uint32 Id = 0, Entry = 0;
		Field* CurrentField = NULL;
		EncounterMap::iterator EncounterIter;
		EncounterState State = State_NotStarted;
		bool StartedInstance = mInstance->pInstance->m_killedNpcs.size() > 0;
		do
		{
			CurrentField = KillResult->Fetch();
			Id = CurrentField[ 0 ].GetUInt32();
			Entry = CurrentField[ 1 ].GetUInt32();

			EncounterIter = mEncounters.find( Entry );
			if ( EncounterIter != mEncounters.end() )
				continue;

			if ( StartedInstance )
			{
				if ( mInstance->pInstance->m_killedNpcs.find( Id ) != mInstance->pInstance->m_killedNpcs.end() )
					State = State_Finished;
				else
					State = State_NotStarted;
			};

			mEncounters.insert( EncounterMap::value_type( Entry, BossData( Id, 0, State ) ) );
		}
		while ( KillResult->NextRow() );

		delete KillResult;
	};
};

// Static data creation without MySQL use
void ArcTicInstanceScript::BuildEncounterMapWithIds( IdVector pIds )
{
	// Won't work with spawns that are not in world - would work well with instance fully loaded
	if ( mInstance->pInstance == NULL || pIds.size() == 0 )
		return;

	uint32 CurrentId = 0;
	EncounterState State = State_NotStarted;
	Creature* Boss = NULL;
	unordered_set< uint32 >::iterator Iter;
	EncounterMap::iterator EncounterIter;
	for ( size_t i = 0; i < pIds.size(); ++i )
	{
		CurrentId = pIds[ i ];
		if ( CurrentId == 0 )
			continue;

		Iter = mInstance->pInstance->m_killedNpcs.find( CurrentId );
		if ( Iter != mInstance->pInstance->m_killedNpcs.end() )
			State = State_Finished;

		Boss = mInstance->GetCreature( CurrentId );
		if ( Boss != NULL )
		{
			EncounterIter = mEncounters.find( Boss->GetEntry() );
			if ( EncounterIter != mEncounters.end() )
				continue;

			mEncounters.insert( EncounterMap::value_type( Boss->GetEntry(), BossData( CurrentId, Boss->GetGUID(), State ) ) );
		};

		State = State_NotStarted;
	};
};

IdVector ArcTicInstanceScript::BuildIdVector( uint32 pCount, ... )
{
	IdVector NewVector;
	va_list List;
	va_start( List, pCount );
	for ( uint32 i = 0; i < pCount; ++i )
	{
		NewVector.push_back( va_arg( List, uint32 ) );
	};
		
	va_end( List );
	return NewVector;
};

IdSet ArcTicInstanceScript::BuildIdSet( uint32 pCount, ... )
{
	IdSet NewSet;
	va_list List;
	va_start( List, pCount );
	for ( uint32 i = 0; i < pCount; ++i )
	{
		NewSet.insert( va_arg( List, uint32 ) );
	};
		
	va_end( List );
	return NewSet;
};

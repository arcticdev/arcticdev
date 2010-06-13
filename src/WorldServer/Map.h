/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __MAP_H
#define __MAP_H

class MapMgr;
class TemplateMgr;
struct MapInfo;
class TerrainMgr;

#include "TerrainMgr.h"

struct Formation;

typedef struct EventIdInfo
{
	uint8  eventid;
	uint8  eventchangesflag;
	uint32 eventdisplayid;
	int32  eventphase;
	uint32 eventitem1;
	uint32 eventitem2;
	uint32 eventitem3;
}EventIdInfo;

typedef struct CreatureSpawn
{
	uint32 id; // spawn ID
	uint32 entry;
	float x;
	float y;
	float z;
	float o;
	Formation* form;
	uint8 movetype;
	uint32 displayid;
	uint32 factionid;
	uint32 flags;
	uint32 bytes;
	uint32 bytes1;
	uint32 bytes2;
	uint32 emote_state;
	// uint32 respawnNpcLink;
	uint16 channel_spell;
	uint32 channel_target_go;
	uint32 channel_target_creature;
	uint16 stand_state;
	uint32 MountedDisplayID;
	int32 phase;
	uint32 vehicle;
	uint8 eventid;
	uint32 CanFly;
	EventIdInfo * eventinfo;
}CreatureSpawn;

typedef struct GOSpawn
{
	uint32 id; // spawn ID
	uint32 entry;
	float x;
	float y;
	float z;
	float orientation1;
	float orientation2;
	float orientation3;
	float orientation4;
	float facing;
	uint32 flags;
	uint32 state;
	uint32 MountDisplayID;
	uint32 faction;
	float scale;
	int32 phase;
	uint8 eventid;
	EventIdInfo * eventinfo;
} GOSpawn;

typedef std::vector<CreatureSpawn*> CreatureSpawnList;
typedef std::vector<GOSpawn*> GOSpawnList;

typedef struct
{
	CreatureSpawnList CreatureSpawns;
	GOSpawnList GOSpawns;
}CellSpawns;

class ARCTIC_DECL Map
{
public:
	Map(uint32 mapid, MapInfo * inf);
	~Map();

	ARCTIC_INLINE string GetNameString() { return name; }
	ARCTIC_INLINE const char* GetName() { return name.c_str(); }
	ARCTIC_INLINE MapEntry* GetDBCEntry() { return me; }

	ARCTIC_INLINE CellSpawns *GetSpawnsList(uint32 cellx,uint32 celly)
	{
		ASSERT(cellx < _sizeX);
		ASSERT(celly < _sizeY);
		if(spawns[cellx]==NULL) return NULL;

		return spawns[cellx][celly];
	}
	ARCTIC_INLINE CellSpawns * GetSpawnsListAndCreate(uint32 cellx, uint32 celly)
	{
		ASSERT(cellx < _sizeX);
		ASSERT(celly < _sizeY);
		if(spawns[cellx] == NULL)
		{
			spawns[cellx] = new CellSpawns*[_sizeY];
			memset(spawns[cellx], 0, sizeof(CellSpawns*)*_sizeY);
		}

		if(spawns[cellx][celly] == 0)
			spawns[cellx][celly] = new CellSpawns;
		return spawns[cellx][celly];
	}

	void LoadSpawns(bool reload = false); // set to true to make clean up
	uint32 CreatureSpawnCount;
	uint32 GameObjectSpawnCount;

	ARCTIC_INLINE float  GetLandHeight(float x, float y)
	{ 
		if(_terrain)
		{
			return _terrain->GetLandHeight(x, y);
		}
		else
		{
			return NO_LAND_HEIGHT;
		}
	}

	ARCTIC_INLINE float  GetWaterHeight(float x, float y) 
	{ 
		if(_terrain)
		{ 
			return _terrain->GetWaterHeight(x, y); 
		}
		else
		{ 
			return NO_LAND_HEIGHT; 
		}
	}

	ARCTIC_INLINE uint8  GetWaterType(float x, float y)
	{
		if(_terrain)
		{ 
			return _terrain->GetWaterType(x, y);
		}
		else
		{ 
			return 0;
		}
	}

	ARCTIC_INLINE uint8  GetWalkableState(float x, float y)
	{
		if(_terrain)
		{ 
			return _terrain->GetWalkableState(x, y);
		}
		else
		{ 
			return 1; 
		}
	}

	ARCTIC_INLINE uint16 GetAreaID(float x, float y)
	{
		if(_terrain)
		{ 
			return _terrain->GetAreaID(x, y);
		}
		else
		{ 
			return 0xFFFF;
		}
	}

	ARCTIC_INLINE void CellGoneActive(uint32 x, uint32 y)
	{ 
		if(_terrain)
		{ 
			_terrain->CellGoneActive(x,y);
		}
	}

	ARCTIC_INLINE void CellGoneIdle(uint32 x,uint32 y)
	{ 
		if(_terrain)
		{ 
			_terrain->CellGoneIdle(x,y);
		}
	}

private:
	MapInfo * _mapInfo;
	TerrainMgr * _terrain;
	uint32 _mapId;
	string name;
	MapEntry * me;

	// New stuff
	CellSpawns **spawns[_sizeX];
public:
	CellSpawns staticSpawns;
};

#endif

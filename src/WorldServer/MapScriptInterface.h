/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */
 
#ifndef _MAP_SCRIPT_INTERFACE_H
#define _MAP_SCRIPT_INTERFACE_H

class GameObject;
class Object;
class Creature;
class Unit;
class Player;

class ARCTIC_DECL MapScriptInterface
{
public:
	MapScriptInterface(MapMgrPointer mgr);
	~MapScriptInterface();

	template<class T, uint32 TypeId> shared_ptr<T> GetObjectNearestCoords(uint32 Entry, float x, float y, float z, float ClosestDist)
	{
		MapCell * pCell = mapMgr->GetCell(mapMgr->GetPosX(x), mapMgr->GetPosY(y));
		if(pCell == 0)
			return CAST(T, NULLPTR);

		ObjectPointer ClosestObject = NULLOBJ;
		float CurrentDist = 0;
        ObjectSet::const_iterator iter = pCell->Begin();
		for(; iter != pCell->End(); ++iter)
		{
			CurrentDist = (*iter)->CalcDistance(x, y, (z != 0.0f ? z : (*iter)->GetPositionZ()));
			if(CurrentDist < ClosestDist && (*iter)->GetTypeId() == TypeId)
			{
				if((Entry && (*iter)->GetEntry() == Entry) || !Entry)
				{
					ClosestDist = CurrentDist;
					ClosestObject = (*iter);
				}
			}
		}

		return CAST(T, ClosestObject);
	}

	ARCTIC_INLINE GameObjectPointer GetGameObjectNearestCoords(float x, float y, float z = 0.0f, uint32 Entry = 0, float ClosestDistance = 999999.0f)
	{
		return GetObjectNearestCoords<GameObject, TYPEID_GAMEOBJECT>(Entry, x, y, z, ClosestDistance);
	}

	ARCTIC_INLINE CreaturePointer GetCreatureNearestCoords(float x, float y, float z = 0.0f, uint32 Entry = 0, float ClosestDistance = 999999.0f)
	{
		return GetObjectNearestCoords<Creature, TYPEID_UNIT>(Entry, x, y, z, ClosestDistance);
	}

	ARCTIC_INLINE PlayerPointer GetPlayerNearestCoords(float x, float y, float z = 0.0f, uint32 Entry = 0, float ClosestDistance = 999999.0f)
	{
		if(!mapMgr->GetPlayerCount())
			return NULLPLR;
		return GetObjectNearestCoords<Player, TYPEID_PLAYER>(Entry, x, y, z, ClosestDistance);
	}

	uint32 GetPlayerCountInRadius(float x, float y, float z = 0.0f, float radius = 5.0f);
	
	GameObjectPointer SpawnGameObject(uint32 Entry, float cX, float cY, float cZ, float cO, bool AddToWorld, uint32 Misc1, uint32 Misc2);
	CreaturePointer SpawnCreature(uint32 Entry, float cX, float cY, float cZ, float cO, bool AddToWorld, bool tmplate, uint32 Misc1, uint32 Misc2);
	WayPoint * CreateWaypoint();

	void DeleteGameObject(GameObjectPointer ptr);
	void DeleteCreature(CreaturePointer ptr);

private:
	MapMgrPointer mapMgr;
};

class ARCTIC_DECL StructFactory : public Singleton<StructFactory>
{
public:
	StructFactory() {}
	WayPoint * CreateWaypoint();
};

#define sStructFactory StructFactory::getSingleton()

#endif


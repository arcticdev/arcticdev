/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#include "StdAfx.h"

MapCell::MapCell()
{
	_forcedActive = false;
}

MapCell::~MapCell()
{
	RemoveObjects();
}

void MapCell::Init(uint32 x, uint32 y, uint32 mapid, MapMgr* mapmgr)
{
	_mapmgr = mapmgr;
	_active = false;
	_loaded = false;
	_playerCount = 0;
	_x=x;
	_y=y;
	_unloadpending=false;
	_objects.clear();
}

void MapCell::AddObject(Object* obj)
{
	if(obj->IsPlayer())
		++_playerCount;

	_objects.insert(obj);
}

void MapCell::RemoveObject(Object* obj)
{
	if(obj->IsPlayer())
		--_playerCount;

	_objects.erase(obj);
}

void MapCell::SetActivity(bool state)
{
	if(!_active && state)
	{
		// Move all objects to active set.
		for(ObjectSet::iterator itr = _objects.begin(); itr != _objects.end(); itr++)
		{
			if(!(*itr)->Active && (*itr)->CanActivate())
				(*itr)->Activate(_mapmgr);
		}

		if(_unloadpending)
			CancelPendingUnload();

		if (_mapmgr->IsCollisionEnabled())
			CollideInterface.ActivateTile(_mapmgr->GetMapId(), _x/8, _y/8);
	} else if(_active && !state)
	{
		// Move all objects from active set.
		for(ObjectSet::iterator itr = _objects.begin(); itr != _objects.end(); itr++)
		{
			if((*itr)->Active)
				(*itr)->Deactivate(_mapmgr);
		}

		if(sWorld.map_unload_time && !_unloadpending)
			QueueUnloadPending();

		if (_mapmgr->IsCollisionEnabled())
			CollideInterface.DeactivateTile(_mapmgr->GetMapId(), _x/8, _y/8);
	}

	_active = state;

}
void MapCell::RemoveObjects()
{
	ObjectSet::iterator itr;

	/* delete objects in pending respawn state */
	Object* pObject;
	for(itr = _respawnObjects.begin(); itr != _respawnObjects.end(); itr++)
	{
		pObject = *itr;
		if(!pObject)
			continue;

		switch(pObject->GetTypeId())
		{
		case TYPEID_UNIT:
			{
				if( pObject->IsVehicle() )
				{
					_mapmgr->_reusable_guids_vehicle.push_back( pObject->GetUIdFromGUID() );
					TO_VEHICLE(pObject)->m_respawnCell = NULL;
					delete TO_VEHICLE(pObject);
					pObject = NULL;
				}
				else if( !pObject->IsPet() )
				{
					_mapmgr->_reusable_guids_creature.push_back( pObject->GetUIdFromGUID() );
					TO_CREATURE(pObject)->m_respawnCell = NULL;
					delete TO_CREATURE(pObject);
					pObject = NULL;
				}
			}break;

		case TYPEID_GAMEOBJECT:
		{
			TO_GAMEOBJECT(pObject)->m_respawnCell = NULL;
			delete TO_GAMEOBJECT(pObject);
			pObject = NULL;
			}break;
		default:
			delete pObject;
			pObject = NULL;
			break;

		}
	}
	_respawnObjects.clear();

	// This time it's simpler! We just remove everything :)
	Object* obj; // do this outside the loop!
	for(itr = _objects.begin(); itr != _objects.end();)
	{
		obj = (*itr);
		itr++;

		if(!obj)
			continue;

		if( _unloadpending )
		{
			if(obj->GetTypeFromGUID() == HIGHGUID_TYPE_TRANSPORTER)
				continue;

			if(obj->GetTypeId()==TYPEID_CORPSE && obj->GetUInt32Value(CORPSE_FIELD_OWNER) != 0)
				continue;

			if(!obj->m_loadedFromDB)
				continue;
		}

		if( obj->Active )
			obj->Deactivate( _mapmgr );

		if( obj->IsInWorld())
			obj->RemoveFromWorld( true );

		delete obj;
		obj = NULL;
	}
	_objects.clear();

	_playerCount = 0;
	_loaded = false;
}

void MapCell::LoadObjects(CellSpawns * sp)
{
	_loaded = true;
	Instance * pInstance = _mapmgr->pInstance;

	if(sp->CreatureSpawns.size()) // got creatures
	{
		Vehicle* v = NULL;
		Creature* c = NULL;
		for(CreatureSpawnList::iterator i=sp->CreatureSpawns.begin();i!=sp->CreatureSpawns.end();i++)
		{
			if(pInstance)
			{
				if(pInstance->m_killedNpcs.find((*i)->id) != pInstance->m_killedNpcs.end())
					continue;

			}
			if((*i)->vehicle != 0)
			{
				v =_mapmgr->CreateVehicle((*i)->entry);
				if(v == NULL)
					continue;

				v->SetMapId(_mapmgr->GetMapId());
				v->SetInstanceID(_mapmgr->GetInstanceID());
				v->m_loadedFromDB = true;

				if(v->Load(*i, _mapmgr->iInstanceMode, _mapmgr->GetMapInfo()))
				{
					if(!v->CanAddToWorld())
					{
						delete v;
						v = NULL;
						continue;
					}

					v->PushToWorld(_mapmgr);
				}
				else
				{
					delete v;
					v = NULL;
				}
			}
			else
			{
				c=_mapmgr->CreateCreature((*i)->entry);
				if(c == NULL)
					continue;

				c->SetMapId(_mapmgr->GetMapId());
				c->SetInstanceID(_mapmgr->GetInstanceID());
				c->m_loadedFromDB = true;

				if(c->Load(*i, _mapmgr->iInstanceMode, _mapmgr->GetMapInfo()))
				{
					if(!c->CanAddToWorld())
					{
						delete c;
						c = NULL;
						continue;
					}

					c->PushToWorld(_mapmgr);
				}
				else
				{
					delete c;
					c = NULL;
				}
			}
		}
	}

	if(sp->GOSpawns.size()) // got GOs
	{
		GameObject* go;
		for(GOSpawnList::iterator i=sp->GOSpawns.begin();i!=sp->GOSpawns.end();i++)
		{
			go = _mapmgr->CreateGameObject((*i)->entry);
			if(go == NULL)
				continue;
			if(go->Load(*i))
			{
				go->m_loadedFromDB = true;
				go->PushToWorld(_mapmgr);
				CALL_GO_SCRIPT_EVENT(go, OnSpawn)();
			}
			else
			{
				delete go;
				go = NULL;
			}
		}
	}
}
void MapCell::QueueUnloadPending()
{
	if(_unloadpending)
		return;

	_unloadpending = true;
	sEventMgr.AddEvent(_mapmgr, &MapMgr::UnloadCell,(uint32)_x,(uint32)_y,MAKE_CELL_EVENT(_x,_y),sWorld.map_unload_time * 1000,1,0);
}

void MapCell::CancelPendingUnload()
{
	if(!_unloadpending)
		return;

	sEventMgr.RemoveEvents(_mapmgr,MAKE_CELL_EVENT(_x,_y));
}

void MapCell::Unload()
{
	ASSERT(_unloadpending);
	if(_active)
		return;

	RemoveObjects();
	_unloadpending = false;
}

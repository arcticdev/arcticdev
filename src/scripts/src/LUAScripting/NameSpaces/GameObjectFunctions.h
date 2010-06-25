#ifndef GOFUNCTIONS_H
#define GOFUNCTIONS_H

namespace luaGameObject
{
	// Begin - GO - Gossip Functions.
	int GossipCreateMenu(lua_State * L, GameObjectPointer ptr);
	int GossipMenuAddItem(lua_State * L, GameObjectPointer ptr);
	int GossipSendMenu(lua_State * L, GameObjectPointer ptr);
	int GossipComplete(lua_State * L, GameObjectPointer ptr);
	int GossipSendPOI(lua_State * L, GameObjectPointer ptr);
	// End - Go - Gossip Functions.
	int PlaySoundToSet(lua_State * L, GameObjectPointer ptr);
	int GetName(lua_State * L, GameObjectPointer ptr);
	int Teleport(lua_State * L, GameObjectPointer ptr);
	int GetClosestPlayer(lua_State * L, GameObjectPointer ptr);
	int GetZoneId(lua_State *L, GameObjectPointer ptr);
	int GetItemCount(lua_State * L, GameObjectPointer ptr);
	int GetSpawnX(lua_State * L, GameObjectPointer ptr);
	int GetSpawnY(lua_State * L, GameObjectPointer ptr);
	int GetSpawnZ(lua_State * L, GameObjectPointer ptr);
	int GetSpawnO(lua_State * L, GameObjectPointer ptr);
	int GetInRangePlayersCount(lua_State * L, GameObjectPointer ptr);
	int GetEntry(lua_State * L, GameObjectPointer ptr);
	int GetX(lua_State * L, GameObjectPointer ptr);
	int GetY(lua_State * L, GameObjectPointer ptr);
	int GetZ(lua_State * L, GameObjectPointer ptr);
	int GetO(lua_State * L, GameObjectPointer ptr);
	int GetInRangePlayers(lua_State * L, GameObjectPointer ptr);
	int GetInRangeGameObjects(lua_State * L, GameObjectPointer ptr);
	int GetInstanceID(lua_State * L, GameObjectPointer ptr);
	int GetUInt64Value(lua_State * L, GameObjectPointer ptr);
	int GetUInt32Value(lua_State * L, GameObjectPointer ptr);
	int GetFloatValue(lua_State * L, GameObjectPointer ptr);
	int GetGUID(lua_State * L, GameObjectPointer  ptr);
	int AddItem(lua_State * L, GameObjectPointer ptr);
	int Despawn(lua_State * L, GameObjectPointer ptr);
	int IsInWorld(lua_State * L, GameObjectPointer ptr);
	int IsInBack(lua_State * L, GameObjectPointer ptr);
	int IsInFront(lua_State * L, GameObjectPointer ptr);
	int SpawnCreature(lua_State * L, GameObjectPointer ptr);
	int SpawnGameObject(lua_State * L, GameObjectPointer ptr);
	int CalcDistance(lua_State * L, GameObjectPointer ptr);
	int SetOrientation(lua_State * L, GameObjectPointer ptr);
	int RemoveFromWorld(lua_State * L, GameObjectPointer ptr);
	int CalcRadAngle(lua_State * L, GameObjectPointer ptr);
	int SetUInt32Value(lua_State * L, GameObjectPointer ptr);
	int SetUInt64Value(lua_State * L, GameObjectPointer ptr);
	int SetFloatValue(lua_State * L, GameObjectPointer ptr);
	int ModUInt32Value(lua_State * L, GameObjectPointer ptr);
	int CastSpell(lua_State * L, GameObjectPointer ptr);
	int FullCastSpell(lua_State * L, GameObjectPointer ptr);
	int CastSpellOnTarget(lua_State * L, GameObjectPointer ptr);
	int FullCastSpellOnTarget(lua_State * L, GameObjectPointer ptr);
	int Despawn(lua_State * L, GameObjectPointer ptr);
	int RegisterAIUpdateEvent(lua_State * L, GameObjectPointer ptr);
	int ModifyAIUpdateEvent(lua_State * L, GameObjectPointer ptr);
	int RemoveAIUpdateEvent(lua_State * L, GameObjectPointer ptr);
	int OnGameObjectEvent(lua_State * L, GameObjectPointer ptr);
	int GetCreatureNearestCoords(lua_State * L, GameObjectPointer ptr);
	int GetGameObjectNearestCoords(lua_State * L, GameObjectPointer ptr);
	/* Date : 01/07/2009 */
	int SetSpawnPosition(lua_State * L, GameObjectPointer ptr);
	int SaveToDB(lua_State * L, GameObjectPointer ptr);
	int DeleteFromDB(lua_State * L, GameObjectPointer ptr);
	int WorldQuery(lua_State * L, GameObjectPointer ptr);
	/* End Date: 01/07/2009 */
}
#endif

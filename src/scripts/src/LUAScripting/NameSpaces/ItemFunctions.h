	// Full Credits To LuaAppArc
#ifndef ITEMFUNCTIONS_H
#define ITEMFUNCTIONS_H

namespace luaItem
{
	int GossipCreateMenu(lua_State * L, ItemPointer  ptr);
	int GossipMenuAddItem(lua_State * L, ItemPointer  ptr);
	int GossipSendMenu(lua_State * L, ItemPointer  ptr);
	int GossipComplete(lua_State * L, ItemPointer  ptr);
	int GossipSendPOI(lua_State * L, ItemPointer  ptr);
}
#endif
/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2011 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

extern SQLStorage<ItemPrototype, ArrayStorageContainer<ItemPrototype> >				ItemPrototypeStorage;
extern SQLStorage<CreatureInfo, HashMapStorageContainer<CreatureInfo> >				CreatureNameStorage;
extern SQLStorage<GameObjectInfo, HashMapStorageContainer<GameObjectInfo> >			GameObjectNameStorage;
extern SQLStorage<ItemPage, HashMapStorageContainer<ItemPage> >						ItemPageStorage;
extern SQLStorage<Quest, HashMapStorageContainer<Quest> >							QuestStorage;
extern SQLStorage<GossipText, HashMapStorageContainer<GossipText> >					NpcTextStorage;
extern SQLStorage<MapInfo, HashMapStorageContainer<MapInfo> >						WorldMapInfoStorage;

void Storage_Cleanup();
void Storage_Load();
bool Storage_ReloadTable(const char * TableName);

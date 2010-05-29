/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef OBJECT_STORAGE_H
#define OBJECT_STORAGE_H

extern ARCTIC_DECL SQLStorage<ItemPrototype, ArrayStorageContainer<ItemPrototype> >					ItemPrototypeStorage;
extern ARCTIC_DECL SQLStorage<CreatureInfo, HashMapStorageContainer<CreatureInfo> >					CreatureNameStorage;
extern ARCTIC_DECL SQLStorage<GameObjectInfo, HashMapStorageContainer<GameObjectInfo> >				GameObjectNameStorage;
extern ARCTIC_DECL SQLStorage<CreatureProto, HashMapStorageContainer<CreatureProto> >				CreatureProtoStorage;
extern ARCTIC_DECL SQLStorage<CreatureProtoHeroic, HashMapStorageContainer<CreatureProtoHeroic> >	CreatureProtoHeroicStorage;
extern ARCTIC_DECL SQLStorage<CreatureProtoVehicle, HashMapStorageContainer<CreatureProtoVehicle> >	CreatureProtoVehicleStorage;
extern ARCTIC_DECL SQLStorage<AreaTrigger, HashMapStorageContainer<AreaTrigger> >					AreaTriggerStorage;
extern ARCTIC_DECL SQLStorage<ItemPage, HashMapStorageContainer<ItemPage> >							ItemPageStorage;
extern ARCTIC_DECL SQLStorage<Quest, HashMapStorageContainer<Quest> >								QuestStorage;
extern ARCTIC_DECL SQLStorage<GossipText, HashMapStorageContainer<GossipText> >						NpcTextStorage;
extern ARCTIC_DECL SQLStorage<GraveyardTeleport, HashMapStorageContainer<GraveyardTeleport> >		GraveyardStorage;
extern ARCTIC_DECL SQLStorage<TeleportCoords, HashMapStorageContainer<TeleportCoords> >				TeleportCoordStorage;
extern ARCTIC_DECL SQLStorage<FishingZoneEntry, HashMapStorageContainer<FishingZoneEntry> >			FishingZoneStorage;
extern ARCTIC_DECL SQLStorage<MapInfo, ArrayStorageContainer<MapInfo> >								WorldMapInfoStorage;
extern ARCTIC_DECL SQLStorage<ZoneGuardEntry, HashMapStorageContainer<ZoneGuardEntry> >				ZoneGuardStorage;
extern ARCTIC_DECL SQLStorage<AchievementReward, HashMapStorageContainer<AchievementReward> >		AchievementRewardStorage;
extern ARCTIC_DECL SQLStorage<RandomItemCreation, HashMapStorageContainer<RandomItemCreation> >		RandomItemCreationStorage;
extern ARCTIC_DECL SQLStorage<RandomCardCreation, HashMapStorageContainer<RandomCardCreation> >		RandomCardCreationStorage;
extern ARCTIC_DECL SQLStorage<ScrollCreation, HashMapStorageContainer<ScrollCreation> >				ScrollCreationStorage;

void Storage_FillTaskList(TaskList & tl);
void Storage_Cleanup();
bool Storage_ReloadTable(const char * TableName);
void Storage_LoadAdditionalTables();

extern ARCTIC_DECL set<string> ExtraMapCreatureTables;
extern ARCTIC_DECL set<string> ExtraMapGameObjectTables;

#endif

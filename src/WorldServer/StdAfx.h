/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __STDAFX_H
#define __STDAFX_H

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#define _GAME

#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <string>
//#include <fstream>

#include "../libs/Common.h"
#include "../libs/MersenneTwister.h"
#include "../libs/WorldPacket.h"
#include "../libs/Log.h"
#include "../libs/NGLog.h"
#include "../libs/ByteBuffer.h"
#include "../libs/StackBuffer.h"
#include "../libs/Config/ConfigEnv.h"
#include "../libs/crc32.h"
#include "../libs/LocationVector.h"
#include "../libs/hashmap.h"

#include "../libs/Collision/vmap/IVMapManager.h"
#include "../libs/Collision/vmap/VMapManager.h"

#include "../../dep/vc/include/zlib.h"

#include <DataStorage/DatabaseEnv.h>
#include <DataStorage/DBCStores.h>
#include <DataStorage/dbcfile.h>

#include <Network/Network.h>

#include "../libs/Auth/MD5.h"
#include "../libs/Auth/BigNumber.h"
#include "../libs/Auth/Sha1.h"
#include "../libs/Auth/WowCrypt.h"
#include "../libs/CrashHandler.h"
#include "../libs/FastQueue.h"
#include "../libs/CircularQueue.h"
#include "../libs/Threading/RWLock.h"
#include "../libs/Threading/Condition.h"
#include "../libs/Getopt.h"
#include "../libs/BufferPool.h"

#include "Const.h"
#include "NameTables.h"
#include "UpdateFields.h"
#include "UpdateMask.h"
#include "Opcodes.h"
#include "WorldStates.h"

#ifdef CLUSTERING
	#include "../ClusterServer/WorkerOpcodes.h"
#endif

#include "Packets.h"

#include "../libs/CallBack.h"
#include "WordFilter.h"
#include "EventMgr.h"
#include "EventableObject.h"
#include "Object.h"
#include "LootMgr.h"
#include "Unit.h"

#include "AddonMgr.h"
#include "AIInterface.h"
#include "AreaTrigger.h"
#include "BattlegroundMgr.h"
#include "AlteracValley.h"
#include "ArathiBasin.h"
#include "EyeOfTheStorm.h"
#include "Arenas.h"
#include "CellHandler.h"
#include "Chat.h"
#include "Corpse.h"
#include "Quest.h"
#include "QuestMgr.h"
#include "Creature.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Group.h"
#include "Guild.h"
#include "HonorHandler.h"
#include "ItemPrototype.h"
#include "Item.h"
#include "Container.h"
#include "AuctionHouse.h"
#include "AuctionMgr.h"
#include "LfgMgr.h"
#include "MailSystem.h"
#include "Map.h"
#include "MapCell.h"
#include "TerrainMgr.h"
#include "MiscHandler.h"
#include "NPCHandler.h"
#include "Pet.h"
#include "WorldSocket.h"
#include "World.h"
#include "WorldSession.h"
#include "WorldStateManager.h"
#include "MapMgr.h"
#include "MapScriptInterface.h"
#include "Player.h"
#include "faction.h"
#include "Skill.h"
#include "SkillNameMgr.h"
#include "SpellNameHashes.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "TaxiMgr.h"
#include "TransporterHandler.h"
#include "WarsongGulch.h"
#include "WeatherMgr.h"
#include "ItemInterface.h"
#include "Stats.h"
#include "ObjectMgr.h"
#include "WorldCreator.h"
#include "ScriptMgr.h"
#include "Channel.h"
#include "ChannelMgr.h"
#include "ArenaTeam.h"
#include "LogonCommClient.h"
#include "LogonCommHandler.h"
#include "MainServerDefines.h"
#include "WorldRunnable.h"
#include "../libs/Storage.h"
#include "ObjectStorage.h"
#include "DayWatcherThread.h"
#include "Vehicle.h"
#include "AchievementInterface.h"
#include "ChainAggroEntity.h"
#include "StrandOfTheAncients.h"
#include "TheIsleOfConquest.h"
#include "Wintergrasp.h"

#ifdef CLUSTERING
	#include "WorkerServerClient.h"
	#include "ClusterInterface.h"
#endif

#include "CollideInterface.h"

#include "Master.h"
#include "BaseConsole.h"
// #define COLLECTION_OF_UNTESTED_STUFF_AND_TESTERS 1

#endif

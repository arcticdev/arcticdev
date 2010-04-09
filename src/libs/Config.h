/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Enable/disable ArcTic world server cluster support.
// Warning: ArcTic will no longer function independantly when built in cluster mode. 
// It will require a realmserver to function.
// As of last update, it is nowhere near complete, only enable for dev use.
// Default: Disabled

#ifdef ENABLE_CLUSTERING
#  error Sorry but clustering is not finished yet. dont bother to try to compile it. it wont work.
#  define CLUSTERING 1
#endif
// #define CLUSTERING 1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Use memory mapping for map files for faster access (let OS take care of caching)
// (currently only available under windows)
// Only recommended under X64 builds, X86 builds will most likely run out of address space.
// Default: Disabled

// #define USE_MEMORY_MAPPING_FOR_MAPS

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Enable/disable ArcTic's Voice Chat support.
// While not completely finished (but close!) you can link your ArcTic server to a voice chat
// server (also compiled by default) and use the client's ingame voice chat function.
// At the moment it is only good for joining, you can't leave a voice channel yet :P
// Also, it only works for parties. Custom chat channels are not fully supported yet.
// However, if you want to play around with it, feel free to enable this define.
// Default: Disabled

// #define VOICE_CHAT 1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Enable/disable movement compression.
// This allows the server to compress long-range creatures movement into a buffer and then flush
// it periodically, compressed with deflate. This can make a large difference to server bandwidth.
// Currently this sort of compression is only used for player and creature movement, although
// it may be expanded in the future.
// Default: disabled

#define ENABLE_COMPRESSED_MOVEMENT 1
#define ENABLE_COMPRESSED_MOVEMENT_FOR_PLAYERS 1
#define ENABLE_COMPRESSED_MOVEMENT_FOR_CREATURES 1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Allow loading of unused testmaps.
// Default: disabled

// #define EXCLUDE_TEST_MAPS 1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Enable/disable using of shared pointers.
// This allows core to use "brain" pointers.
// Default: enabled

// #define USING_SHARED_PTRS   // script stuff(you can easily turn on shared pointers if your scripts support it)
// #define SHAREDPTR_DEBUGMODE // devs only, or prepare for spam, seriously.
#define SHARED_PTR_MODE_ON

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Localization - For transfer into different languages.
// RURU - Russian Local.
// ENGB - English Local.

////////////////////////////////////////////////////////////////////////////////////
// A
#define ARENATEAM_RURU 1
// #define ARENATEAM_ENGB 1
#define AUTHCOMMCLIENT_RURU 1
// #define AUTHCOMMCLIENT_ENGB 1
#define AUTHCOMMHANDLER_RURU 1
// #define AUTHCOMMHANDLER_ENGB 1
////////////////////////////////////////////////////////////////////////////////////
// B
#define BATTLEGROUNDMGR_RURU 1
// #define BATTLEGROUNDMGR_ENGB 1
////////////////////////////////////////////////////////////////////////////////////
// C
#define CHARACTERHANDLER_RURU 1
// #define CHARACTERHANDLER_ENGB 1
#define CHAT_RURU 1
// #define CHAT_ENGB 1
#define CHATHANDLER_RURU 1
// #define CHATHANDLER_ENGB 1
#define CLUSTERINTERFACE_RURU 1
// #define CLUSTERINTERFACE_ENGB 1
#define COMBATHANDLER_RURU 1
// #define COMBATHANDLER_ENGB 1
#define COMMON_RURU 1
// #define COMMON_ENGB 1
#define CONSOLECOMMANDS_RURU 1
// #define CONSOLECOMMANDS_ENGB 1
#define CONSOLELISTENER_RURU 1
// #define CONSOLELISTENER_ENGB 1
#define CONTAINER_RURU 1
// #define CONTAINER_ENGB 1
#define CREATURE_RURU 1
// #define CREATURE_ENGB 1
#define DAYWATCHERTHREAD_RURU 1
// #define DAYWATCHERTHREAD_ENGB 1
#define DEBUGCMDS_RURU 1
// #define DEBUGCMDS_ENGB 1
////////////////////////////////////////////////////////////////////////////////////
// E
#define EYEOFTHESTORM_RURU 1
// #define EYEOFTHESTORM_ENGB 1
////////////////////////////////////////////////////////////////////////////////////
// G
#define GAMEOBJECT_RURU 1
// #define GAMEOBJECT_ENGB 1
#define GMTICKET_RURU 1
// #define GMTICKET_ENGB 1
#define GROUP_RURU 1
// #define GROUP_ENGB 1
#define GUILD_RURU 1
// #define GUILD_ENGB 1
#define GUILDHANDLER_RURU 1
// #define GUILDHANDLER_ENGB 1
////////////////////////////////////////////////////////////////////////////////////
// H
#define HONORHANDLER_RURU 1
// #define HONORHANDLER_ENGB 1
////////////////////////////////////////////////////////////////////////////////////
// I
#define ITEM_RURU 1
// #define ITEM_ENGB 1
#define ITEMHANDLER_RURU 1
// #define ITEMHANDLER_ENGB 1
#define ITEMINTERFACE_RURU 1
// #define ITEMINTERFACE_ENGB 1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// To choose localisation files.

////////////////////////////////////////////////////////////////////////////////////
// A
#ifdef ARENATEAM_RURU
// #ifdef ARENATEAM_ENGB
#ifdef AUTHCOMMCLIENT_RURU
// #ifdef AUTHCOMMCLIENT_ENGB
#ifdef AUTHCOMMHANDLER_RURU
// #ifdef AUTHCOMMHANDLER_ENGB
////////////////////////////////////////////////////////////////////////////////////
// B
#ifdef BATTLEGROUNDMGR_RURU
// #ifdef BATTLEGROUNDMGR_ENGB
////////////////////////////////////////////////////////////////////////////////////
// C
#ifdef CHARACTERHANDLER_RURU 
// #ifdef CHARACTERHANDLER_ENGB 
#ifdef CHAT_RURU
// #ifdef CHAT_ENGB
#ifdef  CHATHANDLER_RURU 
// #ifdef CHATHANDLER_ENGB 
#ifdef CLUSTERINTERFACE_RURU
// #ifdef CLUSTERINTERFACE_ENGB
#ifdef COMBATHANDLER_RURU 
// #ifdef COMBATHANDLER_ENGB 
#ifdef COMMON_RURU
// #ifdef COMMON_ENGB
#ifdef CONSOLECOMMANDS_RURU
// #ifdef CONSOLECOMMANDS_ENGB 
#ifdef CONSOLELISTENER_RURU 
// #ifdef CONSOLELISTENER_ENGB 
#ifdef CONTAINER_RURU
// #ifdef CONTAINER_ENGB
#ifdef CREATURE_RURU 
// #ifdef CREATURE_ENGB 
#ifdef DAYWATCHERTHREAD_RURU 
// #ifdef DAYWATCHERTHREAD_ENGB 
#ifdef DEBUGCMDS_RURU 
// #ifdef DEBUGCMDS_ENGB 
////////////////////////////////////////////////////////////////////////////////////
// E
#ifdef EYEOFTHESTORM_RURU 
// #ifdef EYEOFTHESTORM_ENGB 
////////////////////////////////////////////////////////////////////////////////////
// G
#ifdef GAMEOBJECT_RURU 
// #ifdef GAMEOBJECT_ENGB 
#ifdef GMTICKET_RURU 
// #ifdef GMTICKET_ENGB 
#ifdef GROUP_RURU 
// #ifdef GROUP_ENGB 
#ifdef GUILD_RURU 
// #ifdef GUILD_ENGB 
#ifdef GUILDHANDLER_RURU
// #ifdef GUILDHANDLER_ENGB
////////////////////////////////////////////////////////////////////////////////////
// H
#ifdef HONORHANDLER_RURU 
// #ifdef HONORHANDLER_ENGB 
////////////////////////////////////////////////////////////////////////////////////
// I
#ifdef ITEM_RURU 
// #ifdef ITEM_ENGB 
#ifdef ITEMHANDLER_RURU 
// #ifdef ITEMHANDLER_ENGB 
#ifdef ITEMINTERFACE_RURU 
// #ifdef ITEMINTERFACE_ENGB 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// To choose localisation files.

////////////////////////////////////////////////////////////////////////////////////
// A
#include "locale/ArenaTeam/ruRU_ArenaTeam.h"
#else
#include "locale/ArenaTeam/enGB_ArenaTeam.h"
#endif
#include "locale/AuthCommClient/ruRU_AuthCommClient.h"
#else
#include "locale/AuthCommClient/enGB_AuthCommClient.h"
#endif
#include "locale/AuthCommHandler/ruRU_AuthCommHandler.h"
#else
#include "locale/AuthCommHandler/enGB_AuthCommHandler.h"
#endif
////////////////////////////////////////////////////////////////////////////////////
// B
#include "locale/BattlegroundMgr/ruRU_BattlegroundMgr.h"
#else
#include "locale/BattlegroundMgr/enGB_BattlegroundMgr.h"
#endif
////////////////////////////////////////////////////////////////////////////////////
// C
#include "locale/CharacterHandler/ruRU_CharacterHandler.h"
#else
#include "locale/CharacterHandler/enGB_CharacterHandler.h"
#endif
#include "locale/Chat/ruRU_Chat.h"
#else
#include "locale/Chat/enGB_Chat.h"
#endif
#include "locale/ChatHandler/ruRU_ChatHandler.h"
#else
#include "locale/ChatHandler/enGB_ChatHandler.h"
#endif
#include "locale/ClusterInterface/ruRU_ClusterInterface.h"
#else
#include "locale/ClusterInterface/enGB_ClusterInterface.h"
#endif
#include "locale/CombatHandler/ruRU_CombatHandler.h"
#else
#include "locale/CombatHandler/enGB_CombatHandler.h"
#endif
#include "locale/Common/ruRU_Common.h"
#else
#include "locale/Common/enGB_Common.h"
#endif
#include "locale/ConsoleCommands/ruRU_ConsoleCommands.h"
#else
#include "locale/ConsoleCommands/enGB_ConsoleCommands.h"
#endif
#include "locale/ConsoleListener/ruRU_ConsoleListener.h"
#else
#include "locale/ConsoleListener/enGB_ConsoleListener.h"
#endif
#include "locale/Container/ruRU_Container.h"
#else
#include "locale/Container/enGB_Container.h"
#endif
#include "locale/Creature/ruRU_Creature.h"
#else
#include "locale/Creature/enGB_Creature.h"
#endif
#include "locale/DayWatcherThread/ruRU_DayWatcherThread.h"
#else
#include "locale/DayWatcherThread/enGB_DayWatcherThread.h"
#endif
#include "locale/Debugcmds/ruRU_Debugcmds.h"
#else
#include "locale/Debugcmds/enGB_Debugcmds.h"
#endif
////////////////////////////////////////////////////////////////////////////////////
// E
#include "locale/EyeOfTheStorm/ruRU_EyeOfTheStorm.h"
#else
#include "locale/EyeOfTheStorm/enGB_EyeOfTheStorm.h"
#endif
////////////////////////////////////////////////////////////////////////////////////
// G
#include "locale/GameObject/ruRU_GameObject.h"
#else
#include "locale/GameObject/enGB_GameObject.h"
#endif
#include "locale/GMTicket/ruRU_GMTicket.h"
#else
#include "locale/GMTicket/enGB_GMTicket.h"
#endif
#include "locale/Group/ruRU_Group.h"
#else
#include "locale/Group/enGB_Group.h"
#endif
#include "locale/Guild/ruRU_Guild.h"
#else
#include "locale/Guild/enGB_Guild.h"
#endif
#include "locale/GuildHandler/ruRU_GuildHandler.h"
#else
#include "locale/GuildHandler/enGB_GuildHandler.h"
#endif
////////////////////////////////////////////////////////////////////////////////////
// H
#include "locale/HonorHandler/ruRU_HonorHandler.h"
#else
#include "locale/HonorHandler/enGB_HonorHandler.h"
#endif
////////////////////////////////////////////////////////////////////////////////////
// I
#include "locale/Item/ruRU_Item.h"
#else
#include "locale/Item/enGB_Item.h"
#endif
#include "locale/ItemHandler/ruRU_ItemHandler.h"
#else
#include "locale/ItemHandler/enGB_ItemHandler.h"
#endif
#include "locale/ItemInterface/ruRU_ItemInterface.h"
#else
#include "locale/ItemInterface/enGB_ItemInterface.h"
#endif

#endif	// __CONFIG_H

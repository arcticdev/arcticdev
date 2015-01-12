/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2014 Arctic Server Team
 * See COPYING for license details.
 */

///////////////////////////////////////////////////////////////////////////////////////////////////////
// ArcTic Configuration Header File                                                                  //
// Feel free to customize to your needs.                                                             //
///////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Enable/distance Sticky NPC movement, npcs will follow terrain.
// This code is optimized and shouldn't use too much CPU usage (the usage per npc is in nanoseconds)
// Don't enable this unless you have all vmaps and maps.
// Default: Disabled

// #define STICKY_NPC_MOVEMENT 

///////////////////////////////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Enable/disable 3D geometry calculations
// Warning: This may be resource heavy.
// As of last update, it was nowhere near complete. Only enable for dev use.
// Default: Disabled

#ifdef ENABLE_COLLISION
# define COLLISION 1
#endif
#define COLLISION 1

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Use memory mapping for map files for faster access (let OS take care of caching)
// (currently only available under windows)
// Only recommended under X64 builds, X86 builds will most likely run out of address space.
// Default: Disabled

// #define USE_MEMORY_MAPPING_FOR_MAPS

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Enable/disable movement compression.
// This allows the server to compress long-range creatures movement into a buffer and then flush
// it periodically, compressed with deflate. This can make a large difference to server bandwidth.
// Currently this sort of compression is only used for player and creature movement, although
// it may be expanded in the future.
// Default: Disabled

#define ENABLE_COMPRESSED_MOVEMENT 1
#define ENABLE_COMPRESSED_MOVEMENT_FOR_PLAYERS 1
#define ENABLE_COMPRESSED_MOVEMENT_FOR_CREATURES 1

///////////////////////////////////////////////////////////////////////////////////////////////////////
// DATABASE LAYER SET UP                                                                             //
///////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Enable/disable database backends.
// Currently supported, MySQL, (under development): PostgreSQL, SQLite
// Default: Disabled

// #if !defined(NO_DBLAYER_MYSQL)
// #define ENABLE_DATABASE_MYSQL 1
// #endif
// #define ENABLE_DATABASE_POSTGRES 1
// #define ENABLE_DATABASE_SQLITE 1

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Optimize the server for MySQL usage.
// This may give a small boost to performance.
// Enable it if you do not plan on using ArcTic with PostgreSQL or SQLite.
// Default: Disabled

// #define OPTIMIZE_SERVER_FOR_MYSQL 1

/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __CONST_H__
#define __CONST_H__

//////////////////////////////////////////////////////////////////////////
// Global defines                                                       //
//////////////////////////////////////////////////////////////////////////

#define NUM_MAPS         750

#define TAXI_NODES        12

#define TOTEM_SLOTS        4
#define OBJECT_SLOTS       4

// Spells
#define GROWL_RANK_1    2649
#define GROWL_RANK_2   14916
#define WATER_ELEMENTAL  510
#define SHADOWFIEND    19668

// Enums
enum Stats
{
	STAT_STRENGTH,
	STAT_AGILITY,
	STAT_STAMINA,
	STAT_INTELLECT,
	STAT_SPIRIT,
	STAT_TOTAL
};

enum School
{
	SCHOOL_NORMAL = 0,
	SCHOOL_HOLY = 1,
	SCHOOL_FIRE = 2,
	SCHOOL_NATURE = 3,
	SCHOOL_FROST = 4,
	SCHOOL_SHADOW = 5,
	SCHOOL_ARCANE = 6,
	SCHOOL_TOTAL = 7
};

#endif

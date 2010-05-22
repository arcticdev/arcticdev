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

enum UNIT_TYPE
{
	UNIT_TYPE_NONE = 0,
	UNIT_TYPE_BEAST = 1,
	UNIT_TYPE_DRAGONKIN = 2,
	UNIT_TYPE_DEMON = 3,
	UNIT_TYPE_ELEMENTAL = 4,
	UNIT_TYPE_GIANT = 5,
	UNIT_TYPE_UNDEAD = 6,
	UNIT_TYPE_HUMANOID = 7,
	UNIT_TYPE_CRITTER = 8,
	UNIT_TYPE_MECHANICAL = 9,
	UNIT_TYPE_MISC = 10,
	UNIT_TYPE_TOTEM = 11,
	UNIT_TYPE_NONCOMBAT_PET = 12,
	UNIT_TYPE_GAS_CLOUD = 13,
	UNIT_TYPE_TOTAL = 14
};

enum DISPEL_TYPE
{
	DISPEL_ZGTRINKETS = -1,
	DISPEL_NULL,
	DISPEL_MAGIC,
	DISPEL_CURSE,
	DISPEL_DISEASE,
	DISPEL_POISON,
	DISPEL_STEALTH,
	DISPEL_INVISIBILTY,
	DISPEL_ALL,
	DISPEL_SPECIAL_NPCONLY,
	DISPEL_FRENZY,
	NUM_DISPELS,
};

#endif

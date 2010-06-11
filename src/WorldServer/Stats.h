/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __STATS_H
#define __STATS_H

#include "Unit.h"
#include "UpdateMask.h"
#include "ItemInterface.h"

enum Resistances
{
	RESISTANCE_ARMOR,
	RESISTANCE_HOLY,
	RESISTANCE_FIRE,
	RESISTANCE_NATURE,
	RESISTANCE_FROST,
	RESISTANCE_SHADOW,
	RESISTANCE_ARCANE
};

ARCTIC_DECL uint32 getConColor(uint16 AttackerLvl, uint16 VictimLvl);
ARCTIC_DECL uint32 CalculateXpToGive(Unit* pVictim, Unit* pAttacker);
ARCTIC_DECL uint32 CalculateStat(uint16 level,double a3, double a2, double a1, double a0);
ARCTIC_DECL uint32 CalculateDamage( Unit* pAttacker, Unit* pVictim, uint32 weapon_damage_type, SpellEntry* ability);
ARCTIC_DECL uint32 CalcStatForLevel(uint16 level, uint8 playerclass,uint8 Stat);
ARCTIC_DECL bool isEven (int num);

#endif

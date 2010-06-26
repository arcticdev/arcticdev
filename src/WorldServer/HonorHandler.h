/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef HONORHANDLER_H
#define HONORHANDLER_H

class HonorHandler
{
public:
	static int32 CalculateHonorPointsForKill(PlayerPointer pPlayer, UnitPointer pVictim);
	static void RecalculateHonorFields(PlayerPointer pPlayer);
	static void AddHonorPointsToPlayer(PlayerPointer pPlayer, uint32 uAmount);
	static void OnPlayerKilledUnit(PlayerPointer pPlayer, UnitPointer pVictim);	
	static int32 CalculateHonorPointsFormula(uint32 AttackerLevel,uint32 VictimLevel);
};


#endif

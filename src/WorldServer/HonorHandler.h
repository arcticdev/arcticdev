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
	static int32 CalculateHonorPointsForKill(Player* pPlayer, Unit* pVictim);
	static void RecalculateHonorFields(Player* pPlayer);
	static void AddHonorPointsToPlayer(Player* pPlayer, uint32 uAmount);
	static void OnPlayerKilledUnit(Player* pPlayer, Unit* pVictim);	
	static int32 CalculateHonorPointsFormula(uint32 AttackerLevel,uint32 VictimLevel);
};


#endif

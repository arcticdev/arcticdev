/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#pragma once

class HonorHandler
{
public:
	static int32 CalculateHonorPointsForKill(Player* pPlayer, Unit* pVictim);
	static void RecalculateHonorFields(Player* pPlayer);
	static void AddHonorPointsToPlayer(Player* pPlayer, uint32 uAmount);
	static void OnPlayerKilledUnit(Player* pPlayer, Unit* pVictim);
	static int32 CalculateHonorPointsFormula(uint32 AttackerLevel,uint32 VictimLevel);
	static void UpdateCurrencyItem(Player* pPlayer, uint32 itemid, uint32 amount);
};

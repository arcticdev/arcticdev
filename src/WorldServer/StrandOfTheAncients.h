/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#pragma once

static const float SOTAStartLocations[2][3] =
{
	{ 1601.004395f, -105.182663f, 8.873691f }, //attackers
	{ 922.102234f, -111.102646f, 97.178421f }, //defenders
};

class StrandOfTheAncients : public CBattleground
{
public:
	StrandOfTheAncients(MapMgr* mgr, uint32 id, uint32 lgroup, uint32 t);
	~StrandOfTheAncients();
	virtual void Init();

	void HookOnPlayerDeath(Player* plr);
	void HookFlagDrop(Player* plr, GameObject* obj);
	void HookFlagStand(Player* plr, GameObject* obj);
	void HookOnMount(Player* plr);
	void HookOnAreaTrigger(Player* plr, uint32 id);
	bool HookHandleRepop(Player* plr);
	void OnAddPlayer(Player* plr);
	void OnRemovePlayer(Player* plr);
	void OnCreate();
	void HookOnPlayerKill(Player* plr, Unit* pVictim);
	void HookOnHK(Player* plr);
	void HookOnShadowSight();
	LocationVector GetStartingCoords(uint32 Team);

	static CBattleground* Create(MapMgr* m, uint32 i, uint32 l, uint32 t) { return new StrandOfTheAncients(m, i, l, t); }

	const char * GetName() { return "Strand of the Ancients"; }
	void OnStart();

	bool SupportsPlayerLoot() { return true; }
	bool HookSlowLockOpen(GameObject* pGo, Player* pPlayer, Spell* pSpell);

	void HookGenerateLoot(Player* plr, Corpse* pCorpse);

	void SetIsWeekend(bool isweekend);
	void SetTime(uint32 secs, uint32 WorldState);
	uint32 GetRoundTime(){ return RoundTime; };
	void SetRoundTime(uint32 secs){ RoundTime = secs; };
	void TimeTick();
	void PrepareRound();
protected:
	uint32 Attackers; // 0 - horde / 1 - alliance
	uint32 BattleRound;
	uint32 RoundTime;
};

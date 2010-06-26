/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#define BUFF_RESPAWN_TIME 90000

class WarsongGulch : public CBattleground
{
	GameObjectPointer m_buffs[6];
	GameObjectPointer m_homeFlags[2];
	GameObjectPointer m_dropFlags[2];
	uint32 m_flagHolders[2];
	list<GameObjectPointer > m_gates;
	uint32 m_scores[2];
	uint32 m_lgroup;
	bool m_flagAtBase[2];
	uint32 m_FlagCaptureHonor;
	uint32 m_WinHonor;
	uint32 m_CompleteHonor;
public:
	WarsongGulch(MapMgrPointer mgr, uint32 id, uint32 lgroup, uint32 t);
	~WarsongGulch();

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

	virtual void Init();

	void HookOnPlayerDeath(PlayerPointer plr);
	void HookFlagDrop(PlayerPointer plr, GameObjectPointer obj);
	void HookFlagStand(PlayerPointer plr, GameObjectPointer obj);
	void HookOnMount(PlayerPointer plr);
	void HookOnAreaTrigger(PlayerPointer plr, uint32 id);
	bool HookHandleRepop(PlayerPointer plr);
	void OnAddPlayer(PlayerPointer plr);
	void OnRemovePlayer(PlayerPointer plr);
	void OnCreate();
	void HookOnPlayerKill(PlayerPointer plr, UnitPointer pVictim);
	void HookOnHK(PlayerPointer plr);
	void HookOnShadowSight();
	void SpawnBuff(uint32 x);
	LocationVector GetStartingCoords(uint32 Team);
	void DropFlag(PlayerPointer plr);
	void ReturnFlag(uint32 team);

	static BattlegroundPointer Create(MapMgrPointer m, uint32 i, uint32 l, uint32 t) { return WarsongGulchPointer(new WarsongGulch(m, i, l, t)); }

	uint32 GetAllianceFlagHolderGUID() { return m_flagHolders[0]; }
	uint32 GetHordeFlagHolderGUID() { return m_flagHolders[1]; }
	const char * GetName() { return "Warsong Gulch"; }
	void OnStart();

	/* looooooot */
	bool SupportsPlayerLoot() { return true; }
	void HookGenerateLoot(PlayerPointer plr, CorpsePointer pCorpse);

	void SetIsWeekend(bool isweekend);
};

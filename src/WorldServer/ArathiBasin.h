/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#define AB_BUFF_RESPAWN_TIME 90000

enum ABBuffs
{
	AB_BUFF_STABLES						= 0,
	AB_BUFF_BLACKSMITH					= 1,
	AB_BUFF_FARM						= 2,
	AB_BUFF_LUMBERMILL					= 3,
	AB_BUFF_MINE						= 4,
	AB_NUM_BUFFS						= 5,
};

enum ABControlPoints
{
	AB_CONTROL_POINT_STABLE				= 0,
	AB_CONTROL_POINT_FARM				= 1,
	AB_CONTROL_POINT_BLACKSMITH			= 2,
	AB_CONTROL_POINT_MINE				= 3,
	AB_CONTROL_POINT_LUMBERMILL			= 4,
	AB_NUM_CONTROL_POINTS				= 5,
};

enum ABSpawnTypes
{
	AB_SPAWN_TYPE_NEUTRAL				= 0,
	AB_SPAWN_TYPE_ALLIANCE_ASSAULT		= 1,
	AB_SPAWN_TYPE_HORDE_ASSAULT			= 2,
	AB_SPAWN_TYPE_ALLIANCE_CONTROLLED	= 3,
	AB_SPAWN_TYPE_HORDE_CONTROLLED		= 4,
	AB_NUM_SPAWN_TYPES					= 5,
};

class ArathiBasin : public CBattleground
{
public:
	GameObjectPointer m_buffs[AB_NUM_BUFFS];
	GameObjectPointer m_controlPoints[AB_NUM_CONTROL_POINTS];
	GameObjectPointer m_controlPointAuras[AB_NUM_CONTROL_POINTS];
	bool m_nearingVictory[2];

protected:
	list< GameObjectPointer > m_gates;
	
	uint32 m_resources[2];
	uint32 m_capturedBases[2];
	uint32 m_lastHonorGainResources[2];
	int32 m_basesLastOwnedBy[AB_NUM_CONTROL_POINTS];
	int32 m_basesOwnedBy[AB_NUM_CONTROL_POINTS];
	int32 m_basesAssaultedBy[AB_NUM_CONTROL_POINTS];
	int m_bonusHonor;
	uint32 m_resToGainBG;
	bool m_flagIsVirgin[AB_NUM_CONTROL_POINTS];
	CreaturePointer m_spiritGuides[AB_NUM_CONTROL_POINTS];
	uint32 m_lgroup;

public:
	ArathiBasin( MapMgrPointer mgr, uint32 id, uint32 lgroup, uint32 t);
	~ArathiBasin();

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

	static BattlegroundPointer Create( MapMgrPointer m, uint32 i, uint32 l, uint32 t) { return ArathiBasinPointer(new ArathiBasin(m, i, l, t)); }

	const char * GetName() { return XARCTIDAI; }
	void OnStart();

	void EventUpdateResources(uint32 Team);
	bool HookSlowLockOpen( GameObjectPointer pGo, PlayerPointer pPlayer, SpellPointer pSpell);

	/* AB Game Mechanics */
	void SpawnControlPoint(uint32 Id, uint32 Type);
	void CaptureControlPoint(uint32 Id, uint32 Team);
	void AssaultControlPoint(PlayerPointer pPlayer, uint32 Id);

	/* looooooot */
	bool SupportsPlayerLoot() { return true; }
	void HookGenerateLoot(PlayerPointer plr, CorpsePointer pCorpse);

	void SetIsWeekend(bool isweekend);
};

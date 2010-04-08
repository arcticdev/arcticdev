/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#define MAX_DUNGEONS 257+1   // lfgdungeons.dbc
#define MAX_LFG_QUEUE_ID 3
#define LFG_MATCH_TIMEOUT 30 // in seconds

enum LFGTypes 
{
    LFG_TYPE_NONE = 0,
    LFG_TYPE_DUNGEON = 1,
    LFG_TYPE_RAID = 2,
    LFG_TYPE_QUEST = 3,
    LFG_TYPE_ZONE = 4,
    LFG_TYPE_HEROIC_DUNGEON = 5,
    LFG_TYPE_ANY_DUNGEON = 6,
    LFG_TYPE_ANY_HEROIC_DUNGEON = 7,
    LFG_TYPE_DAILY_DUNGEON = 8,
    LFG_TYPE_DAILY_HEROIC_DUNGEON = 9
};

class LfgMatch;
class LfgMgr : public Singleton < LfgMgr >, EventableObject
{
public:	
	
	typedef list<PlayerPointer  > LfgPlayerList;

	LfgMgr();
	~LfgMgr();

	bool AttemptLfgJoin(PlayerPointer pl, uint32 LfgDungeonId);
	void SetPlayerInLFGqueue(PlayerPointer pl,uint32 LfgDungeonId);
	void SetPlayerInLfmList(PlayerPointer pl, uint32 LfgDungeonId);
	void RemovePlayerFromLfgQueue(PlayerPointer pl,uint32 LfgDungeonId);
	void RemovePlayerFromLfgQueues(PlayerPointer pl);
	void RemovePlayerFromLfmList(PlayerPointer pl, uint32 LfmDungeonId);
	void UpdateLfgQueue(uint32 LfgDungeonId);
	void SendLfgList(PlayerPointer plr, uint32 Dungeon);
	void EventMatchTimeout(LfgMatch * pMatch);

	int32 event_GetInstanceId() { return -1; }
	
protected:
	
	LfgPlayerList m_lookingForGroup[MAX_DUNGEONS];
	LfgPlayerList m_lookingForMore[MAX_DUNGEONS];
	Mutex m_lock;
};

class LfgMatch
{
public:
	set<PlayerPointer  > PendingPlayers;
	set<PlayerPointer  > AcceptedPlayers;
	Mutex lock;
	uint32 DungeonId;
    Group * pGroup;

	LfgMatch(uint32 did) : DungeonId(did), pGroup(NULL) { }
};

extern uint32 LfgDungeonTypes[MAX_DUNGEONS];

#define sLfgMgr LfgMgr::getSingleton()

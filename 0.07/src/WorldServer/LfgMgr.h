/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

enum LFGTypes 
{
	LFG_NONE = 0,
	LFG_INSTANCE = 1,
	LFG_RAID = 2,
	LFG_QUEST = 3,
	LFG_ZONE = 4,
	LFG_HEROIC_DUNGEON = 5, // from client
};

#define MAX_DUNGEONS 244+1 // check max entrys +1 on lfgdungeons.dbc
#define MAX_LFG_QUEUE_ID 3
#define LFG_MATCH_TIMEOUT 30		// in seconds

class LfgMatch;
class LfgMgr : public Singleton < LfgMgr >, EventableObject
{
public:	
	
	typedef list<PlayerPointer  > LfgPlayerList;

	LfgMgr();
	~LfgMgr();

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

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

	LfgMatch(uint32 did) : DungeonId(did),pGroup(NULL) { }
};

extern uint32 LfgDungeonTypes[MAX_DUNGEONS];

#define sLfgMgr LfgMgr::getSingleton()

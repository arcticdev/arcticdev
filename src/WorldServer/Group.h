/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _GROUP_H_
#define _GROUP_H_

enum PartyErrors
{
	ERR_PARTY_NO_ERROR					= 0,
	ERR_PARTY_CANNOT_FIND				= 1,
	ERR_PARTY_IS_NOT_IN_YOUR_PARTY		= 2,
	ERR_PARTY_UNK						= 3,
	ERR_PARTY_IS_FULL					= 4,
	ERR_PARTY_ALREADY_IN_GROUP			= 5,
	ERR_PARTY_YOU_ARENT_IN_A_PARTY		= 6,
	ERR_PARTY_YOU_ARE_NOT_LEADER		= 7,
	ERR_PARTY_WRONG_FACTION				= 8,
	ERR_PARTY_IS_IGNORING_YOU			= 9,
};

enum GroupTypes
{
	GROUP_TYPE_NORMAL = 0,
    GROUP_TYPE_RAID = 1
};

enum MaxGroupCount
{
	MAX_GROUP_SIZE_PARTY				= 5,
	MAX_GROUP_SIZE_RAID					= 40,
};

enum QuickGroupUpdateFlags
{
	PARTY_UPDATE_FLAG_POSITION			= 1,
	PARTY_UPDATE_FLAG_ZONEID			= 2,
};

enum GroupFlags
{
	GROUP_FLAG_DONT_DISBAND_WITH_NO_MEMBERS			= 1,
	GROUP_FLAG_REMOVE_OFFLINE_PLAYERS				= 2,
	GROUP_FLAG_BATTLEGROUND_GROUP					= 4,
};

struct PlayerInfo;
typedef struct
{
	PlayerInfo * player_info;
	PlayerPointer player;
}GroupMember;

class Group;
class Player;

typedef std::set<PlayerInfo*> GroupMembersSet;

class ARCTIC_DECL SubGroup // Most stuff will be done through here, not through the "Group" class.
{
public:
	friend class Group;

	SubGroup(Group* parent, uint32 id):m_Parent(parent),m_Id(id)
	{
	}

	~SubGroup();

	ARCTIC_INLINE GroupMembersSet::iterator GetGroupMembersBegin(void) { return m_GroupMembers.begin(); }
	ARCTIC_INLINE GroupMembersSet::iterator GetGroupMembersEnd(void)   { return m_GroupMembers.end();   }

	bool AddPlayer(PlayerInfo * info);
	void RemovePlayer(PlayerInfo * info);
	
	ARCTIC_INLINE bool IsFull(void)				   { return m_GroupMembers.size() >= MAX_GROUP_SIZE_PARTY; }
	ARCTIC_INLINE size_t GetMemberCount(void)	   { return m_GroupMembers.size(); }
	
	ARCTIC_INLINE uint32 GetID(void)			   { return m_Id; }
	ARCTIC_INLINE void SetID(uint32 newid)		   { m_Id = newid; }

	ARCTIC_INLINE void   SetParent(Group* parent)  { m_Parent = parent; }
	ARCTIC_INLINE Group* GetParent(void)		   { return m_Parent; }

	void   Disband();
	bool HasMember(uint32 guid);

protected:

	GroupMembersSet	 m_GroupMembers;
	Group * m_Parent;
	uint32 m_Id;

};

class Arena;
class ARCTIC_DECL Group
{
public:
	friend class SubGroup;

	static Group * Create();

	Group(bool Assign);
	~Group();

	// Adding/Removal Management
	bool AddMember(PlayerInfo * info, int32 subgroupid=-1);
	void RemovePlayer(PlayerInfo * info);

	// Leaders and Looting
	void SetLeader(PlayerPointer pPlayer,bool silent);
	void SetLooter(PlayerPointer pPlayer, uint8 method, uint16 threshold);

	// Transferring data to clients
	void Update();

	ARCTIC_INLINE void SendPacketToAll(WorldPacket *packet) { SendPacketToAllButOne(packet, NULLPLR); }
	void SendPacketToAllButOne(WorldPacket *packet, PlayerPointer pSkipTarget);

	ARCTIC_INLINE void SendPacketToAll(StackPacket *packet) { SendPacketToAllButOne(packet, NULLPLR); }
	void SendPacketToAllButOne(StackPacket *packet, PlayerPointer pSkipTarget);

	ARCTIC_INLINE void OutPacketToAll(uint16 op, uint16 len, const void* data) { OutPacketToAllButOne(op, len, data, NULLPLR); }
	void OutPacketToAllButOne(uint16 op, uint16 len, const void* data, PlayerPointer pSkipTarget);

	ARCTIC_INLINE uint32 GetGroupInstanceID(void)		{ return m_GroupInstanceID; }
	ARCTIC_INLINE void SetGroupInstanceID(uint32 newid)	{ m_GroupInstanceID = newid; }

	void SendNullUpdate(PlayerPointer pPlayer);

	// Group Combat
	void SendPartyKillLog(ObjectPointer player, ObjectPointer Unit);

	// Destroying/Converting
	void Disband();
	PlayerPointer FindFirstPlayer();
	
	// Accessing functions
	ARCTIC_INLINE SubGroup * GetSubGroup(uint32 Id)
	{
		if(Id >= 8)
			return 0;

		return m_SubGroups[Id];
	}

	ARCTIC_INLINE uint32 GetSubGroupCount(void) { return m_SubGroupCount; }

	ARCTIC_INLINE uint8 GetMethod(void) { return m_LootMethod; }
	ARCTIC_INLINE uint16 GetThreshold(void) { return m_LootThreshold; }
	ARCTIC_INLINE PlayerInfo * GetLeader(void) { return m_Leader; }
	ARCTIC_INLINE PlayerInfo * GetLooter(void) { return m_Looter; }

	void MovePlayer(PlayerInfo * info, uint8 subgroup);

	bool HasMember(PlayerPointer pPlayer);
	bool HasMember(PlayerInfo * info);
	ARCTIC_INLINE uint32 MemberCount(void) { return m_MemberCount; }
	ARCTIC_INLINE bool IsFull() { return ((m_GroupType == GROUP_TYPE_NORMAL && m_MemberCount >= MAX_GROUP_SIZE_PARTY) || (m_GroupType == GROUP_TYPE_RAID && m_MemberCount >= MAX_GROUP_SIZE_RAID)); }

	SubGroup* FindFreeSubGroup();

	void ExpandToRaid();

	void SaveToDB();
	void LoadFromDB(Field *fields);

	ARCTIC_INLINE uint8 GetGroupType() { return m_GroupType; }
	ARCTIC_INLINE uint32 GetID() { return m_Id; }

	void UpdateOutOfRangePlayer(PlayerPointer pPlayer, uint32 Flags, bool Distribute, WorldPacket * Packet);
	void UpdateAllOutOfRangePlayersFor(PlayerPointer pPlayer);
	void HandleUpdateFieldChange(uint32 Index, PlayerPointer pPlayer);
	void HandlePartialChange(uint32 Type, PlayerPointer pPlayer);

	uint64 m_targetIcons[8];
	ARCTIC_INLINE Mutex& getLock() { return m_groupLock; }
	ARCTIC_INLINE void Lock() { m_groupLock.Acquire(); }
	ARCTIC_INLINE void Unlock() { return m_groupLock.Release(); }
	bool m_isqueued;

	void SetAssistantLeader(PlayerInfo * pMember);
	void SetMainTank(PlayerInfo * pMember);
	void SetMainAssist(PlayerInfo * pMember);

	ARCTIC_INLINE PlayerInfo * GetAssistantLeader() { return m_assistantLeader; }
	ARCTIC_INLINE PlayerInfo * GetMainTank() { return m_mainTank; }
	ARCTIC_INLINE PlayerInfo * GetMainAssist() { return m_mainAssist; }

	void SetDifficulty(uint8 difficulty);
	
	//////////////////////////////////////////////////////////////////////////
	// VoiceChat                                                            //
	//////////////////////////////////////////////////////////////////////////
	
#ifdef VOICE_CHAT
	void AddVoiceMember(PlayerInfo * pPlayer);
	void RemoveVoiceMember(PlayerInfo * pPlayer);
	void SendVoiceUpdate();
	void CreateVoiceSession();
	void VoiceChannelCreated(uint16 id);
	void VoiceSessionDropped();
	void VoiceSessionReconnected();

public:
	bool m_voiceChannelRequested;
	int16 m_voiceChannelId;
	uint32 m_voiceMemberCount;
protected:
	PlayerInfo* m_voiceMembersList[41];
#endif	// VOICE_CHAT

	ARCTIC_INLINE void SetFlag(uint8 groupflag) { m_groupFlags |= groupflag; }
	ARCTIC_INLINE void RemoveFlag(uint8 groupflag) { m_groupFlags &= ~groupflag; }
	ARCTIC_INLINE bool HasFlag(uint8 groupflag) { return (m_groupFlags & groupflag) > 0 ? true : false; }

protected:
	PlayerInfo * m_Leader;
	PlayerInfo * m_Looter;
	PlayerInfo * m_assistantLeader;
	PlayerInfo * m_mainTank;
	PlayerInfo * m_mainAssist;

	uint8 m_LootMethod;
	uint16 m_LootThreshold;
	uint8 m_GroupType;
	uint32 m_Id;
	uint32 m_GroupInstanceID;

	SubGroup* m_SubGroups[8];
	uint8 m_SubGroupCount;
	uint32 m_MemberCount;
	Mutex m_groupLock;
	bool m_dirty;
	bool m_updateblock;
	uint8 m_difficulty;
	uint8 m_groupFlags;

	// Evil prayer of mending stuff
public:
	uint8 m_prayerOfMendingCount;
	uint32 m_prayerOfMendingTarget;
};

#endif  // _GROUP_H_

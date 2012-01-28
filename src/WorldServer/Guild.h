/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

#include "GuildDefines.h"

struct PlayerInfo;

struct SERVER_DECL GuildRankTabPermissions
{
	uint32 iFlags;
	int32 iStacksPerDay;
};

struct SERVER_DECL GuildRank
{
	uint32 iId;
	uint32 iRights;
	int32 iGoldLimitPerDay;
	GuildRankTabPermissions iTabPermissions[MAX_GUILD_BANK_TABS];
	char * szRankName;
	bool CanPerformCommand(uint32 t);
	bool CanPerformBankCommand(uint32 t, uint32 tab);
};

struct SERVER_DECL GuildMember
{
	PlayerInfo * pPlayer;
	const char * szPublicNote;
	const char * szOfficerNote;
	GuildRank * pRank;
	uint32 uLastWithdrawReset;
	uint32 uWithdrawlsSinceLastReset;
	uint32 uLastItemWithdrawReset[MAX_GUILD_BANK_TABS];
	uint32 uItemWithdrawlsSinceLastReset[MAX_GUILD_BANK_TABS];

	uint32 CalculateAllowedItemWithdraws(uint32 tab);
	void OnItemWithdraw(uint32 tabid);
	
	uint32 CalculateAvailableAmount();
	void OnMoneyWithdraw(uint32 amt);
};

struct SERVER_DECL GuildLogEvent
{
	uint32 iLogId;
	uint8 iEvent;
	uint32 iTimeStamp;
	uint32 iEventData[3];
};

struct SERVER_DECL GuildBankEvent
{
	uint32 iLogId;
	uint8 iAction;
	uint32 uPlayer;
	uint32 uEntry;
	uint8 iStack;
	uint32 uTimeStamp;
};

struct SERVER_DECL GuildBankTab
{
	uint8 iTabId;
	char * szTabName;
	char * szTabIcon;
	Item* pSlots[MAX_GUILD_BANK_SLOTS];
	list<GuildBankEvent*> lLog;
};

class Charter;

class SERVER_DECL Guild
{
public:
	Guild();
	~Guild( );
	static Guild* Create();
	bool LoadFromDB(Field * f);

	/* Log entry processing */
protected:
	uint32 m_hiLogId;
public:
	uint32 GenerateGuildLogEventId();
	
	/* guild bank logging calls */
	void LogGuildBankActionMoney(uint8 iAction, uint32 uGuid, uint32 uAmount);
	void LogGuildBankAction(uint8 iAction, uint32 uGuid, uint32 uEntry, uint8 iStack, GuildBankTab * pTab);
	static void ClearOutOfDateLogEntries();

	/* only call at first create/save */
	void CreateInDB();

	/* Sets new MOTD, and updates in database */
	void SetMOTD(const char * szNewMotd, WorldSession * pClient);

	/* Gets MOTD */
	ARCTIC_INLINE const char * GetMOTD() const { return m_motd; }

	/* Sets guild information, updates in database */
	void SetGuildInformation(const char * szGuildInformation, WorldSession * pClient);

	/* Gets guild information */
	ARCTIC_INLINE const char * GetGuildInformation() const { return m_guildInfo; }

	/* Sends the guild roster to this client. */
	void SendGuildRoster(WorldSession * pClient);

	/* Sends the guild query response to this client. */
	void SendGuildQuery(WorldSession * pClient);

	/* Adds a member to the guild, saves him into the database.
	 * A provided rank of -1 means the lowest rank.
	 */
	void AddGuildMember(PlayerInfo * pMember, WorldSession * pClient, int32 ForcedRank = -1);

	/* Removes a member from the guild.
	 * If this member is the guild master, the guild will be automatically handed down to the next
	 * highest member.
	 */
	void RemoveGuildMember(PlayerInfo * pMember, WorldSession * pClient);

	/* Promotes a member of a guild.
	 * Do not use for changing guild master. Use ChangeGuildMaster() for that instead.
	 */
	void PromoteGuildMember(PlayerInfo * pMember, WorldSession * pClient);

	/* Demotes a member of a guild.
	 * Do not use for changing guild master. Use ChangeGuildMaster() for that instead.
	 */
	void DemoteGuildMember(PlayerInfo * pMember, WorldSession * pClient);

	/* Changes the guild master of the guild. */
	void ChangeGuildMaster(PlayerInfo * pNewMaster, WorldSession * pClient);

	/* Sends a guild command packet to the client. */
	static void SendGuildCommandResult(WorldSession * pClient, uint32 iCmd, const char * szMsg, uint32 iType);

	/* Logs a guild event and sends it to all online players. */
	void LogGuildEvent(uint8 iEvent, uint8 iStringCount, ...);
	
	/* Guild event logging. */
	void AddGuildLogEntry(uint8 iEvent, uint8 iParamCount, ...);

	/* Creates a guild from a charter. */
	void CreateFromCharter(Charter * pCharter, WorldSession * pTurnIn);

	/* Sends a packet to all online players. */
	void SendPacket(WorldPacket * data);

	/* Sends a guild chat message. */
	void GuildChat(const char * szMessage, WorldSession * pClient, int32 iType);

	/* Sends an officer chat message. */
	void OfficerChat(const char * szMessage, WorldSession * pClient, int32 iType);

	/* Sends the guild log to a player. */
	void SendGuildLog(WorldSession * pClient);
	void SendGuildBankLog(WorldSession * pClient, uint8 iSlot);

	/* Sets the public note for a player. */
	void SetPublicNote(PlayerInfo * pMember, const char * szNewNote, WorldSession * pClient);

	/* Sets the officer note for a player. */
	void SetOfficerNote(PlayerInfo * pMember, const char * szNewNote, WorldSession * pClient);

	/* Disbands a guild. */
	void Disband();

	/* creation time stuff */
	uint32 creationDay;
	uint32 creationMonth;
	uint32 creationYear;

	/* Getters :P */
	ARCTIC_INLINE const char * GetGuildName() const { return m_guildName; }
	ARCTIC_INLINE const uint32 GetGuildLeader() const { return m_guildLeader; }
	ARCTIC_INLINE const uint32 GetGuildId() const { return m_guildId; }
	ARCTIC_INLINE const uint32 GetBankTabCount() const { return m_bankTabCount; }
	ARCTIC_INLINE const uint32 GetBankBalance() const { return m_bankBalance; }
	ARCTIC_INLINE const size_t GetNumMembers() const { return m_members.size(); }

	Mutex* getLock() { return &m_lock; }
	map<PlayerInfo*, GuildMember*>::iterator GetGuildMembersBegin() { return m_members.begin(); }
	map<PlayerInfo*, GuildMember*>::iterator GetGuildMembersEnd() { return m_members.end(); }
	
	/* Creates a guild rank with the specified permissions. */
	GuildRank * CreateGuildRank(const char * szRankName, uint32 iPermissions, bool bFullGuildBankPermissions);

	/* "Pops" or removes the bottom guild rank. */
	void RemoveGuildRank(WorldSession * pClient);

	/* Buys a new guild bank tab, usable only by guild master */
	void BuyBankTab(WorldSession * pClient);

	/* Deposits money into the guild bank, usable by any member. */
	void DepositMoney(WorldSession * pClient, uint32 uAmount);

	/* Withdraws money from the guild bank, usable by members with that permission. */
	void WithdrawMoney(WorldSession * pClient, uint32 uAmount);

	/* Retrieves a guild rank for editing */
	ARCTIC_INLINE GuildRank * GetGuildRank(uint32 Id)
	{ 
		if(Id >= MAX_GUILD_RANKS)
			return NULL;

		return m_ranks[Id];
	}

	/* Gets a guild bank tab for editing/viewing */

	ARCTIC_INLINE GuildBankTab * GetBankTab(uint32 Id)
	{
		if(Id >= m_bankTabCount)
			return NULL;

		return m_bankTabs[Id];
	}

	/* Gets a guild member struct */
	ARCTIC_INLINE GuildMember * GetGuildMember(PlayerInfo * pInfo)
	{
		GuildMemberMap::iterator itr;
		GuildMember * ret;
		m_lock.Acquire();
		itr = m_members.find(pInfo);
		ret = (itr!=m_members.end()) ? itr->second : NULL;
		m_lock.Release();
		return ret;
	}

	/* Sends the guild bank to this client. */
	void SendGuildBank(WorldSession * pClient, GuildBankTab * pTab, int8 updated_slot1 = -1, int8 updated_slot2 = -1);
	void SendGuildBankInfo(WorldSession * pClient);

	/* Changes the tabard info.  */
	void SetTabardInfo(uint32 EmblemStyle, uint32 EmblemColor, uint32 BorderStyle, uint32 BorderColor, uint32 BackgroundColor);
	
	/* Sends the guild information packet to the specified client. */
	void SendGuildInfo(WorldSession * pClient);

	/* Force a guild leader change internally
	 * used for char renames, etc.
	 */
	void ForceLeaderChange(uint32 newGuid) { m_guildLeader = newGuid; }

protected:
	
	/* Enables/disables command logging.
	 * Use when performing mass events such as guild creation or destruction.
	 */
	bool m_commandLogging;
	
	/* Internal variables */
	uint32 m_guildId;
	uint32 m_emblemStyle;
	uint32 m_emblemColor;
	uint32 m_borderStyle;
	uint32 m_borderColor;
	uint32 m_backgroundColor;
	uint32 m_guildLeader;
	uint32 m_creationTimeStamp;
	uint32 m_bankTabCount;
	uint32 m_bankBalance;

	typedef vector<GuildBankTab*> GuildBankTabVector;
	GuildBankTabVector m_bankTabs;

	char * m_guildName;
	char * m_guildInfo;
	char * m_motd;
	
	/* Guild Member Map. */
	typedef map<PlayerInfo*, GuildMember*> GuildMemberMap;
	GuildMemberMap m_members;

	/* Guild Rank Information. */
	GuildRank * m_ranks[MAX_GUILD_RANKS];

	/* Guild log. Ordered in first event -> last event. */
	typedef list<GuildLogEvent*> GuildLogList;
	GuildLogList m_log;
	list<GuildBankEvent*> m_moneyLog;

	/* Guild lock. */
	Mutex m_lock;

	/* finds the lowest rank */
	GuildRank * FindLowestRank();
	GuildRank * FindHighestRank();
};

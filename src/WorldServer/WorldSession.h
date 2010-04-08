/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

//////////////////////////////////////////////////////////////////////////
// WorldSession.h                                                       //
//////////////////////////////////////////////////////////////////////////

#ifndef __WORLDSESSION_H
#define __WORLDSESSION_H

class Player;
class WorldPacket;
class WorldSocket;
class WorldSession;
class MapMgr;
class Creature;
class MovementInfo;
struct TrainerSpell;

//#define SESSION_CAP 5

// MovementFlags Contribution by Tenshi
enum MovementFlags
{
	// Byte 1 (Resets on Movement Key Press)
    MOVEFLAG_MOVE_STOP                  = 0x00,			// verified
	MOVEFLAG_MOVE_FORWARD				= 0x01,			// verified
	MOVEFLAG_MOVE_BACKWARD				= 0x02,			// verified
	MOVEFLAG_STRAFE_LEFT				= 0x04,			// verified
	MOVEFLAG_STRAFE_RIGHT				= 0x08,			// verified
	MOVEFLAG_TURN_LEFT					= 0x10,			// verified
	MOVEFLAG_TURN_RIGHT					= 0x20,			// verified
	MOVEFLAG_PITCH_DOWN					= 0x40,			// Unconfirmed
	MOVEFLAG_PITCH_UP					= 0x80,			// Unconfirmed

	// Byte 2 (Resets on Situation Change)
	MOVEFLAG_WALK						= 0x100,		// verified
	MOVEFLAG_TAXI						= 0x200,		
	MOVEFLAG_NO_COLLISION				= 0x400,
	MOVEFLAG_FLYING	    				= 0x800,		// verified
	MOVEFLAG_REDIRECTED					= 0x1000,		// Unconfirmed
	MOVEFLAG_FALLING					= 0x2000,       // verified
	MOVEFLAG_FALLING_FAR				= 0x4000,		// verified
	MOVEFLAG_FREE_FALLING				= 0x8000,		// half verified

	// Byte 3 (Set by server. TB = Third Byte. Completely unconfirmed.)
	MOVEFLAG_TB_PENDING_STOP			= 0x10000,		// (MOVEFLAG_PENDING_STOP)
	MOVEFLAG_TB_PENDING_UNSTRAFE		= 0x20000,		// (MOVEFLAG_PENDING_UNSTRAFE)
	MOVEFLAG_TB_PENDING_FALL			= 0x40000,		// (MOVEFLAG_PENDING_FALL)
	MOVEFLAG_TB_PENDING_FORWARD			= 0x80000,		// (MOVEFLAG_PENDING_FORWARD)
	MOVEFLAG_TB_PENDING_BACKWARD		= 0x100000,		// (MOVEFLAG_PENDING_BACKWARD)
	MOVEFLAG_SWIMMING          		    = 0x200000,		//  verified
	MOVEFLAG_FLYING_PITCH_UP	        = 0x400000,		// (half confirmed)(MOVEFLAG_PENDING_STR_RGHT)
	MOVEFLAG_TB_MOVED					= 0x800000,		// (half confirmed) gets called when landing (MOVEFLAG_MOVED)

	// Byte 4 (Script Based Flags. Never reset, only turned on or off.)
	MOVEFLAG_AIR_SUSPENSION	   	 		= 0x1000000,	// confirmed allow body air suspension(good name? lol).
	MOVEFLAG_AIR_SWIMMING				= 0x2000000,	// confirmed while flying.
	MOVEFLAG_SPLINE_MOVER				= 0x4000000,	// Unconfirmed
	MOVEFLAG_IMMOBILIZED				= 0x8000000,
	MOVEFLAG_WATER_WALK					= 0x10000000,
	MOVEFLAG_FEATHER_FALL				= 0x20000000,	// Does not negate fall damage.
	MOVEFLAG_LEVITATE					= 0x40000000,
	MOVEFLAG_LOCAL						= 0x80000000,	// This flag defaults to on. (Assumption)

	// Masks
	MOVEFLAG_MOVING_MASK				= 0x03,
	MOVEFLAG_STRAFING_MASK				= 0x0C,
	MOVEFLAG_TURNING_MASK				= 0x30,
	MOVEFLAG_FALLING_MASK				= 0x6000,
	MOVEFLAG_MOTION_MASK				= 0xE00F,		// Forwards, Backwards, Strafing, Falling
	MOVEFLAG_PENDING_MASK				= 0x7F0000,
	MOVEFLAG_PENDING_STRAFE_MASK		= 0x600000,
	MOVEFLAG_PENDING_MOVE_MASK			= 0x180000,
	MOVEFLAG_FULL_FALLING_MASK			= 0xE000,
};

enum AreaTriggerFailures
{
	AREA_TRIGGER_FAILURE_OK				= 0,
	AREA_TRIGGER_FAILURE_UNAVAILABLE	= 1,
	AREA_TRIGGER_FAILURE_NO_BC			= 2,
	AREA_TRIGGER_FAILURE_NO_HEROIC		= 3,
	AREA_TRIGGER_FAILURE_NO_RAID		= 4,
	AREA_TRIGGER_FAILURE_NO_ATTUNE_Q	= 5,
	AREA_TRIGGER_FAILURE_NO_ATTUNE_I	= 6,
	AREA_TRIGGER_FAILURE_LEVEL			= 7,
	AREA_TRIGGER_FAILURE_NO_GROUP		= 8,
	AREA_TRIGGER_FAILURE_NO_KEY			= 9,
	AREA_TRIGGER_FAILURE_LEVEL_HEROIC	= 10,
	AREA_TRIGGER_FAILURE_NO_CHECK		= 11,
	AREA_TRIGGER_FAILURE_NO_WOTLK		= 12,
	AREA_TRIGGER_FAILURE_IN_QUEUE		= 13,
};

struct OpcodeHandler
{
	uint16 status;
	void (WorldSession::*handler)(WorldPacket& recvPacket);
};

enum SessionStatus
{
	STATUS_AUTHED = 0,
	STATUS_LOGGEDIN
};

struct AccountDataEntry
{
	char * data;
	uint32 sz;
	bool bIsDirty;
};

// New 3.2.2 Account DataType
enum AccountDataTypes
{
	GLOBAL_CONFIG_CACHE				= 0,	// 0x01 
	PER_CHARACTER_CONFIG_CACHE		= 1,	// 0x02 
	GLOBAL_BINDINGS_CACHE			= 2,	// 0x04 
	PER_CHARACTER_BINDINGS_CACHE	= 3,	// 0x08 
	GLOBAL_MACROS_CACHE				= 4,	// 0x10 
	PER_CHARACTER_MACROS_CACHE		= 5,	// 0x20 
    PER_CHARACTER_LAYOUT_CACHE		= 6,	// 0x40 
	PER_CHARACTER_CHAT_CACHE		= 7,	// 0x80 
	NUM_ACCOUNT_DATA_TYPES			= 8
};

#define GLOBAL_CACHE_MASK           0x15
#define PER_CHARACTER_CACHE_MASK    0xEA

typedef struct Cords 
{
	float x,y,z;
}Cords;

class MovementInfo
{
public:
	uint32 time;
	float pitch;                            // -1.55=looking down, 0=looking forward, +1.55=looking up
	float jump_sinAngle;                    // on slip 8 is zero, on jump some other number
	float jump_cosAngle, jump_xySpeed;      // 9,10 changes if you are not on foot
	uint32 unk11;
	uint32 spline_unk;
	uint8 unk13;
	uint32 unklast;                         // something related to collision
	uint16 flag16;

	float x, y, z, orientation;
	uint32 flags;
	uint32 FallTime;
	uint64 transGuid;
	WoWGuid PlayerGUID;
	WoWGuid TransportWoWGuid;
	float transX, transY, transZ, transO, transTime;
	uint8 transSeat;

	void init(WorldPacket & data);
	void write(WorldPacket & data);

	MovementInfo()
	{
		time = 0;
		pitch = jump_sinAngle = jump_cosAngle = jump_xySpeed = 0;
		unk11 = 0;
		spline_unk = 0;
		unk13 = 0;
		unklast = 0;
		flag16 = 0;

		x = y = z = orientation = 0;
		flags = 0;
		FallTime = 0;
		transGuid = 0;

		transX = transY = transZ = transO = transTime = 0;
		transSeat = 0;
	}
};

#define PLAYER_LOGOUT_DELAY (20*1000) // 20 seconds should be more than enough to gank ya. 

#define CHECK_INWORLD_RETURN if(_player == NULL || !_player->IsInWorld()) { return; }
#define CHECK_GUID_EXISTS(guidx) if(_player->GetMapMgr()->GetUnit((guidx)) == NULL) { return; }
#define CHECK_PACKET_SIZE(pckp, ssize) if(ssize && pckp.size() < ssize) { Disconnect(); return; }

#define NOTIFICATION_MESSAGE_NO_PERMISSION "You do not have permission to perform that function."
// #define CHECK_PACKET_SIZE(x, y) if(y > 0 && x.size() < y) { _socket->Disconnect(); return; }

void EncodeHex(const char* source, char* dest, uint32 size);
void DecodeHex(const char* source, char* dest, uint32 size);

extern OpcodeHandler WorldPacketHandlers[NUM_MSG_TYPES];
void CapitalizeString(string& arg);

class ARCTIC_DECL WorldSession
{
	friend class WorldSocket;
public:
	WorldSession(uint32 id, string Name, WorldSocket *sock);
	~WorldSession();

	PlayerPointer m_loggingInPlayer;

 	bool portPlr;
 	LocationVector portVec;
	uint32 portMap;
	uint32 portInst;
 
	ARCTIC_INLINE void SetPortVec(uint32 map, uint32 iid, LocationVector vec) { portMap = map; portInst = iid; portVec = vec; portPlr = true; }


	ARCTIC_INLINE void SendPacket(WorldPacket* packet)
	{
		if(_socket && _socket->IsConnected())
			_socket->SendPacket(packet);
	}

	ARCTIC_INLINE void SendPacket(StackPacket * packet)
	{
		if(_socket && _socket->IsConnected())
			_socket->SendPacket(packet);
	}

	ARCTIC_INLINE void OutPacket(uint16 opcode)
	{
		if(_socket && _socket->IsConnected())
			_socket->OutPacket(opcode, 0, NULL);
	}

	void Delete();

	void SendChatPacket(WorldPacket * data, uint32 langpos, int32 lang, WorldSession * originator);

	uint32 m_currMsTime;
	uint32 m_lastPing;

	ARCTIC_INLINE uint32 GetAccountId() const { return _accountId; }
	ARCTIC_INLINE PlayerPointer GetPlayer() { return _player; }
	
	/* Acct flags */
	void SetAccountFlags(uint32 flags) { _accountFlags = flags; }
	bool HasFlag(uint32 flag) { return (_accountFlags & flag) != 0; }

	/* GM Permission System */
	void LoadSecurity(std::string securitystring);
	void SetSecurity(std::string securitystring);
	ARCTIC_INLINE char* GetPermissions() { return permissions; }
	ARCTIC_INLINE int GetPermissionCount() { return permissioncount; }
	ARCTIC_INLINE bool HasPermissions() { return (permissioncount > 0) ? true : false; }
	ARCTIC_INLINE bool HasGMPermissions()
	{
		if(!permissioncount)
			return false;

		return (strchr(permissions,'a')!=NULL) ? true : false;
	}
   
	bool CanUseCommand(char cmdstr);

	ARCTIC_INLINE void SetSocket(WorldSocket *sock)
	{
		_socket = sock;
	}
	ARCTIC_INLINE void SetPlayer(PlayerPointer plr) { _player = plr; }
	
	ARCTIC_INLINE void SetAccountData(uint32 index, char* data, bool initial,uint32 sz)
	{
		ASSERT(index < 8);
		if(sAccountData[index].data)
			delete [] sAccountData[index].data;
		sAccountData[index].data = data;
		sAccountData[index].sz = sz;
		if(!initial && !sAccountData[index].bIsDirty)		// Mark as "changed" or "dirty"
			sAccountData[index].bIsDirty = true;
		else if(initial)
			sAccountData[index].bIsDirty = false;
	}
	
	ARCTIC_INLINE AccountDataEntry* GetAccountData(uint32 index)
	{
		ASSERT(index < 8);
		return &sAccountData[index];
	}

	void SetLogoutTimer(uint32 ms)
	{
		if(ms)  _logoutTime = m_currMsTime+ms;
		else	_logoutTime = 0;
	}

	void LogoutPlayer(bool Save);

	ARCTIC_INLINE void QueuePacket(WorldPacket* packet)
	{
		m_lastPing = (uint32)UNIXTIME;
		_recvQueue.Push(packet);
	}
	
	void OutPacket(uint16 opcode, uint16 len, const void* data)
	{
		if(_socket && _socket->IsConnected())
			_socket->OutPacket(opcode, len, data);
	}

	ARCTIC_INLINE WorldSocket* GetSocket() { return _socket; }
	
	void Disconnect()
	{
		if(_socket && _socket->IsConnected())
			_socket->Disconnect();
	}

	int __fastcall Update(uint32 InstanceID);

	void SendItemPushResult(ItemPointer pItem, bool Created, bool Received, bool SendToSet, bool NewItem, uint8 DestBagSlot, uint32 DestSlot, uint32 AddCount);
	void SendBuyFailed(uint64 guid, uint32 itemid, uint8 error);
	void SendSellItem(uint64 vendorguid, uint64 itemid, uint8 error);
	void SendNotification(const char *message, ...);

	ARCTIC_INLINE void SetInstance(uint32 Instance) { instanceId = Instance; }
	ARCTIC_INLINE uint32 GetLatency() { return _latency; }
	ARCTIC_INLINE string GetAccountName() { return _accountName; }
	ARCTIC_INLINE const char * GetAccountNameS() { return _accountName.c_str(); }

	ARCTIC_INLINE uint32 GetClientBuild() { return client_build; }
	ARCTIC_INLINE void SetClientBuild(uint32 build) { client_build = build; }
	bool bDeleted;
	ARCTIC_INLINE uint32 GetInstance() { return instanceId; }
	Mutex deleteMutex;
	void _HandleAreaTriggerOpcode(uint32 id);//real handle
	int32 m_moveDelayTime;
	int32 m_clientTimeDelay;

	void CharacterEnumProc(QueryResult * result);
	void LoadAccountDataProc(QueryResult * result);
	ARCTIC_INLINE bool IsLoggingOut() { return _loggingOut; }

	bool CanCreateDeathKnight()
	{
		if( sWorld.m_deathKnightOnePerAccount && m_hasDeathKnight )
			return false;

		if( sWorld.m_deathKnightReqLevel <= m_highestLevel )
			return true;

		return false;
	}

protected:
	bool m_hasDeathKnight;
	uint8 m_highestLevel;
	uint8 DeleteCharacter(uint32 guid);

	// Login screen opcodes (PlayerHandler.cpp):
	void HandleCharEnumOpcode(WorldPacket& recvPacket);
	void HandleCharDeleteOpcode(WorldPacket& recvPacket);
	void HandleCharCreateOpcode(WorldPacket& recvPacket);
	void HandlePlayerLoginOpcode(WorldPacket& recvPacket);
	void HandleDeclinedPlayerNameOpcode(WorldPacket& recv_data);

	// Authentification and misc opcodes (MiscHandler.cpp):
	void HandlePingOpcode(WorldPacket& recvPacket);
	void HandleAuthSessionOpcode(WorldPacket& recvPacket);
	void HandleRepopRequestOpcode(WorldPacket& recvPacket);
	void HandleAutostoreLootItemOpcode(WorldPacket& recvPacket);
	void HandleLootMoneyOpcode(WorldPacket& recvPacket);
	void HandleLootOpcode(WorldPacket& recvPacket);
	void HandleLootReleaseOpcode(WorldPacket& recvPacket);
	void HandleLootMasterGiveOpcode(WorldPacket& recv_data);
	void HandleLootRollOpcode(WorldPacket& recv_data);
	void HandleWhoOpcode(WorldPacket& recvPacket);
	void HandleLogoutRequestOpcode(WorldPacket& recvPacket);
	void HandlePlayerLogoutOpcode(WorldPacket& recvPacket);
	void HandleLogoutCancelOpcode(WorldPacket& recvPacket);
	void HandleZoneUpdateOpcode(WorldPacket& recvPacket);
	void HandleSetTargetOpcode(WorldPacket& recvPacket);
	void HandleSetSelectionOpcode(WorldPacket& recvPacket);
	void HandleStandStateChangeOpcode(WorldPacket& recvPacket);
	void HandleDismountOpcode(WorldPacket & recvPacket);
	void HandleFriendListOpcode(WorldPacket& recvPacket);
	void HandleAddFriendOpcode(WorldPacket& recvPacket);
	void HandleDelFriendOpcode(WorldPacket& recvPacket);
	void HandleAddIgnoreOpcode(WorldPacket& recvPacket);
	void HandleDelIgnoreOpcode(WorldPacket& recvPacket);
	void HandleBugOpcode(WorldPacket& recvPacket);
	void HandleAreaTriggerOpcode(WorldPacket& recvPacket);
	void HandleUpdateAccountData(WorldPacket& recvPacket);
	void HandleRequestAccountData(WorldPacket& recvPacket);
	void HandleSetActionButtonOpcode(WorldPacket& recvPacket);
	void HandleSetAtWarOpcode(WorldPacket& recvPacket);
	void HandleSetWatchedFactionIndexOpcode(WorldPacket& recvPacket);
	void HandleTogglePVPOpcode(WorldPacket& recvPacket);
	void HandleAmmoSetOpcode(WorldPacket& recvPacket);
	void HandleGameObjectUse(WorldPacket& recvPacket);
	// void HandleJoinChannelOpcode(WorldPacket& recvPacket);
	// void HandleLeaveChannelOpcode(WorldPacket& recvPacket);
	void HandlePlayedTimeOpcode(WorldPacket & recv_data);
	void HandleSetSheathedOpcode(WorldPacket & recv_data);
	void HandleCompleteCinematic(WorldPacket & recv_data);
	void HandleInspectOpcode( WorldPacket & recv_data );

	// Gm Ticket System in GMTicket.cpp:
	void HandleGMTicketCreateOpcode(WorldPacket& recvPacket);
	void HandleGMTicketUpdateOpcode(WorldPacket& recvPacket);
	void HandleGMTicketDeleteOpcode(WorldPacket& recvPacket);
	void HandleGMTicketGetTicketOpcode(WorldPacket& recvPacket);
	void HandleGMTicketSystemStatusOpcode(WorldPacket& recvPacket);
	void HandleGMTicketToggleSystemStatusOpcode(WorldPacket& recvPacket);

	// Opcodes implemented in QueryHandler.cpp:
	void HandleNameQueryOpcode(WorldPacket& recvPacket);
	void HandleQueryTimeOpcode(WorldPacket& recvPacket);
	void HandleCreatureQueryOpcode(WorldPacket& recvPacket);
	void HandleGameObjectQueryOpcode(WorldPacket& recvPacket);
	void HandleItemNameQueryOpcode( WorldPacket & recv_data );
	void HandlePageTextQueryOpcode( WorldPacket & recv_data );

	// Opcodes implemented in MovementHandler.cpp
	void HandleMoveWorldportAckOpcode( WorldPacket& recvPacket );
	void HandleMovementOpcodes( WorldPacket& recvPacket );
	void HandleMoveFallResetOpcode( WorldPacket & recvPacket);
	void HandleMoveTimeSkippedOpcode( WorldPacket & recv_data );
	void HandleMoveNotActiveMoverOpcode( WorldPacket & recv_data );
	void HandleSetActiveMoverOpcode( WorldPacket & recv_data );
	void HandleMoveTeleportAckOpcode( WorldPacket & recv_data );

	// Opcodes implemented in GroupHandler.cpp:
	void HandleGroupInviteOpcode(WorldPacket& recvPacket);
	void HandleGroupCancelOpcode(WorldPacket& recvPacket);
	void HandleGroupAcceptOpcode(WorldPacket& recvPacket);
	void HandleGroupDeclineOpcode(WorldPacket& recvPacket);
	void HandleGroupUninviteOpcode(WorldPacket& recvPacket);
	void HandleGroupUninviteGUIDOpcode(WorldPacket& recvPacket);
	void HandleGroupSetLeaderOpcode(WorldPacket& recvPacket);
	void HandleGroupDisbandOpcode(WorldPacket& recvPacket);
	void HandleLootMethodOpcode(WorldPacket& recvPacket);
	void HandleMinimapPingOpcode(WorldPacket& recvPacket);
	void HandleSetPlayerIconOpcode(WorldPacket& recv_data);
	void SendPartyCommandResult(PlayerPointer pPlayer, uint32 p1, std::string name, uint32 err);

	// Raid
	void HandleConvertGroupToRaidOpcode(WorldPacket& recvPacket);
    void HandleWorldStateUITimerUpdate(WorldPacket& recv_data);
	void HandleGroupChangeSubGroup(WorldPacket& recvPacket);
	void HandleGroupAssistantLeader(WorldPacket& recvPacket);
	void HandleRequestRaidInfoOpcode(WorldPacket& recvPacket);
	void HandleReadyCheckOpcode(WorldPacket& recv_data);
	void HandleGroupPromote(WorldPacket& recv_data);

	// LFG opcodes
	void HandleEnableAutoJoin(WorldPacket& recvPacket);
	void HandleDisableAutoJoin(WorldPacket& recvPacket);
	void HandleEnableAutoAddMembers(WorldPacket& recvPacket);
	void HandleDisableAutoAddMembers(WorldPacket& recvPacket);
	void HandleSetLookingForGroupComment(WorldPacket& recvPacket);
	void HandleMsgLookingForGroup(WorldPacket& recvPacket);
	void HandleSetLookingForGroup(WorldPacket& recvPacket);
	void HandleSetLookingForMore(WorldPacket& recvPacket);
	void HandleSetLookingForNone(WorldPacket& recvPacket);
	void HandleLfgClear(WorldPacket & recvPacket);
	void HandleLfgInviteAccept(WorldPacket & recvPacket);
	void HandleLfgInviteDeny(WorldPacket & recvPacket);

	// Taxi opcodes (TaxiHandler.cpp)
	void HandleTaxiNodeStatusQueryOpcode(WorldPacket& recvPacket);
	void HandleTaxiQueryAvaibleNodesOpcode(WorldPacket& recvPacket);
	void HandleActivateTaxiOpcode(WorldPacket& recvPacket);
	void HandleMultipleActivateTaxiOpcode(WorldPacket & recvPacket);

	// NPC opcodes (NPCHandler.cpp)
	void HandleTabardVendorActivateOpcode(WorldPacket& recvPacket);
	void HandleBankerActivateOpcode(WorldPacket& recvPacket);
	void HandleBuyBankSlotOpcode(WorldPacket& recvPacket); 
	void HandleTrainerListOpcode(WorldPacket& recvPacket);
	void HandleTrainerBuySpellOpcode(WorldPacket& recvPacket);
	void HandleCharterShowListOpcode(WorldPacket& recvPacket);
	void HandleGossipHelloOpcode(WorldPacket& recvPacket);
	void HandleGossipSelectOptionOpcode(WorldPacket& recvPacket);
	void HandleSpiritHealerActivateOpcode(WorldPacket& recvPacket);
	void HandleNpcTextQueryOpcode(WorldPacket& recvPacket);
	void HandleBinderActivateOpcode(WorldPacket& recvPacket);

	// Auction House opcodes
	void HandleAuctionHelloOpcode(WorldPacket& recvPacket);
	void HandleAuctionListItems( WorldPacket & recv_data );
	void HandleAuctionListBidderItems( WorldPacket & recv_data );
	void HandleAuctionSellItem( WorldPacket & recv_data );
	void HandleAuctionListOwnerItems( WorldPacket & recv_data );
	void HandleAuctionPlaceBid( WorldPacket & recv_data );
	void HandleCancelAuction( WorldPacket & recv_data);

	// Mail opcodes
	void HandleGetMail( WorldPacket & recv_data );
	void HandleSendMail( WorldPacket & recv_data );
	void HandleTakeMoney( WorldPacket & recv_data );
	void HandleTakeItem( WorldPacket & recv_data );
	void HandleMarkAsRead( WorldPacket & recv_data );
	void HandleReturnToSender( WorldPacket & recv_data );
	void HandleMailDelete( WorldPacket & recv_data );
	void HandleItemTextQuery( WorldPacket & recv_data);
	void HandleMailTime(WorldPacket & recv_data);
	void HandleMailCreateTextItem(WorldPacket & recv_data );

	// Item opcodes (ItemHandler.cpp)
	void HandleSwapInvItemOpcode(WorldPacket& recvPacket);
	void HandleSwapItemOpcode(WorldPacket& recvPacket);
	void HandleDestroyItemOpcode(WorldPacket& recvPacket);
	void HandleAutoEquipItemOpcode(WorldPacket& recvPacket);
	void HandleItemQuerySingleOpcode(WorldPacket& recvPacket);
	void HandleSellItemOpcode(WorldPacket& recvPacket);
	void HandleBuyItemInSlotOpcode(WorldPacket& recvPacket);
	void HandleBuyItemOpcode(WorldPacket& recvPacket);
	void HandleListInventoryOpcode(WorldPacket& recvPacket);
	void HandleAutoStoreBagItemOpcode(WorldPacket& recvPacket);
	void HandleBuyBackOpcode(WorldPacket& recvPacket);
	void HandleSplitOpcode(WorldPacket& recvPacket);
	void HandleReadItemOpcode(WorldPacket& recvPacket);
	void HandleRepairItemOpcode(WorldPacket &recvPacket);
	void HandleAutoBankItemOpcode(WorldPacket &recvPacket);
	void HandleAutoStoreBankItemOpcode(WorldPacket &recvPacket);
	void HandleCancelTemporaryEnchantmentOpcode(WorldPacket &recvPacket);
	void HandleInsertGemOpcode(WorldPacket &recvPacket);

	// Combat opcodes (CombatHandler.cpp)
	void HandleAttackSwingOpcode(WorldPacket& recvPacket);
	void HandleAttackStopOpcode(WorldPacket& recvPacket);

	// Spell opcodes (SpellHandler.cpp)
	void HandleUseItemOpcode(WorldPacket& recvPacket);
	void HandleCastSpellOpcode(WorldPacket& recvPacket);
	void HandleCancelCastOpcode(WorldPacket& recvPacket);
	void HandleCancelAuraOpcode(WorldPacket& recvPacket);
	void HandleCancelChannellingOpcode(WorldPacket& recvPacket);
	void HandleCancelAutoRepeatSpellOpcode(WorldPacket& recv_data);
	void HandleAddDynamicTargetOpcode(WorldPacket & recvPacket);

	// Skill opcodes (SkillHandler.spp)
	//void HandleSkillLevelUpOpcode(WorldPacket& recvPacket);
	void HandleLearnTalentOpcode(WorldPacket& recvPacket);
	void HandleLearnPreviewTalents(WorldPacket& recv_data);
	void HandleUnlearnTalents( WorldPacket & recv_data );

	// Quest opcodes (QuestHandler.cpp)
	void HandleQuestgiverStatusQueryOpcode(WorldPacket& recvPacket);
	void HandleQuestgiverHelloOpcode(WorldPacket& recvPacket);
	void HandleQuestgiverAcceptQuestOpcode(WorldPacket& recvPacket);
	void HandleQuestgiverCancelOpcode(WorldPacket& recvPacket);
	void HandleQuestgiverChooseRewardOpcode(WorldPacket& recvPacket);
	void HandleQuestgiverRequestRewardOpcode(WorldPacket& recvPacket);
	void HandleQuestGiverQueryQuestOpcode( WorldPacket& recvPacket );
	void HandleQuestQueryOpcode(WorldPacket& recvPacket);
	void HandleQuestgiverCompleteQuestOpcode( WorldPacket & recvPacket );
	void HandleQuestlogRemoveQuestOpcode(WorldPacket& recvPacket);
	void HandlePushQuestToPartyOpcode(WorldPacket &recvPacket);
	void HandleQuestPushResult(WorldPacket &recvPacket);

	// Chat opcodes (Chat.cpp)
	void HandleMessagechatOpcode(WorldPacket& recvPacket);
	void HandleTextEmoteOpcode(WorldPacket& recvPacket);
	void HandleReportSpamOpcode(WorldPacket& recvPacket);

	// Corpse opcodes (Corpse.cpp)
	void HandleCorpseReclaimOpcode( WorldPacket& recvPacket );
	void HandleCorpseQueryOpcode( WorldPacket& recvPacket );
	void HandleResurrectResponseOpcode(WorldPacket& recvPacket);

	// Channel Opcodes (ChannelHandler.cpp)
	void HandleChannelJoin(WorldPacket& recvPacket);
	void HandleChannelLeave(WorldPacket& recvPacket);
	void HandleChannelList(WorldPacket& recvPacket);
	void HandleChannelPassword(WorldPacket& recvPacket);
	void HandleChannelSetOwner(WorldPacket& recvPacket);
	void HandleChannelOwner(WorldPacket& recvPacket);
	void HandleChannelModerator(WorldPacket& recvPacket);
	void HandleChannelUnmoderator(WorldPacket& recvPacket);
	void HandleChannelMute(WorldPacket& recvPacket);
	void HandleChannelUnmute(WorldPacket& recvPacket);
	void HandleChannelInvite(WorldPacket& recvPacket);
	void HandleChannelKick(WorldPacket& recvPacket);
	void HandleChannelBan(WorldPacket& recvPacket);
	void HandleChannelUnban(WorldPacket& recvPacket);
	void HandleChannelAnnounce(WorldPacket& recvPacket);
	void HandleChannelModerate(WorldPacket& recvPacket);
	void HandleChannelNumMembersQuery(WorldPacket & recvPacket);
	void HandleChannelRosterQuery(WorldPacket & recvPacket);

	// Duel
	void HandleDuelAccepted(WorldPacket & recv_data);
	void HandleDuelCancelled(WorldPacket & recv_data);

	// Trade
	void HandleInitiateTrade(WorldPacket & recv_data);
	void HandleBeginTrade(WorldPacket & recv_data);
	void HandleBusyTrade(WorldPacket & recv_data);
	void HandleIgnoreTrade(WorldPacket & recv_data);
	void HandleAcceptTrade(WorldPacket & recv_data);
	void HandleUnacceptTrade(WorldPacket & recv_data);
	void HandleCancelTrade(WorldPacket & recv_data);
	void HandleSetTradeItem(WorldPacket & recv_data);
	void HandleClearTradeItem(WorldPacket & recv_data);
	void HandleSetTradeGold(WorldPacket & recv_data);

	// Guild
	void HandleGuildQuery(WorldPacket & recv_data);
	void HandleCreateGuild(WorldPacket & recv_data);				   
	void HandleInviteToGuild(WorldPacket & recv_data);			  
	void HandleGuildAccept(WorldPacket & recv_data);			 
	void HandleGuildDecline(WorldPacket & recv_data);
	void HandleGuildInfo(WorldPacket & recv_data);
	void HandleGuildRoster(WorldPacket & recv_data);
	void HandleGuildPromote(WorldPacket & recv_data);
	void HandleGuildDemote(WorldPacket & recv_data);
	void HandleGuildLeave(WorldPacket & recv_data);
	void HandleGuildRemove(WorldPacket & recv_data);
	void HandleGuildDisband(WorldPacket & recv_data);
	void HandleGuildLeader(WorldPacket & recv_data);
	void HandleGuildMotd(WorldPacket & recv_data);
	void HandleGuildRank(WorldPacket & recv_data);
	void HandleGuildAddRank(WorldPacket & recv_data);
	void HandleGuildDelRank(WorldPacket & recv_data);
	void HandleGuildSetPublicNote(WorldPacket & recv_data);
	void HandleGuildSetOfficerNote(WorldPacket & recv_data);
	void HandleSaveGuildEmblem(WorldPacket & recv_data);
	void HandleCharterBuy(WorldPacket & recv_data);
	void HandleCharterShowSignatures(WorldPacket & recv_data);
	void HandleCharterTurnInCharter(WorldPacket & recv_data);
	void HandleCharterQuery(WorldPacket & recv_data);
	void HandleCharterOffer(WorldPacket & recv_data);
	void HandleCharterSign(WorldPacket &recv_data);
	void HandleCharterRename(WorldPacket & recv_data);
	void HandleSetGuildInformation(WorldPacket & recv_data);
	void HandleGuildLog(WorldPacket & recv_data);
	void HandleGuildBankViewTab(WorldPacket & recv_data);
	void HandleGuildBankViewLog(WorldPacket & recv_data);
	void HandleGuildBankOpenVault(WorldPacket & recv_data);
	void HandleGuildBankBuyTab(WorldPacket & recv_data);
	void HandleGuildBankDepositMoney(WorldPacket & recv_data);
	void HandleGuildBankWithdrawMoney(WorldPacket & recv_data);
	void HandleGuildBankDepositItem(WorldPacket & recv_data);
	void HandleGuildBankWithdrawItem(WorldPacket & recv_data);
	void HandleGuildBankGetAvailableAmount(WorldPacket & recv_data);
	void HandleGuildBankModifyTab(WorldPacket & recv_data);
	void HandleGuildGetFullPermissions(WorldPacket & recv_data);

	// Pet
	void HandlePetAction(WorldPacket & recv_data);
	void HandlePetInfo(WorldPacket & recv_data);
	void HandlePetNameQuery(WorldPacket & recv_data);
	void HandleBuyStableSlot(WorldPacket & recv_data);
	void HandleStablePet(WorldPacket & recv_data);
	void HandleUnstablePet(WorldPacket & recv_data);
	void HandleStabledPetList(WorldPacket & recv_data);
	void HandleStableSwapPet(WorldPacket & recv_data);
	void HandlePetRename(WorldPacket & recv_data);
	void HandlePetAbandon(WorldPacket & recv_data);
	void HandlePetUnlearn(WorldPacket & recv_data);

	// Totems
	void HandleTotemDestroyed(WorldPacket & recv_data);

	// Battleground
	void HandleBattlefieldPortOpcode(WorldPacket &recv_data);
	void HandleBattlefieldStatusOpcode(WorldPacket &recv_data);
	void HandleBattleMasterHelloOpcode(WorldPacket &recv_data);
	void HandleLeaveBattlefieldOpcode(WorldPacket &recv_data);
	void HandleAreaSpiritHealerQueryOpcode(WorldPacket &recv_data);
	void HandleAreaSpiritHealerQueueOpcode(WorldPacket &recv_data);
	void HandleBattlegroundPlayerPositionsOpcode(WorldPacket &recv_data);
	void HandleArenaJoinOpcode(WorldPacket &recv_data);
	void HandleBattleMasterJoinOpcode(WorldPacket &recv_data);
	void HandleInspectHonorStatsOpcode(WorldPacket &recv_data);
	void HandlePVPLogDataOpcode(WorldPacket &recv_data);
	void HandleBattlefieldListOpcode(WorldPacket &recv_data);

	void HandleSetActionBarTogglesOpcode(WorldPacket &recvPacket);
	void HandleMoveSplineCompleteOpcode(WorldPacket &recvPacket);

	// Helper functions
	void SetNpcFlagsForTalkToQuest(const uint64& guid, const uint64& targetGuid);

	//Tutorials
	void HandleTutorialFlag ( WorldPacket & recv_data );
	void HandleTutorialClear( WorldPacket & recv_data );
	void HandleTutorialReset( WorldPacket & recv_data );

	//Acknowledgements
	void HandleAcknowledgementOpcodes( WorldPacket & recv_data );
	void HandleMountSpecialAnimOpcode(WorldPacket& recv_data);	

	void HandleSelfResurrectOpcode(WorldPacket& recv_data);
	void HandleUnlearnSkillOpcode(WorldPacket &recv_data);
	void HandleRandomRollOpcode(WorldPacket &recv_data);
	void HandleOpenItemOpcode(WorldPacket &recv_data);
	
	void HandleToggleHelmOpcode(WorldPacket &recv_data);
	void HandleToggleCloakOpcode(WorldPacket &recv_data);
	void HandleSetVisibleRankOpcode(WorldPacket& recv_data);
	void HandlePetSetActionOpcode(WorldPacket& recv_data);

	// instances
	void HandleResetInstanceOpcode(WorldPacket& recv_data);
	void HandleDungeonDifficultyOpcode(WorldPacket& recv_data);
	void HandleRaidDifficultyOpcode(WorldPacket& recv_data);

	uint8 TrainerGetSpellStatus(TrainerSpell* pSpell);
	void SendMailError(uint32 error);

	void HandleCharRenameOpcode(WorldPacket & recv_data);
	void HandlePartyMemberStatsOpcode(WorldPacket & recv_data);
	void HandleSummonResponseOpcode(WorldPacket & recv_data);

	void HandleArenaTeamAddMemberOpcode(WorldPacket & recv_data);
	void HandleArenaTeamRemoveMemberOpcode(WorldPacket & recv_data);
	void HandleArenaTeamInviteAcceptOpcode(WorldPacket & recv_data);
	void HandleArenaTeamInviteDenyOpcode(WorldPacket & recv_data);
	void HandleArenaTeamLeaveOpcode(WorldPacket & recv_data);
	void HandleArenaTeamDisbandOpcode(WorldPacket & recv_data);
	void HandleArenaTeamPromoteOpcode(WorldPacket & recv_data);
	void HandleArenaTeamQueryOpcode(WorldPacket & recv_data);
	void HandleArenaTeamRosterOpcode(WorldPacket & recv_data);
	void HandleInspectArenaStatsOpcode(WorldPacket & recv_data);

	void HandleTeleportCheatOpcode(WorldPacket & recv_data);
	void HandleTeleportToUnitOpcode(WorldPacket & recv_data);
	void HandleWorldportOpcode(WorldPacket & recv_data);
	void HandleWrapItemOpcode(WorldPacket& recv_data);

	// Voicechat
	void HandleEnableMicrophoneOpcode(WorldPacket & recv_data);
	void HandleVoiceChatQueryOpcode(WorldPacket & recv_data);
	void HandleChannelVoiceQueryOpcode(WorldPacket & recv_data);
	void HandleSetAutoLootPassOpcode(WorldPacket & recv_data);

	void HandleSetFriendNote(WorldPacket & recv_data);
	void Handle38C(WorldPacket & recv_data);
	void HandleInrangeQuestgiverQuery(WorldPacket & recv_data);

	// Misc Opcodes
	void HandleAlterAppearance(WorldPacket & recv_data);
	void HandleAchievementInspect(WorldPacket & recv_data);
	void HandleRemoveGlyph(WorldPacket & recv_data);

	// Vehicles
	void HandleVehicleDismiss(WorldPacket & recv_data);
	void HandleSpellClick( WorldPacket & recv_data );

public:
	void SendTradeStatus(uint32 TradeStatus);
	void SendInventoryList(CreaturePointer pCreature);
	void SendTrainerList(CreaturePointer pCreature);
	void SendCharterRequest(CreaturePointer pCreature);
	void SendTaxiList(CreaturePointer pCreature);
	void SendInnkeeperBind(CreaturePointer pCreature);
	void SendBattlegroundList(CreaturePointer pCreature, uint32 mapid);
	void SendBankerList(CreaturePointer pCreature);
	void SendTabardHelp(CreaturePointer pCreature);
	void SendAuctionList(CreaturePointer pCreature);
	void SendSpiritHealerRequest(CreaturePointer pCreature);
	void FullLogin(PlayerPointer plr);
    void SendAccountDataTimes(uint32 mask);
	
	float m_wLevel; // Level of water the player is currently in
	bool m_bIsWLevelSet; // Does the m_wLevel variable contain up-to-date information about water level?

	MovementInfo* GetMovementInfo() { return &movement_info; }

private:
	friend class Player;
	PlayerPointer _player;
	WorldSocket *_socket;
		
	/* Preallocated buffers for movement handlers */
	MovementInfo movement_info;

	bool m_isFalling;

	uint32 _accountId;
	uint32 _accountFlags;
	string _accountName;
	int8 _side;

	WoWGuid m_MoverWoWGuid;

	uint32 _logoutTime; // time we received a logout request -- wait 20 seconds, and quit

	AccountDataEntry sAccountData[8];

	FastQueue<WorldPacket*, Mutex> _recvQueue;
	char *permissions;
	int permissioncount;

	bool _loggingOut; // Player will be logged out in 20 seconds
	bool LoggingOut;  // Player is waiting to be logged out.
	uint32 _latency;
	uint32 client_build;
	uint32 instanceId;
	uint8 _updatecount;
public:
	static void InitPacketHandlerTable();
	uint32 floodLines;
	time_t floodTime;
	void SystemMessage(const char * format, ...);
	uint32 language;
	WorldPacket* BuildQuestQueryResponse(Quest *qst);
	uint32 m_muted;
	uint32 m_lastEnumTime;
	uint32 m_lastWhoTime;
	bool m_asyncQuery;

protected:
	uint32 m_repeatTime;
	string m_repeatMessage;
	uint32 m_repeatEmoteTime;
	uint32 m_repeatEmoteId;
};

typedef std::set<WorldSession*> SessionSet;

#endif
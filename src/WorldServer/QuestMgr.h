/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __QUESTMGR_H
#define __QUESTMGR_H

enum RepeatableTypes
{
	REPEATABLE_QUEST	= 1,
	REPEATABLE_DAILY	= 2,
};

struct QuestRelation
{
	Quest *qst;
	uint8 type;
};

struct QuestAssociation
{
	Quest *qst;
	uint8 item_count;
};

class Item;

typedef std::list<QuestRelation *> QuestRelationList;
typedef std::list<QuestAssociation *> QuestAssociationList;

class SERVER_DECL QuestMgr :  public Singleton < QuestMgr >
{
public:

	~QuestMgr();

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

	uint32 PlayerMeetsReqs(PlayerPointer plr, Quest* qst, bool skiplevelcheck);

	uint8 CalcStatus(ObjectPointer quest_giver, PlayerPointer plr);
	uint32 CalcQuestStatus(ObjectPointer quest_giver, PlayerPointer plr, QuestRelation* qst);
	uint32 CalcQuestStatus(ObjectPointer quest_giver, PlayerPointer plr, Quest* qst, uint8 type, bool skiplevelcheck);
	uint32 ActiveQuestsCount(ObjectPointer quest_giver, PlayerPointer plr);

	//Packet Forging...
	void BuildOfferReward(WorldPacket* data,Quest* qst, ObjectPointer qst_giver, uint32 menutype, uint32 language, PlayerPointer plr);
	void BuildQuestDetails(WorldPacket* data, Quest* qst, ObjectPointer qst_giver, uint32 menutype, uint32 language, PlayerPointer plr);	
	void BuildRequestItems(WorldPacket* data, Quest* qst, ObjectPointer qst_giver, uint32 status, uint32 language);
	void BuildQuestComplete(PlayerPointer , Quest* qst);
	void BuildQuestList(WorldPacket* data, ObjectPointer qst_giver, PlayerPointer plr, uint32 language);
	bool OnActivateQuestGiver(ObjectPointer qst_giver, PlayerPointer plr);
    bool isRepeatableQuestFinished(PlayerPointer plr, Quest *qst);

	void SendQuestUpdateAddKill(PlayerPointer plr, uint32 questid, uint32 entry, uint32 count, uint32 tcount, uint64 guid);
	void BuildQuestUpdateAddItem(WorldPacket* data, uint32 itemid, uint32 count);
	void BuildQuestUpdateComplete(WorldPacket* data, Quest* qst);
	void BuildQuestFailed(WorldPacket* data, uint32 questid);
	void SendPushToPartyResponse(PlayerPointer plr, PlayerPointer pTarget, uint32 response);

	bool OnGameObjectActivate(PlayerPointer plr, GameObjectPointer go);
	void _OnPlayerKill(PlayerPointer plr, uint32 creature_entry);
	void OnPlayerKill(PlayerPointer plr, CreaturePointer victim);
	void OnPlayerCast(PlayerPointer plr, uint32 spellid, uint64& victimguid);
	void OnPlayerItemPickup(PlayerPointer plr, ItemPointer item);
	void OnPlayerExploreArea(PlayerPointer plr, uint32 AreaID);
	void OnPlayerSlain(PlayerPointer plr, PlayerPointer victim);
	void OnQuestAccepted(PlayerPointer plr, Quest* qst, ObjectPointer qst_giver);
	void OnQuestFinished(PlayerPointer plr, Quest* qst, ObjectPointer qst_giver, uint32 reward_slot);
	bool SkippedKills( uint32 QuestID );

	void GiveQuestRewardReputation(PlayerPointer plr, Quest* qst, ObjectPointer qst_giver);
	void GiveQuestTitleReward(PlayerPointer plr, Quest* qst);

	uint32 GenerateQuestXP(PlayerPointer pl, Quest *qst);
	uint32 GenerateRewardMoney(PlayerPointer pl, Quest *qst);

	void SendQuestInvalid( INVALID_REASON reason, PlayerPointer plyr);
	void SendQuestFailed(FAILED_REASON failed, Quest *qst, PlayerPointer plyr);
	void SendQuestUpdateFailed(Quest *pQuest, PlayerPointer plyr);
	void SendQuestUpdateFailedTimer(Quest *pQuest, PlayerPointer plyr);
	void SendQuestLogFull(PlayerPointer plyr);
	
	void LoadNPCQuests(CreaturePointer qst_giver);
	void LoadGOQuests(GameObjectPointer go);

	QuestRelationList* GetCreatureQuestList(uint32 entryid);
	QuestRelationList* GetGOQuestList(uint32 entryid);
	QuestAssociationList* GetQuestAssociationListForItemId (uint32 itemId);

	uint32 GetGameObjectLootQuest(uint32 GO_Entry);
	void SetGameObjectLootQuest(uint32 GO_Entry, uint32 Item_Entry);
	ARCTIC_INLINE bool IsQuestRepeatable(Quest *qst) { return (qst->is_repeatable!=0 ? true : false); }
	ARCTIC_INLINE bool IsQuestDaily(Quest *qst) { return (qst->is_repeatable==2 ? true : false); }

	bool CanStoreReward(PlayerPointer plyr, Quest *qst, uint32 reward_slot);

	ARCTIC_INLINE int32 QuestHasMob(Quest* qst, uint32 mob)
	{
		for(uint32 i = 0; i < 4; ++i)
			if(qst->required_mob[i] == mob)
				return qst->required_mobcount[i];
		return -1;
	}

	ARCTIC_INLINE int32 GetOffsetForMob(Quest *qst, uint32 mob)
	{
		for(uint32 i = 0; i < 4; ++i)
			if(qst->required_mob[i] == mob)
				return i;

		return -1;
	}

	ARCTIC_INLINE int32 GetOffsetForItem(Quest *qst, uint32 itm)
	{
		for(uint32 i = 0; i < 4; ++i)
			if(qst->required_item[i] == itm)
				return i;

		return -1;
	}
	void LoadExtraQuestStuff();

private:

	HM_NAMESPACE::hash_map<uint32, list<QuestRelation *>* > m_npc_quests;
	HM_NAMESPACE::hash_map<uint32, list<QuestRelation *>* > m_obj_quests;
	HM_NAMESPACE::hash_map<uint32, list<QuestRelation *>* > m_itm_quests;
	list<uint32> m_extraqueststuff_list;

	HM_NAMESPACE::hash_map<uint32, list<QuestAssociation *>* > m_quest_associations;
	HM_NAMESPACE::hash_map<uint32, list<QuestAssociation *>* >& GetQuestAssociationList(){return m_quest_associations;}

	HM_NAMESPACE::hash_map<uint32, uint32>		  m_ObjectLootQuestList;

	template <class T> void _AddQuest(uint32 entryid, Quest *qst, uint8 type);

	template <class T> HM_NAMESPACE::hash_map<uint32, list<QuestRelation *>* >& _GetList();

	void AddItemQuestAssociation( uint32 itemId, Quest *qst, uint8 item_count);

	// Quest Loading
	void _RemoveChar(char* c, std::string *str);
	void _CleanLine(std::string *str);
};

template<> ARCTIC_INLINE HM_NAMESPACE::hash_map<uint32, list<QuestRelation *>* >& QuestMgr::_GetList<Creature>()
	{return m_npc_quests;}
template<> ARCTIC_INLINE HM_NAMESPACE::hash_map<uint32, list<QuestRelation *>* >& QuestMgr::_GetList<GameObject>()
	{return m_obj_quests;}
template<> ARCTIC_INLINE HM_NAMESPACE::hash_map<uint32, list<QuestRelation *>* >& QuestMgr::_GetList<Item>()
	{return m_itm_quests;}


#define sQuestMgr QuestMgr::getSingleton()

#endif

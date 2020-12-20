/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#include "StdAfx.h"

/************************************************************************/
/* Talent Anti-Cheat                                                    */
/************************************************************************/

void WorldSession::HandleLearnTalentOpcode( WorldPacket & recv_data )
{
	CHECK_INWORLD_RETURN;
 	 
	uint32 talent_id, requested_rank;	
	recv_data >> talent_id >> requested_rank;

	_player->LearnTalent(talent_id, requested_rank);

	_player->UpdateTalentInspectBuffer();
	_player->smsg_TalentsInfo(false);
}

void WorldSession::HandleLearnPreviewTalents( WorldPacket & recv_data )
{
	uint32 count = 0;
	uint32 talent_id, requested_rank;
	recv_data >> count;
	for(uint32 i = 0; i < count && recv_data.rpos() < recv_data.size(); i++)
	{
		recv_data >> talent_id >> requested_rank;
		_player->LearnTalent(talent_id, requested_rank);
	}
	_player->UpdateTalentInspectBuffer();
	_player->smsg_TalentsInfo(false);
}

void WorldSession::HandleTalentWipeConfirmOpcode( WorldPacket & recv_data )
{
	CHECK_INWORLD_RETURN;
	uint32 playerGold = GetPlayer()->GetUInt32Value( PLAYER_FIELD_COINAGE );
	uint32 price = GetPlayer()->CalcTalentResetCost(GetPlayer()->GetTalentResetTimes());

	if( playerGold < price ) return;

	GetPlayer()->SetTalentResetTimes(GetPlayer()->GetTalentResetTimes() + 1);
	GetPlayer()->SetUInt32Value( PLAYER_FIELD_COINAGE, playerGold - price );
	GetPlayer()->Reset_Talents();

	GetPlayer()->GetAchievementInterface()->HandleAchievementCriteriaTalentResetCostTotal( price );
	GetPlayer()->GetAchievementInterface()->HandleAchievementCriteriaTalentResetCount();
}

void WorldSession::HandleUnlearnSkillOpcode(WorldPacket& recv_data)
{
	CHECK_INWORLD_RETURN;
	uint32 skill_line;
	uint32 points_remaining=_player->GetUInt32Value(PLAYER_CHARACTER_POINTS2);
	recv_data >> skill_line;

	// Cheater detection
	// if(!_player->HasSkillLine(skill_line)) return;

	// Remove any spells within that line that the player has
	_player->RemoveSpellsFromLine(skill_line);
	
	// Remove any quests finished and active for this skill
	_player->RemoveQuestsFromLine(skill_line);

	// Finally, remove the skill line.
	_player->_RemoveSkillLine(skill_line);

	//added by Zack : This is probably wrong or already made elsewhere : restore skill learnability
	if(points_remaining==_player->GetUInt32Value(PLAYER_CHARACTER_POINTS2))
	{
		//we unlearned a kill so we enable a new one to be learned
		skilllineentry *sk=dbcSkillLine.LookupEntry(skill_line);
		if(!sk)
			return;
		if(sk->type==SKILL_TYPE_PROFESSION && points_remaining<2)
			_player->SetUInt32Value(PLAYER_CHARACTER_POINTS2,points_remaining+1);
	}
}

/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#include "StdAfx.h"

#define FACTION_FLAG_HIDDEN 4                
#define FACTION_FLAG_INVISIBLE_FORCED 8               
#define FACTION_FLAG_PEACE_FORCED 16  
#define FACTION_FLAG_AT_WAR  2
#define FACTION_FLAG_VISIBLE 1

Standing Player::GetReputationRankFromStanding(int32 Standing_)
{
	if( Standing_ >= 42000 )  
		return STANDING_EXALTED;  
	else if( Standing_ >= 21000 )  
		return STANDING_REVERED;  
	else if( Standing_ >= 9000 )  
		return STANDING_HONORED;  
	else if( Standing_ >= 3000 )  
		return STANDING_FRIENDLY;  
	else if( Standing_ >= 0 )  
		return STANDING_NEUTRAL;  
	else if( Standing_ > -3000 )  
		return STANDING_UNFRIENDLY;  
	else if( Standing_ > -6000 )  
		return STANDING_HOSTILE;  
	return STANDING_HATED;  
}

ARCTIC_INLINE void SetFlagAtWar(uint8 & flag)
{
	if(flag & FACTION_FLAG_AT_WAR)
		return;

	flag |= FACTION_FLAG_AT_WAR;
}

ARCTIC_INLINE void UnsetFlagAtWar(uint8 & flag)
{
	if(!(flag & FACTION_FLAG_AT_WAR))
		return;

	flag &= ~FACTION_FLAG_AT_WAR;
}

ARCTIC_INLINE void SetFlagVisible(uint8 & flag)
{
	if(flag & FACTION_FLAG_VISIBLE)
		return;

	flag |= FACTION_FLAG_VISIBLE;
}

ARCTIC_INLINE void SetFlagPeaceForced(uint8 & flag)
{
	if(flag & FACTION_FLAG_PEACE_FORCED)
		return;

	flag |= FACTION_FLAG_PEACE_FORCED;
}

ARCTIC_INLINE void SetForcedInvisible(uint8 & flag)
{
	if(flag & FACTION_FLAG_INVISIBLE_FORCED)
		return;

	flag |= FACTION_FLAG_INVISIBLE_FORCED;
}

ARCTIC_INLINE void UnsetFlagVisible(uint8 & flag)
{
	if(!(flag & FACTION_FLAG_VISIBLE))
		return;

	flag &= ~FACTION_FLAG_VISIBLE;
}

ARCTIC_INLINE bool AtWar(uint8 flag) { return (flag & FACTION_FLAG_AT_WAR) ? true : false; }
ARCTIC_INLINE bool Visible(uint8 flag) { return (flag & FACTION_FLAG_VISIBLE) ? true : false; }

ARCTIC_INLINE bool RankChanged(int32 Standing, int32 Change)
{
	if(Player::GetReputationRankFromStanding(Standing) != Player::GetReputationRankFromStanding(Standing + Change))
		return true;
	else
		return false;
}

ARCTIC_INLINE bool RankChangedFlat(int32 Standing, int32 NewStanding)
{
	if(Player::GetReputationRankFromStanding(Standing) != Player::GetReputationRankFromStanding(NewStanding))
		return true;
	else
		return false;
}

void Player::smsg_InitialFactions()
{
	WorldPacket data(SMSG_INITIALIZE_FACTIONS, 764);
	data << uint32(128);
	FactionReputation * rep;
	for(uint32 i = 0; i < 128; ++i)
	{
		rep = reputationByListId[i];
		if(rep)
		{
			if(rep->flag & 2 && rep->standing >= 0)
			{
				DEBUG_LOG("Player","smsg_InitialFactions reputationByListId[%u]", i);
			}
			// TODO fix. Structure is right but need to filter sent data.
			// crashes client when opening rep window with assert((value >= min) && (value <= max))
			data << rep->flag << rep->CalcStanding();
			//data << uint8(0) << uint32(0);
		}
		else
			data << uint8(0) << uint32(0);
	}
	m_session->SendPacket(&data);
}

void Player::_InitialReputation()
{
	// Generate Initial Reputation Values
	FactionReputation * rep;
	FactionDBC * f;
	int32 BaseRep = 0;
	uint32 j;
	uint32 RaceMask = getRaceMask();
	for(uint32 i = 0; i < dbcFaction.GetNumRows(); ++i)
	{
		f = dbcFaction.LookupRow(i);
		if(f == 0) continue;

		// Get Base Reputation
		for(j = 0; j < 4; ++j)
		{
			if(f->baseRepMask[j] & RaceMask)
			{
				BaseRep = f->baseRepValue[j];
				break;
			}
		}

		if(j != 4 && f->RepListId >= 0)
		{
			// This is one we can add.
			rep = new FactionReputation;
			rep->standing = BaseRep;
			rep->flag = 0;
			rep->baseStanding = BaseRep;
			if(GetReputationRankFromStanding(BaseRep) <= STANDING_HOSTILE)
				SetFlagAtWar(rep->flag);

			// Visible-ness shit.
			if((f->parentFaction == 469 && GetTeam() == 0) ||		// Alliance own faction.
				(f->parentFaction == 67 && GetTeam() == 1) )		 // Horde own faction.
			{
				SetFlagVisible(rep->flag);
				SetFlagPeaceForced(rep->flag);
			}

			if((f->parentFaction == 469 && GetTeam() == 1) ||		// Alliance own faction.
				(f->parentFaction == 67 && GetTeam() == 0) )		 // Horde own faction.
			{
				SetForcedInvisible(rep->flag);
			}
				
			reputationByListId[f->RepListId] = rep;
		}
		else
		{
			// No default standing.
			continue;
		}

		m_reputation[f->ID] = rep;
	}
}

int32 Player::GetStanding(uint32 Faction)
{
	ReputationMap::iterator itr = m_reputation.find(Faction);
	if(itr == m_reputation.end()) return 0;
	else return itr->second->standing;
}

int32 Player::GetBaseStanding(uint32 Faction)
{
	ReputationMap::iterator itr = m_reputation.find(Faction);
	if(itr == m_reputation.end()) return 0;
	else return itr->second->baseStanding;
}

void Player::SetStanding(uint32 Faction, int32 Value)
{
	ReputationMap::iterator itr = m_reputation.find(Faction);
	FactionDBC * dbc = dbcFaction.LookupEntry(Faction);
	if(dbc == 0) return;

	if(itr == m_reputation.end())
	{
		// New faction!
		FactionReputation * rep = new FactionReputation;
		rep->flag = 0;
		rep->standing = Value;
		rep->baseStanding = 0;
		m_reputation[dbc->ID] = rep;
		if(dbc->RepListId >= 0)
			reputationByListId[dbc->RepListId] = rep;
	}
	else
	{
		// Increment it.
		if(RankChangedFlat(itr->second->standing, Value))
		{
			itr->second->standing = Value;
			UpdateInrangeSetsBasedOnReputation();
		}
		else
		{
			itr->second->standing = Value;
		}

		// Set visible if invisible.
		if(!Visible(itr->second->flag))
		{
			SetFlagVisible(itr->second->flag);
			if(IsInWorld())
				m_session->OutPacket(SMSG_SET_FACTION_VISIBLE, 4, &dbc->RepListId);
		}

		// Set at war if we're beyond hostile.
		Standing rank = GetReputationRankFromStanding(itr->second->standing);
		if(rank <= STANDING_HOSTILE && !AtWar(itr->second->flag))
			SetFlagAtWar(itr->second->flag);
		else if(rank >= STANDING_NEUTRAL && AtWar(itr->second->flag))
			UnsetFlagAtWar(itr->second->flag);

		if(IsInWorld())
		{
			WorldPacket data(SMSG_SET_FACTION_STANDING, 12);
			data << uint32(0) << uint8(0) << uint32(itr->second->flag) << dbc->RepListId << itr->second->CalcStanding();
			m_session->SendPacket(&data);
		}
	}
}

Standing Player::GetStandingRank(uint32 Faction)
{
	return Standing(GetReputationRankFromStanding(GetStanding(Faction)));
}

bool Player::IsHostileBasedOnReputation(FactionDBC * dbc)
{
	if(dbc->RepListId < 0 || dbc->RepListId >= 128)
		return false;

	FactionReputation * rep = reputationByListId[dbc->RepListId];
	if(!rep) return false;

	// forced reactions take precedence
	if( m_forcedReactions.size() )
	{
		map<uint32,uint32>::iterator itr = m_forcedReactions.find( dbc->ID );
		if( itr != m_forcedReactions.end() )
			return ( itr->second <= STANDING_HOSTILE ) ? true : false;
	}

	if(rep->flag & FACTION_FLAG_AT_WAR || GetReputationRankFromStanding(rep->standing) <= STANDING_HOSTILE)
		return true;
	else
		return false;

	/*map<uint32, FactionReputation>::iterator itr = m_reputation.find(Faction);
	if(itr == m_reputation.end()) return false;
	if(itr->second.flag & FACTION_FLAG_AT_WAR || GetReputationRankFromStanding(itr->second.standing) <= STANDING_HOSTILE)
		return true;
	else
		return false;*/
}

void Player::ModStanding(uint32 Faction, int32 Value)
{
	ReputationMap::iterator itr = m_reputation.find(Faction);
	FactionDBC * dbc = dbcFaction.LookupEntry(Faction);
	if(dbc == 0) return;

	if(itr == m_reputation.end())
	{
		// New faction!
		FactionReputation * rep = new FactionReputation;
		rep->flag = 0;
		rep->standing = Value;
		rep->baseStanding = 0;
		m_reputation[dbc->ID] = rep;
		if(dbc->RepListId >= 0)
			reputationByListId[dbc->RepListId] = rep;
	}
	else
	{
		// Bonus
		if(pctReputationMod > 0)
		{
			float d = float(float(pctReputationMod) / 100.0f);
			Value += FL2UINT( float( float(Value) * d ) );
		}

		// Increment it.
		if(RankChanged(itr->second->standing, Value))
		{
			itr->second->standing += Value;
			UpdateInrangeSetsBasedOnReputation();
		}
		else
		{
			itr->second->standing += Value;
		}

		// Set visible if invisible.
		if(!Visible(itr->second->flag))
		{
			SetFlagVisible(itr->second->flag);
			if(IsInWorld())
				m_session->OutPacket(SMSG_SET_FACTION_VISIBLE, 4, &dbc->RepListId);
		}

		// Set at war if we're beyond hostile.
		if(GetReputationRankFromStanding(itr->second->standing) <= STANDING_HOSTILE && !AtWar(itr->second->flag))
			SetFlagAtWar(itr->second->flag);

		if(IsInWorld() && Visible(itr->second->flag))
		{
			WorldPacket data(SMSG_SET_FACTION_STANDING, 12);
			data << uint32(0) << uint8(0) << uint32(1) << dbc->RepListId << itr->second->CalcStanding();
			m_session->SendPacket(&data);
		}
   }
}

void Player::SetAtWar(uint32 Faction, bool Set)
{
	if( Faction >= 128 )
		return;

	FactionReputation * rep = reputationByListId[Faction];
	if(!rep) return;
	
	if(GetReputationRankFromStanding(rep->standing) <= STANDING_HOSTILE && !Set) // At this point we have to be at war.
		return;

	FactionDBC * f = dbcFaction.LookupEntry(Faction);
	if(rep->flag & 0x4)
		return;

	if(Set)
	{
		if(!AtWar(rep->flag))
			SetFlagAtWar(rep->flag);

		UpdateInrangeSetsBasedOnReputation();
	}
	else
	{
		if(AtWar(rep->flag))
			UnsetFlagAtWar(rep->flag);

		UpdateInrangeSetsBasedOnReputation();
	}
}

void WorldSession::HandleSetAtWarOpcode(WorldPacket& recv_data)
{
	uint32 id;
	uint8 state;
	recv_data >> id >> state;

	if(state == 1)
		_player->SetAtWar(id, true);
	else
		_player->SetAtWar(id, false);
}

void Player::UpdateInrangeSetsBasedOnReputation()
{
	// This function assumes that the opp faction set for player = the opp faction set for the unit.
	InRangeSet::iterator itr;
	Unit* pUnit;
	bool rep_value;
	bool enemy_current;
	for( itr = m_objectsInRange.begin(); itr != m_objectsInRange.end(); ++itr )
	{
		if( (*itr)->GetTypeId() != TYPEID_UNIT )
			continue;

		pUnit = TO_UNIT( *itr );
		if(pUnit->m_factionDBC == NULL || pUnit->m_factionDBC->RepListId < 0)
			continue;

		rep_value = IsHostileBasedOnReputation( pUnit->m_factionDBC );
		enemy_current = IsInRangeOppFactSet( pUnit );

		if( rep_value && !enemy_current ) // We are now enemies.
			m_oppFactsInRange.insert( pUnit );
		else if( !rep_value && enemy_current )
			m_oppFactsInRange.erase( pUnit );
	}
}

void Player::Reputation_OnKilledUnit(Unit* pUnit, bool InnerLoop)
{
	// add rep for on kill
	if(pUnit->GetTypeId() != TYPEID_UNIT || pUnit->IsPet())
		return;

	Group * m_Group = m_playerInfo->m_Group;
	if(!InnerLoop && m_Group)
	{
		/* loop the rep for group members */
		m_Group->getLock().Acquire();
		GroupMembersSet::iterator it;
		for(uint32 i = 0; i < m_Group->GetSubGroupCount(); ++i)
		{
			for(it = m_Group->GetSubGroup(i)->GetGroupMembersBegin(); it != m_Group->GetSubGroup(i)->GetGroupMembersEnd(); ++it)
			{
				if((*it)->m_loggedInPlayer && (*it)->m_loggedInPlayer->isInRange(TO_PLAYER(this),100.0f))
					(*it)->m_loggedInPlayer->Reputation_OnKilledUnit(pUnit, true);
			}
		}
		m_Group->getLock().Release();
		return;
	}

	int team = GetTeam();
	ReputationModifier * modifier = objmgr.GetReputationModifier(pUnit->GetEntry(), pUnit->m_factionDBC->ID);
	if(modifier != 0)
	{
		// Apply this data.
		for(vector<ReputationMod>::iterator itr = modifier->mods.begin(); itr != modifier->mods.end(); itr++)
		{
			if(!(*itr).faction[team])
				continue;

			/* rep limit? */
			if (!IS_INSTANCE(GetMapId()) || (IS_INSTANCE(GetMapId()) && this->iInstanceType != MODE_HEROIC_5MEN))
			{
				if((*itr).replimit)
				{
					if(GetStanding((*itr).faction[team]) >= (int32)(*itr).replimit)
						continue;
				}
			}

			int32 value = int32(float(itr->value) * sWorld.getRate(RATE_KILLREPUTATION));
			//value *= sWorld.getRate(RATE_KILLREPUTATION);
			ModStanding(itr->faction[team], value);
		}
	}
	else
	{
		if(IS_INSTANCE(GetMapId()) && objmgr.HandleInstanceReputationModifiers(TO_PLAYER(this), pUnit))
			return;

		if(pUnit->m_factionDBC->RepListId < 0)
			return;

		// decrease rep by 5.
		int change = -5;
		change = int32((float(change) * sWorld.getRate(RATE_KILLREPUTATION)));
		ModStanding(pUnit->m_factionDBC->ID, change);
	}
}

void Player::Reputation_OnTalk(FactionDBC * dbc)
{
	// set faction visible if not visible
	if(!dbc || dbc->RepListId < 0)
		return;

	FactionReputation * rep = reputationByListId[dbc->RepListId];
	if(!rep)
		return;

	if(!Visible(rep->flag))
	{
		SetFlagVisible(rep->flag);
		if(IsInWorld())
			m_session->OutPacket(SMSG_SET_FACTION_VISIBLE, 4, &dbc->RepListId);
	}
}

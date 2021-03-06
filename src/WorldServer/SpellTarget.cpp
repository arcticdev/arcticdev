/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#include "StdAfx.h"

// Function pointer holder
pSpellTarget SpellTargetHandler[TOTAL_SPELL_TARGET] =
{
	&Spell::SpellTargetDefault,					// 0
	&Spell::SpellTargetSelf,					// 1
	&Spell::SpellTargetNULL,					// 2 Not handled (Test spells)
	&Spell::SpellTargetInvisibleAOE,			// 3
	&Spell::SpellTargetFriendly,				// 4
	&Spell::SpellTargetPet,						// 5
	&Spell::SpellTargetSingleTargetEnemy,		// 6
	&Spell::SpellTargetNULL,					// 7
	&Spell::SpellTargetCustomAreaOfEffect,		// 8
	&Spell::SpellTargetNULL,					// 9 Not handled (no spells)
	&Spell::SpellTargetNULL,					// 10 Not handled (no spells)
	&Spell::SpellTargetNULL,					// 11 Not handled (Test spells)
	&Spell::SpellTargetNULL,					// 12 Not handled (no spells)
	&Spell::SpellTargetNULL,					// 13 Not handled (no spells)
	&Spell::SpellTargetNULL,					// 14 Not handled (no spells)
	&Spell::SpellTargetAreaOfEffect,			// 15
	&Spell::SpellTargetAreaOfEffect,			// 16
	&Spell::SpellTargetNULL,					// 17 Target is a location
	&Spell::SpellTargetLandUnderCaster,			// 18
	&Spell::SpellTargetNULL,					// 19 Not handled (Test spells)
	&Spell::SpellTargetAllPartyMembersRangeNR,	// 20
	&Spell::SpellTargetSingleTargetFriend,		// 21
	&Spell::SpellTargetAoE,						// 22
	&Spell::SpellTargetSingleGameobjectTarget,	// 23
	&Spell::SpellTargetInFrontOfCaster,			// 24
	&Spell::SpellTargetSingleFriend,			// 25
	&Spell::SpellTargetGameobject_itemTarget,	// 26
	&Spell::SpellTargetPetOwner,				// 27
	&Spell::SpellTargetEnemysAreaOfEffect,		// 28 channeled
	&Spell::SpellTargetTypeTAOE,				// 29
	&Spell::SpellTargetAllyBasedAreaEffect,		// 30
	&Spell::SpellTargetScriptedEffects,			// 31
	&Spell::SpellTargetSummon,					// 32
	&Spell::SpellTargetNearbyPartyMembers,		// 33
	&Spell::SpellTargetNULL,					// 34 Not handled (No spells)
	&Spell::SpellTargetSingleTargetPartyMember,	// 35
	&Spell::SpellTargetScriptedEffects2,		// 36
	&Spell::SpellTargetPartyMember,				// 37
	&Spell::SpellTargetDummyTarget,				// 38
	&Spell::SpellTargetFishing,					// 39
	&Spell::SpellTargetType40,					// 40
	&Spell::SpellTargetTotem,					// 41
	&Spell::SpellTargetTotem,					// 42
	&Spell::SpellTargetTotem,					// 43
	&Spell::SpellTargetTotem,					// 44
	&Spell::SpellTargetChainTargeting,			// 45
	&Spell::SpellTargetSimpleTargetAdd,			// 46
	&Spell::SpellTargetSimpleTargetAdd,			// 47
	&Spell::SpellTargetSimpleTargetAdd,			// 48
	&Spell::SpellTargetSimpleTargetAdd,			// 49
	&Spell::SpellTargetSimpleTargetAdd,			// 50
	&Spell::SpellTargetNULL,					// 51
	&Spell::SpellTargetSimpleTargetAdd,			// 52
	&Spell::SpellTargetTargetAreaSelectedUnit,	// 53
	&Spell::SpellTargetInFrontOfCaster2,		// 54
	&Spell::SpellTargetNULL,					// 55 Not handled (Not realy handled by the current spell system)
	&Spell::SpellTarget56,						// 56
	&Spell::SpellTargetTargetPartyMember,		// 57
	&Spell::SpellTargetNULL,					// 58
	&Spell::SpellTargetNULL,					// 59
	&Spell::SpellTargetNULL,					// 60 // scripted target fill..
	&Spell::SpellTargetSameGroupSameClass,		// 61
	&Spell::SpellTargetNULL,					// 62 // targets the priest champion, big range..
	&Spell::SpellTargetScriptedEffects,			// 63 // summon [] creature
	&Spell::SpellTargetSimpleTargetAdd,			// 64 // summon [] creature
	&Spell::SpellTargetSimpleTargetAdd,			// 65 // summon [] creature
	&Spell::SpellTargetSimpleTargetAdd,			// 66 // summon [] creature
	&Spell::SpellTargetSimpleTargetAdd,			// 67 // summon [] creature
	&Spell::SpellTargetNULL,					// 68 Not handled (No spells)
	&Spell::SpellTargetTotem,					// 69 // Spitfire totem
	&Spell::SpellTargetNULL,					// 70 Not handled (No spells)
	&Spell::SpellTargetNULL,					// 71 Not handled (No spells)
	&Spell::SpellTargetSimpleTargetAdd,			// 72 // summon [] creature + trow items
	&Spell::SpellTargetSummon,					// 73
	&Spell::SpellTargetNULL,					// 74
	&Spell::SpellTargetNULL,					// 75
	&Spell::SpellTargetAllTargetsInArea,		// 76
	&Spell::SpellTargetSingleTargetEnemy,		// 77
	&Spell::SpellTargetNULL,					// 78
	&Spell::SpellTargetNULL,					// 79
	&Spell::SpellTargetNULL,					// 80
	&Spell::SpellTargetNULL,					// 81
	&Spell::SpellTargetNULL,					// 82
	&Spell::SpellTargetNULL,					// 83
	&Spell::SpellTargetNULL,					// 84
	&Spell::SpellTargetNULL,					// 85
	&Spell::SpellTargetNULL,					// 86
	&Spell::SpellTargetAreaOfEffect87,			// 87
	&Spell::SpellTargetNULL,					// 88
	&Spell::SpellTargetAllTargetsInArea,		// 89
	&Spell::SpellTargetNULL,					// 90
	&Spell::SpellTargetNULL,					// 91
	&Spell::SpellTargetNULL,					// 92
	&Spell::SpellTargetNULL,					// 93
	&Spell::SpellTargetVehicle,					// 94
	&Spell::SpellTargetNULL,					// 95
	&Spell::SpellTargetNULL,					// 96
	&Spell::SpellTargetNULL,					// 97
	&Spell::SpellTargetNULL,					// 98
	&Spell::SpellTargetNULL,					// 99
	&Spell::SpellTargetNULL,					// 100
	&Spell::SpellTargetNULL,					// 101
	&Spell::SpellTargetNULL,					// 102
	&Spell::SpellTargetNULL,					// 103
	&Spell::SpellTargetInFrontOfCaster,			// 104
	&Spell::SpellTargetNULL,					// 105 
	&Spell::SpellTargetNULL,					// 106 
	&Spell::SpellTargetNULL,					// 107 
	&Spell::SpellTargetNULL,					// 108 
	&Spell::SpellTargetNULL,					// 109 
	&Spell::SpellTargetNULL,					// 110 
	// all 110 > n spelltargettype's are from test spells
};

/* LEFTOVER RESEARCH, this contains note's comments from Captnoord
// these are left here because of the importance's of the info.
// comments and additional information related to this send to Captnoord

// Type 4:
// 4 is related to Diseases fun to give it a try..
// dono related to "Wandering Plague", "Spirit Steal", "Contagion of Rot", "Retching Plague" and "Copy of Wandering Plague"

// Type 7:
// Point Blank Area of Effect
// think its wrong, related to 2 spells, "Firegut Fear Storm" and "Mind Probe"
// FillAllTargetsInArea(tmpMap,m_targets.m_destX,m_targets.m_destY,m_targets.m_destZ,GetDBCCastTime(i));

//fear storm is nice
//Score 5.7	 Vote: [-] [+] by plle, 1.5 years ago
//when you set that ogre head on the top of the rock and all orges see it they /yell: FLEE (and) RUN!!
//and then all ogres get fear storm =D

//this quest
//Score 6.9	 Vote: [-] [+] by ewendim, 1.1 years ago
//happens while doing this quest http://www.thottbot.com/?qu=3825

// Type 11
// this is related to spellID: 4, as I think is a gm spell

// 11 select id,name, EffectImplicitTargetA1 from spell where EffectImplicitTargetA1 = 11;
// +----+----------------------+------------------------+
// | id | name				 | EffectImplicitTargetA1 |
// +----+----------------------+------------------------+
// |  4 | Word of Recall Other |					 11 |
// +----+----------------------+------------------------+

// type 17:
// spells like 17278:Cannon Fire and 21117:Summon Son of Flame A
// A single target at a xyz location or the target is a possition xyz

// select id,name, EffectImplicitTargetA1 from spell where EffectImplicitTargetB1 = 9;
// +-------+----------------------------+------------------------+
// | id	| name					   | EffectImplicitTargetA1 |
// +-------+----------------------------+------------------------+
// |	 1 | Word of Recall (OLD)	   |					  1 |
// |	 3 | Word of Mass Recall (OLD)  |					 20 |
// |   556 | Astral Recall			  |					  1 |
// |  8690 | Hearthstone				|					  1 |
// | 39937 | There's No Place Like Home |					  1 |
// +-------+----------------------------+------------------------+

// type 10: is not used
// type 12: is not used
// type 13: is not used
// type 14: is not used

// type 19: is target zone I think (test spells)

// type 48: is summon wild unit
// type 49: is summon friend unit
// type 50: something related to the pref 2
// type 51: is targeting objects / egg's / possible to use those while flying


// type 55 related to blink and Netherstep... I think this one sets the xyz where you should end...
// type 56 is related to aura holder... Player 1 give's me a aura and that aura has as target me. I wear then the aura / spell and it targeting me

// type 58 proc triggeret target...
// Apply Aura: Proc Trigger Spell
// Retching Plague
// 10% chance.

// type 59 related to 2 visual spells
// type 60 1 target related. rest is unknown or not clear

// type 62 targets the best player of [class]
// type 63 targets chess player... something like that
// type 64 something related to wharp storm... and the wharpstorm creature..
// type 65 target enemy's weapon... Item target..... "A" target type, "B" target type is target enemy unit...
// type 66 related to summon some unit...
// type 67 related to summon some unit...
// type 68 is not used
// type 69 is totem stuff level 70 totem stuff
// type 70 is not used
// type 71 is not used
// type 72 target enemy unit... (I think it does not matter if its a friendly unit)
// type 73 is serverside scripted.... Mostly summons
// type 74 Target Random Enemy
// type 75 Target location in front of the caster
// type 76 target a area... of target...
// type 77 target single enemy
// type 78 units in front of caster ( test spell )
// type 79 is not used
// type 80 related to summon some unit
// type 81 > N are not handled because they are test spells

*/

/// Fill the target map with the targets
/// the targets are specified with numbers and handled accordingly
void Spell::FillTargetMap(uint32 i)
{
	uint32 cur;

	uint32 TypeA = m_spellInfo->EffectImplicitTargetA[i];
	uint32 TypeB = m_spellInfo->EffectImplicitTargetB[i];

	// if all secondary targets are 0 then use only primary targets
	if(!TypeB)
	{
		if(TypeA < TOTAL_SPELL_TARGET)
			(this->*SpellTargetHandler[TypeA])(i, 0);		//0=A

		return;
	}

	// if all primary targets are 0 then use only secondary targets
	if(!TypeA)
	{
		if(TypeB < TOTAL_SPELL_TARGET)
			(this->*SpellTargetHandler[TypeB])(i, 1);		//1=B

		return;
	}

	// j = 0
	cur = m_spellInfo->EffectImplicitTargetA[i];
	if (cur < TOTAL_SPELL_TARGET)
	{
		(this->*SpellTargetHandler[cur])(i,0);	//0=A
	}

	// j = 1
	cur = m_spellInfo->EffectImplicitTargetB[i];
	if (cur < TOTAL_SPELL_TARGET)
	{
		(this->*SpellTargetHandler[cur])(i,1);	//1=B
	}
}

void Spell::SpellTargetNULL(uint32 i, uint32 j)
{
	OUT_DEBUG("[SPELL][TARGET] Unhandled target typeA: %u typeB: %u", m_spellInfo->EffectImplicitTargetA[j], m_spellInfo->EffectImplicitTargetB[j]);
}

/// Spell Target Handling for type 0: Default targeting
void Spell::SpellTargetDefault(uint32 i, uint32 j)
{
	if(j==0 || (m_caster->IsPet() && j==1))
	{
		if(m_targets.m_unitTarget)
			_AddTargetForced(m_targets.m_unitTarget, i);
		else if(m_targets.m_itemTarget)
			_AddTargetForced(m_targets.m_itemTarget, i);
		else if( m_spellInfo->Effect[i] == SPELL_EFFECT_ADD_FARSIGHT ||
				 m_spellInfo->Effect[i] == SPELL_EFFECT_SUMMON_DEMON ||
				 m_spellInfo->Effect[i] == SPELL_EFFECT_SUMMON_WILD )
			_AddTargetForced(m_caster->GetGUID(), i);
	}
}

/// Spell Target Handling for type 1: Self Target + in moon skin form party member in radius
void Spell::SpellTargetSelf(uint32 i, uint32 j)
{
	_AddTargetForced(m_caster->GetGUID(), i);
}
void Spell::SpellTargetInvisibleAOE(uint32 i, uint32 j)
{
	FillSpecifiedTargetsInArea(i,m_targets.m_destX,m_targets.m_destY,m_targets.m_destZ,GetDBCCastTime(i),1); //TARGET_SPEC_INVISIBLE);
}

/// Spell Target Handling for type 4: Target is holder of the aura
void Spell::SpellTargetFriendly(uint32 i, uint32 j)
{
	// O fuck we are contagious...
	// this off course is not tested yet.
	if (p_caster)
		_AddTargetForced(p_caster->GetGUID(), i);
}

/// Spell Target Handling for type 5: Target: Pet
void Spell::SpellTargetPet(uint32 i, uint32 j)
{
	if(p_caster)
	{
		if( p_caster->GetSummon() != NULL )
			_AddTargetForced( p_caster->GetSummon()->GetGUID(), i );
	}
}

// Spell Target Handling for type 6 and 77: Single Target Enemy (grep thinks 77 fits in 6)
void Spell::SpellTargetSingleTargetEnemy(uint32 i, uint32 j)
{
	if(!m_caster->IsInWorld())
		return;

	Unit* pTarget = m_caster->GetMapMgr()->GetUnit(m_targets.m_unitTarget);
	if(!pTarget)
		return;

	if(m_spellInfo->TargetCreatureType && pTarget->GetTypeId()==TYPEID_UNIT)
	{
		Creature* cr = TO_CREATURE( pTarget );

		if( cr == NULL )
			return;

		if( cr->GetCreatureInfo() )
			if(!(1<<(cr->GetCreatureInfo()->Type-1) & m_spellInfo->TargetCreatureType))
				return;
	}

	if(p_caster && pTarget != p_caster)
	{
		// this is mostly used for things like duels
		if(pTarget->IsPlayer() && !isAttackable(p_caster, pTarget, false))
		{
			cancastresult = SPELL_FAILED_BAD_TARGETS;
			return;
		}
	}

	// magnet!!!!!
	if( pTarget->IsPlayer() && TO_PLAYER(pTarget)->m_magnetAura != NULL && m_magnetTarget == NULL )
	{
		if(!m_spellInfo->is_melee_spell && GetType() == SPELL_DMG_TYPE_MAGIC )
		{
			// redirect it to the magnet
			m_magnetTarget = TO_PLAYER(pTarget)->m_magnetAura->GetUnitCaster();

			// clear the magnet aura
			TO_PLAYER(pTarget)->m_magnetAura->Remove();
		}
	}

	if( m_magnetTarget != NULL )
	{
		// if the target exists, shoot it at him.
		if( m_magnetTarget != NULL && m_magnetTarget->IsInWorld() && !m_magnetTarget->isDead() )
			pTarget = m_magnetTarget;
	}

	_AddTarget(pTarget, i);

	if(m_spellInfo->EffectChainTarget[i])
	{
		uint32 jumps=m_spellInfo->EffectChainTarget[i]-1;
		float range=GetMaxRange(dbcSpellRange.LookupEntry(m_spellInfo->rangeIndex));//this is probably wrong
		range*=range;
		unordered_set<Object*>::iterator itr;
		for( itr = m_caster->GetInRangeSetBegin(); itr != m_caster->GetInRangeSetEnd(); ++itr )
		{
			if((*itr)->GetGUID()==m_targets.m_unitTarget)
				continue;
			if( !((*itr)->IsUnit()) || !TO_UNIT(*itr)->isAlive())
				continue;

			if(IsInrange(m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),(*itr),range))
			{
				if(isAttackable(u_caster,TO_UNIT(*itr)))
				{
					_AddTarget(TO_UNIT(*itr), i);
					if(!--jumps)
						return;
				}
			}
		}
	}
}

// Spell Target Handling for type 8:  related to Chess Move (DND), Firecrackers, Spotlight, aedm, Spice Mortar
// Seems to be some kind of custom area of effect... Scripted... or something like that
void Spell::SpellTargetCustomAreaOfEffect(uint32 i, uint32 j)
{
	// This should be good enough for now
	FillAllTargetsInArea(i,m_targets.m_destX,m_targets.m_destY,m_targets.m_destZ,GetDBCCastTime(i));
}

/// Spell Target Handling for type 15 / 16: All Enemies in Area of Effect (instant)
void Spell::SpellTargetAreaOfEffect(uint32 i, uint32 j)
{
	FillAllTargetsInArea(i,m_targets.m_destX,m_targets.m_destY,m_targets.m_destZ,GetDBCCastTime(i));
}

/// Spell Target Handling for type 18: Land under caster
void Spell::SpellTargetLandUnderCaster(uint32 i, uint32 j) /// I don't think this is the correct name for this one
{
	if(	m_spellInfo->Effect[i] != SPELL_EFFECT_SUMMON_DEMON &&
		m_spellInfo->Effect[i] != SPELL_EFFECT_SUMMON_OBJECT_WILD &&
		m_spellInfo->Effect[i] != SPELL_EFFECT_SUMMON_OBJECT_SLOT1 &&
		m_spellInfo->Effect[i] != SPELL_EFFECT_SUMMON_OBJECT_SLOT2 &&
		m_spellInfo->Effect[i] != SPELL_EFFECT_SUMMON_OBJECT_SLOT3 &&
		m_spellInfo->Effect[i] != SPELL_EFFECT_SUMMON_OBJECT_SLOT4 )
		FillAllTargetsInArea(i, m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), GetDBCCastTime(i));
	else
		_AddTargetForced(m_caster->GetGUID(), i);
}

/// Spell Target Handling for type 18: All Party Members around the Caster in given range NOT RAID
void Spell::SpellTargetAllPartyMembersRangeNR(uint32 i, uint32 j)
{
	Player* p = p_caster;

	if( p == NULL )
	{
		if( TO_CREATURE( u_caster)->IsTotem() )
			p = TO_PLAYER( TO_CREATURE(u_caster)->GetSummonOwner());
		else if( u_caster->IsPet() && TO_PET( u_caster )->GetPetOwner() )
			p = TO_PET( u_caster )->GetPetOwner();
	}

	if( p == NULL )
		return;

	float r = GetDBCCastTime(i);

	r *= r;
	if( IsInrange( m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), p, r ) )
		_AddTargetForced(p->GetGUID(), i);

	SubGroup* subgroup = p->GetGroup() ? p->GetGroup()->GetSubGroup( p->GetSubGroup() ) : 0;

	if( subgroup != NULL )
	{
		p->GetGroup()->Lock();
		for(GroupMembersSet::iterator itr = subgroup->GetGroupMembersBegin(); itr != subgroup->GetGroupMembersEnd(); itr++)
		{
			if(!(*itr)->m_loggedInPlayer || m_caster == (*itr)->m_loggedInPlayer)
				continue;
			if(IsInrange(m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),(*itr)->m_loggedInPlayer,r))
				_AddTargetForced( (*itr)->m_loggedInPlayer->GetGUID(), i );
		}
		p->GetGroup()->Unlock();
	}
}

/// Spell Target Handling for type 21: Single Target Friend
void Spell::SpellTargetSingleTargetFriend(uint32 i, uint32 j)
{
	Unit* Target;
	if(m_targets.m_unitTarget == m_caster->GetGUID())
		Target = u_caster;
	else
		Target = m_caster->GetMapMgr() ? m_caster->GetMapMgr()->GetUnit(m_targets.m_unitTarget) : NULL;
	if(!Target)
		return;

	float r= GetMaxRange(dbcSpellRange.LookupEntry(m_spellInfo->rangeIndex));
	if(IsInrange (m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),Target, r*r))
		_AddTargetForced(Target->GetGUID(), i);
}

/// Spell Target Handling for type 22: Enemy Targets around the Caster//changed party members around you
/// place around the target / near the target //targeted Area effect
void Spell::SpellTargetAoE(uint32 i, uint32 j) // something special
// grep: this is *totally* broken. AoE only attacking friendly party members and self
// is NOT correct. // not correct at all:P
{
	FillAllTargetsInArea(i,m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),GetDBCCastTime(i));
}

/// Spell Target Handling for type 23: Gameobject Target
void Spell::SpellTargetSingleGameobjectTarget(uint32 i, uint32 j)
{
	_AddTargetForced(m_targets.m_unitTarget, i);
}

/// Spell Target Handling for type 24: Targets in Front of the Caster
void Spell::SpellTargetInFrontOfCaster(uint32 i, uint32 j)
{
	unordered_set<Object*>::iterator itr,itr2;

	if( m_spellInfo->cone_width == 0.0f )
	{
		for( itr = m_caster->GetInRangeSetBegin(); itr != m_caster->GetInRangeSetEnd();)
		{
			itr2 = itr;
			itr++;
			if(!((*itr2)->IsUnit()) || !TO_UNIT(*itr2)->isAlive())
				continue;
			//is Creature in range
			if(m_caster->isInRange((*itr2),GetDBCCastTime(i)))
			{
				if(m_caster->isInFront(*itr2))
				{
					if(isAttackable(u_caster, (*itr2)))
						_AddTarget(TO_UNIT(*itr2), i);
				}
			}
		}
	}
	else
	{
		for( itr = m_caster->GetInRangeSetBegin(); itr != m_caster->GetInRangeSetEnd();)
		{
			itr2 = itr;
			itr++;
			if(!((*itr2)->IsUnit()) || !TO_UNIT(*itr2)->isAlive())
				continue;
			//is Creature in range
			if(m_caster->isInArc(*itr2, m_spellInfo->cone_width))
			{
				if(m_caster->isInFront((*itr2)))
				{
					if(isAttackable(u_caster, (*itr2)))
						_AddTarget(TO_UNIT(*itr2), i);
				}
			}
		}
	}
}

/// Spell Target Handling for type 25: Single Target Friend	 // Used o.a. in Duel
void Spell::SpellTargetSingleFriend(uint32 i, uint32 j)
{
	_AddTargetForced(m_targets.m_unitTarget, i);
}

/// Spell Target Handling for type 26: unit target/Item Target
/// game object and item related... research pickpocket stuff
void Spell::SpellTargetGameobject_itemTarget(uint32 i, uint32 j)
{
	if( m_targets.m_unitTarget )
		_AddTargetForced(m_targets.m_unitTarget, i);

	if( m_targets.m_itemTarget )
		_AddTargetForced(m_targets.m_itemTarget, i);
}

/// Spell Target Handling for type 27: target is owner of pet
void Spell::SpellTargetPetOwner(uint32 i, uint32 j)
{
	if( u_caster->IsPet() && TO_PET(u_caster)->GetPetOwner() )
		_AddTargetForced( TO_PET(u_caster)->GetPetOwner()->GetGUID(), i );
}

/// this is handled in DO
/// Spell Target Handling for type 28: All Enemies in Area of Effect(Blizzard/Rain of Fire/volley) channeled
void Spell::SpellTargetEnemysAreaOfEffect(uint32 i, uint32 j)
{
	FillAllTargetsInArea(i,m_targets.m_destX,m_targets.m_destY,m_targets.m_destZ,GetDBCCastTime(i));
}

// all object around the the caster / object
/*
mysql> select id,name from spell where EffectImplicitTargetb1 = 29;
+-------+-----------------------------------------------+
| 23467 | Tower Buff									|
| 32087 | Putrid Cloud								  |
| 34378 | Thrall Calls Thunder						  |
| 35487 | Seed of Revitalization Lightning Cloud Visual |
| 36037 | Rina's Bough Lightning Cloud Visual		   |
+-------+-----------------------------------------------+
*/
/// Spell Target Handling for type 29: all object around the the caster / object (so it seems)
void Spell::SpellTargetTypeTAOE(uint32 i, uint32 j)
{
	Unit* Target = m_caster->GetMapMgr()->GetUnit(m_targets.m_unitTarget);
	if( Target == NULL )
		return;

	// tranquility
	if( u_caster != NULL && m_spellInfo->NameHash == SPELL_HASH_TRANQUILITY )
		_AddTargetForced(u_caster->GetGUID(), i);
	else
	{
		FillAllTargetsInArea( (LocationVector&)Target->GetPosition(), i );
	}
}

void Spell::SpellTargetPositionOfTarget(uint32 i, uint32 j)
{
	// Something with AOE. Who knows?
}

/// Spell Target Handling for type 30: PBAE Party Based Area Effect
void Spell::SpellTargetAllyBasedAreaEffect(uint32 i, uint32 j)
{
	/* Description
	We take the selected party member(also known as target), then we get a list of all the party members in the area

	// Used in
	26043 -> Battle Shout
	*/
	FillAllFriendlyInArea(i,m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),GetDBCCastTime(i));
}

/// Spell Target Handling for type 31: related to scripted effects
void Spell::SpellTargetScriptedEffects(uint32 i, uint32 j)
{
	if( m_spellInfo->NameHash == SPELL_HASH_WILD_GROWTH || m_spellInfo->NameHash == SPELL_HASH_CIRCLE_OF_HEALING )
	{
		if( p_caster == NULL || !p_caster->IsInWorld() )
			return;

		if( p_caster->GetGroup() )
		{
			uint32 TargetCount = 0;
			p_caster->GetGroup()->Lock();
			for(uint32 x = 0; x < p_caster->GetGroup()->GetSubGroupCount(); ++x)
			{
				if( TargetCount == 5 )
					break;
				for(GroupMembersSet::iterator itr = p_caster->GetGroup()->GetSubGroup( x )->GetGroupMembersBegin(); itr != p_caster->GetGroup()->GetSubGroup( x )->GetGroupMembersEnd(); itr++)
				{
					if((*itr)->m_loggedInPlayer && TargetCount != 5)
					{
						Player* p_target = (*itr)->m_loggedInPlayer;
						if( p_caster->GetDistance2dSq( p_target ) <= 225 ) // both spells have 15yd range, change in future if needed
						{
							_AddTargetForced( (*itr)->m_loggedInPlayer->GetGUID(), i );
							TargetCount += 1;
						}
					}
				}
			}
			p_caster->GetGroup()->Unlock();
		}
	}
	else
		FillAllTargetsInArea(i,m_targets.m_destX,m_targets.m_destY,m_targets.m_destZ,GetDBCCastTime(i));
}

/// Spell Target Handling for type 32 / 73: related to summoned pet or creature
void Spell::SpellTargetSummon(uint32 i, uint32 j)
{// Minion Target
	if(m_caster->GetUInt64Value(UNIT_FIELD_SUMMON) == 0)
		_AddTargetForced(m_caster->GetGUID(), i);
	else
		_AddTargetForced(m_caster->GetUInt64Value(UNIT_FIELD_SUMMON), i);
}

/// Spell Target Handling for type 33: Party members of totem, inside given range
void Spell::SpellTargetNearbyPartyMembers(uint32 i, uint32 j)
{
	// this implementation is wrong.... this one is for totems
	if( u_caster != NULL )
	{
		if( u_caster->GetTypeId()==TYPEID_UNIT)
		{
			if( TO_CREATURE( u_caster )->IsTotem() )
			{
				float r = GetDBCCastTime(i);
				r *= r;

				Player* p = TO_PLAYER( TO_CREATURE(u_caster)->GetSummonOwner());

				if( p == NULL)
					return;

				if(IsInrange(m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),p,r))
					_AddTargetForced(p->GetGUID(), i);

				SubGroup * pGroup = p->GetGroup() ?
					p->GetGroup()->GetSubGroup(p->GetSubGroup()) : 0;

				if(pGroup)
				{
					p->GetGroup()->Lock();
					for(GroupMembersSet::iterator itr = pGroup->GetGroupMembersBegin();
						itr != pGroup->GetGroupMembersEnd(); itr++)
					{
						if(!(*itr)->m_loggedInPlayer || p == (*itr)->m_loggedInPlayer)
							continue;
						if(IsInrange(m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),(*itr)->m_loggedInPlayer,r))
							_AddTargetForced((*itr)->m_loggedInPlayer->GetGUID(), i);
					}
					p->GetGroup()->Unlock();
				}
			}
		}
	}
}

// Spell Target Handling for type 35: Single Target Party Member (if not in party then the target can not be himself)
// this one requeres more research
void Spell::SpellTargetSingleTargetPartyMember(uint32 i, uint32 j)
{
	if(!m_caster->IsInWorld())
		return;

	Unit* Target = m_caster->GetMapMgr()->GetPlayer((uint32)m_targets.m_unitTarget);
	if(!Target)
		return;
	float r=GetMaxRange(dbcSpellRange.LookupEntry(m_spellInfo->rangeIndex));
	if(IsInrange(m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),Target,r*r))
		_AddTargetForced(m_targets.m_unitTarget, i);
}

/// Spell Target Handling for type 36: these targets are scripted :s or something.. there seems to be a system...
void Spell::SpellTargetScriptedEffects2(uint32 i, uint32 j)
{

}

// Spell Target Handling for type 37: all Members of the targets party
void Spell::SpellTargetPartyMember(uint32 i, uint32 j)
{
	if(!m_caster->IsInWorld())
		return;

	// if no group target self
	Player* Target = m_caster->GetMapMgr()->GetPlayer((uint32)m_targets.m_unitTarget);
	if(!Target)
		return;

	SubGroup * subgroup = Target->GetGroup() ?
		Target->GetGroup()->GetSubGroup(Target->GetSubGroup()) : 0;

	if(subgroup)
	{
		Target->GetGroup()->Lock();
		for(GroupMembersSet::iterator itr = subgroup->GetGroupMembersBegin(); itr != subgroup->GetGroupMembersEnd(); itr++)
		{
			if((*itr)->m_loggedInPlayer)
				_AddTargetForced( (*itr)->m_loggedInPlayer->GetGUID(), i );
		}
		Target->GetGroup()->Unlock();
	}
	else
		_AddTargetForced(Target->GetGUID(), i);
}

/// Spell Target Handling for type 38: Dummy Target (Server-side script effect)
void Spell::SpellTargetDummyTarget(uint32 i, uint32 j)
{
	//TargetsList *tmpMap=&m_targetUnits[i];
	if( m_spellInfo->Id == 51699 )
	{
		if( p_caster )
		{
			Aura* aur = p_caster->FindAura( 52916 );
			if( aur && aur->GetUnitCaster() )
			{
				_AddTargetForced(aur->GetUnitCaster()->GetGUID(), i);
				return;
			}
		}
	}
	else if( m_spellInfo->Id == 12938 )
	{
		//FIXME:this ll be immortal targets
		FillAllTargetsInArea(i,m_targets.m_destX,m_targets.m_destY,m_targets.m_destZ,GetDBCCastTime(i));
	}
	_AddTargetForced(m_caster->GetGUID(), i);
}

/// Spell Target Handling for type 39: Fishing
void Spell::SpellTargetFishing(uint32 i, uint32 j)
{
	_AddTargetForced(m_caster->GetGUID(), i);
}

/// Spell Target Handling for type 40: Activate Object target(probably based on focus)
/// movement proc, like traps.
void Spell::SpellTargetType40(uint32 i, uint32 j)
{

}

/// Spell Target Handling for type 41 / 42 / 43 / 44: Totems
void Spell::SpellTargetTotem(uint32 i, uint32 j)
{
	_AddTargetForced(m_caster->GetGUID(), i);
}

/// Spell Target Handling for type 45: Chain,!!only for healing!! for chain lightning =6
void Spell::SpellTargetChainTargeting(uint32 i, uint32 j)
{
	if( !m_caster->IsInWorld() )
		return;

	//if selected target is party member, then jumps on party
	Unit* firstTarget;

	bool PartyOnly = false;
	float range = GetMaxRange(dbcSpellRange.LookupEntry(m_spellInfo->rangeIndex));//this is probably wrong,
	//this is cast distance, not searching distance
	range *= range;

	firstTarget = m_caster->GetMapMgr()->GetPlayer((uint32)m_targets.m_unitTarget);
	if( firstTarget && p_caster != NULL )
	{
		if( p_caster->InGroup() )
			if( p_caster->GetSubGroup() == TO_PLAYER( firstTarget )->GetSubGroup() )
				PartyOnly=true;
	}
	else
	{
		firstTarget = m_caster->GetMapMgr()->GetUnit(m_targets.m_unitTarget);
		if(!firstTarget)
			return;
	}

	uint32 jumps=m_spellInfo->EffectChainTarget[i];
	if(m_spellInfo->SpellGroupType && u_caster)
	{
		SM_FIValue(u_caster->SM[SMT_ADDITIONAL_TARGET][0],(int32*)&jumps,m_spellInfo->SpellGroupType);
	}

	_AddTargetForced(firstTarget->GetGUID(), i);
	if(!jumps)
		return;
	jumps--;
	if(PartyOnly)
	{
		GroupMembersSet::iterator itr;
		SubGroup * pGroup = p_caster->GetGroup() ?
			p_caster->GetGroup()->GetSubGroup(p_caster->GetSubGroup()) : 0;

		if(pGroup)
		{
			p_caster->GetGroup()->Lock();
			for(itr = pGroup->GetGroupMembersBegin();
				itr != pGroup->GetGroupMembersEnd(); itr++)
			{
				if(!(*itr)->m_loggedInPlayer || (*itr)->m_loggedInPlayer == u_caster || (*itr)->m_loggedInPlayer->GetUInt32Value(UNIT_FIELD_HEALTH) == (*itr)->m_loggedInPlayer->GetUInt32Value(UNIT_FIELD_MAXHEALTH))
					continue;
				if(IsInrange(u_caster->GetPositionX(),u_caster->GetPositionY(),u_caster->GetPositionZ(),(*itr)->m_loggedInPlayer, range))
				{
					_AddTargetForced((*itr)->m_loggedInPlayer->GetGUID(), i);
					if(!--jumps)
					{
						p_caster->GetGroup()->Unlock();
						return;
					}
				}
			}
			p_caster->GetGroup()->Unlock();
		}
	}//find nearby friendly target
	else
	{
		unordered_set<Object*>::iterator itr;
		for( itr = firstTarget->GetInRangeSetBegin(); itr != firstTarget->GetInRangeSetEnd(); ++itr )
		{
			if( !(*itr)->IsUnit() || !TO_UNIT(*itr)->isAlive())
				continue;

			if(IsInrange(firstTarget->GetPositionX(),firstTarget->GetPositionY(),firstTarget->GetPositionZ(),*itr, range))
			{
				if(!isAttackable(u_caster,TO_UNIT(*itr)) && (*itr)->GetUInt32Value(UNIT_FIELD_HEALTH) != (*itr)->GetUInt32Value(UNIT_FIELD_MAXHEALTH))
				{
					_AddTargetForced((*itr)->GetGUID(), i);
					if(!--jumps)
						return;
				}
			}
		}
	}
}

/// Spell target handling for commonly used simple target add's
/// mostly used in scripted and kinda unknown target

/// This handler is used in
/// Spell Target Handling for type 46: Unknown Summon Atal'ai Skeleton
/// Spell Target Handling for type 47: Portal (Not sure, fix me.)
/// Spell Target Handling for type 48: fix me
/// Spell Target Handling for type 49: fix me
/// Spell Target Handling for type 50: fix me
/// Spell Target Handling for type 52: Lightwells, etc (Need more research)

void Spell::SpellTargetSimpleTargetAdd(uint32 i, uint32 j)
{
	_AddTargetForced(m_caster->GetGUID(), i);
}

/// Spell Target Handling for type 53: Target Area by Players CurrentSelection()
void Spell::SpellTargetTargetAreaSelectedUnit(uint32 i, uint32 j)
{
	Unit* Target = NULL;
	if(m_caster->IsInWorld())
	{
		if(p_caster)
			Target = m_caster->GetMapMgr()->GetUnit(p_caster->GetSelection());
		else
			Target = m_caster->GetMapMgr()->GetUnit(m_targets.m_unitTarget);
	}

	if(!Target)
		return;

	FillAllTargetsInArea((LocationVector&)Target->GetPosition(), i);
}

/// Spell Target Handling for type 54: Targets in Front of the Caster
void Spell::SpellTargetInFrontOfCaster2(uint32 i, uint32 j)
{
	unordered_set<Object*>::iterator itr;

	for( itr = m_caster->GetInRangeSetBegin(); itr != m_caster->GetInRangeSetEnd(); ++itr )
	{
		if(!((*itr)->IsUnit()) || !TO_UNIT(*itr)->isAlive())
			continue;
		//is Creature in range
		if(m_caster->isInRange(TO_UNIT(*itr),GetDBCCastTime(i)))
		{
			if(m_caster->isInFront(TO_UNIT(*itr)))
			{
				if(isAttackable(u_caster, TO_UNIT(*itr)))
					_AddTarget(TO_UNIT(*itr), i);
			}
		}
	}
}

// Spell Target Handling for type 56: your party or raid within radius
void Spell::SpellTarget56(uint32 i, uint32 j)
{
	SpellTargetAllPartyMembersRangeNR(i, j);
}

// Spell Target Handling for type 57: Targeted Party Member
void Spell::SpellTargetTargetPartyMember(uint32 i, uint32 j)
{
	if(!m_caster->IsInWorld())
		return;

	Unit* Target = m_caster->GetMapMgr()->GetPlayer ((uint32)m_targets.m_unitTarget);
	if(!Target)
		Target = u_caster;
	if(!Target)
		return;

	float r=GetMaxRange(dbcSpellRange.LookupEntry(m_spellInfo->rangeIndex));
	if(IsInrange(m_caster->GetPositionX(),m_caster->GetPositionY(),m_caster->GetPositionZ(),Target,r*r))
		_AddTargetForced(Target->GetGUID(), i);
}

// Spell Target Handling for type 61: targets with the same group/raid and the same class
void Spell::SpellTargetSameGroupSameClass(uint32 i, uint32 j)
{
	if(!m_caster->IsInWorld())
		return;

	if( m_caster->IsPlayer() )
		if( !TO_PLAYER(m_caster)->GetGroup() )
			_AddTargetForced(m_caster->GetGUID(), i);

	Player* Target = m_caster->GetMapMgr()->GetPlayer((uint32)m_targets.m_unitTarget);
	if(!Target)
		return;

	if( m_caster->IsPlayer() && Target->IsPlayer() && Target->GetGroup() && (Target == m_caster || Target->GetGroup()->HasMember(TO_PLAYER(m_caster))) )
	{
		Target->GetGroup()->Lock();

		for( uint32 x = 0; x < Target->GetGroup()->GetSubGroupCount(); ++x )
		{
			for(GroupMembersSet::iterator itr = Target->GetGroup()->GetSubGroup( x )->GetGroupMembersBegin(); itr != Target->GetGroup()->GetSubGroup( x )->GetGroupMembersEnd(); itr++)
			{
				if(!(*itr)->m_loggedInPlayer || Target->getClass() != (*itr)->m_loggedInPlayer->getClass())
					continue;

				_AddTargetForced((*itr)->m_loggedInPlayer->GetGUID(), i);
			}
		}
		Target->GetGroup()->Unlock();
	}
}


// returns Guid of lowest percentage health friendly party or raid target within sqrt('dist') yards
uint64 Spell::FindLowestHealthRaidMember(Player* Target, uint32 dist)
{

	if(!Target || !Target->IsInWorld())
		return 0;

	uint64 lowestHealthTarget = Target->GetGUID();
	uint32 lowestHealthPct = Target->GetHealthPct();
	Group *group = Target->GetGroup();
	if(group)
	{
		group->Lock();
		for(uint32 j = 0; j < group->GetSubGroupCount(); ++j) {
			for(GroupMembersSet::iterator itr = group->GetSubGroup(j)->GetGroupMembersBegin(); itr != group->GetSubGroup(j)->GetGroupMembersEnd(); itr++)
			{
				if((*itr)->m_loggedInPlayer && Target->GetDistance2dSq((*itr)->m_loggedInPlayer) <= dist)
				{
					uint32 healthPct = (*itr)->m_loggedInPlayer->GetHealthPct();
					if(healthPct < lowestHealthPct)
					{
						lowestHealthPct = healthPct;
						lowestHealthTarget = (*itr)->m_loggedInPlayer->GetGUID();
					}
				}
			}
		}
		group->Unlock();
	}
	return lowestHealthTarget;
}

/// Spell Target Handling for type 87
void Spell::SpellTargetAreaOfEffect87(uint32 i, uint32 j)
{
	if( !m_caster || !m_caster->IsInWorld() )
		return;

	_AddTargetForced(m_caster->GetGUID(), i);
}

/// Spell Target Handling for type 76 All targets in area
void Spell::SpellTargetAllTargetsInArea(uint32 i, uint32 j)
{
	if( !m_caster || !m_caster->IsInWorld() )
		return;

	FillAllTargetsInArea(i, m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, GetDBCCastTime(i));
}
/// Spell Target Handling for type 94: Target: Vehicle
void Spell::SpellTargetVehicle(uint32 i, uint32 j)
{
	if(p_caster)
	{
		if( p_caster->m_CurrentVehicle != NULL )
			_AddTargetForced( p_caster->m_CurrentVehicle->GetGUID(), i );
	}
}
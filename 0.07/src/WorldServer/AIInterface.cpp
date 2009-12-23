/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */
 
#include "StdAfx.h"

#define RADIUS 25
#define UPDATETIME 10000

//Конструктор и деструктор для динамических строк в объектах
void *AIInterface::operator new(size_t size)
{
	sLog.outDebug("New AIInterface dynamic string in object.");
	return malloc(size);
}

void AIInterface::operator delete(void* p)
{
	sLog.outDebug("Delete AIInterface dynamic string in object.");
	free(p);
}

AIInterface::AIInterface()
{
	m_ChainAgroSet = NULL;
	m_waypoints = NULL;
	m_canMove = true;
	m_destinationX = m_destinationY = m_destinationZ = 0;
	m_nextPosX = m_nextPosY = m_nextPosZ = 0;
	UnitToFollow = NULLCREATURE;
	FollowDistance = 0.0f;
	m_fallowAngle = float(M_PI/2);
	m_timeToMove = 0;
	m_timeMoved = 0;
	m_moveTimer = 0;
	m_WayPointsShowing = false;
	m_WayPointsShowBackwards = false;
	m_currentWaypoint = 0;
	m_moveBackward = false;
	m_moveType = 0;
	m_moveRun = false;
	m_moveSprint = false;
	m_moveFly = false;
	m_creatureState = STOPPED;
	m_canCallForHelp = false;
	m_hasCalledForHelp = false;
	m_fleeTimer = 0;
	m_FleeDuration = 0;
	m_canFlee = false;
	m_hasFled = false;
	m_canRangedAttack = false;
	m_FleeHealth = m_CallForHelpHealth = 0.0f;
	m_AIState = STATE_IDLE;

	m_updateAssist = false;
	m_updateTargets = false;
	m_updateAssistTimer = 1;
	m_updateTargetsTimer = TARGET_UPDATE_INTERVAL;

	m_nextSpell = NULL;
	m_nextTarget = NULLUNIT;
	totemspell = NULL;
	m_Unit = NULLUNIT;
	SetPetOwner(NULLUNIT);
	m_aiCurrentAgent = AGENT_NULL;
	m_runSpeed = 0.0f;
	m_flySpeed = 0.0f;
	UnitToFear = NULLUNIT;
	firstLeaveCombat = true;
	m_outOfCombatRange = 10000;

	tauntedBy = NULLUNIT;
	isTaunted = false;
	m_AllowedToEnterCombat = true;
	m_totalMoveTime = 0;
	m_lastFollowX = m_lastFollowY = 0;
	m_FearTimer = 0;
	m_WanderTimer = 0;
	m_totemspelltime = 0;
	m_totemspelltimer = 0;
	m_formationFollowAngle = 0.0f;
	m_formationFollowDistance = 0.0f;
	m_formationLinkTarget = NULLCREATURE;
	m_formationLinkSqlId = 0;
	m_currentHighestThreat = 0;

	disable_combat = false;

	disable_melee = false;
	disable_ranged = false;
	disable_spell = false;

	disable_targeting = false;

	next_spell_time = 0;

	waiting_for_cooldown = false;
	UnitToFollow_backup = NULLUNIT;
	m_isGuard = false;
	m_is_in_instance = false;
	skip_reset_hp = false;
	m_guardCallTimer = 0;

	m_aiTargets.clear();
	GetAssistTargets().clear();
	m_spells.clear();

}

void AIInterface::Init(UnitPointer un, AIType at, MovementType mt)
{
	ASSERT(at != AITYPE_PET);

	m_AIType = at;
	m_MovementType = mt;

	SetAIState(STATE_IDLE);
	m_MovementState = MOVEMENTSTATE_STOP;

	m_Unit = un;

	m_walkSpeed = GetUnit()->m_walkSpeed*0.001f; // move distance per ms time 
	m_runSpeed = GetUnit()->m_runSpeed*0.001f;   // move/ms
	m_flySpeed = GetUnit()->m_flySpeed*0.001f;
	m_sourceX = un->GetPositionX();
	m_sourceY = un->GetPositionY();
	m_sourceZ = un->GetPositionZ();
	m_guardTimer = getMSTime();
}

AIInterface::~AIInterface()
{
	for(list<AI_Spell*>::iterator itr = m_spells.begin(); itr != m_spells.end(); ++itr)
		if((*itr)->custom_pointer)
			delete (*itr);

	if( m_ChainAgroSet && GetUnit()->IsCreature() )
	{
		m_ChainAgroSet->RemoveAggroEntity( TO_CREATURE(GetUnit()) );
	}

	m_formationLinkTarget = NULLCREATURE;
	m_Unit = NULLUNIT;
	SetPetOwner(NULLUNIT);
	soullinkedWith = NULLUNIT;
	UnitToFollow_backup = NULLUNIT;
 	
}

void AIInterface::Init(UnitPointer un, AIType at, MovementType mt, UnitPointer owner)
{
	ASSERT(at == AITYPE_PET || at == AITYPE_TOTEM);

	m_AIType = at;
	m_MovementType = mt;

	SetAIState(STATE_IDLE);
	m_MovementState = MOVEMENTSTATE_STOP;

	m_Unit = un;
	SetPetOwner(owner);

	m_walkSpeed = GetUnit()->m_walkSpeed*0.001f; // move distance per ms time 
	m_runSpeed = GetUnit()->m_runSpeed*0.001f;   // move/ms
	m_flySpeed = GetUnit()->m_flySpeed*0.001f;
	m_sourceX = un->GetPositionX();
	m_sourceY = un->GetPositionY();
	m_sourceZ = un->GetPositionZ();
}

void AIInterface::HandleEvent(uint32 event, UnitPointer pUnit, uint32 misc1)
{
	if( GetUnit() == NULL ) return;

	CreaturePointer cr = NULLCREATURE;
	if( GetUnit()->GetTypeId() == TYPEID_UNIT )
	{
		cr = TO_CREATURE( GetUnit() );
		if(cr == NULL)
			return;
	}

	if(getAIState() != STATE_EVADE)
	{
		switch(event)
		{
		case EVENT_ENTERCOMBAT:
			{
				if( pUnit == NULL || pUnit->isDead() || GetUnit()->isDead() ) return; 
					

				// send the message.
				if( cr != NULL )
				{
					if( cr->has_combat_text )
						objmgr.HandleMonsterSayEvent( cr, MONSTER_SAY_EVENT_ENTER_COMBAT );

					CALL_SCRIPT_EVENT(GetUnit(), OnCombatStart)(pUnit);

					if( cr->m_spawn && ( cr->m_spawn->channel_target_go || cr->m_spawn->channel_target_creature))
					{
						GetUnit()->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
						GetUnit()->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
					}
				}
				
				// Stop the emote
				GetUnit()->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
				m_returnX = GetUnit()->GetPositionX();
				m_returnY = GetUnit()->GetPositionY();
				m_returnZ = GetUnit()->GetPositionZ();

				m_moveRun = true; // run to the target

				// dismount if mounted
				GetUnit()->Dismount();

				if(getAIState() != STATE_ATTACKING)
					StopMovement(0);

				if( m_ChainAgroSet )
				{
					m_ChainAgroSet->EventEnterCombat( pUnit );
				}

				SetAIState(STATE_ATTACKING);
				firstLeaveCombat = true;

				if(pUnit->GetInstanceID() == GetUnit()->GetInstanceID())
					GetUnit()->SetUInt64Value(UNIT_FIELD_TARGET, pUnit->GetGUID());

				// Mark raid as combat in progress if it concerns a boss 
				if(pUnit->GetMapMgr() && pUnit->GetMapMgr()->GetMapInfo() && pUnit->GetMapMgr()->GetMapInfo()->type == INSTANCE_RAID)
				{
					if(GetUnit()->GetTypeId() == TYPEID_UNIT && GetUnit()->m_loadedFromDB )
					{
						if(cr->GetCreatureName() && cr->GetCreatureName()->Rank == ELITE_WORLDBOSS)
							 pUnit->GetMapMgr()->AddCombatInProgress(GetUnit()->GetGUID());
					}
				}
				//BLooD_LorD : Put mob into combat animation. Take out weapons and start to look serious :P
				GetUnit()->smsg_AttackStart( pUnit );
			}break;
		case EVENT_LEAVECOMBAT:
			{
				if( pUnit == NULL ) 
					return;

				if( pUnit->GetTypeId() == TYPEID_UNIT && !pUnit->IsPet() && !pUnit->isAlive() )
				if( pUnit->IsPlayer() || pUnit->IsCreature() )
					pUnit->RemoveAllNegativeAuras();

				// cancel spells that we are casting. Should remove bug where creatures cast a spell after they died
				if( pUnit->IsCreature() )
					CancelSpellCast();

				// restart emote
				if(cr != NULL)
				{
					cr->SetSheatheForAttackType(0); // sheathe yuor weapons!

					if( cr->has_combat_text )
						objmgr.HandleMonsterSayEvent( cr, MONSTER_SAY_EVENT_ON_COMBAT_STOP );

					if(cr->original_emotestate)
						GetUnit()->SetUInt32Value(UNIT_NPC_EMOTESTATE, cr->original_emotestate);
					
					if(cr->m_spawn)
					{
						if(cr->m_spawn->channel_target_go || cr->m_spawn->channel_target_creature)
						{
							if(cr->m_spawn->channel_target_go)
								sEventMgr.AddEvent( cr, &Creature::ChannelLinkUpGO, cr->m_spawn->channel_target_go, EVENT_CREATURE_CHANNEL_LINKUP, 1000, 5, 0 );

							if(cr->m_spawn->channel_target_creature)
								sEventMgr.AddEvent( cr, &Creature::ChannelLinkUpCreature, cr->m_spawn->channel_target_creature, EVENT_CREATURE_CHANNEL_LINKUP, 1000, 5, 0 );
						}
						// Remount if mounted
						if( cr->m_spawn->MountedDisplayID )
							GetUnit()->SetUInt32Value( UNIT_FIELD_MOUNTDISPLAYID, cr->m_spawn->MountedDisplayID );
					}
				}

				// reset ProcCount
				// ResetProcCounts();
				m_moveRun = true;
				m_aiTargets.clear();			
				m_fleeTimer = 0;
				m_hasFled = false;
				m_hasCalledForHelp = false;
				m_nextSpell = NULL;
				SetNextTarget(NULLUNIT);
				GetUnit()->CombatStatus.Vanished();

				if(getAIType() == AITYPE_PET)
				{
					SetAIState(STATE_FOLLOWING);
					getUnitToFollow() = GetPetOwner();
					SetFollowDistance(3.0f);
					m_lastFollowX = m_lastFollowY = 0;
					if(GetUnit()->IsPet())
					{
						TO_PET(GetUnit())->SetPetAction(PET_ACTION_FOLLOW);
						if( GetUnit()->GetEntry() == 416 && GetUnit()->isAlive() && GetUnit()->IsInWorld() )
						{
							TO_PET(GetUnit())->HandleAutoCastEvent(AUTOCAST_EVENT_LEAVE_COMBAT);
						}
					}
					HandleEvent(EVENT_FOLLOWOWNER, NULLUNIT, 0);
				}
				else
				{
					CALL_SCRIPT_EVENT(GetUnit(), OnCombatStop)(getUnitToFollow());
					SetAIState(STATE_EVADE);

					SetUnitToFollow(NULLUNIT);
					SetFollowDistance(0.0f);
					m_lastFollowX = m_lastFollowY = 0;

					if(GetUnit()->isAlive())
					{
						if(m_returnX != 0.0f && m_returnY != 0.0f && m_returnZ != 0.0f)
							MoveTo(m_returnX,m_returnY,m_returnZ,GetUnit()->GetOrientation());
						else
						{
							MoveTo(GetUnit()->GetSpawnX(),GetUnit()->GetSpawnY(),GetUnit()->GetSpawnZ(),GetUnit()->GetSpawnO());
							m_returnX=GetUnit()->GetSpawnX();
							m_returnY=GetUnit()->GetSpawnY();
							m_returnZ=GetUnit()->GetSpawnZ();
						}

						// clear tagger
						if(cr != NULL)
							cr->ClearTag();
					}
				}

				if( cr!= NULL && GetUnit()->GetMapMgr() )
					GetUnit()->GetMapMgr()->RemoveCombatInProgress(GetUnit()->GetGUID());

				// BLooD_LorD : not sure we need to send this. Did not see it in the dumps since mob died eventually but it seems logical to make this
				GetUnit()->smsg_AttackStop( pUnit );
			}break;
		case EVENT_DAMAGETAKEN:
			{
				if( pUnit == NULL ) return;

				if( cr!= NULL && cr->has_combat_text )
					objmgr.HandleMonsterSayEvent( TO_CREATURE( GetUnit() ), MONSTER_SAY_EVENT_ON_DAMAGE_TAKEN );

				CALL_SCRIPT_EVENT(GetUnit(), OnDamageTaken)(pUnit, float(misc1));
				if(!modThreatByPtr(pUnit, misc1))
				{
					if( pUnit->IsPlayer() )
					{
						if( pUnit->mThreatRTarget )
							m_aiTargets.insert(TargetMap::value_type(TO_PLAYER(pUnit->mThreatRTarget), misc1));
						else
							m_aiTargets.insert(TargetMap::value_type(pUnit, misc1));
					}
					else
						m_aiTargets.insert(TargetMap::value_type(pUnit, misc1));
				}
				GetUnit()->CombatStatus.OnDamageDealt(pUnit, 1);
			}break;
		case EVENT_FOLLOWOWNER:
			{
				SetAIState(STATE_FOLLOWING);
				if(GetUnit()->IsPet())
					TO_PET(GetUnit())->SetPetAction(PET_ACTION_FOLLOW);
				SetUnitToFollow(GetPetOwner());
				m_lastFollowX = m_lastFollowY = 0;
				SetFollowDistance(4.0f);

				m_aiTargets.clear();
				m_fleeTimer = 0;
				m_hasFled = false;
				m_hasCalledForHelp = false;
				m_nextSpell = NULL;
				SetNextTarget(NULLUNIT);
				m_moveRun = true;
			}break;

		case EVENT_FEAR:
			{
				if( pUnit == NULL ) return;

				m_FearTimer = 0;
				SetUnitToFear(pUnit);

				CALL_SCRIPT_EVENT(GetUnit(), OnFear)(pUnit, 0);
				SetAIState(STATE_FEAR);
				StopMovement(1);

				UnitToFollow_backup =  getUnitToFollow();
				UnitToFollow = NULLUNIT;
				m_lastFollowX = m_lastFollowY = 0;
				FollowDistance_backup = FollowDistance;
				SetFollowDistance(0.0f);

				m_fleeTimer = 0;
				m_hasFled = false;
				m_hasCalledForHelp = false;

				// update speed
				m_moveRun = true;
				getMoveFlags();

				SetNextSpell(NULL);
				SetNextTarget(NULLUNIT);
			}break;

		case EVENT_UNFEAR:
			{
				SetUnitToFollow(UnitToFollow_backup);
				SetFollowDistance(FollowDistance_backup);
				SetAIState(STATE_IDLE); // we need this to prevent permanent fear, wander, and other problems

				SetUnitToFear(NULLUNIT);
				StopMovement(1);
			}break;

		case EVENT_WANDER:
			{
				if( pUnit == NULL ) return;

				m_WanderTimer = 0;

				// CALL_SCRIPT_EVENT(GetUnit(), OnWander)(pUnit, 0); FIXME
				SetAIState(STATE_WANDER);
				StopMovement(1);

				m_aiTargets.clear(); // we'll get a new target after we are unwandered
				m_fleeTimer = 0;
				m_hasFled = false;
				m_hasCalledForHelp = false;

				// update speed
				m_moveRun = true;
				getMoveFlags();

				SetNextSpell(NULL);
				SetNextTarget(NULLUNIT);
			}break;

		case EVENT_UNWANDER:
			{
				SetUnitToFollow(UnitToFollow_backup);
				SetFollowDistance(FollowDistance_backup);
				SetAIState(STATE_IDLE); // we need this to prevent permanent fear, wander, and other problems

				StopMovement(1);
			}break;

		default:
			{
			}break;
		}
	}

	// Should be able to do this stuff even when evading
	switch(event)
	{
		case EVENT_UNITDIED:
		{
			if( pUnit == NULL ) 
				return;

			if( pUnit->m_CurrentVehicle )
				pUnit->m_CurrentVehicle->RemovePassenger(pUnit);

			if( cr != NULL )
			{
				if( cr->has_combat_text )
					objmgr.HandleMonsterSayEvent( cr, MONSTER_SAY_EVENT_ON_DIED );

				if(getUnitToFollow() != NULL)
					SetUnitToFollow(NULLUNIT);

				if(UnitToFollow_backup != NULL)
					UnitToFollow_backup = NULLUNIT;

				m_lastFollowX = m_lastFollowY = 0;
				SetFollowDistance(0.0f);
			}

			CALL_SCRIPT_EVENT(GetUnit(), OnDied)(pUnit);
			if ( GetUnit()->IsCreature() )
				CALL_INSTANCE_SCRIPT_EVENT( GetUnit()->GetMapMgr(), OnCreatureDeath )( TO_CREATURE( GetUnit() ), pUnit );

			SetAIState(STATE_IDLE);

			StopMovement(0);
			m_aiTargets.clear();
			SetUnitToFear(NULLUNIT);
			m_fleeTimer = 0;
			m_hasFled = false;
			m_hasCalledForHelp = false;
			m_nextSpell = NULL;

			SetNextTarget(NULLUNIT);
		
			// reset waypoint to 1
			setWaypointToMove(1);
			
			// There isn't any need to do any attacker checks here, as
			// they should all be taken care of in DealDamage

			if(cr != NULL && !GetUnit()->IsPet())
			{
				// only save creature which exist in db (don't want to save 0 values in db) 
				if( GetUnit()->m_loadedFromDB && cr->m_spawn != NULL )
				{
					MapMgrPointer GMap = GetUnit()->GetMapMgr();
					if(GMap != NULL)
					if( GMap && GMap->pInstance && GMap->GetMapInfo()->type != INSTANCE_PVP )
					{
						GMap->pInstance->m_killedNpcs.insert( cr->GetSQL_id() );
						GMap->pInstance->SaveToDB();
					}
				}
			}
		}break;
	}
}

void AIInterface::Update(uint32 p_time)
{
	float tdist;
	if(getAIType() == AITYPE_TOTEM)
	{
		assert(totemspell != 0);
		if(p_time >= m_totemspelltimer)
		{
			SpellPointer pSpell(new Spell(GetUnit(), totemspell, true, NULLAURA));

			SpellCastTargets targets(0);
			if(! GetNextTarget() ||
				( GetNextTarget() && 
					(!GetUnit()->GetMapMgr()->GetUnit( GetNextTarget()->GetGUID()) || 
					! GetNextTarget()->isAlive() ||
					( GetNextTarget()->GetTypeId() == TYPEID_UNIT && TO_CREATURE( GetNextTarget())->IsTotem()) ||
					!IsInrange(GetUnit(), GetNextTarget(),pSpell->m_spellInfo->base_range_or_radius_sqr) ||
					!isAttackable(GetUnit(),  GetNextTarget(),!(pSpell->m_spellInfo->c_is_flags & SPELL_FLAG_IS_TARGETINGSTEALTHED))
					)
				)
				)
			{
				// we set no target and see if we managed to fid a new one
				SetNextTarget(NULLUNIT);
				// something happend to our target, pick another one
				pSpell->GenerateTargets(&targets);
				if(targets.m_targetMask & TARGET_FLAG_UNIT)
					SetNextTarget(GetUnit()->GetMapMgr()->GetUnit(targets.m_unitTarget));
			}
			if(GetNextTarget())
			{
				SpellCastTargets targets(GetNextTarget()->GetGUID());
				pSpell->prepare(&targets);
				// need proper cooldown time!
				m_totemspelltimer = m_totemspelltime;
			}
			else
			{
				pSpell->Destructor();
				pSpell = NULLSPELL;
			}
		}
		else
		{
			m_totemspelltimer -= p_time;
		}
		return;
	}

	_UpdateTimer(p_time);
	_UpdateTargets();
	if(GetUnit()->isAlive() && getAIState() != STATE_IDLE 
		&& getAIState() != STATE_FOLLOWING && getAIState() != STATE_FEAR 
		&& getAIState() != STATE_WANDER && getAIState() != STATE_SCRIPTMOVE)
	{
		if(getAIType() == AITYPE_PET )
		{
			if(!GetUnit()->bInvincible && GetUnit()->IsPet()) 
			{
				PetPointer pPet = TO_PET(GetUnit());
	
				if(pPet->GetPetAction() == PET_ACTION_ATTACK || pPet->GetPetState() != PET_STATE_PASSIVE)
				{
					_UpdateCombat(p_time);
				}
			}
			// we just use any creature as a pet guardian
			else if(!GetUnit()->IsPet())
			{
				_UpdateCombat(p_time);
			}
		}
		else
		{
			_UpdateCombat(p_time);
		}
	}

	_UpdateMovement(p_time);
	if(getAIState()==STATE_EVADE)
	{
		tdist = GetUnit()->GetDistanceSq(m_returnX,m_returnY,m_returnZ);
		if(tdist <= 4.0f/*2.0*/)
		{
			SetAIState(STATE_IDLE);
			m_returnX = m_returnY = m_returnZ = 0.0f;
			m_moveRun = false;
		
			// Set health to full if they at there last location before attacking
			if(getAIType() != AITYPE_PET&&!skip_reset_hp)
				GetUnit()->SetUInt32Value(UNIT_FIELD_HEALTH,GetUnit()->GetUInt32Value(UNIT_FIELD_MAXHEALTH));
		}
		else
		{
			if( m_creatureState == STOPPED )
			{
				// return to the home
				if( m_returnX == 0.0f && m_returnY == 0.0f )
				{
					m_returnX = GetUnit()->GetSpawnX();
					m_returnY = GetUnit()->GetSpawnY();
					m_returnZ = GetUnit()->GetSpawnZ();
				}

				MoveTo(m_returnX, m_returnY, m_returnZ, GetUnit()->GetSpawnO());
			}
		}
	}

	if(m_fleeTimer)
	{
		if(m_fleeTimer > p_time)
		{
			m_fleeTimer -= p_time;
			if(!GetNextTarget()) // something happened to our target, lets find another one
				SetNextTarget(FindTargetForSpell(m_nextSpell));
			if(GetNextTarget())
				_CalcDestinationAndMove(GetNextTarget(), 5.0f);
		}
		else
		{
			m_fleeTimer = 0;
			SetNextTarget(FindTargetForSpell(m_nextSpell));
		}
	}
}

void AIInterface::_UpdateTimer(uint32 p_time)
{
	if(m_updateAssistTimer > p_time)
	{
		m_updateAssistTimer -= p_time;
	}else
	{
		m_updateAssist = true;
		m_updateAssistTimer = TARGET_UPDATE_INTERVAL * 2 - m_updateAssistTimer - p_time;
	}

	if(m_updateTargetsTimer > p_time)
	{
		m_updateTargetsTimer -= p_time;
	}else
	{
		m_updateTargets = true;
		m_updateTargetsTimer = TARGET_UPDATE_INTERVAL * 2 - m_updateTargetsTimer - p_time;
	}
}

void AIInterface::_UpdateTargets()
{
	if( GetUnit()->IsPlayer() || (getAIType() != AITYPE_PET && disable_targeting ))
		return;

	if( TO_CREATURE(GetUnit())->GetCreatureName() && TO_CREATURE(GetUnit())->GetCreatureName()->Type == CRITTER )
		return;

	AssistTargetSet::iterator i, i2;
	TargetMap::iterator itr, it2;

	// Find new Assist Targets and remove old ones
	if(getAIState() == STATE_FLEEING)
	{
		FindFriends(100.0f/*10.0*/);
	}
	else if(getAIState() != STATE_IDLE && getAIState() != STATE_SCRIPTIDLE)
	{
		FindFriends(16.0f/*4.0f*/);
	}

	if( m_updateAssist )
	{
		m_updateAssist = false;

		for(i = GetAssistTargets().begin(); i != GetAssistTargets().end();)
		{
			i2 = i++;
			if((*i2) == NULL || (*i2)->event_GetCurrentInstanceId() != GetUnit()->event_GetCurrentInstanceId() || !GetUnit()->PhasedCanInteract(*i2) ||
				!(*i2)->isAlive() || GetUnit()->GetDistanceSq((*i2)) >= 2500.0f || !(*i2)->CombatStatus.IsInCombat() )
			{
				GetAssistTargets().erase( i2 );
			}
		}
	}

	if( m_updateTargets )
	{
		m_updateTargets = false;
		
		for(itr = m_aiTargets.begin(); itr != m_aiTargets.end();)
		{
			it2 = itr++;

			if( it2->first->event_GetCurrentInstanceId() != GetUnit()->event_GetCurrentInstanceId() || !GetUnit()->PhasedCanInteract(it2->first) ||
				!it2->first->isAlive() || GetUnit()->GetDistanceSq(it2->first) >= 6400.0f )
			{
				m_aiTargets.erase( it2 );
			}
		}
		
		if(getAITargetsCount() == 0 
			&& getAIState() != STATE_IDLE && getAIState() != STATE_FOLLOWING 
			&& getAIState() != STATE_EVADE && getAIState() != STATE_FEAR 
			&& getAIState() != STATE_WANDER && getAIState() != STATE_SCRIPTIDLE)
		{
			if(firstLeaveCombat)
			{
				UnitPointer target = FindTarget();
				if(target)
				{
					AttackReaction(target, 1, 0);
				}else
				{
					firstLeaveCombat = false;
				}
			}
		}
		else if( getAITargetsCount() == 0 && (getAIType() == AITYPE_PET && (GetUnit()->IsPet() && TO_PET(GetUnit())->GetPetState() == PET_STATE_AGGRESSIVE) || (!GetUnit()->IsPet() && disable_melee == false ) ) )
		{
			 UnitPointer target = FindTarget();
			 if( target )
			 {
				 AttackReaction(target, 1, 0);
			 }

		}
	}
	// Find new Targets when we are ooc
	if((getAIState() == STATE_IDLE || getAIState() == STATE_SCRIPTIDLE) && GetAssistTargets().size() == 0)
	{
		UnitPointer target = FindTarget();
		if(target)
		{
			AttackReaction(target, 1, 0);
		}
	}
}

//////////////////////////////////////////////////////////////
//  Desc: Updates Combat Status of GetUnit()                //
//////////////////////////////////////////////////////////////
void AIInterface::_UpdateCombat(uint32 p_time)
{
	if( getAIType() != AITYPE_PET && disable_combat )
		return;

	// just make sure we are not hitting self. This was reported as an exploit.Should never ocure anyway
	if( GetNextTarget() == GetUnit() )
		SetNextTarget(GetMostHated());

	uint16 agent = getCurrentAgent();

		// If at instance returns to spawnpoint after empty agrolist
		if(	getAIType() != AITYPE_PET
			&& getAIState() != STATE_EVADE
			&& getAIState() != STATE_SCRIPTMOVE
			&& !m_is_in_instance
			&& (getOutOfCombatRange() && GetUnit()->GetDistanceSq(m_returnX,m_returnY,m_returnZ) > getOutOfCombatRange()) )
		HandleEvent( EVENT_LEAVECOMBAT, GetUnit(), 0 );
	else if( GetNextTarget() == NULL && getAIState() != STATE_FOLLOWING && getAIState() != STATE_SCRIPTMOVE )
	{
		SetNextTarget(GetMostHated());
		if( GetNextTarget() == NULL )
			HandleEvent( EVENT_LEAVECOMBAT, GetUnit(), 0 );
	}

	if( GetNextTarget() != NULL && GetNextTarget()->isAlive() && getAIState() != STATE_EVADE && !GetUnit()->isCasting() )
	{
		if( agent == AGENT_NULL || ( getAIType() == AITYPE_PET && !m_nextSpell ) ) // allow pets autocast
		{
			if(m_canFlee && !m_hasFled && ( m_FleeHealth ? float(GetUnit()->GetUInt32Value(UNIT_FIELD_HEALTH) / GetUnit()->GetUInt32Value(UNIT_FIELD_MAXHEALTH)) < m_FleeHealth : 1))
				agent = AGENT_FLEE;
			else if(m_canCallForHelp && !m_hasCalledForHelp )
				agent = AGENT_CALLFORHELP;
			else // default to melee if no spells found
			{
				m_nextSpell = getSpell();
				if(m_nextSpell != NULL && m_nextSpell->agent != AGENT_NULL)
					agent = m_nextSpell->agent;
				else
					agent = AGENT_MELEE;
			}
		}
		// check if we can do range attacks
		if(agent == AGENT_RANGED || agent == AGENT_MELEE)
		{
			if(m_canRangedAttack)
			{
				float dist = GetUnit()->GetDistanceSq(GetNextTarget());
				if(GetNextTarget()->GetTypeId() == TYPEID_PLAYER)
				{
					if( TO_PLAYER( GetNextTarget() )->m_currentMovement == MOVE_ROOT || dist >= 32.0f )
						agent = AGENT_RANGED;
				}
				else if( GetNextTarget()->m_canMove == false || dist >= 32.0f )
				   agent = AGENT_RANGED;
			}
			else
			{
				agent = AGENT_MELEE;
			}
		}

		if( disable_melee && agent == AGENT_MELEE )
			agent = AGENT_NULL;
		  
		if( disable_ranged && agent == AGENT_RANGED )
			agent = AGENT_NULL;

		if( disable_spell && agent == AGENT_SPELL )
			agent = AGENT_NULL;

		switch(agent)
		{
			case AGENT_MELEE:
			{
				if( GetUnit()->GetTypeId() == TYPEID_UNIT )
					TO_CREATURE(GetUnit())->SetSheatheForAttackType( 1 );
				float combatReach[2]; // Calculate Combat Reach
				float distance = GetUnit()->CalcDistance(GetNextTarget());

				combatReach[0] = PLAYER_SIZE;
				combatReach[1] = _CalcCombatRange(GetNextTarget(), false);

				if(	distance >= combatReach[0] && distance <= combatReach[1] + 0.75f) // Target is (alomst) in Range -> Attack
				{
					if(getUnitToFollow() != NULL)
					{
						SetUnitToFollow(NULLUNIT); // we shouldn't be following any one
						m_lastFollowX = m_lastFollowY = 0;
						SetFollowDistance(0.0f);
					}
				
					if(GetUnit()->isAttackReady(false) && !m_fleeTimer)
					{
						setCreatureState(ATTACKING);
						bool infront = GetUnit()->isInFront(GetNextTarget());	

						if(!infront) // set InFront
						{
							// prevent mob from rotating while stunned
							if(!GetUnit()->IsStunned ())
							{
								setInFront(GetNextTarget());
								infront = true;
							}							
						}
						if(infront)
						{
							GetUnit()->setAttackTimer(0, false);
#ifdef ENABLE_CREATURE_DAZE
							// we require to know if strike was succesfull. If there was no dmg then target cannot be dazed by it
							uint32 health_before_strike=GetNextTarget()->GetUInt32Value(UNIT_FIELD_HEALTH);
#endif
							if(GetNextTarget() != NULL)
							{
								GetUnit()->Strike( GetNextTarget(), MELEE, NULL, 0, 0, 0, false, false, true );
#ifdef ENABLE_CREATURE_DAZE
								// now if the target is facing his back to us then we could just cast dazed on him :P
								// as far as i know dazed is casted by most of the creatures but feel free to remove this code if you think otherwise
								if(GetNextTarget() != NULL && GetUnit()->m_factionDBC && !(GetUnit()->m_factionDBC->RepListId == -1 && GetUnit()->m_faction->FriendlyMask==0 && GetUnit()->m_faction->HostileMask==0) /* neutral creature */
										&& GetNextTarget()->IsPlayer() && !GetUnit()->IsPet() && health_before_strike>GetNextTarget()->GetUInt32Value(UNIT_FIELD_HEALTH)
										&& Rand(GetUnit()->CalculateDazeCastChance(GetNextTarget())))
								{
									float our_facing=GetUnit()->calcRadAngle(GetUnit()->GetPositionX(),GetUnit()->GetPositionY(),GetNextTarget()->GetPositionX(),m_nextTarget->GetPositionY());
									float his_facing=GetNextTarget()->GetOrientation();
									if(fabs(our_facing-his_facing)<CREATURE_DAZE_TRIGGER_ANGLE && !GetNextTarget()->HasNegativeAura(CREATURE_SPELL_TO_DAZE))
									{
										SpellEntry *info = dbcSpell.LookupEntry(CREATURE_SPELL_TO_DAZE);
										SpellPointer sp(new Spell(GetUnit(), info, false, NULLAURA));
										SpellCastTargets targets;
										targets.m_unitTarget = GetNextTarget()->GetGUID();
										sp->prepare(&targets);
									}
								}
#endif
							}
						}
					}	
				}
				else // Target out of Range -> Run to it
				{
					// Make sure target can reach us.
					float dist = combatReach[1] - GetUnit()->GetFloatValue( UNIT_FIELD_COMBATREACH ); 
					if(dist < PLAYER_SIZE)
						dist = PLAYER_SIZE; // unbelievable how this could happen
					if (distance<combatReach[0])
						dist = -(distance+combatReach[0]*0.6666f);

					m_moveRun = true;
					_CalcDestinationAndMove(GetNextTarget(), dist);
				}
			}break;
		case AGENT_RANGED:
			{
				if( GetUnit()->GetTypeId() == TYPEID_UNIT )
					TO_CREATURE(GetUnit())->SetSheatheForAttackType( 3 );

				float combatReach[4]; // Used Shooting Ranges
				float distance = GetUnit()->CalcDistance(GetNextTarget());

				combatReach[0] = GetUnit()->GetFloatValue(UNIT_FIELD_COMBATREACH); // normal combat reach
				combatReach[1] = combatReach[0] + 8.0f;  // if distance <  combatReach[1], run towards target, and enter melee.
				combatReach[2] = combatReach[0] + 30.0f; // When shooting and distance > combatReach[2], 
				combatReach[3] = combatReach[0] + 26.0f; // close in to combatReach[3] again, and continue shooting.

				if(distance >= combatReach[1] && distance <= combatReach[2]) // Target is in Range -> Shoot!!
				{
					if(getUnitToFollow() != NULL)
					{
						SetUnitToFollow(NULLUNIT); // we shouldn't be following any one
						m_lastFollowX = m_lastFollowY = 0;
						SetFollowDistance(0.0f);
					}
					

					// FIXME: offhand shit
					if(GetUnit()->isAttackReady(false) && !m_fleeTimer)
					{
						setCreatureState(ATTACKING);
						bool infront = GetUnit()->isInFront(GetNextTarget());	

						if(!infront) // set InFront
						{
							// prevent mob from rotating while stunned
							if(!GetUnit()->IsStunned ())
							{
								setInFront(GetNextTarget());
								infront = true;
							}							
						}

						if(infront)
						{
							GetUnit()->setAttackTimer(0, false);
							SpellEntry *info = dbcSpell.LookupEntry(m_RangedAttackSpell);
							if(info)
							{
								SpellPointer sp(new Spell(GetUnit(), info, false, NULLAURA));
								SpellCastTargets targets(GetNextTarget()->GetGUID());
								sp->prepare(&targets);

								// Did we give it a sound ID?	
								if(m_SpellSoundid)
									GetUnit()->PlaySoundToSet(m_SpellSoundid);
							}
						}
					}
				}
				else // Target out of Range -> Run to/from it, depending on current distance
				{
					m_moveRun = true;
					float drun = (distance < combatReach[1] ? combatReach[0] : combatReach[3] );
					_CalcDestinationAndMove(GetNextTarget(), drun);
				}
			}break;
		case AGENT_SPELL:
			{
				if( m_nextSpell == NULL || GetNextTarget() == NULL )
					return;  // this shouldnt happen

				DEBUG_LOG(AIAGANTSAAAAAAAI,NEXTSPELLAAAAAAI,m_nextSpell->spell->Id, GetUnit()->GetGUID());

				if( GetUnit()->GetTypeId() == TYPEID_UNIT )
					TO_CREATURE(GetUnit())->SetSheatheForAttackType( 0 );

				float distance = GetUnit()->GetDistanceSq(GetNextTarget());
				bool los = true;
				if (GetUnit()->GetMapMgr() && GetUnit()->GetMapMgr()->IsCollisionEnabled())
				{
					los = CollideInterface.CheckLOS( GetUnit()->GetMapId(), GetUnit()->GetPositionX(), GetUnit()->GetPositionY(), GetUnit()->GetPositionZ(),
						GetNextTarget()->GetPositionX(), GetNextTarget()->GetPositionY(), GetNextTarget()->GetPositionZ() );
				}
				if(los && ((distance <= (m_nextSpell->maxrange*m_nextSpell->maxrange)  && distance >= (m_nextSpell->minrange*m_nextSpell->minrange)) || m_nextSpell->maxrange == 0)) // Target is in Range -> Attack
				{
					SpellEntry* spellInfo = m_nextSpell->spell;

					// If this is a healing spell, check health of self and surroundings.
					SpellCastTargets targets;
					if(m_nextSpell->spellType == STYPE_HEAL)
					{
						UnitPointer starget = FindHealTargetForSpell(m_nextSpell);
						if(starget)
							targets = setSpellTargets(spellInfo, starget);
					}
					else
					{
						targets = setSpellTargets(spellInfo, GetNextTarget());
					}

					// Let's find out on whom to cast the spell on
					uint32 	targettype = m_nextSpell->spelltargetType;
					targets = setSpellTargets(spellInfo, GetNextTarget());
					targettype = m_nextSpell->spelltargetType;
					uint8 ccr = 0;
					switch(targettype)
					{
						case TTYPE_CASTER:
						case TTYPE_SINGLETARGET:
						{
							ccr = CastSpell(GetUnit(), spellInfo, targets);
							break;
						}
						case TTYPE_SOURCE:
						{
							ccr = GetUnit()->CastSpellAoF(GetUnit()->GetPositionX(),GetUnit()->GetPositionY(),GetUnit()->GetPositionZ(), spellInfo, true);
							break;
						}
						case TTYPE_DESTINATION:
						{
							ccr = GetUnit()->CastSpellAoF(GetUnit()->GetPositionX(),GetUnit()->GetPositionY(),GetUnit()->GetPositionZ(), spellInfo, false);
							break;
						}
						case TTYPE_OWNER:
						{
							if(GetUnit()->IsPet() &&  GetPetOwner())
								ccr = CastSpell(GetPetOwner(), spellInfo, targets);
							break;
						}
					}

					if( ccr == SPELL_CANCAST_OK )
					{
						// Did we give it a sound ID?	
						if( m_nextSpell && m_nextSpell->Misc2 )
							GetUnit()->PlaySoundToSet(m_nextSpell->Misc2);

						// add pet spell after use to pet owner with some chance
						if( GetUnit()->IsPet() &&  GetPetOwner() && GetPetOwner()->IsPlayer())
						{	
							PetPointer pPet = TO_PET(GetUnit());
							if( pPet && Rand(5)) //5% change to gain spell from pet
								pPet->AddPetSpellToOwner(spellInfo->Id);
						}
						// This spell won't be cast until it cooldown cleared.
						if(m_nextSpell && m_nextSpell->cooldown)
							m_nextSpell->cooldowntime = getMSTime() + m_nextSpell->cooldown;

						// increase procCounter if we're counting
						if(m_nextSpell && m_nextSpell->procCount)
							m_nextSpell->procCounter++;
					}
					else
						DEBUG_LOG(AIAGANTSAAAAAAAI,SPELLFALESAAAAAI, ccr, GetUnit()->GetEntry() , spellInfo->Id, targettype );
				}
				else // Target out of Range/not in LOS -> Run to it
				{
					// calculate next move
					m_moveRun = true;
					_CalcDestinationAndMove( GetNextTarget(), ( m_nextSpell->maxrange < 5.0f ? GetUnit()->GetFloatValue(UNIT_FIELD_COMBATREACH) : m_nextSpell->maxrange - 5.0f ));
				}
				// Null out the agent, so we force the lookup of the next spell.
				setCurrentAgent(AGENT_NULL);
			}break;
		case AGENT_FLEE:
			{
				m_moveRun = false;
				if(m_fleeTimer == 0)
					m_fleeTimer = m_FleeDuration;

				_CalcDestinationAndMove(GetNextTarget(), 5.0f);
				if(!m_hasFled)
					CALL_SCRIPT_EVENT(GetUnit(), OnFlee)(GetNextTarget());

				SetAIState(STATE_FLEEING);
				SetNextTarget(NULLUNIT);

				WorldPacket data( SMSG_MESSAGECHAT, 100 );
				string msg = ATTEMPTSRUMAWAAI;
				data << (uint8)CHAT_MSG_CHANNEL;
				data << (uint32)LANG_UNIVERSAL;
				data << (uint32)( strlen( TO_CREATURE( GetUnit() )->GetCreatureName()->Name ) + 1 );
				data << TO_CREATURE( GetUnit() )->GetCreatureName()->Name;
				data << (uint64)0;
				data << (uint32)(msg.size() + 1);
				data << msg;
				data << uint8(0);

				GetUnit()->SendMessageToSet(&data, false);
				m_hasFled = true;
			}break;
		case AGENT_CALLFORHELP:
			{
				FindFriends( 50.0f /*7.0f*/ );
				m_hasCalledForHelp = true; // We only want to call for Help once in a Fight.
				if( GetUnit()->GetTypeId() == TYPEID_UNIT )
						objmgr.HandleMonsterSayEvent( TO_CREATURE( GetUnit() ), MONSTER_SAY_EVENT_CALL_HELP );
				CALL_SCRIPT_EVENT( GetUnit(), OnCallForHelp )();
			}break;
		}
	}
	else if( !GetNextTarget() || !GetUnit()->isCasting() ||GetNextTarget()->GetInstanceID() != GetUnit()->GetInstanceID() || !GetNextTarget()->isAlive() || !GetNextTarget()->IsInWorld() )
	{
		// no more target
		SetNextTarget( NULLUNIT );
	}
}

void AIInterface::DismissPet()
{
//
//
}

void AIInterface::AttackReaction(UnitPointer pUnit, uint32 damage_dealt, uint32 spellId)
{
	if( getAIState() == STATE_EVADE || m_fleeTimer != 0 || !pUnit || !pUnit->isAlive() || !GetUnit()->isAlive() )
	{
		return;
	}

	if( GetUnit() == pUnit )
	{
		return;
	}

	if( getAIState() == STATE_IDLE || getAIState() == STATE_FOLLOWING )
	{
		WipeTargetList();
		
		HandleEvent(EVENT_ENTERCOMBAT, pUnit, 0);
	}

	HandleEvent(EVENT_DAMAGETAKEN, pUnit, _CalcThreat(damage_dealt, spellId ? dbcSpell.LookupEntryForced(spellId) : NULL, pUnit));
}

bool AIInterface::HealReaction(UnitPointer caster, UnitPointer victim, uint32 amount, SpellEntry * sp)
{
	if(!caster || !victim)
	{
		// printf("!!!BAD POINTER IN AIInterface::HealReaction!!!\n");
		return false;
	}

	// apply spell modifiers
	if (sp != NULL && sp->SpellGroupType)
	{
		SM_FIValue(caster->SM[SMT_THREAT_REDUCED][0],(int32*)&amount,sp->SpellGroupType);
		SM_PIValue(caster->SM[SMT_THREAT_REDUCED][1],(int32*)&amount,sp->SpellGroupType);
	}
	amount += (amount * caster->GetGeneratedThreatModifier() / 100);

	int casterInList = 0, victimInList = 0;

	if(m_aiTargets.find(caster) != m_aiTargets.end())
		casterInList = 1;

	if(m_aiTargets.find(victim) != m_aiTargets.end())
		victimInList = 1;

	if(!victimInList && !casterInList) // none of the Casters is in the Creatures Threat list
	{
		return false;
	}
	if(!casterInList && victimInList) // caster is not yet in Combat but victim is
	{
		// get caster into combat if he's hostile
		if(isHostile(GetUnit(), caster))
		{
			if( caster->IsPlayer() )
			{
				if( caster->mThreatRTarget )
					m_aiTargets.insert(TargetMap::value_type(TO_PLAYER(caster->mThreatRTarget), amount));
				else
					m_aiTargets.insert(TargetMap::value_type(caster, amount));
			}
			else
				m_aiTargets.insert(TargetMap::value_type(caster, amount));

			return true;
		}
		return false;
	}
	else if(casterInList && victimInList) // both are in combat already
	{
		// mod threat for caster
		modThreatByPtr(caster, amount);
		return true;
	}
	else // caster is in Combat already but victim is not
	{
		modThreatByPtr(caster, amount);
		// both are players so they might be in the same group
		if( caster->GetTypeId() == TYPEID_PLAYER && victim->GetTypeId() == TYPEID_PLAYER )
		{
			if( TO_PLAYER( caster )->GetGroup() == TO_PLAYER( victim )->GetGroup() )
			{
				// get victim into combat since they are both
				// in the same party
				if( isHostile( GetUnit(), victim ) )
				{
					m_aiTargets.insert( TargetMap::value_type( victim, 1 ) );
					return true;
				}
				return false;
			}
		}
	}

	return false;
}

void AIInterface::OnDeath(ObjectPointer pKiller)
{
	if(pKiller->GetTypeId() == TYPEID_PLAYER || pKiller->GetTypeId() == TYPEID_UNIT)
		HandleEvent(EVENT_UNITDIED, TO_UNIT(pKiller), 0);
	else
		HandleEvent(EVENT_UNITDIED, GetUnit(), 0);
}

UnitPointer AIInterface::FindTarget()
{// find nearest hostile Target to attack
	if( !GetAllowedToEnterCombat() ) 
		return NULLUNIT;

	UnitPointer target = NULLUNIT;
	UnitPointer critterTarget = NULLUNIT;
	float distance = 999999.0f; // that should do it.. :p
	float crange;
	float z_diff;

	unordered_set<ObjectPointer >::iterator itr, it2;
	ObjectPointer pObj;
	UnitPointer pUnit;
	float dist;
	bool pvp=true;
	if(GetUnit()->GetTypeId()==TYPEID_UNIT&&TO_CREATURE(GetUnit())->GetCreatureName()&&TO_CREATURE(GetUnit())->GetCreatureName()->Civilian)
		pvp=false;

	// target is immune to all form of attacks, cant attack either.
	if(GetUnit()->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
	{
		return NULLUNIT;
	}

	for( itr = GetUnit()->GetInRangeOppFactsSetBegin(); itr != GetUnit()->GetInRangeOppFactsSetEnd(); )
	{
		it2 = itr;
		++itr;

		pObj = (*it2);
		if( pObj->GetTypeId() == TYPEID_PLAYER )
		{
			if(TO_PLAYER( pObj )->GetTaxiState() )	  // skip players on taxi
				continue;
		}
		else if( pObj->GetTypeId() != TYPEID_UNIT )
				continue;

		pUnit = TO_UNIT(pObj);
		// Don't agro on invincibility
		if( pUnit->bInvincible )
			continue;

		// do not agro units that are faking death. Should this be based on chance ?
		if( pUnit->HasFlag( UNIT_FIELD_FLAGS, UNIT_FLAG_FEIGN_DEATH ) )
			continue;

		// target is immune to unit attacks however can be targeted
		// as a part of AI we allow this mode to attack creatures as seen many times on oficial.
		if( GetUnit()->HasFlag( UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9 ) )
		{
			if( pUnit->IsPlayer() || pUnit->IsPet() )
			{
				continue;
			}
		}

		// is it a player? we have to check for our pvp flag.
		crange = _CalcCombatRange(pUnit,false);
		if(m_isGuard)
			crange *= 4;

		z_diff = fabs(GetUnit()->GetPositionZ() - pUnit->GetPositionZ());
		if(z_diff > crange)
		{
			continue;
		}

		if( !GetUnit()->PhasedCanInteract( pUnit ) )
			continue;

		/*if(pUnit->m_invisible) // skip invisible units
			continue;*/
		
		if(!pUnit->isAlive()
			|| GetUnit() == pUnit 
			|| GetUnit()->GetUInt64Value(UNIT_FIELD_CREATEDBY) == pUnit->GetGUID())
			continue;

		dist = GetUnit()->GetDistanceSq(pUnit);
		if(!pUnit->m_faction || !pUnit->m_factionDBC)
			continue;

		//BLooD_LorD:don't agro neutrals
		if( ( pUnit->IsPlayer() || pUnit->IsPet() )
			&& GetUnit()->m_factionDBC->RepListId == -1 
			&& GetUnit()->m_faction->HostileMask == 0 
			&& GetUnit()->m_faction->FriendlyMask == 0
			)
				continue;
		else if( ( GetUnit()->IsPlayer() || GetUnit()->IsPet() )
			 && pUnit->m_factionDBC->RepListId == -1 
			 && pUnit->m_faction->HostileMask == 0 
			 && pUnit->m_faction->FriendlyMask == 0
			 )
				continue;	

		if(pUnit->m_faction && pUnit->m_faction->Faction == 28) // only Attack a critter if there is no other Enemy in range
		{
			if(dist < 225.0f)	// was 10
				critterTarget = pUnit;
			continue;
		}

		if(dist > distance)	 // we want to find the CLOSEST target
			continue;
		
		if(dist <= _CalcAggroRange(pUnit) )
		{
            if( GetUnit()->IsInLineOfSight(pUnit) )
			{
				distance = dist;
				target = pUnit;
			}
		}
	}

	if( !target )
	{
		target = critterTarget;
	}

	if( target )
	{

		AttackReaction(target, 1, 0);
		WorldPacket data(SMSG_AI_REACTION, 12);
		data << GetUnit()->GetGUID() << uint32(2);		// Aggro sound
		GetUnit()->SendMessageToSet(&data, false);

		if(target->GetUInt32Value(UNIT_FIELD_CREATEDBY) != 0)
		{
			UnitPointer target2 = GetUnit()->GetMapMgr()->GetPlayer(target->GetUInt32Value(UNIT_FIELD_CREATEDBY));
			if(target2)
			{
				AttackReaction(target2, 1, 0);
			}
		}
	}
	return target;
}

UnitPointer AIInterface::FindTargetForSpell(AI_Spell *sp)
{

	TargetMap::iterator itr, itr2;

	if(sp)
	{
		if(sp->spellType == STYPE_HEAL)
		{
			uint32 cur = GetUnit()->GetUInt32Value(UNIT_FIELD_HEALTH) + 1;
			uint32 max = GetUnit()->GetUInt32Value(UNIT_FIELD_MAXHEALTH) + 1;
			float healthPercent = float(cur) / float(max);
			if(healthPercent <= sp->floatMisc1) // Heal ourselves cause we got too low HP
			{
				GetUnit()->SetUInt64Value(UNIT_FIELD_TARGET, 0);
				return GetUnit();
			}
			for(AssistTargetSet::iterator i = GetAssistTargets().begin(); i != GetAssistTargets().end(); i++)
			{
				if(!(*i)->isAlive())
				{
					continue;
				}
				cur = (*i)->GetUInt32Value(UNIT_FIELD_HEALTH);
				max = (*i)->GetUInt32Value(UNIT_FIELD_MAXHEALTH);
				healthPercent = float(cur) / float(max);
				if(healthPercent <= sp->floatMisc1) // Heal ourselves cause we got too low HP
				{
					GetUnit()->SetUInt64Value(UNIT_FIELD_TARGET, (*i)->GetGUID());
					return (*i); // heal Assist Target which has low HP
				}
			}
		}
		if(sp->spellType == STYPE_BUFF)
		{
			GetUnit()->SetUInt64Value(UNIT_FIELD_TARGET, 0);
			return GetUnit();
		}
	}

	return GetMostHated();
}
UnitPointer AIInterface::FindHealTargetForSpell(AI_Spell *sp)
{
	TargetMap::iterator itr, itr2;

	if(sp)
	{
		ASSERT(sp->spellType == STYPE_HEAL);

		uint32 cur = GetUnit()->GetUInt32Value(UNIT_FIELD_HEALTH) + 1;
		uint32 max = GetUnit()->GetUInt32Value(UNIT_FIELD_MAXHEALTH) + 1;
		float healthPercent = float(cur) / float(max);
		if(healthPercent <= sp->floatMisc1 && !GetUnit()->HasActiveAura(sp->spell->Id,GetUnit()->GetGUID())) // Heal ourselves cause we got too low HP
		{
			sp->spelltargetType = TTYPE_CASTER;
			GetUnit()->SetUInt64Value(UNIT_FIELD_TARGET, 0);
			return GetUnit();
		}
		for(AssistTargetSet::iterator i = GetAssistTargets().begin(); i != GetAssistTargets().end(); ++i)
		{
			if(!(*i)->isAlive())
				continue;

			cur = (*i)->GetUInt32Value(UNIT_FIELD_HEALTH);
			max = (*i)->GetUInt32Value(UNIT_FIELD_MAXHEALTH);
			healthPercent = float(cur / max);
			if(healthPercent <= sp->floatMisc1 && !(*i)->HasActiveAura(sp->spell->Id,GetUnit()->GetGUID()))
			{
				sp->spelltargetType = TTYPE_SINGLETARGET;
				GetUnit()->SetUInt64Value(UNIT_FIELD_TARGET, (*i)->GetGUID());
				return (*i); // heal Assist Target which has low HP
			}
		}
	}

	return NULLUNIT;
}


bool AIInterface::FindFriends(float dist)
{
	if( GetUnit()->IsPet() ) // pet's do not have friends; Players are exploiting this :-/
		return false;

	bool result = false;
	TargetMap::iterator it;

	unordered_set<ObjectPointer >::iterator itr;
	UnitPointer pUnit;

	for( itr = GetUnit()->GetInRangeSetBegin(); itr != GetUnit()->GetInRangeSetEnd(); itr++ )
	{
		if((*itr) == NULL || !(*itr)->IsInWorld() || (*itr)->GetTypeId() != TYPEID_UNIT)
			continue;

		pUnit = TO_UNIT((*itr));
		if(!pUnit->isAlive())
			continue;

		if(pUnit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
		{
			continue;
		}
		if(pUnit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9))
		{
			continue;
		}

		if( !isHostile(GetMostHated(), pUnit) )
		{
			continue;
		}

		if( !GetUnit()->PhasedCanInteract(pUnit) )
			continue;

		if( isCombatSupport( GetUnit(), pUnit ) && ( pUnit->GetAIInterface()->getAIState() == STATE_IDLE || pUnit->GetAIInterface()->getAIState() == STATE_SCRIPTIDLE ) )//Not sure
		{
			if( GetUnit()->GetDistanceSq(pUnit) < dist)
			{
				if( GetAssistTargets().count( pUnit ) > 0 ) // already have him
					break;

				result = true;
				GetAssistTargets().insert(pUnit);
					
				for(it = m_aiTargets.begin(); it != m_aiTargets.end(); ++it)
				{
					TO_UNIT( *itr )->GetAIInterface()->AttackReaction( it->first, 1, 0 );
				}
			}
		}
	}

	// check if we're a civillan, in which case summon guards on a despawn timer
	CreatureInfo * ci = TO_CREATURE(GetUnit())->GetCreatureName();
	if( ci && ci->Type == HUMANOID && ci->Civilian )
		CallGuards();	

	return result;
}

float AIInterface::_CalcAggroRange(UnitPointer target)
{
	const static float baseAR[17] = {19.0f, 18.5f, 18.0f, 17.5f, 17.0f, 16.5f, 16.0f, 15.5f, 15.0f, 14.5f, 12.0f, 10.5f, 8.5f,  7.5f,  6.5f,  6.5f, 5.0f};
	int8 lvlDiff = target->getLevel() - GetUnit()->getLevel();
	uint8 realLvlDiff = lvlDiff;
	if(lvlDiff > 8)
	{
		lvlDiff = 8;
	}
	if(lvlDiff < -8)
	{
		lvlDiff = -8;
	}
	if(!TO_CREATURE(GetUnit())->CanSee(target))
		return 0;
	
	float AggroRange = baseAR[lvlDiff + 8];
	if(realLvlDiff > 8)
	{
		AggroRange += AggroRange * ((lvlDiff - 8) * 5 / 100);
	}

	// Multiply by elite value
	if(TO_CREATURE(GetUnit())->GetCreatureName() && TO_CREATURE(GetUnit())->GetCreatureName()->Rank > 0)
		AggroRange *= (TO_CREATURE(GetUnit())->GetCreatureName()->Rank) * 1.50f;

	if(AggroRange > 40.0f) // cap at 40.0f
	{
		AggroRange = 40.0f;
	}
	// SPELL_AURA_MOD_DETECT_RANGE
	int32 modDetectRange = target->getDetectRangeMod(GetUnit()->GetGUID());
	AggroRange += modDetectRange;
	if(target->IsPlayer())
		AggroRange += TO_PLAYER( target )->DetectedRange;
	if(AggroRange < 3.0f)
	{
		AggroRange = 3.0f;
	}
	if(AggroRange > 40.0f) // cap at 40.0f
	{
		AggroRange = 40.0f;
	}

	return (AggroRange*AggroRange);
}

void AIInterface::_CalcDestinationAndMove(UnitPointer target, float dist)
{
	if(!m_canMove || GetUnit()->IsStunned())
	{
		StopMovement(0); // Just Stop
		return;
	}
	
	if(target && (target->GetTypeId() == TYPEID_UNIT || target->GetTypeId() == TYPEID_PLAYER))
	{
		float ResX = target->GetPositionX();
		float ResY = target->GetPositionY();
		float ResZ = target->GetPositionZ();

		float angle = GetUnit()->calcAngle(GetUnit()->GetPositionX(), GetUnit()->GetPositionY(), ResX, ResY) * float(M_PI) / 180.0f;
		float x = dist * cosf(angle);
		float y = dist * sinf(angle);

		if(target->GetTypeId() == TYPEID_PLAYER && TO_PLAYER( target )->m_isMoving )
		{
			// cater for moving player vector based on orientation
			x -= cosf(target->GetOrientation());
			y -= sinf(target->GetOrientation());
		}

		m_nextPosX = ResX - x;
		m_nextPosY = ResY - y;
		m_nextPosZ = ResZ;
	}
	else
	{
		target = NULLUNIT;
		m_nextPosX = GetUnit()->GetPositionX();
		m_nextPosY = GetUnit()->GetPositionY();
		m_nextPosZ = GetUnit()->GetPositionZ();
	}

	float dx = m_nextPosX - GetUnit()->GetPositionX();
	float dy = m_nextPosY - GetUnit()->GetPositionY();
	if(dy != 0.0f)
	{
		float angle = atan2(dx, dy);
		GetUnit()->SetOrientation(angle);
	}

	if(m_creatureState != MOVING)
		UpdateMove();
}

float AIInterface::_CalcCombatRange(UnitPointer target, bool ranged)
{
	if(!target)
	{
		return 0;
	}
	float range = 0.0f;
	float rang = PLAYER_SIZE;
	if(ranged)
	{
		rang = 5.0f;
	}

	float selfreach = GetUnit()->GetFloatValue(UNIT_FIELD_COMBATREACH);
	float targetradius = target->GetFloatValue(UNIT_FIELD_BOUNDINGRADIUS);
	float selfradius = GetUnit()->GetFloatValue(UNIT_FIELD_BOUNDINGRADIUS);
	float targetscale = GetScale( dbcCreatureDisplayInfo.LookupEntry( target->GetUInt32Value(UNIT_FIELD_DISPLAYID)));
	float selfscale =  GetScale( dbcCreatureDisplayInfo.LookupEntry( GetUnit()->GetUInt32Value(UNIT_FIELD_DISPLAYID)));

	range = ((((targetradius*targetradius)*targetscale) + selfreach) + ((selfradius*selfscale) + rang));
	if(range > 28.29f) range = 28.29f;
	return range < PLAYER_SIZE ? PLAYER_SIZE :range ;
}

float AIInterface::_CalcDistanceFromHome()
{
	if (getAIType() == AITYPE_PET)
	{
		return GetUnit()->GetDistanceSq(GetPetOwner());
	}
	else if(GetUnit()->GetTypeId() == TYPEID_UNIT)
	{

		if(m_returnX !=0.0f && m_returnY != 0.0f)
		{
			return GetUnit()->GetDistanceSq(m_returnX,m_returnY,m_returnZ);
		}
	}

	return 0.0f;
}

void AIInterface::SendMoveToPacket(float toX, float toY, float toZ, float toO, uint32 time, uint32 MoveFlags)
{
	// this should NEVER be called directly.
	// use MoveTo()
	// WorldPacket data(SMSG_MONSTER_MOVE, 60);
	uint8 buffer[100];
	StackPacket data(SMSG_MONSTER_MOVE, buffer, 100);
	data << GetUnit()->GetNewGUID();
	data << uint8(0);
	data << GetUnit()->GetPositionX() << GetUnit()->GetPositionY() << GetUnit()->GetPositionZ();
	data << getMSTime();
	
	// Check if we have an orientation
	if(toO != 0.0f)
	{
		data << uint8(4);
		data << toO;
	} else {
		data << uint8(0);
	}
	data << MoveFlags;
	if(MoveFlags & 0x200000)
	{
		data << uint8(0);
		data << uint32(0);
	}
	if(MoveFlags & 0x800)
	{
		data << float(0);
		data << uint32(0);
	}

	data << time;
	data << uint32(1);	  // 1 waypoint
	data << toX << toY << toZ;

#ifndef ENABLE_COMPRESSED_MOVEMENT_FOR_CREATURES
	bool self = GetUnit()->GetTypeId() == TYPEID_PLAYER;
	GetUnit()->SendMessageToSet( &data, self );
#else
	if( GetUnit()->GetTypeId() == TYPEID_PLAYER )
		TO_PLAYER(GetUnit())->GetSession()->SendPacket(&data);

	for(unordered_set<PlayerPointer  >::iterator itr = GetUnit()->GetInRangePlayerSetBegin(); itr != GetUnit()->GetInRangePlayerSetEnd(); ++itr)
	{
		if( (*itr)->GetPositionNC().Distance2DSq( GetUnit()->GetPosition() ) >= World::m_movementCompressThresholdCreatures )
			(*itr)->AppendMovementData( SMSG_MONSTER_MOVE, data.GetSize(), (const uint8*)data.GetBufferPointer() );
		else
			(*itr)->GetSession()->SendPacket(&data);
	}
#endif
}

void AIInterface::StopMovement(uint32 time)
{
	m_moveTimer = time; // set pause after stopping
	setCreatureState(STOPPED);

	m_destinationX = m_destinationY = m_destinationZ = 0;
	m_nextPosX = m_nextPosY = m_nextPosZ = 0;
	m_timeMoved = 0;
	m_timeToMove = 0;

	SendMoveToPacket(GetUnit()->GetPositionX(), GetUnit()->GetPositionY(), GetUnit()->GetPositionZ(), GetUnit()->GetOrientation(), 0, getMoveFlags());
}

void AIInterface::MoveTo(float x, float y, float z, float o)
{
	m_sourceX = GetUnit()->GetPositionX();
	m_sourceY = GetUnit()->GetPositionY();
	m_sourceZ = GetUnit()->GetPositionZ();

	if(!m_canMove || GetUnit()->IsStunned()|| GetUnit()->isCasting())
	{
		StopMovement(0); // Just Stop
		return;
	}

	m_nextPosX = x;
	m_nextPosY = y;
	m_nextPosZ = z;

	if(m_creatureState != MOVING)
		UpdateMove();
}

bool AIInterface::IsFlying()
{
	if(m_moveFly)
		return true;
	
	if( GetUnit()->GetTypeId() == TYPEID_PLAYER )
		return TO_PLAYER( GetUnit() )->FlyCheat;

	return false;
}

uint32 AIInterface::getMoveFlags()
{
	uint32 MoveFlags = MONSTER_MOVE_FLAG_RUN;
	if(m_moveFly == true)           // Fly
	{
		m_flySpeed = GetUnit()->m_flySpeed*0.001f;
		MoveFlags = MONSTER_MOVE_FLAG_FLY;
	}
	else if(m_moveSprint == true)  // Sprint
	{
		m_runSpeed = (GetUnit()->m_runSpeed+5.0f)*0.001f;
	}
	else if(m_moveRun == true)     // Run
	{
		m_runSpeed = GetUnit()->m_runSpeed*0.001f;
	}
	m_walkSpeed = GetUnit()->m_walkSpeed*0.001f; // move distance per ms time 
	return MoveFlags;
}

void AIInterface::UpdateMove()
{
	// this should NEVER be called directly.
	// use MoveTo()
	float distance = GetUnit()->CalcDistance(m_nextPosX,m_nextPosY,m_nextPosZ);
	

	m_destinationX = m_nextPosX;
	m_destinationY = m_nextPosY;
	m_destinationZ = m_nextPosZ;
	
	m_nextPosX = m_nextPosY = m_nextPosZ = 0;

	uint32 moveTime = 0;
	if(m_moveFly)
		moveTime = (uint32)(distance/m_flySpeed);
	else if(m_moveRun)
		moveTime = (uint32)(distance/m_runSpeed);
	else
		moveTime = (uint32)(distance/m_walkSpeed);

	m_totalMoveTime = moveTime;

	if(GetUnit()->GetTypeId() == TYPEID_UNIT)
	{
		CreaturePointer creature = TO_CREATURE(GetUnit());

		float angle = 0.0f;
		float c_reach =GetUnit()->GetFloatValue(UNIT_FIELD_COMBATREACH);

		// We don't want little movements here and there; 
		float DISTANCE_TO_SMALL_TO_WALK = c_reach - 1.0f <= 0.0f ? 1.0f : c_reach - 1.0f;

		// don't move if we're well within combat range; rooted can't move neither
		if( distance < DISTANCE_TO_SMALL_TO_WALK || (creature->proto && creature->proto->CanMove == LIMIT_ROOT ) )
			return; 

		// check if we're returning to our respawn location. if so, reset back to default orientation.
		if(creature->GetSpawnX() == m_destinationX && creature->GetSpawnY() == m_destinationY)
		{
			angle = GetUnit()->GetOrientation();
			creature->SetOrientation(angle);
		}
		else
		{
			// Calculate the angle to our next position

			float dx = (float)m_destinationX - GetUnit()->GetPositionX();
			float dy = (float)m_destinationY - GetUnit()->GetPositionY();
			if(dy != 0.0f)
			{
				angle = atan2(dy, dx);
				GetUnit()->SetOrientation(angle);
			}
		}
	}
	SendMoveToPacket(m_destinationX, m_destinationY, m_destinationZ, GetUnit()->GetOrientation(), moveTime + UNIT_MOVEMENT_INTERPOLATE_INTERVAL, getMoveFlags());

	m_timeToMove = moveTime;
	m_timeMoved = 0;
	if(m_moveTimer == 0)
		m_moveTimer =  UNIT_MOVEMENT_INTERPOLATE_INTERVAL; // update every few msecs

	setCreatureState(MOVING);
}

void AIInterface::SendCurrentMove(PlayerPointer plyr/*uint64 guid*/)
{
	if(m_destinationX == 0.0f && m_destinationY == 0.0f && m_destinationZ == 0.0f) return; // invalid move 

	uint32 numpoints = 4;
	float pointDiffX = m_sourceX - m_destinationX / (float)numpoints;
	float pointDiffY = m_sourceY - m_destinationY / (float)numpoints;
	float pointDiffZ = m_sourceZ - m_destinationZ / (float)numpoints;

	if(pointDiffX < 1.0f || pointDiffY < 1.0f)
	{
		SendMoveToPacket(m_destinationX, m_destinationY, m_destinationZ, 0.0f, 0, getMoveFlags());
		return;
	}

	ByteBuffer *splineBuf = new ByteBuffer(34*4);
	uint32 flags = 0;
	*splineBuf << uint32(flags);                                        // spline flags

	*splineBuf << uint32(0); // dont know if this is an uint32 but client seems to be trying to read 4 - 24 + 8 + 4
	*splineBuf << uint32((m_totalMoveTime - m_timeToMove)+m_moveTimer); //Time Passed (start Position) //should be generated/save 
	*splineBuf << uint32(m_totalMoveTime); // Total Time // should be generated/save
	*splineBuf << m_sourceX << m_sourceY << m_sourceZ;
	*splineBuf << uint32(0);
 
	*splineBuf << uint32(numpoints); //Spline Count	// lets try this

	for(uint8 i = 0 ; i < numpoints; i++)
	{
		*splineBuf << m_sourceX + (pointDiffX * i);
		*splineBuf << m_sourceY + (pointDiffY * i);
		*splineBuf << m_sourceZ + (pointDiffZ * i);
	}
	/*

	*splineBuf << m_sourceX << m_sourceY << m_sourceZ;
	*splineBuf << GetUnit()->GetPositionX() << GetUnit()->GetPositionY() << GetUnit()->GetPositionZ();
	*splineBuf << m_destinationX << m_destinationY << m_destinationZ;
	*splineBuf << m_destinationX << m_destinationY << m_destinationZ;
	*/
	*splineBuf << uint8(0); // Pguid?

	*splineBuf << m_destinationX << m_destinationY << m_destinationZ;	// 3 floats after all the spline points

	plyr->AddSplinePacket(GetUnit()->GetGUID(), splineBuf);

}

bool AIInterface::setInFront(UnitPointer target) // not the best way to do it, though
{
	// angle the object has to face
	float angle = GetUnit()->calcAngle(GetUnit()->GetPositionX(), GetUnit()->GetPositionY(), target->GetPositionX(), target->GetPositionY() ); 
	// Change angle slowly 2000ms to turn 180 deg around
	if(angle > 180) angle += 90;
	else angle -= 90; //angle < 180
	GetUnit()->getEasyAngle(angle);
	// Convert from degrees to radians (180 deg = PI rad)
	float orientation = angle / float(180 / M_PI);
	// Update Orentation Server Side
	GetUnit()->SetPosition(GetUnit()->GetPositionX(), GetUnit()->GetPositionY(), GetUnit()->GetPositionZ(), orientation);
	
	return GetUnit()->isInFront(target);
}

bool AIInterface::addWayPoint(WayPoint* wp)
{
	if(!hasWaypoints())
		m_waypoints = new WayPointMap ;
	if(!wp) 
		return false;
	if(wp->id <= 0)
		return false; // not valid id

	if(m_waypoints->size() < wp->id)
		m_waypoints->resize(wp->id);

	if((*m_waypoints)[wp->id-1] == NULL)
	{
		(*m_waypoints)[wp->id-1] = wp;
		return true;
	}
	return false;
}

void AIInterface::changeWayPointID(uint32 oldwpid, uint32 newwpid)
{
	if(!hasWaypoints())return;
	if(newwpid <= 0) 
		return; // not valid id
	if(newwpid > m_waypoints->size()) 
		return; // not valid id
	if(oldwpid > m_waypoints->size())
		return;

	if(newwpid == oldwpid) 
		return; // same spot

	// already wp with that id ?
	WayPoint* originalwp = getWayPoint(newwpid);
	if(!originalwp) 
		return;
	WayPoint* oldwp = getWayPoint(oldwpid);
	if(!oldwp) 
		return;

	oldwp->id = newwpid;
	originalwp->id = oldwpid;
	(*m_waypoints)[oldwp->id-1] = oldwp;
	(*m_waypoints)[originalwp->id-1] = originalwp;

	// SaveAll to db
	saveWayPoints();
}

void AIInterface::deleteWayPoint(uint32 wpid)
{
	if(!hasWaypoints())return;
	if(wpid <= 0) 
		return; // not valid id
	if(wpid > m_waypoints->size()) 
		return; // not valid id

	WayPointMap new_waypoints;
	uint32 newpid = 1;
	for(WayPointMap::iterator itr = m_waypoints->begin(); itr != m_waypoints->end(); ++itr)
	{
		if((*itr) == NULL || (*itr)->id == wpid)
		{
			if((*itr) != NULL)
				delete ((*itr));

			continue;
		}

		new_waypoints.push_back(*itr);
	}

	m_waypoints->clear();
	m_waypoints->push_back(NULL); // waypoint 0
	for(WayPointMap::iterator itr = new_waypoints.begin(); itr != new_waypoints.end(); ++itr)
	{
		(*itr)->id = newpid++;
		m_waypoints->push_back(*itr);
	}

	saveWayPoints();
}

bool AIInterface::showWayPoints(PlayerPointer pPlayer, bool Backwards)
{
	if(!hasWaypoints())
		return false;

	// wpid of 0 == all
	WayPointMap::const_iterator itr;
	if(m_WayPointsShowing == true) 
		return false;

	m_WayPointsShowing = true;

	WayPoint* wp = NULL;
	for (itr = m_waypoints->begin(); itr != m_waypoints->end(); itr++)
	{
		if( (*itr) != NULL )
		{
			wp = *itr;

			// Create
			CreaturePointer pWayPoint(new Creature((uint64)HIGHGUID_TYPE_WAYPOINT << 32 | wp->id));
			pWayPoint->Init();
			pWayPoint->CreateWayPoint(wp->id,pPlayer->GetMapId(),wp->x,wp->y,wp->z,0);
			pWayPoint->SetUInt32Value(OBJECT_FIELD_ENTRY, 300000);
			pWayPoint->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
			if(Backwards)
			{
				uint32 DisplayID = (wp->backwardskinid == 0)? GetUnit()->GetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID) : wp->backwardskinid;
				pWayPoint->SetUInt32Value(UNIT_FIELD_DISPLAYID, DisplayID);
				pWayPoint->SetUInt32Value(UNIT_NPC_EMOTESTATE, wp->backwardemoteid);
				pWayPoint->SetStandState(wp->backwardStandState);
			}
			else
			{
				uint32 DisplayID = (wp->forwardskinid == 0)? GetUnit()->GetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID) : wp->forwardskinid;
				pWayPoint->SetUInt32Value(UNIT_FIELD_DISPLAYID, DisplayID);
				pWayPoint->SetUInt32Value(UNIT_NPC_EMOTESTATE, wp->forwardemoteid);
				pWayPoint->SetStandState(wp->forwardStandState);
			}
			pWayPoint->SetUInt32Value(UNIT_FIELD_LEVEL, wp->id);
			pWayPoint->SetUInt32Value(UNIT_NPC_FLAGS, 0);
			pWayPoint->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE , pPlayer->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE));
			pWayPoint->SetUInt32Value(UNIT_FIELD_HEALTH, 1);
			pWayPoint->SetUInt32Value(UNIT_FIELD_MAXHEALTH, 1);
			pWayPoint->SetUInt32Value(UNIT_FIELD_STAT0, wp->flags);

			// Create on client
			ByteBuffer buf(2500);
			uint32 count = pWayPoint->BuildCreateUpdateBlockForPlayer(&buf, pPlayer);
			pPlayer->PushCreationData(&buf, count);

			// root the object
			WorldPacket data1;
			data1.Initialize(SMSG_FORCE_MOVE_ROOT);
			data1 << pWayPoint->GetNewGUID();
			pPlayer->GetSession()->SendPacket( &data1 );

			// Cleanup
			pWayPoint->Destructor();
			pWayPoint = NULLCREATURE;
		}
	}
	return true;
}

bool AIInterface::hideWayPoints(PlayerPointer pPlayer)
{
	if(!hasWaypoints())
		return false;

	// wpid of 0 == all
	if(m_WayPointsShowing != true) return false;
	m_WayPointsShowing = false;
	WayPointMap::const_iterator itr;

	// slightly better way to do this
	uint64 guid;

	for (itr = m_waypoints->begin(); itr != m_waypoints->end(); itr++)
	{
		if( (*itr) != NULL )
		{
			// avoid C4293
			guid = ((uint64)HIGHGUID_TYPE_WAYPOINT << 32) | (*itr)->id;
			WoWGuid wowguid(guid);
			pPlayer->PushOutOfRange(wowguid);
		}
	}
	return true;
}

bool AIInterface::saveWayPoints()
{
	if(!hasWaypoints())return false;

	if(!GetUnit()) return false;
	if(GetUnit()->GetTypeId() != TYPEID_UNIT ||
		TO_CREATURE(GetUnit())->m_spawn == NULL ) return false;

	WorldDatabase.Execute("DELETE FROM creature_waypoints WHERE spawnid = %u", TO_CREATURE(GetUnit())->GetSQL_id());
	WayPointMap::const_iterator itr;
	WayPoint* wp = NULL;
	std::stringstream ss;

	for (itr = m_waypoints->begin(); itr != m_waypoints->end();)
	{
		wp = (*itr);
		itr++;
		// Save
		ss.str("");
		ss << "REPLACE INTO creature_waypoints ";
		ss << "(spawnid,waypointid,position_x,position_y,position_z,orientation,waittime,flags,forwardemoteoneshot,forwardemoteid,backwardemoteoneshot,backwardemoteid,forwardskinid,backwardskinid,forwardStandState,backwardStandState,forwardSpellToCast,backwardSpellToCast,forwardSayText,backwardSayText) VALUES (";
		ss << TO_CREATURE(GetUnit())->GetSQL_id() << ", ";
		ss << wp->id << ", ";
		ss << wp->x << ", ";
		ss << wp->y << ", ";
		ss << wp->z << ", ";
		ss << wp->o << ", ";
		ss << wp->waittime << ", ";
		ss << wp->flags << ", ";
		ss << wp->forwardemoteoneshot << ", ";
		ss << wp->forwardemoteid << ", ";
		ss << wp->backwardemoteoneshot << ", ";
		ss << wp->backwardemoteid << ", ";
		ss << wp->forwardskinid << ", ";
		ss << wp->backwardskinid << ", ";
		ss << wp->forwardStandState << ", ";
		ss << wp->backwardStandState << ", ";
		ss << wp->forwardSpellToCast << ", ";
		ss << wp->backwardSpellToCast << ",'";
		ss << WorldDatabase.EscapeString(wp->forwardSayText) << "','";
		ss << WorldDatabase.EscapeString(wp->backwardSayText) << "')\0";
		WorldDatabase.Query( ss.str().c_str() );
	}
	return true;
}

void AIInterface::deleteWaypoints()
{
	if(!hasWaypoints())
		return;

	for(WayPointMap::iterator itr = m_waypoints->begin(); itr != m_waypoints->end(); ++itr)
	{
		if((*itr) != NULL)
			delete (*itr);
	}
	m_waypoints->clear();
}

WayPoint* AIInterface::getWayPoint(uint32 wpid)
{
	if(!hasWaypoints())
		return NULL;

	// make sure wpid is valid, return 1st/last if out of boundaries.
	wpid = ( wpid > m_waypoints->size() ? m_waypoints->size() : ( !wpid?  1 : wpid ));

	return m_waypoints->at(wpid-1);
}

void AIInterface::_UpdateMovement(uint32 p_time)
{
	if(!GetUnit()->isAlive())
	{
		StopMovement(0);
		return;
	}

	uint32 timediff = 0;

	if(m_moveTimer > 0)
	{
		if(p_time >= m_moveTimer)
		{
			timediff = p_time - m_moveTimer;
			m_moveTimer = 0;
		}
		else
			m_moveTimer -= p_time;
	}

	if(m_timeToMove > 0)
	{
		m_timeMoved = m_timeToMove <= p_time + m_timeMoved ? m_timeToMove : p_time + m_timeMoved;
	}

	if(m_creatureState == MOVING)
	{
		if(!m_moveTimer)
		{
			if(m_timeMoved == m_timeToMove) // reached destination
			{

				if(getMoveType() == MOVEMENTTYPE_WANTEDWP)   // We reached wanted wp stop now
					setMoveType(MOVEMENTTYPE_DONTMOVEWP);

				float wayO = 0.0f;

				if((GetWayPointsCount() != 0) && (getAIState() == STATE_IDLE || getAIState() == STATE_SCRIPTMOVE)) // if we attacking don't use wps
				{
					WayPoint* wp = getWayPoint(getCurrentWaypoint());
					if(wp)
					{
						CALL_SCRIPT_EVENT(GetUnit(), OnReachWP)(wp->id, !m_moveBackward);
						if(TO_CREATURE(GetUnit())->has_waypoint_text)
							objmgr.HandleMonsterSayEvent(TO_CREATURE(GetUnit()), MONSTER_SAY_EVENT_RANDOM_WAYPOINT);

						// Lets face to correct orientation
						wayO = wp->o;
						m_moveTimer = wp->waittime; // wait before next move
						if(!m_moveBackward)
						{
							if(wp->forwardemoteoneshot)
							{
								GetUnit()->Emote(EmoteType(wp->forwardemoteid));
							}
							else
							{
								if(GetUnit()->GetUInt32Value(UNIT_NPC_EMOTESTATE) != wp->forwardemoteid)
								{
									GetUnit()->SetUInt32Value(UNIT_NPC_EMOTESTATE, wp->forwardemoteid);
								}
							}
							if(GetUnit()->getStandState() != wp->forwardStandState )
								GetUnit()->SetStandState(wp->forwardStandState);
							if (wp->forwardSpellToCast)
								GetUnit()->CastSpell(GetUnit(),wp->forwardSpellToCast,false);
							if (wp->forwardSayText != "")
								GetUnit()->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, wp->forwardSayText.c_str() );
						}
						else
						{
							if(wp->backwardemoteoneshot)
							{
								GetUnit()->Emote(EmoteType(wp->backwardemoteid));
							}
							else
							{
								if(GetUnit()->GetUInt32Value(UNIT_NPC_EMOTESTATE) != wp->backwardemoteid)
								{
									GetUnit()->SetUInt32Value(UNIT_NPC_EMOTESTATE, wp->backwardemoteid);
								}
							}
							if(GetUnit()->getStandState() != wp->backwardStandState )
								GetUnit()->SetStandState(wp->backwardStandState);
							if (wp->backwardSpellToCast)
								GetUnit()->CastSpell(GetUnit(),wp->backwardSpellToCast,false);
							if (wp->backwardSayText != "")
								GetUnit()->SendChatMessage(CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, wp->backwardSayText.c_str() );
						}
					}
					else
						m_moveTimer = RandomUInt(m_moveRun ? 5000 : 10000); // wait before next move
				}

				setCreatureState(STOPPED);
				m_moveSprint = false;

				if(m_MovementType == MOVEMENTTYPE_DONTMOVEWP)
					GetUnit()->SetPosition(m_destinationX, m_destinationY, m_destinationZ, wayO, true);
				else
					GetUnit()->SetPosition(m_destinationX, m_destinationY, m_destinationZ, GetUnit()->GetOrientation(), true);

				m_destinationX = m_destinationY = m_destinationZ = 0;
				m_timeMoved = 0;
				m_timeToMove = 0;
			}
			else
			{
				// Move Server Side Update
				float q = (float)m_timeMoved / (float)m_timeToMove;
				float x = GetUnit()->GetPositionX() + (m_destinationX - GetUnit()->GetPositionX()) * q;
				float y = GetUnit()->GetPositionY() + (m_destinationY - GetUnit()->GetPositionY()) * q;
				float z = GetUnit()->GetPositionZ() + (m_destinationZ - GetUnit()->GetPositionZ()) * q;
				

				GetUnit()->SetPosition(x, y, z, GetUnit()->GetOrientation());
				
				m_timeToMove -= m_timeMoved;
				m_timeMoved = 0;
				m_moveTimer = (UNIT_MOVEMENT_INTERPOLATE_INTERVAL < m_timeToMove) ? UNIT_MOVEMENT_INTERPOLATE_INTERVAL : m_timeToMove;
			}

			if(m_nextPosX != 0.0f && m_nextPosY != 0.0f)
			{
				UpdateMove();
			}
		}
	}
	else if(m_creatureState == STOPPED && (getAIState() == STATE_IDLE || getAIState() == STATE_SCRIPTMOVE) && !m_moveTimer && !m_timeToMove && getUnitToFollow() == NULL) //creature is stopped and out of Combat
	{
		if(sWorld.getAllowMovement() == false)                    // is creature movement enabled?
			return;

		if(GetUnit()->GetUInt32Value(UNIT_FIELD_DISPLAYID) == 5233)  // if Spirit Healer don't move
			return;

		// do we have a formation?
		if(m_formationLinkSqlId != 0)
		{
			if( m_formationLinkTarget == NULL)
			{
				// haven't found our target yet
				CreaturePointer c = TO_CREATURE(GetUnit());
				if(!c->haslinkupevent)
				{
					// register linkup event
					c->haslinkupevent = true;
					sEventMgr.AddEvent(c, &Creature::FormationLinkUp, m_formationLinkSqlId, 
						EVENT_CREATURE_FORMATION_LINKUP, 1000, 0,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
				}
			}
			else
			{
				// we've got a formation target, set unittofollow to this
				SetUnitToFollow(m_formationLinkTarget);
				SetFollowDistance(m_formationFollowDistance);
				SetUnitToFollowAngle(m_formationFollowAngle);
			}
		}
		if(getUnitToFollow() == NULL)
		{
			// no formation, use waypoints
			int destpoint = -1;

			//BLooD_LorD:Added this stuff code. :)
			if(GetWayPointsCount()==0 && GetUnit()->HasFlag(UNIT_NPC_FLAGS, NULL) && !GetUnit()->GetInstanceID()) // no waypoints
			{
			if ((GetUnit() && GetUnit()->GetMapMgr() && GetUnit()->GetMapMgr()->IsCollisionEnabled()) && sWorld.Collision)
			{
				float ang = rand()/100.0f;
				float ran = (rand()%(RADIUS*10))/10.0f;
				while(ran<1)
				{
				ran = (rand()%(RADIUS*10))/10.0f;
				}
				float x = GetUnit()->GetSpawnX()+ran*sin(ang);
				float y = GetUnit()->GetSpawnY()+ran*cos(ang);
				float z = GetUnit()->GetMapMgr()->GetBaseMap()->GetLandHeight(x,y);

				if ( CollideInterface.CheckLOS(GetUnit()->GetMapId(),GetUnit()->GetPositionX(),GetUnit()->GetPositionY(),GetUnit()->GetPositionZ(),x,y,z) )
				{
				m_moveTimer = (UPDATETIME);
				GetUnit()->GetAIInterface()->MoveTo(x, y, z, 0);
				}
 				else
 				{
				m_timeToMove = 2000;
 				}
			}
			}																																						  
			else // we do have waypoints
			{
				uint32 wpcount = uint32(GetWayPointsCount());
				if(getMoveType() == MOVEMENTTYPE_RANDOMWP) // is random move on if so move to a random waypoint
				{
					if(wpcount > 1)
						destpoint = RandomUInt(wpcount-1)+1;
				}
				else if (getMoveType() == MOVEMENTTYPE_CIRCLEWP) // random move is not on lets follow the path in circles
				{
					// 1 -> 10 then 1 -> 10
					m_currentWaypoint++;
					if (getCurrentWaypoint() > wpcount) 
						setWaypointToMove(1); // Happens when you delete last wp seems to continue ticking
					destpoint = getCurrentWaypoint();
					m_moveBackward = false;
				}
				else if(getMoveType() == MOVEMENTTYPE_WANTEDWP) // Move to wanted wp
				{
					if(getCurrentWaypoint())
					{
						if( wpcount > 0)
						{
							destpoint = getCurrentWaypoint();
						}
						else
							destpoint = -1;
					}
				}
				else if(getMoveType() == MOVEMENTTYPE_FORWARDTHANSTOP) // move to end, then stop
				{
					++m_currentWaypoint;
					if(getCurrentWaypoint() > wpcount)
					{
						// hmm maybe we should stop being path walker since we are waiting here anyway
						destpoint = -1;
					}
					else
						destpoint = getCurrentWaypoint();
				}
				else if(getMoveType() != MOVEMENTTYPE_QUEST && getMoveType() != MOVEMENTTYPE_DONTMOVEWP) // 4 Unused
				{
					// 1 -> 10 then 10 -> 1
					if (getCurrentWaypoint() > wpcount)
						setWaypointToMove(1);        // Happens when you delete last wp seems to continue ticking
					if (getCurrentWaypoint() == wpcount) // Are we on the last waypoint? if so walk back
						m_moveBackward = true;
					if (getCurrentWaypoint() == 1)       // Are we on the first waypoint? if so lets goto the second waypoint
						m_moveBackward = false;
					if (!m_moveBackward)              // going 1..n
						destpoint = ++m_currentWaypoint;
					else				              // going n..1
						destpoint = --m_currentWaypoint;
				}

				if(destpoint != -1)
				{
					WayPoint* wp = getWayPoint(destpoint);
					if(wp)
					{
						if(!m_moveBackward)
						{
							if((wp->forwardskinid != 0) && (GetUnit()->GetUInt32Value(UNIT_FIELD_DISPLAYID) != wp->forwardskinid))
							{
								GetUnit()->SetUInt32Value(UNIT_FIELD_DISPLAYID, wp->forwardskinid);
							}
						}
						else
						{
							if((wp->backwardskinid != 0) && (GetUnit()->GetUInt32Value(UNIT_FIELD_DISPLAYID) != wp->backwardskinid))
							{
								GetUnit()->SetUInt32Value(UNIT_FIELD_DISPLAYID, wp->backwardskinid);
							}
						}
						m_moveFly = (wp->flags == 768) ? 1 : 0;
						m_moveRun = (wp->flags == 256) ? 1 : 0;
						MoveTo(wp->x, wp->y, wp->z, 0);
					}
				}
			}
		}
	}

	// Fear Code
	if(getAIState() == STATE_FEAR && UnitToFear != NULL && m_creatureState == STOPPED)
	{
		if(getMSTime() > m_FearTimer)   // Wait at point for x ms ;)
		{
			float Fx;
			float Fy;
			float Fz;
			// Calculate new angle to target.
			float Fo = GetUnit()->calcRadAngle(UnitToFear->GetPositionX(), UnitToFear->GetPositionY(), GetUnit()->GetPositionX(), GetUnit()->GetPositionY());
			double fAngleAdd = RandomDouble(((M_PI/2) * 2)) - (M_PI/2);
			Fo += (float)fAngleAdd;
			
			float dist = GetUnit()->CalcDistance(UnitToFear);
			if(dist > 30.0f || (Rand(25) && dist > 10.0f))	// not too far or too close
			{
				Fx = GetUnit()->GetPositionX() - (RandomFloat(15.f)+5.0f)*cosf(Fo);
				Fy = GetUnit()->GetPositionY() - (RandomFloat(15.f)+5.0f)*sinf(Fo);
			}
			else
			{
				Fx = GetUnit()->GetPositionX() + (RandomFloat(20.f)+5.0f)*cosf(Fo);
				Fy = GetUnit()->GetPositionY() + (RandomFloat(20.f)+5.0f)*sinf(Fo);
			}
			// Check if this point is in water.
			float wl = GetUnit()->GetMapMgr()->GetWaterHeight(Fx, Fy);
            // uint8 wt = GetUnit()->GetMapMgr()->GetWaterType(Fx, Fy);

			if (GetUnit()->GetMapMgr() && GetUnit()->GetMapMgr()->IsCollisionEnabled())
			{
				if( !CollideInterface.GetFirstPoint( GetUnit()->GetMapId(), GetUnit()->GetPositionX(), GetUnit()->GetPositionY(), GetUnit()->GetPositionZ(), 
					Fx, Fy, GetUnit()->GetPositionZ() + 1.5f, Fx, Fy, Fz, -3.5f ) )
				{
					// clear path?
					Fz = CollideInterface.GetHeight( GetUnit()->GetMapId(), Fx, Fy, GetUnit()->GetPositionZ() );
					if( Fz == NO_WMO_HEIGHT )
						Fz = GetUnit()->GetMapMgr()->GetLandHeight(Fx, Fy);
				}
				else
				{
					// obstruction in the way.
					// the distmod will fuck up the Z, so get a new height.
					float fz2 = CollideInterface.GetHeight(GetUnit()->GetMapId(), Fx, Fy, Fz);
					if( fz2 != NO_WMO_HEIGHT )
						Fz = fz2;
				}

				if( fabs( GetUnit()->GetPositionZ() - Fz ) > 3.5f || ( wl != 0.0f && Fz < wl ) )		// in water
				{
					m_FearTimer=getMSTime() + 500;
				}
				else
				{
					MoveTo(Fx, Fy, Fz, Fo);
					m_FearTimer = m_totalMoveTime + getMSTime() + 400;
				}
			}
			else
			{
				Fz = GetUnit()->GetMapMgr()->GetLandHeight(Fx, Fy);
				if(fabs(GetUnit()->GetPositionZ()-Fz) > 4 || (Fz != 0.0f && Fz < (wl-2.0f)))
					m_FearTimer=getMSTime()+100;
				else
				{
					MoveTo(Fx, Fy, Fz, Fo);
					m_FearTimer = m_totalMoveTime + getMSTime() + 200;
				}
			}
		}
	}

	// Wander AI movement code
	if(getAIState() == STATE_WANDER && m_creatureState == STOPPED)
	{
		if(getMSTime() < m_WanderTimer) // is it time to move again?
			return;

		// calculate a random distance and angle to move
		float wanderD = RandomFloat(2.0f) + 2.0f;
		float wanderO = RandomFloat(6.283f);
		float Fx = GetUnit()->GetPositionX() + wanderD * cosf(wanderO);
		float Fy = GetUnit()->GetPositionY() + wanderD * sinf(wanderO);
		float Fz;

		if (GetUnit()->GetMapMgr() && GetUnit()->GetMapMgr()->IsCollisionEnabled())
		{
			if( !CollideInterface.GetFirstPoint( GetUnit()->GetMapId(), GetUnit()->GetPositionX(), GetUnit()->GetPositionY(), GetUnit()->GetPositionZ(), 
				Fx, Fy, GetUnit()->GetPositionZ() + 1.5f, Fx, Fy, Fz, -3.5f ) )
			{
				// clear path?
				Fz = CollideInterface.GetHeight( GetUnit()->GetMapId(), Fx, Fy, GetUnit()->GetPositionZ() );
				if( Fz == NO_WMO_HEIGHT )
					Fz = GetUnit()->GetMapMgr()->GetLandHeight(Fx, Fy);
			}
			else
			{
				// obstruction in the way.
				// the distmod will fuck up the Z, so get a new height.
				float fz2 = CollideInterface.GetHeight(GetUnit()->GetMapId(), Fx, Fy, Fz);
				if( fz2 != NO_WMO_HEIGHT )
					Fz = fz2;
			}

			if( fabs( GetUnit()->GetPositionZ() - Fz ) > 3.5f )
			{
				m_WanderTimer=getMSTime() + 1000;
			}
			else
			{
				GetUnit()->SetOrientation(wanderO);
				MoveTo(Fx, Fy, Fz, wanderO);
				m_WanderTimer = getMSTime() + m_totalMoveTime + 300; // time till next move (+ pause)
			}
		}
		else
		{
			Fz = GetUnit()->GetMapMgr()->GetLandHeight(Fx, Fy);

			// without these next checks we could fall through the "ground" (WMO) and get stuck
			// wander won't work correctly in cities until we get some way to fix this and remove these checks
			float currentZ = GetUnit()->GetPositionZ();
			float landZ = GetUnit()->GetMapMgr()->GetLandHeight(GetUnit()->GetPositionX(), GetUnit()->GetPositionY());

			if( currentZ > landZ + 1.0f  // are we more than 1yd above ground? (possible WMO)
			 || Fz < currentZ - 5.0f     // is our destination land height too low? (possible WMO)
			 || Fz > currentZ + wanderD) // is our destination too high to climb?
			{
				m_WanderTimer = getMSTime() + 1000; // wait 1 second before we try again
				return;
			}

			GetUnit()->SetOrientation(wanderO);
			MoveTo(Fx, Fy, Fz, wanderO);
			m_WanderTimer = getMSTime() + m_totalMoveTime + 300; // time till next move (+ pause)
		}
	}

	// Unit Follow Code
	if(getUnitToFollow() != NULL)
	{
		if( getUnitToFollow()->event_GetCurrentInstanceId() != GetUnit()->event_GetCurrentInstanceId() || !getUnitToFollow()->IsInWorld() )
			SetUnitToFollow(NULLUNIT);
		else
		{
			if(getAIState() == STATE_IDLE || getAIState() == STATE_FOLLOWING)
			{
				float dist = GetUnit()->GetDistanceSq(getUnitToFollow());

				// re-calculate orientation based on target's movement
				if(m_lastFollowX != getUnitToFollow()->GetPositionX() ||
					m_lastFollowY != getUnitToFollow()->GetPositionY())
				{
					float dx = getUnitToFollow()->GetPositionX() - GetUnit()->GetPositionX();
					float dy = getUnitToFollow()->GetPositionY() - GetUnit()->GetPositionY();
					if(dy != 0.0f)
					{
						float angle = atan2(dx,dy);
						GetUnit()->SetOrientation(angle);
					}
					m_lastFollowX = getUnitToFollow()->GetPositionX();
					m_lastFollowY = getUnitToFollow()->GetPositionY();
				}

				if (dist > (FollowDistance*FollowDistance)) // if out of range
				{
					SetAIState(STATE_FOLLOWING);
						
					if(dist > 25.0f) // 25 yard away lets run else we will loose the them
						m_moveRun = true;
					else 
						m_moveRun = false;

					if(getAIType() == AITYPE_PET || getUnitToFollow() == m_formationLinkTarget) // Unit is Pet/formation
					{
						if(dist > 900.0f/*30*/)
							m_moveSprint = true;

						float delta_x = getUnitToFollow()->GetPositionX();
						float delta_y = getUnitToFollow()->GetPositionY();
						float d = 3;
						if(m_formationLinkTarget != NULL)
							d = m_formationFollowDistance;

						MoveTo(delta_x+(d*(cosf(m_fallowAngle+getUnitToFollow()->GetOrientation()))),
							delta_y+(d*(sinf(m_fallowAngle+getUnitToFollow()->GetOrientation()))),
							getUnitToFollow()->GetPositionZ(),getUnitToFollow()->GetOrientation());				
					}
					else
					{
						_CalcDestinationAndMove(getUnitToFollow(), FollowDistance);
					}
				}
			}
		}
	}
}

uint8 AIInterface::CastSpell(UnitPointer caster, SpellEntry *spellInfo, SpellCastTargets targets)
{
	if( getAIType() != AITYPE_PET && disable_spell )
		return SPELL_FAILED_ERROR;

	// only stop for spells with casting time
	uint32 delay = GetCastTime( dbcSpellCastTime.LookupEntry(spellInfo->CastingTimeIndex));
	if( delay )
		StopMovement( delay + 500);

	// Stop AI while casting.
	SetAIState(STATE_CASTING);

	SpellPointer nspell(new Spell(caster, spellInfo, false, NULLAURA));
	return nspell->prepare(&targets);
}

void AIInterface::CancelSpellCast()
{
	m_nextSpell = NULL;
	if( GetUnit() && GetUnit()->m_currentSpell)
		GetUnit()->m_currentSpell->cancel();
}

SpellEntry *AIInterface::getSpellEntry(uint32 spellId)
{
	SpellEntry *spellInfo = dbcSpell.LookupEntry(spellId );

	if(!spellInfo)
	{
		OUT_DEBUG(WORLDUNKNOWNSPAI, spellId);
		return NULL;
	}

	return spellInfo;
}

SpellCastTargets AIInterface::setSpellTargets(SpellEntry *spellInfo, UnitPointer target)
{
	SpellCastTargets targets;
	targets.m_unitTarget = target ? target->GetGUID() : 0;
	targets.m_itemTarget = 0;
	targets.m_srcX = 0;
	targets.m_srcY = 0;
	targets.m_srcZ = 0;
	targets.m_destX = 0;
	targets.m_destY = 0;
	targets.m_destZ = 0;

	if(m_nextSpell->spelltargetType == TTYPE_SINGLETARGET)
	{
		targets.m_targetMask = TARGET_FLAG_UNIT;
		targets.m_unitTarget = target->GetGUID();
	}
	else if(m_nextSpell->spelltargetType == TTYPE_SOURCE)
	{
		targets.m_targetMask = TARGET_FLAG_SOURCE_LOCATION;
		targets.m_srcX = GetUnit()->GetPositionX();
		targets.m_srcY = GetUnit()->GetPositionY();
		targets.m_srcZ = GetUnit()->GetPositionZ();
	}
	else if(m_nextSpell->spelltargetType == TTYPE_DESTINATION)
	{
		targets.m_targetMask = TARGET_FLAG_DEST_LOCATION;
		targets.m_destX = target->GetPositionX();
		targets.m_destY = target->GetPositionY();
		targets.m_destZ = target->GetPositionZ();
	}
	else if(m_nextSpell->spelltargetType == TTYPE_CASTER)
	{
		targets.m_targetMask = TARGET_FLAG_UNIT;
		targets.m_unitTarget = GetUnit()->GetGUID();
	}

	return targets;
}

AI_Spell *AIInterface::getSpell()
{
	// look at our spells
	AI_Spell *  sp = NULL;
	AI_Spell *  def_spell = NULL;
	uint32 cool_time = 0;
	uint32 nowtime = getMSTime();

	if( nowtime > next_spell_time )
	{
		if(GetUnit()->IsPet())
		{
			PetPointer pPet = TO_PET(GetUnit());
			def_spell = pPet->HandleAutoCastEvent();
		}
		else
		{
			// start searching the list for a suitable spell. 
			for(list<AI_Spell*>::iterator itr = m_spells.begin(); itr != m_spells.end(); ++itr)
			{
				sp = (*itr);

				// don't waste our time if we already have spell in priority
				if (def_spell && def_spell->spellType > sp->spellType)
					continue;

				// Wtf?? There should be only spells on the list
				if(sp->agent != AGENT_SPELL)
				{
					// Log.Warning("AI_Agent","Agent entry %u is loaded, but not valid",sp->agent); 
					continue;
				}

				// skip when max proccount reached.	
				if((sp->procCount && sp->procCounter >= sp->procCount ))
					continue;

				// skip when still cooling down.
				if(sp->cooldown && sp->cooldowntime > nowtime )
					continue;

				// skip if proc change not met.
				if(sp->procChance < 100 && !Rand(sp->procChance))
					continue;

				// checks by spell type
				switch (sp->spellType)
				{
				case STYPE_DEBUFF:
					{
						if (!GetNextTarget() || GetNextTarget()->HasActiveAura(sp->spell->Id))
							continue;
					}break;
				case STYPE_BUFF:
					{
						if (GetUnit()->HasActiveAura(sp->spell->Id))
							continue;
					}break;
				case STYPE_HEAL:
					{
						if (!FindHealTargetForSpell(sp))
							continue;
					}
				case STYPE_INTERRUPT:
					{
						if (!GetNextTarget() || !GetNextTarget()->isCasting())
							continue;
					}break;
				}
				// success
				def_spell = sp;
			}
		}

		// Lets update cooldown and return a spell.
		next_spell_time = nowtime + 500 + RandomUInt(1000);
		return def_spell;
	}

	return NULL;
}

void AIInterface::addSpellToList(AI_Spell *sp)
{
	if(sp->spell == NULL)
		return;

	if(sp->procCount || sp->cooldown)
	{
		AI_Spell*sp2 = new AI_Spell;
		memcpy(sp2, sp, sizeof(AI_Spell));
		sp2->procCounter=0;
		sp2->cooldowntime = getMSTime() + sp->cooldown;
		sp2->custom_pointer = true;
		m_spells.push_back(sp2);
	}
	else
		m_spells.push_back(sp);

	GetUnit()->m_SpellList.insert(sp->spell->Id); // add to list
}

uint32 AIInterface::getThreatByGUID(uint64 guid)
{
	UnitPointer obj = GetUnit()->GetMapMgr()->GetUnit(guid);
	if(obj)
		return getThreatByPtr(obj);

	return 0;
}

uint32 AIInterface::getThreatByPtr(UnitPointer obj)
{
	TargetMap::iterator it = m_aiTargets.find(obj);
	if(it != m_aiTargets.end())
	{
		return it->second;
	}
	return 0;
}

// should return a valid target
UnitPointer AIInterface::GetMostHated()
{
	UnitPointer ResultUnit=NULLUNIT;

	// override mosthated with taunted target. Basic combat checks are made for it. 
	// What happens if we can't see tauntedby unit ?
	ResultUnit = getTauntedBy();
	if(ResultUnit)
		return ResultUnit;

	pair< UnitPointer , int32> currentTarget;
	currentTarget.first = NULLUNIT;
	currentTarget.second = -1;

	TargetMap::iterator it2 = m_aiTargets.begin();
	TargetMap::iterator itr;
	for(; it2 != m_aiTargets.end();)
	{
		itr = it2;
		++it2;

		// check the target is valid.
		if(itr->first->event_GetCurrentInstanceId() != GetUnit()->event_GetCurrentInstanceId() || !itr->first->isAlive() || !isAttackable(GetUnit(), itr->first))
		{
			m_aiTargets.erase(itr);
			continue;
		}

		if((itr->second + itr->first->GetThreatModifier()) > currentTarget.second)
		{
			// new target.
			currentTarget.first = itr->first;
			currentTarget.second = itr->second + itr->first->GetThreatModifier();
			m_currentHighestThreat = currentTarget.second;
		}

		// there are no more checks needed here... the needed checks are done by CheckTarget().
	}

	return currentTarget.first;
}
UnitPointer AIInterface::GetSecondHated()
{
	UnitPointer ResultUnit=GetMostHated();

	pair< UnitPointer, int32> currentTarget;
	currentTarget.first = NULLUNIT;
	currentTarget.second = -1;

	TargetMap::iterator it2 = m_aiTargets.begin();
	TargetMap::iterator itr;
	for(; it2 != m_aiTargets.end();)
	{
		itr = it2;
		++it2;

		// check the target is valid.
		if(itr->first->GetInstanceID() != GetUnit()->GetInstanceID() || !itr->first->isAlive() || !isAttackable(GetUnit(), itr->first))
		{
			m_aiTargets.erase(itr);
			continue;
		}

		if((itr->second + itr->first->GetThreatModifier()) > currentTarget.second &&
			itr->first != ResultUnit)
		{
			// new target.
			currentTarget.first = itr->first;
			currentTarget.second = itr->second + itr->first->GetThreatModifier();
			m_currentHighestThreat = currentTarget.second;
		}
	}

	return currentTarget.first;
}
bool AIInterface::modThreatByGUID(uint64 guid, int32 mod)
{
	if (!m_aiTargets.size())
		return false;

	UnitPointer obj = GetUnit()->GetMapMgr()->GetUnit(guid);
	if(obj)
		return modThreatByPtr(obj, mod);

	return false;
}

bool AIInterface::modThreatByPtr(UnitPointer obj, int32 mod)
{
	if(!obj)
		return false;

	if( obj->mThreatRTarget && mod > 0)
	{
		int32 partmod = float2int32(mod * obj->mThreatRAmount);
		mod -= partmod;
		UnitPointer robj = obj->mThreatRTarget;
		if( partmod && robj && robj->isAlive() && obj->GetDistanceSq(robj) < 1600 )
		{
			TargetMap::iterator it = m_aiTargets.find(robj);
			if(it != m_aiTargets.end())
			{
				it->second += partmod;
				if((it->second + robj->GetThreatModifier()) > m_currentHighestThreat)
				{
					// new target.
					if(!isTaunted)
					{
						m_currentHighestThreat = it->second + robj->GetThreatModifier();
						SetNextTarget(robj);
					}
				}
			}
			else
			{
				m_aiTargets.insert( make_pair( robj, partmod ) );
				if((partmod + robj->GetThreatModifier()) > m_currentHighestThreat)
				{
					if(!isTaunted)
					{
						m_currentHighestThreat = partmod + robj->GetThreatModifier();
						SetNextTarget(robj);
					}
				}
			}
		}
	}

	TargetMap::iterator it = m_aiTargets.find(obj);
	if( it != m_aiTargets.end() )
	{
		it->second += mod;
		if( (it->second + obj->GetThreatModifier()) > m_currentHighestThreat )
		{
			// new target!
			if( !isTaunted )
			{
				m_currentHighestThreat = it->second + obj->GetThreatModifier();
				SetNextTarget(obj);
			}
		}
	}
	else
	{
		m_aiTargets.insert( make_pair( obj, mod ) );
		if( (mod + obj->GetThreatModifier()) > m_currentHighestThreat )
		{
			if( !isTaunted )
			{
				m_currentHighestThreat = mod + obj->GetThreatModifier();
				SetNextTarget(obj);
			}
		}
	}

	if(obj == GetNextTarget())
	{
		// check for a possible decrease in threat.
		if(mod < 0)
		{
			SetNextTarget(GetMostHated());
			// if there is no more new targets then we can walk back home ?
			if(!GetNextTarget())
				HandleEvent(EVENT_LEAVECOMBAT, GetUnit(), 0);
			SetNextTarget(GetNextTarget());
		}
	}
	return true;
}

void AIInterface::RemoveThreatByPtr(UnitPointer obj)
{
	if(!obj)
		return;

	TargetMap::iterator it = m_aiTargets.find(obj);
	if(it != m_aiTargets.end())
	{
		m_aiTargets.erase(it);
		// check if we are in combat and need a new target
		if(obj == m_nextTarget)
		{
			m_nextTarget = GetMostHated();
			// if there is no more new targets then we can walk back home ?
			if( !m_nextTarget )
				HandleEvent(EVENT_LEAVECOMBAT, GetUnit(), 0);
			else
				SetNextTarget(m_nextTarget);
		}
	}
}

void AIInterface::addAssistTargets(UnitPointer Friend)
{
	// stop adding stuff that gives errors on linux!
	GetAssistTargets().insert(Friend);
}

void AIInterface::WipeHateList()
{
	for(TargetMap::iterator itr = m_aiTargets.begin(); itr != m_aiTargets.end(); ++itr)
		itr->second = 0;
	m_currentHighestThreat = 0;
}
void AIInterface::ClearHateList() // without leaving combat
{
	for(TargetMap::iterator itr = m_aiTargets.begin(); itr != m_aiTargets.end(); ++itr)
		itr->second = 1;
	m_currentHighestThreat = 1;
}

void AIInterface::WipeTargetList()
{
	SetNextTarget(NULLUNIT);

	m_nextSpell = NULL;
	m_currentHighestThreat = 0;
	m_aiTargets.clear();
	GetUnit()->CombatStatus.Vanished();
}

bool AIInterface::taunt(UnitPointer caster, bool apply)
{
	if(apply)
	{
		// wowwiki says that we cannot owerride this spell
		if(GetIsTaunted())
			return false;

		if(!caster)
		{
			isTaunted = false;
			return false;
		}

		// check if we can attack taunter. Maybe it's a hack or a bug if we fail this test
		if(isHostile(GetUnit(), caster))
		{
			// check if we have to add him to our agro list
			// GetMostHated(); //update our most hated list/ Note that at this point we do not have a taunter yet. If we would have then this funtion will not give real mosthated
			int32 oldthreat = getThreatByPtr(caster);
			// make sure we rush the target anyway. Since we are not tauted yet, this will also set our target
			modThreatByPtr(caster,abs(m_currentHighestThreat-oldthreat)+1); //we need to be the most hated at this moment
            // SetNextTarget(caster);
		}
		isTaunted = true;
		tauntedBy = caster;
	}
	else
	{
		isTaunted = false;
		tauntedBy = NULLUNIT;
		// taunt is over, we should get a new target based on most hated list
		SetNextTarget(GetMostHated());
	}

	return true;
}

UnitPointer AIInterface::getTauntedBy()
{
	if(GetIsTaunted())
	{
		return tauntedBy;
	}
	else
	{
		return NULLUNIT;
	}
}

bool AIInterface::GetIsTaunted()
{
	if(isTaunted)
	{
		if(!tauntedBy || !tauntedBy->isAlive())
		{
			isTaunted = false;
			tauntedBy = NULLUNIT;
		}
	}
	return isTaunted;
}

void AIInterface::CheckTarget(UnitPointer target)
{
	if( target == NULL )
		return;

	if( target == getUnitToFollow() )		  // fix for crash here
	{
		SetUnitToFollow(NULLUNIT);
		m_lastFollowX = m_lastFollowY = 0;
		SetFollowDistance(0);
	}

	if( target == UnitToFollow_backup )
	{
		UnitToFollow_backup = NULLUNIT;
	}

	AssistTargetSet::iterator  itr = GetAssistTargets().find(target);
	if(itr != GetAssistTargets().end())
		GetAssistTargets().erase(itr);

	TargetMap::iterator it2 = m_aiTargets.find( target );
	if( it2 != m_aiTargets.end() || target == GetNextTarget() )
	{
		if(it2 != m_aiTargets.end())
		{
			m_aiTargets.erase(it2);
		}

		if (target == GetNextTarget())	 // no need to cast on these.. mem addresses are still the same
		{
			SetNextTarget(NULLUNIT);
			m_nextSpell = NULL;

			// find the one with the next highest threat
			GetMostHated();
		}
	}

	if( target->GetTypeId() == TYPEID_UNIT )
	{
		it2 = target->GetAIInterface()->m_aiTargets.find( GetUnit() );
		if( it2 != target->GetAIInterface()->m_aiTargets.end() )
			target->GetAIInterface()->m_aiTargets.erase( it2 );
        
		if( target->GetAIInterface()->GetNextTarget() == GetUnit() )
		{
			target->GetAIInterface()->SetNextTarget(NULLUNIT);
			target->GetAIInterface()->m_nextSpell = NULL;
			target->GetAIInterface()->GetMostHated();
		}

		if( target->GetAIInterface()->getUnitToFollow() == GetUnit() )
			target->GetAIInterface()->SetUnitToFollow(NULLUNIT);
	}

	if(target == UnitToFear)
		UnitToFear = NULLUNIT;

	if(tauntedBy == target)
		tauntedBy = NULLUNIT;
}

uint32 AIInterface::_CalcThreat(uint32 damage, SpellEntry * sp, UnitPointer Attacker)
{
	if (isSameFaction(GetUnit(),Attacker))
		return 0;

	int32 mod = 0;
	if( sp != NULL && sp->ThreatForSpell != 0 )
	{
		mod = sp->ThreatForSpell;
	}
	else
	{
		mod = damage;
	}

	if (sp != NULL && sp->SpellGroupType && Attacker)
	{
		SM_FIValue(Attacker->SM[SMT_THREAT_REDUCED][0],&mod,sp->SpellGroupType);
		SM_PIValue(Attacker->SM[SMT_THREAT_REDUCED][1],&mod,sp->SpellGroupType);
	}

	// modify mod by Affects
	mod += (mod * Attacker->GetGeneratedThreatModifier() / 100);

	return mod;
}

void AIInterface::WipeReferences()
{
	m_nextSpell = 0;
	m_currentHighestThreat = 0;
	m_aiTargets.clear();
	m_nextTarget = NULLUNIT;
	UnitToFear = NULLUNIT;
	SetUnitToFollow(NULLUNIT);
	tauntedBy = NULLUNIT;
}

void AIInterface::ResetProcCounts()
{
	for(list<AI_Spell*>::iterator itr = m_spells.begin(); itr != m_spells.end(); ++itr)
		if((*itr)->procCount)
			(*itr)->procCounter=0;
}

// we only cast once a spell and we will set his health and resistances. Note that this can be made with db too !
void AIInterface::Event_Summon_EE_totem(uint32 summon_duration)
{
	m_totemspelltimer = 0xEFFFFFFF;
	UnitPointer ourslave=GetUnit()->CreateTemporaryGuardian(15352,summon_duration,float(-M_PI*2), 0);
	if(ourslave)
	{
		TO_CREATURE(ourslave)->ResistanceModPct[NATURE_DAMAGE]=100;   // we should be imune to nature dmg. This can be also set in db
		ourslave->SetUInt32Value(UNIT_FIELD_LEVEL, GetUnit()->GetUInt32Value(UNIT_FIELD_LEVEL));
		ourslave->BaseDamage[0]=250;
		ourslave->BaseDamage[1]=450;
		ourslave->CalcDamage();
		sEventMgr.AddEvent(TO_CREATURE(ourslave), &Creature::SummonExpire, EVENT_SUMMON_EXPIRE, summon_duration, 1,0);
	}
}

// we only cast once a spell and we will set his health and resistances. Note that this can be made with db too !
void AIInterface::Event_Summon_FE_totem(uint32 summon_duration)
{
	// timer should not reach this value thus not cast this spell again
	m_totemspelltimer = 0xEFFFFFFF;
	// creatures do not support PETs and the spell uses that effect so we force a summon guardian thing
	UnitPointer ourslave=GetUnit()->CreateTemporaryGuardian(15438,summon_duration,float(-M_PI*2), 0);
	if(ourslave)
	{
		TO_CREATURE(ourslave)->ResistanceModPct[FIRE_DAMAGE]=100;// we should be imune to fire dmg. This can be also set in db
		ourslave->SetUInt32Value(UNIT_FIELD_LEVEL, GetUnit()->GetUInt32Value(UNIT_FIELD_LEVEL));
		ourslave->BaseDamage[0]=250; // todo: damage should be fire instead of physical and scale with player spell damage
		ourslave->BaseDamage[1]=450;
		ourslave->CalcDamage();
		/*
		- also : select * from dbc_spell where name like "%fire blast%"
		- also : select * from dbc_spell where name like "%fire nova"
		*/
		sEventMgr.AddEvent(TO_CREATURE(ourslave), &Creature::SummonExpire, EVENT_SUMMON_EXPIRE, summon_duration, 1,0);
	}
}

void AIInterface::CallGuards()
{
	if( GetUnit()->isDead() || !GetUnit()->isAlive() || GetUnit()->GetInRangePlayersCount() == 0 )
		return;

	if(  getMSTime() > m_guardTimer && !IS_INSTANCE(GetUnit()->GetMapId()))
	{
		m_guardTimer = getMSTime() + 15000;
		uint16 AreaId = GetUnit()->GetMapMgr()->GetAreaID(GetUnit()->GetPositionX(),GetUnit()->GetPositionY());
		AreaTable * at = dbcArea.LookupEntry(AreaId);
		if(!at)
			return;

		ZoneGuardEntry * zoneSpawn = ZoneGuardStorage.LookupEntry(at->ZoneId);
		if(!zoneSpawn) 
			return;

		uint32 team = isAlliance(GetUnit()) ? 0 : 1; // Set team
		uint32 guardId = 0;
		guardId = team ? zoneSpawn->HordeEntry : zoneSpawn->AllianceEntry;
		guardId = guardId ? guardId : team ? 3296 : 68;

		CreatureProto * cp = CreatureProtoStorage.LookupEntry( guardId );
		if(!cp) 
			return;

		float x = GetUnit()->GetPositionX() + (float(rand() % 150 + 100) / 1000.0f );
		float y = GetUnit()->GetPositionY() + (float(rand() % 150 + 100) / 1000.0f );
#ifdef COLLISION
		float z = CollideInterface.GetHeight(GetUnit()->GetMapId(), x, y, GetUnit()->GetPositionZ() + 2.0f);
		if( z == NO_WMO_HEIGHT )
			z = GetUnit()->GetMapMgr()->GetLandHeight(x, y);

		if( fabs( z - GetUnit()->GetPositionZ() ) > 10.0f )
			z = GetUnit()->GetPositionZ();
#else
		float z = GetUnit()->GetPositionZ();
		float adt_z = GetUnit()->GetMapMgr()->GetLandHeight(x, y);
		if(fabs(z - adt_z) < 3)
			z = adt_z;
#endif

		// "Guards!"
		GetUnit()->SendChatMessage(CHAT_MSG_MONSTER_SAY, team ? LANG_ORCISH : LANG_COMMON, GUARDSGUARDSGUAI);

		uint8 spawned = 0;
	
		unordered_set<PlayerPointer>::iterator hostileItr = GetUnit()->GetInRangePlayerSetBegin();
		for(; hostileItr != GetUnit()->GetInRangePlayerSetEnd(); hostileItr++)
		{
			if(spawned >= 3)
				break;

			if(!isHostile(*hostileItr, GetUnit()))
				continue;

			CreaturePointer guard = GetUnit()->GetMapMgr()->CreateCreature(guardId);
			guard->Load(cp, x, y, z);
			guard->SetInstanceID(GetUnit()->GetInstanceID());
			guard->SetZoneId(GetUnit()->GetZoneId());
			guard->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP); /* shitty DBs */
			guard->m_noRespawn=true;
		
			if(!guard->CanAddToWorld())
			{
				guard->SafeDelete();
				return;
			}

			uint32 t = spawned ? 0 : RandomUInt(8)*1000;
			if( t == 0 )
					guard->PushToWorld(GetUnit()->GetMapMgr());
				else
					sEventMgr.AddEvent(guard,&Creature::AddToWorld, GetUnit()->GetMapMgr(), EVENT_UNK, t, 1, 0);

			// despawn after 5 minutes.
			sEventMgr.AddEvent(guard, &Creature::SafeDelete, EVENT_CREATURE_SAFE_DELETE, 60*5*1000, 1,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
			// Start patrolling if nothing else to do.
			sEventMgr.AddEvent(guard, &Creature::SetGuardWaypoints, EVENT_UNK, 10000, 1,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);

			spawned++;
		}
	}
}

void AIInterface::WipeCurrentTarget()
{
	TargetMap::iterator itr = m_aiTargets.find( GetNextTarget() );
	if( itr != m_aiTargets.end() )
		m_aiTargets.erase( itr );

	SetNextTarget(NULLUNIT);

	if( GetNextTarget() == getUnitToFollow() )
		SetUnitToFollow(NULLUNIT);

	if( GetNextTarget() == UnitToFollow_backup )
		UnitToFollow_backup = NULLUNIT;
}

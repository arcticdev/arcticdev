/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

#include "GuildDefines.h"

class SpellCastTargets
{
public:
    void read ( WorldPacket & data,uint64 caster );
    void write ( WorldPacket & data);
    void write ( StackPacket & data);

    SpellCastTargets() : m_targetMask(0), m_unitTarget(0), m_itemTarget(0), m_srcX(0), m_srcY(0), m_srcZ(0),
        m_destX(0), m_destY(0), m_destZ(0) {}

    SpellCastTargets(uint16 TargetMask, uint64 unitTarget, uint64 itemTarget, float srcX, float srcY,
        float srcZ, float destX, float destY, float destZ) : m_targetMask(TargetMask), m_unitTarget(unitTarget),
        m_itemTarget(itemTarget), m_srcX(srcX), m_srcY(srcY), m_srcZ(srcZ), m_destX(destX), m_destY(destY), m_destZ(destZ) {}

    SpellCastTargets(uint64 unitTarget) : m_targetMask(0x2), m_unitTarget(unitTarget), m_itemTarget(0),
        m_srcX(0), m_srcY(0), m_srcZ(0), m_destX(0), m_destY(0), m_destZ(0) {}

    SpellCastTargets(WorldPacket & data, uint64 caster) : m_targetMask(0), m_unitTarget(0), m_itemTarget(0), m_srcX(0), m_srcY(0), m_srcZ(0),
        m_destX(0), m_destY(0), m_destZ(0)
    {
        read(data, caster);
    }

    SpellCastTargets& operator=(const SpellCastTargets &target)
    {
        m_unitTarget = target.m_unitTarget;
        m_itemTarget = target.m_itemTarget;

        m_srcX = target.m_srcX;
        m_srcY = target.m_srcY;
        m_srcZ = target.m_srcZ;

        m_destX = target.m_destX;
        m_destY = target.m_destY;
        m_destZ = target.m_destZ;

        /*m_strTarget = target.m_strTarget;*/

        m_targetMask = target.m_targetMask;
        return *this;
    }

    uint32 m_targetMask;
    uint64 m_unitTarget;
    uint64 m_itemTarget;
    float m_srcX, m_srcY, m_srcZ;
    float m_destX, m_destY, m_destZ;
    //std::string m_strTarget;

};

// Spell instance
class SERVER_DECL Spell
{
public:
    friend class DummySpellHandler;
    Spell( Object* Caster, SpellEntry *info, bool triggered, Aura* aur);
    ~Spell();

    // Fills specified targets at the area of effect
    void FillSpecifiedTargetsInArea(float srcx,float srcy,float srcz,uint32 ind, uint32 specification);
    // Fills specified targets at the area of effect. We suppose we already inited this spell and know the details
    void FillSpecifiedTargetsInArea(uint32 i,float srcx,float srcy,float srcz, float range, uint32 specification);
    // Fills the targets at the area of effect
    void FillAllTargetsInArea(uint32 i, float srcx,float srcy,float srcz, float range);
    // Fills the targets at the area of effect. We suppose we already inited this spell and know the details
    void FillAllTargetsInArea(float srcx,float srcy,float srcz,uint32 ind);
    // Fills the targets at the area of effect. We suppose we already inited this spell and know the details
    void FillAllTargetsInArea(LocationVector & location,uint32 ind);
    // Fills the targets at the area of effect. We suppose we already inited this spell and know the details
    void FillAllFriendlyInArea(uint32 i, float srcx,float srcy,float srcz, float range);
    // get single Enemy as target
    uint64 GetSinglePossibleEnemy(uint32 i, float prange=0);
    // get single Enemy as target
    uint64 GetSinglePossibleFriend(uint32 i, float prange=0);
    // generate possible target list for a spell. Use as last resort since it is not acurate
    void GenerateTargets(SpellCastTargets *store_buff);
    // Fills the target map of the spell packet
    void FillTargetMap(uint32);
    // Prepares the spell thats going to cast to targets
    uint8 prepare(SpellCastTargets * targets);
    // Cancels the current spell
    void cancel();
    // Update spell state based on time difference
    void update(uint32 difftime);
    // Casts the spell
    void cast(bool);
    // Finishes the casted spell
    void finish();
    // Handle the Effects of the Spell
    void HandleEffects(uint32 i);
    // Take Power from the caster based on spell power usage
    bool TakePower();
    // Has power?
    bool HasPower();
    // Checks the caster is ready for cast
    uint8 CanCast(bool tolerate);
    // Removes reagents, ammo, and items/charges
    void RemoveItems();
    // Calculates the i'th effect value
    int32 CalculateEffect(uint32, Unit* target);
    // Handles Teleport function
    void HandleTeleport(uint32 id, Unit* Target);
    // Determines how much skill caster going to gain
    void DetermineSkillUp();
    // Increases cast time of the spell
    void AddTime(uint32 type);
    void AddCooldown();
    void AddStartCooldown();

    bool Reflect(Unit* refunit);

    ARCTIC_INLINE uint32 getState() { return m_spellState; }
    ARCTIC_INLINE void SetUnitTarget(Unit* punit){unitTarget=punit;}
    ARCTIC_INLINE SpellEntry *GetSpellProto() { return m_spellInfo; }

    // Send Packet functions
    void SendCastResult(uint8 result);
    void SendSpellStart();
	void SendSpellGo();
	void SendLogExecute(uint32 damage, uint64 & targetGuid);
	void SendInterrupted(uint8 result);
	void SendChannelUpdate(uint32 time);
	void SendChannelStart(uint32 duration);
	void SendResurrectRequest(Player* target);
	static void SendHealSpellOnPlayer(Object* caster, Object* target, uint32 dmg, bool critical, uint32 overheal, uint32 spellid);
	static void SendHealManaSpellOnPlayer(Object* caster, Object* target, uint32 dmg, uint32 powertype, uint32 spellid);
	
	void HandleAddAura(uint64 guid);
	void writeSpellGoTargets( WorldPacket * data );

	SpellEntry* m_spellInfo;
	uint32 pSpellId;
	SpellEntry *ProcedOnSpell; // some spells need to know the origins of the proc too
	SpellCastTargets m_targets;

	void CreateItem(uint32 itemId);

	// Effect Handlers
	void SpellEffectNULL(uint32 i);
	void SpellEffectInstantKill(uint32 i);
	void SpellEffectSchoolDMG(uint32 i);
	void SpellEffectDummy(uint32 i);
	void SpellEffectRestoreHealthPct(uint32 i);
	void SpellEffectRestoreManaPct(uint32 i);
	void SpellEffectTeleportUnits(uint32 i);
	void SpellEffectApplyAura(uint32 i);
	void SpellEffectPowerDrain(uint32 i);
	void SpellEffectHealthLeech(uint32 i);
	void SpellEffectHeal(uint32 i);
	void SpellEffectQuestComplete(uint32 i);
	void SpellEffectWeapondamageNoschool(uint32 i);
	void SpellEffectResurrect(uint32 i);
	void SpellEffectAddExtraAttacks(uint32 i);
	void SpellEffectDodge(uint32 i);
	void SpellEffectBlock(uint32 i);
	void SpellEffectParry(uint32 i);
	void SpellEffectCreateItem(uint32 i);
	void SpellEffectPersistentAA(uint32 i);
	void SpellEffectSummon(uint32 i);
	void SummonCreature(uint32 i);
	void SpellEffectLeap(uint32 i);
	void SpellEffectEnergize(uint32 i);
	void SpellEffectWeaponDmgPerc(uint32 i);
	void SpellEffectTriggerMissile(uint32 i);
	void SpellEffectOpenLock(uint32 i);
	void SpellEffectApplyAA(uint32 i);
	void SpellEffectLearnSpell(uint32 i);
	void SpellEffectSpellDefense(uint32 i);
	void SpellEffectDispel(uint32 i);
	void SummonGuardian(uint32 i);
	void SpellEffectSkillStep(uint32 i);
	void SpellEffectSummonObject(uint32 i);
	void SpellEffectEnchantItem(uint32 i);
	void SpellEffectEnchantItemTemporary(uint32 i);
	void SpellEffectTameCreature(uint32 i);
	void SpellEffectSummonPet(uint32 i);
	void SpellEffectWeapondamage(uint32 i);
	void SpellEffectPowerBurn(uint32 i);
	void SpellEffectThreat(uint32 i);
	void SpellEffectTriggerSpell(uint32 i);
	void SpellEffectHealthFunnel(uint32 i);
	void SpellEffectPowerFunnel(uint32 i);
	void SpellEffectHealMaxHealth(uint32 i);
	void SpellEffectInterruptCast(uint32 i);
	void SpellEffectDistract(uint32 i);
	void SpellEffectPickpocket(uint32 i);
	void SpellEffectAddFarsight(uint32 i);
	void SummonPossessed(uint32 i);
	void SpellEffectUseGlyph(uint32 i);
	void SpellEffectHealMechanical(uint32 i);
	void SpellEffectSummonObjectWild(uint32 i);
	void SpellEffectScriptEffect(uint32 i);
	void SpellEffectSanctuary(uint32 i);
	void SpellEffectAddComboPoints(uint32 i);
	void SpellEffectCreateHouse(uint32 i);
	void SpellEffectDuel(uint32 i);
	void SpellEffectStuck(uint32 i);
	void SpellEffectSummonPlayer(uint32 i);
	void SpellEffectActivateObject(uint32 i);
	void SpellEffectWMODamage(uint32 i); 
 	void SpellEffectWMORepair(uint32 i); 
	void SummonTotem(uint32 i);
	void SpellEffectProficiency(uint32 i);
	void SpellEffectSendEvent(uint32 i);
	void SpellEffectSkinning(uint32 i);
	void SpellEffectCharge(uint32 i);
	void SummonNonCombatPet(uint32 i);
	void SpellEffectKnockBack(uint32 i);
	void SpellEffectInebriate(uint32 i);
	void SpellEffectFeedPet(uint32 i);
	void SpellEffectDismissPet(uint32 i);
	void SpellEffectReputation(uint32 i);
	void SpellEffectSummonObjectSlot(uint32 i);
	void SpellEffectDispelMechanic(uint32 i);
	void SpellEffectSummonDeadPet(uint32 i);
	void SpellEffectDestroyAllTotems(uint32 i);
	void SpellEffectSummonDemonOld(uint32 i);
	void SpellEffectAttackMe(uint32 i);
	void SpellEffectSkill(uint32 i);
	void SpellEffectApplyPetAura(uint32 i);
	void SpellEffectDummyMelee(uint32 i);
	void SpellEffectPlayerPull( uint32 i );
	void SpellEffectSpellSteal(uint32 i);
	void SpellEffectProspecting(uint32 i);
	void SpellEffectOpenLockItem(uint32 i);
	void SpellEffectSelfResurrect(uint32 i);
	void SpellEffectDisenchant(uint32 i);
	void SpellEffectWeapon(uint32 i);
	void SpellEffectDefense(uint32 i);
	void SpellEffectDualWield(uint32 i);
	void SpellEffectSkinPlayerCorpse(uint32 i);
	void SpellEffectResurrectNew(uint32 i);
	void SpellEffectTranformItem(uint32);
	void SpellEffectEnvironmentalDamage(uint32);
	void SpellEffectLearnPetSpell(uint32 i);
	void SpellEffectEnchantHeldItem(uint32 i);
	void SpellEffectAddHonor(uint32 i);
	void SpellEffectSpawn(uint32 i);
	void SpellEffectApplyAura128(uint32 i);
	void SpellEffectTriggerSpellWithValue(uint32 i);
	void SpellEffectMegaJump(uint32 i);
	void SpellEffectMilling(uint32 i);
	void SpellEffectAddPrismaticSocket(uint32 i);
	void SpellEffectTitanGrip(uint32 i);
	void SummonLightwell(uint32 i);
	void SpellEffectCreateRandomItem(uint32 i);
	void SpellEffectSendTaxi(uint32 i);
	void SpellEffectKillCredit(uint32 i);
	void SpellEffectForceCast(uint32 i);
	void SpellEffectSetTalentSpecsCount(uint32 i);
	void SpellEffectActivateTalentSpec(uint32 i);

	// Spell Targets Handlers
	void SpellTargetNULL(uint32 i, uint32 j);
	void SpellTargetDefault(uint32 i, uint32 j);
	void SpellTargetSelf(uint32 i, uint32 j);
	void SpellTargetInvisibleAOE(uint32 i, uint32 j);
	void SpellTargetFriendly(uint32 i, uint32 j);
	void SpellTargetPet(uint32 i, uint32 j);
	void SpellTargetSingleTargetEnemy(uint32 i, uint32 j);
	void SpellTargetCustomAreaOfEffect(uint32 i, uint32 j);
	void SpellTargetAreaOfEffect(uint32 i, uint32 j);
	void SpellTargetLandUnderCaster(uint32 i, uint32 j); // I don't think this is the correct name for this one
	void SpellTargetAllPartyMembersRangeNR(uint32 i, uint32 j);
	void SpellTargetSingleTargetFriend(uint32 i, uint32 j);
	void SpellTargetAoE(uint32 i, uint32 j); // something special
	void SpellTargetSingleGameobjectTarget(uint32 i, uint32 j);
	void SpellTargetInFrontOfCaster(uint32 i, uint32 j);
	void SpellTargetSingleFriend(uint32 i, uint32 j);
	void SpellTargetGameobject_itemTarget(uint32 i, uint32 j);
	void SpellTargetPetOwner(uint32 i, uint32 j);
	void SpellTargetEnemysAreaOfEffect(uint32 i, uint32 j);
	void SpellTargetTypeTAOE(uint32 i, uint32 j);
	void SpellTargetAllyBasedAreaEffect(uint32 i, uint32 j);
	void SpellTargetScriptedEffects(uint32 i, uint32 j);
	void SpellTargetSummon(uint32 i, uint32 j);
	void SpellTargetNearbyPartyMembers(uint32 i, uint32 j);
	void SpellTargetSingleTargetPartyMember(uint32 i, uint32 j);
	void SpellTargetScriptedEffects2(uint32 i, uint32 j);
	void SpellTargetPartyMember(uint32 i, uint32 j);
	void SpellTargetDummyTarget(uint32 i, uint32 j);
	void SpellTargetFishing(uint32 i, uint32 j);
	void SpellTargetType40(uint32 i, uint32 j);
	void SpellTargetTotem(uint32 i, uint32 j);
	void SpellTargetChainTargeting(uint32 i, uint32 j);
	void SpellTargetSimpleTargetAdd(uint32 i, uint32 j);
	void SpellTarget56(uint32 o, uint32 j);
	void SpellTargetTargetAreaSelectedUnit(uint32 i, uint32 j);
	void SpellTargetInFrontOfCaster2(uint32 i, uint32 j);
	void SpellTargetTargetPartyMember(uint32 i, uint32 j);
	void SpellTargetSameGroupSameClass(uint32 i, uint32 j);
	void SpellTargetPositionOfTarget(uint32 i, uint32 j);
	void SpellTargetAreaOfEffect87(uint32 i, uint32 j);
	void SpellTargetAllTargetsInArea(uint32 i, uint32 j);
	void SpellTargetVehicle(uint32 i, uint32 j);

	uint64 static FindLowestHealthRaidMember(Player* Target, uint32 dist);

	void Heal(int32 amount);

	GameObject*			g_caster;
	Unit*				u_caster;
	Item*				i_caster;
	Player* 			p_caster;
	Object*				m_caster;
	Vehicle*			v_caster;

	bool SpellEffectUpdateQuest(uint32 questid);

	// 15007 = resurecting sickness
	
	// This returns SPELL_ENTRY_Spell_Dmg_Type where 0 = SPELL_DMG_TYPE_NONE, 1 = SPELL_DMG_TYPE_MAGIC, 2 = SPELL_DMG_TYPE_MELEE, 3 = SPELL_DMG_TYPE_RANGED
	// It should NOT be used for weapon_damage_type which needs: 0 = MELEE, 1 = OFFHAND, 2 = RANGED
	ARCTIC_INLINE uint32 GetType() { return ( m_spellInfo->Spell_Dmg_Type == SPELL_DMG_TYPE_NONE ? SPELL_DMG_TYPE_MAGIC : m_spellInfo->Spell_Dmg_Type ); }
	ARCTIC_INLINE Item* GetItemTarget() { return itemTarget; }
	ARCTIC_INLINE Unit* GetUnitTarget() { return unitTarget; }
	ARCTIC_INLINE Player* GetPlayerTarget() { return playerTarget; }
	ARCTIC_INLINE GameObject* GetGameObjectTarget() { return gameObjTarget; }

	uint32 chaindamage;

	bool IsAspect();
	bool IsSeal();
	bool static IsBinary(SpellEntry * sp);

	uint32 GetDuration()
	{
		if(bDurSet)return Dur;
		bDurSet = true;
		int32 c_dur = 0;

		if(m_spellInfo->DurationIndex)
		{
			SpellDuration *sd=dbcSpellDuration.LookupEntry(m_spellInfo->DurationIndex);
			if(sd)
			{
				// check for negative and 0 durations.
				// duration affected by level
				if((int32)sd->Duration1 < 0 && sd->Duration2 && u_caster)
				{
					this->Dur = uint32(((int32)sd->Duration1 + (sd->Duration2 * u_caster->getLevel())));
					if((int32)this->Dur > 0 && sd->Duration3 > 0 && (int32)this->Dur > (int32)sd->Duration3)
					{
						this->Dur = sd->Duration3;
					}

					if((int32)this->Dur < 0)
						this->Dur = 0;
					c_dur = this->Dur;
				}
				if(sd->Duration1 >= 0 && !c_dur)
				{
					this->Dur = sd->Duration1;
				}
				// combo point lolerCopter? ;P
				if(p_caster)  
				{
					uint32 cp=p_caster->m_comboPoints;
					if(cp)
					{
						uint32 bonus = (cp*(sd->Duration3-sd->Duration1))/5;
						if(bonus)
						{
							this->Dur += bonus;
							m_requiresCP = true;
						}
					}
				}

				if(m_spellInfo->SpellGroupType && u_caster)
				{
					SM_FIValue(u_caster->SM[SMT_DURATION][0],(int32*)&this->Dur,m_spellInfo->SpellGroupType);
					SM_PIValue(u_caster->SM[SMT_DURATION][1],(int32*)&this->Dur,m_spellInfo->SpellGroupType);
				}
				// Limit duration in PvP but not applying diminishing returns
				if(unitTarget != NULL && unitTarget->IsPlayer() && this->Dur > 10000)
				{
					switch(m_spellInfo->NameHash)
					{
					case SPELL_HASH_CURSE_OF_TONGUES:
					case SPELL_HASH_BANISH:
						this->Dur = 10000;
					}
				}
				if( unitTarget != NULL && p_caster && unitTarget == p_caster )
				{
					if( m_spellInfo->NameHash == SPELL_HASH_THORNS )
					{
						if( p_caster->HasDummyAura( SPELL_HASH_GLYPH_OF_THORNS ) )
						{
							Dur += (p_caster->GetDummyAura( SPELL_HASH_GLYPH_OF_THORNS )->EffectBasePoints[0]+1) * MSTIME_MINUTE;
						}
					}
					else if( m_spellInfo->NameHash == SPELL_HASH_BLESSING_OF_MIGHT )
					{
						if( p_caster->HasDummyAura(SPELL_HASH_GLYPH_OF_BLESSING_OF_MIGHT) )
							Dur += 20 * MSTIME_MINUTE;
					}
				}
			}
			else
			{
				this->Dur = uint32(-1);
			}
		}
		else
		{
			 this->Dur = uint32(-1);
		}

		return this->Dur;
	}

	ARCTIC_INLINE float GetDBCCastTime(uint32 i)
	{
		if(bRadSet[i])return Rad[i];
		bRadSet[i]=true;
		Rad[i]=::GetDBCCastTime(dbcSpellRadius.LookupEntry(m_spellInfo->EffectRadiusIndex[i]));
		if(m_spellInfo->SpellGroupType && u_caster)
		{
			SM_FFValue(u_caster->SM[SMT_RADIUS][0],&Rad[i],m_spellInfo->SpellGroupType);
			SM_PFValue(u_caster->SM[SMT_RADIUS][1],&Rad[i],m_spellInfo->SpellGroupType);
		}

		return Rad[i];
	}

	ARCTIC_INLINE static uint32 GetBaseThreat(uint32 dmg)
	{
		return dmg;
	}

	ARCTIC_INLINE static bool HasMechanic(SpellEntry * sp, uint32 MechanicsType)
	{
		return sp->MechanicsType == MechanicsType ||
			(uint32)sp->EffectMechanic[0] == MechanicsType ||
			(uint32)sp->EffectMechanic[1] == MechanicsType ||
			(uint32)sp->EffectMechanic[2] == MechanicsType;
	}

	ARCTIC_INLINE static uint32 GetMechanic(SpellEntry * sp)
	{
		if(sp->MechanicsType)
			return sp->MechanicsType;
		if(sp->EffectMechanic[2])
			return sp->EffectMechanic[2];
		if(sp->EffectMechanic[1])
			return sp->EffectMechanic[1];
		if(sp->EffectMechanic[0])
			return sp->EffectMechanic[0];

		return 0;
	}

	ARCTIC_INLINE static uint32 GetMechanicOfEffect(SpellEntry * sp, uint32 i)
	{
		if(sp->EffectMechanic[i])
			return sp->EffectMechanic[i];
		if(sp->MechanicsType)
			return sp->MechanicsType;

		return 0;
	}

    bool IsStealthSpell();
    bool IsInvisibilitySpell();

    SummonPropertiesEntry * m_summonProperties;

    int32 damage;
    Aura*  m_triggeredByAura;
    signed int	forced_basepoints[3]; //some talent inherit base points from previous caster spells

    bool m_triggeredSpell;
    bool m_AreaAura;
    //uint32 TriggerSpellId;  // used to set next spell to use
    //uint64 TriggerSpellTarget; // used to set next spell target
    bool m_requiresCP;
    float m_castPositionX;
    float m_castPositionY;
    float m_castPositionZ;

    int32 damageToHit;
    uint32 castedItemId;
    uint8 extra_cast_number;
    uint32 m_glyphIndex;
    uint32 m_pushbackCount;

    bool duelSpell;

    ////////////////////////////////////////////////////////////////////////////////
	// bool DuelSpellNoMoreValid()
	//  Tells if the Spell was being casted while dueling but now the duel is over
	//
	// Return Value
	//  Returns true if Spell is now invalid because the duel is over.
	//  Returns false if Spell is valid.
	//
	///////////////////////////////////////////////////////////////////////////////

	bool DuelSpellNoMoreValid()
	{
		if(duelSpell && (
				(p_caster != NULL && p_caster->GetDuelState() != DUEL_STATE_STARTED) ||
				(u_caster != NULL && u_caster->IsPet() && TO_PET(u_caster)->GetPetOwner() && TO_PET(u_caster)->GetPetOwner()->GetDuelState() != DUEL_STATE_STARTED)))
			return true;
		else
			return false;
	}

	ARCTIC_INLINE void safe_cancel()
	{
		m_cancelled = true;
	}

	// Spell state's
	// Spell failed
	ARCTIC_INLINE bool GetSpellFailed(){return m_Spell_Failed;}
	ARCTIC_INLINE void SetSpellFailed(bool failed = true){m_Spell_Failed = failed;}

	Spell* m_reflectedParent;

	// Returns true if spellEffect's effectNum effect affects testSpell based on EffectSpellClassMask
	ARCTIC_INLINE static bool EffectAffectsSpell(SpellEntry* spellEffect, uint32 effectNum, SpellEntry* testSpell)
	{
		return (testSpell->SpellGroupType[0] && (spellEffect->EffectSpellClassMask[effectNum][0] & testSpell->SpellGroupType[0]) || 
			testSpell->SpellGroupType[1] && (spellEffect->EffectSpellClassMask[effectNum][1] & testSpell->SpellGroupType[1]) || 
			testSpell->SpellGroupType[2] && (spellEffect->EffectSpellClassMask[effectNum][2] & testSpell->SpellGroupType[2]));
	}

protected:

	/// Spell state's
	bool	m_usesMana;
	bool	m_Spell_Failed;		//for 5sr
	bool	m_Delayed;
	uint32  m_spellState;
	int32   m_castTime;
	int32   m_timer;
	bool	m_ForceConsumption;

	// Current Targets to be used in effect handler
	Unit*	  unitTarget;
	Item*	  itemTarget;
	GameObject* gameObjTarget;
	Player*	 playerTarget;
	Corpse*	 corpseTarget;
	uint32	  add_damage;

	uint8	   cancastresult;
	uint32	  Dur;
	bool		bDurSet;
	float	   Rad[3];
	bool		bRadSet[3];
	bool		m_cancelled;
	bool m_isCasting;
	bool m_projectileWait;

private:
	struct SpellTarget
	{
		uint64 Guid;
		uint8 HitResult;
		uint8 EffectMask;
	};

	typedef vector<SpellTarget> SpellTargetList;
	SpellTargetList m_targetList;

	// adds a target to the list, performing DidHit checks
	void _AddTarget(const Unit* target, const uint32 effectid);

	// adds a target to the list, negating DidHit checks
	void _AddTargetForced(const uint64& guid, const uint32 effectid);

	// didhit checker
	uint8 _DidHit(const Unit* target);

	// gets the pointer of an object (optimized for spell system)
	Object* _LookupObject(const uint64& guid);

	// sets the pointers (unitTarget, itemTarget, etc) for a given guid
	void _SetTargets(const uint64& guid);

	friend class DynamicObject;
	void DetermineSkillUp(uint32 skillid,uint32 targetlevel, uint32 multiplicator = 1);
	void DetermineSkillUp(uint32 skillid);

	uint32 m_hitTargetCount;
	uint32 m_missTargetCount;
	
	// magnet
	Unit* m_magnetTarget;
};

void ApplyDiminishingReturnTimer(uint32 * Duration, Unit* Target, SpellEntry * spell);
void UnapplyDiminishingReturnTimer(Unit* Target, SpellEntry * spell);
uint32 GetDiminishingGroup(uint32 NameHash);

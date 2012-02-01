/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

class WorldSession;
class Unit;
class DynamicObj;
class Player;
class Item;
class Group;
class Aura;

// 4-bit flag
enum AURA_FLAGS
{
	AFLAG_EMPTY = 0x0,
	AFLAG_SET = 0x9
};

enum SUMMON_TYPE
{
	SUMMON_TYPE_POSSESSED = 65,
	SUMMON_TYPE_GUARDIAN = 61,
	SUMMON_TYPE_WILD = 64,
	SUMMON_TYPE_DEMON = 66,
	SUMMON_TYPE_TOTEM_1 = 63,
	SUMMON_TYPE_TOTEM_2 = 81,
	SUMMON_TYPE_TOTEM_3 = 82,
	SUMMON_TYPE_TOTEM_4 = 83,
	SUMMON_TYPE_SUMMON = 67,
	SUMMON_TYPE_CRITTER = 41,
	SUMMON_TYPE_GHOUL = 829,
	SUMMON_TYPE_LIGHTWELL = 1141,
	SUMMON_TYPE_WATER_ELEMENTAL = 1561,
};

enum AURA_STATE_FLAGS
{
	AURASTATE_FLAG_DODGE_BLOCK			= 0x00000001,
	AURASTATE_FLAG_HEALTH20				= 0x00000002,
	AURASTATE_FLAG_BERSERK				= 0x00000004,
	AURASTATE_FLAG_FROZEN				= 0x00000008,
	AURASTATE_FLAG_JUDGEMENT			= 0x00000010,
	AURASTATE_FLAG_STUNNED				= 0x00000020,
	AURASTATE_FLAG_PARRY				= 0x00000040,
	AURASTATE_FLAG_UNK2					= 0x00000080,
	AURASTATE_FLAG_UNK3					= 0x00000100,
	AURASTATE_FLAG_VICTORIOUS			= 0x00000200, // after you kill an enemy that yields experience or honor
	AURASTATE_FLAG_CRITICAL				= 0x00000400,
	AURASTATE_FLAG_UNK4					= 0x00000800,
	AURASTATE_FLAG_HEALTH35				= 0x00001000,
	AURASTATE_FLAG_IMMOLATE				= 0x00002000,
	AURASTATE_FLAG_REJUVENATE			= 0x00004000,
	AURASTATE_FLAG_POISON				= 0x00008000,
	AURASTATE_FLAG_ENRAGE				= 0x00010000,
	AURASTATE_FLAG_UNK5					= 0x00020000,
	AURASTATE_FLAG_UNK6					= 0x00040000,
	AURASTATE_FLAG_UNK7					= 0x00080000,
	AURASTATE_FLAG_UNK8					= 0x00100000,
	AURASTATE_FLAG_UNK9					= 0x00200000,
	AURASTATE_FLAG_HEALTHABOVE75		= 0x00400000,
};

enum MOD_TYPES
{
    SPELL_AURA_NONE = 0,                                // None
    SPELL_AURA_BIND_SIGHT = 1,                          // Bind Sight
    SPELL_AURA_MOD_POSSESS = 2,                         // Mod Possess
    SPELL_AURA_PERIODIC_DAMAGE = 3,                     // Periodic Damage
    SPELL_AURA_DUMMY = 4,                               // Script Aura
    SPELL_AURA_MOD_CONFUSE = 5,                         // Mod Confuse
    SPELL_AURA_MOD_CHARM = 6,                           // Mod Charm
    SPELL_AURA_MOD_FEAR = 7,                            // Mod Fear
    SPELL_AURA_PERIODIC_HEAL = 8,                       // Periodic Heal
    SPELL_AURA_MOD_ATTACKSPEED = 9,                     // Mod Attack Speed
    SPELL_AURA_MOD_THREAT = 10,                         // Mod Threat
    SPELL_AURA_MOD_TAUNT = 11,                          // Taunt
    SPELL_AURA_MOD_STUN = 12,                           // Stun
    SPELL_AURA_MOD_DAMAGE_DONE = 13,                    // Mod Damage Done
    SPELL_AURA_MOD_DAMAGE_TAKEN = 14,                   // Mod Damage Taken
    SPELL_AURA_DAMAGE_SHIELD = 15,                      // Damage Shield
    SPELL_AURA_MOD_STEALTH = 16,                        // Mod Stealth
    SPELL_AURA_MOD_DETECT = 17,                         // Mod Detect
    SPELL_AURA_MOD_INVISIBILITY = 18,                   // Mod Invisibility
    SPELL_AURA_MOD_INVISIBILITY_DETECTION = 19,         // Mod Invisibility Detection
    SPELL_AURA_MOD_TOTAL_HEALTH_REGEN_PCT = 20,
    SPELL_AURA_MOD_TOTAL_MANA_REGEN_PCT = 21,
    SPELL_AURA_MOD_RESISTANCE = 22,                     // Mod Resistance
    SPELL_AURA_PERIODIC_TRIGGER_SPELL = 23,             // Periodic Trigger
    SPELL_AURA_PERIODIC_ENERGIZE = 24,                  // Periodic Energize
    SPELL_AURA_MOD_PACIFY = 25,                         // Pacify
    SPELL_AURA_MOD_ROOT = 26,                           // Root
    SPELL_AURA_MOD_SILENCE = 27,                        // Silence
    SPELL_AURA_REFLECT_SPELLS = 28,                     // Reflect Spells %
    SPELL_AURA_MOD_STAT = 29,                           // Mod Stat
    SPELL_AURA_MOD_SKILL = 30,                          // Mod Skill
    SPELL_AURA_MOD_INCREASE_SPEED = 31,                 // Mod Speed
    SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED = 32,         // Mod Speed Mounted
    SPELL_AURA_MOD_DECREASE_SPEED = 33,                 // Mod Speed Slow
    SPELL_AURA_MOD_INCREASE_HEALTH = 34,                // Mod Increase Health
    SPELL_AURA_MOD_INCREASE_ENERGY = 35,                // Mod Increase Energy
    SPELL_AURA_MOD_SHAPESHIFT = 36,                     // Shapeshift
    SPELL_AURA_EFFECT_IMMUNITY = 37,                    // Immune Effect
    SPELL_AURA_STATE_IMMUNITY = 38,                     // Immune State
    SPELL_AURA_SCHOOL_IMMUNITY = 39,                    // Immune School
    SPELL_AURA_DAMAGE_IMMUNITY = 40,                    // Immune Damage
    SPELL_AURA_DISPEL_IMMUNITY = 41,                    // Immune Dispel Type
    SPELL_AURA_PROC_TRIGGER_SPELL = 42,                 // Proc Trigger Spell
    SPELL_AURA_PROC_TRIGGER_DAMAGE = 43,                // Proc Trigger Damage
    SPELL_AURA_TRACK_CREATURES = 44,                    // Track Creatures
    SPELL_AURA_TRACK_RESOURCES = 45,                    // Track Resources
    SPELL_AURA_MOD_PARRY_SKILL = 46,                    // Mod Parry Skill
    SPELL_AURA_MOD_PARRY_PERCENT = 47,                  // Mod Parry Percent
    SPELL_AURA_MOD_DODGE_SKILL = 48,                    // Mod Dodge Skill
    SPELL_AURA_MOD_DODGE_PERCENT = 49,                  // Mod Dodge Percent
    SPELL_AURA_MOD_BLOCK_SKILL = 50,                    // Mod Block Skill
    SPELL_AURA_MOD_BLOCK_PERCENT = 51,                  // Mod Block Percent
    SPELL_AURA_MOD_CRIT_PERCENT = 52,                   // Mod Crit Percent
    SPELL_AURA_PERIODIC_LEECH = 53,                     // Periodic Leech
    SPELL_AURA_MOD_HIT_CHANCE = 54,                     // Mod Hit Chance
    SPELL_AURA_MOD_SPELL_HIT_CHANCE = 55,               // Mod Spell Hit Chance
    SPELL_AURA_TRANSFORM = 56,                          // Transform
    SPELL_AURA_MOD_SPELL_CRIT_CHANCE = 57,              // Mod Spell Crit Chance
    SPELL_AURA_MOD_INCREASE_SWIM_SPEED = 58,            // Mod Speed Swim
    SPELL_AURA_MOD_DAMAGE_DONE_CREATURE = 59,           // Mod Creature Dmg Done
    SPELL_AURA_MOD_PACIFY_SILENCE = 60,                 // Pacify & Silence
    SPELL_AURA_MOD_SCALE = 61,                          // Mod Scale
    SPELL_AURA_PERIODIC_HEALTH_FUNNEL = 62,             // Periodic Health Funnel
    SPELL_AURA_PERIODIC_MANA_FUNNEL = 63,               // Periodic Mana Funnel
    SPELL_AURA_PERIODIC_MANA_LEECH = 64,                // Periodic Mana Leech
    SPELL_AURA_MOD_CASTING_SPEED = 65,                  // Haste - Spells
    SPELL_AURA_FEIGN_DEATH = 66,                        // Feign Death
    SPELL_AURA_MOD_DISARM = 67,                         // Disarm
    SPELL_AURA_MOD_STALKED = 68,                        // Mod Stalked
    SPELL_AURA_SCHOOL_ABSORB = 69,                      // School Absorb
    SPELL_AURA_EXTRA_ATTACKS = 70,                      // Extra Attacks
    SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL = 71,       // Mod School Spell Crit Chance
    SPELL_AURA_MOD_POWER_COST = 72,                     // Mod Power Cost
    SPELL_AURA_MOD_POWER_COST_SCHOOL = 73,              // Mod School Power Cost
    SPELL_AURA_REFLECT_SPELLS_SCHOOL = 74,              // Reflect School Spells %
    SPELL_AURA_MOD_LANGUAGE = 75,                       // Mod Language
    SPELL_AURA_FAR_SIGHT = 76,                          // Far Sight
    SPELL_AURA_MECHANIC_IMMUNITY = 77,                  // Immune Mechanic
    SPELL_AURA_MOUNTED = 78,                            // Mounted
    SPELL_AURA_MOD_DAMAGE_PERCENT_DONE = 79,            // Mod Dmg %
    SPELL_AURA_MOD_PERCENT_STAT = 80,                   // Mod Stat %
    SPELL_AURA_SPLIT_DAMAGE = 81,                       // Split Damage
    SPELL_AURA_WATER_BREATHING = 82,                    // Water Breathing
    SPELL_AURA_MOD_BASE_RESISTANCE = 83,                // Mod Base Resistance
    SPELL_AURA_MOD_REGEN = 84,                          // Mod Health Regen
    SPELL_AURA_MOD_POWER_REGEN = 85,                    // Mod Power Regen
    SPELL_AURA_CHANNEL_DEATH_ITEM = 86,                 // Create Death Item
    SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN = 87,           // Mod Dmg % Taken
    SPELL_AURA_MOD_PERCENT_REGEN = 88,                  // Mod Health Regen Percent
    SPELL_AURA_PERIODIC_DAMAGE_PERCENT = 89,            // Periodic Damage Percent
    SPELL_AURA_MOD_RESIST_CHANCE = 90,                  // Mod Resist Chance
    SPELL_AURA_MOD_DETECT_RANGE = 91,                   // Mod Detect Range
    SPELL_AURA_PREVENTS_FLEEING = 92,                   // Prevent Fleeing
    SPELL_AURA_MOD_UNATTACKABLE = 93,                   // Mod Uninteractible
    SPELL_AURA_INTERRUPT_REGEN = 94,                    // Interrupt Regen
    SPELL_AURA_GHOST = 95,                              // Ghost
    SPELL_AURA_SPELL_MAGNET = 96,                       // Spell Magnet
    SPELL_AURA_MANA_SHIELD = 97,                        // Mana Shield
    SPELL_AURA_MOD_SKILL_TALENT = 98,                   // Mod Skill Talent
    SPELL_AURA_MOD_ATTACK_POWER = 99,                   // Mod Attack Power
    SPELL_AURA_AURAS_VISIBLE = 100,                     // Auras Visible
    SPELL_AURA_MOD_RESISTANCE_PCT = 101,                // Mod Resistance %
    SPELL_AURA_MOD_CREATURE_ATTACK_POWER = 102,         // Mod Creature Attack Power
    SPELL_AURA_MOD_TOTAL_THREAT = 103,                  // Mod Total Threat (Fade)
    SPELL_AURA_WATER_WALK = 104,                        // Water Walk
    SPELL_AURA_FEATHER_FALL = 105,                      // Feather Fall
    SPELL_AURA_HOVER = 106,                             // Hover
    SPELL_AURA_ADD_FLAT_MODIFIER = 107,                 // Add Flat Modifier
    SPELL_AURA_ADD_PCT_MODIFIER = 108,                  // Add % Modifier
    SPELL_AURA_ADD_TARGET_TRIGGER = 109,                // Add Class Target Trigger
    SPELL_AURA_MOD_POWER_REGEN_PERCENT = 110,           // Mod Power Regen %
    SPELL_AURA_ADD_CASTER_HIT_TRIGGER = 111,            // Add Class Caster Hit Trigger
    SPELL_AURA_OVERRIDE_CLASS_SCRIPTS = 112,            // Override Class Scripts
    SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN = 113,           // Mod Ranged Dmg Taken
    SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN_PCT = 114,       // Mod Ranged % Dmg Taken
    SPELL_AURA_MOD_HEALING = 115,                       // Mod Healing
    SPELL_AURA_IGNORE_REGEN_INTERRUPT = 116,            // Regen During Combat
    SPELL_AURA_MOD_MECHANIC_RESISTANCE = 117,           // Mod Mechanic Resistance
    SPELL_AURA_MOD_HEALING_PCT = 118,                   // Mod Healing %
    SPELL_AURA_SHARE_PET_TRACKING = 119,                // Share Pet Tracking
    SPELL_AURA_UNTRACKABLE = 120,                       // Untrackable
    SPELL_AURA_EMPATHY = 121,                           // Empathy (Lore, whatever)
    SPELL_AURA_MOD_OFFHAND_DAMAGE_PCT = 122,            // Mod Offhand Dmg %
    SPELL_AURA_MOD_POWER_COST_PCT = 123,                // Mod Power Cost % --> armor penetration & spell penetration
    SPELL_AURA_MOD_RANGED_ATTACK_POWER = 124,           // Mod Ranged Attack Power
    SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN = 125,            // Mod Melee Dmg Taken
    SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT = 126,        // Mod Melee % Dmg Taken
    SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS = 127,// Rngd Atk Pwr Attckr Bonus
    SPELL_AURA_MOD_POSSESS_PET = 128,                   // Mod Possess Pet
    SPELL_AURA_MOD_INCREASE_SPEED_ALWAYS = 129,         // Mod Speed Always
    SPELL_AURA_MOD_MOUNTED_SPEED_ALWAYS = 130,          // Mod Mounted Speed Always
    SPELL_AURA_MOD_CREATURE_RANGED_ATTACK_POWER = 131,  // Mod Creature Ranged Attack Power
    SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT = 132,       // Mod Increase Energy %
    SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT = 133,       // Mod Max Health %
    SPELL_AURA_MOD_MANA_REGEN_INTERRUPT = 134,          // Mod Interrupted Mana Regen
    SPELL_AURA_MOD_HEALING_DONE = 135,                  // Mod Healing Done
    SPELL_AURA_MOD_HEALING_DONE_PERCENT = 136,          // Mod Healing Done %
    SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE = 137,         // Mod Total Stat %
    SPELL_AURA_MOD_HASTE = 138,                         // Haste - Melee
    SPELL_AURA_FORCE_REACTION = 139,                    // Force Reaction
    SPELL_AURA_MOD_RANGED_HASTE = 140,                  // Haste - Ranged
    SPELL_AURA_MOD_RANGED_AMMO_HASTE = 141,             // Haste - Ranged (Ammo Only)
    SPELL_AURA_MOD_BASE_RESISTANCE_PCT = 142,           // Mod Base Resistance %
    SPELL_AURA_MOD_RESISTANCE_EXCLUSIVE = 143,          // Mod Resistance Exclusive
    SPELL_AURA_SAFE_FALL = 144,                         // Safe Fall
	SPELL_AURA_MOD_PET_TALENT_POINTS = 145,             // Mod Pet Talent Points
    SPELL_AURA_PERSUADED = 146,                         // Persuaded
    SPELL_AURA_ADD_CREATURE_IMMUNITY = 147,             // Add Creature Immunity
    SPELL_AURA_RETAIN_COMBO_POINTS = 148,               // Retain Combo Points
    SPELL_AURA_RESIST_PUSHBACK = 149,                   // Resist Pushback
    SPELL_AURA_MOD_SHIELD_BLOCK_PCT = 150,              // Mod Shield Block %
    SPELL_AURA_TRACK_STEALTHED = 151,                   // Track Stealthed
    SPELL_AURA_MOD_DETECTED_RANGE = 152,                // Mod Detected Range
    SPELL_AURA_SPLIT_DAMAGE_FLAT = 153,                 // Split Damage Flat
    SPELL_AURA_MOD_STEALTH_LEVEL = 154,                 // Stealth Level Modifier
    SPELL_AURA_MOD_WATER_BREATHING = 155,               // Mod Water Breathing
    SPELL_AURA_MOD_REPUTATION_ADJUST = 156,             // Mod Reputation Gain
    SPELL_AURA_PET_DAMAGE_MULTI = 157,                  // Mod Pet Damage
    SPELL_AURA_MOD_SHIELD_BLOCK = 158,                  // Mod Shield Block
    SPELL_AURA_NO_PVP_CREDIT = 159,                     // No PVP Credit
    SPELL_AURA_MOD_SIDE_REAR_PDAE_DAMAGE_TAKEN = 160,   // Mod Side/Rear PBAE Damage Taken
    SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT = 161,        // Mod Health Regen In Combat
    SPELL_AURA_POWER_BURN = 162,                        // Power Burn
    SPELL_AURA_MOD_CRIT_DAMAGE_BONUS_MELEE = 163,       // Mod Critical Damage Bonus (Physical)
    SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS = 165, // Melee AP Attacker Bonus
    SPELL_AURA_MOD_ATTACK_POWER_PCT = 166,              // Mod Attack Power
    SPELL_AURA_MOD_RANGED_ATTACK_POWER_PCT = 167,       // Mod Ranged Attack Power %
    SPELL_AURA_INCREASE_DAMAGE = 168,                   // Increase Damage Type
    SPELL_AURA_INCREASE_CRITICAL = 169,                 // Increase Critical Type
    SPELL_AURA_DETECT_AMORE = 170,                      // Detect Amore
    SPELL_AURA_INCREASE_MOVEMENT_AND_MOUNTED_SPEED = 172,// Increase Movement and Mounted Speed (Non-Stacking)
    SPELL_AURA_INCREASE_SPELL_DAMAGE_PCT = 174,         // Increase Spell Damage by % status
    SPELL_AURA_INCREASE_SPELL_HEALING_PCT = 175,        // Increase Spell Healing by % status
    SPELL_AURA_SPIRIT_OF_REDEMPTION = 176,              // Spirit of Redemption Auras
    SPELL_AURA_AREA_CHARM = 177,                        // Area Charm
    SPELL_AURA_INCREASE_ATTACKER_SPELL_CRIT = 179,      // Increase Attacker Spell Crit Type
    SPELL_AURA_INCREASE_SPELL_DAMAGE_VS_TYPE = 180,     // Increase Spell Damage Type
    SPELL_AURA_INCREASE_ARMOR_BASED_ON_INTELLECT_PCT = 182, // Increase Armor based on Intellect
    SPELL_AURA_DECREASE_CRIT_THREAT = 183,              // Decrease Critical Threat by
    SPELL_AURA_DECREASE_ATTACKER_CHANCE_TO_HIT_MELEE = 184,//Reduces Attacker Chance to Hit with Melee
    SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_HIT_RANGED = 185,// Reduces Attacker Chance to Hit with Ranged
    SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_HIT_SPELLS = 186,// Reduces Attacker Chance to Hit with Spells
    SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_CRIT_MELEE = 187,// Reduces Attacker Chance to Crit with Melee (Ranged?)
    SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_CRIT_RANGED = 188,// Reduces Attacker Chance to Crit with Ranged (Melee?)
    SPELL_AURA_INCREASE_REPUTATION = 190,               // Increases reputation from killed creatures
    SPELL_AURA_SPEED_LIMIT = 191,                       // speed limit
    SPELL_AURA_MELEE_SLOW_PCT = 192,
    SPELL_AURA_INCREASE_TIME_BETWEEN_ATTACKS = 193,
    SPELL_AURA_INREASE_SPELL_DAMAGE_PCT_OF_INTELLECT = 194,  // NOT USED ANYMORE - 174 used instead
    SPELL_AURA_INCREASE_HEALING_PCT_OF_INTELLECT = 195,		// NOT USED ANYMORE - 175 used instead
    SPELL_AURA_MOD_ALL_WEAPON_SKILLS = 196,
    SPELL_AURA_REDUCE_ATTACKER_CRICTICAL_HIT_CHANCE_PCT = 197,
    SPELL_AURA_INCREASE_SPELL_HIT_PCT = 199,
    SPELL_AURA_CANNOT_BE_DODGED = 201,
	SPELL_AURA_FINISHING_MOVES_CANNOT_BE_DODGED = 202,
    SPELL_AURA_REDUCE_ATTACKER_CRICTICAL_HIT_DAMAGE_MELEE_PCT = 203,
    SPELL_AURA_REDUCE_ATTACKER_CRICTICAL_HIT_DAMAGE_RANGED_PCT = 204,
    SPELL_AURA_INCREASE_RANGED_ATTACK_POWER_PCT_OF_INTELLECT = 212,
    SPELL_AURA_INCREASE_RAGE_FROM_DAMAGE_DEALT_PCT = 213,
    SPELL_AURA_INCREASE_CASTING_TIME_PCT = 216,
	SPELL_AURA_HASTE_RANGED = 218,
    SPELL_AURA_REGEN_MANA_STAT_PCT=219,
    SPELL_AURA_HEALING_STAT_PCT=220,
	SPELL_AURA_REDUCE_AOE_DAMAGE_TAKEN = 229,
    SPELL_AURA_INCREASE_MAX_HEALTH=230,//Used by Commanding Shout
	SPELL_AURA_VEHICLE_PASSENGER=236,
	SPELL_AURA_MODIFY_AXE_SKILL=240,
	SPELL_AURA_ADD_HEALTH=250,
	SPELL_AURA_MOD_DOT_DAMAGE_DONE_BY_MECHANIC=255,
	SPELL_AURA_NO_REAGENT=256,
	SPELL_AURA_SET_PHASE=261,
	SPELL_AURA_FROZEN_TARGET=262,
	SPELL_AURA_INCREASE_AP_BY_ATTRIBUTE=268,
	SPELL_AURA_INCREASE_SPELL_DOT_DAMAGE_PCT = 271,
	SPELL_AURA_REDIRECT_THREAT = 277,
	SPELL_AURA_IGNORE_ARMOR_PCT=280,
	SPELL_AURA_MOD_BASE_HEALTH = 282,
	SPELL_AURA_REFLECT_INFRONT = 287,
    TOTAL_SPELL_AURAS = 288,
};
enum AuraTickFlags
{
    FLAG_PERIODIC_DAMAGE            = 3,	// also 89
    FLAG_PERIODIC_HEAL              = 8,	// also 20
    FLAG_PERIODIC_ENERGIZE          = 21,	// also 24
	FLAG_PERIODIC_LEECH             = 64,
};
enum AuraFlags
{
    AFLAG_NONE              = 0x00,
    AFLAG_VISIBLE           = 0x01,
    AFLAG_EFF_INDEX_1       = 0x02,
    AFLAG_EFF_INDEX_2       = 0x04,
    AFLAG_NOT_GUID          = 0x08,
    AFLAG_CANCELLABLE       = 0x10,
    AFLAG_HAS_DURATION      = 0x20,
    AFLAG_UNK2              = 0x40,
    AFLAG_NEGATIVE          = 0x80,
    AFLAG_POSITIVE          = 0x1F,
    AFLAG_MASK              = 0xFF
};

enum AURAIMMUNE_FLAG
{
	AURAIMMUNE_NONE				= 0x0,
	AURAIMMUNE_CONFUSE			= 0X1,			//SPELL_AURA_MOD_CONFUSE = 5
	AURAIMMUNE_CHARM			= 0x2,			//SPELL_AURA_MOD_CHARM = 6
	AURAIMMUNE_FEAR				= 0X4,			//SPELL_AURA_MOD_FEAR = 7
	AURAIMMUNE_STUN				= 0x8,			//SPELL_AURA_MOD_STUN = 12
	AURAIMMUNE_PACIFY			= 0x10,			//SPELL_AURA_MOD_PACIFY = 25
	AURAIMMUNE_ROOT				= 0x20,			//SPELL_AURA_MOD_ROOT = 26
	AURAIMMUNE_SILENCE			= 0x40,			//SPELL_AURA_MOD_SILENCE = 27
	AURAIMMUNE_INCSPEED			= 0x80,         //SPELL_AURA_MOD_INCREASE_SPEED = 31
	AURAIMMUNE_DECSPEED			= 0x100,		//SPELL_AURA_MOD_DECREASE_SPEED = 33
	AURAIMMUNE_TRANSFORM		= 0x200,		//SPELL_AURA_TRANSFORM = 56
	AURAIMMUNE_TAUNT			= 0x400,		//SPELL_AURA_MOD_TAUNT = 11
	AURAIMMUNE_BLEED			= 0x800,		//MECHANIC BLEED = 15
	AURAIMMUNE_POISON			= 0x1000,		//DISPEL TYPE POISON = 4
	AURAIMMUNE_MANALEECH		= 0x2000,		//SPELL_AURA_PERIODIC_MANA_LEECH = 64,
	AURAIMMUNE_LEECH			= 0x4000,		//SPELL_AURA_PERIODIC_LEECH = 53

	AURAIMMUNE_GENERIC_BOSS     = AURAIMMUNE_CONFUSE | AURAIMMUNE_CHARM | AURAIMMUNE_FEAR |
								  AURAIMMUNE_STUN | AURAIMMUNE_PACIFY | AURAIMMUNE_ROOT |
								  AURAIMMUNE_SILENCE | AURAIMMUNE_INCSPEED | AURAIMMUNE_DECSPEED |
								  AURAIMMUNE_TRANSFORM, //1023
};

enum SpellCastError
{
	SPELL_FAILED_SUCCESS                                         = 0,
	SPELL_FAILED_AFFECTING_COMBAT                                = 1,
	SPELL_FAILED_ALREADY_AT_FULL_HEALTH                          = 2,
	SPELL_FAILED_ALREADY_AT_FULL_MANA                            = 3,
	SPELL_FAILED_ALREADY_AT_FULL_POWER                           = 4,
	SPELL_FAILED_ALREADY_BEING_TAMED                             = 5,
	SPELL_FAILED_ALREADY_HAVE_CHARM                              = 6,
	SPELL_FAILED_ALREADY_HAVE_SUMMON                             = 7,
	SPELL_FAILED_ALREADY_OPEN                                    = 8,
	SPELL_FAILED_AURA_BOUNCED                                    = 9,
	SPELL_FAILED_AUTOTRACK_INTERRUPTED                           = 10,
	SPELL_FAILED_BAD_IMPLICIT_TARGETS                            = 11,
	SPELL_FAILED_BAD_TARGETS                                     = 12,
	SPELL_FAILED_CANT_BE_CHARMED                                 = 13,
	SPELL_FAILED_CANT_BE_DISENCHANTED                            = 14,
	SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL                      = 15,
	SPELL_FAILED_CANT_BE_MILLED                                  = 16,
	SPELL_FAILED_CANT_BE_PROSPECTED                              = 17,
	SPELL_FAILED_CANT_CAST_ON_TAPPED                             = 18,
	SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE                       = 19,
	SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED                       = 20,
	SPELL_FAILED_CANT_STEALTH                                    = 21,
	SPELL_FAILED_CASTER_AURASTATE                                = 22,
	SPELL_FAILED_CASTER_DEAD                                     = 23,
	SPELL_FAILED_CHARMED                                         = 24,
	SPELL_FAILED_CHEST_IN_USE                                    = 25,
	SPELL_FAILED_CONFUSED                                        = 26,
	SPELL_FAILED_DONT_REPORT                                     = 27,
	SPELL_FAILED_EQUIPPED_ITEM                                   = 28,
	SPELL_FAILED_EQUIPPED_ITEM_CLASS                             = 29,
	SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND                    = 30,
	SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND                     = 31,
	SPELL_FAILED_ERROR                                           = 32,
	SPELL_FAILED_FIZZLE                                          = 33,
	SPELL_FAILED_FLEEING                                         = 34,
	SPELL_FAILED_FOOD_LOWLEVEL                                   = 35,
	SPELL_FAILED_HIGHLEVEL                                       = 36,
	SPELL_FAILED_HUNGER_SATIATED                                 = 37,
	SPELL_FAILED_IMMUNE                                          = 38,
	SPELL_FAILED_INCORRECT_AREA                                  = 39,
	SPELL_FAILED_INTERRUPTED                                     = 40,
	SPELL_FAILED_INTERRUPTED_COMBAT                              = 41,
	SPELL_FAILED_ITEM_ALREADY_ENCHANTED                          = 42,
	SPELL_FAILED_ITEM_GONE                                       = 43,
	SPELL_FAILED_ITEM_NOT_FOUND                                  = 44,
	SPELL_FAILED_ITEM_NOT_READY                                  = 45,
	SPELL_FAILED_LEVEL_REQUIREMENT                               = 46,
	SPELL_FAILED_LINE_OF_SIGHT                                   = 47,
	SPELL_FAILED_LOWLEVEL                                        = 48,
	SPELL_FAILED_LOW_CASTLEVEL                                   = 49,
	SPELL_FAILED_MAINHAND_EMPTY                                  = 50,
	SPELL_FAILED_MOVING                                          = 51,
	SPELL_FAILED_NEED_AMMO                                       = 52,
	SPELL_FAILED_NEED_AMMO_POUCH                                 = 53,
	SPELL_FAILED_NEED_EXOTIC_AMMO                                = 54,
	SPELL_FAILED_NEED_MORE_ITEMS                                 = 55,
	SPELL_FAILED_NOPATH                                          = 56,
	SPELL_FAILED_NOT_BEHIND                                      = 57,
	SPELL_FAILED_NOT_FISHABLE                                    = 58,
	SPELL_FAILED_NOT_FLYING                                      = 59,
	SPELL_FAILED_NOT_HERE                                        = 60,
	SPELL_FAILED_NOT_INFRONT                                     = 61,
	SPELL_FAILED_NOT_IN_CONTROL                                  = 62,
	SPELL_FAILED_NOT_KNOWN                                       = 63,
	SPELL_FAILED_NOT_MOUNTED                                     = 64,
	SPELL_FAILED_NOT_ON_TAXI                                     = 65,
	SPELL_FAILED_NOT_ON_TRANSPORT                                = 66,
	SPELL_FAILED_NOT_READY                                       = 67,
	SPELL_FAILED_NOT_SHAPESHIFT                                  = 68,
	SPELL_FAILED_NOT_STANDING                                    = 69,
	SPELL_FAILED_NOT_TRADEABLE                                   = 70,
	SPELL_FAILED_NOT_TRADING                                     = 71,
	SPELL_FAILED_NOT_UNSHEATHED                                  = 72,
	SPELL_FAILED_NOT_WHILE_GHOST                                 = 73,
	SPELL_FAILED_NOT_WHILE_LOOTING                               = 74,
	SPELL_FAILED_NO_AMMO                                         = 75,
	SPELL_FAILED_NO_CHARGES_REMAIN                               = 76,
	SPELL_FAILED_NO_CHAMPION                                     = 77,
	SPELL_FAILED_NO_COMBO_POINTS                                 = 78,
	SPELL_FAILED_NO_DUELING                                      = 79,
	SPELL_FAILED_NO_ENDURANCE                                    = 80,
	SPELL_FAILED_NO_FISH                                         = 81,
	SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED                     = 82,
	SPELL_FAILED_NO_MOUNTS_ALLOWED                               = 83,
	SPELL_FAILED_NO_PET                                          = 84,
	SPELL_FAILED_NO_POWER                                        = 85,
	SPELL_FAILED_NOTHING_TO_DISPEL                               = 86,
	SPELL_FAILED_NOTHING_TO_STEAL                                = 87,
	SPELL_FAILED_ONLY_ABOVEWATER                                 = 88,
	SPELL_FAILED_ONLY_DAYTIME                                    = 89,
	SPELL_FAILED_ONLY_INDOORS                                    = 90,
	SPELL_FAILED_ONLY_MOUNTED                                    = 91,
	SPELL_FAILED_ONLY_NIGHTTIME                                  = 92,
	SPELL_FAILED_ONLY_OUTDOORS                                   = 93,
	SPELL_FAILED_ONLY_SHAPESHIFT                                 = 94,
	SPELL_FAILED_ONLY_STEALTHED                                  = 95,
	SPELL_FAILED_ONLY_UNDERWATER                                 = 96,
	SPELL_FAILED_OUT_OF_RANGE                                    = 97,
	SPELL_FAILED_PACIFIED                                        = 98,
	SPELL_FAILED_POSSESSED                                       = 99,
	SPELL_FAILED_REAGENTS                                        = 100,
	SPELL_FAILED_REQUIRES_AREA                                   = 101,
	SPELL_FAILED_REQUIRES_SPELL_FOCUS                            = 102,
	SPELL_FAILED_ROOTED                                          = 103,
	SPELL_FAILED_SILENCED                                        = 104,
	SPELL_FAILED_SPELL_IN_PROGRESS                               = 105,
	SPELL_FAILED_SPELL_LEARNED                                   = 106,
	SPELL_FAILED_SPELL_UNAVAILABLE                               = 107,
	SPELL_FAILED_STUNNED                                         = 108,
	SPELL_FAILED_TARGETS_DEAD                                    = 109,
	SPELL_FAILED_TARGET_AFFECTING_COMBAT                         = 110,
	SPELL_FAILED_TARGET_AURASTATE                                = 111,
	SPELL_FAILED_TARGET_DUELING                                  = 112,
	SPELL_FAILED_TARGET_ENEMY                                    = 113,
	SPELL_FAILED_TARGET_ENRAGED                                  = 114,
	SPELL_FAILED_TARGET_FRIENDLY                                 = 115,
	SPELL_FAILED_TARGET_IN_COMBAT                                = 116,
	SPELL_FAILED_TARGET_IS_PLAYER                                = 117,
	SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED                     = 118,
	SPELL_FAILED_TARGET_NOT_DEAD                                 = 119,
	SPELL_FAILED_TARGET_NOT_IN_PARTY                             = 120,
	SPELL_FAILED_TARGET_NOT_LOOTED                               = 121,
	SPELL_FAILED_TARGET_NOT_PLAYER                               = 122,
	SPELL_FAILED_TARGET_NO_POCKETS                               = 123,
	SPELL_FAILED_TARGET_NO_WEAPONS                               = 124,
	SPELL_FAILED_TARGET_NO_RANGED_WEAPONS                        = 125,
	SPELL_FAILED_TARGET_UNSKINNABLE                              = 126,
	SPELL_FAILED_THIRST_SATIATED                                 = 127,
	SPELL_FAILED_TOO_CLOSE                                       = 128,
	SPELL_FAILED_TOO_MANY_OF_ITEM                                = 129,
	SPELL_FAILED_TOTEM_CATEGORY                                  = 130,
	SPELL_FAILED_TOTEMS                                          = 131,
	SPELL_FAILED_TRY_AGAIN                                       = 132,
	SPELL_FAILED_UNIT_NOT_BEHIND                                 = 133,
	SPELL_FAILED_UNIT_NOT_INFRONT                                = 134,
	SPELL_FAILED_WRONG_PET_FOOD                                  = 135,
	SPELL_FAILED_NOT_WHILE_FATIGUED                              = 136,
	SPELL_FAILED_TARGET_NOT_IN_INSTANCE                          = 137,
	SPELL_FAILED_NOT_WHILE_TRADING                               = 138,
	SPELL_FAILED_TARGET_NOT_IN_RAID                              = 139,
	SPELL_FAILED_TARGET_FREEFORALL                               = 140,
	SPELL_FAILED_NO_EDIBLE_CORPSES                               = 141,
	SPELL_FAILED_ONLY_BATTLEGROUNDS                              = 142,
	SPELL_FAILED_TARGET_NOT_GHOST                                = 143,
	SPELL_FAILED_TRANSFORM_UNUSABLE                              = 144,
	SPELL_FAILED_WRONG_WEATHER                                   = 145,
	SPELL_FAILED_DAMAGE_IMMUNE                                   = 146,
	SPELL_FAILED_PREVENTED_BY_MECHANIC                           = 147,
	SPELL_FAILED_PLAY_TIME                                       = 148,
	SPELL_FAILED_REPUTATION                                      = 149,
	SPELL_FAILED_MIN_SKILL                                       = 150,
	SPELL_FAILED_NOT_IN_ARENA                                    = 151,
	SPELL_FAILED_NOT_ON_SHAPESHIFT                               = 152,
	SPELL_FAILED_NOT_ON_STEALTHED                                = 153,
	SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE                            = 154,
	SPELL_FAILED_NOT_ON_MOUNTED                                  = 155,
	SPELL_FAILED_TOO_SHALLOW                                     = 156,
	SPELL_FAILED_TARGET_NOT_IN_SANCTUARY                         = 157,
	SPELL_FAILED_TARGET_IS_TRIVIAL                               = 158,
	SPELL_FAILED_BM_OR_INVISGOD                                  = 159,
	SPELL_FAILED_EXPERT_RIDING_REQUIREMENT                       = 160,
	SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT                      = 161,
	SPELL_FAILED_NOT_IDLE                                        = 162,
	SPELL_FAILED_NOT_INACTIVE                                    = 163,
	SPELL_FAILED_PARTIAL_PLAYTIME                                = 164,
	SPELL_FAILED_NO_PLAYTIME                                     = 165,
	SPELL_FAILED_NOT_IN_BATTLEGROUND                             = 166,
	SPELL_FAILED_NOT_IN_RAID_INSTANCE                            = 167,
	SPELL_FAILED_ONLY_IN_ARENA                                   = 168,
	SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE                  = 169,
	SPELL_FAILED_ON_USE_ENCHANT                                  = 170,
	SPELL_FAILED_NOT_ON_GROUND                                   = 171,
	SPELL_FAILED_CUSTOM_ERROR                                    = 172,
	SPELL_FAILED_TOO_MANY_SOCKETS                                = 173,
	SPELL_FAILED_INVALID_GLYPH                                   = 174,
	SPELL_FAILED_UNIQUE_GLYPH                                    = 175,
	SPELL_FAILED_GLYPH_SOCKET_LOCKED                             = 176,
	SPELL_FAILED_NO_VALID_TARGETS                                = 177,
	SPELL_FAILED_ITEM_AT_MAX_CHARGES                             = 178,
	SPELL_FAILED_NOT_IN_BARBERSHOP                               = 179,
	SPELL_FAILED_FISHING_TOO_LOW                                 = 180,
	SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW                       = 181,
	SPELL_FAILED_SUMMON_PENDING                                  = 182,
	SPELL_FAILED_MAX_SOCKETS                                     = 183,
	SPELL_FAILED_PET_CAN_RENAME                                  = 184,
	SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED                    = 185,
	SPELL_FAILED_UNKNOWN                                         = 186,
	SPELL_CANCAST_OK                                             = 255,
};

//wooohooo, there are 19 spells that actually require to add a proccounter for these
//first spell catched is "presence of mind"
//an ugly solution would be to add a proc flag to remove aura on event it should expire (like attack or cast) but that is only if count=1
enum SPELL_MODIFIER_TYPE
{
	SMT_DAMAGE_DONE				= 0,// increases the damage done by spell by x% dmg (flat as x dmg)
	SMT_DURATION				= 1,// spell	duration increase	// GOOD
	//hmm shaman spirit weapon clearly states that this should be parry chance
	SMT_THREAT_REDUCED			= 2,// reduces threat generated by this spell by x%	// GOOD but need more work
	SMT_FIRST_EFFECT_BONUS		= 3,// modifies points of second spell effect	// GOOD
	SMT_CHARGES					= 4,// increases the number of charges
	SMT_RANGE					= 5,// spell range bonus	// GOOD
	SMT_RADIUS					= 6,// spell radius bonus	// GOOD
	SMT_CRITICAL				= 7,// critical chance bonus	// GOOD	//only 1 example in 2.1.1
	SMT_MISC_EFFECT				= 8,// dummy effect	// needs work is not only pets Hp but effect of spells to
	SMT_NONINTERRUPT			= 9,// x% chance not to be interrupted by received damage (no flat)
	SMT_CAST_TIME				= 10,// cast time decrease	// GOOD
	SMT_COOLDOWN_DECREASE		= 11,// cooldown decrease <-probably fully handled by client	// GOOD
	SMT_SECOND_EFFECT_BONUS		= 12,// modifies points of second spell effect	// GOOD
	// 13 dont exist spells with it
	SMT_COST					= 14,// mana/energy/rage cost reduction	// GOOD
	SMT_CRITICAL_DAMAGE			= 15,// increases critical strike damage bonus (no flat)
	SMT_HITCHANCE				= 16,// enemy resist chance decrease (flat as %)	// GOOD need work
	SMT_ADDITIONAL_TARGET		= 17,// Your Healing Wave will now jump to additional nearby targets. Each jump reduces the effectiveness of the heal by 80%	// GOOD
	SMT_PROC_CHANCE				= 18,// adds/increases chance to trigger some spell for example increase chance to apply poisons or entaglin	// GOOD need work
	SMT_TIME					= 19,// delay for nova, redirection time bonus for totem,maybe smth else	// GOOD need work
	SMT_JUMP_REDUCE				= 20,// Increases the amount healed by Chain Heal to targets beyond the first by x%. (no flat)
	SMT_GLOBAL_COOLDOWN			= 21,// Reduces the global cooldown
	//!!! most spells have both SMT_DAMAGE_DONE and this value. Be carefull case there is no need to apply both !
	SMT_SPELL_VALUE_PCT			= 22,// damage done by ability by x% : SELECT id,name,description FROM dbc_spell where (EffectApplyAuraName_1=108 and EffectMiscValue_1=22) or (EffectApplyAuraName_2=108 and EffectMiscValue_2=22) or (EffectApplyAuraName_3=108 and EffectMiscValue_3=22)	its DoT actually
	SMT_LAST_EFFECT_BONUS		= 23,// increases points of last effect in affected spells	// GOOD
	SMT_SPD_BONUS				= 24,// This is a modifer for the amount of +spell damage applied to the spell group from spell bonuses
	// 25 dont exist spells with it
	// 26 is obsolete stuff
	SMT_MULTIPLE_VALUE			= 27,// mana lost cost per point of damage taken for mana shield,Health or Mana gained from Drain Life and Drain Mana increased by x%.
	SMT_RESIST_DISPEL			= 28,// GOOD
	// 29 Mod Crowd Damage Test 45365 - Increases the critical strike damage bonus of your Frost spells by 100%
};

static void SM_FFValue( int32* m, float* v, uint32* group )
{
    if( m == 0 )
		return;

    uint32 intbit = 0, groupnum = 0;
	for(uint32 bit = 0; bit < SPELL_GROUPS; ++bit, ++intbit)
	{
		if(intbit == 32)
		{
			++groupnum;
			intbit = 0;
		}
		if( ( 1 << intbit ) & group[groupnum] )
			(*v) += m[bit];
	}
}

static void SM_FIValue( int32* m, int32* v, uint32* group )
{
    if( m == 0 )
		return;

	uint32 intbit = 0, groupnum = 0;
	for(uint32 bit = 0; bit < SPELL_GROUPS; ++bit, ++intbit)
	{
		if(intbit == 32)
		{
			++groupnum;
			intbit = 0;
		}
		if( ( 1 << intbit ) & group[groupnum] )
			(*v) += m[bit];
	}
}

static void SM_PIValue( int32* m, int32* v, uint32* group )
{
    if( m == 0 )
		return;

	uint32 intbit = 0, groupnum = 0;
	for(uint32 bit = 0; bit < SPELL_GROUPS; ++bit, ++intbit)
	{
		if(intbit == 32)
		{
			++groupnum;
			intbit = 0;
		}
		if( ( 1 << intbit ) & group[groupnum] )
			(*v) += ( (*v) * m[bit] ) / 100;
	}
}

static void SM_PFValue( int32* m, float* v, uint32* group )
{
    if( m == 0 )
		return;

	uint32 intbit = 0, groupnum = 0;
	for(uint32 bit = 0; bit < SPELL_GROUPS; ++bit, ++intbit)
	{
		if(intbit == 32)
		{
			++groupnum;
			intbit = 0;
		}
		if( ( 1 << intbit ) & group[groupnum] )
			(*v) += ( (*v) * m[bit] ) / 100.0f;
	}
}

enum SPELL_DMG_TYPE // SPELL_ENTRY_Spell_Dmg_Type
{
	SPELL_DMG_TYPE_NONE   = 0,
	SPELL_DMG_TYPE_MAGIC  = 1,
	SPELL_DMG_TYPE_MELEE  = 2,
	SPELL_DMG_TYPE_RANGED = 3
};

// value's for SendSpellLog
enum SPELL_LOG
{
    SPELL_LOG_NONE,
    SPELL_LOG_MISS,
    SPELL_LOG_RESIST,
    SPELL_LOG_DODGE,
    SPELL_LOG_PARRY,
    SPELL_LOG_BLOCK,
    SPELL_LOG_EVADE,
    SPELL_LOG_IMMUNE,
    SPELL_LOG_IMMUNE2,
    SPELL_LOG_DEFLECT,
    SPELL_LOG_ABSORB,
    SPELL_LOG_REFLECT
};

enum SpellCastTargetFlags
{
    TARGET_FLAG_SELF                = 0x0000, // they are checked in following order
    TARGET_FLAG_UNK1                = 0x0001,
    TARGET_FLAG_UNIT                = 0x0002,
    TARGET_FLAG_UNK2                = 0x0004,
    TARGET_FLAG_UNK3                = 0x0008,
    TARGET_FLAG_ITEM                = 0x0010,
    TARGET_FLAG_SOURCE_LOCATION     = 0x0020,
    TARGET_FLAG_DEST_LOCATION       = 0x0040,
    TARGET_FLAG_UNK6                = 0x0080,
    TARGET_FLAG_UNK7                = 0x0100,
    TARGET_FLAG_CORPSE              = 0x0200,
    TARGET_FLAG_UNK8                = 0x0400,
    TARGET_FLAG_OBJECT              = 0x0800,
    TARGET_FLAG_TRADE_ITEM          = 0x1000,
    TARGET_FLAG_STRING              = 0x2000,
    TARGET_FLAG_ITEM2               = 0x4000,
    TARGET_FLAG_CORPSE2             = 0x8000,
	TARGET_FLAG_GLYPH				= 0x20000,
};

enum procFlags
{
    PROC_NULL                       = 0x0,
    PROC_ON_ANY_HOSTILE_ACTION      = 0x1,
    PROC_ON_GAIN_EXPIERIENCE        = 0x2,
    PROC_ON_MELEE_ATTACK            = 0x4,
    PROC_ON_CRIT_HIT_VICTIM         = 0x8,
    PROC_ON_CAST_SPELL              = 0x10,
    PROC_ON_PHYSICAL_ATTACK_VICTIM  = 0x20,
    PROC_ON_RANGED_ATTACK           = 0x40,
    PROC_ON_RANGED_CRIT_ATTACK      = 0x80,
//    PROC_ON_UNK_DAMAGE_VICTIM       = 0x80,//seems to be on ranged dmg victim 99% sure('each melee or ranged attack' -> flag =680 (dec))
    PROC_ON_PHYSICAL_ATTACK         = 0x100,
    PROC_ON_MELEE_ATTACK_VICTIM     = 0x200,
//    PROC_ON_ANY_ACTION              = 0x400,
    PROC_ON_SPELL_LAND              = 0x400,
//    PROC_UNK_DEFILLED               = 0x800,
    PROC_ON_RANGED_CRIT_ATTACK_VICTIM = 0x800,
    PROC_ON_CRIT_ATTACK             = 0x1000,
    PROC_ON_RANGED_ATTACK_VICTIM    = 0x2000,
//    PROC_ANYTIME                    = 0x4000,
    PROC_ON_DISPEL_AURA_VICTIM		= 0x4000,
//    PROC_UNK2_DEFILLED              = 0x8000,
	PROC_ON_SPELL_LAND_VICTIM       = 0x8000,//custom flag. PROC only when spell landed on victim
    PROC_ON_CAST_SPECIFIC_SPELL     = 0x10000,
    PROC_ON_SPELL_HIT_VICTIM        = 0x20000,
    PROC_ON_SPELL_CRIT_HIT_VICTIM   = 0x40000,
//    PROC_ON_UNK2_DAMAGE_VICTIM      = 0x80000,
    PROC_ON_TARGET_DIE		        = 0x80000,
    PROC_ON_ANY_DAMAGE_VICTIM       = 0x100000,
	PROC_ON_TRAP_TRIGGER            = 0x200000, //triggers on trap activation)
    PROC_ON_AUTO_SHOT_HIT           = 0x400000,
    PROC_ON_ABSORB                  = 0x800000,
	PROC_ON_FULL_RESIST		        = 0x1000000,//added it as custom, maybe already exists in another form ?
    PROC_ON_DODGE_VICTIM            = 0x2000000,//added it as custom, maybe already exists in another form ?
    PROC_ON_DIE                     = 0x4000000,//added it as custom, maybe already exists in another form ?
    PROC_REMOVEONUSE                = 0x8000000,//remove prochcharge only when it is used
    PROC_MISC		                = 0x10000000,// depending on destination, flag can be freely used (spell cant visit strike function)
    PROC_ON_BLOCK_VICTIM            = 0x20000000,//added it as custom, maybe already exists in another form ?
    PROC_ON_SPELL_CRIT_HIT          = 0x40000000,//added it as custom, maybe already exists in another form ?
    PROC_TARGET_SELF               = 0x80000000,//our custom flag to decide if proc target is self or victim
};

enum CastInterruptFlags
{
    CAST_INTERRUPT_NULL            = 0x0,
    CAST_INTERRUPT_ON_SILENCE      = 0x1,
    CAST_INTERRUPT_ON_SLEEP        = 0x2, // could be wrong
    CAST_INTERRUPT_ON_STUNNED      = 0x4, // could be wrong
    CAST_INTERRUPT_ON_MOVEMENT     = 0x8,
    CAST_INTERRUPT_ON_DAMAGE_TAKEN = 0x10
};

/************************************************************************/
/* General Spell Go Flags, for documentation reasons                    */
/************************************************************************/
enum SpellGoFlags
{
	SPELL_GO_FLAGS_NONE					= 0x00000000,
	SPELL_GO_FLAGS_UNKNOWN0				= 0x00000001,              // may be pending spell cast
	SPELL_GO_FLAGS_UNKNOWN1				= 0x00000002,
	SPELL_GO_FLAGS_UNKNOWN2				= 0x00000004,
	SPELL_GO_FLAGS_UNKNOWN3				= 0x00000008,
	SPELL_GO_FLAGS_UNKNOWN4				= 0x00000010,
	SPELL_GO_FLAGS_RANGED				= 0x00000020,
	SPELL_GO_FLAGS_UNKNOWN6				= 0x00000040,
	SPELL_GO_FLAGS_UNKNOWN7				= 0x00000080,
	SPELL_GO_FLAGS_ITEM_CASTER			= 0x00000100,
	SPELL_GO_FLAGS_UNKNOWN9				= 0x00000200,
	SPELL_GO_FLAGS_EXTRA_MESSAGE		= 0x00000400, //TARGET MISSES AND OTHER MESSAGES LIKE "Resist"
	SPELL_GO_FLAGS_POWER_UPDATE			= 0x00000800,
	SPELL_GO_FLAGS_UNKNOWN12			= 0x00001000,
	SPELL_GO_FLAGS_UNKNOWN13			= 0x00002000,
	SPELL_GO_FLAGS_UNKNOWN14			= 0x00004000,
	SPELL_GO_FLAGS_UNKNOWN15			= 0x00008000,
	SPELL_GO_FLAGS_UNKNOWN16			= 0x00010000,
    SPELL_GO_FLAGS_UNKNOWN17			= 0x00020000,
	SPELL_GO_FLAGS_UNKNOWN18			= 0x00040000,
	SPELL_GO_FLAGS_UNKNOWN19			= 0x00080000,
	SPELL_GO_FLAGS_UNKNOWN20			= 0x00100000,
	SPELL_GO_FLAGS_RUNE_UPDATE			= 0x00200000,
	SPELL_GO_FLAGS_UNKNOWN22			= 0x00400000,
};

enum AuraInterruptFlags
{
    AURA_INTERRUPT_NULL                       = 0x0,
    AURA_INTERRUPT_ON_HOSTILE_SPELL_INFLICTED = 0x1,
    AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN        = 0x2,
    AURA_INTERRUPT_ON_UNK1                    = 0x4,
    AURA_INTERRUPT_ON_MOVEMENT                = 0x8, // could be AURA_INTERRUPT_ON_MOVEMENT
    AURA_INTERRUPT_ON_UNK2                    = 0x10,
    AURA_INTERRUPT_ON_UNK3                    = 0x20,
    AURA_INTERRUPT_ON_UNUSED1                 = 0x40,
    AURA_INTERRUPT_ON_SLOWED                  = 0x80,
    AURA_INTERRUPT_ON_LEAVE_WATER             = 0x100, // could be AURA_INTERRUPT_ON_LEAVE_CURRENT_SURFACE
    AURA_INTERRUPT_ON_UNUSED2                 = 0x200,
    AURA_INTERRUPT_ON_UNK4                    = 0x400,
    AURA_INTERRUPT_ON_UNK5                    = 0x800,
    AURA_INTERRUPT_ON_START_ATTACK            = 0x1000,
    AURA_INTERRUPT_ON_UNK6                    = 0x2000,
    AURA_INTERRUPT_ON_UNUSED3                 = 0x4000,
    AURA_INTERRUPT_ON_CAST_SPELL              = 0x8000,
    AURA_INTERRUPT_ON_UNK7                    = 0x10000,
    AURA_INTERRUPT_ON_MOUNT                   = 0x20000,
    AURA_INTERRUPT_ON_STAND_UP                = 0x40000,
    AURA_INTERRUPT_ON_LEAVE_AREA              = 0x80000,
    AURA_INTERRUPT_ON_INVINCIBLE              = 0x100000,
    AURA_INTERRUPT_ON_STEALTH                 = 0x200000,
    AURA_INTERRUPT_ON_UNK8                    = 0x400000,
};

enum ChannelInterruptFlags
{
    CHANNEL_INTERRUPT_NULL  = 0x0,
    CHANNEL_INTERRUPT_ON_1  = 0x1,
    CHANNEL_INTERRUPT_ON_2  = 0x2,
    CHANNEL_INTERRUPT_ON_3  = 0x4,
    CHANNEL_INTERRUPT_ON_4  = 0x8,
    CHANNEL_INTERRUPT_ON_5  = 0x10,
    CHANNEL_INTERRUPT_ON_6  = 0x20,
    CHANNEL_INTERRUPT_ON_7  = 0x40,
    CHANNEL_INTERRUPT_ON_8  = 0x80,
    CHANNEL_INTERRUPT_ON_9  = 0x100,
    CHANNEL_INTERRUPT_ON_10 = 0x200,
    CHANNEL_INTERRUPT_ON_11 = 0x400,
    CHANNEL_INTERRUPT_ON_12 = 0x800,
    CHANNEL_INTERRUPT_ON_13 = 0x1000,
    CHANNEL_INTERRUPT_ON_14 = 0x2000,
    CHANNEL_INTERRUPT_ON_15 = 0x4000,
    CHANNEL_INTERRUPT_ON_16 = 0x8000,
    CHANNEL_INTERRUPT_ON_17 = 0x10000,
    CHANNEL_INTERRUPT_ON_18 = 0x20000
};

enum Attributes
{
	ATTRIBUTES_NULL								= 0x0,
	ATTRIBUTES_UNK2								= 0x1,
	ATTRIBUTES_UNK3								= 0x2, // related to ranged??
	ATTRIBUTE_ON_NEXT_ATTACK					= 0x4,
	ATTRIBUTES_UNUSED0							= 0x8,
	ATTRIBUTES_UNK6								= 0x10,
	ATTRIBUTES_UNK7								= 0x20, // Tradeskill recipies
	ATTRIBUTES_PASSIVE							= 0x40,
	ATTRIBUTES_NO_VISUAL_AURA					= 0x80,
	ATTRIBUTES_UNK10							= 0x100,	//seems to be afflicts pet
	ATTRIBUTES_UNK11							= 0x200, // looks like temp enchants.
	ATTRIBUTES_UNK12							= 0x400, //completely the same as ATTRIBUTE_ON_NEXT_ATTACK for class spells. So difference somewhere in mob abilities.
	ATTRIBUTES_UNK13							= 0x800,
	ATTRIBUTES_UNUSED1							= 0x1000,
	ATTRIBUTES_UNUSED2							= 0x2000,
	ATTRIBUTES_UNUSED3							= 0x4000,
	ATTRIBUTES_ONLY_OUTDOORS					= 0x8000,
	ATTRIBUTES_UNK								= 0x10000,
	ATTRIBUTES_REQ_STEALTH						= 0x20000,
	ATTRIBUTES_UNK20							= 0x40000,//it's not : must be behind
	ATTRIBUTES_UNK21							= 0x80000,
	ATTRIBUTES_STOP_ATTACK						= 0x100000,//switch off auto attack on use. Maim,Gouge,Disengage,Polymorph etc
	ATTRIBUTES_CANT_BE_DPB				    	= 0x200000,//can't be dodged, blocked, parried
	ATTRIBUTES_UNK24							= 0x400000, // related to ranged
	ATTRIBUTES_UNK25							= 0x800000,
	ATTRIBUTES_MOUNT_CASTABLE					= 0x1000000, //castable on mounts
	ATTRIBUTES_TRIGGER_COOLDOWN			        = 0x2000000, //also requires atributes ex = 32 ?
	ATTRIBUTES_UNK28							= 0x4000000,
	ATTRIBUTES_UNK29							= 0x8000000,
	ATTRIBUTES_REQ_OOC							= 0x10000000, //     ATTRIBUTES_REQ_OUT_OF_COMBAT
    ATTRIBUTES_IGNORE_INVULNERABILITY           = 0x20000000, //debuffs that can't be removed by any spell and spells that can't be resisted in any case
	ATTRIBUTES_UNK32							= 0x40000000, // seems like IS_DIMINISHING but some spells not there (f.e. Gouge)
};

enum AttributesEx
{
	ATTRIBUTESEX_NULL                         = 0x0,
	ATTRIBUTESEX_UNK2                         = 0x1, // pet summonings
	ATTRIBUTESEX_DRAIN_WHOLE_MANA             = 0x2,
	ATTRIBUTESEX_UNK4                         = 0x4,
	ATTRIBUTESEX_AREA_OF_EFFECT               = 0x8,
	ATTRIBUTESEX_UNK6                         = 0x10, // stealth effects but Rockbiter wtf 0_0
	ATTRIBUTESEX_NOT_BREAK_STEALTH            = 0x20,
	ATTRIBUTESEX_UNK8                         = 0x40,
	ATTRIBUTESEX_UNK9                         = 0x80,
	ATTRIBUTESEX_UNK10                        = 0x100,
	ATTRIBUTESEX_UNK11                        = 0x200,
	ATTRIBUTESEX_UNK12                        = 0x400,
	ATTRIBUTESEX_UNK13                        = 0x800,
	ATTRIBUTESEX_UNK14                        = 0x1000, // related to pickpocket
	ATTRIBUTESEX_UNK15                        = 0x2000, // related to remote control
	ATTRIBUTESEX_UNK16                        = 0x4000,
	ATTRIBUTESEX_UNK17                        = 0x8000, // something like "grant immunity"
	ATTRIBUTESEX_UNK18                        = 0x10000, // something like "grant immunity" too
	ATTRIBUTESEX_REMAIN_OOC                   = 0x20000,
	ATTRIBUTESEX_UNK20                        = 0x40000,
	ATTRIBUTESEX_UNK21                        = 0x80000,
	ATTRIBUTESEX_UNK22                        = 0x100000, // related to "Finishing move" and "Instantly overpowers"
	ATTRIBUTESEX_UNK23                        = 0x200000,
	ATTRIBUTESEX_UNK24                        = 0x400000, // only related to "Finishing move"
	ATTRIBUTESEX_UNK25                        = 0x800000, // related to spells like "ClearAllBuffs"
	ATTRIBUTESEX_UNK26                        = 0x1000000, // FISHING SPELLS
	ATTRIBUTESEX_UNK27                        = 0x2000000, // related to "Detect" spell
	ATTRIBUTESEX_UNK28                        = 0x4000000,
	ATTRIBUTESEX_UNK29                        = 0x8000000,
	ATTRIBUTESEX_UNK30                        = 0x10000000,
	ATTRIBUTESEX_UNK31                        = 0x20000000,
	ATTRIBUTESEX_UNK32                        = 0x40000000, // Overpower
};

enum Flags3
{
	FLAGS3_NULL               = 0x0,
	FLAGS3_UNK2               = 0x1,
	FLAGS3_UNK3               = 0x2,    // Can be used while stealthed
	FLAGS3_UNK4               = 0x4,    // request pet maybe
	FLAGS3_UNK5               = 0x8,    // something todo with temp enchanted items
	FLAGS3_PARTY_EFFECTING_AURA = 0x10, // Party affecting aura's
	FLAGS3_ACTIVATE_AUTO_SHOT = 0x20,   // spell that enable's auto shoot
	FLAGS3_UNK8               = 0x40,   //Polymorph spells
	FLAGS3_UNK9               = 0x80,
	FLAGS3_UNUSED1            = 0x100,
	FLAGS3_UNK11              = 0x200,  // used by 2 spells, 30421 | Nether Portal - Perseverence and  30466 | Nether Portal - Perseverence
	FLAGS3_TAME_X             = 0x400,  // tame [creature]
	FLAGS3_FUNNEL             = 0x800,  // only funnel spells
	FLAGS3_UNK14              = 0x1000, // swipe / Cleave spells
	FLAGS3_ENCHANT_OWN_ONLY   = 0x2000, // no trade window targets, BoE items get soulbound to you
	FLAGS3_SPELL_PLAYER_EVENT = 0x4000, // Player event's like logging in, finishing quests, triggering cinematic, being adored, Heartbroken etc
	FLAGS3_UNUSED3            = 0x8000,
	FLAGS3_CONTROL_UNIT       = 0x10000, // PvP Controller, RC, Creature taming, Taming Lesson
	FLAGS3_REQ_RANGED_WEAPON  = 0x20000, // this is shit and has nothing to do with auto shot
	FLAGS3_REVIVE_PET         = 0x40000, // actually 1 spell, revive pet
	FLAGS3_UNK21              = 0x80000, // this is a group of spells that are triggered by something. (I have no clue on how to name this one)
	FLAGS3_REQ_BEHIND_TARGET  = 0x100000,
	FLAGS3_UNK23              = 0x200000,
	FLAGS3_UNK24              = 0x400000,
	FLAGS3_UNK25              = 0x800000,
	FLAGS3_UNK26              = 0x1000000,
	FLAGS3_UNK27              = 0x2000000,
	FLAGS3_UNK28              = 0x4000000,
	FLAGS3_UNK29              = 0x8000000, // fishing spells and enchanting weapons
	FLAGS3_UNK30              = 0x10000000, // some secondairy spell triggers, especialy for lightning shield alike spells
	FLAGS3_UNK31              = 0x20000000,
	FLAGS3_UNK32              = 0x40000000,
};

enum Flags4
{
	FLAGS4_BG_ONLY                      = 0x800,
	FLAGS4_PLAYER_RANGED_SPELLS         = 0x8000,
	CAN_PERSIST_AND_CASTED_WHILE_DEAD   = 0x100000,
	FLAGS4_PLAYER_RANGED_WAND           = 0x400000,
	FLAGS4_OFFHAND                      = 0x1000000,
};

enum Flags5
{
	FLAGS5_PROCCHANCE_COMBOBASED        = 0x2,
	FLAGS5_ONLY_IN_OUTLANDS             = 0x4000000,
};

enum SpellCastFlags
{
    CAST_FLAG_UNKNOWN1           = 0x2,
    CAST_FLAG_UNKNOWN2           = 0x10, // no idea yet, i saw it in blizzard spell
    CAST_FLAG_AMMO               = 0x20 // load ammo display id (uint32) and ammo inventory type (uint32)
};

enum School
{
    SCHOOL_NORMAL = 0,
    SCHOOL_HOLY   = 1,
    SCHOOL_FIRE   = 2,
    SCHOOL_NATURE = 3,
    SCHOOL_FROST  = 4,
    SCHOOL_SHADOW = 5,
    SCHOOL_ARCANE = 6,
    SCHOOL_SPELL  = 7,
    SCHOOL_MAGIC  = 8,
    SCHOOL_ALL    = 9,
};

// converting schools for 2.4.0 client
static const uint32 spellMaskArray[SCHOOL_ALL+1] =
{
	1,				// SCHOOL_NORMAL
	2,				// SCHOOL_HOLY
	4,				// SCHOOL_FIRE
	8,				// SCHOOL_NATURE
	16,				// SCHOOL_FROST
	32,				// SCHOOL_SHADOW
	64,				// SCHOOL_ARCANE
 	124,            // SCHOOL_SPELL
 	126,            // SCHOOL_MAGIC
 	127,            // SCHOOL_ALL
};

ARCTIC_INLINE uint8 SchoolMask(uint8 school)
{
	if(school > SCHOOL_ALL)
		return uint8(0);
	return spellMaskArray[school];
}

enum ReplenishType
{
    REPLENISH_UNDEFINED = 0,
    REPLENISH_HEALTH    = 20,
    REPLENISH_MANA      = 21,
    REPLENISH_RAGE      = 22 //don't know if rage is 22 or what, but will do for now
};

enum SpellTargetType
{
    TARGET_TYPE_NULL       = 0x0,
    TARGET_TYPE_BEAST      = 0x1,
    TARGET_TYPE_DRAGONKIN  = 0x2,
    TARGET_TYPE_DEMON      = 0x4,
    TARGET_TYPE_ELEMENTAL  = 0x8,
    TARGET_TYPE_GIANT      = 0x10,
    TARGET_TYPE_UNDEAD     = 0x20,
    TARGET_TYPE_HUMANOID   = 0x40,
    TARGET_TYPE_CRITTER    = 0x80,
    TARGET_TYPE_MECHANICAL = 0x100,
};

/************************************************************************/
/*SpellExtraFlags defines                                               */
/* Used for infront check and other checks                              */
/* when they are not in spell.dbc                                       */
/************************************************************************/

enum ARCTICDEV_SPELL_EXTRA
{
    SPELL_EXTRA_INFRONT     = 1,
    SPELL_EXTRA_BEHIND      = 2,
    SPELL_EXTRA_UNDEF0      = 4, // not used yet
    SPELL_EXTRA_UNDEF1      = 8, // not used yet
};

/************************************************************************/
/* Ranged spellid                                                       */
/* Note: These spell id's are checked for 3.0.x                         */
/************************************************************************/

enum ARCTICDEV_SPELL_RANGED
{
    SPELL_ATTACK            = 6603,
    SPELL_RANGED_GENERAL    = 3018,
    SPELL_RANGED_THROW      = 2764,
    SPELL_RANGED_WAND       = 5019,
};

#pragma pack(push,1)
struct TeleportCoords
{
    uint32 id;
    uint32 mapId;
    float x;
    float y;
    float z;
	float o;
};
#pragma pack(pop)

enum SPELL_ENTRY
{
    SPELL_ENTRY_Id,
    SPELL_ENTRY_School,
    SPELL_ENTRY_Category,
    SPELL_ENTRY_field4,
    SPELL_ENTRY_DispelType,
    SPELL_ENTRY_MechanicsType,
    SPELL_ENTRY_Attributes,
    SPELL_ENTRY_AttributesEx,
    SPELL_ENTRY_Flags3,
    SPELL_ENTRY_Flags4,
    SPELL_ENTRY_Flags5,
    SPELL_ENTRY_unk201_1,
    SPELL_ENTRY_RequiredShapeShift,
    SPELL_ENTRY_UNK14,
    SPELL_ENTRY_Targets,
    SPELL_ENTRY_TargetCreatureType,
    SPELL_ENTRY_RequiresSpellFocus,
    SPELL_ENTRY_CasterAuraState,
    SPELL_ENTRY_TargetAuraState,
    SPELL_ENTRY_unk201_2,
    SPELL_ENTRY_unk201_3,
    SPELL_ENTRY_CastingTimeIndex,
    SPELL_ENTRY_RecoveryTime,
    SPELL_ENTRY_CategoryRecoveryTime,
    SPELL_ENTRY_InterruptFlags,
    SPELL_ENTRY_AuraInterruptFlags,
    SPELL_ENTRY_ChannelInterruptFlags,
    SPELL_ENTRY_procFlags,
    SPELL_ENTRY_procChance,
    SPELL_ENTRY_procCharges,
    SPELL_ENTRY_maxLevel,
    SPELL_ENTRY_baseLevel,
    SPELL_ENTRY_spellLevel,
    SPELL_ENTRY_DurationIndex,
    SPELL_ENTRY_powerType,
    SPELL_ENTRY_manaCost,
    SPELL_ENTRY_manaCostPerlevel,
    SPELL_ENTRY_manaPerSecond,
    SPELL_ENTRY_manaPerSecondPerLevel,
    SPELL_ENTRY_rangeIndex,
    SPELL_ENTRY_speed,
    SPELL_ENTRY_modalNextSpell,
    SPELL_ENTRY_maxstack,
    SPELL_ENTRY_Totem_1,
    SPELL_ENTRY_Totem_2,
    SPELL_ENTRY_Reagent_1,
    SPELL_ENTRY_Reagent_2,
    SPELL_ENTRY_Reagent_3,
    SPELL_ENTRY_Reagent_4,
    SPELL_ENTRY_Reagent_5,
    SPELL_ENTRY_Reagent_6,
    SPELL_ENTRY_Reagent_7,
    SPELL_ENTRY_Reagent_8,
    SPELL_ENTRY_ReagentCount_1,
    SPELL_ENTRY_ReagentCount_2,
    SPELL_ENTRY_ReagentCount_3,
    SPELL_ENTRY_ReagentCount_4,
    SPELL_ENTRY_ReagentCount_5,
    SPELL_ENTRY_ReagentCount_6,
    SPELL_ENTRY_ReagentCount_7,
    SPELL_ENTRY_ReagentCount_8,
    SPELL_ENTRY_EquippedItemClass,
    SPELL_ENTRY_EquippedItemSubClass,
    SPELL_ENTRY_RequiredItemFlags,
    SPELL_ENTRY_Effect_1,
    SPELL_ENTRY_Effect_2,
    SPELL_ENTRY_Effect_3,
    SPELL_ENTRY_EffectDieSides_1,
    SPELL_ENTRY_EffectDieSides_2,
    SPELL_ENTRY_EffectDieSides_3,
    SPELL_ENTRY_EffectBaseDice_1,
    SPELL_ENTRY_EffectBaseDice_2,
    SPELL_ENTRY_EffectBaseDice_3,
    SPELL_ENTRY_EffectDicePerLevel_1,
    SPELL_ENTRY_EffectDicePerLevel_2,
    SPELL_ENTRY_EffectDicePerLevel_3,
    SPELL_ENTRY_EffectRealPointsPerLevel_1,
    SPELL_ENTRY_EffectRealPointsPerLevel_2,
    SPELL_ENTRY_EffectRealPointsPerLevel_3,
    SPELL_ENTRY_EffectBasePoints_1,
    SPELL_ENTRY_EffectBasePoints_2,
    SPELL_ENTRY_EffectBasePoints_3,
    SPELL_ENTRY_EffectMechanic_1,
    SPELL_ENTRY_EffectMechanic_2,
    SPELL_ENTRY_EffectMechanic_3,
    SPELL_ENTRY_EffectImplicitTargetA_1,
    SPELL_ENTRY_EffectImplicitTargetA_2,
    SPELL_ENTRY_EffectImplicitTargetA_3,
    SPELL_ENTRY_EffectImplicitTargetB_1,
    SPELL_ENTRY_EffectImplicitTargetB_2,
    SPELL_ENTRY_EffectImplicitTargetB_3,
    SPELL_ENTRY_EffectRadiusIndex_1,
    SPELL_ENTRY_EffectRadiusIndex_2,
    SPELL_ENTRY_EffectRadiusIndex_3,
    SPELL_ENTRY_EffectApplyAuraName_1,
    SPELL_ENTRY_EffectApplyAuraName_2,
    SPELL_ENTRY_EffectApplyAuraName_3,
    SPELL_ENTRY_EffectAmplitude_1,
    SPELL_ENTRY_EffectAmplitude_2,
    SPELL_ENTRY_EffectAmplitude_3,
    SPELL_ENTRY_Effectunknown_1,
    SPELL_ENTRY_Effectunknown_2,
    SPELL_ENTRY_Effectunknown_3,
    SPELL_ENTRY_EffectChainTarget_1,
    SPELL_ENTRY_EffectChainTarget_2,
    SPELL_ENTRY_EffectChainTarget_3,
    SPELL_ENTRY_EffectSpellGroupRelation_1,
    SPELL_ENTRY_EffectSpellGroupRelation_2,
    SPELL_ENTRY_EffectSpellGroupRelation_3,
    SPELL_ENTRY_EffectMiscValue_1,
    SPELL_ENTRY_EffectMiscValue_2,
    SPELL_ENTRY_EffectMiscValue_3,
    SPELL_ENTRY_EffectTriggerSpell_1,
    SPELL_ENTRY_EffectTriggerSpell_2,
    SPELL_ENTRY_EffectTriggerSpell_3,
    SPELL_ENTRY_EffectPointsPerComboPoint_1,
    SPELL_ENTRY_EffectPointsPerComboPoint_2,
    SPELL_ENTRY_EffectPointsPerComboPoint_3,
    SPELL_ENTRY_SpellVisual,
    SPELL_ENTRY_field114,
    SPELL_ENTRY_dummy,
    SPELL_ENTRY_CoSpell,
    SPELL_ENTRY_spellPriority,
    SPELL_ENTRY_Name,
    SPELL_ENTRY_NameAlt1,
    SPELL_ENTRY_NameAlt2,
    SPELL_ENTRY_NameAlt3,
    SPELL_ENTRY_NameAlt4,
    SPELL_ENTRY_NameAlt5,
    SPELL_ENTRY_NameAlt6,
    SPELL_ENTRY_NameAlt7,
    SPELL_ENTRY_NameAlt8,
    SPELL_ENTRY_NameAlt9,
    SPELL_ENTRY_NameAlt10,
    SPELL_ENTRY_NameAlt11,
    SPELL_ENTRY_NameAlt12,
    SPELL_ENTRY_NameAlt13,
    SPELL_ENTRY_NameAlt14,
    SPELL_ENTRY_NameAlt15,
    SPELL_ENTRY_NameFlags,
    SPELL_ENTRY_Rank,
    SPELL_ENTRY_RankAlt1,
    SPELL_ENTRY_RankAlt2,
    SPELL_ENTRY_RankAlt3,
    SPELL_ENTRY_RankAlt4,
    SPELL_ENTRY_RankAlt5,
    SPELL_ENTRY_RankAlt6,
    SPELL_ENTRY_RankAlt7,
    SPELL_ENTRY_RankAlt8,
    SPELL_ENTRY_RankAlt9,
    SPELL_ENTRY_RankAlt10,
    SPELL_ENTRY_RankAlt11,
    SPELL_ENTRY_RankAlt12,
    SPELL_ENTRY_RankAlt13,
    SPELL_ENTRY_RankAlt14,
    SPELL_ENTRY_RankAlt15,
    SPELL_ENTRY_RankFlags,
    SPELL_ENTRY_Description,
    SPELL_ENTRY_DescriptionAlt1,
    SPELL_ENTRY_DescriptionAlt2,
    SPELL_ENTRY_DescriptionAlt3,
    SPELL_ENTRY_DescriptionAlt4,
    SPELL_ENTRY_DescriptionAlt5,
    SPELL_ENTRY_DescriptionAlt6,
    SPELL_ENTRY_DescriptionAlt7,
    SPELL_ENTRY_DescriptionAlt8,
    SPELL_ENTRY_DescriptionAlt9,
    SPELL_ENTRY_DescriptionAlt10,
    SPELL_ENTRY_DescriptionAlt11,
    SPELL_ENTRY_DescriptionAlt12,
    SPELL_ENTRY_DescriptionAlt13,
    SPELL_ENTRY_DescriptionAlt14,
    SPELL_ENTRY_DescriptionAlt15,
    SPELL_ENTRY_DescriptionFlags,
    SPELL_ENTRY_BuffDescription,
    SPELL_ENTRY_BuffDescriptionAlt1,
    SPELL_ENTRY_BuffDescriptionAlt2,
    SPELL_ENTRY_BuffDescriptionAlt3,
    SPELL_ENTRY_BuffDescriptionAlt4,
    SPELL_ENTRY_BuffDescriptionAlt5,
    SPELL_ENTRY_BuffDescriptionAlt6,
    SPELL_ENTRY_BuffDescriptionAlt7,
    SPELL_ENTRY_BuffDescriptionAlt8,
    SPELL_ENTRY_BuffDescriptionAlt9,
    SPELL_ENTRY_BuffDescriptionAlt10,
    SPELL_ENTRY_BuffDescriptionAlt11,
    SPELL_ENTRY_BuffDescriptionAlt12,
    SPELL_ENTRY_BuffDescriptionAlt13,
    SPELL_ENTRY_BuffDescriptionAlt14,
    SPELL_ENTRY_BuffDescriptionAlt15,
    SPELL_ENTRY_buffdescflags,
    SPELL_ENTRY_ManaCostPercentage,
    SPELL_ENTRY_unkflags,
    SPELL_ENTRY_StartRecoveryTime,
    SPELL_ENTRY_StartRecoveryCategory,
    SPELL_ENTRY_SpellFamilyName,
    SPELL_ENTRY_SpellGroupType,
    SPELL_ENTRY_unkne,
    SPELL_ENTRY_MaxTargets,
    SPELL_ENTRY_Spell_Dmg_Type,
    SPELL_ENTRY_FG,
    SPELL_ENTRY_FH,
    SPELL_ENTRY_dmg_multiplier_1,
    SPELL_ENTRY_dmg_multiplier_2,
    SPELL_ENTRY_dmg_multiplier_3,
    SPELL_ENTRY_FL,
    SPELL_ENTRY_FM,
    SPELL_ENTRY_FN,
	SPELL_ENTRY_TotemCategory1,
	SPELL_ENTRY_TotemCategory2,
	SPELL_ENTRY_RequiredAreaID
};

enum SpellCoefficientsFlags
{
	SPELL_FLAG_IS_DOT_OR_HOT_SPELL		= 0x00000001, //Damage over Time or Healing over Time Spells
	SPELL_FLAG_IS_DD_OR_DH_SPELL		= 0x00000002, //Direct Damage or Direct Healing Spells
	SPELL_FLAG_IS_DD_DH_DOT_SPELL		= SPELL_FLAG_IS_DOT_OR_HOT_SPELL | SPELL_FLAG_IS_DD_OR_DH_SPELL, //DoT+(DD|DH) Spells
	SPELL_FLAG_AOE_SPELL				= 0x00000004, //AoE Spells
	SPELL_FLAG_ADITIONAL_EFFECT			= 0x00000008, //Spells with aditional effect not DD or DoT or HoT
};

struct TotemSpells
{
	uint32 spellId;
	uint32 spellToCast[3];
};

enum LOCKTYPES
{
	LOCKTYPE_PICKLOCK				= 1,
	LOCKTYPE_HERBALISM				= 2,
	LOCKTYPE_MINING					= 3,
	LOCKTYPE_DISARM_TRAP			= 4,
	LOCKTYPE_OPEN					= 5,
	LOCKTYPE_TREASURE				= 6,
	LOCKTYPE_CALCIFIED_ELVEN_GEMS	= 7,
	LOCKTYPE_CLOSE					= 8,
	LOCKTYPE_ARM_TRAP				= 9,
	LOCKTYPE_QUICK_OPEN				= 10,
	LOCKTYPE_QUICK_CLOSE			= 11,
	LOCKTYPE_OPEN_TINKERING			= 12,
	LOCKTYPE_OPEN_KNEELING			= 13,
	LOCKTYPE_OPEN_ATTACKING			= 14,
	LOCKTYPE_GAHZRIDIAN				= 15,
	LOCKTYPE_BLASTING				= 16,
	LOCKTYPE_SLOW_OPEN				= 17,
	LOCKTYPE_SLOW_CLOSE				= 18,
	LOCKTYPE_FISHING				= 19,
	LOCKTYPE_INSCRIPTION			= 20,
	LOCKTYPE_OPEN_FROM_VEHICLE		= 21
};

enum SpellEffects
{
    SPELL_EFFECT_NULL = 0,
    SPELL_EFFECT_INSTANT_KILL,              //    1
    SPELL_EFFECT_SCHOOL_DAMAGE,             //    2
    SPELL_EFFECT_DUMMY,                     //    3
    SPELL_EFFECT_PORTAL_TELEPORT,           //    4
    SPELL_EFFECT_TELEPORT_UNITS,            //    5
    SPELL_EFFECT_APPLY_AURA,                //    6
    SPELL_EFFECT_ENVIRONMENTAL_DAMAGE,      //    7
    SPELL_EFFECT_POWER_DRAIN,               //    8
    SPELL_EFFECT_HEALTH_LEECH,              //    9
    SPELL_EFFECT_HEAL,                      //    10
    SPELL_EFFECT_BIND,                      //    11
    SPELL_EFFECT_PORTAL,                    //    12
    SPELL_EFFECT_RITUAL_BASE,               //    13
    SPELL_EFFECT_RITUAL_SPECIALIZE,         //    14
    SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL,    //    15
    SPELL_EFFECT_QUEST_COMPLETE,            //    16
    SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL,    //    17
    SPELL_EFFECT_RESURRECT,                 //    18
    SPELL_EFFECT_ADD_EXTRA_ATTACKS,         //    19
    SPELL_EFFECT_DODGE,                     //    20
    SPELL_EFFECT_EVADE,                     //    21
    SPELL_EFFECT_PARRY,                     //    22
    SPELL_EFFECT_BLOCK,                     //    23
    SPELL_EFFECT_CREATE_ITEM,               //    24
    SPELL_EFFECT_WEAPON,                    //    25
    SPELL_EFFECT_DEFENSE,                   //    26
    SPELL_EFFECT_PERSISTENT_AREA_AURA,      //    27
    SPELL_EFFECT_SUMMON,                    //    28
    SPELL_EFFECT_LEAP,                      //    29
    SPELL_EFFECT_ENERGIZE,                  //    30
    SPELL_EFFECT_WEAPON_PERCENT_DAMAGE,     //    31
    SPELL_EFFECT_TRIGGER_MISSILE,           //    32
    SPELL_EFFECT_OPEN_LOCK,                 //    33
    SPELL_EFFECT_TRANSFORM_ITEM,            //    34
    SPELL_EFFECT_APPLY_AREA_AURA,           //    35
    SPELL_EFFECT_LEARN_SPELL,               //    36
    SPELL_EFFECT_SPELL_DEFENSE,             //    37
    SPELL_EFFECT_DISPEL,                    //    38
    SPELL_EFFECT_LANGUAGE,                  //    39
    SPELL_EFFECT_DUAL_WIELD,                //    40
    SPELL_EFFECT_SUMMON_WILD,               //    41
    SPELL_EFFECT_MEGA_JUMP,					//    42
    SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER,//    43
    SPELL_EFFECT_SKILL_STEP,                //    44
    SPELL_EFFECT_UNDEFINED_45,              //    45
    SPELL_EFFECT_SPAWN,                     //    46
    SPELL_EFFECT_TRADE_SKILL,               //    47
    SPELL_EFFECT_STEALTH,                   //    48
    SPELL_EFFECT_DETECT,                    //    49
    SPELL_EFFECT_SUMMON_OBJECT,             //    50
    //SPELL_EFFECT_TRANS_DOOR,              //    50
    SPELL_EFFECT_FORCE_CRITICAL_HIT,        //    51
    SPELL_EFFECT_GUARANTEE_HIT,             //    52
    SPELL_EFFECT_ENCHANT_ITEM,              //    53
    SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY,    //    54
    SPELL_EFFECT_TAMECREATURE,              //    55
    SPELL_EFFECT_SUMMON_PET,                //    56
    SPELL_EFFECT_LEARN_PET_SPELL,           //    57
    SPELL_EFFECT_WEAPON_DAMAGE,             //    58
    SPELL_EFFECT_OPEN_LOCK_ITEM,            //    59
    SPELL_EFFECT_PROFICIENCY,               //    60
    SPELL_EFFECT_SEND_EVENT,                //    61
    SPELL_EFFECT_POWER_BURN,                //    62
    SPELL_EFFECT_THREAT,                    //    63
    SPELL_EFFECT_TRIGGER_SPELL,             //    64
    SPELL_EFFECT_HEALTH_FUNNEL,             //    65
    SPELL_EFFECT_POWER_FUNNEL,              //    66
    SPELL_EFFECT_HEAL_MAX_HEALTH,           //    67
    SPELL_EFFECT_INTERRUPT_CAST,            //    68
    SPELL_EFFECT_DISTRACT,                  //    69
    SPELL_EFFECT_PULL,                      //    70
    SPELL_EFFECT_PICKPOCKET,                //    71
    SPELL_EFFECT_ADD_FARSIGHT,              //    72
    SPELL_EFFECT_SUMMON_POSSESSED,          //    73
    SPELL_EFFECT_USE_GLYPH,                 //    74
    SPELL_EFFECT_HEAL_MECHANICAL,           //    75
    SPELL_EFFECT_SUMMON_OBJECT_WILD,        //    76
    SPELL_EFFECT_SCRIPT_EFFECT,             //    77
    SPELL_EFFECT_ATTACK,                    //    78
    SPELL_EFFECT_SANCTUARY,                 //    79
    SPELL_EFFECT_ADD_COMBO_POINTS,          //    80
    SPELL_EFFECT_CREATE_HOUSE,              //    81
    SPELL_EFFECT_BIND_SIGHT,                //    82
    SPELL_EFFECT_DUEL,                      //    83
    SPELL_EFFECT_STUCK,                     //    84
    SPELL_EFFECT_SUMMON_PLAYER,             //    85
    SPELL_EFFECT_ACTIVATE_OBJECT,           //    86
	SPELL_EFFECT_WMO_DAMAGE,				//    87
	SPELL_EFFECT_WMO_REPAIR,				//    88
    SPELL_EFFECT_SUMMON_TOTEM_SLOT3,        //    89
    SPELL_EFFECT_SUMMON_TOTEM_SLOT4,        //    90
    SPELL_EFFECT_THREAT_ALL,                //    91
    SPELL_EFFECT_ENCHANT_HELD_ITEM,         //    92
    SPELL_EFFECT_SUMMON_PHANTASM,           //    93
    SPELL_EFFECT_SELF_RESURRECT,            //    94
    SPELL_EFFECT_SKINNING,                  //    95
    SPELL_EFFECT_CHARGE,                    //    96
    SPELL_EFFECT_SUMMON_CRITTER,            //    97
    SPELL_EFFECT_KNOCK_BACK,                //    98
    SPELL_EFFECT_DISENCHANT,                //    99
    SPELL_EFFECT_INEBRIATE,                 //    100
    SPELL_EFFECT_FEED_PET,                  //    101
    SPELL_EFFECT_DISMISS_PET,               //    102
    SPELL_EFFECT_REPUTATION,                //    103
    SPELL_EFFECT_SUMMON_OBJECT_SLOT1,       //    104
    SPELL_EFFECT_SUMMON_OBJECT_SLOT2,       //    105
    SPELL_EFFECT_SUMMON_OBJECT_SLOT3,       //    106
    SPELL_EFFECT_SUMMON_OBJECT_SLOT4,       //    107
    SPELL_EFFECT_DISPEL_MECHANIC,           //    108
    SPELL_EFFECT_SUMMON_DEAD_PET,           //    109
    SPELL_EFFECT_DESTROY_ALL_TOTEMS,        //    110
    SPELL_EFFECT_DURABILITY_DAMAGE,         //    111
    SPELL_EFFECT_SUMMON_DEMON,              //    112
    SPELL_EFFECT_RESURRECT_FLAT,            //    113
    SPELL_EFFECT_ATTACK_ME,                 //    114
    SPELL_EFFECT_DURABILITY_DAMAGE_PCT,     //    115
    SPELL_EFFECT_SKIN_PLAYER_CORPSE,        //    116
    SPELL_EFFECT_SPIRIT_HEAL,               //    117
    SPELL_EFFECT_SKILL,                     //    118
    SPELL_EFFECT_APPLY_PET_AURA,            //    119
    SPELL_EFFECT_TELEPORT_GRAVEYARD,        //    120
    SPELL_EFFECT_DUMMYMELEE,                //    121
    SPELL_EFFECT_UNKNOWN1,                  //    122
    SPELL_EFFECT_SEND_TAXI,                 //    123
    SPELL_EFFECT_PLAYER_PULL,               //    124
    SPELL_EFFECT_UNKNOWN4,                  //    125
    SPELL_EFFECT_UNKNOWN5,                  //    126
    SPELL_EFFECT_PROSPECTING,               //    127
    SPELL_EFFECT_APPLY_AURA_128,            //    128
    SPELL_EFFECT_UNKNOWN9,                  //    129
    SPELL_EFFECT_UNKNOWN10,                 //    130
    SPELL_EFFECT_UNKNOWN11,                 //    131
    SPELL_EFFECT_UNKNOWN12,                 //    132
    SPELL_EFFECT_FORGET_SPECIALIZATION,     //    133
    SPELL_EFFECT_KILL_CREDIT,               //    134
    SPELL_EFFECT_UNKNOWN15,                 //    135
    SPELL_EFFECT_UNKNOWN16,                 //    136
    SPELL_EFFECT_UNKNOWN17,                 //    137
    SPELL_EFFECT_UNKNOWN18,                 //    138
    SPELL_EFFECT_UNKNOWN19,                 //    139
    SPELL_EFFECT_FORCE_CAST,                //    140
    SPELL_EFFECT_UNKNOWN20,                 //    141
    SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE,	//    142
    SPELL_EFFECT_UNKNOWN23,                 //    143
	SPELL_EFFECT_UNKNOWN24,                 //    144
	SPELL_EFFECT_UNKNOWN25,                 //    145
	SPELL_EFFECT_UNKNOWN26,                 //    146
	SPELL_EFFECT_UNKNOWN27,                 //    147
	SPELL_EFFECT_UNKNOWN28,                 //    148
	SPELL_EFFECT_UNKNOWN29,                 //    149
	SPELL_EFFECT_UNKNOWN30,                 //    150
    SPELL_EFFECT_TRIGGER_SPELL_2,           //    151
	SPELL_EFFECT_UNKNOWN32,                 //    152
	SPELL_EFFECT_UNKNOWN33,                 //    153
	SPELL_EFFECT_UNKNOWN34,                 //    154
	SPELL_EFFECT_UNKNOWN35,                 //    155
	SPELL_EFFECT_UNKNOWN36,                 //    156
	SPELL_EFFECT_UNKNOWN37,                 //    157
	SPELL_EFFECT_MILLING,	                //    158
	SPELL_EFFECT_UNKNOWN39,                 //    159
	SPELL_EFFECT_UNKNOWN40,                 //    160
	SPELL_EFFECT_SET_TALENT_SPECS_COUNT,    //    161
	SPELL_EFFECT_ACTIVATE_TALENT_SPEC,      //    162
    TOTAL_SPELL_EFFECTS,                    //    163
};

// target type flags
enum SpellTargetTypes
{
	SPELL_TARGET_TYPE_NONE				= 0x01,
	SPELL_TARGET_TYPE_PROFESSION		= 0x02,
	SPELL_TARGET_TYPE_NONE1				= 0x04,
	SPELL_TARGET_TYPE_NONE2				= 0x08,
	SPELL_TARGET_TYPE_ENCHANTABLE_ITEM	= 0x10,
	SPELL_TARGET_TYPE_UNK				= 0x20,		// seems to be scripted stuff
	SPELL_TARGET_TYPE_UNK0				= 0x40,		// lots of spells interesting to research this one further
	SPELL_TARGET_TYPE_UNK1				= 0x80,		// something todo with scripted and GM stuff
	SPELL_TARGET_TYPE_UNK2				= 0x100,	// lots of spells interesting to research this one further...
	SPELL_TARGET_TYPE_PLAYER_CORPSE		= 0x200,
	SPELL_TARGET_TYPE_DEATHx			= 0x400,
	SPELL_TARGET_TYPE_NONE3				= 0x800,
	SPELL_TARGET_TYPE_NONE4				= 0x1000,
	SPELL_TARGET_TYPE_NONE5				= 0x2000,
	SPELL_TARGET_TYPE_GAME_OBJECTS		= 0x4000,	// like chests and mining
	SPELL_TARGET_TYPE_DEATH				= 0x8000,
};

enum SpellTypes	// SPELL_ENTRY_buffType
{
	SPELL_TYPE_NONE					= 0x00000000,
	SPELL_TYPE_SEAL					= 0x00000001,
	SPELL_TYPE_ASPECT				= 0x00000002,
	SPELL_TYPE_BLESSING				= 0x00000004,
	SPELL_TYPE_CURSE				= 0x00000008,
	SPELL_TYPE_STING				= 0x00000010,
	SPELL_TYPE_ARMOR				= 0x00000020,
	SPELL_TYPE_AURA					= 0x00000040,
	//hmm these could be named simply incompatible spells. One active at a time
	SPELL_TYPE_MARK_GIFT			= 0x00000080,
	SPELL_TYPE_TRACK				= 0x00000100,
	SPELL_TYPE_HUNTER_TRAP			= 0x00000200,
	SPELL_TYPE_MAGE_INTEL			= 0x00000400,
	SPELL_TYPE_MAGE_MAGI			= 0x00000800,
	SPELL_TYPE_MAGE_WARDS			= 0x00001000,
	SPELL_TYPE_PRIEST_SH_PPROT		= 0x00002000,
	SPELL_TYPE_SHIELD				= 0x00004000,
	SPELL_TYPE_FORTITUDE			= 0x00008000,
	SPELL_TYPE_SPIRIT				= 0x00010000,
	SPELL_TYPE_MAGE_AMPL_DUMP		= 0x00020000,
	SPELL_TYPE_WARLOCK_IMMOLATE		= 0x00040000,	//maybe there is a better way to trigger the aura state for immolate spell
	SPELL_TYPE_ELIXIR_BATTLE		= 0x00080000,
	SPELL_TYPE_ELIXIR_GUARDIAN		= 0x00100000,
	SPELL_TYPE_ELIXIR_FLASK			= SPELL_TYPE_ELIXIR_BATTLE | SPELL_TYPE_ELIXIR_GUARDIAN,	//weee, this contains both battle and guardian elixirs ;)
	SPELL_TYPE_HUNTER_MARK			= 0x00200000,
	SPELL_TYPE_WARRIOR_SHOUT		= 0x00400000,
	SPELL_TYPE_DK_PRESENCE			= 0x00800000,
	SPELL_TYPE_JUDGEMENT			= 0x01000000,
	SPELL_TYPE_HASTE				= 0x02000000,
};

//custom stuff generated for spells that will not change in time
enum SpellIsFlags
{
    SPELL_FLAG_IS_DAMAGING				= 0x00000001,
    SPELL_FLAG_IS_HEALING				= 0x00000002,
    SPELL_FLAG_IS_TARGETINGSTEALTHED	= 0x00000004,
    SPELL_FLAG_IS_REQUIRECOOLDOWNUPDATE	= 0x00000008, //it started with rogue cold blood but i'm sure others will come
    SPELL_FLAG_IS_POISON				= 0x00000010, //rogue has a few spells that can stack so can't use the spell_type enum ;)
    SPELL_FLAG_IS_FINISHING_MOVE		= 0x00000020, //rogue has a few spells that can stack so can't use the spell_type enum ;)
    // UNUSED							= 0x00000040,
    SPELL_FLAG_IS_CHILD_SPELL			= 0x00000080, //auras proc auras that have same name, these should not remove mother aura when adding to target
    SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET		= 0x00000100, //we should cast these on pet too
    SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_PET_OWNER	= 0x00000200, //we should cast these on owner too
    SPELL_FLAG_IS_EXPIREING_WITH_PET	= 0x00000400, //when pet dies, we remove this too
    SPELL_FLAG_IS_EXPIREING_ON_PET		= 0x00000800, //when pet is summoned
	SPELL_FLAG_IS_DISPEL_SPELL			= 0x00001000,
	SPELL_FLAG_CAN_BE_REFLECTED			= 0x00002000,
	SPELL_FLAG_IS_HEALING_SPELL			= 0x00004000,
	SPELL_FLAG_IS_HEALING_MANA_SPELL	= 0x00008000,
	SPELL_FLAG_CANNOT_PROC_ON_SELF		= 0x00010000,
	SPELL_FLAG_IS_FLYING				= 0x00020000,
	SPELL_FLAG_IS_FORCEDDEBUFF			= 0x00040000,
	SPELL_FLAG_IS_FORCEDBUFF			= 0x00080000,
	SPELL_FLAG_ON_ONLY_ONE_TARGET		= 0x00100000,
	SPELL_FLAG_IS_NOT_RESISTABLE		= 0x00200000,
	SPELL_FLAG_PIERCES_ABSORBTION_EFF	= 0x00400000,
	SPELL_FLAG_CASTED_ON_FRIENDS		= 0x00800000,
	SPELL_FLAG_CASTED_ON_ENEMIES		= 0x01000000,
};

enum PoisonTypes
{
	POISON_TYPE_DEADLY			= 1,
	POISON_TYPE_WOUND			= 2,
	POISON_TYPE_INSTANT			= 3,
	POISON_TYPE_MIND_NUMBING	= 4,
	POISON_TYPE_CRIPPLING		= 5,
	POISON_TYPE_SCORPID			= 6,

};

enum AreaAuraTargets
{
	AA_TARGET_PARTY				= 0x01,
	AA_TARGET_RAID				= 0x02,
	AA_TARGET_ALLFRIENDLY		= 0x04,
	AA_TARGET_ALLENEMIES		= 0x08,
	AA_TARGET_PET				= 0x10,
	AA_TARGET_NOTSELF			= 0x20,
};

enum SpellFamilyNames
{
	SPELLFAMILY_GENERIC		= 0,
	SPELLFAMILY_UNK1,
	SPELLFAMILY_MAGE		= 3,
	SPELLFAMILY_WARRIOR,
	SPELLFAMILY_WARLOCK,
	SPELLFAMILY_PRIEST,
	SPELLFAMILY_DRUID,
	SPELLFAMILY_ROGUE,
	SPELLFAMILY_HUNTER,
	SPELLFAMILY_PALADIN,
	SPELLFAMILY_SHAMAN,
	SPELLFAMILY_UNK2,
	SPELLFAMILY_POTION,
	SPELLFAMILY_DEATHKNIGHT	= 15,
	SPELLFAMILY_PET			= 17
};

ARCTIC_INLINE bool CanAgroHash(uint32 spellhashname)
{
    if (spellhashname == SPELL_HASH_HUNTER_S_MARK || spellhashname == SPELL_HASH_SAP || spellhashname == SPELL_HASH_EAGLE_EYE || spellhashname == SPELL_HASH_FAR_SIGHT ) //hunter's mark
        return false;
    else
        return true;
}

ARCTIC_INLINE bool IsCastedOnFriends(SpellEntry *sp)
{
	for( int frloop = 0; frloop < 3; frloop++ )
	{
		switch (sp->EffectImplicitTargetA[frloop])
		{
			case 1:		//EFF_TARGET_SELF
			case 4:
			case 5:		//EFF_TARGET_PET
			case 20:	//EFF_TARGET_ALL_PARTY_AROUND_CASTER
			case 21:	//EFF_TARGET_SINGLE_FRIEND
			case 27:	//EFF_TARGET_PET_MASTER
			case 30:	//EFF_TARGET_ALL_FRIENDLY_IN_AREA
			case 31:	//EFF_TARGET_ALL_TARGETABLE_AROUND_LOCATION_IN_RADIUS_OVER_TIME
			case 32:	//EFF_TARGET_MINION
			case 33:	//EFF_TARGET_ALL_PARTY_IN_AREA
			case 35:	//EFF_TARGET_SINGLE_PARTY
			case 37:	//EFF_TARGET_ALL_PARTY
			case 41:	//EFF_TARGET_TOTEM_EARTH
			case 42:	//EFF_TARGET_TOTEM_WATER
			case 43:	//EFF_TARGET_TOTEM_AIR
			case 44:	//EFF_TARGET_TOTEM_FIRE
			case 45:	//EFF_TARGET_CHAIN
			case 56:
			case 57:	//EFF_TARGET_PARTY_MEMBER
			case 61:	//EFF_TARGET_AREAEFFECT_PARTY_AND_CLASS
				return true;
		}

		switch (sp->EffectImplicitTargetB[frloop])
		{
			case 1:		//EFF_TARGET_SELF
			case 4:
			case 5:		//EFF_TARGET_PET
			case 20:	//EFF_TARGET_ALL_PARTY_AROUND_CASTER
			case 21:	//EFF_TARGET_SINGLE_FRIEND
			case 27:	//EFF_TARGET_PET_MASTER
			case 30:	//EFF_TARGET_ALL_FRIENDLY_IN_AREA
			case 31:	//EFF_TARGET_ALL_TARGETABLE_AROUND_LOCATION_IN_RADIUS_OVER_TIME
			case 32:	//EFF_TARGET_MINION
			case 33:	//EFF_TARGET_ALL_PARTY_IN_AREA
			case 35:	//EFF_TARGET_SINGLE_PARTY
			case 37:	//EFF_TARGET_ALL_PARTY
			case 41:	//EFF_TARGET_TOTEM_EARTH
			case 42:	//EFF_TARGET_TOTEM_WATER
			case 43:	//EFF_TARGET_TOTEM_AIR
			case 44:	//EFF_TARGET_TOTEM_FIRE
			case 45:	//EFF_TARGET_CHAIN
			case 56:
			case 57:	//EFF_TARGET_PARTY_MEMBER
			case 61:	//EFF_TARGET_AREAEFFECT_PARTY_AND_CLASS
				return true;
		}
	}
	return false;
}

ARCTIC_INLINE bool IsCastedOnEnemies(SpellEntry *sp)
{
	for( int frloop = 0; frloop < 3; frloop++ )
	{
		switch (sp->EffectImplicitTargetA[frloop])
		{
			case 6:		//EFF_TARGET_SINGLE_ENEMY
			case 8:		//EFF_TARGET_ALL_TARGETABLE_AROUND_LOCATION_IN_RADIUS
			case 15:	//EFF_TARGET_ALL_ENEMY_IN_AREA
			case 16:	//EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT
			case 22:	//EFF_TARGET_ALL_ENEMIES_AROUND_CASTER
			case 24:	//EFF_TARGET_IN_FRONT_OF_CASTER
			case 28:	//EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED
			case 54:	//EFF_TARGET_TARGET_AT_ORIENTATION_TO_CASTER
			case 77:	//EFF_TARGET_SELECTED_ENEMY_CHANNELED
				return true;
		}

		switch (sp->EffectImplicitTargetB[frloop])
		{
			case 6:		//EFF_TARGET_SINGLE_ENEMY
			case 8:		//EFF_TARGET_ALL_TARGETABLE_AROUND_LOCATION_IN_RADIUS
			case 15:	//EFF_TARGET_ALL_ENEMY_IN_AREA
			case 16:	//EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT
			case 22:	//EFF_TARGET_ALL_ENEMIES_AROUND_CASTER
			case 24:	//EFF_TARGET_IN_FRONT_OF_CASTER
			case 28:	//EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED
			case 54:	//EFF_TARGET_TARGET_AT_ORIENTATION_TO_CASTER
			case 77:	//EFF_TARGET_SELECTED_ENEMY_CHANNELED
				return true;
		}
	}
	return false;
}

/************************************************************************/
/* IsDamagingSpell, this function seems slow, its only used rarely      */
/************************************************************************/
ARCTIC_INLINE bool IsDamagingSpell(SpellEntry *sp)
{
	if( sp->NameHash == SPELL_HASH_MUTILATE )
		return true;

	for (uint32 i = 0; i < 3; i++)
	{
		switch (sp->Effect[i])
		{
			case SPELL_EFFECT_SCHOOL_DAMAGE:
			case SPELL_EFFECT_ENVIRONMENTAL_DAMAGE:
			case SPELL_EFFECT_HEALTH_LEECH:
			case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
			case SPELL_EFFECT_ADD_EXTRA_ATTACKS:
			case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
			case SPELL_EFFECT_WEAPON_DAMAGE:
			case SPELL_EFFECT_POWER_BURN:
			case SPELL_EFFECT_ATTACK:
			case SPELL_EFFECT_DUMMYMELEE:
				return true;

			case SPELL_EFFECT_APPLY_AURA:
			case SPELL_EFFECT_APPLY_AREA_AURA:
			{
				switch (sp->EffectApplyAuraName[i])
				{
					case 3://SPELL_AURA_PERIODIC_DAMAGE:
					case 43://SPELL_AURA_PROC_TRIGGER_DAMAGE:
					case 53://SPELL_AURA_PERIODIC_LEECH:
					case 89://SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
					case 162://SPELL_AURA_POWER_BURN:
						return true;
				};
			}
		}
	}
    return false;
}

ARCTIC_INLINE bool IsHealingSpell(SpellEntry *sp)
{
	for(uint32 i = 0; i < 3; ++i)
	{
		switch( sp->Effect[i] )
		{
			case SPELL_EFFECT_HEAL:
			case SPELL_EFFECT_HEALTH_FUNNEL:
			case SPELL_EFFECT_HEAL_MAX_HEALTH:
				return true;

			case SPELL_EFFECT_APPLY_AURA:
			case SPELL_EFFECT_APPLY_AREA_AURA:
			{
				switch( sp->EffectApplyAuraName[i] )
				{
					case 8://SPELL_AURA_PERIODIC_HEAL:
					case 62://SPELL_AURA_PERIODIC_HEALTH_FUNNEL:
						return true;

					case 23://SPELL_AURA_PERIODIC_TRIGGER_SPELL:
						{
							SpellEntry * triggered = dbcSpell.LookupEntryForced(sp->EffectTriggerSpell[i]);
							if(triggered && triggered != sp && IsHealingSpell(triggered))
								return true;
						}
				};
			}
		}
	}

	//flash of light, holy light uses scripted effect which is not neceserally heal spell
	if( sp->NameHash == SPELL_HASH_HOLY_LIGHT || sp->NameHash == SPELL_HASH_FLASH_OF_LIGHT  )
		return true;

	return false;
}

ARCTIC_INLINE bool IsInrange(LocationVector & location, Object* o, float square_r)
{
    float r = o->GetDistanceSq(location);
    return ( r<=square_r);
}

ARCTIC_INLINE bool IsInrange(float x1,float y1, float z1, Object* o,float square_r)
{
    float r = o->GetDistanceSq(x1, y1, z1);
    return ( r<=square_r);
}

ARCTIC_INLINE bool IsInrange(float x1,float y1, float z1,float x2,float y2, float z2,float square_r)
{
    float t;
    float r;
    t=x1-x2;
    r=t*t;
    t=y1-y2;
    r+=t*t;
    t=z1-z2;
    r+=t*t;
    return ( r<=square_r);
}

ARCTIC_INLINE bool IsInrange(Object* o1,Object* o2,float square_r)
{
    return IsInrange(o1->GetPositionX(),o1->GetPositionY(),o1->GetPositionZ(),
        o2->GetPositionX(),o2->GetPositionY(),o2->GetPositionZ(),square_r);
}

ARCTIC_INLINE bool TargetTypeCheck(Object* obj,uint32 ReqCreatureTypeMask)
{
	if( !ReqCreatureTypeMask )
		return true;

	if( obj->GetTypeId() == TYPEID_UNIT )
	{
		Creature* cr = TO_CREATURE(obj);
		CreatureInfo* inf = cr->GetCreatureInfo();
		if( inf == NULL || !( 1 << ( inf->Type - 1 ) & ReqCreatureTypeMask ) )
			return false;
	}
	else if(obj->GetTypeId() == TYPEID_PLAYER && !(UNIT_TYPE_HUMANOID_BIT & ReqCreatureTypeMask))
		return false;
	else return false;//omg, how in the hack did we cast it on a GO ? But who cares ?
	return true;
}

enum SpellState
{
	SPELL_STATE_NULL		= 0,
	SPELL_STATE_PREPARING	= 1,
	SPELL_STATE_CASTING		= 2,
	SPELL_STATE_FINISHED	= 3,
	SPELL_STATE_IDLE		= 4
};

enum ShapeshiftForm
{
	FORM_NORMAL             = 0,  //1
	FORM_CAT                = 1,  //2
	FORM_TREE               = 2,  //4
	FORM_TRAVEL             = 3,  //8
	FORM_AQUA               = 4,  //16
	FORM_BEAR               = 5,  //32
	FORM_AMBIENT            = 6,  //64
	FORM_GHOUL              = 7,  //128
	FORM_DIREBEAR           = 8,  //256
	FORM_9                  = 9,  //512
	FORM_10                 = 10, //1024
	FORM_11                 = 11, //2048
	FORM_12                 = 12, //4096
	FORM_13                 = 13, //8192
	FORM_CREATUREBEAR       = 14, //16384
	FORM_GHOSTWOLF          = 16, //65536
	FORM_BATTLESTANCE       = 17, //131072
	FORM_DEFENSIVESTANCE    = 18, //262144
	FORM_BERSERKERSTANCE    = 19, //524288
	FORM_20                 = 20, //1048576
	FORM_ZOMBIE				= 21, //2097152
	FORM_DEMON				= 22, //4194304
	FORM_23                 = 23, //8388608
	FORM_24                 = 24, //16777216
	FORM_UNDEAD				= 25, //33554432
	FORM_MASTER_ANGLER		= 26, //67108864
	FORM_SWIFT              = 27, //134217728
	FORM_SHADOW             = 28, //268435456
	FORM_FLIGHT             = 29, //536870912
	FORM_STEALTH            = 30, //1073741824
	FORM_MOONKIN            = 31, //2147483648
	FORM_SPIRITOFREDEMPTION = 32, //4294967296
};

enum DISPEL_TYPE
{
	DISPEL_ZGTRINKETS	= -1,
	DISPEL_NULL,
	DISPEL_MAGIC,
	DISPEL_CURSE,
	DISPEL_DISEASE,
	DISPEL_POISON,
	DISPEL_STEALTH,
	DISPEL_INVISIBILTY,
	DISPEL_ALL,
	DISPEL_SPECIAL_NPCONLY,
	DISPEL_FRENZY,
	NUM_DISPELS,
};

enum DISPEL_MECHANIC_TYPE
{
    DISPEL_MECHANIC_CHARM       = 1,
    DISPEL_MECHANIC_FEAR        = 5,
    DISPEL_MECHANIC_ROOT        = 7,
    DISPEL_MECHANIC_SLEEP       = 10,
    DISPEL_MECHANIC_SNARE       = 11,
    DISPEL_MECHANIC_STUN        = 12,
    DISPEL_MECHANIC_KNOCKOUT    = 14,
    DISPEL_MECHANIC_BLEED       = 15,
    DISPEL_MECHANIC_POLYMORPH   = 17,
    DISPEL_MECHANIC_BANISH      = 18,
    DISPEL_MECHANIC_MOUNTED     = 21,
};
enum MECHANICS
{
	MECHANIC_CHARMED		= 1,
	MECHANIC_DISORIENTED,	// 2
	MECHANIC_DISARMED,		// 3
	MECHANIC_DISTRACED,		// 4
	MECHANIC_FLEEING,		// 5
	MECHANIC_CLUMSY,		// 6
	MECHANIC_ROOTED,		// 7
	MECHANIC_PACIFIED,		// 8
	MECHANIC_SILENCED,		// 9
	MECHANIC_ASLEEP,		// 10
	MECHANIC_ENSNARED,		// 11
	MECHANIC_STUNNED,
    MECHANIC_FROZEN,
    MECHANIC_INCAPACIPATED,
    MECHANIC_BLEEDING,
    MECHANIC_HEALING,
    MECHANIC_POLYMORPHED,
    MECHANIC_BANISHED,
    MECHANIC_SHIELDED,
    MECHANIC_SHACKLED,
    MECHANIC_MOUNTED,
    MECHANIC_SEDUCED,
    MECHANIC_TURNED,
    MECHANIC_HORRIFIED,
    MECHANIC_INVULNARABLE,
    MECHANIC_INTERRUPTED,
    MECHANIC_DAZED,
    MECHANIC_DISCOVERY,
    MECHANIC_PROTECTED,
    MECHANIC_SAPPED,
	MECHANIC_ENRAGED,
	MECHANIC_COUNT
};

typedef enum SpellEffectTarget
{
	EFF_TARGET_NONE										= 0,
	EFF_TARGET_SELF										= 1,
	EFF_TARGET_INVISIBLE_OR_HIDDEN_ENEMIES_AT_LOCATION_RADIUS		= 3,
	EFF_TARGET_PET										= 5,
	EFF_TARGET_SINGLE_ENEMY								= 6,
	EFF_TARGET_SCRIPTED_TARGET							= 7,
	EFF_TARGET_ALL_TARGETABLE_AROUND_LOCATION_IN_RADIUS	= 8,
	EFF_TARGET_HEARTSTONE_LOCATION						= 9,
	EFF_TARGET_ALL_ENEMY_IN_AREA						= 15,
	EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT				= 16,
	EFF_TARGET_TELEPORT_LOCATION						= 17,
	EFF_TARGET_LOCATION_TO_SUMMON						= 18,
	EFF_TARGET_ALL_PARTY_AROUND_CASTER					= 20,
	EFF_TARGET_SINGLE_FRIEND							= 21,
	EFF_TARGET_ALL_ENEMIES_AROUND_CASTER				= 22,
	EFF_TARGET_GAMEOBJECT								= 23,
	EFF_TARGET_IN_FRONT_OF_CASTER						= 24,
	EFF_TARGET_DUEL										= 25,//Dont know the real name!!!
	EFF_TARGET_GAMEOBJECT_ITEM							= 26,
	EFF_TARGET_PET_MASTER								= 27,
	EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED				= 28,
	EFF_TARGET_ALL_PARTY_IN_AREA_CHANNELED				= 29,
	EFF_TARGET_ALL_FRIENDLY_IN_AREA						= 30,
	EFF_TARGET_ALL_TARGETABLE_AROUND_LOCATION_IN_RADIUS_OVER_TIME	= 31,
	EFF_TARGET_MINION									= 32,
	EFF_TARGET_ALL_PARTY_IN_AREA						= 33,
	EFF_TARGET_SINGLE_PARTY								= 35,
	EFF_TARGET_PET_SUMMON_LOCATION						= 36,
	EFF_TARGET_ALL_PARTY								= 37,
	EFF_TARGET_SCRIPTED_OR_SINGLE_TARGET				= 38,
	EFF_TARGET_SELF_FISHING								= 39,
	EFF_TARGET_SCRIPTED_GAMEOBJECT						= 40,
	EFF_TARGET_TOTEM_EARTH								= 41,
	EFF_TARGET_TOTEM_WATER								= 42,
	EFF_TARGET_TOTEM_AIR								= 43,
	EFF_TARGET_TOTEM_FIRE								= 44,
	EFF_TARGET_CHAIN									= 45,
	EFF_TARGET_SCIPTED_OBJECT_LOCATION					= 46,
	EFF_TARGET_DYNAMIC_OBJECT							= 47,//not sure exactly where is used
	EFF_TARGET_MULTIPLE_SUMMON_LOCATION					= 48,
	EFF_TARGET_MULTIPLE_SUMMON_PET_LOCATION				= 49,
	EFF_TARGET_SUMMON_LOCATION							= 50,
	EFF_TARGET_CALIRI_EGS								= 51,
	EFF_TARGET_LOCATION_NEAR_CASTER						= 52,
	EFF_TARGET_CURRENT_SELECTION						= 53,
	EFF_TARGET_TARGET_AT_ORIENTATION_TO_CASTER			= 54,
	EFF_TARGET_LOCATION_INFRONT_CASTER					= 55,
	EFF_TARGET_PARTY_MEMBER								= 57,
	EFF_TARGET_TARGET_FOR_VISUAL_EFFECT					= 59,
	EFF_TARGET_SCRIPTED_TARGET2							= 60,
	EFF_TARGET_AREAEFFECT_PARTY_AND_CLASS				= 61,
	EFF_TARGET_PRIEST_CHAMPION							= 62,	//wtf ?
	EFF_TARGET_NATURE_SUMMON_LOCATION					= 63,
	EFF_TARGET_BEHIND_TARGET_LOCATION					= 65,
	EFF_TARGET_MULTIPLE_GUARDIAN_SUMMON_LOCATION		= 72,
	EFF_TARGET_NETHETDRAKE_SUMMON_LOCATION				= 73,
	EFF_TARGET_SCRIPTED_LOCATION						= 74,
	EFF_TARGET_LOCATION_INFRONT_CASTER_AT_RANGE			= 75,
	EFF_TARGET_ENEMYS_IN_ARE_CHANNELED_WITH_EXCEPTIONS	= 76,
	EFF_TARGET_SELECTED_ENEMY_CHANNELED					= 77,
	EFF_TARGET_SELECTED_ENEMY_DEADLY_POISON				= 86,
	EFF_TARGET_SIMPLE_AOE								= 87,	//just seems to be a simple aoe target, with a little circle
	EFF_TARGET_SMALL_AOE								= 88,	//even smaller aoe circle
	EFF_TARGET_NONCOMBAT_PET							= 90,	//target non-combat pet :P
	EFF_TARGET_VEHICLE									= 94,
	EFF_TARGET_VEHICLEDRIVER							= 95,
	EFF_TARGET_VEHICLE_PASSENGER_0						= 96,
	EFF_TARGET_VEHICLE_PASSENGER_1						= 97,
	EFF_TARGET_VEHICLE_PASSENGER_2						= 98,
	EFF_TARGET_VEHICLE_PASSENGER_3						= 99,
	EFF_TARGET_VEHICLE_PASSENGER_4						= 100,
	EFF_TARGET_VEHICLE_PASSENGER_5						= 101,
	EFF_TARGET_VEHICLE_PASSENGER_6						= 102,
	EFF_TARGET_VEHICLE_PASSENGER_7						= 103,
	EFF_TARGET_IN_FRONT_OF_CASTER_30					= 104,
	TOTAL_SPELL_TARGET									= 111	// note: This is the highest known as of 3.3.3
} SpellEffectTarget;

ARCTIC_INLINE bool IsFlyingSpell(SpellEntry *sp)
{
	if( sp->EffectApplyAuraName[0] == 206 ||
		sp->EffectApplyAuraName[1] == 206 ||
		sp->EffectApplyAuraName[1] == 206 ||

		sp->EffectApplyAuraName[0] == 207 ||
		sp->EffectApplyAuraName[1] == 207 ||
		sp->EffectApplyAuraName[1] == 207 ||

		sp->EffectApplyAuraName[0] == 208 ||
		sp->EffectApplyAuraName[1] == 208 ||
		sp->EffectApplyAuraName[1] == 208 ||

		sp->NameHash == SPELL_HASH_SWIFT_FLIGHT_FORM ||
		sp->NameHash == SPELL_HASH_FLIGHT_FORM ||
		sp->NameHash == SPELL_HASH_MAGNIFICENT_FLYING_CARPET ||
		sp->NameHash == SPELL_HASH_FLYING_CARPET )
	{
		return true;
	}

	return false;
}

ARCTIC_INLINE bool IsTargetingStealthed(SpellEntry *sp)
{
	if(	sp->Id == 3600 )
		return false;

	if(		sp->EffectImplicitTargetA[0]==EFF_TARGET_INVISIBLE_OR_HIDDEN_ENEMIES_AT_LOCATION_RADIUS ||
			sp->EffectImplicitTargetA[1]==EFF_TARGET_INVISIBLE_OR_HIDDEN_ENEMIES_AT_LOCATION_RADIUS ||
			sp->EffectImplicitTargetA[2]==EFF_TARGET_INVISIBLE_OR_HIDDEN_ENEMIES_AT_LOCATION_RADIUS ||
			sp->EffectImplicitTargetB[0]==EFF_TARGET_INVISIBLE_OR_HIDDEN_ENEMIES_AT_LOCATION_RADIUS ||
			sp->EffectImplicitTargetB[1]==EFF_TARGET_INVISIBLE_OR_HIDDEN_ENEMIES_AT_LOCATION_RADIUS ||
			sp->EffectImplicitTargetB[2]==EFF_TARGET_INVISIBLE_OR_HIDDEN_ENEMIES_AT_LOCATION_RADIUS ||

			sp->EffectImplicitTargetA[0]==EFF_TARGET_ALL_ENEMIES_AROUND_CASTER ||
			sp->EffectImplicitTargetA[1]==EFF_TARGET_ALL_ENEMIES_AROUND_CASTER ||
			sp->EffectImplicitTargetA[2]==EFF_TARGET_ALL_ENEMIES_AROUND_CASTER ||
			sp->EffectImplicitTargetB[0]==EFF_TARGET_ALL_ENEMIES_AROUND_CASTER ||
			sp->EffectImplicitTargetB[1]==EFF_TARGET_ALL_ENEMIES_AROUND_CASTER ||
			sp->EffectImplicitTargetB[2]==EFF_TARGET_ALL_ENEMIES_AROUND_CASTER ||

			sp->EffectImplicitTargetA[0]==EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED ||
			sp->EffectImplicitTargetA[1]==EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED ||
			sp->EffectImplicitTargetA[2]==EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED ||
			sp->EffectImplicitTargetB[0]==EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED ||
			sp->EffectImplicitTargetB[1]==EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED ||
			sp->EffectImplicitTargetB[2]==EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED ||

			sp->EffectImplicitTargetA[0]==EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT ||
			sp->EffectImplicitTargetA[1]==EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT ||
			sp->EffectImplicitTargetA[2]==EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT ||
			sp->EffectImplicitTargetB[0]==EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT ||
			sp->EffectImplicitTargetB[1]==EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT ||
			sp->EffectImplicitTargetB[2]==EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT
		)
	{
		return true;
	}

	return false;
}

typedef void(Spell::*pSpellEffect)(uint32 i);
typedef void(Spell::*pSpellTarget)(uint32 i, uint32 j);

enum PowerType
{
	POWER_TYPE_HEALTH	 = -2,
	POWER_TYPE_MANA		 = 0,
	POWER_TYPE_RAGE		 = 1,
	POWER_TYPE_FOCUS	 = 2,
	POWER_TYPE_ENERGY	 = 3,
	POWER_TYPE_HAPPINESS = 4, // Not used in creature powertypes.
	POWER_TYPE_RUNE		 = 5,
	POWER_TYPE_RUNIC	 = 6,
	MAX_POWER_TYPE		 = 7
};

#define GO_FISHING_BOBBER 35591

#define SPELL_SPELL_CHANNEL_UPDATE_INTERVAL 1000
class DummySpellHandler;

enum SpellDidHitResult
{
	SPELL_DID_HIT_SUCCESS					= 0,
	SPELL_DID_HIT_MISS						= 1,
	SPELL_DID_HIT_RESIST					= 2,
	SPELL_DID_HIT_DODGE						= 3,
	SPELL_DID_HIT_PARRY						= 4,
	SPELL_DID_HIT_BLOCK						= 5,
	SPELL_DID_HIT_EVADE						= 6,
	SPELL_DID_HIT_IMMUNE					= 7,
	SPELL_DID_HIT_IMMUNE_2					= 8,
	SPELL_DID_HIT_DEFLECT					= 9,
	SPELL_DID_HIT_ABSORB					= 10,
	SPELL_DID_HIT_REFLECT					= 11,
};


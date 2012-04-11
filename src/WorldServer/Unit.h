/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

class AIInterface;

#define MAX_AURAS 96 // 40 buff slots, 46 debuff slots.
#define MAX_POSITIVE_AURAS 40 // maximum numbers of buffs
#define MAX_PASSIVE_AURAS 192   // grep: i mananged to break this.. :p seems we need more

bool SERVER_DECL Rand(float);

#define UF_TARGET_DIED  1
#define UF_ATTACKING	2 // this unit is attacking it's selection
#define SPELL_GROUPS	96
#define SPELL_MODIFIERS 30
#define DIMINISH_GROUPS	13
#define NUM_MECHANIC 32

#define UNIT_TYPE_HUMANOID_BIT (1 << (HUMANOID-1)) //should get computed by precompiler ;)

class Aura;
class Spell;
class AIInterface;
class GameObject;
class Creature;

struct CreatureInfo;
struct FactionTemplateDBC;
struct FactionDBC;

#define MAX_DECLINED_NAME_CASES 5

struct DeclinedName
{
    std::string name[MAX_DECLINED_NAME_CASES];
};

struct ReflectSpellSchool
{
	uint32 spellId;
	int32 school;
	int32 chance;
	int32 require_aura_hash;
	bool infinity;
	bool infront;
};

typedef struct
{
	uint32 spellid;
	uint64 caster;//not yet in use
	int32 amt;
	int32 reflect_pct;
}Absorb;

typedef std::list<Absorb*> SchoolAbsorb;

typedef struct
{
	uint32 spellid;
	uint32 mindmg;
	uint32 maxdmg;
} OnHitSpell;

struct DamageSplitTarget
{
	uint64 m_target; // we store them
	uint32 m_spellId;
	float m_pctDamageSplit; // % of taken damage to transfer (i.e. Soul Link)
	uint32 m_flatDamageSplit; // flat damage to transfer (i.e. Blessing of Sacrifice)
	uint8 damage_type; // bitwise 0-127 thingy
	bool active;
};

struct AreaAura
{
	uint32 auraid;
	Unit* caster;
};

typedef struct
{
	SpellEntry *spell_info;
	uint32 charges;
	bool deleted;
} ExtraStrike;

typedef struct
{
	uint32 spell;
	uint32 chance;
	bool self;
	bool deleted;
} onAuraRemove;

enum DeathState
{
	ALIVE = 0,  // Unit is alive and well
	JUST_DIED,  // Unit has JUST died
	CORPSE,	 // Unit has died but remains in the world as a corpse
	DEAD		// Unit is dead and his corpse is gone from the world
};

#define HIGHEST_FACTION = 46
enum Factions
{
	FACTION_BLOODSAIL_BUCCANEERS,
	FACTION_BOOTY_BAY,
	FACTION_GELKIS_CLAN_CENTAUR,
	FACTION_MAGRAM_CLAN_CENTAUR,
	FACTION_THORIUM_BROTHERHOOD,
	FACTION_RAVENHOLDT,
	FACTION_SYNDICATE,
	FACTION_GADGETZAN,
	FACTION_WILDHAMMER_CLAN,
	FACTION_RATCHET,
	FACTION_UNK1,
	FACTION_UNK2,
	FACTION_UNK3,
	FACTION_ARGENT_DAWN,
	FACTION_ORGRIMMAR,
	FACTION_DARKSPEAR_TROLLS,
	FACTION_THUNDER_BLUFF,
	FACTION_UNDERCITY,
	FACTION_GNOMEREGAN_EXILES,
	FACTION_STORMWIND,
	FACTION_IRONFORGE,
	FACTION_DARNASSUS,
	FACTION_LEATHERWORKING_DRAGON,
	FACTION_LEATHERWORKING_ELEMENTAL,
	FACTION_LEATHERWORKING_TRIBAL,
	FACTION_ENGINEERING_GNOME,
	FACTION_ENGINEERING_GOBLIN,
	FACTION_WINTERSABER_TRAINERS,
	FACTION_EVERLOOK,
	FACTION_BLACKSMITHING_ARMOR,
	FACTION_BLACKSMITHING_WEAPON,
	FACTION_BLACKSMITHING_AXE,
	FACTION_BLACKSMITHING_SWORD,
	FACTION_BLACKSMITHING_HAMMER,
	FACTION_CAER_DARROW,
	FACTION_TIMBERMAW_FURBOLGS,
	FACTION_CENARION_CIRCLE,
	FACTION_SHATTERSPEAR_TROLLS,
	FACTION_RAVASAUR_TRAINERS,
	FACTION_BATTLEGROUND_NEUTRAL,
	FACTION_STORMPIKE_GUARDS,
	FACTION_FROSTWOLF_CLAN,
	FACTION_HYDRAXIAN_WATERLORDS,
	FACTION_MORO_GAI,
	FACTION_SHEN_DRALAR,
	FACTION_SILVERWING_SENTINELS,
	FACTION_WARSONG_OUTRIDERS
};

// EmotesText.dbc
typedef enum
{
    TEXT_EMOTE_AGREE                = 1,
    TEXT_EMOTE_AMAZE                = 2,
    TEXT_EMOTE_ANGRY                = 3,
    TEXT_EMOTE_APOLOGIZE            = 4,
    TEXT_EMOTE_APPLAUD              = 5,
    TEXT_EMOTE_BASHFUL              = 6,
    TEXT_EMOTE_BECKON               = 7,
    TEXT_EMOTE_BEG                  = 8,
    TEXT_EMOTE_BITE                 = 9,
    TEXT_EMOTE_BLEED                = 10,
    TEXT_EMOTE_BLINK                = 11,
    TEXT_EMOTE_BLUSH                = 12,
    TEXT_EMOTE_BONK                 = 13,
    TEXT_EMOTE_BORED                = 14,
    TEXT_EMOTE_BOUNCE               = 15,
    TEXT_EMOTE_BRB                  = 16,
    TEXT_EMOTE_BOW                  = 17,
    TEXT_EMOTE_BURP                 = 18,
    TEXT_EMOTE_BYE                  = 19,
    TEXT_EMOTE_CACKLE               = 20,
    TEXT_EMOTE_CHEER                = 21,
    TEXT_EMOTE_CHICKEN              = 22,
    TEXT_EMOTE_CHUCKLE              = 23,
    TEXT_EMOTE_CLAP                 = 24,
    TEXT_EMOTE_CONFUSED             = 25,
    TEXT_EMOTE_CONGRATULATE         = 26,
    TEXT_EMOTE_COUGH                = 27,
    TEXT_EMOTE_COWER                = 28,
    TEXT_EMOTE_CRACK                = 29,
    TEXT_EMOTE_CRINGE               = 30,
    TEXT_EMOTE_CRY                  = 31,
    TEXT_EMOTE_CURIOUS              = 32,
    TEXT_EMOTE_CURTSEY              = 33,
    TEXT_EMOTE_DANCE                = 34,
    TEXT_EMOTE_DRINK                = 35,
    TEXT_EMOTE_DROOL                = 36,
    TEXT_EMOTE_EAT                  = 37,
    TEXT_EMOTE_EYE                  = 38,
    TEXT_EMOTE_FART                 = 39,
    TEXT_EMOTE_FIDGET               = 40,
    TEXT_EMOTE_FLEX                 = 41,
    TEXT_EMOTE_FROWN                = 42,
    TEXT_EMOTE_GASP                 = 43,
    TEXT_EMOTE_GAZE                 = 44,
    TEXT_EMOTE_GIGGLE               = 45,
    TEXT_EMOTE_GLARE                = 46,
    TEXT_EMOTE_GLOAT                = 47,
    TEXT_EMOTE_GREET                = 48,
    TEXT_EMOTE_GRIN                 = 49,
    TEXT_EMOTE_GROAN                = 50,
    TEXT_EMOTE_GROVEL               = 51,
    TEXT_EMOTE_GUFFAW               = 52,
    TEXT_EMOTE_HAIL                 = 53,
    TEXT_EMOTE_HAPPY                = 54,
    TEXT_EMOTE_HELLO                = 55,
    TEXT_EMOTE_HUG                  = 56,
    TEXT_EMOTE_HUNGRY               = 57,
    TEXT_EMOTE_KISS                 = 58,
    TEXT_EMOTE_KNEEL                = 59,
    TEXT_EMOTE_LAUGH                = 60,
    TEXT_EMOTE_LAYDOWN              = 61,
    TEXT_EMOTE_MESSAGE              = 62,
    TEXT_EMOTE_MOAN                 = 63,
    TEXT_EMOTE_MOON                 = 64,
    TEXT_EMOTE_MOURN                = 65,
    TEXT_EMOTE_NO                   = 66,
    TEXT_EMOTE_NOD                  = 67,
    TEXT_EMOTE_NOSEPICK             = 68,
    TEXT_EMOTE_PANIC                = 69,
    TEXT_EMOTE_PEER                 = 70,
    TEXT_EMOTE_PLEAD                = 71,
    TEXT_EMOTE_POINT                = 72,
    TEXT_EMOTE_POKE                 = 73,
    TEXT_EMOTE_PRAY                 = 74,
    TEXT_EMOTE_ROAR                 = 75,
    TEXT_EMOTE_ROFL                 = 76,
    TEXT_EMOTE_RUDE                 = 77,
    TEXT_EMOTE_SALUTE               = 78,
    TEXT_EMOTE_SCRATCH              = 79,
    TEXT_EMOTE_SEXY                 = 80,
    TEXT_EMOTE_SHAKE                = 81,
    TEXT_EMOTE_SHOUT                = 82,
    TEXT_EMOTE_SHRUG                = 83,
    TEXT_EMOTE_SHY                  = 84,
    TEXT_EMOTE_SIGH                 = 85,
    TEXT_EMOTE_SIT                  = 86,
    TEXT_EMOTE_SLEEP                = 87,
    TEXT_EMOTE_SNARL                = 88,
    TEXT_EMOTE_SPIT                 = 89,
    TEXT_EMOTE_STARE                = 90,
    TEXT_EMOTE_SURPRISED            = 91,
    TEXT_EMOTE_SURRENDER            = 92,
    TEXT_EMOTE_TALK                 = 93,
    TEXT_EMOTE_TALKEX               = 94,
    TEXT_EMOTE_TALKQ                = 95,
    TEXT_EMOTE_TAP                  = 96,
    TEXT_EMOTE_THANK                = 97,
    TEXT_EMOTE_THREATEN             = 98,
    TEXT_EMOTE_TIRED                = 99,
    TEXT_EMOTE_VICTORY              = 100,
    TEXT_EMOTE_WAVE                 = 101,
    TEXT_EMOTE_WELCOME              = 102,
    TEXT_EMOTE_WHINE                = 103,
    TEXT_EMOTE_WHISTLE              = 104,
    TEXT_EMOTE_WORK                 = 105,
    TEXT_EMOTE_YAWN                 = 106,
    TEXT_EMOTE_BOGGLE               = 107,
    TEXT_EMOTE_CALM                 = 108,
    TEXT_EMOTE_COLD                 = 109,
    TEXT_EMOTE_COMFORT              = 110,
    TEXT_EMOTE_CUDDLE               = 111,
    TEXT_EMOTE_DUCK                 = 112,
    TEXT_EMOTE_INSULT               = 113,
    TEXT_EMOTE_INTRODUCE            = 114,
    TEXT_EMOTE_JK                   = 115,
    TEXT_EMOTE_LICK                 = 116,
    TEXT_EMOTE_LISTEN               = 117,
    TEXT_EMOTE_LOST                 = 118,
    TEXT_EMOTE_MOCK                 = 119,
    TEXT_EMOTE_PONDER               = 120,
    TEXT_EMOTE_POUNCE               = 121,
    TEXT_EMOTE_PRAISE               = 122,
    TEXT_EMOTE_PURR                 = 123,
    TEXT_EMOTE_PUZZLE               = 124,
    TEXT_EMOTE_RAISE                = 125,
    TEXT_EMOTE_READY                = 126,
    TEXT_EMOTE_SHIMMY               = 127,
    TEXT_EMOTE_SHIVER               = 128,
    TEXT_EMOTE_SHOO                 = 129,
    TEXT_EMOTE_SLAP                 = 130,
    TEXT_EMOTE_SMIRK                = 131,
    TEXT_EMOTE_SNIFF                = 132,
    TEXT_EMOTE_SNUB                 = 133,
    TEXT_EMOTE_SOOTHE               = 134,
    TEXT_EMOTE_STINK                = 135,
    TEXT_EMOTE_TAUNT                = 136,
    TEXT_EMOTE_TEASE                = 137,
    TEXT_EMOTE_THIRSTY              = 138,
    TEXT_EMOTE_VETO                 = 139,
    TEXT_EMOTE_SNICKER              = 140,
    TEXT_EMOTE_STAND                = 141,
    TEXT_EMOTE_TICKLE               = 142,
    TEXT_EMOTE_VIOLIN               = 143,
    TEXT_EMOTE_SMILE                = 163,
    TEXT_EMOTE_RASP                 = 183,
    TEXT_EMOTE_PITY                 = 203,
    TEXT_EMOTE_GROWL                = 204,
    TEXT_EMOTE_BARK                 = 205,
    TEXT_EMOTE_SCARED               = 223,
    TEXT_EMOTE_FLOP                 = 224,
    TEXT_EMOTE_LOVE                 = 225,
    TEXT_EMOTE_MOO                  = 226,
    TEXT_EMOTE_COMMEND              = 243,
    TEXT_EMOTE_TRAIN                = 264,
    TEXT_EMOTE_HELPME               = 303,
    TEXT_EMOTE_INCOMING             = 304,
    TEXT_EMOTE_CHARGE               = 305,
    TEXT_EMOTE_FLEE                 = 306,
    TEXT_EMOTE_ATTACKMYTARGET       = 307,
    TEXT_EMOTE_OOM                  = 323,
    TEXT_EMOTE_FOLLOW               = 324,
    TEXT_EMOTE_WAIT                 = 325,
    TEXT_EMOTE_HEALME               = 326,
    TEXT_EMOTE_OPENFIRE             = 327,
    TEXT_EMOTE_FLIRT                = 328,
    TEXT_EMOTE_JOKE                 = 329,
    TEXT_EMOTE_GOLFCLAP             = 343,
    TEXT_EMOTE_WINK                 = 363,
    TEXT_EMOTE_PAT                  = 364,
    TEXT_EMOTE_SERIOUS              = 365,
    TEXT_EMOTE_MOUNT_SPECIAL        = 366,
    TEXT_EMOTE_GOODLUCK             = 367,
    TEXT_EMOTE_BLAME                = 368,
    TEXT_EMOTE_BLANK                = 369,
    TEXT_EMOTE_BRANDISH             = 370,
    TEXT_EMOTE_BREATH               = 371,
    TEXT_EMOTE_DISAGREE             = 372,
    TEXT_EMOTE_DOUBT                = 373,
    TEXT_EMOTE_EMBARRASS            = 374,
    TEXT_EMOTE_ENCOURAGE            = 375,
    TEXT_EMOTE_ENEMY                = 376,
    TEXT_EMOTE_EYEBROW              = 377,
    TEXT_EMOTE_TOAST                = 378,
    TEXT_EMOTE_FAIL                 = 379,
    TEXT_EMOTE_HIGHFIVE             = 380,
    TEXT_EMOTE_ABSENT               = 381,
    TEXT_EMOTE_ARM                  = 382,
    TEXT_EMOTE_AWE                  = 383,
    TEXT_EMOTE_BACKPACK             = 384,
    TEXT_EMOTE_BADFEELING           = 385,
    TEXT_EMOTE_CHALLENGE            = 386,
    TEXT_EMOTE_CHUG                 = 387,
    TEXT_EMOTE_DING                 = 389,
    TEXT_EMOTE_FACEPALM             = 390,
    TEXT_EMOTE_FAINT                = 391,
    TEXT_EMOTE_GO                   = 392,
    TEXT_EMOTE_GOING                = 393,
    TEXT_EMOTE_GLOWER               = 394,
    TEXT_EMOTE_HEADACHE             = 395,
    TEXT_EMOTE_HICCUP               = 396,
    TEXT_EMOTE_HISS                 = 398,
    TEXT_EMOTE_HOLDHAND             = 399,
    TEXT_EMOTE_HURRY                = 401,
    TEXT_EMOTE_IDEA                 = 402,
    TEXT_EMOTE_JEALOUS              = 403,
    TEXT_EMOTE_LUCK                 = 404,
    TEXT_EMOTE_MAP                  = 405,
    TEXT_EMOTE_MERCY                = 406,
    TEXT_EMOTE_MUTTER               = 407,
    TEXT_EMOTE_NERVOUS              = 408,
    TEXT_EMOTE_OFFER                = 409,
    TEXT_EMOTE_PET                  = 410,
    TEXT_EMOTE_PINCH                = 411,
    TEXT_EMOTE_PROUD                = 413,
    TEXT_EMOTE_PROMISE              = 414,
    TEXT_EMOTE_PULSE                = 415,
    TEXT_EMOTE_PUNCH                = 416,
    TEXT_EMOTE_POUT                 = 417,
    TEXT_EMOTE_REGRET               = 418,
    TEXT_EMOTE_REVENGE              = 420,
    TEXT_EMOTE_ROLLEYES             = 421,
    TEXT_EMOTE_RUFFLE               = 422,
    TEXT_EMOTE_SAD                  = 423,
    TEXT_EMOTE_SCOFF                = 424,
    TEXT_EMOTE_SCOLD                = 425,
    TEXT_EMOTE_SCOWL                = 426,
    TEXT_EMOTE_SEARCH               = 427,
    TEXT_EMOTE_SHAKEFIST            = 428,
    TEXT_EMOTE_SHIFTY               = 429,
    TEXT_EMOTE_SHUDDER              = 430,
    TEXT_EMOTE_SIGNAL               = 431,
    TEXT_EMOTE_SILENCE              = 432,
    TEXT_EMOTE_SING                 = 433,
    TEXT_EMOTE_SMACK                = 434,
    TEXT_EMOTE_SNEAK                = 435,
    TEXT_EMOTE_SNEEZE               = 436,
    TEXT_EMOTE_SNORT                = 437,
    TEXT_EMOTE_SQUEAL               = 438,
    TEXT_EMOTE_STOPATTACK           = 439,
    TEXT_EMOTE_SUSPICIOUS           = 440,
    TEXT_EMOTE_THINK                = 441,
    TEXT_EMOTE_TRUCE                = 442,
    TEXT_EMOTE_TWIDDLE              = 443,
    TEXT_EMOTE_WARN                 = 444,
    TEXT_EMOTE_SNAP                 = 445,
    TEXT_EMOTE_CHARM                = 446,
    TEXT_EMOTE_COVEREARS            = 447,
    TEXT_EMOTE_CROSSARMS            = 448,
    TEXT_EMOTE_LOOK                 = 449,
    TEXT_EMOTE_OBJECT               = 450,
    TEXT_EMOTE_SWEAT                = 451,
    TEXT_EMOTE_YW                   = 453,
} TextEmoteType;

typedef enum
{
    EMOTE_ONESHOT_NONE                 = 0,
    EMOTE_ONESHOT_TALK                 = 1,
    EMOTE_ONESHOT_BOW                  = 2,
    EMOTE_ONESHOT_WAVE                 = 3,
    EMOTE_ONESHOT_CHEER                = 4,
    EMOTE_ONESHOT_EXCLAMATION          = 5,
    EMOTE_ONESHOT_QUESTION             = 6,
    EMOTE_ONESHOT_EAT                  = 7,
    EMOTE_STATE_DANCE                  = 10,
    EMOTE_ONESHOT_LAUGH                = 11,
    EMOTE_STATE_SLEEP                  = 12,
    EMOTE_STATE_SIT                    = 13,
    EMOTE_ONESHOT_RUDE                 = 14,
    EMOTE_ONESHOT_ROAR                 = 15,
    EMOTE_ONESHOT_KNEEL                = 16,
    EMOTE_ONESHOT_KISS                 = 17,
    EMOTE_ONESHOT_CRY                  = 18,
    EMOTE_ONESHOT_CHICKEN              = 19,
    EMOTE_ONESHOT_BEG                  = 20,
    EMOTE_ONESHOT_APPLAUD              = 21,
    EMOTE_ONESHOT_SHOUT                = 22,
    EMOTE_ONESHOT_FLEX                 = 23,
    EMOTE_ONESHOT_SHY                  = 24,
    EMOTE_ONESHOT_POINT                = 25,
    EMOTE_STATE_STAND                  = 26,
    EMOTE_STATE_READYUNARMED           = 27,
    EMOTE_STATE_WORK_SHEATHED          = 28,
    EMOTE_STATE_POINT                  = 29,
    EMOTE_STATE_NONE                   = 30,
    EMOTE_ONESHOT_WOUND                = 33,
    EMOTE_ONESHOT_WOUNDCRITICAL        = 34,
    EMOTE_ONESHOT_ATTACKUNARMED        = 35,
    EMOTE_ONESHOT_ATTACK1H             = 36,
    EMOTE_ONESHOT_ATTACK2HTIGHT        = 37,
    EMOTE_ONESHOT_ATTACK2HLOOSE        = 38,
    EMOTE_ONESHOT_PARRYUNARMED         = 39,
    EMOTE_ONESHOT_PARRYSHIELD          = 43,
    EMOTE_ONESHOT_READYUNARMED         = 44,
    EMOTE_ONESHOT_READY1H              = 45,
    EMOTE_ONESHOT_READYBOW             = 48,
    EMOTE_ONESHOT_SPELLPRECAST         = 50,
    EMOTE_ONESHOT_SPELLCAST            = 51,
    EMOTE_ONESHOT_BATTLEROAR           = 53,
    EMOTE_ONESHOT_SPECIALATTACK1H      = 54,
    EMOTE_ONESHOT_KICK                 = 60,
    EMOTE_ONESHOT_ATTACKTHROWN         = 61,
    EMOTE_STATE_STUN                   = 64,
    EMOTE_STATE_DEAD                   = 65,
    EMOTE_ONESHOT_SALUTE               = 66,
    EMOTE_STATE_KNEEL                  = 68,
    EMOTE_STATE_USESTANDING            = 69,
    EMOTE_ONESHOT_WAVE_NOSHEATHE       = 70,
    EMOTE_ONESHOT_CHEER_NOSHEATHE      = 71,
    EMOTE_ONESHOT_EAT_NOSHEATHE        = 92,
    EMOTE_STATE_STUN_NOSHEATHE         = 93,
    EMOTE_ONESHOT_DANCE                = 94,
    EMOTE_ONESHOT_SALUTE_NOSHEATH      = 113,
    EMOTE_STATE_USESTANDING_NOSHEATHE  = 133,
    EMOTE_ONESHOT_LAUGH_NOSHEATHE      = 153,
    EMOTE_STATE_WORK                   = 173,
    EMOTE_STATE_SPELLPRECAST           = 193,
    EMOTE_ONESHOT_READYRIFLE           = 213,
    EMOTE_STATE_READYRIFLE             = 214,
    EMOTE_STATE_WORK_MINING            = 233,
    EMOTE_STATE_WORK_CHOPWOOD          = 234,
    EMOTE_STATE_APPLAUD                = 253,
    EMOTE_ONESHOT_LIFTOFF              = 254,
    EMOTE_ONESHOT_YES                  = 273,
    EMOTE_ONESHOT_NO                   = 274,
    EMOTE_ONESHOT_TRAIN                = 275,
    EMOTE_ONESHOT_LAND                 = 293,
    EMOTE_STATE_AT_EASE                = 313,
    EMOTE_STATE_READY1H                = 333,
    EMOTE_STATE_SPELLKNEELSTART        = 353,
    EMOTE_STATE_SUBMERGED              = 373,
    EMOTE_ONESHOT_SUBMERGE             = 374,
    EMOTE_STATE_READY2H                = 375,
    EMOTE_STATE_READYBOW               = 376,
    EMOTE_ONESHOT_MOUNTSPECIAL         = 377,
    EMOTE_STATE_TALK                   = 378,
    EMOTE_STATE_FISHING                = 379,
    EMOTE_ONESHOT_FISHING              = 380,
    EMOTE_ONESHOT_LOOT                 = 381,
    EMOTE_STATE_WHIRLWIND              = 382,
    EMOTE_STATE_DROWNED                = 383,
    EMOTE_STATE_HOLD_BOW               = 384,
    EMOTE_STATE_HOLD_RIFLE             = 385,
    EMOTE_STATE_HOLD_THROWN            = 386,
    EMOTE_ONESHOT_DROWN                = 387,
    EMOTE_ONESHOT_STOMP                = 388,
    EMOTE_ONESHOT_ATTACKOFF            = 389,
    EMOTE_ONESHOT_ATTACKOFFPIERCE      = 390,
    EMOTE_STATE_ROAR                   = 391,
    EMOTE_STATE_LAUGH                  = 392,
    EMOTE_ONESHOT_CREATURE_SPECIAL     = 393,
    EMOTE_ONESHOT_JUMPLANDRUN          = 394,
    EMOTE_ONESHOT_JUMPEND              = 395,
    EMOTE_ONESHOT_TALK_NOSHEATHE       = 396,
    EMOTE_ONESHOT_POINT_NOSHEATHE      = 397,
    EMOTE_STATE_CANNIBALIZE            = 398,
    EMOTE_ONESHOT_JUMPSTART            = 399,
    EMOTE_STATE_DANCESPECIAL           = 400,
    EMOTE_ONESHOT_DANCESPECIAL         = 401,
    EMOTE_ONESHOT_CUSTOMSPELL01        = 402,
    EMOTE_ONESHOT_CUSTOMSPELL02        = 403,
    EMOTE_ONESHOT_CUSTOMSPELL03        = 404,
    EMOTE_ONESHOT_CUSTOMSPELL04        = 405,
    EMOTE_ONESHOT_CUSTOMSPELL05        = 406,
    EMOTE_ONESHOT_CUSTOMSPELL06        = 407,
    EMOTE_ONESHOT_CUSTOMSPELL07        = 408,
    EMOTE_ONESHOT_CUSTOMSPELL08        = 409,
    EMOTE_ONESHOT_CUSTOMSPELL09        = 410,
    EMOTE_ONESHOT_CUSTOMSPELL10        = 411,
    EMOTE_STATE_EXCLAIM                = 412,
    EMOTE_STATE_DANCE_CUSTOM           = 413,
    EMOTE_STATE_SIT_CHAIR_MED          = 415,
    EMOTE_STATE_CUSTOM_SPELL_01        = 416,
    EMOTE_STATE_CUSTOM_SPELL_02        = 417,
    EMOTE_STATE_EAT                    = 418,
    EMOTE_STATE_CUSTOM_SPELL_04        = 419,
    EMOTE_STATE_CUSTOM_SPELL_03        = 420,
    EMOTE_STATE_CUSTOM_SPELL_05        = 421,
    EMOTE_STATE_SPELLEFFECT_HOLD       = 422,
    EMOTE_STATE_EAT_NO_SHEATHE         = 423,
    EMOTE_STATE_MOUNT                  = 424,
    EMOTE_STATE_READY2HL               = 425,
    EMOTE_STATE_SIT_CHAIR_HIGH         = 426,
    EMOTE_STATE_FALL                   = 427,
    EMOTE_STATE_LOOT                   = 428,
    EMOTE_STATE_SUBMERGED_NEW          = 429,
    EMOTE_ONESHOT_COWER                = 430,
    EMOTE_STATE_COWER                  = 431,
    EMOTE_ONESHOT_USESTANDING          = 432,
    EMOTE_STATE_STEALTH_STAND          = 433,
    EMOTE_ONESHOT_OMNICAST_GHOUL       = 434,
    EMOTE_ONESHOT_ATTACKBOW            = 435,
    EMOTE_ONESHOT_ATTACKRIFLE          = 436,
    EMOTE_STATE_SWIM_IDLE              = 437,
    EMOTE_STATE_ATTACK_UNARMED         = 438,
    EMOTE_ONESHOT_SPELLCAST_W_SOUND    = 439,
    EMOTE_ONESHOT_DODGE                = 440,
    EMOTE_ONESHOT_PARRY1H              = 441,
    EMOTE_ONESHOT_PARRY2H              = 442,
    EMOTE_ONESHOT_PARRY2HL             = 443,
    EMOTE_STATE_FLYFALL                = 444,
    EMOTE_ONESHOT_FLYDEATH             = 445,
    EMOTE_STATE_FLY_FALL               = 446,
    EMOTE_ONESHOT_FLY_SIT_GROUND_DOWN  = 447,
    EMOTE_ONESHOT_FLY_SIT_GROUND_UP    = 448,
    EMOTE_ONESHOT_EMERGE               = 449,
    EMOTE_ONESHOT_DRAGONSPIT           = 450,
    EMOTE_STATE_SPECIALUNARMED         = 451,
    EMOTE_ONESHOT_FLYGRAB              = 452,
    EMOTE_STATE_FLYGRABCLOSED          = 453,
    EMOTE_ONESHOT_FLYGRABTHROWN        = 454,
    EMOTE_STATE_FLY_SIT_GROUND         = 455,
    EMOTE_STATE_WALKBACKWARDS          = 456,
    EMOTE_ONESHOT_FLYTALK              = 457,
    EMOTE_ONESHOT_FLYATTACK1H          = 458,
    EMOTE_STATE_CUSTOMSPELL08          = 459,
    EMOTE_ONESHOT_FLY_DRAGONSPIT       = 460,
    EMOTE_STATE_SIT_CHAIR_LOW          = 461,
    EMOTE_ONE_SHOT_STUN                = 462,
    EMOTE_ONESHOT_SPELLCAST_OMNI       = 463,
    EMOTE_STATE_READYTHROWN            = 465,
    EMOTE_ONESHOT_WORK_CHOPWOOD        = 466,
    EMOTE_ONESHOT_WORK_MINING          = 467,
    EMOTE_STATE_SPELL_CHANNEL_OMNI     = 468,
    EMOTE_STATE_SPELL_CHANNEL_DIRECTED = 469,
    EMOTE_STAND_STATE_NONE             = 470,
    EMOTE_STATE_READYJOUST             = 471,
    EMOTE_STATE_STRANGULATE            = 473,
    EMOTE_STATE_READYSPELLOMNI         = 474,
    EMOTE_STATE_HOLD_JOUST             = 475,
    EMOTE_ONESHOT_CRY_JAINA            = 476
} EmoteType;

enum StandState
{
	STANDSTATE_STAND			= 0,
	STANDSTATE_SIT			  = 1,
	STANDSTATE_SIT_CHAIR		= 2,
	STANDSTATE_SLEEP			= 3,
	STANDSTATE_SIT_LOW_CHAIR	= 4,
	STANDSTATE_SIT_MEDIUM_CHAIR = 5,
	STANDSTATE_SIT_HIGH_CHAIR   = 6,
	STANDSTATE_DEAD			 = 7,
	STANDSTATE_KNEEL			= 8
};

enum UnitSpecialStates
{
	UNIT_STATE_NORMAL    = 0x0000,
	UNIT_STATE_DISARMED  = 0X0001,
	UNIT_STATE_CHARM     = 0x0002,
	UNIT_STATE_FEAR      = 0x0004,
	UNIT_STATE_ROOT      = 0x0008,
	UNIT_STATE_SLEEP     = 0x0010,  // never set
	UNIT_STATE_SNARE     = 0x0020,  // never set
	UNIT_STATE_STUN      = 0x0040,
	UNIT_STATE_KNOCKOUT  = 0x0080,  // not used
	UNIT_STATE_BLEED     = 0x0100,  // not used
	UNIT_STATE_POLYMORPH = 0x0200,  // not used
	UNIT_STATE_BANISH    = 0x0400,  // not used
	UNIT_STATE_CONFUSE   = 0x0800,
	UNIT_STATE_PACIFY    = 0x1000,
	UNIT_STATE_SILENCE   = 0x2000,
	UNIT_STATE_FROZEN    = 0x4000,
};

enum UnitFieldBytes1
{
	U_FIELD_BYTES_ANIMATION_FROZEN = 0x01,
};

enum UnitFieldBytes2
{
	U_FIELD_BYTES_FLAG_PVP		= 0x01,
	U_FIELD_BYTES_FLAG_FFA_PVP	= 0x04,
	U_FIELD_BYTES_FLAG_AURAS	= 0x10,
};

enum UnitFieldFlags // UNIT_FIELD_FLAGS #46 - these are client flags
{	//                                            Hex    Bit     Decimal  Comments
	UNIT_FLAG_UNKNOWN_1                  = 0x00000001, // 1            1
	UNIT_FLAG_NOT_ATTACKABLE_2           = 0x00000002, // 2            2  client won't let you attack them
	UNIT_FLAG_LOCK_PLAYER                = 0x00000004, // 3            4  ? does nothing to client (probably wrong) - only taxi code checks this
	UNIT_FLAG_PLAYER_CONTROLLED          = 0x00000008, // 4            8  makes players and NPCs attackable / not attackable
	UNIT_FLAG_UNKNOWN_5                  = 0x00000010, // 5           16  ? some NPCs have this
	UNIT_FLAG_PREPARATION                = 0x00000020, // 6           32  don't take reagents for spells with SPELL_ATTR_EX5_NO_REAGENT_WHILE_PREP
	UNIT_FLAG_PLUS_MOB                   = 0x00000040, // 7           64  ? some NPCs have this (Rare/Elite/Boss?)
	UNIT_FLAG_NOT_ATTACKABLE_1           = 0x00000080, // 8          128  ? can change attackable status (UNIT_FLAG_PLAYER_CONTROLLED | UNIT_FLAG_NOT_ATTACKABLE_1) is NON_PVP_ATTACKABLE
	UNIT_FLAG_NOT_ATTACKABLE_9           = 0x00000100, // 9          256  changes attackable status
	UNIT_FLAG_UNKNOWN_10                 = 0x00000200, // 10         512  3.0.3 - makes you unable to attack everything
	UNIT_FLAG_LOOTING                    = 0x00000400, // 11        1024
	UNIT_FLAG_SELF_RES                   = 0x00000800, // 12        2048  ? some NPCs have this
	UNIT_FLAG_PVP                        = 0x00001000, // 13        4096  sets PvP flag
	UNIT_FLAG_SILENCED                   = 0x00002000, // 14        8192
	UNIT_FLAG_DEAD                       = 0x00004000, // 15       16384  used for special "dead" NPCs like Withered Corpses
	UNIT_FLAG_UNKNOWN_16                 = 0x00008000, // 16       32768  ? some NPCs have this
	UNIT_FLAG_ALIVE                      = 0x00010000, // 17       65536  ?
	UNIT_FLAG_PACIFIED                   = 0x00020000, // 18      131072
	UNIT_FLAG_STUNNED                    = 0x00040000, // 19      262144
	UNIT_FLAG_COMBAT                     = 0x00080000, // 20      524288  sets combat flag
	UNIT_FLAG_MOUNTED_TAXI               = 0x00100000, // 21     1048576  mounted on a taxi
	UNIT_FLAG_DISARMED                   = 0x00200000, // 22     2097152  3.0.3, disable melee spells casting..., "Required melee weapon" added to melee spells tooltip.
	UNIT_FLAG_CONFUSED                   = 0x00400000, // 23     4194304
	UNIT_FLAG_FLEEING                    = 0x00800000, // 24     8388608  fear
	UNIT_FLAG_PLAYER_CONTROLLED_CREATURE = 0x01000000, // 25    16777216  used in spell Eyes of the Beast for pet
	UNIT_FLAG_NOT_SELECTABLE             = 0x02000000, // 26    33554432  cannot select the unit
	UNIT_FLAG_SKINNABLE                  = 0x04000000, // 27    67108864
	UNIT_FLAG_MOUNT		                 = 0x08000000, // 28   134217728  ? was MAKE_CHAR_UNTOUCHABLE (probably wrong), nothing ever set it
	UNIT_FLAG_UNKNOWN_29                 = 0x10000000, // 29   268435456
	UNIT_FLAG_FEIGN_DEATH                = 0x20000000, // 30   536870912
	UNIT_FLAG_SHEATHE                    = 0x40000000, // 31  1073741824  ? was WEAPON_OFF and being used for disarm
	UNIT_FLAG_UNKNOWN_32                 = 0x80000000, // 32  2147483648
};

enum UnitFlags2
{
	UNIT_FLAG2_FEIGN_DEATH				= 0x00000001,
	UNIT_FLAG2_UNK1						= 0x00000002, // Hide unit model (show only player equip)
	UNIT_FLAG2_COMPREHEND_LANG			= 0x00000008,
	UNIT_FLAG2_FORCE_MOVE				= 0x00000040,
	UNIT_FLAG2_REGENERATE_POWER			= 0x00000800
};

enum UnitDynamicFlags
{
	U_DYN_FLAG_LOOTABLE				 = 0x01,
	U_DYN_FLAG_UNIT_TRACKABLE		   = 0x02,
	U_DYN_FLAG_TAGGED_BY_OTHER		  = 0x04,
	U_DYN_FLAG_TAPPED_BY_PLAYER		 = 0x08,
	U_DYN_FLAG_PLAYER_INFO			  = 0x10,
	U_DYN_FLAG_DEAD					 = 0x20,
};

enum DamageFlags
{
	DAMAGE_FLAG_MELEE   = 1,
	DAMAGE_FLAG_HOLY	= 2,
	DAMAGE_FLAG_FIRE	= 4,
	DAMAGE_FLAG_NATURE  = 8,
	DAMAGE_FLAG_FROST   = 16,
	DAMAGE_FLAG_SHADOW  = 32,
	DAMAGE_FLAG_ARCANE  = 64
};

enum WeaponDamageType // this is NOT the same as SPELL_ENTRY_Spell_Dmg_Type, or Spell::GetType(), or SPELL_ENTRY_School !!
{
	MELEE   = 0,
	OFFHAND = 1,
	RANGED  = 2,
};

enum VisualState
{
	ATTACK = 1,
	DODGE,
	PARRY,
	INTERRUPT,
	BLOCK,
	EVADE,
	IMMUNE,
	DEFLECT
};

enum HitStatus
{
	HITSTATUS_unk			= 0x01,
	HITSTATUS_HITANIMATION  = 0x02,
	HITSTATUS_DUALWIELD     = 0x04,
	HITSTATUS_MISS          = 0x10,
	HITSTATUS_ABSORBED      = 0x20,
	HITSTATUS_ABSORBED2		= 0x40,
	HITSTATUS_RESIST        = 0x80,
	HITSTATUS_RESIST2       = 0x100,
	HITSTATUS_CRICTICAL     = 0x200,
	HITSTATUS_BLOCK         = 0x2000,
	HITSTATUS_CRUSHINGBLOW  = 0x8000,
	HITSTATUS_GLANCING      = 0x10000,
	HITSTATUS_NOACTION      = 0x10000,
	HITSTATUS_SWINGNOHITSOUND = 0x80000 // as in miss?
};

enum INVIS_FLAG
{
	INVIS_FLAG_NORMAL, // players and units with no special invisibility flags
	INVIS_FLAG_SPIRIT1,
	INVIS_FLAG_SPIRIT2,
	INVIS_FLAG_TRAP,
	INVIS_FLAG_QUEST,
	INVIS_FLAG_GHOST,
	INVIS_FLAG_UNKNOWN6,
	INVIS_FLAG_UNKNOWN7,
	INVIS_FLAG_SHADOWMOON,
	INVIS_FLAG_NETHERSTORM,
	INVIS_FLAG_PHASED,
	INVIS_FLAG_TOTAL
};

enum FIELD_PADDING // Since this field isnt used you can expand it for you needs
{
	PADDING_NONE
};

struct AuraCheckResponse
{
	uint32 Error;
	uint32 Misc;
};

enum AURA_CHECK_RESULT
{
	AURA_CHECK_RESULT_NONE                 = 1,
	AURA_CHECK_RESULT_HIGHER_BUFF_PRESENT  = 2,
	AURA_CHECK_RESULT_LOWER_BUFF_PRESENT   = 3,
};

enum CUSTOM_TIMERS
{
	CUSTOM_TIMER_CHIMERA_SCORPID,
	CUSTOM_TIMER_ECLIPSE,
	CUSTOM_TIMER_ERADICATION,
	CUSTOM_TIMER_CHEATDEATH,
	CUSTOM_TIMER_RAPTURE,
	NUM_CUSTOM_TIMERS
};

enum Powers
{
    POWER_MANA                          = 0,
    POWER_RAGE                          = 1,
    POWER_FOCUS                         = 2,
    POWER_ENERGY                        = 3,
    POWER_HAPPINESS                     = 4,
    POWER_RUNE                          = 5,
    POWER_RUNIC_POWER                   = 6,
    POWER_HEALTH                        = 0xFFFFFFFE
};

typedef std::list<struct ProcTriggerSpellOnSpell> ProcTriggerSpellOnSpellList;

class MovementInfo
{
public:
	uint32 time;
	float pitch; // -1.55=looking down, 0=looking forward, +1.55=looking up
	float jump_sinAngle; // on slip 8 is zero, on jump some other number
	float jump_cosAngle, jump_xySpeed; // 9,10 changes if you are not on foot
	float jumpspeed; // something related to collision,
	uint32 unk11;
	uint32 spline_unk;
	uint8 unk13;
	uint16 flag16;

	float x, y, z, orientation;
	uint32 flags;
	uint32 FallTime;
	WoWGuid transGuid;
	float transX, transY, transZ, transO;
	uint32 transTime;
	uint8 transSeat;

	WoWGuid guid;

	void init(WorldPacket & data);
	void write(WorldPacket & data);
};

/************************************************************************/
/* "In-Combat" Handler                                                  */
/************************************************************************/

class Unit;
class SERVER_DECL CombatStatusHandler
{
	typedef set<uint64> AttackerMap;
	typedef map<uint64, uint32> AttackTMap;
	typedef set<uint32> HealedSet;		// Must Be Players!
	AttackerMap m_attackers;
	HealedSet m_healers;
	HealedSet m_healed;
	Unit* m_Unit;
	bool m_lastStatus;
	AttackTMap m_attackTargets;
	uint32 condom[16]; // wear protection, damagemap! don't get access violated!
	map<uint64,uint32> DamageMap;

public:
	CombatStatusHandler() : m_lastStatus(false)
	{
		m_attackers.clear();
		m_healers.clear();
		m_healed.clear();
		m_attackTargets.clear();
		DamageMap.clear();
	}

	Unit* GetKiller();													// Gets this unit's current killer.

	void OnDamageDealt(Unit* pTarget, uint32 damage);					// this is what puts the other person in combat.
	void WeHealed(Unit* pHealTarget);									// called when a player heals another player, regardless of combat state.
	void RemoveAttackTarget(Unit* pTarget);							    // means our DoT expired.
	void ForceRemoveAttacker(const uint64& guid);						// when target is invalid pointer

	void UpdateFlag();													// detects if we have changed combat state (in/out), and applies the flag.

	ARCTIC_INLINE bool IsInCombat() { return m_lastStatus; }			// checks if we are in combat or not.

	void OnRemoveFromWorld();											// called when we are removed from world, kills all references to us.

	ARCTIC_INLINE void Vanished()
	{
		ClearAttackers();
		ClearHealers();
		DamageMap.clear();
	}

	bool DidHeal(uint32 guidLow)
	{
		return (m_healed.find(guidLow) != m_healed.end());
	}

	bool HealedBy(uint32 guidLow)
	{
		return (m_healers.find(guidLow) != m_healers.end());
	}

	bool DidDamageTo(uint64 guid)
	{
		return (DamageMap.find(guid) != DamageMap.end());
	}

	ARCTIC_INLINE void SetUnit(Unit* p) { m_Unit = p; }
	void UpdateTargets();

protected:
	bool InternalIsInCombat();											// called by UpdateFlag, do not call from anything else!
	bool IsAttacking(Unit* pTarget);									// internal function used to determine if we are still attacking target x.
	void RemoveHealed(Unit* pHealTarget);								// usually called only by updateflag
	void ClearHealers();												// this is called on instance change.
	void ClearAttackers();												// means we vanished, or died.
	void ClearMyHealers();
};

//====================================================================
//  Unit
//  Base object for Players and Creatures
//====================================================================

class SERVER_DECL Unit : public Object
{
public:
	void CombatStatusHandler_UpdateTargets();

	virtual ~Unit();
	virtual void Init();

	friend class AIInterface;
	friend class Aura;

	virtual void Update( uint32 time );
	virtual void RemoveFromWorld(bool free_guid);
	virtual void OnPushToWorld();

	void setAttackTimer(int32 time, bool offhand);
	bool isAttackReady(bool offhand);
	bool ARCTIC_FASTCALL canReachWithAttack(Unit* pVictim);

	ARCTIC_INLINE void SetDuelWield(bool enabled)
	{
		m_duelWield = enabled;
	}

	// State flags are server-only flags to help me know when to do stuff, like die, or attack
	ARCTIC_INLINE void addStateFlag(uint32 f) { m_state |= f; };
	ARCTIC_INLINE bool hasStateFlag(uint32 f) { return (m_state & f ? true : false); }
	ARCTIC_INLINE void clearStateFlag(uint32 f) { m_state &= ~f; };

	// Stats
	ARCTIC_INLINE uint32 getLevel() { return m_uint32Values[ UNIT_FIELD_LEVEL ]; };
	ARCTIC_INLINE uint8 getRace() { return GetByte(UNIT_FIELD_BYTES_0,0); }
	ARCTIC_INLINE uint8 getClass() { return GetByte(UNIT_FIELD_BYTES_0,1); }
	ARCTIC_INLINE void setRace(uint8 race) { SetByte(UNIT_FIELD_BYTES_0,0,race); }
	ARCTIC_INLINE void setClass(uint8 class_) { SetByte(UNIT_FIELD_BYTES_0,1, class_ ); }
	ARCTIC_INLINE uint32 getClassMask() { return 1 << (getClass() - 1); }
	ARCTIC_INLINE uint32 getRaceMask() { return 1 << (getRace() - 1); }
	ARCTIC_INLINE uint8 getGender() { return GetByte(UNIT_FIELD_BYTES_0,2); }
	ARCTIC_INLINE void setGender(uint8 gender) { SetByte(UNIT_FIELD_BYTES_0,2,gender); }
	ARCTIC_INLINE uint8 getStandState() { return ((uint8)m_uint32Values[UNIT_FIELD_BYTES_1]); }

	uint32 GetSpellDidHitResult( Unit* pVictim, uint32 weapon_damage_type, SpellEntry* ability );
	void Strike( Unit* pVictim, uint32 weapon_damage_type, SpellEntry* ability, int32 add_damage, int32 pct_dmg_mod, uint32 exclusive_damage, bool disable_proc, bool skip_hit_check, bool proc_extrastrike = false );

	uint32 m_procCounter;
	uint32 HandleProc(uint32 flag, Unit* victim, SpellEntry* CastingSpell,uint32 dmg=-1,uint32 abs=0, uint32 weapon_damage_type=0);
	void HandleProcDmgShield(uint32 flag, Unit* attacker);//almost the same as handleproc :P

	void RemoveExtraStrikeTarget(SpellEntry *spell_info);
	void AddExtraStrikeTarget(SpellEntry *spell_info, uint32 charges);

	int32 GetAP();
	int32 GetRAP();

	ARCTIC_INLINE float GetSize() { return GetFloatValue(OBJECT_FIELD_SCALE_X) * GetFloatValue(UNIT_FIELD_BOUNDINGRADIUS); }

	void CastSpell(Unit* Target, uint32 SpellID, bool triggered);
	void CastSpell(Unit* Target, SpellEntry* Sp, bool triggered);
	void CastSpell(uint64 targetGuid, uint32 SpellID, bool triggered);
	void CastSpell(uint64 targetGuid, SpellEntry* Sp, bool triggered);
	uint8 CastSpellAoF(float x,float y,float z,SpellEntry* Sp, bool triggered);
	void EventCastSpell(Unit* Target, SpellEntry * Sp);

	bool isCasting();
	bool IsInInstance();
	double GetResistanceReducion(Unit* pVictim, uint32 type, float armorReducePct);
    void CalculateResistanceReduction(Unit* pVictim,dealdamage *dmg,SpellEntry* ability, float armorreducepct) ;
	void RegenerateHealth();
	void RegenerateEnergy();
	void RegeneratePower(bool isinterrupted);
	void SendPowerUpdate();
	ARCTIC_INLINE void setHRegenTimer(uint32 time) {m_H_regenTimer = time; }
	ARCTIC_INLINE void setPRegenTimer(uint32 time) {m_P_regenTimer = time; }
	ARCTIC_INLINE void DelayPowerRegeneration(uint32 time) { m_P_regenTimer = time; if (!m_interruptedRegenTime) m_interruptedRegenTime = 2000; }
	void DeMorph();
	uint32 ManaShieldAbsorb(uint32 dmg, SpellEntry* sp);
	void smsg_AttackStart(Unit* pVictim);
	void smsg_AttackStop(Unit* pVictim);
	void smsg_AttackStop(uint64 victimGuid);

	bool IsDazed();
	float CalculateDazeCastChance(Unit* target);

	// Stealth
	ARCTIC_INLINE int32 GetStealthLevel() { return (m_stealthLevel + (getLevel() * 5)); }
	ARCTIC_INLINE int32 GetStealthDetectBonus() { return m_stealthDetectBonus; }
	ARCTIC_INLINE void SetStealth(uint32 id) { m_stealth = id; }
	ARCTIC_INLINE bool InStealth() { return (m_stealth!=0 ? true : false); }
	float detectRange;

	// Invisibility
	ARCTIC_INLINE void SetInvisibility(uint32 id) { m_invisibility = id; }
	ARCTIC_INLINE bool IsInvisible() { return (m_invisible!=0 ? true : false); }
	uint32 m_invisibility;
	bool m_invisible;
	uint8 m_invisFlag;
	int32 m_invisDetect[INVIS_FLAG_TOTAL];

    /************************************************************************/
    /* Stun Immobilize                                                      */
    /************************************************************************/
	uint32 trigger_on_stun;				// second wind warrior talent
	uint32 trigger_on_stun_chance;

	void SetTriggerStunOrImmobilize(uint32 newtrigger,uint32 new_chance);
    void EventStunOrImmobilize();

    /************************************************************************/
    /* Chill                                                                */
    /************************************************************************/
	uint32 trigger_on_chill;			//mage "Frostbite" talent chill
	uint32 trigger_on_chill_chance;

	void SetTriggerChill(uint32 newtrigger, uint32 new_chance);
    void EventChill(Unit* proc_target);

	bool HasAura(uint32 spellid);
	bool HasAuraVisual(uint32 visualid);//not spell id!!!
	bool HasActiveAura(uint32 spelllid);
	bool HasActiveAura(uint32 spelllid,uint64);
	bool HasAuraWithMechanic(uint32 mechanic);
	bool HasPosAuraWithMechanic(uint32 mechanic);
	bool HasNegAuraWithMechanic(uint32 mechanic);

	void GiveGroupXP(Unit* pVictim, Player* PlayerInGroup);

	// Combat / Death Status
	ARCTIC_INLINE bool isAlive() { return m_deathState == ALIVE; };
	ARCTIC_INLINE bool isDead() { return  m_deathState != ALIVE; };
	virtual void setDeathState(DeathState s) { m_deathState = s; };
	DeathState getDeathState() { return m_deathState; }
	void OnDamageTaken();

	bool IsFFAPvPFlagged();
	void SetFFAPvPFlag();
	void RemoveFFAPvPFlag();

	// Add Aura to unit
	void AddAura(Aura* aur);

	// Remove aura from unit
	void RemoveAura(Aura* aur);
	void RemoveAuraBySlot(uint16 Slot);
	void RemoveAuraNoReturn(uint32 spellId);
	bool RemovePositiveAura(uint32 spellId);
	bool RemoveNegativeAura(uint32 spellId);
	bool RemoveAura(uint32 spellId,uint64 guid = 0);
	bool RemoveAuraByNameHash(uint32 namehash);//required to remove weaker instances of a spell
	bool RemoveAuraPosByNameHash(uint32 namehash);//required to remove weaker instances of a spell
	bool RemoveAuraNegByNameHash(uint32 namehash);//required to remove weaker instances of a spell
	bool RemoveAuras(uint32 * SpellIds);

	void EventRemoveAura(uint32 SpellId)
	{
		RemoveAura(SpellId);
	}

	// Remove all auras
	void RemoveAllAuras();
	bool RemoveAllAuras(uint32 spellId,uint64 guid = 0); //remove stacked auras but only if they come from the same caster. Shaman purge If GUID = 0 then removes all auras with this spellid
	void RemoveAllAurasOfType(uint32 auratype);//ex:to remove morph spells
	bool RemoveAllAuraByNameHash(uint32 namehash);//required to remove weaker instances of a spell
	bool RemoveAllPosAuraByNameHash(uint32 namehash);//required to remove weaker instances of a spell
	bool RemoveAllNegAuraByNameHash(uint32 namehash);//required to remove weaker instances of a spell
	bool RemoveAllAurasByMechanic( uint32 MechanicType , uint32 MaxDispel , bool HostileOnly ); // Removes all (de)buffs on unit of a specific mechanic type.

	void RemoveAllNegativeAuras();

	Aura* FindPositiveAuraByNameHash(uint32 namehash);
	Aura* FindNegativeAuraByNameHash(uint32 namehash);
	Aura* FindActiveAura(uint32 spellId, uint64 guid = 0);
	Aura* FindAura(uint32 spellId, uint64 guid = 0);
	Aura* FindActiveAuraWithNameHash(uint32 namehash, uint64 guid = 0);
	bool SetAuraDuration(uint32 spellId,Unit* caster,int32 duration);
	bool SetAuraDuration(uint32 spellId, int32 duration);
	void EventDeathAuraRemoval();

	void CastSpell(Spell* pSpell);
	void InterruptCurrentSpell();

	// caller is the caster
	int32 GetSpellBonusDamage(Unit* pVictim, SpellEntry *spellInfo,int32 base_dmg, bool isdot, bool healing);

	// guardians are temporary spawn that will inherit master faction and will folow them. Apart from that they have their own mind
	Unit* CreateTemporaryGuardian(uint32 guardian_entry,uint32 duration,float angle, uint32 lvl, uint8 Slot);

	uint32 m_addDmgOnce;
	Creature* m_SummonSlots[7];
	void SummonExpireSlot(uint8 slot); // Empties just slot x.
	void SummonExpireAll(bool clearowner); //Empties all slots (NPC's + GameObjects
	uint32 m_ObjectSlots[4];
	uint32 m_triggerSpell;
	uint32 m_triggerDamage;
	uint32 m_canMove;

	uint32 m_lastHauntInitialDamage;

	// Spell Effect Variables
	int32 m_silenced;
	bool m_damgeShieldsInUse;
	std::list<struct DamageProc> m_damageShields;
	std::list<struct ReflectSpellSchool*> m_reflectSpellSchool;

	std::list<struct ProcTriggerSpell> m_procSpells;
	bool m_chargeSpellsInUse;
	std::deque<Aura*> m_chargeSpellRemoveQueue;
	std::list<Aura*> m_chargeSpells;
	ARCTIC_INLINE void SetOnMeleeSpell(uint32 spell, uint8 cast_number ) { m_meleespell = spell; m_meleespell_cn = cast_number; }
	ARCTIC_INLINE uint32 GetOnMeleeSpell() { return m_meleespell; }

	// On Aura Remove Procs
	HM_NAMESPACE::hash_map<uint32, onAuraRemove* > m_onAuraRemoveSpells;

	void AddOnAuraRemoveSpell(uint32 NameHash, uint32 procSpell, uint32 procChance, bool procSelf);
	void RemoveOnAuraRemoveSpell(uint32 NameHash);
	void OnAuraRemove(uint32 NameHash, Unit* m_target);

	// Split Damage
	struct DamageSplitTarget m_damageSplitTarget;
	uint32 DoDamageSplitTarget(uint32 res, uint32 school_type, bool melee_dmg);

	// Spell Crit
	float spellcritperc;

	// dummy auras, spell stuff
	void AddDummyAura( SpellEntry* sp )
	{
		m_DummyAuras[sp->NameHash] = sp;
	}
	bool HasDummyAura( uint32 namehash )
	{
		return m_DummyAuras[namehash] != NULL;
	}
	SpellEntry* GetDummyAura( uint32 namehash )
	{
		return m_DummyAuras[namehash];
	}
	void RemoveDummyAura( uint32 namehash )//we removes only this shit, not aura
	{
		m_DummyAuras[namehash] = NULL;
	}

	// Custom timers
	uint32 m_CustomTimers[NUM_CUSTOM_TIMERS];

	// Beacon of Light
	Unit* BeaconCaster; // if we receive heal from him
	Unit* BeaconTarget; // heal him for this same value

	// AIInterface
	AIInterface *GetAIInterface() { return m_aiInterface; }

	void ReplaceAIInterface(AIInterface *new_interface) ;

	int32 GetThreatModifier() { return m_threatModifyer; }
	void ModThreatModifier(int32 mod) { m_threatModifyer += mod; }
	int32 GetGeneratedThreatModifier() { return m_generatedThreatModifyer; }
	void ModGeneratedThreatModifier(int32 mod) { m_generatedThreatModifyer += mod; }

	// DK:Affect
	ARCTIC_INLINE uint32 IsPacified() { return m_pacified; }
	ARCTIC_INLINE uint32 IsStunned() { return m_stunned; }
	ARCTIC_INLINE uint32 IsFeared() { return m_fearmodifiers; }
	ARCTIC_INLINE uint32 GetResistChanceMod() { return m_resistChance; }
	ARCTIC_INLINE void SetResistChanceMod(uint32 amount) { m_resistChance=amount; }

	ARCTIC_INLINE uint16 HasNoInterrupt() { return m_noInterrupt; }
	bool setDetectRangeMod(uint64 guid, int32 amount);
	void unsetDetectRangeMod(uint64 guid);
	int32 getDetectRangeMod(uint64 guid);
	uint32 Heal(Unit* target,uint32 SpellId, uint32 amount, bool silent = false);
	void Energize(Unit* target,uint32 SpellId, uint32 amount, uint32 type);

	uint32 SchoolCastPrevent[7];
	float MechanicDurationPctMod[NUM_MECHANIC];
	int32 GetDamageDoneMod(uint32 school);
	float GetDamageDonePctMod(uint32 school);
	int32 DamageTakenMod[7];
	float DamageTakenPctMod[7];
	// float DamageTakenPctModOnHP35; DEPRECATED, YAY!
	float CritMeleeDamageTakenPctMod[7];
	float CritRangedDamageTakenPctMod[7];
	int32 RangedDamageTaken;
	void CalcDamage();
	float BaseDamage[2];
	float BaseOffhandDamage[2];
	float BaseRangedDamage[2];
	SchoolAbsorb Absorbs[7];
	uint32 AbsorbDamage(Object* Attacker, uint32 School,uint32 * dmg, SpellEntry * pSpell);//returns amt of absorbed dmg, decreases dmg by absorbed value
	int32 RAPvModifier;
	int32 APvModifier;
	uint64 stalkedby;
	uint32 dispels[10];
	uint32 MechanicsDispels[NUM_MECHANIC];
	float MechanicsResistancesPCT[NUM_MECHANIC];
	float ModDamageTakenByMechPCT[NUM_MECHANIC];
	// int32 RangedDamageTakenPct;

	// SM
	int32 * SM[SPELL_MODIFIERS][2]; // 0 = flat, 1 = percent
	void InheritSMMods(Unit* inherit_from);
	// Multimap used to handle aura 271
	// key is caster GUID and value is a pair of SpellMask pointer and mod value
	typedef unordered_multimap<uint64, pair<uint32*, int32> > DamageTakenPctModPerCasterType;
	DamageTakenPctModPerCasterType DamageTakenPctModPerCaster;

	// Events
	void Emote (EmoteType emote);
	void EventAddEmote(EmoteType emote, uint32 time);
	void EventAllowCombat(bool allow);
	void EmoteExpire();
	ARCTIC_INLINE void setEmoteState(uint8 emote) { m_emoteState = emote; };
	ARCTIC_INLINE uint32 GetOldEmote() { return m_oldEmote; }
	void EventSummonPetExpire();
	void EventAurastateExpire(uint32 aurastateflag){RemoveFlag(UNIT_FIELD_AURASTATE,aurastateflag);}
	void EventHealthChangeSinceLastUpdate();

	void SetStandState (uint8 standstate);

	ARCTIC_INLINE StandState GetStandState()
	{
		uint32 bytes1 = GetUInt32Value (UNIT_FIELD_BYTES_1);
		return StandState (uint8 (bytes1));
	}

	ARCTIC_INLINE uint32 computeOverkill(uint32 damage)
	{
		uint32 curHealth = GetUInt32Value(UNIT_FIELD_HEALTH);
		return (damage > curHealth) ? damage - curHealth : 0;
	}

	void SendChatMessage(uint8 type, uint32 lang, const char *msg);
	void SendChatMessageToPlayer(uint8 type, uint32 lang, const char *msg, Player* plr);
	void SendChatMessageAlternateEntry(uint32 entry, uint8 type, uint32 lang, const char * msg);
	void RegisterPeriodicChatMessage(uint32 delay, uint32 msgid, std::string message, bool sendnotify);

	ARCTIC_INLINE int32 GetHealthPct() { return (int32)(GetUInt32Value(UNIT_FIELD_HEALTH) * 100 / std::max(1, (int32)GetUInt32Value(UNIT_FIELD_MAXHEALTH))); }
    ARCTIC_INLINE void SetHealthPct(uint32 val) { if (val>0) SetUInt32Value(UNIT_FIELD_HEALTH,float2int32(val*0.01f*GetUInt32Value(UNIT_FIELD_MAXHEALTH))); }
	ARCTIC_INLINE int32 GetManaPct() { return (int32)(GetUInt32Value(UNIT_FIELD_POWER1) * 100 / std::max(1, (int32)GetUInt32Value(UNIT_FIELD_MAXPOWER1))); }

	uint32 GetResistance(uint32 type);

	uint32 m_teleportAckCounter;

	/************************************************************************/
	/* Vehicle                                                              */
	/************************************************************************/

	uint8 m_inVehicleSeatId;
	Vehicle* m_CurrentVehicle;
	ARCTIC_INLINE int8 GetSeatID() { return m_inVehicleSeatId; }

	// Pet
	ARCTIC_INLINE void SetIsPet(bool chck) { m_isPet = chck; }

	// In-Range
	virtual void AddInRangeObject(Object* pObj);
	virtual void OnRemoveInRangeObject(Object* pObj);
	void ClearInRangeSet();

	ARCTIC_INLINE Spell* GetCurrentSpell(){return m_currentSpell;}
	ARCTIC_INLINE void SetCurrentSpell(Spell* cSpell) { m_currentSpell = cSpell; }

	uint32 m_CombatUpdateTimer;

	ARCTIC_INLINE void setcanperry(bool newstatus){can_parry=newstatus;}

	std::map<uint32,Aura* > tmpAura;

	uint32 BaseResistance[7]; //there are resistances for silence, fear, mechanics ....
	uint32 BaseStats[5];
	int32 HealDoneMod[7];
	float HealDonePctMod[7];
	int32 HealTakenMod[7];
	float HealTakenPctMod[7];
	uint32 SchoolImmunityList[7];
	float SpellCritChanceSchool[7];
	int32 PowerCostMod[7];
	float PowerCostPctMod[7]; // armor penetration & spell penetration
	int32 AttackerCritChanceMod[7];
	uint32 SpellDelayResist[7];
	int32 CreatureAttackPowerMod[12];
	int32 CreatureRangedAttackPowerMod[12];
	float AOEDmgMod;

	int32 PctRegenModifier;
	float m_toRegen;
	float PctPowerRegenModifier[4];
	ARCTIC_INLINE uint32 GetPowerType(){ return (GetByte(UNIT_FIELD_BYTES_0,3));}
	void RemoveSoloAura(uint32 type);

	void RemoveAurasByInterruptFlag(uint32 flag);
	void RemoveAurasByInterruptFlagButSkip(uint32 flag, uint32 skip);

	// Auras Modifiers
	int32 m_pacified;
	int32 m_interruptRegen;
	int32 m_resistChance;
	int32 m_powerRegenPCT;
	int32 m_stunned;
	int32 m_extraattacks[2];
	int32 m_extrastriketarget;
	int32 m_extrastriketargetc;
	std::list<ExtraStrike*> m_extraStrikeTargets;
	int32 m_fearmodifiers;

	int32 m_noInterrupt;
	int32 m_rooted;
	bool disarmed;
	bool disarmedShield;
	uint64 m_detectRangeGUID[5];
	int32  m_detectRangeMOD[5];

	// Affect Speed
	int32 m_speedModifier;
	int32 m_slowdown;
	float m_maxSpeed;
	map< uint32, int32 > speedReductionMap;
	bool GetSpeedDecrease();
	int32 m_mountedspeedModifier;
	int32 m_flyspeedModifier;
	void UpdateSpeed();
	void EnableFlight();
	void DisableFlight();

	void MoveToWaypoint(uint32 wp_id);
	void PlaySpellVisual(uint64 target, uint32 spellVisual);

	void RemoveStealth();
	void RemoveInvisibility();

	void ChangePetTalentPointModifier(bool Increment) { Increment ? m_PetTalentPointModifier++ : m_PetTalentPointModifier-- ; };
	bool m_isPet;
	uint32 m_stealth;
	bool m_can_stealth;

	Aura* m_auras[MAX_AURAS+MAX_PASSIVE_AURAS];

	int32 m_modlanguage;

	ARCTIC_INLINE uint32 GetCharmTempVal() { return m_charmtemp; }
	ARCTIC_INLINE void SetCharmTempVal(uint32 val) { m_charmtemp = val; }
	set<uint32> m_SpellList;

	ARCTIC_INLINE void DisableAI() { m_useAI = false; }
	ARCTIC_INLINE void EnableAI() { m_useAI = true; }

	void SetPowerType(uint8 type);

	ARCTIC_INLINE bool IsSpiritHealer()
	{
		if(GetUInt32Value(OBJECT_FIELD_ENTRY) == 6491 || GetUInt32Value(OBJECT_FIELD_ENTRY) == 13116 || GetUInt32Value(OBJECT_FIELD_ENTRY) == 13117)
			return true;

		return false;
	}

	ARCTIC_INLINE bool ClassMaskAffect(uint32 *classmask, SpellEntry* testSpell)
	{
		bool cl1 = false, cl2 = false, cl3 = false;

		if( testSpell->SpellGroupType[0] )
		{
			if( classmask[0] & testSpell->SpellGroupType[0] )
				cl1 = true;
		}
		else
			cl1 = true;

		if( testSpell->SpellGroupType[1] )
		{
			if( classmask[1] & testSpell->SpellGroupType[1] )
				cl2 = true;
		}
		else
			cl2 = true;

		if( testSpell->SpellGroupType[2] )
		{
			if( testSpell->SpellGroupType[0] == 0 && testSpell->SpellGroupType[1] == 0 )
			{
				if( classmask[2] & testSpell->SpellGroupType[2] )
					cl3 = true;
			}
			else
				cl3 = true;
		}
		else
			cl3 = true;

		return cl1 && cl2 && cl3;
	}

	void Root();
	void UnRoot();

	void SetFacing(float newo); // only working if creature is idle

	void RemoveAurasByBuffIndexType(uint32 buff_index_type, const uint64 &guid);
	void RemoveAurasByBuffType(uint32 buff_type, const uint64 &guid,uint32 skip);
	bool HasAurasOfBuffType(uint32 buff_type, const uint64 &guid,uint32 skip);
	int	 GetAuraSpellIDWithNameHash(uint32 name_hash);
	bool HasNegativeAuraWithNameHash(uint32 name_hash); //just to reduce search range in some cases
	bool HasNegativeAura(uint32 spell_id); //just to reduce search range in some cases
	bool IsPoisoned();
	uint32 GetPoisonDosesCount( uint32 poison_type );

	AuraCheckResponse AuraCheck(SpellEntry *info);

	uint16 m_diminishCount[DIMINISH_GROUPS];
	uint8  m_diminishAuraCount[DIMINISH_GROUPS];
	uint16 m_diminishTimer[DIMINISH_GROUPS];
	bool   m_diminishActive;

	void SetDiminishTimer(uint32 index);

	uint32 AddAuraVisual(uint32 SpellId, uint32 count, bool positive);

	bool HasVisibleAura(uint32 spellid);

	void RemoveAurasOfSchool(uint32 School, bool Positive, bool Immune);
	SpellEntry * pLastSpell;
	bool bProcInUse;
	bool bInvincible;
	Player* m_redirectSpellPackets;
	void UpdateVisibility();

	// Is PVP flagged?
	bool IsPvPFlagged();
	void SetPvPFlag();
	// Removal
	void RemovePvPFlag();

	struct
	{
		uint32 amt;
		uint32 max;
	} m_soulSiphon;

	// solo target auras
	uint32 m_hotStreakCount;
	uint32 m_incanterAbsorption;
	uint32 m_frozenTargetCharges;
	uint32 m_frozenTargetId;
	uint32 polySpell;
	uint32 m_special_state; // flags for special states (stunned,rooted etc)

	// uint32 fearSpell;
	CombatStatusHandler CombatStatus;
	bool m_temp_summon;

	// Redirect Threat shit
	Unit* mThreatRTarget;
	float mThreatRAmount;

	uint32 m_vampiricTouch;

	/************************************************************************/
	/* Unit properties                                                      */
	/************************************************************************/

	void SetCharmedUnitGUID(uint64 GUID) { SetUInt64Value(UNIT_FIELD_CHARM, GUID); }
	void SetSummonedUnitGUID(uint64 GUID) { SetUInt64Value(UNIT_FIELD_SUMMON, GUID); }
	void SetCharmedByGUID(uint64 GUID) { SetUInt64Value(UNIT_FIELD_CHARMEDBY, GUID); }
	void SetSummonedByGUID(uint64 GUID) { SetUInt64Value(UNIT_FIELD_SUMMONEDBY, GUID); }
	void SetCreatedByGUID(uint64 GUID) { SetUInt64Value(UNIT_FIELD_CREATEDBY, GUID); }
	void SetChannelSpellTargetGUID(uint64 GUID) { SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, GUID); }
	void SetTargetGUID(uint64 GUID) { SetUInt64Value(UNIT_FIELD_TARGET, GUID); }

	uint64 GetCharmedUnitGUID() { return GetUInt64Value(UNIT_FIELD_CHARM); }

	/************************************************************************/
	/* Unit properties end                                                  */
	/************************************************************************/

	void CancelSpell(Spell* ptr);
	void EventStrikeWithAbility(uint64 guid, SpellEntry * sp, uint32 damage);
	void DispelAll(bool positive);

	void SetPower(uint32 type, int32 value);

	bool HasAurasOfNameHashWithCaster(uint32 namehash, Unit* caster);
	bool mAngerManagement;
	bool mRecentlyBandaged;

	float m_ignoreArmorPctMaceSpec;
	float m_ignoreArmorPct;

	int32 m_LastSpellManaCost;

	void OnPositionChange();
	void Dismount();
	// custom functions for scripting
	void SetWeaponDisplayId(uint8 slot, uint32 displayId);

	// Transporters
	WoWGuid m_transportNewGuid;
	uint64 m_TransporterGUID;
	LocationVector* m_transportPosition;
	float m_TransporterUnk;
	bool m_lockTransportVariables;

	// Movement Info.
	MovementInfo* GetMovementInfo() { return &movement_info; }
	MovementInfo movement_info;

protected:
	Unit ();
	/* Preallocated buffers for movement handlers */
	uint8 movement_packet[90];

	uint32 m_meleespell;
	uint8 m_meleespell_cn;
	void _UpdateSpells(uint32 time);

	uint32 m_H_regenTimer;
	uint32 m_P_regenTimer;
	uint32 m_interruptedRegenTime; // PowerInterruptedegenTimer.
	uint32 m_state; // flags for keeping track of some states
	uint32 m_attackTimer; // timer for attack
	uint32 m_attackTimer_1;
	bool m_duelWield;

	// Combat
	DeathState m_deathState;

	// Stealth
	uint32 m_stealthLevel;
	uint32 m_stealthDetectBonus;

	// DK:pet
	// uint32 m_pet_state;
	// uint32 m_pet_action;
	uint8 m_PetTalentPointModifier;

	// Spell currently casting
	Spell* m_currentSpell;

	// AI
	AIInterface *m_aiInterface;

	bool m_useAI;
	bool m_spellsbusy;
	bool can_parry; // will be enabled by block spell
	int32 m_threatModifyer;
	int32 m_generatedThreatModifyer;

	//	float getDistance( float Position1X, float Position1Y, float Position2X, float Position2Y );

	int32 m_manashieldamt;
	SpellEntry * m_manaShieldSpell;

	// Quest emote
	uint8 m_emoteState;
	uint32 m_oldEmote;

	uint32 m_charmtemp;

	HM_NAMESPACE::hash_map<uint32, SpellEntry*> m_DummyAuras;
};

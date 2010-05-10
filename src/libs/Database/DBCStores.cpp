/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "DBCStores.h"
#include "DataStore.h"
#include "NGLog.h"

ARCTIC_DECL DBCStorage<AreaTriggerEntry> dbcAreaTrigger;
ARCTIC_DECL DBCStorage<AchievementEntry> dbcAchievement;
ARCTIC_DECL DBCStorage<AchievementCriteriaEntry> dbcAchievementCriteria;
ARCTIC_DECL DBCStorage<AreaGroup> dbcAreaGroup;
ARCTIC_DECL DBCStorage<CurrencyTypesEntry> dbcCurrencyTypesStore;
ARCTIC_DECL DBCStorage<GemPropertyEntry> dbcGemProperty;
ARCTIC_DECL DBCStorage<GlyphPropertyEntry> dbcGlyphProperty;
ARCTIC_DECL DBCStorage<ItemLimitCategoryEntry> dbcItemLimitCategory;
ARCTIC_DECL DBCStorage<ItemSetEntry> dbcItemSet;
ARCTIC_DECL DBCStorage<Lock> dbcLock;
ARCTIC_DECL DBCStorage<SpellEntry> dbcSpell;
ARCTIC_DECL DBCStorage<SpellDuration> dbcSpellDuration;
ARCTIC_DECL DBCStorage<SpellRange> dbcSpellRange;
ARCTIC_DECL DBCStorage<SpellRuneCostEntry> dbcSpellRuneCost;
ARCTIC_DECL DBCStorage<emoteentry> dbcEmoteEntry;
ARCTIC_DECL DBCStorage<SpellRadius> dbcSpellRadius;
ARCTIC_DECL DBCStorage<SpellCastTime> dbcSpellCastTime;
ARCTIC_DECL DBCStorage<AreaTable> dbcArea;
ARCTIC_DECL DBCStorage<FactionTemplateDBC> dbcFactionTemplate;
ARCTIC_DECL DBCStorage<FactionDBC> dbcFaction;
ARCTIC_DECL DBCStorage<EnchantEntry> dbcEnchant;
ARCTIC_DECL DBCStorage<RandomProps> dbcRandomProps;
ARCTIC_DECL DBCStorage<skilllinespell> dbcSkillLineSpell;
ARCTIC_DECL DBCStorage<skilllineentry> dbcSkillLine;
ARCTIC_DECL DBCStorage<DBCTaxiNode> dbcTaxiNode;
ARCTIC_DECL DBCStorage<DBCTaxiPath> dbcTaxiPath;
ARCTIC_DECL DBCStorage<DBCTaxiPathNode> dbcTaxiPathNode;
ARCTIC_DECL DBCStorage<AuctionHouseDBC> dbcAuctionHouse;
ARCTIC_DECL DBCStorage<TalentEntry> dbcTalent;
ARCTIC_DECL DBCStorage<TalentTabEntry> dbcTalentTab;
ARCTIC_DECL DBCStorage<CreatureDisplayInfo> dbcCreatureDisplayInfo;
ARCTIC_DECL DBCStorage<CreatureSpellDataEntry> dbcCreatureSpellData;
ARCTIC_DECL DBCStorage<CreatureFamilyEntry> dbcCreatureFamily;
ARCTIC_DECL DBCStorage<CharClassEntry> dbcCharClass;
ARCTIC_DECL DBCStorage<CharRaceEntry> dbcCharRace;
ARCTIC_DECL DBCStorage<MapEntry> dbcMap;
ARCTIC_DECL DBCStorage<ItemExtendedCostEntry> dbcItemExtendedCost;
ARCTIC_DECL DBCStorage<ItemRandomSuffixEntry> dbcItemRandomSuffix;
ARCTIC_DECL DBCStorage<CombatRatingDBC> dbcCombatRating;
ARCTIC_DECL DBCStorage<ChatChannelDBC> dbcChatChannels;
ARCTIC_DECL DBCStorage<DurabilityQualityEntry> dbcDurabilityQuality;
ARCTIC_DECL DBCStorage<DurabilityCostsEntry> dbcDurabilityCosts;
ARCTIC_DECL DBCStorage<BankSlotPrice> dbcBankSlotPrices;
ARCTIC_DECL DBCStorage<BankSlotPrice> dbcStableSlotPrices;
ARCTIC_DECL DBCStorage<BarberShopStyleEntry> dbcBarberShopStyle;
ARCTIC_DECL DBCStorage<gtFloat> dbcBarberShopPrices;
ARCTIC_DECL DBCStorage<gtFloat> dbcMeleeCrit;
ARCTIC_DECL DBCStorage<gtFloat> dbcMeleeCritBase;
ARCTIC_DECL DBCStorage<gtFloat> dbcSpellCrit;
ARCTIC_DECL DBCStorage<gtFloat> dbcSpellCritBase;
ARCTIC_DECL DBCStorage<gtFloat> dbcManaRegen;
ARCTIC_DECL DBCStorage<gtFloat> dbcManaRegenBase;
ARCTIC_DECL DBCStorage<gtFloat> dbcHPRegen;
ARCTIC_DECL DBCStorage<gtFloat> dbcHPRegenBase;
ARCTIC_DECL DBCStorage<SpellShapeshiftForm> dbcSpellShapeshiftForm;
ARCTIC_DECL DBCStorage<VehicleEntry> dbcVehicle;
ARCTIC_DECL DBCStorage<VehicleSeatEntry> dbcVehicleSeat;
ARCTIC_DECL DBCStorage<WorldMapOverlayEntry> dbcWorldMapOverlay;
ARCTIC_DECL DBCStorage<SummonPropertiesEntry> dbcSummonProps;
ARCTIC_DECL DBCStorage<AreaPOIEntry> dbcAreaPOI;

const char* SummonPropertiesfmt = "uuuuuu";
const char* AreaTriggerFormat = "uuffffffff";
const char* AreaGroupFormat = "niiiiiii";
const char* CurrencyTypesEntryFormat = "xnxu";
const char* ItemSetFormat = "uxxxxxxxxxxxxxxxxxuuuuuuuuuuxxxxxxxuuuuuuuuuuuuuuuuuu";
const char* LockFormat = "uuuuuuxxxuuuuuxxxuuuuuxxxxxxxxxxx";
const char* EmoteEntryFormat = "uxuxxxxxxxxxxxxxxxx";
const char* skilllinespellFormat = "uuuuuxxuuuuuxx";
const char* EnchantEntrYFormat = "uxuuuuuuuuuuuusxxxxxxxxxxxxxxxxuuuuxxx";
const char* GemPropertyEntryFormat = "uuuuu";
const char* GlyphPropertyEntryFormat = "uuuu";
const char* skilllineentrYFormat = "uuusxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char* spellentryFormat =
	"u"						// Id
	"u"						// Category
	"u"						// DispelType
	"u"						// MechanicsType
	"uuuuuuuu"				// 8x Flags
	"u"						// RequiredShapeShift
	"x"						// unk00
	"u"						// NotAllowedShapeShift
	"x"						// unk01
	"u"						// Targets
	"u"						// TargetCreatureType
	"u"						// RequiresSpellFocus
	"u"						// FacingCasterFlags
	"uuuuuuuu"				// 8x Aura crap
	"u"						// CastingTimeIndex
	"u"						// RecoveryTime
	"u"						// CategoryRecoveryTime
	"u"						// InterruptFlags
	"u"						// AuraInterruptFlags
	"u"						// ChannelInterruptFlags
	"u"						// procFlags
	"u"						// procChance
	"u"						// procCharges
	"u"						// maxLevel
	"u"						// baseLevel
	"u"						// spellLevel
	"u"						// DurationIndex
	"u"						// powerType
	"u"						// manaCost
	"u"						// manaCostPerlevel
	"u"						// manaPerSecond
	"u"						// manaPerSecondPerLevel
	"u"						// rangeIndex
	"f"						// Speed
	"u"						// modalNextSpell
	"u"						// maxstack
	"uu"					// Totem
	"uuuuuuuu"				// 8x Reagent
	"uuuuuuuu"				// 8x ReagentCount
	"i"						// EquippedItemClass
	"u"						// EquippedItemSubClass
	"u"						// RequiredItemFlags
	"uuu"					// 3x Spell Effect
	"uuu"					// 3x Spell Effect Die Sides
	"fff"					// 3x Spell Effect Real Points per Level
	"iii"					// 3x Spell Effect Base Points
	"iii"					// 3x Spell Effect Mechanic
	"uuu"					// 3x Spell Effect Target A
	"uuu"					// 3x Spell Effect Target B
	"uuu"					// 3x Spell Effect Radius index
	"uuu"					// 3x Spell Effect Apply Aura Name
	"uuu"					// 3x Spell Effect Amplitude
	"fff"					// 3x Spell Effect Multiple Value
	"uuu"					// 3x Spell Effect Chain Target
	"uuu"					// 3x Spell Effect Item Type
	"uuu"					// 3x Spell Effect Misc Value
	"uuu"					// 3x Spell Effect Misc Value B
	"uuu"					// 3x Spell Effect Trigger Spell
	"fff"					// 3x Spell Effect Points per Combo Point
	"uuuuuuuuu"				// 3x Spell Effect Class Mask[3]
	"uu"					// 2x SpellVisual
	"u"						// SpellIconID
	"u"						// activeIconID
	"u"						// spellPriority
	"sxxxxxxxxxxxxxxxx"		// Name
	"sxxxxxxxxxxxxxxxx"		// Rank
	"sxxxxxxxxxxxxxxxx"		// Spell Description
	"sxxxxxxxxxxxxxxxx"		// Buff Description
	"u"						// ManaCostPercentage
	"u"						// StartRecoveryCategory
	"u"						// StartRecoveryTime
	"u"						// MaxTargetLevel
	"u"						// SpellFamilyName
	"uuu"					// 3x SpellGroupType
	"u"						// MaxTargets
	"u"						// Spell_Dmg_Type
	"u"						// PreventionType
	"i"						// StanceBarOrder
	"fff"					// 3x dmg_multiplier
	"u"						// MinFactionID
	"u"						// MinReputation
	"u"						// RequiredAuraVision
	"uu"					// 2x TotemCategory
	"i"						// AreaGroupId
	"u"						// School
	"ux"					// runeCostID and spellMissileID
	"u"						// PowerDisplayId
	"xxxxx";				// Unk

const char* itemextendedcostFormat = "uuuuuuuuuuuuuuux";
const char* talententryFormat = "uuuuuuuuuxxxxuxxuxxxuxx";
const char* talenttabentryFormat = "uxxxxxxxxxxxxxxxxxxxuxux";
const char* spellcasttimeFormat = "uuxx";
const char* spellradiusFormat = "ufxf";
const char* spellrangeFormat =
	"u"						// Id
	"f"						// MinRange
	"x"
	"f"						// MaxRange
	"x"
	"u"
	"sxxxxxxxxxxxxxxxx"
	"sxxxxxxxxxxxxxxxx";

const char* WorldMapOverlayfmt = "uxuxxxxxxxxxxxxxx";
const char* SpellRuneCostfmt = "uuuuu";
const char* spelldurationFormat = "uuuu";
const char* randompropsFormat = "usuuuxxxxxxxxxxxxxxxxxxx";
const char* areatableFormat = "uuuuuxxxuxusxxxxxxxxxxxxxxxxuxxxxxxx";
const char* factiontemplatedbcFormat = "uuuuuuuuuuuuuu";
const char* auctionhousedbcFormat = "uuuuxxxxxxxxxxxxxxxxx";
const char* factiondbcFormat = "uiuuuuxxxxiiiixxxxxxxxusxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char* dbctaxinodeFormat = "uufffxxxxxxxxxxxxxxxxxuu";
const char* dbctaxipathFormat = "uuuu";
const char* dbctaxipathnodeFormat = "uuuufffuuxx";
const char* creaturedisplayFormat = "uxxxfxxxxxxxxxxx";
const char* creaturespelldataFormat = "uuuuuuuuu";
const char* charraceFormat = "uxxxxxxuxxxxuxsxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char* charclassFormat = "uxuxsxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxuxux";
const char* creaturefamilyFormat = "ufufuuuuuxsxxxxxxxxxxxxxxxxx";
const char* mapentryFormat =
	"u"						// 0 id
	"x"						// 1 name_internal
	"u"						// 2 map_type
	"x"						// 3 is_pvp_zone
	"x"						// 4 0 or 1 for battlegrounds (not arenas)
	"xxxxxxxxxxxxxxxxx"		// 5-21 real_name
	"x"						// 22 linked_zone
	"xxxxxxxxxxxxxxxxx"		// 23-39 hordeIntro
	"xxxxxxxxxxxxxxxxx"		// 40-56 allianceIntro
	"u"						// 57 multimap_id
	"x"						// 58 unk_float (all 1 but arathi 1.25)
	"x"						// 59 parent_map
	"x"						// 60 start_x
	"x"						// 61 start_y
	"x"						// 62 unk
	"x"						// 63 addon
	"x"						// 64 normalReqText
	"x";					// 65 Max players

const char* itemrandomsuffixformat = "usxxxxxxxxxxxxxxxxxuuuuuuuuuu";
const char* chatchannelformat = "uuxsxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char* durabilityqualityFormat = "uf";
const char* durabilitycostsFormat = "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuu";
const char* bankslotpriceformat = "uu";
const char* barbershopstyleFormat="nusxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxuuu";
const char* gtfloatformat = "f";
const char* spellshapeshiftformformat = "uxxxxxxxxxxxxxxxxxxxxxxxxxxxuuuuuuu";

const char* vehicleseatentryFormat = "uuxfffxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxuuxxxxxxxxxxxx";
const char* vehicleentryFormat = "uxxxxxuuuuuuuuxxxxxxxxxxxxxxxxxxxxxxxxxx";

const char* achievementfmt=
	"n"						// Index
	"i"						// Faction
	"i"						// Mapid
	"u"						// Previous Achievement
	"s"						// Name
	"xxxxxxxxxxxxxxxx"
	"s"						// Description
	"xxxxxxxxxxxxxxxx"
	"i"						// Category Id
	"x"						// points
	"x"						// Order In Category
	"i"						// Flags
	"xxxxxxxxxxxxxxxxxxxx";

const char* achievementCriteriafmt = "niiiiiiiisxxxxxxxxxxxxxxxxiixix";


const char* AreaPOIFormat = "nuuuuuuuuuuufffuxuxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxux";
const char* itemlimitcategoryformat = "usxxxxxxxxxxxxxxxxuu";
template<class T>
bool loader_stub(const char * filename, const char * format, bool ind, T& l, bool loadstrs)
{
	Log.Notice("WoWArcTic DBC", "Loading %s.", filename);
	return l.Load(filename, format, ind, loadstrs);
}

#define LOAD_DBC(filename, format, ind, stor, strings) if(!loader_stub(filename, format, ind, stor, strings)) { return false; } 

bool LoadDBCs()
{
	/* Needed for: Used in loading of achievements and finding saving information and grabbing criteria
	info to see if player deserves achievement. */
	LOAD_DBC("DBC/Achievement.dbc", achievementfmt,true, dbcAchievement,true);
	LOAD_DBC("DBC/Achievement_Criteria.dbc", achievementCriteriafmt,true,dbcAchievementCriteria,true);
	LOAD_DBC("DBC/AreaGroup.dbc", AreaGroupFormat, true, dbcAreaGroup, true);
	LOAD_DBC("DBC/AreaTable.dbc", areatableFormat, true, dbcArea, true);
	LOAD_DBC("DBC/AreaTrigger.dbc", AreaTriggerFormat, true, dbcAreaTrigger, false);
	LOAD_DBC("DBC/AreaPOI.dbc",AreaPOIFormat,true,dbcAreaPOI,false);
	LOAD_DBC("DBC/AuctionHouse.dbc", auctionhousedbcFormat, true, dbcAuctionHouse, false);
	LOAD_DBC("DBC/BankBagSlotPrices.dbc", bankslotpriceformat, true, dbcBankSlotPrices, false);
	LOAD_DBC("DBC/BarberShopStyle.dbc", barbershopstyleFormat, true, dbcBarberShopStyle, true);
	LOAD_DBC("DBC/ChatChannels.dbc", chatchannelformat, true, dbcChatChannels, true);
	LOAD_DBC("DBC/CurrencyTypes.dbc", CurrencyTypesEntryFormat, true, dbcCurrencyTypesStore, true);
	LOAD_DBC("DBC/ChrClasses.dbc", charclassFormat, true, dbcCharClass, true);
	LOAD_DBC("DBC/ChrRaces.dbc", charraceFormat, true, dbcCharRace, true);
	LOAD_DBC("DBC/CreatureDisplayInfo.dbc", creaturedisplayFormat, true, dbcCreatureDisplayInfo, true);
	LOAD_DBC("DBC/CreatureFamily.dbc", creaturefamilyFormat, true, dbcCreatureFamily, true);
	LOAD_DBC("DBC/CreatureSpellData.dbc", creaturespelldataFormat, true, dbcCreatureSpellData, false);
	LOAD_DBC("DBC/DurabilityQuality.dbc", durabilityqualityFormat, true, dbcDurabilityQuality, false);
	LOAD_DBC("DBC/DurabilityCosts.dbc", durabilitycostsFormat, true, dbcDurabilityCosts, false);
	LOAD_DBC("DBC/EmotesText.dbc", EmoteEntryFormat, true, dbcEmoteEntry, false);
	LOAD_DBC("DBC/Faction.dbc", factiondbcFormat, true, dbcFaction, true);
	LOAD_DBC("DBC/FactionTemplate.dbc", factiontemplatedbcFormat, true, dbcFactionTemplate, false);
	LOAD_DBC("DBC/GemProperties.dbc", GemPropertyEntryFormat, true, dbcGemProperty, false);
	LOAD_DBC("DBC/GlyphProperties.dbc", GlyphPropertyEntryFormat, true, dbcGlyphProperty, false);
	LOAD_DBC("DBC/gtBarberShopCostBase.dbc", gtfloatformat, false, dbcBarberShopPrices, false);
	LOAD_DBC("DBC/gtChanceToMeleeCrit.dbc", gtfloatformat, false, dbcMeleeCrit, false);
	LOAD_DBC("DBC/gtChanceToMeleeCritBase.dbc", gtfloatformat, false, dbcMeleeCritBase, false);
	LOAD_DBC("DBC/gtChanceToSpellCrit.dbc", gtfloatformat, false, dbcSpellCrit, false);
	LOAD_DBC("DBC/gtChanceToSpellCritBase.dbc", gtfloatformat, false, dbcSpellCritBase, false);
	LOAD_DBC("DBC/gtCombatRatings.dbc", gtfloatformat, false, dbcCombatRating, false);
	LOAD_DBC("DBC/gtOCTRegenHP.dbc", gtfloatformat, false, dbcHPRegen, false);
	LOAD_DBC("DBC/gtOCTRegenMP.dbc", gtfloatformat, false, dbcManaRegen, false);
	LOAD_DBC("DBC/gtRegenHPPerSpt.dbc", gtfloatformat, false, dbcHPRegenBase, false);
	LOAD_DBC("DBC/gtRegenMPPerSpt.dbc", gtfloatformat, false, dbcManaRegenBase, false);
	LOAD_DBC("DBC/ItemExtendedCost.dbc", itemextendedcostFormat, true, dbcItemExtendedCost, false);
	LOAD_DBC("DBC/ItemSet.dbc", ItemSetFormat, true, dbcItemSet, true);
	LOAD_DBC("DBC/ItemRandomProperties.dbc", randompropsFormat, true, dbcRandomProps, false);
	LOAD_DBC("DBC/ItemRandomSuffix.dbc", itemrandomsuffixformat, true, dbcItemRandomSuffix, false);
	LOAD_DBC("DBC/ItemLimitCategory.dbc", itemlimitcategoryformat, true, dbcItemLimitCategory, true);

	LOAD_DBC("DBC/Lock.dbc", LockFormat, true, dbcLock, false);
	LOAD_DBC("DBC/Map.dbc", mapentryFormat, true, dbcMap, true);
	LOAD_DBC("DBC/StableSlotPrices.dbc", bankslotpriceformat, true, dbcStableSlotPrices, false);
	LOAD_DBC("DBC/SkillLine.dbc", skilllineentrYFormat, true, dbcSkillLine, true);
	LOAD_DBC("DBC/SkillLineAbility.dbc", skilllinespellFormat, false, dbcSkillLineSpell, false);
	LOAD_DBC("DBC/Spell.dbc", spellentryFormat, true, dbcSpell, true);
	LOAD_DBC("DBC/SpellCastTimes.dbc", spellcasttimeFormat, true, dbcSpellCastTime, false);
	LOAD_DBC("DBC/SpellDuration.dbc", spelldurationFormat, true, dbcSpellDuration, false);
	LOAD_DBC("DBC/SpellItemEnchantment.dbc", EnchantEntrYFormat, true, dbcEnchant, true);
	LOAD_DBC("DBC/SpellRadius.dbc", spellradiusFormat, true, dbcSpellRadius, false);
	LOAD_DBC("DBC/SpellRange.dbc", spellrangeFormat, true, dbcSpellRange, false);
	/* Needed for: Spell costs and calculations for dummy scripts or scripted spells for DK's. */
	LOAD_DBC("DBC/SpellRuneCost.dbc", SpellRuneCostfmt, true, dbcSpellRuneCost, false);
	LOAD_DBC("DBC/SpellShapeshiftForm.dbc", spellshapeshiftformformat, true, dbcSpellShapeshiftForm, false);
	LOAD_DBC("DBC/SummonProperties.dbc", SummonPropertiesfmt, true, dbcSummonProps, false);
	LOAD_DBC("DBC/Talent.dbc", talententryFormat, true, dbcTalent, false);
	LOAD_DBC("DBC/TalentTab.dbc", talenttabentryFormat, true, dbcTalentTab, false);
	LOAD_DBC("DBC/TaxiNodes.dbc", dbctaxinodeFormat, false, dbcTaxiNode, false);
	LOAD_DBC("DBC/TaxiPath.dbc", dbctaxipathFormat, false, dbcTaxiPath, false);
	LOAD_DBC("DBC/TaxiPathNode.dbc", dbctaxipathnodeFormat, false, dbcTaxiPathNode, false);
	LOAD_DBC("DBC/Vehicle.dbc", vehicleentryFormat, true, dbcVehicle, true);
	LOAD_DBC("DBC/VehicleSeat.dbc", vehicleseatentryFormat, true, dbcVehicleSeat, true);
	LOAD_DBC("DBC/WorldMapOverlay.dbc", WorldMapOverlayfmt, true, dbcWorldMapOverlay, true);

	return true;
}

void FreeDBCs()
{
    dbcAreaPOI.Cleanup();
    dbcAreaTrigger.Cleanup();
    dbcGemProperty.Cleanup();
    dbcGlyphProperty.Cleanup();
    dbcItemSet.Cleanup();
    dbcLock.Cleanup();
    dbcSpell.Cleanup();
    dbcSpellDuration.Cleanup();
    dbcSpellRange.Cleanup();
    dbcSpellRuneCost.Cleanup();
    dbcEmoteEntry.Cleanup();
    dbcSpellRadius.Cleanup();
    dbcSpellCastTime.Cleanup();
    dbcArea.Cleanup();
    dbcFactionTemplate.Cleanup();
    dbcFaction.Cleanup();
    dbcEnchant.Cleanup();
    dbcRandomProps.Cleanup();
    dbcSkillLineSpell.Cleanup();
    dbcSkillLine.Cleanup();
    dbcTaxiNode.Cleanup();
    dbcTaxiPath.Cleanup();
    dbcTaxiPathNode.Cleanup();
    dbcAuctionHouse.Cleanup();
    dbcTalent.Cleanup();
    dbcTalentTab.Cleanup();
    dbcCreatureSpellData.Cleanup();
    dbcCreatureFamily.Cleanup();
    dbcCharClass.Cleanup();
    dbcCharRace.Cleanup();
    dbcMap.Cleanup();
    dbcItemExtendedCost.Cleanup();
    dbcItemRandomSuffix.Cleanup();
    dbcItemLimitCategory.Cleanup();
    dbcCombatRating.Cleanup();
    dbcChatChannels.Cleanup();
    dbcDurabilityQuality.Cleanup();
    dbcDurabilityCosts.Cleanup();
    dbcBankSlotPrices.Cleanup();
    dbcStableSlotPrices.Cleanup();
    dbcBarberShopStyle.Cleanup();
    dbcBarberShopPrices.Cleanup();
    dbcMeleeCrit.Cleanup();
    dbcMeleeCritBase.Cleanup();
    dbcSpellCrit.Cleanup();
    dbcSpellCritBase.Cleanup();
    dbcManaRegen.Cleanup();
    dbcManaRegenBase.Cleanup();
    dbcHPRegen.Cleanup();
    dbcHPRegenBase.Cleanup();
    dbcSpellShapeshiftForm.Cleanup();
    dbcAchievement.Cleanup();
    dbcAchievementCriteria.Cleanup();
    dbcVehicle.Cleanup();
    dbcVehicleSeat.Cleanup();
    dbcWorldMapOverlay.Cleanup();
    dbcSummonProps.Cleanup();
    dbcCreatureDisplayInfo.Cleanup();
}

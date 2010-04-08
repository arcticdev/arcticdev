/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "DBCStores.h"
#include "DataStore.h"
#include "NGLog.h"

ARCTIC_DECL DBCStorage<AreaTriggerEntry> dbcAreaTrigger;
ARCTIC_DECL DBCStorage<AreaGroup> dbcAreaGroup;
ARCTIC_DECL DBCStorage<CharTitlesEntry> dbcCharTitlesEntry;
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
ARCTIC_DECL DBCStorage<AchievementEntry> dbcAchievement;
ARCTIC_DECL DBCStorage<AchievementCriteriaEntry> dbcAchivementCriteria;
ARCTIC_DECL DBCStorage<VehicleEntry> dbcVehicle;
ARCTIC_DECL DBCStorage<VehicleSeatEntry> dbcVehicleSeat;
ARCTIC_DECL DBCStorage<WorldMapOverlayEntry> dbcWorldMapOverlay;
ARCTIC_DECL DBCStorage<SummonPropertiesEntry> dbcSummonProps;
ARCTIC_DECL DBCStorage<AreaPOIEntry> dbcAreaPOI;

const char * SummonPropertiesfmt = "uuuuuu";
const char * AreaTriggerFormat = "uuffffffff";
const char * AreaGroupFormat = "niiiiiii";
const char * CharTitlesEntryfmt = "usxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxu";
const char * ItemSetFormat = "usxxxxxxxxxxxxxxxuuuuuuuuuuuxxxxxxxuuuuuuuuuuuuuuuuuu";
const char * LockFormat = "uuuuuuxxxuuuuuxxxuuuuuxxxxxxxxxxx";
const char * EmoteEntryFormat = "uxuuuuxuxuxxxxxxxxx";
const char * skilllinespellFormat = "uuuuuxxuuuuuxx";
const char * EnchantEntrYFormat = "uxuuuuuuuuuuuusxxxxxxxxxxxxxxxxuuuuxxx";
const char * GemPropertyEntryFormat = "uuuuu";
const char * GlyphPropertyEntryFormat = "uuuu";
const char * skilllineentrYFormat = "uuusxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char * spellentryFormat = "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuufuuuuuuuuuuuuuuuuuuuuiuuuuuuuuuuuffffffiiiiiiuuuuuuuuuuuuuuufffuuuuuuuuuuuuuuufffuuuuuuuuuuxuuusxxxxxxxxxxxxxxxxsxxxxxxxxxxxxxxxxsxxxxxxxxxxxxxxxxsxxxxxxxxxxxxxxxxuuuuuuuuuuuifffuuuuuiuuxuuuuu";

const char * itemextendedcostFormat = "uuuuuuuuuuuuuuux";
const char * talententryFormat = "uuuuuuuuuxxxxuxxuxxxuxx";
const char * talenttabentryFormat = "uxxxxxxxxxxxxxxxxxxxuxux";
const char * spellcasttimeFormat = "uuxx";
const char * spellradiusFormat = "ufxf";
const char * spellrangeFormat = "u"/*Id*/"f"/*MinRange*/"x""f"/*MaxRange*/"x""u""sxxxxxxxxxxxxxxxx""sxxxxxxxxxxxxxxxx";

const char * WorldMapOverlayfmt = "uxuxxxxxxxxxxxxxx";
const char * SpellRuneCostfmt = "uuuuu";
const char * spelldurationFormat = "uuuu";
const char * randompropsFormat = "usuuuxxxxxxxxxxxxxxxxxxx";
const char * areatableFormat = "uuuuuxxxuxusxxxxxxxxxxxxxxxxuxxxxxxx";
const char * factiontemplatedbcFormat = "uuuuuuuuuuuuuu";
const char * auctionhousedbcFormat = "uuuuxxxxxxxxxxxxxxxxx";
const char * factiondbcFormat = "uiuuuuxxxxiiiixxxxusxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char * dbctaxinodeFormat = "uufffxxxxxxxxxxxxxxxxxuu";
const char * dbctaxipathFormat = "uuuu";
const char * dbctaxipathnodeFormat = "uuuufffuuxx";
const char * creaturedisplayFormat = "uxxxfxxxxxxxxxxx";
const char * creaturespelldataFormat = "uuuuuuuuu";
const char * charraceFormat = "uxuxuuxuxxxxxusxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxu"; // const char * charraceFormat = "uxxxxxxuxxxxuxlxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
const char * charclassFormat = "uxuxsxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxuxux";
const char * creaturefamilyFormat = "ufufuuuuuxsxxxxxxxxxxxxxxxxx";
const char * mapentryFormat =
	"u"                  // 0 id
	"s"                  // 1 name_internal
	"u"                  // 2 map_type
	"u"                  // 3 is_pvp_zone
	"sxxxxxxxxxxxxxxxx"  // 4-20 real_name
	"u"                  // 21 linked_zone
	"sxxxxxxxxxxxxxxxx"  // 22-38 hordeIntro
	"sxxxxxxxxxxxxxxxx"  // 39-55 allianceIntro
	"u"                  // 56 multimap_id
	"x"                  // 57 unk_float (all 1 but arathi 1.25)
	"s"                  // 58 normalReqText
	"u"                  // 59 parent_map
	"u"                  // 60 start_x
	"u"                  // 61 start_y
	"u"                  // 62 addon
	"x"                  // 63 unk
	"x";                 // 64 unk

const char * itemrandomsuffixformat = "usxxxxxxxxxxxxxxxxxuuuuuuuuuu";
const char * chatchannelformat = "uuxsxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

const char * durabilityqualityFormat = "uf";
const char * durabilitycostsFormat = "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuu";

const char * bankslotpriceformat = "uu";
const char * barbershopstyleFormat = "nusxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxuuu";

const char * gtfloatformat = "f";
const char * spellshapeshiftformformat = "uxxxxxxxxxxxxxxxxxxxxxxxxxxxuuuuuuu";

const char * vehicleseatentryFormat = "uuuffffffffffuuuuuufffffffuuufffuuuuuuuffuuuuuxxxxxxxxxxxx";
const char * vehicleentryFormat = "uuffffuuuuuuuufffffffffffffffssssfufuxxx";

const char * achievementfmt="niixsxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxiixixxxxxxxxxxxxxxxxxxxx";
const char * achievementCriteriafmt="niiiiiiiisxxxxxxxxxxxxxxxxiixix";

const char * AreaPOIFormat = "nuuuuuuuuuuufffuxuxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxux";
const char * itemlimitcategoryformat = "usxxxxxxxxxxxxxxxxuu";

template<class T>
bool loader_stub(const char * filename, const char * format, bool ind, T& l, bool loadstrs)
{
	Log.Notice("WoWArcTic DBC", "Loading %s.", filename);
	return l.Load(filename, format, ind, loadstrs);
}

#define LOAD_DBC(filename, format, ind, stor, strings) if(!loader_stub(filename, format, ind, stor, strings)) { return false; } 

bool LoadDBCs()
{
	LOAD_DBC("DBC/Achievement.dbc", achievementfmt,true, dbcAchievement,true);
	LOAD_DBC("DBC/Achievement_Criteria.dbc", achievementCriteriafmt,true,dbcAchivementCriteria,true);
	LOAD_DBC("DBC/AreaGroup.dbc", AreaGroupFormat, true, dbcAreaGroup, true);
	LOAD_DBC("DBC/AreaTable.dbc", areatableFormat, true, dbcArea, true);
	LOAD_DBC("DBC/AreaTrigger.dbc", AreaTriggerFormat, true, dbcAreaTrigger, false);
	LOAD_DBC("DBC/AreaPOI.dbc",AreaPOIFormat,true,dbcAreaPOI,false);
	LOAD_DBC("DBC/AuctionHouse.dbc", auctionhousedbcFormat, true, dbcAuctionHouse, false);

	LOAD_DBC("DBC/BankBagSlotPrices.dbc", bankslotpriceformat, true, dbcBankSlotPrices, false);
	LOAD_DBC("DBC/BarberShopStyle.dbc", barbershopstyleFormat, true, dbcBarberShopStyle, true);

	LOAD_DBC("DBC/ChatChannels.dbc", chatchannelformat, true, dbcChatChannels, true);
	LOAD_DBC("DBC/CharTitles.dbc", CharTitlesEntryfmt, true, dbcCharTitlesEntry, false);
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
    dbcCharTitlesEntry.Cleanup();
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
    dbcAchivementCriteria.Cleanup();
    dbcVehicle.Cleanup();
    dbcVehicleSeat.Cleanup();
    dbcWorldMapOverlay.Cleanup();
    dbcSummonProps.Cleanup();
    dbcCreatureDisplayInfo.Cleanup();
}

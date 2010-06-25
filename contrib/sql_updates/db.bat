@ECHO off
COLOR 8
:TOP
cls
echo.
echo          ษออออออออออออออออออออออออออออออออออออออออออออออป
echo          บ       WoWArcTic DB Installer                 บ
echo          ศออออออออออออออออออออออออออออออออออออออออออออออป
echo.
set /p server=    MySQL Host : 
set /p port=      MySQL Port : 
set /p user=      MySQL Username : 
set /p pass=      MySQL Password : 
set /p wdb=       World Database : 
set /p cdb=       Character Database : 
set /p ldb=       Logon Database : 
if %user% == CHANGEME GOTO error
if %pass% == CHANGEME GOTO error

COLOR 8
:menu
cls
echo.
echo          ษอออออออออออออออออออออออออออออออป
echo          บ         Install Menu          บ
echo          ศอออออออออออออออออออออออออออออออป
ECHO.
echo                       	w=World Updates
Echo.
echo                        l=Logon Updates
Echo.
echo                        c=Character Updates
Echo.
echo                        loc=Localization Install(ruRU)
ECHO.
echo                        s=Script Updates
Echo.
echo                        b=Backup World Db
Echo.
echo                        i=Import Full World DB
Echo.
echo                        h=Help
Echo.
echo                        e=Exit
ECHO.


set /p l=		Select : 
if %l%==* goto error
if %l%==w goto wdb
if %l%==l goto ldb
if %l%==c goto cdb
if %l%==loc goto loc
if %l%==s goto sdb
if %l%==i goto import
if %l%==b goto backup
if %l%==e goto quit

:wdb
CLS
ECHO.
echo          World Updates Installing
ECHO.
ECHO [Import] Database is being installed.Please wait.
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./world_updates/485_world_updates.sql
ECHO [Import] Import has been completed.
ECHO.
PAUSE
GOTO MENU

:ldb
CLS
ECHO.
echo          Logon Updates Installing
ECHO.
ECHO [Import] Database is being installed.Please wait.
mysql -h %server% --user=%user% --password=%pass% --port=%port% %ldb% < ./logon_updates/5_premium.sql
ECHO [Import] Import has been completed.
ECHO.
PAUSE
GOTO MENU

:sdb
CLS
ECHO.
echo          Script Updates Installing
ECHO.
ECHO [Import] Database is being installed.Please wait.
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < Script_Template.sql
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./script_updates/illidan_stormrage_encounter.sql
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./script_updates/berthold_chat_fix.sql
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./script_updates/Trainer_gossip_fix.sql
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./script_updates/barnes_opera_fix.sql
ECHO [Import] Import has been completed.
ECHO.
PAUSE
GOTO MENU

:cdb
CLS
ECHO.
echo          Character Updates Installing
ECHO.
ECHO [Import] Database is being installed.Please wait.
mysql -h %server% --user=%user% --password=%pass% --port=%port% %cdb% < ./character_updates/485_character_updates.sql
ECHO [Import] Import has been completed.
ECHO.
PAUSE
GOTO MENU

:loc
CLS
ECHO.
echo          Localization Installing
ECHO.
ECHO [Import] Database is being installed.Please wait.
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./locale/ruRU_localized_creature_names.sql
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./locale/ruRU_localized_gameobject_names.sql
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./locale/ruRU_localized_itempages.sql
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./locale/ruRU_localized_items.sql
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./locale/ruRU_localized_npc_text.sql
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./locale/ruRU_localized_quests.sql
ECHO [Import] Import has been completed.
ECHO.
PAUSE
GOTO MENU
:backup
CLS
ECHO.
echo          Creating backup
ECHO.
ECHO [Import] Database backup is being created.Please wait.
ECHO ai_agents
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% ai_agents > ./World-Backup/ai_agents.sql
ECHO achievement_rewards
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% achievement_rewards > ./World-Backup/achievement_rewards.sql
ECHO ai_threattospellid
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% ai_threattospellid > ./World-Backup/ai_threattospellid.sql
ECHO areatriggers
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% areatriggers > ./World-Backup/areatriggers.sql
ECHO banned_phrases
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% banned_phrases > ./World-Backup/banned_phrases.sql
ECHO auctionhouse
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% auctionhouse > ./World-Backup/auctionhouse.sql
ECHO clientaddons
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% clientaddons > ./World-Backup/clientaddons.sql
ECHO command_overrides
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% command_overrides > ./World-Backup/command_overrides.sql
ECHO creature_formations
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creature_formations > ./World-Backup/creature_formations.sql
ECHO creature_names
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creature_names > ./World-Backup/creature_names.sql
ECHO creature_names_localized
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creature_names_localized > ./World-Backup/creature_names_localized.sql
ECHO creature_proto
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creature_proto > ./World-Backup/creature_proto.sql
ECHO creature_quest_finisher
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creature_quest_finisher > ./World-Backup/creature_quest_finisher.sql
ECHO creature_quest_starter
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creature_quest_starter > ./World-Backup/creature_quest_starter.sql
ECHO creature_spawns
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creature_spawns > ./World-Backup/creature_spawns.sql
ECHO creature_staticspawns
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creature_staticspawns > ./World-Backup/creature_staticspawns.sql
ECHO creature_stats_heroic
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creature_stats_heroic > ./World-Backup/creature_stats_heroic.sql
ECHO creature_timed_emotes
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creature_timed_emotes > ./World-Backup/creature_timed_emotes.sql
ECHO creature_waypoints
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creature_waypoints > ./World-Backup/creature_waypoints.sql
ECHO creatureloot
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creatureloot > ./World-Backup/creatureloot.sql
ECHO creatureloot_gathering
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% creatureloot_gathering > ./World-Backup/creatureloot_gathering.sql
ECHO disenchantingloot
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% disenchantingloot > ./World-Backup/disenchantingloot.sql
ECHO events
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% events > ./World-Backup/events.sql
ECHO events_creature
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% events_creature > ./World-Backup/events_creature.sql
ECHO events_gameobject
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% events_gameobject > ./World-Backup/events_gameobject.sql
ECHO fishing
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% fishing > ./World-Backup/fishing.sql
ECHO fishingloot
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% fishingloot > ./World-Backup/fishingloot.sql
ECHO gameobject_names
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% gameobject_names > ./World-Backup/gameobject_names.sql
ECHO gameobject_names_localized
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% gameobject_names_localized > ./World-Backup/gameobject_names_localized.sql
ECHO gameobject_quest_finisher
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% gameobject_quest_finisher > ./World-Backup/gameobject_quest_finisher.sql
ECHO gameobject_quest_item_binding
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% gameobject_quest_item_binding > ./World-Backup/gameobject_quest_item_binding.sql
ECHO gameobject_quest_pickup_binding
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% gameobject_quest_pickup_binding > ./World-Backup/gameobject_quest_pickup_binding.sql
ECHO gameobject_quest_starter
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% gameobject_quest_starter > ./World-Backup/gameobject_quest_starter.sql
ECHO gameobject_spawns
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% gameobject_spawns > ./World-Backup/gameobject_spawns.sql
ECHO gameobject_staticspawns
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% gameobject_staticspawns > ./World-Backup/gameobject_staticspawns.sql
ECHO gameobject_teleports
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% gameobject_teleports > ./World-Backup/gameobject_teleports.sql
ECHO graveyards
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% graveyards > ./World-Backup/graveyards.sql
ECHO instance_bosses
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% instance_bosses > ./World-Backup/instance_bosses.sql
ECHO item_quest_association
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% item_quest_association > ./World-Backup/item_quest_association.sql
ECHO item_randomprop_groups
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% item_randomprop_groups > ./World-Backup/item_randomprop_groups.sql
ECHO item_randomsuffix_groups
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% item_randomsuffix_groups > ./World-Backup/item_randomsuffix_groups.sql
ECHO itemnames
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% itemnames > ./World-Backup/itemnames.sql
ECHO itempages
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% itempages > ./World-Backup/itempages.sql
ECHO itempages_localized
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% itempages_localized > ./World-Backup/itempages_localized.sql
ECHO itempetfood
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% itempetfood > ./World-Backup/itempetfood.sql
ECHO items
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% items > ./World-Backup/items.sql
ECHO items_extendedcost
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% items_extendedcost > ./World-Backup/items_extendedcost.sql
ECHO items_localized
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% items_localized > ./World-Backup/items_localized.sql
ECHO map_checkpoint
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% map_checkpoint > ./World-Backup/map_checkpoint.sql
ECHO millingloot
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% millingloot > ./World-Backup/millingloot.sql
ECHO news_announcements
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% news_announcements > ./World-Backup/news_announcements.sql
ECHO npc_gossip_textid
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% npc_gossip_textid > ./World-Backup/npc_gossip_textid.sql
ECHO npc_monstersay
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% npc_monstersay > ./World-Backup/npc_monstersay.sql
ECHO npc_text
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% npc_text > ./World-Backup/npc_text.sql
ECHO npc_text_localized
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% npc_text_localized > ./World-Backup/npc_text_localized.sql
ECHO objectloot
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% objectloot > ./World-Backup/objectloot.sql
ECHO pickpocketingloot
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% pickpocketingloot > ./World-Backup/pickpocketingloot.sql
ECHO playercreateinfo
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% playercreateinfo > ./World-Backup/playercreateinfo.sql
ECHO playercreateinfo_bars
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% playercreateinfo_bars > ./World-Backup/playercreateinfo_bars.sql
ECHO playercreateinfo_items
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% playercreateinfo_items > ./World-Backup/playercreateinfo_items.sql
ECHO playercreateinfo_skills
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% playercreateinfo_skills > ./World-Backup/playercreateinfo_skills.sql
ECHO playercreateinfo_spells
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% playercreateinfo_spells > ./World-Backup/playercreateinfo_spells.sql
ECHO prestartqueries
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% prestartqueries > ./World-Backup/prestartqueries.sql
ECHO professiondiscoveries
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% professiondiscoveries > ./World-Backup/professiondiscoveries.sql
ECHO prospectingloot
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% prospectingloot > ./World-Backup/prospectingloot.sql
ECHO itemloot
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% itemloot > ./World-Backup/itemloot.sql
ECHO quests
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% quests > ./World-Backup/quests.sql
ECHO quests_localized
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% quests_localized > ./World-Backup/quests_localized.sql
ECHO randomcardcreation
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% randomcardcreation > ./World-Backup/randomcardcreation.sql
ECHO randomitemcreation
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% randomitemcreation > ./World-Backup/randomitemcreation.sql
ECHO recall
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% recall > ./World-Backup/recall.sql
ECHO reputation_creature_onkill
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% reputation_creature_onkill > ./World-Backup/reputation_creature_onkill.sql
ECHO reputation_faction_onkill
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% reputation_faction_onkill > ./World-Backup/reputation_faction_onkill.sql
ECHO reputation_instance_onkill
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% reputation_instance_onkill > ./World-Backup/reputation_instance_onkill.sql
ECHO scrollcreation
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% scrollcreation > ./World-Backup/scrollcreation.sql
ECHO spell_coef_override
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% spell_coef_override > ./World-Backup/spell_coef_override.sql
ECHO spell_disable
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% spell_disable > ./World-Backup/spell_disable.sql
ECHO spell_disable_trainers
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% spell_disable_trainers > ./World-Backup/spell_disable_trainers.sql
ECHO spell_effects_override
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% spell_effects_override > ./World-Backup/spell_effects_override.sql
ECHO spell_forced_targets
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% spell_forced_targets > ./World-Backup/spell_forced_targets.sql
ECHO spell_proc
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% spell_proc > ./World-Backup/spell_proc.sql
ECHO spell_proc_override
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% spell_proc_override > ./World-Backup/spell_proc_override.sql
ECHO spellfixes
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% spellfixes > ./World-Backup/spellfixes.sql
ECHO spelloverride
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% spelloverride > ./World-Backup/spelloverride.sql
ECHO teleport_coords
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% teleport_coords > ./World-Backup/teleport_coords.sql
ECHO totemspells
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% totemspells < ./World-Backup/totemspells.sql
ECHO trainer_defs
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% trainer_defs > ./World-Backup/trainer_defs.sql
ECHO trainer_spells
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% trainer_spells > ./World-Backup/trainer_spells.sql
ECHO trainerspelloverride
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% trainerspelloverride > ./World-Backup/trainerspelloverride.sql
ECHO transport_creatures
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% transport_creatures > ./World-Backup/transport_creatures.sql
ECHO totemspells
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% totemspells > ./World-Backup/totemspells.sql
ECHO transporters
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% transporters > ./World-Backup/transporters.sql
ECHO unit_display_sizes
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% unit_display_sizes > ./World-Backup/unit_display_sizes.sql
ECHO vendor_restrictions
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% vendor_restrictions > ./World-Backup/vendor_restrictions.sql
ECHO vendors
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% vendors > ./World-Backup/vendors.sql
ECHO weather
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% weather > ./World-Backup/weather.sql
ECHO wordfilter_character_names
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% wordfilter_character_names > ./World-Backup/wordfilter_character_names.sql
ECHO wordfilter_chat
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% wordfilter_chat > ./World-Backup/wordfilter_chat.sql
ECHO worldbroadcast
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% worldbroadcast > ./World-Backup/worldbroadcast.sql
ECHO worldbroadcast_localized
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% worldbroadcast_localized > ./World-Backup/worldbroadcast_localized.sql
ECHO worldmap_info
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% worldmap_info > ./World-Backup/worldmap_info.sql
ECHO worldmap_info_localized
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% worldmap_info_localized > ./World-Backup/worldmap_info_localized.sql
ECHO worldstate_template
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% worldstate_template > ./World-Backup/worldstate_template.sql
ECHO worldstring_tables
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% worldstring_tables > ./World-Backup/worldstring_tables.sql
ECHO worldstring_tables_localized
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% worldstring_tables_localized > ./World-Backup/worldstring_tables_localized.sql
ECHO zoneguards
mysqldump -h %server% --user=%user% --password=%pass% --port=%port% %wdb% zoneguards > ./World-Backup/zoneguards.sql
ECHO [Import] Backup has been completed.Check up your World-Backup dir.
ECHO.
PAUSE
GOTO MENU

:import
CLS
ECHO.
echo          Importing DB, Note that db must be clean
ECHO.
ECHO [Import] Database Import is in progress.Please wait.
ECHO ai_agents
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/ai_agents.sql
ECHO achievement_rewards
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/achievement_rewards.sql
ECHO ai_threattospellid
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/ai_threattospellid.sql
ECHO areatriggers
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/areatriggers.sql
ECHO banned_names
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/banned_names.sql
ECHO auctionhouse
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/auctionhouse.sql
ECHO clientaddons
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/clientaddons.sql
ECHO command_overrides
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/command_overrides.sql
ECHO creature_formations
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creature_formations.sql
ECHO creature_names
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creature_names.sql
ECHO creature_names_localized
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creature_names_localized.sql
ECHO creature_proto
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creature_proto.sql
ECHO creature_quest_finisher
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creature_quest_finisher.sql
ECHO creature_quest_starter
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creature_quest_starter.sql
ECHO creature_spawns
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creature_spawns.sql
ECHO creature_staticspawns
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creature_staticspawns.sql
ECHO creature_stats_heroic
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creature_stats_heroic.sql
ECHO creature_timed_emotes
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creature_timed_emotes.sql
ECHO creature_waypoints
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creature_waypoints.sql
ECHO creatureloot
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creatureloot.sql
ECHO creatureloot_gathering
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/creatureloot_gathering.sql
ECHO disenchantingloot
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/disenchantingloot.sql
ECHO events
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/events.sql
ECHO events_creature
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/events_creature.sql
ECHO events_gameobject
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/events_gameobject.sql
ECHO fishing
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/fishing.sql
ECHO fishingloot
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/fishingloot.sql
ECHO gameobject_names
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/gameobject_names.sql
ECHO gameobject_names_localized
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/gameobject_names_localized.sql
ECHO gameobject_quest_finisher
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/gameobject_quest_finisher.sql
ECHO gameobject_quest_item_binding
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/gameobject_quest_item_binding.sql
ECHO gameobject_quest_pickup_binding
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/gameobject_quest_pickup_binding.sql
ECHO gameobject_quest_starter
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/gameobject_quest_starter.sql
ECHO gameobject_spawns
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/gameobject_spawns.sql
ECHO gameobject_staticspawns
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/gameobject_staticspawns.sql
ECHO gameobject_teleports
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/gameobject_teleports.sql
ECHO graveyards
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/graveyards.sql
ECHO instance_bosses
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/instance_bosses.sql
ECHO item_quest_association
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/item_quest_association.sql
ECHO item_randomprop_groups
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/item_randomprop_groups.sql
ECHO item_randomsuffix_groups
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/item_randomsuffix_groups.sql
ECHO itemnames
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/itemnames.sql
ECHO itempages
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/itempages.sql
ECHO itempages_localized
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/itempages_localized.sql
ECHO itempetfood
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/itempetfood.sql
ECHO items
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/items.sql
ECHO items_extendedcost
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/items_extendedcost.sql
ECHO items_localized
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/items_localized.sql
ECHO map_checkpoint
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/map_checkpoint.sql
ECHO millingloot
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/millingloot.sql
ECHO news_announcements
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/news_announcements.sql
ECHO npc_gossip_textid
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/npc_gossip_textid.sql
ECHO npc_monstersay
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/npc_monstersay.sql
ECHO npc_text
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/npc_text.sql
ECHO npc_text_localized
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/npc_text_localized.sql
ECHO objectloot
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/objectloot.sql
ECHO pickpocketingloot
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/pickpocketingloot.sql
ECHO playercreateinfo
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/playercreateinfo.sql
ECHO playercreateinfo_bars
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/playercreateinfo_bars.sql
ECHO playercreateinfo_items
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/playercreateinfo_items.sql
ECHO playercreateinfo_skills
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/playercreateinfo_skills.sql
ECHO playercreateinfo_spells
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/playercreateinfo_spells.sql
ECHO prestartqueries
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/prestartqueries.sql
ECHO professiondiscoveries
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/professiondiscoveries.sql
ECHO prospectingloot
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/prospectingloot.sql
ECHO itemloot
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/itemloot.sql
ECHO quests
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/quests.sql
ECHO quests_localized
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/quests_localized.sql
ECHO randomcardcreation
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/randomcardcreation.sql
ECHO randomitemcreation
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/randomitemcreation.sql
ECHO recall
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/recall.sql
ECHO reputation_creature_onkill
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/reputation_creature_onkill.sql
ECHO reputation_faction_onkill
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/reputation_faction_onkill.sql
ECHO reputation_instance_onkill
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/reputation_instance_onkill.sql
ECHO scrollcreation
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/scrollcreation.sql
ECHO spell_coef_override
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/spell_coef_override.sql
ECHO spell_disable
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/spell_disable.sql
ECHO spell_disable_trainers
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/spell_disable_trainers.sql
ECHO spell_effects_override
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/spell_effects_override.sql
ECHO spell_forced_targets
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/spell_forced_targets.sql
ECHO spell_proc
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/spell_proc.sql
ECHO spell_proc_override
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/spell_proc_override.sql
ECHO spellfixes
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/spellfixes.sql
ECHO spelloverride
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/spelloverride.sql
ECHO teleport_coords
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/teleport_coords.sql
ECHO totemspells
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/totemspells.sql
ECHO trainer_defs
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/trainer_defs.sql
ECHO trainer_spells
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/trainer_spells.sql
ECHO trainerspelloverride
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/trainerspelloverride.sql
ECHO transport_creatures
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/transport_creatures.sql
ECHO transporters
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/transporters.sql
ECHO unit_display_sizes
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/unit_display_sizes.sql
ECHO vendor_restrictions
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/vendor_restrictions.sql
ECHO vendors
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/vendors.sql
ECHO weather
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/weather.sql
ECHO wordfilter_character_names
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/wordfilter_character_names.sql
ECHO wordfilter_chat
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/wordfilter_chat.sql
ECHO worldbroadcast
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/worldbroadcast.sql
ECHO worldbroadcast_localized
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/worldbroadcast_localized.sql
ECHO worldmap_info
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/worldmap_info.sql
ECHO worldmap_info_localized
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/worldmap_info_localized.sql
ECHO worldstate_template
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/worldstate_template.sql
ECHO worldstring_tables
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/worldstring_tables.sql
ECHO worldstring_tables_localized
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/worldstring_tables_localized.sql
ECHO zoneguards
mysql -h %server% --user=%user% --password=%pass% --port=%port% %wdb% < ./WorldDB/zoneguards.sql
ECHO [Import] Import has been completed.
ECHO.
PAUSE
GOTO MENU

:help
cls
echo.
echo          ษอออออออออออออออออออออออออออออออป
echo         บ Please Choose One Of the option บ
echo          ศอออออออออออออออออออออออออออออออป
ECHO.
PAUSE
COLOR 0A
:quit







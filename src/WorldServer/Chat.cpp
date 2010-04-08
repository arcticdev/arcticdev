/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

initialiseSingleton( ChatHandler );
initialiseSingleton(CommandTableStorage);

ChatCommand * ChatHandler::getCommandTable()
{
	ASSERT(false);
	return 0;
}

ChatCommand * CommandTableStorage::GetSubCommandTable(const char * name)
{
	if(!strcmp(name, "modify"))
		return _modifyCommandTable;
	else if(!strcmp(name, "debug"))
		return _debugCommandTable;
	else if(!strcmp(name, "waypoint"))
		return _waypointCommandTable;
	else if(!strcmp(name, "gmTicket"))
		return _GMTicketCommandTable;
	else if(!strcmp(name, "gobject"))
		return _GameObjectCommandTable;
	else if(!strcmp(name, "battleground"))
		return _BattlegroundCommandTable;
	else if(!strcmp(name, "npc"))
		return _NPCCommandTable;
	else if(!strcmp(name, "cheat"))
		return _CheatCommandTable;
	else if(!strcmp(name, "account"))
		return _accountCommandTable;
	else if(!strcmp(name, "pet"))
		return _petCommandTable;
	else if(!strcmp(name, "recall"))
		return _recallCommandTable;
	else if(!strcmp(name, "honor"))
		return _honorCommandTable;
	else if(!strcmp(name, "guild"))
		return _GuildCommandTable;
	else if(!strcmp(name, "title"))
		return _TitleCommandTable;
	else if(!strcmp(name, "quest"))
		return _questCommandTable;
	return 0;
}

#define dupe_command_table(ct, dt) this->dt = (ChatCommand*)allocate_and_copy(sizeof(ct)/* / sizeof(ct[0])*/, ct)
ARCTIC_INLINE void* allocate_and_copy(uint32 len, void * pointer)
{
	void * data = (void*)malloc(len);
	memcpy(data, pointer, len);
	return data;
}

void CommandTableStorage::Load()
{
	QueryResult * result = WorldDatabase.Query("SELECT * FROM command_overrides");
	if(!result) return;

	do 
	{
		const char * name = result->Fetch()[0].GetString();
		const char * level = result->Fetch()[1].GetString();
		Override(name, level);
	} while(result->NextRow());
	delete result;
}

void CommandTableStorage::Override(const char * command, const char * level)
{
	ASSERT(level[0] != '\0');
	char * cmd = strdup(command);

	// find the command we're talking about
	char * sp = strchr(cmd, ' ');
	const char * command_name = cmd;
	const char * subcommand_name = 0;

	if(sp != 0)
	{
		// we're dealing with a subcommand.
		*sp = 0;
		subcommand_name = sp + 1;
	}

	size_t len1 = strlen(command_name);
	size_t len2 = subcommand_name ? strlen(subcommand_name) : 0;

	// look for the command.
	ChatCommand * p = &_commandTable[0];
	while(p->Name != 0)
	{
		if(!strnicmp(p->Name, command_name, len1))
		{
			// this is the one we wanna modify
			if(!subcommand_name)
			{
				// no subcommand, we can change it.
				p->CommandGroup = level[0];
				printf(CHANGINGACOAA, p->Name, level[0]);
			}
			else
			{
				// assume this is a subcommand, loop the second set.
				ChatCommand * p2 = p->ChildCommands;
				if(!p2)
				{
					printf(INVALIDACOMMA, command_name);
				}
				else
				{
					while(p2->Name != 0)
					{
						if(!strnicmp("*",subcommand_name,1))
						{
								p2->CommandGroup = level[0];
								printf(CHANGINGACOMA, p->Name, p2->Name, level[0]);
						}else{
							if(!strnicmp(p2->Name, subcommand_name, len2))
							{
								// change the level
								p2->CommandGroup = level[0];
								printf(CHAGENGACOMMA, p->Name, p2->Name, level[0]);
								break;
							}
						}
						p2++;
					}
					if(p2->Name == 0)
					{
						if(strnicmp("*",subcommand_name,1)) 
						{
							printf(INVALEDESASUA, subcommand_name, p->Name);
						}
						break;
					}
				}
			}
			break;
		}
		++p;
	}

	if(p->Name == 0)
	{
		printf(INVALEDESAREA, command_name);
	}

	free(cmd);
}

void CommandTableStorage::Dealloc()
{
	free( _modifyCommandTable );
	free( _debugCommandTable );
	free( _waypointCommandTable );
	free( _GMTicketCommandTable );
	free( _GameObjectCommandTable );
	free( _BattlegroundCommandTable );
	free( _NPCCommandTable );
	free( _CheatCommandTable );
	free( _accountCommandTable );
	free( _petCommandTable );
	free( _recallCommandTable );
	free( _honorCommandTable );
	free( _GuildCommandTable);
	free( _TitleCommandTable);
	free( _questCommandTable );
	free( _commandTable );
}

void CommandTableStorage::Init()
{
	static ChatCommand modifyCommandTable[] =
	{
		{ "hp",		               'm', NULL,	                                                       HEALAAAAAAAA,	             NULL, UNIT_FIELD_HEALTH, UNIT_FIELD_MAXHEALTH, 1 },
		{ "mana",	               'm', NULL,	                                                       MANAAAAAAAAA,	             NULL, UNIT_FIELD_POWER1, UNIT_FIELD_MAXPOWER1, 1 },
		{ "rage",	               'm', NULL,	                                                       RAGEAAAAAAAA,	        	 NULL, UNIT_FIELD_POWER2, UNIT_FIELD_MAXPOWER2, 1 },
		{ "runicpower",            'm', NULL,	                                                       RUNICAAAAAAA,	        	 NULL, UNIT_FIELD_POWER7, UNIT_FIELD_MAXPOWER7, 1 },
		{ "energy",	               'm', NULL,	                                                       ENERAAAAAAAA,	             NULL, UNIT_FIELD_POWER4, UNIT_FIELD_MAXPOWER4, 1 },
		{ "lvl",	               'm', &ChatHandler::HandleModifyLevelCommand,                        LEVELAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "armor",	               'm', NULL,	                                                       ARMORAAAAAAA,			                         NULL, UNIT_FIELD_STAT1, 0, 1 },
		{ "holy",	               'm', NULL,	                                                       HOLYAAAAAAAA,	                         NULL, UNIT_FIELD_RESISTANCES_1, 0, 1 },
		{ "fire",	               'm', NULL,	                                                       FIREAAAAAAAA,	                         NULL, UNIT_FIELD_RESISTANCES_2, 0, 1 },
		{ "nature",	               'm', NULL,	                                                       NATUREAAAAAA,                             NULL, UNIT_FIELD_RESISTANCES_3, 0, 1 },
		{ "frost",	               'm', NULL,                                                      	   FROSTAAAAAAA,	                         NULL, UNIT_FIELD_RESISTANCES_4, 0, 1 },
		{ "shadow",	               'm', NULL,	                                                       SHADOWAAAAAA,                             NULL, UNIT_FIELD_RESISTANCES_5, 0, 1 },
		{ "arcane",	               'm', NULL,	                                                       ARCANEAAAAAA,                             NULL, UNIT_FIELD_RESISTANCES_6, 0, 1 },
		{ "damage",	               'm', NULL,	                                                       UNITDAAAAAAA,              NULL, UNIT_FIELD_MINDAMAGE, UNIT_FIELD_MAXDAMAGE, 2 },
		{ "scale",	               'm', NULL,	                                                       SIZEAAAAAAAA,		                         NULL, OBJECT_FIELD_SCALE_X, 0, 2 },
		{ "gold",	               'm', &ChatHandler::HandleModifyGoldCommand,                         GOLDAAAAAAAA,	                                                NULL, 0, 0, 0 },
		{ "speed",	               'm', &ChatHandler::HandleModifySpeedCommand,                        MGVEMENTAAAA,	    	                                        NULL, 0, 0, 0 },
		{ "nativedisplayid",       'm', NULL,                                                          NATIVEAAAAAA,                           NULL, UNIT_FIELD_NATIVEDISPLAYID, 0, 1 },
		{ "displayid" ,            'm', NULL,                                                          DISPLAYAAAAA,		                         NULL, UNIT_FIELD_DISPLAYID, 0, 1 },
		{ "flags" ,	               'm', NULL,	                                                       UFLAGSAAAAAA,		                             NULL, UNIT_FIELD_FLAGS, 0, 1 },
		{ "faction",	           'm', NULL,	                                                       TEMPLATEAAAA,                           NULL, UNIT_FIELD_FACTIONTEMPLATE, 0, 1 },
		{ "dynamicflags",          'm', NULL,	                                                       DYNAMISFAAAA,	                               NULL, UNIT_DYNAMIC_FLAGS, 0, 1 },
		{ "talentpoints",          'm', NULL,	                                                       TALANTSAAAAA,	                         NULL, PLAYER_CHARACTER_POINTS1, 0, 1 },
		{ "happiness",	           'm', NULL,	                                                       HAPPINESAAAA,	             NULL, UNIT_FIELD_POWER5, UNIT_FIELD_MAXPOWER5, 1 },
		{ "spirit",	               'm', NULL,	                                                       SPIRITAAAAAA,			                         NULL, UNIT_FIELD_STAT0, 0, 1 },
		{ "boundingraidius",       'm', NULL,                                                          RADIUSBAAAAA,	                        NULL, UNIT_FIELD_BOUNDINGRADIUS, 0, 2 },
		{ "combatreach",           'm', NULL,	                                                       REACHAAAAAAA,		                       NULL, UNIT_FIELD_COMBATREACH, 0, 2 },             
		{ "emotestate",            'm', NULL,	                                                       NPCEMOTEAAAA,	                              NULL, UNIT_NPC_EMOTESTATE, 0, 1 },
		{ "bytes",                 'm', NULL,                                                          BYTESAAAAAAA,                                   NULL, UNIT_FIELD_BYTES_0, 0, 1 },
		{ NULL,		                0,  NULL,	                                                       "",	    	                                                     NULL, 0, 0 }
	};
	dupe_command_table(modifyCommandTable, _modifyCommandTable);

	static ChatCommand debugCommandTable[] =
	{
		{ "spellwar",	           'z',	&ChatHandler::HandleDebugSpellWarCommand,	                   "",						                                        NULL, 0, 0, 0 },
		{ "retroactivequest",      'd', &ChatHandler::HandleDebugRetroactiveQuestAchievements,         RETROATAAAAA,			                                        NULL, 0, 0, 0 },
		{ "setphase",              'd', &ChatHandler::HandleDebugSetPhase,                             SETPHASEAAAA,			                                        NULL, 0, 0, 0 },
		{ "infront",	           'd', &ChatHandler::HandleDebugInFrontCommand,                       INFRONTAAAAA,			                                        NULL, 0, 0, 0 },
		{ "showreact",             'd', &ChatHandler::HandleShowReactionCommand,                       SHOWREATAAAA,			                                        NULL, 0, 0, 0 },
		{ "aimove",	               'd', &ChatHandler::HandleAIMoveCommand,		                       AIMONEAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "dist",	 	           'd', &ChatHandler::HandleDistanceCommand,	                       DISTAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "face",		           'd', &ChatHandler::HandleFaceCommand,	                    	   FACEAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "moveinfo", 	           'd', &ChatHandler::HandleMoveInfoCommand,                    	   MOVEINFOAAAA,			                                        NULL, 0, 0, 0 },
		{ "setbytes",	           'd', &ChatHandler::HandleSetBytesCommand,	                       SETBYTESAAAA,			                                        NULL, 0, 0, 0 },
		{ "getbytes",	           'd', &ChatHandler::HandleGetBytesCommand,	                       GETBYTESAAAA,			                                        NULL, 0, 0, 0 },
		{ "unroot",	               'd', &ChatHandler::HandleDebugUnroot,		                       UNROOTAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "root",		           'd', &ChatHandler::HandleDebugRoot,			                       ROOTAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "landwalk",	           'd', &ChatHandler::HandleDebugLandWalk,	                           LANDWALKAAAA,			                                        NULL, 0, 0, 0 },
		{ "waterwalk",             'd', &ChatHandler::HandleDebugWaterWalk,	                           EATERWALKAAA,			                                        NULL, 0, 0, 0 },
		{ "castspellne",           'd', &ChatHandler::HandleCastSpellNECommand,                        SPELLIDAAAAA,			                                        NULL, 0, 0, 0 },
		{ "aggrorange",            'd', &ChatHandler::HandleAggroRangeCommand,	                       SHGWSAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "knockback ",            'd', &ChatHandler::HandleKnockBackCommand,	                       VSPEEDAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "fade ",	               'd', &ChatHandler::HandleFadeCommand,		                       MODTHEATAAAA,			                                        NULL, 0, 0, 0 },
		{ "threatMod ",            'd', &ChatHandler::HandleThreatModCommand,	                       THEATMODAAAA,			                                        NULL, 0, 0, 0 },
		{ "calcThreat ",           'd', &ChatHandler::HandleCalcThreatCommand,	                       DMGAAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "threatList ",           'd', &ChatHandler::HandleThreatListCommand,	                       THEALISTAAAA,			                                        NULL, 0, 0, 0 },
		{ "gettptime",             'd', &ChatHandler::HandleGetTransporterTime,                        GRABSAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "itempushresult",        'd', &ChatHandler::HandleSendItemPushResult,                        SENDSAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "setbit",	               'd', &ChatHandler::HandleModifyBitCommand,	                       SETBITSAAAAA,			                                        NULL, 0, 0, 0 },
		{ "setvalue",	           'd', &ChatHandler::HandleModifyValueCommand,                        SETVALUEAAAA,			                                        NULL, 0, 0, 0 },
		{ "aispelltestbegin",      'd', &ChatHandler::HandleAIAgentDebugBegin,                         AISPILLAAAAA,			                                        NULL, 0, 0, 0 },
		{ "aispelltestcontinue",   'd', &ChatHandler::HandleAIAgentDebugContinue,                      CONSTAINAAAA,			                                        NULL, 0, 0, 0 },
		{ "aispelltestskip",       'd', &ChatHandler::HandleAIAgentDebugSkip,                          LIAINSRAAAAA,			                                        NULL, 0, 0, 0 },
		{ "dumpcoords",            'd', &ChatHandler::HandleDebugDumpCoordsCommmand,                   DUMPVAAAAAAA,			                                        NULL, 0, 0, 0 },
        { "sendpacket",            'd', &ChatHandler::HandleSendpacket,                                OOPSAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "sqlquery",              'd', &ChatHandler::HandleSQLQueryCommand,                           SQYQAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "rangecheck",            'd', &ChatHandler::HandleRangeCheckCommand,                         RANGEAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "setallratings",         'd', &ChatHandler::HandleRatingsCommand,                            SETSAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ NULL,		                0,  NULL,									                       "",							                                    NULL, 0, 0  }
	};
	dupe_command_table(debugCommandTable, _debugCommandTable);

	static ChatCommand waypointCommandTable[] =
	{
		{ "add",		           'w', &ChatHandler::HandleWPAddCommand,		                       WPPOSAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "show",	 	           'w', &ChatHandler::HandleWPShowCommand,		                       SHOWAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "hide",		           'w', &ChatHandler::HandleWPHideCommand,		                       HIDEAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "delete",	               'w', &ChatHandler::HandleWPDeleteCommand,	                       DELETESPAAAA,			                                        NULL, 0, 0, 0 },
		{ "movehere",	           'w', &ChatHandler::HandleWPMoveHereCommand,                    	   MOVWSPAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "flags",	               'w', &ChatHandler::HandleWPFlagsCommand,	                           WPFLANGAAAAA,			                                        NULL, 0, 0, 0 },
		{ "waittime",	           'w', &ChatHandler::HandleWPWaitCommand,		                       WAITTIMEAAAA,			                                        NULL, 0, 0, 0 },
		{ "standstate",        	   'w', &ChatHandler::HandleWPStandStateCommand, 	                   STANDSTAREAA,			                                        NULL, 0, 0, 0 },
		{ "SpellToCast",           'w', &ChatHandler::HandleWPSpellToCastCommand,                  	   SKILLLADSAAA,			                                        NULL, 0, 0, 0 },
		{ "emote",	               'w', &ChatHandler::HandleWPEmoteCommand,	                           EMOTEATDLAAA,			                                        NULL, 0, 0, 0 },
		{ "equip",                 'n', &ChatHandler::HandleNPCEquipCommand,                           NPSWQIPSAAAA,			                                        NULL, 0, 0, 0 },
		{ "skin",		           'w', &ChatHandler::HandleWPSkinCommand,		                       SKINATIJAAAA,			                                        NULL, 0, 0, 0 },
		{ "change",	               'w', &ChatHandler::HandleWPChangeNoCommand,	                       CHANDEATCAAA,			                                        NULL, 0, 0, 0 },
		{ "info",		           'w', &ChatHandler::HandleWPInfoCommand,		                       INTAFDFAAAAA,			                                        NULL, 0, 0, 0 },
		{ "movetype",          	   'w', &ChatHandler::HandleWPMoveTypeCommand,	                       MOVEMENTAAAA,			                                        NULL, 0, 0, 0 },
		{ "generate",	           'w', &ChatHandler::HandleGenerateWaypoints,	                       RANDOMLYWEAA,			                                        NULL, 0, 0, 0 },
		{ "save",		           'w', &ChatHandler::HandleSaveWaypoints,	                           SALLEAALAAAA,			                                        NULL, 0, 0, 0 },
		{ "deleteall",	           'w', &ChatHandler::HandleDeleteWaypoints,	                       DELEREALLEAA,			                                        NULL, 0, 0, 0 },
		{ "addfly",                'w', &ChatHandler::HandleWaypointAddFlyCommand,                     ADDSISAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "gettext",	           'w', &ChatHandler::HandleWaypointGettextCommand,                    ASYTESTSAAAA,			                                        NULL, 0, 0, 0 },
		{ "backwardtext",          'w', &ChatHandler::HandleWaypointBackwardTextCommand,               BACKWARFEAAA,			                                        NULL, 0, 0, 0 },
		{ "forwardtext",           'w', &ChatHandler::HandleWaypointForwardTextCommand,                SADDSFORAAAA,			                                        NULL, 0, 0, 0 },
		{ NULL,			            0,  NULL,									                       "",							                                    NULL, 0, 0  }
	};
	dupe_command_table(waypointCommandTable, _waypointCommandTable);

	static ChatCommand GMTicketCommandTable[] =
	{
		{ "get",		           'c', &ChatHandler::HandleGMTicketGetAllCommand,                     GETSGMSAAAAA,			                                        NULL, 0, 0, 0 },
		{ "getId",	               'c', &ChatHandler::HandleGMTicketGetByIdCommand,                    GETSGMSIDAAA,			                                        NULL, 0, 0, 0 },
		{ "delId",	               'c', &ChatHandler::HandleGMTicketDelByIdCommand,                    DELETESAGMAA,			                                        NULL, 0, 0, 0 },
		{ NULL,			            0,  NULL,									                       "",							                                    NULL, 0, 0  }
	};
	dupe_command_table(GMTicketCommandTable, _GMTicketCommandTable);

	static ChatCommand GuildCommandTable[] =
	{
		{ "create",		           'm', &ChatHandler::CreateGuildCommand,                              CREATIVEGIAA,			                                        NULL, 0, 0, 0 },
		{ "rename",	               'm', &ChatHandler::HandleRenameGuildCommand,                        RAHAMEGILAAA,			                                        NULL, 0, 0, 0 },
		{ "members",	           'm', &ChatHandler::HandleGuildMembersCommand,                       LISTSGINLSAA,			                                        NULL, 0, 0, 0 },
		{ "removeplayer",	       'm', &ChatHandler::HandleGuildRemovePlayerCommand,                  REMOVERPLAAA,			                                        NULL, 0, 0, 0 },
		{ "disband",	           'm', &ChatHandler::HandleGuildDisbandCommand,                       DISBANDSAAAA,			                                        NULL, 0, 0, 0 },
		{ "setleader",             'm', &ChatHandler::HandleGuildSetLeaderCommand,                     SETSAGIRLSAA,			                                        NULL, 0, 0, 0 },
		{ NULL,			            0,  NULL,									                       "",						                                        NULL, 0, 0  }
	};
	dupe_command_table(GuildCommandTable, _GuildCommandTable);

	static ChatCommand TitleCommandTable[] =
	{
		{ "add",		           'm', &ChatHandler::HandleAddTitleCommand,                           TITLENUMBERA,			                                        NULL, 0, 0, 0},
		{ "remove",	               'm', &ChatHandler::HandleRemoveTitleCommand,                        REMOVERTITAA,			                                        NULL, 0, 0, 0},
		{ "known",	               'm', &ChatHandler::HandleGetKnownTitlesCommand,                     SHOWSAAAAAAA,			                                        NULL, 0, 0, 0},
		{ "setchosen",	           'm', &ChatHandler::HandleSetChosenTitleCommand,                     SETSTITLESAA,			                                        NULL, 0, 0, 0},
		{ NULL,		 	            0,  NULL,									                       "",							                                    NULL, 0, 0 }
	};
	dupe_command_table(TitleCommandTable, _TitleCommandTable);

	static ChatCommand GameObjectCommandTable[] =
	{
		{ "select",	               'o', &ChatHandler::HandleGOSelect,                                  GAMEOBECTAAA,			                                        NULL, 0, 0, 0 },
		{ "delete",	               'o', &ChatHandler::HandleGODelete,                                  DELGAMEOBEAA,			                                        NULL, 0, 0, 0 },
		{ "spawn",	               'o', &ChatHandler::HandleGOSpawn,	                               SPAWSGAMEOBA,			                                        NULL, 0, 0, 0 },
		{ "info",		           'o', &ChatHandler::HandleGOInfo,	                                   GIVEYOUAAAAA,			                                        NULL, 0, 0, 0 },
		{ "activate",	           'o', &ChatHandler::HandleGOActivate,                                OPENSASTIAAA,			                                        NULL, 0, 0, 0 },
		{ "enable",	               'o', &ChatHandler::HandleGOEnable,                                  ENABLESAGOAA,			                                        NULL, 0, 0, 0 },
		{ "scale",	               'o', &ChatHandler::HandleGOScale,	                               SETSSCALEAAA,			                                        NULL, 0, 0, 0 },
		{ "animprogress",          'o', &ChatHandler::HandleGOAnimProgress,                            ASTESTANIMAA,			                                        NULL, 0, 0, 0 },
		{ "export",	               'o', &ChatHandler::HandleGOExport,                                  GOSTNESAAAAA,			                                        NULL, 0, 0, 0 },
		{ "move",                  'g', &ChatHandler::HandleGOMove,                                    XYZMOVESAAAA,			                                        NULL, 0, 0, 0 },
		{ "rotate",                'g', &ChatHandler::HandleGORotate,                                  ROTATESAAAAA,			                                        NULL, 0, 0, 0 },
		{ "f_flags",               'g', NULL,                                                          FLANGSAGOAAA,			                                        NULL, GAMEOBJECT_FLAGS, 0, 3 },
		{ "f_dynflags",            'g', NULL,                                                          DYNFLANGOSAA,			                                        NULL, GAMEOBJECT_DYNAMIC, 0, 3 },
		{ NULL,			            0,  NULL,					                                  	   "",										                        NULL, 0, 0  }
	};
	dupe_command_table(GameObjectCommandTable, _GameObjectCommandTable);

	static ChatCommand BattlegroundCommandTable[] = 
	{
		{ "setbgscore",		       'e', &ChatHandler::HandleSetBGScoreCommand,	                       TEAMSIDAAAAA,			                                        NULL, 0, 0, 0 },
		{ "startbg",		       'e', &ChatHandler::HandleStartBGCommand,	                           STARTSBATTLA,                                                    NULL, 0, 0, 0 },
		{ "pausebg",		       'e', &ChatHandler::HandlePauseBGCommand,	                           PAUSERASUNTA,                                                    NULL, 0, 0, 0 },
		{ "bginfo",			       'e', &ChatHandler::HandleBGInfoCommnad,		                       DISPLAYNSFAA,                                                    NULL, 0, 0, 0 },
		{ "battleground",	       'e', &ChatHandler::HandleBattlegroundCommand,                       BGMENUPIAAAA,			                                        NULL, 0, 0, 0 },
		{ "setworldstate",	       'e', &ChatHandler::HandleSetWorldStateCommand,                      VALVALAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "playsound",		       'e', &ChatHandler::HandlePlaySoundCommand,	                       CAMDVALAAAAA,			                                        NULL, 0, 0, 0 },
		{ "setbfstatus",	       'e', &ChatHandler::HandleSetBattlefieldStatusCommand,               POIUYHNAAAAA,			                                        NULL, 0, 0, 0 },
		{ "leave",			       'e', &ChatHandler::HandleBattlegroundExitCommand,                   LEAVESAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "forcestart",		       'e', &ChatHandler::HandleBattlegroundForcestartCommand,             FORECETARTAA,			                                        NULL, 0, 0, 0 },
		{ NULL,			            0,  NULL,									                       "",									                            NULL, 0, 0  }
	};
	dupe_command_table(BattlegroundCommandTable, _BattlegroundCommandTable);

	static ChatCommand NPCCommandTable[] =                                                                                                                             
	{
		{ "vendoradditem",         'z', &ChatHandler::HandleItemCommand,	                           ADDSTOVENDAA,			                                        NULL, 0, 0, 0 },
		{ "vendorremoveitem",      'z', &ChatHandler::HandleItemRemoveCommand,                         REMOVESVENDA,			                                        NULL, 0, 0, 0 },
		{ "flags",	               'n', &ChatHandler::HandleNPCFlagCommand,	                           CHANGERSNPSA,			                                        NULL, 0, 0, 0 },
		{ "emote",	               'n', &ChatHandler::HandleEmoteCommand,		                       EMOSSTATESAA,			                                        NULL, 0, 0, 0 },
		{ "delete",	               'n', &ChatHandler::HandleDeleteCommand,		                       DELETASMOBAA,			                                        NULL, 0, 0, 0 },
		{ "info",		           'n', &ChatHandler::HandleNpcInfoCommand,	                           DISPLAYSAAAA,			                                        NULL, 0, 0, 0 },
		{ "addAgent",	           'n', &ChatHandler::HandleAddAIAgentCommand,                   	   NPSADDAGENTA,                                                    NULL, 0, 0, 0 },
		{ "listAgent",             'n', &ChatHandler::HandleListAIAgentCommand,                        LISTAGENTSAA,			                                        NULL, 0, 0, 0 },
		{ "say",		           'n', &ChatHandler::HandleMonsterSayCommand,	                       TSETNPSAAAAA,			                                        NULL, 0, 0, 0 },
		{ "yell",		           'n', &ChatHandler::HandleMonsterYellCommand,                        MAKESTESEQAA,			                                        NULL, 0, 0, 0 },
		{ "come",		           'n', &ChatHandler::HandleNpcComeCommand,	                           NPSCOMESAAAA,			                                        NULL, 0, 0, 0 },
		{ "return",           	   'n', &ChatHandler::HandleNpcReturnCommand,	                       NPSRETUSAAAA,			                                        NULL, 0, 0, 0 },
		{ "spawn",                 'n', &ChatHandler::HandleCreatureSpawnCommand,                      NPSSPAWNSAAA,			                                        NULL, 0, 0, 0 },
		{ "spawnlink",             'n', &ChatHandler::HandleNpcSpawnLinkCommand,                       SPAWNSLINKAA,			                                        NULL, 0, 0, 0 },
		{ "possess",               'n', &ChatHandler::HandleNpcPossessCommand,                         NPSPOSESSAAA,			                                        NULL, 0, 0, 0 },
		{ "unpossess",             'n', &ChatHandler::HandleNpcUnPossessCommand,                       NPSUNPOSSAAA,			                                        NULL, 0, 0, 0 },
		{ "select",                'n', &ChatHandler::HandleNpcSelectCommand,                          NPSSELECTAAA,			                                        NULL, 0, 0, 0 },
		{ "cast",                  'd', &ChatHandler::HandleMonsterCastCommand,                        NPSCASTAAAAA,			                                        NULL, 0, 0, 0 },
		{ NULL,		                0,  NULL,										                   "",										          			    NULL, 0, 0, 0 },
	};
	dupe_command_table(NPCCommandTable, _NPCCommandTable);

	static ChatCommand CheatCommandTable[] =
	{ 
		{ "status",                'm', &ChatHandler::HandleShowCheatsCommand,                         SHOWSACTAAAA,			                                        NULL, 0, 0, 0 },
		{ "taxi",	               'm', &ChatHandler::HandleTaxiCheatCommand,	                       ENABLESAAAAA,			                                        NULL, 0, 0, 0 },
		{ "cooldown",              'm', &ChatHandler::HandleCooldownCheatCommand,                      COOLDOWSQAAA,			                                        NULL, 0, 0, 0 },
		{ "casttime",              'm', &ChatHandler::HandleCastTimeCheatCommand,                      TIZEENABLESA,                                                    NULL, 0, 0, 0 },
		{ "power",	               'm', &ChatHandler::HandlePowerCheatCommand,                         DISABLESAAAA,			                                        NULL, 0, 0, 0 },
		{ "god",		           'm', &ChatHandler::HandleGodModeCommand,                            SETSGOSAAAAA,			                                        NULL, 0, 0, 0 },
		{ "fly",		           'm', &ChatHandler::HandleFlyCommand,                                SETSMODEAAAA,			                                        NULL, 0, 0, 0 },
		{ "land",	               'm', &ChatHandler::HandleLandCommand,                               UNESETSAAAAA,			                                        NULL, 0, 0, 0 },
		{ "explore",	           'm', &ChatHandler::HandleExploreCheatCommand,                       REVEALSAAAAA,			                                        NULL, 0, 0, 0 },
		{ "flyspeed",              'm', &ChatHandler::HandleFlySpeedCheatCommand,                      MODIFYFLEAAA,			                                        NULL, 0, 0, 0 },
		{ "stack",	               'm', &ChatHandler::HandleStackCheatCommand,                         ENABLESRAAAA,			                                        NULL, 0, 0, 0 },
		{ "triggerpass",           'm', &ChatHandler::HandleTriggerpassCheatCommand,                   IGNJREAAAAAA,			                                        NULL, 0, 0, 0 },
		{ NULL,		                0,  NULL,							                               "",		                                                        NULL, 0, 0, 0 },
	};
	dupe_command_table(CheatCommandTable, _CheatCommandTable);

	static ChatCommand accountCommandTable[] =
	{
		{ "ban",	               'a', &ChatHandler::HandleAccountBannedCommand,	                   BANACAUNTSAA,			                                        NULL, 0, 0, 0 },
		{ "unban",	               'z', &ChatHandler::HandleAccountUnbanCommand,	                   UNBANACCAUNA,			                                        NULL, 0, 0, 0 },
		{ "lvl",	               'z', &ChatHandler::HandleAccountLevelCommand,	                   SETSGMSLEVEA,			                                        NULL, 0, 0, 0 },
		{ "mute",	               'a', &ChatHandler::HandleAccountMuteCommand,	                       MYTERACAUNTA,			                                        NULL, 0, 0, 0 },
		{ "unmute",	               'a', &ChatHandler::HandleAccountUnmuteCommand,	                   UNMUTESACCAA,			                                        NULL, 0, 0, 0 },
		{ NULL,		                0,  NULL,										                   "",										            			NULL, 0, 0, 0 },
	};
	dupe_command_table(accountCommandTable, _accountCommandTable);

	static ChatCommand honorCommandTable[] =
	{
		{ "addpoints",			   'm', &ChatHandler::HandleAddHonorCommand,						   ADDSXAMOUTAA,			                                        NULL, 0, 0, 0 },
		{ "addkills",			   'm', &ChatHandler::HandleAddKillCommand,						       HONERSADDSAA,			                                        NULL, 0, 0, 0 },
		{ "globaldailyupdate",	   'm', &ChatHandler::HandleGlobalHonorDailyMaintenanceCommand,	       DAILYHONERSA,			                                        NULL, 0, 0, 0 },
		{ "singledailyupdate",	   'm', &ChatHandler::HandleNextDayCommand,						       DAILYSAPOINA,			                                        NULL, 0, 0, 0 },
		{ "pvpcredit",			   'm', &ChatHandler::HandlePVPCreditCommand,					       SENTSPVPSAAA,			                                        NULL, 0, 0, 0 },
		{ NULL,					    0,  NULL,		       										       "",			     							     				NULL, 0, 0, 0 },
	};
	dupe_command_table(honorCommandTable, _honorCommandTable);

	static ChatCommand petCommandTable[] = 
	{
		{ "createpet",		       'm', &ChatHandler::HandleCreatePetCommand,		                   CREATESPETAA,			                                        NULL, 0, 0, 0 },
		{ "renamepet",		       'm', &ChatHandler::HandleRenamePetCommand,		                   PETTONAMESAA,			                                        NULL, 0, 0, 0 },
		{ "addspell",		       'm', &ChatHandler::HandleAddPetSpellCommand,	                       TEACHESPETAA,			                                        NULL, 0, 0, 0 },
		{ "removespell",	       'm', &ChatHandler::HandleRemovePetSpellCommand,                	   PESSPELLAAAA,			                                        NULL, 0, 0, 0 },
		{ NULL,				        0,  NULL,										                   "",								                                NULL, 0, 0, 0 },
	};
	dupe_command_table(petCommandTable, _petCommandTable);

	static ChatCommand recallCommandTable[] =
	{
		{ "list",		           'q', &ChatHandler::HandleRecallListCommand,			               LISTAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "port",		           'q', &ChatHandler::HandleRecallGoCommand,		          	       PORTAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "add",	 	           'q', &ChatHandler::HandleRecallAddCommand,			               AADAAAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "del",		           'q', &ChatHandler::HandleRecallDelCommand,			               LOCALAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "portplayer",	           'm', &ChatHandler::HandleRecallPortPlayerCommand,	               PORTSAAAAAAA,			                                        NULL, 0, 0, 0 },
		{ NULL,			            0,  NULL,										            	   "",									                            NULL, 0, 0, 0 },
	};
	dupe_command_table(recallCommandTable, _recallCommandTable);

	static ChatCommand questCommandTable[] =
	{
		{ "addboth",               '2', &ChatHandler::HandleQuestAddBothCommand,                 	   ADDSQUOSTAAA,			                                        NULL, 0, 0, 0 },
		{ "addfinish",             '2', &ChatHandler::HandleQuestAddFinishCommand,	            	   IDADDSAAAAAA,			                                        NULL, 0, 0, 0 },
		{ "addstart",              '2', &ChatHandler::HandleQuestAddStartCommand,	            	   NPSASQUSTAAA,			                                        NULL, 0, 0, 0 },
		{ "delboth",               '2', &ChatHandler::HandleQuestDelBothCommand,            	 	   DELETERSIDAA,			                                        NULL, 0, 0, 0 },
		{ "delfinish",             '2', &ChatHandler::HandleQuestDelFinishCommand,	            	   FINISHERSTAA,			                                        NULL, 0, 0, 0 },
		{ "delstart",              '2', &ChatHandler::HandleQuestDelStartCommand,	            	   ZDELETESARAA,			                                        NULL, 0, 0, 0 },
		{ "complete",              '2', &ChatHandler::HandleQuestFinishCommand,		            	   COMPILESDFIA,			                                        NULL, 0, 0, 0 },
		{ "finisher",              '2', &ChatHandler::HandleQuestFinisherCommand,	            	   LOOTERSAAAAA,			                                        NULL, 0, 0, 0 },
		{ "item",	               '2', &ChatHandler::HandleQuestItemCommand,		            	   ITEMSALOOTSA,			                                        NULL, 0, 0, 0 },
		{ "list",	               '2', &ChatHandler::HandleQuestListCommand,		            	   LIKSTBEHECYA,			                                        NULL, 0, 0, 0 },
		{ "load",	               '2', &ChatHandler::HandleQuestLoadCommand,		            	   LOTSRTWFRAAA,			                                        NULL, 0, 0, 0 },
		{ "lookup",	               '2', &ChatHandler::HandleQuestLookupCommand,		            	   ZLOOTSZUPSAA,			                                        NULL, 0, 0, 0 },
		{ "giver",	               '2', &ChatHandler::HandleQuestGiverCommand,		            	   LOOTSKUPAAAA,			                                        NULL, 0, 0, 0 },
		{ "remove",	               '2', &ChatHandler::HandleQuestRemoveCommand,		            	   REMASYTSSDQA,			                                        NULL, 0, 0, 0 },
		{ "reward",	               '2', &ChatHandler::HandleQuestRewardCommand,		            	   SHOUSTASAAAA,			                                        NULL, 0, 0, 0 },
		{ "status",	               '2', &ChatHandler::HandleQuestStatusCommand,		            	   LISTSTHEZAAA,			                                        NULL, 0, 0, 0 },
		{ "spawn",	               '2', &ChatHandler::HandleQuestSpawnCommand,		            	   ZAPORTSAZAAA,			                                        NULL, 0, 0, 0 },
		{ "start",	               '2', &ChatHandler::HandleQuestStartCommand,		            	   STARTSZQUSPA,			                                        NULL, 0, 0, 0 },
		{ NULL,		                0,  NULL,										            	   "",									 			  	   	        NULL, 0, 0, 0 },
	};
	dupe_command_table(questCommandTable, _questCommandTable);

	static ChatCommand commandTable[] =
    {
		{ "masssummon",            'z', &ChatHandler::HandleMassSummonCommand,                         MASSSISUMONA,                                                    NULL, 0, 0, 0 },
		{ "commands",	           '0', &ChatHandler::HandleCommandsCommand,		                   SHORWSCOMMSA,			                                        NULL, 0, 0, 0 },
		{ "help",		           '0', &ChatHandler::HandleHelpCommand,		                       FORHEALCOMSA,			                                        NULL, 0, 0, 0 },
		{ "announce",	           'u', &ChatHandler::HandleAnnounceCommand,	                       SENDSAGMSGSA,			                                        NULL, 0, 0, 0 },
		{ "wannounce",             'u', &ChatHandler::HandleWAnnounceCommand,	                       SENTSMSGALLA,			                                        NULL, 0, 0, 0 },
		{ "appear",	               'v', &ChatHandler::HandleAppearCommand,		                       TELEPWRTSALA,			                                        NULL, 0, 0, 0 },
		{ "summon",	               'v', &ChatHandler::HandleSummonCommand,		                       SUMMONTSALLA,			                                        NULL, 0, 0, 0 },
		{ "banchar",	           'b', &ChatHandler::HandleBanCharacterCommand,                       BANSCHARACTA,			                                        NULL, 0, 0, 0 },
		{ "unbanchar",             'b', &ChatHandler::HandleUnBanCharacterCommand,                     UNBATSCAHARA,			                                        NULL, 0, 0, 0 },
		{ "kick",		           'b', &ChatHandler::HandleKickCommand,		                       KIKSTPLAYERA,			                                        NULL, 0, 0, 0 },
		{ "kill",		           'r', &ChatHandler::HandleKillCommand,		                       SELESTERSALA,			                                        NULL, 0, 0, 0 },
		{ "killplr" ,              'r', &ChatHandler::HandleKillByPlrCommand,                          KILLALLHAMRA,			                                        NULL, 0, 0, 0 },
		{ "revive",	               'r', &ChatHandler::HandleReviveCommand,		                       REVIRESYOUSA,			                                        NULL, 0, 0, 0 },
		{ "reviveplr",             'r', &ChatHandler::HandleReviveStringcommand,                       REVIRESYOUFA,			                                        NULL, 0, 0, 0 },
		{ "demorph",	           'm', &ChatHandler::HandleDeMorphCommand,	                           DEROSBEYFGRA,			                                        NULL, 0, 0, 0 },
		{ "mount",	               'm', &ChatHandler::HandleMountCommand,		                       MOUNTSINFOSA,			                                        NULL, 0, 0, 0 },
		{ "dismount",	           'h', &ChatHandler::HandleDismountCommand,	                       CEUIDNRTSYRA,			                                        NULL, 0, 0, 0 },
		{ "gm",		               '0', &ChatHandler::HandleGMListCommand,		                       SHOURSACTIVA,			                                        NULL, 0, 0, 0 },
		{ "gmoff",	               't', &ChatHandler::HandleGMOffCommand,	 	                       STERTSBHJTRA,			                                        NULL, 0, 0, 0 },
		{ "gmon",		           't', &ChatHandler::HandleGMOnCommand,		                       SETSAGMSAONA,			                                        NULL, 0, 0, 0 },
		{ "gps",		           '0', &ChatHandler::HandleGPSCommand,		                           POSITIONALLA,			                                        NULL, 0, 0, 0 },
		{ "info",	               '0', &ChatHandler::HandleInfoCommand,		                       SREVERINFOSA,			                                        NULL, 0, 0, 0 },
		{ "worldport",             'v', &ChatHandler::HandleWorldPortCommand,	                       WORLDSAPORTA,			                                        NULL, 0, 0, 0 },
		{ "save",		           's', &ChatHandler::HandleSaveCommand,		                       SAVESACHARAA,			                                        NULL, 0, 0, 0 },
		{ "saveall",         	   'z', &ChatHandler::HandleSaveAllCommand,	                           ALLSACHARACA,			                                        NULL, 0, 0, 0 },
		{ "start",	               'm', &ChatHandler::HandleStartCommand,		                       TELEPORTSALA,			                                        NULL, 0, 0, 0 },
		{ "additem",	           'm', &ChatHandler::HandleAddInvItemCommand,                    	   ADDITEMSALLA,			                                        NULL, 0, 0, 0 },
		{ "removeitem",            'm', &ChatHandler::HandleRemoveItemCommand,	                       REMOSALLSSSA,			                                        NULL, 0, 0, 0 },
		{ "invincible",            'j', &ChatHandler::HandleInvincibleCommand,	                       INVESIAYOUAA,			                                        NULL, 0, 0, 0 },
		{ "invisible",             'i', &ChatHandler::HandleInvisibleCommand,	                       TOFSDGSDSFSA,			                                        NULL, 0, 0, 0 },
		{ "resetreputation",       'n', &ChatHandler::HandleResetReputationCommand,                    STATRSALLSAA,			                                        NULL, 0, 0, 0 },
		{ "resetspells",           'n', &ChatHandler::HandleResetSpellsCommand,                        DANGEROUSAAA,			                                        NULL, 0, 0, 0 },
		{ "resettalents",          'n', &ChatHandler::HandleResetTalentsCommand,                       ZDANGEROUSZA,			                                        NULL, 0, 0, 0 },
		{ "resetskills",           'n', &ChatHandler::HandleResetSkillsCommand ,                       SKILSAZALLSA,			                                        NULL, 0, 0, 0 },
		{ "learn",	               'm', &ChatHandler::HandleLearnCommand,		                       SPELSSALLSSA,			                                        NULL, 0, 0, 0 },
		{ "unlearn",	           'm', &ChatHandler::HandleUnlearnCommand,	                           UPLEDHASPELA,			                                        NULL, 0, 0, 0 },
		{ "getskilllevel",         'm', &ChatHandler::HandleGetSkillLevelCommand,                      ZAGETSALLSSA,			                                        NULL, 0, 0, 0 }, 
        { "getskillinfo",          'm', &ChatHandler::HandleGetSkillsInfoCommand,                      ZAPLAYERTSSA,			                                        NULL, 0, 0, 0 },
		{ "learnskill",            'm', &ChatHandler::HandleLearnSkillCommand,	                       ZAOPTIONALSA,			                                        NULL, 0, 0, 0 },
		{ "advanceskill",          'm', &ChatHandler::HandleModifySkillCommand,                        ADSPIIOAAAHA,			                                        NULL, 0, 0, 0 },
		{ "removeskill",           'm', &ChatHandler::HandleRemoveSkillCommand,                        REMOVSRAALLA,			                                        NULL, 0, 0, 0 },
		{ "increaseweaponskill",   'm', &ChatHandler::HandleIncreaseWeaponSkill,                       DARACTERTSAA,			                                        NULL, 0, 0, 0 },
		{ "playerinfo",            'm', &ChatHandler::HandlePlayerInfo,		                           CHATACTERTSA,			                                        NULL, 0, 0, 0 },
		{ "modify",		           'm', NULL,									                       MODIFYALLLSA,				                      modifyCommandTable, 0, 0, 0 },
		{ "waypoint",	           'w', NULL,									                       WAYPOINSALLA,			                        waypointCommandTable, 0, 0, 0 },
		{ "debug",		           'd', NULL,									                       ZDEGINALLSLA,			                           debugCommandTable, 0, 0, 0 },
		{ "gmTicket",	           'c', NULL,			                       						   ZGMTICKETSSA,			                        GMTicketCommandTable, 0, 0, 0 },
		{ "gobject",	           'o', NULL,									                       GOZOMBETHKAA,			                      GameObjectCommandTable, 0, 0, 0 },
		{ "battleground",          'e', NULL,									                       ZPBALLESALLA,		                        BattlegroundCommandTable, 0, 0, 0 },
		{ "npc",                   'n', NULL,									                       ZZZAAAAAAZZA,					                     NPCCommandTable, 0, 0, 0 },
		{ "cheat",                 'm', NULL,									                       ZAAAAAAAAAAA,				                       CheatCommandTable, 0, 0, 0 },
		{ "account",               'a', NULL,								                       	   ACCOUNTSALLA,				                     accountCommandTable, 0, 0, 0 },
		{ "honor",                 'm', NULL,									                       HONERSALLSSA, 			                           honorCommandTable, 0, 0, 0 },
		{ "quest",		           'q', NULL,									                       ALLSQUSTIONA,				                       questCommandTable, 0, 0, 0 },
		{ "pet",		           'm', NULL,									                       SSPOIUYTRQXA,					                     petCommandTable, 0, 0, 0 },
		{ "recall",		           'q', NULL,									                       RACALLSALLSA,			                          recallCommandTable, 0, 0, 0 },
		{ "guild",		           'm', NULL,									                       ZGINGSALLSSA,				                       GuildCommandTable, 0, 0, 0 },
		{ "title",		           'm', NULL,									                       TITLSALLAAAA,			                           TitleCommandTable, 0, 0, 0 },
		{ "getpos"	  ,            'd', &ChatHandler::HandleGetPosCommand,	                           GETPOINTSAAA,	      		                                    NULL, 0, 0, 0 },
		{ "clearcooldowns",        'm', &ChatHandler::HandleClearCooldownsCommand,                     CLIEAALLAAAA,                                                    NULL, 0, 0, 0 },
		{ "removeauras",           'm', &ChatHandler::HandleRemoveAurasCommand,                        FROMSALLSAAA,                                                    NULL, 0, 0, 0 },
		{ "paralyze",	           'b', &ChatHandler::HandleParalyzeCommand,	                       ZROOMSTAAAAA,                        	                        NULL, 0, 0, 0 },
		{ "unparalyze",            'b', &ChatHandler::HandleUnParalyzeCommand,                         TARGERSAAAAA,                                                    NULL, 0, 0, 0 },
		{ "setmotd",	           'm', &ChatHandler::HandleSetMotdCommand,	                           MOTDAAAAAAAA,    			                                    NULL, 0, 0, 0 },
		{ "additemset",	           'm', &ChatHandler::HandleAddItemSetCommand,	                       ADDSKALISTSA,	                                                NULL, 0, 0, 0 },
		{ "gotrig",		           'v', &ChatHandler::HandleTriggerCommand,	                           WAPRPISAAAAA,	                                                NULL, 0, 0, 0 },
		{ "exitinstance",          'm', &ChatHandler::HandleExitInstanceCommand,                       ZEXITSRTAAAA,                                                    NULL, 0, 0, 0 },
		{ "reloadtable",	       'm', &ChatHandler::HandleDBReloadCommand,	                       TABLESTOSAAA,                                                    NULL, 0, 0, 0 },
		{ "shutdown",              'z', &ChatHandler::HandleShutdownCommand,                           SECONTSLSAAA,                                                    NULL, 0, 0, 0 },
		{ "restart",               'z', &ChatHandler::HandleShutdownRestartCommand,                    ZAPFOCSUPALA,                                                    NULL, 0, 0, 0 },
		{ "allowwhispers",         'c', &ChatHandler::HandleAllowWhispersCommand,                      ALLSIPSKAIAA,                                                    NULL, 0, 0, 0 },
		{ "blockwhispers",         'c', &ChatHandler::HandleBlockWhispersCommand,                      BLOCKSASDAAA,                                                    NULL, 0, 0, 0 },
		{ "advanceallskills",      'm', &ChatHandler::HandleAdvanceAllSkillsCommand,                   ZLADLSDLLAAA,                                                    NULL, 0, 0, 0 },
		{ "killbyplayer",          'f', &ChatHandler::HandleKillByPlayerCommand,                       DISCANECTSAA,                                                    NULL, 0, 0, 0 },
		{ "killbyaccount",         'f', &ChatHandler::HandleKillBySessionCommand,                      DISCONECTSAA,                                                    NULL, 0, 0, 0 },
		{ "castall",               'z', &ChatHandler::HandleCastAllCommand,                            ZAMAKESAAAAA,                                                    NULL, 0, 0, 0 },
		{ "dispelall",             'z', &ChatHandler::HandleDispelAllCommand,                          DISASPELLSAA,                                                    NULL, 0, 0, 0 },
		{ "castspell",             'd', &ChatHandler::HandleCastSpellCommand,	                       CASTSAONAAAA,                                                    NULL, 0, 0, 0 },
		{ "modperiod" ,            'm', &ChatHandler::HandleModPeriodCommand,                          CHANGWRSAAAA,                                                    NULL, 0, 0, 0 },
		{ "npcfollow",             'm', &ChatHandler::HandleNpcFollowCommand,                          SETSAYOUAAAA,                                                    NULL, 0, 0, 0 },
		{ "nullfollow",            'm', &ChatHandler::HandleNullFollowCommand,                         SETSANPSANOA,                                                    NULL, 0, 0, 0 },
		{ "formationlink1",        'm', &ChatHandler::HandleFormationLink1Command,                     FORAMASTERSA,                                                    NULL, 0, 0, 0 },
		{ "formationlink2",        'm', &ChatHandler::HandleFormationLink2Command,                     ANGLEANOTSAA,                                                    NULL, 0, 0, 0 },
		{ "formationclear",        'm', &ChatHandler::HandleFormationClearCommand,                     CREATIVEARAA,                                                    NULL, 0, 0, 0 },
		{ "playall",               'z', &ChatHandler::HandleGlobalPlaySoundCommand,                    PLAYSAAZAAAA,                                                    NULL, 0, 0, 0 },
		{ "addipban",              'm', &ChatHandler::HandleIPBanCommand,                              TIAADDSAAAAA,                                                    NULL, 0, 0, 0 },
		{ "delipban",              'm', &ChatHandler::HandleIPUnBanCommand,                            DELETESTAAAA,                                                    NULL, 0, 0, 0 },
		{ "renamechar",            'm', &ChatHandler::HandleRenameCommand,                             REHAMESAAAAA,                                                    NULL, 0, 0, 0 },
		{ "forcerenamechar",       'm', &ChatHandler::HandleForceRenameCommand,                        NEXTSALOGINA,                                                    NULL, 0, 0, 0 },
		{ "getstanding",           'm', &ChatHandler::HandleGetStandingCommand,                        AFACTERTDGSA,                                                    NULL, 0, 0, 0 },
		{ "setstanding",           'm', &ChatHandler::HandleSetStandingCommand,                        STARTSRTYUEA,                                                    NULL, 0, 0, 0 },
		{ "lookupitem",            'l', &ChatHandler::HandleLookupItemCommand,                         XAUPLAATSSSA,                                                    NULL, 0, 0, 0 },
		{ "lookupquest",           'l', &ChatHandler::HandleQuestLookupCommand,                        HALAATSRSAAA,                                                    NULL, 0, 0, 0 },
		{ "lookupcreature",        'l', &ChatHandler::HandleLookupCreatureCommand,                     ITEMSAAAAAAA,                                                    NULL, 0, 0, 0 },
		{ "rehash",                'z', &ChatHandler::HandleRehashCommand,                             RELAADSACANA,                                                    NULL, 0, 0, 0 },
		{ "createarenateam",       'g', &ChatHandler::HandleCreateArenaTeamCommands,                   AREANAATEAMA,                                                    NULL, 0, 0, 0 },
		{ "whisperblock",          'g', &ChatHandler::HandleWhisperBlockCommand,                       AGMONAAAAAAA,                                                    NULL, 0, 0, 0 },
		{ "logcomment" ,           '1' , &ChatHandler::HandleGmLogCommentCommand,                      READAADDAAAA,                                                    NULL, 0, 0, 0 },
		{ "showitems",             'm', &ChatHandler::HandleShowItems,                                 TETSAITEMSAA,                                                    NULL, 0, 0, 0 },
		{ "testlos",               'm', &ChatHandler::HandleCollisionTestLOS,                          TETSALASAAAA,                                                    NULL, 0, 0, 0 },
		{ "testindoor",            'm', &ChatHandler::HandleCollisionTestIndoor,                       TETSAINDAARA,                                                    NULL, 0, 0, 0 },
		{ "getheight",             'm', &ChatHandler::HandleCollisionGetHeight,                        GETSAHEAGHTA,                                                    NULL, 0, 0, 0 },
		{ "renameallinvalidchars", 'z', &ChatHandler::HandleRenameAllCharacter,                        ALLSAAAAAAAA,                                                    NULL, 0, 0, 0 },
		{ "removesickness",        'm', &ChatHandler::HandleRemoveRessurectionSickessAuraCommand,      FROMAFROMSAA,                                                    NULL, 0, 0, 0 },
		{ "fixscale",              'm', &ChatHandler::HandleFixScaleCommand,                           FIXSCALESAAA,                                                    NULL, 0, 0, 0 },
		{ "addtrainerspell",       'm', &ChatHandler::HandleAddTrainerSpellCommand,                    ADDTARAINERA,                                                    NULL, 0, 0, 0 },
		{ "clearcorpses",          'm', &ChatHandler::HandleClearCorpsesCommand,                       CLEARACASKAA,                                                    NULL, 0, 0, 0 },
		{ "clearbones",            'm', &ChatHandler::HandleClearBonesCommand,                         FIJIGIFWEVWA,                                                    NULL, 0, 0, 0 },
		{ "multimute",             'b', &ChatHandler::HandleMultiMuteCommand,                          MUTESMILLTIA,                                                    NULL, 0, 0, 0 },
		{ "multiban",              'b', &ChatHandler::HandleMultiBanCommand,                           ZXBATSMUTLLA,                                                    NULL, 0, 0, 0 },
		{ "multiaccountban",       'b', &ChatHandler::HandleMultiAccountBanCommand,                    ACCAUNTSRADA,                                                    NULL, 0, 0, 0 },
		{ "multikick",             'b', &ChatHandler::HandleMultiKickCommand,                          KIKKSAAAAAAA,                                                    NULL, 0, 0, 0 },
	    { NULL,		                0,  NULL,	                                                       "",							                                    NULL, 0, 0  }
	};
	dupe_command_table(commandTable, _commandTable);

	/* set the correct pointers */
	ChatCommand * p = &_commandTable[0];
	while(p->Name != 0)
	{
		if(p->ChildCommands != 0)
		{
			// Set the correct pointer.
			ChatCommand * np = GetSubCommandTable(p->Name);
			ASSERT(np);
			p->ChildCommands = np;
		}
		++p;
	}
}

ChatHandler::ChatHandler()
{
	new CommandTableStorage;
	CommandTableStorage::getSingleton().Init();
	SkillNameManager = new SkillNameMgr;
}

ChatHandler::~ChatHandler()
{
	CommandTableStorage::getSingleton().Dealloc();
	delete CommandTableStorage::getSingletonPtr();
	delete SkillNameManager;
}

bool ChatHandler::hasStringAbbr(const char* s1, const char* s2)
{
	for(;;)
	{
		if( !*s2 )
			return true;
		else if( !*s1 )
			return false;
		else if( tolower( *s1 ) != tolower( *s2 ) )
			return false;
		s1++; s2++;
	}
}

void ChatHandler::SendMultilineMessage(WorldSession *m_session, const char *str)
{
	char * start = (char*)str, *end;
	for(;;)
	{
        end = strchr(start, '\n');
		if(!end)
			break;

		*end = '\0';
		SystemMessage(m_session, start);
		start = end + 1;
	}
	if(*start != '\0')
		SystemMessage(m_session, start);
}

bool ChatHandler::ExecuteCommandInTable(ChatCommand *table, const char* text, WorldSession *m_session)
{
	std::string cmd = "";

	// get command
	while (*text != ' ' && *text != '\0')
	{
		cmd += *text;
		text++;
	}

	while (*text == ' ') text++; // skip whitespace

	if(!cmd.length())
		return false;

	for(uint32 i = 0; table[i].Name != NULL; i++)
	{
		if(!hasStringAbbr(table[i].Name, cmd.c_str()))
			continue;

		if(table[i].CommandGroup != '0' && !m_session->CanUseCommand(table[i].CommandGroup))
			continue;

		if(table[i].ChildCommands != NULL)
		{
			if(!ExecuteCommandInTable(table[i].ChildCommands, text, m_session))
			{
				if(table[i].Help != "")
					SendMultilineMessage(m_session, table[i].Help.c_str());
				else
				{
					GreenSystemMessage(m_session, AVAILABLEASUA);
					for(uint32 k=0; table[i].ChildCommands[k].Name;k++)
					{
						if(table[i].ChildCommands[k].CommandGroup != '0' && m_session->CanUseCommand(table[i].ChildCommands[k].CommandGroup))
							BlueSystemMessage(m_session, " %s - %s", table[i].ChildCommands[k].Name, table[i].ChildCommands[k].Help.size() ? table[i].ChildCommands[k].Help.c_str() : "No Help Available");
					}
				}
			}

			return true;
		}
		
		// Check for field-based commands
		if(table[i].Handler == NULL && (table[i].MaxValueField || table[i].NormalValueField))
		{
			bool result = false;
			if(strlen(text) == 0)
			{
				RedSystemMessage(m_session, NOAVALUESASPA);
			}
			if(table[i].ValueType == 2)
				result = CmdSetFloatField(m_session, table[i].NormalValueField, table[i].MaxValueField, table[i].Name, text);
			else if(table[i].ValueType == 3)
			{
				result = true;
				if( m_session->GetPlayer()->m_GM_SelectedGO != NULL )
					m_session->GetPlayer()->m_GM_SelectedGO->SetUInt32Value(table[i].NormalValueField, atoi(text));
				else
					result = false;
			}
			else
				result = CmdSetValueField(m_session, table[i].NormalValueField, table[i].MaxValueField, table[i].Name, text);

			if(!result)
				RedSystemMessage(m_session, CHAGGINGACOAA);
		}
		else
		{
			if(!(this->*(table[i].Handler))(text, m_session))
			{
				if(table[i].Help != "")
					SendMultilineMessage(m_session, table[i].Help.c_str());
				else
				{
					RedSystemMessage(m_session, INCORRECTASYA, table[i].Name);
				}
			}
		}

		return true;
	}
	return false;
}

int ChatHandler::ParseCommands(const char* text, WorldSession *session)
{
	if (!session)
		return 0;

	if(!*text)
		return 0;

	if(session->GetPermissionCount() == 0 && sWorld.m_reqGmForCommands)
		return 0;

	if(text[0] != '!' && text[0] != '.') // let's not confuse users
		return 0;

	/* skip '..' :P that pisses me off */
	if(text[1] == '.')
		return 0;

	text++;

	if(!ExecuteCommandInTable(CommandTableStorage::getSingleton().Get(), text, session))
	{
		SystemMessage(session, THEREAISANOAA);
	}

	return 1;
}

WorldPacket * ChatHandler::FillMessageData( uint32 type, int32 language, const char *message,uint64 guid , uint8 flag) const
{
	// Packet   structure
	// uint8    type;
	// uint32	language;
	// uint64	guid;
	// uint64	guid;
	// uint32	len_of_text;
	// char	    text[];		 // not sure ? i think is null terminated .. not null terminated
	// uint8	afk_state;
	
	ASSERT(type != CHAT_MSG_CHANNEL);
	   //channels are handled in channel handler and so on
	uint32 messageLength = (uint32)strlen((char*)message) + 1;

	WorldPacket *data = new WorldPacket(SMSG_MESSAGECHAT, messageLength + 30);

	*data << (uint8)type;
	*data << language;

	*data << guid;
	*data << uint32(0);

	*data << guid;

	*data << messageLength;
	*data << message;

	*data << uint8(flag);
	return data;
}

WorldPacket* ChatHandler::FillSystemMessageData(const char *message) const
{
	uint32 messageLength = (uint32)strlen((char*)message) + 1;

	WorldPacket * data = new WorldPacket(SMSG_MESSAGECHAT, 30 + messageLength);
	*data << (uint8)CHAT_MSG_SYSTEM;
	*data << (uint32)LANG_UNIVERSAL;
	
	*data << (uint64)0; // Who cares about guid when there's no nickname displayed heh ?
	*data << (uint32)0;
	*data << (uint64)0;

	*data << messageLength;
	*data << message;

	*data << uint8(0);

	return data;
}

PlayerPointer ChatHandler::getSelectedChar(WorldSession *m_session, bool showerror)
{
	uint64 guid;
	PlayerPointer chr;


	if (!m_session || !m_session->GetPlayer()) return NULLPLR;

	guid = m_session->GetPlayer()->GetSelection();
	
	if (guid == 0)
	{
		if(showerror) 
			GreenSystemMessage(m_session, AUTOATARGETIA);
		chr = m_session->GetPlayer(); // autoselect
	}
	else
		chr = m_session->GetPlayer()->GetMapMgr()->GetPlayer((uint32)guid);
	
	if(chr == NULL)
	{
		if(showerror) 
			RedSystemMessage(m_session, THISACOMMANDA);
		return NULLPLR;
	}

	return chr;
}

CreaturePointer ChatHandler::getSelectedCreature(WorldSession *m_session, bool showerror)
{
	uint64 guid;
	CreaturePointer creature = NULLCREATURE;
	
	if (!m_session || !m_session->GetPlayer()) return NULLCREATURE;

	guid = m_session->GetPlayer()->GetSelection();
	if(GET_TYPE_FROM_GUID(guid) == HIGHGUID_TYPE_PET)
		creature = m_session->GetPlayer()->GetMapMgr()->GetPet( GET_LOWGUID_PART(guid) );
	else if(GET_TYPE_FROM_GUID(guid) == HIGHGUID_TYPE_UNIT)
		creature = m_session->GetPlayer()->GetMapMgr()->GetCreature( GET_LOWGUID_PART(guid) );
	else if(GET_TYPE_FROM_GUID(guid) == HIGHGUID_TYPE_VEHICLE)
		creature = m_session->GetPlayer()->GetMapMgr()->GetVehicle( GET_LOWGUID_PART(guid) );
	
	if(creature != NULL)
		return creature;
	else
	{
		if(showerror) 
			RedSystemMessage(m_session, THISACAMMANDA);
		return NULLCREATURE;
	}
}

void ChatHandler::SystemMessage(WorldSession *m_session, const char* message, ...)
{
	if( !message ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024, message,ap);
	WorldPacket * data = FillSystemMessageData(msg1);
	if(m_session != NULL) 
		m_session->SendPacket(data);
	delete data;
}

void ChatHandler::ColorSystemMessage(WorldSession *m_session, const char* colorcode, const char *message, ...)
{
	if( !message ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024, message,ap);
	char msg[1024];
	snprintf(msg, 1024, "%s%s|r", colorcode, msg1);
	WorldPacket * data = FillSystemMessageData(msg);
	if(m_session != NULL) 
		m_session->SendPacket(data);
	delete data;
}

void ChatHandler::RedSystemMessage(WorldSession *m_session, const char *message, ...)
{
	if( !message ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024,message,ap);
	char msg[1024];
	snprintf(msg, 1024,"%s%s|r", MSG_COLOR_LIGHTRED/*MSG_COLOR_RED*/, msg1);
	WorldPacket * data = FillSystemMessageData(msg);
	if(m_session != NULL) 
		m_session->SendPacket(data);
	delete data;
}

void ChatHandler::GreenSystemMessage(WorldSession *m_session, const char *message, ...)
{
	if( !message ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024, message,ap);
	char msg[1024];
	snprintf(msg, 1024, "%s%s|r", MSG_COLOR_GREEN, msg1);
	WorldPacket * data = FillSystemMessageData(msg);
	if(m_session != NULL) 
		m_session->SendPacket(data);
	delete data;
}

void ChatHandler::BlueSystemMessage(WorldSession *m_session, const char *message, ...)
{
	if( !message ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024, message,ap);
	char msg[1024];
	snprintf(msg, 1024,"%s%s|r", MSG_COLOR_LIGHTBLUE, msg1);
	WorldPacket * data = FillSystemMessageData(msg);
	if(m_session != NULL) 
		m_session->SendPacket(data);
	delete data;
}

void ChatHandler::RedSystemMessageToPlr(PlayerPointer plr, const char *message, ...)
{
	if( !message || !plr || !plr->GetSession() ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024,message,ap);
	RedSystemMessage(plr->GetSession(), (const char*)msg1);
}

void ChatHandler::GreenSystemMessageToPlr(PlayerPointer plr, const char *message, ...)
{
	if( !message || !plr || !plr->GetSession() ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024,message,ap);
	GreenSystemMessage(plr->GetSession(), (const char*)msg1);
}

void ChatHandler::BlueSystemMessageToPlr(PlayerPointer plr, const char *message, ...)
{
	if( !message || !plr || !plr->GetSession() ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024,message,ap);
	BlueSystemMessage(plr->GetSession(), (const char*)msg1);
}

void ChatHandler::SystemMessageToPlr(PlayerPointer plr, const char* message, ...)
{
	if( !message || !plr || !plr->GetSession() ) return;
	va_list ap;
	va_start(ap, message);
	char msg1[1024];
	vsnprintf(msg1,1024,message,ap);
	SystemMessage(plr->GetSession(), msg1);
}

bool ChatHandler::CmdSetValueField(WorldSession *m_session, uint32 field, uint32 fieldmax, const char *fieldname, const char *args)
{
	char* pvalue;
	uint32 mv, av;
	
	if(!args || !m_session) return false;

	pvalue = strtok((char*)args, " ");
	if (!pvalue)
		return false;
	else
		av = atol(pvalue);

	if(fieldmax)
	{
		char* pvaluemax = strtok(NULL, " ");   
		if (!pvaluemax)
			return false;  
		else
			mv = atol(pvaluemax);
	}
	else
	{
		mv = 0;
	}

	if (av <= 0 && mv > 0)
	{  
		RedSystemMessage(m_session, VALUESAAREAAA);
		return true;   
	}
	if(fieldmax)
	{
		if(mv < av || mv <= 0)
		{
			RedSystemMessage(m_session, VALUESAAREAAA);
			return true;  
		}
	}

	PlayerPointer plr = getSelectedChar(m_session, false);
	if(plr)
	{  
		sGMLog.writefromsession(m_session, USEDAMODAAAAA, fieldname, av, plr->GetName());
		if(fieldmax)
		{
			BlueSystemMessage(m_session, YOUASETATHEAA, fieldname, plr->GetName(), av, mv);
			GreenSystemMessageToPlr(plr, SETAYOURAAAAA, m_session->GetPlayer()->GetName(), fieldname, av, mv);
		}
		else
		{
			BlueSystemMessage(m_session, YOUASERATHEAA, fieldname, plr->GetName(), av);
			GreenSystemMessageToPlr(plr, SETAYOURSAAAA, m_session->GetPlayer()->GetName(), fieldname, av);
		}

		if(field == UNIT_FIELD_STAT1) av /= 2;
		if(field == UNIT_FIELD_BASE_HEALTH) 
		{
			plr->SetUInt32Value(UNIT_FIELD_HEALTH, av);
		}

		plr->SetUInt32Value(field, av);

		if(fieldmax) {
			plr->SetUInt32Value(fieldmax, mv);
		}
	}
	else
	{
		CreaturePointer cr = getSelectedCreature(m_session, false);
		if(cr)
		{
			if(!(field < UNIT_END && fieldmax < UNIT_END)) return false;
			std::string creaturename = UNKNOWNBEINGA;
			if(cr->GetCreatureName())
				creaturename = cr->GetCreatureName()->Name;
			if(fieldmax)
				BlueSystemMessage(m_session, SETTINGATOAAA, fieldname, creaturename.c_str(), av, mv);
			else
				BlueSystemMessage(m_session, SETTINGATAASA, fieldname, creaturename.c_str(), av);
			sGMLog.writefromsession(m_session, USEDAMODSAAAA, fieldname, av, creaturename.c_str());
			if(field == UNIT_FIELD_STAT1) av /= 2;
			if(field == UNIT_FIELD_BASE_HEALTH) 
				cr->SetUInt32Value(UNIT_FIELD_HEALTH, av);

			switch(field)
			{
			case UNIT_FIELD_FACTIONTEMPLATE:
				{
					if(cr->m_spawn)
						WorldDatabase.Execute("UPDATE creature_spawns SET faction = %u WHERE entry = %u", av, cr->m_spawn->entry);
				}break;
			case UNIT_NPC_FLAGS:
				{
					if(cr->proto)
						WorldDatabase.Execute("UPDATE creature_proto SET npcflags = %u WHERE entry = %u", av, cr->proto->Id);
				}break;
			}

			cr->SetUInt32Value(field, av);

			if(fieldmax) {
				cr->SetUInt32Value(fieldmax, mv);
			}
			// reset faction
			if(field == UNIT_FIELD_FACTIONTEMPLATE)
				cr->_setFaction();

			cr->SaveToDB();
		}
		else
		{
			RedSystemMessage(m_session, INVALEDESSELA);
		}
	}
	return true;
}

bool ChatHandler::CmdSetFloatField(WorldSession *m_session, uint32 field, uint32 fieldmax, const char *fieldname, const char *args)
{
	char* pvalue;
	float mv, av;
	
	if(!args || !m_session) return false;

	pvalue = strtok((char*)args, " ");
	if (!pvalue)
		return false;
	else
		av = (float)atof(pvalue);

	if(fieldmax)
	{
		char* pvaluemax = strtok(NULL, " ");   
		if (!pvaluemax)
			return false;  
		else
			mv = (float)atof(pvaluemax);
	}
	else
	{
		mv = 0;
	}

	if (av <= 0)
	{  
		RedSystemMessage(m_session, VALUESAAREAAA);
		return true;   
	}
	if(fieldmax)
	{
		if(mv < av || mv <= 0)
		{
			RedSystemMessage(m_session, VALUESAAREAAA);
			return true;  
		}
	}

	PlayerPointer plr = getSelectedChar(m_session, false);
	if(plr)
	{  
		sGMLog.writefromsession(m_session, USEDAMODAMODA, fieldname, av, plr->GetName());
		if(fieldmax)
		{
			BlueSystemMessage(m_session, YOUASERAAYOUA, fieldname, plr->GetName(), av, mv);
			GreenSystemMessageToPlr(plr, SETAYOURSALIA, m_session->GetPlayer()->GetName(), fieldname, av, mv);
		}
		else
		{
			BlueSystemMessage(m_session, SETAYOARSALAA, fieldname, plr->GetName(), av);
			GreenSystemMessageToPlr(plr, SETAYOURSALAA, m_session->GetPlayer()->GetName(), fieldname, av);
		}
		plr->SetFloatValue(field, av);
		if(fieldmax) plr->SetFloatValue(fieldmax, mv);
	}
	else
	{
		CreaturePointer cr = getSelectedCreature(m_session, false);
		if(cr)
		{
			if(!(field < UNIT_END && fieldmax < UNIT_END)) return false;
			std::string creaturename = UNKNOWNABEINA;
			if(cr->GetCreatureName())
				creaturename = cr->GetCreatureName()->Name;
			if(fieldmax)
				BlueSystemMessage(m_session, SETTINGATOSIA, fieldname, creaturename.c_str(), av, mv);
			else
				BlueSystemMessage(m_session, SETTINGATOASA, fieldname, creaturename.c_str(), av);
			cr->SetFloatValue(field, av);
			sGMLog.writefromsession(m_session, USEDAMODACREA, fieldname, av, creaturename.c_str());
			if(fieldmax) {
				cr->SetFloatValue(fieldmax, mv);
			}
			//cr->SaveToDB();
		}
		else
		{
			RedSystemMessage(m_session, INVALEDESAAAA);
		}
	}
	return true;
}

bool ChatHandler::HandleGetPosCommand(const char* args, WorldSession *m_session)
{
	if(!args || !m_session) return false;

	uint32 spell = atol(args);
	SpellEntry *se = dbcSpell.LookupEntry(spell);
	if(se)
		BlueSystemMessage(m_session, SPELLAICONAAA, se->Id, se->SpellIconID);
	return true;
}

bool ChatHandler::HandleDebugRetroactiveQuestAchievements(const char *args, WorldSession *m_session)
{
	PlayerPointer pTarget = getSelectedChar(m_session, true );
	if(!pTarget) return true;

	pTarget->RetroactiveCompleteQuests();
	m_session->GetPlayer()->BroadcastMessage(DONEAAAAAAAAA);
	return true;
}
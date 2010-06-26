/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"
#include <svn_revision.h>
#include "ConsoleCommands.h"

bool HandleInfoCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	uint32 clientsNum = (uint32)sWorld.GetSessionCount();

	int gm = 0;
	int count = 0;
	int avg = 0;
	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		if(itr->second->GetSession())
		{
			count++;
			avg += itr->second->GetSession()->GetLatency();
			if(itr->second->GetSession()->GetPermissionCount())
				gm++;
		}			
	}
	objmgr._playerslock.ReleaseReadLock();

	pConsole->Write("======================================================================\r\n");
	pConsole->Write(WOWSERVERINFOAI);
	pConsole->Write("======================================================================\r\n");
	pConsole->Write(SERVETRESRERVAI, BUILD_REVISION, CONFIG, PLATFORM_TEXT, ARCH);
	pConsole->Write(SERVERUPTITESAI, sWorld.GetUptimeString().c_str());
	pConsole->Write(CUNRREPLAYERSAI, clientsNum, gm,  0);
	pConsole->Write(ALLIANCRONLINAI,sWorld.AlliancePlayers);
	pConsole->Write(HORLEONLAINSDAI,sWorld.HordePlayers);
	pConsole->Write(CONNECTIONSPEAI, sWorld.PeakSessionCount);
	pConsole->Write(ACCEPTEDCONNEAI, sWorld.mAcceptedConnections);
	pConsole->Write(ACTIOVETHEADEAI, ThreadPool.GetActiveThreadCount());
	pConsole->Write(FREETHESCOUUSAI, ThreadPool.GetFreeThreadCount());
	pConsole->Write(AVIERAGESLATEAI, count ?  ((float)((float)avg / (float)count)) : 0.0f);
	pConsole->Write(SQLKAWOWCACKEAI, WorldDatabase.GetQueueSize());
	pConsole->Write(SQLKAWDSADSKEAI, CharacterDatabase.GetQueueSize());
	pConsole->Write("======================================================================\r\n\r\n");

	return true;
}

bool HandleGMsCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	WorldPacket data;
	//bool first = true;

	pConsole->Write(THEADREAREHTEAI);
	pConsole->Write("======================================================\r\n");
	pConsole->Write(MCSWOWARCTIZZAI, WOWARCTICNAMEAI, ZAPERMISTISFFAI, LATENCOWCACKEAI);
	pConsole->Write("======================================================\r\n");

	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		if(itr->second->GetSession()->GetPermissionCount())
		{
			pConsole->Write(MCSWOWARCTIZZAI , itr->second->GetName(), itr->second->GetSession()->GetPermissions(), itr->second->GetSession()->GetLatency());
		}
	}
	objmgr._playerslock.ReleaseReadLock();

	pConsole->Write("======================================================\r\n\r\n");
	return true;
}


void ConcatArgs(string & outstr, int argc, int startoffset, const char * argv[])
{
	for(int i = startoffset + 1; i < argc; ++i)
	{
		outstr += argv[i];
		if((i+1) != (argc))
			outstr += " ";
	}
}
bool HandleAnnounceCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	char pAnnounce[1024];
	string outstr;
	if(argc < 2)
		return false;

	ConcatArgs(outstr, argc, 0, argv);
	snprintf(pAnnounce, 1024, DASCONCOLEAAAAI, MSG_COLOR_LIGHTBLUE, outstr.c_str());
	sWorld.SendWorldText(pAnnounce); // send message
	pConsole->Write(MESSAGESENTSSAI);
	return true;
}

bool HandleWAnnounceCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	char pAnnounce[1024];
	string outstr;
	if(argc < 2)
		return false;

	ConcatArgs(outstr, argc, 0, argv);
	snprintf(pAnnounce, 1024, DASCONCOLEAAAAI, MSG_COLOR_LIGHTBLUE, outstr.c_str());
	sWorld.SendWorldWideScreenText(pAnnounce); // send message
	pConsole->Write(MESSAGESENTSSAI);
	return true;
}

bool HandleKickCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 3)
		return false;

	char pAnnounce[1024];
	PlayerPointer pPlayer;

	pPlayer = objmgr.GetPlayer(argv[1]);
	if( pPlayer == NULL )
	{
		pConsole->Write(ZCONLDSANOTSSAI, argv[1]);
		return true;
	}
	string outstr;
	ConcatArgs(outstr, argc, 1, argv);
	snprintf(pAnnounce, 1024, KIKLERCONSOLEAI, MSG_COLOR_LIGHTBLUE, pPlayer->GetName(), argv[2]);
	pPlayer->BroadcastMessage(ZCONLDSANOFSDAI, argv[2]);
	sWorld.SendWorldText(pAnnounce, NULL);
	pPlayer->Kick(5000);
	pConsole->Write(KIKLERCDSFSDEAI, pPlayer->GetName());
	return true;
}

bool HandleQuitCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	uint32 delay = 5;
	if(argc >= 2)
		delay = atoi(argv[1]);

	pConsole->Write(KIKLERCASDADEAI);
	sWorld.QueueShutdown(delay, SERVER_SHUTDOWN_TYPE_SHUTDOWN);
	return true;
}

bool HandleCancelCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write(STUTLESDOWNSDAI);
	sWorld.CancelShutdown();
	return true;
}

bool HandleUptimeCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	string up = sWorld.GetUptimeString();
	pConsole->Write(SERVERUPTITESAI, up.c_str());
	return true;
}

bool HandleBanAccountCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 4)
		return false;

	int32 timeperiod = GetTimePeriodFromString(argv[2]);
	if(timeperiod < 0)
		return false;

	uint32 banned = (timeperiod ? (uint32)UNIXTIME+timeperiod : 1);

	// apply instantly in db
	sLogonCommHandler.Account_SetBanned(argv[1], banned, argv[3]);

	pConsole->Write(FREETHESCOKUSAI, argv[1], 
		timeperiod ? SEVERSUNTILLSAI : WOWARCTICLOVEAI, timeperiod ? ConvertTimeStampToDataTime(timeperiod+(uint32)UNIXTIME).c_str() : "");
	
	return true;
}

bool HandleUnbanAccountCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 2)
		return false;

	sLogonCommHandler.Account_SetBanned(argv[1], 0, "");

	pConsole->Write(ZACCOUNTSSBEDAI, argv[1]);
	return true;
}

bool HandleCreateAccountCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 5)
		return false;

	const char * username = argv[1];
	const char * password = argv[2];
	const char * email = argv[3];

	if(strlen(username) == 0 || strlen(password) == 0 || strlen(email) == 0)
		return false;
	return true;
}

bool HandleMOTDCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 2)
	{
		pConsole->Write( THEAZCURRENTTAI, sWorld.GetMotd() );
	}else
	{
		char set_motd[1024];
		string outstr;
		ConcatArgs( outstr, argc, 0, argv );
		snprintf( set_motd, 1024, "%s", outstr.c_str() );

		sWorld.SetMotd( set_motd );
		pConsole->Write( THESMOTSHASDSAI, sWorld.GetMotd() );
	}
	return true;
}

bool HandlePlayerInfoCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 2)
		return false;

	PlayerPointer plr = objmgr.GetPlayer(argv[1]);
	if( plr == NULL )
	{
		pConsole->Write(WOWZPLAYERSAAAI);
		return true;
	}

	pConsole->Write(PLAYERSWOWSSSAI, plr->GetName());
	pConsole->Write(WOWRACEWOWSSSAI, plr->myRace->name1);
	pConsole->Write(WOWCLASSWOWAAAI, plr->myClass->name);
	pConsole->Write(IPIPIPIPIPIPIAI, plr->GetSession()->GetSocket() ? plr->GetSession()->GetSocket()->GetRemoteIP().c_str() : DICONNECTSSDDAI);
	pConsole->Write(WOWLVLWOWARCTAI, plr->getLevel());
	pConsole->Write(WOWACCUONSTSAAI, plr->GetSession()->GetAccountNameS());
	return true;
}

void TestConsoleLogin(string& username, string& password, uint32 requestno)
{
	sLogonCommHandler.TestConsoleLogon(username, password, requestno);
}

bool HandleRehashCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write(COUNETSDSDSDDAI);
	sWorld.Rehash(true);
	return true;
}

bool HandleBPStatsCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	g_bufferPool.Stats();
	return true;
}

bool HandleBackupDBCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	sWorld.BackupDB();
	return true;
}

bool HandleSaveAllCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	PlayerStorageMap::const_iterator itr;
	uint32 stime = now();
	uint32 count = 0;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		if(itr->second->GetSession())
		{
			itr->second->SaveToDB(false);
			count++;
		}
	}
	objmgr._playerslock.ReleaseReadLock();
	char msg[100];
	snprintf(msg, 100, ASVESALLSONLAAI, (int)count, int((uint32)now() - stime));
	sWorld.SendWorldText(msg);
	sWorld.SendWorldWideScreenText(msg);

	return true;
}
bool HandleWhisperCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	char pAnnounce[1024];
	PlayerPointer pPlayer;
	string outstr;

	if(argc < 3)
		return false;

	pPlayer = objmgr.GetPlayer(argv[1]);

	if( pPlayer == NULL )
	{
		pConsole->Write(ZCONLDSANOTSSAI, argv[1]);
		return true;
	}

	ConcatArgs(outstr, argc, 1, argv);
	snprintf(pAnnounce, 1024, MESSAGESENTKJAI, MSG_COLOR_MAGENTA, outstr.c_str());

	pPlayer->BroadcastMessage(pAnnounce);
	pConsole->Write(MESSAGESENTPOAI, pPlayer->GetName());
	return true;
}
bool HandleNameHashCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if( !argc )
		return false;
	string spstring;
		ConcatArgs(spstring, argc, 0, argv);
	uint32 spellid = (int)atoi((char*)spstring.c_str());
	SpellEntry * sp = dbcSpell.LookupEntryForced(spellid);
	if ( !sp )
	{
		pConsole->Write( SPELLWOWCOLIEAI, spellid );
		return true;
	}
	else
	{
		pConsole->Write( NAMEHASTFORSSAI, sp->Id, sp->Name , uLong(sp->NameHash));
		return true;
	}
}
bool HandleOnlinePlayersCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	WorldPacket data;
	//bool first = true;

	pConsole->Write(TRENAFOLLOMMMAI);
	pConsole->Write("======================================================\r\n");
	pConsole->Write(MCSWOWARCTIZZAI, ARCTICWOWNAMEAI, LEVELWOWARCTIAI, LATEENCESWOWWAI);
	pConsole->Write("======================================================\r\n");

	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		pConsole->Write( MCSWOWARCTIZZAI, itr->second->GetName(), itr->second->GetSession()->GetPlayer()->getLevel(), itr->second->GetSession()->GetLatency());
	}
	objmgr._playerslock.ReleaseReadLock();

	pConsole->Write("======================================================\r\n\r\n");
	return true;
}

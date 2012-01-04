/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "RStdAfx.h"
#include <svn_revision.h>
#include <Console/BaseConsole.h>
#include <Console/CConsole.h>
#include "ConsoleCommands.h"

bool HandleInfoCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	//uint32 clientsNum = (uint32)sWorld.GetSessionCount();

	int gm = 0;
	int count = 0;
	int avg = 0;
	int alliance = 0;
	int horde = 0;
	HM_NAMESPACE::hash_map<uint32, RPlayerInfo*>::const_iterator itr;
	sClientMgr.m_lock.AcquireReadLock();
	for (itr = sClientMgr.m_clients.begin(); itr != sClientMgr.m_clients.end(); itr++)
	{
			count++;
			avg += itr->second->Latency;
			if(itr->second->GMPermissions.size())
				gm++;
			if(itr->second->Team)
				horde++;
			else
				alliance++;
	}
	sClientMgr.m_lock.ReleaseReadLock();

	pConsole->Write("======================================================================\r\n");
	pConsole->Write("ArcTic Core Information: \r\n");
	pConsole->Write("======================================================================\r\n");
	pConsole->Write("ArcTic Revision Information %s/%s-%s-%s\r\n", BUILD_REVISION, CONFIG, PLATFORM_TEXT, ARCH);
	pConsole->Write("Server Uptime: %s\r\n", sRMaster.GetUptimeString().c_str());
	pConsole->Write("Current Players: %u (%d GMs, %d queued)\r\n", count, gm,  0);
	pConsole->Write("Alliance Online: %u\r\n",alliance);
	pConsole->Write("Horde Online: %u\r\n",horde);
	pConsole->Write("Active Thread Count: %u\r\n", ThreadPool.GetActiveThreadCount());
	pConsole->Write("Free Thread Count: %u\r\n", ThreadPool.GetFreeThreadCount());
	pConsole->Write("Average Latency: %.3fms\r\n", count ?  ((float)((float)avg / (float)count)) : 0.0f);
	pConsole->Write("SQL Query Cache Size (World): %u queries delayed\r\n", WorldDatabase.GetQueueSize());
	pConsole->Write("SQL Query Cache Size (Character): %u queries delayed\r\n", CharacterDatabase.GetQueueSize());
	pConsole->Write("======================================================================\r\n\r\n");

	return true;
}

bool HandleGMsCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write("There are the following GM's online on this server: \r\n");
	pConsole->Write("======================================================\r\n");
	pConsole->Write("| %21s | %15s | %04s  |\r\n" , "Name", "Permissions", "Latency");
	pConsole->Write("======================================================\r\n");

	HM_NAMESPACE::hash_map<uint32, RPlayerInfo*>::const_iterator itr;
	sClientMgr.m_lock.AcquireReadLock();
	for (itr = sClientMgr.m_clients.begin(); itr != sClientMgr.m_clients.end(); itr++)
	{
		if(itr->second->GMPermissions.size())
		{
			pConsole->Write("| %21s | %15s | %04u ms |\r\n" , itr->second->Name, itr->second->GMPermissions, itr->second->Latency);
		}
	}
	sClientMgr.m_lock.ReleaseReadLock();

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
	//char pAnnounce[1024];
	string outstr;
	if(argc < 2)
		return false;

	pConsole->Write("Not Implemented!");
	
	return true;
}

bool HandleWAnnounceCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	//char pAnnounce[1024];
	string outstr;
	if(argc < 2)
		return false;

	pConsole->Write("Not Implemented!");
	
	return true;
}

bool HandleKickCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 3)
		return false;

	RPlayerInfo* pPlayer;

	pPlayer = sClientMgr.GetRPlayer(std::string(argv[1]));

	if( pPlayer == NULL || pPlayer->GetSession() == NULL)
	{
		pConsole->Write("Could not find player, %s.\r\n", argv[1]);
		return true;
	}

	//bye fucker :D
	pPlayer->GetSession()->GetSocket()->Disconnect();

	pConsole->Write("Kicked player %s.\r\n", pPlayer->Name);
	return true;
}

bool HandleQuitCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	uint32 delay = 5;
	if(argc >= 2)
		delay = atoi(argv[1]);

	pConsole->Write("Shutdown initiated.\r\n");
	Master::m_stopEvent = true;
	//sWorld.QueueShutdown(delay, SERVER_SHUTDOWN_TYPE_SHUTDOWN);
	return true;
}

bool HandleCancelCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write("Shutdown canceled.\r\n");
	Master::m_stopEvent = false; //wont do anything just for compile sake
	//sWorld.CancelShutdown();
	return true;
}

bool HandleUptimeCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	string up = sRMaster.GetUptimeString();
	pConsole->Write("Server Uptime: %s\r\n", up.c_str());
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

	/// apply instantly in db
	sLogonCommHandler.Account_SetBanned(argv[1], banned, argv[3]);

	pConsole->Write("Account '%s' has been banned %s%s. The change will be effective with the next reload cycle.\r\n", argv[1], 
		timeperiod ? "until " : "forever", timeperiod ? ConvertTimeStampToDataTime(timeperiod+(uint32)UNIXTIME).c_str() : "");

	return true;
}

bool HandleUnbanAccountCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 2)
		return false;

	sLogonCommHandler.Account_SetBanned(argv[1], 0, "");
	
	pConsole->Write("Account '%s' has been unbanned.\r\n", argv[1]);
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

	pConsole->Write("Not Implemented!");

	return true;
}

bool HandleMOTDCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write("Not Implemented!");

	return true;
}

bool HandlePlayerInfoCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 2)
		return false;

	RPlayerInfo* plr = sClientMgr.GetRPlayer(std::string(argv[1]));
	if( plr == NULL || plr->GetSession() == NULL )
	{
		pConsole->Write("Player not found.\r\n");
		return true;
	}

	pConsole->Write("Player: %s\r\n", plr->Name);
	pConsole->Write("IP: %s\r\n", plr->GetSession()->GetSocket() ? plr->GetSession()->GetSocket()->GetRemoteIP().c_str() : "disconnected");
	pConsole->Write("Level: %u\r\n", plr->Level);
	pConsole->Write("Account: %s\r\n", plr->GetSession()->GetAccountName());
	return true;
}

bool HandleRehashCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write("Config file re-parsed.\n");
	sRMaster.Rehash(true);
	return true;
}

bool HandleBackupDBCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write("Not Implemented!");
	//sWorld.BackupDB();
	return true;
}

bool HandleSaveAllCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write("Not Implemented!");

	return true;
}
bool HandleWhisperCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write("Not Implemented!");
	return true;
}

bool HandleOnlinePlayersCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	WorldPacket data;
	//bool first = true;

	pConsole->Write("The following players are online on this server: \r\n");
	pConsole->Write("======================================================\r\n");
	pConsole->Write("| %21s | %15s | % 04s  |\r\n" , "Name", "Level", "Latency");
	pConsole->Write("======================================================\r\n");

	HM_NAMESPACE::hash_map<uint32, RPlayerInfo*>::const_iterator itr;
	sClientMgr.m_lock.AcquireReadLock();
	for (itr = sClientMgr.m_clients.begin(); itr != sClientMgr.m_clients.end(); itr++)
	{
		pConsole->Write("| %21s | %15u | %04u ms |\r\n" , itr->second->Name, itr->second->Level, itr->second->Latency);
	}
	sClientMgr.m_lock.ReleaseReadLock();

	pConsole->Write("======================================================\r\n\r\n");
	return true;
}
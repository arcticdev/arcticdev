/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#include "RStdAfx.h"
#include "../libs/svn_revision.h"
#define BANNER "WoWArcTic MMORPG Server r%u/%s-%s-%s :: ClusterServer\n"
#define WoWArcTicDev "Developer: Schnek_rus BLooD_LorD.\n"

Database * Database_Character;
Database * Database_World;

bool _StartCharacterDatabase()
{
	string hostname, username, password, database;
	int port = 0;
	bool result = Config.ClusterConfig.GetString( "CharacterDatabase", "Username", &username );
	Config.ClusterConfig.GetString( "CharacterDatabase", "Password", &password );
	result = !result ? result : Config.ClusterConfig.GetString( "CharacterDatabase", "Hostname", &hostname );
	result = !result ? result : Config.ClusterConfig.GetString( "CharacterDatabase", "Name", &database );
	result = !result ? result : Config.ClusterConfig.GetInt( "CharacterDatabase", "Port", &port );
	return Database_Character->Initialize(hostname.c_str(), port, username.c_str(), password.c_str(), database.c_str(), 5, 16384);
}

bool _StartWorldDatabase()
{
	string hostname, username, password, database;
	int port = 0;
	bool result = Config.ClusterConfig.GetString( "WorldDatabase", "Username", &username );
	Config.ClusterConfig.GetString( "WorldDatabase", "Password", &password );
	result = !result ? result : Config.ClusterConfig.GetString( "WorldDatabase", "Hostname", &hostname );
	result = !result ? result : Config.ClusterConfig.GetString( "WorldDatabase", "Name", &database );
	result = !result ? result : Config.ClusterConfig.GetInt( "WorldDatabase", "Port", &port );
	return Database_World->Initialize(hostname.c_str(), port, username.c_str(), password.c_str(), database.c_str(), 5, 16384);
}

int main(int argc, char *argv[])
{
	//sLog.outString("TexT");
	/* Initialize global timestamp */
	UNIXTIME = time(NULL);
	g_localTime = *localtime(&UNIXTIME);;

	ThreadPool.Startup();

    /* Print Banner */
	printf(BANNER, BUILD_REVISION, CONFIG, PLATFORM_TEXT, ARCH);
	printf(WoWArcTicDev);

	

	Database_Character = Database::Create();
	Database_World = Database::Create();
	Log.Success("Database", "Interface Created.");

	new ClusterMgr;
	new ClientMgr;
	
	Log.Line();
	Config.ClusterConfig.SetSource("conf/ClusterServer.conf");
	Config.RealmConfig.SetSource("conf/Realms.conf");
	Log.Notice("Database", "Connecting to databases...");
	if(!_StartCharacterDatabase() ||
	   !_StartWorldDatabase() )
	{
		Log.Error("Database", "One or more errors occured while connecting to databases.");
		exit(-1);
	}
	else
	{
		Log.Error("Database", "Connections established successfully.");
	}

	ThreadPool.ShowStats();
	Log.Line();

	Log.Success("Storage", "DBC Files Loaded...");
	Storage_Load();

	Log.Line();

	new SocketMgr;
	new SocketGarbageCollector;
	sSocketMgr.SpawnWorkerThreads();

	/* connect to LS */
	new LogonCommHandler;
	sLogonCommHandler.Startup();

	string host = Config.ClusterConfig.GetStringDefault( "Listen", "Host", "0.0.0.0" );
	int wsport = Config.ClusterConfig.GetIntDefault( "Listen", "WorldServerPort", 8129 );
	
	string shost = Config.ClusterConfig.GetStringDefault( "Server", "Host", "0.0.0.0" );
	int sport = Config.ClusterConfig.GetIntDefault( "Server", "WorldServerPort", 11010 );

	Log.Success("Network", "Network Subsystem Started.");

	Log.Notice("Network", "Opening Client Port...");
	ListenSocket<WorldSocket> * wsl = new ListenSocket<WorldSocket>(host.c_str(), wsport);
	bool lsc = wsl->IsOpen();

	Log.Notice("Network", "Opening Server Port...");
	ListenSocket<WSSocket> * isl = new ListenSocket<WSSocket>(shost.c_str(), sport);
	bool ssc = isl->IsOpen();

	if(!lsc || !ssc)
	{
		Log.Error("Network", "Could not open one of the sockets.");
		return 1;
	}

	ThreadPool.ExecuteTask( isl );
	ThreadPool.ExecuteTask( wsl );

	// connect to LS 
	new LogonCommHandler;
	sLogonCommHandler.Startup();

	/* main loop */
	for(;;)
	{
        sLogonCommHandler.UpdateSockets();
		//wsl->Update();
		//isl->Update();
		sClientMgr.Update();
		sClusterMgr.Update();
		Sleep(50);
	}

}

void OnCrash(bool Terminate)
{

}



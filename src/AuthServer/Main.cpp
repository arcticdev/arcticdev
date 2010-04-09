/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "AuthStdAfx.h"
#include <signal.h>
#include "svn_revision.h"
#ifndef WIN32
#include <sys/resource.h>
#endif
#include "../libs/Getopt.h"

#define BANNER "WoWArcTic MMORPG Server r%u/%s-%s-%s :: AuthServer\n"

#ifndef WIN32
#include <sched.h>
#endif

// Database impl
Database * sAuthSQL;
initialiseSingleton(AuthServer);
bool mrunning = true;
bool m_encryptedPasswords;
Mutex _authSocketLock;
set<AuthSocket*> _authSockets;

#ifdef WIN32
CircularQueue<uint32,30> last_spells;
#endif

// Signal Handler 
void _OnSignal(int s)
{
	switch (s)
	{
#ifndef WIN32
	    case SIGHUP:
	    {
		    sLog.outString("Received SIGHUP signal, reloading accounts.");
		    AccountMgr::getSingleton().ReloadAccounts(true);
	    }break;
#endif
	    case SIGINT:
	    case SIGTERM:
	    case SIGABRT:
#ifdef _WIN32
	    case SIGBREAK:
#endif
		mrunning = false;
		break;
	}

	signal(s, _OnSignal);
}

void RunLS(int argc, char** argv)
{
	new AuthServer;
	AuthServer::getSingleton( ).Run(argc, argv);
	delete AuthServer::getSingletonPtr();
}

int main(int argc, char** argv)
{
#ifndef WIN32
	rlimit rl;
	if (getrlimit(RLIMIT_CORE, &rl) == -1)
		printf("getrlimit failed. This could be problem.\n");
	else
	{
		rl.rlim_cur = rl.rlim_max;
		if (setrlimit(RLIMIT_CORE, &rl) == -1)
			printf("setrlimit failed. Server may not save core.dump files.\n");
	}
#endif

	// Run.
	THREAD_TRY_EXECUTION
	{
		RunLS(argc, argv);
	}
	THREAD_HANDLE_CRASH
}

bool startdb()
{
	string lhostname, lusername, lpassword, ldatabase;
	int lport = 0;
	int ltype = 1;
	// Configure Main Database

	bool result;

	// Configure Auth Database...
	result = Config.MainConfig.GetString("AuthDatabase", "Username", &lusername);
	result = !result ? result : Config.MainConfig.GetString("AuthDatabase", "Password", &lpassword);
	result = !result ? result : Config.MainConfig.GetString("AuthDatabase", "Hostname", &lhostname);
	result = !result ? result : Config.MainConfig.GetString("AuthDatabase", "Name", &ldatabase);
	result = !result ? result : Config.MainConfig.GetInt("AuthDatabase", "Port", &lport);
	result = !result ? result : Config.MainConfig.GetInt("AuthDatabase", "Type", &ltype);

	if(result == false)
	{
		sLog.outString("sql: Auth database parameters not found.");
		return false;
	}

	sLog.SetScreenLoggingLevel(Config.MainConfig.GetIntDefault("LogLevel", "Screen", 0));
	sAuthSQL = Database::Create();

	// Initialize it
	if(!sAuthSQL->Initialize(lhostname.c_str(), (unsigned int)lport, lusername.c_str(),
		lpassword.c_str(), ldatabase.c_str(), Config.MainConfig.GetIntDefault("AuthDatabase", "ConnectionCount", 5),
		16384))
	{
		sLog.outError("sql: Auth database initialization failed. Exiting.");
		return false;
	}   
	
	return true;
}

#define DEF_VALUE_NOT_SET 0xDEADBEEF

Mutex m_allowedIpLock;
vector<AllowedIP> m_allowedIps;
vector<AllowedIP> m_allowedModIps;

bool IsServerAllowed(unsigned int IP)
{
	m_allowedIpLock.Acquire();
	for(vector<AllowedIP>::iterator itr = m_allowedIps.begin(); itr != m_allowedIps.end(); ++itr)
	{
		if( ParseCIDRBan(IP, itr->IP, itr->Bytes) )
		{
			m_allowedIpLock.Release();
			return true;
		}
	}
	m_allowedIpLock.Release();
	return false;
}

bool IsServerAllowedMod(unsigned int IP)
{
	m_allowedIpLock.Acquire();
	for(vector<AllowedIP>::iterator itr = m_allowedModIps.begin(); itr != m_allowedModIps.end(); ++itr)
	{
		if( ParseCIDRBan(IP, itr->IP, itr->Bytes) )
		{
			m_allowedIpLock.Release();
			return true;
		}
	}
	m_allowedIpLock.Release();
	return false;
}

bool Rehash()
{
	char * config_file = "conf/AuthServer.conf";

	if(!Config.MainConfig.SetSource(config_file))
	{
		printf("Config file could not be rehashed.\n");
		return false;
	}

	m_encryptedPasswords = Config.MainConfig.GetBoolDefault("AuthServer", "UseEncryptedPasswords", false);

	// re-set the allowed server IP's
	string ips = Config.MainConfig.GetStringDefault("AuthServer", "AllowedIPs", "");
	string ipsmod = Config.MainConfig.GetStringDefault("AuthServer", "AllowedModIPs", "");

	vector<string> vips = StrSplit(ips, " ");
	vector<string> vipsmod = StrSplit(ipsmod, " ");

	// m_allowedIpLock.Acquire(); // I think no need fucking mutex here 
	m_allowedIps.clear();
	m_allowedModIps.clear();
	vector<string>::iterator itr;
	for(itr = vips.begin(); itr != vips.end(); ++itr)
	{
		string::size_type i = itr->find("/");
		if( i == string::npos )
		{
			printf("IP: %s could not be parsed. Ignoring\n", itr->c_str());
			continue;
		}

		string stmp = itr->substr(0, i);
		string smask = itr->substr(i+1);

		unsigned int ipraw = MakeIP(stmp.c_str());
		unsigned int ipmask = atoi(smask.c_str());
		if( ipraw == 0 || ipmask == 0 )
		{
			printf("IP: %s could not be parsed. Ignoring\n", itr->c_str());
			continue;
		}

		AllowedIP tmp;
		tmp.Bytes = ipmask;
		tmp.IP = ipraw;
		m_allowedIps.push_back(tmp);
	}

	for(itr = vipsmod.begin(); itr != vipsmod.end(); ++itr)
	{
		string::size_type i = itr->find("/");
		if( i == string::npos )
		{
			printf("IP: %s could not be parsed. Ignoring\n", itr->c_str());
			continue;
		}

		string stmp = itr->substr(0, i);
		string smask = itr->substr(i+1);

		unsigned int ipraw = MakeIP(stmp.c_str());
		unsigned int ipmask = atoi(smask.c_str());
		if( ipraw == 0 || ipmask == 0 )
		{
			printf("IP: %s could not be parsed. Ignoring\n", itr->c_str());
			continue;
		}

		AllowedIP tmp;
		tmp.Bytes = ipmask;
		tmp.IP = ipraw;
		m_allowedModIps.push_back(tmp);
	}

	if( InformationCore::getSingletonPtr() != NULL )
		sInfoCore.CheckServers();

	// m_allowedIpLock.Release(); // if Any problem uncomment two lines 

	return true;
}

void AuthServer::Run(int argc, char ** argv)
{
	UNIXTIME = time(NULL);
	g_localTime = *localtime(&UNIXTIME);
	char * config_file = "conf/AuthServer.conf";

	int file_log_level = DEF_VALUE_NOT_SET;
	int screen_log_level = DEF_VALUE_NOT_SET;
	int do_check_conf = 0;
	int do_version = 0;

	struct arctic_option longopts[] =
	{
		{ "checkconf", arctic_no_argument, &do_check_conf, 1 },
		{ "screenloglevel", arctic_required_argument, &screen_log_level, 1 },
		{ "fileloglevel", arctic_required_argument, &file_log_level, 1 },
		{ "version", arctic_no_argument, &do_version, 1 },
		{ "conf", arctic_required_argument, NULL, 'c' },
		{ 0, 0, 0, 0 }
	};

	char c;
	while ((c = arctic_getopt_long_only(argc, argv, ":f:", longopts, NULL)) != -1)
	{
		switch (c)
		{
		case 'c':
			// Log filename was set.
			config_file = new char[strlen(arctic_optarg)];
			strcpy(config_file,arctic_optarg);
			break;
		case 0:
			break;
		default:
			sLog.m_fileLogLevel = -1;
			sLog.m_screenLogLevel = 3;
			printf("Usage: %s [--checkconf] [--screenloglevel <level>] [--fileloglevel <level>] [--conf <filename>] [--version]\n", argv[0]);
			return;
		}
	}

	// Startup banner
	if(!do_version && !do_check_conf)
	{
		sLog.Init(-1, 3);
	}
	else
	{
		sLog.m_fileLogLevel = -1;
		sLog.m_screenLogLevel = 3;
	}
	Log.Color(TBLUE);
	printf(BANNER, BUILD_REVISION, CONFIG, PLATFORM_TEXT, ARCH);
	sLog.outString("==============================================================================");
	Log.Line();
	
	if( do_version )
	    return;

	if(do_check_conf)
	{
		printf("Checking config file: %s\n", config_file);
		if(Config.MainConfig.SetSource(config_file, true))
			printf("  Passed without errors.\n");
		else
			printf("  Encountered one or more errors.\n");
		// test for die variables.
		string die;
		if(Config.MainConfig.GetString("die", "msg", &die) || Config.MainConfig.GetString("die2", "msg", &die))
			printf("Die directive received: %s", die.c_str());

		return;
	}
	
	sLog.outString("The key combination <Ctrl-C> will safely shut down the server at any time.");
	sLog.outString("");
	Log.Notice("System","Initializing Random Number Generators...");

	Log.Notice("Config", "Loading Config Files...");
	if(!Rehash())
		return;

	Log.Notice("ThreadMgr", "Starting...");

	ThreadPool.Startup(4);
   
	if(!startdb())
		return;

	Log.Notice("AccountMgr", "Starting...");
	new AccountMgr;
	new IPBanner;

	Log.Notice("InfoCore", "Starting...");
	new InformationCore;

	new PatchMgr;
	Log.Notice("AccountMgr", "Precaching accounts...");
	sAccountMgr.ReloadAccounts(true);
	Log.Notice("AccountMgr", "%u accounts are loaded and ready.", sAccountMgr.GetCount());
	Log.Line();

	// Spawn periodic function caller thread for account reload every 10mins
	int atime = Config.MainConfig.GetIntDefault("Rates", "AccountRefresh", 600);
	atime *= 1000;
	PeriodicFunctionCaller<AccountMgr> * pfc = new PeriodicFunctionCaller<AccountMgr>(AccountMgr::getSingletonPtr(),&AccountMgr::ReloadAccountsCallback, atime);
	ThreadPool.ExecuteTask(pfc);

	// Load conf settings..
	uint32 cport = Config.MainConfig.GetIntDefault("Listen", "RealmListPort", 3724);
	uint32 sport = Config.MainConfig.GetIntDefault("Listen", "ServerPort", 8093);
	string host = Config.MainConfig.GetStringDefault("Listen", "Host", "0.0.0.0");
	string shost = Config.MainConfig.GetStringDefault("Listen", "ISHost", host.c_str());
	min_build = Config.MainConfig.GetIntDefault("Client", "MinBuild", 6180);
	max_build = Config.MainConfig.GetIntDefault("Client", "MaxBuild", 99999);
	string Auth_pass = Config.MainConfig.GetStringDefault("AuthServer", "RemotePassword", "r3m0t3b4d");
	Sha1Hash hash;
	hash.UpdateData(Auth_pass);
	hash.Finalize();
	memcpy(sql_hash, hash.GetDigest(), 20);
	
	ThreadPool.ExecuteTask(new AuthConsoleThread);

	new SocketMgr;
	new SocketGarbageCollector;
	sSocketMgr.SpawnWorkerThreads();

	ListenSocket<AuthSocket> * cl = new ListenSocket<AuthSocket>(host.c_str(), cport);
	ListenSocket<AuthCommServerSocket> * sl = new ListenSocket<AuthCommServerSocket>(shost.c_str(), sport);

	// Spawn auth listener
	// Spawn interserver listener
	bool authsockcreated = cl->IsOpen();
	bool intersockcreated = sl->IsOpen();
#ifdef WIN32
	if(authsockcreated)
		ThreadPool.ExecuteTask(cl);
	if(intersockcreated)
		ThreadPool.ExecuteTask(sl);
#endif
	// hook signals
	Log.Notice("AuthServer","Hooking signals...");
	signal(SIGINT, _OnSignal);
	signal(SIGTERM, _OnSignal);
	signal(SIGABRT, _OnSignal);
#ifdef _WIN32
	signal(SIGBREAK, _OnSignal);
#else
	signal(SIGHUP, _OnSignal);
#endif
	// write pid file 
	FILE * fPid = fopen("AuthServer.pid", "w");
	if(fPid)
	{
		uint32 pid;
#ifdef WIN32
		pid = GetCurrentProcessId();
#else
		pid = getpid();
#endif
		fprintf(fPid, "%u", (unsigned int)pid);
		fclose(fPid);
	}
	
    Log.Notice("AuthServer","Success! Ready for connections");
	uint32 timers[2];
    timers[0] = getMSTime() + 120000; // 120000/60000 = 2 min
    timers[1] = getMSTime() + 2000;   // 2000/1000 = 2 sec
	while(mrunning && authsockcreated && intersockcreated)
	{

		if(timers[0] <= getMSTime())	           
		{
			ThreadPool.IntegrityCheck(2); // Check every two minutes
			timers[0] = getMSTime() + 120000;
		}

		if(timers[1] <= getMSTime())                
		{
			sInfoCore.TimeoutSockets();
			sSocketGarbageCollector.Update();
			CheckForDeadSockets(); // Flood Protection
			UNIXTIME = time(NULL);
			g_localTime = *localtime(&UNIXTIME);
            timers[0] = getMSTime() + 2000;
		}

		PatchMgr::getSingleton().UpdateJobs();
		Sleep(10);
	}

	Log.Notice("AuthServer","Shutting down...");

	signal(SIGINT, 0);
	signal(SIGTERM, 0);
	signal(SIGABRT, 0);
#ifdef _WIN32
	signal(SIGBREAK, 0);
#else
	signal(SIGHUP, 0);
#endif
	pfc->kill();

	cl->Close();
	sl->Close();
	sSocketMgr.CloseAll();
#ifdef WIN32
	sSocketMgr.ShutdownThreads();
#endif
	sAuthConsole.Kill();
	delete AuthConsole::getSingletonPtr();

	// kill db
	sLog.outString("Waiting for database to close..");
	sAuthSQL->EndThreads();
	sAuthSQL->Shutdown();
	delete sAuthSQL;

	ThreadPool.Shutdown();

	// delete pid file
	remove("AuthServer.pid");

	delete AccountMgr::getSingletonPtr();
	delete InformationCore::getSingletonPtr();
	delete IPBanner::getSingletonPtr();
	delete SocketMgr::getSingletonPtr();
	delete SocketGarbageCollector::getSingletonPtr();
	delete pfc;
	Log.Notice("AuthServer","Shutdown complete.\n");
}

void OnCrash(bool Terminate)
{
}

void AuthServer::CheckForDeadSockets()
{
	_authSocketLock.Acquire();
	time_t t = time(NULL);
	time_t diff;
	set<AuthSocket*>::iterator itr = _authSockets.begin();
	set<AuthSocket*>::iterator it2;
	AuthSocket * s;

	for(itr = _authSockets.begin(); itr != _authSockets.end();)
	{
		it2 = itr;
		s = (*it2);
		++itr;

		diff = t - s->GetLastRecv();
		if(diff > 240) // More than 4mins -> kill the socket.
		{
			_authSockets.erase(it2);
			s->removedFromSet = true;
			s->Disconnect();
		}
	}
	_authSocketLock.Release();
}

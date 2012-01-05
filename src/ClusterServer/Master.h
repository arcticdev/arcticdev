/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _R_MASTER_H
#define _R_MASTER_H

#include "Common.h"
#include "Config/ConfigEnv.h"
#include "DataStorage/DatabaseEnv.h"
#include "Getopt.h"

#ifndef _VERSION
# define _VERSION "3.3.5"
#endif

#if PLATFORM == PLATFORM_WIN32
# define _FULLVERSION _VERSION "-SVN (Win32)"
#else
# define _FULLVERSION _VERSION "-SVN (Unix)"
#endif

#ifdef _DEBUG
#define BUILDTYPE "Debug"
#else
#define BUILDTYPE "Release"
#endif

extern Database * Database_World;
extern Database * Database_Character;

#define WorldDatabase (*Database_World)
#define CharacterDatabase (*Database_Character)

class SERVER_DECL Master : public Singleton<Master>
{
public:
	Master();
	~Master();
	bool Run(int argc, char ** argv);
	void Rehash(bool load);

	static volatile bool m_stopEvent;
	uint32 m_startTime;
	std::string GetUptimeString()
	{
		char str[300];
		time_t pTime = (time_t)UNIXTIME - m_startTime;
		tm * tmv = gmtime(&pTime);

		snprintf(str, 300, "%u days, %u hours, %u minutes, %u seconds.", tmv->tm_yday, tmv->tm_hour, tmv->tm_min, tmv->tm_sec);
		return string(str);
	}

	bool m_lfgForNonLfg;
	std::string GmClientChannel;

private:
	bool _StartDB();
	void _StopDB();

	void _HookSignals();
	void _UnhookSignals();

	static void _OnSignal(int s);
};

#define sRMaster Master::getSingleton()

#endif

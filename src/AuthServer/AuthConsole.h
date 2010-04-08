/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __AUTHCONSOLE_H
#define __AUTHCONSOLE_H

#include "Common.h"

class AuthConsoleThread : public ThreadContext
{
public:
	bool kill;
	AuthConsoleThread();
	~AuthConsoleThread();
	bool run();
};

class AuthConsole :  public Singleton < AuthConsole >
{
	friend class AuthConsoleThread;

public:						// Public methods:
	void Kill();

protected:					// Protected methods:
	AuthConsoleThread *_thread;

	// Process one command
	void ProcessCmd(char *cmd);

	// quit | exit
	void TranslateQuit(char *str);
	void ProcessQuit(int delay);
	void CancelShutdown(char *str);

	// help | ?
	void TranslateHelp(char *str);
	void ProcessHelp(char *command);

	void ReloadAccts(char *str);
	void TranslateRehash(char* str);
};

#define sAuthConsole AuthConsole::getSingleton()

#endif

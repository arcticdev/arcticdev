/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "AuthStdAfx.h"
#include "AuthConsole.h"
#include "Log.h"

initialiseSingleton(AuthConsole);
bool Rehash();

void AuthConsole::TranslateRehash(char* str)
{
	sLog.outString("rehashing config file...");
	Rehash();
}

void AuthConsole::Kill()
{
#ifdef WIN32
	DWORD dwTmp;
	INPUT_RECORD ir[2];
	ir[0].EventType = KEY_EVENT;
	ir[0].Event.KeyEvent.bKeyDown = TRUE;
	ir[0].Event.KeyEvent.dwControlKeyState = 288;
	ir[0].Event.KeyEvent.uChar.AsciiChar = 13;
	ir[0].Event.KeyEvent.wRepeatCount = 1;
	ir[0].Event.KeyEvent.wVirtualKeyCode = 13;
	ir[0].Event.KeyEvent.wVirtualScanCode = 28;
	ir[1].EventType = KEY_EVENT;
	ir[1].Event.KeyEvent.bKeyDown = FALSE;
	ir[1].Event.KeyEvent.dwControlKeyState = 288;
	ir[1].Event.KeyEvent.uChar.AsciiChar = 13;
	ir[1].Event.KeyEvent.wRepeatCount = 1;
	ir[1].Event.KeyEvent.wVirtualKeyCode = 13;
	ir[1].Event.KeyEvent.wVirtualScanCode = 28;
	_thread->kill=true;
	WriteConsoleInput (GetStdHandle(STD_INPUT_HANDLE), ir, 2, & dwTmp);
	printf("Waiting for console thread to terminate....\n");
	while(_thread != NULL)
	{
		Sleep(100);
	}
	printf("Console shut down.\n");
#endif
}

bool AuthConsoleThread::run()
{
	new AuthConsole;

	SetThreadName("Console Interpreter");
	sAuthConsole._thread = this;
	int i = 0;
	char cmd[96];

	while (!kill)
	{
		memset(cmd,0,sizeof(cmd)); 
		fgets(cmd, 80, stdin);

		if(kill)
			break;

		for( i = 0 ; i < 80 || cmd[i] != '\0' ; i++ )
		{
			if( cmd[i] =='\n' )
			{
				cmd[i]='\0';
				sAuthConsole.ProcessCmd(cmd);
				fflush(stdin);
				break;
			}
		}
	}

	sAuthConsole._thread=NULL;
	return true;
}

//////////////////////////////////////////////////////////////////////////
// Protected methods                                                    //
//////////////////////////////////////////////////////////////////////////

// Process one command
void AuthConsole::ProcessCmd(char *cmd)
{
	typedef void (AuthConsole::*PTranslater)(char *str);
	struct SCmd
	{
		const char *name;
		PTranslater tr;
	};

	SCmd cmds[] =
	{

		{"?", &AuthConsole::TranslateHelp}, {"help", &AuthConsole::TranslateHelp},
		{"reload", &AuthConsole::ReloadAccts},
		{"rehash", &AuthConsole::TranslateRehash},
		{"shutdown", &AuthConsole::TranslateQuit}, {"quit", &AuthConsole::TranslateQuit}, {"exit", &AuthConsole::TranslateQuit}, 
	};

	char cmd2[80];
	strcpy(cmd2, cmd);
	for(size_t i = 0; i < strlen(cmd); ++i)
		cmd2[i] = tolower(cmd[i]);

	for (size_t i = 0; i < sizeof(cmds)/sizeof(SCmd); i++)
		if (strncmp(cmd2, cmds[i].name, strlen(cmds[i].name)) == 0)
		{
			(this->*(cmds[i].tr)) (cmd + strlen(cmds[i].name));
			return;
		}

		printf("Console:Unknown console command (use \"help\" for help).\n");
}

void AuthConsole::ReloadAccts(char *str)
{
	AccountMgr::getSingleton().ReloadAccounts(false);
	IPBanner::getSingleton().Reload();
}

// quit | exit
void AuthConsole::TranslateQuit(char *str)
{
	int delay = str != NULL ? atoi(str) : 5000;
	if(!delay)
		delay = 5000;
	else
		delay *= 1000;

	ProcessQuit(delay);
}
void AuthConsole::ProcessQuit(int delay)
{
	mrunning = false;
}

void AuthConsole::TranslateHelp(char *str)
{
	ProcessHelp(NULL);
}
void AuthConsole::ProcessHelp(char *command)
{
	if (command == NULL)
	{
		sLog.outString("Console:--------help--------");
		sLog.outString("   help, ?: print this text");
		sLog.outString("   reload, reloads accounts");
		sLog.outString("   rehash, rehashes config file");
		sLog.outString("   quit, shutdown, exit: close program");
	}
}

AuthConsoleThread::AuthConsoleThread()
{
	kill = false;
}

AuthConsoleThread::~AuthConsoleThread()
{
}

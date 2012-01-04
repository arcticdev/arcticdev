/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _BASECONSOLE_H
#define _BASECONSOLE_H

#include <Console/BaseConsole.h>

class ConsoleSocket;

class RemoteConsole : public BaseConsole
{
	ConsoleSocket * m_pSocket;
public:
	RemoteConsole(ConsoleSocket* pSocket);
	void Write(const char * Format, ...);
	void WriteNA(const char * Format);
};

void HandleConsoleInput(BaseConsole * pConsole, const char * szInput);

#endif


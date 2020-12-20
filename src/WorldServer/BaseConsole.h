/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#pragma once

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

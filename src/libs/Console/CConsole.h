/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2011 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __CConsole_LIB
#define __CConsole_LIB

#include "Common.h"

class ConsoleThread : public ThreadContext
{
protected:
	bool m_isRunning;
public:
	void terminate();
	bool run();
};

#endif

/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __CCONSOLE_H
#define __CCONSOLE_H

#include "Common.h"

class ConsoleThread : public ThreadContext
{
protected:
    bool m_isRunning;
public:
    void terminate();
    bool run();
};

#endif // __CCONSOLE_H

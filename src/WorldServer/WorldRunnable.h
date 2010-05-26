/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __WORLDRUNNABLE_H
#define __WORLDRUNNABLE_H

class WorldRunnable : public ThreadContext
{
public:
	WorldRunnable();
	bool run();
};

#endif

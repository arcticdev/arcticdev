/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef WOWSERVER_MEMORY_H
#define WOWSERVER_MEMORY_H

#include "Common.h"
#include "Singleton.h"

struct MemoryManager : public Singleton < MemoryManager > {
	MemoryManager();
};

#endif


/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _THREADING_H
#define _THREADING_H

// We need assertions.
#include "../Errors.h"

// Platform Specific Lock Implementation
#include "Mutex.h"

// Platform Independant Guard
#include "Guard.h"

// Platform Specific Thread Starter
#include "ThreadStarter.h"

// Platform independant locked queue
#include "LockedQueue.h"

// Thread Pool
#include "ThreadPool.h"

#endif


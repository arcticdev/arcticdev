/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2011 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

initialiseSingleton( EventMgr );

TimedEvent * TimedEvent::Allocate(void* object, CallbackBase* callback, uint32 flags, time_t time, uint32 repeat)
{
	return new TimedEvent(object, callback, flags, time, repeat, 0);
}

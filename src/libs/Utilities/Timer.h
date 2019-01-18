/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#ifndef WOW_TIMER_H
#define WOW_TIMER_H

#ifdef WIN32
__forceinline uint32 getMSTime() { return GetTickCount(); }
#else
ARCTIC_INLINE uint32 getMSTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}
#endif

#endif

/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _UTIL_H
#define _UTIL_H

#include "../Common.h"

inline std::wstring GetMainPartOfName(std::wstring wname)
{
	// supported only Cyrillic case A      IE      I       SHORT I O       U       YERU    SOFT SIGN E     YU      YA      IO
	static wchar_t dropChars[] = { 0x0430, 0x0435, 0x0438, 0x0439, 0x043E, 0x0443, 0x044B, 0x044C, 0x044D, 0x044E, 0x044F, 0x0451 };
	size_t pos = wname.find_last_not_of(dropChars);
	return pos!=wname.npos ? wname.substr(0,pos+1) : wname;
}

//////////////////////////////////////////////////////////////////////////
// String Functions                                                     //
//////////////////////////////////////////////////////////////////////////

std::vector<std::string> StrSplit(const std::string &src, const std::string &sep);

// This HAS to be called outside the threads __try / __except block!
void SetThreadName(const char* format, ...);
time_t convTimePeriod ( uint32 dLength, char dType);

ARCTIC_INLINE uint32 secsToTimeBitFields(time_t secs)
{
	tm* lt = localtime(&secs);
	return (lt->tm_year - 100) << 24 | lt->tm_mon  << 20 | (lt->tm_mday - 1) << 14 | lt->tm_wday << 11 | lt->tm_hour << 6 | lt->tm_min;
}

#ifdef WIN32

	typedef struct tagTHREADNAME_INFO
	{
		DWORD dwType; // must be 0x1000
		LPCSTR szName; // pointer to name (in user addr space)
		DWORD dwThreadID; // thread ID (-1=caller thread)
		DWORD dwFlags; // reserved for future use, must be zero
	} THREADNAME_INFO;

#endif

#endif

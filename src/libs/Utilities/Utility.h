/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _UTIL_H
#define _UTIL_H

#include "../Common.h"

bool Utf8toWStr(std::string utf8str, std::wstring& wstr);
bool WStrToUtf8(std::wstring wstr, std::string& utf8str);

size_t utf8length(std::string& utf8str);                    // set string to "" if invalid utf8 sequence

inline wchar_t wcharToUpper(wchar_t wchar)
{
    if(wchar >= L'a' && wchar <= L'z')                      // LATIN SMALL LETTER A - LATIN SMALL LETTER Z
        return wchar_t(uint16(wchar)-0x0020);
    if(wchar == 0x00DF)                                     // LATIN SMALL LETTER SHARP S
        return wchar_t(0x1E9E);
    if(wchar >= 0x00E0 && wchar <= 0x00F6)                  // LATIN SMALL LETTER A WITH GRAVE - LATIN SMALL LETTER O WITH DIAERESIS
        return wchar_t(uint16(wchar)-0x0020);
    if(wchar >= 0x00F8 && wchar <= 0x00FE)                  // LATIN SMALL LETTER O WITH STROKE - LATIN SMALL LETTER THORN
        return wchar_t(uint16(wchar)-0x0020);
    if(wchar >= 0x0101 && wchar <= 0x012F)                  // LATIN SMALL LETTER A WITH MACRON - LATIN SMALL LETTER I WITH OGONEK (only %2=1)
    {
        if(wchar % 2 == 1)
            return wchar_t(uint16(wchar)-0x0001);
    }
    if(wchar >= 0x0430 && wchar <= 0x044F)                  // CYRILLIC SMALL LETTER A - CYRILLIC SMALL LETTER YA
        return wchar_t(uint16(wchar)-0x0020);

    return wchar;
}

inline wchar_t wcharToLower(wchar_t wchar)
{
    if(wchar >= L'A' && wchar <= L'Z')                      // LATIN CAPITAL LETTER A - LATIN CAPITAL LETTER Z
        return wchar_t(uint16(wchar)+0x0020);
    if(wchar >= 0x00C0 && wchar <= 0x00D6)                  // LATIN CAPITAL LETTER A WITH GRAVE - LATIN CAPITAL LETTER O WITH DIAERESIS
        return wchar_t(uint16(wchar)+0x0020);
    if(wchar >= 0x00D8 && wchar <= 0x00DF)                  // LATIN CAPITAL LETTER O WITH STROKE - LATIN CAPITAL LETTER THORN
        return wchar_t(uint16(wchar)+0x0020);
    if(wchar >= 0x0100 && wchar <= 0x012E)                  // LATIN CAPITAL LETTER A WITH MACRON - LATIN CAPITAL LETTER I WITH OGONEK (only %2=0)
    {
        if(wchar % 2 == 0)
            return wchar_t(uint16(wchar)+0x0001);
    }
    if(wchar == 0x1E9E)                                     // LATIN CAPITAL LETTER SHARP S
        return wchar_t(0x00DF);
    if(wchar >= 0x0410 && wchar <= 0x042F)                  // CYRILLIC CAPITAL LETTER A - CYRILLIC CAPITAL LETTER YA
        return wchar_t(uint16(wchar)+0x0020);

    return wchar;
}

inline void wstrToUpper(std::wstring& str)
{
    std::transform( str.begin(), str.end(), str.begin(), wcharToUpper );
}

inline void wstrToLower(std::wstring& str)
{
    std::transform( str.begin(), str.end(), str.begin(), wcharToLower );
}

inline bool normalizePlayerName(std::string& name)
{
    if(name.empty())
        return false;

    std::wstring wstr;
    if(!Utf8toWStr(name,wstr))
        return false;

    wstr[0] = wcharToUpper(wstr[0]);
    for(size_t i = 1; i < wstr.size(); ++i)
        wstr[i] = wcharToLower(wstr[i]);

    if(!WStrToUtf8(wstr,name))
        return false;

    return true;
}

//////////////////////////////////////////////////////////////////////////
// String Functions
//////////////////////////////////////////////////////////////////////////

std::vector<std::string> StrSplit(const std::string &src, const std::string &sep);

// This HAS to be called outside the threads __try / __except block!
void SetThreadName(const char* format, ...);
time_t convTimePeriod ( uint32 dLength, char dType);

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

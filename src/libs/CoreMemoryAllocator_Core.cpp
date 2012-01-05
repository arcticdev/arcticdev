/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include <new>
#include <malloc.h>

#ifdef WIN32
#ifndef SCRIPTLIB

__declspec(dllexport) void* AllocateMemory(size_t iSize)
{
	return operator new(iSize);
}

__declspec(dllexport) void FreeMemory(void* pPointer)
{
	operator delete(pPointer);
}

#endif		// SCRIPTLIB
#endif		// WIN32


/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "stdlib.h"
#include "stdio.h"

void * operator new[](size_t iSize)
{
	return malloc(iSize);
}

void operator delete[](void* pPointer)
{
	free(pPointer);
}

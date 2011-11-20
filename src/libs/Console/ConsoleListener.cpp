/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2011 Arctic Server Team
 * See COPYING for license details.
 */

#include "Common.h"

#include "BaseConsole.h"

void LocalConsole::Write(const char * Format, ...)
{
	va_list ap;
	va_start(ap, Format);
	vprintf(Format, ap);
}

void LocalConsole::WriteNA(const char * Format)
{
	printf(Format);
}

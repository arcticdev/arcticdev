/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2011 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef SCRIPTSETUP_H
#define SCRIPTSETUP_H

#ifdef SCRIPTLIB

#include <revision.h>
#ifndef SKIP_ALLOCATOR_SHARING
#include "CoreMemoryAllocator.cpp"
#endif

extern "C" SCRIPT_DECL const char* _exp_get_version()
{
	return BUILD_HASH_STR;
}

#endif // SCRIPTLIB
#endif // SCRIPTSETUP_H


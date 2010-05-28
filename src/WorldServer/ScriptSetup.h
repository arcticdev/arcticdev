/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef SCRIPTSETUP_H
#define SCRIPTSETUP_H

#ifdef SCRIPTLIB

#include <svn_revision.h>
#define MAKE_SCRIPT_VERSION(major, minor) (uint32)(((uint16)major << 16) | ((uint16)minor))

extern "C" SCRIPT_DECL uint32 _exp_get_version()
{
	return MAKE_SCRIPT_VERSION(BUILD_REVISION / 1000, BUILD_REVISION % 1000);
}

#endif
#endif

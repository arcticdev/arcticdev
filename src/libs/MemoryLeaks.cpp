/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "MemoryLeaks.h"

// #include <vld.h>
// #include <vldapi.h>

#if COMPILER == MICROSOFT

createFileSingleton( MemoryManager ) ;

// Catch memory leaks
MemoryManager::MemoryManager( )
{
// VLDEnable();
}

#endif

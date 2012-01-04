/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "MemoryLeaks.h"

#if COMPILER == MICROSOFT

createFileSingleton( MemoryManager ) ;

// Catch memory leaks
MemoryManager::MemoryManager( )
{
}

#endif


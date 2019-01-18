/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#include "ManagedModelContainer.h"

namespace VMAP
{

	ManagedModelContainer::ManagedModelContainer(void) : ModelContainer()
	{
		refCount = 0;
	}

	ManagedModelContainer::~ManagedModelContainer(void)
	{
	}

}

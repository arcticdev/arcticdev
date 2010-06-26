/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
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

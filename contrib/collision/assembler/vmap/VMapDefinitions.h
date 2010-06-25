/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */
 
#ifndef _VMAPDEFINITIONS_H
#define _VMAPDEFINITIONS_H

namespace VMAP
{
    //=====================================
    #define MAX_CAN_FALL_DISTANCE 10.0

    class VMapDefinitions
    {
        public:
            static const double getMaxCanFallDistance() { return(MAX_CAN_FALL_DISTANCE); }
    };

    //======================================
}
#endif

/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __MISCHANDLER_H
#define __MISCHANDLER_H

#pragma pack(push,1)
struct GraveyardTeleport
{
    uint32 ID;
    float X;
    float Y;
    float Z;
    float O;
    uint32 ZoneId;
	uint32 AdjacentZoneId;
	uint32 MapId;
    uint32 FactionID;
};
#pragma pack(pop)
/*
// schnek: I'm not exactly sure what way it should be so let's wait a bit :P
class ARCTIC_DECL MiscHandler
{
    Loot m_loot;
    // Get functions
    Loot GetLoot() { return m_loot; }
};
*/
#endif

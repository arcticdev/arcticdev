/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2014 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

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

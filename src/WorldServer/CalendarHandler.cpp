/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#include "StdAfx.h"

void WorldSession::HandleCalendarGetCalendar(WorldPacket& recv_data)
{
	time_t cur_time = time(NULL);

	WorldPacket data(SMSG_CALENDAR_SEND_CALENDAR, 4+4*0+4+4*0+4+4);

	// TODO: calendar invite event output
	// TODO: calendar event output
	data << uint32(0);                                // invite node count
	data << uint32(0);                                // event count
	data << uint32(0);
	data << uint32(secsToTimeBitFields(cur_time));    // current time

	uint32 count = 0;
	size_t p_count = data.wpos();
	data << uint32(count);                            // Calender shit.
	data.put<uint32>(p_count,count);
	data << uint32(1135753200);                       // Unix Time for when calendars started?
	data << uint32(0);                                //  unk counter 4
	data << uint32(0);                                // unk counter 5
	SendPacket(&data);
}

void WorldSession::HandleCalendarGetEvent(WorldPacket& recv_data)
{
}

void WorldSession::HandleCalendarGuildFilter(WorldPacket& recv_data)
{
}

void WorldSession::HandleCalendarArenaTeam(WorldPacket& recv_data)
{
}

void WorldSession::HandleCalendarAddEvent(WorldPacket& recv_data)
{
	SKIP_READ_PACKET(recv_data);

	std::string unk1, unk2;
	recv_data >> unk1;
	recv_data >> unk2;

	uint8   unk3, unk4;
	uint32  unk5, unk6, unk7, unk8, unk9, count = 0;
	recv_data >> unk3;
	recv_data >> unk4;
	recv_data >> unk5;
	recv_data >> unk6;
	recv_data >> unk7;
	recv_data >> unk8;
	recv_data >> unk9;
	if(!((unk9 >> 6) & 1))
	{
		recv_data >> count;
		if (count)
		{
			uint8 unk12,unk13;
			WoWGuid guid;
			for (uint i = 0; i < count; i++)
			{
				recv_data >> guid;
				recv_data >> unk12;
				recv_data >> unk13;
			}
		}
	}
}

void WorldSession::HandleCalendarUpdateEvent(WorldPacket& recv_data)
{
	SKIP_READ_PACKET(recv_data);

	//recv_data >> uint64
	//recv_data >> uint64
	//recv_data >> std::string
	//recv_data >> std::string
	//recv_data >> uint8
	//recv_data >> uint8
	//recv_data >> uint32
	//recv_data >> uint32
	//recv_data >> uint32
	//recv_data >> uint32
	//recv_data >> uint32
}

void WorldSession::HandleCalendarRemoveEvent(WorldPacket& recv_data)
{
	SKIP_READ_PACKET(recv_data);

	//recv_data >> uint64
	//recv_data >> uint64
	//recv_data >> uint32
}

void WorldSession::HandleCalendarCopyEvent(WorldPacket& recv_data)
{
	SKIP_READ_PACKET(recv_data);

	//recv_data >> uint64
	//recv_data >> uint64
	//recv_data >> uint32
}

void WorldSession::HandleCalendarEventInvite(WorldPacket& recv_data)
{
	recv_data.hexlike();
	SKIP_READ_PACKET(recv_data);

	//recv_data >> uint64
	//recv_data >> uint64
	//recv_data >> std::string
	//recv_data >> uint8
	//recv_data >> uint8
}

void WorldSession::HandleCalendarEventRsvp(WorldPacket& recv_data)
{
	recv_data.hexlike();
	SKIP_READ_PACKET(recv_data);

	//recv_data >> uint64
	//recv_data >> uint64
	//recv_data >> uint32
}

void WorldSession::HandleCalendarEventRemoveInvite(WorldPacket& recv_data)
{
	recv_data.hexlike();
	SKIP_READ_PACKET(recv_data);

	//recv_data >> wowguid(guid);
	//recv_data >> uint64
	//recv_data >> uint64
	//recv_data >> uint64
}

void WorldSession::HandleCalendarEventStatus(WorldPacket& recv_data)
{
	recv_data.hexlike();
	SKIP_READ_PACKET(recv_data);

	//recv_data >> wowguid(guid);
	//recv_data >> uint64
	//recv_data >> uint64
	//recv_data >> uint64
	//recv_data >> uint32
}

void WorldSession::HandleCalendarEventModeratorStatus(WorldPacket& recv_data)
{
	recv_data.hexlike();
	SKIP_READ_PACKET(recv_data);

	//recv_data >> wowguid(guid);
	//recv_data >> uint64
	//recv_data >> uint64
	//recv_data >> uint64
	//recv_data >> uint32
}

void WorldSession::HandleCalendarComplain(WorldPacket& recv_data)
{
	recv_data.hexlike();
	SKIP_READ_PACKET(recv_data);

	//recv_data >> uint64
	//recv_data >> uint64
	//recv_data >> uint64
}

void WorldSession::HandleCalendarGetNumPending(WorldPacket & /*recv_data*/)
{
	WorldPacket data(SMSG_CALENDAR_SEND_NUM_PENDING, 4);
	data << uint32(0);
	SendPacket(&data);
}

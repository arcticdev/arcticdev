/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

void WorldSession::HandleChannelWatchOpcode(WorldPacket & recv_data)
{
	SKIP_READ_PACKET(recv_data);
}

void WorldSession::HandleEnableMicrophoneOpcode(WorldPacket & recv_data)
{
	SKIP_READ_PACKET(recv_data);
}

void WorldSession::HandleChannelVoiceOnOpcode(WorldPacket & recv_data)
{
	SKIP_READ_PACKET(recv_data);
}

void WorldSession::HandleVoiceChatQueryOpcode(WorldPacket & recv_data)
{
	SKIP_READ_PACKET(recv_data);
}

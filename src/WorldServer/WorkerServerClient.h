/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#ifdef CLUSTERING

#pragma once

class WSClient : public Socket
{
	bool _authenticated;
	uint32 _remaining;
	uint16 _cmd;
public:
	WSClient(SOCKET fd);
	~WSClient();

	void SendPacket(WorldPacket * data);
	void OnRead();
	void OnConnect();
	void OnDisconnect();
};

#endif

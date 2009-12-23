/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#ifdef CLUSTERING
#ifndef _WORKERSERVER_CLIENT_H
#define _WORKERSERVER_CLIENT_H

class WSClient : public Socket
{
	bool _authenticated;
	uint32 _remaining;
	uint16 _cmd;
public:
	WSClient(SOCKET fd);
	~WSClient();

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

	void SendPacket(WorldPacket * data);
	void OnRead();
	void OnConnect();
};

#endif
#endif

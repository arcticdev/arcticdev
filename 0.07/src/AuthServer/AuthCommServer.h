/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __Auth_COMM_SERVER_H
#define __Auth_COMM_SERVER_H

#include <RC4Engine.h>

class AuthCommServerSocket : public Socket
{
	uint32 remaining;
	uint16 opcode;
	uint32 seed;
	RC4Engine sendCrypto;
	RC4Engine recvCrypto;
public:
	uint32 authenticated;
	bool use_crypto;

	AuthCommServerSocket(SOCKET fd);
	~AuthCommServerSocket();

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

	void OnRead();
	void OnDisconnect();
	void OnConnect();
	void SendPacket(WorldPacket * data);
	void HandlePacket(WorldPacket & recvData);

	void HandleRegister(WorldPacket & recvData);
	void HandlePing(WorldPacket & recvData);
	void HandleSessionRequest(WorldPacket & recvData);
	void HandleSQLExecute(WorldPacket & recvData);
	void HandleReloadAccounts(WorldPacket & recvData);
	void HandleAuthChallenge(WorldPacket & recvData);
	void HandleMappingReply(WorldPacket & recvData);
	void HandleUpdateMapping(WorldPacket & recvData);
	void HandleTestConsoleLogin(WorldPacket & recvData);
	void HandleServerPong(WorldPacket &recvData);
	void HandleDatabaseModify(WorldPacket& recvData);
	void HandlePopulationRespond(WorldPacket & recvData);
 
	void RefreshRealmsPop();

	void SendPing();

	uint32 last_ping;
	uint32 next_server_ping;
	bool removed;
	set<uint32> server_ids;
};

typedef void (AuthCommServerSocket::*Authpacket_handler)(WorldPacket&);

#endif

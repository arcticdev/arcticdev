/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#pragma once

#define WORLDSOCKET_SENDBUF_SIZE 131078
#define WORLDSOCKET_RECVBUF_SIZE 16384

class WorldPacket;
class Session;

class WorldSocket : public Socket
{
public:
	bool Authed;
	WorldSocket(SOCKET fd);
	~WorldSocket();

	// vs8 fix - send null on empty buffer
	ARCTIC_INLINE void SendPacket(WorldPacket* packet) { if(!packet) return; OutPacket(packet->GetOpcode(), packet->size(), (packet->size() ? (const void*)packet->contents() : NULL)); }
	ARCTIC_INLINE void SendPacket(StackPacket * packet) { if(!packet) return; OutPacket(packet->GetOpcode(), packet->GetSize(), (packet->GetSize() ? (const void*)packet->GetBufferPointer() : NULL)); }

	void __fastcall OutPacket(uint16 opcode, size_t len, const void* data);
   
	ARCTIC_INLINE uint32 GetLatency() { return _latency; }

	void Authenticate();
	void InformationRetreiveCallback(WorldPacket & recvData, uint32 requestid);

	void OnRead();
	void OnConnect();
	void OnDisconnect();

	void SendAddonInfoPacket(WorldPacket *source, uint32 pos, Session *m_session);
	
protected:
	
	void _HandleAuthSession(WorldPacket* recvPacket);
	void _HandlePing(WorldPacket* recvPacket);

private:

	uint8 K[40];
	uint32 mOpcode;
	uint32 mRemaining;
	uint32 mSize;
	uint32 mSeed;
	uint32 mClientSeed;
	uint32 mClientBuild;
	uint32 mRequestID;

	WorldPacket * pAuthenticationPacket;
	string * m_fullAccountName;
	WowCrypt _crypt;
	uint32 _latency;

	Session * m_session;
};

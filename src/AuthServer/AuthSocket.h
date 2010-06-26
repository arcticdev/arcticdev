/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef AUTHSOCKET_H
#define AUTHSOCKET_H

#include "AccountCache.h"
#include "AuthStructs.h"

class AuthCommServerSocket;
struct Patch;
class PatchJob;

class AuthSocket : public Socket
{
	friend class AuthCommServerSocket;
public:

	//////////////////////////////////////////////////////////////
	// Netcore shit
	//////////////////////////////////////////////////////////////
	
	AuthSocket(SOCKET fd);
	~AuthSocket();

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

	void OnRead();

	//////////////////////////////////////////////////////////////
	// Client Packet Handlers
	//////////////////////////////////////////////////////////////

	void HandleChallenge();
	void HandleProof();
	void HandleRealmlist();
	void HandleReconnectChallenge();
	void HandleReconnectProof();
	void HandleTransferAccept();
	void HandleTransferResume();
	void HandleTransferCancel();

	//////////////////////////////////////////////////////////////
	// Server Packet Builders
	//////////////////////////////////////////////////////////////

	void SendChallengeError(uint8 Error);
	void SendProofError(uint8 Error, uint8 * M2);
	ARCTIC_INLINE sAuthAuthChallenge_C * GetChallenge() { return &m_challenge; }
	ARCTIC_INLINE void SendPacket(const uint8* data, const uint16 len) { Send(data, len); }
	void OnDisconnect();
	ARCTIC_INLINE time_t GetLastRecv() { return last_recv; }
	bool removedFromSet;
	ARCTIC_INLINE uint32 GetAccountID() { return m_account ? m_account->AccountId : 0; }

protected:

	sAuthAuthChallenge_C m_challenge;
	Account * m_account;
	bool m_authenticated;
	std::string AccountName;

	//////////////////////////////////////////////////////////////
	// Authentication BigNumbers
	//////////////////////////////////////////////////////////////
	
	BigNumber N, s, g, v;
	BigNumber b, B;
	BigNumber K;
	BigNumber rs;
    //////////////////////////////////////////////////////////////
	// Session Key
	//////////////////////////////////////////////////////////////

	BigNumber m_sessionkey;
	time_t last_recv;

	//////////////////////////////////////////////////////////////
	// Patching stuff
	//////////////////////////////////////////////////////////////
	
public:
	Patch * m_patch;
	PatchJob * m_patchJob;
};

#endif

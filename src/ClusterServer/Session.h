/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _R_SESSION_H
#define _R_SESSION_H

typedef void(Session::*SessionPacketHandler)(WorldPacket&);

class Session
{
public:
	friend class WorldSocket;
	friend class CharacterStorage;
	Session(uint32 id);
	~Session();

protected:
	FastQueue<WorldPacket*, Mutex> m_readQueue;
	WorldSocket * m_socket;
	WServer * m_server;
	WServer * m_nextServer;
	uint32 m_sessionId;
	uint32 m_accountId;
	RPlayerInfo * m_currentPlayer;
	uint32 m_latency;
	uint32 m_accountFlags;
	string m_GMPermissions;
	string m_accountName;
	uint32 m_build;
	static SessionPacketHandler Handlers[NUM_MSG_TYPES];
	bool m_loadedPlayerData;

public:
	static void InitHandlers();
	void Update();
	ARCTIC_INLINE RPlayerInfo * GetPlayer() { return m_currentPlayer; }

	ARCTIC_INLINE void ClearCurrentPlayer() { m_currentPlayer = 0; }
	ARCTIC_INLINE void ClearServers() { m_nextServer = m_server = 0; }
	ARCTIC_INLINE void SetNextServer() { m_server = m_nextServer; }
	ARCTIC_INLINE void SetServer(WServer * s) { m_server = s; }
	ARCTIC_INLINE WServer * GetServer() { return m_server; }
	ARCTIC_INLINE WorldSocket * GetSocket() { return m_socket; }
	ARCTIC_INLINE uint32 GetAccountId() { return m_accountId; }
	ARCTIC_INLINE uint32 GetSessionId() { return m_sessionId; }

	void SendPacket(WorldPacket * data)
	{
		if(m_socket && m_socket->IsConnected())
			m_socket->SendPacket(data);
	}

	void HandlePlayerLogin(WorldPacket & pck);

	void HandleCharacterEnum(WorldPacket & pck);
	void HandleCharacterEnumProc();

	void HandleCharacterCreate(WorldPacket & pck);
	void HandleCharacterDelete(WorldPacket & pck);
	void HandleCharacterRename(WorldPacket & pck);
	
	void HandleItemQuerySingleOpcode(WorldPacket & pck);
	void HandleCreatureQueryOpcode(WorldPacket & pck);
	void HandleGameObjectQueryOpcode(WorldPacket & pck);
	void HandleItemPageQueryOpcode(WorldPacket & pck);
	void HandleNpcTextQueryOpcode(WorldPacket & pck);

	void HandleRealmSplitQuery(WorldPacket & pck);
};

#endif



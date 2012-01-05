/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#define MAX_SESSIONS_PER_SERVER 1000

struct Instance;
typedef void(WServer::*WServerHandler)(WorldPacket &);

class WServer
{
	static WServerHandler PHandlers[IMSG_NUM_TYPES];
	uint32 m_id;
	WSSocket * m_socket;
	FastQueue<WorldPacket*, Mutex> m_recvQueue;
	list<Instance*> m_instances;

public:
	static void InitHandlers();
	WServer(uint32 id, WSSocket * s);
	~WServer() { sSocketGarbageCollector.QueueSocket(m_socket); };

	ARCTIC_INLINE size_t GetInstanceCount() { return m_instances.size(); }
	ARCTIC_INLINE void SendPacket(WorldPacket * data) { if(m_socket) m_socket->SendPacket(data); }
	ARCTIC_INLINE void SendWoWPacket(Session * from, WorldPacket * data) { if(m_socket) m_socket->SendWoWPacket(from, data); }
	ARCTIC_INLINE void AddInstance(Instance * pInstance) { m_instances.push_back(pInstance); }
	ARCTIC_INLINE void QueuePacket(WorldPacket * data) { m_recvQueue.Push(data); }
	ARCTIC_INLINE uint32 GetID() { return m_id; }

	void Update();

protected:
	/* packet handlers */
	void HandleRegisterWorker(WorldPacket & pck);
	void HandleWoWPacket(WorldPacket & pck);
	void HandlePlayerLoginResult(WorldPacket & pck);
	void HandlePlayerLogout(WorldPacket & pck);
	void HandleTeleportRequest(WorldPacket & pck);
	void HandleError(WorldPacket & pck);
	void HandleSwitchServer(WorldPacket & pck);
	void HandleCreatePlayerResult(WorldPacket & pck);
	void HandleTransporterMapChange(WorldPacket & pck);
	void HandleSaveAllPlayers(WorldPacket & pck);
	void HandlePlayerTeleport(WorldPacket & pck);
	void HandlePlayerInfo(WorldPacket & pck);
	void HandleChannelAction(WorldPacket & pck);
	void HandleChannelUpdate(WorldPacket & pck);
	void HandleChannelLFGDungeonStatusReply(WorldPacket& pck);
};

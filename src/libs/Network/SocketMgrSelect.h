/*
/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2012 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef SOCKETMGR_H_SELECT
#define SOCKETMGR_H_SELECT

#ifdef CONFIG_USE_SELECT

class Socket;
class SERVER_DECL SocketMgr : public Singleton<SocketMgr>
{
	/* FD->Pointer Map */
	map<int, Socket*> fds;

	/* How many sockets are we holding? */
	int socket_count;

	/* Our FD sets */
	FD_SET m_allSet;
	FD_SET m_readableSet;
	FD_SET m_writableSet;
	FD_SET m_exceptionSet;
	Mutex m_setLock;
	
public:

	SocketMgr();
	~SocketMgr();

	// returns number of sockets in array
	inline int Count() { return socket_count; }

	/* socket removal/adding */
	void AddSocket(Socket * s);
	void AddListenSocket(Socket * s);
	void RemoveSocket(Socket * s);
	void WantWrite(int fd);

	void SpawnWorkerThreads();
	void CloseAll();
	void ShutdownThreads();

	void thread_function();
};

#define sSocketMgr SocketMgr::getSingleton()

class SocketWorkerThread : public ThreadBase
{
public:
	void run();
};

#endif
#endif
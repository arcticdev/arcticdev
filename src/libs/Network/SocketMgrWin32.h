/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef SOCKETMGR_H_WIN32
#define SOCKETMGR_H_WIN32

#ifdef CONFIG_USE_IOCP

class Socket;
class ARCTIC_DECL SocketMgr : public Singleton<SocketMgr>
{
public:
	SocketMgr();
	~SocketMgr();

	ARCTIC_INLINE HANDLE GetCompletionPort() { return m_completionPort; }
	void SpawnWorkerThreads();
	void CloseAll();
	void AddSocket(Socket * s)
	{
		socketLock.Acquire();
		_sockets.insert(s);
		socketLock.Release();
	}

	void RemoveSocket(Socket * s)
	{
		socketLock.Acquire();
		_sockets.erase(s);
		socketLock.Release();
	}

	void ShutdownThreads();
	long threadcount;

private:
	HANDLE m_completionPort;
	set<Socket*> _sockets;
	Mutex socketLock;
};

#define sSocketMgr SocketMgr::getSingleton()

typedef void(*OperationHandler)(Socket * s, uint32 len);

class SocketWorkerThread : public ThreadContext
{
public:
	bool run();
};

void ARCTIC_DECL HandleReadComplete(Socket * s, uint32 len);
void ARCTIC_DECL HandleWriteComplete(Socket * s, uint32 len);
void ARCTIC_DECL HandleShutdown(Socket * s, uint32 len);

static OperationHandler ophandlers[NUM_SOCKET_IO_EVENTS] = {
	&HandleReadComplete,
	&HandleWriteComplete,
	&HandleShutdown };

#endif
#endif
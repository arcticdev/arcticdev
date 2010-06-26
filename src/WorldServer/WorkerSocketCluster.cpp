/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

#ifdef CLUSTERING

//Конструктор и деструктор для динамических строк в объектах
void *WorldSocket::operator new(size_t size)
{
	sLog.outDebug("New WorldSocket dynamic string in object.");
	return malloc(size);
}

void WorldSocket::operator delete(void* p)
{
	sLog.outDebug("Delete WorldSocket dynamic string in object.");
	free(p);
}

WorldSocket::WorldSocket(uint32 sessionid) : m_sessionId(sessionid)
{

}

WorldSocket::~WorldSocket()
{

}

void WorldSocket::Disconnect()
{

}

bool WorldSocket::IsConnected()
{
	return true;
}

void WorldSocket::OutPacket(uint16 opcode, uint16 len, const void* data)
{
	sClusterInterface.ForwardWoWPacket(opcode, len, data, m_sessionId);
}

#endif

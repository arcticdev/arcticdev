/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

/*
 * Voice Chat Engine
 * Copyright (C) 2005-2007 Burlex <burlex@gmail.com>
 * Copyright (C) 2008-2010 schnek <schnek@gmail.com>
 */ 
 
#ifndef _VOICECHATCLIENTSOCKET_H
#define _VOICECHATCLIENTSOCKET_H

#ifdef VOICE_CHAT

class VoiceChatClientSocket : public Socket
{
	uint16 op;
	uint16 remaining;
public:
	VoiceChatClientSocket(uint32 fd);
	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);
	void OnDisconnect();
	void OnRead();
	void SendPacket(WorldPacket* data);
	time_t next_ping;
	time_t last_pong;
};

#endif		// VOICE_CHAT
#endif		// _VOICECHATCLIENTSOCKET_H


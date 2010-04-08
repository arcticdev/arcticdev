/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

class ChannelMgr :  public Singleton < ChannelMgr >
{
public:
	ChannelMgr();
	~ChannelMgr();

	Channel *GetCreateChannel(const char *name, PlayerPointer p, uint32 type_id);
	Channel *GetChannel(const char *name, PlayerPointer p);
	Channel * GetChannel(const char * name, uint32 team);
	Channel *GetChannel(uint32 id);
#ifdef VOICE_CHAT
	void VoiceDied();
#endif
	void RemoveChannel(Channel * chn);
	bool seperatechannels;

private:
	// Team 0: aliance, team 1 horde
	typedef map<string,Channel *> ChannelList;
	typedef HM_NAMESPACE::hash_map<uint32, Channel*> ChannelMap;
	ChannelMap m_idToChannel;
	uint32 m_idHigh;
	ChannelList Channels[2];
	Mutex lock;
};

#define channelmgr ChannelMgr::getSingleton()

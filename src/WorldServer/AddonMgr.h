/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __ADDONMGR_H
#define __ADDONMGR_H

struct AddonEntry
{
	std::string name;
	uint64 crc;
	bool banned;
	bool isNew;
	bool showinlist;
};

typedef std::map<std::string, AddonEntry *> KnownAddons;
typedef KnownAddons::iterator KnownAddonsItr;

typedef std::map<std::string, ByteBuffer> AddonData;
typedef AddonData::iterator AddonDataItr;

class AddonMgr : public Singleton < AddonMgr >
{
public:
	AddonMgr();
	~AddonMgr();

	//Конструктор и деструктор для динамических строк в объектах
	void *operator new(size_t);
	void operator delete(void*);

	void		LoadFromDB();
	void		SaveToDB();

	void		SendAddonInfoPacket(WorldPacket *source, uint32 pos, WorldSession *m_session);
	bool		AppendPublicKey(WorldPacket &data, std::string &AddonName, uint32 CRC);

private:
	bool		IsAddonBanned(uint64 crc, std::string name = "");
	bool		IsAddonBanned(std::string name, uint64 crc = 0);
	bool		ShouldShowInList(std::string name);

	KnownAddons	mKnownAddons;
	AddonData	mAddonData;
};

#define sAddonMgr AddonMgr::getSingleton()

#endif

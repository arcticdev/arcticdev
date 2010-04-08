/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

initialiseSingleton( AddonMgr );

// Prints out Received addon packet when char logging in
// #define DEBUG_PRINT_ADDON_PACKET	

AddonMgr::AddonMgr()
{
	KnownAddons.clear();
}

AddonMgr::~AddonMgr()
{
	std::map<std::string, AddonEntry*>::iterator itr;
	for(itr = KnownAddons.begin(); itr!=KnownAddons.end(); ++itr) 
	{
		delete itr->second;
	}
	KnownAddons.clear();
}

bool AddonMgr::IsAddonBanned(uint32 crc, std::string name)
{
	return false; // Bleh needs work
}

bool AddonMgr::IsAddonBanned(std::string name, uint32 crc)
{
	std::map<std::string,AddonEntry*>::iterator i = KnownAddons.find(name);
	if(i != KnownAddons.end())
	{
		if(i->second->banned)
		{
			OUT_DEBUG("Addon %s is banned.", name.c_str());
			return true;
		}
	}
	else
	{
		// New addon. It'll be saved to db at server shutdown.
		AddonEntry *ent = new AddonEntry;
		ent->name = name;
		ent->crc = crc;
		ent->banned = false; // We can change this I guess..
		ent->isNew = true;
		ent->showinlist = (crc == 0x4C1C776D ? false : true);

		OUT_DEBUG("Discovered new addon %s sent by client.", name.c_str());

		KnownAddons[ent->name] = ent;
	}

	return false;
}

bool AddonMgr::ShouldShowInList(std::string name, uint32 crc)
{
	std::map<std::string,AddonEntry*>::iterator i = KnownAddons.find(name);
	if(i != KnownAddons.end())
	{
		if(i->second->showinlist)
			return true;
		else
			return false;
	}
	else
	{
		// New addon. It'll be saved to db at server shutdown.		
		AddonEntry *ent = new AddonEntry;
		ent->name = name;
		ent->crc = crc;
		ent->banned = false; // We can change this I guess..
		ent->isNew = true;
		ent->showinlist = (crc == 0x4C1C776D ? false : true);

		DEBUG_LOG("AddonMgr","Discovered new addon %s sent by client.", name.c_str());

		KnownAddons[ent->name] = ent;
	}
	return true;
}

void AddonMgr::SendAddonInfoPacket(WorldPacket *source, uint32 pos, WorldSession *m_session)
{
	WorldPacket returnpacket;
	returnpacket.Initialize(SMSG_ADDON_INFO); // SMSG_ADDON_INFO

	uint32 realsize;
	uLongf rsize;
	try
	{
		*source >> realsize;
	}
	catch (ByteBuffer::error &)
	{
		DEBUG_LOG("AddonMgr","Warning, Incomplete auth session sent.");
		return;
	}	
	rsize = realsize;
	size_t position = source->rpos();

	ByteBuffer unpacked;
	unpacked.resize(realsize);

	if((source->size() - position) < 4 || realsize == 0)
	{
		// We shouldnt get here.. but just in case this will stop any crash here.
		DEBUG_LOG("AddonMgr","Warning, Incomplete auth session sent.");
		return;
	}
	int32 result;
	result = uncompress((uint8*)unpacked.contents(), &rsize, (uint8*)(*source).contents() + position, (uLong)((*source).size() - position));

	if(result != Z_OK)
	{
		DEBUG_LOG("AddonMgr","Decompression of addon section of CMSG_AUTH_SESSION failed.");
		return;
	}

	DEBUG_LOG("AddonMgr","Decompression of addon section of CMSG_AUTH_SESSION succeeded.");

	uint32 addons; // Added in 3.0.8
	uint8 Enable;  // Based on the parsed files from retool
	uint32 crc;
	uint32 unknown;

	unpacked >> addons;
	size_t p = unpacked.rpos(); 
	if( p + (addons*10) > unpacked.size() - p - 4) 
	{ 
		// Stupid fucker, trying to make us waste CPU cycles 
		m_session->Disconnect(); 
		return; 
	}

	std::string name;
	for (uint32 i = 0; i < addons; ++i)
	{
		unpacked >> name;
		unpacked >> Enable;
		unpacked >> crc;
		unpacked >> unknown;

		// Yea I know its a hacky fix I will make a proper handler one's I got the crc crap
		if (crc != 0x4C1C776D) // CRC of public key version 2.0.1
			returnpacket.append(PublicKey,264);
		else
			returnpacket << uint8(0x02) << uint8(0x01) << uint8(0x00) << uint32(0) << uint8(0);
	}

	uint32 unk308;

	unpacked >> unk308;
	m_session->SendPacket(&returnpacket);
}

bool AddonMgr::AppendPublicKey(WorldPacket& data, string AddonName, uint32 CRC)
{
	if(CRC == 0x4C1C776D)
	{
		// Open public key file with that addon
		map<string, ByteBuffer>::iterator itr = AddonData.find(AddonName);
		if(itr != AddonData.end())
			data.append(itr->second);
		else
		{
			// Open the file
			char path[500];
			snprintf(path, 500, "addons\\%s.pub", AddonName.c_str());
			FILE * f = fopen(path, "rb");
			if(f != 0)
			{
				// Read the file into a bytebuffer
				ByteBuffer buf;
				fseek(f, 0, SEEK_END);
				uint32 length = 264;
				fseek(f, 0, SEEK_SET);
				buf.resize(length);
				fread((void*)buf.contents(), length, 1, f);
				fclose(f);

				AddonData[AddonName] = buf;
				data.append(buf);
			}
			else
			{
				ByteBuffer buf;
				buf.append(PublicKey, 264);
				AddonData[AddonName] = buf;
				data.append(buf);
			}
		}
		return true;
	}
	return false;
}

void AddonMgr::LoadFromDB()
{
	QueryResult *result = WorldDatabase.Query("SELECT * FROM clientaddons");
	if(!result)
	{
		sLog.outString("Query failed: SELECT * FROM clientaddons");
		return;
	}
	do 
	{
		Field *field = result->Fetch();
		AddonEntry *ent = new AddonEntry;

		ent->name = field[1].GetString();
		ent->crc = field[2].GetUInt64();
		ent->banned = (field[3].GetUInt32()>0? true:false);
		ent->isNew = false;
		if(result->GetFieldCount() == 5) // To avoid crashes for stilly nubs who don't update table 
			ent->showinlist = (field[4].GetUInt32()>0 ? true : false);

		KnownAddons[ent->name] = ent;
	} while(result->NextRow());

	delete result;
}

void AddonMgr::SaveToDB()
{
	DEBUG_LOG("AddonMgr","Saving any new addons discovered in this session to database.");
	for(std::map<std::string, AddonEntry*>::iterator itr = KnownAddons.begin();itr!=KnownAddons.end();++itr)
	{
		if(itr->second->isNew)
		{
			OUT_DEBUG("Saving new addon %s", itr->second->name.c_str());
			std::stringstream ss;
			ss << "INSERT INTO clientaddons (name, crc, banned, showinlist) VALUES(\""
				<< WorldDatabase.EscapeString(itr->second->name) << "\",\""
				<< itr->second->crc << "\",\""
				<< itr->second->banned << "\",\""
				<< itr->second->showinlist << "\");";

			WorldDatabase.Execute(ss.str().c_str());
		}
	}
}

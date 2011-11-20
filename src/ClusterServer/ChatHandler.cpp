/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2011 Arctic Server Team
 * See COPYING for license details.
 */

#include "RStdAfx.h"

static const uint32 LanguageSkills[NUM_LANGUAGES] = {
	0,				// UNIVERSAL		0x00
	109,			// ORCISH			0x01
	113,			// DARNASSIAN		0x02
	115,			// TAURAHE			0x03
	0,				// -				0x04
	0,				// -				0x05
	111,			// DWARVISH			0x06
	98,				// COMMON			0x07
	139,			// DEMON TONGUE		0x08
	140,			// TITAN			0x09
	137,			// THALSSIAN		0x0A
	138,			// DRACONIC			0x0B
	0,				// KALIMAG			0x0C
	313,			// GNOMISH			0x0D
	315,			// TROLL			0x0E
	0,				// -				0x0F
	0,				// -				0x10
	0,				// -				0x11
	0,				// -				0x12
	0,				// -				0x13
	0,				// -				0x14
	0,				// -				0x15
	0,				// -				0x16
	0,				// -				0x17
	0,				// -				0x18
	0,				// -				0x19
	0,				// -				0x1A
	0,				// -				0x1B
	0,				// -				0x1C
	0,				// -				0x1D
	0,				// -				0x1E
	0,				// -				0x1F
	0,				// -				0x20
	673,			// -				0x21
	0,				// -				0x22
	759,			// -				0x23
};

void Session::HandleMessagechatOpcode( WorldPacket & recv_data )
{
	CHECK_PACKET_SIZE(recv_data, 9);
	WorldPacket *data;
	//CHECK_INWORLD_RETURN;

	uint32 type;
	int32 lang;

	recv_data >> type;
	// were only going to handle these types here, otherwise send it to the world server for processing
	if( type != CHAT_MSG_CHANNEL && type != CHAT_MSG_WHISPER )
	{
		GetServer()->SendWoWPacket(this, &recv_data);
	}
	recv_data >> lang;

	if( lang >= NUM_LANGUAGES )
		return;

	/*
	if(GetPlayer()->IsBanned())
		{
			SystemMessage("You cannot do that when banned.");
			return;
		}*/
	

	string msg, misc;

	// special misc
	if( type == CHAT_MSG_CHANNEL || type == CHAT_MSG_WHISPER )
	{
		recv_data >> misc;
		recv_data >> msg;
	}
	else
		recv_data >> msg;

	/*
	if(!sHookInterface.OnChat(TO_PLAYER(_player), type, lang, msg, misc))
			return;*/
	

	// Idiots spamming giant pictures through the chat system
	if( msg.find("|TInterface") != string::npos || msg.find("\n") != string::npos)
	{
		sChatHandler.SystemMessage(this, "Your message has been blocked.");
		return;
	}

	if(  msg.find("|c") != string::npos && msg.find("|H") == string::npos )
	{
		return;
	}

	switch(type)
	{
	case CHAT_MSG_WHISPER:
		{
			RPlayerInfo* player = sClientMgr.GetRPlayer(misc.c_str());
			if(!player)
			{
				ARCTIC_TOLOWER(misc);
				if( misc == "console" )
				{
					Log.Notice("Whisper","%s to %s: %s", GetPlayer()->Name, misc.c_str(), msg.c_str());
					return;
				}
				else
				{
					data = new WorldPacket(SMSG_CHAT_PLAYER_NOT_FOUND, misc.length() + 1);
					*data << misc;
					SendPacket(data);
					delete data;
				}
				break;
			}

			// Check that the player isn't a gm
			if(!GetPlayer()->GMPermissions.size() && player->GMPermissions.size())
			{
				// Build automated reply
				string Reply = "This Game Master does not currently have an open ticket from you and did not receive your whisper. Please submit a new GM Ticket request if you need to speak to a GM. This is an automatic message.";
				data = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.c_str(), uint64(player->Guid), 3);
				SendPacket(data);
				delete data;
				break;
			}

			if(lang > 0 && LanguageSkills[lang] /* && _player->_HasSkillLine(LanguageSkills[lang]) == false*/)
				return;

			if(lang==0 && !CanUseCommand("c"))
				return;

					data = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, ((CanUseCommand("c") || player->GetSession()->CanUseCommand("c")) && lang != -1) ? LANG_UNIVERSAL : lang,  msg.c_str(), uint64(GetPlayer()->Guid), GetPlayer()->GMPermissions.size() ? 4 : 0 );

				player->GetSession()->SendPacket(data);
				delete data;

			//Sent the to Users id as the channel, this should be fine as it's not used for whisper

			data = sChatHandler.FillMessageData(CHAT_MSG_WHISPER_INFORM, LANG_UNIVERSAL,msg.c_str(), uint64(player->Guid), player->GMPermissions.size() ? 4 : 0  );
			SendPacket(data);
			delete data;

		} break;
	case CHAT_MSG_CHANNEL:
		{
			if (sChatHandler.ParseCommands(msg.c_str(), this) > 0)
				break;

			Channel *chn = channelmgr.GetChannel(misc.c_str(),GetPlayer()); 
			if(chn != NULL)
				chn->Say(GetPlayer(),msg.c_str(), NULL, false);
		} break;

	default:
		OUT_DEBUG("CHAT: unknown msg type %u, lang: %u", type, lang);
	}
}

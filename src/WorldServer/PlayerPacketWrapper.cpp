/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#include "StdAfx.h"

void Player::SendWorldStateUpdate(uint32 WorldState, uint32 Value)
{
	packetSMSG_WORLD_STATE_UPDATE pck;
	pck.State = WorldState;
	pck.Value = Value;

	GetSession()->OutPacket(SMSG_UPDATE_WORLD_STATE, sizeof(packetSMSG_WORLD_STATE_UPDATE), (const char*)&pck);
}

void Player::Gossip_SendPOI(float X, float Y, uint32 Icon, uint32 Flags, uint32 Data, const char* Name)
{
	WorldPacket data(SMSG_GOSSIP_POI, 50);
	 data << uint32( Flags ); 
	data << float( X ); 
	data << float( Y );
	data << uint32( Icon ); 
	data << uint32( Data ); 
	data << uint32( Name ); 
	GetSession()->SendPacket(&data);
}
  
void Player::SendLevelupInfo(uint32 level, uint32 Hp, uint32 Mana, uint32 Stat0, uint32 Stat1, uint32 Stat2, uint32 Stat3, uint32 Stat4)
{
    WorldPacket data( SMSG_LEVELUP_INFO, 14 * 4 ); 
    data << uint32( level ); 
    data << uint32( Hp ); 
    data << uint32( Mana ); 

    for( int i = 0; i < 6; ++i )
        data << uint32( 0 ); 
    
	// Append stat differences
    data << uint32( Stat0 ); 
    data << uint32( Stat1 ); 
    data << uint32( Stat2 ); 
    data << uint32( Stat3 );
    data << uint32( Stat4 ); 
    
	m_session->SendPacket( &data ); 
}

void Player::SendLogXPGain(uint64 guid, uint32 NormalXP, uint32 RestedXP, bool type)
{
    WorldPacket data( SMSG_LOG_XPGAIN, 24 ); 
	
    if (type == false)
    {
        data << uint64( guid );
        data << uint32( NormalXP ); 
        if( type ) 
            data << uint8( 1 ); 
        else
		    data << uint8( 0 );
		data << uint32( RestedXP );
        data << float( 1.0f ); 
    }
    else if (type == true)
    {
        data << uint64( 0 );          // does not need to be set for questxp 
        data << uint32( NormalXP ); 
        if( type ) 
            data << uint8( 1 ); 
 	    else 
 	        data << uint8( 0 ); 
        
        data << uint8( 0 ); 
    }
    m_session->SendPacket( &data );
}

void Player::SendEnvironmentalDamageLog(const uint64 & guid, uint8 type, uint32 damage)
{ 
    WorldPacket data( SMSG_ENVIRONMENTALDAMAGELOG, 12 ); 

    data << uint64( guid ); 
    data << uint8( type ); 
    data << uint32( damage ); 

    m_session->SendPacket( &data ); 
} 

void Player::SendCastResult(uint32 SpellId, uint8 ErrorMessage, uint8 MultiCast, uint32 Extra)
{ 
    WorldPacket data( SMSG_CAST_FAILED, 80 ); 
    data << uint32( SpellId ); 
    data << uint8( ErrorMessage ); 
    data << uint8( MultiCast ); 
} 

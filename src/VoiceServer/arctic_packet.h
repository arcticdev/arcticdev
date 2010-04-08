/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __ARCTIC_PACKET_H
#define __ARCTIC_PACKET_H

typedef struct  
{
	uint32 opcode;
	uint32 size;
	uint8* buffer;
	uint32 buffer_size;
	uint32 rpos;
	uint32 wpos;
	int stack;
} arctic_packet;

static arctic_packet* arcticpacket_create(uint32 opcode, uint32 size)
{
	arctic_packet * p;

	p = (arctic_packet*)vc_malloc(sizeof(arctic_packet));
	p->buffer = (uint8*)vc_malloc(size);
	p->buffer_size = size;
	p->opcode = opcode;
	p->size = size;
	p->wpos = p->rpos = 0;
	p->stack = 0;

	return p;
}

static void arcticpacket_init(uint32 opcode, uint32 size, arctic_packet *p)
{
	p->buffer = (uint8*)vc_malloc(size);
	p->buffer_size = size;
	p->opcode = opcode;
	p->size = size;
	p->wpos = p->rpos = 0;
	p->stack = 1;
}

static uint8* arcticpacket_getbuf(arctic_packet* p)
{
	return &p->buffer[p->wpos];
}

static void arcticpacket_free(arctic_packet* p)
{
	free(p->buffer);
	if( !p->stack )
		free(p);
}

#define DECLARE_ARCTICPACKET_OPERATOR(t, name) static t name(arctic_packet* p) { \
	uint32 orpos = p->rpos; \
	p->rpos += sizeof(t); \
	return *(t*)&p->buffer[orpos]; }

DECLARE_ARCTICPACKET_OPERATOR(uint32, arcticpacket_readu32);
DECLARE_ARCTICPACKET_OPERATOR(int32, arcticpacket_readi32);
DECLARE_ARCTICPACKET_OPERATOR(uint16, arcticpacket_readu16);
DECLARE_ARCTICPACKET_OPERATOR(int16, arcticpacket_readi16);
DECLARE_ARCTICPACKET_OPERATOR(uint8, arcticpacket_readu8);
DECLARE_ARCTICPACKET_OPERATOR(int8, arcticpacket_readi8);

#define DECLARE_ARCTICPACKET_WRITE_OPERATOR(t, name) static void name(arctic_packet* p, t v) { \
	*(t*)&p->buffer[p->wpos] = v; \
	p->wpos += sizeof(t); } 

DECLARE_ARCTICPACKET_WRITE_OPERATOR(uint32, arcticpacket_writeu32);
DECLARE_ARCTICPACKET_WRITE_OPERATOR(int32, arcticpacket_writei32);
DECLARE_ARCTICPACKET_WRITE_OPERATOR(uint16, arcticpacket_writeu16);
DECLARE_ARCTICPACKET_WRITE_OPERATOR(int16, arcticpacket_writei16);
DECLARE_ARCTICPACKET_WRITE_OPERATOR(uint8, arcticpacket_writeu8);
DECLARE_ARCTICPACKET_WRITE_OPERATOR(int8, arcticpacket_writei8);

#endif

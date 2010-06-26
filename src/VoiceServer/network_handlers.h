/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef __NETWORK_HANDLERS_H
#define __NETWORK_HANDLERS_H

int voicechat_arctic_listen_socket_read_handler(network_socket *s, int act);
int voicechat_arctic_socket_read_handler(network_socket *s, int act);
int voicechat_client_socket_read_handler(network_socket *s, int act);

int voicechat_init_clientsocket();
int voicechat_init_serversocket();
int get_server_count();

#endif


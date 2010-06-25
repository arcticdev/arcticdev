/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _MAINSERVER_DEFINES_H
#define _MAINSERVER_DEFINES_H

class Database;

SERVER_DECL extern Database* Database_Character;
SERVER_DECL extern Database* Database_World;

#define WorldDatabase (*Database_World)
#define CharacterDatabase (*Database_Character)

#endif

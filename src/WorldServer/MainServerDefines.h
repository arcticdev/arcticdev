/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _MAINSERVER_DEFINES_H
#define _MAINSERVER_DEFINES_H

class Database;

ARCTIC_DECL extern Database* Database_Character;
ARCTIC_DECL extern Database* Database_World;

#define WorldDatabase (*Database_World)
#define CharacterDatabase (*Database_Character)

#endif

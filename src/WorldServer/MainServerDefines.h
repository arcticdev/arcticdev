/*
 * Arctic MMORPG Software
 * Copyright (c) 2008-2014 Arctic
 * See COPYING for license details.
 */

#pragma once

class Database;

SERVER_DECL extern Database* Database_Character;
SERVER_DECL extern Database* Database_World;

#define WorldDatabase (*Database_World)
#define CharacterDatabase (*Database_Character)

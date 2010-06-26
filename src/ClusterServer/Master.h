/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#ifndef _R_MASTER_H
#define _R_MASTER_H

extern Database * Database_World;
extern Database * Database_Character;

#define WorldDatabase (*Database_World)
#define CharacterDatabase (*Database_Character)

#endif

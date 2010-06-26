/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2010 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <iostream>

#include "Common.h"
#include <Network/Network.h>

#include "../libs/Log.h"
#include "../libs/Util.h"
#include "../libs/ByteBuffer.h"
#include "../libs/Config/ConfigEnv.h"
#include <zlib.h>

#include "../libs/Database/DatabaseEnv.h"
#include "../libs/Database/DBCStores.h"
#include "../libs/Database/dbcfile.h"

#include "../libs/Auth/BigNumber.h"
#include "../libs/Auth/Sha1.h"
#include "../libs/Auth/WowCrypt.h"
#include "../libs/CrashHandler.h"

#include "AuthOpcodes.h"
#include "Main.h"
#include "../WorldServer/NameTables.h"
#include "AccountCache.h"
#include "PeriodicFunctionCall_Thread.h"
#include "AutoPatcher.h"
#include "AuthSocket.h"
#include "AuthStructs.h"
#include "AuthOpcodes.h"
#include "AuthCommServer.h"
#include "AuthConsole.h"
#include "../libs/WorldPacket.h"

// database decl
extern Database* sAuthSQL;
using namespace std;
/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2011 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <string>
//#include <fstream>

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

#include "LogonOpcodes.h"
#include "../AuthServer/Main.h"
#include "../WorldServer/NameTables.h"
#include "AccountCache.h"
#include "PeriodicFunctionCall_Thread.h"
#include "../AuthServer/AutoPatcher.h"
#include "../AuthServer/AuthSocket.h"
#include "../AuthServer/AuthStructs.h"
#include "../AuthServer/LogonOpcodes.h"
#include "../AuthServer/LogonCommServer.h"
#include "../AuthServer/LogonConsole.h"
#include "../libs/WorldPacket.h"

// database decl
extern Database* sLogonSQL;
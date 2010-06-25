/*
 * Arctic MMORPG Server Software
 * Copyright (c) 2008-2009 Arctic Server Team
 * See COPYING for license details.
 */

#pragma once

#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <string>
//#include <fstream>

#include "../libs/Common.h"
#include "../libs/MersenneTwister.h"
#include "../libs/WorldPacket.h"
#include "../libs/Log.h"
#include "../libs/NGLog.h"
#include "../libs/ByteBuffer.h"
#include "../libs/StackBuffer.h"
#include "../libs/Config/ConfigEnv.h"
#include "../libs/crc32.h"
#include "../libs/LocationVector.h"

#include <zlib.h>

#include "../libs/Database/DatabaseEnv.h"
#include "../libs/Database/DBCStores.h"
#include "../libs/Database/dbcfile.h"
#include "../libs/FastQueue.h"

#include <Network/Network.h>

#include "../libs/Auth/MD5.h"
#include "../libs/Auth/BigNumber.h"
#include "../libs/Auth/Sha1.h"
#include "../libs/Auth/WowCrypt.h"
#include "../libs/CrashHandler.h"

#include "../WorldServer/NameTables.h"
#include "../WorldServer/Opcodes.h"
#include "../libs/CallBack.h"

#include "Master.h"
#include "WorkerOpcodes.h"
#include "WorkerServerSocket.h"
#include "Structures.h"
#include "WorldSocket.h"
#include "Session.h"
#include "WorkerServer.h"
#include "ClusterManager.h"
#include "ClientManager.h"
#include "AuthCommClient.h"
#include "AuthCommHandler.h"
#include "../libs/Storage.h"
#include "ObjectStorage.h"
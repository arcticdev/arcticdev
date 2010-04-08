# Arctic MMORPG Server Software
# Copyright (c) 2008-2010 Arctic Server Team
# See COPYING for license details.

INCLUDES += -I$(srcdir) -I$(srcdir)/../libs

bin_PROGRAMS = ClusterServer
    ClusterServer_SOURCES = \
    ClientManager.h \
    ClusterManager.h \
    AuthCommClient.h \
    AuthCommHandler.h \
    Master.h \
    ObjectStorage.h \
    RStdAfx.h \
    Session.h \
    Structures.h \
    WorkerOpcodes.h \
    WorkerServer.h \
    WorkerServerSocket.h \
    WorldSocket.h \
    CharacterHandler.cpp \
    ClientManager.cpp \
    ClusterManager.cpp \
    AuthCommClient.cpp \
    AuthCommHandler.cpp \
    Master.cpp \
    ObjectStorage.cpp \
    QueryHandler.cpp \
    RStdAfx.cpp \
    Session.cpp \
    WorkerServer.cpp \
    WorkerServerSocket.cpp \
    WorldSocket.cpp 
	
ClusterServer_LDADD = -lshared -lz

ClusterServer_LDFLAGS = -L$(srcdir)/../libs \
               -L/usr/lib

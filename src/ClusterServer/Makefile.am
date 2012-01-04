INCLUDES += -I$(srcdir) -I$(srcdir)/../libs

bin_PROGRAMS = ClusterServer
ClusterServer_SOURCES = \
	ClientManager.h \
	ClusterManager.h \
	LogonCommClient.h \
	LogonCommHandler.h \
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
	LogonCommClient.cpp \
	LogonCommHandler.cpp \
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
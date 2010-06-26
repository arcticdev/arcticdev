# Arctic MMORPG Server Software
# Copyright (c) 2008-2010 Arctic Server Team
# See COPYING for license details.

INCLUDES += -I$(srcdir) -I$(srcdir)/../../dep/include -I$(srcdir)/../libs

bin_PROGRAMS = AuthServer

AuthServer_SOURCES = \
AccountCache.cpp \
AccountCache.h \
AuthSocket.cpp \
AuthSocket.h \
AuthStructs.h \
AuthCommServer.cpp \
AuthCommServer.h \
AuthConsole.cpp \
AuthConsole.h \
AuthOpcodes.cpp \
AuthOpcodes.h \
AuthStdAfx.cpp \
AuthStdAfx.h \
AutoPatcher.h \
AutoPatcher.cpp \
Main.cpp \
Main.h \
PeriodicFunctionCall_Thread.h

AuthServer_LDADD = -lshared -lz
AuthServer_LDFLAGS = -L$(srcdir)/../libs

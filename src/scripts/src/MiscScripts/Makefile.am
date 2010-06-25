INCLUDES = -I$(top_srcdir)/src/AuthServer \
   -I$(top_srcdir)/src/ClusterServer -I$(top_srcdir)/src/libs -I$(top_srcdir)/src/VoiceServer \
   -I$(top_srcdir)/src/WorldServer -I$(srcdir) -I$(srcdir)/../../../../dep/include \
   -I$(srcdir)/../../../../dep/src -I$(srcdir)/../../../../src
INCLUDES += -I$(srcdir)/../../../libs/g3dlite -I$(srcdir)/../../../libs/vmap

AM_CXXFLAGS = -DSCRIPTLIB

lib_LTLIBRARIES = libSunMiscScripts.la

libSunMiscScripts_la_SOURCES = Creatures.cpp \
GameObjects.cpp \
RandomScripts.cpp \
QuelDanasPortal.cpp \
DarkmoonFaireObjects.cpp \
Setup.cpp

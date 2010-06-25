INCLUDES = -I$(top_srcdir)/src/AuthServer \
   -I$(top_srcdir)/src/ClusterServer -I$(top_srcdir)/src/libs -I$(top_srcdir)/src/VoiceServer \
   -I$(top_srcdir)/src/WorldServer -I$(srcdir) -I$(srcdir)/../../../../dep/include \
   -I$(srcdir)/../../../../dep/src -I$(srcdir)/../../../../src
INCLUDES += -I$(srcdir)/../../../libs/g3dlite -I$(srcdir)/../../../libs/vmap
AM_CXXFLAGS = -DSCRIPTLIB

lib_LTLIBRARIES = libSpellHandlers.la

libSpellHandlers_la_SOURCES = DruidSpells.cpp HunterSpells.cpp ItemSpells_1.cpp \
MageSpells.cpp PaladinSpells.cpp PriestSpells.cpp OldSpellCPPStuff.cpp RogueSpells.cpp \
ShamanSpells.cpp WarlockSpells.cpp WarriorSpells.cpp Raid_BlackTemple.cpp QIspells.cpp Setup.cpp

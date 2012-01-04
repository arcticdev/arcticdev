INCLUDES = -I$(top_srcdir)/src/AuthServer \
   -I$(top_srcdir)/src/ClusterServer -I$(top_srcdir)/src/libs \
   -I$(top_srcdir)/src/WorldServer -I$(srcdir) -I$(srcdir)/../../../../dep/include \
   -I$(srcdir)/../../../../dep/src -I$(srcdir)/../../../../src
INCLUDES += -I$(srcdir)/../../../libs/g3dlite -I$(srcdir)/../../../libs/vmap \
            -I../Common/

AM_CXXFLAGS = -DSCRIPTLIB

lib_LTLIBRARIES = libInstanceScripts.la
libInstanceScripts_la_SOURCES = Raid_BlackTemple.cpp \
    Raid_BlackwingLair.cpp \
    Raid_CoT_BattleOfMountHyjal.cpp \
    Raid_GruulsLair.cpp \
    Raid_Karazhan.cpp \
    Raid_MoltenCore.cpp \
    Raid_Naxxramas.cpp \
    Raid_OnyxiasLair.cpp \
    Raid_SerpentshrineCavern.cpp \
    Raid_TheEye.cpp \
    Raid_TheObsidianSanctum.cpp \
    Raid_Ulduar.cpp \
    Raid_ZulGurub.cpp \
    Raid_Magtheridons_Lair.cpp \
    Raid_SunwellPlateau.cpp \
    Raid_WorldBosses.cpp \
    Raid_ZulAman.cpp \
    ../Common/Instance_Base.cpp \
    ../Common/Base.cpp \
    Setup.cpp

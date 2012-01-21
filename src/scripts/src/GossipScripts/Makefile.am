INCLUDES = -I$(top_srcdir)/src/AuthServer \
   -I$(top_srcdir)/src/ClusterServer -I$(top_srcdir)/src/libs \
   -I$(top_srcdir)/src/WorldServer -I$(srcdir) -I$(srcdir)/../../../../dep/include \
   -I$(srcdir)/../../../../dep/src -I$(srcdir)/../../../../src
INCLUDES += -I$(srcdir)/../../../libs/g3dlite -I$(srcdir)/../../../libs/vmap

AM_CXXFLAGS = -DSCRIPTLIB

lib_LTLIBRARIES = libGossipScripts.la
libGossipScripts_la_SOURCES = \
    Gossip_Innkeepers.cpp \
    Gossip_Guard.cpp \
    Gossip_Trainer.cpp \
    Gossip_Mulgore.cpp \
    Gossip_Shattrath.cpp \
    Gossip_Tanaris.cpp \
    Gossip_Stormwind.cpp \
    Gossip_Moonglade.cpp \
    Gossip_Theramore.cpp \
    Gossip_BoreanTundra.cpp \
    Gossip_WyrmrestTemple.cpp \
    Setup.cpp
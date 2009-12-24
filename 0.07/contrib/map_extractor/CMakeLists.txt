# Arctic MMORPG Server Software
# Copyright (c) 2008-2009 Arctic Server Team
# See COPYING for license details.

cmake_minimum_required (VERSION 2.6)
project (ARCTIC_MAP_EXTRACTOR)

add_subdirectory (libmpq)
add_subdirectory (loadlib)

include_directories (${ARCTIC_MAP_EXTRACTOR_SOURCE_DIR}/libmpq) 
include_directories (${ARCTIC_MAP_EXTRACTOR_SOURCE_DIR}/loadlib) 

link_directories (${ARCTIC_MAP_EXTRACTOR_SOURCE_DIR}/libmpq) 
link_directories (${ARCTIC_MAP_EXTRACTOR_SOURCE_DIR}/loadlib) 

add_executable (ad dbcfile.cpp mpq_libmpq.cpp System.cpp)

target_link_libraries (ad libmpq)
target_link_libraries (ad loadlib)

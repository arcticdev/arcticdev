# Arctic MMORPG Server Software
# Copyright (c) 2008-2009 Arctic Server Team
# See COPYING for license details.

add_library (libmpq common.cpp  explode.cpp  extract.cpp  huffman.cpp  mpq.cpp  parser.cpp  wave.cpp )
# link libmpq with zlib
target_link_libraries (libmpq z)

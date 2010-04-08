# Arctic MMORPG Server Software
# Copyright (c) 2008-2009 Arctic Server Team
# See COPYING for license details.

add_library (loadlib loadlib.cpp  adt.cpp  wdt.cpp)
# link loadlib with zlib
target_link_libraries (loadlib z)

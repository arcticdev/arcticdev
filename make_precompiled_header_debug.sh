#!/bin/sh
echo Extracting svn_revision...
sh extract_svn_revision.sh
echo Building Precompiled Header...
cd src/WorldServer
g++ -std=c++0x -pthread -Wall -g -DHAVE_CONFIG_H -I. -I../.. -I/usr/include/mysql -I/usr/include/openssl -I/usr/local/include/openssl -I/usr/local/include -I. -I./../libs -o StdAfx.h.gch StdAfx.h

echo All has passed well!
echo You should run this again every time a .h file changes.

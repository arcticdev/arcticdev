#!/usr/bin/env sh

echo Building Precompiled Header...
cd src/WorldServer
g++ -pthread -Wall -DHAVE_CONFIG_H -I. -I../.. -I/usr/include/mysql -I/usr/include/openssl -I/usr/local/include/openssl -I/usr/local/include -I. -I./../libs -I./../libs/vmap -I./../libs/g3dlite -o StdAfx.h.gch StdAfx.h

echo Done. Now you can run make, and experience much faster build times. Remember to re-run this script every time you svn update.

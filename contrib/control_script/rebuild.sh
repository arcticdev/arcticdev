#!/bin/sh

DEST=~/realm
OPTS="--prefix=$DEST --enable-debug --enable-optimize --enable-scripts"

autoreconf -fi
./configure $OPTS
make clean
make -j3
make install

#!/bin/sh

DEST=~/devrealm
OPTS="--prefix=$DEST --enable-debug --enable-optimize"

autoreconf -fi
./configure $OPTS
make clean
make -j3
make install

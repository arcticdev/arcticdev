#!/bin/sh
version=`git log -1 --pretty=format:"%h"`
timestamp=`git log -1 --pretty=format:"%ct"`
hostname=`hostname`
username=`whoami | cut -d\\\ -f2`

if [ -z "$version" ]
then
	version="0"
fi

if [ -z "$timestamp" ]
then
	timestamp="0"
fi

echo "#ifndef _VERSION_H" > src/libs/version.h
echo "#define _VERSION_H" >> src/libs/version.h
echo "" >> src/libs/version.h
echo "#define BUILD_HASH 0x$version" >> src/libs/version.h
echo "#define COMMIT_TIMESTAMP $timestamp" >> src/libs/version.h
echo "#define BUILD_HASH_STR \"$version\"" >> src/libs/version.h
echo "#define BUILD_USER_STR \"$username\"" >> src/libs/version.h
echo "#define BUILD_HOST_STR \"$hostname\"" >> src/libs/version.h
echo "" >> src/libs/version.h
echo "#endif" >> src/libs/version.h


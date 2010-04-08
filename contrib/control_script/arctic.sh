#!/bin/sh
# WoWArcTic Server Control Script by schnek

PATH=./:$PATH

LOGON_SERVER=AuthServer
WORLD_SERVER=WorldServer

case $1 in
    'start')
        exec ./${LOGON_SERVER}&
        exec ./${WORLD_SERVER}&
		
		echo " "
		echo "WoWArcTic Has Been Successfully Started."
		echo " "
;;
    'stop')
        killall -9 ${LOGON_SERVER}
		killall -9 ${WORLD_SERVER}
		
		echo " "
		echo "WoWArcTic Has Been Successfully Stopped."
		echo " "
;;
    'restart')
        $0 stop
        $0 start
		
		echo " "
		echo "WoWArcTic Has Been Successfully Re-Started."
		echo " "
;;
    *)
		echo " "
        echo "Usage: ./arctic { start | stop | restart }"
		echo " ";
;;
esac

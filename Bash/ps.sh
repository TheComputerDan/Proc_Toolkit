#!/bin/bash
pidarray=($(ls -d /proc/* | grep '[0-9]' | cut -d '/' -f 3 | sort -n))
for i in ${pidarray[@]}
do
 if [ -d "/proc/$i" ]
  then
  echo -e '\n'
  printf "\033[1;32mPID: $i  \033[0m\n"
 fi
# Add functionality to filter further
 (cat /proc/$i/status | grep -w "Name\|Pid\|PPid\|Uid") 2>/dev/null
 if [ -d "/proc/$i" ]
  then
 echo -n "Socket/inode: "
  fi
	let ST=1
	let EN=100
	 for e in $(eval echo "{$ST..$EN}")
	do
 	(readlink /proc/$i/fd/$e | grep socket | uniq -u | cut -f2 -d"[" | sed 's/]$//') 2>/dev/null
	done
done

echo -e '\n'
PS3="Please enter your choice... "
select opt in tcp tcp6 udp quit
do
	case $opt in
	tcp)
 		echo -n "[tcp] Enter the Socket/inode: "
 		read socket
 		port=$(cat /proc/net/tcp | grep $socket | cut -f3 -d":" | awk '{print $1}')
 		echo $((0x$port))
	;;
	tcp6)
		echo -n "[tcp6] Enter the Socket/inode: "
		read socket
		port=$(cat /proc/net/tcp6 | grep $socket | cut -f3 -d":" | awk '{print $1}')
		echo $((0x$port))
	;;
	udp)
		echo -n "[udp] Enter the Socket/inode: "
		read socket
		port=$(cat /proc/net/udp | grep $socket | cut -f3 -d":" | awk '{print $1}')
		echo $((0x$port))
	;;
	quit)
	break
	;;
	*) echo "invalid option";;
	esac
done


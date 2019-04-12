#!/bin/bash

pidarray=($(ls -d /proc/* | grep '[0-9]' | cut -d '/' -f 3 | sort -n))

printf "\033[1;31mTCP:  \033[0m\n"
printf "\033[1;36mOpen Ports: \033[0m\n"
hexportstcp=($(cat /proc/net/tcp | cut -f3 -d":" | awk '{print $1}' | sed -n '1!p'))
for i in ${hexportstcp[@]}
do
echo $((0x$i))
done
echo -e "\n"
cat /proc/net/tcp | awk '{print $10}' | sed -n '1!p'

#For loop to match inodes in /proc/net/___ with its pid >> Not currently operational 

#inodetcp=($(cat /proc/net/tcp | awk '{print $10}' | sed -n '1!p'))
#for g in ${pidarray[@]}
#do
#inds=$(ls -d /proc/$g/fd | grep '[0-9]' | cut -d '/' | sort -n)
#for h in ${inds[@]}
#	do
#	(readlink /proc/$g/fd/$h | grep socket | uniq -u | cut -f2 -d"[" | sed 's/$//') 2>/dev/null
#	done
#done


printf "\033[1;31mTCP6: \033[0m\n"
printf "\033[1;36mOpen Ports: \033[0m\n"
hexportstcps=($(cat /proc/net/tcp6 | cut -f3 -d":" | awk '{print $1}' | sed -n '1!p'))
for i in ${hexportstcps[@]}
do
echo $((0x$i))
done
echo -e "\n"
cat /proc/net/tcp6 | awk '{print $10}' | sed -n '1!p'


printf "\033[1;31mUDP:  \033[0m\n"
printf "\033[1;36mOpen Ports: \033[0m\n"
hexportsudp=($(cat /proc/net/udp | cut -f3 -d":" | awk '{print $1}' | sed -n '1!p'))
for i in ${hexportsudp[@]}
do
echo $((0x$i))
done
echo -e "\n"
cat /proc/net/udp | awk '{print $10}' | sed -n '1!p'


printf "\033[1;31mUDP6:  \033[0m\n"
printf "\033[1;36mOpen Ports: \033[0m\n"
hexportsudps=($(cat /proc/net/udp6 | cut -f3 -d":" | awk '{print $1}' | sed -n '1!p'))
for i in ${hexportsudps[@]}
do
echo $((0x$i))
done
echo -e "\n"
cat /proc/net/udp6 | awk '{print $10}' | sed -n '1!p'


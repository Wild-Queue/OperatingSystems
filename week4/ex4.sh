#!/bin/bash

echo "Write 'stop' when you want to stop writing commands\n"

while :
do 
	read -p "Command: " inputline
	if [ $inputline = "stop" ]
	then 
		echo "Exit\n"
		break
	else
		echo "Command executing"
		execve
		bash -c "$inputline"
	fi
	
done

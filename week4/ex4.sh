#!/bin/bash

echo "Write 'stop' when you want to stop writing commands"

fork() {
		bash -c "$inputline" $
}

while :
do 
	read -p "Command: " inputline
	if [ $inputline = "stop" ]
	then 
		echo "Exit"
		break
	else
		echo "Command executing"
		fork $
fi
	
done

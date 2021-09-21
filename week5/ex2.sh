#!/bin/bash
for i in 1 2 3 4 5 6 7 8 9 10
do	
	while [ -f "./exercise2.lock" ]
	do
		sleep 0
	done 
	
	
	ln exercise2.txt exercise2.lock; echo "$(($(tail -n 1 "./exercise2.txt") + 1))" >> exercise2.txt; rm exercise2.lock &
	
	while [ -f "./exercise2.lock" ]
	do
		sleep 0
	done
	
	ln exercise2.txt exercise2.lock; echo "$(($(tail -n 1 "./exercise2.txt") + 1))" >> exercise2.txt; rm exercise2.lock
done

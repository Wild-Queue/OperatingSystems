#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	for (int i = 0; i < 5; i++){
		fork();
		fork();
		fork();
		
		sleep(5);
	}
	// after the first 'pstree' comand there was 32 processes and after the secod one there was 163 processes (number of processes in only number of processes created by ex2.1 file)
	// Such situstion is happend because each 'fork()' double number of processes that happens at this moment
	
	return 0;
}

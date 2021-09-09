#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	int n = 0;
	int pid = fork();
	pid = fork();
	if (pid > 0){
		printf("hello from parent[%d - %d]\n", pid, n);
		n+=1;
	}
	else if (pid == 0){
		printf("Hello from chid[%d - %d]\n", pid, n);
		n+=1;
	}
	else
	{
		return -1;
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
pid_t pid;
pid = fork();
	if (pid == 0)
	{
		printf("Hello from chid[%d - %s]\n", pid, argv[1]);
	}
	else if (pid != -1)
	{
		printf("Hello from parent[%d - %s]\n", pid, argv[1]);
	}
	else {
		return -1;
	}
	return 0;
}
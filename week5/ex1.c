#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<pthread.h>

void *myThread(void *vargp)
{
    printf("	>>Hello from thread #%d\n", (int)(vargp));
    return NULL;
}
   

int main (void)
{
	int n;
	printf("Enter the number of threads\nNumber: ");
	scanf("%d", &n);

	pthread_t thread;

	for (int i = 1; i <= n; i++){
		if (pthread_create(&thread, NULL, myThread, (void*)(intptr_t)i))
		{
			printf("	>>ERROR IN CREATING Thread #d!\n", i);
			pthread_exit(NULL);
			return 1;
		}
		else
		{
			printf(" >>Thread #%d created!\n", i);
			pthread_join(thread, NULL);
		}
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<pthread.h>

int n = 1, i;
int inwork = 1;
int full = 0;
int empty = 10, x = 0;
void *producer()
{
if ((inwork == 1) && (empty != 0)) {
	--inwork;
	++full;
	--empty;
	x++;
	printf("\nProducer produces item %d", x);
	++inwork;
	n = 2;
}

else {
        printf("Buffer is full!\n");
      }
}

void *consumer()
{
if ((inwork == 1) && (full != 0)) {
	--inwork;
	--full;
	++empty;
	printf("\nConsumer consumes item %d", x);
	x--;
	++inwork;
    n = 1;
      }

      else {
        //printf("%d", n);
        printf("Buffer is empty!\n");
      }
}

int main()
{
  pthread_t threadP, threadC;
  
    
  for (i = 100000000; i > 0; i--) {
    pthread_create(&threadP, NULL, producer, NULL);
    pthread_create(&threadC, NULL, consumer, NULL);
    pthread_join(threadP, NULL);
    pthread_join(threadC, NULL);
  }
}

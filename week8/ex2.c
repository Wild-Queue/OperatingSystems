#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include<mem.h>

int main (void)
{
   char *src[10];
 
   // Заполняем массив сим
	int n = 0;
	
	printf("\n########################################\n");
	printf("#######MEM ALLOCATOR#########WEEK 8#####\n");
	printf("########################################\n");
	
	for(int i = 0; i < 10; i++){
		n += 10;
		printf(">>MEM ALLOCATOR: %dMB were allocated\n", n);
		src[i] = malloc(10000000);
		memset (src[i], '\0', 10000000);
		sleep(1);
	}

	for (int i = 0; i < 10; i++){
		free(src[i]);
	}
		
	return 0;
}

/*
########################################
#######MEM ALLOCATOR#########WEEK 8#####
########################################
>>MEM ALLOCATOR: 10MB were allocated
vmstat 1
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 0  0      0 3139524 235312 2441416    0    0   177    95  399  887 21  3 75  1  0
>>MEM ALLOCATOR: 20MB were allocated
 0  0      0 3135512 235312 2435916    0    0     0     0  433 1430  2  2 96  0  0
>>MEM ALLOCATOR: 30MB were allocated
 0  0      0 3125736 235312 2435900    0    0     0     0  683 1074  2  2 96  0  0
>>MEM ALLOCATOR: 40MB were allocated
 1  0      0 3115404 235312 2436316    0    0     0     0  236  394  1  1 98  0  0
>>MEM ALLOCATOR: 50MB were allocated
 0  0      0 3107340 235312 2434876    0    0     0   184  389  610  2  1 97  0  0
>>MEM ALLOCATOR: 60MB were allocated
 0  0      0 3100468 235320 2434324    0    0     0    12  816  487  3  1 96  0  0
>>MEM ALLOCATOR: 70MB were allocated
 0  0      0 3090708 235320 2434324    0    0     0     0  203  255  1  0 99  0  0
>>MEM ALLOCATOR: 80MB were allocated
 0  0      0 3080880 235320 2434132    0    0     0     0  326  301  1  1 98  0  0
>>MEM ALLOCATOR: 90MB were allocated
 0  0      0 3071556 235320 2434132    0    0     0     0  739 1882  4  2 94  0  0
>>MEM ALLOCATOR: 100MB were allocated
 0  0      0 3054892 235328 2440676    0    0     0   140  573 1366  5  1 93  1  0
*/

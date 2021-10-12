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

//Command 'top' show that used memory is increasing


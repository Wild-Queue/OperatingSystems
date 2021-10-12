#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include<sys/resource.h>

int main (void)
{
	srand(time(NULL));
	
	char *src[10];
	
	struct rusage *usage;
	
	// Заполняем массив сим
	int n = 0;
	
	printf("########################################\n");
	printf("#######MEM ALLOCATOR#########WEEK 8#####\n");
	printf("########################################\n");
	
	for(int i = 0; i < 10; i++){
		n += 10;
		printf(">>MEM ALLOCATOR: %dMB were allocated\n", n);
		usage = malloc(1000000);
		memset (usage, '0', 1000000);
		getrusage(RUSAGE_SELF, usage);
		
		printf("ru_stime = %li \n", usage->ru_stime);
		printf("ru_maxrss = %li \n", usage->ru_maxrss);
		printf("ru_ixrss = %li \n", usage->ru_ixrss);
		printf("ru_idrss = %li \n", usage->ru_idrss);
		printf("ru_minflt = %li \n", usage->ru_minflt);
		sleep(1);
	}

	/*for (int i = 0; i < 10; i++){
		free(src[i]);
	}*/
	
	free(usage);
		
	return 0;
}


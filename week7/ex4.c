#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *Myrealloc (void *ptr, size_t new_size){
	void *new = malloc(new_size);
	new = ptr;
	return new;
}

int main (void)
{	srand(time(NULL));

	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	int* a1 = calloc(0, n1 * sizeof(int));
	int i;
	
	for(i=0; i<n1; i++){
		a1[i] =100;
		printf("%d ", a1[i]);
	}
	
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);
	
	a1 = Myrealloc(a1, n2*sizeof(int));
		
	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}
	printf("\n");	
	return 0;
}

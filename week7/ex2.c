#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (void)
{
	int n;
	printf("Enter number of array elements: ");
	scanf("%d", &n);
	int *array = malloc(n * sizeof(int));
	
	for (int i = 0; i < n; i++){
		array[i] = i;
		printf("array[%d]== %d\n", i, array[i]);	
	}
	
	free(array);
  return 0;
}

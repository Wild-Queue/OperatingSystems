#include <stdio.h>
#include <string.h>

void swap(int* a, int* b){
	int c = *a;
	*a = *b;
	*b = c;
}

int main(void)
{
	int n, m;
	printf("Enter 2 numbers separated by commas(examle: `1, 2`):\n");
	scanf("%i, %i", &n, &m);
	
	swap(&n, &m);
	printf("Swaped numbers: %i, %i\n", n, m);
	
    return 0;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	printf("Enter number of lines:\n");
	scanf("%i", &n);
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n - i; j++){ 
			printf(" ");
		}
		
		for(int j = 0; j < 1 + 2 * i; j++){ 
			printf("*");
		}
		
		/*for(int j = 0; j < n - i; j++){ 
			printf(" ");
		}*/
		printf("\n");
	}
	
    return 0;
}

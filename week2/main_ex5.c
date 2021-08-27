#include <stdio.h>
#include <string.h>

void IsoscelesTriangle(int n){
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n - i; j++){ 
			printf(" ");
		}
		
		for(int j = 0; j < 1 + 2 * i; j++){ 
			printf("*");
		}
		
		printf("\n");
	}
}

void RightTriangle(int n){
	for (int i = 0; i < n; i++){
		for(int j = 0; j < 1 + i; j++){ 
			printf("*");
		}
		
		printf("\n");
	}
}

void LeftSideIsostTriangle(int n){
	for (int i = 0; i < n; i++){
		if (i < n/2){
			for(int j = 0; j < 1 + i; j++){ 
				printf("*");
			}
		}
		else {
			for(int j = n - i; j > 0 ; j--){ 
				printf("*");
			}
		}
			printf("\n");
	}
}

void Rectangle(int n){
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){ 
			printf("*");
		}
		printf("\n");
	}
}

int main(void)
{
	int n;
	int m;
	printf("Enter number of lines:\n");
	scanf("%i", &n);
	
	printf("Choose what figure you whant to drow: \n 1 - Isosceles Triangle \n 2 - Right Triangle \n 3 - Rotated Isosceles Triangle\n 4 - Rectangle\n");
	printf("Enter the number of figure:");
	scanf("%i", &m);
	
	if (m == 1){
		IsoscelesTriangle(n);
	}
	if (m == 2){
		RightTriangle(n);
	}
	if (m == 3){
		LeftSideIsostTriangle(n);
	}
	if (m == 4){
		Rectangle(n);
	}
	return 0;
}

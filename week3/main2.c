#include <stdio.h>
#include <string.h>

void BubbleSort(int *a, int Size){
	for (int i = 1; i < Size; i++){
		for (int j = 0; j < Size - i; j++){
			if (a[j] > a[j+1]){
				int tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main (void)
{
	int a[1000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	BubbleSort(a, n);
	
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}

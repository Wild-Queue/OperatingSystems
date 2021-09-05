#include <stdio.h>
#include <string.h>

void BubbleSort(int *a, int Size){
	for (int i = 0; i < Size; i++){
		for (int j = i; j < Size; j++){
			if (a[i] > a[j]){
				int tmp = a[i];
				a[i] = a[j];
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

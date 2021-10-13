#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
long int a[1000][2];
int N = 0;

int MinPriority(){
	int Iterator = 0;
	for (int i = 0; i < N; i++)
		if (a[i][1] < a[Iterator][1])
			Iterator = i;
			
	return Iterator;
}

int Checker(int number){
	for (int i = 0; i < N; i++)
		if (a[i][0] == number)
			return i;
				
	return -1;

}

int main(void) {
	printf("Enter the number of pages: ");
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++){
		a[i][0] = -1;
	}
	
	FILE *fp;
	char name[] = "Lab 09 input.txt";
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("Не удалось открыть файл");
		//getchar();
		return 0;
	}
	
	char number[3];
	
	double Hits = 0;
	double Miss = 0;
	
	while (fscanf(fp, "%s ", number) != EOF){					
		for (int i = 0; i < N; i++)
			printf("i = %d id = %ld %ld \n", i, a[i][0], a[i][1]);
		printf("current page number %s \n\n", number);
		
		if (Checker(atoi(number)) != -1){
			a[Checker(atoi(number))][1] = 65535* 2;	
			
			for (int i = 0; i < N; i++)
				a[i][1] /= 2;
			
			Hits++;
		}
		else {
			int Iterator = MinPriority();
			if (a[Iterator][1] == 1)
				break;
			
			a[Iterator][0] = atoi(number);
			a[Iterator][1] = 65535;
			
			for (int i = 0; i < N; i++)
				if (i != Iterator)
					a[i][1] /= 2;
			
			Miss++;

		} 
	}
	printf("hit = %f miss = %f ratio = %f \n", Hits, Miss, Hits/Miss);
	
	fclose(fp);
	//getchar();
	return 0;
}

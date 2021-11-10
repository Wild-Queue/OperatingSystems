#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int Check_resources(int A[3], int R[3]){
	for (int j = 0; j < 3; j++){
		if (A[j] < R[j])
			return 0;
	}
	return 1;
}


int main (void)
{
	FILE *fptr;
	fptr = fopen("input_dl.txt", "r");
	
	int E[3];
	int A[3];
	int C[5][3];
	int R[5][3];
	int P[5] = {0, 0, 0, 0, 0};
	
	fscanf(fptr, "%d %d %d \n \n%d %d %d \n", &E[0], &E[1], &E[2], &A[0], &A[1], &A[2]);
	
	for (int i = 0 ; i < 5; i++){
		for (int j = 0; j < 3; j++){
			fscanf(fptr, "%d", &C[i][j]);
		}
	}
	
	for (int i = 0 ; i < 5; i++){
		for (int j = 0; j < 3; j++){
			fscanf(fptr, "%d", &R[i][j]);
		}
	}
	
	int Continue = 1;
	int Pprevious[5] = {0, 0, 0, 0, 0};
	while (Continue){
		for (int i = 0; i<5; i++){
			int Can_finish = Check_resources(A, R[i]);
			
			printf("i -> %d, proc_finished -> %d, check_resources - > %d\n", i, P[i], Can_finish);
			
			if (Can_finish){
				for (int j = 0; j < 3; j++){
					A[j] += C[i][j];
				}
				P[i] = 1;
			}
		}
		
		Continue = 0;
		for (int i = 0; i < 5; i++){
			if (P[i] != Pprevious[i]){
				Continue = 1;
				Pprevious[i] = P[i]; 
			}
		}
		printf("\n");
	}
	fclose(fptr);
	
	fptr = fopen("output.txt", "w");
	int Dead_lock_existens = 0;
	for (int i = 0; i < 5; i++){
		if (P[i] == 0){
			Dead_lock_existens += 1;
		}
	}
	if (Dead_lock_existens == 0)
		fprintf(fptr, "No procces deadloked");
		
	if (Dead_lock_existens == 1){
		fprintf(fptr, "Process");
		for (int i = 0; i < 5; i++)
			if (P[i] == 0)
				fprintf(fptr, " %d deadlocked", i);
	}
	
	if (Dead_lock_existens > 1){
		fprintf(fptr, "Processes");
		for (int i = 0; i < 5; i++)
			if (P[i] == 0)
				fprintf(fptr, " %d", i);
		fprintf(fptr, " deadlocked");
	}
	fclose(fptr);
	return 0;
}

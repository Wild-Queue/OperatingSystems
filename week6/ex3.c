#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int Quantum = 3;


struct Proc
{
  int Number;

  int AT;
  int BT;
  int BTT;

  int CT;
  int TAT;
  int WT;

};

void swap(struct Proc* First, struct Proc* Second){
  int Number = First->Number;
  int AT = First->AT;
  int BT = First->BT;
  int BTT = First->BTT;

  First->Number = Second->Number;
  First->AT = Second->AT;
  First->BT = Second->BT;
  First->BTT = Second->BTT;

  Second->Number = Number;
  Second->AT = AT;
  Second->BT = BT;
  Second->BTT = BTT;
}

void sort(struct Proc* Array, int NoP){
  for (int i = 0; i < NoP; i++){
    for (int j = 0; j < NoP - i; j++){
      if (Array[j+1].AT < Array[j].AT){
        swap(&Array[j+1], &Array[j]);
      }
    }
  }
}


int main (void)
{
  int NoP;
  printf("Enter quantum number: ");
  scanf("%d", &Quantum);

  printf("Enter number of processes: ");
  scanf("%d", &NoP);

  printf("Enter Arrival time and Burst time for each ptocess\n");

  struct Proc* Processes;

  for (int i = 0; i < NoP; i++){
    Processes[i].Number = i+1;
    printf("Arrival time of process[%d]: ", i+1);

    scanf("%d", &Processes[i].AT);

    printf("Burst time of process[%d]: ", i+1);

    scanf("%d", &Processes[i].BT);
    Processes[i].BTT = Processes[i].BT;
    Processes[i].CT = 0;
    Processes[i].WT = 0;
    Processes[i].TAT = 0;
  }

  double ATT = 0;
  double AWT = 0;

  int TIME = 0;

  sort(Processes, NoP);
  for (int j = 0; j < NoP; j++){
    for (int i = 0; i < NoP; i++){
      if (Processes[i].AT > TIME) TIME = Processes[i].AT;

      if (Processes[i].BTT > 0){
        if (Processes[i].BTT > Quantum){
          TIME += Quantum;
          Processes[i].BTT -= Quantum;
        }
        else {
         TIME += Processes[i].BTT;
         Processes[i].BTT = 0;

         Processes[i].CT = TIME;
         Processes[i].TAT = TIME - Processes[i].AT;

         Processes[i].WT = Processes[i].CT - Processes[i].AT - Processes[i].BT;
        }
      }
    }
  }

  for (int i = 0; i < NoP; i++){
    AWT += Processes[i].WT;
    ATT += Processes[i].TAT;
  }


  printf("P#    AT    BT    CT    TAT     WT\n");

  for (int i = 0; i < NoP; i++){
    printf("P%d     %d     %d     %d      %d      %d\n", Processes[i].Number, Processes[i].AT, Processes[i].BT, Processes[i].CT, Processes[i].TAT, Processes[i].WT);
  }

  printf("Average Turnaround time: %f\n", ATT/NoP);

  printf("Average waiting time: %f\n", AWT/NoP);

  return 0;
}
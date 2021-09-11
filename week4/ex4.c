#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
  char s[2097152];
  printf("Enter 'stop' to finish\n");

  while (1) {
    pid_t pid = fork();

    if (pid != 0){
      sleep(3);
    }
    
    printf("Command: ");
    gets(s);
    s[strlen(s)] = ' ';
    s[strlen(s)] = '&';
    
    if (strlen(s) == 4 && s[0] == 's' && s[1] == 't' && s[2] == 'o' && s[3] == 'p'){
      return 0;
    }
    system(s);
  }
  return 0;
}

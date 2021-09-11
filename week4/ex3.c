#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (void)
{
  char s[2097152];
  printf("Command: ");
  scanf("%s", s);
  system(s);
  return 0;
}
#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[10000];
	printf("Enter the string:\n");
	scanf("%s", a);
	
	int i = 0;
	char b[100000];
	
	while (i <= strlen(a)){
		b[i] = a[strlen(a)-i-1];
		i++;
	}
	
	printf("Reverse string:\n%s\n", b);
    return 0;
}

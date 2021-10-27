#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main (void)
{
	
	DIR *dirp;
	struct dirent *dp;
	dirp = opendir("./");
	if (!dirp) { 
		perror("diropen");
		exit(1);
	}
	
	printf("Files in file system: ");
	while ((dp = readdir(dirp)) != NULL){
		printf("%s; ", dp->d_name);
	};
	printf("\n");
	
	closedir(dirp);
	return (-1);
}

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
	dirp = opendir("./tmp");
	if (!dirp) { 
		perror("diropen");
		exit(1);
	}
	
		
	//printf("%d - %s [%d] %d\n", dirp->d_name, dp->d_ino);
	
	while ((dp = readdir(dirp)) != NULL){
		printf("%s - %d\n", dp->d_name, dp->d_ino);
	};
	
	
	closedir(dirp);
	return (-1);
}

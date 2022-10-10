#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include<sys/socket.h>


int main(int n, char *args[]){

	if(n<2){
		printf("File path not specified!!");
		return 1;
	}

	char* file = args[1];

	struct stat buff;
	int r =  lstat(file,&buff);
	
	if(r==-1)	
    {	
         perror("Failed : ");
         exit(1);
    }
	printf("The given file is of type : ");
	switch (buff.st_mode & S_IFMT) {
		case S_IFBLK:  printf("block device\n");            break;
		case S_IFCHR:  printf("character device\n");        break;
		case S_IFDIR:  printf("directory\n");               break;
		case S_IFIFO:  printf("FIFO/pipe\n");               break;
		case S_IFLNK:  printf("symlink\n");                 break;
		case S_IFREG:  printf("regular file\n");            break;
		case S_IFSOCK: printf("socket\n");                  break;
		default:       printf("unknown?\n");                break;
    }


    return 0;
}
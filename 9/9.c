#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/sysmacros.h>


int main(){

	struct stat buff;
	int fd =  stat("9.txt",&buff);
	
	if(fd==-1)	
    {	
         perror("Failed : ");
         exit(1);
    }
	
	printf("Inode No. : %ld\n",(long)buff.st_ino);
	printf("# of Hard Links : %ld\n",(long)buff.st_nlink);
	printf("UID : %ld\n",(long)buff.st_uid);
	printf("GID : %ld\n",(long)buff.st_gid);
	printf("File size in bytes : %ld\n",(long)buff.st_size);
	printf("Block size : %ld\n",(long)buff.st_blksize);
	printf("# of Blocks : %ld\n",(long)buff.st_blocks);
	printf("Last Access Time : %s",ctime(&buff.st_atime));
	printf("Last Modification Time : %s",ctime(&buff.st_mtime));	
	printf("Last Change Time : %s",ctime(&buff.st_ctime));
    

    return 0;
}
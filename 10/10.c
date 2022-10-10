#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>


int main(){

	int fd = open("10.txt",O_RDWR);
	
	char str[11]="01010110101";
	
	write(fd,str,10);
	
	int offset = lseek(fd,10,SEEK_END);
	printf("offset : %d",offset);
	
	if(offset==-1)
	  perror("Offset setting failed : ");
	write(fd,str,10);
	close(fd);	  
	return 0;
}
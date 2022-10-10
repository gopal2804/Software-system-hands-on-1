#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){

    int fd = open("8.txt",O_RDONLY);
    char buff;
	while(1)
	{
		int s = read(fd,&buff,1);
		
		if(s==0)
		  break;
		  
		write(1,&buff,s);
	}
	close(fd);
	return 0;
}
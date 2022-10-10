#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main(){
    int fd;
    fd=open("4.txt",O_RDWR|O_CREAT|O_EXCL);
    //O_EXCL Ensure that this call creates the file: if this flag is speci‐ fied in conjunction with O_CREAT, and pathname already exists, then open() fails with the error EEXIST.
    //fd=-1;
    printf("The file descriptor value is: %d",fd);
    return 0;
}
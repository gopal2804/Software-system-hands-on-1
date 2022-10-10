#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main(){
    int fd;
    fd=creat("sample.txt",0777);
    printf("The file descriptor value is: %d",fd);
    return 0;
}
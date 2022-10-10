#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
    int fd1,fd2,fd3,fd4,fd5;
    while(1){
        fd1=open("one.txt",O_RDWR|O_CREAT,0777);
        fd2=open("two.txt",O_RDWR|O_CREAT,0777);
        fd3=open("three.txt",O_RDWR|O_CREAT,0777);
        fd4=open("four.txt",O_RDWR|O_CREAT,0777);
        fd5=open("five.txt",O_RDWR|O_CREAT,0777);
    }
    return 0;
}
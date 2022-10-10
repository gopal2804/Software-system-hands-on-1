#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
    struct flock lock;
    int fd;
    fd=open("db.txt",O_RDWR);
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_pid=getpid();
    printf("Before entering into critical section\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("inside the critical section....\n");
    printf("Enter to unlock..\n");
    getchar();
    printf("unlocked");
    lock.l_type=F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    return 0;
}
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>


int main(){
    
    int fd = open("11.txt",O_WRONLY | O_APPEND);

    if(fd<0){
        perror("Failed");
        return 1;
    }

    int dupfd = dup(fd);
    int dup2fd = dup2(fd,12);
    int fcntlfd = fcntl(fd,F_DUPFD,0);

    printf("fd, dupfd, dup2fd, fcntlfd = %d, %d, %d, %d\n",fd, dupfd, dup2fd, fcntlfd);

    char origStr[] = "This is appended by original fd.\n";
    char dupStr[] = "This is appended by duplicate fd.\n";
    char dup2Str[] = "This is appended by duplicate2 fd.\n";
    char fcntlStr[] = "This is appended by fcntlDUP fd.\n";

    write(fd,origStr,sizeof(origStr));
    write(dupfd,dupStr,sizeof(dupStr));
    write(dup2fd,dup2Str,sizeof(dup2Str));
    write(fcntlfd,fcntlStr,sizeof(fcntlStr));

    close(fd);
    close(dupfd);
    close(dup2fd);
    close(fcntlfd);

    return 0;
}
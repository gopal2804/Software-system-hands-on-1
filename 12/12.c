#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>




int main(void){
    
    int fd1 = open("12.txt",O_RDONLY);
    int fd2 = open("12.txt",O_WRONLY);
    int fd3 = open("12.txt",O_RDWR);
    int fd4 = open("12.txt",O_APPEND);
    int fd5 = open("12.txt",O_APPEND | O_WRONLY);
    int fd6 = open("12.txt",O_APPEND | O_RDWR);


    if(fd1<0 || fd2<0 || fd3<0 || fd4<0 || fd5<0 || fd6<0){
        perror("Failed to open the file!");
        return 1;
    }

    int mode1 = fcntl(fd1,F_GETFL);
    int mode2 = fcntl(fd2,F_GETFL);
    int mode3 = fcntl(fd3,F_GETFL);
    int mode4 = fcntl(fd4,F_GETFL);
    int mode5 = fcntl(fd5,F_GETFL);
    int mode6 = fcntl(fd6,F_GETFL);


    printf("Read Mode Only - %d\nWrite Mode Only - %d\nRead-Write Mode - %d\nAppend Mode Only - %d\nAppend-Write Mode - %d\nAppend-Read-Write Mode - %d\n", mode1, mode2, mode3, mode4, mode5, mode6);
     
    return 0;
}
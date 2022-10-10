#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

    int s = symlink("three.txt","four.txt");
    if(s<0)
        perror("Failed : ");

    int h = link("three.txt","four.txt");
    if(h<0)
        perror("Failed : ");

    return 0;

}
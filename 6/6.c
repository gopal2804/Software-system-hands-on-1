#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    char buff[80];
    int n,x;
    printf("Ehter the size of the text you want to enter , MAX_CHAR=80\n");
    scanf("%d",&x);
    printf("enter string\n");
    n=read(0,buff,x);
    printf("the entered string is\n");
    write(1,buff,n);
    printf("\n");
    return 0;
}
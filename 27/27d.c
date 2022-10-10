#include <unistd.h> 
#include <stdio.h>  

int main()
{
    char *args[] = {"/bin/ls", "-Rl", "27.txt", NULL}; 

    printf("----------------------OUTPUT(ls -Rl) USING execv() system call---------------------\n");
    execv(args[0], args);
    printf("\n");
    return 0;
}
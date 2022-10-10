#include <unistd.h> 
#include <stdio.h> 

int main()
{
    char *args[] = {"/bin/ls", "-Rl", "27.txt", NULL};

    printf("--------------------------OUTPUT(ls -Rl) USING execvp() system call---------------------\n");
    execvp(args[0], args);
    printf("\n");
    return 0;
}
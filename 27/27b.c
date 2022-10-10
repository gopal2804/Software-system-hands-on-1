#include <unistd.h>
#include <stdio.h> 

int main()
{
    char *path = "/bin/ls";
    char *options = "-Rl";
    char *file_path = "27.txt";

    printf("-----------------OUTPUT(ls -Rl) USING execlp() system call-----------------------\n");
    execlp(path, path, options, file_path, NULL);
    printf("\n");
    return 0;
}
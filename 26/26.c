#include <unistd.h> 

int main()
{
    char *executable_path = "./25/25_out";
    char *arg = "25.c";

    execl(executable_path, executable_path, arg, NULL);
    return 0;
}
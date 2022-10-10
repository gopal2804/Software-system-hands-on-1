#include <sys/types.h>
#include <unistd.h>
#include <stdio.h> 

int main()
{
    int childPid, parentPid;

    parentPid = getpid();  //getting the pid of the current running process that is parent process

    printf("Process id(PID) of the parent process is: %d\n", parentPid);

    childPid = fork(); //If child process created successfully it will not return 0

    if (childPid != 0)
    {
        printf("Process id(PID) of the child process is: %d\n", childPid);
    }
    return 0;
}
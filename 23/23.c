#include <sys/types.h> 
#include <unistd.h>   
#include <stdio.h>    

int main()
{
    pid_t childPid;

    if ((childPid = fork()) != 0)
    {
        // Only parent process can enter this branch
        printf("Parent PID is: %d\n", getpid());
        printf("Putting parent to sleep for 10s!\n");
        sleep(10); // Putting the parent process to sleep for 10s
        printf("Parent is now awake!\n");
    }
    else
    {
        // Only child process can enter this branch
        printf("Child PID is: %d\n", getpid());
        printf("Exiting child!\n");
        _exit(0); // Terminate the child process
        // The above exit causes the child to exit while the parent is asleep, hence won't be able to send the exit signal to the parent & ends up becoming a zombie
    }
    return 0;
}
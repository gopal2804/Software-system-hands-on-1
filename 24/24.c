//A process whose parent process no more exists i.e. either finished or terminated without waiting for its child process to terminate is called an orphan process.
#include <sys/types.h> 
#include <unistd.h>   
#include <stdio.h>     

void main()
{
    pid_t childPid;

    if ((childPid = fork()) != 0)
    {
        // Only parent process can enter this branch
        printf("Parent PID is: %d\n", getpid());
        printf("Putting Parent to sleep for 10s\n");
        sleep(10); // Put the parent process to sleep for 10s
        printf("Exiting parent!\n");
        _exit(0); // Terminate the parent process
        // The above exit causes the parent to exit while the child is asleep
    }
    else
    {
        // Only child process can enter this branch
        printf("Child PID is: %d\n", getpid());
        printf("Putting child to sleep for 12s!\n");
        sleep(12); // Put the child process to sleep for 12s
        printf("Child is now awake!\n");
    }
}
#include <unistd.h>    
#include <sys/types.h> 
#include <sys/wait.h>  
#include <stdio.h>     

int main()
{
    pid_t child_a, child_b, child_c, terminated_child;
    int waitStatus;

    if ((child_a = fork()) == 0)
    {
        // Child A will enter this branch
        printf("Child A is created...\n");
        printf("Putting child A to sleep for 5 sec\n");
        sleep(5);
        printf("Child A is now awake!\n");
        _exit(0);
    }
    else
    {
        // Parent will enter this branch
        if ((child_b = fork()) == 0)
        {
            // Child B will enter this branch
            printf("Child B is created...\n");
            printf("Putting child B to sleep for 10 sec\n");
            sleep(10);
            printf("Child B is now awake!\n");
            _exit(0);
        }
        else
        {
            // Parent will enter this branch

            if ((child_c = fork()) == 0)
            {
                // Child C will enter this branch
                printf("Child C is created...\n");
                printf("Putting child C to sleep for 15 sec\n");
                sleep(15);
                printf("Child C is now awake!\n");
                _exit(0);
            }
            else
            {
                // Parent will enter this branch
                terminated_child = waitpid(child_c, &waitStatus, 0);

                if (terminated_child == child_c)
                {
                    if (waitStatus == 0)
                        printf("Child C has terminated with exit status = 0\n");
                    else
                        printf("Child has exited with exit status : %d\n", waitStatus);
                }
            }
        }
    }
    return 0;
}
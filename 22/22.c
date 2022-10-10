#include <unistd.h>    
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     

int main()
{
    int childPid, fd;
    fd = open("22.txt", O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);

    if ((childPid = fork()) != 0) // Only parent can enter this branch
        write(fd, "Parent Process\n!", 15);
    else // Only child can enter this branch
        write(fd, "Child Process\n!", 15);
    close(fd);
    return 0;
}
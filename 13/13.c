#include <sys/time.h>  //for select system call
#include <sys/types.h> //for select system call
#include <unistd.h>    //for select system call
#include <stdio.h>     //for perror & printf function

void main()
{
    fd_set Read_fd_set, Write_fd_set;

    struct timeval time;

    int value;

    // FD_ZERO(&readFDSet);
    FD_SET(STDIN_FILENO, &Read_fd_set);   // Adding STDIN to the set of file descriptors to read from
    FD_SET(STDOUT_FILENO, &Write_fd_set); // Adding STDOUT to the set of file descriptors to write to

    // Setting the time to wait to 10s
    time.tv_sec = 10;
    time.tv_usec = 0;

    value = select(1, &Read_fd_set, &Write_fd_set, NULL, &time);

    if (value == -1)
        perror("error ");
    else if (value) // returnVal -> 1 due because STDIN will contain the data
        printf("The data is now available\n");
    else // returnVal -> 0 due to time out
        printf("No data was given for 10 seconds\n");
}
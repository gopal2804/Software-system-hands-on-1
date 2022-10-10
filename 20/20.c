#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 

void main(int argc, char *argv[])
{
    int priority, newPriority;
    if (argc != 2)
        printf("Please pass the integer value to set the priority in command line\n");
    else
    {
        newPriority = atoi(argv[1]); //String to integer conversion
        priority = nice(0); // storing the current priority of the running process after adding 0 to it
        printf("Current priority of the running process is: %d\n", priority);
        priority = nice(newPriority); // Adding the newPriority to the current priority
        printf("\nNew priority of the running process is: %d\n", priority);
    }
}
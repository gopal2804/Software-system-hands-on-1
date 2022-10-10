#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>    
#include <unistd.h>   
#include <stdio.h>     
void main()
{
    char *file = "ticket.txt"; 
    int fd, fcntlStatus;
    ssize_t read_, write_;
    off_t lseek_offset;
    int buffer;
    struct flock ticket_lock;

    fd = open(file, O_CREAT | O_RDWR, S_IRWXU);

    if (fd == -1)
        perror("Error occured, file not opening!");
    else
    {
        ticket_lock.l_type = F_WRLCK;
        ticket_lock.l_pid = getpid();
        // locking the entire file
        ticket_lock.l_whence = SEEK_SET;
        ticket_lock.l_len = 0;
        ticket_lock.l_start = 0;

        fcntlStatus = fcntl(fd, F_GETLK, &ticket_lock);

        if (fcntlStatus == -1)
            perror("Error while getting the lock access!");
        else
        {
            switch (ticket_lock.l_type)
            {
            case F_WRLCK:
                // File already has write lock
                printf("The ticket File %s is already locked for writing!\n", file);
                break;
            case F_RDLCK:
                // File already has a read lock
                printf("The ticket File %s is already locked for reading!\n", file);
                break;
            default:
                // No lock on the file
                ticket_lock.l_type = F_WRLCK;
                fcntlStatus = fcntl(fd, F_SETLKW, &ticket_lock);
                if (fcntlStatus == -1)
                    perror("Error while locking the ticket file!");
                else
                {
                    read_ = read(fd, &buffer, sizeof(int));
                    if (read_ == -1)
                        perror("Error while reading ticket!");
                    else if (read_ == 0)
                    {
                        buffer = 1;
                        write_ = write(fd, &buffer, sizeof(int));
                        if (write_ == -1)
                            perror("Error while writing to ticket!");
                        else
                            printf("Your ticket number is %d\n", buffer);
                    }
                    else
                    {
                        lseek_offset = lseek(fd, 0, SEEK_SET);
                        if (lseek_offset == -1)
                            perror("Error while seeking!");
                        else
                        {
                            buffer += 1;
                            write_ = write(fd, &buffer, sizeof(int));
                            printf("Your ticket number is: %d\n", buffer);
                        }
                    }
                    ticket_lock.l_type = F_UNLCK;
                    fcntlStatus = fcntl(fd, F_SETLKW, &ticket_lock);
                    if (fcntlStatus == -1)
                        perror("Error releasing lock!");
                    else
                        printf("Done!\n");
                }
            }
        }
        close(fd);
    }
}
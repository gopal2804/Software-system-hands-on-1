#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>

#include "18_record.h" 

void main(int argc, char *argv[])
{
    int fd, fcntlStatus, recordNumber;
    ssize_t read_, write_;
    off_t lseekOffset;
    struct flock lock;
    struct record record;

    if (argc != 2)
    {
        printf("Pass the record number to be read as the argument program\n");
        _exit(0);
    }

    recordNumber = (int)*argv[1] - 48;

    if (recordNumber > 0 && recordNumber < 4)
    {
        fd = open(file, O_RDONLY);

        if (fd == -1)
            perror("Error while opening the file");
        else
        {
            lock.l_type = F_RDLCK;
            lock.l_start = sizeof(struct record) * (recordNumber - 1);
            lock.l_len = sizeof(struct record);
            lock.l_whence = SEEK_SET;
            lock.l_pid = getpid();

            fcntlStatus = fcntl(fd, F_GETLK, &lock);
            if (fcntlStatus == -1)
                perror("Error while checking lock status");
            else
            {
                switch (lock.l_type)
                {
                case F_WRLCK:
                    // Record already has write lock
                    printf("Record already has write lock!\n");
                    break;
                default:
                    // Record is unlocked / is locked for reading
                    lock.l_type = F_RDLCK;
                    fcntlStatus = fcntl(fd, F_SETLKW, &lock);
                    if (fcntlStatus == -1)
                        perror("Error while getting read lock on the record");
                    else
                    {
                        lseekOffset = lseek(fd, lock.l_start, SEEK_SET);
                        printf("Reading record %d...\n", recordNumber);
                        read_ = read(fd, &record, sizeof(record));

                        if (read_ == -1)
                            perror("Error while reading record!");
                        else
                        {
                            lseekOffset = lseek(fd, lock.l_start, SEEK_SET);
                            if (lseekOffset == -1)
                                perror("Error while seeking!");
                            else
                                printf("The record %d has the value %d\n", record.recordNumber, record.someNumber);
                        }
                        // sleep(10); //Uncomment for to delay the releasing of the read lock
                        fcntlStatus = fcntl(fd, F_UNLCK, &lock);
                        if (fcntlStatus == -1)
                            perror("Error while unlocking!");
                    }
                }
                close(fd);
            }
        }
    }
    else
        printf("Record with %d doesn't exist!\n", recordNumber);
}
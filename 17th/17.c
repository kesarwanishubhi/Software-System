/*
======================================================================================================================================================================
Name : 17.c
Author : SHUBHI KESARWANI
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
======================================================================================================================================================================
======================================================================================================================================================================
Sample Output:Updated ticket number to 1001




======================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define TICKET_FILE "prg.txt"
#define BUFFER_SIZE 12

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    int ticket_number;
    struct flock lock;

    
    fd = open(TICKET_FILE, O_RDWR);
    

    
    lock.l_type = F_WRLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; 
    
    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        perror("Error applying lock");
        close(fd);
        return 1;
    }

    
    lseek(fd, 0, SEEK_SET); 
    if (read(fd, buffer, sizeof(buffer)) < 0) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    
    ticket_number = atoi(buffer);

   
    ticket_number++;

   
    snprintf(buffer, sizeof(buffer), "%d", ticket_number);
    lseek(fd, 0, SEEK_SET);
    if (write(fd, buffer, sizeof(buffer)) < 0) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    
    lock.l_type = F_UNLCK; 
    if (fcntl(fd, F_SETLK, &lock) < 0) {
        perror("Error releasing lock");
        close(fd);
        return 1;
    }

    close(fd);

    printf("Updated ticket number to %d\n", ticket_number);

    return 0;
}

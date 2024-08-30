/*
======================================================================================================================================================================
Name : 17a.c
Author : SHUBHI KESARWANI
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
======================================================================================================================================================================
======================================================================================================================================================================
Sample Output:Ticket file initialized with new ticket number 1000




======================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define TICKET_FILE "prg.txt"
#define INITIAL_TICKET 1000

int main() {
    int fd;
    char ticket_no[10];

    
    fd = open(TICKET_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error");
        return 1;
    }

    
    snprintf(ticket_no, sizeof(ticket_no), "%d", INITIAL_TICKET);
    if (write(fd, ticket_no, sizeof(ticket_no)) < 0) {
        perror("Error");
        close(fd);
        return 1;
    }

    
    close(fd);
    printf("Ticket file initialized with new ticket number %d\n", INITIAL_TICKET);

    return 0;
}

/*
======================================================================================================================================================================
Name : 12.c
Author :SHUBHI KESARWANI
Description : Write a program to find out the opening mode of a file. Use fcntl.
======================================================================================================================================================================
======================================================================================================================================================================
Sample Output:
File descriptor flags:
  - O_WRONLY (write-only)


======================================================================================================================================================================

*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *filename = "sample.txt";

    
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    
    int flags = fcntl(fd, F_GETFL);
    if (flags < 0) {
        perror("ERROR");
        close(fd);
        return 1;
    }

    
    printf("File descriptor flags:\n");
    if (flags & O_RDONLY) printf("  - O_RDONLY (read-only)\n");
    if (flags & O_WRONLY) printf("  - O_WRONLY (write-only)\n");
    if (flags & O_RDWR) printf("  - O_RDWR (read-write)\n");
    if (flags & O_APPEND) printf("  - O_APPEND (append mode)\n");
    if (flags & O_NONBLOCK) printf("  - O_NONBLOCK (non-blocking mode)\n");
    if (flags & O_SYNC) printf("  - O_SYNC (synchronous I/O)\n");
    if (flags & O_CREAT) printf("  - O_CREAT (create file if it does not exist)\n");
    if (flags & O_TRUNC) printf("  - O_TRUNC (truncate file to zero length)\n");
    if (flags & O_EXCL) printf("  - O_EXCL (exclusive creation)\n");

    
    close(fd);
    return 0;
}
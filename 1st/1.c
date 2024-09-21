/*
======================================================================================================================================================================
Name : 1.c
Author : SHUBHI KESRARWANI
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
======================================================================================================================================================================

======================================================================================================================================================================
Sample Output:
ln -s s.txt soft
ln s.txt hard
mkfifo fifo


======================================================================================================================================================================
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <source_file> <hardlink_file> <symlink_file> <fifo_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Creating a hard link file
    if (link(argv[1], argv[2]) == -1) {
        perror("Error creating hard link");
    } else {
        printf("Hard link file '%s' created successfully\n", argv[2]);
    }

    // Creating a symbolic link file
    if (symlink(argv[1], argv[3]) == -1) {
        perror("Error creating symbolic link");
    } else {
        printf("Symbolic link file '%s' created successfully\n", argv[3]);
    }

    // Creating a FIFO file
    if (mkfifo(argv[4], S_IFIFO | S_IRWXU) == -1) {
        perror("Error creating FIFO");
    } else {
        printf("FIFO file '%s' created successfully\n", argv[4]);
    }

    return 0;
}


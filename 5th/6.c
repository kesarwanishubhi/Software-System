/*
=======================================================================================================================================================================================
Name : 5.c
Author : SHUBHI KESARWANI
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.

=======================================================================================================================================================================================

=======================================================================================================================================================================================
Sample Output:
5.out  6.c  6.out  a.out  file1.txt  file2.txt  file3.txt  file4.txt  file5.txt




========================================================================================================================================================================================
*/




#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *filenames[] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};
    int num_files = sizeof(filenames) / sizeof(filenames[0]);
    
    while (1) {
        for (int i = 0; i < num_files; ++i) {
            int fd = open(filenames[i], O_CREAT | O_RDWR | O_TRUNC, 0666);
           
              close(fd); 
        }
    }
    
    return 0;
}



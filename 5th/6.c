/*
=======================================================================================================================================================================================
Name : 5.c
Author : SHUBHI KESARWANI
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.

=======================================================================================================================================================================================

=======================================================================================================================================================================================
Sample Output:
5.out  6.c  6.out  a.out  file1.txt  file2.txt  file3.txt  file4.txt  file.txt




========================================================================================================================================================================================
*/




#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(){
    int fd =creat("file.txt", O_RDWR);
    fd = creat("file1.txt", O_RDWR);
    fd = creat("file2.txt", O_RDWR);
    fd = creat("file3.txt", O_RDWR);
    fd = creat("file4.txt", O_RDWR);
    for(;;){}

    return 0;
}
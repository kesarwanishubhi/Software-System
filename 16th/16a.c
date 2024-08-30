/*
======================================================================================================================================================================
Name : 16a.c
Author :SHUBHI KESARWANI
Description : Write a program to perform mandatory locking.
		a. Implement write lock
		b. Implement read lock

======================================================================================================================================================================

======================================================================================================================================================================
Sample output:

Before locking the file for reading
Read lock acquired successfully....
Enter to unlock...



======================================================================================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(){
        struct flock fl;
        char str[100];
        int fd = open("file.txt", O_RDWR|O_CREAT, 0666);
        fl.l_type = F_RDLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 0;
        fl.l_len = 0;
        fl.l_pid = getpid();
        printf("Before locking the file for reading\n");
        fcntl(fd, F_SETLKW, &fl);
        printf("Read lock acquired successfully....\n");
        printf("Enter to unlock...\n");
        getchar();
        fl.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &fl);
        printf("Finish\n");
        return 0;
}
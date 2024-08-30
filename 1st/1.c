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

======================================================================================================================================================================
*/

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
    if(argc < 3){
        perror("Please enter the source file and destination file names");
    }
    else{
        //Creating a hard link file
        if(link(argv[1], argv[2]) == -1){
            perror("link");
        }
        else{
            printf("Hard link file created successfully\n");
        }

        //Creating a softlink file
        if(symlink(argv[1], argv[3]) == -1){
            perror("symlink");
        }
        else{
            printf("Soft link file created successfully\n");
        }

        //Creating a FIFO file
        //if(mkfifo("myfifofile", S_IFIFO|S_IRWXU) == -1){
        //  perror("mkfifo");
        //}

        if(mknod(argv[4], S_IFIFO, 0) == -1){
            perror("Failed to create named pipe");
        }
        else {
            printf("FIFO file created successfully\n");
        }
    }
    return 0;
}

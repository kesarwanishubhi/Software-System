/*
=================================================================================================================================================================================
Name : 11.c
Author :SHUBHI KESARWANI
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
		a. use dup
		b. use dup2
		c. use fcntl

=================================================================================================================================================================================

=================================================================================================================================================================================
Sample Output:

Using dup
fd1 = 3
fd2 = 4
Using dup2
fd1 = 3
fd3 = 27
Using fcntl
fd1 = 3
fd4 = 28

=================================================================================================================================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
	int fd = open("11.txt", O_RDWR|O_APPEND);
	int f2, f3, f4;
	if(fd == -1)
	{
		perror("open");
	}
	else{
		printf("Using dup\n");
		f2 = dup(fd);
		printf("fd1 = %d\n", fd);
		printf("fd2 = %d\n", f2);
		write(fd, "This is written by the original file descriptor\n", 48);
		write(f2, "This is written by the duplicate file descriptor\n", 49);
		
		printf("Using dup2\n");
		f3 = dup2(fd, 27);
		printf("fd1 = %d\n", fd);
		printf("fd3 = %d\n", f3);
		write(fd, "Using dup2\nThis is written by the original file descriptor\n", 59);
		write(f2, "This is written by the duplicate file descriptor\n", 49);
		
		printf("Using fcntl\n");
		f4 = fcntl(fd, F_DUPFD, 27);
		printf("fd1 = %d\n", fd);
		printf("fd4 = %d\n", f4);
		write(fd, "Using fcntl\nThis is written by the original file descriptor\n", 60);
		write(f2, "This is written by the duplicate file descriptor\n", 49);
		
		close(fd);
		close(f2);
		close(f3);
		close(f4);
	}
	return 0;
}
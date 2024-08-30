/*
======================================================================================================================================================================
Name : 7.c
Author : SHUBHI KESARWANI
Description : Write a program to copy file1 into file2 ($cp file1 file2).

======================================================================================================================================================================

======================================================================================================================================================================
Sample Output:
File copied successfully



======================================================================================================================================================================
*/



#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		printf("Please provide destination path");
		return 0;
	}
	char buf[1000];
		int fd1 = open(argv[1], O_RDONLY);
		int fd2 = open(argv[2], O_WRONLY|O_CREAT, 0666);
		if(fd1 == -1 || fd2 == -1){
			printf("Could not open the source and destination file\n");
		}
		else{

			int i = read(fd1, buf, sizeof(buf));
			while(i > 0){
				write(fd2, buf, i);
				i = read(fd1, buf, sizeof(buf));
			}	
			printf("File copied successfully\n");
			close(fd1);
			close(fd2);
		}
	
	return 0;
}

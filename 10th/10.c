/*
======================================================================================================================================================================
Name :10.c
Author :SHUBHI KESARWANI
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.

======================================================================================================================================================================
SAMPLE OUTPUT:
Location of the file pointer after lseek (in bytes): 28

======================================================================================================================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("Error: Please enter the file name as argument");
	}
	else{
		int fd = open(argv[1], O_RDWR|O_CREAT, 0666);
		write(fd, "Hello, how are you", 18);
		int loc = lseek(fd, 10, SEEK_CUR);
		printf("Location of the file pointer after lseek (in bytes): %d\n", loc);
	       	write(fd, "How was the day?", 16);
	}

	return 0;
}	
/*
======================================================================================================================================================================
Name : 8.c
Author : SHUBHI KESARWANI
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.

======================================================================================================================================================================

======================================================================================================================================================================
Sample Output:
Line 1 : hello world
Line 2 : hi how are you 
Line 3 : i am fine 
Line 4 : you tell
Line 5 : 



======================================================================================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){
	char str[1000] = "";
	char ch;
	int i=1;

	int fd = open("sample.txt", O_RDONLY);
	while(read(fd, &ch, 1) > 0){
		if(ch == '\n'){
			printf("Line %d : %s\n", i, str);
			i++;
			strcpy(str, "");
		}
		else{
			strncat(str, &ch, 1);
		}
	}
	close(fd);
	return 0;

}

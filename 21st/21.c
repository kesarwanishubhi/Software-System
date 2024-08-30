/*
======================================================================================================================================================================
Name : 21.c
Author : SHUBHI KESARWANI
Description : Write a program, call fork and print the parent and child process id.

======================================================================================================================================================================

======================================================================================================================================================================
Sample Output:
In Parent process, pid = 7956
Child process PID = 7957
In child process, parent process PID: 7956
Child process PID: 7957


======================================================================================================================================================================
*/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int pid = fork();
	if(!pid){
		printf("In child process, parent process PID: %d\n", getppid());
		printf("Child process PID: %d\n", getpid());
	}
	else{
		printf("In Parent process, pid = %d\n", getpid());
		printf("Child process PID = %d\n", pid);
	}
	return 0;
}
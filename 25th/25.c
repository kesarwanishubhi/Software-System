/*
======================================================================================================================================================================
Name : 25.c
Author :SHUBHI KESARWANI
Description : Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).

======================================================================================================================================================================
======================================================================================================================================================================
Sample Output:

Child process 1 exiting
Child process 3 exiting
Child process 2 exited with status: 2
Parent process exiting
======================================================================================================================================================================

*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	int pid1,pid2,pid3, status;
	pid1 = fork();
	if(pid1 > 0){
		pid2 = fork();
		if(pid2 > 0){
			pid3 = fork();
			if(pid3 > 0){
				waitpid(pid2, &status, 0);
				printf("Child process 2 exited with status: %d\n",WEXITSTATUS(status));
			}
			else{
				printf("Child process 3 exiting\n");
				exit(0);
			}
		}
		else{
			sleep(5);
			exit(2);
		}
		printf("Parent process exiting\n");
	}
	else{
		printf("Child process 1 exiting\n");
		exit(0);
	}
	return 0;
}
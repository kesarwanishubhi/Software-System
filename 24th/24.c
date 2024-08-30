/*
======================================================================================================================================================================
Name : 24.c
Author : SHUBHI KESRARWANI
Description :Write a program to create an orphan process.
======================================================================================================================================================================

======================================================================================================================================================================
Sample Output:
In parent process, with PID: 6259
Child PID is: 6260
In child, process, PID: 6260
Parent PID is: 1528


======================================================================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
	int p;
	p = fork();
	if(p==0)
    	{
    	printf("In child, process, PID: %d\n",getpid());
		printf("Parent PID is: %d\n",getppid());
		sleep(3); 
		printf("In child, process, PID: %d\n",getpid());
		printf("Parent PID is: %d\n",getppid());
    	}
	else
	{
		printf("In parent process, with PID: %d\n",getpid());
		printf("Child PID is: %d\n",p);
		exit(0);
	}
	return 0;
 }
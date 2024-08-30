/*
======================================================================================================================================================================
Name : 23.c
Author : SHUBHI KESRARWANI
Description : Write a program to create a Zombie state of the running program.

======================================================================================================================================================================

======================================================================================================================================================================
Sample Output:


======================================================================================================================================================================
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
	int child_pid;
	child_pid = fork();
	if (child_pid > 0) {
		//printf("Entered the zombie state");
		sleep (30);
	}
	else {
		exit (0);
	}
	return 0;
}
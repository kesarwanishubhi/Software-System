/*
==============================================================================================================================
Name : 31a.c
Shubhi kesarwani

=
Sample output:
Binary semaphore created successfully
Current semaphore value: 1


------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x62051b77 0          shubhi    666        1         

==============================================================================================================================
*/
#include <unistd.h> 

#include <stdio.h>

#include <sys/sem.h>

#include <sys/ipc.h>

#include <sys/types.h>

#include <sys/time.h> 

#include <time.h>

union semun{
	int val;    /* Value for SETVAL */
       	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
       	unsigned short int *array;
};

int main(){
	int key = ftok(".", 'b');
	int semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
	if (semid == -1) {
        	perror("semget");
    	}
    	union semun arg;
    	arg.val = 1;
    	int retval = semctl (semid, 0, SETVAL, arg);
    	
    	if(retval == 0) printf("Binary semaphore created successfully\n");
    	else perror("semctl");
    	struct sembuf sem_operation = {0, 0, SEM_UNDO};
    	int current_value = semctl(semid, 0, GETVAL, sem_operation);
    	printf("Current semaphore value: %d\n", current_value);
    	return 0;
    	
}
	
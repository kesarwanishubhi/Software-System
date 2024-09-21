/*
==============================================================================================================================
Name : 31b.c
Shubhi kesarwani
Sample output:
Counting semaphore created successfully
------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x62051b77 0          shubhi     666        1         
0x63051b77 1          shubhi     744        1         

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
	int val;    
       	struct semid_ds *buf;    
       	unsigned short int *array;
};

int main(){
	int key = ftok(".", 'c');
	int sem_id = semget(key, 1, IPC_CREAT | IPC_EXCL | 0744);
	if (sem_id == -1) {
        	perror("semget");
    	}
    	union semun arg;
    	arg.val = 5;
    	int retval = semctl (sem_id, 0, SETVAL, arg);
    	
    	if(retval == 0) printf("Counting semaphore created successfully\n");
    	else perror("semctl");
    	return 0;
}
	
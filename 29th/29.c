/*
======================================================================================================================================================================
Name : 29.c
Author : SHUBHI KESARWANI
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).

======================================================================================================================================================================
======================================================================================================================================================================
Sample Output:
[sudo] password for tushar: 
Policy used is standard round robin time sharing
Scheduling policy has been updated to real time round robin, with priority 0




======================================================================================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sched.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<sys/stat.h>

int main(){
	int p;
	struct sched_param sp;
	sp.sched_priority = 20;
	p = sched_getscheduler(0);
	if(p == -1){
		perror("sched_getscheduler");
		return 0;
	}
	switch(p){
		case SCHED_OTHER:
			printf("Policy used is standard round robin time sharing\n");
			break;
		case SCHED_FIFO:
                        printf("Policy used is real time FIFO scheduling\n");
                        break;
		case SCHED_RR:
                        printf("Policy used is real time round robin scheduling\n");
                        break;
	}

	int pq= sched_setscheduler(0, SCHED_RR, &sp);

	if(pq== -1){
		perror("sched_setscheduler");
		return 0;
	}
	if(sched_getscheduler(0) == SCHED_RR){
		printf("Scheduling policy has been updated to real time round robin, with priority %d\n", getpriority(PRIO_PROCESS, getpid()));
	}
	for(;;);

	return 0;
}



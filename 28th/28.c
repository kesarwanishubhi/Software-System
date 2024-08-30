/*
======================================================================================================================================================================
Name : 28.c
Author : SHUBHI KESARWANI
Description : Write a program to get maximum and minimum real time priority.

======================================================================================================================================================================
======================================================================================================================================================================
Sample Output:
Real-time scheduling priorities:
SCHED_FIFO:
  Maximum Priority: 99
  Minimum Priority: 1
SCHED_RR:
  Maximum Priority: 99
  Minimum Priority: 1


======================================================================================================================================================================
*/
#include <stdio.h>
#include <sched.h>
#include <errno.h>

int main() {
    int max_fifo, min_fifo;
    int max_rr, min_rr;

    
    max_fifo = sched_get_priority_max(SCHED_FIFO);
    min_fifo = sched_get_priority_min(SCHED_FIFO);

    if (max_fifo == -1 || min_fifo == -1) {
        perror("sched_get_priority_max/min");
        return 1;
    }

    
    max_rr = sched_get_priority_max(SCHED_RR);
    min_rr = sched_get_priority_min(SCHED_RR);

    if (max_rr == -1 || min_rr == -1) {
        perror("sched_get_priority_max/min");
        return 1;
    }

    
    printf("Real-time scheduling priorities:\n");
    printf("SCHED_FIFO:\n");
    printf("  Maximum Priority: %d\n", max_fifo);
    printf("  Minimum Priority: %d\n", min_fifo);
    
    printf("SCHED_RR:\n");
    printf("  Maximum Priority: %d\n", max_rr);
    printf("  Minimum Priority: %d\n", min_rr);

    return 0;
}


/*
======================================================================================================================================================================
Name : 19.c
Author : SHUBHI KESARWANI
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.

======================================================================================================================================================================
======================================================================================================================================================================
Sample Output:
Process ID: 26997
Time taken to execute getpid: 13400

======================================================================================================================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <stdint.h> 
#include <x86intrin.h> 

uint64_t get_tsc() {
    return __rdtsc();
}

int main() {
    uint64_t st, end;
    pid_t pid;

   
    st = get_tsc();

    pid = getpid();

   
    end = get_tsc();

    
    uint64_t t_taken = end - st;

    printf("Process ID: %d\n", pid);
    printf("Time taken to execute getpid: %lu\n", t_taken);

    return 0;
}

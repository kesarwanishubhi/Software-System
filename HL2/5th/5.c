/*
==================================================================================================================================================================================
Name : 5.c
Shubhi kesarwani

SAMPLE OUTPUT:
Maximum length of arguments to exec family: 2097152 bytes
Maximum number of simultaneous processes per user ID: 30500
Number of clock ticks (jiffy) per second: 100
Maximum number of open files: Soft limit = 1024, Hard limit = 1048576
Size of a page: 4096 bytes
Total number of pages in physical memory: 1970737
Number of currently available pages in physical memory: 791428
========================================================================================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
#include <limits.h>
#include <sys/sysinfo.h>
#include <stdlib.h>

int main() {
    // a. Maximum length of the arguments to the exec family of functions
    long max = sysconf(_SC_ARG_MAX);
    printf("Maximum length of arguments to exec family: %ld bytes\n", max);

    // b. Maximum number of simultaneous processes per user ID
    long max_p = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user ID: %ld\n", max_p);

    // c. Number of clock ticks (jiffy) per second
    long clock= sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks (jiffy) per second: %ld\n", clock);

    // d. Maximum number of open files
    struct rlimit limit;
    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("Maximum number of open files: Soft limit = %lu, Hard limit = %lu\n",
               limit.rlim_cur, limit.rlim_max);
    } else {
        perror("getrlimit failed");
    }

    // e. Size of a page
    long page = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", page);

    // f. Total number of pages in the physical memory
    struct sysinfo si;
    if (sysinfo(&si) == 0) {
        printf("Total number of pages in physical memory: %ld\n", si.totalram / page);
    } else {
        perror("sysinfo failed");
    }

    // g. Number of currently available pages in the physical memory
    if (sysinfo(&si) == 0) {
        printf("Number of currently available pages in physical memory: %ld\n", si.freeram / page);
    } else {
        perror("sysinfo failed");
    }

    return 0;
}

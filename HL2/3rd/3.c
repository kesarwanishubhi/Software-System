/*
==================================================================================================================================================================================
Name : 3.c
Shubhi kesarwani


Sample Output:
[sudo] password for shubhi: 
Current Limits:
Soft limit: 8388608
Hard limit: 18446744073709551615
New Limits:
Soft limit: 4194304
Hard limit: 18446744073709551615



==================================================================================================================================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() {
    struct rlimit l;

    
    if (getrlimit(RLIMIT_STACK, &l) != 0) {
        perror("getrlimit failed");
        return EXIT_FAILURE;
    }

    
    printf("Current Limits:\n");
    printf("Soft limit: %lu\n", l.rlim_cur);
    printf("Hard limit: %lu\n", l.rlim_max);

    
    l.rlim_cur = 4 * 1024 * 1024;

    if (setrlimit(RLIMIT_STACK, &l) != 0) {
        perror("setrlimit failed");
        return EXIT_FAILURE;
    }

    
    if (getrlimit(RLIMIT_STACK, &l) != 0) {
        perror("getrlimit failed");
        return EXIT_FAILURE;
    }

    printf("New Limits:\n");
    printf("Soft limit: %lu\n", l.rlim_cur);
    printf("Hard limit: %lu\n", l.rlim_max);

    return EXIT_SUCCESS;
}

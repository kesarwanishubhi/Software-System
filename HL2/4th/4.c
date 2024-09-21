/*
==================================================================================================================================================================================
Name : 4.c
Shubhi kesarwani


Sample Output:
Time taken to execute 100 getppid() calls: 66626 CPU cycles



==================================================================================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static inline uint64_t rdtsc() {
    unsigned int l, h;
    __asm__ __volatile__ ("rdtsc" : "=a"(l), "=d"(h));
    return ((uint64_t)h << 32) | l;
}

int main() {
    const int iter = 100;
    uint64_t start, end;

    
    start = rdtsc();

    for (int i = 0; i < iter; i++) {
        getppid(); 
    }

    
    end = rdtsc();

    
    uint64_t elap = end - start;

    printf("Time taken to execute %d getppid() calls: %lu CPU cycles\n", iter, elap);

    return 0;
}

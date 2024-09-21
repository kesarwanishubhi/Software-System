/*
==================================================================================================================================================================================
Name : 6.c
Shubhi kesarwani

SAMPLE OUTPUT:
Thread 1: Hello from thread!
Thread 2: Hello from thread!
Thread 3: Hello from thread!
All threads have finished
==============================================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Function that each thread will execute
void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    printf("Thread %d: Hello from thread!\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3]; 
    int thread_ids[3];    

   
    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1; 
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("Failed");
            exit(EXIT_FAILURE);
        }
    }

    
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished\n");
    return 0;
}

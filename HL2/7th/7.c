/*
==================================================================================================================================================================================
Name : 7.c
Shubhi kesarwani


Sample Output:
Thread ID: 139882758403776
Thread ID: 139882741618368
Thread ID: 139882750011072
All threads have finished.

==================================================================================================================================================================================
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Function that each thread will execute
void* thread_f(void* arg) {
    pthread_t thread_id = pthread_self(); 
    printf("Thread ID: %lu\n", (unsigned long)thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3]; 

   
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_f, NULL) != 0) {
            perror("Failed");
            exit(EXIT_FAILURE);
        }
    }

   
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished.\n");
    return 0;
}

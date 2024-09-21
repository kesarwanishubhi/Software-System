/*
==============================================================================================================================
Name : 30.c
SHUBHI KESARWANI


Sample output:
Written to shared memory: Hello, Shared Memory!
Current content in shared memory: Hello, Shared Memory!
Shared memory removed successfully.

==============================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

#define SHM_SIZE 1024  

void print_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
   
    key_t key = ftok("file", 65); // Generate a unique key
    if (key == -1) {
        print_error("ftok");
    }

    
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        print_error("shmget");
    }

   
    char *data = shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        print_error("shmat");
    }

   
    const char *message = "Hello, Shared Memory!";
    strncpy(data, message, SHM_SIZE);
    printf("Written to shared memory: %s\n", data);

   
    if (shmdt(data) == -1) {
        print_error("shmdt");
    }
    data = shmat(shmid, NULL, SHM_RDONLY);
    if (data == (char *)(-1)) {
        print_error("shmat with O_RDONLY");
    }

    
    printf("Current content in shared memory: %s\n", data);

    
    if (shmdt(data) == -1) {
        print_error("shmdt");
    }

   
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        print_error("shmctl IPC_RMID");
    }

    printf("Shared memory removed successfully.\n");

    return 0;
}

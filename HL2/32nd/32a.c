/*
==================================================================================================================================================================================
Name : 32a.c
Shubhi kesarwani
Description : Write a program to implement semaphore to protect any critical section.
		a. rewrite the ticket number creation program using semaphore
		b. protect shared memory from concurrent write access
		c. protect multiple pseudo resources ( may be two) using counting semaphore
		d. remove the created semaphore

Sample Output:
Before entering into critical section...
Current semaphore value: 1
Inside the critical section...
Current semaphore value: 0
Current ticket number: 1
Press enter to unlock and exit^C


==================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdlib.h>

union semun {
    int val;                    
    struct semid_ds *buf;       
    unsigned short int *array;
};

int main() {
    struct flock fl;
    int ticketno;
    int fd = open("t1.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    
    if (fd == -1) {
        printf("Error: Could not open file\n");
        return EXIT_FAILURE;
    }

    int key = ftok("/home/shubhi/Desktop/Software System/HL2/32nd", 'b');
    if (key == -1) {
        perror("ftok");
        close(fd);
        return EXIT_FAILURE;
    }

    // Create semaphore if it does not exist
    int semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
    if (semid == -1) {
        // If the semaphore already exists, get its ID
        semid = semget(key, 1, 0);
        if (semid == -1) {
            perror("semget");
            close(fd);
            return EXIT_FAILURE;
        }
    } else {
        // Initialize the semaphore to 1
        union semun arg;
        arg.val = 1;
        if (semctl(semid, 0, SETVAL, arg) == -1) {
            perror("semctl SETVAL");
            close(fd);
            return EXIT_FAILURE;
        }
    }

    struct sembuf sem_lock = {0, -1, SEM_UNDO};
    struct sembuf sem_unlock = {0, 1, SEM_UNDO};

    printf("Before entering into critical section...\n");
    struct sembuf sem_operation = {0, 0, SEM_UNDO};
    int current_value = semctl(semid, 0, GETVAL, sem_operation);
    printf("Current semaphore value: %d\n", current_value);

    if (semop(semid, &sem_lock, 1) == -1) {
        perror("semop lock");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Inside the critical section...\n");
    current_value = semctl(semid, 0, GETVAL, sem_operation);
    printf("Current semaphore value: %d\n", current_value);
    
    read(fd, &ticketno, sizeof(ticketno));
    ticketno++;
    printf("Current ticket number: %d\n", ticketno);
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticketno, sizeof(ticketno));

    printf("Press enter to unlock and exit");
    getchar();

    if (semop(semid, &sem_unlock, 1) == -1) {
        perror("semop unlock");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);
    printf("Completed!\n");

    return 0;
}

















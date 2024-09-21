/*
==================================================================================================================================================================================
Name : 12.c
Shubhi kesarwani


Sample Output:
Parent process (PID: 13299) created child (PID: 13300)
Parent process is about to kill itself...
Killed
Child process (PID: 13300) is running and will become an orphan now.

==================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <wait.h>

void handle_sigkill(int sig) {
    printf("Parent process (%d) is terminating.\n", getpid());
    exit(0);
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        printf("Parent process (PID: %d) created child (PID: %d)\n", getpid(), pid);
        
        
        signal(SIGKILL, handle_sigkill);

        
        printf("Parent process is about to kill itself...\n");
        kill(getpid(), SIGKILL); // This will kill the parent process
        
        
        printf("Parent process is still running.\n");
    } else { // Child process
        
        sleep(1);
        
        printf("Child process (PID: %d) is running and will become an orphan now.\n", getpid());
        
       
        while (1) {
            sleep(1);
        }
    }

    return 0;
}

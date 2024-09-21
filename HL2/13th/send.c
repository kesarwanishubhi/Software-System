#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid;
    
    printf("Enter the PID of the process to signal: ");
    scanf("%d", &pid);
    
    
    printf("Sending SIGSTOP to process %d\n", pid);
    kill(pid, SIGSTOP);
    
    sleep(1); 

    
    printf("Sending SIGUSR1 to process %d\n", pid);
    kill(pid, SIGUSR1);

    return 0;
}

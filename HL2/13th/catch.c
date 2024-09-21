#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int signal) {
    if (signal == SIGUSR1) {
        printf("Caught SIGUSR1 signal!\n");
    }
}

int main() {
    // Set up the signal handler for SIGUSR1
    signal(SIGUSR1, handle_signal);

    printf("Process ID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signal...\n");

    // Infinite loop to wait for the signal
    while (1) {
        pause(); // Suspend the process until a signal is received
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum, siginfo_t *info, void *context) {
    printf(" Caught signal %d: SIGINT (Interrupt from keyboard)\n", signum);
    printf("Exiting\n");
    exit(EXIT_SUCCESS);
}

int main() {

    struct sigaction s;

    s.sa_flags = SA_SIGINFO;    
    s.sa_sigaction = sigint_handler; 
    sigemptyset(&s.sa_mask);  

    if (sigaction(SIGINT, &s, NULL) == -1) {
        perror("sigaction(SIGINT) failed");
        return 1;
    }

    printf("Press Ctrl+C to send SIGINT\n");

    while (1) {
        pause(); 
    }

    return 0;
}
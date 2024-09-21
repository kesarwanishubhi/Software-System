/*
==================================================================================================================================================================================
Name : 11.c
Shubhi kesarwani


Sample Output:
SIGINT is now ignored. Press Ctrl+C to test...
^CSIGINT is now reset. Press Ctrl+C again...
^C
==================================================================================================================================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum) {
    printf("SIGINT found this should not happen during ignore).\n");
}

int main() {
    struct sigaction s;

    
    s.sa_handler = SIG_IGN;
    sigemptyset(&s.sa_mask);
    s.sa_flags = 0;

    
    if (sigaction(SIGINT, &s, NULL) == -1) {
        perror("Failed to ignore SIGINT");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is now ignored. Press Ctrl+C to test...\n");
    sleep(5); 

    
    s.sa_handler = SIG_DFL; 

    if (sigaction(SIGINT, &s, NULL) == -1) {
        perror("Failed to reset SIGINT to default");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is now reset. Press Ctrl+C again...\n");
    sleep(5); 
    printf("Exiting program. You can now press Ctrl+C.\n");
    return 0;
}

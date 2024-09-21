/*
==================================================================================================================================================================================
Name : 7.c
Shubhi kesarwani
===================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    
    printf("SIGINT caught (this should not happen during ignore).\n");
}

int main() {
   
    if (signal(SIGINT, SIG_IGN) == SIG_ERR) {
        perror("Failed to ignore SIGINT");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is now ignored. Press Ctrl+C to test...\n");
    sleep(4); 
    
    if (signal(SIGINT, SIG_DFL) == SIG_ERR) {
        perror("Failed to reset SIGINT to default");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is now reset to default action. Press Ctrl+C again...\n");
    sleep(5); 

    printf("Exiting program. You can now press Ctrl+C.\n");
    return 0;
}

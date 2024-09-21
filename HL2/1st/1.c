/*
=======================================================================================================================
NAME-SHUBHI KESARWANI 
QUESTION-. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
========================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum) {
    printf("ITIMER_REAL: Timer expired!\n");
    exit(0);
}

int main() {
    struct itimerval t;

    
    signal(SIGALRM, handler);

    
    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 0;
    t.it_interval.tv_sec = 0;
    t.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &t, NULL);

    
    while (1) {
        pause();
    }

    return 0;
}

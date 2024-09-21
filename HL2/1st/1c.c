#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
void handler(int signum) {
    printf("ITIMER_PROF: Timer expired!\n");
}

int main() {
    struct itimerval timer;

    
    signal(SIGPROF, handler);

    
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    
    while (1) {
        
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum) {
    printf("ITIMER_VIRTUAL: Timer expired!\n");
}

int main() {
    struct itimerval t;

    
    signal(SIGVTALRM, handler);

   
    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 0;
    t.it_interval.tv_sec = 0;
    t.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &t, NULL);

    
    while (1) {
        
    }

    return 0;
}

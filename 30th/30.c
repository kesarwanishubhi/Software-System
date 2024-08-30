

/*
============================================================================
Name : 30.c
Author :SHUBHI KESARWANI
Description : Write a program to run a script at a specific time using a Daemon process.

============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <errno.h>

void create_daemon() {
    pid_t pid;

    
    pid = fork();

    if (pid < 0) {
        perror("Failed to fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        
        exit(EXIT_SUCCESS);
    }

    
    if (setsid() < 0) {
        perror("Failed to create new session");
        exit(EXIT_FAILURE);
    }

    
    pid = fork();

    if (pid < 0) {
        perror("Failed to fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        // First child exits
        exit(EXIT_SUCCESS);
    }

    
    umask(0);

    
    for (int x = sysconf(_SC_OPEN_MAX); x >= 0; x--) {
        close(x);
    }

    
    open("/dev/null", O_RDWR);  
    dup(0);                     
    dup(0);                      
}

void run_script_at_time(const char *script_path, int hour, int minute) {
    time_t now;
    struct tm *current_time;

    while (1) {
        now = time(NULL);
        current_time = localtime(&now);

        if (current_time->tm_hour == hour && current_time->tm_min == minute) {
            
            if (system(script_path) == -1) {
                perror("Failed to execute script");
            }
            
            sleep(60);
        }

       
        sleep(30);
    }
}

int main() {
    const char *script_path = "/path/to/your/script.sh";  
    int hour = 16;  // Desired hour
    int minute = 55;  // Desired minute

    create_daemon();

    run_script_at_time(script_path, hour, minute);

    return 0;
}

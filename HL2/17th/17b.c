#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int f[2];
    pipe(f); 

    if (fork() == 0) { 
        dup2(f[1], STDOUT_FILENO); 
        close(f[0]); 
        close(f[1]); 
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(1);
    }

    if (fork() == 0) { 
        dup2(f[0], STDIN_FILENO); 
        close(f[1]); 
        execlp("wc", "wc", NULL);
        perror("execlp");
        exit(1);
    }

    close(f[0]); 
    close(f[1]);

    wait(NULL); 
    wait(NULL);
    
    return 0;
}

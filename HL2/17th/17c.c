#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) { // Create a pipe
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (fork() == 0) { 
        close(fd[0]); 
        dup(fd[1]); 
        close(fd[1]); 
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    if (fork() == 0) { 
        close(fd[1]); 
        dup(fd[0]); 
        close(fd[0]); 
        execlp("wc", "wc", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Parent process
    close(fd[0]); // Close both ends of the pipe in the parent
    close(fd[1]);

    // Wait for both child processes to finish
    wait(NULL); 
    wait(NULL);

    return 0;
}

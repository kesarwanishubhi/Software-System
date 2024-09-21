#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO_NAME "my_fifo"

int main() {
    char m[] = "Hi from the writer!";
    
    
    mkfifo(FIFO_NAME, 0666);

    
    int fd = open(FIFO_NAME, O_WRONLY);

    
    write(fd, m, sizeof(m));
    printf("Writer: Message sent: %s\n", m);

    
    close(fd);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO_NAME "my_fifo"

int main() {
    char buf[100];

    
    int fd = open(FIFO_NAME, O_RDONLY);

    
    read(fd, buf, sizeof(buf));
    printf("Reader: Got Message: %s\n", buf);

    
    close(fd);

    
    unlink(FIFO_NAME);

    return 0;
}

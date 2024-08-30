#include <stdio.h>    
#include <fcntl.h>    
#include <unistd.h>   
#include <errno.h>    
#include <string.h>   

int main() {
    const char *fname = "sample1.txt";
    
    int fd = creat(fname, 0666);

    if (fd < 0) {
        
        fprintf(stderr, "Error creating file: %s\n", strerror(errno));
        return 1;
    }

    
    printf("File descriptor: %d\n", fd);

    
    close(fd);

    return 0;
}
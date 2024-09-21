/*NAME -SHUBHI KESARWANI
QUESTION NAME-21b.c


OUTPUT---
Receiver: Message received:  hello
Receiver: Enter response: hi
Receiver: Response sent: hi*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO_SEND "fifo_send"
#define FIFO_RECEIVE "fifo_receive"

int main() {
    char msg[100];
    char response[100];

    
    int fd_r = open(FIFO_SEND, O_RDONLY);
    
    int fd_s= open(FIFO_RECEIVE, O_WRONLY);

   
    read(fd_r, msg, sizeof(msg));
    printf("Receiver: Message received: %s", msg);

    
    printf("Receiver: Enter response: ");
    fgets(response, sizeof(response), stdin);
    write(fd_s, response, sizeof(response));
    printf("Receiver: Response sent: %s", response);

    
    close(fd_r);
    close(fd_s);

    return 0;
}

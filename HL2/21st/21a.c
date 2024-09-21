/*NAME -SHUBHI KESARWANI
QUESTION NAME-21a.c


OUTPUT---
Sender: Enter message to send:  hello
Sender: Message sent:  hello
Sender: Response received: hi*/

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

    
    mkfifo(FIFO_SEND, 0666);
    mkfifo(FIFO_RECEIVE, 0666);

    
    int fd_s= open(FIFO_SEND, O_WRONLY);
    
    int fd_r= open(FIFO_RECEIVE, O_RDONLY);

    
    printf("Sender: Enter message to send: ");
    fgets(msg, sizeof(msg), stdin);
    write(fd_s, msg, sizeof(msg));
    printf("Sender: Message sent: %s", msg);

    
    read(fd_r, response, sizeof(response));
    printf("Sender: Response received: %s", response);

    
    close(fd_s);
    close(fd_r);

    
    unlink(FIFO_SEND);
    unlink(FIFO_RECEIVE);

    return 0;
}

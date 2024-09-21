#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main() {
    key_t key = ftok("somefile", 65); // Create a unique key
    int msqid = msgget(key, 0666 | IPC_CREAT); // Create a message queue

    if (msqid == -1) {
        perror("msgget");
        return 1;
    }

    printf("Message Queue ID: %d\n", msqid);
    return 0;
}

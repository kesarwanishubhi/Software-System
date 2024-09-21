#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MESSAGE_QUEUE_KEY 1234
#define MESSAGE_SIZE 256

struct message {
    long msg_type; // Message type
    char msg_text[MESSAGE_SIZE]; // Message content
};

int main() {
    int msgid;
    struct message msg;

    // Access the existing message queue
    msgid = msgget(MESSAGE_QUEUE_KEY, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Receive messages using IPC_NOWAIT
    while (1) {
        // Try to receive the message without blocking
        if (msgrcv(msgid, &msg, sizeof(msg.msg_text), 0, IPC_NOWAIT) == -1) {
            perror("msgrcv");
            printf("No messages available, exiting...\n");
            break; // Exit if no messages
        }
        
        // Print the received message
        printf("Received message: %s\n", msg.msg_text);
    }

    // Cleanup: Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
    }

    return 0;
}

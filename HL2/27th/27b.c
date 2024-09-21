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

    // Create a message queue
    msgid = msgget(MESSAGE_QUEUE_KEY, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Prepare the message
    msg.msg_type = 1; // Message type
    snprintf(msg.msg_text, MESSAGE_SIZE, "Hello from sender!");

    // Send the message
    if (msgsnd(msgid, &msg, sizeof(msg.msg_text), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Message sent: %s\n", msg.msg_text);
    return 0;
}

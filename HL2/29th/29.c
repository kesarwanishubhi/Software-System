
/*
==============================================================================================================================
Name : 29.c
SHUBHI KESARWANI


Sample output:
Message queue ID: 1
Message queue removed successfully.
==============================================================================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

void print_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    
    key_t key = ftok("progfile", 65); 
    if (key == -1) {
        print_error("ftok");
    }

    
    int msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        print_error("msgget");
    }

    
    printf("Message queue ID: %d\n", msqid);

   
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        print_error("msgctl IPC_RMID");
    }

    printf("Message queue removed successfully.\n");

    return 0;
}

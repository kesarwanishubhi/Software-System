/*
==================================================================================================
Name :25.c
Shubhi kesarwani

Sample output:
Access permissions: 666
Owner UID: 1000
Owner GID: 1000
Time of last message sent: Thu Jan  1 05:30:00 1970
Time of last message received: Thu Jan  1 05:30:00 1970
Time of last change in the message queue: Sat Sep 21 17:21:06 2024
Size of the queue: 0 bytes
Number of messages in the queue: 0
Maximum number of bytes allowed: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0
===================================================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void print_message_queue_info(int msqid) {
    struct msqid_ds msg_queue_info;

    
    if (msgctl(msqid, IPC_STAT, &msg_queue_info) == -1) {
        perror("msgctl IPC_STAT");
        return;
    }

    
    printf("Access permissions: %o\n", msg_queue_info.msg_perm.mode);
    printf("Owner UID: %u\n", msg_queue_info.msg_perm.uid);
    printf("Owner GID: %u\n", msg_queue_info.msg_perm.gid);

    
    printf("Time of last message sent: %s", ctime(&msg_queue_info.msg_stime));
    printf("Time of last message received: %s", ctime(&msg_queue_info.msg_rtime));
    printf("Time of last change in the message queue: %s", ctime(&msg_queue_info.msg_ctime));

    
    printf("Size of the queue: %zu bytes\n", msg_queue_info.__msg_cbytes);
    
    
    printf("Number of messages in the queue: %lu\n", msg_queue_info.msg_qnum);

    
    printf("Maximum number of bytes allowed: %lu\n", msg_queue_info.msg_qbytes);

    
    printf("PID of last msgsnd: %u\n", msg_queue_info.msg_lspid);
    printf("PID of last msgrcv: %u\n", msg_queue_info.msg_lrpid);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <msqid>\n", argv[0]);
        return 1;
    }

    int msqid = atoi(argv[1]);
    print_message_queue_info(msqid);

    return 0;
}

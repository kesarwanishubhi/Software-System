/*NAME -SHUBHI KESARWANI
QUESTION NAME-26.c


OUTPUT---
Enter the message type: 102
Enter the message text: hello there

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          shubhi     744        12           1           


*/

#include <sys/msg.h> 

#include <sys/ipc.h>

#include <sys/types.h>

#include <string.h>

#include <stdio.h>

int main () {

	int msgid, size;

	key_t key;

	struct msg {

		long int mtype; 
		char message [80];

	}mq;

	key = ftok("/home/dell/greptext.txt", 'a');
	
	msgid = msgget(key, 0);
	
	printf ("Enter the message type: "); 
	
	scanf("%ld", &mq.mtype);
	
	getchar();
	
	printf ("Enter the message text: "); 
	
	scanf("%[^\n]", mq.message); 
	
	size = strlen (mq.message);

	msgsnd (msgid, &mq, size+1, 0);
}
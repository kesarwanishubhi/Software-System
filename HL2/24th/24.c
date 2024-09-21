/*NAME -SHUBHI KESARWANI
QUESTION NAME-24.c


OUTPUT---
The key is = -1
The key is = 0xffffffff
The message queue id is = 0


*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main(){
	int key = ftok("/home/dell/greptext.txt", 'a');
	int q = msgget(key, IPC_CREAT|0744);

	printf("The key is = %d\n", key);
	printf("The key is = 0x%0x\n", key);
	printf("The message queue id is = %d\n", q);
	return 0;
}
/*
==================================================================================================
Name :19.c
Shubhi kesarwani

Sample output:
total 20
-rw-rw-r-- 1 tushar tushar  1587 Sep 20 23:51 19.c
-rwxrwxr-x 1 tushar tushar 16088 Sep 20 23:51 19.out
p--------- 1 tushar tushar     0 Sep 20 23:51 myfifofile1
prwx------ 1 tushar tushar     0 Sep 20 23:51 myfifofile
prw-rw-r-- 1 tushar tushar     0 Sep 20 23:55 fifo1
prw-rw-r-- 1 tushar tushar     0 Sep 20 23:55 p
prw-rw-r-- 1 tushar tushar     0 Sep 20 23:55 fifo2
tushar@tushar:~/Desktop/Software System/HL2/19th$ 
#mknod fifo1 p


FIFO file created successfully using library call
FIFO file created successfully using mknod system call
$ ls -l
total 20
-rw-rw-r-- 1 shubhi shubhi  1587 Sep 20 23:51 19.c
-rwxrwxr-x 1 shubhi shubhi 16088 Sep 20 23:51 19.out
p--------- 1 shubhi shubhi     0 Sep 20 23:51 myfifofile1
prwx------ 1 shubhi shubhi     0 Sep 20 23:51 myfifofile

===================================================================================================
*/

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	//Create a FIFO file using mkfifo library call
	if(mkfifo("myfifofile", S_IFIFO|S_IRWXU) == -1){
		perror("mkfifo");
	}
	else {
		printf("FIFO file created successfully using library call\n");
	}
	//Create a FIFO file using mknod system call
	if(mknod("myfifofile1", S_IFIFO, 0) == -1){
		perror("Failed to create named pipe");
	}
	else {
		printf("FIFO file created successfully using mknod system call\n");
	}
	return 0;
}
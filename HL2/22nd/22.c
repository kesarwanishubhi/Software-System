/*NAME -SHUBHI KESARWANI
QUESTION NAME-22.c


OUTPUT---
Data is available now....
The text from FIFO: hi
*/



#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>

int main () {

	int fd, retval;

	char buf[80];

	fd_set rfds;

	struct timeval tv;

	fd = open("myfifo", O_RDONLY);

	FD_ZERO(&rfds);

	FD_SET(fd, &rfds);

	tv.tv_sec=10;

	tv.tv_usec=0;

	retval=select (fd+1, &rfds, NULL, NULL, &tv); 
	if (retval){
		printf("Data is available now....\n");
	}
	else {

		printf ("No Data is available within 10 seconds...\n");
		exit(0);
	}
	read (fd, buf, sizeof (buf)); 
	printf("The text from FIFO: %s\n", buf); 
}
/*NAME -SHUBHI KESARWANI
QUESTION NAME-23.c


OUTPUT---
Pipe_buf = 4096
Open max = 1024

*/
#include <stdio.h> 
#include <unistd.h>

int main () {

	long PIPE_BUF, OPEN_MAX;

	PIPE_BUF = pathconf(".", _PC_PIPE_BUF);

	OPEN_MAX= sysconf(_SC_OPEN_MAX);

	printf ("Pipe_buf = %ld\nOpen max = %ld\n", PIPE_BUF, OPEN_MAX);
}
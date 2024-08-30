
/*
======================================================================================================================================================================
Name : 15.c
Author :SHUBHI KESARWANI
Description : Write a program to display the environmental variable of the user (use environ).

======================================================================================================================================================================
======================================================================================================================================================================
Sample Output:
======================================================================================================================================================================

*/

#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main() {
    char **en;

    
    if (environ == NULL) {
        printf("No environment variables found.\n");
        return 1;
    }

    for (en = environ; *en != 0; en++) {
        printf("%s\n", *en);
    }

    return 0;
}

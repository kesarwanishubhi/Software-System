/*
======================================================================================================================================================================
Name : 26.c
Author :SHUBHI KESARWANI
Description :Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)

======================================================================================================================================================================
======================================================================================================================================================================
Sample Output:
Executing my_program with argument: PRIYANSH
Hello, PRIYANSH!

======================================================================================================================================================================

*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    
    char *name = "PRIYANSH";

    
    printf("Executing my_program with argument: %s\n", name);

    
    execl("./prog26.out", "prog26", name, (char *)NULL);

    
    perror("execl failed");
    return 1;
}

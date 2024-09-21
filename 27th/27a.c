/*
======================================================================================================================================================================
Name : 27a.c
Author : SHUBHI KESARWANI
Description : Write a program to execute ls -Rl by the following system calls
		a. execl
		b. execlp
		c. execle
		d. execv
		e. execvp 

======================================================================================================================================================================
======================================================================================================================================================================
Sample Output:
$ ./execl

Executing ls -Rl using execl command:
/home/dell/Downloads:
total 225520
-rw-rw-r-- 1 dell dell     3643 Aug  4 11:52  03AugShellPrograms.tar.gz
-rw-rw-r-- 1 dell dell     1940 Sep  8 09:50  29.c
-rw-rw-r-- 1 dell dell 96126384 Jul 14 10:34  code_1.80.1-1689183569_amd64.deb
-rw-rw-r-- 1 dell dell     2829 Aug  4 11:53  employee_management.sh
-rw-rw-r-- 1 dell dell      119 Aug  4 11:53  employee_records.txt
-rw-rw-r-- 1 dell dell 94355016 Jun 26 21:41  google-chrome-stable_current_amd64.deb
-rw-rw-r-- 1 dell dell    15015 Sep 10 11:39 'Header and footer.txt'
-rw-rw-r-- 1 dell dell    58445 Jul 11 22:33 'Java - Getting Started.pdf'
-rw-rw-r-- 1 dell dell   281733 Dec 12  2021  K177B31ApplicationForm.pdf
-rw-rw-r-- 1 dell dell  2927970 Aug 10 19:49  Lect0.pptx
-rw-rw-r-- 1 dell dell  7104026 Jul 14 19:29 'Linux Fundamentals.pdf'
-rw-rw-r-- 1 dell dell  2933135 Sep  7 13:45 'MML Assignment1.pdf'
-rw-rw-r-- 1 dell dell   120872 Jul 18 13:08  MT2023083.pdf
drwxrwxr-x 2 dell dell     4096 Sep  9 10:56 'Slides Folder-20230810'
-rw-rw-r-- 1 dell dell 26963922 Aug 10 18:18 'Slides Folder-20230810.zip'

======================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // a. Using execl
    printf("Executing ls -Rl using execl:\n");
    execl("/bin/ls", "ls", "-Rl", (char *)NULL);
    
    // If execl fails, it will return -1
    perror("execl failed");
    exit(EXIT_FAILURE);
    
    // b. Using execlp
    // Note: This part will not be reached due to execl replacing the process image
    printf("Executing ls -Rl using execlp:\n");
    execlp("ls", "ls", "-Rl", (char *)NULL);
    
    // If execlp fails, it will return -1
    perror("execlp failed");
    exit(EXIT_FAILURE);
    
    // c. Using execle
    // Note: This part will not be reached due to execlp replacing the process image
    char *envp[] = {NULL}; // Passing an empty environment for demonstration
    printf("Executing ls -Rl using execle:\n");
    execle("/Desktop/Software System", "ls", "-Rl", (char *)NULL, envp);
    
    // If execle fails, it will return -1
    perror("execle failed");
    exit(EXIT_FAILURE);
    
    // d. Using execv
    // Note: This part will not be reached due to execle replacing the process image
    char *argv[] = { "ls", "-Rl", NULL };
    printf("Executing ls -Rl using execv:\n");
    execv("/Desktop/Software System", argv);
    
    // If execv fails, it will return -1
    perror("execv failed");
    exit(EXIT_FAILURE);
    
    // e. Using execvp
    // Note: This part will not be reached due to execv replacing the process image
    printf("Executing ls -Rl using execvp:\n");
    execvp("ls", argv);
    
    // If execvp fails, it will return -1
    perror("execvp failed");
    exit(EXIT_FAILURE);
}

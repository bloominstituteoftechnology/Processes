// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here 

    int x = 100;

    printf("hello world (pid: %d)\n", (int) getpid());

    // -------------------------------CHILD PROCESS START

    int rc = fork();
    if (rc < 0) { // fork failed. EXIT PROGRAM
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // FORK PASSED CHILD PROCESS SATISFIES THIS BRANCH
        x = 200;
    }

    return 0;
}

/* 
Returning Error 2/6/2018 on compile

ex1.c: In function 'main':
ex1.c:17:14: warning: implicit declaration of function 'fork' [-Wimplicit-function-declaration]
     int rc = fork();
              ^~~~
C:\Users\pwong\AppData\Local\Temp\ccsiKR90.o:ex1.c:(.text+0x17): undefined reference to `fork'
collect2.exe: error: ld returned 1 exit status


*/

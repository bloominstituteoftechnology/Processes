// Write a program that calls `fork()`. Before calling `fork()`, 
//have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). 
//What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

// https://www.youtube.com/watch?v=xVSPv-9x3gk  3m overview of how fork and wait works

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;

    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        x = 110;
        printf("hello, child here (pid: %d), x is %d \n", (int) getpid(), x);
    } else {
        int wc = waitpid(rc, NULL, 0);    // `waitpid` call added here
        x = 25;
        printf("hello, parent here (pid: %d) of child %d, x is %d\n", (int) getpid(), rc, x);
    }

    return 0;
}

//pats-MBP-2:ex1 padjo$ gcc ex1.c -o output && ./output
//hello, child here (pid: 23472), x is 110 
//hello, parent here (pid: 23471) of child 23472, x is 25

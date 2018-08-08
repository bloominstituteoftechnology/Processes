// Write a program that calls `fork()`. Before calling `fork()`, 
//have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the 
//variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // Your code here
    // printf("hello world (pid: %d)\n", getpid());
    // int rc = fork();
    // // ------------------------------------------------ child process starts executing here
    // if (rc < 0) {    // fork failed; exit
    //     fprintf(stderr, "fork failed\n");
    //     exit(1);
    // } else if (rc == 0) {    // child process satisfies this branch
    //     printf("hello, child here (pid: %d) \n", getpid());
    // } else {
    //     printf("hello, parent here (pid: %d) of child %d\n", getpid(), rc);
    // }
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x = 13;
        printf("Child: %d\n",x);
    } else {
        int wc = waitpid(rc, NULL, 0);
        x = 19;
        printf("Parent: %d\n", x);
    }

    return 0;
}

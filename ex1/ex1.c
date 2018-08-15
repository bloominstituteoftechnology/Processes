// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?


#include <stdio.h>  //installing the necessary libraries
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid()); // run hello world and pid
    int rc = fork();    // fork funnction
    
    if (rc < 0) {   // handling error during fork()
        fprintf(stderr, "fork failed\n");   // error message
        exit(1);    // exit
    } else if (rc == 0) {   // if child is == 0, run this
        printf("hello, child here(pid: %d) \n", (int)
        getpid());
    } else {    // run this for parent
        printf("hello, parent here (pid: %d) of child %d\n",
        (int) getpid(), rc);
    }

    return 0;
}
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
    int cp = fork();
    // ----------------------------------------------- child process starts here
    if (cp < 0) { // fork failed, exit
        fprintf(stderr, "fork faild\n");
        exit(1);
    } else if (cp == 0) { // child process successfully created
      printf("hello, child process (pid: %d)\n", (int) getpid());
    } else {
        printf("hello, parent process (pid: %d)\n", (int) getpid());
    }

    return 0;
}

// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char* x = "hey you";

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("this is the child process with pid: %d \n", getpid());
        x = "I got assigned by the child\n";
    } else {
        printf("this is the parent process with pid %d.  Child pid is %d \n", getpid(), rc);
        x = "I got assigned by the parent\n";
    }

    puts(x);

    return 0;
}

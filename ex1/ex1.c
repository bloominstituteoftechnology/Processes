// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? 
// Value will remain 100.
// What happens to the variable when both the child and parent change the value of x? 
// They both take on their new respective values but they are not passed onto each other. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // parent process
    // int parentProcess = getpid();
    int x = 100;
    printf("Parent pid: %d\n", (int) getpid());

    // child process
    int childProcess = fork();
    if (childProcess < 0) {
        fprintf(stderr, "fork failed!\n");
        exit(1);
    } else if (childProcess == 0) {
        printf("Child pid:%d variable value: %d\n", (int) getpid(),x);
        x = 200;
        printf("Child new value %d\n", x);
    } else {
        printf("Parent of child with pid %d variable value: %d\n", childProcess, x);
        x = 300;
        printf("Parent new value %d\n", x);
    }

    return 0;
}

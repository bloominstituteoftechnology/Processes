// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int x = 100;

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Fork Failed\n"); 
        exit(1);
    } else if (rc == 0) {
        printf("Child (pid: %d), x = %d \n", (int) getpid(), x);
        x = 48;
        printf("Child (pid: %d), x = %d \n", (int) getpid(), x);
    } else {
        printf("Parent(pid: %d) of child %d, x = %d\n", (int) getpid(), rc, x);
        x = 37;
        printf("Parent(pid: %d) of child %d, x = %d\n", (int) getpid(), rc, x);
    }

    return 0;
}

// Parent(pid: 78) of child 79, x = 100
// Child (pid: 79), x = 100
// Parent(pid: 78) of child 79, x = 37
// Child (pid: 79), x = 48
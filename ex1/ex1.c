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
    printf("here is the value of the variable I initialized: %d\n", x);
    // child process starts executing here
    int rc = fork();
    if (rc < 0) {
    	printf("fork failed\n");
    	exit(1);
    } else if (rc == 0) {
    	printf("child with pid: %d\n", (int) getpid());
    } else {
    	printf("parent with pid: %d of child with pid: %d\n", (int) getpid(), rc);
    }

    return 0;
}

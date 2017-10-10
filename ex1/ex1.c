// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x;
    printf("Hello from Main (pid: %d)\n", (int) getpid());
    printf("Main says: x = %d \n", x);

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        x -= 50;
        printf("Hello from Child (pid: %d)\n", (int) getpid());
        printf("Child says: x = %d \n", x);
    } else {
        x += 25;
        printf("Hello from Parent (pid: %d)\n", (int) getpid());
        printf("Parent Process says: x = %d \n", x);
    }
    printf("Final check says: x = %d \n", x);
    return 0;
}

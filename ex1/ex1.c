// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
        int test = 0;
        test = 100;
        printf("Test: %d (pid: %d)\n\n", test, (int) getpid());

        int rc = fork();
        if (rc == 0) {
          printf("Child: %d (pid: %d)\n", test, (int) getpid());
          test = 111;
          printf("New Child: %d (pid: %d)\n\n", test, (int) getpid());
        } else {
          printf("Parent: %d (pid: %d)\n", test, (int) getpid());
          test = 222;
          printf("New Parent: %d (pid: %d)\n\n", test, (int) getpid());
        }

        printf("New test: %d (pid: %d)\n\n",test, (int) getpid());

    return 0;
}

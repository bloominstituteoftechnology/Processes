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
    printf("1. x = %d, main pid: %d\n", x, (int)getpid());
    x = 0;
    int fk = fork();
    printf("2. x = %d, after fork() pid: %d\n", x, (int)getpid());
    x = 1;
    printf("2. x = %d, after fork() reset x pid: %d\n", x, (int)getpid());
    if (fk < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (fk == 0)
    {
        printf("3. x = %d, child pid: %d\n", x, (int)getpid());
        x = 98;
        printf("4. x = %d, child pid: %d\n", x, (int)getpid());
    }
    else
    {
        printf("5. x = %d, parent pid: %d\n", x, (int)getpid());
        x = 101;
        printf("6. x = %d, parent pid: %d\n", x, (int)getpid());
    }
    printf("7. x = %d, main pid: %d\n", x, (int)getpid());
    return 0;
}

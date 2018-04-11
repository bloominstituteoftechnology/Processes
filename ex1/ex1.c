// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("Initial value: x = %d, pid = %d\n", x, (int)getpid());

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "Nobody here but us chickens...\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("A child is born! pid= %d\n from x (%d)\n", (int) getpid(), x);
        x++;
    }
    else
    {
        printf("Parent here; pid = %d\n of x (%d)\n" , (int) getpid(), x);
        x--;
        printf("Still the parent here. x is now %d\n", x);
    }
    return 0;
}

// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("BEFORE FORK (pid: %d) \n", (int)getpid());
    int x = 10;
    int *xp = &x;

    int f = fork();
    if (f < 0)
    {
        printf("%s\n", "Fork faliled");
        exit(1);
    }
    else if (f == 0)
    {
        // we are in the child branch
        printf("Greetings from child (pid: %d)\n", f);
        printf("Childs x: %i\n", x);
        printf("Childs pointer to x: %p\n", xp);
        printf("Childs pointer to x value: %i\n", *xp);
        x = x + 5;
        printf("%s\n", "Child adding 5 to x");
        printf("Childs x: %i\n", x);
        printf("Childs pointer to x: %p\n", xp);
        printf("Childs pointer to x value: %i\n", *xp);
    }
    else
    {
        // we are in the parent branch
        printf("Greetings from parent (pid: %d)\n", f);
        printf("Parents x: %i\n", x);
        printf("Parents pointer to x: %p\n", xp);
        printf("Parents pointer to x value: %i\n", *xp);
        x = x + 5;
        printf("%s\n", "Parent adding 5 to x");
        printf("Parents x: %i\n", x);
        printf("Parents pointer to x: %p\n", xp);
        printf("Parents pointer to x value: %i\n", *xp);
    }

    return 0;
}

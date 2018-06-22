// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void)
{
    int i = rand() % 100 + 1;
    printf("I am process id (pid): %d, and i is %d\n\n", (int)getpid(), i);

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "sorry, fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("I am child process (pid: %d) and i is: %d\n\n", (int)getpid(), i);
        i++;
        printf("child again, i is now: %d\n\n", i);
    }
    else
    {
        printf("hello, I am parent of %d (pid: %d) and i is: %d\n\n", rc, (int)getpid(), i);
        i--;
        printf("parent again, i is now: %d\n\n", i);
    }

    return 0;
}

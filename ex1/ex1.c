/*Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
(e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change the value of x?
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;
    x += 100;
    printf("%d (pid: %d)\n", x, (int) getpid());
    int rc = fork();
    x += 100;
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
    }
    else if (rc == 0)
    {
        printf("%d, child here (pid: %d)\n", x, (int) getpid());
    }
    else
    {
        printf("%d, parent here (pid: %d) of child %d\n", x, (int) getpid(), rc);
    }
    return 0;
}

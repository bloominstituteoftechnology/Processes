// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        printf("CHILD: the value of X in the child process is %d and the pid: %d) \n", x, (int)getpid());
        x++;
        printf("The incremented value of X in the child is %d\n", x);
    }
    else
    {
        int wc = waitpid(rc, NULL, 0);
        printf("PARENT:  The value of X is %d and the PID is (pid: %d)\n", x, (int)getpid());
    } // Your code here

    return 0;
}

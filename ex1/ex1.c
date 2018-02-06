// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    // Your code here
    int x = 100;
    int *p = &x;

    printf("here is the output \n");
    printf("Before fork is called : ( pid: %d)\n", (int)getpid());

    int rc = fork();
    // int rc = spawn();

    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    /*
    The parent process receives the PID of the child process it just spawned, 
    while the child process receives 0 if the fork() call was successful.
    */
    else if (rc == 0)
    { // child process satisfies this branch
        *p /= 5;
        printf("Child here x: %d address of x : %p (pid: %d) \n", *p, x, (int)getpid());
    }
    else
    { //parent processing
        // int wc = 0;
        *p += 55;
        printf("parent here x: %d address of x : %p (pid: %d) of child %d\n", *p, x, (int)getpid(), rc);
    }

    return 0;
}

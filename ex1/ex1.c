// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Hello world (pid: %d)\n", (int)getpid());

    int x = 100;
    int rc = fork();

    if (rc < 0)
    {
    	fprintf(stderr, "fork failed!\n");
    	exit(1);
    }
    else if (rc == 0)
    {
    	printf("Hello child here (pid: %d). Variable x = %d\n", (int)getpid(), x);
    	x = 90;
    	printf("X new value is: %d\n", x);
    }
    else
    {
    	printf("Hello, parent here (pid: %d) of child %d. Variable x = %d\n", (int)getpid(), rc, x);
    	x = 80;
    	printf("X new value is: %d\n", x);
    }

    return 0;
}

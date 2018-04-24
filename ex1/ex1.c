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
    //clone parent process to a child process
	int rc = fork();

	 if (rc < 0) {    // fork failed; exit
        //if fork() return negative number
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        //in child process
    	x = 200;
        printf("hello, child here (pid: %d) \n", (int) getpid());
        printf("'x' in child program is: %d\n", x);
    } else {
        //in parent process
    	x = 300;
        printf("hello, parent here (pid: %d) of child %d\n", (int) getpid(), rc);
        printf("'x' in parent program is: %d\n", x);
    }

    return 0;
}

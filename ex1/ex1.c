// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 100;
    int rc = fork();
    // if fork fails return value is -1
    if(rc < 0){
        // 'fprintf' is like 'printf' except you add (where, how, what)
        fprintf(stderr, "failing forks\n");
        exit(1);
    } else if (rc == 0) {
        // successful child fork will return a 0, so this would select the child process
        printf("This is a child pid: %d\n", (int) getpid());
    } else {
        printf("This is the parent pid: %d parent to child pid: %d\n", (int) getpid(), rc);
    }
    // printf("%d", x);
    return 0;
}

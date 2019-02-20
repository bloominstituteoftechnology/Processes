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
    int pid = fork();

    if(pid == 0) {
        printf("Hello, I'm a child process!\n");
    }
    else {
        printf("Hello, I'm a parent process!\n");
    }
    printf("%d %d", 100, x);

    return 0;
}

/* After initialization, the variable in the child process would be the same as its value in the parent process. When the parent and child change the value of x, we can access both values of x within their respective forks.
If we were to do something like (x * 2) in the parent fork and (x / 2) in the child fork, we could work with both 200 and 50. */

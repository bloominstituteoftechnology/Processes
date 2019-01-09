// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// > also 100 (i.e. in both processes)
// What happens to the variable when both the child and parent change the value of x?
// > both forks change the value the same way (in this case to 20)

// it also looks like they do run the processes one after another (or at least that's how it's displayed)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x;

    x = 100;

    fork();

    printf("value of x: %d for fork pid: %d\n", x, (int) getpid());

    x = 20;

    printf("value of x after change: %d for fork pid: %d\n", x, (int) getpid());

    return 0;
}

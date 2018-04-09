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
    int child = fork();
     if ( child < 0) {
       printf("Can't fork a child\n");
       exit(1);
     } else if (child == 0) {
       x = 111;
       printf("child print: %d\n", x);
     } else {
       int wait = waitpid(child, NULL, 0);
       printf("Parent value: %d\n", x);
     }

    return 0;
}

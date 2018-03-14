// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Your code here
    // Quick x variable to tinker with
    int x = 100; 

    printf("Parent: x = %d\t\tpid: %d\n\n", x, (int) getpid());

    pid_t rc = fork();
    if (rc == 0) {
        // W're the child
        x = 200;
        printf("Child:  x = %d\t\tpid: %d\n\n", x, (int) getpid());
    } else {
        sleep(1);
        printf("Child:  x = %d\t\tpid: %d\n\n", x, (int) getpid());
    }

    fclose(fp);
    
    return 0;
}

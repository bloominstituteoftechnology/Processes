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
    printf("The value of x in the parent process is %d and its pid is %d.\n", x, (int) getpid()); 
    int rc = fork(); 
    // Child process starts executing here
    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "Fork Failed!\n"); 
        exit(1); 
    }
    else if (rc == 0) { // Child process satisfies this branch 
    printf("\nThe value of x in the child process before its changed is %d and its pid is %d.\n", x, (int) getpid()); 
    x = 25; 
    printf("The value of x in the child process after its changed is %d and its pid is %d.\n", x, (int) getpid()); 
    }
    else {
        printf("The value of x after the child process executes is %d. The parent pid is %d and the child pid is %d.\n", x, (int) getpid(), rc); 
    }
    return 0;
}

// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). 

// Q.What value is the variable in the child process?
// A.It gets the value from its parent.
// Q.What happens to the variable when both the child and parent change the value of x?
// A.They now each have a separate context within which they can manipulate the variable without
// affecting the value in the other context. Essentially, there are different 'x's for each process, although they start with the same value.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    printf("I haven't had children yet - I'm waiting until life stops being fun. X : %i\n", x);
    int responseFromFork = fork();
    if (responseFromFork < 0) {
        fprintf(stderr, "You forked up!\n");
        exit(1);
    } else if (responseFromFork != 0) {
        x = 42;
        printf("Was I dreaming just now, or did I have a kid? X : %i\n", x);
    } else {
       printf("hello, my sweet chile. X : %i\n", x);
    }
    return 0;
}

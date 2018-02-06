// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    FILE * fp;
    int x = 77;
   fp = fopen ("text.txt", "w+");

   int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {    // child process satisfies this branch
        fprintf(fp, "hello, child here (pid: %d), my value of x is: %d\n", (int) getpid(), x);
        x++;
        fprintf(fp, "child again, x is now: %d\n", x);
    }
    else {
        fprintf(fp, "hello, parent here (pid: %d) of child %d and my value of x is: %d\n", (int) getpid(), rc, x);
        x--;
        fprintf(fp, "parent again, x is now: %d\n", x);
    }

    return 0;
}

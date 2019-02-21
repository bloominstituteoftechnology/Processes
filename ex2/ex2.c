// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *file;
    file = fopen("text.txt", "r+");
    int fp = fork();
    if (fp < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (fp == 0)
    { // child process satisfies this branch
        //fprintf(file, "%s");
        fprintf(file, "Hello from child: %d\n", (int)getpid());
    }
    else
    {
        fprintf(file, "Hello from parent: %d\n", (int)getpid());
    }

     fclose(file);
    
    return 0;
}

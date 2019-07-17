// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Answer: Yes they can both access the file descriptor. The file is written to 3 times. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    
    fp = fopen ("text.txt", "r+");

    fprintf(fp, "%s  %d\n", "We are in", getpid());

    int new_process = fork();

    if (new_process)
    {
        fprintf(fp, "%s  %d\n", "We are in", getpid());
    }

    fclose(fp);
    
    return 0;
}

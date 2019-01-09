// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *p = fopen("text.txt", "r+");
    int rc = fork();

    if(rc==0)
    {
        fprintf(p, "Child writes.\n");
    }
    else
    {
        fprintf(p, "Parent writes.\n");
    }
    fclose(p);
    
    return 0;
}

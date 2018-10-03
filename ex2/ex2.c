// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently? Both the child and parent can access the file descriptor returned by `fopen()`. The file is written in the order of the process.

#include <stdio.h> // installing the necessary header files
#include <unistd.h>
#include <stdlib.h>
#include <string.h> // for calling strlen

int main(void)
{
    // Your code here 
    FILE *fp;
    fp = fopen("text.txt", "w");
    
    printf("Parent, pid: %d\n", getpid());
    int rv = fork();

    if(rv < 0)
    {
        printf(stderr, "fork failed\n");
        exit(1);
    }
    else if(rv == 0)
    {
        printf("Child, pid: %d\n", getpid());
        fprintf(fp, "%s: %d\n", "Child", getpid());
    }
    else 
    {
        int wc = waitpid(rv, NULL, 0);
        printf("Parent, pid: %d\n", getpid());
        fprintf(fp, "%s: %d\n", "Parent", getpid());
    }

    fclose(fp);
    
    return 0;
}

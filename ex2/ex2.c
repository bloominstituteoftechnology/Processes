// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently? Yes, they both have access. The file is then written in the order of the process.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("text.txt", "w+");
    printf("Parent, pid: %d\n", getpid());
    int rv = fork();

    if(rv < 0)
    {
        fprintf(stderr, "fork failed\n");
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

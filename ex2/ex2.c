// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Your code here
    FILE *fp;

    fp = fopen("text.txt", "r+");
    // fprintf(fp, "%s %s %s %d", "Lambda School", "cohort", "cs8", 2018);
    int fileno(FILE * stream);

    int rc = fork();

    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch

        printf("hello, child here. my rc is %d. My pid is %d  My fd is %d \n", rc, getpid(), fileno);
        fprintf(fp, "%s  %d", "Child", 1234);
    }
    else
    {

        printf("hello, parent here my rc is %d. My pid is %d  My fd is %d \n", rc, getpid(), fileno);
        fprintf(fp, "%s  %d", "Parent", 5678);
    }

    fclose(fp);

    return 0;
}

// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE * fp;
    fp = fopen("./ex2/text.txt", "w");
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        fprintf(fp, "child pid: %d\n", (int) getpid());
    } else {
        fprintf(fp, "parent pid: %d, child pid: %d\n", (int) getpid(), rc);
    }
    fclose(fp);
    return 0;
}

// Both the parent and child can access the file. They both write to it, without erasing what the other wrote.

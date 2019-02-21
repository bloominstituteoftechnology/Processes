// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("text.txt", "r+");

    fprintf(file, "pre-fork text\n");

    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("post-fork: child pid %d\n", (int)getpid());
        fprintf(file, "child text\n");
    }
    else
    {
        printf("post-fork: parent pid %d of child %d\n", (int)getpid(), rc);
        fprintf(file, "parent text\n");
    }

    return 0;
}

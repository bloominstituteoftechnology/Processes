// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char ERROR_FORK[] = "System failed to execute fork()!";

int main(int argc, char *argv[])
{
    // Your code here
    FILE *fp;

    fp = fopen("text", "a+");
    int fx = fork();

    if (fx < 0)
    {
        printf("%s", ERROR_FORK)
    }
    else if (fx == 0)
    {
        fprintf(fp, "This line was written from a child process\n");
    }
    else
    {
        fprintf(fp, "This line was written from a parent process\n");
    }

    return 0;
}

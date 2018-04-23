// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen("text.txt", "w");
    int child = fork();

    if (child < 0)
    {
        perror("Fork Failed\n");
        exit(1);
    }
    else if (child == 0)
    {
        fprintf(fp, "%s", "I am the child writing!\n");
    }
    else
    {
        fprintf(fp, "%s", "I am the parent writing!\n");
    }

    fclose(fp);

    return 0;
}
// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int c;
    FILE *fp_read;
    FILE *fp_write;
    fp_read = fopen("text.txt", "r");
    fp_write = fopen("text.txt", "w");
    int child = fork();

    if (child < 0)
    {
        perror("Fork Failed\n");
        exit(1);
    }
    else if (child == 0)
    {
        fprintf(fp_write, "%s", "I am the child writing!\n");
    }
    else
    {
        fprintf(fp_write, "%s", "I am the parent writing!\n");
    }

    if (fp_read)
    {
        while ((c = getc(fp_read)) != EOF) putchar(c);
        fclose(fp_read);
    }

    return 0;
}
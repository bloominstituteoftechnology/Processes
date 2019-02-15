// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE * fp;
    fp = fopen ("text.txt", "w+");

    int f = fork();

    if (f > 0)
    {
        fprintf(fp, "Parent goes first! :D\n");
    }
    else if (f == 0)
    {
        fprintf(fp, "Child goes after parent :(\n");
    }
    else
    {
        fprintf(stderr, "Fork Failed!\n");
        exit(1);
    }

    fclose(fp);

    return 0;
}

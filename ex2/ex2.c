// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("text.txt", "r+");
    int f = fork();
    if (f < 0)
    {
        printf("%s\n", "Fork faliled");
        exit(1);
    }
    else if (f == 0)
    {
        // we are in the child branch
        fprintf(fp, "Greetings from child: %d\n", (int)getpid());
    }
    else
    {
        // we are in the parent branch
        fprintf(fp, "Greetings from parent: %d\n", (int)getpid());
    }
    fclose(fp);

    return 0;
}

// Answer yes they were both able to write
// The parent wrote first the the child

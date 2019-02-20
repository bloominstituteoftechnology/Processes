// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;

    fp = fopen("text.txt", "w+");

    fprintf(fp, "%s %s", "Hello", "World");
    fclose(fp);

    int rc = fork();
    if (rc == 0)
    {
        printf("I am the child, pid: %d\n", (int)getpid());
    }
    else
    {
        printf("I am the parent, pid: %d, pid of child: %d\n", (int)getpid(), rc);
    }
    return 0;
}

// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

/* both child and preant can access the file descriptor returned by 'fopen()'
When written concurrently, parent gets iterated first, then the child. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen("text.txt", "a"); // option of appending 'text.txt' iterated
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "forkfailed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        int x = 100;
        fprintf(fp, "%s %d \n", "I'm a child", 456);
    }
    else
    {
        int x = 200;
        fprintf(fp, "%s %d \n", "I'm a parent", 123);
    }
    fclose(fp);

    return 0;
}

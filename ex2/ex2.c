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

    fp = fopen("text.txt", "wrb");

    int fk = fork();

    if (fp != NULL)
    {
        if (fk < 0)
        {
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if (fk == 0)
        {
            char *x = "CHILD\n";
            printf("1. Child pid: %d, file descriptor: %d\n", (int)getpid(), (int)fp);
            fwrite(x, sizeof(char), sizeof(x) / sizeof(char), fp);
        }
        else
        {
            char *y = "PARENT\n";
            printf("2. Parent pid: %d, file descriptor: %d\n", (int)getpid(), (int)fp);
            fwrite(y, sizeof(char), sizeof(y) / sizeof(char), fp);
        }
        fclose(fp);
    }
    else
    {
        fprintf(stderr, "open file failed");
        exit(1);
    }
    return 0;
}

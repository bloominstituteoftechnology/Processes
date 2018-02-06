// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *tx;
    tx = fopen("text.txt", "w");

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("This is child process\n");
        char str1[] = "child String";
        fwrite(str1, 1, sizeof(str1), tx);
    }
    else
    {
        printf("This is parent process\n");
        char str2[] = "parent String\n";
        fwrite(str2, 1, sizeof(str2), tx);
    }

    fclose(tx);

        return 0;
}

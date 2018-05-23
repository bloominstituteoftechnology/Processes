// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Parent and child can both access the file. When writing concurrently, both can append the file.
// Parent writes first, unless I add a 80K for loop to slow down the parent.
// Even closing the file in the process that completes first does not shut out the other process.
// File needs to be closed in each process (or it will auto close on program completion.)

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Your code here
    FILE *fp;
    int rc = fork();

    fp = fopen("text.txt", "a");

    if (rc < 0)
        printf("forking failed");
    if (rc == 0)
    {
        fprintf(fp, "%s %s %s %s %d\n", "We", "are", "in", "child", (int)getpid());
        fclose(fp);
    }
    else if (rc > 0)
    {
        int x = 200000;
        int arr[x];
        for (int i = 1; i <= x; i++)
        {
            // printf("%d\n", i);
            arr[i] = i;
        }
        fprintf(fp, "%s %s %s %s %d\n", "We", "are", "in", "parent", (int)getpid());
    }

    return 0;
}

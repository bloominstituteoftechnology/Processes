// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    pid_t pid;
    pid = fork();
    FILE *fp;
    fp = fopen("text.txt", "w");
    // ------------------------------------------------ child process starts executing here
    if (pid < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (pid == 0)
    { // child process satisfies this branch
        fprintf(fp, "work\n");
    }
    else
    {

        fprintf(fp, "working\n");
    }
    fclose(fp);
    return 0;
}
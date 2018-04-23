// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    FILE *fp = fopen("text.txt", "w+");
    int child = fork();
    if (child < 0) {
        perror("fork failed\n");
        exit(1);
    }
    else if (child == 0) {
        fprintf(fp, "This was written by the child process\n");
    }
    else {
        fprintf(fp, "This was written by the parent process\n");
    }
    fclose(fp);
    return 0;
}

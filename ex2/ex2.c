// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    FILE *fp;
    int rc;

    fp = fopen("text.txt", "a+");
    rc = fork();
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    if (rc < 0) { // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        fprintf(fp, "child\n");
    } else {
        fprintf(fp, "parent\n");
    }
    fclose(fp);

    return 0;
}

// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    FILE * fp;
    fp = fopen("text.txt", "w");
    int rc = fork();

    if (rc == 0){
        fprintf(fp, "%s", "This is the Child\n");
    } else {
        fprintf(fp, "%s", "This is the Parent\n");
    }

    fclose(fp);
    return 0;
}

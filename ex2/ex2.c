// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
   
    FILE* fp;
    
    fp = fopen("text.txt", "w");

    if (fp == NULL) {
        fprintf(stderr, "sometihng went wrong with opening file\n");
    } else {
        int rc = fork();

        if (rc < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (rc == 0) {
            printf("this is the child process with pid: %d \n", getpid());
            fprintf(fp, "this is written from the child process!\n");
        } else {
            printf("this is the parent process with pid %d.  Child pid is %d \n", getpid(), rc);
            fprintf(fp, "this is written from the parent process!\n");
        }
    }

    fclose(fp);

    return 0;
}

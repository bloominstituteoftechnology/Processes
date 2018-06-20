// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *pug = fopen("text.txt", "r+");

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed, exiting\n");
        exit(1);
    } else if (rc == 0) {
        printf("child process (pid: %d) writing %d\n");
    } else {
        fprintf(pug, "parent process (pid: %d) writing %d\n");
    }
    return 0;
}

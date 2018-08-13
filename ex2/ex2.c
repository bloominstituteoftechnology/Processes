// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("text.txt", "r+");

    // both child and parent will get their own copies of the file descriptors,
    // and if they are writing to the file concurrently, they will end up appending their additions
    int rc = fork();

    if (rc < 0) {
        printf("Fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        fprintf(fp, "Hello, child here (pid:%d)\n", (int) getpid());
    }
    else {
        fprintf(fp, "Hello, parent here (pid:%d) of child %d\n", (int) getpid(), rc);
    }

    return 0;
}

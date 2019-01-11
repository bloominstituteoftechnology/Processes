// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;

    file = fopen("text.txt", "r+");

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork did not succeed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid: %d)\n", (int) getpid());
        fprintf(file, "CHILD: I'm a rebel leaving my mark\n");
        //run something on child process

    } else {
        printf("hello, I am parent of %d (pid: %d)\n", rc, (int) getpid());
        fprintf(file, "I'm a parent, picking up after my child -_-\n");
        //run something on parent process
    }
    fclose(file);

    return 0;
}

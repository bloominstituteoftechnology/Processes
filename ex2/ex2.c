// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    char *file = "text.txt";
    char *type = "a";
    FILE *f = fopen(file, type);

    int rc = fork();
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch
        printf("AFTER forking CHILD pid: %d\n", (int)getpid());
        fprintf(f, "%s %s %d\n", "Child-File", "write", (int)getpid());
    }
    else
    {
        printf("AFTER forking PARENT pid: %d\n", (int)getpid());
        fprintf(f, "%s %s %d\n", "Parent-File", "write", (int)getpid());
    }
    fclose(f);
    return 0;
}

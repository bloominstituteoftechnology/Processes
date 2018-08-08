// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;

    file = fopen("text.txt", "r+");

    if (file == NULL)
    {
        fprintf(stderr, "File failed to open\n");
        exit(1);
    }
    fprintf(file, "%s %s %s %s %s %s %s %s %s\n", "Parent", "gets", "first", "crack", "at", "writing", "to", "the", "file");

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child process, pid# %d and I think the file is ... %p\n", (int) getpid(), file);
        fprintf(file, "%s %s %s %s %s %s %s?\n", "Can", "a", "child", "write", "to", "this", "file");
    }
    else
    {
        printf("Parent (%d) process of (%d) and the file is ... %p\n", (int) getpid(), rc, file);
        fprintf(file, "%s %s %s %s %s %s?\n", "What", "if", "the", "parent", "writes", "too");
    }
    
    return 0;
}

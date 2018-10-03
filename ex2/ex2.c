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
    fprintf(file, "%s\n", "Test");

    int ret_val = fork();
    if (ret_val < 0)
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (ret_val == 0)
    {
        printf("This is the child process. %p\n", file);
        fprintf(file, "Child: %s\n", "The Child");
    }
    else
    {
        printf("This is the parent process. %p\n", file);
        fprintf(file, "Parent:%s\n", "The Parent");
    }

    return 0;

}

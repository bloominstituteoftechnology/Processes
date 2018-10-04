// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("text.txt", "w");

    int pid = fork();

    if (pid == 0)
    {
        char child[] = "Child was here";
        fwrite(child, 1, sizeof(child), file);
    }
    else
    {
        char parent[] = "Parent was here";
        fwrite(parent, 1, sizeof(parent), file);
    }

    fclose(file);

    return 0;
}

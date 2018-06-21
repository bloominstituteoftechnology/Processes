// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

// ANSWER: Both the child and parent access it and write to the file concurrently, but it seems the order they write in is randomized?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen("text.txt", "w");

    int rc = fork();

    if (rc < 0)
    {
        printf(stderr, "fork failed, exiting\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("child processes\n");
        char childText[] = "This text is from the child\n";
        fwrite(childText, 1, sizeof(childText) - 1, file);
    }
    else
    {
        printf("parent processes\n");
        char parentText[] = "This text is from the parent\n";
        fwrite(parentText, 1, sizeof(parentText) - 1, file);
    }

    return 0;
}

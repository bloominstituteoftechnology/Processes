// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

// > yes, they can both access the file concurrently
// > the text is added one after the other

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *file = fopen("./text.txt", "a");

    fork();

    fprintf(file, "text to be written over");

    return 0;
}

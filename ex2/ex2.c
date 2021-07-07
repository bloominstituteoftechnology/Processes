// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("text.txt", "r+");

    int rv = fork();
    if (rv == 0) {
        fprintf(file, "TEST: %s\n", "Child");
        printf("FILE-C: %p\n", file);
    } else {
        fprintf(file, "TEST: %s\n", "Parent");
        printf("FILE-P: %p\n", file);
    }

    return 0;
}

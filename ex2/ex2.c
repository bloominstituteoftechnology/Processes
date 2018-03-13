// Write a program that opens the text.txt  file (with the `fopen()` system
// call) located in this directory and then calls `fork()` to create a new
// process. Can both the child and parent access the file descriptor returned by
// `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("text.txt", "w");

    if (fp == NULL) {
        fprintf(stderr, "failed to open file");
        exit(1);
    }

    if (fork() == 0) {
        // We're the child
        for (int i = 0; i < 20000; i++) {
            fprintf(fp, "Child writing to file!\n");
        }
    } else {
        // We're the parent
        for (int i = 0; i < 20000; i++) {
            fprintf(fp, "Parent writing to file!\n");
        }

        wait(NULL);

    }


    
    return 0;
}
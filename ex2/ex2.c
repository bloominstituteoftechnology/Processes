// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("text.txt", "r+");
    char c;

    if (file == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }
    int rc = fork();
    if (rc < 0) {    // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (rc == 0) {
        // printf("because something needs to happen here\n");
        fputs("\n Child testing \n", file);
            // while ((c = fgetc(file)) != EOF) { 
            // printf ("%c", c); 
            // } 
    } else {
        // fputs("\n Parent testing \n", file);
        // fputs("\n Parent 2\n", file);
        printf("Am I getting here?\n");
        while ((c = fgetc(file)) != EOF) { 
        printf ("%c", c); 
        } 

    fclose(file);
    return 0;
    }
}
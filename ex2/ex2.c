// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Answer: The child and parent can indeed print one after another.  If you try to run the entire program
// again,

// Compile in correct ex2 folder: `gcc -Wall -Wextra -o ex2 ex2.c`
// Then run: `./ex2`

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// int argc, char *argv[]
int main()
{
    FILE *fp = fopen("text.txt", "w+"); // https://www.geeksforgeeks.org/data-type-file-c/
    int rc = fork();
    printf("ex2 executing...\n");

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Child running...\n");
        fprintf(fp, "Child printed this!\n");
    }
    else
    {
        printf("Parent running...\n");
        fprintf(fp, "Parent printed this!\n");
    }
    fclose(fp);
    return 0;
}

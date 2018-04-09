// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Answers:
//   1 - yes, both have access to the file descriptor
//   2 - As far as I can tell, both add to the file but only the child prints the output

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    int c;

    fp = fopen("text.txt", "w");
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed, exiting.\n");
        exit(1);
    } else if (rc == 0) {
        fprintf(fp, "\n%s", "Child inserted text.\n");
    } else {
        fprintf(fp, "\n%s", "Parent inserted text.\n");
    }
    fclose(fp);

    return 0;
}

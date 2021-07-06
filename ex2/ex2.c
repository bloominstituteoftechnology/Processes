// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE* myfile;
    myfile = fopen("text.txt", "w");
    fprintf(myfile, "Writing before fork... Parent pid: %d\n", (int) getpid());

    int childProcess = fork();
    if (childProcess < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (childProcess == 0) {
        printf("child called\n");
        fprintf(myfile, "Writing from Child...pid: %d\n", (int) getpid());
    } else {
        printf("parent called\n");
        fprintf(myfile, "Writing from Parent...pid: %d\n", (int) getpid());
    }
    fclose(myfile);
    return 0;
}

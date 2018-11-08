// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
      FILE * fp;
    //opens text.txt and associates stream fp, w truncates to zero length for writing.
    // Note that since the f open is before the fork you recieve both the parent and child process
    // The use of w creates a contention over a shared resources beteween the two processes
    // file is created and overwritten the scheduler seems to determine which file runs first.
    // If we forked before we would start the child process and then open, so we would get the conflict.
    // otherwise the parent and the child would run Parent -> Child.
    // Keep in mind that the terminal output is a shared resources
    fp = fopen("./text.txt", "w");
    //opens new process?
    fork();

    //The C library function int fprintf(FILE *stream, const char *format, ...) sends formatted output to a stream.
    // specifiy file
    fprintf(fp, "%s", "You can't buy my time. it's worth \n");
    // get pid here is getting the child process I think.
    fprintf(fp, "%d. \n", (int) getpid());

    return 0;
}

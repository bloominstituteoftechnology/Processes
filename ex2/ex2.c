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
    fp = fopen("./text.txt", "w");
    //opens new process?
    fork();

    //The C library function int fprintf(FILE *stream, const char *format, ...) sends formatted output to a stream.
    // specifiy file
    fprintf(fp, "%s", "You can't buy my time. it's worth \n");
    fprintf(fp, "%d. \n", (int) getpid());

    return 0;
}

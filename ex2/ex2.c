// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int ch;
    FILE * fp;
    fp = fopen("/Users/homebase/Desktop/Processes/ex2/text.txt", "r");
    ch = getc(fp);
    while (ch != EOF) {
        putchar(ch);
        ch = getc(fp);
    }
    fclose(fp);

    return 0;
}

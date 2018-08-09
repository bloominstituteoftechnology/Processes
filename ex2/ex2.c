// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *text_file;
    text_file = fopen("text.txt", "r+");
    int forked = fork();

    if (forked < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (forked == 0)
    {
        fprintf(text_file, "%s", "Look at me, I'm writing text into a file. I'm a child. What is going on?\n");
    } else 
    {
        fprintf(text_file, "%s", "Look at me, I'm writing text into a file. I'm a parent. Why hello.\n");
    }
    fclose(text_file);
    return 0;
}

// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE * woah;

    woah = fopen("text.txt", "a");
    int opened = fork();

    if (opened == 0){
        fprintf(woah, "%s", "This is the Child\n");
    } else {
        wait(NULL);
        fprintf(woah, "%s", "This is the Parent\n");
    }

    fclose(woah);
    
    return 0;
}

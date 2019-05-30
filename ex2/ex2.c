// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Both the child and the parent can access the file descriptor, if both processes attempt to write to the file then 
// both attempts will be saved.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;

    fp = fopen("text.txt", "r+");

    int pid = fork();

    if (pid == 0) {
        fprintf(fp, "%s %s %s %s", "The", "child", "wrote", "this.");
   
        fclose(fp);
    }
    else {
        fprintf(fp, "%s %s %s %s", "The", "parent", "wrote", "this.");
   
        fclose(fp);
    }
    // Your code here 
    
    return 0;
}

// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

/*
It seems to me that they can. And they will be the same even if you call within their scopes. 
I also printed out the pointer and they are the same as well. What actually suprised me the most
was how it printed to the terminal.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp;
    fp = fopen("text.txt", "r");
    if (fp == NULL)
    {
        printf("Could not open the file for text.txt");
        exit(1);
    }
    int fileNum;
    // fileNum = fileno(fp);
    // printf("Pointer: %d\n", fileNum);

    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        fileNum = fileno(fp);
        printf("Child descriptor: %d\n", fileNum);
        printf("Child pointer: %p\n", fp);
    }
    else
    {
        fileNum = fileno(fp);
        printf("Parent descriptor: %d\n", fileNum);
        printf("Parent pointer: %p\n", fp);
    }

    fclose(fp);
    return 0;
}

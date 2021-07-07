// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE * pFile;
    pFile = fopen ("text.txt", "w+");
    int second = fork();

    if(second < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if(second == 0) {
        fputs("Yo child here.\n", pFile);
    }
    else {
        fputs("Hello parent here.\n", pFile);
    }

    fclose(pFile);

    return 0;
}

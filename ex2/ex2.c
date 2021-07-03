// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Yes they can both access the file descriptor returned by fopen. They both get written in when called concurrently.
    FILE *file;
    file = fopen("text.txt", "r+");
    // Your code here 
    int test = fork();
    if(test == 0) {
        fprintf(file, "%s", "CHILD");
        printf("CHILD %d\n", fileno(file));
    } else {
        fprintf(file, "%s", "PARENT");
        printf("PARENT %d\n", fileno(file));
    }
    
    fclose(file);
    return 0;
}

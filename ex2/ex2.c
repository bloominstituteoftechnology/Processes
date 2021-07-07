// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fp;
    fp = fopen("text.txt", "r+");
    int child = fork();
    if (child == 0) {
        printf("Pointer Child: %d\n", *fp);
        fprintf(fp, "Inside the child\n");
    } else {
        printf("Pointer Parent %d\n", *fp);
        fprintf(fp, "Inside the Parent\n");
    }
    fclose(fp);
    return 0;
}
//returns:

// Pointer Parent: 0
// Pointer Child: 0


// Both can access the file descriptor by fopen().

//They both seem to be able to write to the file from my testing
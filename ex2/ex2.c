// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fptr;
    fptr = fopen("text.txt", "w");

    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed \n");
        exit(1);
    } else if(rc == 0) {
        fprintf(fptr, "This is the written content from child fork\n");
    } else {
        fprintf(fptr, "This is the written content from the parent fork\n");
    }

    fclose(fptr);
    
    return 0;
}

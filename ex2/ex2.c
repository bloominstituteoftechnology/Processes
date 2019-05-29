// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fptr; // declare pointer to type file, needed for communication between file and program
    fptr = fopen("text.txt", "w"); // opens the file text.txt and allows writing with "w" mode as second param

    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "fork failed \n");
        exit(1); 
    }else if(rc == 0){
        fprintf(fptr, "This is the written content from child fork\n"); 
    }else{
        fprintf(fptr, "This is the written content from the parent fork\n"); 
    }

    fclose(fptr); // make sure to close file when done writing
    
    return 0;
}

// Both the child and parent are able to access the file descriptor returned by fopen()
// When written concurrently the parent writes first, then the child 
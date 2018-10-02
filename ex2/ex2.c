// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    return 0;
}

    // FILE *fptr;
    // char c;
    // // Open file 
    // fptr = fopen("text.txt", "r"); 
    // if (fptr == NULL) 
    // { 
    //     printf("Cannot open file \n"); 
    //     exit(0); 
    // } 
  
    // // Read contents from file 
    // while ((c = fgetc(fptr)) != EOF) 
    // { 
    //     printf ("%c", c); 
    // } 
  
    // fclose(fptr); 
    
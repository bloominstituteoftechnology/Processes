// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *pText;
    pText = fopen("text.txt", "w");
    int rc = fork();
    if(rc < 0) {
        perror("Error with forking");
        exit(-1);
    }
    if(rc == 0) {
        fprintf(pText, "Child wrote this text\n");
        
    }   else {
        fprintf(pText, "Parent wrote this text\n");
    }
    fclose(pText);
    
    return 0;
}

/* both can write on the text.txt */

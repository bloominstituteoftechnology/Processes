// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fptr;
    fptr = fopen("text.txt","a");
    printf("Before fork is called\n");
    pid_t pid;        // _t means type delcaration pid under the hood it is an int.
    pid = fork(); // doesn't take paramters
    if (pid == 0) {
        fprintf(fptr, "Child wrote in text file\n");
    } else {
        fprintf(fptr, "Parent wrote in text file\n");
    }
    fclose(fptr);

    
    return 0;
}

/*
"Before fork is called" is written to the terminal.
Both parent and child have access to the file.
Parent & Child both wrote to text.txt
Order observed was always parent before child.
Could this be different since there is no wait?
*/

// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here
    FILE *fp; //create pointer
    fp = fopen("text.txt", "r+"); //open text fil
    int rc = fork();
    if (rc < 0) // if fork failed
    {
        fprintf(stderr,"fork failed\n");
        exit(1); // exit program
    }
    else if (rc == 0) // child satisifies fork
    {
        fprintf(fp, "Your kid is up to no good.\n");
    }
    else
    {
        fprintf(fp, "Parental obfuscation yas.\n");
    }
    fclose(fp);
    return 0;
}
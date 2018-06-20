// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *FP = fopen("./text.txt", "w+");
    int RC = fork();
    if(RC < 0) 
    {
        fprintf(stderr, "Fork Failed\n");
    }
    else if (RC == 0) 
    {
        fprintf(FP, "%s", "From the child process.\n");
        fclose(FP);
    }
    else 
    {
        fprintf(FP, "%s", "From the  parent process.\n");
        fclose(FP);
    }



    return 0;
}

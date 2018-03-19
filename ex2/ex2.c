// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE * fp;
    FILE * fp2;

    fp = fopen("text.txt", "r");
    fp2 = fopen("text.txt", "w");

    pid_t forky = fork();

    if (forky < 0)
    {
        fprintf(stderr, "FORK FAILED\n");
        exit(1);
    }
    // if it fails it returns -1

    if (forky == 0 && fp > 0)
    {
        printf("CHILD IS HERE, IT'S PID IS: %d THIS IS THE INTEGER RETURNED FROM FOPEN: %d\n", getpid(), fp);
        fprintf(fp2, "CHILD HAS WRITTEN\n");
    }
    else
    {
        printf("ONLY PARENT EXISTS, IT'S PID IS: %d THIS IS THE INTEGER RETURNED FROM FOPEN: %d\n", getpid(), fp);
        fprintf(fp2, "PARENT HAS WRITTEN\n");
    }


// if childP contains/opens file then return confirmation 
// else return "Only Parent has access file"


    return 0;
}

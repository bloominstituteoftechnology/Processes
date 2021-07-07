// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE * fp;
    fp = fopen("text.txt", "a");
    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
    int rv = fork();
    if(rv < 0){
        printf("fork failed!");
    }else if(rv == 0){
        printf("Hey, I'm the child process :) %d\n", getpid());
        fprintf(fp, "%s %s", "Boooya!\n", "child can access too :)\n");
    }
    return 0;
}

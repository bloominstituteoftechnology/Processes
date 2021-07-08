// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here
    FILE * fp;

    fp = fopen ("text.txt", "w+");

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork fail\n");
    } else if (rc == 0) {
        fprintf(fp, "%s %s %s %d", "I", "am", "in", 2018 );
    } else {
        printf(fp, "%s %s %s %d", "The", "year", "is", 2018 );
    
    return 0;
}

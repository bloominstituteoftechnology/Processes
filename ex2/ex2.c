/* Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor returned by `fopen()`? What happens when they are written to the file concurrently? */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Your code here 
    FILE* fp = fopen("text.txt", "w"); // initialize FILE pointer and fopens(filename, mode)
    int rc = fork(); // create rc variable and set it equal to fork

    if (rc < 0) {    // fork failed
        fprintf(stderr, "fork failed\n"); // error message
        exit(1); // exit 
    } else if (rc == 0) {
        char *childptr = "hello, child here \n";
        fwrite(childptr, sizeof(char), strlen(childptr), fp); // arguments(pointer to the string to be written, sizeof bytes in each char, strlen of pointer string, initialized file pointer)
    } else {        
        char *parentptr = "hello, parent here \n";
        fwrite(parentptr, sizeof(char), strlen(parentptr), fp);
    }
    fclose(fp);
    return 0;
}

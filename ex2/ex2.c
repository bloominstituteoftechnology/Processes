// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

/* 
> Can both the child and parent access the file descriptor returned by `fopen()`? 

Yes, both the child and parent can access the file, even if it was opened before the fork statement.

> What happens when they are written to the file concurrently?

There doesn't appear to be any conflicts. The parent process appears to do its write operation first before the child.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *fp;
    fp = fopen("text.txt", "r+");
    int rc = fork();
    if (rc < 0) {
        printf("fork failed\n");
        exit(1);
    } 
    else if (rc == 0) {
        fprintf(fp, "Your kid is up to no good.\n");
    }
    else {
        fprintf(fp, "Parental obfuscation yas.\n");
    }
    fclose(fp);
    return 0;
}

// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Your code here
    // "fp" stands for "file pointer" 
    FILE* fp;
    fp = fopen("text.txt", "w");

    // "rc" stands for "run command"
    int rc = fork();
    
    if (rc < 0)
    {
        // The fprintf function sends formatted output to a stream. A stream is a sequence of bytes of data.
        fprintf(stderr, "Fork unsuccessful!\n");
        exit(1);
    }

    else if (rc == 0)
    {
        printf("This is the child process.\n");
        char *child_str = "This is the child string.\n";
        // Writes data to the stream. A stream is a sequence of bytes of data.
        fwrite(child_str, sizeof(char), strlen(child_str), fp);
    }

    else
    {
        printf("This is the parent process.\n");
        char *parent_str = "This is the parent string.\n";
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);
    }

    fclose(fp);
    return 0;
}

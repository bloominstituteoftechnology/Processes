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
        // The fprintf function sends formatted output to a stream. 
        fprintf(stderr, "Fork unsuccessful!\n");
        exit(1);
    }

    else if (rc == 0)
    {
        printf("This is the child process. Pointer: %p\n", fp);
        char *child_str = "This is the child string.\n";
        // Writes data to the stream. A stream is a sequence of bytes of data
        // The first integer stands for the size of the character. The second stands for the length of the string
        fwrite("This is the child string.", 1, 5, fp);
    }

    else
    {
        printf("This is the parent process. Pointer: %p\n", fp);
        char *parent_str = "This is the parent string.\n";
        fwrite("This is the parent string.", 1, 8, fp);
    }

    fclose(fp);
    return 0;
}

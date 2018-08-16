// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> // needed to use built-in function strlen

int main(void)
{
    // Your code here
    FILE *fp;                    // initialize a file pointer
    fp = fopen("text.txt", "w"); // fopen() takes a filename to be opened (text.txt in this example) and a mode 'w' that creates a file for writing.

    int rc = fork(); // call fork to create a child process
    if (rc < 0)      // if fork failed print out a standard error message
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) // represents child process
    {
        printf("child process here\n");
        char *child_str = "This is child string!\n";            // created a character array a.k.a. string
        fwrite(child_str, sizeof(char), strlen(child_str), fp); //fwrite writes data from the array pointed to to the given output stream. child_str is the pointer to the array of elements to be written, sizeof(char) = size of bytes in each element to be written, strlen(child_str) = num of elements, and fp is the pointer to the output stream.
    }
    else // represents the parent after a successful fork
    {
        printf("parent process here\n");
        char *parent_str = "This is parent string!\n";            // created a character array a.k.a. string
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp); // see above comment for fwrite()
    }
    fclose(fp); // closes the file
    return 0;   // needs to return an integer
}

// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // init a file pointer
    FILE* fp;
    // use file open system to access text.txt
    fp = fopen("text.txt", "w");
    // assign the child process to a variable.
    int rc = fork();

    if (rc < 0)
    {
        // format print a standard error if the child process has a negative value
        fprintf(stderr, "fork failed\n");
        // exit the code block
        exit(1);
    }
    else if (rc == 0)
    {
        // if the fork value is 0, send the user a message
        printf("child process here\n");
        // create a string that will serve as the child process's value
        char *child_str = "This is child string!\n";
        // write the string to the text.txt file by passing the string itself,
        // its size, the length of elements in it, and then open the file
        fwrite(child_str, sizeof(char), strlen(child_str), fp);
    }
    else
    {
        // if fork's value is positive, it is still the parent,
        // so let the user know
        printf("parent process here\n");
        // create a string for the parent's value
        char *parent_str = "This is parent string!\n";
        // write the same values as above to the txt file
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);
    }
    // close the txt file.
    fclose(fp);
    return 0;
}

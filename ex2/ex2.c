// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // read_data expects a pointer to a FILE
    FILE *fp;

    // writes the results of the program to a text file
    fp = fopen("text.txt", "w");

    // system call to create a new child process
    int rc = fork();

    // checking if system call is less than
    if (rc < 0) {
        // printing error results 
        fprint(stderr, "fork failed\n");
        exit(1);
        // checking if system call is equal to
    } else if (rc == 0) {
        // printing results
        printf("child process here\n");
        // creating a process
        char *child_str = "This ischild string!\n";
        // function writes the data specified by the void pointer to the file
        fwrite(child_str, sizeof(char), strlen(child_str), fp);
    } else {
        printf("parent process here\n");
        // creating a process
        char *parent_str = "This is parent string!\n";
        // function writes the data specified by the void pointer to the file
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);
    
    }
    // flushes the stream pointed to by stream and closes the underlying file descriptor
    fclose(fp);
    return 0;
}

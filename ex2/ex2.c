// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>  // installing the necessary header files
#include <unistd.h>
#include <stdlib.h>
#include <string.h> // for calling the strlen function

int main(void)
{
    // Your code here 
    FILE* fp;   // initialize a file pointer; writing to files in c
    fp = fopen("text.txt", "w");   // calling the system call fopen() to open access to the file

    int rc = fork();    // fork function: creates a new process by duplicating the calling process. Child process is created.
    
    if (rc < 0) {   // handling error during fork()
        fprintf(stderr, "fork failed\n");   // error message; fprintf printing to standard error
        exit(1);    // exit 
    } else if (rc == 0) {   // on successful forking, run this child process 
        printf("child here\n");
        char *child_str = "This is a child string!\n";  // initialize a character string for child
        fwrite(child_str, sizeof(char), strlen(child_str), fp);  // write to text file taking in string, size, length of string, & where to write the file to
    } else {
        printf("parent here\n");    // on successful forking, run this child process 
        char *parent_str = "This is a parent string!\n";    // initialize a character string for parent
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);   // write to text file taking in string, size, length of string, & where to write the file to
    }

    fclose(fp); // close file pointer 
    
    return 0;
}

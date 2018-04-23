// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen("text.txt", "w");
    int rc = fork();

    // child process starts here
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){
        fprintf(fp, "%s A child wrote this\n");
    }
     else {
        fprintf(fp, "%s A child else statement wrote this\n");
    }

    fprintf(fp, "%s A parent wrote this\n"); 
    
    return 0;
}

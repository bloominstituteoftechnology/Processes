// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp = fopen("text.txt", "w");
    
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file\n");
        exit(1);
    }
    
    // Your code here 
    pid_t rc = fork();
    
    if(rc == 0) {
        fprintf(fp, "Child writing to open file\n");
        fprintf(fp, "x = %d\n", x);
    } else {
        x = 500;
        sleep(1);
        fprintf(fp, "Parent writing to open file\n");
        fprintf(fp, "x = %d\n", x);
        waitpid(rc, NULL, 0);
    }
    return 0;
}

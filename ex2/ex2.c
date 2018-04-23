// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Your code here 
    FIlE *fp;
    fp = fopen("text.txt", "w");
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if (rc == 0) {
        fwrite(fp, "Child Process");
    } else {
        fwrite(fp, "Parent Process");
    }
    
    return 0;
}

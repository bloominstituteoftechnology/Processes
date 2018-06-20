// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Your code here 

    FILE *fp;

    fp = fopen("text.txt", "r+");
    fprintf(fp, "%s %s %s %s\n", "Testing", "file", "with", "fork.");

    int rc = fork();

    if(rc < 0) {
        fprintf(stderr, "fork failed.\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child Process started.\n");
        fprintf(fp, "%s %s %s %s\n", "Testing", "file", "child", "fork.");
    } else {
        printf("Parent Process continues.\n");
        fprintf(fp, "%s %s %s %s\n", "Testing", "file", "parent", "fork.");
    }

    fprintf(fp, "%s %s %s %s\n", "Testing", "file", "post", "fork.");
    
    return 0;
}

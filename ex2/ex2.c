// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

// Purpose: Wait on the child before executing

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Open file
    FILE *fp = fopen('./text.txt', 'w+');
    int rc = fork();
    if (rc < 0) {  
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        fprintf(fp, '%s', ' from child\n');
        fclose(fp);
    } else {
        fprintf(fp, '%s', ' from parent\n');
        fclose(fp);
    }
    return 0;
}

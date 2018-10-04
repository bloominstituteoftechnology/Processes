// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("text.txt","w");

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char child[] = "This is the child string!";
        fwrite(child, 1, sizeof(child), fp);
    } else {
        char parent[] = "This is the parent string!";
        fwrite(parent, 1, sizeof(parent), fp);
    }
    fclose(fp);
    return 0;
}

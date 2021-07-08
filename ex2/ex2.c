// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("text.txt", "r+");
    
    int rc = fork();


    if (rc < 0) {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    } else if (rc == 0) {
        fprintf(fp, "Text from child\n");
    } else {
        fprintf(fp, "Text from parent\n");
    }
    fclose(fp);

    return 0;
}

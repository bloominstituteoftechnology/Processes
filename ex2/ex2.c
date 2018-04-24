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
    // char c;

    fp = fopen("text.txt", "r+");
    int rc = fork();
    // while(1) {
    //     c = fgetc(fp);
    //     if (feof(fp)) {
    //         break;
    //     }
    // }
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // printf("contents of the file in child are: %c\n", c);
        fprintf(fp, "content added to the file of child\n");
    } else {
        // printf("contents of the file in parent are: %c\n", c);
        fprintf(fp, "content added to the file of parent\n");
    }

    fclose(fp);
    return 0;
}

// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Your code here 
    FILE *fp;
    fp = fopen("text.txt", "w");
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("child here\n");
        char *child_str = "me child\n";
        fwrite(child_str, sizeof(char), strlen(child_str), fp);
        // fprintf(fp, child_str);
    } else {
        printf("parent here\n");
        char *parent_str = "me parent\n";
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);
        // fprint(fp, parent_str);
    }

    fclose(fp);
    return 0;
}

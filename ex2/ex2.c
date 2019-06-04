// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE* fp;
    fp = fopen("text.txt", "w");
    int rc = fork();
    
    if (rc < 0) {  // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        char *child_str = "Child lorem ipsum.\n";
        printf("child process: writing %s\n", child_str);
        fwrite(child_str, sizeof(char), strlen(child_str), fp);
    } else {
        char *parent_str = "Parent lorem ipsum.\n";
        printf("parent process: writing %s\n", parent_str);
        fwrite(parent_str, sizeof(char), strlen(parent_str), fp);
    }

    fclose(fp);
    return 0;
}

// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//int main(int argc, char* argv[])
int main()
{
    // Your code here 
    FILE *fp = fopen("text.txt", "w+");
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "Fork failed, exiting.\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child process writing...\n");
        char *child_string = "Written by the child process.\n";
        fprintf(fp, "%s", child_string);
    } else {
        printf("Parent process writing...\n");
        char *parent_string = "Written by the parent process.\r";
        fprintf(fp, "%s", parent_string);
    }
    fclose(fp);
    return 0;
}

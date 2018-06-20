// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    fp = fopen("text.txt", "w");

    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child process\n");
        char child_str[] = "Child string\n";
        fwrite(child_str, 1, sizeof(child_str) - 1, fp);
    } else {
        printf("Parent process\n");
        char parent_str[] = "Parent string\n";
        fwrite(parent_str, 1, sizeof(parent_str) - 1, fp);
    }
    fclose(fp);
    
    return 0;
}

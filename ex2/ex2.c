// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *file;
    file = fopen("text.txt", "w");

    int childProcess = fork();
    if (childProcess < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (childProcess == 0) {
        printf("child process here\n");
        char child_str[] = "Child string is \n";
        fwrite(child_str, 1, sizeof(child_str), file);
    } else {
        printf("parent process here\n");
        char parent_str[] = "Parent string is \n";
        fwrite(parent_str, 1, sizeof(parent_str), file);
    }
    fclose(file);
    return 0;
}

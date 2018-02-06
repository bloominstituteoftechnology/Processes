// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* file_pointer;
    file_pointer = fopen("text.txt", "w");

    int rc = fork();
    if (rc < 0) 
    {
        fprintf(stderr, "the fork failed\n");
        exit(1);
    } else if (rc == 0) 
    {
        printf("This is the child process\n");
        char child_string[] = "This is the child string\n";
        fwrite(child_string, 1, sizeof(child_string), file_pointer);
    }
    fclose(file_pointer);
    return 0;
}

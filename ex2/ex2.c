// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE * file_pointer;

    file_pointer = fopen("text.txt", "r+");
    int pid = fork();

    if(pid == 0) {
        fprintf(file_pointer, "%s %s", "Child", "text.\n");
        fclose(file_pointer);
    }
    else {
        fprintf(file_pointer, "%s %s", "Parent", "text.");
        fclose(file_pointer);
    }

    return 0;
}

/* Yes, both child and parent can access the file returned by fopen(). In the case of concurrent attempts, they are saved together as in the example above. */
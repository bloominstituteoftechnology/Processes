// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *text = fopen("./text.txt", "r+");

    int child = fork();

    if (child < 0)
    {
        printf("Error when creating child process.");
        exit(1);
    }
    else if (child == 0)
    {
        printf("Pointer to child process 'text.txt': %p\n", text);
        fwrite("Child", 1, 5, text);
    }
    else
    {
        printf("Pointer to parent process 'text.txt': %p\n", text);
        fwrite("Parent\n", 1, 8, text);
    }
    return 0;
}

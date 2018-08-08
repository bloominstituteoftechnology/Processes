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

    // printf("\nPointer to `text.txt`: %p\n\n", text);

    int child = fork();

    if (child < 0)
    {
        printf("There was an error when creating the child process.");
        exit(1);
    }
    if (child == 0)
    {
        printf("\nPointer to Child process `text.txt`: %p\n\n", text);
        fwrite("Child", 1, 5, text);
    }
    else
    {
        printf("\nPointer to Parent process `text.txt`: %p\n\n", text);
        fwrite("Parent\n\n", 1, 8, text);
    }
    
    return 0;
}

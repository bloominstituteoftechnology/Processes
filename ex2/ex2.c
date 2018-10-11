// Write a program that opens the text.txt  file (with the `fopen()` system call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here

    FILE *fPointer;

    fPointer = fopen("text.txt", "w+"); // Deletes whats present and then writes

    fprintf(fPointer, "Testing the write with pid: %d\n", getpid());

    pid_t pid = fork();

    if (pid == 0) // Child Process
    {
        fprintf(fPointer, "CHILD: write with pid: %d\n", getpid());
    }
    else // Parent Process
    {
        fprintf(fPointer, "PARENT: write with pid: %d\n", getpid());
    }

    fclose(fPointer); // Closes the file when done

    return 0;
}

// Can both the child and parent access the file descriptor returned by `fopen()`?
// YES

// What happens when they are written to the file concurrently?
// They both get written